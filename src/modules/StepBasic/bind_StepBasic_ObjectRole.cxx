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
#include <StepBasic_ObjectRole.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ObjectRole(py::module &mod){

py::class_<StepBasic_ObjectRole, opencascade::handle<StepBasic_ObjectRole>, Standard_Transient> cls_StepBasic_ObjectRole(mod, "StepBasic_ObjectRole", "Representation of STEP entity ObjectRole");

// Constructors
cls_StepBasic_ObjectRole.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ObjectRole.def("Init", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
cls_StepBasic_ObjectRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ObjectRole::*)() const) &StepBasic_ObjectRole::Name, "Returns field Name");
cls_StepBasic_ObjectRole.def("SetName", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_ObjectRole.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ObjectRole::*)() const) &StepBasic_ObjectRole::Description, "Returns field Description");
cls_StepBasic_ObjectRole.def("SetDescription", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_ObjectRole.def("HasDescription", (Standard_Boolean (StepBasic_ObjectRole::*)() const) &StepBasic_ObjectRole::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_ObjectRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_ObjectRole::get_type_name, "None");
cls_StepBasic_ObjectRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ObjectRole::get_type_descriptor, "None");
cls_StepBasic_ObjectRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ObjectRole::*)() const) &StepBasic_ObjectRole::DynamicType, "None");

// Enums

}