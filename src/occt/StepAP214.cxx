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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepAP214_Protocol.hxx>
#include <StepAP214_AutoDesignDateAndPersonItem.hxx>
#include <StepAP214_AutoDesignDateAndTimeItem.hxx>
#include <StepAP214_AutoDesignDatedItem.hxx>
#include <StepAP214_AutoDesignGeneralOrgItem.hxx>
#include <StepAP214_AutoDesignOrganizationItem.hxx>
#include <StepAP214_AutoDesignGroupedItem.hxx>
#include <StepAP214_AutoDesignPresentedItemSelect.hxx>
#include <StepAP214_AutoDesignReferencingItem.hxx>
#include <StepAP214_DateAndTimeItem.hxx>
#include <StepAP214_DateItem.hxx>
#include <StepAP214_ApprovalItem.hxx>
#include <StepAP214_OrganizationItem.hxx>
#include <StepAP214_DocumentReferenceItem.hxx>
#include <StepAP214_GroupItem.hxx>
#include <StepAP214_PersonAndOrganizationItem.hxx>
#include <StepAP214_PresentedItemSelect.hxx>
#include <StepAP214_SecurityClassificationItem.hxx>
#include <StepAP214_AutoDesignApprovalAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAssignment.hxx>
#include <StepAP214_AutoDesignGroupAssignment.hxx>
#include <StepAP214_AutoDesignOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <StepAP214_AutoDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPresentedItem.hxx>
#include <StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedPresentedItem.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <StepAP214_Class.hxx>
#include <StepAP214_ExternalIdentificationItem.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <StepAP214_RepItemGroup.hxx>
#include <StepAP214.hxx>
#include <StepData_SelectType.hxx>
#include <Standard_TypeDef.hxx>
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
#include <NCollection_Array1.hxx>
#include <StepAP214_Array1OfApprovalItem.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <StepAP214_HArray1OfApprovalItem.hxx>
#include <Standard_Type.hxx>
#include <StepBasic_ApprovalAssignment.hxx>
#include <StepBasic_Approval.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepAP214_Array1OfDateAndTimeItem.hxx>
#include <StepAP214_HArray1OfDateAndTimeItem.hxx>
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepAP214_Array1OfDateItem.hxx>
#include <StepAP214_HArray1OfDateItem.hxx>
#include <StepBasic_DateAssignment.hxx>
#include <StepBasic_DateRole.hxx>
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepAP214_Array1OfDocumentReferenceItem.hxx>
#include <StepAP214_HArray1OfDocumentReferenceItem.hxx>
#include <StepBasic_DocumentReference.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApprovalStatus.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_OrganizationalAddress.hxx>
#include <StepGeom_TrimmedCurve.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepAP214_Array1OfExternalIdentificationItem.hxx>
#include <StepAP214_HArray1OfExternalIdentificationItem.hxx>
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <StepRepr_RepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepAP214_Array1OfGroupItem.hxx>
#include <StepAP214_HArray1OfGroupItem.hxx>
#include <StepBasic_GroupAssignment.hxx>
#include <StepAP214_Array1OfOrganizationItem.hxx>
#include <StepAP214_HArray1OfOrganizationItem.hxx>
#include <StepBasic_OrganizationAssignment.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <StepAP214_Array1OfPersonAndOrganizationItem.hxx>
#include <StepAP214_HArray1OfPersonAndOrganizationItem.hxx>
#include <StepBasic_PersonAndOrganizationAssignment.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepAP214_Array1OfPresentedItemSelect.hxx>
#include <StepAP214_HArray1OfPresentedItemSelect.hxx>
#include <StepVisual_PresentedItem.hxx>
#include <StepBasic_Action.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepVisual_DraughtingModel.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <StepRepr_MakeFromUsageOption.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <StepRepr_ProductDefinitionUsage.hxx>
#include <StepAP214_Array1OfSecurityClassificationItem.hxx>
#include <StepAP214_HArray1OfSecurityClassificationItem.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <StepRepr_ExternallyDefinedRepresentation.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <StepAP214_Array1OfAutoDesignDateAndPersonItem.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <StepAP214_Array1OfAutoDesignDateAndTimeItem.hxx>
#include <StepAP214_Array1OfAutoDesignDatedItem.hxx>
#include <StepAP214_Array1OfAutoDesignGeneralOrgItem.hxx>
#include <StepShape_AdvancedBrepShapeRepresentation.hxx>
#include <StepShape_CsgShapeRepresentation.hxx>
#include <StepShape_FacetedBrepShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedSurfaceShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedWireframeShapeRepresentation.hxx>
#include <StepShape_ManifoldSurfaceShapeRepresentation.hxx>
#include <StepVisual_TemplateInstance.hxx>
#include <StepAP214_Array1OfAutoDesignGroupedItem.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <StepBasic_DocumentRelationship.hxx>
#include <StepAP214_Array1OfAutoDesignPresentedItemSelect.hxx>
#include <StepVisual_PresentationView.hxx>
#include <StepAP214_Array1OfAutoDesignReferencingItem.hxx>
#include <StepAP214_HArray1OfAutoDesignDateAndTimeItem.hxx>
#include <StepAP214_HArray1OfAutoDesignDatedItem.hxx>
#include <StepAP214_HArray1OfAutoDesignGeneralOrgItem.hxx>
#include <StepAP214_HArray1OfAutoDesignDateAndPersonItem.hxx>
#include <StepAP214_HArray1OfAutoDesignReferencingItem.hxx>
#include <StepAP214_HArray1OfAutoDesignGroupedItem.hxx>
#include <StepBasic_PhysicallyModeledProductDefinition.hxx>
#include <StepAP214_HArray1OfAutoDesignPresentedItemSelect.hxx>
#include <StepBasic_HArray1OfApproval.hxx>
#include <StepBasic_SourceItem.hxx>
#include <StepData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>

PYBIND11_MODULE(StepAP214, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepVisual");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.Interface");

// CLASS: STEPAP214
py::class_<StepAP214> cls_StepAP214(mod, "StepAP214", "Complete AP214 CC1 , Revision 4 Upgrading from Revision 2 to Revision 4 : 26 Mar 1997 Splitting in sub-schemas : 5 Nov 1997");

// Constructors
cls_StepAP214.def(py::init<>());

// Methods
// cls_StepAP214.def_static("operator new_", (void * (*)(size_t)) &StepAP214::operator new, "None", py::arg("theSize"));
// cls_StepAP214.def_static("operator delete_", (void (*)(void *)) &StepAP214::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214::operator new[], "None", py::arg("theSize"));
// cls_StepAP214.def_static("operator delete[]_", (void (*)(void *)) &StepAP214::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214.def_static("Protocol_", (opencascade::handle<StepAP214_Protocol> (*)()) &StepAP214::Protocol, "creates a Protocol");

// CLASS: STEPAP214_APPROVALITEM
py::class_<StepAP214_ApprovalItem, StepData_SelectType> cls_StepAP214_ApprovalItem(mod, "StepAP214_ApprovalItem", "None");

// Constructors
cls_StepAP214_ApprovalItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFAPPROVALITEM
bind_NCollection_Array1<StepAP214_ApprovalItem>(mod, "StepAP214_Array1OfApprovalItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFAPPROVALITEM
bind_Define_HArray1<StepAP214_HArray1OfApprovalItem, StepAP214_Array1OfApprovalItem>(mod, "StepAP214_HArray1OfApprovalItem");

// CLASS: STEPAP214_APPLIEDAPPROVALASSIGNMENT
py::class_<StepAP214_AppliedApprovalAssignment, opencascade::handle<StepAP214_AppliedApprovalAssignment>, StepBasic_ApprovalAssignment> cls_StepAP214_AppliedApprovalAssignment(mod, "StepAP214_AppliedApprovalAssignment", "None");

// Constructors
cls_StepAP214_AppliedApprovalAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedApprovalAssignment.def("Init", (void (StepAP214_AppliedApprovalAssignment::*)(const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepAP214_HArray1OfApprovalItem> &)) &StepAP214_AppliedApprovalAssignment::Init, "None", py::arg("aAssignedApproval"), py::arg("aItems"));
cls_StepAP214_AppliedApprovalAssignment.def("SetItems", (void (StepAP214_AppliedApprovalAssignment::*)(const opencascade::handle<StepAP214_HArray1OfApprovalItem> &)) &StepAP214_AppliedApprovalAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedApprovalAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfApprovalItem> (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::Items, "None");
cls_StepAP214_AppliedApprovalAssignment.def("ItemsValue", (StepAP214_ApprovalItem (StepAP214_AppliedApprovalAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedApprovalAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedApprovalAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::NbItems, "None");
cls_StepAP214_AppliedApprovalAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedApprovalAssignment::get_type_name, "None");
cls_StepAP214_AppliedApprovalAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedApprovalAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedApprovalAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedApprovalAssignment::*)() const) &StepAP214_AppliedApprovalAssignment::DynamicType, "None");

// CLASS: STEPAP214_DATEANDTIMEITEM
py::class_<StepAP214_DateAndTimeItem, StepAP214_ApprovalItem> cls_StepAP214_DateAndTimeItem(mod, "StepAP214_DateAndTimeItem", "None");

