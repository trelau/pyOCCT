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
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_GroupRelationship.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepAP214_DocumentReferenceItem.hxx>

void bind_StepAP214_DocumentReferenceItem(py::module &mod){

py::class_<StepAP214_DocumentReferenceItem, StepData_SelectType> cls_StepAP214_DocumentReferenceItem(mod, "StepAP214_DocumentReferenceItem", "None");

// Constructors
cls_StepAP214_DocumentReferenceItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_DocumentReferenceItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_DocumentReferenceItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_DocumentReferenceItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_DocumentReferenceItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_DocumentReferenceItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_DocumentReferenceItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_DocumentReferenceItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_DocumentReferenceItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_DocumentReferenceItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_DocumentReferenceItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_DocumentReferenceItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_DocumentReferenceItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_DocumentReferenceItem.def("CaseNum", (Standard_Integer (StepAP214_DocumentReferenceItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_DocumentReferenceItem::CaseNum, "Recognizes a DocumentReferenceItem Kind Entity that is :", py::arg("ent"));
cls_StepAP214_DocumentReferenceItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::Approval, "returns Value as a Approval (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("DescriptiveRepresentationItem", (opencascade::handle<StepRepr_DescriptiveRepresentationItem> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::DescriptiveRepresentationItem, "returns Value as a (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("MaterialDesignation", (opencascade::handle<StepRepr_MaterialDesignation> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::MaterialDesignation, "returns Value as a MaterialDesignation (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ProductDefinitionRelationship, "returns Value as aProductDefinitionRelationship (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::PropertyDefinition, "returns Value as a PropertyDefinition (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("AppliedExternalIdentificationAssignment", (opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::AppliedExternalIdentificationAssignment, "returns Value as a AppliedExternalIdentificationAssignment (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("AssemblyComponentUsage", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::AssemblyComponentUsage, "returns Value as a AssemblyComponentUsage (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("CharacterizedObject", (opencascade::handle<StepBasic_CharacterizedObject> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::CharacterizedObject, "returns Value as a CharacterizedObject (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ExternallyDefinedItem", (opencascade::handle<StepBasic_ExternallyDefinedItem> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ExternallyDefinedItem, "returns Value as a ExternallyDefinedItem (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("Group", (opencascade::handle<StepBasic_Group> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::Group, "returns Value as a Group (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("GroupRelationship", (opencascade::handle<StepBasic_GroupRelationship> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::GroupRelationship, "returns Value as a GroupRelationship (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("MeasureRepresentationItem", (opencascade::handle<StepRepr_MeasureRepresentationItem> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::MeasureRepresentationItem, "returns Value as a MeasureRepresentationItem (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ProductCategory", (opencascade::handle<StepBasic_ProductCategory> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ProductCategory, "returns Value as a ProductCategory (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("ProductDefinitionContext", (opencascade::handle<StepBasic_ProductDefinitionContext> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::ProductDefinitionContext, "returns Value as a ProductDefinitionContext (Null if another type)");
cls_StepAP214_DocumentReferenceItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_DocumentReferenceItem::*)() const) &StepAP214_DocumentReferenceItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");

// Enums

}