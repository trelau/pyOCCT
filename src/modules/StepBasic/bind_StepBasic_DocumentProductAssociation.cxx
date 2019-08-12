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
#include <StepBasic_Document.hxx>
#include <StepBasic_ProductOrFormationOrDefinition.hxx>
#include <StepBasic_DocumentProductAssociation.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DocumentProductAssociation(py::module &mod){

py::class_<StepBasic_DocumentProductAssociation, opencascade::handle<StepBasic_DocumentProductAssociation>, Standard_Transient> cls_StepBasic_DocumentProductAssociation(mod, "StepBasic_DocumentProductAssociation", "Representation of STEP entity DocumentProductAssociation");

// Constructors
cls_StepBasic_DocumentProductAssociation.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DocumentProductAssociation.def("Init", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &, const StepBasic_ProductOrFormationOrDefinition &)) &StepBasic_DocumentProductAssociation::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingDocument"), py::arg("aRelatedProduct"));
cls_StepBasic_DocumentProductAssociation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::Name, "Returns field Name");
cls_StepBasic_DocumentProductAssociation.def("SetName", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentProductAssociation::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_DocumentProductAssociation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::Description, "Returns field Description");
cls_StepBasic_DocumentProductAssociation.def("SetDescription", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentProductAssociation::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_DocumentProductAssociation.def("HasDescription", (Standard_Boolean (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_DocumentProductAssociation.def("RelatingDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::RelatingDocument, "Returns field RelatingDocument");
cls_StepBasic_DocumentProductAssociation.def("SetRelatingDocument", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentProductAssociation::SetRelatingDocument, "Set field RelatingDocument", py::arg("RelatingDocument"));
cls_StepBasic_DocumentProductAssociation.def("RelatedProduct", (StepBasic_ProductOrFormationOrDefinition (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::RelatedProduct, "Returns field RelatedProduct");
cls_StepBasic_DocumentProductAssociation.def("SetRelatedProduct", (void (StepBasic_DocumentProductAssociation::*)(const StepBasic_ProductOrFormationOrDefinition &)) &StepBasic_DocumentProductAssociation::SetRelatedProduct, "Set field RelatedProduct", py::arg("RelatedProduct"));
cls_StepBasic_DocumentProductAssociation.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentProductAssociation::get_type_name, "None");
cls_StepBasic_DocumentProductAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentProductAssociation::get_type_descriptor, "None");
cls_StepBasic_DocumentProductAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentProductAssociation::*)() const) &StepBasic_DocumentProductAssociation::DynamicType, "None");

// Enums

}