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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_LeaderArrow(py::module &mod){

py::class_<IGESDimen_LeaderArrow, opencascade::handle<IGESDimen_LeaderArrow>, IGESData_IGESEntity> cls_IGESDimen_LeaderArrow(mod, "IGESDimen_LeaderArrow", "defines LeaderArrow, Type <214> Form <1-12> in package IGESDimen Consists of one or more line segments except when leader is part of an angular dimension, with links to presumed text item");

// Constructors
cls_IGESDimen_LeaderArrow.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_LeaderArrow.def("Init", (void (IGESDimen_LeaderArrow::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_XY &, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_LeaderArrow::Init, "This method is used to set the fields of the class LeaderArrow - height : ArrowHead height - width : ArrowHead width - depth : Z Depth - position : ArrowHead coordinates - segments : Segment tail coordinate pairs", py::arg("height"), py::arg("width"), py::arg("depth"), py::arg("position"), py::arg("segments"));
cls_IGESDimen_LeaderArrow.def("SetFormNumber", (void (IGESDimen_LeaderArrow::*)(const Standard_Integer)) &IGESDimen_LeaderArrow::SetFormNumber, "Changes FormNumber (indicates the Shape of the Arrow) Error if not in range [0-12]", py::arg("form"));
cls_IGESDimen_LeaderArrow.def("NbSegments", (Standard_Integer (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::NbSegments, "returns number of segments");
cls_IGESDimen_LeaderArrow.def("ArrowHeadHeight", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHeadHeight, "returns ArrowHead height");
cls_IGESDimen_LeaderArrow.def("ArrowHeadWidth", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHeadWidth, "returns ArrowHead width");
cls_IGESDimen_LeaderArrow.def("ZDepth", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ZDepth, "returns Z depth");
cls_IGESDimen_LeaderArrow.def("ArrowHead", (gp_Pnt2d (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHead, "returns ArrowHead co-ordinates");
cls_IGESDimen_LeaderArrow.def("TransformedArrowHead", (gp_Pnt (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::TransformedArrowHead, "returns ArrowHead co-ordinates after Transformation");
cls_IGESDimen_LeaderArrow.def("SegmentTail", (gp_Pnt2d (IGESDimen_LeaderArrow::*)(const Standard_Integer) const) &IGESDimen_LeaderArrow::SegmentTail, "returns segment tail co-ordinates. raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
cls_IGESDimen_LeaderArrow.def("TransformedSegmentTail", (gp_Pnt (IGESDimen_LeaderArrow::*)(const Standard_Integer) const) &IGESDimen_LeaderArrow::TransformedSegmentTail, "returns segment tail co-ordinates after Transformation. raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
cls_IGESDimen_LeaderArrow.def_static("get_type_name_", (const char * (*)()) &IGESDimen_LeaderArrow::get_type_name, "None");
cls_IGESDimen_LeaderArrow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_LeaderArrow::get_type_descriptor, "None");
cls_IGESDimen_LeaderArrow.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::DynamicType, "None");

// Enums

}