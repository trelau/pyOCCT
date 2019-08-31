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
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepBasic_Action.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepBasic_RWAction.hxx>
#include <StepBasic_ActionAssignment.hxx>
#include <RWStepBasic_RWActionAssignment.hxx>
#include <StepBasic_ActionMethod.hxx>
#include <RWStepBasic_RWActionMethod.hxx>
#include <StepBasic_ActionRequestAssignment.hxx>
#include <RWStepBasic_RWActionRequestAssignment.hxx>
#include <StepBasic_ActionRequestSolution.hxx>
#include <RWStepBasic_RWActionRequestSolution.hxx>
#include <StepBasic_Address.hxx>
#include <RWStepBasic_RWAddress.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <RWStepBasic_RWApplicationContext.hxx>
#include <StepBasic_ApplicationContextElement.hxx>
#include <RWStepBasic_RWApplicationContextElement.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <RWStepBasic_RWApplicationProtocolDefinition.hxx>
#include <StepBasic_Approval.hxx>
#include <RWStepBasic_RWApproval.hxx>
#include <StepBasic_ApprovalDateTime.hxx>
#include <RWStepBasic_RWApprovalDateTime.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <RWStepBasic_RWApprovalPersonOrganization.hxx>
#include <StepBasic_ApprovalRelationship.hxx>
#include <RWStepBasic_RWApprovalRelationship.hxx>
#include <StepBasic_ApprovalRole.hxx>
#include <RWStepBasic_RWApprovalRole.hxx>
#include <StepBasic_ApprovalStatus.hxx>
#include <RWStepBasic_RWApprovalStatus.hxx>
#include <StepBasic_CalendarDate.hxx>
#include <RWStepBasic_RWCalendarDate.hxx>
#include <StepBasic_Certification.hxx>
#include <RWStepBasic_RWCertification.hxx>
#include <StepBasic_CertificationAssignment.hxx>
#include <RWStepBasic_RWCertificationAssignment.hxx>
#include <StepBasic_CertificationType.hxx>
#include <RWStepBasic_RWCertificationType.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <RWStepBasic_RWCharacterizedObject.hxx>
#include <StepBasic_Contract.hxx>
#include <RWStepBasic_RWContract.hxx>
#include <StepBasic_ContractAssignment.hxx>
#include <RWStepBasic_RWContractAssignment.hxx>
#include <StepBasic_ContractType.hxx>
#include <RWStepBasic_RWContractType.hxx>
#include <StepBasic_ConversionBasedUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndAreaUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndAreaUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndLengthUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndLengthUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndMassUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndMassUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndPlaneAngleUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndRatioUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndRatioUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndSolidAngleUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndTimeUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndTimeUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndVolumeUnit.hxx>
#include <RWStepBasic_RWConversionBasedUnitAndVolumeUnit.hxx>
#include <StepBasic_CoordinatedUniversalTimeOffset.hxx>
#include <RWStepBasic_RWCoordinatedUniversalTimeOffset.hxx>
#include <StepBasic_Date.hxx>
#include <RWStepBasic_RWDate.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <RWStepBasic_RWDateAndTime.hxx>
#include <StepBasic_DateRole.hxx>
#include <RWStepBasic_RWDateRole.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <RWStepBasic_RWDateTimeRole.hxx>
#include <StepBasic_DerivedUnit.hxx>
#include <RWStepBasic_RWDerivedUnit.hxx>
#include <StepBasic_DerivedUnitElement.hxx>
#include <RWStepBasic_RWDerivedUnitElement.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <RWStepBasic_RWDimensionalExponents.hxx>
#include <StepBasic_Document.hxx>
#include <RWStepBasic_RWDocument.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <RWStepBasic_RWDocumentFile.hxx>
#include <StepBasic_DocumentProductAssociation.hxx>
#include <RWStepBasic_RWDocumentProductAssociation.hxx>
#include <StepBasic_DocumentProductEquivalence.hxx>
#include <RWStepBasic_RWDocumentProductEquivalence.hxx>
#include <StepBasic_DocumentRelationship.hxx>
#include <RWStepBasic_RWDocumentRelationship.hxx>
#include <StepBasic_DocumentRepresentationType.hxx>
#include <RWStepBasic_RWDocumentRepresentationType.hxx>
#include <StepBasic_DocumentType.hxx>
#include <RWStepBasic_RWDocumentType.hxx>
#include <StepBasic_DocumentUsageConstraint.hxx>
#include <RWStepBasic_RWDocumentUsageConstraint.hxx>
#include <StepBasic_Effectivity.hxx>
#include <RWStepBasic_RWEffectivity.hxx>
#include <StepBasic_EffectivityAssignment.hxx>
#include <RWStepBasic_RWEffectivityAssignment.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <RWStepBasic_RWEulerAngles.hxx>
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <RWStepBasic_RWExternalIdentificationAssignment.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <RWStepBasic_RWExternallyDefinedItem.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <RWStepBasic_RWExternalSource.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <RWStepBasic_RWGeneralProperty.hxx>
#include <StepBasic_Group.hxx>
#include <RWStepBasic_RWGroup.hxx>
#include <StepBasic_GroupAssignment.hxx>
#include <RWStepBasic_RWGroupAssignment.hxx>
#include <StepBasic_GroupRelationship.hxx>
#include <RWStepBasic_RWGroupRelationship.hxx>
#include <StepBasic_IdentificationAssignment.hxx>
#include <RWStepBasic_RWIdentificationAssignment.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <RWStepBasic_RWIdentificationRole.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <RWStepBasic_RWLengthMeasureWithUnit.hxx>
#include <StepBasic_LengthUnit.hxx>
#include <RWStepBasic_RWLengthUnit.hxx>
#include <StepBasic_LocalTime.hxx>
#include <RWStepBasic_RWLocalTime.hxx>
#include <StepBasic_MassMeasureWithUnit.hxx>
#include <RWStepBasic_RWMassMeasureWithUnit.hxx>
#include <StepBasic_MassUnit.hxx>
#include <RWStepBasic_RWMassUnit.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <RWStepBasic_RWMeasureWithUnit.hxx>
#include <StepBasic_MechanicalContext.hxx>
#include <RWStepBasic_RWMechanicalContext.hxx>
#include <StepBasic_NameAssignment.hxx>
#include <RWStepBasic_RWNameAssignment.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <RWStepBasic_RWNamedUnit.hxx>
#include <StepBasic_ObjectRole.hxx>
#include <RWStepBasic_RWObjectRole.hxx>
#include <StepBasic_OrdinalDate.hxx>
#include <RWStepBasic_RWOrdinalDate.hxx>
#include <StepBasic_Organization.hxx>
#include <RWStepBasic_RWOrganization.hxx>
#include <StepBasic_OrganizationalAddress.hxx>
#include <RWStepBasic_RWOrganizationalAddress.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <RWStepBasic_RWOrganizationRole.hxx>
#include <StepBasic_Person.hxx>
#include <RWStepBasic_RWPerson.hxx>
#include <StepBasic_PersonalAddress.hxx>
#include <RWStepBasic_RWPersonalAddress.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <RWStepBasic_RWPersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <RWStepBasic_RWPersonAndOrganizationRole.hxx>
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <RWStepBasic_RWPlaneAngleMeasureWithUnit.hxx>
#include <StepBasic_PlaneAngleUnit.hxx>
#include <RWStepBasic_RWPlaneAngleUnit.hxx>
#include <StepBasic_Product.hxx>
#include <RWStepBasic_RWProduct.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <RWStepBasic_RWProductCategory.hxx>
#include <StepBasic_ProductCategoryRelationship.hxx>
#include <RWStepBasic_RWProductCategoryRelationship.hxx>
#include <StepBasic_ProductConceptContext.hxx>
#include <RWStepBasic_RWProductConceptContext.hxx>
#include <StepBasic_ProductContext.hxx>
#include <RWStepBasic_RWProductContext.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <RWStepBasic_RWProductDefinition.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <RWStepBasic_RWProductDefinitionContext.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <RWStepBasic_RWProductDefinitionEffectivity.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <RWStepBasic_RWProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionFormationRelationship.hxx>
#include <RWStepBasic_RWProductDefinitionFormationRelationship.hxx>
#include <StepBasic_ProductDefinitionFormationWithSpecifiedSource.hxx>
#include <RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.hxx>
#include <StepBasic_ProductDefinitionReference.hxx>
#include <RWStepBasic_RWProductDefinitionReference.hxx>
#include <StepBasic_ProductDefinitionReferenceWithLocalRepresentation.hxx>
#include <RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <RWStepBasic_RWProductDefinitionRelationship.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <RWStepBasic_RWProductDefinitionWithAssociatedDocuments.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <RWStepBasic_RWProductRelatedProductCategory.hxx>
#include <StepBasic_ProductType.hxx>
#include <RWStepBasic_RWProductType.hxx>
#include <StepBasic_RatioMeasureWithUnit.hxx>
#include <RWStepBasic_RWRatioMeasureWithUnit.hxx>
#include <StepBasic_RoleAssociation.hxx>
#include <RWStepBasic_RWRoleAssociation.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <RWStepBasic_RWSecurityClassification.hxx>
#include <StepBasic_SecurityClassificationLevel.hxx>
#include <RWStepBasic_RWSecurityClassificationLevel.hxx>
#include <StepBasic_SiUnit.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <TCollection_AsciiString.hxx>
#include <RWStepBasic_RWSiUnit.hxx>
#include <StepBasic_SiUnitAndAreaUnit.hxx>
#include <RWStepBasic_RWSiUnitAndAreaUnit.hxx>
#include <StepBasic_SiUnitAndLengthUnit.hxx>
#include <RWStepBasic_RWSiUnitAndLengthUnit.hxx>
#include <StepBasic_SiUnitAndMassUnit.hxx>
#include <RWStepBasic_RWSiUnitAndMassUnit.hxx>
#include <StepBasic_SiUnitAndPlaneAngleUnit.hxx>
#include <RWStepBasic_RWSiUnitAndPlaneAngleUnit.hxx>
#include <StepBasic_SiUnitAndRatioUnit.hxx>
#include <RWStepBasic_RWSiUnitAndRatioUnit.hxx>
#include <StepBasic_SiUnitAndSolidAngleUnit.hxx>
#include <RWStepBasic_RWSiUnitAndSolidAngleUnit.hxx>
#include <StepBasic_SiUnitAndThermodynamicTemperatureUnit.hxx>
#include <RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.hxx>
#include <StepBasic_SiUnitAndTimeUnit.hxx>
#include <RWStepBasic_RWSiUnitAndTimeUnit.hxx>
#include <StepBasic_SiUnitAndVolumeUnit.hxx>
#include <RWStepBasic_RWSiUnitAndVolumeUnit.hxx>
#include <StepBasic_SolidAngleMeasureWithUnit.hxx>
#include <RWStepBasic_RWSolidAngleMeasureWithUnit.hxx>
#include <StepBasic_SolidAngleUnit.hxx>
#include <RWStepBasic_RWSolidAngleUnit.hxx>
#include <StepBasic_ThermodynamicTemperatureUnit.hxx>
#include <RWStepBasic_RWThermodynamicTemperatureUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <RWStepBasic_RWUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <RWStepBasic_RWVersionedActionRequest.hxx>
#include <StepBasic_WeekOfYearAndDayDate.hxx>
#include <RWStepBasic_RWWeekOfYearAndDayDate.hxx>

