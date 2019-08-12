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
#include <StepRepr_CharacterizedDefinition.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_MaterialDesignation(py::module &mod){

py::class_<StepRepr_MaterialDesignation, opencascade::handle<StepRepr_MaterialDesignation>, Standard_Transient> cls_StepRepr_MaterialDesignation(mod, "StepRepr_MaterialDesignation", "None");

// Constructors
cls_StepRepr_MaterialDesignation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_MaterialDesignation.def("Init", (void (StepRepr_MaterialDesignation::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepRepr_CharacterizedDefinition &)) &StepRepr_MaterialDesignation::Init, "None", py::arg("aName"), py::arg("aOfDefinition"));
cls_StepRepr_MaterialDesignation.def("SetName", (void (StepRepr_MaterialDesignation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_MaterialDesignation::SetName, "None", py::arg("aName"));
cls_StepRepr_MaterialDesignation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::Name, "None");
cls_StepRepr_MaterialDesignation.def("SetOfDefinition", (void (StepRepr_MaterialDesignation::*)(const StepRepr_CharacterizedDefinition &)) &StepRepr_MaterialDesignation::SetOfDefinition, "None", py::arg("aOfDefinition"));
cls_StepRepr_MaterialDesignation.def("OfDefinition", (StepRepr_CharacterizedDefinition (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::OfDefinition, "None");
cls_StepRepr_MaterialDesignation.def_static("get_type_name_", (const char * (*)()) &StepRepr_MaterialDesignation::get_type_name, "None");
cls_StepRepr_MaterialDesignation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MaterialDesignation::get_type_descriptor, "None");
cls_StepRepr_MaterialDesignation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::DynamicType, "None");

// Enums

}