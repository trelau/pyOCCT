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
from itertools import product

from OCCT.BRep import BRep_Tool
from OCCT.BRepAdaptor import BRepAdaptor_Curve
from OCCT.BRepBuilderAPI import BRepBuilderAPI_Copy
from OCCT.BRepClass3d import BRepClass3d
from OCCT.BRepTools import BRepTools_WireExplorer, BRepTools
from OCCT.Geom import Geom_BSplineCurve
from OCCT.GeomConvert import GeomConvert_CompCurveToBSplineCurve
from OCCT.ShapeAnalysis import (ShapeAnalysis_Edge, ShapeAnalysis_FreeBounds,
                                ShapeAnalysis_ShapeTolerance)
from OCCT.ShapeExtend import ShapeExtend_WireData
from OCCT.ShapeFix import ShapeFix_WireSegment
from OCCT.TopAbs import (TopAbs_COMPOUND, TopAbs_EDGE, TopAbs_FACE,
                         TopAbs_SHELL, TopAbs_SOLID, TopAbs_VERTEX,
                         TopAbs_WIRE,
                         TopAbs_SHAPE)
from OCCT.TopExp import TopExp_Explorer
from OCCT.TopoDS import (TopoDS_Compound, TopoDS_Edge, TopoDS_Face,
                         TopoDS_Shell, TopoDS_Solid, TopoDS_Vertex,
                         TopoDS_Wire, TopoDS)

from OCCT.Topology.Props import AreaOfShapes

__all__ = ['ExploreShape', 'ExploreWire', 'ExploreFreeEdges']


