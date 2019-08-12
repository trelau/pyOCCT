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
#include <Standard_Type.hxx>

void bind_StepBasic_ActionMethod(py::module &mod){

py::class_<StepBasic_ActionMethod, opencascade::handle<StepBasic_ActionMethod>, Standard_Transient> cls_StepBasic_ActionMethod(mod, "StepBasic_ActionMethod", "Representation of STEP entity ActionMethod");

// Constructors
cls_StepBasic_ActionMethod.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ActionMethod.def("Init", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aConsequence"), py::arg("aPurpose"));
cls_StepBasic_ActionMethod.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::Name, "Returns field Name");
cls_StepBasic_ActionMethod.def("SetName", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_ActionMethod.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::Description, "Returns field Description");
cls_StepBasic_ActionMethod.def("SetDescription", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_ActionMethod.def("HasDescription", (Standard_Boolean (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_ActionMethod.def("Consequence", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::Consequence, "Returns field Consequence");
cls_StepBasic_ActionMethod.def("SetConsequence", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetConsequence, "Set field Consequence", py::arg("Consequence"));
cls_StepBasic_ActionMethod.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::Purpose, "Returns field Purpose");
cls_StepBasic_ActionMethod.def("SetPurpose", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepBasic_ActionMethod.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionMethod::get_type_name, "None");
cls_StepBasic_ActionMethod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionMethod::get_type_descriptor, "None");
cls_StepBasic_ActionMethod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionMethod::*)() const) &StepBasic_ActionMethod::DynamicType, "None");

// Enums

}