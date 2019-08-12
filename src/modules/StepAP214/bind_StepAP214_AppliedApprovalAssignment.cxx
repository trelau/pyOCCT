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
#include <StepBasic_ApprovalAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Approval.hxx>
#include <StepAP214_HArray1OfApprovalItem.hxx>
#include <StepAP214_ApprovalItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedApprovalAssignment(py::module &mod){

py::class_<StepAP214_AppliedApprovalAssignment, opencascade::handle<StepAP214_AppliedApprovalAssignment>, StepBasic_ApprovalAssignment> cls_StepAP214_AppliedApprovalAssignment(mod, "StepAP214_AppliedApprovalAssignment", "None");

// Constructors
cls_StepAP214_AppliedApprovalAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedApprovalAssignment.def("Init", (void (StepAP214_AppliedApprovalAssignment::*)(const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepAP214_HArray1OfApprovalItem> &)) &StepAP214_AppliedApprovalAssignment::Init, "None", py::arg("aAssignedApproval"), py::arg("aItems"));
cls_StepAP214_AppliedApprovalAssignment.def("SetItems", (void (StepAP214_AppliedApprovalAssignment::*)(const opencascade::handle<StepAP214_HArray1OfApprovalItem> &)) &StepAP214_AppliedApprovalAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedApprovalAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfApprovalItem> (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::Items, "None");
cls_StepAP214_AppliedApprovalAssignment.def("ItemsValue", (StepAP214_ApprovalItem (StepAP214_AppliedApprovalAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedApprovalAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedApprovalAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::NbItems, "None");
cls_StepAP214_AppliedApprovalAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedApprovalAssignment::get_type_name, "None");
cls_StepAP214_AppliedApprovalAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedApprovalAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedApprovalAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::DynamicType, "None");

// Enums

}