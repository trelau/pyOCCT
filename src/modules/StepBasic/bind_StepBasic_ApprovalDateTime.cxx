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
#include <StepBasic_DateTimeSelect.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Approval.hxx>
#include <StepBasic_ApprovalDateTime.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ApprovalDateTime(py::module &mod){

py::class_<StepBasic_ApprovalDateTime, opencascade::handle<StepBasic_ApprovalDateTime>, Standard_Transient> cls_StepBasic_ApprovalDateTime(mod, "StepBasic_ApprovalDateTime", "Added from StepBasic Rev2 to Rev4");

// Constructors
cls_StepBasic_ApprovalDateTime.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ApprovalDateTime.def("Init", (void (StepBasic_ApprovalDateTime::*)(const StepBasic_DateTimeSelect &, const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalDateTime::Init, "None", py::arg("aDateTime"), py::arg("aDatedApproval"));
cls_StepBasic_ApprovalDateTime.def("SetDateTime", (void (StepBasic_ApprovalDateTime::*)(const StepBasic_DateTimeSelect &)) &StepBasic_ApprovalDateTime::SetDateTime, "None", py::arg("aDateTime"));
cls_StepBasic_ApprovalDateTime.def("DateTime", (StepBasic_DateTimeSelect (StepBasic_ApprovalDateTime::*)() const) &StepBasic_ApprovalDateTime::DateTime, "None");
cls_StepBasic_ApprovalDateTime.def("SetDatedApproval", (void (StepBasic_ApprovalDateTime::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalDateTime::SetDatedApproval, "None", py::arg("aDatedApproval"));
cls_StepBasic_ApprovalDateTime.def("DatedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalDateTime::*)() const) &StepBasic_ApprovalDateTime::DatedApproval, "None");
cls_StepBasic_ApprovalDateTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalDateTime::get_type_name, "None");
cls_StepBasic_ApprovalDateTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalDateTime::get_type_descriptor, "None");
cls_StepBasic_ApprovalDateTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalDateTime::*)() const) &StepBasic_ApprovalDateTime::DynamicType, "None");

// Enums

}