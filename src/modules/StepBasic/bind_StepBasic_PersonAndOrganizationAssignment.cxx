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
#include <Standard_Handle.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepBasic_PersonAndOrganizationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_PersonAndOrganizationAssignment(py::module &mod){

py::class_<StepBasic_PersonAndOrganizationAssignment, opencascade::handle<StepBasic_PersonAndOrganizationAssignment>, Standard_Transient> cls_StepBasic_PersonAndOrganizationAssignment(mod, "StepBasic_PersonAndOrganizationAssignment", "None");

// Constructors

// Fields

// Methods
cls_StepBasic_PersonAndOrganizationAssignment.def("Init", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &)) &StepBasic_PersonAndOrganizationAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"));
cls_StepBasic_PersonAndOrganizationAssignment.def("SetAssignedPersonAndOrganization", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &)) &StepBasic_PersonAndOrganizationAssignment::SetAssignedPersonAndOrganization, "None", py::arg("aAssignedPersonAndOrganization"));
cls_StepBasic_PersonAndOrganizationAssignment.def("AssignedPersonAndOrganization", (opencascade::handle<StepBasic_PersonAndOrganization> (StepBasic_PersonAndOrganizationAssignment::*)() const) &StepBasic_PersonAndOrganizationAssignment::AssignedPersonAndOrganization, "None");
cls_StepBasic_PersonAndOrganizationAssignment.def("SetRole", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganizationRole> &)) &StepBasic_PersonAndOrganizationAssignment::SetRole, "None", py::arg("aRole"));
cls_StepBasic_PersonAndOrganizationAssignment.def("Role", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (StepBasic_PersonAndOrganizationAssignment::*)() const) &StepBasic_PersonAndOrganizationAssignment::Role, "None");
cls_StepBasic_PersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonAndOrganizationAssignment::get_type_name, "None");
cls_StepBasic_PersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonAndOrganizationAssignment::get_type_descriptor, "None");
cls_StepBasic_PersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonAndOrganizationAssignment::*)() const) &StepBasic_PersonAndOrganizationAssignment::DynamicType, "None");

// Enums

}