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
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepAP214_HArray1OfSecurityClassificationItem.hxx>
#include <StepAP214_SecurityClassificationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedSecurityClassificationAssignment(py::module &mod){

py::class_<StepAP214_AppliedSecurityClassificationAssignment, opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment>, StepBasic_SecurityClassificationAssignment> cls_StepAP214_AppliedSecurityClassificationAssignment(mod, "StepAP214_AppliedSecurityClassificationAssignment", "None");

// Constructors
cls_StepAP214_AppliedSecurityClassificationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedSecurityClassificationAssignment.def("Init", (void (StepAP214_AppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &, const opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> &)) &StepAP214_AppliedSecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"), py::arg("aItems"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("SetItems", (void (StepAP214_AppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> &)) &StepAP214_AppliedSecurityClassificationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::Items, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def("ItemsValue", (const StepAP214_SecurityClassificationItem & (StepAP214_AppliedSecurityClassificationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedSecurityClassificationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::NbItems, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedSecurityClassificationAssignment::get_type_name, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedSecurityClassificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::DynamicType, "None");

// Enums

}