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
#include <StepAP214_ApprovalItem.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_Action.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepVisual_DraughtingModel.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <StepRepr_MakeFromUsageOption.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <StepRepr_ProductDefinitionUsage.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepAP214_SecurityClassificationItem.hxx>

void bind_StepAP214_SecurityClassificationItem(py::module &mod){

py::class_<StepAP214_SecurityClassificationItem, std::unique_ptr<StepAP214_SecurityClassificationItem>, StepAP214_ApprovalItem> cls_StepAP214_SecurityClassificationItem(mod, "StepAP214_SecurityClassificationItem", "None");

// Constructors
cls_StepAP214_SecurityClassificationItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_SecurityClassificationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_SecurityClassificationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_SecurityClassificationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_SecurityClassificationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_SecurityClassificationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_SecurityClassificationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_SecurityClassificationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_SecurityClassificationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_SecurityClassificationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_SecurityClassificationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_SecurityClassificationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_SecurityClassificationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_SecurityClassificationItem.def("CaseNum", (Standard_Integer (StepAP214_SecurityClassificationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_SecurityClassificationItem::CaseNum, "Recognizes a SecurityClassificationItem Kind Entity that is : 1 -> Action 2 -> AssemblyComponentUsage 3 -> AssemblyComponentUsageSubstitute 4 -> ConfigurationDesign 5 -> ConfigurationEffectivity 6 -> Document 7 -> DocumentFile 8 -> DraughtingModel 9 -> GeneralProperty 10 -> MakeFromUsageOption 11 -> MaterialDesignation 12 -> MechanicalDesignGeometricPresentationRepresentation 13 -> PresentationArea 14 -> Product 15 -> ProductConcept 16 -> ProductDefinition 17 -> ProductDefinitionFormation 18 -> ProductDefinitionRelationship 19 -> ProductDefinitionUsage 20 -> PropertyDefinition 21 -> ShapeRepresentation 22 -> VersionedActionRequest 0 else", py::arg("ent"));
cls_StepAP214_SecurityClassificationItem.def("Action", (opencascade::handle<StepBasic_Action> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::Action, "returns Value as a Action (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("AssemblyComponentUsage", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::AssemblyComponentUsage, "returns Value as a AssemblyComponentUsage (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("ConfigurationDesign", (opencascade::handle<StepRepr_ConfigurationDesign> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::ConfigurationDesign, "returns Value as a ConfigurationDesign (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("ConfigurationEffectivity", (opencascade::handle<StepRepr_ConfigurationEffectivity> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::ConfigurationEffectivity, "returns Value as a ConfigurationEffectivity (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("DraughtingModel", (opencascade::handle<StepVisual_DraughtingModel> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::DraughtingModel, "returns Value as a DraughtingModel (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("GeneralProperty", (opencascade::handle<StepBasic_GeneralProperty> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::GeneralProperty, "returns Value as a GeneralProperty (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("MakeFromUsageOption", (opencascade::handle<StepRepr_MakeFromUsageOption> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::MakeFromUsageOption, "returns Value as a MakeFromUsageOption (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("ProductConcept", (opencascade::handle<StepRepr_ProductConcept> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::ProductConcept, "returns Value as a ProductConcept (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("ProductDefinitionUsage", (opencascade::handle<StepRepr_ProductDefinitionUsage> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::ProductDefinitionUsage, "returns Value as a ProductDefinitionUsage (Null if another type)");
cls_StepAP214_SecurityClassificationItem.def("VersionedActionRequest", (opencascade::handle<StepBasic_VersionedActionRequest> (StepAP214_SecurityClassificationItem::*)() const) &StepAP214_SecurityClassificationItem::VersionedActionRequest, "returns Value as a VersionedActionRequest (Null if another type)");

// Enums

}