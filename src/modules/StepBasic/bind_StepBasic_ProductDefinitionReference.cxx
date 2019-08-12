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
#include <StepBasic_ExternalSource.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ProductDefinitionReference.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionReference(py::module &mod){

py::class_<StepBasic_ProductDefinitionReference, opencascade::handle<StepBasic_ProductDefinitionReference>, Standard_Transient> cls_StepBasic_ProductDefinitionReference(mod, "StepBasic_ProductDefinitionReference", "Representation of STEP entity Product_Definition_Reference");

// Constructors
cls_StepBasic_ProductDefinitionReference.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionReference.def("Init", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::Init, "Initialize all fields (own and inherited)", py::arg("theSource"), py::arg("theProductId"), py::arg("theProductDefinitionFormationId"), py::arg("theProductDefinitionId"), py::arg("theIdOwningOrganizationName"));
cls_StepBasic_ProductDefinitionReference.def("Init", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::Init, "Initialize all fields (own and inherited)", py::arg("theSource"), py::arg("theProductId"), py::arg("theProductDefinitionFormationId"), py::arg("theProductDefinitionId"));
cls_StepBasic_ProductDefinitionReference.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::Source, "Returns field Source");
cls_StepBasic_ProductDefinitionReference.def("SetSource", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ProductDefinitionReference::SetSource, "Set field Source", py::arg("theSource"));
cls_StepBasic_ProductDefinitionReference.def("ProductId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::ProductId, "Returns field ProductId");
cls_StepBasic_ProductDefinitionReference.def("SetProductId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductId, "Set field ProductId", py::arg("theProductId"));
cls_StepBasic_ProductDefinitionReference.def("ProductDefinitionFormationId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::ProductDefinitionFormationId, "Returns field ProductDefinitionFormationId");
cls_StepBasic_ProductDefinitionReference.def("SetProductDefinitionFormationId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductDefinitionFormationId, "Set field ProductDefinitionFormationId", py::arg("theProductDefinitionFormationId"));
cls_StepBasic_ProductDefinitionReference.def("ProductDefinitionId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::ProductDefinitionId, "Returns field ProductDefinitionId");
cls_StepBasic_ProductDefinitionReference.def("SetProductDefinitionId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductDefinitionId, "Set field ProductDefinitionId", py::arg("theProductDefinitionId"));
cls_StepBasic_ProductDefinitionReference.def("IdOwningOrganizationName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::IdOwningOrganizationName, "Returns field IdOwningOrganizationName");
cls_StepBasic_ProductDefinitionReference.def("SetIdOwningOrganizationName", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetIdOwningOrganizationName, "Set field IdOwningOrganizationName", py::arg("theIdOwningOrganizationName"));
cls_StepBasic_ProductDefinitionReference.def("HasIdOwningOrganizationName", (Standard_Boolean (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::HasIdOwningOrganizationName, "Returns true if IdOwningOrganizationName exists");
cls_StepBasic_ProductDefinitionReference.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionReference::get_type_name, "None");
cls_StepBasic_ProductDefinitionReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionReference::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionReference::*)() const) &StepBasic_ProductDefinitionReference::DynamicType, "None");

// Enums

}