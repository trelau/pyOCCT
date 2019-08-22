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
#include <StepBasic_Approval.hxx>
#include <StepBasic_DocumentRelationship.hxx>
#include <StepRepr_ExternallyDefinedRepresentation.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <StepVisual_PresentationView.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepAP214_AutoDesignReferencingItem.hxx>

void bind_StepAP214_AutoDesignReferencingItem(py::module &mod){

py::class_<StepAP214_AutoDesignReferencingItem, StepData_SelectType> cls_StepAP214_AutoDesignReferencingItem(mod, "StepAP214_AutoDesignReferencingItem", "None");

// Constructors
cls_StepAP214_AutoDesignReferencingItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignReferencingItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignReferencingItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignReferencingItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignReferencingItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignReferencingItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignReferencingItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignReferencingItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignReferencingItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignReferencingItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignReferencingItem::CaseNum, "Recognizes a AutoDesignReferencingItem Kind Entity that is : 1 Approval from StepBasic, 2 DocumentRelationship from StepBasic, 3 ExternallyDefinedRepresentation from StepRepr, 4 MappedItem from StepRepr, 5 MaterialDesignation from StepRepr, 6 PresentationArea from StepVisual, 7 PresentationView from StepVisual, 8 ProductCategory from StepBasic, 9 ProductDefinition from StepBasic, 10 ProductDefinitionRelationship from StepBasic, 11 PropertyDefinition from StepBasic, 12 Representation from StepRepr, 13 RepresentationRelationship from StepRepr, 14 ShapeAspect from StepRepr 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignReferencingItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::Approval, "None");
cls_StepAP214_AutoDesignReferencingItem.def("DocumentRelationship", (opencascade::handle<StepBasic_DocumentRelationship> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::DocumentRelationship, "None");
cls_StepAP214_AutoDesignReferencingItem.def("ExternallyDefinedRepresentation", (opencascade::handle<StepRepr_ExternallyDefinedRepresentation> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::ExternallyDefinedRepresentation, "None");
cls_StepAP214_AutoDesignReferencingItem.def("MappedItem", (opencascade::handle<StepRepr_MappedItem> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::MappedItem, "None");
cls_StepAP214_AutoDesignReferencingItem.def("MaterialDesignation", (opencascade::handle<StepRepr_MaterialDesignation> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::MaterialDesignation, "None");
cls_StepAP214_AutoDesignReferencingItem.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::PresentationArea, "None");
cls_StepAP214_AutoDesignReferencingItem.def("PresentationView", (opencascade::handle<StepVisual_PresentationView> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::PresentationView, "None");
cls_StepAP214_AutoDesignReferencingItem.def("ProductCategory", (opencascade::handle<StepBasic_ProductCategory> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::ProductCategory, "None");
cls_StepAP214_AutoDesignReferencingItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::ProductDefinition, "None");
cls_StepAP214_AutoDesignReferencingItem.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::ProductDefinitionRelationship, "None");
cls_StepAP214_AutoDesignReferencingItem.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::PropertyDefinition, "None");
cls_StepAP214_AutoDesignReferencingItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::Representation, "None");
cls_StepAP214_AutoDesignReferencingItem.def("RepresentationRelationship", (opencascade::handle<StepRepr_RepresentationRelationship> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::RepresentationRelationship, "None");
cls_StepAP214_AutoDesignReferencingItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_AutoDesignReferencingItem::*)() const) &StepAP214_AutoDesignReferencingItem::ShapeAspect, "None");

// Enums

}