class ExploreShape(object):
    """
    Explore shapes.
    """

    @staticmethod
    def get_vertices(shape, unique=True):
        """
        Get vertices from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
        :param bool unique: Option to return only unique vertices.

        :return: Vertices of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Vertex]
        """
        if isinstance(shape, TopoDS_Vertex):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_VERTEX)
        vertices = []
        while exp.More():
            vi = exp.Current()
            vertex = TopoDS.Vertex_(vi)
            if unique:
                is_unique = True
                for v in vertices:
                    if v.IsSame(vertex):
                        is_unique = False
                        break
                if is_unique:
                    vertices.append(vertex)
            else:
                vertices.append(vertex)
            exp.Next()
        return vertices

    @staticmethod
    def get_edges(shape, unique=True):
        """
        Get edges from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
        :param bool unique: Option to return only unique edges.

        :return: Edges of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Edge]
        """
        if isinstance(shape, TopoDS_Edge):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_EDGE)
        edges = []
        while exp.More():
            ei = exp.Current()
            edge = TopoDS.Edge_(ei)
            if unique:
                is_unique = True
                for e in edges:
                    if e.IsSame(edge):
                        is_unique = False
                        break
                if is_unique:
                    edges.append(edge)
            else:
                edges.append(edge)
            exp.Next()
        return edges

    @staticmethod
    def get_wires(shape):
        """
        Get wires from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: Wires of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Wire]
        """
        if isinstance(shape, TopoDS_Wire):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_WIRE)
        wires = []
        while exp.More():
            wi = exp.Current()
            wire = TopoDS.Wire_(wi)
            wires.append(wire)
            exp.Next()
        return wires

    @staticmethod
    def get_faces(shape):
        """
        Get faces from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: Faces of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Face]
        """
        if isinstance(shape, TopoDS_Face):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_FACE)
        faces = []
        while exp.More():
            fi = exp.Current()
            face = TopoDS.Face_(fi)
            faces.append(face)
            exp.Next()
        return faces

    @staticmethod
    def get_shells(shape):
        """
        Get shells from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: Shells of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Shell]
        """
        if isinstance(shape, TopoDS_Shell):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_SHELL)
        shells = []
        while exp.More():
            si = exp.Current()
            shell = TopoDS.Shell_(si)
            shells.append(shell)
            exp.Next()
        return shells

    @staticmethod
    def get_solids(shape):
        """
        Get solids from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: Solids of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Solid]
        """
        if isinstance(shape, TopoDS_Solid):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_SOLID)
        solids = []
        while exp.More():
            si = exp.Current()
            solid = TopoDS.Solid_(si)
            solids.append(solid)
            exp.Next()
        return solids

    @staticmethod
    def get_compounds(shape):
        """
        Get compounds from a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: Compounds of shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Compound]
        """
        if isinstance(shape, TopoDS_Compound):
            return [shape]

        exp = TopExp_Explorer(shape, TopAbs_COMPOUND)
        compounds = []
        while exp.More():
            ci = exp.Current()
            compound = TopoDS.Compound_(ci)
            compounds.append(compound)
            exp.Next()
        return compounds

    @staticmethod
    def get_shared_edges(shape1, shape2):
        """
        Get the shared edges between the two shapes.

        :param TopoDS.TopoDS_Shape shape1: The first shape.
        :param TopoDS.TopoDS_Shape shape2: The second shape.

        :rtype: List of shared edges.
        :rtype: list[OCCT.TopoDS.TopoDS_Edge]
        """
        edges1 = ExploreShape.get_edges(shape1)
        edges2 = ExploreShape.get_edges(shape2)
        if not edges1 or not edges2:
            return []

        shared_edges = []
        for e1, e2 in product(edges1, edges2):
            if e1.IsSame(e2):
                unique = True
                for ei in shared_edges:
                    if ei.IsSame(e1):
                        unique = False
                        break
                if unique:
                    shared_edges.append(e1)

        return shared_edges

    @staticmethod
    def outer_wire(face):
        """
        Get outer wire of face.

        :param OCCT.TopoDS.TopoDS_Face face: The face.

        :return: Outer wire.
        :rtype: OCCT.TopoDS.TopoDS_Wire
        """
        return BRepTools.OuterWire_(face)

    @staticmethod
    def outer_shell(solid):
        """
        Get the outer shell of the solid.

        :param OCCT.TopoDS.TopoDS_Solid solid: The solid.

        :return: Outer shell.
        :rtype: OCCT.TopoDS.TopoDS_Shell
        """
        return BRepClass3d.OuterShell_(solid)

    @staticmethod
    def pnt_of_vertex(vertex):
        """
        Get the underlying point of the vertex.

        :param OCCT.TopoDS.TopoDS_Vertex vertex: The vertex.

        :return: The point.
        :rtype: OCCT.gp.gp_Pnt
        """
        return BRep_Tool.Pnt_(vertex)

    @staticmethod
    def curve_of_edge(edge):
        """
        Get the curve of the edge.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: Underlying curve of edge.
        :rtype: OCCT.Geom.Geom_Curve
        """
        return BRep_Tool.Curve_(edge, 0., 0.)

    @staticmethod
    def curve_of_wire(wire):
        """
        Get the curve of the wire. The edges are concatenated so the
        resulting curve may be C0 continuous.

        :param OCCT.TopoDS.TopoDS_Wire wire: The wire.

        :return: Concatenated curve of wire.
        :rtype: OCCT.Geom.Geom_BSplineCurve

        :raise RuntimeError: If an unsupported curve type is found.
        """
        geom_convert = GeomConvert_CompCurveToBSplineCurve()
        exp = BRepTools_WireExplorer(wire)
        tol = ExploreShape.global_tolerance(wire, 1)
        while exp.More():
            e = TopoDS.Edge_(exp.Current())
            exp.Next()
            adp_crv = BRepAdaptor_Curve(e)
            geom_convert.Add(adp_crv.BSpline(), tol)
        crv = geom_convert.BSplineCurve()
        if not isinstance(crv, Geom_BSplineCurve):
            msg = 'Unsupported curve type.'
            raise RuntimeError(msg)
        return crv

    @classmethod
    def curve_of_shape(cls, shape):
        """
        Get the curve of the shape if possible.

        :param shape: The edge or wire.
        :type shape: OCCT.TopoDS.TopoDS_Edge or OCCT.TopoDS.TopoDS_Wire

        :return: The underlying curve of the edge or wire.
        :rtype: OCCT.Geom.Geom_Curve

        :raise TypeError: If *shape* is not an edge or wire.
        """
        if shape.ShapeType() == TopAbs_EDGE:
            return cls.curve_of_edge(shape)
        elif shape.ShapeType() == TopAbs_WIRE:
            return cls.curve_of_wire(shape)
        else:
            msg = 'Invalid shape.'
            raise TypeError(msg)

    @staticmethod
    def surface_of_face(face):
        """
        Get the surface of the face.

        :param OCCT.TopoDS.TopoDS_Face face: The face.

        :return: Underlying surface of face.
        :rtype: OCCT.Geom.Geom_Surface
        """
        return BRep_Tool.Surface_(face)

    @classmethod
    def surface_of_shape(cls, shape):
        """
        Get the surface of the largest face in the shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.

        :return: The surface.
        :rtype: OCCT.Geom.Geom_Surface
        """
        faces = cls.get_faces(shape)
        if not faces:
            return None

        f = AreaOfShapes(faces).largest_shape
        return cls.surface_of_face(f)

    @staticmethod
    def first_vertex(edge):
        """
        Return the first vertex of the edge considering orientation.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: The first vertex.
        :rtype: OCCT.TopoDS.TopoDS_Vertex
        """
        return ShapeAnalysis_Edge().FirstVertex(edge)

    @staticmethod
    def last_vertex(edge):
        """
        Return the last vertex of the edge considering orientation.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: The last vertex.
        :rtype: OCCT.TopoDS.TopoDS_Vertex
        """
        return ShapeAnalysis_Edge().LastVertex(edge)

    @classmethod
    def vertices(cls, edge):
        """
        Return the first and last vertex of the edge.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.

        :return: The first and last vertices (v1, v2).
        :rtype: tuple(OCCT.TopoDS.TopoDS_Vertex)
        """
        return cls.first_vertex(edge), cls.last_vertex(edge)

    @staticmethod
    def parameter(vertex, edge, face=None):
        """
        Return the parameter of the vertex on the edge.

        :param OCCT.TopoDS.TopoDS_Vertex vertex: The vertex.
        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.
        :param OCCT.TopoDS.TopoDS_Face face: The face.

        :return: The parameter.
        :rtype: float
        """
        if not face:
            BRep_Tool.Parameter_(vertex, edge)
        else:
            return BRep_Tool.Parameter_(vertex, edge, face)

    @classmethod
    def parameters(cls, edge, face=None):
        """
        Return the first and last parameters on the edge.

        :param OCCT.TopoDS.TopoDS_Edge edge: The edge.
        :param OCCT.TopoDS.TopoDS_Face face: The face.

        :return: The parameters (u1, u2).
        :rtype: tuple(float)
        """
        v1, v2 = cls.vertices(edge)
        u1 = cls.parameter(v1, edge, face)
        u2 = cls.parameter(v2, edge, face)
        return u1, u2

    @staticmethod
    def local_tolerance(shape, mode=0, styp=TopAbs_SHAPE):
        """
        Compute the local tolerance of the shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
        :param int mode: Average (0), maximal (1), minimal (2)
        :param OCCT.TopAbs.TopAbs_ShapeEnum styp: The level of shape to examine
            (i.e., only vertices, only edges, only faces, or all shapes).

        :return: The tolerance.
        :rtype: float
        """
        tol = ShapeAnalysis_ShapeTolerance()
        return tol.Tolerance(shape, mode, styp)

    @staticmethod
    def global_tolerance(shape, mode=0):
        """
        Compute the global tolerance of the shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
        :param int mode: Average (0), maximal (1), minimal (2)

        :return: The tolerance.
        :rtype: float
        """
        tol = ShapeAnalysis_ShapeTolerance()
        tol.AddTolerance(shape)
        return tol.GlobalTolerance(mode)

    @staticmethod
    def copy_shape(shape, copy_geom=True):
        """
        Copy a shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape,
        :param bool copy_geom: Option to copy geometry.

        :return: The copied shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        return BRepBuilderAPI_Copy(shape, copy_geom).Shape()


class ExploreWire(object):
    """
    Explore the edges of a wire.

    :param OCCT.TopoDS.TopoDS_Wire wire: The wire.
    :param OCCT.TopoDS.TopoDS_Face face: The face.
    """

    def __init__(self, wire, face=None):
        if face is None:
            explorer = BRepTools_WireExplorer(wire)
        else:
            explorer = BRepTools_WireExplorer(wire, face)

        edges = []
        current_verts = []
        while explorer.More():
            ei = TopoDS.Edge_(explorer.Current())
            vi = TopoDS.Vertex_(explorer.CurrentVertex())
            edges.append(ei)
            current_verts.append(vi)
            explorer.Next()

        # CurrentVertex doesn't get the last vertex. Try to get it.
        ordered_verts = list(current_verts)
        if edges:
            data = ShapeExtend_WireData(wire)
            fix = ShapeFix_WireSegment(data)
            v1 = fix.LastVertex()
            ordered_verts.append(v1)

        self._edges = edges
        self._current_verts = current_verts
        self._ordered_verts = ordered_verts

    @property
    def nedges(self):
        """
        :return: Number of edges.
        :rtype: int
        """
        return len(self._edges)

    @property
    def edges(self):
        """
        :return: The ordered edges.
        :rtype: list[OCCT.TopoDS.TopoDS_Edge]
        """
        return self._edges

    @property
    def current_vertices(self):
        """
        :return: The result of the BRepTools_WireExplorer::CurrentVertex method.
            As the explorer traverses the edges, this stores the vertex
            connecting the current edge to the previous one. This will not be a
            complete list of ordered vertices.
        :rtype: list[OCCT.TopoDS.TopoDS_Vertex]
        """
        return self._current_verts

    @property
    def ordered_vertices(self):
        """
        :return: Attempt to provide the ordered vertices of a wire. If the wire
            is closed the first and last vertices will be the same.
        :rtype: list[OCCT.TopoDS.TopoDS_Vertex]
        """
        return self._ordered_verts


class ExploreFreeEdges(object):
    """
    Explore the free bounds of a shape.

    :param OCCT.TopoDS.TopoDS_Shape shape: The shape.
    """

    def __init__(self, shape):
        tool = ShapeAnalysis_FreeBounds(shape)
        cmp_closed_wires = tool.GetClosedWires()
        cmp_open_wires = tool.GetOpenWires()
        self._closed_wires = ExploreShape.get_wires(cmp_closed_wires)
        self._open_wires = ExploreShape.get_wires(cmp_open_wires)
        self._edges = (ExploreShape.get_edges(cmp_closed_wires) +
                       ExploreShape.get_edges(cmp_open_wires))

    @property
    def closed_wires(self):
        """
        :return: Closed wires of free edges.
        :rtype: list[OCCT.TopoDS.TopoDS_Wire]
        """
        return self._closed_wires

    @property
    def open_wires(self):
        """
        :return: Open wires of free edges.
        :rtype: list[OCCT.TopoDS.TopoDS_Wire]
        """
        return self._open_wires

    @property
    def free_edges(self):
        """
        :return: All free edges of the shape.
        :rtype: list[OCCT.TopoDS.TopoDS_Edge]
        """
        return self._edges
