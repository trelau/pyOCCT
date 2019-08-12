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
#include <StepAP214_AutoDesignOrganizationAssignment.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepRepr_Representation.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <StepRepr_ExternallyDefinedRepresentation.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <StepAP214_AutoDesignDateAndPersonItem.hxx>

void bind_StepAP214_AutoDesignDateAndPersonItem(py::module &mod){

py::class_<StepAP214_AutoDesignDateAndPersonItem, std::unique_ptr<StepAP214_AutoDesignDateAndPersonItem, Deleter<StepAP214_AutoDesignDateAndPersonItem>>, StepData_SelectType> cls_StepAP214_AutoDesignDateAndPersonItem(mod, "StepAP214_AutoDesignDateAndPersonItem", "None");

// Constructors
cls_StepAP214_AutoDesignDateAndPersonItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignDateAndPersonItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignDateAndPersonItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignDateAndPersonItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignDateAndPersonItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignDateAndPersonItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndPersonItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignDateAndPersonItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignDateAndPersonItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignDateAndPersonItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignDateAndPersonItem::CaseNum, "Recognizes a AutoDesignDateAndPersonItem Kind Entity that is : 1 AutoDesignOrganizationAssignment from StepAP214, 2 Product from StepBasic, 3 ProductDefinition from StepBasic, 4 ProductDefinitionFormation from StepBasic, 5 Representation from StepRepr, 6 AutoDesignDocumentReference from StepAP214, 7 ExternallyDefinedRepresentation from StepRepr, 8 ProductDefinitionRelationship from StepBasic, 9 ProductDefinitionWithAssociatedDocuments from StepBasic 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignDateAndPersonItem.def("AutoDesignOrganizationAssignment", (opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::AutoDesignOrganizationAssignment, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("Product", (opencascade::handle<StepBasic_Product> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::Product, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::ProductDefinition, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::ProductDefinitionFormation, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::Representation, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("AutoDesignDocumentReference", (opencascade::handle<StepAP214_AutoDesignDocumentReference> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::AutoDesignDocumentReference, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("ExternallyDefinedRepresentation", (opencascade::handle<StepRepr_ExternallyDefinedRepresentation> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::ExternallyDefinedRepresentation, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::ProductDefinitionRelationship, "None");
cls_StepAP214_AutoDesignDateAndPersonItem.def("ProductDefinitionWithAssociatedDocuments", (opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments> (StepAP214_AutoDesignDateAndPersonItem::*)() const) &StepAP214_AutoDesignDateAndPersonItem::ProductDefinitionWithAssociatedDocuments, "None");

// Enums

}