// Constructors
cls_StepAP214_DateAndTimeItem.def(py::init<>());

// Methods
// cls_StepAP214_DateAndTimeItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_DateAndTimeItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_DateAndTimeItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_DateAndTimeItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_DateAndTimeItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_DateAndTimeItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_DateAndTimeItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_DateAndTimeItem.def("CaseNum", (Standard_Integer (StepAP214_DateAndTimeItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_DateAndTimeItem::CaseNum, "Recognizes a DateAndTimeItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AppliedDateAndPersonAssignment 3 -> AppliedOrganizationAssignment 4 -> AssemblyComponentUsageSubstitute 5 -> DocumentFile 6 -> Effectivity 7 -> MaterialDesignation 8 -> MechanicalDesignGeometricPresentationRepresentation 9 -> PresentationArea 10 -> Product 11 -> ProductDefinition 12 -> ProductDefinitionFormation 13 -> ProductDefinitionRelationship 14 -> PropertyDefinition 15 -> ShapeRepresentation 16 -> SecurityClassification 0 else", py::arg("ent"));
cls_StepAP214_DateAndTimeItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_DateAndTimeItem.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::AppliedPersonAndOrganizationAssignment, "returns Value as a AppliedDateAndPersonAssignment (Null if another type)");
cls_StepAP214_DateAndTimeItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFDATEANDTIMEITEM
bind_NCollection_Array1<StepAP214_DateAndTimeItem>(mod, "StepAP214_Array1OfDateAndTimeItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFDATEANDTIMEITEM
bind_Define_HArray1<StepAP214_HArray1OfDateAndTimeItem, StepAP214_Array1OfDateAndTimeItem>(mod, "StepAP214_HArray1OfDateAndTimeItem");

// CLASS: STEPAP214_APPLIEDDATEANDTIMEASSIGNMENT
py::class_<StepAP214_AppliedDateAndTimeAssignment, opencascade::handle<StepAP214_AppliedDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP214_AppliedDateAndTimeAssignment(mod, "StepAP214_AppliedDateAndTimeAssignment", "None");

// Constructors
cls_StepAP214_AppliedDateAndTimeAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedDateAndTimeAssignment.def("Init", (void (StepAP214_AppliedDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP214_HArray1OfDateAndTimeItem> &)) &StepAP214_AppliedDateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedDateAndTimeAssignment.def("SetItems", (void (StepAP214_AppliedDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_HArray1OfDateAndTimeItem> &)) &StepAP214_AppliedDateAndTimeAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfDateAndTimeItem> (StepAP214_AppliedDateAndTimeAssignment::*)() const) &StepAP214_AppliedDateAndTimeAssignment::Items, "None");
cls_StepAP214_AppliedDateAndTimeAssignment.def("ItemsValue", (StepAP214_DateAndTimeItem (StepAP214_AppliedDateAndTimeAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedDateAndTimeAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedDateAndTimeAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedDateAndTimeAssignment::*)() const) &StepAP214_AppliedDateAndTimeAssignment::NbItems, "None");
cls_StepAP214_AppliedDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedDateAndTimeAssignment::get_type_name, "None");
cls_StepAP214_AppliedDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedDateAndTimeAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedDateAndTimeAssignment::*)() const) &StepAP214_AppliedDateAndTimeAssignment::DynamicType, "None");

// CLASS: STEPAP214_DATEITEM
py::class_<StepAP214_DateItem, StepAP214_ApprovalItem> cls_StepAP214_DateItem(mod, "StepAP214_DateItem", "None");

// Constructors
cls_StepAP214_DateItem.def(py::init<>());

