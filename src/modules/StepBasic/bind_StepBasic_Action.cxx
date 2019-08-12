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
#include <StepBasic_ActionMethod.hxx>
#include <StepBasic_Action.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Action(py::module &mod){

py::class_<StepBasic_Action, opencascade::handle<StepBasic_Action>, Standard_Transient> cls_StepBasic_Action(mod, "StepBasic_Action", "Representation of STEP entity Action");

// Constructors
cls_StepBasic_Action.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Action.def("Init", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_Action::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aChosenMethod"));
cls_StepBasic_Action.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Action::*)() const) &StepBasic_Action::Name, "Returns field Name");
cls_StepBasic_Action.def("SetName", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Action::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_Action.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Action::*)() const) &StepBasic_Action::Description, "Returns field Description");
cls_StepBasic_Action.def("SetDescription", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Action::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_Action.def("HasDescription", (Standard_Boolean (StepBasic_Action::*)() const) &StepBasic_Action::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_Action.def("ChosenMethod", (opencascade::handle<StepBasic_ActionMethod> (StepBasic_Action::*)() const) &StepBasic_Action::ChosenMethod, "Returns field ChosenMethod");
cls_StepBasic_Action.def("SetChosenMethod", (void (StepBasic_Action::*)(const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_Action::SetChosenMethod, "Set field ChosenMethod", py::arg("ChosenMethod"));
cls_StepBasic_Action.def_static("get_type_name_", (const char * (*)()) &StepBasic_Action::get_type_name, "None");
cls_StepBasic_Action.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Action::get_type_descriptor, "None");
cls_StepBasic_Action.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Action::*)() const) &StepBasic_Action::DynamicType, "None");

// Enums

}