PYBIND11_MODULE(RWStepBasic, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.TCollection");

// CLASS: RWSTEPBASIC_RWACTION
py::class_<RWStepBasic_RWAction> cls_RWStepBasic_RWAction(mod, "RWStepBasic_RWAction", "Read & Write tool for Action");

// Constructors
cls_RWStepBasic_RWAction.def(py::init<>());

// Methods
// cls_RWStepBasic_RWAction.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWAction::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWAction.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWAction::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWAction.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWAction::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWAction.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWAction::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWAction.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWAction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWAction.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWAction::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWAction.def("ReadStep", (void (RWStepBasic_RWAction::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Action> &) const) &RWStepBasic_RWAction::ReadStep, "Reads Action", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWAction.def("WriteStep", (void (RWStepBasic_RWAction::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Action> &) const) &RWStepBasic_RWAction::WriteStep, "Writes Action", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWAction.def("Share", (void (RWStepBasic_RWAction::*)(const opencascade::handle<StepBasic_Action> &, Interface_EntityIterator &) const) &RWStepBasic_RWAction::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWACTIONASSIGNMENT
py::class_<RWStepBasic_RWActionAssignment> cls_RWStepBasic_RWActionAssignment(mod, "RWStepBasic_RWActionAssignment", "Read & Write tool for ActionAssignment");

// Constructors
cls_RWStepBasic_RWActionAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWActionAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWActionAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWActionAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWActionAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWActionAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWActionAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWActionAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWActionAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWActionAssignment.def("ReadStep", (void (RWStepBasic_RWActionAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ActionAssignment> &) const) &RWStepBasic_RWActionAssignment::ReadStep, "Reads ActionAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWActionAssignment.def("WriteStep", (void (RWStepBasic_RWActionAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ActionAssignment> &) const) &RWStepBasic_RWActionAssignment::WriteStep, "Writes ActionAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWActionAssignment.def("Share", (void (RWStepBasic_RWActionAssignment::*)(const opencascade::handle<StepBasic_ActionAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWActionAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWACTIONMETHOD
py::class_<RWStepBasic_RWActionMethod> cls_RWStepBasic_RWActionMethod(mod, "RWStepBasic_RWActionMethod", "Read & Write tool for ActionMethod");

// Constructors
cls_RWStepBasic_RWActionMethod.def(py::init<>());

// Methods
// cls_RWStepBasic_RWActionMethod.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWActionMethod::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionMethod.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWActionMethod::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionMethod.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWActionMethod::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionMethod.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWActionMethod::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionMethod.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWActionMethod::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWActionMethod.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWActionMethod::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWActionMethod.def("ReadStep", (void (RWStepBasic_RWActionMethod::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ActionMethod> &) const) &RWStepBasic_RWActionMethod::ReadStep, "Reads ActionMethod", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWActionMethod.def("WriteStep", (void (RWStepBasic_RWActionMethod::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ActionMethod> &) const) &RWStepBasic_RWActionMethod::WriteStep, "Writes ActionMethod", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWActionMethod.def("Share", (void (RWStepBasic_RWActionMethod::*)(const opencascade::handle<StepBasic_ActionMethod> &, Interface_EntityIterator &) const) &RWStepBasic_RWActionMethod::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWACTIONREQUESTASSIGNMENT
py::class_<RWStepBasic_RWActionRequestAssignment> cls_RWStepBasic_RWActionRequestAssignment(mod, "RWStepBasic_RWActionRequestAssignment", "Read & Write tool for ActionRequestAssignment");

// Constructors
cls_RWStepBasic_RWActionRequestAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWActionRequestAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWActionRequestAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWActionRequestAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWActionRequestAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWActionRequestAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWActionRequestAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWActionRequestAssignment.def("ReadStep", (void (RWStepBasic_RWActionRequestAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ActionRequestAssignment> &) const) &RWStepBasic_RWActionRequestAssignment::ReadStep, "Reads ActionRequestAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWActionRequestAssignment.def("WriteStep", (void (RWStepBasic_RWActionRequestAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ActionRequestAssignment> &) const) &RWStepBasic_RWActionRequestAssignment::WriteStep, "Writes ActionRequestAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWActionRequestAssignment.def("Share", (void (RWStepBasic_RWActionRequestAssignment::*)(const opencascade::handle<StepBasic_ActionRequestAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWActionRequestAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWACTIONREQUESTSOLUTION
py::class_<RWStepBasic_RWActionRequestSolution> cls_RWStepBasic_RWActionRequestSolution(mod, "RWStepBasic_RWActionRequestSolution", "Read & Write tool for ActionRequestSolution");

// Constructors
cls_RWStepBasic_RWActionRequestSolution.def(py::init<>());

// Methods
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWActionRequestSolution::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWActionRequestSolution::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWActionRequestSolution::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWActionRequestSolution::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWActionRequestSolution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWActionRequestSolution.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWActionRequestSolution::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWActionRequestSolution.def("ReadStep", (void (RWStepBasic_RWActionRequestSolution::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ActionRequestSolution> &) const) &RWStepBasic_RWActionRequestSolution::ReadStep, "Reads ActionRequestSolution", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWActionRequestSolution.def("WriteStep", (void (RWStepBasic_RWActionRequestSolution::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ActionRequestSolution> &) const) &RWStepBasic_RWActionRequestSolution::WriteStep, "Writes ActionRequestSolution", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWActionRequestSolution.def("Share", (void (RWStepBasic_RWActionRequestSolution::*)(const opencascade::handle<StepBasic_ActionRequestSolution> &, Interface_EntityIterator &) const) &RWStepBasic_RWActionRequestSolution::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWADDRESS
py::class_<RWStepBasic_RWAddress> cls_RWStepBasic_RWAddress(mod, "RWStepBasic_RWAddress", "Read & Write Module for Address");

// Constructors
cls_RWStepBasic_RWAddress.def(py::init<>());

// Methods
// cls_RWStepBasic_RWAddress.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWAddress::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWAddress.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWAddress::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWAddress.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWAddress::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWAddress.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWAddress::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWAddress.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWAddress::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWAddress.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWAddress::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWAddress.def("ReadStep", (void (RWStepBasic_RWAddress::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Address> &) const) &RWStepBasic_RWAddress::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWAddress.def("WriteStep", (void (RWStepBasic_RWAddress::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Address> &) const) &RWStepBasic_RWAddress::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWAPPLICATIONCONTEXT
py::class_<RWStepBasic_RWApplicationContext> cls_RWStepBasic_RWApplicationContext(mod, "RWStepBasic_RWApplicationContext", "Read & Write Module for ApplicationContext");

// Constructors
cls_RWStepBasic_RWApplicationContext.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApplicationContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApplicationContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApplicationContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApplicationContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApplicationContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApplicationContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApplicationContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApplicationContext.def("ReadStep", (void (RWStepBasic_RWApplicationContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApplicationContext> &) const) &RWStepBasic_RWApplicationContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApplicationContext.def("WriteStep", (void (RWStepBasic_RWApplicationContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApplicationContext> &) const) &RWStepBasic_RWApplicationContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWAPPLICATIONCONTEXTELEMENT
py::class_<RWStepBasic_RWApplicationContextElement> cls_RWStepBasic_RWApplicationContextElement(mod, "RWStepBasic_RWApplicationContextElement", "Read & Write Module for ApplicationContextElement");

// Constructors
cls_RWStepBasic_RWApplicationContextElement.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApplicationContextElement::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApplicationContextElement::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApplicationContextElement::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApplicationContextElement::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApplicationContextElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationContextElement.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApplicationContextElement::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApplicationContextElement.def("ReadStep", (void (RWStepBasic_RWApplicationContextElement::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApplicationContextElement> &) const) &RWStepBasic_RWApplicationContextElement::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApplicationContextElement.def("WriteStep", (void (RWStepBasic_RWApplicationContextElement::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApplicationContextElement> &) const) &RWStepBasic_RWApplicationContextElement::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApplicationContextElement.def("Share", (void (RWStepBasic_RWApplicationContextElement::*)(const opencascade::handle<StepBasic_ApplicationContextElement> &, Interface_EntityIterator &) const) &RWStepBasic_RWApplicationContextElement::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPLICATIONPROTOCOLDEFINITION
py::class_<RWStepBasic_RWApplicationProtocolDefinition> cls_RWStepBasic_RWApplicationProtocolDefinition(mod, "RWStepBasic_RWApplicationProtocolDefinition", "Read & Write Module for ApplicationProtocolDefinition");

// Constructors
cls_RWStepBasic_RWApplicationProtocolDefinition.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApplicationProtocolDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApplicationProtocolDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApplicationProtocolDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApplicationProtocolDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApplicationProtocolDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApplicationProtocolDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApplicationProtocolDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApplicationProtocolDefinition.def("ReadStep", (void (RWStepBasic_RWApplicationProtocolDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApplicationProtocolDefinition> &) const) &RWStepBasic_RWApplicationProtocolDefinition::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApplicationProtocolDefinition.def("WriteStep", (void (RWStepBasic_RWApplicationProtocolDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApplicationProtocolDefinition> &) const) &RWStepBasic_RWApplicationProtocolDefinition::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApplicationProtocolDefinition.def("Share", (void (RWStepBasic_RWApplicationProtocolDefinition::*)(const opencascade::handle<StepBasic_ApplicationProtocolDefinition> &, Interface_EntityIterator &) const) &RWStepBasic_RWApplicationProtocolDefinition::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPROVAL
py::class_<RWStepBasic_RWApproval> cls_RWStepBasic_RWApproval(mod, "RWStepBasic_RWApproval", "Read & Write Module for Approval");

// Constructors
cls_RWStepBasic_RWApproval.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApproval.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApproval::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApproval.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApproval::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApproval.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApproval::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApproval.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApproval::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApproval.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApproval::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApproval.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApproval::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApproval.def("ReadStep", (void (RWStepBasic_RWApproval::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Approval> &) const) &RWStepBasic_RWApproval::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApproval.def("WriteStep", (void (RWStepBasic_RWApproval::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Approval> &) const) &RWStepBasic_RWApproval::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApproval.def("Share", (void (RWStepBasic_RWApproval::*)(const opencascade::handle<StepBasic_Approval> &, Interface_EntityIterator &) const) &RWStepBasic_RWApproval::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPROVALDATETIME
py::class_<RWStepBasic_RWApprovalDateTime> cls_RWStepBasic_RWApprovalDateTime(mod, "RWStepBasic_RWApprovalDateTime", "Read & Write Module for ApprovalDateTime");

// Constructors
cls_RWStepBasic_RWApprovalDateTime.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApprovalDateTime::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApprovalDateTime::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApprovalDateTime::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApprovalDateTime::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApprovalDateTime::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalDateTime.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApprovalDateTime::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApprovalDateTime.def("ReadStep", (void (RWStepBasic_RWApprovalDateTime::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApprovalDateTime> &) const) &RWStepBasic_RWApprovalDateTime::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApprovalDateTime.def("WriteStep", (void (RWStepBasic_RWApprovalDateTime::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApprovalDateTime> &) const) &RWStepBasic_RWApprovalDateTime::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApprovalDateTime.def("Share", (void (RWStepBasic_RWApprovalDateTime::*)(const opencascade::handle<StepBasic_ApprovalDateTime> &, Interface_EntityIterator &) const) &RWStepBasic_RWApprovalDateTime::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPROVALPERSONORGANIZATION
py::class_<RWStepBasic_RWApprovalPersonOrganization> cls_RWStepBasic_RWApprovalPersonOrganization(mod, "RWStepBasic_RWApprovalPersonOrganization", "Read & Write Module for ApprovalPersonOrganization");

// Constructors
cls_RWStepBasic_RWApprovalPersonOrganization.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApprovalPersonOrganization::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApprovalPersonOrganization::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApprovalPersonOrganization::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApprovalPersonOrganization::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApprovalPersonOrganization::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalPersonOrganization.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApprovalPersonOrganization::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApprovalPersonOrganization.def("ReadStep", (void (RWStepBasic_RWApprovalPersonOrganization::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApprovalPersonOrganization> &) const) &RWStepBasic_RWApprovalPersonOrganization::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApprovalPersonOrganization.def("WriteStep", (void (RWStepBasic_RWApprovalPersonOrganization::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApprovalPersonOrganization> &) const) &RWStepBasic_RWApprovalPersonOrganization::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApprovalPersonOrganization.def("Share", (void (RWStepBasic_RWApprovalPersonOrganization::*)(const opencascade::handle<StepBasic_ApprovalPersonOrganization> &, Interface_EntityIterator &) const) &RWStepBasic_RWApprovalPersonOrganization::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPROVALRELATIONSHIP
py::class_<RWStepBasic_RWApprovalRelationship> cls_RWStepBasic_RWApprovalRelationship(mod, "RWStepBasic_RWApprovalRelationship", "Read & Write Module for ApprovalRelationship");

// Constructors
cls_RWStepBasic_RWApprovalRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApprovalRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApprovalRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApprovalRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApprovalRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApprovalRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApprovalRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApprovalRelationship.def("ReadStep", (void (RWStepBasic_RWApprovalRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApprovalRelationship> &) const) &RWStepBasic_RWApprovalRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApprovalRelationship.def("WriteStep", (void (RWStepBasic_RWApprovalRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApprovalRelationship> &) const) &RWStepBasic_RWApprovalRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWApprovalRelationship.def("Share", (void (RWStepBasic_RWApprovalRelationship::*)(const opencascade::handle<StepBasic_ApprovalRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWApprovalRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWAPPROVALROLE
py::class_<RWStepBasic_RWApprovalRole> cls_RWStepBasic_RWApprovalRole(mod, "RWStepBasic_RWApprovalRole", "Read & Write Module for ApprovalRole");

// Constructors
cls_RWStepBasic_RWApprovalRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApprovalRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApprovalRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApprovalRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApprovalRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApprovalRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApprovalRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApprovalRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApprovalRole.def("ReadStep", (void (RWStepBasic_RWApprovalRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApprovalRole> &) const) &RWStepBasic_RWApprovalRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApprovalRole.def("WriteStep", (void (RWStepBasic_RWApprovalRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApprovalRole> &) const) &RWStepBasic_RWApprovalRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWAPPROVALSTATUS
py::class_<RWStepBasic_RWApprovalStatus> cls_RWStepBasic_RWApprovalStatus(mod, "RWStepBasic_RWApprovalStatus", "Read & Write Module for ApprovalStatus");

// Constructors
cls_RWStepBasic_RWApprovalStatus.def(py::init<>());

// Methods
// cls_RWStepBasic_RWApprovalStatus.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWApprovalStatus::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalStatus.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWApprovalStatus::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalStatus.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWApprovalStatus::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWApprovalStatus.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWApprovalStatus::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalStatus.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWApprovalStatus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWApprovalStatus.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWApprovalStatus::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWApprovalStatus.def("ReadStep", (void (RWStepBasic_RWApprovalStatus::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ApprovalStatus> &) const) &RWStepBasic_RWApprovalStatus::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWApprovalStatus.def("WriteStep", (void (RWStepBasic_RWApprovalStatus::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ApprovalStatus> &) const) &RWStepBasic_RWApprovalStatus::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWCALENDARDATE
py::class_<RWStepBasic_RWCalendarDate> cls_RWStepBasic_RWCalendarDate(mod, "RWStepBasic_RWCalendarDate", "Read & Write Module for CalendarDate");

// Constructors
cls_RWStepBasic_RWCalendarDate.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCalendarDate.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCalendarDate::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCalendarDate.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCalendarDate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCalendarDate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCalendarDate::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCalendarDate.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCalendarDate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCalendarDate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCalendarDate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCalendarDate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCalendarDate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCalendarDate.def("ReadStep", (void (RWStepBasic_RWCalendarDate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_CalendarDate> &) const) &RWStepBasic_RWCalendarDate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCalendarDate.def("WriteStep", (void (RWStepBasic_RWCalendarDate::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_CalendarDate> &) const) &RWStepBasic_RWCalendarDate::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWCERTIFICATION
py::class_<RWStepBasic_RWCertification> cls_RWStepBasic_RWCertification(mod, "RWStepBasic_RWCertification", "Read & Write tool for Certification");

// Constructors
cls_RWStepBasic_RWCertification.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCertification.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCertification::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertification.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCertification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCertification::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertification.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCertification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCertification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCertification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCertification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCertification.def("ReadStep", (void (RWStepBasic_RWCertification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Certification> &) const) &RWStepBasic_RWCertification::ReadStep, "Reads Certification", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCertification.def("WriteStep", (void (RWStepBasic_RWCertification::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Certification> &) const) &RWStepBasic_RWCertification::WriteStep, "Writes Certification", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWCertification.def("Share", (void (RWStepBasic_RWCertification::*)(const opencascade::handle<StepBasic_Certification> &, Interface_EntityIterator &) const) &RWStepBasic_RWCertification::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCERTIFICATIONASSIGNMENT
py::class_<RWStepBasic_RWCertificationAssignment> cls_RWStepBasic_RWCertificationAssignment(mod, "RWStepBasic_RWCertificationAssignment", "Read & Write tool for CertificationAssignment");

// Constructors
cls_RWStepBasic_RWCertificationAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCertificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCertificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCertificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCertificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCertificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCertificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCertificationAssignment.def("ReadStep", (void (RWStepBasic_RWCertificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_CertificationAssignment> &) const) &RWStepBasic_RWCertificationAssignment::ReadStep, "Reads CertificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCertificationAssignment.def("WriteStep", (void (RWStepBasic_RWCertificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_CertificationAssignment> &) const) &RWStepBasic_RWCertificationAssignment::WriteStep, "Writes CertificationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWCertificationAssignment.def("Share", (void (RWStepBasic_RWCertificationAssignment::*)(const opencascade::handle<StepBasic_CertificationAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWCertificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCERTIFICATIONTYPE
py::class_<RWStepBasic_RWCertificationType> cls_RWStepBasic_RWCertificationType(mod, "RWStepBasic_RWCertificationType", "Read & Write tool for CertificationType");

// Constructors
cls_RWStepBasic_RWCertificationType.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCertificationType.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCertificationType::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertificationType.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCertificationType::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationType.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCertificationType::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCertificationType.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCertificationType::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationType.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCertificationType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCertificationType.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCertificationType::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCertificationType.def("ReadStep", (void (RWStepBasic_RWCertificationType::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_CertificationType> &) const) &RWStepBasic_RWCertificationType::ReadStep, "Reads CertificationType", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCertificationType.def("WriteStep", (void (RWStepBasic_RWCertificationType::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_CertificationType> &) const) &RWStepBasic_RWCertificationType::WriteStep, "Writes CertificationType", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWCertificationType.def("Share", (void (RWStepBasic_RWCertificationType::*)(const opencascade::handle<StepBasic_CertificationType> &, Interface_EntityIterator &) const) &RWStepBasic_RWCertificationType::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCHARACTERIZEDOBJECT
py::class_<RWStepBasic_RWCharacterizedObject> cls_RWStepBasic_RWCharacterizedObject(mod, "RWStepBasic_RWCharacterizedObject", "Read & Write tool for CharacterizedObject");

// Constructors
cls_RWStepBasic_RWCharacterizedObject.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCharacterizedObject::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCharacterizedObject::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCharacterizedObject::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCharacterizedObject::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCharacterizedObject::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCharacterizedObject.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCharacterizedObject::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCharacterizedObject.def("ReadStep", (void (RWStepBasic_RWCharacterizedObject::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_CharacterizedObject> &) const) &RWStepBasic_RWCharacterizedObject::ReadStep, "Reads CharacterizedObject", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCharacterizedObject.def("WriteStep", (void (RWStepBasic_RWCharacterizedObject::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_CharacterizedObject> &) const) &RWStepBasic_RWCharacterizedObject::WriteStep, "Writes CharacterizedObject", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWCharacterizedObject.def("Share", (void (RWStepBasic_RWCharacterizedObject::*)(const opencascade::handle<StepBasic_CharacterizedObject> &, Interface_EntityIterator &) const) &RWStepBasic_RWCharacterizedObject::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONTRACT
py::class_<RWStepBasic_RWContract> cls_RWStepBasic_RWContract(mod, "RWStepBasic_RWContract", "Read & Write tool for Contract");

// Constructors
cls_RWStepBasic_RWContract.def(py::init<>());

// Methods
// cls_RWStepBasic_RWContract.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWContract::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWContract.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWContract::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContract.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWContract::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWContract.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWContract::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContract.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWContract::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWContract.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWContract::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWContract.def("ReadStep", (void (RWStepBasic_RWContract::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Contract> &) const) &RWStepBasic_RWContract::ReadStep, "Reads Contract", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWContract.def("WriteStep", (void (RWStepBasic_RWContract::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Contract> &) const) &RWStepBasic_RWContract::WriteStep, "Writes Contract", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWContract.def("Share", (void (RWStepBasic_RWContract::*)(const opencascade::handle<StepBasic_Contract> &, Interface_EntityIterator &) const) &RWStepBasic_RWContract::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONTRACTASSIGNMENT
py::class_<RWStepBasic_RWContractAssignment> cls_RWStepBasic_RWContractAssignment(mod, "RWStepBasic_RWContractAssignment", "Read & Write tool for ContractAssignment");

// Constructors
cls_RWStepBasic_RWContractAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWContractAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWContractAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWContractAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWContractAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContractAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWContractAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWContractAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWContractAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContractAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWContractAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWContractAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWContractAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWContractAssignment.def("ReadStep", (void (RWStepBasic_RWContractAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ContractAssignment> &) const) &RWStepBasic_RWContractAssignment::ReadStep, "Reads ContractAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWContractAssignment.def("WriteStep", (void (RWStepBasic_RWContractAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ContractAssignment> &) const) &RWStepBasic_RWContractAssignment::WriteStep, "Writes ContractAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWContractAssignment.def("Share", (void (RWStepBasic_RWContractAssignment::*)(const opencascade::handle<StepBasic_ContractAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWContractAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONTRACTTYPE
py::class_<RWStepBasic_RWContractType> cls_RWStepBasic_RWContractType(mod, "RWStepBasic_RWContractType", "Read & Write tool for ContractType");

// Constructors
cls_RWStepBasic_RWContractType.def(py::init<>());

// Methods
// cls_RWStepBasic_RWContractType.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWContractType::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWContractType.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWContractType::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContractType.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWContractType::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWContractType.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWContractType::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWContractType.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWContractType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWContractType.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWContractType::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWContractType.def("ReadStep", (void (RWStepBasic_RWContractType::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ContractType> &) const) &RWStepBasic_RWContractType::ReadStep, "Reads ContractType", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWContractType.def("WriteStep", (void (RWStepBasic_RWContractType::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ContractType> &) const) &RWStepBasic_RWContractType::WriteStep, "Writes ContractType", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWContractType.def("Share", (void (RWStepBasic_RWContractType::*)(const opencascade::handle<StepBasic_ContractType> &, Interface_EntityIterator &) const) &RWStepBasic_RWContractType::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNIT
py::class_<RWStepBasic_RWConversionBasedUnit> cls_RWStepBasic_RWConversionBasedUnit(mod, "RWStepBasic_RWConversionBasedUnit", "Read & Write Module for ConversionBasedUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnit> &) const) &RWStepBasic_RWConversionBasedUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnit> &) const) &RWStepBasic_RWConversionBasedUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDAREAUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndAreaUnit> cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit(mod, "RWStepBasic_RWConversionBasedUnitAndAreaUnit", "Read & Write Module for RWConversionBasedUnitAndAreaUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndAreaUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndAreaUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndAreaUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndAreaUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndAreaUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndAreaUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndAreaUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndAreaUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDLENGTHUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndLengthUnit> cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit(mod, "RWStepBasic_RWConversionBasedUnitAndLengthUnit", "Read & Write Module for ConversionBasedUnitAndLengthUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndLengthUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndLengthUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndLengthUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndLengthUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndLengthUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndLengthUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndLengthUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndLengthUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDMASSUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndMassUnit> cls_RWStepBasic_RWConversionBasedUnitAndMassUnit(mod, "RWStepBasic_RWConversionBasedUnitAndMassUnit", "Read & Write Module for ConversionBasedUnitAndMassUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndMassUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndMassUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndMassUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndMassUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndMassUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndMassUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndMassUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndMassUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndMassUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDPLANEANGLEUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit> cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit(mod, "RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit", "Read & Write Module for ConversionBasedUnitAndPlaneAngleUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndPlaneAngleUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndPlaneAngleUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndPlaneAngleUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDRATIOUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndRatioUnit> cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit(mod, "RWStepBasic_RWConversionBasedUnitAndRatioUnit", "Read & Write Module for ConversionBasedUnitAndRatioUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndRatioUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndRatioUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndRatioUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndRatioUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndRatioUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndRatioUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDSOLIDANGLEUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit> cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit(mod, "RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit", "Read & Write Module for ConversionBasedUnitAndSolidAngleUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndSolidAngleUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndSolidAngleUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndSolidAngleUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDTIMEUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndTimeUnit> cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit(mod, "RWStepBasic_RWConversionBasedUnitAndTimeUnit", "Read & Write Module for ConversionBasedUnitAndTimeUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndTimeUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndTimeUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndTimeUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndTimeUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndTimeUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndTimeUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCONVERSIONBASEDUNITANDVOLUMEUNIT
py::class_<RWStepBasic_RWConversionBasedUnitAndVolumeUnit> cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit(mod, "RWStepBasic_RWConversionBasedUnitAndVolumeUnit", "Read & Write Module for ConversionBasedUnitAndVolumeUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnitAndVolumeUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnitAndVolumeUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnitAndVolumeUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnitAndVolumeUnit> &) const) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnitAndVolumeUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnitAndVolumeUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnitAndVolumeUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnitAndVolumeUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWCOORDINATEDUNIVERSALTIMEOFFSET
py::class_<RWStepBasic_RWCoordinatedUniversalTimeOffset> cls_RWStepBasic_RWCoordinatedUniversalTimeOffset(mod, "RWStepBasic_RWCoordinatedUniversalTimeOffset", "Read & Write Module for CoordinatedUniversalTimeOffset");

// Constructors
cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def(py::init<>());

// Methods
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWCoordinatedUniversalTimeOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def("ReadStep", (void (RWStepBasic_RWCoordinatedUniversalTimeOffset::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &) const) &RWStepBasic_RWCoordinatedUniversalTimeOffset::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWCoordinatedUniversalTimeOffset.def("WriteStep", (void (RWStepBasic_RWCoordinatedUniversalTimeOffset::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &) const) &RWStepBasic_RWCoordinatedUniversalTimeOffset::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWDATE
py::class_<RWStepBasic_RWDate> cls_RWStepBasic_RWDate(mod, "RWStepBasic_RWDate", "Read & Write Module for Date");

// Constructors
cls_RWStepBasic_RWDate.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDate.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDate::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDate.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDate::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDate.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDate.def("ReadStep", (void (RWStepBasic_RWDate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Date> &) const) &RWStepBasic_RWDate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDate.def("WriteStep", (void (RWStepBasic_RWDate::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Date> &) const) &RWStepBasic_RWDate::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWDATEANDTIME
py::class_<RWStepBasic_RWDateAndTime> cls_RWStepBasic_RWDateAndTime(mod, "RWStepBasic_RWDateAndTime", "Read & Write Module for DateAndTime");

// Constructors
cls_RWStepBasic_RWDateAndTime.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDateAndTime.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDateAndTime::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateAndTime.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDateAndTime::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateAndTime.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDateAndTime::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateAndTime.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDateAndTime::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateAndTime.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDateAndTime::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDateAndTime.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDateAndTime::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDateAndTime.def("ReadStep", (void (RWStepBasic_RWDateAndTime::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DateAndTime> &) const) &RWStepBasic_RWDateAndTime::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDateAndTime.def("WriteStep", (void (RWStepBasic_RWDateAndTime::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DateAndTime> &) const) &RWStepBasic_RWDateAndTime::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDateAndTime.def("Share", (void (RWStepBasic_RWDateAndTime::*)(const opencascade::handle<StepBasic_DateAndTime> &, Interface_EntityIterator &) const) &RWStepBasic_RWDateAndTime::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDATEROLE
py::class_<RWStepBasic_RWDateRole> cls_RWStepBasic_RWDateRole(mod, "RWStepBasic_RWDateRole", "Read & Write Module for DateRole");

// Constructors
cls_RWStepBasic_RWDateRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDateRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDateRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDateRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDateRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDateRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDateRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDateRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDateRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDateRole.def("ReadStep", (void (RWStepBasic_RWDateRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DateRole> &) const) &RWStepBasic_RWDateRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDateRole.def("WriteStep", (void (RWStepBasic_RWDateRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DateRole> &) const) &RWStepBasic_RWDateRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWDATETIMEROLE
py::class_<RWStepBasic_RWDateTimeRole> cls_RWStepBasic_RWDateTimeRole(mod, "RWStepBasic_RWDateTimeRole", "Read & Write Module for DateTimeRole");

// Constructors
cls_RWStepBasic_RWDateTimeRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDateTimeRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDateTimeRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateTimeRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDateTimeRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateTimeRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDateTimeRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDateTimeRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDateTimeRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDateTimeRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDateTimeRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDateTimeRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDateTimeRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDateTimeRole.def("ReadStep", (void (RWStepBasic_RWDateTimeRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DateTimeRole> &) const) &RWStepBasic_RWDateTimeRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDateTimeRole.def("WriteStep", (void (RWStepBasic_RWDateTimeRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DateTimeRole> &) const) &RWStepBasic_RWDateTimeRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWDERIVEDUNIT
py::class_<RWStepBasic_RWDerivedUnit> cls_RWStepBasic_RWDerivedUnit(mod, "RWStepBasic_RWDerivedUnit", "Read & Write Module for DerivedUnit");

// Constructors
cls_RWStepBasic_RWDerivedUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDerivedUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDerivedUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDerivedUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDerivedUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDerivedUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDerivedUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDerivedUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDerivedUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDerivedUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDerivedUnit.def("ReadStep", (void (RWStepBasic_RWDerivedUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DerivedUnit> &) const) &RWStepBasic_RWDerivedUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDerivedUnit.def("WriteStep", (void (RWStepBasic_RWDerivedUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DerivedUnit> &) const) &RWStepBasic_RWDerivedUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDerivedUnit.def("Share", (void (RWStepBasic_RWDerivedUnit::*)(const opencascade::handle<StepBasic_DerivedUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWDerivedUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDERIVEDUNITELEMENT
py::class_<RWStepBasic_RWDerivedUnitElement> cls_RWStepBasic_RWDerivedUnitElement(mod, "RWStepBasic_RWDerivedUnitElement", "Read & Write Module for DerivedUnitElement");

// Constructors
cls_RWStepBasic_RWDerivedUnitElement.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDerivedUnitElement::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDerivedUnitElement::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDerivedUnitElement::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDerivedUnitElement::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDerivedUnitElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDerivedUnitElement.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDerivedUnitElement::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDerivedUnitElement.def("ReadStep", (void (RWStepBasic_RWDerivedUnitElement::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DerivedUnitElement> &) const) &RWStepBasic_RWDerivedUnitElement::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDerivedUnitElement.def("WriteStep", (void (RWStepBasic_RWDerivedUnitElement::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DerivedUnitElement> &) const) &RWStepBasic_RWDerivedUnitElement::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDerivedUnitElement.def("Share", (void (RWStepBasic_RWDerivedUnitElement::*)(const opencascade::handle<StepBasic_DerivedUnitElement> &, Interface_EntityIterator &) const) &RWStepBasic_RWDerivedUnitElement::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDIMENSIONALEXPONENTS
py::class_<RWStepBasic_RWDimensionalExponents> cls_RWStepBasic_RWDimensionalExponents(mod, "RWStepBasic_RWDimensionalExponents", "Read & Write Module for DimensionalExponents");

// Constructors
cls_RWStepBasic_RWDimensionalExponents.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDimensionalExponents::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDimensionalExponents::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDimensionalExponents::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDimensionalExponents::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDimensionalExponents::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDimensionalExponents.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDimensionalExponents::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDimensionalExponents.def("ReadStep", (void (RWStepBasic_RWDimensionalExponents::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DimensionalExponents> &) const) &RWStepBasic_RWDimensionalExponents::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDimensionalExponents.def("WriteStep", (void (RWStepBasic_RWDimensionalExponents::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DimensionalExponents> &) const) &RWStepBasic_RWDimensionalExponents::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWDOCUMENT
py::class_<RWStepBasic_RWDocument> cls_RWStepBasic_RWDocument(mod, "RWStepBasic_RWDocument", "Read & Write tool for Document");

// Constructors
cls_RWStepBasic_RWDocument.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocument.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocument::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocument.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocument::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocument.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocument::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocument.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocument::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocument.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocument::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocument.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocument::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocument.def("ReadStep", (void (RWStepBasic_RWDocument::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Document> &) const) &RWStepBasic_RWDocument::ReadStep, "Reads Document", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocument.def("WriteStep", (void (RWStepBasic_RWDocument::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Document> &) const) &RWStepBasic_RWDocument::WriteStep, "Writes Document", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocument.def("Share", (void (RWStepBasic_RWDocument::*)(const opencascade::handle<StepBasic_Document> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocument::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTFILE
py::class_<RWStepBasic_RWDocumentFile> cls_RWStepBasic_RWDocumentFile(mod, "RWStepBasic_RWDocumentFile", "Read & Write tool for DocumentFile");

// Constructors
cls_RWStepBasic_RWDocumentFile.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentFile.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentFile::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentFile.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentFile::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentFile.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentFile::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentFile.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentFile::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentFile.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentFile.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentFile::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentFile.def("ReadStep", (void (RWStepBasic_RWDocumentFile::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentFile> &) const) &RWStepBasic_RWDocumentFile::ReadStep, "Reads DocumentFile", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentFile.def("WriteStep", (void (RWStepBasic_RWDocumentFile::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentFile> &) const) &RWStepBasic_RWDocumentFile::WriteStep, "Writes DocumentFile", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentFile.def("Share", (void (RWStepBasic_RWDocumentFile::*)(const opencascade::handle<StepBasic_DocumentFile> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentFile::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTPRODUCTASSOCIATION
py::class_<RWStepBasic_RWDocumentProductAssociation> cls_RWStepBasic_RWDocumentProductAssociation(mod, "RWStepBasic_RWDocumentProductAssociation", "Read & Write tool for DocumentProductAssociation");

// Constructors
cls_RWStepBasic_RWDocumentProductAssociation.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentProductAssociation::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentProductAssociation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentProductAssociation::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentProductAssociation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentProductAssociation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductAssociation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentProductAssociation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentProductAssociation.def("ReadStep", (void (RWStepBasic_RWDocumentProductAssociation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentProductAssociation> &) const) &RWStepBasic_RWDocumentProductAssociation::ReadStep, "Reads DocumentProductAssociation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentProductAssociation.def("WriteStep", (void (RWStepBasic_RWDocumentProductAssociation::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentProductAssociation> &) const) &RWStepBasic_RWDocumentProductAssociation::WriteStep, "Writes DocumentProductAssociation", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentProductAssociation.def("Share", (void (RWStepBasic_RWDocumentProductAssociation::*)(const opencascade::handle<StepBasic_DocumentProductAssociation> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentProductAssociation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTPRODUCTEQUIVALENCE
py::class_<RWStepBasic_RWDocumentProductEquivalence> cls_RWStepBasic_RWDocumentProductEquivalence(mod, "RWStepBasic_RWDocumentProductEquivalence", "Read & Write tool for DocumentProductEquivalence");

// Constructors
cls_RWStepBasic_RWDocumentProductEquivalence.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentProductEquivalence::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentProductEquivalence::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentProductEquivalence::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentProductEquivalence::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentProductEquivalence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentProductEquivalence.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentProductEquivalence::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentProductEquivalence.def("ReadStep", (void (RWStepBasic_RWDocumentProductEquivalence::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentProductEquivalence> &) const) &RWStepBasic_RWDocumentProductEquivalence::ReadStep, "Reads DocumentProductEquivalence", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentProductEquivalence.def("WriteStep", (void (RWStepBasic_RWDocumentProductEquivalence::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentProductEquivalence> &) const) &RWStepBasic_RWDocumentProductEquivalence::WriteStep, "Writes DocumentProductEquivalence", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentProductEquivalence.def("Share", (void (RWStepBasic_RWDocumentProductEquivalence::*)(const opencascade::handle<StepBasic_DocumentProductEquivalence> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentProductEquivalence::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTRELATIONSHIP
py::class_<RWStepBasic_RWDocumentRelationship> cls_RWStepBasic_RWDocumentRelationship(mod, "RWStepBasic_RWDocumentRelationship", "Read & Write Module for DocumentRelationship");

// Constructors
cls_RWStepBasic_RWDocumentRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentRelationship.def("ReadStep", (void (RWStepBasic_RWDocumentRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentRelationship> &) const) &RWStepBasic_RWDocumentRelationship::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentRelationship.def("WriteStep", (void (RWStepBasic_RWDocumentRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentRelationship> &) const) &RWStepBasic_RWDocumentRelationship::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentRelationship.def("Share", (void (RWStepBasic_RWDocumentRelationship::*)(const opencascade::handle<StepBasic_DocumentRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentRelationship::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTREPRESENTATIONTYPE
py::class_<RWStepBasic_RWDocumentRepresentationType> cls_RWStepBasic_RWDocumentRepresentationType(mod, "RWStepBasic_RWDocumentRepresentationType", "Read & Write tool for DocumentRepresentationType");

// Constructors
cls_RWStepBasic_RWDocumentRepresentationType.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentRepresentationType::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentRepresentationType::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentRepresentationType::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentRepresentationType::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentRepresentationType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentRepresentationType.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentRepresentationType::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentRepresentationType.def("ReadStep", (void (RWStepBasic_RWDocumentRepresentationType::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentRepresentationType> &) const) &RWStepBasic_RWDocumentRepresentationType::ReadStep, "Reads DocumentRepresentationType", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentRepresentationType.def("WriteStep", (void (RWStepBasic_RWDocumentRepresentationType::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentRepresentationType> &) const) &RWStepBasic_RWDocumentRepresentationType::WriteStep, "Writes DocumentRepresentationType", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentRepresentationType.def("Share", (void (RWStepBasic_RWDocumentRepresentationType::*)(const opencascade::handle<StepBasic_DocumentRepresentationType> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentRepresentationType::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTTYPE
py::class_<RWStepBasic_RWDocumentType> cls_RWStepBasic_RWDocumentType(mod, "RWStepBasic_RWDocumentType", "Read & Write Module for DocumentType");

// Constructors
cls_RWStepBasic_RWDocumentType.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentType.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentType::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentType.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentType::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentType.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentType::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentType.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentType::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentType.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentType.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentType::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentType.def("ReadStep", (void (RWStepBasic_RWDocumentType::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentType> &) const) &RWStepBasic_RWDocumentType::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentType.def("WriteStep", (void (RWStepBasic_RWDocumentType::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentType> &) const) &RWStepBasic_RWDocumentType::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentType.def("Share", (void (RWStepBasic_RWDocumentType::*)(const opencascade::handle<StepBasic_DocumentType> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentType::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWDOCUMENTUSAGECONSTRAINT
py::class_<RWStepBasic_RWDocumentUsageConstraint> cls_RWStepBasic_RWDocumentUsageConstraint(mod, "RWStepBasic_RWDocumentUsageConstraint", "Read & Write Module for DocumentUsageConstraint");

// Constructors
cls_RWStepBasic_RWDocumentUsageConstraint.def(py::init<>());

// Methods
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDocumentUsageConstraint::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDocumentUsageConstraint::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDocumentUsageConstraint::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDocumentUsageConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDocumentUsageConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDocumentUsageConstraint.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDocumentUsageConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDocumentUsageConstraint.def("ReadStep", (void (RWStepBasic_RWDocumentUsageConstraint::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_DocumentUsageConstraint> &) const) &RWStepBasic_RWDocumentUsageConstraint::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDocumentUsageConstraint.def("WriteStep", (void (RWStepBasic_RWDocumentUsageConstraint::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_DocumentUsageConstraint> &) const) &RWStepBasic_RWDocumentUsageConstraint::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWDocumentUsageConstraint.def("Share", (void (RWStepBasic_RWDocumentUsageConstraint::*)(const opencascade::handle<StepBasic_DocumentUsageConstraint> &, Interface_EntityIterator &) const) &RWStepBasic_RWDocumentUsageConstraint::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEFFECTIVITY
py::class_<RWStepBasic_RWEffectivity> cls_RWStepBasic_RWEffectivity(mod, "RWStepBasic_RWEffectivity", "Read & Write Module for Effectivity");

// Constructors
cls_RWStepBasic_RWEffectivity.def(py::init<>());

// Methods
// cls_RWStepBasic_RWEffectivity.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWEffectivity::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWEffectivity.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWEffectivity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWEffectivity::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWEffectivity.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWEffectivity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWEffectivity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWEffectivity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWEffectivity.def("ReadStep", (void (RWStepBasic_RWEffectivity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Effectivity> &) const) &RWStepBasic_RWEffectivity::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWEffectivity.def("WriteStep", (void (RWStepBasic_RWEffectivity::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Effectivity> &) const) &RWStepBasic_RWEffectivity::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWEffectivity.def("Share", (void (RWStepBasic_RWEffectivity::*)(const opencascade::handle<StepBasic_Effectivity> &, Interface_EntityIterator &) const) &RWStepBasic_RWEffectivity::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEFFECTIVITYASSIGNMENT
py::class_<RWStepBasic_RWEffectivityAssignment> cls_RWStepBasic_RWEffectivityAssignment(mod, "RWStepBasic_RWEffectivityAssignment", "Read & Write tool for EffectivityAssignment");

// Constructors
cls_RWStepBasic_RWEffectivityAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWEffectivityAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWEffectivityAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWEffectivityAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWEffectivityAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWEffectivityAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWEffectivityAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWEffectivityAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWEffectivityAssignment.def("ReadStep", (void (RWStepBasic_RWEffectivityAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_EffectivityAssignment> &) const) &RWStepBasic_RWEffectivityAssignment::ReadStep, "Reads EffectivityAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWEffectivityAssignment.def("WriteStep", (void (RWStepBasic_RWEffectivityAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_EffectivityAssignment> &) const) &RWStepBasic_RWEffectivityAssignment::WriteStep, "Writes EffectivityAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWEffectivityAssignment.def("Share", (void (RWStepBasic_RWEffectivityAssignment::*)(const opencascade::handle<StepBasic_EffectivityAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWEffectivityAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEULERANGLES
py::class_<RWStepBasic_RWEulerAngles> cls_RWStepBasic_RWEulerAngles(mod, "RWStepBasic_RWEulerAngles", "Read & Write tool for EulerAngles");

// Constructors
cls_RWStepBasic_RWEulerAngles.def(py::init<>());

// Methods
// cls_RWStepBasic_RWEulerAngles.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWEulerAngles::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWEulerAngles.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWEulerAngles::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEulerAngles.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWEulerAngles::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWEulerAngles.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWEulerAngles::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWEulerAngles.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWEulerAngles::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWEulerAngles.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWEulerAngles::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWEulerAngles.def("ReadStep", (void (RWStepBasic_RWEulerAngles::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_EulerAngles> &) const) &RWStepBasic_RWEulerAngles::ReadStep, "Reads EulerAngles", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWEulerAngles.def("WriteStep", (void (RWStepBasic_RWEulerAngles::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_EulerAngles> &) const) &RWStepBasic_RWEulerAngles::WriteStep, "Writes EulerAngles", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWEulerAngles.def("Share", (void (RWStepBasic_RWEulerAngles::*)(const opencascade::handle<StepBasic_EulerAngles> &, Interface_EntityIterator &) const) &RWStepBasic_RWEulerAngles::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEXTERNALIDENTIFICATIONASSIGNMENT
py::class_<RWStepBasic_RWExternalIdentificationAssignment> cls_RWStepBasic_RWExternalIdentificationAssignment(mod, "RWStepBasic_RWExternalIdentificationAssignment", "Read & Write tool for ExternalIdentificationAssignment");

// Constructors
cls_RWStepBasic_RWExternalIdentificationAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWExternalIdentificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWExternalIdentificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("ReadStep", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &) const) &RWStepBasic_RWExternalIdentificationAssignment::ReadStep, "Reads ExternalIdentificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("WriteStep", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &) const) &RWStepBasic_RWExternalIdentificationAssignment::WriteStep, "Writes ExternalIdentificationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("Share", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWExternalIdentificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEXTERNALLYDEFINEDITEM
py::class_<RWStepBasic_RWExternallyDefinedItem> cls_RWStepBasic_RWExternallyDefinedItem(mod, "RWStepBasic_RWExternallyDefinedItem", "Read & Write tool for ExternallyDefinedItem");

// Constructors
cls_RWStepBasic_RWExternallyDefinedItem.def(py::init<>());

// Methods
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWExternallyDefinedItem::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWExternallyDefinedItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWExternallyDefinedItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWExternallyDefinedItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWExternallyDefinedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWExternallyDefinedItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWExternallyDefinedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWExternallyDefinedItem.def("ReadStep", (void (RWStepBasic_RWExternallyDefinedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ExternallyDefinedItem> &) const) &RWStepBasic_RWExternallyDefinedItem::ReadStep, "Reads ExternallyDefinedItem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWExternallyDefinedItem.def("WriteStep", (void (RWStepBasic_RWExternallyDefinedItem::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ExternallyDefinedItem> &) const) &RWStepBasic_RWExternallyDefinedItem::WriteStep, "Writes ExternallyDefinedItem", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWExternallyDefinedItem.def("Share", (void (RWStepBasic_RWExternallyDefinedItem::*)(const opencascade::handle<StepBasic_ExternallyDefinedItem> &, Interface_EntityIterator &) const) &RWStepBasic_RWExternallyDefinedItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWEXTERNALSOURCE
py::class_<RWStepBasic_RWExternalSource> cls_RWStepBasic_RWExternalSource(mod, "RWStepBasic_RWExternalSource", "Read & Write tool for ExternalSource");

// Constructors
cls_RWStepBasic_RWExternalSource.def(py::init<>());

// Methods
// cls_RWStepBasic_RWExternalSource.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWExternalSource::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalSource.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWExternalSource::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalSource.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWExternalSource::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalSource.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWExternalSource::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalSource.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWExternalSource::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWExternalSource.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWExternalSource::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWExternalSource.def("ReadStep", (void (RWStepBasic_RWExternalSource::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ExternalSource> &) const) &RWStepBasic_RWExternalSource::ReadStep, "Reads ExternalSource", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWExternalSource.def("WriteStep", (void (RWStepBasic_RWExternalSource::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ExternalSource> &) const) &RWStepBasic_RWExternalSource::WriteStep, "Writes ExternalSource", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWExternalSource.def("Share", (void (RWStepBasic_RWExternalSource::*)(const opencascade::handle<StepBasic_ExternalSource> &, Interface_EntityIterator &) const) &RWStepBasic_RWExternalSource::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWGENERALPROPERTY
py::class_<RWStepBasic_RWGeneralProperty> cls_RWStepBasic_RWGeneralProperty(mod, "RWStepBasic_RWGeneralProperty", "Read & Write tool for GeneralProperty");

// Constructors
cls_RWStepBasic_RWGeneralProperty.def(py::init<>());

// Methods
// cls_RWStepBasic_RWGeneralProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWGeneralProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWGeneralProperty.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWGeneralProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGeneralProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWGeneralProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWGeneralProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWGeneralProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGeneralProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWGeneralProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWGeneralProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWGeneralProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWGeneralProperty.def("ReadStep", (void (RWStepBasic_RWGeneralProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_GeneralProperty> &) const) &RWStepBasic_RWGeneralProperty::ReadStep, "Reads GeneralProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWGeneralProperty.def("WriteStep", (void (RWStepBasic_RWGeneralProperty::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_GeneralProperty> &) const) &RWStepBasic_RWGeneralProperty::WriteStep, "Writes GeneralProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWGeneralProperty.def("Share", (void (RWStepBasic_RWGeneralProperty::*)(const opencascade::handle<StepBasic_GeneralProperty> &, Interface_EntityIterator &) const) &RWStepBasic_RWGeneralProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWGROUP
py::class_<RWStepBasic_RWGroup> cls_RWStepBasic_RWGroup(mod, "RWStepBasic_RWGroup", "Read & Write tool for Group");

// Constructors
cls_RWStepBasic_RWGroup.def(py::init<>());

// Methods
// cls_RWStepBasic_RWGroup.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWGroup::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroup.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWGroup::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroup.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWGroup::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroup.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWGroup::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroup.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWGroup.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWGroup.def("ReadStep", (void (RWStepBasic_RWGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Group> &) const) &RWStepBasic_RWGroup::ReadStep, "Reads Group", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWGroup.def("WriteStep", (void (RWStepBasic_RWGroup::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Group> &) const) &RWStepBasic_RWGroup::WriteStep, "Writes Group", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWGroup.def("Share", (void (RWStepBasic_RWGroup::*)(const opencascade::handle<StepBasic_Group> &, Interface_EntityIterator &) const) &RWStepBasic_RWGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWGROUPASSIGNMENT
py::class_<RWStepBasic_RWGroupAssignment> cls_RWStepBasic_RWGroupAssignment(mod, "RWStepBasic_RWGroupAssignment", "Read & Write tool for GroupAssignment");

// Constructors
cls_RWStepBasic_RWGroupAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWGroupAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWGroupAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroupAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWGroupAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroupAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWGroupAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroupAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWGroupAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroupAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWGroupAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWGroupAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWGroupAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWGroupAssignment.def("ReadStep", (void (RWStepBasic_RWGroupAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_GroupAssignment> &) const) &RWStepBasic_RWGroupAssignment::ReadStep, "Reads GroupAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWGroupAssignment.def("WriteStep", (void (RWStepBasic_RWGroupAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_GroupAssignment> &) const) &RWStepBasic_RWGroupAssignment::WriteStep, "Writes GroupAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWGroupAssignment.def("Share", (void (RWStepBasic_RWGroupAssignment::*)(const opencascade::handle<StepBasic_GroupAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWGroupAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWGROUPRELATIONSHIP
py::class_<RWStepBasic_RWGroupRelationship> cls_RWStepBasic_RWGroupRelationship(mod, "RWStepBasic_RWGroupRelationship", "Read & Write tool for GroupRelationship");

// Constructors
cls_RWStepBasic_RWGroupRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWGroupRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWGroupRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroupRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWGroupRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroupRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWGroupRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWGroupRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWGroupRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWGroupRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWGroupRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWGroupRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWGroupRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWGroupRelationship.def("ReadStep", (void (RWStepBasic_RWGroupRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_GroupRelationship> &) const) &RWStepBasic_RWGroupRelationship::ReadStep, "Reads GroupRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWGroupRelationship.def("WriteStep", (void (RWStepBasic_RWGroupRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_GroupRelationship> &) const) &RWStepBasic_RWGroupRelationship::WriteStep, "Writes GroupRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWGroupRelationship.def("Share", (void (RWStepBasic_RWGroupRelationship::*)(const opencascade::handle<StepBasic_GroupRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWGroupRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWIDENTIFICATIONASSIGNMENT
py::class_<RWStepBasic_RWIdentificationAssignment> cls_RWStepBasic_RWIdentificationAssignment(mod, "RWStepBasic_RWIdentificationAssignment", "Read & Write tool for IdentificationAssignment");

// Constructors
cls_RWStepBasic_RWIdentificationAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWIdentificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWIdentificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWIdentificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWIdentificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWIdentificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWIdentificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWIdentificationAssignment.def("ReadStep", (void (RWStepBasic_RWIdentificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_IdentificationAssignment> &) const) &RWStepBasic_RWIdentificationAssignment::ReadStep, "Reads IdentificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWIdentificationAssignment.def("WriteStep", (void (RWStepBasic_RWIdentificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_IdentificationAssignment> &) const) &RWStepBasic_RWIdentificationAssignment::WriteStep, "Writes IdentificationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWIdentificationAssignment.def("Share", (void (RWStepBasic_RWIdentificationAssignment::*)(const opencascade::handle<StepBasic_IdentificationAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWIdentificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWIDENTIFICATIONROLE
py::class_<RWStepBasic_RWIdentificationRole> cls_RWStepBasic_RWIdentificationRole(mod, "RWStepBasic_RWIdentificationRole", "Read & Write tool for IdentificationRole");

// Constructors
cls_RWStepBasic_RWIdentificationRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWIdentificationRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWIdentificationRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWIdentificationRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWIdentificationRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWIdentificationRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWIdentificationRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWIdentificationRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWIdentificationRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWIdentificationRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWIdentificationRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWIdentificationRole.def("ReadStep", (void (RWStepBasic_RWIdentificationRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_IdentificationRole> &) const) &RWStepBasic_RWIdentificationRole::ReadStep, "Reads IdentificationRole", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWIdentificationRole.def("WriteStep", (void (RWStepBasic_RWIdentificationRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_IdentificationRole> &) const) &RWStepBasic_RWIdentificationRole::WriteStep, "Writes IdentificationRole", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWIdentificationRole.def("Share", (void (RWStepBasic_RWIdentificationRole::*)(const opencascade::handle<StepBasic_IdentificationRole> &, Interface_EntityIterator &) const) &RWStepBasic_RWIdentificationRole::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWLENGTHMEASUREWITHUNIT
py::class_<RWStepBasic_RWLengthMeasureWithUnit> cls_RWStepBasic_RWLengthMeasureWithUnit(mod, "RWStepBasic_RWLengthMeasureWithUnit", "Read & Write Module for LengthMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWLengthMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWLengthMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWLengthMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWLengthMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWLengthMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWLengthMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWLengthMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWLengthMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWLengthMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWLengthMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &) const) &RWStepBasic_RWLengthMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWLengthMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWLengthMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &) const) &RWStepBasic_RWLengthMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWLengthMeasureWithUnit.def("Share", (void (RWStepBasic_RWLengthMeasureWithUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWLengthMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWLENGTHUNIT
py::class_<RWStepBasic_RWLengthUnit> cls_RWStepBasic_RWLengthUnit(mod, "RWStepBasic_RWLengthUnit", "Read & Write Module for LengthUnit");

// Constructors
cls_RWStepBasic_RWLengthUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWLengthUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWLengthUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWLengthUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWLengthUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLengthUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWLengthUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWLengthUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWLengthUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLengthUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWLengthUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWLengthUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWLengthUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWLengthUnit.def("ReadStep", (void (RWStepBasic_RWLengthUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_LengthUnit> &) const) &RWStepBasic_RWLengthUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWLengthUnit.def("WriteStep", (void (RWStepBasic_RWLengthUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_LengthUnit> &) const) &RWStepBasic_RWLengthUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWLengthUnit.def("Share", (void (RWStepBasic_RWLengthUnit::*)(const opencascade::handle<StepBasic_LengthUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWLengthUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWLOCALTIME
py::class_<RWStepBasic_RWLocalTime> cls_RWStepBasic_RWLocalTime(mod, "RWStepBasic_RWLocalTime", "Read & Write Module for LocalTime");

// Constructors
cls_RWStepBasic_RWLocalTime.def(py::init<>());

// Methods
// cls_RWStepBasic_RWLocalTime.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWLocalTime::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWLocalTime.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWLocalTime::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLocalTime.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWLocalTime::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWLocalTime.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWLocalTime::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWLocalTime.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWLocalTime::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWLocalTime.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWLocalTime::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWLocalTime.def("ReadStep", (void (RWStepBasic_RWLocalTime::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_LocalTime> &) const) &RWStepBasic_RWLocalTime::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWLocalTime.def("WriteStep", (void (RWStepBasic_RWLocalTime::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_LocalTime> &) const) &RWStepBasic_RWLocalTime::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWLocalTime.def("Share", (void (RWStepBasic_RWLocalTime::*)(const opencascade::handle<StepBasic_LocalTime> &, Interface_EntityIterator &) const) &RWStepBasic_RWLocalTime::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWMASSMEASUREWITHUNIT
py::class_<RWStepBasic_RWMassMeasureWithUnit> cls_RWStepBasic_RWMassMeasureWithUnit(mod, "RWStepBasic_RWMassMeasureWithUnit", "Read & Write Module for MassMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWMassMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWMassMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWMassMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWMassMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWMassMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWMassMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWMassMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWMassMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWMassMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWMassMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_MassMeasureWithUnit> &) const) &RWStepBasic_RWMassMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWMassMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWMassMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_MassMeasureWithUnit> &) const) &RWStepBasic_RWMassMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWMassMeasureWithUnit.def("Share", (void (RWStepBasic_RWMassMeasureWithUnit::*)(const opencascade::handle<StepBasic_MassMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWMassMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWMASSUNIT
py::class_<RWStepBasic_RWMassUnit> cls_RWStepBasic_RWMassUnit(mod, "RWStepBasic_RWMassUnit", "Read & Write tool for MassUnit");

// Constructors
cls_RWStepBasic_RWMassUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWMassUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWMassUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWMassUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWMassUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMassUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWMassUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWMassUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWMassUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMassUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWMassUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWMassUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWMassUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWMassUnit.def("ReadStep", (void (RWStepBasic_RWMassUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_MassUnit> &) const) &RWStepBasic_RWMassUnit::ReadStep, "Reads MassUnit", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWMassUnit.def("WriteStep", (void (RWStepBasic_RWMassUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_MassUnit> &) const) &RWStepBasic_RWMassUnit::WriteStep, "Writes MassUnit", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWMassUnit.def("Share", (void (RWStepBasic_RWMassUnit::*)(const opencascade::handle<StepBasic_MassUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWMassUnit::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWMEASUREWITHUNIT
py::class_<RWStepBasic_RWMeasureWithUnit> cls_RWStepBasic_RWMeasureWithUnit(mod, "RWStepBasic_RWMeasureWithUnit", "Read & Write Module for MeasureWithUnit");

// Constructors
cls_RWStepBasic_RWMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_MeasureWithUnit> &) const) &RWStepBasic_RWMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_MeasureWithUnit> &) const) &RWStepBasic_RWMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWMeasureWithUnit.def("Share", (void (RWStepBasic_RWMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWMECHANICALCONTEXT
py::class_<RWStepBasic_RWMechanicalContext> cls_RWStepBasic_RWMechanicalContext(mod, "RWStepBasic_RWMechanicalContext", "Read & Write Module for MechanicalContext");

// Constructors
cls_RWStepBasic_RWMechanicalContext.def(py::init<>());

// Methods
// cls_RWStepBasic_RWMechanicalContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWMechanicalContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWMechanicalContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWMechanicalContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMechanicalContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWMechanicalContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWMechanicalContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWMechanicalContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWMechanicalContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWMechanicalContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWMechanicalContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWMechanicalContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWMechanicalContext.def("ReadStep", (void (RWStepBasic_RWMechanicalContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_MechanicalContext> &) const) &RWStepBasic_RWMechanicalContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWMechanicalContext.def("WriteStep", (void (RWStepBasic_RWMechanicalContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_MechanicalContext> &) const) &RWStepBasic_RWMechanicalContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWMechanicalContext.def("Share", (void (RWStepBasic_RWMechanicalContext::*)(const opencascade::handle<StepBasic_MechanicalContext> &, Interface_EntityIterator &) const) &RWStepBasic_RWMechanicalContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWNAMEASSIGNMENT
py::class_<RWStepBasic_RWNameAssignment> cls_RWStepBasic_RWNameAssignment(mod, "RWStepBasic_RWNameAssignment", "Read & Write tool for NameAssignment");

// Constructors
cls_RWStepBasic_RWNameAssignment.def(py::init<>());

// Methods
// cls_RWStepBasic_RWNameAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWNameAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWNameAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWNameAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWNameAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWNameAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWNameAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWNameAssignment.def("ReadStep", (void (RWStepBasic_RWNameAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_NameAssignment> &) const) &RWStepBasic_RWNameAssignment::ReadStep, "Reads NameAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWNameAssignment.def("WriteStep", (void (RWStepBasic_RWNameAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_NameAssignment> &) const) &RWStepBasic_RWNameAssignment::WriteStep, "Writes NameAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWNameAssignment.def("Share", (void (RWStepBasic_RWNameAssignment::*)(const opencascade::handle<StepBasic_NameAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWNameAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWNAMEDUNIT
py::class_<RWStepBasic_RWNamedUnit> cls_RWStepBasic_RWNamedUnit(mod, "RWStepBasic_RWNamedUnit", "Read & Write Module for NamedUnit");

// Constructors
cls_RWStepBasic_RWNamedUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWNamedUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWNamedUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWNamedUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWNamedUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNamedUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWNamedUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWNamedUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWNamedUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNamedUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWNamedUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWNamedUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWNamedUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWNamedUnit.def("ReadStep", (void (RWStepBasic_RWNamedUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_NamedUnit> &) const) &RWStepBasic_RWNamedUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWNamedUnit.def("WriteStep", (void (RWStepBasic_RWNamedUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_NamedUnit> &) const) &RWStepBasic_RWNamedUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWNamedUnit.def("Share", (void (RWStepBasic_RWNamedUnit::*)(const opencascade::handle<StepBasic_NamedUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWNamedUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWOBJECTROLE
py::class_<RWStepBasic_RWObjectRole> cls_RWStepBasic_RWObjectRole(mod, "RWStepBasic_RWObjectRole", "Read & Write tool for ObjectRole");

// Constructors
cls_RWStepBasic_RWObjectRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWObjectRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWObjectRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWObjectRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWObjectRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWObjectRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWObjectRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWObjectRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWObjectRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWObjectRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWObjectRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWObjectRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWObjectRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWObjectRole.def("ReadStep", (void (RWStepBasic_RWObjectRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ObjectRole> &) const) &RWStepBasic_RWObjectRole::ReadStep, "Reads ObjectRole", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWObjectRole.def("WriteStep", (void (RWStepBasic_RWObjectRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ObjectRole> &) const) &RWStepBasic_RWObjectRole::WriteStep, "Writes ObjectRole", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWObjectRole.def("Share", (void (RWStepBasic_RWObjectRole::*)(const opencascade::handle<StepBasic_ObjectRole> &, Interface_EntityIterator &) const) &RWStepBasic_RWObjectRole::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWORDINALDATE
py::class_<RWStepBasic_RWOrdinalDate> cls_RWStepBasic_RWOrdinalDate(mod, "RWStepBasic_RWOrdinalDate", "Read & Write Module for OrdinalDate");

// Constructors
cls_RWStepBasic_RWOrdinalDate.def(py::init<>());

// Methods
// cls_RWStepBasic_RWOrdinalDate.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWOrdinalDate::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrdinalDate.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWOrdinalDate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrdinalDate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWOrdinalDate::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrdinalDate.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWOrdinalDate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrdinalDate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWOrdinalDate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWOrdinalDate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWOrdinalDate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWOrdinalDate.def("ReadStep", (void (RWStepBasic_RWOrdinalDate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_OrdinalDate> &) const) &RWStepBasic_RWOrdinalDate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWOrdinalDate.def("WriteStep", (void (RWStepBasic_RWOrdinalDate::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_OrdinalDate> &) const) &RWStepBasic_RWOrdinalDate::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWORGANIZATION
py::class_<RWStepBasic_RWOrganization> cls_RWStepBasic_RWOrganization(mod, "RWStepBasic_RWOrganization", "Read & Write Module for Organization");

// Constructors
cls_RWStepBasic_RWOrganization.def(py::init<>());

// Methods
// cls_RWStepBasic_RWOrganization.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWOrganization::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganization.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWOrganization::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganization.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWOrganization::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganization.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWOrganization::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganization.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWOrganization::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWOrganization.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWOrganization::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWOrganization.def("ReadStep", (void (RWStepBasic_RWOrganization::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Organization> &) const) &RWStepBasic_RWOrganization::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWOrganization.def("WriteStep", (void (RWStepBasic_RWOrganization::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Organization> &) const) &RWStepBasic_RWOrganization::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWORGANIZATIONALADDRESS
py::class_<RWStepBasic_RWOrganizationalAddress> cls_RWStepBasic_RWOrganizationalAddress(mod, "RWStepBasic_RWOrganizationalAddress", "Read & Write Module for OrganizationalAddress");

// Constructors
cls_RWStepBasic_RWOrganizationalAddress.def(py::init<>());

// Methods
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationalAddress::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWOrganizationalAddress::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationalAddress::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWOrganizationalAddress::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWOrganizationalAddress::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationalAddress.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWOrganizationalAddress::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWOrganizationalAddress.def("ReadStep", (void (RWStepBasic_RWOrganizationalAddress::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_OrganizationalAddress> &) const) &RWStepBasic_RWOrganizationalAddress::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWOrganizationalAddress.def("WriteStep", (void (RWStepBasic_RWOrganizationalAddress::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_OrganizationalAddress> &) const) &RWStepBasic_RWOrganizationalAddress::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWOrganizationalAddress.def("Share", (void (RWStepBasic_RWOrganizationalAddress::*)(const opencascade::handle<StepBasic_OrganizationalAddress> &, Interface_EntityIterator &) const) &RWStepBasic_RWOrganizationalAddress::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWORGANIZATIONROLE
py::class_<RWStepBasic_RWOrganizationRole> cls_RWStepBasic_RWOrganizationRole(mod, "RWStepBasic_RWOrganizationRole", "Read & Write Module for OrganizationRole");

// Constructors
cls_RWStepBasic_RWOrganizationRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWOrganizationRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWOrganizationRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWOrganizationRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWOrganizationRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWOrganizationRole.def("ReadStep", (void (RWStepBasic_RWOrganizationRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_OrganizationRole> &) const) &RWStepBasic_RWOrganizationRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWOrganizationRole.def("WriteStep", (void (RWStepBasic_RWOrganizationRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_OrganizationRole> &) const) &RWStepBasic_RWOrganizationRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWPERSON
py::class_<RWStepBasic_RWPerson> cls_RWStepBasic_RWPerson(mod, "RWStepBasic_RWPerson", "Read & Write Module for Person");

// Constructors
cls_RWStepBasic_RWPerson.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPerson.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPerson::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPerson.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPerson::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPerson.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPerson::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPerson.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPerson::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPerson.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPerson::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPerson.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPerson::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPerson.def("ReadStep", (void (RWStepBasic_RWPerson::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Person> &) const) &RWStepBasic_RWPerson::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPerson.def("WriteStep", (void (RWStepBasic_RWPerson::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Person> &) const) &RWStepBasic_RWPerson::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWPERSONALADDRESS
py::class_<RWStepBasic_RWPersonalAddress> cls_RWStepBasic_RWPersonalAddress(mod, "RWStepBasic_RWPersonalAddress", "Read & Write Module for PersonalAddress");

// Constructors
cls_RWStepBasic_RWPersonalAddress.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPersonalAddress.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPersonalAddress::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonalAddress.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPersonalAddress::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonalAddress.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPersonalAddress::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonalAddress.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPersonalAddress::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonalAddress.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPersonalAddress::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPersonalAddress.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPersonalAddress::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPersonalAddress.def("ReadStep", (void (RWStepBasic_RWPersonalAddress::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_PersonalAddress> &) const) &RWStepBasic_RWPersonalAddress::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPersonalAddress.def("WriteStep", (void (RWStepBasic_RWPersonalAddress::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_PersonalAddress> &) const) &RWStepBasic_RWPersonalAddress::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWPersonalAddress.def("Share", (void (RWStepBasic_RWPersonalAddress::*)(const opencascade::handle<StepBasic_PersonalAddress> &, Interface_EntityIterator &) const) &RWStepBasic_RWPersonalAddress::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPERSONANDORGANIZATION
py::class_<RWStepBasic_RWPersonAndOrganization> cls_RWStepBasic_RWPersonAndOrganization(mod, "RWStepBasic_RWPersonAndOrganization", "Read & Write Module for PersonAndOrganization");

// Constructors
cls_RWStepBasic_RWPersonAndOrganization.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPersonAndOrganization::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPersonAndOrganization::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPersonAndOrganization::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPersonAndOrganization::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPersonAndOrganization::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganization.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPersonAndOrganization::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPersonAndOrganization.def("ReadStep", (void (RWStepBasic_RWPersonAndOrganization::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_PersonAndOrganization> &) const) &RWStepBasic_RWPersonAndOrganization::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPersonAndOrganization.def("WriteStep", (void (RWStepBasic_RWPersonAndOrganization::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_PersonAndOrganization> &) const) &RWStepBasic_RWPersonAndOrganization::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWPersonAndOrganization.def("Share", (void (RWStepBasic_RWPersonAndOrganization::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, Interface_EntityIterator &) const) &RWStepBasic_RWPersonAndOrganization::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPERSONANDORGANIZATIONROLE
py::class_<RWStepBasic_RWPersonAndOrganizationRole> cls_RWStepBasic_RWPersonAndOrganizationRole(mod, "RWStepBasic_RWPersonAndOrganizationRole", "Read & Write Module for PersonAndOrganizationRole");

// Constructors
cls_RWStepBasic_RWPersonAndOrganizationRole.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPersonAndOrganizationRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPersonAndOrganizationRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPersonAndOrganizationRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPersonAndOrganizationRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPersonAndOrganizationRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPersonAndOrganizationRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPersonAndOrganizationRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPersonAndOrganizationRole.def("ReadStep", (void (RWStepBasic_RWPersonAndOrganizationRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &) const) &RWStepBasic_RWPersonAndOrganizationRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPersonAndOrganizationRole.def("WriteStep", (void (RWStepBasic_RWPersonAndOrganizationRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &) const) &RWStepBasic_RWPersonAndOrganizationRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWPLANEANGLEMEASUREWITHUNIT
py::class_<RWStepBasic_RWPlaneAngleMeasureWithUnit> cls_RWStepBasic_RWPlaneAngleMeasureWithUnit(mod, "RWStepBasic_RWPlaneAngleMeasureWithUnit", "Read & Write Module for PlaneAngleMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPlaneAngleMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWPlaneAngleMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &) const) &RWStepBasic_RWPlaneAngleMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWPlaneAngleMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &) const) &RWStepBasic_RWPlaneAngleMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWPlaneAngleMeasureWithUnit.def("Share", (void (RWStepBasic_RWPlaneAngleMeasureWithUnit::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWPlaneAngleMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPLANEANGLEUNIT
py::class_<RWStepBasic_RWPlaneAngleUnit> cls_RWStepBasic_RWPlaneAngleUnit(mod, "RWStepBasic_RWPlaneAngleUnit", "Read & Write Module for PlaneAngleUnit");

// Constructors
cls_RWStepBasic_RWPlaneAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWPlaneAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWPlaneAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWPlaneAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWPlaneAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWPlaneAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWPlaneAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWPlaneAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWPlaneAngleUnit.def("ReadStep", (void (RWStepBasic_RWPlaneAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_PlaneAngleUnit> &) const) &RWStepBasic_RWPlaneAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWPlaneAngleUnit.def("WriteStep", (void (RWStepBasic_RWPlaneAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_PlaneAngleUnit> &) const) &RWStepBasic_RWPlaneAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWPlaneAngleUnit.def("Share", (void (RWStepBasic_RWPlaneAngleUnit::*)(const opencascade::handle<StepBasic_PlaneAngleUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWPlaneAngleUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCT
py::class_<RWStepBasic_RWProduct> cls_RWStepBasic_RWProduct(mod, "RWStepBasic_RWProduct", "Read & Write Module for Product");

// Constructors
cls_RWStepBasic_RWProduct.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProduct.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProduct::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProduct.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProduct::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProduct.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProduct::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProduct.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProduct::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProduct.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProduct::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProduct.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProduct::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProduct.def("ReadStep", (void (RWStepBasic_RWProduct::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Product> &) const) &RWStepBasic_RWProduct::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProduct.def("WriteStep", (void (RWStepBasic_RWProduct::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Product> &) const) &RWStepBasic_RWProduct::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProduct.def("Share", (void (RWStepBasic_RWProduct::*)(const opencascade::handle<StepBasic_Product> &, Interface_EntityIterator &) const) &RWStepBasic_RWProduct::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTCATEGORY
py::class_<RWStepBasic_RWProductCategory> cls_RWStepBasic_RWProductCategory(mod, "RWStepBasic_RWProductCategory", "Read & Write Module for ProductCategory");

// Constructors
cls_RWStepBasic_RWProductCategory.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductCategory.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductCategory::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductCategory.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductCategory::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategory.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductCategory::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductCategory.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductCategory::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategory.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductCategory::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategory.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductCategory::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductCategory.def("ReadStep", (void (RWStepBasic_RWProductCategory::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductCategory> &) const) &RWStepBasic_RWProductCategory::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductCategory.def("WriteStep", (void (RWStepBasic_RWProductCategory::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductCategory> &) const) &RWStepBasic_RWProductCategory::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWPRODUCTCATEGORYRELATIONSHIP
py::class_<RWStepBasic_RWProductCategoryRelationship> cls_RWStepBasic_RWProductCategoryRelationship(mod, "RWStepBasic_RWProductCategoryRelationship", "Read & Write tool for ProductCategoryRelationship");

// Constructors
cls_RWStepBasic_RWProductCategoryRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductCategoryRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductCategoryRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductCategoryRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductCategoryRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductCategoryRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductCategoryRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductCategoryRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductCategoryRelationship.def("ReadStep", (void (RWStepBasic_RWProductCategoryRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductCategoryRelationship> &) const) &RWStepBasic_RWProductCategoryRelationship::ReadStep, "Reads ProductCategoryRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductCategoryRelationship.def("WriteStep", (void (RWStepBasic_RWProductCategoryRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductCategoryRelationship> &) const) &RWStepBasic_RWProductCategoryRelationship::WriteStep, "Writes ProductCategoryRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductCategoryRelationship.def("Share", (void (RWStepBasic_RWProductCategoryRelationship::*)(const opencascade::handle<StepBasic_ProductCategoryRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductCategoryRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTCONCEPTCONTEXT
py::class_<RWStepBasic_RWProductConceptContext> cls_RWStepBasic_RWProductConceptContext(mod, "RWStepBasic_RWProductConceptContext", "Read & Write tool for ProductConceptContext");

// Constructors
cls_RWStepBasic_RWProductConceptContext.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductConceptContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductConceptContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductConceptContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductConceptContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductConceptContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductConceptContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductConceptContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductConceptContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductConceptContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductConceptContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductConceptContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductConceptContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductConceptContext.def("ReadStep", (void (RWStepBasic_RWProductConceptContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductConceptContext> &) const) &RWStepBasic_RWProductConceptContext::ReadStep, "Reads ProductConceptContext", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductConceptContext.def("WriteStep", (void (RWStepBasic_RWProductConceptContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductConceptContext> &) const) &RWStepBasic_RWProductConceptContext::WriteStep, "Writes ProductConceptContext", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductConceptContext.def("Share", (void (RWStepBasic_RWProductConceptContext::*)(const opencascade::handle<StepBasic_ProductConceptContext> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductConceptContext::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTCONTEXT
py::class_<RWStepBasic_RWProductContext> cls_RWStepBasic_RWProductContext(mod, "RWStepBasic_RWProductContext", "Read & Write Module for ProductContext");

// Constructors
cls_RWStepBasic_RWProductContext.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductContext.def("ReadStep", (void (RWStepBasic_RWProductContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductContext> &) const) &RWStepBasic_RWProductContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductContext.def("WriteStep", (void (RWStepBasic_RWProductContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductContext> &) const) &RWStepBasic_RWProductContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductContext.def("Share", (void (RWStepBasic_RWProductContext::*)(const opencascade::handle<StepBasic_ProductContext> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITION
py::class_<RWStepBasic_RWProductDefinition> cls_RWStepBasic_RWProductDefinition(mod, "RWStepBasic_RWProductDefinition", "Read & Write Module for ProductDefinition");

// Constructors
cls_RWStepBasic_RWProductDefinition.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinition.def("ReadStep", (void (RWStepBasic_RWProductDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinition> &) const) &RWStepBasic_RWProductDefinition::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinition.def("WriteStep", (void (RWStepBasic_RWProductDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinition> &) const) &RWStepBasic_RWProductDefinition::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinition.def("Share", (void (RWStepBasic_RWProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinition> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinition::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONCONTEXT
py::class_<RWStepBasic_RWProductDefinitionContext> cls_RWStepBasic_RWProductDefinitionContext(mod, "RWStepBasic_RWProductDefinitionContext", "Read & Write Module for ProductDefinitionContext");

// Constructors
cls_RWStepBasic_RWProductDefinitionContext.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionContext.def("ReadStep", (void (RWStepBasic_RWProductDefinitionContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &) const) &RWStepBasic_RWProductDefinitionContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionContext.def("WriteStep", (void (RWStepBasic_RWProductDefinitionContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionContext> &) const) &RWStepBasic_RWProductDefinitionContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionContext.def("Share", (void (RWStepBasic_RWProductDefinitionContext::*)(const opencascade::handle<StepBasic_ProductDefinitionContext> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionContext::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONEFFECTIVITY
py::class_<RWStepBasic_RWProductDefinitionEffectivity> cls_RWStepBasic_RWProductDefinitionEffectivity(mod, "RWStepBasic_RWProductDefinitionEffectivity", "Read & Write Module for ProductDefinitionEffectivity");

// Constructors
cls_RWStepBasic_RWProductDefinitionEffectivity.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionEffectivity::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionEffectivity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionEffectivity::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionEffectivity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionEffectivity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionEffectivity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionEffectivity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionEffectivity.def("ReadStep", (void (RWStepBasic_RWProductDefinitionEffectivity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionEffectivity> &) const) &RWStepBasic_RWProductDefinitionEffectivity::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionEffectivity.def("WriteStep", (void (RWStepBasic_RWProductDefinitionEffectivity::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionEffectivity> &) const) &RWStepBasic_RWProductDefinitionEffectivity::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionEffectivity.def("Share", (void (RWStepBasic_RWProductDefinitionEffectivity::*)(const opencascade::handle<StepBasic_ProductDefinitionEffectivity> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionEffectivity::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONFORMATION
py::class_<RWStepBasic_RWProductDefinitionFormation> cls_RWStepBasic_RWProductDefinitionFormation(mod, "RWStepBasic_RWProductDefinitionFormation", "Read & Write Module for ProductDefinitionFormation");

// Constructors
cls_RWStepBasic_RWProductDefinitionFormation.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormation::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormation::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionFormation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionFormation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionFormation.def("ReadStep", (void (RWStepBasic_RWProductDefinitionFormation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &RWStepBasic_RWProductDefinitionFormation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormation.def("WriteStep", (void (RWStepBasic_RWProductDefinitionFormation::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &) const) &RWStepBasic_RWProductDefinitionFormation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormation.def("Share", (void (RWStepBasic_RWProductDefinitionFormation::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionFormation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONFORMATIONRELATIONSHIP
py::class_<RWStepBasic_RWProductDefinitionFormationRelationship> cls_RWStepBasic_RWProductDefinitionFormationRelationship(mod, "RWStepBasic_RWProductDefinitionFormationRelationship", "Read & Write tool for ProductDefinitionFormationRelationship");

// Constructors
cls_RWStepBasic_RWProductDefinitionFormationRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionFormationRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionFormationRelationship.def("ReadStep", (void (RWStepBasic_RWProductDefinitionFormationRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionFormationRelationship> &) const) &RWStepBasic_RWProductDefinitionFormationRelationship::ReadStep, "Reads ProductDefinitionFormationRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormationRelationship.def("WriteStep", (void (RWStepBasic_RWProductDefinitionFormationRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionFormationRelationship> &) const) &RWStepBasic_RWProductDefinitionFormationRelationship::WriteStep, "Writes ProductDefinitionFormationRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormationRelationship.def("Share", (void (RWStepBasic_RWProductDefinitionFormationRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionFormationRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionFormationRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONFORMATIONWITHSPECIFIEDSOURCE
py::class_<RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource> cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource(mod, "RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource", "Read & Write Module for ProductDefinitionFormationWithSpecifiedSource");

// Constructors
cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def("ReadStep", (void (RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionFormationWithSpecifiedSource> &) const) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def("WriteStep", (void (RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionFormationWithSpecifiedSource> &) const) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource.def("Share", (void (RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::*)(const opencascade::handle<StepBasic_ProductDefinitionFormationWithSpecifiedSource> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONREFERENCE
py::class_<RWStepBasic_RWProductDefinitionReference> cls_RWStepBasic_RWProductDefinitionReference(mod, "RWStepBasic_RWProductDefinitionReference", "Read & Write Module for ProductDefinitionReference");

// Constructors
cls_RWStepBasic_RWProductDefinitionReference.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionReference::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionReference.def("ReadStep", (void (RWStepBasic_RWProductDefinitionReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionReference> &) const) &RWStepBasic_RWProductDefinitionReference::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionReference.def("WriteStep", (void (RWStepBasic_RWProductDefinitionReference::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionReference> &) const) &RWStepBasic_RWProductDefinitionReference::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionReference.def("Share", (void (RWStepBasic_RWProductDefinitionReference::*)(const opencascade::handle<StepBasic_ProductDefinitionReference> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionReference::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONREFERENCEWITHLOCALREPRESENTATION
py::class_<RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation> cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation(mod, "RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation", "Read & Write Module for ProductDefinitionReferenceWithLocalRepresentation");

// Constructors
cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def("ReadStep", (void (RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation> &) const) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def("WriteStep", (void (RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation> &) const) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation.def("Share", (void (RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONRELATIONSHIP
py::class_<RWStepBasic_RWProductDefinitionRelationship> cls_RWStepBasic_RWProductDefinitionRelationship(mod, "RWStepBasic_RWProductDefinitionRelationship", "Read & Write tool for ProductDefinitionRelationship");

// Constructors
cls_RWStepBasic_RWProductDefinitionRelationship.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionRelationship.def("ReadStep", (void (RWStepBasic_RWProductDefinitionRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &) const) &RWStepBasic_RWProductDefinitionRelationship::ReadStep, "Reads ProductDefinitionRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionRelationship.def("WriteStep", (void (RWStepBasic_RWProductDefinitionRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &) const) &RWStepBasic_RWProductDefinitionRelationship::WriteStep, "Writes ProductDefinitionRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionRelationship.def("Share", (void (RWStepBasic_RWProductDefinitionRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionRelationship> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTDEFINITIONWITHASSOCIATEDDOCUMENTS
py::class_<RWStepBasic_RWProductDefinitionWithAssociatedDocuments> cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments(mod, "RWStepBasic_RWProductDefinitionWithAssociatedDocuments", "Read & Write Module for ProductDefinitionWithAssociatedDocuments");

// Constructors
cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def("ReadStep", (void (RWStepBasic_RWProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments> &) const) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def("WriteStep", (void (RWStepBasic_RWProductDefinitionWithAssociatedDocuments::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments> &) const) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionWithAssociatedDocuments.def("Share", (void (RWStepBasic_RWProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionWithAssociatedDocuments::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTRELATEDPRODUCTCATEGORY
py::class_<RWStepBasic_RWProductRelatedProductCategory> cls_RWStepBasic_RWProductRelatedProductCategory(mod, "RWStepBasic_RWProductRelatedProductCategory", "Read & Write Module for ProductRelatedProductCategory");

// Constructors
cls_RWStepBasic_RWProductRelatedProductCategory.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductRelatedProductCategory::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductRelatedProductCategory::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductRelatedProductCategory::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductRelatedProductCategory::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductRelatedProductCategory::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductRelatedProductCategory.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductRelatedProductCategory::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductRelatedProductCategory.def("ReadStep", (void (RWStepBasic_RWProductRelatedProductCategory::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductRelatedProductCategory> &) const) &RWStepBasic_RWProductRelatedProductCategory::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductRelatedProductCategory.def("WriteStep", (void (RWStepBasic_RWProductRelatedProductCategory::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductRelatedProductCategory> &) const) &RWStepBasic_RWProductRelatedProductCategory::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductRelatedProductCategory.def("Share", (void (RWStepBasic_RWProductRelatedProductCategory::*)(const opencascade::handle<StepBasic_ProductRelatedProductCategory> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductRelatedProductCategory::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWPRODUCTTYPE
py::class_<RWStepBasic_RWProductType> cls_RWStepBasic_RWProductType(mod, "RWStepBasic_RWProductType", "Read & Write Module for ProductType");

// Constructors
cls_RWStepBasic_RWProductType.def(py::init<>());

// Methods
// cls_RWStepBasic_RWProductType.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductType::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductType.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductType::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductType.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductType::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductType.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductType::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductType.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductType.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductType::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductType.def("ReadStep", (void (RWStepBasic_RWProductType::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductType> &) const) &RWStepBasic_RWProductType::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductType.def("WriteStep", (void (RWStepBasic_RWProductType::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductType> &) const) &RWStepBasic_RWProductType::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductType.def("Share", (void (RWStepBasic_RWProductType::*)(const opencascade::handle<StepBasic_ProductType> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductType::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWRATIOMEASUREWITHUNIT
py::class_<RWStepBasic_RWRatioMeasureWithUnit> cls_RWStepBasic_RWRatioMeasureWithUnit(mod, "RWStepBasic_RWRatioMeasureWithUnit", "Read & Write Module for RatioMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWRatioMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWRatioMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWRatioMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWRatioMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWRatioMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWRatioMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWRatioMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWRatioMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWRatioMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWRatioMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_RatioMeasureWithUnit> &) const) &RWStepBasic_RWRatioMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWRatioMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWRatioMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_RatioMeasureWithUnit> &) const) &RWStepBasic_RWRatioMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWRatioMeasureWithUnit.def("Share", (void (RWStepBasic_RWRatioMeasureWithUnit::*)(const opencascade::handle<StepBasic_RatioMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWRatioMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWROLEASSOCIATION
py::class_<RWStepBasic_RWRoleAssociation> cls_RWStepBasic_RWRoleAssociation(mod, "RWStepBasic_RWRoleAssociation", "Read & Write tool for RoleAssociation");

// Constructors
cls_RWStepBasic_RWRoleAssociation.def(py::init<>());

// Methods
// cls_RWStepBasic_RWRoleAssociation.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWRoleAssociation::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWRoleAssociation.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWRoleAssociation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWRoleAssociation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWRoleAssociation::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWRoleAssociation.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWRoleAssociation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWRoleAssociation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWRoleAssociation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWRoleAssociation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWRoleAssociation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWRoleAssociation.def("ReadStep", (void (RWStepBasic_RWRoleAssociation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_RoleAssociation> &) const) &RWStepBasic_RWRoleAssociation::ReadStep, "Reads RoleAssociation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWRoleAssociation.def("WriteStep", (void (RWStepBasic_RWRoleAssociation::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_RoleAssociation> &) const) &RWStepBasic_RWRoleAssociation::WriteStep, "Writes RoleAssociation", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWRoleAssociation.def("Share", (void (RWStepBasic_RWRoleAssociation::*)(const opencascade::handle<StepBasic_RoleAssociation> &, Interface_EntityIterator &) const) &RWStepBasic_RWRoleAssociation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWSECURITYCLASSIFICATION
py::class_<RWStepBasic_RWSecurityClassification> cls_RWStepBasic_RWSecurityClassification(mod, "RWStepBasic_RWSecurityClassification", "Read & Write Module for SecurityClassification");

// Constructors
cls_RWStepBasic_RWSecurityClassification.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSecurityClassification.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSecurityClassification::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSecurityClassification.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSecurityClassification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSecurityClassification::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSecurityClassification.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSecurityClassification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSecurityClassification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSecurityClassification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSecurityClassification.def("ReadStep", (void (RWStepBasic_RWSecurityClassification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SecurityClassification> &) const) &RWStepBasic_RWSecurityClassification::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSecurityClassification.def("WriteStep", (void (RWStepBasic_RWSecurityClassification::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SecurityClassification> &) const) &RWStepBasic_RWSecurityClassification::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWSecurityClassification.def("Share", (void (RWStepBasic_RWSecurityClassification::*)(const opencascade::handle<StepBasic_SecurityClassification> &, Interface_EntityIterator &) const) &RWStepBasic_RWSecurityClassification::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWSECURITYCLASSIFICATIONLEVEL
py::class_<RWStepBasic_RWSecurityClassificationLevel> cls_RWStepBasic_RWSecurityClassificationLevel(mod, "RWStepBasic_RWSecurityClassificationLevel", "Read & Write Module for SecurityClassificationLevel");

// Constructors
cls_RWStepBasic_RWSecurityClassificationLevel.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSecurityClassificationLevel::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSecurityClassificationLevel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSecurityClassificationLevel::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSecurityClassificationLevel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSecurityClassificationLevel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSecurityClassificationLevel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSecurityClassificationLevel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSecurityClassificationLevel.def("ReadStep", (void (RWStepBasic_RWSecurityClassificationLevel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SecurityClassificationLevel> &) const) &RWStepBasic_RWSecurityClassificationLevel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSecurityClassificationLevel.def("WriteStep", (void (RWStepBasic_RWSecurityClassificationLevel::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SecurityClassificationLevel> &) const) &RWStepBasic_RWSecurityClassificationLevel::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNIT
py::class_<RWStepBasic_RWSiUnit> cls_RWStepBasic_RWSiUnit(mod, "RWStepBasic_RWSiUnit", "Read & Write Module for SiUnit");

// Constructors
cls_RWStepBasic_RWSiUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnit.def("ReadStep", (void (RWStepBasic_RWSiUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnit> &) const) &RWStepBasic_RWSiUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnit.def("WriteStep", (void (RWStepBasic_RWSiUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnit> &) const) &RWStepBasic_RWSiUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWSiUnit.def("DecodePrefix", (Standard_Boolean (RWStepBasic_RWSiUnit::*)(StepBasic_SiPrefix &, const Standard_CString) const) &RWStepBasic_RWSiUnit::DecodePrefix, "None", py::arg("aPrefix"), py::arg("text"));
cls_RWStepBasic_RWSiUnit.def("DecodeName", (Standard_Boolean (RWStepBasic_RWSiUnit::*)(StepBasic_SiUnitName &, const Standard_CString) const) &RWStepBasic_RWSiUnit::DecodeName, "None", py::arg("aName"), py::arg("text"));
cls_RWStepBasic_RWSiUnit.def("EncodePrefix", (TCollection_AsciiString (RWStepBasic_RWSiUnit::*)(const StepBasic_SiPrefix) const) &RWStepBasic_RWSiUnit::EncodePrefix, "None", py::arg("aPrefix"));
cls_RWStepBasic_RWSiUnit.def("EncodeName", (TCollection_AsciiString (RWStepBasic_RWSiUnit::*)(const StepBasic_SiUnitName) const) &RWStepBasic_RWSiUnit::EncodeName, "None", py::arg("aName"));

// CLASS: RWSTEPBASIC_RWSIUNITANDAREAUNIT
py::class_<RWStepBasic_RWSiUnitAndAreaUnit> cls_RWStepBasic_RWSiUnitAndAreaUnit(mod, "RWStepBasic_RWSiUnitAndAreaUnit", "Read & Write Module for SiUnitAndAreaUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndAreaUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndAreaUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndAreaUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndAreaUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndAreaUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndAreaUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndAreaUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndAreaUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndAreaUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndAreaUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndAreaUnit> &) const) &RWStepBasic_RWSiUnitAndAreaUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndAreaUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndAreaUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndAreaUnit> &) const) &RWStepBasic_RWSiUnitAndAreaUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDLENGTHUNIT
py::class_<RWStepBasic_RWSiUnitAndLengthUnit> cls_RWStepBasic_RWSiUnitAndLengthUnit(mod, "RWStepBasic_RWSiUnitAndLengthUnit", "Read & Write Module for SiUnitAndLengthUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndLengthUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndLengthUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndLengthUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndLengthUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndLengthUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndLengthUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndLengthUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndLengthUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndLengthUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndLengthUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndLengthUnit> &) const) &RWStepBasic_RWSiUnitAndLengthUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndLengthUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndLengthUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndLengthUnit> &) const) &RWStepBasic_RWSiUnitAndLengthUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDMASSUNIT
py::class_<RWStepBasic_RWSiUnitAndMassUnit> cls_RWStepBasic_RWSiUnitAndMassUnit(mod, "RWStepBasic_RWSiUnitAndMassUnit", "Read & Write Module for SiUnitAndMassUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndMassUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndMassUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndMassUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndMassUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndMassUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndMassUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndMassUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndMassUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndMassUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndMassUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndMassUnit> &) const) &RWStepBasic_RWSiUnitAndMassUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndMassUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndMassUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndMassUnit> &) const) &RWStepBasic_RWSiUnitAndMassUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDPLANEANGLEUNIT
py::class_<RWStepBasic_RWSiUnitAndPlaneAngleUnit> cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit(mod, "RWStepBasic_RWSiUnitAndPlaneAngleUnit", "Read & Write Module for SiUnitAndPlaneAngleUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndPlaneAngleUnit> &) const) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndPlaneAngleUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndPlaneAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndPlaneAngleUnit> &) const) &RWStepBasic_RWSiUnitAndPlaneAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDRATIOUNIT
py::class_<RWStepBasic_RWSiUnitAndRatioUnit> cls_RWStepBasic_RWSiUnitAndRatioUnit(mod, "RWStepBasic_RWSiUnitAndRatioUnit", "Read & Write Module for SiUnitAndRatioUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndRatioUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndRatioUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndRatioUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndRatioUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndRatioUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndRatioUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndRatioUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndRatioUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndRatioUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndRatioUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndRatioUnit> &) const) &RWStepBasic_RWSiUnitAndRatioUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndRatioUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndRatioUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndRatioUnit> &) const) &RWStepBasic_RWSiUnitAndRatioUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDSOLIDANGLEUNIT
py::class_<RWStepBasic_RWSiUnitAndSolidAngleUnit> cls_RWStepBasic_RWSiUnitAndSolidAngleUnit(mod, "RWStepBasic_RWSiUnitAndSolidAngleUnit", "Read & Write Module for SiUnitAndSolidAngleUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndSolidAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndSolidAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndSolidAngleUnit> &) const) &RWStepBasic_RWSiUnitAndSolidAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndSolidAngleUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndSolidAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndSolidAngleUnit> &) const) &RWStepBasic_RWSiUnitAndSolidAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDTHERMODYNAMICTEMPERATUREUNIT
py::class_<RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit> cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit(mod, "RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit", "Read & Write Module for SiUnitAndThermodynamicTemperatureUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndThermodynamicTemperatureUnit> &) const) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndThermodynamicTemperatureUnit> &) const) &RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDTIMEUNIT
py::class_<RWStepBasic_RWSiUnitAndTimeUnit> cls_RWStepBasic_RWSiUnitAndTimeUnit(mod, "RWStepBasic_RWSiUnitAndTimeUnit", "Read & Write Module for SiUnitAndTimeUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndTimeUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndTimeUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndTimeUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndTimeUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndTimeUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndTimeUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndTimeUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndTimeUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndTimeUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndTimeUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndTimeUnit> &) const) &RWStepBasic_RWSiUnitAndTimeUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndTimeUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndTimeUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndTimeUnit> &) const) &RWStepBasic_RWSiUnitAndTimeUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSIUNITANDVOLUMEUNIT
py::class_<RWStepBasic_RWSiUnitAndVolumeUnit> cls_RWStepBasic_RWSiUnitAndVolumeUnit(mod, "RWStepBasic_RWSiUnitAndVolumeUnit", "Read & Write Module for SiUnitAndVolumeUnit");

// Constructors
cls_RWStepBasic_RWSiUnitAndVolumeUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnitAndVolumeUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnitAndVolumeUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnitAndVolumeUnit.def("ReadStep", (void (RWStepBasic_RWSiUnitAndVolumeUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnitAndVolumeUnit> &) const) &RWStepBasic_RWSiUnitAndVolumeUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnitAndVolumeUnit.def("WriteStep", (void (RWStepBasic_RWSiUnitAndVolumeUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnitAndVolumeUnit> &) const) &RWStepBasic_RWSiUnitAndVolumeUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPBASIC_RWSOLIDANGLEMEASUREWITHUNIT
py::class_<RWStepBasic_RWSolidAngleMeasureWithUnit> cls_RWStepBasic_RWSolidAngleMeasureWithUnit(mod, "RWStepBasic_RWSolidAngleMeasureWithUnit", "Read & Write Module for SolidAngleMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSolidAngleMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWSolidAngleMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SolidAngleMeasureWithUnit> &) const) &RWStepBasic_RWSolidAngleMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWSolidAngleMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SolidAngleMeasureWithUnit> &) const) &RWStepBasic_RWSolidAngleMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWSolidAngleMeasureWithUnit.def("Share", (void (RWStepBasic_RWSolidAngleMeasureWithUnit::*)(const opencascade::handle<StepBasic_SolidAngleMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWSolidAngleMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWSOLIDANGLEUNIT
py::class_<RWStepBasic_RWSolidAngleUnit> cls_RWStepBasic_RWSolidAngleUnit(mod, "RWStepBasic_RWSolidAngleUnit", "Read & Write Module for SolidAngleUnit");

// Constructors
cls_RWStepBasic_RWSolidAngleUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSolidAngleUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSolidAngleUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSolidAngleUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSolidAngleUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSolidAngleUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSolidAngleUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSolidAngleUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSolidAngleUnit.def("ReadStep", (void (RWStepBasic_RWSolidAngleUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SolidAngleUnit> &) const) &RWStepBasic_RWSolidAngleUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSolidAngleUnit.def("WriteStep", (void (RWStepBasic_RWSolidAngleUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SolidAngleUnit> &) const) &RWStepBasic_RWSolidAngleUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWSolidAngleUnit.def("Share", (void (RWStepBasic_RWSolidAngleUnit::*)(const opencascade::handle<StepBasic_SolidAngleUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWSolidAngleUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWTHERMODYNAMICTEMPERATUREUNIT
py::class_<RWStepBasic_RWThermodynamicTemperatureUnit> cls_RWStepBasic_RWThermodynamicTemperatureUnit(mod, "RWStepBasic_RWThermodynamicTemperatureUnit", "Read & Write tool for ThermodynamicTemperatureUnit");

// Constructors
cls_RWStepBasic_RWThermodynamicTemperatureUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWThermodynamicTemperatureUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWThermodynamicTemperatureUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWThermodynamicTemperatureUnit.def("ReadStep", (void (RWStepBasic_RWThermodynamicTemperatureUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ThermodynamicTemperatureUnit> &) const) &RWStepBasic_RWThermodynamicTemperatureUnit::ReadStep, "Reads ThermodynamicTemperatureUnit", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWThermodynamicTemperatureUnit.def("WriteStep", (void (RWStepBasic_RWThermodynamicTemperatureUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ThermodynamicTemperatureUnit> &) const) &RWStepBasic_RWThermodynamicTemperatureUnit::WriteStep, "Writes ThermodynamicTemperatureUnit", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWThermodynamicTemperatureUnit.def("Share", (void (RWStepBasic_RWThermodynamicTemperatureUnit::*)(const opencascade::handle<StepBasic_ThermodynamicTemperatureUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWThermodynamicTemperatureUnit::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWUNCERTAINTYMEASUREWITHUNIT
py::class_<RWStepBasic_RWUncertaintyMeasureWithUnit> cls_RWStepBasic_RWUncertaintyMeasureWithUnit(mod, "RWStepBasic_RWUncertaintyMeasureWithUnit", "Read & Write Module for UncertaintyMeasureWithUnit");

// Constructors
cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def(py::init<>());

// Methods
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWUncertaintyMeasureWithUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def("ReadStep", (void (RWStepBasic_RWUncertaintyMeasureWithUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &) const) &RWStepBasic_RWUncertaintyMeasureWithUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def("WriteStep", (void (RWStepBasic_RWUncertaintyMeasureWithUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &) const) &RWStepBasic_RWUncertaintyMeasureWithUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWUncertaintyMeasureWithUnit.def("Share", (void (RWStepBasic_RWUncertaintyMeasureWithUnit::*)(const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWUncertaintyMeasureWithUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWVERSIONEDACTIONREQUEST
py::class_<RWStepBasic_RWVersionedActionRequest> cls_RWStepBasic_RWVersionedActionRequest(mod, "RWStepBasic_RWVersionedActionRequest", "Read & Write tool for VersionedActionRequest");

// Constructors
cls_RWStepBasic_RWVersionedActionRequest.def(py::init<>());

// Methods
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWVersionedActionRequest::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWVersionedActionRequest::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWVersionedActionRequest::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWVersionedActionRequest::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWVersionedActionRequest::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWVersionedActionRequest.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWVersionedActionRequest::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWVersionedActionRequest.def("ReadStep", (void (RWStepBasic_RWVersionedActionRequest::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_VersionedActionRequest> &) const) &RWStepBasic_RWVersionedActionRequest::ReadStep, "Reads VersionedActionRequest", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWVersionedActionRequest.def("WriteStep", (void (RWStepBasic_RWVersionedActionRequest::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_VersionedActionRequest> &) const) &RWStepBasic_RWVersionedActionRequest::WriteStep, "Writes VersionedActionRequest", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWVersionedActionRequest.def("Share", (void (RWStepBasic_RWVersionedActionRequest::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &, Interface_EntityIterator &) const) &RWStepBasic_RWVersionedActionRequest::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPBASIC_RWWEEKOFYEARANDDAYDATE
py::class_<RWStepBasic_RWWeekOfYearAndDayDate> cls_RWStepBasic_RWWeekOfYearAndDayDate(mod, "RWStepBasic_RWWeekOfYearAndDayDate", "Read & Write Module for WeekOfYearAndDayDate");

// Constructors
cls_RWStepBasic_RWWeekOfYearAndDayDate.def(py::init<>());

// Methods
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWWeekOfYearAndDayDate::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWWeekOfYearAndDayDate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWWeekOfYearAndDayDate::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWWeekOfYearAndDayDate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWWeekOfYearAndDayDate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWWeekOfYearAndDayDate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWWeekOfYearAndDayDate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWWeekOfYearAndDayDate.def("ReadStep", (void (RWStepBasic_RWWeekOfYearAndDayDate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_WeekOfYearAndDayDate> &) const) &RWStepBasic_RWWeekOfYearAndDayDate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWWeekOfYearAndDayDate.def("WriteStep", (void (RWStepBasic_RWWeekOfYearAndDayDate::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_WeekOfYearAndDayDate> &) const) &RWStepBasic_RWWeekOfYearAndDayDate::WriteStep, "None", py::arg("SW"), py::arg("ent"));


}
