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
#include <BRepTools_ReShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>
#include <Geom_Plane.hxx>
#include <ShapeBuild_Vertex.hxx>
#include <ShapeBuild_Edge.hxx>
#include <ShapeBuild.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>

PYBIND11_MODULE(ShapeBuild, mod) {

py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Standard");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");

// CLASS: SHAPEBUILD_RESHAPE
py::class_<ShapeBuild_ReShape, opencascade::handle<ShapeBuild_ReShape>, BRepTools_ReShape> cls_ShapeBuild_ReShape(mod, "ShapeBuild_ReShape", "Rebuilds a Shape by making pre-defined substitutions on some of its components");

// Constructors
cls_ShapeBuild_ReShape.def(py::init<>());

// Methods
cls_ShapeBuild_ReShape.def("Apply", (TopoDS_Shape (ShapeBuild_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const Standard_Integer)) &ShapeBuild_ReShape::Apply, "Applies the substitutions requests to a shape", py::arg("shape"), py::arg("until"), py::arg("buildmode"));
cls_ShapeBuild_ReShape.def("Apply", [](ShapeBuild_ReShape &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.Apply(a0); });
cls_ShapeBuild_ReShape.def("Apply", (TopoDS_Shape (ShapeBuild_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &ShapeBuild_ReShape::Apply, "Applies the substitutions requests to a shape.", py::arg("shape"), py::arg("until"));
cls_ShapeBuild_ReShape.def("Status", [](ShapeBuild_ReShape &self, const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return self.Status(a0, a1); });
cls_ShapeBuild_ReShape.def("Status", (Standard_Integer (ShapeBuild_ReShape::*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean)) &ShapeBuild_ReShape::Status, "Returns a complete substitution status for a shape 0 : not recorded, <newsh> = original <shape> < 0: to be removed, <newsh> is NULL > 0: to be replaced, <newsh> is a new item If <last> is False, returns status and new shape recorded in the map directly for the shape, if True and status > 0 then recursively searches for the last status and new shape.", py::arg("shape"), py::arg("newsh"), py::arg("last"));
cls_ShapeBuild_ReShape.def("Status", (Standard_Boolean (ShapeBuild_ReShape::*)(const ShapeExtend_Status) const) &ShapeBuild_ReShape::Status, "Queries the status of last call to Apply(shape,enum) OK : no (sub)shapes replaced or removed DONE1: source (starting) shape replaced DONE2: source (starting) shape removed DONE3: some subshapes replaced DONE4: some subshapes removed FAIL1: some replacements not done because of bad type of subshape", py::arg("status"));
cls_ShapeBuild_ReShape.def_static("get_type_name_", (const char * (*)()) &ShapeBuild_ReShape::get_type_name, "None");
cls_ShapeBuild_ReShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeBuild_ReShape::get_type_descriptor, "None");
cls_ShapeBuild_ReShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeBuild_ReShape::*)() const) &ShapeBuild_ReShape::DynamicType, "None");

// CLASS: SHAPEBUILD
py::class_<ShapeBuild> cls_ShapeBuild(mod, "ShapeBuild", "This package provides basic building tools for other packages in ShapeHealing. These tools are rather internal for ShapeHealing .");

// Methods
// cls_ShapeBuild.def_static("operator new_", (void * (*)(size_t)) &ShapeBuild::operator new, "None", py::arg("theSize"));
// cls_ShapeBuild.def_static("operator delete_", (void (*)(void *)) &ShapeBuild::operator delete, "None", py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator new[]_", (void * (*)(size_t)) &ShapeBuild::operator new[], "None", py::arg("theSize"));
// cls_ShapeBuild.def_static("operator delete[]_", (void (*)(void *)) &ShapeBuild::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeBuild::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator delete_", (void (*)(void *, void *)) &ShapeBuild::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeBuild.def_static("PlaneXOY_", (opencascade::handle<Geom_Plane> (*)()) &ShapeBuild::PlaneXOY, "Rebuilds a shape with substitution of some components Returns a Geom_Surface which is the Plane XOY (Z positive) This allows to consider an UV space homologous to a 3D space, with this support surface");

// CLASS: SHAPEBUILD_EDGE
py::class_<ShapeBuild_Edge> cls_ShapeBuild_Edge(mod, "ShapeBuild_Edge", "This class provides low-level operators for building an edge 3d curve, copying edge with replaced vertices etc.");

