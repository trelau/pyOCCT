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

void bind_RWStepBasic_RWAction(py::module &);
void bind_RWStepBasic_RWActionAssignment(py::module &);
void bind_RWStepBasic_RWActionMethod(py::module &);
void bind_RWStepBasic_RWActionRequestAssignment(py::module &);
void bind_RWStepBasic_RWActionRequestSolution(py::module &);
void bind_RWStepBasic_RWAddress(py::module &);
void bind_RWStepBasic_RWApplicationContext(py::module &);
void bind_RWStepBasic_RWApplicationContextElement(py::module &);
void bind_RWStepBasic_RWApplicationProtocolDefinition(py::module &);
void bind_RWStepBasic_RWApproval(py::module &);
void bind_RWStepBasic_RWApprovalDateTime(py::module &);
void bind_RWStepBasic_RWApprovalPersonOrganization(py::module &);
void bind_RWStepBasic_RWApprovalRelationship(py::module &);
void bind_RWStepBasic_RWApprovalRole(py::module &);
void bind_RWStepBasic_RWApprovalStatus(py::module &);
void bind_RWStepBasic_RWCalendarDate(py::module &);
void bind_RWStepBasic_RWCertification(py::module &);
void bind_RWStepBasic_RWCertificationAssignment(py::module &);
void bind_RWStepBasic_RWCertificationType(py::module &);
void bind_RWStepBasic_RWCharacterizedObject(py::module &);
void bind_RWStepBasic_RWContract(py::module &);
void bind_RWStepBasic_RWContractAssignment(py::module &);
void bind_RWStepBasic_RWContractType(py::module &);
void bind_RWStepBasic_RWConversionBasedUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndAreaUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndLengthUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndMassUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndRatioUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndTimeUnit(py::module &);
void bind_RWStepBasic_RWConversionBasedUnitAndVolumeUnit(py::module &);
void bind_RWStepBasic_RWCoordinatedUniversalTimeOffset(py::module &);
void bind_RWStepBasic_RWDate(py::module &);
void bind_RWStepBasic_RWDateAndTime(py::module &);
void bind_RWStepBasic_RWDateRole(py::module &);
void bind_RWStepBasic_RWDateTimeRole(py::module &);
void bind_RWStepBasic_RWDerivedUnit(py::module &);
void bind_RWStepBasic_RWDerivedUnitElement(py::module &);
void bind_RWStepBasic_RWDimensionalExponents(py::module &);
void bind_RWStepBasic_RWDocument(py::module &);
void bind_RWStepBasic_RWDocumentFile(py::module &);
void bind_RWStepBasic_RWDocumentProductAssociation(py::module &);
void bind_RWStepBasic_RWDocumentProductEquivalence(py::module &);
void bind_RWStepBasic_RWDocumentRelationship(py::module &);
void bind_RWStepBasic_RWDocumentRepresentationType(py::module &);
void bind_RWStepBasic_RWDocumentType(py::module &);
void bind_RWStepBasic_RWDocumentUsageConstraint(py::module &);
void bind_RWStepBasic_RWEffectivity(py::module &);
void bind_RWStepBasic_RWEffectivityAssignment(py::module &);
void bind_RWStepBasic_RWEulerAngles(py::module &);
void bind_RWStepBasic_RWExternalIdentificationAssignment(py::module &);
void bind_RWStepBasic_RWExternallyDefinedItem(py::module &);
void bind_RWStepBasic_RWExternalSource(py::module &);
void bind_RWStepBasic_RWGeneralProperty(py::module &);
void bind_RWStepBasic_RWGroup(py::module &);
void bind_RWStepBasic_RWGroupAssignment(py::module &);
void bind_RWStepBasic_RWGroupRelationship(py::module &);
void bind_RWStepBasic_RWIdentificationAssignment(py::module &);
void bind_RWStepBasic_RWIdentificationRole(py::module &);
void bind_RWStepBasic_RWLengthMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWLengthUnit(py::module &);
void bind_RWStepBasic_RWLocalTime(py::module &);
void bind_RWStepBasic_RWMassMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWMassUnit(py::module &);
void bind_RWStepBasic_RWMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWMechanicalContext(py::module &);
void bind_RWStepBasic_RWNameAssignment(py::module &);
void bind_RWStepBasic_RWNamedUnit(py::module &);
void bind_RWStepBasic_RWObjectRole(py::module &);
void bind_RWStepBasic_RWOrdinalDate(py::module &);
void bind_RWStepBasic_RWOrganization(py::module &);
void bind_RWStepBasic_RWOrganizationalAddress(py::module &);
void bind_RWStepBasic_RWOrganizationRole(py::module &);
void bind_RWStepBasic_RWPerson(py::module &);
void bind_RWStepBasic_RWPersonalAddress(py::module &);
void bind_RWStepBasic_RWPersonAndOrganization(py::module &);
void bind_RWStepBasic_RWPersonAndOrganizationRole(py::module &);
void bind_RWStepBasic_RWPlaneAngleMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWPlaneAngleUnit(py::module &);
void bind_RWStepBasic_RWProduct(py::module &);
void bind_RWStepBasic_RWProductCategory(py::module &);
void bind_RWStepBasic_RWProductCategoryRelationship(py::module &);
void bind_RWStepBasic_RWProductConceptContext(py::module &);
void bind_RWStepBasic_RWProductContext(py::module &);
void bind_RWStepBasic_RWProductDefinition(py::module &);
void bind_RWStepBasic_RWProductDefinitionContext(py::module &);
void bind_RWStepBasic_RWProductDefinitionEffectivity(py::module &);
void bind_RWStepBasic_RWProductDefinitionFormation(py::module &);
void bind_RWStepBasic_RWProductDefinitionFormationRelationship(py::module &);
void bind_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource(py::module &);
void bind_RWStepBasic_RWProductDefinitionReference(py::module &);
void bind_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation(py::module &);
void bind_RWStepBasic_RWProductDefinitionRelationship(py::module &);
void bind_RWStepBasic_RWProductDefinitionWithAssociatedDocuments(py::module &);
void bind_RWStepBasic_RWProductRelatedProductCategory(py::module &);
void bind_RWStepBasic_RWProductType(py::module &);
void bind_RWStepBasic_RWRatioMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWRoleAssociation(py::module &);
void bind_RWStepBasic_RWSecurityClassification(py::module &);
void bind_RWStepBasic_RWSecurityClassificationLevel(py::module &);
void bind_RWStepBasic_RWSiUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndAreaUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndLengthUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndMassUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndPlaneAngleUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndRatioUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndSolidAngleUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndTimeUnit(py::module &);
void bind_RWStepBasic_RWSiUnitAndVolumeUnit(py::module &);
void bind_RWStepBasic_RWSolidAngleMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWSolidAngleUnit(py::module &);
void bind_RWStepBasic_RWThermodynamicTemperatureUnit(py::module &);
void bind_RWStepBasic_RWUncertaintyMeasureWithUnit(py::module &);
void bind_RWStepBasic_RWVersionedActionRequest(py::module &);
void bind_RWStepBasic_RWWeekOfYearAndDayDate(py::module &);

