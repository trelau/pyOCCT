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
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinition(py::module &mod){

py::class_<StepBasic_ProductDefinition, opencascade::handle<StepBasic_ProductDefinition>, Standard_Transient> cls_StepBasic_ProductDefinition(mod, "StepBasic_ProductDefinition", "None");

// Constructors
cls_StepBasic_ProductDefinition.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinition.def("Init", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinition::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aFormation"), py::arg("aFrameOfReference"));
cls_StepBasic_ProductDefinition.def("SetId", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinition::SetId, "None", py::arg("aId"));
cls_StepBasic_ProductDefinition.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinition::*)() const) &StepBasic_ProductDefinition::Id, "None");
cls_StepBasic_ProductDefinition.def("SetDescription", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinition::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_ProductDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinition::*)() const) &StepBasic_ProductDefinition::Description, "None");
cls_StepBasic_ProductDefinition.def("SetFormation", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinition::SetFormation, "None", py::arg("aFormation"));
cls_StepBasic_ProductDefinition.def("Formation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinition::*)() const) &StepBasic_ProductDefinition::Formation, "None");
cls_StepBasic_ProductDefinition.def("SetFrameOfReference", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinition::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
cls_StepBasic_ProductDefinition.def("FrameOfReference", (opencascade::handle<StepBasic_ProductDefinitionContext> (StepBasic_ProductDefinition::*)() const) &StepBasic_ProductDefinition::FrameOfReference, "None");
cls_StepBasic_ProductDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinition::get_type_name, "None");
cls_StepBasic_ProductDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinition::get_type_descriptor, "None");
cls_StepBasic_ProductDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinition::*)() const) &StepBasic_ProductDefinition::DynamicType, "None");

// Enums

}