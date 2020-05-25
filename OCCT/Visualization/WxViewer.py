# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import os
import sys
import warnings

import wx
from OCCT.AIS import AIS_InteractiveContext, AIS_Shape, AIS_Shaded, AIS_WireFrame
from OCCT.Aspect import Aspect_DisplayConnection, Aspect_TOTP_LEFT_LOWER
from OCCT.BRepBuilderAPI import (BRepBuilderAPI_MakeVertex, BRepBuilderAPI_MakeEdge,
                                 BRepBuilderAPI_MakeFace)
from OCCT.Geom import Geom_Curve, Geom_Surface
from OCCT.Graphic3d import Graphic3d_MaterialAspect
from OCCT.MeshVS import MeshVS_Mesh, MeshVS_MeshPrsBuilder, MeshVS_DrawerAttribute
from OCCT.OpenGl import OpenGl_GraphicDriver
from OCCT.Quantity import Quantity_Color, Quantity_NOC_BLACK, Quantity_TOC_RGB
from OCCT.TopoDS import TopoDS_Shape
from OCCT.V3d import V3d_Viewer, V3d_TypeOfOrientation
from OCCT.gp import gp_Pnt

try:
    from OCCT.SMDSAbs import SMDSAbs_Node
    from OCCT.SMESH import SMESH_MeshVSLink, SMESH_Mesh, SMESH_subMesh

    HAS_SMESH = True
except ImportError:
    HAS_SMESH = False
    msg = "SMESH module was not found for visualization."
    warnings.warn(msg, RuntimeWarning)

__all__ = ['ViewerWx']

_icon = os.path.dirname(__file__) + '/_resources/icon.png'


