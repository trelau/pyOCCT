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
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepAP242_ItemIdentifiedRepresentationUsage.hxx>
#include <Standard_Type.hxx>
#include <StepAP242_DraughtingModelItemAssociation.hxx>
#include <StepAP242_GeometricItemSpecificUsage.hxx>
#include <StepBasic_Action.hxx>
#include <StepBasic_Address.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepAP242_IdAttributeSelect.hxx>
#include <StepAP242_IdAttribute.hxx>

PYBIND11_MODULE(StepAP242, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepAP214");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepDimTol");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TCollection");

// CLASS: STEPAP242_ITEMIDENTIFIEDREPRESENTATIONUSAGEDEFINITION
py::class_<StepAP242_ItemIdentifiedRepresentationUsageDefinition, StepData_SelectType> cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition(mod, "StepAP242_ItemIdentifiedRepresentationUsageDefinition", "None");

// Constructors
cls_StepAP242_ItemIdentifiedRepresentationUsageDefinition.def(py::init<>());

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

// CLASS: STEPAP242_ITEMIDENTIFIEDREPRESENTATIONUSAGE
py::class_<StepAP242_ItemIdentifiedRepresentationUsage, opencascade::handle<StepAP242_ItemIdentifiedRepresentationUsage>, Standard_Transient> cls_StepAP242_ItemIdentifiedRepresentationUsage(mod, "StepAP242_ItemIdentifiedRepresentationUsage", "None");

// Constructors
cls_StepAP242_ItemIdentifiedRepresentationUsage.def(py::init<>());

// Methods
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Init", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const StepAP242_ItemIdentifiedRepresentationUsageDefinition &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::Init, "Init all fields own and inherited", py::arg("theName"), py::arg("theDescription"), py::arg("theDefinition"), py::arg("theUsedRepresentation"), py::arg("theIdentifiedItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetName", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetName, "Set field Name", py::arg("theName"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Name, "Returns field Name");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetDescription", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Description, "Returns field Description");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetDefinition", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const StepAP242_ItemIdentifiedRepresentationUsageDefinition &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetDefinition, "Set field Definition", py::arg("theDefinition"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("Definition", (StepAP242_ItemIdentifiedRepresentationUsageDefinition (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::Definition, "Returns field Definition");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetUsedRepresentation", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepRepr_Representation> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetUsedRepresentation, "Set field UsedRepresentation", py::arg("theUsedRepresentation"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("UsedRepresentation", (opencascade::handle<StepRepr_Representation> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::UsedRepresentation, "Retuns field UsedRepresentation");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("IdentifiedItem", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::IdentifiedItem, "Returns field IdentifiedItem");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("NbIdentifiedItem", (Standard_Integer (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::NbIdentifiedItem, "Returns number of identified items");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetIdentifiedItem", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetIdentifiedItem, "Set fiels IdentifiedItem", py::arg("theIdentifiedItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("IdentifiedItemValue", (opencascade::handle<StepRepr_RepresentationItem> (StepAP242_ItemIdentifiedRepresentationUsage::*)(const Standard_Integer) const) &StepAP242_ItemIdentifiedRepresentationUsage::IdentifiedItemValue, "Returns identified item with given number", py::arg("num"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("SetIdentifiedItemValue", (void (StepAP242_ItemIdentifiedRepresentationUsage::*)(const Standard_Integer, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepAP242_ItemIdentifiedRepresentationUsage::SetIdentifiedItemValue, "Set identified item with given number", py::arg("num"), py::arg("theItem"));
cls_StepAP242_ItemIdentifiedRepresentationUsage.def_static("get_type_name_", (const char * (*)()) &StepAP242_ItemIdentifiedRepresentationUsage::get_type_name, "None");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_ItemIdentifiedRepresentationUsage::get_type_descriptor, "None");
cls_StepAP242_ItemIdentifiedRepresentationUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_ItemIdentifiedRepresentationUsage::*)() const) &StepAP242_ItemIdentifiedRepresentationUsage::DynamicType, "None");

// CLASS: STEPAP242_DRAUGHTINGMODELITEMASSOCIATION
py::class_<StepAP242_DraughtingModelItemAssociation, opencascade::handle<StepAP242_DraughtingModelItemAssociation>, StepAP242_ItemIdentifiedRepresentationUsage> cls_StepAP242_DraughtingModelItemAssociation(mod, "StepAP242_DraughtingModelItemAssociation", "Added for Dimensional Tolerances");

// Constructors
cls_StepAP242_DraughtingModelItemAssociation.def(py::init<>());

// Methods
cls_StepAP242_DraughtingModelItemAssociation.def_static("get_type_name_", (const char * (*)()) &StepAP242_DraughtingModelItemAssociation::get_type_name, "None");
cls_StepAP242_DraughtingModelItemAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_DraughtingModelItemAssociation::get_type_descriptor, "None");
cls_StepAP242_DraughtingModelItemAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_DraughtingModelItemAssociation::*)() const) &StepAP242_DraughtingModelItemAssociation::DynamicType, "None");

