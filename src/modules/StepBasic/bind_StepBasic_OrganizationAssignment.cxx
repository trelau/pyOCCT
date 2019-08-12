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
#include <StepBasic_Organization.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <StepBasic_OrganizationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_OrganizationAssignment(py::module &mod){

py::class_<StepBasic_OrganizationAssignment, opencascade::handle<StepBasic_OrganizationAssignment>, Standard_Transient> cls_StepBasic_OrganizationAssignment(mod, "StepBasic_OrganizationAssignment", "None");

// Constructors

// Fields

// Methods
cls_StepBasic_OrganizationAssignment.def("Init", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &, const opencascade::handle<StepBasic_OrganizationRole> &)) &StepBasic_OrganizationAssignment::Init, "None", py::arg("aAssignedOrganization"), py::arg("aRole"));
cls_StepBasic_OrganizationAssignment.def("SetAssignedOrganization", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &)) &StepBasic_OrganizationAssignment::SetAssignedOrganization, "None", py::arg("aAssignedOrganization"));
cls_StepBasic_OrganizationAssignment.def("AssignedOrganization", (opencascade::handle<StepBasic_Organization> (StepBasic_OrganizationAssignment::*)() const) &StepBasic_OrganizationAssignment::AssignedOrganization, "None");
cls_StepBasic_OrganizationAssignment.def("SetRole", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_OrganizationRole> &)) &StepBasic_OrganizationAssignment::SetRole, "None", py::arg("aRole"));
cls_StepBasic_OrganizationAssignment.def("Role", (opencascade::handle<StepBasic_OrganizationRole> (StepBasic_OrganizationAssignment::*)() const) &StepBasic_OrganizationAssignment::Role, "None");
cls_StepBasic_OrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationAssignment::get_type_name, "None");
cls_StepBasic_OrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationAssignment::get_type_descriptor, "None");
cls_StepBasic_OrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationAssignment::*)() const) &StepBasic_OrganizationAssignment::DynamicType, "None");

// Enums

}