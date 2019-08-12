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
#include <StepBasic_PersonOrganizationSelect.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Approval.hxx>
#include <StepBasic_ApprovalRole.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ApprovalPersonOrganization(py::module &mod){

py::class_<StepBasic_ApprovalPersonOrganization, opencascade::handle<StepBasic_ApprovalPersonOrganization>, Standard_Transient> cls_StepBasic_ApprovalPersonOrganization(mod, "StepBasic_ApprovalPersonOrganization", "None");

// Constructors
cls_StepBasic_ApprovalPersonOrganization.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ApprovalPersonOrganization.def("Init", (void (StepBasic_ApprovalPersonOrganization::*)(const StepBasic_PersonOrganizationSelect &, const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepBasic_ApprovalRole> &)) &StepBasic_ApprovalPersonOrganization::Init, "None", py::arg("aPersonOrganization"), py::arg("aAuthorizedApproval"), py::arg("aRole"));
cls_StepBasic_ApprovalPersonOrganization.def("SetPersonOrganization", (void (StepBasic_ApprovalPersonOrganization::*)(const StepBasic_PersonOrganizationSelect &)) &StepBasic_ApprovalPersonOrganization::SetPersonOrganization, "None", py::arg("aPersonOrganization"));
cls_StepBasic_ApprovalPersonOrganization.def("PersonOrganization", (StepBasic_PersonOrganizationSelect (StepBasic_ApprovalPersonOrganization::*)() const) &StepBasic_ApprovalPersonOrganization::PersonOrganization, "None");
cls_StepBasic_ApprovalPersonOrganization.def("SetAuthorizedApproval", (void (StepBasic_ApprovalPersonOrganization::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalPersonOrganization::SetAuthorizedApproval, "None", py::arg("aAuthorizedApproval"));
cls_StepBasic_ApprovalPersonOrganization.def("AuthorizedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalPersonOrganization::*)() const) &StepBasic_ApprovalPersonOrganization::AuthorizedApproval, "None");
cls_StepBasic_ApprovalPersonOrganization.def("SetRole", (void (StepBasic_ApprovalPersonOrganization::*)(const opencascade::handle<StepBasic_ApprovalRole> &)) &StepBasic_ApprovalPersonOrganization::SetRole, "None", py::arg("aRole"));
cls_StepBasic_ApprovalPersonOrganization.def("Role", (opencascade::handle<StepBasic_ApprovalRole> (StepBasic_ApprovalPersonOrganization::*)() const) &StepBasic_ApprovalPersonOrganization::Role, "None");
cls_StepBasic_ApprovalPersonOrganization.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalPersonOrganization::get_type_name, "None");
cls_StepBasic_ApprovalPersonOrganization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalPersonOrganization::get_type_descriptor, "None");
cls_StepBasic_ApprovalPersonOrganization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalPersonOrganization::*)() const) &StepBasic_ApprovalPersonOrganization::DynamicType, "None");

// Enums

}