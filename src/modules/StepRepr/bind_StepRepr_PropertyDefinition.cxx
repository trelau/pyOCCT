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
#include <StepRepr_CharacterizedDefinition.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_PropertyDefinition(py::module &mod){

py::class_<StepRepr_PropertyDefinition, opencascade::handle<StepRepr_PropertyDefinition>, Standard_Transient> cls_StepRepr_PropertyDefinition(mod, "StepRepr_PropertyDefinition", "Representation of STEP entity PropertyDefinition");

// Constructors
cls_StepRepr_PropertyDefinition.def(py::init<>());

// Fields

// Methods
cls_StepRepr_PropertyDefinition.def("Init", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepRepr_CharacterizedDefinition &)) &StepRepr_PropertyDefinition::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aDefinition"));
cls_StepRepr_PropertyDefinition.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Name, "Returns field Name");
cls_StepRepr_PropertyDefinition.def("SetName", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinition::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_PropertyDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Description, "Returns field Description");
cls_StepRepr_PropertyDefinition.def("SetDescription", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinition::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_PropertyDefinition.def("HasDescription", (Standard_Boolean (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_PropertyDefinition.def("Definition", (StepRepr_CharacterizedDefinition (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Definition, "Returns field Definition");
cls_StepRepr_PropertyDefinition.def("SetDefinition", (void (StepRepr_PropertyDefinition::*)(const StepRepr_CharacterizedDefinition &)) &StepRepr_PropertyDefinition::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepRepr_PropertyDefinition.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinition::get_type_name, "None");
cls_StepRepr_PropertyDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinition::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::DynamicType, "None");

// Enums

}