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
#include <BRepCheck_Result.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepCheck_Status.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Wire.hxx>
#include <Standard_Type.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>

void bind_BRepCheck_Wire(py::module &mod){

py::class_<BRepCheck_Wire, opencascade::handle<BRepCheck_Wire>, BRepCheck_Result> cls_BRepCheck_Wire(mod, "BRepCheck_Wire", "None");

// Constructors
cls_BRepCheck_Wire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));

// Fields

// Methods
cls_BRepCheck_Wire.def("InContext", (void (BRepCheck_Wire::*)(const TopoDS_Shape &)) &BRepCheck_Wire::InContext, "if <ContextShape> is a face, consequently checks SelfIntersect(), Closed(), Orientation() and Closed2d until faulty is found", py::arg("ContextShape"));
cls_BRepCheck_Wire.def("Minimum", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Minimum, "checks that the wire is not empty and 'connex'. Called by constructor");
cls_BRepCheck_Wire.def("Blind", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Blind, "Does nothing");
cls_BRepCheck_Wire.def("Closed", [](BRepCheck_Wire &self) -> BRepCheck_Status { return self.Closed(); });
cls_BRepCheck_Wire.def("Closed", (BRepCheck_Status (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::Closed, "Checks if the oriented edges of the wire give a closed wire. If the wire is closed, returns BRepCheck_NoError. Warning : if the first and last edge are infinite, the wire will be considered as a closed one. If <Update> is set to Standard_True, registers the status in the list. May return (and registers): **BRepCheck_NotConnected, if wire is not topologically closed **BRepCheck_RedundantEdge, if an edge is in wire more than 3 times or in case of 2 occurences if not with FORWARD and REVERSED orientation. **BRepCheck_NoError", py::arg("Update"));
cls_BRepCheck_Wire.def("Closed2d", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Closed2d(a0); });
cls_BRepCheck_Wire.def("Closed2d", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Closed2d, "Checks if edges of the wire give a wire closed in 2d space. Returns BRepCheck_NoError, or BRepCheck_NotClosed If <Update> is set to Standard_True, registers the status in the list.", py::arg("F"), py::arg("Update"));
cls_BRepCheck_Wire.def("Orientation", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Orientation(a0); });
cls_BRepCheck_Wire.def("Orientation", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Orientation, "Checks if the oriented edges of the wire are correctly oriented. An internal call is made to the method Closed. If no face exists, call the method with a null face (TopoDS_face()). If <Update> is set to Standard_True, registers the status in the list. May return (and registers): BRepCheck_InvalidDegeneratedFlag, BRepCheck_BadOrientationOfSubshape, BRepCheck_NotClosed, BRepCheck_NoError", py::arg("F"), py::arg("Update"));
cls_BRepCheck_Wire.def("SelfIntersect", [](BRepCheck_Wire &self, const TopoDS_Face & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> BRepCheck_Status { return self.SelfIntersect(a0, a1, a2); });
cls_BRepCheck_Wire.def("SelfIntersect", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Boolean)) &BRepCheck_Wire::SelfIntersect, "Checks if the wire intersect itself on the face <F>. <E1> and <E2> are the first intersecting edges found. <E2> may be a null edge when a self-intersecting edge is found.If <Update> is set to Standard_True, registers the status in the list. May return (and register): BRepCheck_EmptyWire, BRepCheck_SelfIntersectingWire, BRepCheck_NoCurveOnSurface, BRepCheck_NoError", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("Update"));
cls_BRepCheck_Wire.def("GeometricControls", (Standard_Boolean (BRepCheck_Wire::*)() const) &BRepCheck_Wire::GeometricControls, "report SelfIntersect() check would be (is) done");
cls_BRepCheck_Wire.def("GeometricControls", (void (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::GeometricControls, "set SelfIntersect() to be checked", py::arg("B"));
cls_BRepCheck_Wire.def("SetStatus", (void (BRepCheck_Wire::*)(const BRepCheck_Status)) &BRepCheck_Wire::SetStatus, "Sets status of Wire;", py::arg("theStatus"));
cls_BRepCheck_Wire.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Wire::get_type_name, "None");
cls_BRepCheck_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Wire::get_type_descriptor, "None");
cls_BRepCheck_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Wire::*)() const) &BRepCheck_Wire::DynamicType, "None");

// Enums

}