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
#include <StepBasic_ObjectRole.hxx>
#include <StepBasic_RoleSelect.hxx>
#include <StepBasic_RoleAssociation.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_RoleAssociation(py::module &mod){

py::class_<StepBasic_RoleAssociation, opencascade::handle<StepBasic_RoleAssociation>, Standard_Transient> cls_StepBasic_RoleAssociation(mod, "StepBasic_RoleAssociation", "Representation of STEP entity RoleAssociation");

// Constructors
cls_StepBasic_RoleAssociation.def(py::init<>());

// Fields

// Methods
cls_StepBasic_RoleAssociation.def("Init", (void (StepBasic_RoleAssociation::*)(const opencascade::handle<StepBasic_ObjectRole> &, const StepBasic_RoleSelect &)) &StepBasic_RoleAssociation::Init, "Initialize all fields (own and inherited)", py::arg("aRole"), py::arg("aItemWithRole"));
cls_StepBasic_RoleAssociation.def("Role", (opencascade::handle<StepBasic_ObjectRole> (StepBasic_RoleAssociation::*)() const) &StepBasic_RoleAssociation::Role, "Returns field Role");
cls_StepBasic_RoleAssociation.def("SetRole", (void (StepBasic_RoleAssociation::*)(const opencascade::handle<StepBasic_ObjectRole> &)) &StepBasic_RoleAssociation::SetRole, "Set field Role", py::arg("Role"));
cls_StepBasic_RoleAssociation.def("ItemWithRole", (StepBasic_RoleSelect (StepBasic_RoleAssociation::*)() const) &StepBasic_RoleAssociation::ItemWithRole, "Returns field ItemWithRole");
cls_StepBasic_RoleAssociation.def("SetItemWithRole", (void (StepBasic_RoleAssociation::*)(const StepBasic_RoleSelect &)) &StepBasic_RoleAssociation::SetItemWithRole, "Set field ItemWithRole", py::arg("ItemWithRole"));
cls_StepBasic_RoleAssociation.def_static("get_type_name_", (const char * (*)()) &StepBasic_RoleAssociation::get_type_name, "None");
cls_StepBasic_RoleAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_RoleAssociation::get_type_descriptor, "None");
cls_StepBasic_RoleAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_RoleAssociation::*)() const) &StepBasic_RoleAssociation::DynamicType, "None");

// Enums

}