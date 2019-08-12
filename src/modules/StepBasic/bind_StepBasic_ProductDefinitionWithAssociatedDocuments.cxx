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
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_HArray1OfDocument.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_Document.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionWithAssociatedDocuments(py::module &mod){

py::class_<StepBasic_ProductDefinitionWithAssociatedDocuments, opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments>, StepBasic_ProductDefinition> cls_StepBasic_ProductDefinitionWithAssociatedDocuments(mod, "StepBasic_ProductDefinitionWithAssociatedDocuments", "None");

// Constructors
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("Init", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &, const opencascade::handle<StepBasic_HArray1OfDocument> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aFormation"), py::arg("aFrame"), py::arg("aDocIds"));
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DocIds", (opencascade::handle<StepBasic_HArray1OfDocument> (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const) &StepBasic_ProductDefinitionWithAssociatedDocuments::DocIds, "None");
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("SetDocIds", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<StepBasic_HArray1OfDocument> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::SetDocIds, "None", py::arg("DocIds"));
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("NbDocIds", (Standard_Integer (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const) &StepBasic_ProductDefinitionWithAssociatedDocuments::NbDocIds, "None");
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DocIdsValue", (opencascade::handle<StepBasic_Document> (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const Standard_Integer) const) &StepBasic_ProductDefinitionWithAssociatedDocuments::DocIdsValue, "None", py::arg("num"));
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("SetDocIdsValue", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const Standard_Integer, const opencascade::handle<StepBasic_Document> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::SetDocIdsValue, "None", py::arg("num"), py::arg("adoc"));
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionWithAssociatedDocuments::get_type_name, "None");
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionWithAssociatedDocuments::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const) &StepBasic_ProductDefinitionWithAssociatedDocuments::DynamicType, "None");

// Enums

}