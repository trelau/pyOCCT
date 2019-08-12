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
#include <StepVisual_TextStyleForDefinedFont.hxx>
#include <StepVisual_TextStyle.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_TextStyle(py::module &mod){

py::class_<StepVisual_TextStyle, opencascade::handle<StepVisual_TextStyle>, Standard_Transient> cls_StepVisual_TextStyle(mod, "StepVisual_TextStyle", "None");

// Constructors
cls_StepVisual_TextStyle.def(py::init<>());

// Fields

// Methods
cls_StepVisual_TextStyle.def("Init", (void (StepVisual_TextStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &)) &StepVisual_TextStyle::Init, "None", py::arg("aName"), py::arg("aCharacterAppearance"));
cls_StepVisual_TextStyle.def("SetName", (void (StepVisual_TextStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextStyle::SetName, "None", py::arg("aName"));
cls_StepVisual_TextStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextStyle::*)() const) &StepVisual_TextStyle::Name, "None");
cls_StepVisual_TextStyle.def("SetCharacterAppearance", (void (StepVisual_TextStyle::*)(const opencascade::handle<StepVisual_TextStyleForDefinedFont> &)) &StepVisual_TextStyle::SetCharacterAppearance, "None", py::arg("aCharacterAppearance"));
cls_StepVisual_TextStyle.def("CharacterAppearance", (opencascade::handle<StepVisual_TextStyleForDefinedFont> (StepVisual_TextStyle::*)() const) &StepVisual_TextStyle::CharacterAppearance, "None");
cls_StepVisual_TextStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextStyle::get_type_name, "None");
cls_StepVisual_TextStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextStyle::get_type_descriptor, "None");
cls_StepVisual_TextStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextStyle::*)() const) &StepVisual_TextStyle::DynamicType, "None");

// Enums

}