class ViewerWx(wx.Frame):
    """
    Basic tool for viewing shapes based on wx.

    :param int height: Window height.
    :param int width: Window width.
    """

    def __init__(self, width=800, height=600):
        # Launch an app before initializing any wx types
        self._app = wx.App()
        super(ViewerWx, self).__init__(None, title='pyOCCT', size=(width, height))

        self._init()
        self.Center()

    def _init(self):
        """
        Initialize the viewer.
        """

        # Icon
        ico = wx.Icon(_icon, wx.BITMAP_TYPE_PNG)
        self.SetIcon(ico)

        # Store some defaults
        self._x0, self._y0 = 0., 0.
        self._black = Quantity_Color(Quantity_NOC_BLACK)

        # Display connection
        self.display_connect = Aspect_DisplayConnection()

        # Graphics driver
        graphics_driver = OpenGl_GraphicDriver(self.display_connect)

        # Create viewer and view
        self._my_viewer = V3d_Viewer(graphics_driver)
        self._my_view = self._my_viewer.CreateView()

        # AIS interactive context
        self._my_context = AIS_InteractiveContext(self._my_viewer)

        # Initial settings
        self._my_viewer.SetDefaultLights()
        self._my_viewer.SetLightOn()
        self._my_view.SetBackgroundColor(Quantity_TOC_RGB, 0.5, 0.5, 0.5)
        self._my_context.SetDisplayMode(AIS_Shaded, True)
        self._my_drawer = self._my_context.DefaultDrawer()
        self._my_drawer.SetFaceBoundaryDraw(True)

        self._my_view.TriedronDisplay(Aspect_TOTP_LEFT_LOWER, self._black,
                                      0.08)
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_XposYposZpos)

        # Events
        self.Bind(wx.EVT_PAINT, self._evt_paint)
        self.Bind(wx.EVT_SIZE, self._evt_size)
        self.Bind(wx.EVT_CHAR, self._evt_char)
        self.Bind(wx.EVT_CLOSE, self._evt_close)
        self.Bind(wx.EVT_MOUSE_EVENTS, self._evt_mouse_events)
        self.Bind(wx.EVT_MOUSEWHEEL, self._evt_mousewheel)

    def _init_wind(self, fit, background):
        """
        Under Linux, wxPython's GetHandle() only returns a valid handle if
        called after the MainLoop has started. This function completes the
        parts of the initialisation which require the window handle. It is
        called from start() using wx.CallAfter()
        """
        # Do only if my_view is empty
        if self._my_view.IsEmpty():
            # Suitable handle to window. Returns a HWND in Windows and an X
            # Window identifier in Linux
            hwnd = self.GetHandle()

            if sys.platform.startswith('win'):
                import ctypes
                from OCCT.WNT import WNT_Window

                ctypes.pythonapi.PyCapsule_New.restype = ctypes.py_object
                ctypes.pythonapi.PyCapsule_New.argtypes = [ctypes.c_int,
                                                           ctypes.c_void_p,
                                                           ctypes.c_void_p]
                capsule = ctypes.pythonapi.PyCapsule_New(hwnd, None, None)

                # WNT window
                wind = WNT_Window(capsule)
            elif sys.platform.startswith('linux'):
                from OCCT.Xw import Xw_Window

                # Xw window
                wind = Xw_Window(self.display_connect, hwnd)
            else:
                raise NotImplementedError('Support platform not found for visualization.')

            # Map window
            if not wind.IsMapped():
                wind.Map()

            # Set the window
            self._my_view.SetWindow(wind)

        # Fit if desired
        if fit:
            self.fit()

        # If running in background, just continue. Otherwise, show the window.
        if background:
            self._continue()
        else:
            self.show()

    def _evt_paint(self, *args):
        self._my_view.Redraw()

    def _evt_size(self, *args):
        self._my_view.MustBeResized()

    def _evt_char(self, e):
        if e.GetKeyCode() == ord('f'):
            self.fit()
        elif e.GetKeyCode() == ord('s'):
            self._my_context.SetDisplayMode(AIS_Shaded, True)
        elif e.GetKeyCode() == ord('w'):
            self._my_context.SetDisplayMode(AIS_WireFrame, True)
        elif e.GetKeyCode() == ord('i'):
            self._my_view.SetProj(V3d_TypeOfOrientation.V3d_XposYposZpos)
        elif e.GetKeyCode() == ord('t'):
            self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Zpos)
        elif e.GetKeyCode() == ord('c'):
            self._continue()
        else:
            print('Key is not mapped to anything.')

    def _evt_mousewheel(self, e):
        if e.GetWheelRotation() > 0:
            zoom = 1.5
        else:
            zoom = 0.75
        self._my_view.SetZoom(zoom)

    def _evt_mouse_events(self, e):
        if e.Moving():
            return None

        pos = e.GetPosition()
        x, y = pos.x, pos.y

        if e.LeftDown():
            self._x0, self._y0 = x, y
            self._my_view.StartRotation(x, y)
        if e.RightDown():
            self._x0, self._y0 = x, y

        if e.LeftIsDown():
            self._my_view.Rotation(x, y)
        elif e.RightIsDown():
            dx, dy = x - self._x0, y - self._y0
            self._x0, self._y0 = x, y
            self._my_view.Pan(dx, -dy)

    def _evt_close(self, *args):
        self._my_drawer = None
        self._my_context = None
        self._my_view = None
        self._my_viewer = None
        self.Destroy()
        self._app.ExitMainLoop()

    def _continue(self, *args):
        self.show(False)
        self._app.ExitMainLoop()

    def fit(self):
        """
        Fit the contents.

        :return: None.
        """
        self._my_view.FitAll()
        self._my_view.ZFitAll()
        self._my_view.Redraw()

    def display_ais(self, ais_shape, update=True):
        """
        Display an AIS_Shape.

        :param OCCT.AIS.AIS_Shape ais_shape: The AIS shape.
        :param bool update: Option to update the viewer.

        :return: None.
        """
        self._my_context.Display(ais_shape, update)

    def display_shape(self, shape, rgb=None, transparency=None, material=None):
        """
        Display a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
        :param rgb: The RGB color (r, g, b).
        :type rgb: collections.Sequence(float) or OCCT.Quantity.Quantity_Color
        :param float transparency: The transparency (0 to 1).
        :param OCCT.Graphic3d.Graphic3d_NameOfMaterial material: The material.

        :return: The AIS_Shape created for the part.
        :rtype: OCCT.AIS.AIS_Shape
        """
        ais_shape = AIS_Shape(shape)

        if isinstance(rgb, (tuple, list)):
            r, g, b = rgb
            if r > 1.:
                r /= 255.
            if g > 1.:
                g /= 255.
            if b > 1.:
                b /= 255.
            color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
            ais_shape.SetColor(color)
        elif isinstance(rgb, Quantity_Color):
            ais_shape.SetColor(rgb)

        if transparency is not None:
            ais_shape.SetTransparency(transparency)

        if material is not None:
            ma = Graphic3d_MaterialAspect(material)
            ais_shape.SetMaterial(ma)

        self._my_context.Display(ais_shape, True)
        return ais_shape

    def display_geom(self, geom, rgb=None, transparency=None, material=None):
        """
        Display a geometric entity.

        :param geom: The geometry.
        :type geom: OCCT.gp.gp_Pnt or OCCT.Geom.Geom_Curve or
            OCCT.Geom.Geom_Surface
        :param rgb: The RGB color (r, g, b).
        :type rgb: collections.Sequence(float) or OCCT.Quantity.Quantity_Color
        :param float transparency: The transparency (0 to 1).
        :param OCCT.Graphic3d.Graphic3d_NameOfMaterial material: The material.

        :return: The AIS_Shape created for the geometry. Returns *None* if the
            entity cannot be converted to a shape.
        :rtype: OCCT.AIS.AIS_Shape or None
        """
        if isinstance(geom, gp_Pnt):
            shape = BRepBuilderAPI_MakeVertex(geom).Vertex()
        elif isinstance(geom, Geom_Curve):
            shape = BRepBuilderAPI_MakeEdge(geom).Edge()
        elif isinstance(geom, Geom_Surface):
            shape = BRepBuilderAPI_MakeFace(geom, 1.0e-7).Face()
        else:
            return None

        return self.display_shape(shape, rgb, transparency, material)

    def display_mesh(self, mesh, mode=2, group=None,
                     display_nodes=False, node_size=1, node_color=(1, 1, 1),
                     display_edges=True, edge_size=1, edge_color=(0.5, 0.5, 0.5),
                     beam_size=2, beam_color=(1, 1, 0),
                     face_color=(0, 0, 0.5), back_face_color=None):
        """
        Display a mesh.

        :param mesh: The mesh.
        :type mesh: OCCT.SMESH_SMESH_Mesh or OCCT.SMESH_SMESH_subMesh
        :param int mode: Display mode for mesh elements (1=wireframe, 2=solid).
        :param group: Option to display a group of mesh elements.
        :type group: None or OCCT.SMESH.SMESH_Group group
        :param bool display_nodes: Option to display mesh nodes or not. If a group of nodes is
            provided, then this option is turned on by default.
        :param float node_size: An option to scale the size of the node markers.
        :param node_color: The RGB values for the node markers between 0 and 1.
        :type node_color: tuple(float, float, float)
        :param bool display_edges: An option to display the edges of faces and beams.
        :param float edge_size: An option to scale the size of the edges.
        :param edge_color: The RGB values for the edges between 0 and 1.
        :type edge_color: tuple(float, float, float)
        :param float beam_size: An option to scale the size of the beams.
        :param beam_color: The RGB values for the beams between 0 and 1.
        :type beam_color: tuple(float, float, float)
        :param face_color: The RGB values for the faces between 0 and 1.
        :type face_color: tuple(float, float, float)
        :param back_face_color: The RGB values of the back side of the faces between 0 and 1. If not
            provided, then the back faces are colored the same as the faces.
        :type back_face_color: None or tuple(float, float, float)

        :return: The MeshVS_Mesh created for the mesh.
        :rtype: OCCT.MeshVS.MeshVS_Mesh
        """
        if not HAS_SMESH:
            raise NotImplementedError('SMESH was not found to support mesh visualization.')

        # Create the link
        if group:
            vs_link = SMESH_MeshVSLink(mesh, group)
        else:
            vs_link = SMESH_MeshVSLink(mesh)

        # Initialize
        mesh_vs = MeshVS_Mesh()
        mesh_vs.SetDataSource(vs_link)
        prs_builder = MeshVS_MeshPrsBuilder(mesh_vs)
        mesh_vs.AddBuilder(prs_builder)
        mesh_vs_drawer = mesh_vs.GetDrawer()

        # Node settings
        r, g, b = node_color
        color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
        mesh_vs_drawer.SetColor(MeshVS_DrawerAttribute.MeshVS_DA_MarkerColor, color)
        mesh_vs_drawer.SetDouble(MeshVS_DrawerAttribute.MeshVS_DA_MarkerScale, node_size)
        # Always display nodes for a group of nodes
        if not group:
            mesh_vs_drawer.SetBoolean(MeshVS_DrawerAttribute.MeshVS_DA_DisplayNodes, display_nodes)
        elif group.GetGroupDS().GetType() == SMDSAbs_Node:
            mesh_vs_drawer.SetBoolean(MeshVS_DrawerAttribute.MeshVS_DA_DisplayNodes, True)

        # Edge settings
        r, g, b = edge_color
        color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
        mesh_vs_drawer.SetColor(MeshVS_DrawerAttribute.MeshVS_DA_EdgeColor, color)
        mesh_vs_drawer.SetDouble(MeshVS_DrawerAttribute.MeshVS_DA_EdgeWidth, edge_size)
        mesh_vs_drawer.SetBoolean(MeshVS_DrawerAttribute.MeshVS_DA_ShowEdges, display_edges)

        # Beam settings
        r, g, b = beam_color
        color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
        mesh_vs_drawer.SetColor(MeshVS_DrawerAttribute.MeshVS_DA_BeamColor, color)
        mesh_vs_drawer.SetDouble(MeshVS_DrawerAttribute.MeshVS_DA_BeamWidth, beam_size)

        # Face settings
        r, g, b = face_color
        color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
        mesh_vs_drawer.SetColor(MeshVS_DrawerAttribute.MeshVS_DA_InteriorColor, color)
        if back_face_color:
            r, g, b = back_face_color
            color = Quantity_Color(r, g, b, Quantity_TOC_RGB)
            mesh_vs_drawer.SetColor(MeshVS_DrawerAttribute.MeshVS_DA_BackInteriorColor, color)

        # Display mode
        mesh_vs.SetDisplayMode(mode)

        self._my_context.Display(mesh_vs, True)
        return mesh_vs

    def add(self, entity, rgb=None, transparency=None, material=None, mode=2):
        """
        Add an entity to the view.

        :param entity: The entity.
        :param rgb: The RGB color (r, g, b).
        :type rgb: collections.Sequence(float) or OCCT.Quantity.Quantity_Color
        :param float transparency: The transparency (0 to 1).
        :param OCCT.Graphic3d.Graphic3d_NameOfMaterial material: The material.
        :param int mode: Display mode for mesh elements (1=wireframe, 2=solid).

        :return: The AIS_Shape created for the entity. Returns *None* if the
            entity cannot be converted to a shape.
        :rtype: OCCT.AIS.AIS_Shape or None
        """
        if isinstance(entity, TopoDS_Shape):
            return self.display_shape(entity, rgb, transparency, material)
        elif isinstance(entity, (gp_Pnt, Geom_Curve, Geom_Surface)):
            return self.display_geom(entity, rgb, transparency, material)
        elif HAS_SMESH and isinstance(entity, (SMESH_Mesh, SMESH_subMesh)):
            return self.display_mesh(entity, mode)
        else:
            return None

    def set_background_color(self, r, g, b):
        """
        Set the background color.

        :param float r: The r-value.
        :param float g: The g-value.
        :param float b: The b-value.

        :return: None.
        """
        self._my_view.SetBackgroundColor(Quantity_TOC_RGB, r, g, b)

    def set_white_background(self):
        """
        Set the background color to white.

        :return: None.
        """
        self._my_view.SetBackgroundColor(Quantity_TOC_RGB, 1., 1., 1.)

    def view_iso(self):
        """
        Isometric view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_XposYposZpos)

    def view_top(self):
        """
        Top view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Zpos)

    def view_bottom(self):
        """
        Bottom view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Zneg)

    def view_front(self):
        """
        Front view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Xneg)

    def view_rear(self):
        """
        Rear view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Xpos)

    def view_left(self):
        """
        Left view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Yneg)

    def view_right(self):
        """
        Right view.

        :return: None.
        """
        self._my_view.SetProj(V3d_TypeOfOrientation.V3d_Ypos)

    def capture(self, fn):
        """
        Capture the screen contents and save to a file. The type of file will be
        determined by the extension.

        :param str fn: The filename.

        :return: None.
        """
        self._my_view.Dump(fn)

    def clear(self):
        """
        Clear all items from the context.

        :return: None.
        """
        self._my_context.RemoveAll(True)

    def show(self, show=True):
        """
        Show or hide the window.

        :param bool show: Option to show or hide.

        :return: None.
        """
        self.Show(show)

    def start(self, fit=True, background=False):
        """
        Start the application.

        :param bool fit: Option to fit contents.
        :param bool background: Start the application but keep the window
            hidden. This would be used to take screen captures in the script.

        :return: None
        """
        print('Press \"c\" to continue...')

        # Initialize the OCCT window after the MainLoop has started.
        wx.CallAfter(self._init_wind, fit, background)
        self._app.MainLoop()
