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
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_OrganizationRole(py::module &mod){

py::class_<StepBasic_OrganizationRole, opencascade::handle<StepBasic_OrganizationRole>, Standard_Transient> cls_StepBasic_OrganizationRole(mod, "StepBasic_OrganizationRole", "None");

// Constructors
cls_StepBasic_OrganizationRole.def(py::init<>());

// Fields

// Methods
cls_StepBasic_OrganizationRole.def("Init", (void (StepBasic_OrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationRole::Init, "None", py::arg("aName"));
cls_StepBasic_OrganizationRole.def("SetName", (void (StepBasic_OrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationRole::SetName, "None", py::arg("aName"));
cls_StepBasic_OrganizationRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_OrganizationRole::*)() const) &StepBasic_OrganizationRole::Name, "None");
cls_StepBasic_OrganizationRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationRole::get_type_name, "None");
cls_StepBasic_OrganizationRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationRole::get_type_descriptor, "None");
cls_StepBasic_OrganizationRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationRole::*)() const) &StepBasic_OrganizationRole::DynamicType, "None");

// Enums

}