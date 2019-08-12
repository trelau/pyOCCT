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
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepCheck_ListOfStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Result.hxx>
#include <Standard_Type.hxx>
#include <BRepCheck_DataMapOfShapeListOfStatus.hxx>

void bind_BRepCheck_Result(py::module &mod){

py::class_<BRepCheck_Result, opencascade::handle<BRepCheck_Result>, Standard_Transient> cls_BRepCheck_Result(mod, "BRepCheck_Result", "None");

// Fields

// Methods
cls_BRepCheck_Result.def("Init", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::Init, "None", py::arg("S"));
cls_BRepCheck_Result.def("InContext", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Result.def("Minimum", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Minimum, "None");
cls_BRepCheck_Result.def("Blind", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Blind, "None");
cls_BRepCheck_Result.def("SetFailStatus", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::SetFailStatus, "None", py::arg("S"));
cls_BRepCheck_Result.def("Status", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const) &BRepCheck_Result::Status, "None");
cls_BRepCheck_Result.def("IsMinimum", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::IsMinimum, "None");
cls_BRepCheck_Result.def("IsBlind", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::IsBlind, "None");
cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::StatusOnShape, "If not already done, performs the InContext control and returns the list of status.", py::arg("S"));
cls_BRepCheck_Result.def("InitContextIterator", (void (BRepCheck_Result::*)()) &BRepCheck_Result::InitContextIterator, "None");
cls_BRepCheck_Result.def("MoreShapeInContext", (Standard_Boolean (BRepCheck_Result::*)() const) &BRepCheck_Result::MoreShapeInContext, "None");
cls_BRepCheck_Result.def("ContextualShape", (const TopoDS_Shape & (BRepCheck_Result::*)() const) &BRepCheck_Result::ContextualShape, "None");
cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const) &BRepCheck_Result::StatusOnShape, "None");
cls_BRepCheck_Result.def("NextShapeInContext", (void (BRepCheck_Result::*)()) &BRepCheck_Result::NextShapeInContext, "None");
cls_BRepCheck_Result.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Result::get_type_name, "None");
cls_BRepCheck_Result.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Result::get_type_descriptor, "None");
cls_BRepCheck_Result.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Result::*)() const) &BRepCheck_Result::DynamicType, "None");

// Enums

}