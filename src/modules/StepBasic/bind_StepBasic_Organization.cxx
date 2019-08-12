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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_Organization.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Organization(py::module &mod){

py::class_<StepBasic_Organization, opencascade::handle<StepBasic_Organization>, Standard_Transient> cls_StepBasic_Organization(mod, "StepBasic_Organization", "None");

// Constructors
cls_StepBasic_Organization.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Organization.def("Init", (void (StepBasic_Organization::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::Init, "None", py::arg("hasAid"), py::arg("aId"), py::arg("aName"), py::arg("aDescription"));
cls_StepBasic_Organization.def("SetId", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetId, "None", py::arg("aId"));
cls_StepBasic_Organization.def("UnSetId", (void (StepBasic_Organization::*)()) &StepBasic_Organization::UnSetId, "None");
cls_StepBasic_Organization.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const) &StepBasic_Organization::Id, "None");
cls_StepBasic_Organization.def("HasId", (Standard_Boolean (StepBasic_Organization::*)() const) &StepBasic_Organization::HasId, "None");
cls_StepBasic_Organization.def("SetName", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetName, "None", py::arg("aName"));
cls_StepBasic_Organization.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const) &StepBasic_Organization::Name, "None");
cls_StepBasic_Organization.def("SetDescription", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_Organization.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const) &StepBasic_Organization::Description, "None");
cls_StepBasic_Organization.def_static("get_type_name_", (const char * (*)()) &StepBasic_Organization::get_type_name, "None");
cls_StepBasic_Organization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Organization::get_type_descriptor, "None");
cls_StepBasic_Organization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Organization::*)() const) &StepBasic_Organization::DynamicType, "None");

// Enums

}