// Methods
// cls_StepAP214_DateItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_DateItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_DateItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_DateItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_DateItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_DateItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_DateItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_DateItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_DateItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_DateItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_DateItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_DateItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_DateItem.def("CaseNum", (Standard_Integer (StepAP214_DateItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_DateItem::CaseNum, "Recognizes a DateItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AppliedDateAndPersonAssignment 3 -> AppliedOrganizationAssignment 4 -> AssemblyComponentUsageSubstitute 5 -> DocumentFile 6 -> Effectivity 7 -> MaterialDesignation 8 -> MechanicalDesignGeometricPresentationRepresentation 9 -> PresentationArea 10 -> Product 11 -> ProductDefinition 12 -> ProductDefinitionFormation 13 -> ProductDefinitionRelationship 14 -> PropertyDefinition 15 -> ShapeRepresentation 16 -> AppliedSecurityClassificationAssignment 17 -> Document 0 else", py::arg("ent"));
cls_StepAP214_DateItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_DateItem::*)() const) &StepAP214_DateItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_DateItem.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP214_DateItem::*)() const) &StepAP214_DateItem::AppliedPersonAndOrganizationAssignment, "returns Value as a AppliedDateAndPersonAssignment (Null if another type)");
cls_StepAP214_DateItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_DateItem::*)() const) &StepAP214_DateItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");
cls_StepAP214_DateItem.def("AppliedSecurityClassificationAssignment", (opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> (StepAP214_DateItem::*)() const) &StepAP214_DateItem::AppliedSecurityClassificationAssignment, "returns Value as a AppliedSecurityClassificationAssignment (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFDATEITEM
bind_NCollection_Array1<StepAP214_DateItem>(mod, "StepAP214_Array1OfDateItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFDATEITEM
bind_Define_HArray1<StepAP214_HArray1OfDateItem, StepAP214_Array1OfDateItem>(mod, "StepAP214_HArray1OfDateItem");

// CLASS: STEPAP214_APPLIEDDATEASSIGNMENT
py::class_<StepAP214_AppliedDateAssignment, opencascade::handle<StepAP214_AppliedDateAssignment>, StepBasic_DateAssignment> cls_StepAP214_AppliedDateAssignment(mod, "StepAP214_AppliedDateAssignment", "None");

// Constructors
cls_StepAP214_AppliedDateAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedDateAssignment.def("Init", (void (StepAP214_AppliedDateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &, const opencascade::handle<StepAP214_HArray1OfDateItem> &)) &StepAP214_AppliedDateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedDateAssignment.def("SetItems", (void (StepAP214_AppliedDateAssignment::*)(const opencascade::handle<StepAP214_HArray1OfDateItem> &)) &StepAP214_AppliedDateAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedDateAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfDateItem> (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::Items, "None");
cls_StepAP214_AppliedDateAssignment.def("ItemsValue", (StepAP214_DateItem (StepAP214_AppliedDateAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedDateAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedDateAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::NbItems, "None");
cls_StepAP214_AppliedDateAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedDateAssignment::get_type_name, "None");
cls_StepAP214_AppliedDateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedDateAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedDateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedDateAssignment::*)() const) &StepAP214_AppliedDateAssignment::DynamicType, "None");

// CLASS: STEPAP214_DOCUMENTREFERENCEITEM
py::class_<StepAP214_DocumentReferenceItem, StepData_SelectType> cls_StepAP214_DocumentReferenceItem(mod, "StepAP214_DocumentReferenceItem", "None");

// Constructors
cls_StepAP214_DocumentReferenceItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFDOCUMENTREFERENCEITEM
bind_NCollection_Array1<StepAP214_DocumentReferenceItem>(mod, "StepAP214_Array1OfDocumentReferenceItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFDOCUMENTREFERENCEITEM
bind_Define_HArray1<StepAP214_HArray1OfDocumentReferenceItem, StepAP214_Array1OfDocumentReferenceItem>(mod, "StepAP214_HArray1OfDocumentReferenceItem");

// CLASS: STEPAP214_APPLIEDDOCUMENTREFERENCE
py::class_<StepAP214_AppliedDocumentReference, opencascade::handle<StepAP214_AppliedDocumentReference>, StepBasic_DocumentReference> cls_StepAP214_AppliedDocumentReference(mod, "StepAP214_AppliedDocumentReference", "None");

// Constructors
cls_StepAP214_AppliedDocumentReference.def(py::init<>());

// Methods
cls_StepAP214_AppliedDocumentReference.def("Init", (void (StepAP214_AppliedDocumentReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> &)) &StepAP214_AppliedDocumentReference::Init, "None", py::arg("aAssignedDocument"), py::arg("aSource"), py::arg("aItems"));
cls_StepAP214_AppliedDocumentReference.def("Items", (opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::Items, "None");
cls_StepAP214_AppliedDocumentReference.def("SetItems", (void (StepAP214_AppliedDocumentReference::*)(const opencascade::handle<StepAP214_HArray1OfDocumentReferenceItem> &)) &StepAP214_AppliedDocumentReference::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedDocumentReference.def("ItemsValue", (StepAP214_DocumentReferenceItem (StepAP214_AppliedDocumentReference::*)(const Standard_Integer) const) &StepAP214_AppliedDocumentReference::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedDocumentReference.def("NbItems", (Standard_Integer (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::NbItems, "None");
cls_StepAP214_AppliedDocumentReference.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedDocumentReference::get_type_name, "None");
cls_StepAP214_AppliedDocumentReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedDocumentReference::get_type_descriptor, "None");
cls_StepAP214_AppliedDocumentReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedDocumentReference::*)() const) &StepAP214_AppliedDocumentReference::DynamicType, "None");

// CLASS: STEPAP214_EXTERNALIDENTIFICATIONITEM
py::class_<StepAP214_ExternalIdentificationItem, StepData_SelectType> cls_StepAP214_ExternalIdentificationItem(mod, "StepAP214_ExternalIdentificationItem", "Representation of STEP SELECT type ExternalIdentificationItem");

// Constructors
cls_StepAP214_ExternalIdentificationItem.def(py::init<>());

// Methods
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_ExternalIdentificationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_ExternalIdentificationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_ExternalIdentificationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_ExternalIdentificationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_ExternalIdentificationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_ExternalIdentificationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_ExternalIdentificationItem.def("CaseNum", (Standard_Integer (StepAP214_ExternalIdentificationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_ExternalIdentificationItem::CaseNum, "Recognizes a kind of ExternalIdentificationItem select type 1 -> DocumentFile from StepBasic 2 -> ExternallyDefinedClass from StepAP214 3 -> ExternallyDefinedGeneralProperty from StepAP214 4 -> ProductDefinition from StepBasic 5 -> AppliedOrganizationAssignment from AP214 6 -> AppliedPersonAndOrganizationAssignment from AP214 7 -> Approval from StepBasic 8 -> ApprovalStatus from StepBasic 9 -> ExternalSource from StepBasic 10 -> OrganizationalAddress from StepBasic 11 -> SecurityClassification from StepBasic 12 -> TrimmedCurve from StepGeom 13 -> VersionedActionRequest from StepBasic 14 -> DateAndTimeAssignment from StepBasic 15 -> DateAssignment from StepBasic 0 else", py::arg("ent"));
cls_StepAP214_ExternalIdentificationItem.def("DocumentFile", (opencascade::handle<StepBasic_DocumentFile> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DocumentFile, "Returns Value as DocumentFile (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternallyDefinedClass", (opencascade::handle<StepAP214_ExternallyDefinedClass> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternallyDefinedClass, "Returns Value as ExternallyDefinedClass (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternallyDefinedGeneralProperty", (opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternallyDefinedGeneralProperty, "Returns Value as ExternallyDefinedGeneralProperty (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::AppliedOrganizationAssignment, "Returns Value as AppliedOrganizationAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::AppliedPersonAndOrganizationAssignment, "Returns Value as AppliedPersonAndOrganizationAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::Approval, "Returns Value as Approval (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ApprovalStatus", (opencascade::handle<StepBasic_ApprovalStatus> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ApprovalStatus, "Returns Value as ApprovalStatus (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternalSource", (opencascade::handle<StepBasic_ExternalSource> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternalSource, "Returns Value as ExternalSource (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("OrganizationalAddress", (opencascade::handle<StepBasic_OrganizationalAddress> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::OrganizationalAddress, "Returns Value as OrganizationalAddress (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("TrimmedCurve", (opencascade::handle<StepGeom_TrimmedCurve> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::TrimmedCurve, "Returns Value as TrimmedCurve (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("VersionedActionRequest", (opencascade::handle<StepBasic_VersionedActionRequest> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::VersionedActionRequest, "Returns Value as VersionedActionRequest (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("DateAndTimeAssignment", (opencascade::handle<StepBasic_DateAndTimeAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DateAndTimeAssignment, "Returns Value as DateAndTimeAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("DateAssignment", (opencascade::handle<StepBasic_DateAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DateAssignment, "Returns Value as DateAssignment (or Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFEXTERNALIDENTIFICATIONITEM
bind_NCollection_Array1<StepAP214_ExternalIdentificationItem>(mod, "StepAP214_Array1OfExternalIdentificationItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFEXTERNALIDENTIFICATIONITEM
bind_Define_HArray1<StepAP214_HArray1OfExternalIdentificationItem, StepAP214_Array1OfExternalIdentificationItem>(mod, "StepAP214_HArray1OfExternalIdentificationItem");

// CLASS: STEPAP214_APPLIEDEXTERNALIDENTIFICATIONASSIGNMENT
py::class_<StepAP214_AppliedExternalIdentificationAssignment, opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment>, StepBasic_ExternalIdentificationAssignment> cls_StepAP214_AppliedExternalIdentificationAssignment(mod, "StepAP214_AppliedExternalIdentificationAssignment", "Representation of STEP entity AppliedExternalIdentificationAssignment");

// Constructors
cls_StepAP214_AppliedExternalIdentificationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedExternalIdentificationAssignment.def("Init", (void (StepAP214_AppliedExternalIdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_IdentificationRole> &, const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> &)) &StepAP214_AppliedExternalIdentificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aIdentificationAssignment_AssignedId"), py::arg("aIdentificationAssignment_Role"), py::arg("aExternalIdentificationAssignment_Source"), py::arg("aItems"));
cls_StepAP214_AppliedExternalIdentificationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> (StepAP214_AppliedExternalIdentificationAssignment::*)() const) &StepAP214_AppliedExternalIdentificationAssignment::Items, "Returns field Items");
cls_StepAP214_AppliedExternalIdentificationAssignment.def("SetItems", (void (StepAP214_AppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfExternalIdentificationItem> &)) &StepAP214_AppliedExternalIdentificationAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP214_AppliedExternalIdentificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedExternalIdentificationAssignment::get_type_name, "None");
cls_StepAP214_AppliedExternalIdentificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedExternalIdentificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedExternalIdentificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedExternalIdentificationAssignment::*)() const) &StepAP214_AppliedExternalIdentificationAssignment::DynamicType, "None");

// CLASS: STEPAP214_GROUPITEM
py::class_<StepAP214_GroupItem, StepData_SelectType> cls_StepAP214_GroupItem(mod, "StepAP214_GroupItem", "None");

// Constructors
cls_StepAP214_GroupItem.def(py::init<>());

// Methods
// cls_StepAP214_GroupItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_GroupItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_GroupItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_GroupItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_GroupItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_GroupItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_GroupItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_GroupItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_GroupItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_GroupItem.def("CaseNum", (Standard_Integer (StepAP214_GroupItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_GroupItem::CaseNum, "Recognizes a GroupItem Kind Entity that is : 1 -> GeometricRepresentationItem 2 -> GroupRelationship 3 -> MappedItem 4 -> ProductDefinition 5 -> ProductDefinitionFormation 6 -> PropertyDefinitionRepresentation 7 -> Representation 8 -> RepresentationItem 9 -> RepresentationRelationshipWithTransformation 10 -> ShapeAspect 11 -> ShapeAspectRelationship 12 -> ShapeRepresentationRelationship 13 -> StyledItem 14 -> TopologicalRepresentationItem 0 else", py::arg("ent"));
cls_StepAP214_GroupItem.def("GeometricRepresentationItem", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::GeometricRepresentationItem, "returns Value as a GeometricRepresentationItem (Null if another type)");
cls_StepAP214_GroupItem.def("GroupRelationship", (opencascade::handle<StepBasic_GroupRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::GroupRelationship, "returns Value as a GroupRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("MappedItem", (opencascade::handle<StepRepr_MappedItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::MappedItem, "returns Value as a MappedItem (Null if another type)");
cls_StepAP214_GroupItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_GroupItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ProductDefinitionFormation, "returns Value as a ProductDefinitionFormation (Null if another type)");
cls_StepAP214_GroupItem.def("PropertyDefinitionRepresentation", (opencascade::handle<StepRepr_PropertyDefinitionRepresentation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::PropertyDefinitionRepresentation, "returns Value as a PropertyDefinitionRepresentation (Null if another type)");
cls_StepAP214_GroupItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_GroupItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
cls_StepAP214_GroupItem.def("RepresentationRelationshipWithTransformation", (opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::RepresentationRelationshipWithTransformation, "returns Value as a RepresentationRelationshipWithTransformation (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeRepresentationRelationship", (opencascade::handle<StepRepr_ShapeRepresentationRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeRepresentationRelationship, "returns Value as a ShapeRepresentationRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("StyledItem", (opencascade::handle<StepVisual_StyledItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::StyledItem, "returns Value as a StyledItem (Null if another type)");
cls_StepAP214_GroupItem.def("TopologicalRepresentationItem", (opencascade::handle<StepShape_TopologicalRepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::TopologicalRepresentationItem, "returns Value as a TopologicalRepresentationItem (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFGROUPITEM
bind_NCollection_Array1<StepAP214_GroupItem>(mod, "StepAP214_Array1OfGroupItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFGROUPITEM
bind_Define_HArray1<StepAP214_HArray1OfGroupItem, StepAP214_Array1OfGroupItem>(mod, "StepAP214_HArray1OfGroupItem");

// CLASS: STEPAP214_APPLIEDGROUPASSIGNMENT
py::class_<StepAP214_AppliedGroupAssignment, opencascade::handle<StepAP214_AppliedGroupAssignment>, StepBasic_GroupAssignment> cls_StepAP214_AppliedGroupAssignment(mod, "StepAP214_AppliedGroupAssignment", "Representation of STEP entity AppliedGroupAssignment");

// Constructors
cls_StepAP214_AppliedGroupAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedGroupAssignment.def("Init", (void (StepAP214_AppliedGroupAssignment::*)(const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepAP214_HArray1OfGroupItem> &)) &StepAP214_AppliedGroupAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aGroupAssignment_AssignedGroup"), py::arg("aItems"));
cls_StepAP214_AppliedGroupAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfGroupItem> (StepAP214_AppliedGroupAssignment::*)() const) &StepAP214_AppliedGroupAssignment::Items, "Returns field Items");
cls_StepAP214_AppliedGroupAssignment.def("SetItems", (void (StepAP214_AppliedGroupAssignment::*)(const opencascade::handle<StepAP214_HArray1OfGroupItem> &)) &StepAP214_AppliedGroupAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP214_AppliedGroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedGroupAssignment::get_type_name, "None");
cls_StepAP214_AppliedGroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedGroupAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedGroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedGroupAssignment::*)() const) &StepAP214_AppliedGroupAssignment::DynamicType, "None");

// CLASS: STEPAP214_ORGANIZATIONITEM
py::class_<StepAP214_OrganizationItem, StepAP214_ApprovalItem> cls_StepAP214_OrganizationItem(mod, "StepAP214_OrganizationItem", "None");

// Constructors
cls_StepAP214_OrganizationItem.def(py::init<>());

// Methods
// cls_StepAP214_OrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_OrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_OrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_OrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_OrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_OrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_OrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_OrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_OrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_OrganizationItem.def("CaseNum", (Standard_Integer (StepAP214_OrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_OrganizationItem::CaseNum, "Recognizes a OrganizationItem Kind Entity that is :", py::arg("ent"));
cls_StepAP214_OrganizationItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");
cls_StepAP214_OrganizationItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::Approval, "returns Value as a Approval (Null if another type)");
cls_StepAP214_OrganizationItem.def("AppliedSecurityClassificationAssignment", (opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::AppliedSecurityClassificationAssignment, "returns Value as a AppliedSecurityClassificationAssignment (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFORGANIZATIONITEM
bind_NCollection_Array1<StepAP214_OrganizationItem>(mod, "StepAP214_Array1OfOrganizationItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFORGANIZATIONITEM
bind_Define_HArray1<StepAP214_HArray1OfOrganizationItem, StepAP214_Array1OfOrganizationItem>(mod, "StepAP214_HArray1OfOrganizationItem");

// CLASS: STEPAP214_APPLIEDORGANIZATIONASSIGNMENT
py::class_<StepAP214_AppliedOrganizationAssignment, opencascade::handle<StepAP214_AppliedOrganizationAssignment>, StepBasic_OrganizationAssignment> cls_StepAP214_AppliedOrganizationAssignment(mod, "StepAP214_AppliedOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AppliedOrganizationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedOrganizationAssignment.def("Init", (void (StepAP214_AppliedOrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &, const opencascade::handle<StepBasic_OrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfOrganizationItem> &)) &StepAP214_AppliedOrganizationAssignment::Init, "None", py::arg("aAssignedOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedOrganizationAssignment.def("SetItems", (void (StepAP214_AppliedOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfOrganizationItem> &)) &StepAP214_AppliedOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfOrganizationItem> (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::Items, "None");
cls_StepAP214_AppliedOrganizationAssignment.def("ItemsValue", (StepAP214_OrganizationItem (StepAP214_AppliedOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::NbItems, "None");
cls_StepAP214_AppliedOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AppliedOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::DynamicType, "None");

// CLASS: STEPAP214_PERSONANDORGANIZATIONITEM
py::class_<StepAP214_PersonAndOrganizationItem, StepAP214_ApprovalItem> cls_StepAP214_PersonAndOrganizationItem(mod, "StepAP214_PersonAndOrganizationItem", "None");

// Constructors
cls_StepAP214_PersonAndOrganizationItem.def(py::init<>());

// Methods
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_PersonAndOrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_PersonAndOrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_PersonAndOrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_PersonAndOrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_PersonAndOrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_PersonAndOrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_PersonAndOrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_PersonAndOrganizationItem.def("CaseNum", (Standard_Integer (StepAP214_PersonAndOrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_PersonAndOrganizationItem::CaseNum, "Recognizes a APersonAndOrganizationItem Kind Entity that is : 1 -> AppliedOrganizationAssignment 2 -> AssemblyComponentUsageSubstitute 3 -> DocumentFile 4 -> MaterialDesignation 5 -> MechanicalDesignGeometricPresentationRepresentation 6 -> PresentationArea 7 -> Product 8 -> ProductDefinition 9 -> ProductDefinitionFormation 10 -> ProductDefinitionRelationship 11 -> PropertyDefinition 12 -> ShapeRepresentation 13 -> SecurityClassification 14 -> AppliedSecurityClassificationAssignment 15 -> Approval 0 else", py::arg("ent"));
cls_StepAP214_PersonAndOrganizationItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_PersonAndOrganizationItem::*)() const) &StepAP214_PersonAndOrganizationItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");
cls_StepAP214_PersonAndOrganizationItem.def("AppliedSecurityClassificationAssignment", (opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> (StepAP214_PersonAndOrganizationItem::*)() const) &StepAP214_PersonAndOrganizationItem::AppliedSecurityClassificationAssignment, "returns Value as a AppliedSecurityClassificationAssignment (Null if another type)");
cls_StepAP214_PersonAndOrganizationItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_PersonAndOrganizationItem::*)() const) &StepAP214_PersonAndOrganizationItem::Approval, "returns Value as a Approval (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFPERSONANDORGANIZATIONITEM
bind_NCollection_Array1<StepAP214_PersonAndOrganizationItem>(mod, "StepAP214_Array1OfPersonAndOrganizationItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFPERSONANDORGANIZATIONITEM
bind_Define_HArray1<StepAP214_HArray1OfPersonAndOrganizationItem, StepAP214_Array1OfPersonAndOrganizationItem>(mod, "StepAP214_HArray1OfPersonAndOrganizationItem");

// CLASS: STEPAP214_APPLIEDPERSONANDORGANIZATIONASSIGNMENT
py::class_<StepAP214_AppliedPersonAndOrganizationAssignment, opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP214_AppliedPersonAndOrganizationAssignment(mod, "StepAP214_AppliedPersonAndOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("Init", (void (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> &)) &StepAP214_AppliedPersonAndOrganizationAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("SetItems", (void (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> &)) &StepAP214_AppliedPersonAndOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::Items, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("ItemsValue", (StepAP214_PersonAndOrganizationItem (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedPersonAndOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::NbItems, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedPersonAndOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedPersonAndOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::DynamicType, "None");

// CLASS: STEPAP214_PRESENTEDITEMSELECT
py::class_<StepAP214_PresentedItemSelect, StepData_SelectType> cls_StepAP214_PresentedItemSelect(mod, "StepAP214_PresentedItemSelect", "None");

// Constructors
cls_StepAP214_PresentedItemSelect.def(py::init<>());

// Methods
// cls_StepAP214_PresentedItemSelect.def_static("operator new_", (void * (*)(size_t)) &StepAP214_PresentedItemSelect::operator new, "None", py::arg("theSize"));
// cls_StepAP214_PresentedItemSelect.def_static("operator delete_", (void (*)(void *)) &StepAP214_PresentedItemSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_PresentedItemSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_PresentedItemSelect::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_PresentedItemSelect.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_PresentedItemSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_PresentedItemSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_PresentedItemSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_PresentedItemSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_PresentedItemSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_PresentedItemSelect.def("CaseNum", (Standard_Integer (StepAP214_PresentedItemSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_PresentedItemSelect::CaseNum, "Recognizes a PresentedItemSelect Kind Entity that is : 1 -> ProductDefinition, 2 -> ProductDefinitionRelationship, 0 else", py::arg("ent"));
cls_StepAP214_PresentedItemSelect.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_PresentedItemSelect::*)() const) &StepAP214_PresentedItemSelect::ProductDefinitionRelationship, "returns Value as a ProductDefinitionRelationship (Null if another type)");
cls_StepAP214_PresentedItemSelect.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_PresentedItemSelect::*)() const) &StepAP214_PresentedItemSelect::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFPRESENTEDITEMSELECT
bind_NCollection_Array1<StepAP214_PresentedItemSelect>(mod, "StepAP214_Array1OfPresentedItemSelect", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFPRESENTEDITEMSELECT
bind_Define_HArray1<StepAP214_HArray1OfPresentedItemSelect, StepAP214_Array1OfPresentedItemSelect>(mod, "StepAP214_HArray1OfPresentedItemSelect");

// CLASS: STEPAP214_APPLIEDPRESENTEDITEM
py::class_<StepAP214_AppliedPresentedItem, opencascade::handle<StepAP214_AppliedPresentedItem>, StepVisual_PresentedItem> cls_StepAP214_AppliedPresentedItem(mod, "StepAP214_AppliedPresentedItem", "None");

// Constructors
cls_StepAP214_AppliedPresentedItem.def(py::init<>());

// Methods
cls_StepAP214_AppliedPresentedItem.def("Init", (void (StepAP214_AppliedPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfPresentedItemSelect> &)) &StepAP214_AppliedPresentedItem::Init, "None", py::arg("aItems"));
cls_StepAP214_AppliedPresentedItem.def("SetItems", (void (StepAP214_AppliedPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfPresentedItemSelect> &)) &StepAP214_AppliedPresentedItem::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedPresentedItem.def("Items", (opencascade::handle<StepAP214_HArray1OfPresentedItemSelect> (StepAP214_AppliedPresentedItem::*)() const) &StepAP214_AppliedPresentedItem::Items, "None");
cls_StepAP214_AppliedPresentedItem.def("ItemsValue", (StepAP214_PresentedItemSelect (StepAP214_AppliedPresentedItem::*)(const Standard_Integer) const) &StepAP214_AppliedPresentedItem::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedPresentedItem.def("NbItems", (Standard_Integer (StepAP214_AppliedPresentedItem::*)() const) &StepAP214_AppliedPresentedItem::NbItems, "None");
cls_StepAP214_AppliedPresentedItem.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedPresentedItem::get_type_name, "None");
cls_StepAP214_AppliedPresentedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedPresentedItem::get_type_descriptor, "None");
cls_StepAP214_AppliedPresentedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedPresentedItem::*)() const) &StepAP214_AppliedPresentedItem::DynamicType, "None");

// CLASS: STEPAP214_SECURITYCLASSIFICATIONITEM
py::class_<StepAP214_SecurityClassificationItem, StepAP214_ApprovalItem> cls_StepAP214_SecurityClassificationItem(mod, "StepAP214_SecurityClassificationItem", "None");

// Constructors
cls_StepAP214_SecurityClassificationItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFSECURITYCLASSIFICATIONITEM
bind_NCollection_Array1<StepAP214_SecurityClassificationItem>(mod, "StepAP214_Array1OfSecurityClassificationItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFSECURITYCLASSIFICATIONITEM
bind_Define_HArray1<StepAP214_HArray1OfSecurityClassificationItem, StepAP214_Array1OfSecurityClassificationItem>(mod, "StepAP214_HArray1OfSecurityClassificationItem");

// CLASS: STEPAP214_APPLIEDSECURITYCLASSIFICATIONASSIGNMENT
py::class_<StepAP214_AppliedSecurityClassificationAssignment, opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment>, StepBasic_SecurityClassificationAssignment> cls_StepAP214_AppliedSecurityClassificationAssignment(mod, "StepAP214_AppliedSecurityClassificationAssignment", "None");

// Constructors
cls_StepAP214_AppliedSecurityClassificationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AppliedSecurityClassificationAssignment.def("Init", (void (StepAP214_AppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &, const opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> &)) &StepAP214_AppliedSecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"), py::arg("aItems"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("SetItems", (void (StepAP214_AppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> &)) &StepAP214_AppliedSecurityClassificationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfSecurityClassificationItem> (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::Items, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def("ItemsValue", (const StepAP214_SecurityClassificationItem & (StepAP214_AppliedSecurityClassificationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedSecurityClassificationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedSecurityClassificationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::NbItems, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedSecurityClassificationAssignment::get_type_name, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedSecurityClassificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedSecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedSecurityClassificationAssignment::*)() const) &StepAP214_AppliedSecurityClassificationAssignment::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNDATEANDPERSONITEM
py::class_<StepAP214_AutoDesignDateAndPersonItem, StepData_SelectType> cls_StepAP214_AutoDesignDateAndPersonItem(mod, "StepAP214_AutoDesignDateAndPersonItem", "None");

// Constructors
cls_StepAP214_AutoDesignDateAndPersonItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNDATEANDPERSONITEM
bind_NCollection_Array1<StepAP214_AutoDesignDateAndPersonItem>(mod, "StepAP214_Array1OfAutoDesignDateAndPersonItem", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNDATEANDTIMEITEM
py::class_<StepAP214_AutoDesignDateAndTimeItem, StepData_SelectType> cls_StepAP214_AutoDesignDateAndTimeItem(mod, "StepAP214_AutoDesignDateAndTimeItem", "None");

// Constructors
cls_StepAP214_AutoDesignDateAndTimeItem.def(py::init<>());

// Methods
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignDateAndTimeItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignDateAndTimeItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignDateAndTimeItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignDateAndTimeItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignDateAndTimeItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignDateAndTimeItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignDateAndTimeItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignDateAndTimeItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignDateAndTimeItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignDateAndTimeItem::CaseNum, "Recognizes a AutoDesignDateAndTimeItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AutoDesignDateAndPersonAssignment 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignDateAndTimeItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_AutoDesignDateAndTimeItem::*)() const) &StepAP214_AutoDesignDateAndTimeItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_AutoDesignDateAndTimeItem.def("AutoDesignDateAndPersonAssignment", (opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> (StepAP214_AutoDesignDateAndTimeItem::*)() const) &StepAP214_AutoDesignDateAndTimeItem::AutoDesignDateAndPersonAssignment, "returns Value as a AutoDesignDateAndPersonAssignment (Null if another type)");
cls_StepAP214_AutoDesignDateAndTimeItem.def("ProductDefinitionEffectivity", (opencascade::handle<StepBasic_ProductDefinitionEffectivity> (StepAP214_AutoDesignDateAndTimeItem::*)() const) &StepAP214_AutoDesignDateAndTimeItem::ProductDefinitionEffectivity, "None");

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNDATEANDTIMEITEM
bind_NCollection_Array1<StepAP214_AutoDesignDateAndTimeItem>(mod, "StepAP214_Array1OfAutoDesignDateAndTimeItem", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNDATEDITEM
py::class_<StepAP214_AutoDesignDatedItem, StepData_SelectType> cls_StepAP214_AutoDesignDatedItem(mod, "StepAP214_AutoDesignDatedItem", "None");

// Constructors
cls_StepAP214_AutoDesignDatedItem.def(py::init<>());

// Methods
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignDatedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignDatedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignDatedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignDatedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignDatedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignDatedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignDatedItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignDatedItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignDatedItem::CaseNum, "Recognizes a AutoDesignDatedItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AutoDesignDateAndPersonAssignment 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignDatedItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_AutoDesignDatedItem.def("AutoDesignDateAndPersonAssignment", (opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::AutoDesignDateAndPersonAssignment, "returns Value as a AutoDesignDateAndPersonAssignment (Null if another type)");
cls_StepAP214_AutoDesignDatedItem.def("ProductDefinitionEffectivity", (opencascade::handle<StepBasic_ProductDefinitionEffectivity> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::ProductDefinitionEffectivity, "returns Value as a ProductDefinitionEffectivity");

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNDATEDITEM
bind_NCollection_Array1<StepAP214_AutoDesignDatedItem>(mod, "StepAP214_Array1OfAutoDesignDatedItem", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNGENERALORGITEM
py::class_<StepAP214_AutoDesignGeneralOrgItem, StepData_SelectType> cls_StepAP214_AutoDesignGeneralOrgItem(mod, "StepAP214_AutoDesignGeneralOrgItem", "None");

// Constructors
cls_StepAP214_AutoDesignGeneralOrgItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNGENERALORGITEM
bind_NCollection_Array1<StepAP214_AutoDesignGeneralOrgItem>(mod, "StepAP214_Array1OfAutoDesignGeneralOrgItem", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNGROUPEDITEM
py::class_<StepAP214_AutoDesignGroupedItem, StepData_SelectType> cls_StepAP214_AutoDesignGroupedItem(mod, "StepAP214_AutoDesignGroupedItem", "None");

// Constructors
cls_StepAP214_AutoDesignGroupedItem.def(py::init<>());

// Methods
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignGroupedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignGroupedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignGroupedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignGroupedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignGroupedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignGroupedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignGroupedItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignGroupedItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignGroupedItem::CaseNum, "Recognizes a AutoDesignGroupedItem Kind Entity that is : 1 -> AdvancedBrepShapeRepresentation 2 -> CsgShapeRepresentation 3 -> FacetedBrepShapeRepresentation 4 -> GeometricallyBoundedSurfaceShapeRepresentation 5 -> GeometricallyBoundedWireframeShapeRepresentation 6 -> ManifoldSurfaceShapeRepresentation 7 -> Representation 8 -> RepresentationItem 9 -> ShapeAspect 10 -> ShapeRepresentation 11 -> TemplateInstance 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignGroupedItem.def("AdvancedBrepShapeRepresentation", (opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::AdvancedBrepShapeRepresentation, "returns Value as a AdvancedBrepShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("CsgShapeRepresentation", (opencascade::handle<StepShape_CsgShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::CsgShapeRepresentation, "returns Value as a CsgShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("FacetedBrepShapeRepresentation", (opencascade::handle<StepShape_FacetedBrepShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::FacetedBrepShapeRepresentation, "returns Value as a FacetedBrepShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("GeometricallyBoundedSurfaceShapeRepresentation", (opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::GeometricallyBoundedSurfaceShapeRepresentation, "returns Value as a GeometricallyBoundedSurfaceShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("GeometricallyBoundedWireframeShapeRepresentation", (opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::GeometricallyBoundedWireframeShapeRepresentation, "returns Value as a GeometricallyBoundedWireframeShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ManifoldSurfaceShapeRepresentation", (opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ManifoldSurfaceShapeRepresentation, "returns Value as a ManifoldSurfaceShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ShapeRepresentation", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ShapeRepresentation, "returns Value as a ShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("TemplateInstance", (opencascade::handle<StepVisual_TemplateInstance> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::TemplateInstance, "returns Value as a TemplateInstance (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNGROUPEDITEM
bind_NCollection_Array1<StepAP214_AutoDesignGroupedItem>(mod, "StepAP214_Array1OfAutoDesignGroupedItem", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNPRESENTEDITEMSELECT
py::class_<StepAP214_AutoDesignPresentedItemSelect, StepData_SelectType> cls_StepAP214_AutoDesignPresentedItemSelect(mod, "StepAP214_AutoDesignPresentedItemSelect", "None");

// Constructors
cls_StepAP214_AutoDesignPresentedItemSelect.def(py::init<>());

// Methods
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignPresentedItemSelect::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignPresentedItemSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignPresentedItemSelect::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignPresentedItemSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignPresentedItemSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignPresentedItemSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignPresentedItemSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignPresentedItemSelect.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignPresentedItemSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignPresentedItemSelect::CaseNum, "Recognizes a AutoDesignPresentedItemSelect Kind Entity that is : 1 -> ProductDefinition, 2 -> ProductDefinitionRelationship, 3 -> ProductDefinitionShape 4 -> RepresentationRelationship 5 -> ShapeAspect 6 -> DocumentRelationship, 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignPresentedItemSelect.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::ProductDefinitionRelationship, "returns Value as a ProductDefinitionRelationship (Null if another type)");
cls_StepAP214_AutoDesignPresentedItemSelect.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_AutoDesignPresentedItemSelect.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
cls_StepAP214_AutoDesignPresentedItemSelect.def("RepresentationRelationship", (opencascade::handle<StepRepr_RepresentationRelationship> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::RepresentationRelationship, "returns Value as a RepresentationRelationship (Null if another type)");
cls_StepAP214_AutoDesignPresentedItemSelect.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_AutoDesignPresentedItemSelect.def("DocumentRelationship", (opencascade::handle<StepBasic_DocumentRelationship> (StepAP214_AutoDesignPresentedItemSelect::*)() const) &StepAP214_AutoDesignPresentedItemSelect::DocumentRelationship, "returns Value as a DocumentRelationship (Null if another type)");

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNPRESENTEDITEMSELECT
bind_NCollection_Array1<StepAP214_AutoDesignPresentedItemSelect>(mod, "StepAP214_Array1OfAutoDesignPresentedItemSelect", py::module_local(false));

// CLASS: STEPAP214_AUTODESIGNREFERENCINGITEM
py::class_<StepAP214_AutoDesignReferencingItem, StepData_SelectType> cls_StepAP214_AutoDesignReferencingItem(mod, "StepAP214_AutoDesignReferencingItem", "None");

// Constructors
cls_StepAP214_AutoDesignReferencingItem.def(py::init<>());

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

// TYPEDEF: STEPAP214_ARRAY1OFAUTODESIGNREFERENCINGITEM
bind_NCollection_Array1<StepAP214_AutoDesignReferencingItem>(mod, "StepAP214_Array1OfAutoDesignReferencingItem", py::module_local(false));

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNDATEANDTIMEITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignDateAndTimeItem, StepAP214_Array1OfAutoDesignDateAndTimeItem>(mod, "StepAP214_HArray1OfAutoDesignDateAndTimeItem");

// CLASS: STEPAP214_AUTODESIGNACTUALDATEANDTIMEASSIGNMENT
py::class_<StepAP214_AutoDesignActualDateAndTimeAssignment, opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP214_AutoDesignActualDateAndTimeAssignment(mod, "StepAP214_AutoDesignActualDateAndTimeAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("Init", (void (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignActualDateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("SetItems", (void (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignActualDateAndTimeAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::Items, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("ItemsValue", (StepAP214_AutoDesignDateAndTimeItem (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignActualDateAndTimeAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::NbItems, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignActualDateAndTimeAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignActualDateAndTimeAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNDATEDITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignDatedItem, StepAP214_Array1OfAutoDesignDatedItem>(mod, "StepAP214_HArray1OfAutoDesignDatedItem");

// CLASS: STEPAP214_AUTODESIGNACTUALDATEASSIGNMENT
py::class_<StepAP214_AutoDesignActualDateAssignment, opencascade::handle<StepAP214_AutoDesignActualDateAssignment>, StepBasic_DateAssignment> cls_StepAP214_AutoDesignActualDateAssignment(mod, "StepAP214_AutoDesignActualDateAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignActualDateAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignActualDateAssignment.def("Init", (void (StepAP214_AutoDesignActualDateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignActualDateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAssignment.def("SetItems", (void (StepAP214_AutoDesignActualDateAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignActualDateAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> (StepAP214_AutoDesignActualDateAssignment::*)() const) &StepAP214_AutoDesignActualDateAssignment::Items, "None");
cls_StepAP214_AutoDesignActualDateAssignment.def("ItemsValue", (StepAP214_AutoDesignDatedItem (StepAP214_AutoDesignActualDateAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignActualDateAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignActualDateAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignActualDateAssignment::*)() const) &StepAP214_AutoDesignActualDateAssignment::NbItems, "None");
cls_StepAP214_AutoDesignActualDateAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignActualDateAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignActualDateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignActualDateAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignActualDateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignActualDateAssignment::*)() const) &StepAP214_AutoDesignActualDateAssignment::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNGENERALORGITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignGeneralOrgItem, StepAP214_Array1OfAutoDesignGeneralOrgItem>(mod, "StepAP214_HArray1OfAutoDesignGeneralOrgItem");

// CLASS: STEPAP214_AUTODESIGNAPPROVALASSIGNMENT
py::class_<StepAP214_AutoDesignApprovalAssignment, opencascade::handle<StepAP214_AutoDesignApprovalAssignment>, StepBasic_ApprovalAssignment> cls_StepAP214_AutoDesignApprovalAssignment(mod, "StepAP214_AutoDesignApprovalAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignApprovalAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignApprovalAssignment.def("Init", (void (StepAP214_AutoDesignApprovalAssignment::*)(const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignApprovalAssignment::Init, "None", py::arg("aAssignedApproval"), py::arg("aItems"));
cls_StepAP214_AutoDesignApprovalAssignment.def("SetItems", (void (StepAP214_AutoDesignApprovalAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignApprovalAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignApprovalAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> (StepAP214_AutoDesignApprovalAssignment::*)() const) &StepAP214_AutoDesignApprovalAssignment::Items, "None");
cls_StepAP214_AutoDesignApprovalAssignment.def("ItemsValue", (StepAP214_AutoDesignGeneralOrgItem (StepAP214_AutoDesignApprovalAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignApprovalAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignApprovalAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignApprovalAssignment::*)() const) &StepAP214_AutoDesignApprovalAssignment::NbItems, "None");
cls_StepAP214_AutoDesignApprovalAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignApprovalAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignApprovalAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignApprovalAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignApprovalAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignApprovalAssignment::*)() const) &StepAP214_AutoDesignApprovalAssignment::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNDATEANDPERSONITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignDateAndPersonItem, StepAP214_Array1OfAutoDesignDateAndPersonItem>(mod, "StepAP214_HArray1OfAutoDesignDateAndPersonItem");

// CLASS: STEPAP214_AUTODESIGNDATEANDPERSONASSIGNMENT
py::class_<StepAP214_AutoDesignDateAndPersonAssignment, opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP214_AutoDesignDateAndPersonAssignment(mod, "StepAP214_AutoDesignDateAndPersonAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignDateAndPersonAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("Init", (void (StepAP214_AutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> &)) &StepAP214_AutoDesignDateAndPersonAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("SetItems", (void (StepAP214_AutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> &)) &StepAP214_AutoDesignDateAndPersonAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::Items, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("ItemsValue", (StepAP214_AutoDesignDateAndPersonItem (StepAP214_AutoDesignDateAndPersonAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignDateAndPersonAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::NbItems, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignDateAndPersonAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignDateAndPersonAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNREFERENCINGITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignReferencingItem, StepAP214_Array1OfAutoDesignReferencingItem>(mod, "StepAP214_HArray1OfAutoDesignReferencingItem");

// CLASS: STEPAP214_AUTODESIGNDOCUMENTREFERENCE
py::class_<StepAP214_AutoDesignDocumentReference, opencascade::handle<StepAP214_AutoDesignDocumentReference>, StepBasic_DocumentReference> cls_StepAP214_AutoDesignDocumentReference(mod, "StepAP214_AutoDesignDocumentReference", "None");

// Constructors
cls_StepAP214_AutoDesignDocumentReference.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignDocumentReference.def("Init", (void (StepAP214_AutoDesignDocumentReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> &)) &StepAP214_AutoDesignDocumentReference::Init, "None", py::arg("aAssignedDocument"), py::arg("aSource"), py::arg("aItems"));
cls_StepAP214_AutoDesignDocumentReference.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::Items, "None");
cls_StepAP214_AutoDesignDocumentReference.def("SetItems", (void (StepAP214_AutoDesignDocumentReference::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignReferencingItem> &)) &StepAP214_AutoDesignDocumentReference::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignDocumentReference.def("ItemsValue", (StepAP214_AutoDesignReferencingItem (StepAP214_AutoDesignDocumentReference::*)(const Standard_Integer) const) &StepAP214_AutoDesignDocumentReference::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignDocumentReference.def("NbItems", (Standard_Integer (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::NbItems, "None");
cls_StepAP214_AutoDesignDocumentReference.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignDocumentReference::get_type_name, "None");
cls_StepAP214_AutoDesignDocumentReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignDocumentReference::get_type_descriptor, "None");
cls_StepAP214_AutoDesignDocumentReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignDocumentReference::*)() const) &StepAP214_AutoDesignDocumentReference::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNGROUPEDITEM
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignGroupedItem, StepAP214_Array1OfAutoDesignGroupedItem>(mod, "StepAP214_HArray1OfAutoDesignGroupedItem");

// CLASS: STEPAP214_AUTODESIGNGROUPASSIGNMENT
py::class_<StepAP214_AutoDesignGroupAssignment, opencascade::handle<StepAP214_AutoDesignGroupAssignment>, StepBasic_GroupAssignment> cls_StepAP214_AutoDesignGroupAssignment(mod, "StepAP214_AutoDesignGroupAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignGroupAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignGroupAssignment.def("Init", (void (StepAP214_AutoDesignGroupAssignment::*)(const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> &)) &StepAP214_AutoDesignGroupAssignment::Init, "None", py::arg("aAssignedGroup"), py::arg("aItems"));
cls_StepAP214_AutoDesignGroupAssignment.def("SetItems", (void (StepAP214_AutoDesignGroupAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> &)) &StepAP214_AutoDesignGroupAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignGroupAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::Items, "None");
cls_StepAP214_AutoDesignGroupAssignment.def("ItemsValue", (StepAP214_AutoDesignGroupedItem (StepAP214_AutoDesignGroupAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignGroupAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignGroupAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::NbItems, "None");
cls_StepAP214_AutoDesignGroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignGroupAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignGroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignGroupAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignGroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNNOMINALDATEANDTIMEASSIGNMENT
py::class_<StepAP214_AutoDesignNominalDateAndTimeAssignment, opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP214_AutoDesignNominalDateAndTimeAssignment(mod, "StepAP214_AutoDesignNominalDateAndTimeAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("Init", (void (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignNominalDateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("SetItems", (void (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignNominalDateAndTimeAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignNominalDateAndTimeAssignment::Items, "None");
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("ItemsValue", (StepAP214_AutoDesignDateAndTimeItem (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignNominalDateAndTimeAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignNominalDateAndTimeAssignment::NbItems, "None");
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignNominalDateAndTimeAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignNominalDateAndTimeAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignNominalDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignNominalDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignNominalDateAndTimeAssignment::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNNOMINALDATEASSIGNMENT
py::class_<StepAP214_AutoDesignNominalDateAssignment, opencascade::handle<StepAP214_AutoDesignNominalDateAssignment>, StepBasic_DateAssignment> cls_StepAP214_AutoDesignNominalDateAssignment(mod, "StepAP214_AutoDesignNominalDateAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignNominalDateAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignNominalDateAssignment.def("Init", (void (StepAP214_AutoDesignNominalDateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignNominalDateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("SetItems", (void (StepAP214_AutoDesignNominalDateAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignNominalDateAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::Items, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def("ItemsValue", (StepAP214_AutoDesignDatedItem (StepAP214_AutoDesignNominalDateAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignNominalDateAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::NbItems, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignNominalDateAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignNominalDateAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNORGANIZATIONASSIGNMENT
py::class_<StepAP214_AutoDesignOrganizationAssignment, opencascade::handle<StepAP214_AutoDesignOrganizationAssignment>, StepBasic_OrganizationAssignment> cls_StepAP214_AutoDesignOrganizationAssignment(mod, "StepAP214_AutoDesignOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignOrganizationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignOrganizationAssignment.def("Init", (void (StepAP214_AutoDesignOrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &, const opencascade::handle<StepBasic_OrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignOrganizationAssignment::Init, "None", py::arg("aAssignedOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignOrganizationAssignment.def("SetItems", (void (StepAP214_AutoDesignOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> (StepAP214_AutoDesignOrganizationAssignment::*)() const) &StepAP214_AutoDesignOrganizationAssignment::Items, "None");
cls_StepAP214_AutoDesignOrganizationAssignment.def("ItemsValue", (StepAP214_AutoDesignGeneralOrgItem (StepAP214_AutoDesignOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignOrganizationAssignment::*)() const) &StepAP214_AutoDesignOrganizationAssignment::NbItems, "None");
cls_StepAP214_AutoDesignOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignOrganizationAssignment::*)() const) &StepAP214_AutoDesignOrganizationAssignment::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNORGANIZATIONITEM
py::class_<StepAP214_AutoDesignOrganizationItem, StepAP214_AutoDesignGeneralOrgItem> cls_StepAP214_AutoDesignOrganizationItem(mod, "StepAP214_AutoDesignOrganizationItem", "None");

// Constructors
cls_StepAP214_AutoDesignOrganizationItem.def(py::init<>());

// Methods
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignOrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignOrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignOrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignOrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignOrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignOrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignOrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignOrganizationItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignOrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignOrganizationItem::CaseNum, "None", py::arg("ent"));
cls_StepAP214_AutoDesignOrganizationItem.def("Document", (opencascade::handle<StepBasic_Document> (StepAP214_AutoDesignOrganizationItem::*)() const) &StepAP214_AutoDesignOrganizationItem::Document, "None");
cls_StepAP214_AutoDesignOrganizationItem.def("PhysicallyModeledProductDefinition", (opencascade::handle<StepBasic_PhysicallyModeledProductDefinition> (StepAP214_AutoDesignOrganizationItem::*)() const) &StepAP214_AutoDesignOrganizationItem::PhysicallyModeledProductDefinition, "None");

// CLASS: STEPAP214_AUTODESIGNPERSONANDORGANIZATIONASSIGNMENT
py::class_<StepAP214_AutoDesignPersonAndOrganizationAssignment, opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP214_AutoDesignPersonAndOrganizationAssignment(mod, "StepAP214_AutoDesignPersonAndOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("Init", (void (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignPersonAndOrganizationAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("SetItems", (void (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> &)) &StepAP214_AutoDesignPersonAndOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignGeneralOrgItem> (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)() const) &StepAP214_AutoDesignPersonAndOrganizationAssignment::Items, "None");
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("ItemsValue", (StepAP214_AutoDesignGeneralOrgItem (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignPersonAndOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)() const) &StepAP214_AutoDesignPersonAndOrganizationAssignment::NbItems, "None");
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignPersonAndOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignPersonAndOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignPersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignPersonAndOrganizationAssignment::*)() const) &StepAP214_AutoDesignPersonAndOrganizationAssignment::DynamicType, "None");

// CLASS: STEPAP214_HARRAY1OFAUTODESIGNPRESENTEDITEMSELECT
bind_Define_HArray1<StepAP214_HArray1OfAutoDesignPresentedItemSelect, StepAP214_Array1OfAutoDesignPresentedItemSelect>(mod, "StepAP214_HArray1OfAutoDesignPresentedItemSelect");

// CLASS: STEPAP214_AUTODESIGNPRESENTEDITEM
py::class_<StepAP214_AutoDesignPresentedItem, opencascade::handle<StepAP214_AutoDesignPresentedItem>, StepVisual_PresentedItem> cls_StepAP214_AutoDesignPresentedItem(mod, "StepAP214_AutoDesignPresentedItem", "None");

// Constructors
cls_StepAP214_AutoDesignPresentedItem.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignPresentedItem.def("Init", (void (StepAP214_AutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> &)) &StepAP214_AutoDesignPresentedItem::Init, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignPresentedItem.def("SetItems", (void (StepAP214_AutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> &)) &StepAP214_AutoDesignPresentedItem::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignPresentedItem.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::Items, "None");
cls_StepAP214_AutoDesignPresentedItem.def("ItemsValue", (StepAP214_AutoDesignPresentedItemSelect (StepAP214_AutoDesignPresentedItem::*)(const Standard_Integer) const) &StepAP214_AutoDesignPresentedItem::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignPresentedItem.def("NbItems", (Standard_Integer (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::NbItems, "None");
cls_StepAP214_AutoDesignPresentedItem.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignPresentedItem::get_type_name, "None");
cls_StepAP214_AutoDesignPresentedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignPresentedItem::get_type_descriptor, "None");
cls_StepAP214_AutoDesignPresentedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::DynamicType, "None");

// CLASS: STEPAP214_AUTODESIGNSECURITYCLASSIFICATIONASSIGNMENT
py::class_<StepAP214_AutoDesignSecurityClassificationAssignment, opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment>, StepBasic_SecurityClassificationAssignment> cls_StepAP214_AutoDesignSecurityClassificationAssignment(mod, "StepAP214_AutoDesignSecurityClassificationAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def(py::init<>());

// Methods
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("Init", (void (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &, const opencascade::handle<StepBasic_HArray1OfApproval> &)) &StepAP214_AutoDesignSecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"), py::arg("aItems"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("SetItems", (void (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_HArray1OfApproval> &)) &StepAP214_AutoDesignSecurityClassificationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("Items", (opencascade::handle<StepBasic_HArray1OfApproval> (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::Items, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("ItemsValue", (opencascade::handle<StepBasic_Approval> (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignSecurityClassificationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::NbItems, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignSecurityClassificationAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignSecurityClassificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::DynamicType, "None");

// CLASS: STEPAP214_CLASS
py::class_<StepAP214_Class, opencascade::handle<StepAP214_Class>, StepBasic_Group> cls_StepAP214_Class(mod, "StepAP214_Class", "Representation of STEP entity Class");

// Constructors
cls_StepAP214_Class.def(py::init<>());

// Methods
cls_StepAP214_Class.def_static("get_type_name_", (const char * (*)()) &StepAP214_Class::get_type_name, "None");
cls_StepAP214_Class.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_Class::get_type_descriptor, "None");
cls_StepAP214_Class.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_Class::*)() const) &StepAP214_Class::DynamicType, "None");

// CLASS: STEPAP214_EXTERNALLYDEFINEDCLASS
py::class_<StepAP214_ExternallyDefinedClass, opencascade::handle<StepAP214_ExternallyDefinedClass>, StepAP214_Class> cls_StepAP214_ExternallyDefinedClass(mod, "StepAP214_ExternallyDefinedClass", "Representation of STEP entity ExternallyDefinedClass");

// Constructors
cls_StepAP214_ExternallyDefinedClass.def(py::init<>());

// Methods
cls_StepAP214_ExternallyDefinedClass.def("Init", (void (StepAP214_ExternallyDefinedClass::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepAP214_ExternallyDefinedClass::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("hasGroup_Description"), py::arg("aGroup_Description"), py::arg("aExternallyDefinedItem_ItemId"), py::arg("aExternallyDefinedItem_Source"));
cls_StepAP214_ExternallyDefinedClass.def("ExternallyDefinedItem", (opencascade::handle<StepBasic_ExternallyDefinedItem> (StepAP214_ExternallyDefinedClass::*)() const) &StepAP214_ExternallyDefinedClass::ExternallyDefinedItem, "Returns data for supertype ExternallyDefinedItem");
cls_StepAP214_ExternallyDefinedClass.def("SetExternallyDefinedItem", (void (StepAP214_ExternallyDefinedClass::*)(const opencascade::handle<StepBasic_ExternallyDefinedItem> &)) &StepAP214_ExternallyDefinedClass::SetExternallyDefinedItem, "Set data for supertype ExternallyDefinedItem", py::arg("ExternallyDefinedItem"));
cls_StepAP214_ExternallyDefinedClass.def_static("get_type_name_", (const char * (*)()) &StepAP214_ExternallyDefinedClass::get_type_name, "None");
cls_StepAP214_ExternallyDefinedClass.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_ExternallyDefinedClass::get_type_descriptor, "None");
cls_StepAP214_ExternallyDefinedClass.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_ExternallyDefinedClass::*)() const) &StepAP214_ExternallyDefinedClass::DynamicType, "None");

// CLASS: STEPAP214_EXTERNALLYDEFINEDGENERALPROPERTY
py::class_<StepAP214_ExternallyDefinedGeneralProperty, opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty>, StepBasic_GeneralProperty> cls_StepAP214_ExternallyDefinedGeneralProperty(mod, "StepAP214_ExternallyDefinedGeneralProperty", "Representation of STEP entity ExternallyDefinedGeneralProperty");

// Constructors
cls_StepAP214_ExternallyDefinedGeneralProperty.def(py::init<>());

// Methods
cls_StepAP214_ExternallyDefinedGeneralProperty.def("Init", (void (StepAP214_ExternallyDefinedGeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepAP214_ExternallyDefinedGeneralProperty::Init, "Initialize all fields (own and inherited)", py::arg("aGeneralProperty_Id"), py::arg("aGeneralProperty_Name"), py::arg("hasGeneralProperty_Description"), py::arg("aGeneralProperty_Description"), py::arg("aExternallyDefinedItem_ItemId"), py::arg("aExternallyDefinedItem_Source"));
cls_StepAP214_ExternallyDefinedGeneralProperty.def("ExternallyDefinedItem", (opencascade::handle<StepBasic_ExternallyDefinedItem> (StepAP214_ExternallyDefinedGeneralProperty::*)() const) &StepAP214_ExternallyDefinedGeneralProperty::ExternallyDefinedItem, "Returns data for supertype ExternallyDefinedItem");
cls_StepAP214_ExternallyDefinedGeneralProperty.def("SetExternallyDefinedItem", (void (StepAP214_ExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepBasic_ExternallyDefinedItem> &)) &StepAP214_ExternallyDefinedGeneralProperty::SetExternallyDefinedItem, "Set data for supertype ExternallyDefinedItem", py::arg("ExternallyDefinedItem"));
cls_StepAP214_ExternallyDefinedGeneralProperty.def_static("get_type_name_", (const char * (*)()) &StepAP214_ExternallyDefinedGeneralProperty::get_type_name, "None");
cls_StepAP214_ExternallyDefinedGeneralProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_ExternallyDefinedGeneralProperty::get_type_descriptor, "None");
cls_StepAP214_ExternallyDefinedGeneralProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_ExternallyDefinedGeneralProperty::*)() const) &StepAP214_ExternallyDefinedGeneralProperty::DynamicType, "None");

// CLASS: STEPAP214_PROTOCOL
py::class_<StepAP214_Protocol, opencascade::handle<StepAP214_Protocol>, StepData_Protocol> cls_StepAP214_Protocol(mod, "StepAP214_Protocol", "Protocol for StepAP214 Entities It requires StepAP214 as a Resource");

// Constructors
cls_StepAP214_Protocol.def(py::init<>());

// Methods
cls_StepAP214_Protocol.def("TypeNumber", (Standard_Integer (StepAP214_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &StepAP214_Protocol::TypeNumber, "Returns a Case Number for each of the StepAP214 Entities", py::arg("atype"));
cls_StepAP214_Protocol.def("SchemaName", (Standard_CString (StepAP214_Protocol::*)() const) &StepAP214_Protocol::SchemaName, "None");
cls_StepAP214_Protocol.def("NbResources", (Standard_Integer (StepAP214_Protocol::*)() const) &StepAP214_Protocol::NbResources, "Returns count of Protocol used as Resources (level one)");
cls_StepAP214_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (StepAP214_Protocol::*)(const Standard_Integer) const) &StepAP214_Protocol::Resource, "Returns a Resource, given its rank (between 1 and NbResources)", py::arg("num"));
cls_StepAP214_Protocol.def_static("get_type_name_", (const char * (*)()) &StepAP214_Protocol::get_type_name, "None");
cls_StepAP214_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_Protocol::get_type_descriptor, "None");
cls_StepAP214_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_Protocol::*)() const) &StepAP214_Protocol::DynamicType, "None");

// CLASS: STEPAP214_REPITEMGROUP
py::class_<StepAP214_RepItemGroup, opencascade::handle<StepAP214_RepItemGroup>, StepBasic_Group> cls_StepAP214_RepItemGroup(mod, "StepAP214_RepItemGroup", "Representation of STEP entity RepItemGroup");

// Constructors
cls_StepAP214_RepItemGroup.def(py::init<>());

// Methods
cls_StepAP214_RepItemGroup.def("Init", (void (StepAP214_RepItemGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepAP214_RepItemGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("hasGroup_Description"), py::arg("aGroup_Description"), py::arg("aRepresentationItem_Name"));
cls_StepAP214_RepItemGroup.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_RepItemGroup::*)() const) &StepAP214_RepItemGroup::RepresentationItem, "Returns data for supertype RepresentationItem");
cls_StepAP214_RepItemGroup.def("SetRepresentationItem", (void (StepAP214_RepItemGroup::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepAP214_RepItemGroup::SetRepresentationItem, "Set data for supertype RepresentationItem", py::arg("RepresentationItem"));
cls_StepAP214_RepItemGroup.def_static("get_type_name_", (const char * (*)()) &StepAP214_RepItemGroup::get_type_name, "None");
cls_StepAP214_RepItemGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_RepItemGroup::get_type_descriptor, "None");
cls_StepAP214_RepItemGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_RepItemGroup::*)() const) &StepAP214_RepItemGroup::DynamicType, "None");


}
