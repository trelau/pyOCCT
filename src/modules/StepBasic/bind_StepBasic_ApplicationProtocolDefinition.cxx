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
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ApplicationProtocolDefinition(py::module &mod){

py::class_<StepBasic_ApplicationProtocolDefinition, opencascade::handle<StepBasic_ApplicationProtocolDefinition>, Standard_Transient> cls_StepBasic_ApplicationProtocolDefinition(mod, "StepBasic_ApplicationProtocolDefinition", "None");

// Constructors
cls_StepBasic_ApplicationProtocolDefinition.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ApplicationProtocolDefinition.def("Init", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationProtocolDefinition::Init, "None", py::arg("aStatus"), py::arg("aApplicationInterpretedModelSchemaName"), py::arg("aApplicationProtocolYear"), py::arg("aApplication"));
cls_StepBasic_ApplicationProtocolDefinition.def("SetStatus", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationProtocolDefinition::SetStatus, "None", py::arg("aStatus"));
cls_StepBasic_ApplicationProtocolDefinition.def("Status", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationProtocolDefinition::*)() const) &StepBasic_ApplicationProtocolDefinition::Status, "None");
cls_StepBasic_ApplicationProtocolDefinition.def("SetApplicationInterpretedModelSchemaName", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationProtocolDefinition::SetApplicationInterpretedModelSchemaName, "None", py::arg("aApplicationInterpretedModelSchemaName"));
cls_StepBasic_ApplicationProtocolDefinition.def("ApplicationInterpretedModelSchemaName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationProtocolDefinition::*)() const) &StepBasic_ApplicationProtocolDefinition::ApplicationInterpretedModelSchemaName, "None");
cls_StepBasic_ApplicationProtocolDefinition.def("SetApplicationProtocolYear", (void (StepBasic_ApplicationProtocolDefinition::*)(const Standard_Integer)) &StepBasic_ApplicationProtocolDefinition::SetApplicationProtocolYear, "None", py::arg("aApplicationProtocolYear"));
cls_StepBasic_ApplicationProtocolDefinition.def("ApplicationProtocolYear", (Standard_Integer (StepBasic_ApplicationProtocolDefinition::*)() const) &StepBasic_ApplicationProtocolDefinition::ApplicationProtocolYear, "None");
cls_StepBasic_ApplicationProtocolDefinition.def("SetApplication", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationProtocolDefinition::SetApplication, "None", py::arg("aApplication"));
cls_StepBasic_ApplicationProtocolDefinition.def("Application", (opencascade::handle<StepBasic_ApplicationContext> (StepBasic_ApplicationProtocolDefinition::*)() const) &StepBasic_ApplicationProtocolDefinition::Application, "None");
cls_StepBasic_ApplicationProtocolDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationProtocolDefinition::get_type_name, "None");
cls_StepBasic_ApplicationProtocolDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationProtocolDefinition::get_type_descriptor, "None");
cls_StepBasic_ApplicationProtocolDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationProtocolDefinition::*)() const) &StepBasic_ApplicationProtocolDefinition::DynamicType, "None");

// Enums

}