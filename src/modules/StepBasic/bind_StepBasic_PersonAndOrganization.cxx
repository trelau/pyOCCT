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
#include <StepBasic_Person.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_PersonAndOrganization(py::module &mod){

py::class_<StepBasic_PersonAndOrganization, opencascade::handle<StepBasic_PersonAndOrganization>, Standard_Transient> cls_StepBasic_PersonAndOrganization(mod, "StepBasic_PersonAndOrganization", "None");

// Constructors
cls_StepBasic_PersonAndOrganization.def(py::init<>());

// Fields

// Methods
cls_StepBasic_PersonAndOrganization.def("Init", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Person> &, const opencascade::handle<StepBasic_Organization> &)) &StepBasic_PersonAndOrganization::Init, "None", py::arg("aThePerson"), py::arg("aTheOrganization"));
cls_StepBasic_PersonAndOrganization.def("SetThePerson", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Person> &)) &StepBasic_PersonAndOrganization::SetThePerson, "None", py::arg("aThePerson"));
cls_StepBasic_PersonAndOrganization.def("ThePerson", (opencascade::handle<StepBasic_Person> (StepBasic_PersonAndOrganization::*)() const) &StepBasic_PersonAndOrganization::ThePerson, "None");
cls_StepBasic_PersonAndOrganization.def("SetTheOrganization", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Organization> &)) &StepBasic_PersonAndOrganization::SetTheOrganization, "None", py::arg("aTheOrganization"));
cls_StepBasic_PersonAndOrganization.def("TheOrganization", (opencascade::handle<StepBasic_Organization> (StepBasic_PersonAndOrganization::*)() const) &StepBasic_PersonAndOrganization::TheOrganization, "None");
cls_StepBasic_PersonAndOrganization.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonAndOrganization::get_type_name, "None");
cls_StepBasic_PersonAndOrganization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonAndOrganization::get_type_descriptor, "None");
cls_StepBasic_PersonAndOrganization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonAndOrganization::*)() const) &StepBasic_PersonAndOrganization::DynamicType, "None");

// Enums

}