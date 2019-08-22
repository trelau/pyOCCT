/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Vec2d.hxx>
#include <ShapeExtend_Status.hxx>
#include <Adaptor3d_Curve.hxx>
#include <gp_Pnt.hxx>
#include <ShapeAnalysis_Edge.hxx>

void bind_ShapeAnalysis_Edge(py::module &mod){

py::class_<ShapeAnalysis_Edge> cls_ShapeAnalysis_Edge(mod, "ShapeAnalysis_Edge", "Tool for analyzing the edge. Queries geometrical representations of the edge (3d curve, pcurve on the given face or surface) and topological sub-shapes (bounding vertices). Provides methods for analyzing geometry and topology consistency (3d and pcurve(s) consistency, their adjacency to the vertices).");

// Constructors
cls_ShapeAnalysis_Edge.def(py::init<>());

// Fields

// Methods
// cls_ShapeAnalysis_Edge.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_Edge::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_Edge.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_Edge::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Edge.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_Edge::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_Edge.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_Edge.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_Edge::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_Edge.def("HasCurve3d", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &) const) &ShapeAnalysis_Edge::HasCurve3d, "Tells if the edge has a 3d curve", py::arg("edge"));
cls_ShapeAnalysis_Edge.def("Curve3d", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, opencascade::handle<Geom_Curve> & C3d, Standard_Real & cf, Standard_Real & cl, const Standard_Boolean orient){ Standard_Boolean rv = self.Curve3d(edge, C3d, cf, cl, orient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, cf, cl); }, "Returns the 3d curve and bounding parameteres for the edge Returns False if no 3d curve. If <orient> is True (default), takes orientation into account: if the edge is reversed, cf and cl are toggled", py::arg("edge"), py::arg("C3d"), py::arg("cf"), py::arg("cl"), py::arg("orient"));
cls_ShapeAnalysis_Edge.def("IsClosed3d", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &) const) &ShapeAnalysis_Edge::IsClosed3d, "Gives True if the edge has a 3d curve, this curve is closed, and the edge has the same vertex at start and end", py::arg("edge"));
cls_ShapeAnalysis_Edge.def("HasPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &) const) &ShapeAnalysis_Edge::HasPCurve, "Tells if the Edge has a pcurve on the face.", py::arg("edge"), py::arg("face"));
cls_ShapeAnalysis_Edge.def("HasPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &ShapeAnalysis_Edge::HasPCurve, "Tells if the edge has a pcurve on the surface (with location).", py::arg("edge"), py::arg("surface"), py::arg("location"));
cls_ShapeAnalysis_Edge.def("PCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, const TopoDS_Face & face, opencascade::handle<Geom2d_Curve> & C2d, Standard_Real & cf, Standard_Real & cl, const Standard_Boolean orient){ Standard_Boolean rv = self.PCurve(edge, face, C2d, cf, cl, orient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, cf, cl); }, "None", py::arg("edge"), py::arg("face"), py::arg("C2d"), py::arg("cf"), py::arg("cl"), py::arg("orient"));
cls_ShapeAnalysis_Edge.def("PCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, const opencascade::handle<Geom_Surface> & surface, const TopLoc_Location & location, opencascade::handle<Geom2d_Curve> & C2d, Standard_Real & cf, Standard_Real & cl, const Standard_Boolean orient){ Standard_Boolean rv = self.PCurve(edge, surface, location, C2d, cf, cl, orient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, cf, cl); }, "Returns the pcurve and bounding parameteres for the edge lying on the surface. Returns False if the edge has no pcurve on this surface. If <orient> is True (default), takes orientation into account: if the edge is reversed, cf and cl are toggled", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("C2d"), py::arg("cf"), py::arg("cl"), py::arg("orient"));
cls_ShapeAnalysis_Edge.def("BoundUV", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt2d &) const) &ShapeAnalysis_Edge::BoundUV, "None", py::arg("edge"), py::arg("face"), py::arg("first"), py::arg("last"));
cls_ShapeAnalysis_Edge.def("BoundUV", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, gp_Pnt2d &, gp_Pnt2d &) const) &ShapeAnalysis_Edge::BoundUV, "Returns the ends of pcurve Calls method PCurve with <orient> equal to True", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("first"), py::arg("last"));
cls_ShapeAnalysis_Edge.def("IsSeam", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &) const) &ShapeAnalysis_Edge::IsSeam, "None", py::arg("edge"), py::arg("face"));
cls_ShapeAnalysis_Edge.def("IsSeam", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &ShapeAnalysis_Edge::IsSeam, "Returns True if the edge has two pcurves on one surface", py::arg("edge"), py::arg("surface"), py::arg("location"));
cls_ShapeAnalysis_Edge.def("FirstVertex", (TopoDS_Vertex (ShapeAnalysis_Edge::*)(const TopoDS_Edge &) const) &ShapeAnalysis_Edge::FirstVertex, "Returns start vertex of the edge (taking edge orientation into account).", py::arg("edge"));
cls_ShapeAnalysis_Edge.def("LastVertex", (TopoDS_Vertex (ShapeAnalysis_Edge::*)(const TopoDS_Edge &) const) &ShapeAnalysis_Edge::LastVertex, "Returns end vertex of the edge (taking edge orientation into account).", py::arg("edge"));
cls_ShapeAnalysis_Edge.def("GetEndTangent2d", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Boolean a2, gp_Pnt2d & a3, gp_Vec2d & a4) -> Standard_Boolean { return self.GetEndTangent2d(a0, a1, a2, a3, a4); });
cls_ShapeAnalysis_Edge.def("GetEndTangent2d", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Boolean, gp_Pnt2d &, gp_Vec2d &, const Standard_Real) const) &ShapeAnalysis_Edge::GetEndTangent2d, "None", py::arg("edge"), py::arg("face"), py::arg("atEnd"), py::arg("pos"), py::arg("tang"), py::arg("dparam"));
cls_ShapeAnalysis_Edge.def("GetEndTangent2d", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Boolean a3, gp_Pnt2d & a4, gp_Vec2d & a5) -> Standard_Boolean { return self.GetEndTangent2d(a0, a1, a2, a3, a4, a5); });
cls_ShapeAnalysis_Edge.def("GetEndTangent2d", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Boolean, gp_Pnt2d &, gp_Vec2d &, const Standard_Real) const) &ShapeAnalysis_Edge::GetEndTangent2d, "Returns tangent of the edge pcurve at its start (if atEnd is False) or end (if True), regarding the orientation of edge. If edge is REVERSED, tangent is reversed before return. Returns True if pcurve is available and tangent is computed and is not null, else False.", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("atEnd"), py::arg("pos"), py::arg("tang"), py::arg("dparam"));
cls_ShapeAnalysis_Edge.def("CheckVerticesWithCurve3d", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.CheckVerticesWithCurve3d(a0); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithCurve3d", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const Standard_Real a1) -> Standard_Boolean { return self.CheckVerticesWithCurve3d(a0, a1); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithCurve3d", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Integer)) &ShapeAnalysis_Edge::CheckVerticesWithCurve3d, "Checks the start and/or end vertex of the edge for matching with 3d curve with the given precision. <vtx> = 1 : start vertex only <vtx> = 2 : end vertex only <vtx> = 0 : both (default) If preci < 0 the vertices are considered with their own tolerances, else with the given <preci>.", py::arg("edge"), py::arg("preci"), py::arg("vtx"));
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1) -> Standard_Boolean { return self.CheckVerticesWithPCurve(a0, a1); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Real a2) -> Standard_Boolean { return self.CheckVerticesWithPCurve(a0, a1, a2); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Integer)) &ShapeAnalysis_Edge::CheckVerticesWithPCurve, "None", py::arg("edge"), py::arg("face"), py::arg("preci"), py::arg("vtx"));
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2) -> Standard_Boolean { return self.CheckVerticesWithPCurve(a0, a1, a2); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Real a3) -> Standard_Boolean { return self.CheckVerticesWithPCurve(a0, a1, a2, a3); });
cls_ShapeAnalysis_Edge.def("CheckVerticesWithPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const Standard_Integer)) &ShapeAnalysis_Edge::CheckVerticesWithPCurve, "Checks the start and/or end vertex of the edge for matching with pcurve with the given precision. <vtx> = 1 : start vertex <vtx> = 2 : end vertex <vtx> = 0 : both If preci < 0 the vertices are considered with their own tolerances, else with the given <preci>.", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("preci"), py::arg("vtx"));
cls_ShapeAnalysis_Edge.def("CheckVertexTolerance", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, const TopoDS_Face & face, Standard_Real & toler1, Standard_Real & toler2){ Standard_Boolean rv = self.CheckVertexTolerance(edge, face, toler1, toler2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, toler1, toler2); }, "None", py::arg("edge"), py::arg("face"), py::arg("toler1"), py::arg("toler2"));
cls_ShapeAnalysis_Edge.def("CheckVertexTolerance", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, Standard_Real & toler1, Standard_Real & toler2){ Standard_Boolean rv = self.CheckVertexTolerance(edge, toler1, toler2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, toler1, toler2); }, "Checks if it is necessary to increase tolerances of the edge vertices to comprise the ends of 3d curve and pcurve on the given face (first method) or all pcurves stored in an edge (second one) toler1 returns necessary tolerance for first vertex, toler2 returns necessary tolerance for last vertex.", py::arg("edge"), py::arg("toler1"), py::arg("toler2"));
cls_ShapeAnalysis_Edge.def("CheckCurve3dWithPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeAnalysis_Edge::CheckCurve3dWithPCurve, "None", py::arg("edge"), py::arg("face"));
cls_ShapeAnalysis_Edge.def("CheckCurve3dWithPCurve", (Standard_Boolean (ShapeAnalysis_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeAnalysis_Edge::CheckCurve3dWithPCurve, "Checks mutual orientation of 3d curve and pcurve on the analysis of curves bounding points", py::arg("edge"), py::arg("surface"), py::arg("location"));
cls_ShapeAnalysis_Edge.def("Status", (Standard_Boolean (ShapeAnalysis_Edge::*)(const ShapeExtend_Status) const) &ShapeAnalysis_Edge::Status, "Returns the status (in the form of True/False) of last Check", py::arg("status"));
cls_ShapeAnalysis_Edge.def("CheckSameParameter", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & edge, Standard_Real & maxdev, const Standard_Integer NbControl){ Standard_Boolean rv = self.CheckSameParameter(edge, maxdev, NbControl); return std::tuple<Standard_Boolean, Standard_Real &>(rv, maxdev); }, "Checks the edge to be SameParameter. Calculates the maximal deviation between 3d curve and each pcurve of the edge on <NbControl> equidistant points (the same algorithm as in BRepCheck; default value is 23 as in BRepCheck). This deviation is returned in <maxdev> parameter. If deviation is greater than tolerance of the edge (i.e. incorrect flag) returns False, else returns True.", py::arg("edge"), py::arg("maxdev"), py::arg("NbControl"));
cls_ShapeAnalysis_Edge.def("CheckSameParameter", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & theEdge, const TopoDS_Face & theFace, Standard_Real & theMaxdev, const Standard_Integer theNbControl){ Standard_Boolean rv = self.CheckSameParameter(theEdge, theFace, theMaxdev, theNbControl); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theMaxdev); }, "Checks the edge to be SameParameter. Calculates the maximal deviation between 3d curve and each pcurve of the edge on <NbControl> equidistant points (the same algorithm as in BRepCheck; default value is 23 as in BRepCheck). This deviation is returned in <maxdev> parameter. If deviation is greater than tolerance of the edge (i.e. incorrect flag) returns False, else returns True.", py::arg("theEdge"), py::arg("theFace"), py::arg("theMaxdev"), py::arg("theNbControl"));
cls_ShapeAnalysis_Edge.def("CheckPCurveRange", (Standard_Boolean (ShapeAnalysis_Edge::*)(const Standard_Real, const Standard_Real, const opencascade::handle<Geom2d_Curve> &)) &ShapeAnalysis_Edge::CheckPCurveRange, "Checks possibility for pcurve thePC to have range [theFirst, theLast] (edge range) having respect to real first, last parameters of thePC", py::arg("theFirst"), py::arg("theLast"), py::arg("thePC"));
cls_ShapeAnalysis_Edge.def_static("ComputeDeviation_", [](const Adaptor3d_Curve & CRef, const Adaptor3d_Curve & Other, const Standard_Boolean SameParameter, Standard_Real & dev, const Standard_Integer NCONTROL){ Standard_Boolean rv = ShapeAnalysis_Edge::ComputeDeviation(CRef, Other, SameParameter, dev, NCONTROL); return std::tuple<Standard_Boolean, Standard_Real &>(rv, dev); }, "Computes the maximal deviation between the two curve representations. dev is an input/output parameter and contains the computed deviation (should be initialized with 0. for the first call). Used by CheckSameParameter().", py::arg("CRef"), py::arg("Other"), py::arg("SameParameter"), py::arg("dev"), py::arg("NCONTROL"));
cls_ShapeAnalysis_Edge.def("CheckOverlapping", [](ShapeAnalysis_Edge &self, const TopoDS_Edge & theEdge1, const TopoDS_Edge & theEdge2, Standard_Real & theTolOverlap, const Standard_Real theDomainDist){ Standard_Boolean rv = self.CheckOverlapping(theEdge1, theEdge2, theTolOverlap, theDomainDist); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theTolOverlap); }, "Checks the first edge is overlapped with second edge. If distance between two edges is less then theTolOverlap edges is overlapped. theDomainDis - length of part of edges on wich edges is overlapped.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theTolOverlap"), py::arg("theDomainDist"));

// Enums

}