// CLASS: STEPAP242_GEOMETRICITEMSPECIFICUSAGE
py::class_<StepAP242_GeometricItemSpecificUsage, opencascade::handle<StepAP242_GeometricItemSpecificUsage>, StepAP242_ItemIdentifiedRepresentationUsage> cls_StepAP242_GeometricItemSpecificUsage(mod, "StepAP242_GeometricItemSpecificUsage", "Added for Dimensional Tolerances");

// Constructors
cls_StepAP242_GeometricItemSpecificUsage.def(py::init<>());

// Methods
cls_StepAP242_GeometricItemSpecificUsage.def_static("get_type_name_", (const char * (*)()) &StepAP242_GeometricItemSpecificUsage::get_type_name, "None");
cls_StepAP242_GeometricItemSpecificUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_GeometricItemSpecificUsage::get_type_descriptor, "None");
cls_StepAP242_GeometricItemSpecificUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_GeometricItemSpecificUsage::*)() const) &StepAP242_GeometricItemSpecificUsage::DynamicType, "None");

// CLASS: STEPAP242_IDATTRIBUTESELECT
py::class_<StepAP242_IdAttributeSelect, StepData_SelectType> cls_StepAP242_IdAttributeSelect(mod, "StepAP242_IdAttributeSelect", "None");

// Constructors
cls_StepAP242_IdAttributeSelect.def(py::init<>());

// Methods
// cls_StepAP242_IdAttributeSelect.def_static("operator new_", (void * (*)(size_t)) &StepAP242_IdAttributeSelect::operator new, "None", py::arg("theSize"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete_", (void (*)(void *)) &StepAP242_IdAttributeSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepAP242_IdAttributeSelect::operator new[], "None", py::arg("theSize"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete[]_", (void (*)(void *)) &StepAP242_IdAttributeSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP242_IdAttributeSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP242_IdAttributeSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepAP242_IdAttributeSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP242_IdAttributeSelect.def("CaseNum", (Standard_Integer (StepAP242_IdAttributeSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP242_IdAttributeSelect::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> Action 2 -> Address 3 -> ApplicationContext 4 -> DimensionalSize 5 -> GeometricTolerance 6 -> Group 7 -> Reserved for OrganizatonalProject (not implemented in OCCT) 8 -> ProductCategory 9 -> PropertyDefinition 10 -> Representation 11 -> ShapeAspect 12 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepAP242_IdAttributeSelect.def("Action", (opencascade::handle<StepBasic_Action> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Action, "returns Value as a Action (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Address", (opencascade::handle<StepBasic_Address> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Address, "returns Value as a Address (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ApplicationContext", (opencascade::handle<StepBasic_ApplicationContext> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ApplicationContext, "returns Value as a ApplicationContext (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::GeometricTolerance, "returns Value as a GeometricTolerance (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Group", (opencascade::handle<StepBasic_Group> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Group, "returns Value as a Group (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ProductCategory", (opencascade::handle<StepBasic_ProductCategory> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ProductCategory, "returns Value as a ProductCategory (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::PropertyDefinition, "returns Value as a PropertyDefinition (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP242_IdAttributeSelect.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP242_IdAttributeSelect::*)() const) &StepAP242_IdAttributeSelect::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// CLASS: STEPAP242_IDATTRIBUTE
py::class_<StepAP242_IdAttribute, opencascade::handle<StepAP242_IdAttribute>, Standard_Transient> cls_StepAP242_IdAttribute(mod, "StepAP242_IdAttribute", "None");

// Constructors
cls_StepAP242_IdAttribute.def(py::init<>());

// Methods
cls_StepAP242_IdAttribute.def("Init", (void (StepAP242_IdAttribute::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepAP242_IdAttributeSelect &)) &StepAP242_IdAttribute::Init, "Init all field own and inherited", py::arg("theAttributeValue"), py::arg("theIdentifiedItem"));
cls_StepAP242_IdAttribute.def("SetAttributeValue", (void (StepAP242_IdAttribute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepAP242_IdAttribute::SetAttributeValue, "None", py::arg("theAttributeValue"));
cls_StepAP242_IdAttribute.def("AttributeValue", (opencascade::handle<TCollection_HAsciiString> (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::AttributeValue, "Returns field AttributeValue");
cls_StepAP242_IdAttribute.def("SetIdentifiedItem", (void (StepAP242_IdAttribute::*)(const StepAP242_IdAttributeSelect &)) &StepAP242_IdAttribute::SetIdentifiedItem, "Set field IdentifiedItem", py::arg("theIdentifiedItem"));
cls_StepAP242_IdAttribute.def("IdentifiedItem", (StepAP242_IdAttributeSelect (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::IdentifiedItem, "Returns IdentifiedItem");
cls_StepAP242_IdAttribute.def_static("get_type_name_", (const char * (*)()) &StepAP242_IdAttribute::get_type_name, "None");
cls_StepAP242_IdAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP242_IdAttribute::get_type_descriptor, "None");
cls_StepAP242_IdAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP242_IdAttribute::*)() const) &StepAP242_IdAttribute::DynamicType, "None");


}
