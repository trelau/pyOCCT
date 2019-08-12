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
#include <StepBasic_DateAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Date.hxx>
#include <StepBasic_DateRole.hxx>
#include <StepAP214_HArray1OfDateItem.hxx>
#include <StepAP214_DateItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedDateAssignment(py::module &mod){

py::class_<StepAP214_AppliedDateAssignment, opencascade::handle<StepAP214_AppliedDateAssignment>, StepBasic_DateAssignment> cls_StepAP214_AppliedDateAssignment(mod, "StepAP214_AppliedDateAssignment", "None");

// Constructors
cls_StepAP214_AppliedDateAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedDateAssignment.def("Init", (void (StepAP214_AppliedDateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &, const opencascade::handle<StepAP214_HArray1OfDateItem> &)) &StepAP214_AppliedDateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedDateAssignment.def("SetItems", (void (StepAP214_AppliedDateAssignment::*)(const opencascade::handle<StepAP214_HArray1OfDateItem> &)) &StepAP214_AppliedDateAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedDateAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfDateItem> (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::Items, "None");
cls_StepAP214_AppliedDateAssignment.def("ItemsValue", (StepAP214_DateItem (StepAP214_AppliedDateAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedDateAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedDateAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::NbItems, "None");
cls_StepAP214_AppliedDateAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedDateAssignment::get_type_name, "None");
cls_StepAP214_AppliedDateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedDateAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedDateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::DynamicType, "None");

// Enums

}