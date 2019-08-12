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
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionRelationship(py::module &mod){

py::class_<StepBasic_ProductDefinitionRelationship, opencascade::handle<StepBasic_ProductDefinitionRelationship>, Standard_Transient> cls_StepBasic_ProductDefinitionRelationship(mod, "StepBasic_ProductDefinitionRelationship", "Representation of STEP entity ProductDefinitionRelationship");

// Constructors
cls_StepBasic_ProductDefinitionRelationship.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionRelationship.def("Init", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingProductDefinition"), py::arg("aRelatedProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def("Init", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingProductDefinition"), py::arg("aRelatedProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::Id, "Returns field Id");
cls_StepBasic_ProductDefinitionRelationship.def("SetId", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetId, "Set field Id", py::arg("Id"));
cls_StepBasic_ProductDefinitionRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::Name, "Returns field Name");
cls_StepBasic_ProductDefinitionRelationship.def("SetName", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_ProductDefinitionRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::Description, "Returns field Description");
cls_StepBasic_ProductDefinitionRelationship.def("SetDescription", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_ProductDefinitionRelationship.def("HasDescription", (Standard_Boolean (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_ProductDefinitionRelationship.def("RelatingProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::RelatingProductDefinition, "Returns field RelatingProductDefinition");
cls_StepBasic_ProductDefinitionRelationship.def("RelatingProductDefinitionAP242", (StepBasic_ProductDefinitionOrReference (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::RelatingProductDefinitionAP242, "Returns field RelatingProductDefinition in AP242");
cls_StepBasic_ProductDefinitionRelationship.def("SetRelatingProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::SetRelatingProductDefinition, "Set field RelatingProductDefinition", py::arg("RelatingProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def("SetRelatingProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::SetRelatingProductDefinition, "Set field RelatingProductDefinition in AP242", py::arg("RelatingProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def("RelatedProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::RelatedProductDefinition, "Returns field RelatedProductDefinition");
cls_StepBasic_ProductDefinitionRelationship.def("RelatedProductDefinitionAP242", (StepBasic_ProductDefinitionOrReference (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::RelatedProductDefinitionAP242, "Returns field RelatedProductDefinition in AP242");
cls_StepBasic_ProductDefinitionRelationship.def("SetRelatedProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::SetRelatedProductDefinition, "Set field RelatedProductDefinition", py::arg("RelatedProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def("SetRelatedProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::SetRelatedProductDefinition, "Set field RelatedProductDefinition in AP242", py::arg("RelatedProductDefinition"));
cls_StepBasic_ProductDefinitionRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionRelationship::get_type_name, "None");
cls_StepBasic_ProductDefinitionRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionRelationship::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionRelationship::*)() const) &StepBasic_ProductDefinitionRelationship::DynamicType, "None");

// Enums

}