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
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_PropertyDefinitionRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_PropertyDefinitionRelationship(py::module &mod){

py::class_<StepRepr_PropertyDefinitionRelationship, opencascade::handle<StepRepr_PropertyDefinitionRelationship>, Standard_Transient> cls_StepRepr_PropertyDefinitionRelationship(mod, "StepRepr_PropertyDefinitionRelationship", "Representation of STEP entity PropertyDefinitionRelationship");

// Constructors
cls_StepRepr_PropertyDefinitionRelationship.def(py::init<>());

// Fields

// Methods
cls_StepRepr_PropertyDefinitionRelationship.def("Init", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_PropertyDefinition> &, const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aRelatingPropertyDefinition"), py::arg("aRelatedPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::Name, "Returns field Name");
cls_StepRepr_PropertyDefinitionRelationship.def("SetName", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinitionRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_PropertyDefinitionRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::Description, "Returns field Description");
cls_StepRepr_PropertyDefinitionRelationship.def("SetDescription", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinitionRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_PropertyDefinitionRelationship.def("RelatingPropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::RelatingPropertyDefinition, "Returns field RelatingPropertyDefinition");
cls_StepRepr_PropertyDefinitionRelationship.def("SetRelatingPropertyDefinition", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::SetRelatingPropertyDefinition, "Set field RelatingPropertyDefinition", py::arg("RelatingPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def("RelatedPropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::RelatedPropertyDefinition, "Returns field RelatedPropertyDefinition");
cls_StepRepr_PropertyDefinitionRelationship.def("SetRelatedPropertyDefinition", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::SetRelatedPropertyDefinition, "Set field RelatedPropertyDefinition", py::arg("RelatedPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinitionRelationship::get_type_name, "None");
cls_StepRepr_PropertyDefinitionRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinitionRelationship::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinitionRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::DynamicType, "None");

// Enums

}