PYBIND11_MODULE(RWStepBasic, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.TCollection");

bind_RWStepBasic_RWAction(mod);
bind_RWStepBasic_RWActionAssignment(mod);
bind_RWStepBasic_RWActionMethod(mod);
bind_RWStepBasic_RWActionRequestAssignment(mod);
bind_RWStepBasic_RWActionRequestSolution(mod);
bind_RWStepBasic_RWAddress(mod);
bind_RWStepBasic_RWApplicationContext(mod);
bind_RWStepBasic_RWApplicationContextElement(mod);
bind_RWStepBasic_RWApplicationProtocolDefinition(mod);
bind_RWStepBasic_RWApproval(mod);
bind_RWStepBasic_RWApprovalDateTime(mod);
bind_RWStepBasic_RWApprovalPersonOrganization(mod);
bind_RWStepBasic_RWApprovalRelationship(mod);
bind_RWStepBasic_RWApprovalRole(mod);
bind_RWStepBasic_RWApprovalStatus(mod);
bind_RWStepBasic_RWCalendarDate(mod);
bind_RWStepBasic_RWCertification(mod);
bind_RWStepBasic_RWCertificationAssignment(mod);
bind_RWStepBasic_RWCertificationType(mod);
bind_RWStepBasic_RWCharacterizedObject(mod);
bind_RWStepBasic_RWContract(mod);
bind_RWStepBasic_RWContractAssignment(mod);
bind_RWStepBasic_RWContractType(mod);
bind_RWStepBasic_RWConversionBasedUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndAreaUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndLengthUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndMassUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndPlaneAngleUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndRatioUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndSolidAngleUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndTimeUnit(mod);
bind_RWStepBasic_RWConversionBasedUnitAndVolumeUnit(mod);
bind_RWStepBasic_RWCoordinatedUniversalTimeOffset(mod);
bind_RWStepBasic_RWDate(mod);
bind_RWStepBasic_RWDateAndTime(mod);
bind_RWStepBasic_RWDateRole(mod);
bind_RWStepBasic_RWDateTimeRole(mod);
bind_RWStepBasic_RWDerivedUnit(mod);
bind_RWStepBasic_RWDerivedUnitElement(mod);
bind_RWStepBasic_RWDimensionalExponents(mod);
bind_RWStepBasic_RWDocument(mod);
bind_RWStepBasic_RWDocumentFile(mod);
bind_RWStepBasic_RWDocumentProductAssociation(mod);
bind_RWStepBasic_RWDocumentProductEquivalence(mod);
bind_RWStepBasic_RWDocumentRelationship(mod);
bind_RWStepBasic_RWDocumentRepresentationType(mod);
bind_RWStepBasic_RWDocumentType(mod);
bind_RWStepBasic_RWDocumentUsageConstraint(mod);
bind_RWStepBasic_RWEffectivity(mod);
bind_RWStepBasic_RWEffectivityAssignment(mod);
bind_RWStepBasic_RWEulerAngles(mod);
bind_RWStepBasic_RWExternalIdentificationAssignment(mod);
bind_RWStepBasic_RWExternallyDefinedItem(mod);
bind_RWStepBasic_RWExternalSource(mod);
bind_RWStepBasic_RWGeneralProperty(mod);
bind_RWStepBasic_RWGroup(mod);
bind_RWStepBasic_RWGroupAssignment(mod);
bind_RWStepBasic_RWGroupRelationship(mod);
bind_RWStepBasic_RWIdentificationAssignment(mod);
bind_RWStepBasic_RWIdentificationRole(mod);
bind_RWStepBasic_RWLengthMeasureWithUnit(mod);
bind_RWStepBasic_RWLengthUnit(mod);
bind_RWStepBasic_RWLocalTime(mod);
bind_RWStepBasic_RWMassMeasureWithUnit(mod);
bind_RWStepBasic_RWMassUnit(mod);
bind_RWStepBasic_RWMeasureWithUnit(mod);
bind_RWStepBasic_RWMechanicalContext(mod);
bind_RWStepBasic_RWNameAssignment(mod);
bind_RWStepBasic_RWNamedUnit(mod);
bind_RWStepBasic_RWObjectRole(mod);
bind_RWStepBasic_RWOrdinalDate(mod);
bind_RWStepBasic_RWOrganization(mod);
bind_RWStepBasic_RWOrganizationalAddress(mod);
bind_RWStepBasic_RWOrganizationRole(mod);
bind_RWStepBasic_RWPerson(mod);
bind_RWStepBasic_RWPersonalAddress(mod);
bind_RWStepBasic_RWPersonAndOrganization(mod);
bind_RWStepBasic_RWPersonAndOrganizationRole(mod);
bind_RWStepBasic_RWPlaneAngleMeasureWithUnit(mod);
bind_RWStepBasic_RWPlaneAngleUnit(mod);
bind_RWStepBasic_RWProduct(mod);
bind_RWStepBasic_RWProductCategory(mod);
bind_RWStepBasic_RWProductCategoryRelationship(mod);
bind_RWStepBasic_RWProductConceptContext(mod);
bind_RWStepBasic_RWProductContext(mod);
bind_RWStepBasic_RWProductDefinition(mod);
bind_RWStepBasic_RWProductDefinitionContext(mod);
bind_RWStepBasic_RWProductDefinitionEffectivity(mod);
bind_RWStepBasic_RWProductDefinitionFormation(mod);
bind_RWStepBasic_RWProductDefinitionFormationRelationship(mod);
bind_RWStepBasic_RWProductDefinitionFormationWithSpecifiedSource(mod);
bind_RWStepBasic_RWProductDefinitionReference(mod);
bind_RWStepBasic_RWProductDefinitionReferenceWithLocalRepresentation(mod);
bind_RWStepBasic_RWProductDefinitionRelationship(mod);
bind_RWStepBasic_RWProductDefinitionWithAssociatedDocuments(mod);
bind_RWStepBasic_RWProductRelatedProductCategory(mod);
bind_RWStepBasic_RWProductType(mod);
bind_RWStepBasic_RWRatioMeasureWithUnit(mod);
bind_RWStepBasic_RWRoleAssociation(mod);
bind_RWStepBasic_RWSecurityClassification(mod);
bind_RWStepBasic_RWSecurityClassificationLevel(mod);
bind_RWStepBasic_RWSiUnit(mod);
bind_RWStepBasic_RWSiUnitAndAreaUnit(mod);
bind_RWStepBasic_RWSiUnitAndLengthUnit(mod);
bind_RWStepBasic_RWSiUnitAndMassUnit(mod);
bind_RWStepBasic_RWSiUnitAndPlaneAngleUnit(mod);
bind_RWStepBasic_RWSiUnitAndRatioUnit(mod);
bind_RWStepBasic_RWSiUnitAndSolidAngleUnit(mod);
bind_RWStepBasic_RWSiUnitAndThermodynamicTemperatureUnit(mod);
bind_RWStepBasic_RWSiUnitAndTimeUnit(mod);
bind_RWStepBasic_RWSiUnitAndVolumeUnit(mod);
bind_RWStepBasic_RWSolidAngleMeasureWithUnit(mod);
bind_RWStepBasic_RWSolidAngleUnit(mod);
bind_RWStepBasic_RWThermodynamicTemperatureUnit(mod);
bind_RWStepBasic_RWUncertaintyMeasureWithUnit(mod);
bind_RWStepBasic_RWVersionedActionRequest(mod);
bind_RWStepBasic_RWWeekOfYearAndDayDate(mod);

}