// Methods
// cls_ShapeBuild_Edge.def_static("operator new_", (void * (*)(size_t)) &ShapeBuild_Edge::operator new, "None", py::arg("theSize"));
// cls_ShapeBuild_Edge.def_static("operator delete_", (void (*)(void *)) &ShapeBuild_Edge::operator delete, "None", py::arg("theAddress"));
// cls_ShapeBuild_Edge.def_static("operator new[]_", (void * (*)(size_t)) &ShapeBuild_Edge::operator new[], "None", py::arg("theSize"));
// cls_ShapeBuild_Edge.def_static("operator delete[]_", (void (*)(void *)) &ShapeBuild_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeBuild_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeBuild_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeBuild_Edge.def_static("operator delete_", (void (*)(void *, void *)) &ShapeBuild_Edge::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeBuild_Edge.def("CopyReplaceVertices", (TopoDS_Edge (ShapeBuild_Edge::*)(const TopoDS_Edge &, const TopoDS_Vertex &, const TopoDS_Vertex &) const) &ShapeBuild_Edge::CopyReplaceVertices, "Copy edge and replace one or both its vertices to a given one(s). Vertex V1 replaces FORWARD vertex, and V2 - REVERSED, as they are found by TopoDS_Iterator. If V1 or V2 is NULL, the original vertex is taken", py::arg("edge"), py::arg("V1"), py::arg("V2"));
cls_ShapeBuild_Edge.def("CopyRanges", [](ShapeBuild_Edge &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1) -> void { return self.CopyRanges(a0, a1); });
cls_ShapeBuild_Edge.def("CopyRanges", [](ShapeBuild_Edge &self, const TopoDS_Edge & a0, const TopoDS_Edge & a1, const Standard_Real a2) -> void { return self.CopyRanges(a0, a1, a2); });
cls_ShapeBuild_Edge.def("CopyRanges", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real) const) &ShapeBuild_Edge::CopyRanges, "Copies ranges for curve3d and all common pcurves from edge <fromedge> into edge <toedge>.", py::arg("toedge"), py::arg("fromedge"), py::arg("alpha"), py::arg("beta"));
cls_ShapeBuild_Edge.def("SetRange3d", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real) const) &ShapeBuild_Edge::SetRange3d, "Sets range on 3d curve only.", py::arg("edge"), py::arg("first"), py::arg("last"));
cls_ShapeBuild_Edge.def("CopyPCurves", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const TopoDS_Edge &) const) &ShapeBuild_Edge::CopyPCurves, "Makes a copy of pcurves from edge <fromedge> into edge <toedge>. Pcurves which are already present in <toedge>, are replaced by copies, other are copied. Ranges are also copied.", py::arg("toedge"), py::arg("fromedge"));
cls_ShapeBuild_Edge.def("Copy", [](ShapeBuild_Edge &self, const TopoDS_Edge & a0) -> TopoDS_Edge { return self.Copy(a0); });
cls_ShapeBuild_Edge.def("Copy", (TopoDS_Edge (ShapeBuild_Edge::*)(const TopoDS_Edge &, const Standard_Boolean) const) &ShapeBuild_Edge::Copy, "Make a copy of <edge> by call to CopyReplaceVertices() (i.e. construct new TEdge with the same pcurves and vertices). If <sharepcurves> is False, pcurves are also replaced by their copies with help of method CopyPCurves", py::arg("edge"), py::arg("sharepcurves"));
cls_ShapeBuild_Edge.def("RemovePCurve", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &) const) &ShapeBuild_Edge::RemovePCurve, "Removes the PCurve(s) which could be recorded in an Edge for the given Face", py::arg("edge"), py::arg("face"));
cls_ShapeBuild_Edge.def("RemovePCurve", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &) const) &ShapeBuild_Edge::RemovePCurve, "Removes the PCurve(s) which could be recorded in an Edge for the given Surface", py::arg("edge"), py::arg("surf"));
cls_ShapeBuild_Edge.def("RemovePCurve", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &ShapeBuild_Edge::RemovePCurve, "Removes the PCurve(s) which could be recorded in an Edge for the given Surface, with given Location", py::arg("edge"), py::arg("surf"), py::arg("loc"));
cls_ShapeBuild_Edge.def("ReplacePCurve", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &) const) &ShapeBuild_Edge::ReplacePCurve, "Replace the PCurve in an Edge for the given Face In case if edge is seam, i.e. has 2 pcurves on that face, only pcurve corresponding to the orientation of the edge is replaced", py::arg("edge"), py::arg("pcurve"), py::arg("face"));
cls_ShapeBuild_Edge.def("ReassignPCurve", (Standard_Boolean (ShapeBuild_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &) const) &ShapeBuild_Edge::ReassignPCurve, "Reassign edge pcurve lying on face <old> to another face . If edge has two pcurves on <old> face, only one of them will be reassigned, and other will left alone. Similarly, if edge already had a pcurve on face , it will have two pcurves on it. Returns True if succeeded, False if no pcurve lying on <old> found.", py::arg("edge"), py::arg("old"), py::arg("sub"));
cls_ShapeBuild_Edge.def("TransformPCurve", [](ShapeBuild_Edge &self, const opencascade::handle<Geom2d_Curve> & pcurve, const gp_Trsf2d & trans, const Standard_Real uFact, Standard_Real & aFirst, Standard_Real & aLast){ opencascade::handle<Geom2d_Curve> rv = self.TransformPCurve(pcurve, trans, uFact, aFirst, aLast); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &, Standard_Real &>(rv, aFirst, aLast); }, "Transforms the PCurve with given matrix and affinity U factor.", py::arg("pcurve"), py::arg("trans"), py::arg("uFact"), py::arg("aFirst"), py::arg("aLast"));
cls_ShapeBuild_Edge.def("RemoveCurve3d", (void (ShapeBuild_Edge::*)(const TopoDS_Edge &) const) &ShapeBuild_Edge::RemoveCurve3d, "Removes the Curve3D recorded in an Edge", py::arg("edge"));
cls_ShapeBuild_Edge.def("BuildCurve3d", (Standard_Boolean (ShapeBuild_Edge::*)(const TopoDS_Edge &) const) &ShapeBuild_Edge::BuildCurve3d, "Calls BRepTools::BuildCurve3D", py::arg("edge"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with curve and location", py::arg("edge"), py::arg("curve"), py::arg("L"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, const Standard_Real, const Standard_Real) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with curve, location and range [p1, p2]", py::arg("edge"), py::arg("curve"), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with pcurve and face", py::arg("edge"), py::arg("pcurve"), py::arg("face"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const Standard_Real, const Standard_Real) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with pcurve, face and range [p1, p2]", py::arg("edge"), py::arg("pcurve"), py::arg("face"), py::arg("p1"), py::arg("p2"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with pcurve, surface and location", py::arg("edge"), py::arg("pcurve"), py::arg("S"), py::arg("L"));
cls_ShapeBuild_Edge.def("MakeEdge", (void (ShapeBuild_Edge::*)(TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const Standard_Real) const) &ShapeBuild_Edge::MakeEdge, "Makes edge with pcurve, surface, location and range [p1, p2]", py::arg("edge"), py::arg("pcurve"), py::arg("S"), py::arg("L"), py::arg("p1"), py::arg("p2"));

// CLASS: SHAPEBUILD_VERTEX
py::class_<ShapeBuild_Vertex> cls_ShapeBuild_Vertex(mod, "ShapeBuild_Vertex", "Provides low-level functions used for constructing vertices");

// Methods
// cls_ShapeBuild_Vertex.def_static("operator new_", (void * (*)(size_t)) &ShapeBuild_Vertex::operator new, "None", py::arg("theSize"));
// cls_ShapeBuild_Vertex.def_static("operator delete_", (void (*)(void *)) &ShapeBuild_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &ShapeBuild_Vertex::operator new[], "None", py::arg("theSize"));
// cls_ShapeBuild_Vertex.def_static("operator delete[]_", (void (*)(void *)) &ShapeBuild_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeBuild_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &ShapeBuild_Vertex::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeBuild_Vertex.def("CombineVertex", [](ShapeBuild_Vertex &self, const TopoDS_Vertex & a0, const TopoDS_Vertex & a1) -> TopoDS_Vertex { return self.CombineVertex(a0, a1); });
cls_ShapeBuild_Vertex.def("CombineVertex", (TopoDS_Vertex (ShapeBuild_Vertex::*)(const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real) const) &ShapeBuild_Vertex::CombineVertex, "Combines new vertex from two others. This new one is the smallest vertex which comprises both of the source vertices. The function takes into account the positions and tolerances of the source vertices. The tolerance of the new vertex will be equal to the minimal tolerance that is required to comprise source vertices multiplied by tolFactor (in order to avoid errors because of discreteness of calculations).", py::arg("V1"), py::arg("V2"), py::arg("tolFactor"));
cls_ShapeBuild_Vertex.def("CombineVertex", [](ShapeBuild_Vertex &self, const gp_Pnt & a0, const gp_Pnt & a1, const Standard_Real a2, const Standard_Real a3) -> TopoDS_Vertex { return self.CombineVertex(a0, a1, a2, a3); });
cls_ShapeBuild_Vertex.def("CombineVertex", (TopoDS_Vertex (ShapeBuild_Vertex::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeBuild_Vertex::CombineVertex, "The same function as above, except that it accepts two points and two tolerances instead of vertices", py::arg("pnt1"), py::arg("pnt2"), py::arg("tol1"), py::arg("tol2"), py::arg("tolFactor"));


}
