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
#include <StepBasic_DateTimeRole.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DateTimeRole(py::module &mod){

py::class_<StepBasic_DateTimeRole, opencascade::handle<StepBasic_DateTimeRole>, Standard_Transient> cls_StepBasic_DateTimeRole(mod, "StepBasic_DateTimeRole", "None");

// Constructors
cls_StepBasic_DateTimeRole.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DateTimeRole.def("Init", (void (StepBasic_DateTimeRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateTimeRole::Init, "None", py::arg("aName"));
cls_StepBasic_DateTimeRole.def("SetName", (void (StepBasic_DateTimeRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateTimeRole::SetName, "None", py::arg("aName"));
cls_StepBasic_DateTimeRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DateTimeRole::*)() const) &StepBasic_DateTimeRole::Name, "None");
cls_StepBasic_DateTimeRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateTimeRole::get_type_name, "None");
cls_StepBasic_DateTimeRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateTimeRole::get_type_descriptor, "None");
cls_StepBasic_DateTimeRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateTimeRole::*)() const) &StepBasic_DateTimeRole::DynamicType, "None");

// Enums

}