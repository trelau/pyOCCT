import sys

from OCCT.AIS import AIS_InteractiveContext, AIS_Shaded, AIS_Shape
from OCCT.Aspect import Aspect_DisplayConnection, Aspect_TOTP_LEFT_LOWER
from OCCT.MeshVS import (MeshVS_DA_DisplayNodes, MeshVS_DA_EdgeColor,
                         MeshVS_Mesh, MeshVS_MeshPrsBuilder)
from OCCT.OpenGl import OpenGl_GraphicDriver
from OCCT.Quantity import (Quantity_TOC_RGB, Quantity_NOC_WHITE,
                           Quantity_Color,
                           Quantity_NOC_BLACK)
from OCCT.SMESH import SMESH_MeshVSLink
from OCCT.V3d import V3d_Viewer
from OCCT.WNT import WNT_Window
from PySide import QtCore
from PySide.QtGui import QWidget, QApplication, QPalette, QIcon


class SimpleViewer(QWidget):
    def __init__(self, width=800, height=600, title='pyOCCT'):
        super(SimpleViewer, self).__init__()

        # Qt settings
        self.setBackgroundRole(QPalette.NoRole)
        self.setMouseTracking(True)
        self.resize(width, height)
        self.setWindowTitle(title)
        icon = QIcon('./resources/main.png')
        self.setWindowIcon(icon)

        # Display connection
        display_connection = Aspect_DisplayConnection()

        # Graphics driver
        graphics_driver = OpenGl_GraphicDriver(display_connection)

        # Window handle
        window_handle = self.winId()

        # Windows window
        wind = WNT_Window(window_handle)

        # Create viewer and view
        self.my_viewer = V3d_Viewer(graphics_driver)
        self.my_view = self.my_viewer.CreateView()
        self.my_view.SetWindow(wind)

        # Map window
        wind.Map()

        # AIS interactive context
        self.my_context = AIS_InteractiveContext(self.my_viewer)

        # Some default settings
        self._white = Quantity_Color(Quantity_NOC_WHITE)
        self._black = Quantity_Color(Quantity_NOC_BLACK)
        self.my_viewer.SetDefaultLights()
        self.my_viewer.SetLightOn()
        self.my_view.SetBackgroundColor(Quantity_TOC_RGB, 0.5, 0.5, 0.5)
        self.my_context.SetDisplayMode(AIS_Shaded, True)
        drawer = self.my_context.DefaultDrawer()
        drawer.SetFaceBoundaryDraw(True)
        self.my_view.TriedronDisplay(Aspect_TOTP_LEFT_LOWER, self._white, 0.08)

        # Keyboard map
        self._keys = {
            ord('F'): self.my_view.FitAll
        }

        # Values for mouse movement
        self._x0, self._y0 = 0., 0.

    def resizeEvent(self, *args, **kwargs):
        self.my_view.MustBeResized()

    def keyPressEvent(self, e):
        try:
            self._keys[e.key()]()
        except KeyError:
            pass

    def wheelEvent(self, e):
        if e.delta() > 0:
            zoom = 1.5
        else:
            zoom = 0.75
        self.my_view.SetZoom(zoom)

    def mousePressEvent(self, e):
        pos = e.pos()
        x, y = pos.x(), pos.y()
        self._x0, self._y0 = x, y
        self.my_view.StartRotation(x, y)

    def mouseDoubleClickEvent(self, e):
        pos = e.pos()
        x, y = pos.x(), pos.y()
        self._x0, self._y0 = x, y
        self.my_view.StartRotation(x, y)

    def mouseMoveEvent(self, e):
        pos = e.pos()
        x, y = pos.x(), pos.y()
        button = e.buttons()

        # Rotate
        if button == QtCore.Qt.LeftButton:
            self.my_view.Rotation(x, y)
        # Pan
        elif button == QtCore.Qt.MidButton:
            dx, dy = x - self._x0, y - self._y0
            self._x0, self._y0 = x, y
            self.my_view.Pan(dx, -dy)

    def display_shape(self, shape):
        ais_shape = AIS_Shape(shape)
        self.my_context.Display(ais_shape, True)

    def display_mesh(self, mesh):
        vs_link = SMESH_MeshVSLink(mesh)
        mesh_vs = MeshVS_Mesh()
        mesh_vs.SetDataSource(vs_link)
        prs_builder = MeshVS_MeshPrsBuilder(mesh_vs)
        mesh_vs.AddBuilder(prs_builder)
        mesh_vs_drawer = mesh_vs.GetDrawer()
        mesh_vs_drawer.SetBoolean(MeshVS_DA_DisplayNodes, False)
        mesh_vs_drawer.SetColor(MeshVS_DA_EdgeColor, self._black)
        mesh_vs.SetDisplayMode(2)
        self.my_context.Display(mesh_vs, True)

    def fit(self):
        self.my_view.FitAll()


def display_shape(shape=None, mesh=None):
    app = QApplication(sys.argv)
    v = SimpleViewer()
    if shape is not None:
        v.display_shape(shape)
    if mesh is not None:
        v.display_mesh(mesh)
    v.fit()
    app.exec_()


if __name__ == '__main__':
    from OCCT.BRepPrimAPI import BRepPrimAPI_MakeBox
    from OCCT.NETGENPlugin import (NETGENPlugin_Hypothesis_2D,
                                   NETGENPlugin_NETGEN_2D)
    from OCCT.SMESH import SMESH_Gen

    box = BRepPrimAPI_MakeBox(10, 20, 30).Solid()

    gen = SMESH_Gen()

    the_mesh = gen.CreateMesh(0, True)
    the_mesh.ShapeToMesh(box)

    hyp2d = NETGENPlugin_Hypothesis_2D(0, 0, gen)
    hyp2d.SetQuadAllowed(True)
    hyp2d.SetMaxSize(1)
    hyp2d.SetMinSize(1)
    hyp2d.SetSurfaceCurvature(False)

    alg2d = NETGENPlugin_NETGEN_2D(1, 0, gen)

    the_mesh.AddHypothesis(the_mesh.GetShapeToMesh(), 0)
    the_mesh.AddHypothesis(the_mesh.GetShapeToMesh(), 1)

    gen.Compute(the_mesh, the_mesh.GetShapeToMesh())

    display_shape(None, the_mesh)
