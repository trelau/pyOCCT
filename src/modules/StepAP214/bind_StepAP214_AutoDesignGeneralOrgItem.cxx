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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_ExternallyDefinedRepresentation.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <StepAP214_AutoDesignGeneralOrgItem.hxx>

void bind_StepAP214_AutoDesignGeneralOrgItem(py::module &mod){

py::class_<StepAP214_AutoDesignGeneralOrgItem, StepData_SelectType> cls_StepAP214_AutoDesignGeneralOrgItem(mod, "StepAP214_AutoDesignGeneralOrgItem", "None");

// Constructors
cls_StepAP214_AutoDesignGeneralOrgItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignGeneralOrgItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignGeneralOrgItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignGeneralOrgItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignGeneralOrgItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignGeneralOrgItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignGeneralOrgItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignGeneralOrgItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignGeneralOrgItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignGeneralOrgItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignGeneralOrgItem::CaseNum, "Recognizes a AutoDesignGeneralOrgItem Kind Entity that is : 1 Product from StepBasic, 2 ProductDefinition from StepBasic, 3 ProductDefinitionFormation from StepBasic, 4 ProductDefinitionRelationship from StepBasic, 5 ProductDefinitionWithAssociatedDocuments from StepBasic, 6 Representation from StepRepr 7 ExternallyDefinedRepresentation from StepRepr, 8 AutoDesignDocumentReference from StepAP214, 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignGeneralOrgItem.def("Product", (opencascade::handle<StepBasic_Product> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::Product, "returns Value as a Product (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::ProductDefinitionFormation, "returns Value as a ProductDefinitionFormation (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::ProductDefinitionRelationship, "returns Value as a ProductDefinitionRelationship (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("ProductDefinitionWithAssociatedDocuments", (opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::ProductDefinitionWithAssociatedDocuments, "returns Value as a ProductDefinitionWithAssociatedDocuments (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("ExternallyDefinedRepresentation", (opencascade::handle<StepRepr_ExternallyDefinedRepresentation> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::ExternallyDefinedRepresentation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_AutoDesignGeneralOrgItem.def("AutoDesignDocumentReference", (opencascade::handle<StepAP214_AutoDesignDocumentReference> (StepAP214_AutoDesignGeneralOrgItem::*)() const) &StepAP214_AutoDesignGeneralOrgItem::AutoDesignDocumentReference, "None");

// Enums

}