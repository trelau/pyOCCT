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
#include <StepRepr_AssemblyComponentUsageSubstitute.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <StepBasic_Date.hxx>
#include <StepBasic_Document.hxx>
#include <StepBasic_Effectivity.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_GroupRelationship.hxx>
#include <StepBasic_ProductDefinitionFormationRelationship.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepAP214_ApprovalItem.hxx>

void bind_StepAP214_ApprovalItem(py::module &mod){

py::class_<StepAP214_ApprovalItem, std::unique_ptr<StepAP214_ApprovalItem, Deleter<StepAP214_ApprovalItem>>, StepData_SelectType> cls_StepAP214_ApprovalItem(mod, "StepAP214_ApprovalItem", "None");

// Constructors
cls_StepAP214_ApprovalItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_ApprovalItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_ApprovalItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_ApprovalItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_ApprovalItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_ApprovalItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_ApprovalItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_ApprovalItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_ApprovalItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_ApprovalItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_ApprovalItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_ApprovalItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_ApprovalItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_ApprovalItem.def("CaseNum", (Standard_Integer (StepAP214_ApprovalItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_ApprovalItem::CaseNum, "Recognizes a ApprovalItem Kind Entity that is : 1 -> AssemblyComponentUsageSubstitute 2 -> DocumentFile 3 -> MaterialDesignation 4 -> MechanicalDesignGeometricPresentationRepresentation 5 -> PresentationArea 6 -> Product 7 -> ProductDefinition 8 -> ProductDefinitionFormation 9 -> ProductDefinitionRelationship 10 -> PropertyDefinition 11 -> ShapeRepresentation 12 -> SecurityClassification 13 -> ConfigurationItem 14 -> Date 15 -> Document 16 -> Effectivity 17 -> Group 18 -> GroupRelationship 19 -> ProductDefinitionFormationRelationship 20 -> Representation 21 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepAP214_ApprovalItem.def("AssemblyComponentUsageSubstitute", (opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::AssemblyComponentUsageSubstitute, "returns Value as a AssemblyComponentUsageSubstitute (Null if another type)");
cls_StepAP214_ApprovalItem.def("DocumentFile", (opencascade::handle<StepBasic_DocumentFile> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::DocumentFile, "returns Value as a DocumentFile (Null if another type)");
cls_StepAP214_ApprovalItem.def("MaterialDesignation", (opencascade::handle<StepRepr_MaterialDesignation> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::MaterialDesignation, "returns Value as a MaterialDesignation (Null if another type)");
cls_StepAP214_ApprovalItem.def("MechanicalDesignGeometricPresentationRepresentation", (opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::MechanicalDesignGeometricPresentationRepresentation, "returns Value as a MechanicalDesignGeometricPresentationRepresentation (Null if another type)");
cls_StepAP214_ApprovalItem.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::PresentationArea, "returns Value as a PresentationArea (Null if another type)");
cls_StepAP214_ApprovalItem.def("Product", (opencascade::handle<StepBasic_Product> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Product, "returns Value as a Product (Null if another type)");
cls_StepAP214_ApprovalItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_ApprovalItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ProductDefinitionFormation, "returns Value as a ProductDefinitionFormation (Null if another type)");
cls_StepAP214_ApprovalItem.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ProductDefinitionRelationship, "returns Value as aProductDefinitionRelationship (Null if another type)");
cls_StepAP214_ApprovalItem.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::PropertyDefinition, "returns Value as a PropertyDefinition (Null if another type)");
cls_StepAP214_ApprovalItem.def("ShapeRepresentation", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ShapeRepresentation, "returns Value as a ShapeRepresentation (Null if another type)");
cls_StepAP214_ApprovalItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::SecurityClassification, "returns Value as a SecurityClassification (Null if another type)");
cls_StepAP214_ApprovalItem.def("ConfigurationItem", (opencascade::handle<StepRepr_ConfigurationItem> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ConfigurationItem, "returns Value as a ConfigurationItem (Null if another type)");
cls_StepAP214_ApprovalItem.def("Date", (opencascade::handle<StepBasic_Date> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Date, "returns Value as a Date (Null if another type)");
cls_StepAP214_ApprovalItem.def("Document", (opencascade::handle<StepBasic_Document> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Document, "returns Value as a Document (Null if another type)");
cls_StepAP214_ApprovalItem.def("Effectivity", (opencascade::handle<StepBasic_Effectivity> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Effectivity, "returns Value as a Effectivity (Null if another type)");
cls_StepAP214_ApprovalItem.def("Group", (opencascade::handle<StepBasic_Group> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Group, "returns Value as a Group (Null if another type)");
cls_StepAP214_ApprovalItem.def("GroupRelationship", (opencascade::handle<StepBasic_GroupRelationship> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::GroupRelationship, "returns Value as a GroupRelationship (Null if another type)");
cls_StepAP214_ApprovalItem.def("ProductDefinitionFormationRelationship", (opencascade::handle<StepBasic_ProductDefinitionFormationRelationship> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ProductDefinitionFormationRelationship, "returns Value as a ProductDefinitionFormationRelationship (Null if another type)");
cls_StepAP214_ApprovalItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_ApprovalItem.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP214_ApprovalItem::*)() const) &StepAP214_ApprovalItem::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// Enums

}