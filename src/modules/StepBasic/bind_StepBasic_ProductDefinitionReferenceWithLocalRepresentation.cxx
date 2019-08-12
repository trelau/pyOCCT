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
#include <StepBasic_ProductDefinition.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_ProductDefinitionReferenceWithLocalRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionReferenceWithLocalRepresentation(py::module &mod){

py::class_<StepBasic_ProductDefinitionReferenceWithLocalRepresentation, opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation>, StepBasic_ProductDefinition> cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation(mod, "StepBasic_ProductDefinitionReferenceWithLocalRepresentation", "None");

// Constructors
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("Init", (void (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::Init, "None", py::arg("theSource"), py::arg("theId"), py::arg("theDescription"), py::arg("theFormation"), py::arg("theFrameOfReference"));
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)() const) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::Source, "Returns field Source");
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("SetSource", (void (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::SetSource, "Set field Source", py::arg("theSource"));
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::get_type_name, "None");
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)() const) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::DynamicType, "None");

// Enums

}