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
#include <Standard_TypeDef.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_IdentificationRole(py::module &mod){

py::class_<StepBasic_IdentificationRole, opencascade::handle<StepBasic_IdentificationRole>, Standard_Transient> cls_StepBasic_IdentificationRole(mod, "StepBasic_IdentificationRole", "Representation of STEP entity IdentificationRole");

// Constructors
cls_StepBasic_IdentificationRole.def(py::init<>());

// Fields

// Methods
cls_StepBasic_IdentificationRole.def("Init", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
cls_StepBasic_IdentificationRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_IdentificationRole::*)() const) &StepBasic_IdentificationRole::Name, "Returns field Name");
cls_StepBasic_IdentificationRole.def("SetName", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_IdentificationRole.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_IdentificationRole::*)() const) &StepBasic_IdentificationRole::Description, "Returns field Description");
cls_StepBasic_IdentificationRole.def("SetDescription", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_IdentificationRole.def("HasDescription", (Standard_Boolean (StepBasic_IdentificationRole::*)() const) &StepBasic_IdentificationRole::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_IdentificationRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_IdentificationRole::get_type_name, "None");
cls_StepBasic_IdentificationRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_IdentificationRole::get_type_descriptor, "None");
cls_StepBasic_IdentificationRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_IdentificationRole::*)() const) &StepBasic_IdentificationRole::DynamicType, "None");

// Enums

}