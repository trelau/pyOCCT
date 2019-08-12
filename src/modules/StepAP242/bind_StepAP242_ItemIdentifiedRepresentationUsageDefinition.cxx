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
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_PropertyDefinitionRelationship.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepAP242_ItemIdentifiedRepresentationUsageDefinition.hxx>

void bind_StepAP242_ItemIdentifiedRepresentationUsageDefinition(py::module &mod){

py::class_<StepAP242_ItemIdentifiedRepresentationUsageDefinition, std::unique_ptr<StepAP242_ItemIdentifiedRepresentationUsageDefinition, Deleter<StepAP242_ItemIdentifiedRepresentationUsageDefinition>>, StepData_SelectType> cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition(mod, "StepAP242_ItemIdentifiedRepresentationUsageDefinition", "None");

// Constructors
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator new_", (void * (*)(size_t)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator new, "None", py::arg("theSize"));
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator delete_", (void (*)(void *)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("CaseNum", (Standard_Integer (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::CaseNum, "Recognizes a ItemIdentifiedRepresentationUsageDefinition Kind Entity that is : 1 -> AppliedApprovalAssignment 2 -> AppliedDateAndTimeAssignment 3 -> AppliedDateAssignment 4 -> AppliedDocumentReference 5 -> AppliedExternalIdentificationAssignment 6 -> AppliedGroupAssignment 7 -> AppliedOrganizationAssignment 8 -> AppliedPersonAndOrganizationAssignment 9 -> AppliedSecurityClassificationAssignment 10 -> DimensionalSize 11 -> GeneralProperty 12 -> GeometricTolerance 13 -> ProductDefinitionRelationship 14 -> PropertyDefinition 15 -> PropertyDefinitionRelationship 16 -> ShapeAspect 17 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedApprovalAssignment", (opencascade::handle<StepAP214_AppliedApprovalAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedApprovalAssignment, "returns Value as a AppliedApprovalAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedDateAndTimeAssignment", (opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedDateAndTimeAssignment, "returns Value as a AppliedDateAndTimeAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedDateAssignment", (opencascade::handle<StepAP214_AppliedDateAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedDateAssignment, "returns Value as a AppliedDateAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedDocumentReference", (opencascade::handle<StepAP214_AppliedDocumentReference> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedDocumentReference, "returns Value as a AppliedDocumentReference (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedExternalIdentificationAssignment", (opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedExternalIdentificationAssignment, "returns Value as a AppliedExternalIdentificationAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedGroupAssignment", (opencascade::handle<StepAP214_AppliedGroupAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedGroupAssignment, "returns Value as a AppliedGroupAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedPersonAndOrganizationAssignment, "returns Value as a AppliedPersonAndOrganizationAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("AppliedSecurityClassificationAssignment", (opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::AppliedSecurityClassificationAssignment, "returns Value as a AppliedSecurityClassificationAssignment (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("GeneralProperty", (opencascade::handle<StepBasic_GeneralProperty> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::GeneralProperty, "returns Value as a GeneralProperty (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::GeometricTolerance, "returns Value as a GeometricTolerance (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::ProductDefinitionRelationship, "returns Value as a ProductDefinitionRelationship (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::PropertyDefinition, "returns Value as a PropertyDefinition (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("PropertyDefinitionRelationship", (opencascade::handle<StepRepr_PropertyDefinitionRelationship> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::PropertyDefinitionRelationship, "returns Value as a PropertyDefinitionRelationship (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP242_ItemIdentifiedRepresentationUsageDefinition::*)() const) &StepAP242_ItemIdentifiedRepresentationUsageDefinition::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// Enums

}