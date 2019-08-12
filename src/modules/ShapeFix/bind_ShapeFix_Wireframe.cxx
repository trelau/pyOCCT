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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Handle.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Wireframe(py::module &mod){

py::class_<ShapeFix_Wireframe, opencascade::handle<ShapeFix_Wireframe>, ShapeFix_Root> cls_ShapeFix_Wireframe(mod, "ShapeFix_Wireframe", "Provides methods for fixing wireframe of shape");

// Constructors
cls_ShapeFix_Wireframe.def(py::init<>());
cls_ShapeFix_Wireframe.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));

// Fields

// Methods
cls_ShapeFix_Wireframe.def("ClearStatuses", (void (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::ClearStatuses, "Clears all statuses");
cls_ShapeFix_Wireframe.def("Load", (void (ShapeFix_Wireframe::*)(const TopoDS_Shape &)) &ShapeFix_Wireframe::Load, "Loads a shape, resets statuses", py::arg("shape"));
cls_ShapeFix_Wireframe.def("FixWireGaps", (Standard_Boolean (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::FixWireGaps, "Fixes gaps between ends of curves of adjacent edges (both 3d and pcurves) in wires If precision is 0.0, uses Precision::Confusion().");
cls_ShapeFix_Wireframe.def("FixSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::FixSmallEdges, "Fixes small edges in shape by merging adjacent edges If precision is 0.0, uses Precision::Confusion().");
cls_ShapeFix_Wireframe.def("CheckSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(TopTools_MapOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_MapOfShape &)) &ShapeFix_Wireframe::CheckSmallEdges, "Auxiliary tool for FixSmallEdges which checks for small edges and fills the maps. Returns True if at least one small edge has been found.", py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"));
cls_ShapeFix_Wireframe.def("MergeSmallEdges", [](ShapeFix_Wireframe &self, TopTools_MapOfShape & a0, TopTools_DataMapOfShapeListOfShape & a1, TopTools_DataMapOfShapeListOfShape & a2, TopTools_MapOfShape & a3) -> Standard_Boolean { return self.MergeSmallEdges(a0, a1, a2, a3); });
cls_ShapeFix_Wireframe.def("MergeSmallEdges", [](ShapeFix_Wireframe &self, TopTools_MapOfShape & a0, TopTools_DataMapOfShapeListOfShape & a1, TopTools_DataMapOfShapeListOfShape & a2, TopTools_MapOfShape & a3, const Standard_Boolean a4) -> Standard_Boolean { return self.MergeSmallEdges(a0, a1, a2, a3, a4); });
cls_ShapeFix_Wireframe.def("MergeSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(TopTools_MapOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_DataMapOfShapeListOfShape &, TopTools_MapOfShape &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Wireframe::MergeSmallEdges, "Auxiliary tool for FixSmallEdges which merges small edges. If theModeDrop is equal to Standard_True then small edges, which cannot be connected with adjacent edges are dropped. Otherwise they are kept. theLimitAngle specifies maximum allowed tangency discontinuity between adjacent edges. If theLimitAngle is equal to -1, this angle is not taken into account.", py::arg("theSmallEdges"), py::arg("theEdgeToFaces"), py::arg("theFaceWithSmall"), py::arg("theMultyEdges"), py::arg("theModeDrop"), py::arg("theLimitAngle"));
cls_ShapeFix_Wireframe.def("StatusWireGaps", (Standard_Boolean (ShapeFix_Wireframe::*)(const ShapeExtend_Status) const) &ShapeFix_Wireframe::StatusWireGaps, "Decodes the status of the last FixWireGaps. OK - No gaps were found DONE1 - Some gaps in 3D were fixed DONE2 - Some gaps in 2D were fixed FAIL1 - Failed to fix some gaps in 3D FAIL2 - Failed to fix some gaps in 2D", py::arg("status"));
cls_ShapeFix_Wireframe.def("StatusSmallEdges", (Standard_Boolean (ShapeFix_Wireframe::*)(const ShapeExtend_Status) const) &ShapeFix_Wireframe::StatusSmallEdges, "Decodes the status of the last FixSmallEdges. OK - No small edges were found DONE1 - Some small edges were fixed FAIL1 - Failed to fix some small edges", py::arg("status"));
cls_ShapeFix_Wireframe.def("Shape", (TopoDS_Shape (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::Shape, "None");
cls_ShapeFix_Wireframe.def("ModeDropSmallEdges", (Standard_Boolean & (ShapeFix_Wireframe::*)()) &ShapeFix_Wireframe::ModeDropSmallEdges, "Returns mode managing removing small edges.");
cls_ShapeFix_Wireframe.def("SetLimitAngle", (void (ShapeFix_Wireframe::*)(const Standard_Real)) &ShapeFix_Wireframe::SetLimitAngle, "Set limit angle for merging edges.", py::arg("theLimitAngle"));
cls_ShapeFix_Wireframe.def("LimitAngle", (Standard_Real (ShapeFix_Wireframe::*)() const) &ShapeFix_Wireframe::LimitAngle, "Get limit angle for merging edges.");
cls_ShapeFix_Wireframe.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Wireframe::get_type_name, "None");
cls_ShapeFix_Wireframe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Wireframe::get_type_descriptor, "None");
cls_ShapeFix_Wireframe.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Wireframe::*)() const) &ShapeFix_Wireframe::DynamicType, "None");

// Enums

}