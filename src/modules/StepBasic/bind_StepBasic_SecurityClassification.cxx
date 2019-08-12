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
#include <StepBasic_SecurityClassificationLevel.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_SecurityClassification(py::module &mod){

py::class_<StepBasic_SecurityClassification, opencascade::handle<StepBasic_SecurityClassification>, Standard_Transient> cls_StepBasic_SecurityClassification(mod, "StepBasic_SecurityClassification", "None");

// Constructors
cls_StepBasic_SecurityClassification.def(py::init<>());

// Fields

// Methods
cls_StepBasic_SecurityClassification.def("Init", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_SecurityClassificationLevel> &)) &StepBasic_SecurityClassification::Init, "None", py::arg("aName"), py::arg("aPurpose"), py::arg("aSecurityLevel"));
cls_StepBasic_SecurityClassification.def("SetName", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassification::SetName, "None", py::arg("aName"));
cls_StepBasic_SecurityClassification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SecurityClassification::*)() const) &StepBasic_SecurityClassification::Name, "None");
cls_StepBasic_SecurityClassification.def("SetPurpose", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassification::SetPurpose, "None", py::arg("aPurpose"));
cls_StepBasic_SecurityClassification.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SecurityClassification::*)() const) &StepBasic_SecurityClassification::Purpose, "None");
cls_StepBasic_SecurityClassification.def("SetSecurityLevel", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<StepBasic_SecurityClassificationLevel> &)) &StepBasic_SecurityClassification::SetSecurityLevel, "None", py::arg("aSecurityLevel"));
cls_StepBasic_SecurityClassification.def("SecurityLevel", (opencascade::handle<StepBasic_SecurityClassificationLevel> (StepBasic_SecurityClassification::*)() const) &StepBasic_SecurityClassification::SecurityLevel, "None");
cls_StepBasic_SecurityClassification.def_static("get_type_name_", (const char * (*)()) &StepBasic_SecurityClassification::get_type_name, "None");
cls_StepBasic_SecurityClassification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SecurityClassification::get_type_descriptor, "None");
cls_StepBasic_SecurityClassification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SecurityClassification::*)() const) &StepBasic_SecurityClassification::DynamicType, "None");

// Enums

}