#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_ActionMethod.hxx>
#include <Standard_Type.hxx>
#include <StepBasic_Action.hxx>
#include <StepBasic_ActionAssignment.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepBasic_ActionRequestAssignment.hxx>
#include <StepBasic_ActionRequestSolution.hxx>
#include <StepBasic_Address.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_ApplicationContextElement.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <StepBasic_ApprovalStatus.hxx>
#include <StepBasic_Approval.hxx>
#include <StepBasic_DateTimeSelect.hxx>
#include <StepBasic_ApprovalDateTime.hxx>
#include <StepBasic_PersonOrganizationSelect.hxx>
#include <StepBasic_ApprovalRole.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepBasic_ApprovalRelationship.hxx>
#include <StepBasic_Date.hxx>
#include <StepBasic_CalendarDate.hxx>
#include <StepBasic_CertificationType.hxx>
#include <StepBasic_Certification.hxx>
#include <StepBasic_CertificationAssignment.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <StepBasic_ContractType.hxx>
#include <StepBasic_Contract.hxx>
#include <StepBasic_ContractAssignment.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepBasic_ConversionBasedUnit.hxx>
#include <StepBasic_AreaUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndAreaUnit.hxx>
#include <StepBasic_LengthUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndLengthUnit.hxx>
#include <StepBasic_MassUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndMassUnit.hxx>
#include <StepBasic_PlaneAngleUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndPlaneAngleUnit.hxx>
#include <StepBasic_RatioUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndRatioUnit.hxx>
#include <StepBasic_SolidAngleUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndSolidAngleUnit.hxx>
#include <StepBasic_TimeUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndTimeUnit.hxx>
#include <StepBasic_VolumeUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndVolumeUnit.hxx>
#include <StepBasic_AheadOrBehind.hxx>
#include <StepBasic_CoordinatedUniversalTimeOffset.hxx>
#include <StepBasic_LocalTime.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateRole.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepBasic_HArray1OfDerivedUnitElement.hxx>
#include <StepBasic_DerivedUnitElement.hxx>
#include <StepBasic_DerivedUnit.hxx>
#include <StepBasic_DocumentType.hxx>
#include <StepBasic_Document.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <StepBasic_ProductOrFormationOrDefinition.hxx>
#include <StepBasic_DocumentProductAssociation.hxx>
#include <StepBasic_DocumentProductEquivalence.hxx>
#include <StepBasic_DocumentRelationship.hxx>
#include <StepBasic_DocumentRepresentationType.hxx>
#include <StepBasic_DocumentUsageConstraint.hxx>
#include <StepBasic_Effectivity.hxx>
#include <StepBasic_EffectivityAssignment.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <StepBasic_IdentificationAssignment.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <StepBasic_SourceItem.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <StepBasic_Group.hxx>
#include <StepBasic_GroupAssignment.hxx>
#include <StepBasic_GroupRelationship.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepBasic_MassMeasureWithUnit.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <StepBasic_ProductContext.hxx>
#include <StepBasic_MechanicalContext.hxx>
#include <StepBasic_NameAssignment.hxx>
#include <StepBasic_ObjectRole.hxx>
#include <StepBasic_OrdinalDate.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_HArray1OfOrganization.hxx>
#include <StepBasic_OrganizationalAddress.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <StepBasic_Person.hxx>
#include <StepBasic_HArray1OfPerson.hxx>
#include <StepBasic_PersonalAddress.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <StepBasic_HArray1OfProductContext.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductCategory.hxx>
#include <StepBasic_ProductCategoryRelationship.hxx>
#include <StepBasic_ProductConceptContext.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <StepBasic_ProductDefinitionFormationRelationship.hxx>
#include <StepBasic_Source.hxx>
#include <StepBasic_ProductDefinitionFormationWithSpecifiedSource.hxx>
#include <StepBasic_ProductDefinitionReference.hxx>
#include <StepBasic_ProductDefinitionReferenceWithLocalRepresentation.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>
#include <StepBasic_HArray1OfDocument.hxx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <StepBasic_HArray1OfProduct.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <StepBasic_ProductType.hxx>
#include <StepBasic_RatioMeasureWithUnit.hxx>
#include <StepBasic_RoleSelect.hxx>
#include <StepBasic_RoleAssociation.hxx>
#include <StepBasic_SecurityClassificationLevel.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <StepBasic_SiUnit.hxx>
#include <StepBasic_SiUnitAndAreaUnit.hxx>
#include <StepBasic_SiUnitAndLengthUnit.hxx>
#include <StepBasic_SiUnitAndMassUnit.hxx>
#include <StepBasic_SiUnitAndPlaneAngleUnit.hxx>
#include <StepBasic_SiUnitAndRatioUnit.hxx>
#include <StepBasic_SiUnitAndSolidAngleUnit.hxx>
#include <StepBasic_ThermodynamicTemperatureUnit.hxx>
#include <StepBasic_SiUnitAndThermodynamicTemperatureUnit.hxx>
#include <StepBasic_SiUnitAndTimeUnit.hxx>
#include <StepBasic_SiUnitAndVolumeUnit.hxx>
#include <StepBasic_SolidAngleMeasureWithUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <StepBasic_WeekOfYearAndDayDate.hxx>
#include <StepBasic_ApprovalAssignment.hxx>
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <StepBasic_PersonAndOrganizationAssignment.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <StepBasic_DocumentReference.hxx>
#include <StepBasic_DateAssignment.hxx>
#include <StepBasic_OrganizationAssignment.hxx>
#include <StepBasic_PhysicallyModeledProductDefinition.hxx>
#include <NCollection_Array1.hxx>
#include <StepBasic_Array1OfApproval.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepBasic_HArray1OfApproval.hxx>
#include <StepData_SelectType.hxx>
#include <StepData_SelectMember.hxx>
#include <StepBasic_Array1OfDerivedUnitElement.hxx>
#include <StepBasic_Array1OfDocument.hxx>
#include <StepBasic_Array1OfNamedUnit.hxx>
#include <StepBasic_Array1OfOrganization.hxx>
#include <StepBasic_Array1OfPerson.hxx>
#include <StepBasic_Array1OfProductContext.hxx>
#include <StepBasic_Array1OfProduct.hxx>
#include <StepBasic_Array1OfProductDefinition.hxx>
#include <StepData_SelectReal.hxx>
#include <StepBasic_Array1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_DesignContext.hxx>
#include <StepBasic_DigitalDocument.hxx>
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_HArray1OfProductDefinition.hxx>
#include <StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_SizeMember.hxx>
#include <StepBasic_SizeSelect.hxx>
#include <StepBasic_TimeMeasureWithUnit.hxx>

PYBIND11_MODULE(StepBasic, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.StepData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiPrefix.hxx
	py::enum_<StepBasic_SiPrefix>(mod, "StepBasic_SiPrefix", "None")
		.value("StepBasic_spExa", StepBasic_SiPrefix::StepBasic_spExa)
		.value("StepBasic_spPeta", StepBasic_SiPrefix::StepBasic_spPeta)
		.value("StepBasic_spTera", StepBasic_SiPrefix::StepBasic_spTera)
		.value("StepBasic_spGiga", StepBasic_SiPrefix::StepBasic_spGiga)
		.value("StepBasic_spMega", StepBasic_SiPrefix::StepBasic_spMega)
		.value("StepBasic_spKilo", StepBasic_SiPrefix::StepBasic_spKilo)
		.value("StepBasic_spHecto", StepBasic_SiPrefix::StepBasic_spHecto)
		.value("StepBasic_spDeca", StepBasic_SiPrefix::StepBasic_spDeca)
		.value("StepBasic_spDeci", StepBasic_SiPrefix::StepBasic_spDeci)
		.value("StepBasic_spCenti", StepBasic_SiPrefix::StepBasic_spCenti)
		.value("StepBasic_spMilli", StepBasic_SiPrefix::StepBasic_spMilli)
		.value("StepBasic_spMicro", StepBasic_SiPrefix::StepBasic_spMicro)
		.value("StepBasic_spNano", StepBasic_SiPrefix::StepBasic_spNano)
		.value("StepBasic_spPico", StepBasic_SiPrefix::StepBasic_spPico)
		.value("StepBasic_spFemto", StepBasic_SiPrefix::StepBasic_spFemto)
		.value("StepBasic_spAtto", StepBasic_SiPrefix::StepBasic_spAtto)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitName.hxx
	py::enum_<StepBasic_SiUnitName>(mod, "StepBasic_SiUnitName", "None")
		.value("StepBasic_sunMetre", StepBasic_SiUnitName::StepBasic_sunMetre)
		.value("StepBasic_sunGram", StepBasic_SiUnitName::StepBasic_sunGram)
		.value("StepBasic_sunSecond", StepBasic_SiUnitName::StepBasic_sunSecond)
		.value("StepBasic_sunAmpere", StepBasic_SiUnitName::StepBasic_sunAmpere)
		.value("StepBasic_sunKelvin", StepBasic_SiUnitName::StepBasic_sunKelvin)
		.value("StepBasic_sunMole", StepBasic_SiUnitName::StepBasic_sunMole)
		.value("StepBasic_sunCandela", StepBasic_SiUnitName::StepBasic_sunCandela)
		.value("StepBasic_sunRadian", StepBasic_SiUnitName::StepBasic_sunRadian)
		.value("StepBasic_sunSteradian", StepBasic_SiUnitName::StepBasic_sunSteradian)
		.value("StepBasic_sunHertz", StepBasic_SiUnitName::StepBasic_sunHertz)
		.value("StepBasic_sunNewton", StepBasic_SiUnitName::StepBasic_sunNewton)
		.value("StepBasic_sunPascal", StepBasic_SiUnitName::StepBasic_sunPascal)
		.value("StepBasic_sunJoule", StepBasic_SiUnitName::StepBasic_sunJoule)
		.value("StepBasic_sunWatt", StepBasic_SiUnitName::StepBasic_sunWatt)
		.value("StepBasic_sunCoulomb", StepBasic_SiUnitName::StepBasic_sunCoulomb)
		.value("StepBasic_sunVolt", StepBasic_SiUnitName::StepBasic_sunVolt)
		.value("StepBasic_sunFarad", StepBasic_SiUnitName::StepBasic_sunFarad)
		.value("StepBasic_sunOhm", StepBasic_SiUnitName::StepBasic_sunOhm)
		.value("StepBasic_sunSiemens", StepBasic_SiUnitName::StepBasic_sunSiemens)
		.value("StepBasic_sunWeber", StepBasic_SiUnitName::StepBasic_sunWeber)
		.value("StepBasic_sunTesla", StepBasic_SiUnitName::StepBasic_sunTesla)
		.value("StepBasic_sunHenry", StepBasic_SiUnitName::StepBasic_sunHenry)
		.value("StepBasic_sunDegreeCelsius", StepBasic_SiUnitName::StepBasic_sunDegreeCelsius)
		.value("StepBasic_sunLumen", StepBasic_SiUnitName::StepBasic_sunLumen)
		.value("StepBasic_sunLux", StepBasic_SiUnitName::StepBasic_sunLux)
		.value("StepBasic_sunBecquerel", StepBasic_SiUnitName::StepBasic_sunBecquerel)
		.value("StepBasic_sunGray", StepBasic_SiUnitName::StepBasic_sunGray)
		.value("StepBasic_sunSievert", StepBasic_SiUnitName::StepBasic_sunSievert)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_AheadOrBehind.hxx
	py::enum_<StepBasic_AheadOrBehind>(mod, "StepBasic_AheadOrBehind", "None")
		.value("StepBasic_aobAhead", StepBasic_AheadOrBehind::StepBasic_aobAhead)
		.value("StepBasic_aobExact", StepBasic_AheadOrBehind::StepBasic_aobExact)
		.value("StepBasic_aobBehind", StepBasic_AheadOrBehind::StepBasic_aobBehind)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Source.hxx
	py::enum_<StepBasic_Source>(mod, "StepBasic_Source", "None")
		.value("StepBasic_sMade", StepBasic_Source::StepBasic_sMade)
		.value("StepBasic_sBought", StepBasic_Source::StepBasic_sBought)
		.value("StepBasic_sNotKnown", StepBasic_Source::StepBasic_sNotKnown)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Action.hxx
	py::class_<StepBasic_Action, opencascade::handle<StepBasic_Action>, Standard_Transient> cls_StepBasic_Action(mod, "StepBasic_Action", "Representation of STEP entity Action");
	cls_StepBasic_Action.def(py::init<>());
	cls_StepBasic_Action.def("Init", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_Action::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aChosenMethod"));
	cls_StepBasic_Action.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Action::*)() const ) &StepBasic_Action::Name, "Returns field Name");
	cls_StepBasic_Action.def("SetName", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Action::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_Action.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Action::*)() const ) &StepBasic_Action::Description, "Returns field Description");
	cls_StepBasic_Action.def("SetDescription", (void (StepBasic_Action::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Action::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_Action.def("HasDescription", (Standard_Boolean (StepBasic_Action::*)() const ) &StepBasic_Action::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_Action.def("ChosenMethod", (opencascade::handle<StepBasic_ActionMethod> (StepBasic_Action::*)() const ) &StepBasic_Action::ChosenMethod, "Returns field ChosenMethod");
	cls_StepBasic_Action.def("SetChosenMethod", (void (StepBasic_Action::*)(const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_Action::SetChosenMethod, "Set field ChosenMethod", py::arg("ChosenMethod"));
	cls_StepBasic_Action.def_static("get_type_name_", (const char * (*)()) &StepBasic_Action::get_type_name, "None");
	cls_StepBasic_Action.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Action::get_type_descriptor, "None");
	cls_StepBasic_Action.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Action::*)() const ) &StepBasic_Action::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ActionAssignment.hxx
	py::class_<StepBasic_ActionAssignment, opencascade::handle<StepBasic_ActionAssignment>, Standard_Transient> cls_StepBasic_ActionAssignment(mod, "StepBasic_ActionAssignment", "Representation of STEP entity ActionAssignment");
	cls_StepBasic_ActionAssignment.def(py::init<>());
	cls_StepBasic_ActionAssignment.def("Init", (void (StepBasic_ActionAssignment::*)(const opencascade::handle<StepBasic_Action> &)) &StepBasic_ActionAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedAction"));
	cls_StepBasic_ActionAssignment.def("AssignedAction", (opencascade::handle<StepBasic_Action> (StepBasic_ActionAssignment::*)() const ) &StepBasic_ActionAssignment::AssignedAction, "Returns field AssignedAction");
	cls_StepBasic_ActionAssignment.def("SetAssignedAction", (void (StepBasic_ActionAssignment::*)(const opencascade::handle<StepBasic_Action> &)) &StepBasic_ActionAssignment::SetAssignedAction, "Set field AssignedAction", py::arg("AssignedAction"));
	cls_StepBasic_ActionAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionAssignment::get_type_name, "None");
	cls_StepBasic_ActionAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionAssignment::get_type_descriptor, "None");
	cls_StepBasic_ActionAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionAssignment::*)() const ) &StepBasic_ActionAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ActionMethod.hxx
	py::class_<StepBasic_ActionMethod, opencascade::handle<StepBasic_ActionMethod>, Standard_Transient> cls_StepBasic_ActionMethod(mod, "StepBasic_ActionMethod", "Representation of STEP entity ActionMethod");
	cls_StepBasic_ActionMethod.def(py::init<>());
	cls_StepBasic_ActionMethod.def("Init", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aConsequence"), py::arg("aPurpose"));
	cls_StepBasic_ActionMethod.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::Name, "Returns field Name");
	cls_StepBasic_ActionMethod.def("SetName", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_ActionMethod.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::Description, "Returns field Description");
	cls_StepBasic_ActionMethod.def("SetDescription", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ActionMethod.def("HasDescription", (Standard_Boolean (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_ActionMethod.def("Consequence", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::Consequence, "Returns field Consequence");
	cls_StepBasic_ActionMethod.def("SetConsequence", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetConsequence, "Set field Consequence", py::arg("Consequence"));
	cls_StepBasic_ActionMethod.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::Purpose, "Returns field Purpose");
	cls_StepBasic_ActionMethod.def("SetPurpose", (void (StepBasic_ActionMethod::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ActionMethod::SetPurpose, "Set field Purpose", py::arg("Purpose"));
	cls_StepBasic_ActionMethod.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionMethod::get_type_name, "None");
	cls_StepBasic_ActionMethod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionMethod::get_type_descriptor, "None");
	cls_StepBasic_ActionMethod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionMethod::*)() const ) &StepBasic_ActionMethod::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ActionRequestAssignment.hxx
	py::class_<StepBasic_ActionRequestAssignment, opencascade::handle<StepBasic_ActionRequestAssignment>, Standard_Transient> cls_StepBasic_ActionRequestAssignment(mod, "StepBasic_ActionRequestAssignment", "Representation of STEP entity ActionRequestAssignment");
	cls_StepBasic_ActionRequestAssignment.def(py::init<>());
	cls_StepBasic_ActionRequestAssignment.def("Init", (void (StepBasic_ActionRequestAssignment::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedActionRequest"));
	cls_StepBasic_ActionRequestAssignment.def("AssignedActionRequest", (opencascade::handle<StepBasic_VersionedActionRequest> (StepBasic_ActionRequestAssignment::*)() const ) &StepBasic_ActionRequestAssignment::AssignedActionRequest, "Returns field AssignedActionRequest");
	cls_StepBasic_ActionRequestAssignment.def("SetAssignedActionRequest", (void (StepBasic_ActionRequestAssignment::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestAssignment::SetAssignedActionRequest, "Set field AssignedActionRequest", py::arg("AssignedActionRequest"));
	cls_StepBasic_ActionRequestAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionRequestAssignment::get_type_name, "None");
	cls_StepBasic_ActionRequestAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionRequestAssignment::get_type_descriptor, "None");
	cls_StepBasic_ActionRequestAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionRequestAssignment::*)() const ) &StepBasic_ActionRequestAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ActionRequestSolution.hxx
	py::class_<StepBasic_ActionRequestSolution, opencascade::handle<StepBasic_ActionRequestSolution>, Standard_Transient> cls_StepBasic_ActionRequestSolution(mod, "StepBasic_ActionRequestSolution", "Representation of STEP entity ActionRequestSolution");
	cls_StepBasic_ActionRequestSolution.def(py::init<>());
	cls_StepBasic_ActionRequestSolution.def("Init", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_ActionMethod> &, const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestSolution::Init, "Initialize all fields (own and inherited)", py::arg("aMethod"), py::arg("aRequest"));
	cls_StepBasic_ActionRequestSolution.def("Method", (opencascade::handle<StepBasic_ActionMethod> (StepBasic_ActionRequestSolution::*)() const ) &StepBasic_ActionRequestSolution::Method, "Returns field Method");
	cls_StepBasic_ActionRequestSolution.def("SetMethod", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_ActionMethod> &)) &StepBasic_ActionRequestSolution::SetMethod, "Set field Method", py::arg("Method"));
	cls_StepBasic_ActionRequestSolution.def("Request", (opencascade::handle<StepBasic_VersionedActionRequest> (StepBasic_ActionRequestSolution::*)() const ) &StepBasic_ActionRequestSolution::Request, "Returns field Request");
	cls_StepBasic_ActionRequestSolution.def("SetRequest", (void (StepBasic_ActionRequestSolution::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestSolution::SetRequest, "Set field Request", py::arg("Request"));
	cls_StepBasic_ActionRequestSolution.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionRequestSolution::get_type_name, "None");
	cls_StepBasic_ActionRequestSolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionRequestSolution::get_type_descriptor, "None");
	cls_StepBasic_ActionRequestSolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionRequestSolution::*)() const ) &StepBasic_ActionRequestSolution::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Address.hxx
	py::class_<StepBasic_Address, opencascade::handle<StepBasic_Address>, Standard_Transient> cls_StepBasic_Address(mod, "StepBasic_Address", "None");
	cls_StepBasic_Address.def(py::init<>());
	cls_StepBasic_Address.def("Init", (void (StepBasic_Address::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"));
	cls_StepBasic_Address.def("SetInternalLocation", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetInternalLocation, "None", py::arg("aInternalLocation"));
	cls_StepBasic_Address.def("UnSetInternalLocation", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetInternalLocation, "None");
	cls_StepBasic_Address.def("InternalLocation", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::InternalLocation, "None");
	cls_StepBasic_Address.def("HasInternalLocation", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasInternalLocation, "None");
	cls_StepBasic_Address.def("SetStreetNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetStreetNumber, "None", py::arg("aStreetNumber"));
	cls_StepBasic_Address.def("UnSetStreetNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetStreetNumber, "None");
	cls_StepBasic_Address.def("StreetNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::StreetNumber, "None");
	cls_StepBasic_Address.def("HasStreetNumber", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasStreetNumber, "None");
	cls_StepBasic_Address.def("SetStreet", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetStreet, "None", py::arg("aStreet"));
	cls_StepBasic_Address.def("UnSetStreet", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetStreet, "None");
	cls_StepBasic_Address.def("Street", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::Street, "None");
	cls_StepBasic_Address.def("HasStreet", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasStreet, "None");
	cls_StepBasic_Address.def("SetPostalBox", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetPostalBox, "None", py::arg("aPostalBox"));
	cls_StepBasic_Address.def("UnSetPostalBox", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetPostalBox, "None");
	cls_StepBasic_Address.def("PostalBox", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::PostalBox, "None");
	cls_StepBasic_Address.def("HasPostalBox", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasPostalBox, "None");
	cls_StepBasic_Address.def("SetTown", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTown, "None", py::arg("aTown"));
	cls_StepBasic_Address.def("UnSetTown", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTown, "None");
	cls_StepBasic_Address.def("Town", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::Town, "None");
	cls_StepBasic_Address.def("HasTown", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasTown, "None");
	cls_StepBasic_Address.def("SetRegion", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetRegion, "None", py::arg("aRegion"));
	cls_StepBasic_Address.def("UnSetRegion", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetRegion, "None");
	cls_StepBasic_Address.def("Region", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::Region, "None");
	cls_StepBasic_Address.def("HasRegion", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasRegion, "None");
	cls_StepBasic_Address.def("SetPostalCode", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetPostalCode, "None", py::arg("aPostalCode"));
	cls_StepBasic_Address.def("UnSetPostalCode", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetPostalCode, "None");
	cls_StepBasic_Address.def("PostalCode", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::PostalCode, "None");
	cls_StepBasic_Address.def("HasPostalCode", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasPostalCode, "None");
	cls_StepBasic_Address.def("SetCountry", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetCountry, "None", py::arg("aCountry"));
	cls_StepBasic_Address.def("UnSetCountry", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetCountry, "None");
	cls_StepBasic_Address.def("Country", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::Country, "None");
	cls_StepBasic_Address.def("HasCountry", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasCountry, "None");
	cls_StepBasic_Address.def("SetFacsimileNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetFacsimileNumber, "None", py::arg("aFacsimileNumber"));
	cls_StepBasic_Address.def("UnSetFacsimileNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetFacsimileNumber, "None");
	cls_StepBasic_Address.def("FacsimileNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::FacsimileNumber, "None");
	cls_StepBasic_Address.def("HasFacsimileNumber", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasFacsimileNumber, "None");
	cls_StepBasic_Address.def("SetTelephoneNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTelephoneNumber, "None", py::arg("aTelephoneNumber"));
	cls_StepBasic_Address.def("UnSetTelephoneNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTelephoneNumber, "None");
	cls_StepBasic_Address.def("TelephoneNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::TelephoneNumber, "None");
	cls_StepBasic_Address.def("HasTelephoneNumber", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasTelephoneNumber, "None");
	cls_StepBasic_Address.def("SetElectronicMailAddress", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetElectronicMailAddress, "None", py::arg("aElectronicMailAddress"));
	cls_StepBasic_Address.def("UnSetElectronicMailAddress", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetElectronicMailAddress, "None");
	cls_StepBasic_Address.def("ElectronicMailAddress", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::ElectronicMailAddress, "None");
	cls_StepBasic_Address.def("HasElectronicMailAddress", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasElectronicMailAddress, "None");
	cls_StepBasic_Address.def("SetTelexNumber", (void (StepBasic_Address::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Address::SetTelexNumber, "None", py::arg("aTelexNumber"));
	cls_StepBasic_Address.def("UnSetTelexNumber", (void (StepBasic_Address::*)()) &StepBasic_Address::UnSetTelexNumber, "None");
	cls_StepBasic_Address.def("TelexNumber", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Address::*)() const ) &StepBasic_Address::TelexNumber, "None");
	cls_StepBasic_Address.def("HasTelexNumber", (Standard_Boolean (StepBasic_Address::*)() const ) &StepBasic_Address::HasTelexNumber, "None");
	cls_StepBasic_Address.def_static("get_type_name_", (const char * (*)()) &StepBasic_Address::get_type_name, "None");
	cls_StepBasic_Address.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Address::get_type_descriptor, "None");
	cls_StepBasic_Address.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Address::*)() const ) &StepBasic_Address::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApplicationContext.hxx
	py::class_<StepBasic_ApplicationContext, opencascade::handle<StepBasic_ApplicationContext>, Standard_Transient> cls_StepBasic_ApplicationContext(mod, "StepBasic_ApplicationContext", "None");
	cls_StepBasic_ApplicationContext.def(py::init<>());
	cls_StepBasic_ApplicationContext.def("Init", (void (StepBasic_ApplicationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContext::Init, "None", py::arg("aApplication"));
	cls_StepBasic_ApplicationContext.def("SetApplication", (void (StepBasic_ApplicationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContext::SetApplication, "None", py::arg("aApplication"));
	cls_StepBasic_ApplicationContext.def("Application", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationContext::*)() const ) &StepBasic_ApplicationContext::Application, "None");
	cls_StepBasic_ApplicationContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationContext::get_type_name, "None");
	cls_StepBasic_ApplicationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationContext::get_type_descriptor, "None");
	cls_StepBasic_ApplicationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationContext::*)() const ) &StepBasic_ApplicationContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApplicationContextElement.hxx
	py::class_<StepBasic_ApplicationContextElement, opencascade::handle<StepBasic_ApplicationContextElement>, Standard_Transient> cls_StepBasic_ApplicationContextElement(mod, "StepBasic_ApplicationContextElement", "None");
	cls_StepBasic_ApplicationContextElement.def(py::init<>());
	cls_StepBasic_ApplicationContextElement.def("Init", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationContextElement::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"));
	cls_StepBasic_ApplicationContextElement.def("SetName", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContextElement::SetName, "None", py::arg("aName"));
	cls_StepBasic_ApplicationContextElement.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationContextElement::*)() const ) &StepBasic_ApplicationContextElement::Name, "None");
	cls_StepBasic_ApplicationContextElement.def("SetFrameOfReference", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationContextElement::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
	cls_StepBasic_ApplicationContextElement.def("FrameOfReference", (opencascade::handle<StepBasic_ApplicationContext> (StepBasic_ApplicationContextElement::*)() const ) &StepBasic_ApplicationContextElement::FrameOfReference, "None");
	cls_StepBasic_ApplicationContextElement.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationContextElement::get_type_name, "None");
	cls_StepBasic_ApplicationContextElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationContextElement::get_type_descriptor, "None");
	cls_StepBasic_ApplicationContextElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationContextElement::*)() const ) &StepBasic_ApplicationContextElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApplicationProtocolDefinition.hxx
	py::class_<StepBasic_ApplicationProtocolDefinition, opencascade::handle<StepBasic_ApplicationProtocolDefinition>, Standard_Transient> cls_StepBasic_ApplicationProtocolDefinition(mod, "StepBasic_ApplicationProtocolDefinition", "None");
	cls_StepBasic_ApplicationProtocolDefinition.def(py::init<>());
	cls_StepBasic_ApplicationProtocolDefinition.def("Init", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationProtocolDefinition::Init, "None", py::arg("aStatus"), py::arg("aApplicationInterpretedModelSchemaName"), py::arg("aApplicationProtocolYear"), py::arg("aApplication"));
	cls_StepBasic_ApplicationProtocolDefinition.def("SetStatus", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationProtocolDefinition::SetStatus, "None", py::arg("aStatus"));
	cls_StepBasic_ApplicationProtocolDefinition.def("Status", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationProtocolDefinition::*)() const ) &StepBasic_ApplicationProtocolDefinition::Status, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def("SetApplicationInterpretedModelSchemaName", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationProtocolDefinition::SetApplicationInterpretedModelSchemaName, "None", py::arg("aApplicationInterpretedModelSchemaName"));
	cls_StepBasic_ApplicationProtocolDefinition.def("ApplicationInterpretedModelSchemaName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationProtocolDefinition::*)() const ) &StepBasic_ApplicationProtocolDefinition::ApplicationInterpretedModelSchemaName, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def("SetApplicationProtocolYear", (void (StepBasic_ApplicationProtocolDefinition::*)(const Standard_Integer)) &StepBasic_ApplicationProtocolDefinition::SetApplicationProtocolYear, "None", py::arg("aApplicationProtocolYear"));
	cls_StepBasic_ApplicationProtocolDefinition.def("ApplicationProtocolYear", (Standard_Integer (StepBasic_ApplicationProtocolDefinition::*)() const ) &StepBasic_ApplicationProtocolDefinition::ApplicationProtocolYear, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def("SetApplication", (void (StepBasic_ApplicationProtocolDefinition::*)(const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationProtocolDefinition::SetApplication, "None", py::arg("aApplication"));
	cls_StepBasic_ApplicationProtocolDefinition.def("Application", (opencascade::handle<StepBasic_ApplicationContext> (StepBasic_ApplicationProtocolDefinition::*)() const ) &StepBasic_ApplicationProtocolDefinition::Application, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationProtocolDefinition::get_type_name, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationProtocolDefinition::get_type_descriptor, "None");
	cls_StepBasic_ApplicationProtocolDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationProtocolDefinition::*)() const ) &StepBasic_ApplicationProtocolDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Approval.hxx
	py::class_<StepBasic_Approval, opencascade::handle<StepBasic_Approval>, Standard_Transient> cls_StepBasic_Approval(mod, "StepBasic_Approval", "None");
	cls_StepBasic_Approval.def(py::init<>());
	cls_StepBasic_Approval.def("Init", (void (StepBasic_Approval::*)(const opencascade::handle<StepBasic_ApprovalStatus> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Approval::Init, "None", py::arg("aStatus"), py::arg("aLevel"));
	cls_StepBasic_Approval.def("SetStatus", (void (StepBasic_Approval::*)(const opencascade::handle<StepBasic_ApprovalStatus> &)) &StepBasic_Approval::SetStatus, "None", py::arg("aStatus"));
	cls_StepBasic_Approval.def("Status", (opencascade::handle<StepBasic_ApprovalStatus> (StepBasic_Approval::*)() const ) &StepBasic_Approval::Status, "None");
	cls_StepBasic_Approval.def("SetLevel", (void (StepBasic_Approval::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Approval::SetLevel, "None", py::arg("aLevel"));
	cls_StepBasic_Approval.def("Level", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Approval::*)() const ) &StepBasic_Approval::Level, "None");
	cls_StepBasic_Approval.def_static("get_type_name_", (const char * (*)()) &StepBasic_Approval::get_type_name, "None");
	cls_StepBasic_Approval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Approval::get_type_descriptor, "None");
	cls_StepBasic_Approval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Approval::*)() const ) &StepBasic_Approval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalDateTime.hxx
	py::class_<StepBasic_ApprovalDateTime, opencascade::handle<StepBasic_ApprovalDateTime>, Standard_Transient> cls_StepBasic_ApprovalDateTime(mod, "StepBasic_ApprovalDateTime", "Added from StepBasic Rev2 to Rev4");
	cls_StepBasic_ApprovalDateTime.def(py::init<>());
	cls_StepBasic_ApprovalDateTime.def("Init", (void (StepBasic_ApprovalDateTime::*)(const StepBasic_DateTimeSelect &, const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalDateTime::Init, "None", py::arg("aDateTime"), py::arg("aDatedApproval"));
	cls_StepBasic_ApprovalDateTime.def("SetDateTime", (void (StepBasic_ApprovalDateTime::*)(const StepBasic_DateTimeSelect &)) &StepBasic_ApprovalDateTime::SetDateTime, "None", py::arg("aDateTime"));
	cls_StepBasic_ApprovalDateTime.def("DateTime", (StepBasic_DateTimeSelect (StepBasic_ApprovalDateTime::*)() const ) &StepBasic_ApprovalDateTime::DateTime, "None");
	cls_StepBasic_ApprovalDateTime.def("SetDatedApproval", (void (StepBasic_ApprovalDateTime::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalDateTime::SetDatedApproval, "None", py::arg("aDatedApproval"));
	cls_StepBasic_ApprovalDateTime.def("DatedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalDateTime::*)() const ) &StepBasic_ApprovalDateTime::DatedApproval, "None");
	cls_StepBasic_ApprovalDateTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalDateTime::get_type_name, "None");
	cls_StepBasic_ApprovalDateTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalDateTime::get_type_descriptor, "None");
	cls_StepBasic_ApprovalDateTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalDateTime::*)() const ) &StepBasic_ApprovalDateTime::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalPersonOrganization.hxx
	py::class_<StepBasic_ApprovalPersonOrganization, opencascade::handle<StepBasic_ApprovalPersonOrganization>, Standard_Transient> cls_StepBasic_ApprovalPersonOrganization(mod, "StepBasic_ApprovalPersonOrganization", "None");
	cls_StepBasic_ApprovalPersonOrganization.def(py::init<>());
	cls_StepBasic_ApprovalPersonOrganization.def("Init", (void (StepBasic_ApprovalPersonOrganization::*)(const StepBasic_PersonOrganizationSelect &, const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepBasic_ApprovalRole> &)) &StepBasic_ApprovalPersonOrganization::Init, "None", py::arg("aPersonOrganization"), py::arg("aAuthorizedApproval"), py::arg("aRole"));
	cls_StepBasic_ApprovalPersonOrganization.def("SetPersonOrganization", (void (StepBasic_ApprovalPersonOrganization::*)(const StepBasic_PersonOrganizationSelect &)) &StepBasic_ApprovalPersonOrganization::SetPersonOrganization, "None", py::arg("aPersonOrganization"));
	cls_StepBasic_ApprovalPersonOrganization.def("PersonOrganization", (StepBasic_PersonOrganizationSelect (StepBasic_ApprovalPersonOrganization::*)() const ) &StepBasic_ApprovalPersonOrganization::PersonOrganization, "None");
	cls_StepBasic_ApprovalPersonOrganization.def("SetAuthorizedApproval", (void (StepBasic_ApprovalPersonOrganization::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalPersonOrganization::SetAuthorizedApproval, "None", py::arg("aAuthorizedApproval"));
	cls_StepBasic_ApprovalPersonOrganization.def("AuthorizedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalPersonOrganization::*)() const ) &StepBasic_ApprovalPersonOrganization::AuthorizedApproval, "None");
	cls_StepBasic_ApprovalPersonOrganization.def("SetRole", (void (StepBasic_ApprovalPersonOrganization::*)(const opencascade::handle<StepBasic_ApprovalRole> &)) &StepBasic_ApprovalPersonOrganization::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_ApprovalPersonOrganization.def("Role", (opencascade::handle<StepBasic_ApprovalRole> (StepBasic_ApprovalPersonOrganization::*)() const ) &StepBasic_ApprovalPersonOrganization::Role, "None");
	cls_StepBasic_ApprovalPersonOrganization.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalPersonOrganization::get_type_name, "None");
	cls_StepBasic_ApprovalPersonOrganization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalPersonOrganization::get_type_descriptor, "None");
	cls_StepBasic_ApprovalPersonOrganization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalPersonOrganization::*)() const ) &StepBasic_ApprovalPersonOrganization::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalRelationship.hxx
	py::class_<StepBasic_ApprovalRelationship, opencascade::handle<StepBasic_ApprovalRelationship>, Standard_Transient> cls_StepBasic_ApprovalRelationship(mod, "StepBasic_ApprovalRelationship", "None");
	cls_StepBasic_ApprovalRelationship.def(py::init<>());
	cls_StepBasic_ApprovalRelationship.def("Init", (void (StepBasic_ApprovalRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalRelationship::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRelatingApproval"), py::arg("aRelatedApproval"));
	cls_StepBasic_ApprovalRelationship.def("SetName", (void (StepBasic_ApprovalRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalRelationship::SetName, "None", py::arg("aName"));
	cls_StepBasic_ApprovalRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApprovalRelationship::*)() const ) &StepBasic_ApprovalRelationship::Name, "None");
	cls_StepBasic_ApprovalRelationship.def("SetDescription", (void (StepBasic_ApprovalRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalRelationship::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_ApprovalRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApprovalRelationship::*)() const ) &StepBasic_ApprovalRelationship::Description, "None");
	cls_StepBasic_ApprovalRelationship.def("SetRelatingApproval", (void (StepBasic_ApprovalRelationship::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalRelationship::SetRelatingApproval, "None", py::arg("aRelatingApproval"));
	cls_StepBasic_ApprovalRelationship.def("RelatingApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalRelationship::*)() const ) &StepBasic_ApprovalRelationship::RelatingApproval, "None");
	cls_StepBasic_ApprovalRelationship.def("SetRelatedApproval", (void (StepBasic_ApprovalRelationship::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalRelationship::SetRelatedApproval, "None", py::arg("aRelatedApproval"));
	cls_StepBasic_ApprovalRelationship.def("RelatedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalRelationship::*)() const ) &StepBasic_ApprovalRelationship::RelatedApproval, "None");
	cls_StepBasic_ApprovalRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalRelationship::get_type_name, "None");
	cls_StepBasic_ApprovalRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalRelationship::get_type_descriptor, "None");
	cls_StepBasic_ApprovalRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalRelationship::*)() const ) &StepBasic_ApprovalRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalRole.hxx
	py::class_<StepBasic_ApprovalRole, opencascade::handle<StepBasic_ApprovalRole>, Standard_Transient> cls_StepBasic_ApprovalRole(mod, "StepBasic_ApprovalRole", "None");
	cls_StepBasic_ApprovalRole.def(py::init<>());
	cls_StepBasic_ApprovalRole.def("Init", (void (StepBasic_ApprovalRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalRole::Init, "None", py::arg("aRole"));
	cls_StepBasic_ApprovalRole.def("SetRole", (void (StepBasic_ApprovalRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalRole::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_ApprovalRole.def("Role", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApprovalRole::*)() const ) &StepBasic_ApprovalRole::Role, "None");
	cls_StepBasic_ApprovalRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalRole::get_type_name, "None");
	cls_StepBasic_ApprovalRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalRole::get_type_descriptor, "None");
	cls_StepBasic_ApprovalRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalRole::*)() const ) &StepBasic_ApprovalRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalStatus.hxx
	py::class_<StepBasic_ApprovalStatus, opencascade::handle<StepBasic_ApprovalStatus>, Standard_Transient> cls_StepBasic_ApprovalStatus(mod, "StepBasic_ApprovalStatus", "None");
	cls_StepBasic_ApprovalStatus.def(py::init<>());
	cls_StepBasic_ApprovalStatus.def("Init", (void (StepBasic_ApprovalStatus::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalStatus::Init, "None", py::arg("aName"));
	cls_StepBasic_ApprovalStatus.def("SetName", (void (StepBasic_ApprovalStatus::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApprovalStatus::SetName, "None", py::arg("aName"));
	cls_StepBasic_ApprovalStatus.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApprovalStatus::*)() const ) &StepBasic_ApprovalStatus::Name, "None");
	cls_StepBasic_ApprovalStatus.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalStatus::get_type_name, "None");
	cls_StepBasic_ApprovalStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalStatus::get_type_descriptor, "None");
	cls_StepBasic_ApprovalStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalStatus::*)() const ) &StepBasic_ApprovalStatus::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Date.hxx
	py::class_<StepBasic_Date, opencascade::handle<StepBasic_Date>, Standard_Transient> cls_StepBasic_Date(mod, "StepBasic_Date", "None");
	cls_StepBasic_Date.def(py::init<>());
	cls_StepBasic_Date.def("Init", (void (StepBasic_Date::*)(const Standard_Integer)) &StepBasic_Date::Init, "None", py::arg("aYearComponent"));
	cls_StepBasic_Date.def("SetYearComponent", (void (StepBasic_Date::*)(const Standard_Integer)) &StepBasic_Date::SetYearComponent, "None", py::arg("aYearComponent"));
	cls_StepBasic_Date.def("YearComponent", (Standard_Integer (StepBasic_Date::*)() const ) &StepBasic_Date::YearComponent, "None");
	cls_StepBasic_Date.def_static("get_type_name_", (const char * (*)()) &StepBasic_Date::get_type_name, "None");
	cls_StepBasic_Date.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Date::get_type_descriptor, "None");
	cls_StepBasic_Date.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Date::*)() const ) &StepBasic_Date::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Certification.hxx
	py::class_<StepBasic_Certification, opencascade::handle<StepBasic_Certification>, Standard_Transient> cls_StepBasic_Certification(mod, "StepBasic_Certification", "Representation of STEP entity Certification");
	cls_StepBasic_Certification.def(py::init<>());
	cls_StepBasic_Certification.def("Init", (void (StepBasic_Certification::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_CertificationType> &)) &StepBasic_Certification::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aPurpose"), py::arg("aKind"));
	cls_StepBasic_Certification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Certification::*)() const ) &StepBasic_Certification::Name, "Returns field Name");
	cls_StepBasic_Certification.def("SetName", (void (StepBasic_Certification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Certification::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_Certification.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Certification::*)() const ) &StepBasic_Certification::Purpose, "Returns field Purpose");
	cls_StepBasic_Certification.def("SetPurpose", (void (StepBasic_Certification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Certification::SetPurpose, "Set field Purpose", py::arg("Purpose"));
	cls_StepBasic_Certification.def("Kind", (opencascade::handle<StepBasic_CertificationType> (StepBasic_Certification::*)() const ) &StepBasic_Certification::Kind, "Returns field Kind");
	cls_StepBasic_Certification.def("SetKind", (void (StepBasic_Certification::*)(const opencascade::handle<StepBasic_CertificationType> &)) &StepBasic_Certification::SetKind, "Set field Kind", py::arg("Kind"));
	cls_StepBasic_Certification.def_static("get_type_name_", (const char * (*)()) &StepBasic_Certification::get_type_name, "None");
	cls_StepBasic_Certification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Certification::get_type_descriptor, "None");
	cls_StepBasic_Certification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Certification::*)() const ) &StepBasic_Certification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_CertificationAssignment.hxx
	py::class_<StepBasic_CertificationAssignment, opencascade::handle<StepBasic_CertificationAssignment>, Standard_Transient> cls_StepBasic_CertificationAssignment(mod, "StepBasic_CertificationAssignment", "Representation of STEP entity CertificationAssignment");
	cls_StepBasic_CertificationAssignment.def(py::init<>());
	cls_StepBasic_CertificationAssignment.def("Init", (void (StepBasic_CertificationAssignment::*)(const opencascade::handle<StepBasic_Certification> &)) &StepBasic_CertificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedCertification"));
	cls_StepBasic_CertificationAssignment.def("AssignedCertification", (opencascade::handle<StepBasic_Certification> (StepBasic_CertificationAssignment::*)() const ) &StepBasic_CertificationAssignment::AssignedCertification, "Returns field AssignedCertification");
	cls_StepBasic_CertificationAssignment.def("SetAssignedCertification", (void (StepBasic_CertificationAssignment::*)(const opencascade::handle<StepBasic_Certification> &)) &StepBasic_CertificationAssignment::SetAssignedCertification, "Set field AssignedCertification", py::arg("AssignedCertification"));
	cls_StepBasic_CertificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_CertificationAssignment::get_type_name, "None");
	cls_StepBasic_CertificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CertificationAssignment::get_type_descriptor, "None");
	cls_StepBasic_CertificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CertificationAssignment::*)() const ) &StepBasic_CertificationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_CertificationType.hxx
	py::class_<StepBasic_CertificationType, opencascade::handle<StepBasic_CertificationType>, Standard_Transient> cls_StepBasic_CertificationType(mod, "StepBasic_CertificationType", "Representation of STEP entity CertificationType");
	cls_StepBasic_CertificationType.def(py::init<>());
	cls_StepBasic_CertificationType.def("Init", (void (StepBasic_CertificationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CertificationType::Init, "Initialize all fields (own and inherited)", py::arg("aDescription"));
	cls_StepBasic_CertificationType.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_CertificationType::*)() const ) &StepBasic_CertificationType::Description, "Returns field Description");
	cls_StepBasic_CertificationType.def("SetDescription", (void (StepBasic_CertificationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CertificationType::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_CertificationType.def_static("get_type_name_", (const char * (*)()) &StepBasic_CertificationType::get_type_name, "None");
	cls_StepBasic_CertificationType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CertificationType::get_type_descriptor, "None");
	cls_StepBasic_CertificationType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CertificationType::*)() const ) &StepBasic_CertificationType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_CharacterizedObject.hxx
	py::class_<StepBasic_CharacterizedObject, opencascade::handle<StepBasic_CharacterizedObject>, Standard_Transient> cls_StepBasic_CharacterizedObject(mod, "StepBasic_CharacterizedObject", "Representation of STEP entity CharacterizedObject");
	cls_StepBasic_CharacterizedObject.def(py::init<>());
	cls_StepBasic_CharacterizedObject.def("Init", (void (StepBasic_CharacterizedObject::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CharacterizedObject::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_CharacterizedObject.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_CharacterizedObject::*)() const ) &StepBasic_CharacterizedObject::Name, "Returns field Name");
	cls_StepBasic_CharacterizedObject.def("SetName", (void (StepBasic_CharacterizedObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CharacterizedObject::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_CharacterizedObject.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_CharacterizedObject::*)() const ) &StepBasic_CharacterizedObject::Description, "Returns field Description");
	cls_StepBasic_CharacterizedObject.def("SetDescription", (void (StepBasic_CharacterizedObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CharacterizedObject::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_CharacterizedObject.def("HasDescription", (Standard_Boolean (StepBasic_CharacterizedObject::*)() const ) &StepBasic_CharacterizedObject::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_CharacterizedObject.def_static("get_type_name_", (const char * (*)()) &StepBasic_CharacterizedObject::get_type_name, "None");
	cls_StepBasic_CharacterizedObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CharacterizedObject::get_type_descriptor, "None");
	cls_StepBasic_CharacterizedObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CharacterizedObject::*)() const ) &StepBasic_CharacterizedObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Contract.hxx
	py::class_<StepBasic_Contract, opencascade::handle<StepBasic_Contract>, Standard_Transient> cls_StepBasic_Contract(mod, "StepBasic_Contract", "Representation of STEP entity Contract");
	cls_StepBasic_Contract.def(py::init<>());
	cls_StepBasic_Contract.def("Init", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ContractType> &)) &StepBasic_Contract::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aPurpose"), py::arg("aKind"));
	cls_StepBasic_Contract.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Contract::*)() const ) &StepBasic_Contract::Name, "Returns field Name");
	cls_StepBasic_Contract.def("SetName", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Contract::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_Contract.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Contract::*)() const ) &StepBasic_Contract::Purpose, "Returns field Purpose");
	cls_StepBasic_Contract.def("SetPurpose", (void (StepBasic_Contract::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Contract::SetPurpose, "Set field Purpose", py::arg("Purpose"));
	cls_StepBasic_Contract.def("Kind", (opencascade::handle<StepBasic_ContractType> (StepBasic_Contract::*)() const ) &StepBasic_Contract::Kind, "Returns field Kind");
	cls_StepBasic_Contract.def("SetKind", (void (StepBasic_Contract::*)(const opencascade::handle<StepBasic_ContractType> &)) &StepBasic_Contract::SetKind, "Set field Kind", py::arg("Kind"));
	cls_StepBasic_Contract.def_static("get_type_name_", (const char * (*)()) &StepBasic_Contract::get_type_name, "None");
	cls_StepBasic_Contract.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Contract::get_type_descriptor, "None");
	cls_StepBasic_Contract.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Contract::*)() const ) &StepBasic_Contract::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ContractAssignment.hxx
	py::class_<StepBasic_ContractAssignment, opencascade::handle<StepBasic_ContractAssignment>, Standard_Transient> cls_StepBasic_ContractAssignment(mod, "StepBasic_ContractAssignment", "Representation of STEP entity ContractAssignment");
	cls_StepBasic_ContractAssignment.def(py::init<>());
	cls_StepBasic_ContractAssignment.def("Init", (void (StepBasic_ContractAssignment::*)(const opencascade::handle<StepBasic_Contract> &)) &StepBasic_ContractAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedContract"));
	cls_StepBasic_ContractAssignment.def("AssignedContract", (opencascade::handle<StepBasic_Contract> (StepBasic_ContractAssignment::*)() const ) &StepBasic_ContractAssignment::AssignedContract, "Returns field AssignedContract");
	cls_StepBasic_ContractAssignment.def("SetAssignedContract", (void (StepBasic_ContractAssignment::*)(const opencascade::handle<StepBasic_Contract> &)) &StepBasic_ContractAssignment::SetAssignedContract, "Set field AssignedContract", py::arg("AssignedContract"));
	cls_StepBasic_ContractAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ContractAssignment::get_type_name, "None");
	cls_StepBasic_ContractAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ContractAssignment::get_type_descriptor, "None");
	cls_StepBasic_ContractAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ContractAssignment::*)() const ) &StepBasic_ContractAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ContractType.hxx
	py::class_<StepBasic_ContractType, opencascade::handle<StepBasic_ContractType>, Standard_Transient> cls_StepBasic_ContractType(mod, "StepBasic_ContractType", "Representation of STEP entity ContractType");
	cls_StepBasic_ContractType.def(py::init<>());
	cls_StepBasic_ContractType.def("Init", (void (StepBasic_ContractType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ContractType::Init, "Initialize all fields (own and inherited)", py::arg("aDescription"));
	cls_StepBasic_ContractType.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ContractType::*)() const ) &StepBasic_ContractType::Description, "Returns field Description");
	cls_StepBasic_ContractType.def("SetDescription", (void (StepBasic_ContractType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ContractType::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ContractType.def_static("get_type_name_", (const char * (*)()) &StepBasic_ContractType::get_type_name, "None");
	cls_StepBasic_ContractType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ContractType::get_type_descriptor, "None");
	cls_StepBasic_ContractType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ContractType::*)() const ) &StepBasic_ContractType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_NamedUnit.hxx
	py::class_<StepBasic_NamedUnit, opencascade::handle<StepBasic_NamedUnit>, Standard_Transient> cls_StepBasic_NamedUnit(mod, "StepBasic_NamedUnit", "None");
	cls_StepBasic_NamedUnit.def(py::init<>());
	cls_StepBasic_NamedUnit.def("Init", (void (StepBasic_NamedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_NamedUnit::Init, "None", py::arg("aDimensions"));
	cls_StepBasic_NamedUnit.def("SetDimensions", (void (StepBasic_NamedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_NamedUnit::SetDimensions, "None", py::arg("aDimensions"));
	cls_StepBasic_NamedUnit.def("Dimensions", (opencascade::handle<StepBasic_DimensionalExponents> (StepBasic_NamedUnit::*)() const ) &StepBasic_NamedUnit::Dimensions, "None");
	cls_StepBasic_NamedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_NamedUnit::get_type_name, "None");
	cls_StepBasic_NamedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_NamedUnit::get_type_descriptor, "None");
	cls_StepBasic_NamedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_NamedUnit::*)() const ) &StepBasic_NamedUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnit.hxx
	py::class_<StepBasic_ConversionBasedUnit, opencascade::handle<StepBasic_ConversionBasedUnit>, StepBasic_NamedUnit> cls_StepBasic_ConversionBasedUnit(mod, "StepBasic_ConversionBasedUnit", "None");
	cls_StepBasic_ConversionBasedUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnit.def("Init", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnit.def("SetName", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ConversionBasedUnit::SetName, "None", py::arg("aName"));
	cls_StepBasic_ConversionBasedUnit.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ConversionBasedUnit::*)() const ) &StepBasic_ConversionBasedUnit::Name, "None");
	cls_StepBasic_ConversionBasedUnit.def("SetConversionFactor", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnit::SetConversionFactor, "None", py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnit.def("ConversionFactor", (opencascade::handle<StepBasic_MeasureWithUnit> (StepBasic_ConversionBasedUnit::*)() const ) &StepBasic_ConversionBasedUnit::ConversionFactor, "None");
	cls_StepBasic_ConversionBasedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnit::*)() const ) &StepBasic_ConversionBasedUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndLengthUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndLengthUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndLengthUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndLengthUnit(mod, "StepBasic_ConversionBasedUnitAndLengthUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndLengthUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndLengthUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def("SetLengthUnit", (void (StepBasic_ConversionBasedUnitAndLengthUnit::*)(const opencascade::handle<StepBasic_LengthUnit> &)) &StepBasic_ConversionBasedUnitAndLengthUnit::SetLengthUnit, "None", py::arg("aLengthUnit"));
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def("LengthUnit", (opencascade::handle<StepBasic_LengthUnit> (StepBasic_ConversionBasedUnitAndLengthUnit::*)() const ) &StepBasic_ConversionBasedUnitAndLengthUnit::LengthUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndLengthUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndLengthUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndLengthUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndLengthUnit::*)() const ) &StepBasic_ConversionBasedUnitAndLengthUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndMassUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndMassUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndMassUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndMassUnit(mod, "StepBasic_ConversionBasedUnitAndMassUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndMassUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def("SetMassUnit", (void (StepBasic_ConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepBasic_MassUnit> &)) &StepBasic_ConversionBasedUnitAndMassUnit::SetMassUnit, "None", py::arg("aMassUnit"));
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def("MassUnit", (opencascade::handle<StepBasic_MassUnit> (StepBasic_ConversionBasedUnitAndMassUnit::*)() const ) &StepBasic_ConversionBasedUnitAndMassUnit::MassUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndMassUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndMassUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndMassUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndMassUnit::*)() const ) &StepBasic_ConversionBasedUnitAndMassUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndPlaneAngleUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndPlaneAngleUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndPlaneAngleUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit(mod, "StepBasic_ConversionBasedUnitAndPlaneAngleUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("SetPlaneAngleUnit", (void (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_PlaneAngleUnit> &)) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::SetPlaneAngleUnit, "None", py::arg("aPlaneAngleUnit"));
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("PlaneAngleUnit", (opencascade::handle<StepBasic_PlaneAngleUnit> (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)() const ) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::PlaneAngleUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)() const ) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndRatioUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndRatioUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndRatioUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndRatioUnit(mod, "StepBasic_ConversionBasedUnitAndRatioUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndRatioUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("SetRatioUnit", (void (StepBasic_ConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_RatioUnit> &)) &StepBasic_ConversionBasedUnitAndRatioUnit::SetRatioUnit, "None", py::arg("aRatioUnit"));
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("RatioUnit", (opencascade::handle<StepBasic_RatioUnit> (StepBasic_ConversionBasedUnitAndRatioUnit::*)() const ) &StepBasic_ConversionBasedUnitAndRatioUnit::RatioUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndRatioUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndRatioUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndRatioUnit::*)() const ) &StepBasic_ConversionBasedUnitAndRatioUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndSolidAngleUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndSolidAngleUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndSolidAngleUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit(mod, "StepBasic_ConversionBasedUnitAndSolidAngleUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndSolidAngleUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def("SetSolidAngleUnit", (void (StepBasic_ConversionBasedUnitAndSolidAngleUnit::*)(const opencascade::handle<StepBasic_SolidAngleUnit> &)) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::SetSolidAngleUnit, "None", py::arg("aSolidAngleUnit"));
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def("SolidAngleUnit", (opencascade::handle<StepBasic_SolidAngleUnit> (StepBasic_ConversionBasedUnitAndSolidAngleUnit::*)() const ) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::SolidAngleUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndSolidAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndSolidAngleUnit::*)() const ) &StepBasic_ConversionBasedUnitAndSolidAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndTimeUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndTimeUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndTimeUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndTimeUnit(mod, "StepBasic_ConversionBasedUnitAndTimeUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndTimeUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("SetTimeUnit", (void (StepBasic_ConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_TimeUnit> &)) &StepBasic_ConversionBasedUnitAndTimeUnit::SetTimeUnit, "None", py::arg("aTimeUnit"));
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("TimeUnit", (opencascade::handle<StepBasic_TimeUnit> (StepBasic_ConversionBasedUnitAndTimeUnit::*)() const ) &StepBasic_ConversionBasedUnitAndTimeUnit::TimeUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndTimeUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndTimeUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndTimeUnit::*)() const ) &StepBasic_ConversionBasedUnitAndTimeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndVolumeUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndVolumeUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndVolumeUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndVolumeUnit(mod, "StepBasic_ConversionBasedUnitAndVolumeUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def("SetVolumeUnit", (void (StepBasic_ConversionBasedUnitAndVolumeUnit::*)(const opencascade::handle<StepBasic_VolumeUnit> &)) &StepBasic_ConversionBasedUnitAndVolumeUnit::SetVolumeUnit, "None", py::arg("aVolumeUnit"));
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def("VolumeUnit", (opencascade::handle<StepBasic_VolumeUnit> (StepBasic_ConversionBasedUnitAndVolumeUnit::*)() const ) &StepBasic_ConversionBasedUnitAndVolumeUnit::VolumeUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndVolumeUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndVolumeUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndVolumeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndVolumeUnit::*)() const ) &StepBasic_ConversionBasedUnitAndVolumeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_CoordinatedUniversalTimeOffset.hxx
	py::class_<StepBasic_CoordinatedUniversalTimeOffset, opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset>, Standard_Transient> cls_StepBasic_CoordinatedUniversalTimeOffset(mod, "StepBasic_CoordinatedUniversalTimeOffset", "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def(py::init<>());
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("Init", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, const StepBasic_AheadOrBehind)) &StepBasic_CoordinatedUniversalTimeOffset::Init, "None", py::arg("aHourOffset"), py::arg("hasAminuteOffset"), py::arg("aMinuteOffset"), py::arg("aSense"));
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetHourOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer)) &StepBasic_CoordinatedUniversalTimeOffset::SetHourOffset, "None", py::arg("aHourOffset"));
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("HourOffset", (Standard_Integer (StepBasic_CoordinatedUniversalTimeOffset::*)() const ) &StepBasic_CoordinatedUniversalTimeOffset::HourOffset, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetMinuteOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const Standard_Integer)) &StepBasic_CoordinatedUniversalTimeOffset::SetMinuteOffset, "None", py::arg("aMinuteOffset"));
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("UnSetMinuteOffset", (void (StepBasic_CoordinatedUniversalTimeOffset::*)()) &StepBasic_CoordinatedUniversalTimeOffset::UnSetMinuteOffset, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("MinuteOffset", (Standard_Integer (StepBasic_CoordinatedUniversalTimeOffset::*)() const ) &StepBasic_CoordinatedUniversalTimeOffset::MinuteOffset, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("HasMinuteOffset", (Standard_Boolean (StepBasic_CoordinatedUniversalTimeOffset::*)() const ) &StepBasic_CoordinatedUniversalTimeOffset::HasMinuteOffset, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("SetSense", (void (StepBasic_CoordinatedUniversalTimeOffset::*)(const StepBasic_AheadOrBehind)) &StepBasic_CoordinatedUniversalTimeOffset::SetSense, "None", py::arg("aSense"));
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("Sense", (StepBasic_AheadOrBehind (StepBasic_CoordinatedUniversalTimeOffset::*)() const ) &StepBasic_CoordinatedUniversalTimeOffset::Sense, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def_static("get_type_name_", (const char * (*)()) &StepBasic_CoordinatedUniversalTimeOffset::get_type_name, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CoordinatedUniversalTimeOffset::get_type_descriptor, "None");
	cls_StepBasic_CoordinatedUniversalTimeOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CoordinatedUniversalTimeOffset::*)() const ) &StepBasic_CoordinatedUniversalTimeOffset::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_CalendarDate.hxx
	py::class_<StepBasic_CalendarDate, opencascade::handle<StepBasic_CalendarDate>, StepBasic_Date> cls_StepBasic_CalendarDate(mod, "StepBasic_CalendarDate", "None");
	cls_StepBasic_CalendarDate.def(py::init<>());
	cls_StepBasic_CalendarDate.def("Init", (void (StepBasic_CalendarDate::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &StepBasic_CalendarDate::Init, "None", py::arg("aYearComponent"), py::arg("aDayComponent"), py::arg("aMonthComponent"));
	cls_StepBasic_CalendarDate.def("SetDayComponent", (void (StepBasic_CalendarDate::*)(const Standard_Integer)) &StepBasic_CalendarDate::SetDayComponent, "None", py::arg("aDayComponent"));
	cls_StepBasic_CalendarDate.def("DayComponent", (Standard_Integer (StepBasic_CalendarDate::*)() const ) &StepBasic_CalendarDate::DayComponent, "None");
	cls_StepBasic_CalendarDate.def("SetMonthComponent", (void (StepBasic_CalendarDate::*)(const Standard_Integer)) &StepBasic_CalendarDate::SetMonthComponent, "None", py::arg("aMonthComponent"));
	cls_StepBasic_CalendarDate.def("MonthComponent", (Standard_Integer (StepBasic_CalendarDate::*)() const ) &StepBasic_CalendarDate::MonthComponent, "None");
	cls_StepBasic_CalendarDate.def_static("get_type_name_", (const char * (*)()) &StepBasic_CalendarDate::get_type_name, "None");
	cls_StepBasic_CalendarDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CalendarDate::get_type_descriptor, "None");
	cls_StepBasic_CalendarDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CalendarDate::*)() const ) &StepBasic_CalendarDate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateAndTime.hxx
	py::class_<StepBasic_DateAndTime, opencascade::handle<StepBasic_DateAndTime>, Standard_Transient> cls_StepBasic_DateAndTime(mod, "StepBasic_DateAndTime", "None");
	cls_StepBasic_DateAndTime.def(py::init<>());
	cls_StepBasic_DateAndTime.def("Init", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_LocalTime> &)) &StepBasic_DateAndTime::Init, "None", py::arg("aDateComponent"), py::arg("aTimeComponent"));
	cls_StepBasic_DateAndTime.def("SetDateComponent", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_Date> &)) &StepBasic_DateAndTime::SetDateComponent, "None", py::arg("aDateComponent"));
	cls_StepBasic_DateAndTime.def("DateComponent", (opencascade::handle<StepBasic_Date> (StepBasic_DateAndTime::*)() const ) &StepBasic_DateAndTime::DateComponent, "None");
	cls_StepBasic_DateAndTime.def("SetTimeComponent", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_LocalTime> &)) &StepBasic_DateAndTime::SetTimeComponent, "None", py::arg("aTimeComponent"));
	cls_StepBasic_DateAndTime.def("TimeComponent", (opencascade::handle<StepBasic_LocalTime> (StepBasic_DateAndTime::*)() const ) &StepBasic_DateAndTime::TimeComponent, "None");
	cls_StepBasic_DateAndTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAndTime::get_type_name, "None");
	cls_StepBasic_DateAndTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAndTime::get_type_descriptor, "None");
	cls_StepBasic_DateAndTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAndTime::*)() const ) &StepBasic_DateAndTime::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateRole.hxx
	py::class_<StepBasic_DateRole, opencascade::handle<StepBasic_DateRole>, Standard_Transient> cls_StepBasic_DateRole(mod, "StepBasic_DateRole", "None");
	cls_StepBasic_DateRole.def(py::init<>());
	cls_StepBasic_DateRole.def("Init", (void (StepBasic_DateRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateRole::Init, "None", py::arg("aName"));
	cls_StepBasic_DateRole.def("SetName", (void (StepBasic_DateRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateRole::SetName, "None", py::arg("aName"));
	cls_StepBasic_DateRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DateRole::*)() const ) &StepBasic_DateRole::Name, "None");
	cls_StepBasic_DateRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateRole::get_type_name, "None");
	cls_StepBasic_DateRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateRole::get_type_descriptor, "None");
	cls_StepBasic_DateRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateRole::*)() const ) &StepBasic_DateRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateTimeRole.hxx
	py::class_<StepBasic_DateTimeRole, opencascade::handle<StepBasic_DateTimeRole>, Standard_Transient> cls_StepBasic_DateTimeRole(mod, "StepBasic_DateTimeRole", "None");
	cls_StepBasic_DateTimeRole.def(py::init<>());
	cls_StepBasic_DateTimeRole.def("Init", (void (StepBasic_DateTimeRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateTimeRole::Init, "None", py::arg("aName"));
	cls_StepBasic_DateTimeRole.def("SetName", (void (StepBasic_DateTimeRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DateTimeRole::SetName, "None", py::arg("aName"));
	cls_StepBasic_DateTimeRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DateTimeRole::*)() const ) &StepBasic_DateTimeRole::Name, "None");
	cls_StepBasic_DateTimeRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateTimeRole::get_type_name, "None");
	cls_StepBasic_DateTimeRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateTimeRole::get_type_descriptor, "None");
	cls_StepBasic_DateTimeRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateTimeRole::*)() const ) &StepBasic_DateTimeRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DerivedUnit.hxx
	py::class_<StepBasic_DerivedUnit, opencascade::handle<StepBasic_DerivedUnit>, Standard_Transient> cls_StepBasic_DerivedUnit(mod, "StepBasic_DerivedUnit", "Added from StepBasic Rev2 to Rev4");
	cls_StepBasic_DerivedUnit.def(py::init<>());
	cls_StepBasic_DerivedUnit.def("Init", (void (StepBasic_DerivedUnit::*)(const opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> &)) &StepBasic_DerivedUnit::Init, "None", py::arg("elements"));
	cls_StepBasic_DerivedUnit.def("SetElements", (void (StepBasic_DerivedUnit::*)(const opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> &)) &StepBasic_DerivedUnit::SetElements, "None", py::arg("elements"));
	cls_StepBasic_DerivedUnit.def("Elements", (opencascade::handle<StepBasic_HArray1OfDerivedUnitElement> (StepBasic_DerivedUnit::*)() const ) &StepBasic_DerivedUnit::Elements, "None");
	cls_StepBasic_DerivedUnit.def("NbElements", (Standard_Integer (StepBasic_DerivedUnit::*)() const ) &StepBasic_DerivedUnit::NbElements, "None");
	cls_StepBasic_DerivedUnit.def("ElementsValue", (opencascade::handle<StepBasic_DerivedUnitElement> (StepBasic_DerivedUnit::*)(const Standard_Integer) const ) &StepBasic_DerivedUnit::ElementsValue, "None", py::arg("num"));
	cls_StepBasic_DerivedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_DerivedUnit::get_type_name, "None");
	cls_StepBasic_DerivedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DerivedUnit::get_type_descriptor, "None");
	cls_StepBasic_DerivedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DerivedUnit::*)() const ) &StepBasic_DerivedUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DerivedUnitElement.hxx
	py::class_<StepBasic_DerivedUnitElement, opencascade::handle<StepBasic_DerivedUnitElement>, Standard_Transient> cls_StepBasic_DerivedUnitElement(mod, "StepBasic_DerivedUnitElement", "Added from StepBasic Rev2 to Rev4");
	cls_StepBasic_DerivedUnitElement.def(py::init<>());
	cls_StepBasic_DerivedUnitElement.def("Init", (void (StepBasic_DerivedUnitElement::*)(const opencascade::handle<StepBasic_NamedUnit> &, const Standard_Real)) &StepBasic_DerivedUnitElement::Init, "None", py::arg("aUnit"), py::arg("aExponent"));
	cls_StepBasic_DerivedUnitElement.def("SetUnit", (void (StepBasic_DerivedUnitElement::*)(const opencascade::handle<StepBasic_NamedUnit> &)) &StepBasic_DerivedUnitElement::SetUnit, "None", py::arg("aUnit"));
	cls_StepBasic_DerivedUnitElement.def("Unit", (opencascade::handle<StepBasic_NamedUnit> (StepBasic_DerivedUnitElement::*)() const ) &StepBasic_DerivedUnitElement::Unit, "None");
	cls_StepBasic_DerivedUnitElement.def("SetExponent", (void (StepBasic_DerivedUnitElement::*)(const Standard_Real)) &StepBasic_DerivedUnitElement::SetExponent, "None", py::arg("aExponent"));
	cls_StepBasic_DerivedUnitElement.def("Exponent", (Standard_Real (StepBasic_DerivedUnitElement::*)() const ) &StepBasic_DerivedUnitElement::Exponent, "None");
	cls_StepBasic_DerivedUnitElement.def_static("get_type_name_", (const char * (*)()) &StepBasic_DerivedUnitElement::get_type_name, "None");
	cls_StepBasic_DerivedUnitElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DerivedUnitElement::get_type_descriptor, "None");
	cls_StepBasic_DerivedUnitElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DerivedUnitElement::*)() const ) &StepBasic_DerivedUnitElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DimensionalExponents.hxx
	py::class_<StepBasic_DimensionalExponents, opencascade::handle<StepBasic_DimensionalExponents>, Standard_Transient> cls_StepBasic_DimensionalExponents(mod, "StepBasic_DimensionalExponents", "None");
	cls_StepBasic_DimensionalExponents.def(py::init<>());
	cls_StepBasic_DimensionalExponents.def("Init", (void (StepBasic_DimensionalExponents::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &StepBasic_DimensionalExponents::Init, "None", py::arg("aLengthExponent"), py::arg("aMassExponent"), py::arg("aTimeExponent"), py::arg("aElectricCurrentExponent"), py::arg("aThermodynamicTemperatureExponent"), py::arg("aAmountOfSubstanceExponent"), py::arg("aLuminousIntensityExponent"));
	cls_StepBasic_DimensionalExponents.def("SetLengthExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetLengthExponent, "None", py::arg("aLengthExponent"));
	cls_StepBasic_DimensionalExponents.def("LengthExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::LengthExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetMassExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetMassExponent, "None", py::arg("aMassExponent"));
	cls_StepBasic_DimensionalExponents.def("MassExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::MassExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetTimeExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetTimeExponent, "None", py::arg("aTimeExponent"));
	cls_StepBasic_DimensionalExponents.def("TimeExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::TimeExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetElectricCurrentExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetElectricCurrentExponent, "None", py::arg("aElectricCurrentExponent"));
	cls_StepBasic_DimensionalExponents.def("ElectricCurrentExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::ElectricCurrentExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetThermodynamicTemperatureExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetThermodynamicTemperatureExponent, "None", py::arg("aThermodynamicTemperatureExponent"));
	cls_StepBasic_DimensionalExponents.def("ThermodynamicTemperatureExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::ThermodynamicTemperatureExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetAmountOfSubstanceExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetAmountOfSubstanceExponent, "None", py::arg("aAmountOfSubstanceExponent"));
	cls_StepBasic_DimensionalExponents.def("AmountOfSubstanceExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::AmountOfSubstanceExponent, "None");
	cls_StepBasic_DimensionalExponents.def("SetLuminousIntensityExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetLuminousIntensityExponent, "None", py::arg("aLuminousIntensityExponent"));
	cls_StepBasic_DimensionalExponents.def("LuminousIntensityExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::LuminousIntensityExponent, "None");
	cls_StepBasic_DimensionalExponents.def_static("get_type_name_", (const char * (*)()) &StepBasic_DimensionalExponents::get_type_name, "None");
	cls_StepBasic_DimensionalExponents.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DimensionalExponents::get_type_descriptor, "None");
	cls_StepBasic_DimensionalExponents.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DimensionalExponents::*)() const ) &StepBasic_DimensionalExponents::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Document.hxx
	py::class_<StepBasic_Document, opencascade::handle<StepBasic_Document>, Standard_Transient> cls_StepBasic_Document(mod, "StepBasic_Document", "Representation of STEP entity Document");
	cls_StepBasic_Document.def(py::init<>());
	cls_StepBasic_Document.def("Init", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_DocumentType> &)) &StepBasic_Document::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aKind"));
	cls_StepBasic_Document.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const ) &StepBasic_Document::Id, "Returns field Id");
	cls_StepBasic_Document.def("SetId", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetId, "Set field Id", py::arg("Id"));
	cls_StepBasic_Document.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const ) &StepBasic_Document::Name, "Returns field Name");
	cls_StepBasic_Document.def("SetName", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_Document.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Document::*)() const ) &StepBasic_Document::Description, "Returns field Description");
	cls_StepBasic_Document.def("SetDescription", (void (StepBasic_Document::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Document::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_Document.def("HasDescription", (Standard_Boolean (StepBasic_Document::*)() const ) &StepBasic_Document::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_Document.def("Kind", (opencascade::handle<StepBasic_DocumentType> (StepBasic_Document::*)() const ) &StepBasic_Document::Kind, "Returns field Kind");
	cls_StepBasic_Document.def("SetKind", (void (StepBasic_Document::*)(const opencascade::handle<StepBasic_DocumentType> &)) &StepBasic_Document::SetKind, "Set field Kind", py::arg("Kind"));
	cls_StepBasic_Document.def_static("get_type_name_", (const char * (*)()) &StepBasic_Document::get_type_name, "None");
	cls_StepBasic_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Document::get_type_descriptor, "None");
	cls_StepBasic_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Document::*)() const ) &StepBasic_Document::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentFile.hxx
	py::class_<StepBasic_DocumentFile, opencascade::handle<StepBasic_DocumentFile>, StepBasic_Document> cls_StepBasic_DocumentFile(mod, "StepBasic_DocumentFile", "Representation of STEP entity DocumentFile");
	cls_StepBasic_DocumentFile.def(py::init<>());
	cls_StepBasic_DocumentFile.def("Init", (void (StepBasic_DocumentFile::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_DocumentType> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentFile::Init, "Initialize all fields (own and inherited)", py::arg("aDocument_Id"), py::arg("aDocument_Name"), py::arg("hasDocument_Description"), py::arg("aDocument_Description"), py::arg("aDocument_Kind"), py::arg("aCharacterizedObject_Name"), py::arg("hasCharacterizedObject_Description"), py::arg("aCharacterizedObject_Description"));
	cls_StepBasic_DocumentFile.def("CharacterizedObject", (opencascade::handle<StepBasic_CharacterizedObject> (StepBasic_DocumentFile::*)() const ) &StepBasic_DocumentFile::CharacterizedObject, "Returns data for supertype CharacterizedObject");
	cls_StepBasic_DocumentFile.def("SetCharacterizedObject", (void (StepBasic_DocumentFile::*)(const opencascade::handle<StepBasic_CharacterizedObject> &)) &StepBasic_DocumentFile::SetCharacterizedObject, "Set data for supertype CharacterizedObject", py::arg("CharacterizedObject"));
	cls_StepBasic_DocumentFile.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentFile::get_type_name, "None");
	cls_StepBasic_DocumentFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentFile::get_type_descriptor, "None");
	cls_StepBasic_DocumentFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentFile::*)() const ) &StepBasic_DocumentFile::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentProductAssociation.hxx
	py::class_<StepBasic_DocumentProductAssociation, opencascade::handle<StepBasic_DocumentProductAssociation>, Standard_Transient> cls_StepBasic_DocumentProductAssociation(mod, "StepBasic_DocumentProductAssociation", "Representation of STEP entity DocumentProductAssociation");
	cls_StepBasic_DocumentProductAssociation.def(py::init<>());
	cls_StepBasic_DocumentProductAssociation.def("Init", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &, const StepBasic_ProductOrFormationOrDefinition &)) &StepBasic_DocumentProductAssociation::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingDocument"), py::arg("aRelatedProduct"));
	cls_StepBasic_DocumentProductAssociation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::Name, "Returns field Name");
	cls_StepBasic_DocumentProductAssociation.def("SetName", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentProductAssociation::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_DocumentProductAssociation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::Description, "Returns field Description");
	cls_StepBasic_DocumentProductAssociation.def("SetDescription", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentProductAssociation::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_DocumentProductAssociation.def("HasDescription", (Standard_Boolean (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_DocumentProductAssociation.def("RelatingDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::RelatingDocument, "Returns field RelatingDocument");
	cls_StepBasic_DocumentProductAssociation.def("SetRelatingDocument", (void (StepBasic_DocumentProductAssociation::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentProductAssociation::SetRelatingDocument, "Set field RelatingDocument", py::arg("RelatingDocument"));
	cls_StepBasic_DocumentProductAssociation.def("RelatedProduct", (StepBasic_ProductOrFormationOrDefinition (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::RelatedProduct, "Returns field RelatedProduct");
	cls_StepBasic_DocumentProductAssociation.def("SetRelatedProduct", (void (StepBasic_DocumentProductAssociation::*)(const StepBasic_ProductOrFormationOrDefinition &)) &StepBasic_DocumentProductAssociation::SetRelatedProduct, "Set field RelatedProduct", py::arg("RelatedProduct"));
	cls_StepBasic_DocumentProductAssociation.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentProductAssociation::get_type_name, "None");
	cls_StepBasic_DocumentProductAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentProductAssociation::get_type_descriptor, "None");
	cls_StepBasic_DocumentProductAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentProductAssociation::*)() const ) &StepBasic_DocumentProductAssociation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentProductEquivalence.hxx
	py::class_<StepBasic_DocumentProductEquivalence, opencascade::handle<StepBasic_DocumentProductEquivalence>, StepBasic_DocumentProductAssociation> cls_StepBasic_DocumentProductEquivalence(mod, "StepBasic_DocumentProductEquivalence", "Representation of STEP entity DocumentProductEquivalence");
	cls_StepBasic_DocumentProductEquivalence.def(py::init<>());
	cls_StepBasic_DocumentProductEquivalence.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentProductEquivalence::get_type_name, "None");
	cls_StepBasic_DocumentProductEquivalence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentProductEquivalence::get_type_descriptor, "None");
	cls_StepBasic_DocumentProductEquivalence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentProductEquivalence::*)() const ) &StepBasic_DocumentProductEquivalence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentRelationship.hxx
	py::class_<StepBasic_DocumentRelationship, opencascade::handle<StepBasic_DocumentRelationship>, Standard_Transient> cls_StepBasic_DocumentRelationship(mod, "StepBasic_DocumentRelationship", "None");
	cls_StepBasic_DocumentRelationship.def(py::init<>());
	cls_StepBasic_DocumentRelationship.def("Init", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &, const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRelating"), py::arg("aRelated"));
	cls_StepBasic_DocumentRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRelationship::*)() const ) &StepBasic_DocumentRelationship::Name, "None");
	cls_StepBasic_DocumentRelationship.def("SetName", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRelationship::SetName, "None", py::arg("aName"));
	cls_StepBasic_DocumentRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRelationship::*)() const ) &StepBasic_DocumentRelationship::Description, "None");
	cls_StepBasic_DocumentRelationship.def("SetDescription", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRelationship::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_DocumentRelationship.def("RelatingDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRelationship::*)() const ) &StepBasic_DocumentRelationship::RelatingDocument, "None");
	cls_StepBasic_DocumentRelationship.def("SetRelatingDocument", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::SetRelatingDocument, "None", py::arg("aRelating"));
	cls_StepBasic_DocumentRelationship.def("RelatedDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRelationship::*)() const ) &StepBasic_DocumentRelationship::RelatedDocument, "None");
	cls_StepBasic_DocumentRelationship.def("SetRelatedDocument", (void (StepBasic_DocumentRelationship::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRelationship::SetRelatedDocument, "None", py::arg("aRelated"));
	cls_StepBasic_DocumentRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentRelationship::get_type_name, "None");
	cls_StepBasic_DocumentRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentRelationship::get_type_descriptor, "None");
	cls_StepBasic_DocumentRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentRelationship::*)() const ) &StepBasic_DocumentRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentRepresentationType.hxx
	py::class_<StepBasic_DocumentRepresentationType, opencascade::handle<StepBasic_DocumentRepresentationType>, Standard_Transient> cls_StepBasic_DocumentRepresentationType(mod, "StepBasic_DocumentRepresentationType", "Representation of STEP entity DocumentRepresentationType");
	cls_StepBasic_DocumentRepresentationType.def(py::init<>());
	cls_StepBasic_DocumentRepresentationType.def("Init", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRepresentationType::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aRepresentedDocument"));
	cls_StepBasic_DocumentRepresentationType.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentRepresentationType::*)() const ) &StepBasic_DocumentRepresentationType::Name, "Returns field Name");
	cls_StepBasic_DocumentRepresentationType.def("SetName", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentRepresentationType::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_DocumentRepresentationType.def("RepresentedDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentRepresentationType::*)() const ) &StepBasic_DocumentRepresentationType::RepresentedDocument, "Returns field RepresentedDocument");
	cls_StepBasic_DocumentRepresentationType.def("SetRepresentedDocument", (void (StepBasic_DocumentRepresentationType::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentRepresentationType::SetRepresentedDocument, "Set field RepresentedDocument", py::arg("RepresentedDocument"));
	cls_StepBasic_DocumentRepresentationType.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentRepresentationType::get_type_name, "None");
	cls_StepBasic_DocumentRepresentationType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentRepresentationType::get_type_descriptor, "None");
	cls_StepBasic_DocumentRepresentationType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentRepresentationType::*)() const ) &StepBasic_DocumentRepresentationType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentType.hxx
	py::class_<StepBasic_DocumentType, opencascade::handle<StepBasic_DocumentType>, Standard_Transient> cls_StepBasic_DocumentType(mod, "StepBasic_DocumentType", "None");
	cls_StepBasic_DocumentType.def(py::init<>());
	cls_StepBasic_DocumentType.def("Init", (void (StepBasic_DocumentType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentType::Init, "None", py::arg("apdt"));
	cls_StepBasic_DocumentType.def("ProductDataType", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentType::*)() const ) &StepBasic_DocumentType::ProductDataType, "None");
	cls_StepBasic_DocumentType.def("SetProductDataType", (void (StepBasic_DocumentType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentType::SetProductDataType, "None", py::arg("apdt"));
	cls_StepBasic_DocumentType.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentType::get_type_name, "None");
	cls_StepBasic_DocumentType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentType::get_type_descriptor, "None");
	cls_StepBasic_DocumentType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentType::*)() const ) &StepBasic_DocumentType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentUsageConstraint.hxx
	py::class_<StepBasic_DocumentUsageConstraint, opencascade::handle<StepBasic_DocumentUsageConstraint>, Standard_Transient> cls_StepBasic_DocumentUsageConstraint(mod, "StepBasic_DocumentUsageConstraint", "None");
	cls_StepBasic_DocumentUsageConstraint.def(py::init<>());
	cls_StepBasic_DocumentUsageConstraint.def("Init", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::Init, "None", py::arg("aSource"), py::arg("ase"), py::arg("asev"));
	cls_StepBasic_DocumentUsageConstraint.def("Source", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentUsageConstraint::*)() const ) &StepBasic_DocumentUsageConstraint::Source, "None");
	cls_StepBasic_DocumentUsageConstraint.def("SetSource", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentUsageConstraint::SetSource, "None", py::arg("aSource"));
	cls_StepBasic_DocumentUsageConstraint.def("SubjectElement", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentUsageConstraint::*)() const ) &StepBasic_DocumentUsageConstraint::SubjectElement, "None");
	cls_StepBasic_DocumentUsageConstraint.def("SetSubjectElement", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::SetSubjectElement, "None", py::arg("ase"));
	cls_StepBasic_DocumentUsageConstraint.def("SubjectElementValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentUsageConstraint::*)() const ) &StepBasic_DocumentUsageConstraint::SubjectElementValue, "None");
	cls_StepBasic_DocumentUsageConstraint.def("SetSubjectElementValue", (void (StepBasic_DocumentUsageConstraint::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentUsageConstraint::SetSubjectElementValue, "None", py::arg("asev"));
	cls_StepBasic_DocumentUsageConstraint.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentUsageConstraint::get_type_name, "None");
	cls_StepBasic_DocumentUsageConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentUsageConstraint::get_type_descriptor, "None");
	cls_StepBasic_DocumentUsageConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentUsageConstraint::*)() const ) &StepBasic_DocumentUsageConstraint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Effectivity.hxx
	py::class_<StepBasic_Effectivity, opencascade::handle<StepBasic_Effectivity>, Standard_Transient> cls_StepBasic_Effectivity(mod, "StepBasic_Effectivity", "None");
	cls_StepBasic_Effectivity.def(py::init<>());
	cls_StepBasic_Effectivity.def("Init", (void (StepBasic_Effectivity::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Effectivity::Init, "None", py::arg("aid"));
	cls_StepBasic_Effectivity.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Effectivity::*)() const ) &StepBasic_Effectivity::Id, "None");
	cls_StepBasic_Effectivity.def("SetId", (void (StepBasic_Effectivity::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Effectivity::SetId, "None", py::arg("aid"));
	cls_StepBasic_Effectivity.def_static("get_type_name_", (const char * (*)()) &StepBasic_Effectivity::get_type_name, "None");
	cls_StepBasic_Effectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Effectivity::get_type_descriptor, "None");
	cls_StepBasic_Effectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Effectivity::*)() const ) &StepBasic_Effectivity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_EffectivityAssignment.hxx
	py::class_<StepBasic_EffectivityAssignment, opencascade::handle<StepBasic_EffectivityAssignment>, Standard_Transient> cls_StepBasic_EffectivityAssignment(mod, "StepBasic_EffectivityAssignment", "Representation of STEP entity EffectivityAssignment");
	cls_StepBasic_EffectivityAssignment.def(py::init<>());
	cls_StepBasic_EffectivityAssignment.def("Init", (void (StepBasic_EffectivityAssignment::*)(const opencascade::handle<StepBasic_Effectivity> &)) &StepBasic_EffectivityAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedEffectivity"));
	cls_StepBasic_EffectivityAssignment.def("AssignedEffectivity", (opencascade::handle<StepBasic_Effectivity> (StepBasic_EffectivityAssignment::*)() const ) &StepBasic_EffectivityAssignment::AssignedEffectivity, "Returns field AssignedEffectivity");
	cls_StepBasic_EffectivityAssignment.def("SetAssignedEffectivity", (void (StepBasic_EffectivityAssignment::*)(const opencascade::handle<StepBasic_Effectivity> &)) &StepBasic_EffectivityAssignment::SetAssignedEffectivity, "Set field AssignedEffectivity", py::arg("AssignedEffectivity"));
	cls_StepBasic_EffectivityAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_EffectivityAssignment::get_type_name, "None");
	cls_StepBasic_EffectivityAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_EffectivityAssignment::get_type_descriptor, "None");
	cls_StepBasic_EffectivityAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_EffectivityAssignment::*)() const ) &StepBasic_EffectivityAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_EulerAngles.hxx
	py::class_<StepBasic_EulerAngles, opencascade::handle<StepBasic_EulerAngles>, Standard_Transient> cls_StepBasic_EulerAngles(mod, "StepBasic_EulerAngles", "Representation of STEP entity EulerAngles");
	cls_StepBasic_EulerAngles.def(py::init<>());
	cls_StepBasic_EulerAngles.def("Init", (void (StepBasic_EulerAngles::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepBasic_EulerAngles::Init, "Initialize all fields (own and inherited)", py::arg("aAngles"));
	cls_StepBasic_EulerAngles.def("Angles", (opencascade::handle<TColStd_HArray1OfReal> (StepBasic_EulerAngles::*)() const ) &StepBasic_EulerAngles::Angles, "Returns field Angles");
	cls_StepBasic_EulerAngles.def("SetAngles", (void (StepBasic_EulerAngles::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepBasic_EulerAngles::SetAngles, "Set field Angles", py::arg("Angles"));
	cls_StepBasic_EulerAngles.def_static("get_type_name_", (const char * (*)()) &StepBasic_EulerAngles::get_type_name, "None");
	cls_StepBasic_EulerAngles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_EulerAngles::get_type_descriptor, "None");
	cls_StepBasic_EulerAngles.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_EulerAngles::*)() const ) &StepBasic_EulerAngles::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_IdentificationAssignment.hxx
	py::class_<StepBasic_IdentificationAssignment, opencascade::handle<StepBasic_IdentificationAssignment>, Standard_Transient> cls_StepBasic_IdentificationAssignment(mod, "StepBasic_IdentificationAssignment", "Representation of STEP entity IdentificationAssignment");
	cls_StepBasic_IdentificationAssignment.def(py::init<>());
	cls_StepBasic_IdentificationAssignment.def("Init", (void (StepBasic_IdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_IdentificationRole> &)) &StepBasic_IdentificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedId"), py::arg("aRole"));
	cls_StepBasic_IdentificationAssignment.def("AssignedId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_IdentificationAssignment::*)() const ) &StepBasic_IdentificationAssignment::AssignedId, "Returns field AssignedId");
	cls_StepBasic_IdentificationAssignment.def("SetAssignedId", (void (StepBasic_IdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationAssignment::SetAssignedId, "Set field AssignedId", py::arg("AssignedId"));
	cls_StepBasic_IdentificationAssignment.def("Role", (opencascade::handle<StepBasic_IdentificationRole> (StepBasic_IdentificationAssignment::*)() const ) &StepBasic_IdentificationAssignment::Role, "Returns field Role");
	cls_StepBasic_IdentificationAssignment.def("SetRole", (void (StepBasic_IdentificationAssignment::*)(const opencascade::handle<StepBasic_IdentificationRole> &)) &StepBasic_IdentificationAssignment::SetRole, "Set field Role", py::arg("Role"));
	cls_StepBasic_IdentificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_IdentificationAssignment::get_type_name, "None");
	cls_StepBasic_IdentificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_IdentificationAssignment::get_type_descriptor, "None");
	cls_StepBasic_IdentificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_IdentificationAssignment::*)() const ) &StepBasic_IdentificationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ExternallyDefinedItem.hxx
	py::class_<StepBasic_ExternallyDefinedItem, opencascade::handle<StepBasic_ExternallyDefinedItem>, Standard_Transient> cls_StepBasic_ExternallyDefinedItem(mod, "StepBasic_ExternallyDefinedItem", "Representation of STEP entity ExternallyDefinedItem");
	cls_StepBasic_ExternallyDefinedItem.def(py::init<>());
	cls_StepBasic_ExternallyDefinedItem.def("Init", (void (StepBasic_ExternallyDefinedItem::*)(const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternallyDefinedItem::Init, "Initialize all fields (own and inherited)", py::arg("aItemId"), py::arg("aSource"));
	cls_StepBasic_ExternallyDefinedItem.def("ItemId", (StepBasic_SourceItem (StepBasic_ExternallyDefinedItem::*)() const ) &StepBasic_ExternallyDefinedItem::ItemId, "Returns field ItemId");
	cls_StepBasic_ExternallyDefinedItem.def("SetItemId", (void (StepBasic_ExternallyDefinedItem::*)(const StepBasic_SourceItem &)) &StepBasic_ExternallyDefinedItem::SetItemId, "Set field ItemId", py::arg("ItemId"));
	cls_StepBasic_ExternallyDefinedItem.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ExternallyDefinedItem::*)() const ) &StepBasic_ExternallyDefinedItem::Source, "Returns field Source");
	cls_StepBasic_ExternallyDefinedItem.def("SetSource", (void (StepBasic_ExternallyDefinedItem::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternallyDefinedItem::SetSource, "Set field Source", py::arg("Source"));
	cls_StepBasic_ExternallyDefinedItem.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternallyDefinedItem::get_type_name, "None");
	cls_StepBasic_ExternallyDefinedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternallyDefinedItem::get_type_descriptor, "None");
	cls_StepBasic_ExternallyDefinedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternallyDefinedItem::*)() const ) &StepBasic_ExternallyDefinedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ExternalSource.hxx
	py::class_<StepBasic_ExternalSource, opencascade::handle<StepBasic_ExternalSource>, Standard_Transient> cls_StepBasic_ExternalSource(mod, "StepBasic_ExternalSource", "Representation of STEP entity ExternalSource");
	cls_StepBasic_ExternalSource.def(py::init<>());
	cls_StepBasic_ExternalSource.def("Init", (void (StepBasic_ExternalSource::*)(const StepBasic_SourceItem &)) &StepBasic_ExternalSource::Init, "Initialize all fields (own and inherited)", py::arg("aSourceId"));
	cls_StepBasic_ExternalSource.def("SourceId", (StepBasic_SourceItem (StepBasic_ExternalSource::*)() const ) &StepBasic_ExternalSource::SourceId, "Returns field SourceId");
	cls_StepBasic_ExternalSource.def("SetSourceId", (void (StepBasic_ExternalSource::*)(const StepBasic_SourceItem &)) &StepBasic_ExternalSource::SetSourceId, "Set field SourceId", py::arg("SourceId"));
	cls_StepBasic_ExternalSource.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternalSource::get_type_name, "None");
	cls_StepBasic_ExternalSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternalSource::get_type_descriptor, "None");
	cls_StepBasic_ExternalSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternalSource::*)() const ) &StepBasic_ExternalSource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_GeneralProperty.hxx
	py::class_<StepBasic_GeneralProperty, opencascade::handle<StepBasic_GeneralProperty>, Standard_Transient> cls_StepBasic_GeneralProperty(mod, "StepBasic_GeneralProperty", "Representation of STEP entity GeneralProperty");
	cls_StepBasic_GeneralProperty.def(py::init<>());
	cls_StepBasic_GeneralProperty.def("Init", (void (StepBasic_GeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GeneralProperty::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_GeneralProperty.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GeneralProperty::*)() const ) &StepBasic_GeneralProperty::Id, "Returns field Id");
	cls_StepBasic_GeneralProperty.def("SetId", (void (StepBasic_GeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GeneralProperty::SetId, "Set field Id", py::arg("Id"));
	cls_StepBasic_GeneralProperty.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GeneralProperty::*)() const ) &StepBasic_GeneralProperty::Name, "Returns field Name");
	cls_StepBasic_GeneralProperty.def("SetName", (void (StepBasic_GeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GeneralProperty::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_GeneralProperty.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GeneralProperty::*)() const ) &StepBasic_GeneralProperty::Description, "Returns field Description");
	cls_StepBasic_GeneralProperty.def("SetDescription", (void (StepBasic_GeneralProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GeneralProperty::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_GeneralProperty.def("HasDescription", (Standard_Boolean (StepBasic_GeneralProperty::*)() const ) &StepBasic_GeneralProperty::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_GeneralProperty.def_static("get_type_name_", (const char * (*)()) &StepBasic_GeneralProperty::get_type_name, "None");
	cls_StepBasic_GeneralProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_GeneralProperty::get_type_descriptor, "None");
	cls_StepBasic_GeneralProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_GeneralProperty::*)() const ) &StepBasic_GeneralProperty::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Group.hxx
	py::class_<StepBasic_Group, opencascade::handle<StepBasic_Group>, Standard_Transient> cls_StepBasic_Group(mod, "StepBasic_Group", "Representation of STEP entity Group");
	cls_StepBasic_Group.def(py::init<>());
	cls_StepBasic_Group.def("Init", (void (StepBasic_Group::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Group::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_Group.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Group::*)() const ) &StepBasic_Group::Name, "Returns field Name");
	cls_StepBasic_Group.def("SetName", (void (StepBasic_Group::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Group::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_Group.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Group::*)() const ) &StepBasic_Group::Description, "Returns field Description");
	cls_StepBasic_Group.def("SetDescription", (void (StepBasic_Group::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Group::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_Group.def("HasDescription", (Standard_Boolean (StepBasic_Group::*)() const ) &StepBasic_Group::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_Group.def_static("get_type_name_", (const char * (*)()) &StepBasic_Group::get_type_name, "None");
	cls_StepBasic_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Group::get_type_descriptor, "None");
	cls_StepBasic_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Group::*)() const ) &StepBasic_Group::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_GroupAssignment.hxx
	py::class_<StepBasic_GroupAssignment, opencascade::handle<StepBasic_GroupAssignment>, Standard_Transient> cls_StepBasic_GroupAssignment(mod, "StepBasic_GroupAssignment", "Representation of STEP entity GroupAssignment");
	cls_StepBasic_GroupAssignment.def(py::init<>());
	cls_StepBasic_GroupAssignment.def("Init", (void (StepBasic_GroupAssignment::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedGroup"));
	cls_StepBasic_GroupAssignment.def("AssignedGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupAssignment::*)() const ) &StepBasic_GroupAssignment::AssignedGroup, "Returns field AssignedGroup");
	cls_StepBasic_GroupAssignment.def("SetAssignedGroup", (void (StepBasic_GroupAssignment::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupAssignment::SetAssignedGroup, "Set field AssignedGroup", py::arg("AssignedGroup"));
	cls_StepBasic_GroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_GroupAssignment::get_type_name, "None");
	cls_StepBasic_GroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_GroupAssignment::get_type_descriptor, "None");
	cls_StepBasic_GroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_GroupAssignment::*)() const ) &StepBasic_GroupAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_GroupRelationship.hxx
	py::class_<StepBasic_GroupRelationship, opencascade::handle<StepBasic_GroupRelationship>, Standard_Transient> cls_StepBasic_GroupRelationship(mod, "StepBasic_GroupRelationship", "Representation of STEP entity GroupRelationship");
	cls_StepBasic_GroupRelationship.def(py::init<>());
	cls_StepBasic_GroupRelationship.def("Init", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingGroup"), py::arg("aRelatedGroup"));
	cls_StepBasic_GroupRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::Name, "Returns field Name");
	cls_StepBasic_GroupRelationship.def("SetName", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GroupRelationship::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_GroupRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::Description, "Returns field Description");
	cls_StepBasic_GroupRelationship.def("SetDescription", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_GroupRelationship::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_GroupRelationship.def("HasDescription", (Standard_Boolean (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_GroupRelationship.def("RelatingGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::RelatingGroup, "Returns field RelatingGroup");
	cls_StepBasic_GroupRelationship.def("SetRelatingGroup", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::SetRelatingGroup, "Set field RelatingGroup", py::arg("RelatingGroup"));
	cls_StepBasic_GroupRelationship.def("RelatedGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::RelatedGroup, "Returns field RelatedGroup");
	cls_StepBasic_GroupRelationship.def("SetRelatedGroup", (void (StepBasic_GroupRelationship::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupRelationship::SetRelatedGroup, "Set field RelatedGroup", py::arg("RelatedGroup"));
	cls_StepBasic_GroupRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_GroupRelationship::get_type_name, "None");
	cls_StepBasic_GroupRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_GroupRelationship::get_type_descriptor, "None");
	cls_StepBasic_GroupRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_GroupRelationship::*)() const ) &StepBasic_GroupRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ExternalIdentificationAssignment.hxx
	py::class_<StepBasic_ExternalIdentificationAssignment, opencascade::handle<StepBasic_ExternalIdentificationAssignment>, StepBasic_IdentificationAssignment> cls_StepBasic_ExternalIdentificationAssignment(mod, "StepBasic_ExternalIdentificationAssignment", "Representation of STEP entity ExternalIdentificationAssignment");
	cls_StepBasic_ExternalIdentificationAssignment.def(py::init<>());
	cls_StepBasic_ExternalIdentificationAssignment.def("Init", (void (StepBasic_ExternalIdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_IdentificationRole> &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternalIdentificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aIdentificationAssignment_AssignedId"), py::arg("aIdentificationAssignment_Role"), py::arg("aSource"));
	cls_StepBasic_ExternalIdentificationAssignment.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ExternalIdentificationAssignment::*)() const ) &StepBasic_ExternalIdentificationAssignment::Source, "Returns field Source");
	cls_StepBasic_ExternalIdentificationAssignment.def("SetSource", (void (StepBasic_ExternalIdentificationAssignment::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternalIdentificationAssignment::SetSource, "Set field Source", py::arg("Source"));
	cls_StepBasic_ExternalIdentificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternalIdentificationAssignment::get_type_name, "None");
	cls_StepBasic_ExternalIdentificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternalIdentificationAssignment::get_type_descriptor, "None");
	cls_StepBasic_ExternalIdentificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternalIdentificationAssignment::*)() const ) &StepBasic_ExternalIdentificationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_IdentificationRole.hxx
	py::class_<StepBasic_IdentificationRole, opencascade::handle<StepBasic_IdentificationRole>, Standard_Transient> cls_StepBasic_IdentificationRole(mod, "StepBasic_IdentificationRole", "Representation of STEP entity IdentificationRole");
	cls_StepBasic_IdentificationRole.def(py::init<>());
	cls_StepBasic_IdentificationRole.def("Init", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_IdentificationRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_IdentificationRole::*)() const ) &StepBasic_IdentificationRole::Name, "Returns field Name");
	cls_StepBasic_IdentificationRole.def("SetName", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_IdentificationRole.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_IdentificationRole::*)() const ) &StepBasic_IdentificationRole::Description, "Returns field Description");
	cls_StepBasic_IdentificationRole.def("SetDescription", (void (StepBasic_IdentificationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_IdentificationRole::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_IdentificationRole.def("HasDescription", (Standard_Boolean (StepBasic_IdentificationRole::*)() const ) &StepBasic_IdentificationRole::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_IdentificationRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_IdentificationRole::get_type_name, "None");
	cls_StepBasic_IdentificationRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_IdentificationRole::get_type_descriptor, "None");
	cls_StepBasic_IdentificationRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_IdentificationRole::*)() const ) &StepBasic_IdentificationRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_MeasureWithUnit.hxx
	py::class_<StepBasic_MeasureWithUnit, opencascade::handle<StepBasic_MeasureWithUnit>, Standard_Transient> cls_StepBasic_MeasureWithUnit(mod, "StepBasic_MeasureWithUnit", "None");
	cls_StepBasic_MeasureWithUnit.def(py::init<>());
	cls_StepBasic_MeasureWithUnit.def("Init", (void (StepBasic_MeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &)) &StepBasic_MeasureWithUnit::Init, "None", py::arg("aValueComponent"), py::arg("aUnitComponent"));
	cls_StepBasic_MeasureWithUnit.def("SetValueComponent", (void (StepBasic_MeasureWithUnit::*)(const Standard_Real)) &StepBasic_MeasureWithUnit::SetValueComponent, "None", py::arg("aValueComponent"));
	cls_StepBasic_MeasureWithUnit.def("ValueComponent", (Standard_Real (StepBasic_MeasureWithUnit::*)() const ) &StepBasic_MeasureWithUnit::ValueComponent, "None");
	cls_StepBasic_MeasureWithUnit.def("ValueComponentMember", (opencascade::handle<StepBasic_MeasureValueMember> (StepBasic_MeasureWithUnit::*)() const ) &StepBasic_MeasureWithUnit::ValueComponentMember, "None");
	cls_StepBasic_MeasureWithUnit.def("SetValueComponentMember", (void (StepBasic_MeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepBasic_MeasureWithUnit::SetValueComponentMember, "None", py::arg("val"));
	cls_StepBasic_MeasureWithUnit.def("SetUnitComponent", (void (StepBasic_MeasureWithUnit::*)(const StepBasic_Unit &)) &StepBasic_MeasureWithUnit::SetUnitComponent, "None", py::arg("aUnitComponent"));
	cls_StepBasic_MeasureWithUnit.def("UnitComponent", (StepBasic_Unit (StepBasic_MeasureWithUnit::*)() const ) &StepBasic_MeasureWithUnit::UnitComponent, "None");
	cls_StepBasic_MeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_MeasureWithUnit::get_type_name, "None");
	cls_StepBasic_MeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_MeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MeasureWithUnit::*)() const ) &StepBasic_MeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_LengthUnit.hxx
	py::class_<StepBasic_LengthUnit, opencascade::handle<StepBasic_LengthUnit>, StepBasic_NamedUnit> cls_StepBasic_LengthUnit(mod, "StepBasic_LengthUnit", "None");
	cls_StepBasic_LengthUnit.def(py::init<>());
	cls_StepBasic_LengthUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_LengthUnit::get_type_name, "None");
	cls_StepBasic_LengthUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_LengthUnit::get_type_descriptor, "None");
	cls_StepBasic_LengthUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_LengthUnit::*)() const ) &StepBasic_LengthUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_LocalTime.hxx
	py::class_<StepBasic_LocalTime, opencascade::handle<StepBasic_LocalTime>, Standard_Transient> cls_StepBasic_LocalTime(mod, "StepBasic_LocalTime", "None");
	cls_StepBasic_LocalTime.def(py::init<>());
	cls_StepBasic_LocalTime.def("Init", (void (StepBasic_LocalTime::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, const Standard_Boolean, const Standard_Real, const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &)) &StepBasic_LocalTime::Init, "None", py::arg("aHourComponent"), py::arg("hasAminuteComponent"), py::arg("aMinuteComponent"), py::arg("hasAsecondComponent"), py::arg("aSecondComponent"), py::arg("aZone"));
	cls_StepBasic_LocalTime.def("SetHourComponent", (void (StepBasic_LocalTime::*)(const Standard_Integer)) &StepBasic_LocalTime::SetHourComponent, "None", py::arg("aHourComponent"));
	cls_StepBasic_LocalTime.def("HourComponent", (Standard_Integer (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::HourComponent, "None");
	cls_StepBasic_LocalTime.def("SetMinuteComponent", (void (StepBasic_LocalTime::*)(const Standard_Integer)) &StepBasic_LocalTime::SetMinuteComponent, "None", py::arg("aMinuteComponent"));
	cls_StepBasic_LocalTime.def("UnSetMinuteComponent", (void (StepBasic_LocalTime::*)()) &StepBasic_LocalTime::UnSetMinuteComponent, "None");
	cls_StepBasic_LocalTime.def("MinuteComponent", (Standard_Integer (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::MinuteComponent, "None");
	cls_StepBasic_LocalTime.def("HasMinuteComponent", (Standard_Boolean (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::HasMinuteComponent, "None");
	cls_StepBasic_LocalTime.def("SetSecondComponent", (void (StepBasic_LocalTime::*)(const Standard_Real)) &StepBasic_LocalTime::SetSecondComponent, "None", py::arg("aSecondComponent"));
	cls_StepBasic_LocalTime.def("UnSetSecondComponent", (void (StepBasic_LocalTime::*)()) &StepBasic_LocalTime::UnSetSecondComponent, "None");
	cls_StepBasic_LocalTime.def("SecondComponent", (Standard_Real (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::SecondComponent, "None");
	cls_StepBasic_LocalTime.def("HasSecondComponent", (Standard_Boolean (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::HasSecondComponent, "None");
	cls_StepBasic_LocalTime.def("SetZone", (void (StepBasic_LocalTime::*)(const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &)) &StepBasic_LocalTime::SetZone, "None", py::arg("aZone"));
	cls_StepBasic_LocalTime.def("Zone", (opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::Zone, "None");
	cls_StepBasic_LocalTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_LocalTime::get_type_name, "None");
	cls_StepBasic_LocalTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_LocalTime::get_type_descriptor, "None");
	cls_StepBasic_LocalTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_LocalTime::*)() const ) &StepBasic_LocalTime::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_MassMeasureWithUnit.hxx
	py::class_<StepBasic_MassMeasureWithUnit, opencascade::handle<StepBasic_MassMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_MassMeasureWithUnit(mod, "StepBasic_MassMeasureWithUnit", "None");
	cls_StepBasic_MassMeasureWithUnit.def(py::init<>());
	cls_StepBasic_MassMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_MassMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_MassMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MassMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_MassMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MassMeasureWithUnit::*)() const ) &StepBasic_MassMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_MassUnit.hxx
	py::class_<StepBasic_MassUnit, opencascade::handle<StepBasic_MassUnit>, StepBasic_NamedUnit> cls_StepBasic_MassUnit(mod, "StepBasic_MassUnit", "Representation of STEP entity MassUnit");
	cls_StepBasic_MassUnit.def(py::init<>());
	cls_StepBasic_MassUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_MassUnit::get_type_name, "None");
	cls_StepBasic_MassUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MassUnit::get_type_descriptor, "None");
	cls_StepBasic_MassUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MassUnit::*)() const ) &StepBasic_MassUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_LengthMeasureWithUnit.hxx
	py::class_<StepBasic_LengthMeasureWithUnit, opencascade::handle<StepBasic_LengthMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_LengthMeasureWithUnit(mod, "StepBasic_LengthMeasureWithUnit", "None");
	cls_StepBasic_LengthMeasureWithUnit.def(py::init<>());
	cls_StepBasic_LengthMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_LengthMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_LengthMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_LengthMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_LengthMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_LengthMeasureWithUnit::*)() const ) &StepBasic_LengthMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductContext.hxx
	py::class_<StepBasic_ProductContext, opencascade::handle<StepBasic_ProductContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductContext(mod, "StepBasic_ProductContext", "None");
	cls_StepBasic_ProductContext.def(py::init<>());
	cls_StepBasic_ProductContext.def("Init", (void (StepBasic_ProductContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductContext::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"), py::arg("aDisciplineType"));
	cls_StepBasic_ProductContext.def("SetDisciplineType", (void (StepBasic_ProductContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductContext::SetDisciplineType, "None", py::arg("aDisciplineType"));
	cls_StepBasic_ProductContext.def("DisciplineType", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductContext::*)() const ) &StepBasic_ProductContext::DisciplineType, "None");
	cls_StepBasic_ProductContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductContext::get_type_name, "None");
	cls_StepBasic_ProductContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductContext::get_type_descriptor, "None");
	cls_StepBasic_ProductContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductContext::*)() const ) &StepBasic_ProductContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_NameAssignment.hxx
	py::class_<StepBasic_NameAssignment, opencascade::handle<StepBasic_NameAssignment>, Standard_Transient> cls_StepBasic_NameAssignment(mod, "StepBasic_NameAssignment", "Representation of STEP entity NameAssignment");
	cls_StepBasic_NameAssignment.def(py::init<>());
	cls_StepBasic_NameAssignment.def("Init", (void (StepBasic_NameAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_NameAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedName"));
	cls_StepBasic_NameAssignment.def("AssignedName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_NameAssignment::*)() const ) &StepBasic_NameAssignment::AssignedName, "Returns field AssignedName");
	cls_StepBasic_NameAssignment.def("SetAssignedName", (void (StepBasic_NameAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_NameAssignment::SetAssignedName, "Set field AssignedName", py::arg("AssignedName"));
	cls_StepBasic_NameAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_NameAssignment::get_type_name, "None");
	cls_StepBasic_NameAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_NameAssignment::get_type_descriptor, "None");
	cls_StepBasic_NameAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_NameAssignment::*)() const ) &StepBasic_NameAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ConversionBasedUnitAndAreaUnit.hxx
	py::class_<StepBasic_ConversionBasedUnitAndAreaUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndAreaUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndAreaUnit(mod, "StepBasic_ConversionBasedUnitAndAreaUnit", "None");
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def(py::init<>());
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def("SetAreaUnit", (void (StepBasic_ConversionBasedUnitAndAreaUnit::*)(const opencascade::handle<StepBasic_AreaUnit> &)) &StepBasic_ConversionBasedUnitAndAreaUnit::SetAreaUnit, "None", py::arg("anAreaUnit"));
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def("AreaUnit", (opencascade::handle<StepBasic_AreaUnit> (StepBasic_ConversionBasedUnitAndAreaUnit::*)() const ) &StepBasic_ConversionBasedUnitAndAreaUnit::AreaUnit, "None");
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndAreaUnit::get_type_name, "None");
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndAreaUnit::get_type_descriptor, "None");
	cls_StepBasic_ConversionBasedUnitAndAreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndAreaUnit::*)() const ) &StepBasic_ConversionBasedUnitAndAreaUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ObjectRole.hxx
	py::class_<StepBasic_ObjectRole, opencascade::handle<StepBasic_ObjectRole>, Standard_Transient> cls_StepBasic_ObjectRole(mod, "StepBasic_ObjectRole", "Representation of STEP entity ObjectRole");
	cls_StepBasic_ObjectRole.def(py::init<>());
	cls_StepBasic_ObjectRole.def("Init", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_ObjectRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ObjectRole::*)() const ) &StepBasic_ObjectRole::Name, "Returns field Name");
	cls_StepBasic_ObjectRole.def("SetName", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_ObjectRole.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ObjectRole::*)() const ) &StepBasic_ObjectRole::Description, "Returns field Description");
	cls_StepBasic_ObjectRole.def("SetDescription", (void (StepBasic_ObjectRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ObjectRole::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ObjectRole.def("HasDescription", (Standard_Boolean (StepBasic_ObjectRole::*)() const ) &StepBasic_ObjectRole::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_ObjectRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_ObjectRole::get_type_name, "None");
	cls_StepBasic_ObjectRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ObjectRole::get_type_descriptor, "None");
	cls_StepBasic_ObjectRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ObjectRole::*)() const ) &StepBasic_ObjectRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_OrdinalDate.hxx
	py::class_<StepBasic_OrdinalDate, opencascade::handle<StepBasic_OrdinalDate>, StepBasic_Date> cls_StepBasic_OrdinalDate(mod, "StepBasic_OrdinalDate", "None");
	cls_StepBasic_OrdinalDate.def(py::init<>());
	cls_StepBasic_OrdinalDate.def("Init", (void (StepBasic_OrdinalDate::*)(const Standard_Integer, const Standard_Integer)) &StepBasic_OrdinalDate::Init, "None", py::arg("aYearComponent"), py::arg("aDayComponent"));
	cls_StepBasic_OrdinalDate.def("SetDayComponent", (void (StepBasic_OrdinalDate::*)(const Standard_Integer)) &StepBasic_OrdinalDate::SetDayComponent, "None", py::arg("aDayComponent"));
	cls_StepBasic_OrdinalDate.def("DayComponent", (Standard_Integer (StepBasic_OrdinalDate::*)() const ) &StepBasic_OrdinalDate::DayComponent, "None");
	cls_StepBasic_OrdinalDate.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrdinalDate::get_type_name, "None");
	cls_StepBasic_OrdinalDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrdinalDate::get_type_descriptor, "None");
	cls_StepBasic_OrdinalDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrdinalDate::*)() const ) &StepBasic_OrdinalDate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Organization.hxx
	py::class_<StepBasic_Organization, opencascade::handle<StepBasic_Organization>, Standard_Transient> cls_StepBasic_Organization(mod, "StepBasic_Organization", "None");
	cls_StepBasic_Organization.def(py::init<>());
	cls_StepBasic_Organization.def("Init", (void (StepBasic_Organization::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::Init, "None", py::arg("hasAid"), py::arg("aId"), py::arg("aName"), py::arg("aDescription"));
	cls_StepBasic_Organization.def("SetId", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetId, "None", py::arg("aId"));
	cls_StepBasic_Organization.def("UnSetId", (void (StepBasic_Organization::*)()) &StepBasic_Organization::UnSetId, "None");
	cls_StepBasic_Organization.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const ) &StepBasic_Organization::Id, "None");
	cls_StepBasic_Organization.def("HasId", (Standard_Boolean (StepBasic_Organization::*)() const ) &StepBasic_Organization::HasId, "None");
	cls_StepBasic_Organization.def("SetName", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetName, "None", py::arg("aName"));
	cls_StepBasic_Organization.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const ) &StepBasic_Organization::Name, "None");
	cls_StepBasic_Organization.def("SetDescription", (void (StepBasic_Organization::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Organization::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_Organization.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Organization::*)() const ) &StepBasic_Organization::Description, "None");
	cls_StepBasic_Organization.def_static("get_type_name_", (const char * (*)()) &StepBasic_Organization::get_type_name, "None");
	cls_StepBasic_Organization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Organization::get_type_descriptor, "None");
	cls_StepBasic_Organization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Organization::*)() const ) &StepBasic_Organization::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_OrganizationalAddress.hxx
	py::class_<StepBasic_OrganizationalAddress, opencascade::handle<StepBasic_OrganizationalAddress>, StepBasic_Address> cls_StepBasic_OrganizationalAddress(mod, "StepBasic_OrganizationalAddress", "None");
	cls_StepBasic_OrganizationalAddress.def(py::init<>());
	cls_StepBasic_OrganizationalAddress.def("Init", (void (StepBasic_OrganizationalAddress::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfOrganization> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationalAddress::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"), py::arg("aOrganizations"), py::arg("aDescription"));
	cls_StepBasic_OrganizationalAddress.def("SetOrganizations", (void (StepBasic_OrganizationalAddress::*)(const opencascade::handle<StepBasic_HArray1OfOrganization> &)) &StepBasic_OrganizationalAddress::SetOrganizations, "None", py::arg("aOrganizations"));
	cls_StepBasic_OrganizationalAddress.def("Organizations", (opencascade::handle<StepBasic_HArray1OfOrganization> (StepBasic_OrganizationalAddress::*)() const ) &StepBasic_OrganizationalAddress::Organizations, "None");
	cls_StepBasic_OrganizationalAddress.def("OrganizationsValue", (opencascade::handle<StepBasic_Organization> (StepBasic_OrganizationalAddress::*)(const Standard_Integer) const ) &StepBasic_OrganizationalAddress::OrganizationsValue, "None", py::arg("num"));
	cls_StepBasic_OrganizationalAddress.def("NbOrganizations", (Standard_Integer (StepBasic_OrganizationalAddress::*)() const ) &StepBasic_OrganizationalAddress::NbOrganizations, "None");
	cls_StepBasic_OrganizationalAddress.def("SetDescription", (void (StepBasic_OrganizationalAddress::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationalAddress::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_OrganizationalAddress.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_OrganizationalAddress::*)() const ) &StepBasic_OrganizationalAddress::Description, "None");
	cls_StepBasic_OrganizationalAddress.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationalAddress::get_type_name, "None");
	cls_StepBasic_OrganizationalAddress.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationalAddress::get_type_descriptor, "None");
	cls_StepBasic_OrganizationalAddress.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationalAddress::*)() const ) &StepBasic_OrganizationalAddress::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_OrganizationRole.hxx
	py::class_<StepBasic_OrganizationRole, opencascade::handle<StepBasic_OrganizationRole>, Standard_Transient> cls_StepBasic_OrganizationRole(mod, "StepBasic_OrganizationRole", "None");
	cls_StepBasic_OrganizationRole.def(py::init<>());
	cls_StepBasic_OrganizationRole.def("Init", (void (StepBasic_OrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationRole::Init, "None", py::arg("aName"));
	cls_StepBasic_OrganizationRole.def("SetName", (void (StepBasic_OrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_OrganizationRole::SetName, "None", py::arg("aName"));
	cls_StepBasic_OrganizationRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_OrganizationRole::*)() const ) &StepBasic_OrganizationRole::Name, "None");
	cls_StepBasic_OrganizationRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationRole::get_type_name, "None");
	cls_StepBasic_OrganizationRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationRole::get_type_descriptor, "None");
	cls_StepBasic_OrganizationRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationRole::*)() const ) &StepBasic_OrganizationRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Person.hxx
	py::class_<StepBasic_Person, opencascade::handle<StepBasic_Person>, Standard_Transient> cls_StepBasic_Person(mod, "StepBasic_Person", "None");
	cls_StepBasic_Person.def(py::init<>());
	cls_StepBasic_Person.def("Init", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Boolean, const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::Init, "None", py::arg("aId"), py::arg("hasAlastName"), py::arg("aLastName"), py::arg("hasAfirstName"), py::arg("aFirstName"), py::arg("hasAmiddleNames"), py::arg("aMiddleNames"), py::arg("hasAprefixTitles"), py::arg("aPrefixTitles"), py::arg("hasAsuffixTitles"), py::arg("aSuffixTitles"));
	cls_StepBasic_Person.def("SetId", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetId, "None", py::arg("aId"));
	cls_StepBasic_Person.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::Id, "None");
	cls_StepBasic_Person.def("SetLastName", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetLastName, "None", py::arg("aLastName"));
	cls_StepBasic_Person.def("UnSetLastName", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetLastName, "None");
	cls_StepBasic_Person.def("LastName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::LastName, "None");
	cls_StepBasic_Person.def("HasLastName", (Standard_Boolean (StepBasic_Person::*)() const ) &StepBasic_Person::HasLastName, "None");
	cls_StepBasic_Person.def("SetFirstName", (void (StepBasic_Person::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Person::SetFirstName, "None", py::arg("aFirstName"));
	cls_StepBasic_Person.def("UnSetFirstName", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetFirstName, "None");
	cls_StepBasic_Person.def("FirstName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::FirstName, "None");
	cls_StepBasic_Person.def("HasFirstName", (Standard_Boolean (StepBasic_Person::*)() const ) &StepBasic_Person::HasFirstName, "None");
	cls_StepBasic_Person.def("SetMiddleNames", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetMiddleNames, "None", py::arg("aMiddleNames"));
	cls_StepBasic_Person.def("UnSetMiddleNames", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetMiddleNames, "None");
	cls_StepBasic_Person.def("MiddleNames", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::MiddleNames, "None");
	cls_StepBasic_Person.def("HasMiddleNames", (Standard_Boolean (StepBasic_Person::*)() const ) &StepBasic_Person::HasMiddleNames, "None");
	cls_StepBasic_Person.def("MiddleNamesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const ) &StepBasic_Person::MiddleNamesValue, "None", py::arg("num"));
	cls_StepBasic_Person.def("NbMiddleNames", (Standard_Integer (StepBasic_Person::*)() const ) &StepBasic_Person::NbMiddleNames, "None");
	cls_StepBasic_Person.def("SetPrefixTitles", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetPrefixTitles, "None", py::arg("aPrefixTitles"));
	cls_StepBasic_Person.def("UnSetPrefixTitles", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetPrefixTitles, "None");
	cls_StepBasic_Person.def("PrefixTitles", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::PrefixTitles, "None");
	cls_StepBasic_Person.def("HasPrefixTitles", (Standard_Boolean (StepBasic_Person::*)() const ) &StepBasic_Person::HasPrefixTitles, "None");
	cls_StepBasic_Person.def("PrefixTitlesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const ) &StepBasic_Person::PrefixTitlesValue, "None", py::arg("num"));
	cls_StepBasic_Person.def("NbPrefixTitles", (Standard_Integer (StepBasic_Person::*)() const ) &StepBasic_Person::NbPrefixTitles, "None");
	cls_StepBasic_Person.def("SetSuffixTitles", (void (StepBasic_Person::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &StepBasic_Person::SetSuffixTitles, "None", py::arg("aSuffixTitles"));
	cls_StepBasic_Person.def("UnSetSuffixTitles", (void (StepBasic_Person::*)()) &StepBasic_Person::UnSetSuffixTitles, "None");
	cls_StepBasic_Person.def("SuffixTitles", (opencascade::handle<Interface_HArray1OfHAsciiString> (StepBasic_Person::*)() const ) &StepBasic_Person::SuffixTitles, "None");
	cls_StepBasic_Person.def("HasSuffixTitles", (Standard_Boolean (StepBasic_Person::*)() const ) &StepBasic_Person::HasSuffixTitles, "None");
	cls_StepBasic_Person.def("SuffixTitlesValue", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Person::*)(const Standard_Integer) const ) &StepBasic_Person::SuffixTitlesValue, "None", py::arg("num"));
	cls_StepBasic_Person.def("NbSuffixTitles", (Standard_Integer (StepBasic_Person::*)() const ) &StepBasic_Person::NbSuffixTitles, "None");
	cls_StepBasic_Person.def_static("get_type_name_", (const char * (*)()) &StepBasic_Person::get_type_name, "None");
	cls_StepBasic_Person.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Person::get_type_descriptor, "None");
	cls_StepBasic_Person.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Person::*)() const ) &StepBasic_Person::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PersonalAddress.hxx
	py::class_<StepBasic_PersonalAddress, opencascade::handle<StepBasic_PersonalAddress>, StepBasic_Address> cls_StepBasic_PersonalAddress(mod, "StepBasic_PersonalAddress", "None");
	cls_StepBasic_PersonalAddress.def(py::init<>());
	cls_StepBasic_PersonalAddress.def("Init", (void (StepBasic_PersonalAddress::*)(const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfPerson> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonalAddress::Init, "None", py::arg("hasAinternalLocation"), py::arg("aInternalLocation"), py::arg("hasAstreetNumber"), py::arg("aStreetNumber"), py::arg("hasAstreet"), py::arg("aStreet"), py::arg("hasApostalBox"), py::arg("aPostalBox"), py::arg("hasAtown"), py::arg("aTown"), py::arg("hasAregion"), py::arg("aRegion"), py::arg("hasApostalCode"), py::arg("aPostalCode"), py::arg("hasAcountry"), py::arg("aCountry"), py::arg("hasAfacsimileNumber"), py::arg("aFacsimileNumber"), py::arg("hasAtelephoneNumber"), py::arg("aTelephoneNumber"), py::arg("hasAelectronicMailAddress"), py::arg("aElectronicMailAddress"), py::arg("hasAtelexNumber"), py::arg("aTelexNumber"), py::arg("aPeople"), py::arg("aDescription"));
	cls_StepBasic_PersonalAddress.def("SetPeople", (void (StepBasic_PersonalAddress::*)(const opencascade::handle<StepBasic_HArray1OfPerson> &)) &StepBasic_PersonalAddress::SetPeople, "None", py::arg("aPeople"));
	cls_StepBasic_PersonalAddress.def("People", (opencascade::handle<StepBasic_HArray1OfPerson> (StepBasic_PersonalAddress::*)() const ) &StepBasic_PersonalAddress::People, "None");
	cls_StepBasic_PersonalAddress.def("PeopleValue", (opencascade::handle<StepBasic_Person> (StepBasic_PersonalAddress::*)(const Standard_Integer) const ) &StepBasic_PersonalAddress::PeopleValue, "None", py::arg("num"));
	cls_StepBasic_PersonalAddress.def("NbPeople", (Standard_Integer (StepBasic_PersonalAddress::*)() const ) &StepBasic_PersonalAddress::NbPeople, "None");
	cls_StepBasic_PersonalAddress.def("SetDescription", (void (StepBasic_PersonalAddress::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonalAddress::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_PersonalAddress.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_PersonalAddress::*)() const ) &StepBasic_PersonalAddress::Description, "None");
	cls_StepBasic_PersonalAddress.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonalAddress::get_type_name, "None");
	cls_StepBasic_PersonalAddress.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonalAddress::get_type_descriptor, "None");
	cls_StepBasic_PersonalAddress.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonalAddress::*)() const ) &StepBasic_PersonalAddress::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PersonAndOrganization.hxx
	py::class_<StepBasic_PersonAndOrganization, opencascade::handle<StepBasic_PersonAndOrganization>, Standard_Transient> cls_StepBasic_PersonAndOrganization(mod, "StepBasic_PersonAndOrganization", "None");
	cls_StepBasic_PersonAndOrganization.def(py::init<>());
	cls_StepBasic_PersonAndOrganization.def("Init", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Person> &, const opencascade::handle<StepBasic_Organization> &)) &StepBasic_PersonAndOrganization::Init, "None", py::arg("aThePerson"), py::arg("aTheOrganization"));
	cls_StepBasic_PersonAndOrganization.def("SetThePerson", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Person> &)) &StepBasic_PersonAndOrganization::SetThePerson, "None", py::arg("aThePerson"));
	cls_StepBasic_PersonAndOrganization.def("ThePerson", (opencascade::handle<StepBasic_Person> (StepBasic_PersonAndOrganization::*)() const ) &StepBasic_PersonAndOrganization::ThePerson, "None");
	cls_StepBasic_PersonAndOrganization.def("SetTheOrganization", (void (StepBasic_PersonAndOrganization::*)(const opencascade::handle<StepBasic_Organization> &)) &StepBasic_PersonAndOrganization::SetTheOrganization, "None", py::arg("aTheOrganization"));
	cls_StepBasic_PersonAndOrganization.def("TheOrganization", (opencascade::handle<StepBasic_Organization> (StepBasic_PersonAndOrganization::*)() const ) &StepBasic_PersonAndOrganization::TheOrganization, "None");
	cls_StepBasic_PersonAndOrganization.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonAndOrganization::get_type_name, "None");
	cls_StepBasic_PersonAndOrganization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonAndOrganization::get_type_descriptor, "None");
	cls_StepBasic_PersonAndOrganization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonAndOrganization::*)() const ) &StepBasic_PersonAndOrganization::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PersonAndOrganizationRole.hxx
	py::class_<StepBasic_PersonAndOrganizationRole, opencascade::handle<StepBasic_PersonAndOrganizationRole>, Standard_Transient> cls_StepBasic_PersonAndOrganizationRole(mod, "StepBasic_PersonAndOrganizationRole", "None");
	cls_StepBasic_PersonAndOrganizationRole.def(py::init<>());
	cls_StepBasic_PersonAndOrganizationRole.def("Init", (void (StepBasic_PersonAndOrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonAndOrganizationRole::Init, "None", py::arg("aName"));
	cls_StepBasic_PersonAndOrganizationRole.def("SetName", (void (StepBasic_PersonAndOrganizationRole::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_PersonAndOrganizationRole::SetName, "None", py::arg("aName"));
	cls_StepBasic_PersonAndOrganizationRole.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_PersonAndOrganizationRole::*)() const ) &StepBasic_PersonAndOrganizationRole::Name, "None");
	cls_StepBasic_PersonAndOrganizationRole.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonAndOrganizationRole::get_type_name, "None");
	cls_StepBasic_PersonAndOrganizationRole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonAndOrganizationRole::get_type_descriptor, "None");
	cls_StepBasic_PersonAndOrganizationRole.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonAndOrganizationRole::*)() const ) &StepBasic_PersonAndOrganizationRole::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PlaneAngleMeasureWithUnit.hxx
	py::class_<StepBasic_PlaneAngleMeasureWithUnit, opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_PlaneAngleMeasureWithUnit(mod, "StepBasic_PlaneAngleMeasureWithUnit", "None");
	cls_StepBasic_PlaneAngleMeasureWithUnit.def(py::init<>());
	cls_StepBasic_PlaneAngleMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_PlaneAngleMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_PlaneAngleMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PlaneAngleMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_PlaneAngleMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PlaneAngleMeasureWithUnit::*)() const ) &StepBasic_PlaneAngleMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PlaneAngleUnit.hxx
	py::class_<StepBasic_PlaneAngleUnit, opencascade::handle<StepBasic_PlaneAngleUnit>, StepBasic_NamedUnit> cls_StepBasic_PlaneAngleUnit(mod, "StepBasic_PlaneAngleUnit", "None");
	cls_StepBasic_PlaneAngleUnit.def(py::init<>());
	cls_StepBasic_PlaneAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_PlaneAngleUnit::get_type_name, "None");
	cls_StepBasic_PlaneAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PlaneAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_PlaneAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PlaneAngleUnit::*)() const ) &StepBasic_PlaneAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Product.hxx
	py::class_<StepBasic_Product, opencascade::handle<StepBasic_Product>, Standard_Transient> cls_StepBasic_Product(mod, "StepBasic_Product", "None");
	cls_StepBasic_Product.def(py::init<>());
	cls_StepBasic_Product.def("Init", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfProductContext> &)) &StepBasic_Product::Init, "None", py::arg("aId"), py::arg("aName"), py::arg("aDescription"), py::arg("aFrameOfReference"));
	cls_StepBasic_Product.def("SetId", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetId, "None", py::arg("aId"));
	cls_StepBasic_Product.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const ) &StepBasic_Product::Id, "None");
	cls_StepBasic_Product.def("SetName", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetName, "None", py::arg("aName"));
	cls_StepBasic_Product.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const ) &StepBasic_Product::Name, "None");
	cls_StepBasic_Product.def("SetDescription", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_Product.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const ) &StepBasic_Product::Description, "None");
	cls_StepBasic_Product.def("SetFrameOfReference", (void (StepBasic_Product::*)(const opencascade::handle<StepBasic_HArray1OfProductContext> &)) &StepBasic_Product::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
	cls_StepBasic_Product.def("FrameOfReference", (opencascade::handle<StepBasic_HArray1OfProductContext> (StepBasic_Product::*)() const ) &StepBasic_Product::FrameOfReference, "None");
	cls_StepBasic_Product.def("FrameOfReferenceValue", (opencascade::handle<StepBasic_ProductContext> (StepBasic_Product::*)(const Standard_Integer) const ) &StepBasic_Product::FrameOfReferenceValue, "None", py::arg("num"));
	cls_StepBasic_Product.def("NbFrameOfReference", (Standard_Integer (StepBasic_Product::*)() const ) &StepBasic_Product::NbFrameOfReference, "None");
	cls_StepBasic_Product.def_static("get_type_name_", (const char * (*)()) &StepBasic_Product::get_type_name, "None");
	cls_StepBasic_Product.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Product::get_type_descriptor, "None");
	cls_StepBasic_Product.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Product::*)() const ) &StepBasic_Product::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductCategory.hxx
	py::class_<StepBasic_ProductCategory, opencascade::handle<StepBasic_ProductCategory>, Standard_Transient> cls_StepBasic_ProductCategory(mod, "StepBasic_ProductCategory", "None");
	cls_StepBasic_ProductCategory.def(py::init<>());
	cls_StepBasic_ProductCategory.def("Init", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::Init, "None", py::arg("aName"), py::arg("hasAdescription"), py::arg("aDescription"));
	cls_StepBasic_ProductCategory.def("SetName", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::SetName, "None", py::arg("aName"));
	cls_StepBasic_ProductCategory.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategory::*)() const ) &StepBasic_ProductCategory::Name, "None");
	cls_StepBasic_ProductCategory.def("SetDescription", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_ProductCategory.def("UnSetDescription", (void (StepBasic_ProductCategory::*)()) &StepBasic_ProductCategory::UnSetDescription, "None");
	cls_StepBasic_ProductCategory.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategory::*)() const ) &StepBasic_ProductCategory::Description, "None");
	cls_StepBasic_ProductCategory.def("HasDescription", (Standard_Boolean (StepBasic_ProductCategory::*)() const ) &StepBasic_ProductCategory::HasDescription, "None");
	cls_StepBasic_ProductCategory.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductCategory::get_type_name, "None");
	cls_StepBasic_ProductCategory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductCategory::get_type_descriptor, "None");
	cls_StepBasic_ProductCategory.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductCategory::*)() const ) &StepBasic_ProductCategory::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductCategoryRelationship.hxx
	py::class_<StepBasic_ProductCategoryRelationship, opencascade::handle<StepBasic_ProductCategoryRelationship>, Standard_Transient> cls_StepBasic_ProductCategoryRelationship(mod, "StepBasic_ProductCategoryRelationship", "Representation of STEP entity ProductCategoryRelationship");
	cls_StepBasic_ProductCategoryRelationship.def(py::init<>());
	cls_StepBasic_ProductCategoryRelationship.def("Init", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductCategory> &, const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aCategory"), py::arg("aSubCategory"));
	cls_StepBasic_ProductCategoryRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::Name, "Returns field Name");
	cls_StepBasic_ProductCategoryRelationship.def("SetName", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategoryRelationship::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_ProductCategoryRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::Description, "Returns field Description");
	cls_StepBasic_ProductCategoryRelationship.def("SetDescription", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategoryRelationship::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ProductCategoryRelationship.def("HasDescription", (Standard_Boolean (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_ProductCategoryRelationship.def("Category", (opencascade::handle<StepBasic_ProductCategory> (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::Category, "Returns field Category");
	cls_StepBasic_ProductCategoryRelationship.def("SetCategory", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::SetCategory, "Set field Category", py::arg("Category"));
	cls_StepBasic_ProductCategoryRelationship.def("SubCategory", (opencascade::handle<StepBasic_ProductCategory> (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::SubCategory, "Returns field SubCategory");
	cls_StepBasic_ProductCategoryRelationship.def("SetSubCategory", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::SetSubCategory, "Set field SubCategory", py::arg("SubCategory"));
	cls_StepBasic_ProductCategoryRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductCategoryRelationship::get_type_name, "None");
	cls_StepBasic_ProductCategoryRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductCategoryRelationship::get_type_descriptor, "None");
	cls_StepBasic_ProductCategoryRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductCategoryRelationship::*)() const ) &StepBasic_ProductCategoryRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductConceptContext.hxx
	py::class_<StepBasic_ProductConceptContext, opencascade::handle<StepBasic_ProductConceptContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductConceptContext(mod, "StepBasic_ProductConceptContext", "Representation of STEP entity ProductConceptContext");
	cls_StepBasic_ProductConceptContext.def(py::init<>());
	cls_StepBasic_ProductConceptContext.def("Init", (void (StepBasic_ProductConceptContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductConceptContext::Init, "Initialize all fields (own and inherited)", py::arg("aApplicationContextElement_Name"), py::arg("aApplicationContextElement_FrameOfReference"), py::arg("aMarketSegmentType"));
	cls_StepBasic_ProductConceptContext.def("MarketSegmentType", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductConceptContext::*)() const ) &StepBasic_ProductConceptContext::MarketSegmentType, "Returns field MarketSegmentType");
	cls_StepBasic_ProductConceptContext.def("SetMarketSegmentType", (void (StepBasic_ProductConceptContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductConceptContext::SetMarketSegmentType, "Set field MarketSegmentType", py::arg("MarketSegmentType"));
	cls_StepBasic_ProductConceptContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductConceptContext::get_type_name, "None");
	cls_StepBasic_ProductConceptContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductConceptContext::get_type_descriptor, "None");
	cls_StepBasic_ProductConceptContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductConceptContext::*)() const ) &StepBasic_ProductConceptContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_MechanicalContext.hxx
	py::class_<StepBasic_MechanicalContext, opencascade::handle<StepBasic_MechanicalContext>, StepBasic_ProductContext> cls_StepBasic_MechanicalContext(mod, "StepBasic_MechanicalContext", "None");
	cls_StepBasic_MechanicalContext.def(py::init<>());
	cls_StepBasic_MechanicalContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_MechanicalContext::get_type_name, "None");
	cls_StepBasic_MechanicalContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MechanicalContext::get_type_descriptor, "None");
	cls_StepBasic_MechanicalContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MechanicalContext::*)() const ) &StepBasic_MechanicalContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinition.hxx
	py::class_<StepBasic_ProductDefinition, opencascade::handle<StepBasic_ProductDefinition>, Standard_Transient> cls_StepBasic_ProductDefinition(mod, "StepBasic_ProductDefinition", "None");
	cls_StepBasic_ProductDefinition.def(py::init<>());
	cls_StepBasic_ProductDefinition.def("Init", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinition::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aFormation"), py::arg("aFrameOfReference"));
	cls_StepBasic_ProductDefinition.def("SetId", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinition::SetId, "None", py::arg("aId"));
	cls_StepBasic_ProductDefinition.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinition::*)() const ) &StepBasic_ProductDefinition::Id, "None");
	cls_StepBasic_ProductDefinition.def("SetDescription", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinition::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_ProductDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinition::*)() const ) &StepBasic_ProductDefinition::Description, "None");
	cls_StepBasic_ProductDefinition.def("SetFormation", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinition::SetFormation, "None", py::arg("aFormation"));
	cls_StepBasic_ProductDefinition.def("Formation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinition::*)() const ) &StepBasic_ProductDefinition::Formation, "None");
	cls_StepBasic_ProductDefinition.def("SetFrameOfReference", (void (StepBasic_ProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinition::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
	cls_StepBasic_ProductDefinition.def("FrameOfReference", (opencascade::handle<StepBasic_ProductDefinitionContext> (StepBasic_ProductDefinition::*)() const ) &StepBasic_ProductDefinition::FrameOfReference, "None");
	cls_StepBasic_ProductDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinition::get_type_name, "None");
	cls_StepBasic_ProductDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinition::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinition::*)() const ) &StepBasic_ProductDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionContext.hxx
	py::class_<StepBasic_ProductDefinitionContext, opencascade::handle<StepBasic_ProductDefinitionContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductDefinitionContext(mod, "StepBasic_ProductDefinitionContext", "None");
	cls_StepBasic_ProductDefinitionContext.def(py::init<>());
	cls_StepBasic_ProductDefinitionContext.def("Init", (void (StepBasic_ProductDefinitionContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionContext::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"), py::arg("aLifeCycleStage"));
	cls_StepBasic_ProductDefinitionContext.def("SetLifeCycleStage", (void (StepBasic_ProductDefinitionContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionContext::SetLifeCycleStage, "None", py::arg("aLifeCycleStage"));
	cls_StepBasic_ProductDefinitionContext.def("LifeCycleStage", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionContext::*)() const ) &StepBasic_ProductDefinitionContext::LifeCycleStage, "None");
	cls_StepBasic_ProductDefinitionContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionContext::get_type_name, "None");
	cls_StepBasic_ProductDefinitionContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionContext::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionContext::*)() const ) &StepBasic_ProductDefinitionContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionEffectivity.hxx
	py::class_<StepBasic_ProductDefinitionEffectivity, opencascade::handle<StepBasic_ProductDefinitionEffectivity>, StepBasic_Effectivity> cls_StepBasic_ProductDefinitionEffectivity(mod, "StepBasic_ProductDefinitionEffectivity", "None");
	cls_StepBasic_ProductDefinitionEffectivity.def(py::init<>());
	cls_StepBasic_ProductDefinitionEffectivity.def("Init", (void (StepBasic_ProductDefinitionEffectivity::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &)) &StepBasic_ProductDefinitionEffectivity::Init, "None", py::arg("aId"), py::arg("aUsage"));
	cls_StepBasic_ProductDefinitionEffectivity.def("Usage", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepBasic_ProductDefinitionEffectivity::*)() const ) &StepBasic_ProductDefinitionEffectivity::Usage, "None");
	cls_StepBasic_ProductDefinitionEffectivity.def("SetUsage", (void (StepBasic_ProductDefinitionEffectivity::*)(const opencascade::handle<StepBasic_ProductDefinitionRelationship> &)) &StepBasic_ProductDefinitionEffectivity::SetUsage, "None", py::arg("aUsage"));
	cls_StepBasic_ProductDefinitionEffectivity.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionEffectivity::get_type_name, "None");
	cls_StepBasic_ProductDefinitionEffectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionEffectivity::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionEffectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionEffectivity::*)() const ) &StepBasic_ProductDefinitionEffectivity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionFormation.hxx
	py::class_<StepBasic_ProductDefinitionFormation, opencascade::handle<StepBasic_ProductDefinitionFormation>, Standard_Transient> cls_StepBasic_ProductDefinitionFormation(mod, "StepBasic_ProductDefinitionFormation", "None");
	cls_StepBasic_ProductDefinitionFormation.def(py::init<>());
	cls_StepBasic_ProductDefinitionFormation.def("Init", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Product> &)) &StepBasic_ProductDefinitionFormation::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aOfProduct"));
	cls_StepBasic_ProductDefinitionFormation.def("SetId", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormation::SetId, "None", py::arg("aId"));
	cls_StepBasic_ProductDefinitionFormation.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormation::*)() const ) &StepBasic_ProductDefinitionFormation::Id, "None");
	cls_StepBasic_ProductDefinitionFormation.def("SetDescription", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormation::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_ProductDefinitionFormation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormation::*)() const ) &StepBasic_ProductDefinitionFormation::Description, "None");
	cls_StepBasic_ProductDefinitionFormation.def("SetOfProduct", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<StepBasic_Product> &)) &StepBasic_ProductDefinitionFormation::SetOfProduct, "None", py::arg("aOfProduct"));
	cls_StepBasic_ProductDefinitionFormation.def("OfProduct", (opencascade::handle<StepBasic_Product> (StepBasic_ProductDefinitionFormation::*)() const ) &StepBasic_ProductDefinitionFormation::OfProduct, "None");
	cls_StepBasic_ProductDefinitionFormation.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormation::get_type_name, "None");
	cls_StepBasic_ProductDefinitionFormation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormation::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionFormation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormation::*)() const ) &StepBasic_ProductDefinitionFormation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionFormationRelationship.hxx
	py::class_<StepBasic_ProductDefinitionFormationRelationship, opencascade::handle<StepBasic_ProductDefinitionFormationRelationship>, Standard_Transient> cls_StepBasic_ProductDefinitionFormationRelationship(mod, "StepBasic_ProductDefinitionFormationRelationship", "Representation of STEP entity ProductDefinitionFormationRelationship");
	cls_StepBasic_ProductDefinitionFormationRelationship.def(py::init<>());
	cls_StepBasic_ProductDefinitionFormationRelationship.def("Init", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("aDescription"), py::arg("aRelatingProductDefinitionFormation"), py::arg("aRelatedProductDefinitionFormation"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::Id, "Returns field Id");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("SetId", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetId, "Set field Id", py::arg("Id"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::Name, "Returns field Name");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("SetName", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::Description, "Returns field Description");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("SetDescription", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def("RelatingProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::RelatingProductDefinitionFormation, "Returns field RelatingProductDefinitionFormation");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("SetRelatingProductDefinitionFormation", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::SetRelatingProductDefinitionFormation, "Set field RelatingProductDefinitionFormation", py::arg("RelatingProductDefinitionFormation"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def("RelatedProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::RelatedProductDefinitionFormation, "Returns field RelatedProductDefinitionFormation");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("SetRelatedProductDefinitionFormation", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::SetRelatedProductDefinitionFormation, "Set field RelatedProductDefinitionFormation", py::arg("RelatedProductDefinitionFormation"));
	cls_StepBasic_ProductDefinitionFormationRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormationRelationship::get_type_name, "None");
	cls_StepBasic_ProductDefinitionFormationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormationRelationship::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionFormationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormationRelationship::*)() const ) &StepBasic_ProductDefinitionFormationRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionFormationWithSpecifiedSource.hxx
	py::class_<StepBasic_ProductDefinitionFormationWithSpecifiedSource, opencascade::handle<StepBasic_ProductDefinitionFormationWithSpecifiedSource>, StepBasic_ProductDefinitionFormation> cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource(mod, "StepBasic_ProductDefinitionFormationWithSpecifiedSource", "None");
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def(py::init<>());
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("Init", (void (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Product> &, const StepBasic_Source)) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aOfProduct"), py::arg("aMakeOrBuy"));
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("SetMakeOrBuy", (void (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)(const StepBasic_Source)) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::SetMakeOrBuy, "None", py::arg("aMakeOrBuy"));
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("MakeOrBuy", (StepBasic_Source (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)() const ) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::MakeOrBuy, "None");
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::get_type_name, "None");
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionFormationWithSpecifiedSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormationWithSpecifiedSource::*)() const ) &StepBasic_ProductDefinitionFormationWithSpecifiedSource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionReference.hxx
	py::class_<StepBasic_ProductDefinitionReference, opencascade::handle<StepBasic_ProductDefinitionReference>, Standard_Transient> cls_StepBasic_ProductDefinitionReference(mod, "StepBasic_ProductDefinitionReference", "Representation of STEP entity Product_Definition_Reference");
	cls_StepBasic_ProductDefinitionReference.def(py::init<>());
	cls_StepBasic_ProductDefinitionReference.def("Init", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::Init, "Initialize all fields (own and inherited)", py::arg("theSource"), py::arg("theProductId"), py::arg("theProductDefinitionFormationId"), py::arg("theProductDefinitionId"), py::arg("theIdOwningOrganizationName"));
	cls_StepBasic_ProductDefinitionReference.def("Init", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::Init, "Initialize all fields (own and inherited)", py::arg("theSource"), py::arg("theProductId"), py::arg("theProductDefinitionFormationId"), py::arg("theProductDefinitionId"));
	cls_StepBasic_ProductDefinitionReference.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::Source, "Returns field Source");
	cls_StepBasic_ProductDefinitionReference.def("SetSource", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ProductDefinitionReference::SetSource, "Set field Source", py::arg("theSource"));
	cls_StepBasic_ProductDefinitionReference.def("ProductId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::ProductId, "Returns field ProductId");
	cls_StepBasic_ProductDefinitionReference.def("SetProductId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductId, "Set field ProductId", py::arg("theProductId"));
	cls_StepBasic_ProductDefinitionReference.def("ProductDefinitionFormationId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::ProductDefinitionFormationId, "Returns field ProductDefinitionFormationId");
	cls_StepBasic_ProductDefinitionReference.def("SetProductDefinitionFormationId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductDefinitionFormationId, "Set field ProductDefinitionFormationId", py::arg("theProductDefinitionFormationId"));
	cls_StepBasic_ProductDefinitionReference.def("ProductDefinitionId", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::ProductDefinitionId, "Returns field ProductDefinitionId");
	cls_StepBasic_ProductDefinitionReference.def("SetProductDefinitionId", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetProductDefinitionId, "Set field ProductDefinitionId", py::arg("theProductDefinitionId"));
	cls_StepBasic_ProductDefinitionReference.def("IdOwningOrganizationName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::IdOwningOrganizationName, "Returns field IdOwningOrganizationName");
	cls_StepBasic_ProductDefinitionReference.def("SetIdOwningOrganizationName", (void (StepBasic_ProductDefinitionReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionReference::SetIdOwningOrganizationName, "Set field IdOwningOrganizationName", py::arg("theIdOwningOrganizationName"));
	cls_StepBasic_ProductDefinitionReference.def("HasIdOwningOrganizationName", (Standard_Boolean (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::HasIdOwningOrganizationName, "Returns true if IdOwningOrganizationName exists");
	cls_StepBasic_ProductDefinitionReference.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionReference::get_type_name, "None");
	cls_StepBasic_ProductDefinitionReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionReference::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionReference::*)() const ) &StepBasic_ProductDefinitionReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionReferenceWithLocalRepresentation.hxx
	py::class_<StepBasic_ProductDefinitionReferenceWithLocalRepresentation, opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation>, StepBasic_ProductDefinition> cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation(mod, "StepBasic_ProductDefinitionReferenceWithLocalRepresentation", "None");
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def(py::init<>());
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("Init", (void (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepBasic_ExternalSource> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &)) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::Init, "None", py::arg("theSource"), py::arg("theId"), py::arg("theDescription"), py::arg("theFormation"), py::arg("theFrameOfReference"));
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)() const ) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::Source, "Returns field Source");
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("SetSource", (void (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::SetSource, "Set field Source", py::arg("theSource"));
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::get_type_name, "None");
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionReferenceWithLocalRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionReferenceWithLocalRepresentation::*)() const ) &StepBasic_ProductDefinitionReferenceWithLocalRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionRelationship.hxx
	py::class_<StepBasic_ProductDefinitionRelationship, opencascade::handle<StepBasic_ProductDefinitionRelationship>, Standard_Transient> cls_StepBasic_ProductDefinitionRelationship(mod, "StepBasic_ProductDefinitionRelationship", "Representation of STEP entity ProductDefinitionRelationship");
	cls_StepBasic_ProductDefinitionRelationship.def(py::init<>());
	cls_StepBasic_ProductDefinitionRelationship.def("Init", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingProductDefinition"), py::arg("aRelatedProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def("Init", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingProductDefinition"), py::arg("aRelatedProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::Id, "Returns field Id");
	cls_StepBasic_ProductDefinitionRelationship.def("SetId", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetId, "Set field Id", py::arg("Id"));
	cls_StepBasic_ProductDefinitionRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::Name, "Returns field Name");
	cls_StepBasic_ProductDefinitionRelationship.def("SetName", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetName, "Set field Name", py::arg("Name"));
	cls_StepBasic_ProductDefinitionRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::Description, "Returns field Description");
	cls_StepBasic_ProductDefinitionRelationship.def("SetDescription", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionRelationship::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_ProductDefinitionRelationship.def("HasDescription", (Standard_Boolean (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_ProductDefinitionRelationship.def("RelatingProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::RelatingProductDefinition, "Returns field RelatingProductDefinition");
	cls_StepBasic_ProductDefinitionRelationship.def("RelatingProductDefinitionAP242", (StepBasic_ProductDefinitionOrReference (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::RelatingProductDefinitionAP242, "Returns field RelatingProductDefinition in AP242");
	cls_StepBasic_ProductDefinitionRelationship.def("SetRelatingProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::SetRelatingProductDefinition, "Set field RelatingProductDefinition", py::arg("RelatingProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def("SetRelatingProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::SetRelatingProductDefinition, "Set field RelatingProductDefinition in AP242", py::arg("RelatingProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def("RelatedProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::RelatedProductDefinition, "Returns field RelatedProductDefinition");
	cls_StepBasic_ProductDefinitionRelationship.def("RelatedProductDefinitionAP242", (StepBasic_ProductDefinitionOrReference (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::RelatedProductDefinitionAP242, "Returns field RelatedProductDefinition in AP242");
	cls_StepBasic_ProductDefinitionRelationship.def("SetRelatedProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_ProductDefinitionRelationship::SetRelatedProductDefinition, "Set field RelatedProductDefinition", py::arg("RelatedProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def("SetRelatedProductDefinition", (void (StepBasic_ProductDefinitionRelationship::*)(const StepBasic_ProductDefinitionOrReference &)) &StepBasic_ProductDefinitionRelationship::SetRelatedProductDefinition, "Set field RelatedProductDefinition in AP242", py::arg("RelatedProductDefinition"));
	cls_StepBasic_ProductDefinitionRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionRelationship::get_type_name, "None");
	cls_StepBasic_ProductDefinitionRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionRelationship::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionRelationship::*)() const ) &StepBasic_ProductDefinitionRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionWithAssociatedDocuments.hxx
	py::class_<StepBasic_ProductDefinitionWithAssociatedDocuments, opencascade::handle<StepBasic_ProductDefinitionWithAssociatedDocuments>, StepBasic_ProductDefinition> cls_StepBasic_ProductDefinitionWithAssociatedDocuments(mod, "StepBasic_ProductDefinitionWithAssociatedDocuments", "None");
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def(py::init<>());
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("Init", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &, const opencascade::handle<StepBasic_HArray1OfDocument> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aFormation"), py::arg("aFrame"), py::arg("aDocIds"));
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DocIds", (opencascade::handle<StepBasic_HArray1OfDocument> (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const ) &StepBasic_ProductDefinitionWithAssociatedDocuments::DocIds, "None");
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("SetDocIds", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const opencascade::handle<StepBasic_HArray1OfDocument> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::SetDocIds, "None", py::arg("DocIds"));
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("NbDocIds", (Standard_Integer (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const ) &StepBasic_ProductDefinitionWithAssociatedDocuments::NbDocIds, "None");
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DocIdsValue", (opencascade::handle<StepBasic_Document> (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const Standard_Integer) const ) &StepBasic_ProductDefinitionWithAssociatedDocuments::DocIdsValue, "None", py::arg("num"));
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("SetDocIdsValue", (void (StepBasic_ProductDefinitionWithAssociatedDocuments::*)(const Standard_Integer, const opencascade::handle<StepBasic_Document> &)) &StepBasic_ProductDefinitionWithAssociatedDocuments::SetDocIdsValue, "None", py::arg("num"), py::arg("adoc"));
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionWithAssociatedDocuments::get_type_name, "None");
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionWithAssociatedDocuments::get_type_descriptor, "None");
	cls_StepBasic_ProductDefinitionWithAssociatedDocuments.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionWithAssociatedDocuments::*)() const ) &StepBasic_ProductDefinitionWithAssociatedDocuments::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductRelatedProductCategory.hxx
	py::class_<StepBasic_ProductRelatedProductCategory, opencascade::handle<StepBasic_ProductRelatedProductCategory>, StepBasic_ProductCategory> cls_StepBasic_ProductRelatedProductCategory(mod, "StepBasic_ProductRelatedProductCategory", "None");
	cls_StepBasic_ProductRelatedProductCategory.def(py::init<>());
	cls_StepBasic_ProductRelatedProductCategory.def("Init", (void (StepBasic_ProductRelatedProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfProduct> &)) &StepBasic_ProductRelatedProductCategory::Init, "None", py::arg("aName"), py::arg("hasAdescription"), py::arg("aDescription"), py::arg("aProducts"));
	cls_StepBasic_ProductRelatedProductCategory.def("SetProducts", (void (StepBasic_ProductRelatedProductCategory::*)(const opencascade::handle<StepBasic_HArray1OfProduct> &)) &StepBasic_ProductRelatedProductCategory::SetProducts, "None", py::arg("aProducts"));
	cls_StepBasic_ProductRelatedProductCategory.def("Products", (opencascade::handle<StepBasic_HArray1OfProduct> (StepBasic_ProductRelatedProductCategory::*)() const ) &StepBasic_ProductRelatedProductCategory::Products, "None");
	cls_StepBasic_ProductRelatedProductCategory.def("ProductsValue", (opencascade::handle<StepBasic_Product> (StepBasic_ProductRelatedProductCategory::*)(const Standard_Integer) const ) &StepBasic_ProductRelatedProductCategory::ProductsValue, "None", py::arg("num"));
	cls_StepBasic_ProductRelatedProductCategory.def("NbProducts", (Standard_Integer (StepBasic_ProductRelatedProductCategory::*)() const ) &StepBasic_ProductRelatedProductCategory::NbProducts, "None");
	cls_StepBasic_ProductRelatedProductCategory.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductRelatedProductCategory::get_type_name, "None");
	cls_StepBasic_ProductRelatedProductCategory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductRelatedProductCategory::get_type_descriptor, "None");
	cls_StepBasic_ProductRelatedProductCategory.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductRelatedProductCategory::*)() const ) &StepBasic_ProductRelatedProductCategory::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductType.hxx
	py::class_<StepBasic_ProductType, opencascade::handle<StepBasic_ProductType>, StepBasic_ProductRelatedProductCategory> cls_StepBasic_ProductType(mod, "StepBasic_ProductType", "None");
	cls_StepBasic_ProductType.def(py::init<>());
	cls_StepBasic_ProductType.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductType::get_type_name, "None");
	cls_StepBasic_ProductType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductType::get_type_descriptor, "None");
	cls_StepBasic_ProductType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductType::*)() const ) &StepBasic_ProductType::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_RatioMeasureWithUnit.hxx
	py::class_<StepBasic_RatioMeasureWithUnit, opencascade::handle<StepBasic_RatioMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_RatioMeasureWithUnit(mod, "StepBasic_RatioMeasureWithUnit", "None");
	cls_StepBasic_RatioMeasureWithUnit.def(py::init<>());
	cls_StepBasic_RatioMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_RatioMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_RatioMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_RatioMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_RatioMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_RatioMeasureWithUnit::*)() const ) &StepBasic_RatioMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_RoleAssociation.hxx
	py::class_<StepBasic_RoleAssociation, opencascade::handle<StepBasic_RoleAssociation>, Standard_Transient> cls_StepBasic_RoleAssociation(mod, "StepBasic_RoleAssociation", "Representation of STEP entity RoleAssociation");
	cls_StepBasic_RoleAssociation.def(py::init<>());
	cls_StepBasic_RoleAssociation.def("Init", (void (StepBasic_RoleAssociation::*)(const opencascade::handle<StepBasic_ObjectRole> &, const StepBasic_RoleSelect &)) &StepBasic_RoleAssociation::Init, "Initialize all fields (own and inherited)", py::arg("aRole"), py::arg("aItemWithRole"));
	cls_StepBasic_RoleAssociation.def("Role", (opencascade::handle<StepBasic_ObjectRole> (StepBasic_RoleAssociation::*)() const ) &StepBasic_RoleAssociation::Role, "Returns field Role");
	cls_StepBasic_RoleAssociation.def("SetRole", (void (StepBasic_RoleAssociation::*)(const opencascade::handle<StepBasic_ObjectRole> &)) &StepBasic_RoleAssociation::SetRole, "Set field Role", py::arg("Role"));
	cls_StepBasic_RoleAssociation.def("ItemWithRole", (StepBasic_RoleSelect (StepBasic_RoleAssociation::*)() const ) &StepBasic_RoleAssociation::ItemWithRole, "Returns field ItemWithRole");
	cls_StepBasic_RoleAssociation.def("SetItemWithRole", (void (StepBasic_RoleAssociation::*)(const StepBasic_RoleSelect &)) &StepBasic_RoleAssociation::SetItemWithRole, "Set field ItemWithRole", py::arg("ItemWithRole"));
	cls_StepBasic_RoleAssociation.def_static("get_type_name_", (const char * (*)()) &StepBasic_RoleAssociation::get_type_name, "None");
	cls_StepBasic_RoleAssociation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_RoleAssociation::get_type_descriptor, "None");
	cls_StepBasic_RoleAssociation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_RoleAssociation::*)() const ) &StepBasic_RoleAssociation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SecurityClassification.hxx
	py::class_<StepBasic_SecurityClassification, opencascade::handle<StepBasic_SecurityClassification>, Standard_Transient> cls_StepBasic_SecurityClassification(mod, "StepBasic_SecurityClassification", "None");
	cls_StepBasic_SecurityClassification.def(py::init<>());
	cls_StepBasic_SecurityClassification.def("Init", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_SecurityClassificationLevel> &)) &StepBasic_SecurityClassification::Init, "None", py::arg("aName"), py::arg("aPurpose"), py::arg("aSecurityLevel"));
	cls_StepBasic_SecurityClassification.def("SetName", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassification::SetName, "None", py::arg("aName"));
	cls_StepBasic_SecurityClassification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SecurityClassification::*)() const ) &StepBasic_SecurityClassification::Name, "None");
	cls_StepBasic_SecurityClassification.def("SetPurpose", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassification::SetPurpose, "None", py::arg("aPurpose"));
	cls_StepBasic_SecurityClassification.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SecurityClassification::*)() const ) &StepBasic_SecurityClassification::Purpose, "None");
	cls_StepBasic_SecurityClassification.def("SetSecurityLevel", (void (StepBasic_SecurityClassification::*)(const opencascade::handle<StepBasic_SecurityClassificationLevel> &)) &StepBasic_SecurityClassification::SetSecurityLevel, "None", py::arg("aSecurityLevel"));
	cls_StepBasic_SecurityClassification.def("SecurityLevel", (opencascade::handle<StepBasic_SecurityClassificationLevel> (StepBasic_SecurityClassification::*)() const ) &StepBasic_SecurityClassification::SecurityLevel, "None");
	cls_StepBasic_SecurityClassification.def_static("get_type_name_", (const char * (*)()) &StepBasic_SecurityClassification::get_type_name, "None");
	cls_StepBasic_SecurityClassification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SecurityClassification::get_type_descriptor, "None");
	cls_StepBasic_SecurityClassification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SecurityClassification::*)() const ) &StepBasic_SecurityClassification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SecurityClassificationLevel.hxx
	py::class_<StepBasic_SecurityClassificationLevel, opencascade::handle<StepBasic_SecurityClassificationLevel>, Standard_Transient> cls_StepBasic_SecurityClassificationLevel(mod, "StepBasic_SecurityClassificationLevel", "None");
	cls_StepBasic_SecurityClassificationLevel.def(py::init<>());
	cls_StepBasic_SecurityClassificationLevel.def("Init", (void (StepBasic_SecurityClassificationLevel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassificationLevel::Init, "None", py::arg("aName"));
	cls_StepBasic_SecurityClassificationLevel.def("SetName", (void (StepBasic_SecurityClassificationLevel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_SecurityClassificationLevel::SetName, "None", py::arg("aName"));
	cls_StepBasic_SecurityClassificationLevel.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SecurityClassificationLevel::*)() const ) &StepBasic_SecurityClassificationLevel::Name, "None");
	cls_StepBasic_SecurityClassificationLevel.def_static("get_type_name_", (const char * (*)()) &StepBasic_SecurityClassificationLevel::get_type_name, "None");
	cls_StepBasic_SecurityClassificationLevel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SecurityClassificationLevel::get_type_descriptor, "None");
	cls_StepBasic_SecurityClassificationLevel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SecurityClassificationLevel::*)() const ) &StepBasic_SecurityClassificationLevel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnit.hxx
	py::class_<StepBasic_SiUnit, opencascade::handle<StepBasic_SiUnit>, StepBasic_NamedUnit> cls_StepBasic_SiUnit(mod, "StepBasic_SiUnit", "None");
	cls_StepBasic_SiUnit.def(py::init<>());
	cls_StepBasic_SiUnit.def("Init", (void (StepBasic_SiUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnit.def("SetPrefix", (void (StepBasic_SiUnit::*)(const StepBasic_SiPrefix)) &StepBasic_SiUnit::SetPrefix, "None", py::arg("aPrefix"));
	cls_StepBasic_SiUnit.def("UnSetPrefix", (void (StepBasic_SiUnit::*)()) &StepBasic_SiUnit::UnSetPrefix, "None");
	cls_StepBasic_SiUnit.def("Prefix", (StepBasic_SiPrefix (StepBasic_SiUnit::*)() const ) &StepBasic_SiUnit::Prefix, "None");
	cls_StepBasic_SiUnit.def("HasPrefix", (Standard_Boolean (StepBasic_SiUnit::*)() const ) &StepBasic_SiUnit::HasPrefix, "None");
	cls_StepBasic_SiUnit.def("SetName", (void (StepBasic_SiUnit::*)(const StepBasic_SiUnitName)) &StepBasic_SiUnit::SetName, "None", py::arg("aName"));
	cls_StepBasic_SiUnit.def("Name", (StepBasic_SiUnitName (StepBasic_SiUnit::*)() const ) &StepBasic_SiUnit::Name, "None");
	cls_StepBasic_SiUnit.def("SetDimensions", (void (StepBasic_SiUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &)) &StepBasic_SiUnit::SetDimensions, "None", py::arg("aDimensions"));
	cls_StepBasic_SiUnit.def("Dimensions", (opencascade::handle<StepBasic_DimensionalExponents> (StepBasic_SiUnit::*)() const ) &StepBasic_SiUnit::Dimensions, "None");
	cls_StepBasic_SiUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnit::get_type_name, "None");
	cls_StepBasic_SiUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnit::*)() const ) &StepBasic_SiUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndAreaUnit.hxx
	py::class_<StepBasic_SiUnitAndAreaUnit, opencascade::handle<StepBasic_SiUnitAndAreaUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndAreaUnit(mod, "StepBasic_SiUnitAndAreaUnit", "None");
	cls_StepBasic_SiUnitAndAreaUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndAreaUnit.def("SetAreaUnit", (void (StepBasic_SiUnitAndAreaUnit::*)(const opencascade::handle<StepBasic_AreaUnit> &)) &StepBasic_SiUnitAndAreaUnit::SetAreaUnit, "None", py::arg("anAreaUnit"));
	cls_StepBasic_SiUnitAndAreaUnit.def("AreaUnit", (opencascade::handle<StepBasic_AreaUnit> (StepBasic_SiUnitAndAreaUnit::*)() const ) &StepBasic_SiUnitAndAreaUnit::AreaUnit, "None");
	cls_StepBasic_SiUnitAndAreaUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndAreaUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndAreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndAreaUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndAreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndAreaUnit::*)() const ) &StepBasic_SiUnitAndAreaUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndLengthUnit.hxx
	py::class_<StepBasic_SiUnitAndLengthUnit, opencascade::handle<StepBasic_SiUnitAndLengthUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndLengthUnit(mod, "StepBasic_SiUnitAndLengthUnit", "None");
	cls_StepBasic_SiUnitAndLengthUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndLengthUnit.def("Init", (void (StepBasic_SiUnitAndLengthUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndLengthUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndLengthUnit.def("SetLengthUnit", (void (StepBasic_SiUnitAndLengthUnit::*)(const opencascade::handle<StepBasic_LengthUnit> &)) &StepBasic_SiUnitAndLengthUnit::SetLengthUnit, "None", py::arg("aLengthUnit"));
	cls_StepBasic_SiUnitAndLengthUnit.def("LengthUnit", (opencascade::handle<StepBasic_LengthUnit> (StepBasic_SiUnitAndLengthUnit::*)() const ) &StepBasic_SiUnitAndLengthUnit::LengthUnit, "None");
	cls_StepBasic_SiUnitAndLengthUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndLengthUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndLengthUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndLengthUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndLengthUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndLengthUnit::*)() const ) &StepBasic_SiUnitAndLengthUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndMassUnit.hxx
	py::class_<StepBasic_SiUnitAndMassUnit, opencascade::handle<StepBasic_SiUnitAndMassUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndMassUnit(mod, "StepBasic_SiUnitAndMassUnit", "None");
	cls_StepBasic_SiUnitAndMassUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndMassUnit.def("Init", (void (StepBasic_SiUnitAndMassUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndMassUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndMassUnit.def("SetMassUnit", (void (StepBasic_SiUnitAndMassUnit::*)(const opencascade::handle<StepBasic_MassUnit> &)) &StepBasic_SiUnitAndMassUnit::SetMassUnit, "None", py::arg("aMassUnit"));
	cls_StepBasic_SiUnitAndMassUnit.def("MassUnit", (opencascade::handle<StepBasic_MassUnit> (StepBasic_SiUnitAndMassUnit::*)() const ) &StepBasic_SiUnitAndMassUnit::MassUnit, "None");
	cls_StepBasic_SiUnitAndMassUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndMassUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndMassUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndMassUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndMassUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndMassUnit::*)() const ) &StepBasic_SiUnitAndMassUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndPlaneAngleUnit.hxx
	py::class_<StepBasic_SiUnitAndPlaneAngleUnit, opencascade::handle<StepBasic_SiUnitAndPlaneAngleUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndPlaneAngleUnit(mod, "StepBasic_SiUnitAndPlaneAngleUnit", "None");
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def("Init", (void (StepBasic_SiUnitAndPlaneAngleUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndPlaneAngleUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def("SetPlaneAngleUnit", (void (StepBasic_SiUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_PlaneAngleUnit> &)) &StepBasic_SiUnitAndPlaneAngleUnit::SetPlaneAngleUnit, "None", py::arg("aPlaneAngleUnit"));
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def("PlaneAngleUnit", (opencascade::handle<StepBasic_PlaneAngleUnit> (StepBasic_SiUnitAndPlaneAngleUnit::*)() const ) &StepBasic_SiUnitAndPlaneAngleUnit::PlaneAngleUnit, "None");
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndPlaneAngleUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndPlaneAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndPlaneAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndPlaneAngleUnit::*)() const ) &StepBasic_SiUnitAndPlaneAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndRatioUnit.hxx
	py::class_<StepBasic_SiUnitAndRatioUnit, opencascade::handle<StepBasic_SiUnitAndRatioUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndRatioUnit(mod, "StepBasic_SiUnitAndRatioUnit", "None");
	cls_StepBasic_SiUnitAndRatioUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndRatioUnit.def("Init", (void (StepBasic_SiUnitAndRatioUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndRatioUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndRatioUnit.def("SetRatioUnit", (void (StepBasic_SiUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_RatioUnit> &)) &StepBasic_SiUnitAndRatioUnit::SetRatioUnit, "None", py::arg("aRatioUnit"));
	cls_StepBasic_SiUnitAndRatioUnit.def("RatioUnit", (opencascade::handle<StepBasic_RatioUnit> (StepBasic_SiUnitAndRatioUnit::*)() const ) &StepBasic_SiUnitAndRatioUnit::RatioUnit, "None");
	cls_StepBasic_SiUnitAndRatioUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndRatioUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndRatioUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndRatioUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndRatioUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndRatioUnit::*)() const ) &StepBasic_SiUnitAndRatioUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndSolidAngleUnit.hxx
	py::class_<StepBasic_SiUnitAndSolidAngleUnit, opencascade::handle<StepBasic_SiUnitAndSolidAngleUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndSolidAngleUnit(mod, "StepBasic_SiUnitAndSolidAngleUnit", "None");
	cls_StepBasic_SiUnitAndSolidAngleUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndSolidAngleUnit.def("Init", (void (StepBasic_SiUnitAndSolidAngleUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndSolidAngleUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndSolidAngleUnit.def("SetSolidAngleUnit", (void (StepBasic_SiUnitAndSolidAngleUnit::*)(const opencascade::handle<StepBasic_SolidAngleUnit> &)) &StepBasic_SiUnitAndSolidAngleUnit::SetSolidAngleUnit, "None", py::arg("aSolidAngleUnit"));
	cls_StepBasic_SiUnitAndSolidAngleUnit.def("SolidAngleUnit", (opencascade::handle<StepBasic_SolidAngleUnit> (StepBasic_SiUnitAndSolidAngleUnit::*)() const ) &StepBasic_SiUnitAndSolidAngleUnit::SolidAngleUnit, "None");
	cls_StepBasic_SiUnitAndSolidAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndSolidAngleUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndSolidAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndSolidAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndSolidAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndSolidAngleUnit::*)() const ) &StepBasic_SiUnitAndSolidAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndThermodynamicTemperatureUnit.hxx
	py::class_<StepBasic_SiUnitAndThermodynamicTemperatureUnit, opencascade::handle<StepBasic_SiUnitAndThermodynamicTemperatureUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit(mod, "StepBasic_SiUnitAndThermodynamicTemperatureUnit", "None");
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def("Init", (void (StepBasic_SiUnitAndThermodynamicTemperatureUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def("SetThermodynamicTemperatureUnit", (void (StepBasic_SiUnitAndThermodynamicTemperatureUnit::*)(const opencascade::handle<StepBasic_ThermodynamicTemperatureUnit> &)) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::SetThermodynamicTemperatureUnit, "None", py::arg("aThermodynamicTemperatureUnit"));
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def("ThermodynamicTemperatureUnit", (opencascade::handle<StepBasic_ThermodynamicTemperatureUnit> (StepBasic_SiUnitAndThermodynamicTemperatureUnit::*)() const ) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::ThermodynamicTemperatureUnit, "None");
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndThermodynamicTemperatureUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndThermodynamicTemperatureUnit::*)() const ) &StepBasic_SiUnitAndThermodynamicTemperatureUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndTimeUnit.hxx
	py::class_<StepBasic_SiUnitAndTimeUnit, opencascade::handle<StepBasic_SiUnitAndTimeUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndTimeUnit(mod, "StepBasic_SiUnitAndTimeUnit", "None");
	cls_StepBasic_SiUnitAndTimeUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndTimeUnit.def("Init", (void (StepBasic_SiUnitAndTimeUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndTimeUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
	cls_StepBasic_SiUnitAndTimeUnit.def("SetTimeUnit", (void (StepBasic_SiUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_TimeUnit> &)) &StepBasic_SiUnitAndTimeUnit::SetTimeUnit, "None", py::arg("aTimeUnit"));
	cls_StepBasic_SiUnitAndTimeUnit.def("TimeUnit", (opencascade::handle<StepBasic_TimeUnit> (StepBasic_SiUnitAndTimeUnit::*)() const ) &StepBasic_SiUnitAndTimeUnit::TimeUnit, "None");
	cls_StepBasic_SiUnitAndTimeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndTimeUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndTimeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndTimeUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndTimeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndTimeUnit::*)() const ) &StepBasic_SiUnitAndTimeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SiUnitAndVolumeUnit.hxx
	py::class_<StepBasic_SiUnitAndVolumeUnit, opencascade::handle<StepBasic_SiUnitAndVolumeUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndVolumeUnit(mod, "StepBasic_SiUnitAndVolumeUnit", "None");
	cls_StepBasic_SiUnitAndVolumeUnit.def(py::init<>());
	cls_StepBasic_SiUnitAndVolumeUnit.def("SetVolumeUnit", (void (StepBasic_SiUnitAndVolumeUnit::*)(const opencascade::handle<StepBasic_VolumeUnit> &)) &StepBasic_SiUnitAndVolumeUnit::SetVolumeUnit, "None", py::arg("aVolumeUnit"));
	cls_StepBasic_SiUnitAndVolumeUnit.def("VolumeUnit", (opencascade::handle<StepBasic_VolumeUnit> (StepBasic_SiUnitAndVolumeUnit::*)() const ) &StepBasic_SiUnitAndVolumeUnit::VolumeUnit, "None");
	cls_StepBasic_SiUnitAndVolumeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndVolumeUnit::get_type_name, "None");
	cls_StepBasic_SiUnitAndVolumeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndVolumeUnit::get_type_descriptor, "None");
	cls_StepBasic_SiUnitAndVolumeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndVolumeUnit::*)() const ) &StepBasic_SiUnitAndVolumeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SolidAngleMeasureWithUnit.hxx
	py::class_<StepBasic_SolidAngleMeasureWithUnit, opencascade::handle<StepBasic_SolidAngleMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_SolidAngleMeasureWithUnit(mod, "StepBasic_SolidAngleMeasureWithUnit", "None");
	cls_StepBasic_SolidAngleMeasureWithUnit.def(py::init<>());
	cls_StepBasic_SolidAngleMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SolidAngleMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_SolidAngleMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SolidAngleMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_SolidAngleMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SolidAngleMeasureWithUnit::*)() const ) &StepBasic_SolidAngleMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SolidAngleUnit.hxx
	py::class_<StepBasic_SolidAngleUnit, opencascade::handle<StepBasic_SolidAngleUnit>, StepBasic_NamedUnit> cls_StepBasic_SolidAngleUnit(mod, "StepBasic_SolidAngleUnit", "None");
	cls_StepBasic_SolidAngleUnit.def(py::init<>());
	cls_StepBasic_SolidAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SolidAngleUnit::get_type_name, "None");
	cls_StepBasic_SolidAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SolidAngleUnit::get_type_descriptor, "None");
	cls_StepBasic_SolidAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SolidAngleUnit::*)() const ) &StepBasic_SolidAngleUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ThermodynamicTemperatureUnit.hxx
	py::class_<StepBasic_ThermodynamicTemperatureUnit, opencascade::handle<StepBasic_ThermodynamicTemperatureUnit>, StepBasic_NamedUnit> cls_StepBasic_ThermodynamicTemperatureUnit(mod, "StepBasic_ThermodynamicTemperatureUnit", "Representation of STEP entity ThermodynamicTemperatureUnit");
	cls_StepBasic_ThermodynamicTemperatureUnit.def(py::init<>());
	cls_StepBasic_ThermodynamicTemperatureUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ThermodynamicTemperatureUnit::get_type_name, "None");
	cls_StepBasic_ThermodynamicTemperatureUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ThermodynamicTemperatureUnit::get_type_descriptor, "None");
	cls_StepBasic_ThermodynamicTemperatureUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ThermodynamicTemperatureUnit::*)() const ) &StepBasic_ThermodynamicTemperatureUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_UncertaintyMeasureWithUnit.hxx
	py::class_<StepBasic_UncertaintyMeasureWithUnit, opencascade::handle<StepBasic_UncertaintyMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_UncertaintyMeasureWithUnit(mod, "StepBasic_UncertaintyMeasureWithUnit", "None");
	cls_StepBasic_UncertaintyMeasureWithUnit.def(py::init<>());
	cls_StepBasic_UncertaintyMeasureWithUnit.def("Init", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::Init, "None", py::arg("aValueComponent"), py::arg("aUnitComponent"), py::arg("aName"), py::arg("aDescription"));
	cls_StepBasic_UncertaintyMeasureWithUnit.def("SetName", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::SetName, "None", py::arg("aName"));
	cls_StepBasic_UncertaintyMeasureWithUnit.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_UncertaintyMeasureWithUnit::*)() const ) &StepBasic_UncertaintyMeasureWithUnit::Name, "None");
	cls_StepBasic_UncertaintyMeasureWithUnit.def("SetDescription", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::SetDescription, "None", py::arg("aDescription"));
	cls_StepBasic_UncertaintyMeasureWithUnit.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_UncertaintyMeasureWithUnit::*)() const ) &StepBasic_UncertaintyMeasureWithUnit::Description, "None");
	cls_StepBasic_UncertaintyMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_UncertaintyMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_UncertaintyMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_UncertaintyMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_UncertaintyMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_UncertaintyMeasureWithUnit::*)() const ) &StepBasic_UncertaintyMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_VersionedActionRequest.hxx
	py::class_<StepBasic_VersionedActionRequest, opencascade::handle<StepBasic_VersionedActionRequest>, Standard_Transient> cls_StepBasic_VersionedActionRequest(mod, "StepBasic_VersionedActionRequest", "Representation of STEP entity VersionedActionRequest");
	cls_StepBasic_VersionedActionRequest.def(py::init<>());
	cls_StepBasic_VersionedActionRequest.def("Init", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aVersion"), py::arg("aPurpose"), py::arg("hasDescription"), py::arg("aDescription"));
	cls_StepBasic_VersionedActionRequest.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::Id, "Returns field Id");
	cls_StepBasic_VersionedActionRequest.def("SetId", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetId, "Set field Id", py::arg("Id"));
	cls_StepBasic_VersionedActionRequest.def("Version", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::Version, "Returns field Version");
	cls_StepBasic_VersionedActionRequest.def("SetVersion", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetVersion, "Set field Version", py::arg("Version"));
	cls_StepBasic_VersionedActionRequest.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::Purpose, "Returns field Purpose");
	cls_StepBasic_VersionedActionRequest.def("SetPurpose", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetPurpose, "Set field Purpose", py::arg("Purpose"));
	cls_StepBasic_VersionedActionRequest.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::Description, "Returns field Description");
	cls_StepBasic_VersionedActionRequest.def("SetDescription", (void (StepBasic_VersionedActionRequest::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_VersionedActionRequest::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepBasic_VersionedActionRequest.def("HasDescription", (Standard_Boolean (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::HasDescription, "Returns True if optional field Description is defined");
	cls_StepBasic_VersionedActionRequest.def_static("get_type_name_", (const char * (*)()) &StepBasic_VersionedActionRequest::get_type_name, "None");
	cls_StepBasic_VersionedActionRequest.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_VersionedActionRequest::get_type_descriptor, "None");
	cls_StepBasic_VersionedActionRequest.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_VersionedActionRequest::*)() const ) &StepBasic_VersionedActionRequest::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_WeekOfYearAndDayDate.hxx
	py::class_<StepBasic_WeekOfYearAndDayDate, opencascade::handle<StepBasic_WeekOfYearAndDayDate>, StepBasic_Date> cls_StepBasic_WeekOfYearAndDayDate(mod, "StepBasic_WeekOfYearAndDayDate", "None");
	cls_StepBasic_WeekOfYearAndDayDate.def(py::init<>());
	cls_StepBasic_WeekOfYearAndDayDate.def("Init", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::Init, "None", py::arg("aYearComponent"), py::arg("aWeekComponent"), py::arg("hasAdayComponent"), py::arg("aDayComponent"));
	cls_StepBasic_WeekOfYearAndDayDate.def("SetWeekComponent", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::SetWeekComponent, "None", py::arg("aWeekComponent"));
	cls_StepBasic_WeekOfYearAndDayDate.def("WeekComponent", (Standard_Integer (StepBasic_WeekOfYearAndDayDate::*)() const ) &StepBasic_WeekOfYearAndDayDate::WeekComponent, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def("SetDayComponent", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::SetDayComponent, "None", py::arg("aDayComponent"));
	cls_StepBasic_WeekOfYearAndDayDate.def("UnSetDayComponent", (void (StepBasic_WeekOfYearAndDayDate::*)()) &StepBasic_WeekOfYearAndDayDate::UnSetDayComponent, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def("DayComponent", (Standard_Integer (StepBasic_WeekOfYearAndDayDate::*)() const ) &StepBasic_WeekOfYearAndDayDate::DayComponent, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def("HasDayComponent", (Standard_Boolean (StepBasic_WeekOfYearAndDayDate::*)() const ) &StepBasic_WeekOfYearAndDayDate::HasDayComponent, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def_static("get_type_name_", (const char * (*)()) &StepBasic_WeekOfYearAndDayDate::get_type_name, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_WeekOfYearAndDayDate::get_type_descriptor, "None");
	cls_StepBasic_WeekOfYearAndDayDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_WeekOfYearAndDayDate::*)() const ) &StepBasic_WeekOfYearAndDayDate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ApprovalAssignment.hxx
	py::class_<StepBasic_ApprovalAssignment, opencascade::handle<StepBasic_ApprovalAssignment>, Standard_Transient> cls_StepBasic_ApprovalAssignment(mod, "StepBasic_ApprovalAssignment", "None");
	cls_StepBasic_ApprovalAssignment.def("Init", (void (StepBasic_ApprovalAssignment::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalAssignment::Init, "None", py::arg("aAssignedApproval"));
	cls_StepBasic_ApprovalAssignment.def("SetAssignedApproval", (void (StepBasic_ApprovalAssignment::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_ApprovalAssignment::SetAssignedApproval, "None", py::arg("aAssignedApproval"));
	cls_StepBasic_ApprovalAssignment.def("AssignedApproval", (opencascade::handle<StepBasic_Approval> (StepBasic_ApprovalAssignment::*)() const ) &StepBasic_ApprovalAssignment::AssignedApproval, "None");
	cls_StepBasic_ApprovalAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApprovalAssignment::get_type_name, "None");
	cls_StepBasic_ApprovalAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApprovalAssignment::get_type_descriptor, "None");
	cls_StepBasic_ApprovalAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApprovalAssignment::*)() const ) &StepBasic_ApprovalAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateAndTimeAssignment.hxx
	py::class_<StepBasic_DateAndTimeAssignment, opencascade::handle<StepBasic_DateAndTimeAssignment>, Standard_Transient> cls_StepBasic_DateAndTimeAssignment(mod, "StepBasic_DateAndTimeAssignment", "None");
	cls_StepBasic_DateAndTimeAssignment.def("Init", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &)) &StepBasic_DateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"));
	cls_StepBasic_DateAndTimeAssignment.def("SetAssignedDateAndTime", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &)) &StepBasic_DateAndTimeAssignment::SetAssignedDateAndTime, "None", py::arg("aAssignedDateAndTime"));
	cls_StepBasic_DateAndTimeAssignment.def("AssignedDateAndTime", (opencascade::handle<StepBasic_DateAndTime> (StepBasic_DateAndTimeAssignment::*)() const ) &StepBasic_DateAndTimeAssignment::AssignedDateAndTime, "None");
	cls_StepBasic_DateAndTimeAssignment.def("SetRole", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateTimeRole> &)) &StepBasic_DateAndTimeAssignment::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_DateAndTimeAssignment.def("Role", (opencascade::handle<StepBasic_DateTimeRole> (StepBasic_DateAndTimeAssignment::*)() const ) &StepBasic_DateAndTimeAssignment::Role, "None");
	cls_StepBasic_DateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAndTimeAssignment::get_type_name, "None");
	cls_StepBasic_DateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAndTimeAssignment::get_type_descriptor, "None");
	cls_StepBasic_DateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAndTimeAssignment::*)() const ) &StepBasic_DateAndTimeAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PersonAndOrganizationAssignment.hxx
	py::class_<StepBasic_PersonAndOrganizationAssignment, opencascade::handle<StepBasic_PersonAndOrganizationAssignment>, Standard_Transient> cls_StepBasic_PersonAndOrganizationAssignment(mod, "StepBasic_PersonAndOrganizationAssignment", "None");
	cls_StepBasic_PersonAndOrganizationAssignment.def("Init", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &)) &StepBasic_PersonAndOrganizationAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"));
	cls_StepBasic_PersonAndOrganizationAssignment.def("SetAssignedPersonAndOrganization", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &)) &StepBasic_PersonAndOrganizationAssignment::SetAssignedPersonAndOrganization, "None", py::arg("aAssignedPersonAndOrganization"));
	cls_StepBasic_PersonAndOrganizationAssignment.def("AssignedPersonAndOrganization", (opencascade::handle<StepBasic_PersonAndOrganization> (StepBasic_PersonAndOrganizationAssignment::*)() const ) &StepBasic_PersonAndOrganizationAssignment::AssignedPersonAndOrganization, "None");
	cls_StepBasic_PersonAndOrganizationAssignment.def("SetRole", (void (StepBasic_PersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganizationRole> &)) &StepBasic_PersonAndOrganizationAssignment::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_PersonAndOrganizationAssignment.def("Role", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (StepBasic_PersonAndOrganizationAssignment::*)() const ) &StepBasic_PersonAndOrganizationAssignment::Role, "None");
	cls_StepBasic_PersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_PersonAndOrganizationAssignment::get_type_name, "None");
	cls_StepBasic_PersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PersonAndOrganizationAssignment::get_type_descriptor, "None");
	cls_StepBasic_PersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PersonAndOrganizationAssignment::*)() const ) &StepBasic_PersonAndOrganizationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SecurityClassificationAssignment.hxx
	py::class_<StepBasic_SecurityClassificationAssignment, opencascade::handle<StepBasic_SecurityClassificationAssignment>, Standard_Transient> cls_StepBasic_SecurityClassificationAssignment(mod, "StepBasic_SecurityClassificationAssignment", "None");
	cls_StepBasic_SecurityClassificationAssignment.def("Init", (void (StepBasic_SecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &)) &StepBasic_SecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"));
	cls_StepBasic_SecurityClassificationAssignment.def("SetAssignedSecurityClassification", (void (StepBasic_SecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &)) &StepBasic_SecurityClassificationAssignment::SetAssignedSecurityClassification, "None", py::arg("aAssignedSecurityClassification"));
	cls_StepBasic_SecurityClassificationAssignment.def("AssignedSecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepBasic_SecurityClassificationAssignment::*)() const ) &StepBasic_SecurityClassificationAssignment::AssignedSecurityClassification, "None");
	cls_StepBasic_SecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_SecurityClassificationAssignment::get_type_name, "None");
	cls_StepBasic_SecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SecurityClassificationAssignment::get_type_descriptor, "None");
	cls_StepBasic_SecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SecurityClassificationAssignment::*)() const ) &StepBasic_SecurityClassificationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DocumentReference.hxx
	py::class_<StepBasic_DocumentReference, opencascade::handle<StepBasic_DocumentReference>, Standard_Transient> cls_StepBasic_DocumentReference(mod, "StepBasic_DocumentReference", "None");
	cls_StepBasic_DocumentReference.def("Init0", (void (StepBasic_DocumentReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentReference::Init0, "None", py::arg("aAssignedDocument"), py::arg("aSource"));
	cls_StepBasic_DocumentReference.def("AssignedDocument", (opencascade::handle<StepBasic_Document> (StepBasic_DocumentReference::*)() const ) &StepBasic_DocumentReference::AssignedDocument, "None");
	cls_StepBasic_DocumentReference.def("SetAssignedDocument", (void (StepBasic_DocumentReference::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_DocumentReference::SetAssignedDocument, "None", py::arg("aAssignedDocument"));
	cls_StepBasic_DocumentReference.def("Source", (opencascade::handle<TCollection_HAsciiString> (StepBasic_DocumentReference::*)() const ) &StepBasic_DocumentReference::Source, "None");
	cls_StepBasic_DocumentReference.def("SetSource", (void (StepBasic_DocumentReference::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_DocumentReference::SetSource, "None", py::arg("aSource"));
	cls_StepBasic_DocumentReference.def_static("get_type_name_", (const char * (*)()) &StepBasic_DocumentReference::get_type_name, "None");
	cls_StepBasic_DocumentReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DocumentReference::get_type_descriptor, "None");
	cls_StepBasic_DocumentReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DocumentReference::*)() const ) &StepBasic_DocumentReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateAssignment.hxx
	py::class_<StepBasic_DateAssignment, opencascade::handle<StepBasic_DateAssignment>, Standard_Transient> cls_StepBasic_DateAssignment(mod, "StepBasic_DateAssignment", "None");
	cls_StepBasic_DateAssignment.def("Init", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &)) &StepBasic_DateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"));
	cls_StepBasic_DateAssignment.def("SetAssignedDate", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_Date> &)) &StepBasic_DateAssignment::SetAssignedDate, "None", py::arg("aAssignedDate"));
	cls_StepBasic_DateAssignment.def("AssignedDate", (opencascade::handle<StepBasic_Date> (StepBasic_DateAssignment::*)() const ) &StepBasic_DateAssignment::AssignedDate, "None");
	cls_StepBasic_DateAssignment.def("SetRole", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_DateRole> &)) &StepBasic_DateAssignment::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_DateAssignment.def("Role", (opencascade::handle<StepBasic_DateRole> (StepBasic_DateAssignment::*)() const ) &StepBasic_DateAssignment::Role, "None");
	cls_StepBasic_DateAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAssignment::get_type_name, "None");
	cls_StepBasic_DateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAssignment::get_type_descriptor, "None");
	cls_StepBasic_DateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAssignment::*)() const ) &StepBasic_DateAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_OrganizationAssignment.hxx
	py::class_<StepBasic_OrganizationAssignment, opencascade::handle<StepBasic_OrganizationAssignment>, Standard_Transient> cls_StepBasic_OrganizationAssignment(mod, "StepBasic_OrganizationAssignment", "None");
	cls_StepBasic_OrganizationAssignment.def("Init", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &, const opencascade::handle<StepBasic_OrganizationRole> &)) &StepBasic_OrganizationAssignment::Init, "None", py::arg("aAssignedOrganization"), py::arg("aRole"));
	cls_StepBasic_OrganizationAssignment.def("SetAssignedOrganization", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &)) &StepBasic_OrganizationAssignment::SetAssignedOrganization, "None", py::arg("aAssignedOrganization"));
	cls_StepBasic_OrganizationAssignment.def("AssignedOrganization", (opencascade::handle<StepBasic_Organization> (StepBasic_OrganizationAssignment::*)() const ) &StepBasic_OrganizationAssignment::AssignedOrganization, "None");
	cls_StepBasic_OrganizationAssignment.def("SetRole", (void (StepBasic_OrganizationAssignment::*)(const opencascade::handle<StepBasic_OrganizationRole> &)) &StepBasic_OrganizationAssignment::SetRole, "None", py::arg("aRole"));
	cls_StepBasic_OrganizationAssignment.def("Role", (opencascade::handle<StepBasic_OrganizationRole> (StepBasic_OrganizationAssignment::*)() const ) &StepBasic_OrganizationAssignment::Role, "None");
	cls_StepBasic_OrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_OrganizationAssignment::get_type_name, "None");
	cls_StepBasic_OrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_OrganizationAssignment::get_type_descriptor, "None");
	cls_StepBasic_OrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_OrganizationAssignment::*)() const ) &StepBasic_OrganizationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PhysicallyModeledProductDefinition.hxx
	py::class_<StepBasic_PhysicallyModeledProductDefinition, opencascade::handle<StepBasic_PhysicallyModeledProductDefinition>, StepBasic_ProductDefinition> cls_StepBasic_PhysicallyModeledProductDefinition(mod, "StepBasic_PhysicallyModeledProductDefinition", "None");
	cls_StepBasic_PhysicallyModeledProductDefinition.def(py::init<>());
	cls_StepBasic_PhysicallyModeledProductDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_PhysicallyModeledProductDefinition::get_type_name, "None");
	cls_StepBasic_PhysicallyModeledProductDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_PhysicallyModeledProductDefinition::get_type_descriptor, "None");
	cls_StepBasic_PhysicallyModeledProductDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_PhysicallyModeledProductDefinition::*)() const ) &StepBasic_PhysicallyModeledProductDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfApproval, std::unique_ptr<StepBasic_Array1OfApproval, Deleter<StepBasic_Array1OfApproval>>> cls_StepBasic_Array1OfApproval(mod, "StepBasic_Array1OfApproval", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfApproval.def(py::init<>());
	cls_StepBasic_Array1OfApproval.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfApproval.def(py::init([] (const StepBasic_Array1OfApproval &other) {return new StepBasic_Array1OfApproval(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfApproval.def(py::init<StepBasic_Array1OfApproval &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfApproval.def(py::init<const opencascade::handle<StepBasic_Approval> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfApproval.def("begin", (StepBasic_Array1OfApproval::iterator (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfApproval.def("end", (StepBasic_Array1OfApproval::iterator (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfApproval.def("cbegin", (StepBasic_Array1OfApproval::const_iterator (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfApproval.def("cend", (StepBasic_Array1OfApproval::const_iterator (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfApproval.def("Init", (void (StepBasic_Array1OfApproval::*)(const opencascade::handle<StepBasic_Approval> &)) &StepBasic_Array1OfApproval::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfApproval.def("Size", (Standard_Integer (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::Size, "Size query");
	cls_StepBasic_Array1OfApproval.def("Length", (Standard_Integer (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::Length, "Length query (the same)");
	cls_StepBasic_Array1OfApproval.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfApproval.def("Lower", (Standard_Integer (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::Lower, "Lower bound");
	cls_StepBasic_Array1OfApproval.def("Upper", (Standard_Integer (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::Upper, "Upper bound");
	cls_StepBasic_Array1OfApproval.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfApproval.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfApproval.def("Assign", (StepBasic_Array1OfApproval & (StepBasic_Array1OfApproval::*)(const StepBasic_Array1OfApproval &)) &StepBasic_Array1OfApproval::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfApproval.def("Move", (StepBasic_Array1OfApproval & (StepBasic_Array1OfApproval::*)(StepBasic_Array1OfApproval &&)) &StepBasic_Array1OfApproval::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfApproval.def("assign", (StepBasic_Array1OfApproval & (StepBasic_Array1OfApproval::*)(const StepBasic_Array1OfApproval &)) &StepBasic_Array1OfApproval::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfApproval.def("assign", (StepBasic_Array1OfApproval & (StepBasic_Array1OfApproval::*)(StepBasic_Array1OfApproval &&)) &StepBasic_Array1OfApproval::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfApproval.def("First", (const opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::First, "Returns first element");
	cls_StepBasic_Array1OfApproval.def("ChangeFirst", (opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)()) &StepBasic_Array1OfApproval::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfApproval.def("Last", (const opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)() const ) &StepBasic_Array1OfApproval::Last, "Returns last element");
	cls_StepBasic_Array1OfApproval.def("ChangeLast", (opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)()) &StepBasic_Array1OfApproval::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfApproval.def("Value", (const opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)(const Standard_Integer) const ) &StepBasic_Array1OfApproval::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfApproval.def("__call__", (const opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)(const Standard_Integer) const ) &StepBasic_Array1OfApproval::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfApproval.def("ChangeValue", (opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)(const Standard_Integer)) &StepBasic_Array1OfApproval::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfApproval.def("__call__", (opencascade::handle<StepBasic_Approval> & (StepBasic_Array1OfApproval::*)(const Standard_Integer)) &StepBasic_Array1OfApproval::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfApproval.def("SetValue", (void (StepBasic_Array1OfApproval::*)(const Standard_Integer, const opencascade::handle<StepBasic_Approval> &)) &StepBasic_Array1OfApproval::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfApproval.def("Resize", (void (StepBasic_Array1OfApproval::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfApproval::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfApproval.def("__iter__", [](const StepBasic_Array1OfApproval &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SourceItem.hxx
	py::class_<StepBasic_SourceItem, std::unique_ptr<StepBasic_SourceItem, Deleter<StepBasic_SourceItem>>, StepData_SelectType> cls_StepBasic_SourceItem(mod, "StepBasic_SourceItem", "Representation of STEP SELECT type SourceItem");
	cls_StepBasic_SourceItem.def(py::init<>());
	cls_StepBasic_SourceItem.def("CaseNum", (Standard_Integer (StepBasic_SourceItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_SourceItem::CaseNum, "Recognizes a kind of SourceItem select type 1 -> HAsciiString from TCollection 0 else", py::arg("ent"));
	cls_StepBasic_SourceItem.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepBasic_SourceItem::*)() const ) &StepBasic_SourceItem::NewMember, "None");
	cls_StepBasic_SourceItem.def("Identifier", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SourceItem::*)() const ) &StepBasic_SourceItem::Identifier, "Returns Value as Identifier (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DateTimeSelect.hxx
	py::class_<StepBasic_DateTimeSelect, std::unique_ptr<StepBasic_DateTimeSelect, Deleter<StepBasic_DateTimeSelect>>, StepData_SelectType> cls_StepBasic_DateTimeSelect(mod, "StepBasic_DateTimeSelect", "None");
	cls_StepBasic_DateTimeSelect.def(py::init<>());
	cls_StepBasic_DateTimeSelect.def("CaseNum", (Standard_Integer (StepBasic_DateTimeSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_DateTimeSelect::CaseNum, "Recognizes a DateTimeSelect Kind Entity that is : 1 -> Date 2 -> LocalTime 3 -> DateAndTime 0 else", py::arg("ent"));
	cls_StepBasic_DateTimeSelect.def("Date", (opencascade::handle<StepBasic_Date> (StepBasic_DateTimeSelect::*)() const ) &StepBasic_DateTimeSelect::Date, "returns Value as a Date (Null if another type)");
	cls_StepBasic_DateTimeSelect.def("LocalTime", (opencascade::handle<StepBasic_LocalTime> (StepBasic_DateTimeSelect::*)() const ) &StepBasic_DateTimeSelect::LocalTime, "returns Value as a LocalTime (Null if another type)");
	cls_StepBasic_DateTimeSelect.def("DateAndTime", (opencascade::handle<StepBasic_DateAndTime> (StepBasic_DateTimeSelect::*)() const ) &StepBasic_DateTimeSelect::DateAndTime, "returns Value as a DateAndTime (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_PersonOrganizationSelect.hxx
	py::class_<StepBasic_PersonOrganizationSelect, std::unique_ptr<StepBasic_PersonOrganizationSelect, Deleter<StepBasic_PersonOrganizationSelect>>, StepData_SelectType> cls_StepBasic_PersonOrganizationSelect(mod, "StepBasic_PersonOrganizationSelect", "None");
	cls_StepBasic_PersonOrganizationSelect.def(py::init<>());
	cls_StepBasic_PersonOrganizationSelect.def("CaseNum", (Standard_Integer (StepBasic_PersonOrganizationSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_PersonOrganizationSelect::CaseNum, "Recognizes a PersonOrganizationSelect Kind Entity that is : 1 -> Person 2 -> Organization 3 -> PersonAndOrganization 0 else", py::arg("ent"));
	cls_StepBasic_PersonOrganizationSelect.def("Person", (opencascade::handle<StepBasic_Person> (StepBasic_PersonOrganizationSelect::*)() const ) &StepBasic_PersonOrganizationSelect::Person, "returns Value as a Person (Null if another type)");
	cls_StepBasic_PersonOrganizationSelect.def("Organization", (opencascade::handle<StepBasic_Organization> (StepBasic_PersonOrganizationSelect::*)() const ) &StepBasic_PersonOrganizationSelect::Organization, "returns Value as a Organization (Null if another type)");
	cls_StepBasic_PersonOrganizationSelect.def("PersonAndOrganization", (opencascade::handle<StepBasic_PersonAndOrganization> (StepBasic_PersonOrganizationSelect::*)() const ) &StepBasic_PersonOrganizationSelect::PersonAndOrganization, "returns Value as a PersonAndOrganization (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_AreaUnit.hxx
	py::class_<StepBasic_AreaUnit, opencascade::handle<StepBasic_AreaUnit>, StepBasic_NamedUnit> cls_StepBasic_AreaUnit(mod, "StepBasic_AreaUnit", "None");
	cls_StepBasic_AreaUnit.def(py::init<>());
	cls_StepBasic_AreaUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_AreaUnit::get_type_name, "None");
	cls_StepBasic_AreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_AreaUnit::get_type_descriptor, "None");
	cls_StepBasic_AreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_AreaUnit::*)() const ) &StepBasic_AreaUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfProductContext, std::unique_ptr<StepBasic_Array1OfProductContext, Deleter<StepBasic_Array1OfProductContext>>> cls_StepBasic_Array1OfProductContext(mod, "StepBasic_Array1OfProductContext", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfProductContext.def(py::init<>());
	cls_StepBasic_Array1OfProductContext.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProductContext.def(py::init([] (const StepBasic_Array1OfProductContext &other) {return new StepBasic_Array1OfProductContext(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfProductContext.def(py::init<StepBasic_Array1OfProductContext &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfProductContext.def(py::init<const opencascade::handle<StepBasic_ProductContext> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProductContext.def("begin", (StepBasic_Array1OfProductContext::iterator (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProductContext.def("end", (StepBasic_Array1OfProductContext::iterator (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProductContext.def("cbegin", (StepBasic_Array1OfProductContext::const_iterator (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProductContext.def("cend", (StepBasic_Array1OfProductContext::const_iterator (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProductContext.def("Init", (void (StepBasic_Array1OfProductContext::*)(const opencascade::handle<StepBasic_ProductContext> &)) &StepBasic_Array1OfProductContext::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfProductContext.def("Size", (Standard_Integer (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::Size, "Size query");
	cls_StepBasic_Array1OfProductContext.def("Length", (Standard_Integer (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::Length, "Length query (the same)");
	cls_StepBasic_Array1OfProductContext.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfProductContext.def("Lower", (Standard_Integer (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::Lower, "Lower bound");
	cls_StepBasic_Array1OfProductContext.def("Upper", (Standard_Integer (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::Upper, "Upper bound");
	cls_StepBasic_Array1OfProductContext.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfProductContext.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfProductContext.def("Assign", (StepBasic_Array1OfProductContext & (StepBasic_Array1OfProductContext::*)(const StepBasic_Array1OfProductContext &)) &StepBasic_Array1OfProductContext::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProductContext.def("Move", (StepBasic_Array1OfProductContext & (StepBasic_Array1OfProductContext::*)(StepBasic_Array1OfProductContext &&)) &StepBasic_Array1OfProductContext::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfProductContext.def("assign", (StepBasic_Array1OfProductContext & (StepBasic_Array1OfProductContext::*)(const StepBasic_Array1OfProductContext &)) &StepBasic_Array1OfProductContext::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProductContext.def("assign", (StepBasic_Array1OfProductContext & (StepBasic_Array1OfProductContext::*)(StepBasic_Array1OfProductContext &&)) &StepBasic_Array1OfProductContext::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfProductContext.def("First", (const opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::First, "Returns first element");
	cls_StepBasic_Array1OfProductContext.def("ChangeFirst", (opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)()) &StepBasic_Array1OfProductContext::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfProductContext.def("Last", (const opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)() const ) &StepBasic_Array1OfProductContext::Last, "Returns last element");
	cls_StepBasic_Array1OfProductContext.def("ChangeLast", (opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)()) &StepBasic_Array1OfProductContext::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfProductContext.def("Value", (const opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)(const Standard_Integer) const ) &StepBasic_Array1OfProductContext::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductContext.def("__call__", (const opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)(const Standard_Integer) const ) &StepBasic_Array1OfProductContext::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductContext.def("ChangeValue", (opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)(const Standard_Integer)) &StepBasic_Array1OfProductContext::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductContext.def("__call__", (opencascade::handle<StepBasic_ProductContext> & (StepBasic_Array1OfProductContext::*)(const Standard_Integer)) &StepBasic_Array1OfProductContext::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductContext.def("SetValue", (void (StepBasic_Array1OfProductContext::*)(const Standard_Integer, const opencascade::handle<StepBasic_ProductContext> &)) &StepBasic_Array1OfProductContext::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfProductContext.def("Resize", (void (StepBasic_Array1OfProductContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfProductContext::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfProductContext.def("__iter__", [](const StepBasic_Array1OfProductContext &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_Unit.hxx
	py::class_<StepBasic_Unit, std::unique_ptr<StepBasic_Unit, Deleter<StepBasic_Unit>>, StepData_SelectType> cls_StepBasic_Unit(mod, "StepBasic_Unit", "Implements a select type unit (NamedUnit or DerivedUnit)");
	cls_StepBasic_Unit.def(py::init<>());
	cls_StepBasic_Unit.def("CaseNum", (Standard_Integer (StepBasic_Unit::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_Unit::CaseNum, "Recognizes a type of Unit Entity 1 -> NamedUnit 2 -> DerivedUnit", py::arg("ent"));
	cls_StepBasic_Unit.def("NamedUnit", (opencascade::handle<StepBasic_NamedUnit> (StepBasic_Unit::*)() const ) &StepBasic_Unit::NamedUnit, "returns Value as a NamedUnit (Null if another type)");
	cls_StepBasic_Unit.def("DerivedUnit", (opencascade::handle<StepBasic_DerivedUnit> (StepBasic_Unit::*)() const ) &StepBasic_Unit::DerivedUnit, "returns Value as a DerivedUnit (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_MeasureValueMember.hxx
	py::class_<StepBasic_MeasureValueMember, opencascade::handle<StepBasic_MeasureValueMember>, StepData_SelectReal> cls_StepBasic_MeasureValueMember(mod, "StepBasic_MeasureValueMember", "for Select MeasureValue, i.e. : length_measure,time_measure,plane_angle_measure, solid_angle_measure,ratio_measure,parameter_value, context_dependent_measure,positive_length_measure, positive_plane_angle_measure,positive_ratio_measure, area_measure,volume_measure, count_measure");
	cls_StepBasic_MeasureValueMember.def(py::init<>());
	cls_StepBasic_MeasureValueMember.def("HasName", (Standard_Boolean (StepBasic_MeasureValueMember::*)() const ) &StepBasic_MeasureValueMember::HasName, "None");
	cls_StepBasic_MeasureValueMember.def("Name", (Standard_CString (StepBasic_MeasureValueMember::*)() const ) &StepBasic_MeasureValueMember::Name, "None");
	cls_StepBasic_MeasureValueMember.def("SetName", (Standard_Boolean (StepBasic_MeasureValueMember::*)(const Standard_CString)) &StepBasic_MeasureValueMember::SetName, "None", py::arg("name"));
	cls_StepBasic_MeasureValueMember.def_static("get_type_name_", (const char * (*)()) &StepBasic_MeasureValueMember::get_type_name, "None");
	cls_StepBasic_MeasureValueMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MeasureValueMember::get_type_descriptor, "None");
	cls_StepBasic_MeasureValueMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MeasureValueMember::*)() const ) &StepBasic_MeasureValueMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_RatioUnit.hxx
	py::class_<StepBasic_RatioUnit, opencascade::handle<StepBasic_RatioUnit>, StepBasic_NamedUnit> cls_StepBasic_RatioUnit(mod, "StepBasic_RatioUnit", "None");
	cls_StepBasic_RatioUnit.def(py::init<>());
	cls_StepBasic_RatioUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_RatioUnit::get_type_name, "None");
	cls_StepBasic_RatioUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_RatioUnit::get_type_descriptor, "None");
	cls_StepBasic_RatioUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_RatioUnit::*)() const ) &StepBasic_RatioUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_TimeUnit.hxx
	py::class_<StepBasic_TimeUnit, opencascade::handle<StepBasic_TimeUnit>, StepBasic_NamedUnit> cls_StepBasic_TimeUnit(mod, "StepBasic_TimeUnit", "None");
	cls_StepBasic_TimeUnit.def(py::init<>());
	cls_StepBasic_TimeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_TimeUnit::get_type_name, "None");
	cls_StepBasic_TimeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_TimeUnit::get_type_descriptor, "None");
	cls_StepBasic_TimeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_TimeUnit::*)() const ) &StepBasic_TimeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_VolumeUnit.hxx
	py::class_<StepBasic_VolumeUnit, opencascade::handle<StepBasic_VolumeUnit>, StepBasic_NamedUnit> cls_StepBasic_VolumeUnit(mod, "StepBasic_VolumeUnit", "None");
	cls_StepBasic_VolumeUnit.def(py::init<>());
	cls_StepBasic_VolumeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_VolumeUnit::get_type_name, "None");
	cls_StepBasic_VolumeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_VolumeUnit::get_type_descriptor, "None");
	cls_StepBasic_VolumeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_VolumeUnit::*)() const ) &StepBasic_VolumeUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfDerivedUnitElement, std::unique_ptr<StepBasic_Array1OfDerivedUnitElement, Deleter<StepBasic_Array1OfDerivedUnitElement>>> cls_StepBasic_Array1OfDerivedUnitElement(mod, "StepBasic_Array1OfDerivedUnitElement", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfDerivedUnitElement.def(py::init<>());
	cls_StepBasic_Array1OfDerivedUnitElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfDerivedUnitElement.def(py::init([] (const StepBasic_Array1OfDerivedUnitElement &other) {return new StepBasic_Array1OfDerivedUnitElement(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfDerivedUnitElement.def(py::init<StepBasic_Array1OfDerivedUnitElement &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfDerivedUnitElement.def(py::init<const opencascade::handle<StepBasic_DerivedUnitElement> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("begin", (StepBasic_Array1OfDerivedUnitElement::iterator (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfDerivedUnitElement.def("end", (StepBasic_Array1OfDerivedUnitElement::iterator (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfDerivedUnitElement.def("cbegin", (StepBasic_Array1OfDerivedUnitElement::const_iterator (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfDerivedUnitElement.def("cend", (StepBasic_Array1OfDerivedUnitElement::const_iterator (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Init", (void (StepBasic_Array1OfDerivedUnitElement::*)(const opencascade::handle<StepBasic_DerivedUnitElement> &)) &StepBasic_Array1OfDerivedUnitElement::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("Size", (Standard_Integer (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::Size, "Size query");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Length", (Standard_Integer (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::Length, "Length query (the same)");
	cls_StepBasic_Array1OfDerivedUnitElement.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Lower", (Standard_Integer (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::Lower, "Lower bound");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Upper", (Standard_Integer (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::Upper, "Upper bound");
	cls_StepBasic_Array1OfDerivedUnitElement.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfDerivedUnitElement.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Assign", (StepBasic_Array1OfDerivedUnitElement & (StepBasic_Array1OfDerivedUnitElement::*)(const StepBasic_Array1OfDerivedUnitElement &)) &StepBasic_Array1OfDerivedUnitElement::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfDerivedUnitElement.def("Move", (StepBasic_Array1OfDerivedUnitElement & (StepBasic_Array1OfDerivedUnitElement::*)(StepBasic_Array1OfDerivedUnitElement &&)) &StepBasic_Array1OfDerivedUnitElement::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("assign", (StepBasic_Array1OfDerivedUnitElement & (StepBasic_Array1OfDerivedUnitElement::*)(const StepBasic_Array1OfDerivedUnitElement &)) &StepBasic_Array1OfDerivedUnitElement::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfDerivedUnitElement.def("assign", (StepBasic_Array1OfDerivedUnitElement & (StepBasic_Array1OfDerivedUnitElement::*)(StepBasic_Array1OfDerivedUnitElement &&)) &StepBasic_Array1OfDerivedUnitElement::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("First", (const opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::First, "Returns first element");
	cls_StepBasic_Array1OfDerivedUnitElement.def("ChangeFirst", (opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)()) &StepBasic_Array1OfDerivedUnitElement::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Last", (const opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)() const ) &StepBasic_Array1OfDerivedUnitElement::Last, "Returns last element");
	cls_StepBasic_Array1OfDerivedUnitElement.def("ChangeLast", (opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)()) &StepBasic_Array1OfDerivedUnitElement::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfDerivedUnitElement.def("Value", (const opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer) const ) &StepBasic_Array1OfDerivedUnitElement::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("__call__", (const opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer) const ) &StepBasic_Array1OfDerivedUnitElement::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("ChangeValue", (opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer)) &StepBasic_Array1OfDerivedUnitElement::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("__call__", (opencascade::handle<StepBasic_DerivedUnitElement> & (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer)) &StepBasic_Array1OfDerivedUnitElement::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("SetValue", (void (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer, const opencascade::handle<StepBasic_DerivedUnitElement> &)) &StepBasic_Array1OfDerivedUnitElement::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("Resize", (void (StepBasic_Array1OfDerivedUnitElement::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfDerivedUnitElement::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfDerivedUnitElement.def("__iter__", [](const StepBasic_Array1OfDerivedUnitElement &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DesignContext.hxx
	py::class_<StepBasic_DesignContext, opencascade::handle<StepBasic_DesignContext>, StepBasic_ProductDefinitionContext> cls_StepBasic_DesignContext(mod, "StepBasic_DesignContext", "class added to Schema AP214 around April 1996");
	cls_StepBasic_DesignContext.def(py::init<>());
	cls_StepBasic_DesignContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_DesignContext::get_type_name, "None");
	cls_StepBasic_DesignContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DesignContext::get_type_descriptor, "None");
	cls_StepBasic_DesignContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DesignContext::*)() const ) &StepBasic_DesignContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_DigitalDocument.hxx
	py::class_<StepBasic_DigitalDocument, opencascade::handle<StepBasic_DigitalDocument>, StepBasic_Document> cls_StepBasic_DigitalDocument(mod, "StepBasic_DigitalDocument", "None");
	cls_StepBasic_DigitalDocument.def(py::init<>());
	cls_StepBasic_DigitalDocument.def_static("get_type_name_", (const char * (*)()) &StepBasic_DigitalDocument::get_type_name, "None");
	cls_StepBasic_DigitalDocument.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DigitalDocument::get_type_descriptor, "None");
	cls_StepBasic_DigitalDocument.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DigitalDocument::*)() const ) &StepBasic_DigitalDocument::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductOrFormationOrDefinition.hxx
	py::class_<StepBasic_ProductOrFormationOrDefinition, std::unique_ptr<StepBasic_ProductOrFormationOrDefinition, Deleter<StepBasic_ProductOrFormationOrDefinition>>, StepData_SelectType> cls_StepBasic_ProductOrFormationOrDefinition(mod, "StepBasic_ProductOrFormationOrDefinition", "Representation of STEP SELECT type ProductOrFormationOrDefinition");
	cls_StepBasic_ProductOrFormationOrDefinition.def(py::init<>());
	cls_StepBasic_ProductOrFormationOrDefinition.def("CaseNum", (Standard_Integer (StepBasic_ProductOrFormationOrDefinition::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_ProductOrFormationOrDefinition::CaseNum, "Recognizes a kind of ProductOrFormationOrDefinition select type 1 -> Product from StepBasic 2 -> ProductDefinitionFormation from StepBasic 3 -> ProductDefinition from StepBasic 0 else", py::arg("ent"));
	cls_StepBasic_ProductOrFormationOrDefinition.def("Product", (opencascade::handle<StepBasic_Product> (StepBasic_ProductOrFormationOrDefinition::*)() const ) &StepBasic_ProductOrFormationOrDefinition::Product, "Returns Value as Product (or Null if another type)");
	cls_StepBasic_ProductOrFormationOrDefinition.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductOrFormationOrDefinition::*)() const ) &StepBasic_ProductOrFormationOrDefinition::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
	cls_StepBasic_ProductOrFormationOrDefinition.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductOrFormationOrDefinition::*)() const ) &StepBasic_ProductOrFormationOrDefinition::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfDocument, std::unique_ptr<StepBasic_Array1OfDocument, Deleter<StepBasic_Array1OfDocument>>> cls_StepBasic_Array1OfDocument(mod, "StepBasic_Array1OfDocument", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfDocument.def(py::init<>());
	cls_StepBasic_Array1OfDocument.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfDocument.def(py::init([] (const StepBasic_Array1OfDocument &other) {return new StepBasic_Array1OfDocument(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfDocument.def(py::init<StepBasic_Array1OfDocument &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfDocument.def(py::init<const opencascade::handle<StepBasic_Document> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfDocument.def("begin", (StepBasic_Array1OfDocument::iterator (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfDocument.def("end", (StepBasic_Array1OfDocument::iterator (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfDocument.def("cbegin", (StepBasic_Array1OfDocument::const_iterator (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfDocument.def("cend", (StepBasic_Array1OfDocument::const_iterator (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfDocument.def("Init", (void (StepBasic_Array1OfDocument::*)(const opencascade::handle<StepBasic_Document> &)) &StepBasic_Array1OfDocument::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfDocument.def("Size", (Standard_Integer (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::Size, "Size query");
	cls_StepBasic_Array1OfDocument.def("Length", (Standard_Integer (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::Length, "Length query (the same)");
	cls_StepBasic_Array1OfDocument.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfDocument.def("Lower", (Standard_Integer (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::Lower, "Lower bound");
	cls_StepBasic_Array1OfDocument.def("Upper", (Standard_Integer (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::Upper, "Upper bound");
	cls_StepBasic_Array1OfDocument.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfDocument.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfDocument.def("Assign", (StepBasic_Array1OfDocument & (StepBasic_Array1OfDocument::*)(const StepBasic_Array1OfDocument &)) &StepBasic_Array1OfDocument::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfDocument.def("Move", (StepBasic_Array1OfDocument & (StepBasic_Array1OfDocument::*)(StepBasic_Array1OfDocument &&)) &StepBasic_Array1OfDocument::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfDocument.def("assign", (StepBasic_Array1OfDocument & (StepBasic_Array1OfDocument::*)(const StepBasic_Array1OfDocument &)) &StepBasic_Array1OfDocument::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfDocument.def("assign", (StepBasic_Array1OfDocument & (StepBasic_Array1OfDocument::*)(StepBasic_Array1OfDocument &&)) &StepBasic_Array1OfDocument::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfDocument.def("First", (const opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::First, "Returns first element");
	cls_StepBasic_Array1OfDocument.def("ChangeFirst", (opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)()) &StepBasic_Array1OfDocument::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfDocument.def("Last", (const opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)() const ) &StepBasic_Array1OfDocument::Last, "Returns last element");
	cls_StepBasic_Array1OfDocument.def("ChangeLast", (opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)()) &StepBasic_Array1OfDocument::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfDocument.def("Value", (const opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)(const Standard_Integer) const ) &StepBasic_Array1OfDocument::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfDocument.def("__call__", (const opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)(const Standard_Integer) const ) &StepBasic_Array1OfDocument::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfDocument.def("ChangeValue", (opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)(const Standard_Integer)) &StepBasic_Array1OfDocument::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfDocument.def("__call__", (opencascade::handle<StepBasic_Document> & (StepBasic_Array1OfDocument::*)(const Standard_Integer)) &StepBasic_Array1OfDocument::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfDocument.def("SetValue", (void (StepBasic_Array1OfDocument::*)(const Standard_Integer, const opencascade::handle<StepBasic_Document> &)) &StepBasic_Array1OfDocument::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfDocument.def("Resize", (void (StepBasic_Array1OfDocument::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfDocument::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfDocument.def("__iter__", [](const StepBasic_Array1OfDocument &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfNamedUnit, std::unique_ptr<StepBasic_Array1OfNamedUnit, Deleter<StepBasic_Array1OfNamedUnit>>> cls_StepBasic_Array1OfNamedUnit(mod, "StepBasic_Array1OfNamedUnit", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfNamedUnit.def(py::init<>());
	cls_StepBasic_Array1OfNamedUnit.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfNamedUnit.def(py::init([] (const StepBasic_Array1OfNamedUnit &other) {return new StepBasic_Array1OfNamedUnit(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfNamedUnit.def(py::init<StepBasic_Array1OfNamedUnit &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfNamedUnit.def(py::init<const opencascade::handle<StepBasic_NamedUnit> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfNamedUnit.def("begin", (StepBasic_Array1OfNamedUnit::iterator (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfNamedUnit.def("end", (StepBasic_Array1OfNamedUnit::iterator (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfNamedUnit.def("cbegin", (StepBasic_Array1OfNamedUnit::const_iterator (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfNamedUnit.def("cend", (StepBasic_Array1OfNamedUnit::const_iterator (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfNamedUnit.def("Init", (void (StepBasic_Array1OfNamedUnit::*)(const opencascade::handle<StepBasic_NamedUnit> &)) &StepBasic_Array1OfNamedUnit::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfNamedUnit.def("Size", (Standard_Integer (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::Size, "Size query");
	cls_StepBasic_Array1OfNamedUnit.def("Length", (Standard_Integer (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::Length, "Length query (the same)");
	cls_StepBasic_Array1OfNamedUnit.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfNamedUnit.def("Lower", (Standard_Integer (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::Lower, "Lower bound");
	cls_StepBasic_Array1OfNamedUnit.def("Upper", (Standard_Integer (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::Upper, "Upper bound");
	cls_StepBasic_Array1OfNamedUnit.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfNamedUnit.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfNamedUnit.def("Assign", (StepBasic_Array1OfNamedUnit & (StepBasic_Array1OfNamedUnit::*)(const StepBasic_Array1OfNamedUnit &)) &StepBasic_Array1OfNamedUnit::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfNamedUnit.def("Move", (StepBasic_Array1OfNamedUnit & (StepBasic_Array1OfNamedUnit::*)(StepBasic_Array1OfNamedUnit &&)) &StepBasic_Array1OfNamedUnit::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfNamedUnit.def("assign", (StepBasic_Array1OfNamedUnit & (StepBasic_Array1OfNamedUnit::*)(const StepBasic_Array1OfNamedUnit &)) &StepBasic_Array1OfNamedUnit::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfNamedUnit.def("assign", (StepBasic_Array1OfNamedUnit & (StepBasic_Array1OfNamedUnit::*)(StepBasic_Array1OfNamedUnit &&)) &StepBasic_Array1OfNamedUnit::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfNamedUnit.def("First", (const opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::First, "Returns first element");
	cls_StepBasic_Array1OfNamedUnit.def("ChangeFirst", (opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)()) &StepBasic_Array1OfNamedUnit::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfNamedUnit.def("Last", (const opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)() const ) &StepBasic_Array1OfNamedUnit::Last, "Returns last element");
	cls_StepBasic_Array1OfNamedUnit.def("ChangeLast", (opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)()) &StepBasic_Array1OfNamedUnit::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfNamedUnit.def("Value", (const opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer) const ) &StepBasic_Array1OfNamedUnit::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfNamedUnit.def("__call__", (const opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer) const ) &StepBasic_Array1OfNamedUnit::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfNamedUnit.def("ChangeValue", (opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer)) &StepBasic_Array1OfNamedUnit::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfNamedUnit.def("__call__", (opencascade::handle<StepBasic_NamedUnit> & (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer)) &StepBasic_Array1OfNamedUnit::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfNamedUnit.def("SetValue", (void (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer, const opencascade::handle<StepBasic_NamedUnit> &)) &StepBasic_Array1OfNamedUnit::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfNamedUnit.def("Resize", (void (StepBasic_Array1OfNamedUnit::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfNamedUnit::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfNamedUnit.def("__iter__", [](const StepBasic_Array1OfNamedUnit &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfOrganization, std::unique_ptr<StepBasic_Array1OfOrganization, Deleter<StepBasic_Array1OfOrganization>>> cls_StepBasic_Array1OfOrganization(mod, "StepBasic_Array1OfOrganization", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfOrganization.def(py::init<>());
	cls_StepBasic_Array1OfOrganization.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfOrganization.def(py::init([] (const StepBasic_Array1OfOrganization &other) {return new StepBasic_Array1OfOrganization(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfOrganization.def(py::init<StepBasic_Array1OfOrganization &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfOrganization.def(py::init<const opencascade::handle<StepBasic_Organization> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfOrganization.def("begin", (StepBasic_Array1OfOrganization::iterator (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfOrganization.def("end", (StepBasic_Array1OfOrganization::iterator (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfOrganization.def("cbegin", (StepBasic_Array1OfOrganization::const_iterator (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfOrganization.def("cend", (StepBasic_Array1OfOrganization::const_iterator (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfOrganization.def("Init", (void (StepBasic_Array1OfOrganization::*)(const opencascade::handle<StepBasic_Organization> &)) &StepBasic_Array1OfOrganization::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfOrganization.def("Size", (Standard_Integer (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::Size, "Size query");
	cls_StepBasic_Array1OfOrganization.def("Length", (Standard_Integer (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::Length, "Length query (the same)");
	cls_StepBasic_Array1OfOrganization.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfOrganization.def("Lower", (Standard_Integer (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::Lower, "Lower bound");
	cls_StepBasic_Array1OfOrganization.def("Upper", (Standard_Integer (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::Upper, "Upper bound");
	cls_StepBasic_Array1OfOrganization.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfOrganization.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfOrganization.def("Assign", (StepBasic_Array1OfOrganization & (StepBasic_Array1OfOrganization::*)(const StepBasic_Array1OfOrganization &)) &StepBasic_Array1OfOrganization::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfOrganization.def("Move", (StepBasic_Array1OfOrganization & (StepBasic_Array1OfOrganization::*)(StepBasic_Array1OfOrganization &&)) &StepBasic_Array1OfOrganization::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfOrganization.def("assign", (StepBasic_Array1OfOrganization & (StepBasic_Array1OfOrganization::*)(const StepBasic_Array1OfOrganization &)) &StepBasic_Array1OfOrganization::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfOrganization.def("assign", (StepBasic_Array1OfOrganization & (StepBasic_Array1OfOrganization::*)(StepBasic_Array1OfOrganization &&)) &StepBasic_Array1OfOrganization::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfOrganization.def("First", (const opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::First, "Returns first element");
	cls_StepBasic_Array1OfOrganization.def("ChangeFirst", (opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)()) &StepBasic_Array1OfOrganization::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfOrganization.def("Last", (const opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)() const ) &StepBasic_Array1OfOrganization::Last, "Returns last element");
	cls_StepBasic_Array1OfOrganization.def("ChangeLast", (opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)()) &StepBasic_Array1OfOrganization::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfOrganization.def("Value", (const opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)(const Standard_Integer) const ) &StepBasic_Array1OfOrganization::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfOrganization.def("__call__", (const opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)(const Standard_Integer) const ) &StepBasic_Array1OfOrganization::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfOrganization.def("ChangeValue", (opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)(const Standard_Integer)) &StepBasic_Array1OfOrganization::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfOrganization.def("__call__", (opencascade::handle<StepBasic_Organization> & (StepBasic_Array1OfOrganization::*)(const Standard_Integer)) &StepBasic_Array1OfOrganization::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfOrganization.def("SetValue", (void (StepBasic_Array1OfOrganization::*)(const Standard_Integer, const opencascade::handle<StepBasic_Organization> &)) &StepBasic_Array1OfOrganization::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfOrganization.def("Resize", (void (StepBasic_Array1OfOrganization::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfOrganization::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfOrganization.def("__iter__", [](const StepBasic_Array1OfOrganization &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfPerson, std::unique_ptr<StepBasic_Array1OfPerson, Deleter<StepBasic_Array1OfPerson>>> cls_StepBasic_Array1OfPerson(mod, "StepBasic_Array1OfPerson", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfPerson.def(py::init<>());
	cls_StepBasic_Array1OfPerson.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfPerson.def(py::init([] (const StepBasic_Array1OfPerson &other) {return new StepBasic_Array1OfPerson(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfPerson.def(py::init<StepBasic_Array1OfPerson &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfPerson.def(py::init<const opencascade::handle<StepBasic_Person> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfPerson.def("begin", (StepBasic_Array1OfPerson::iterator (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfPerson.def("end", (StepBasic_Array1OfPerson::iterator (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfPerson.def("cbegin", (StepBasic_Array1OfPerson::const_iterator (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfPerson.def("cend", (StepBasic_Array1OfPerson::const_iterator (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfPerson.def("Init", (void (StepBasic_Array1OfPerson::*)(const opencascade::handle<StepBasic_Person> &)) &StepBasic_Array1OfPerson::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfPerson.def("Size", (Standard_Integer (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::Size, "Size query");
	cls_StepBasic_Array1OfPerson.def("Length", (Standard_Integer (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::Length, "Length query (the same)");
	cls_StepBasic_Array1OfPerson.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfPerson.def("Lower", (Standard_Integer (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::Lower, "Lower bound");
	cls_StepBasic_Array1OfPerson.def("Upper", (Standard_Integer (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::Upper, "Upper bound");
	cls_StepBasic_Array1OfPerson.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfPerson.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfPerson.def("Assign", (StepBasic_Array1OfPerson & (StepBasic_Array1OfPerson::*)(const StepBasic_Array1OfPerson &)) &StepBasic_Array1OfPerson::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfPerson.def("Move", (StepBasic_Array1OfPerson & (StepBasic_Array1OfPerson::*)(StepBasic_Array1OfPerson &&)) &StepBasic_Array1OfPerson::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfPerson.def("assign", (StepBasic_Array1OfPerson & (StepBasic_Array1OfPerson::*)(const StepBasic_Array1OfPerson &)) &StepBasic_Array1OfPerson::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfPerson.def("assign", (StepBasic_Array1OfPerson & (StepBasic_Array1OfPerson::*)(StepBasic_Array1OfPerson &&)) &StepBasic_Array1OfPerson::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfPerson.def("First", (const opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::First, "Returns first element");
	cls_StepBasic_Array1OfPerson.def("ChangeFirst", (opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)()) &StepBasic_Array1OfPerson::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfPerson.def("Last", (const opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)() const ) &StepBasic_Array1OfPerson::Last, "Returns last element");
	cls_StepBasic_Array1OfPerson.def("ChangeLast", (opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)()) &StepBasic_Array1OfPerson::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfPerson.def("Value", (const opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)(const Standard_Integer) const ) &StepBasic_Array1OfPerson::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfPerson.def("__call__", (const opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)(const Standard_Integer) const ) &StepBasic_Array1OfPerson::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfPerson.def("ChangeValue", (opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)(const Standard_Integer)) &StepBasic_Array1OfPerson::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfPerson.def("__call__", (opencascade::handle<StepBasic_Person> & (StepBasic_Array1OfPerson::*)(const Standard_Integer)) &StepBasic_Array1OfPerson::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfPerson.def("SetValue", (void (StepBasic_Array1OfPerson::*)(const Standard_Integer, const opencascade::handle<StepBasic_Person> &)) &StepBasic_Array1OfPerson::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfPerson.def("Resize", (void (StepBasic_Array1OfPerson::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfPerson::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfPerson.def("__iter__", [](const StepBasic_Array1OfPerson &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfProduct, std::unique_ptr<StepBasic_Array1OfProduct, Deleter<StepBasic_Array1OfProduct>>> cls_StepBasic_Array1OfProduct(mod, "StepBasic_Array1OfProduct", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfProduct.def(py::init<>());
	cls_StepBasic_Array1OfProduct.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProduct.def(py::init([] (const StepBasic_Array1OfProduct &other) {return new StepBasic_Array1OfProduct(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfProduct.def(py::init<StepBasic_Array1OfProduct &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfProduct.def(py::init<const opencascade::handle<StepBasic_Product> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProduct.def("begin", (StepBasic_Array1OfProduct::iterator (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProduct.def("end", (StepBasic_Array1OfProduct::iterator (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProduct.def("cbegin", (StepBasic_Array1OfProduct::const_iterator (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProduct.def("cend", (StepBasic_Array1OfProduct::const_iterator (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProduct.def("Init", (void (StepBasic_Array1OfProduct::*)(const opencascade::handle<StepBasic_Product> &)) &StepBasic_Array1OfProduct::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfProduct.def("Size", (Standard_Integer (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::Size, "Size query");
	cls_StepBasic_Array1OfProduct.def("Length", (Standard_Integer (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::Length, "Length query (the same)");
	cls_StepBasic_Array1OfProduct.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfProduct.def("Lower", (Standard_Integer (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::Lower, "Lower bound");
	cls_StepBasic_Array1OfProduct.def("Upper", (Standard_Integer (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::Upper, "Upper bound");
	cls_StepBasic_Array1OfProduct.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfProduct.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfProduct.def("Assign", (StepBasic_Array1OfProduct & (StepBasic_Array1OfProduct::*)(const StepBasic_Array1OfProduct &)) &StepBasic_Array1OfProduct::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProduct.def("Move", (StepBasic_Array1OfProduct & (StepBasic_Array1OfProduct::*)(StepBasic_Array1OfProduct &&)) &StepBasic_Array1OfProduct::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfProduct.def("assign", (StepBasic_Array1OfProduct & (StepBasic_Array1OfProduct::*)(const StepBasic_Array1OfProduct &)) &StepBasic_Array1OfProduct::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProduct.def("assign", (StepBasic_Array1OfProduct & (StepBasic_Array1OfProduct::*)(StepBasic_Array1OfProduct &&)) &StepBasic_Array1OfProduct::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfProduct.def("First", (const opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::First, "Returns first element");
	cls_StepBasic_Array1OfProduct.def("ChangeFirst", (opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)()) &StepBasic_Array1OfProduct::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfProduct.def("Last", (const opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)() const ) &StepBasic_Array1OfProduct::Last, "Returns last element");
	cls_StepBasic_Array1OfProduct.def("ChangeLast", (opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)()) &StepBasic_Array1OfProduct::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfProduct.def("Value", (const opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)(const Standard_Integer) const ) &StepBasic_Array1OfProduct::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProduct.def("__call__", (const opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)(const Standard_Integer) const ) &StepBasic_Array1OfProduct::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfProduct.def("ChangeValue", (opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)(const Standard_Integer)) &StepBasic_Array1OfProduct::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProduct.def("__call__", (opencascade::handle<StepBasic_Product> & (StepBasic_Array1OfProduct::*)(const Standard_Integer)) &StepBasic_Array1OfProduct::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfProduct.def("SetValue", (void (StepBasic_Array1OfProduct::*)(const Standard_Integer, const opencascade::handle<StepBasic_Product> &)) &StepBasic_Array1OfProduct::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfProduct.def("Resize", (void (StepBasic_Array1OfProduct::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfProduct::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfProduct.def("__iter__", [](const StepBasic_Array1OfProduct &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfProductDefinition, std::unique_ptr<StepBasic_Array1OfProductDefinition, Deleter<StepBasic_Array1OfProductDefinition>>> cls_StepBasic_Array1OfProductDefinition(mod, "StepBasic_Array1OfProductDefinition", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfProductDefinition.def(py::init<>());
	cls_StepBasic_Array1OfProductDefinition.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProductDefinition.def(py::init([] (const StepBasic_Array1OfProductDefinition &other) {return new StepBasic_Array1OfProductDefinition(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfProductDefinition.def(py::init<StepBasic_Array1OfProductDefinition &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfProductDefinition.def(py::init<const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfProductDefinition.def("begin", (StepBasic_Array1OfProductDefinition::iterator (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProductDefinition.def("end", (StepBasic_Array1OfProductDefinition::iterator (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProductDefinition.def("cbegin", (StepBasic_Array1OfProductDefinition::const_iterator (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfProductDefinition.def("cend", (StepBasic_Array1OfProductDefinition::const_iterator (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfProductDefinition.def("Init", (void (StepBasic_Array1OfProductDefinition::*)(const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_Array1OfProductDefinition::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfProductDefinition.def("Size", (Standard_Integer (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::Size, "Size query");
	cls_StepBasic_Array1OfProductDefinition.def("Length", (Standard_Integer (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::Length, "Length query (the same)");
	cls_StepBasic_Array1OfProductDefinition.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfProductDefinition.def("Lower", (Standard_Integer (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::Lower, "Lower bound");
	cls_StepBasic_Array1OfProductDefinition.def("Upper", (Standard_Integer (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::Upper, "Upper bound");
	cls_StepBasic_Array1OfProductDefinition.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfProductDefinition.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfProductDefinition.def("Assign", (StepBasic_Array1OfProductDefinition & (StepBasic_Array1OfProductDefinition::*)(const StepBasic_Array1OfProductDefinition &)) &StepBasic_Array1OfProductDefinition::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProductDefinition.def("Move", (StepBasic_Array1OfProductDefinition & (StepBasic_Array1OfProductDefinition::*)(StepBasic_Array1OfProductDefinition &&)) &StepBasic_Array1OfProductDefinition::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfProductDefinition.def("assign", (StepBasic_Array1OfProductDefinition & (StepBasic_Array1OfProductDefinition::*)(const StepBasic_Array1OfProductDefinition &)) &StepBasic_Array1OfProductDefinition::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfProductDefinition.def("assign", (StepBasic_Array1OfProductDefinition & (StepBasic_Array1OfProductDefinition::*)(StepBasic_Array1OfProductDefinition &&)) &StepBasic_Array1OfProductDefinition::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfProductDefinition.def("First", (const opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::First, "Returns first element");
	cls_StepBasic_Array1OfProductDefinition.def("ChangeFirst", (opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)()) &StepBasic_Array1OfProductDefinition::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfProductDefinition.def("Last", (const opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)() const ) &StepBasic_Array1OfProductDefinition::Last, "Returns last element");
	cls_StepBasic_Array1OfProductDefinition.def("ChangeLast", (opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)()) &StepBasic_Array1OfProductDefinition::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfProductDefinition.def("Value", (const opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer) const ) &StepBasic_Array1OfProductDefinition::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductDefinition.def("__call__", (const opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer) const ) &StepBasic_Array1OfProductDefinition::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductDefinition.def("ChangeValue", (opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer)) &StepBasic_Array1OfProductDefinition::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductDefinition.def("__call__", (opencascade::handle<StepBasic_ProductDefinition> & (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer)) &StepBasic_Array1OfProductDefinition::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfProductDefinition.def("SetValue", (void (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer, const opencascade::handle<StepBasic_ProductDefinition> &)) &StepBasic_Array1OfProductDefinition::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfProductDefinition.def("Resize", (void (StepBasic_Array1OfProductDefinition::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfProductDefinition::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfProductDefinition.def("__iter__", [](const StepBasic_Array1OfProductDefinition &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepBasic_Array1OfUncertaintyMeasureWithUnit, std::unique_ptr<StepBasic_Array1OfUncertaintyMeasureWithUnit, Deleter<StepBasic_Array1OfUncertaintyMeasureWithUnit>>> cls_StepBasic_Array1OfUncertaintyMeasureWithUnit(mod, "StepBasic_Array1OfUncertaintyMeasureWithUnit", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def(py::init<>());
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def(py::init([] (const StepBasic_Array1OfUncertaintyMeasureWithUnit &other) {return new StepBasic_Array1OfUncertaintyMeasureWithUnit(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def(py::init<StepBasic_Array1OfUncertaintyMeasureWithUnit &&>(), py::arg("theOther"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def(py::init<const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("begin", (StepBasic_Array1OfUncertaintyMeasureWithUnit::iterator (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("end", (StepBasic_Array1OfUncertaintyMeasureWithUnit::iterator (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("cbegin", (StepBasic_Array1OfUncertaintyMeasureWithUnit::const_iterator (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("cend", (StepBasic_Array1OfUncertaintyMeasureWithUnit::const_iterator (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Init", (void (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Size", (Standard_Integer (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Size, "Size query");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Length", (Standard_Integer (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Length, "Length query (the same)");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("IsEmpty", (Standard_Boolean (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Lower", (Standard_Integer (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Lower, "Lower bound");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Upper", (Standard_Integer (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Upper, "Upper bound");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("IsDeletable", (Standard_Boolean (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::IsDeletable, "myDeletable flag");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("IsAllocated", (Standard_Boolean (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Assign", (StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const StepBasic_Array1OfUncertaintyMeasureWithUnit &)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Move", (StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(StepBasic_Array1OfUncertaintyMeasureWithUnit &&)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Move, "Move assignment", py::arg("theOther"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("assign", (StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const StepBasic_Array1OfUncertaintyMeasureWithUnit &)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("assign", (StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(StepBasic_Array1OfUncertaintyMeasureWithUnit &&)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("First", (const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::First, "Returns first element");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("ChangeFirst", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)()) &StepBasic_Array1OfUncertaintyMeasureWithUnit::ChangeFirst, "Returns first element");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Last", (const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Last, "Returns last element");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("ChangeLast", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)()) &StepBasic_Array1OfUncertaintyMeasureWithUnit::ChangeLast, "Returns last element");
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Value", (const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer) const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Value, "Constant value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("__call__", (const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer) const ) &StepBasic_Array1OfUncertaintyMeasureWithUnit::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("ChangeValue", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("__call__", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> & (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("SetValue", (void (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer, const opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> &)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("Resize", (void (StepBasic_Array1OfUncertaintyMeasureWithUnit::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepBasic_Array1OfUncertaintyMeasureWithUnit::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepBasic_Array1OfUncertaintyMeasureWithUnit.def("__iter__", [](const StepBasic_Array1OfUncertaintyMeasureWithUnit &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_ProductDefinitionOrReference.hxx
	py::class_<StepBasic_ProductDefinitionOrReference, std::unique_ptr<StepBasic_ProductDefinitionOrReference, Deleter<StepBasic_ProductDefinitionOrReference>>, StepData_SelectType> cls_StepBasic_ProductDefinitionOrReference(mod, "StepBasic_ProductDefinitionOrReference", "None");
	cls_StepBasic_ProductDefinitionOrReference.def(py::init<>());
	cls_StepBasic_ProductDefinitionOrReference.def("CaseNum", (Standard_Integer (StepBasic_ProductDefinitionOrReference::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_ProductDefinitionOrReference::CaseNum, "Recognizes a ProductDefinitionOrReference Kind Entity that is : 1 -> ProductDefinition 2 -> ProductDefinitionReference 3 -> ProductDefinitionReferenceWithLocalPresentation 0 else", py::arg("ent"));
	cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionOrReference::*)() const ) &StepBasic_ProductDefinitionOrReference::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
	cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinitionReference", (opencascade::handle<StepBasic_ProductDefinitionReference> (StepBasic_ProductDefinitionOrReference::*)() const ) &StepBasic_ProductDefinitionOrReference::ProductDefinitionReference, "returns Value as a ProductDefinitionReference (Null if another type)");
	cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinitionReferenceWithLocalRepresentation", (opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation> (StepBasic_ProductDefinitionOrReference::*)() const ) &StepBasic_ProductDefinitionOrReference::ProductDefinitionReferenceWithLocalRepresentation, "returns Value as a ProductDefinitionReferenceWithLocalRepresentation (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_RoleSelect.hxx
	py::class_<StepBasic_RoleSelect, std::unique_ptr<StepBasic_RoleSelect, Deleter<StepBasic_RoleSelect>>, StepData_SelectType> cls_StepBasic_RoleSelect(mod, "StepBasic_RoleSelect", "Representation of STEP SELECT type RoleSelect");
	cls_StepBasic_RoleSelect.def(py::init<>());
	cls_StepBasic_RoleSelect.def("CaseNum", (Standard_Integer (StepBasic_RoleSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_RoleSelect::CaseNum, "Recognizes a kind of RoleSelect select type 1 -> ActionAssignment from StepBasic 2 -> ActionRequestAssignment from StepBasic 3 -> ApprovalAssignment from StepBasic 4 -> ApprovalDateTime from StepBasic 5 -> CertificationAssignment from StepBasic 6 -> ContractAssignment from StepBasic 7 -> DocumentReference from StepBasic 8 -> EffectivityAssignment from StepBasic 9 -> GroupAssignment from StepBasic 10 -> NameAssignment from StepBasic 11 -> SecurityClassificationAssignment from StepBasic 0 else", py::arg("ent"));
	cls_StepBasic_RoleSelect.def("ActionAssignment", (opencascade::handle<StepBasic_ActionAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::ActionAssignment, "Returns Value as ActionAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("ActionRequestAssignment", (opencascade::handle<StepBasic_ActionRequestAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::ActionRequestAssignment, "Returns Value as ActionRequestAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("ApprovalAssignment", (opencascade::handle<StepBasic_ApprovalAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::ApprovalAssignment, "Returns Value as ApprovalAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("ApprovalDateTime", (opencascade::handle<StepBasic_ApprovalDateTime> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::ApprovalDateTime, "Returns Value as ApprovalDateTime (or Null if another type)");
	cls_StepBasic_RoleSelect.def("CertificationAssignment", (opencascade::handle<StepBasic_CertificationAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::CertificationAssignment, "Returns Value as CertificationAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("ContractAssignment", (opencascade::handle<StepBasic_ContractAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::ContractAssignment, "Returns Value as ContractAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("DocumentReference", (opencascade::handle<StepBasic_DocumentReference> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::DocumentReference, "Returns Value as DocumentReference (or Null if another type)");
	cls_StepBasic_RoleSelect.def("EffectivityAssignment", (opencascade::handle<StepBasic_EffectivityAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::EffectivityAssignment, "Returns Value as EffectivityAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("GroupAssignment", (opencascade::handle<StepBasic_GroupAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::GroupAssignment, "Returns Value as GroupAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("NameAssignment", (opencascade::handle<StepBasic_NameAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::NameAssignment, "Returns Value as NameAssignment (or Null if another type)");
	cls_StepBasic_RoleSelect.def("SecurityClassificationAssignment", (opencascade::handle<StepBasic_SecurityClassificationAssignment> (StepBasic_RoleSelect::*)() const ) &StepBasic_RoleSelect::SecurityClassificationAssignment, "Returns Value as SecurityClassificationAssignment (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SizeMember.hxx
	py::class_<StepBasic_SizeMember, opencascade::handle<StepBasic_SizeMember>, StepData_SelectReal> cls_StepBasic_SizeMember(mod, "StepBasic_SizeMember", "For immediate members of SizeSelect, i.e. : ParameterValue (a Real)");
	cls_StepBasic_SizeMember.def(py::init<>());
	cls_StepBasic_SizeMember.def("HasName", (Standard_Boolean (StepBasic_SizeMember::*)() const ) &StepBasic_SizeMember::HasName, "None");
	cls_StepBasic_SizeMember.def("Name", (Standard_CString (StepBasic_SizeMember::*)() const ) &StepBasic_SizeMember::Name, "None");
	cls_StepBasic_SizeMember.def("SetName", (Standard_Boolean (StepBasic_SizeMember::*)(const Standard_CString)) &StepBasic_SizeMember::SetName, "None", py::arg("name"));
	cls_StepBasic_SizeMember.def_static("get_type_name_", (const char * (*)()) &StepBasic_SizeMember::get_type_name, "None");
	cls_StepBasic_SizeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SizeMember::get_type_descriptor, "None");
	cls_StepBasic_SizeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SizeMember::*)() const ) &StepBasic_SizeMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_SizeSelect.hxx
	py::class_<StepBasic_SizeSelect, std::unique_ptr<StepBasic_SizeSelect, Deleter<StepBasic_SizeSelect>>, StepData_SelectType> cls_StepBasic_SizeSelect(mod, "StepBasic_SizeSelect", "None");
	cls_StepBasic_SizeSelect.def(py::init<>());
	cls_StepBasic_SizeSelect.def("CaseNum", (Standard_Integer (StepBasic_SizeSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepBasic_SizeSelect::CaseNum, "Recognizes a TrimmingSelect Kind Entity that is : 1 -> SizeMember 0 else (i.e. Real)", py::arg("ent"));
	cls_StepBasic_SizeSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepBasic_SizeSelect::*)() const ) &StepBasic_SizeSelect::NewMember, "Returns a SizeMember (POSITIVE_LENGTH_MEASURE) as preferred");
	cls_StepBasic_SizeSelect.def("CaseMem", (Standard_Integer (StepBasic_SizeSelect::*)(const opencascade::handle<StepData_SelectMember> &) const ) &StepBasic_SizeSelect::CaseMem, "Recognizes a SelectMember as Real, named as PARAMETER_VALUE 1 -> PositiveLengthMeasure i.e. Real 0 else (i.e. Entity)", py::arg("ent"));
	cls_StepBasic_SizeSelect.def("SetRealValue", (void (StepBasic_SizeSelect::*)(const Standard_Real)) &StepBasic_SizeSelect::SetRealValue, "None", py::arg("aReal"));
	cls_StepBasic_SizeSelect.def("RealValue", (Standard_Real (StepBasic_SizeSelect::*)() const ) &StepBasic_SizeSelect::RealValue, "returns Value as a Real (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_TimeMeasureWithUnit.hxx
	py::class_<StepBasic_TimeMeasureWithUnit, opencascade::handle<StepBasic_TimeMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_TimeMeasureWithUnit(mod, "StepBasic_TimeMeasureWithUnit", "None");
	cls_StepBasic_TimeMeasureWithUnit.def(py::init<>());
	cls_StepBasic_TimeMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_TimeMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_TimeMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_TimeMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_TimeMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_TimeMeasureWithUnit::*)() const ) &StepBasic_TimeMeasureWithUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfApproval.hxx
	py::class_<StepBasic_HArray1OfApproval, opencascade::handle<StepBasic_HArray1OfApproval>, StepBasic_Array1OfApproval, Standard_Transient> cls_StepBasic_HArray1OfApproval(mod, "StepBasic_HArray1OfApproval", "None");
	cls_StepBasic_HArray1OfApproval.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfApproval.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfApproval::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfApproval.def(py::init<const StepBasic_Array1OfApproval &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfApproval.def("Array1", (const StepBasic_Array1OfApproval & (StepBasic_HArray1OfApproval::*)() const ) &StepBasic_HArray1OfApproval::Array1, "None");
	cls_StepBasic_HArray1OfApproval.def("ChangeArray1", (StepBasic_Array1OfApproval & (StepBasic_HArray1OfApproval::*)()) &StepBasic_HArray1OfApproval::ChangeArray1, "None");
	cls_StepBasic_HArray1OfApproval.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfApproval::get_type_name, "None");
	cls_StepBasic_HArray1OfApproval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfApproval::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfApproval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfApproval::*)() const ) &StepBasic_HArray1OfApproval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfDerivedUnitElement.hxx
	py::class_<StepBasic_HArray1OfDerivedUnitElement, opencascade::handle<StepBasic_HArray1OfDerivedUnitElement>, StepBasic_Array1OfDerivedUnitElement, Standard_Transient> cls_StepBasic_HArray1OfDerivedUnitElement(mod, "StepBasic_HArray1OfDerivedUnitElement", "None");
	cls_StepBasic_HArray1OfDerivedUnitElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfDerivedUnitElement.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfDerivedUnitElement::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfDerivedUnitElement.def(py::init<const StepBasic_Array1OfDerivedUnitElement &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfDerivedUnitElement.def("Array1", (const StepBasic_Array1OfDerivedUnitElement & (StepBasic_HArray1OfDerivedUnitElement::*)() const ) &StepBasic_HArray1OfDerivedUnitElement::Array1, "None");
	cls_StepBasic_HArray1OfDerivedUnitElement.def("ChangeArray1", (StepBasic_Array1OfDerivedUnitElement & (StepBasic_HArray1OfDerivedUnitElement::*)()) &StepBasic_HArray1OfDerivedUnitElement::ChangeArray1, "None");
	cls_StepBasic_HArray1OfDerivedUnitElement.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfDerivedUnitElement::get_type_name, "None");
	cls_StepBasic_HArray1OfDerivedUnitElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfDerivedUnitElement::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfDerivedUnitElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfDerivedUnitElement::*)() const ) &StepBasic_HArray1OfDerivedUnitElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfDocument.hxx
	py::class_<StepBasic_HArray1OfDocument, opencascade::handle<StepBasic_HArray1OfDocument>, StepBasic_Array1OfDocument, Standard_Transient> cls_StepBasic_HArray1OfDocument(mod, "StepBasic_HArray1OfDocument", "None");
	cls_StepBasic_HArray1OfDocument.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfDocument.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfDocument::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfDocument.def(py::init<const StepBasic_Array1OfDocument &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfDocument.def("Array1", (const StepBasic_Array1OfDocument & (StepBasic_HArray1OfDocument::*)() const ) &StepBasic_HArray1OfDocument::Array1, "None");
	cls_StepBasic_HArray1OfDocument.def("ChangeArray1", (StepBasic_Array1OfDocument & (StepBasic_HArray1OfDocument::*)()) &StepBasic_HArray1OfDocument::ChangeArray1, "None");
	cls_StepBasic_HArray1OfDocument.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfDocument::get_type_name, "None");
	cls_StepBasic_HArray1OfDocument.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfDocument::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfDocument.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfDocument::*)() const ) &StepBasic_HArray1OfDocument::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfNamedUnit.hxx
	py::class_<StepBasic_HArray1OfNamedUnit, opencascade::handle<StepBasic_HArray1OfNamedUnit>, StepBasic_Array1OfNamedUnit, Standard_Transient> cls_StepBasic_HArray1OfNamedUnit(mod, "StepBasic_HArray1OfNamedUnit", "None");
	cls_StepBasic_HArray1OfNamedUnit.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfNamedUnit.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfNamedUnit::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfNamedUnit.def(py::init<const StepBasic_Array1OfNamedUnit &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfNamedUnit.def("Array1", (const StepBasic_Array1OfNamedUnit & (StepBasic_HArray1OfNamedUnit::*)() const ) &StepBasic_HArray1OfNamedUnit::Array1, "None");
	cls_StepBasic_HArray1OfNamedUnit.def("ChangeArray1", (StepBasic_Array1OfNamedUnit & (StepBasic_HArray1OfNamedUnit::*)()) &StepBasic_HArray1OfNamedUnit::ChangeArray1, "None");
	cls_StepBasic_HArray1OfNamedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfNamedUnit::get_type_name, "None");
	cls_StepBasic_HArray1OfNamedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfNamedUnit::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfNamedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfNamedUnit::*)() const ) &StepBasic_HArray1OfNamedUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfOrganization.hxx
	py::class_<StepBasic_HArray1OfOrganization, opencascade::handle<StepBasic_HArray1OfOrganization>, StepBasic_Array1OfOrganization, Standard_Transient> cls_StepBasic_HArray1OfOrganization(mod, "StepBasic_HArray1OfOrganization", "None");
	cls_StepBasic_HArray1OfOrganization.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfOrganization.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfOrganization::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfOrganization.def(py::init<const StepBasic_Array1OfOrganization &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfOrganization.def("Array1", (const StepBasic_Array1OfOrganization & (StepBasic_HArray1OfOrganization::*)() const ) &StepBasic_HArray1OfOrganization::Array1, "None");
	cls_StepBasic_HArray1OfOrganization.def("ChangeArray1", (StepBasic_Array1OfOrganization & (StepBasic_HArray1OfOrganization::*)()) &StepBasic_HArray1OfOrganization::ChangeArray1, "None");
	cls_StepBasic_HArray1OfOrganization.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfOrganization::get_type_name, "None");
	cls_StepBasic_HArray1OfOrganization.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfOrganization::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfOrganization.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfOrganization::*)() const ) &StepBasic_HArray1OfOrganization::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfPerson.hxx
	py::class_<StepBasic_HArray1OfPerson, opencascade::handle<StepBasic_HArray1OfPerson>, StepBasic_Array1OfPerson, Standard_Transient> cls_StepBasic_HArray1OfPerson(mod, "StepBasic_HArray1OfPerson", "None");
	cls_StepBasic_HArray1OfPerson.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfPerson.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfPerson::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfPerson.def(py::init<const StepBasic_Array1OfPerson &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfPerson.def("Array1", (const StepBasic_Array1OfPerson & (StepBasic_HArray1OfPerson::*)() const ) &StepBasic_HArray1OfPerson::Array1, "None");
	cls_StepBasic_HArray1OfPerson.def("ChangeArray1", (StepBasic_Array1OfPerson & (StepBasic_HArray1OfPerson::*)()) &StepBasic_HArray1OfPerson::ChangeArray1, "None");
	cls_StepBasic_HArray1OfPerson.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfPerson::get_type_name, "None");
	cls_StepBasic_HArray1OfPerson.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfPerson::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfPerson.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfPerson::*)() const ) &StepBasic_HArray1OfPerson::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfProductContext.hxx
	py::class_<StepBasic_HArray1OfProductContext, opencascade::handle<StepBasic_HArray1OfProductContext>, StepBasic_Array1OfProductContext, Standard_Transient> cls_StepBasic_HArray1OfProductContext(mod, "StepBasic_HArray1OfProductContext", "None");
	cls_StepBasic_HArray1OfProductContext.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfProductContext.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfProductContext::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfProductContext.def(py::init<const StepBasic_Array1OfProductContext &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfProductContext.def("Array1", (const StepBasic_Array1OfProductContext & (StepBasic_HArray1OfProductContext::*)() const ) &StepBasic_HArray1OfProductContext::Array1, "None");
	cls_StepBasic_HArray1OfProductContext.def("ChangeArray1", (StepBasic_Array1OfProductContext & (StepBasic_HArray1OfProductContext::*)()) &StepBasic_HArray1OfProductContext::ChangeArray1, "None");
	cls_StepBasic_HArray1OfProductContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfProductContext::get_type_name, "None");
	cls_StepBasic_HArray1OfProductContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfProductContext::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfProductContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfProductContext::*)() const ) &StepBasic_HArray1OfProductContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfProduct.hxx
	py::class_<StepBasic_HArray1OfProduct, opencascade::handle<StepBasic_HArray1OfProduct>, StepBasic_Array1OfProduct, Standard_Transient> cls_StepBasic_HArray1OfProduct(mod, "StepBasic_HArray1OfProduct", "None");
	cls_StepBasic_HArray1OfProduct.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfProduct.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfProduct::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfProduct.def(py::init<const StepBasic_Array1OfProduct &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfProduct.def("Array1", (const StepBasic_Array1OfProduct & (StepBasic_HArray1OfProduct::*)() const ) &StepBasic_HArray1OfProduct::Array1, "None");
	cls_StepBasic_HArray1OfProduct.def("ChangeArray1", (StepBasic_Array1OfProduct & (StepBasic_HArray1OfProduct::*)()) &StepBasic_HArray1OfProduct::ChangeArray1, "None");
	cls_StepBasic_HArray1OfProduct.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfProduct::get_type_name, "None");
	cls_StepBasic_HArray1OfProduct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfProduct::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfProduct.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfProduct::*)() const ) &StepBasic_HArray1OfProduct::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfProductDefinition.hxx
	py::class_<StepBasic_HArray1OfProductDefinition, opencascade::handle<StepBasic_HArray1OfProductDefinition>, StepBasic_Array1OfProductDefinition, Standard_Transient> cls_StepBasic_HArray1OfProductDefinition(mod, "StepBasic_HArray1OfProductDefinition", "None");
	cls_StepBasic_HArray1OfProductDefinition.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfProductDefinition.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfProductDefinition::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfProductDefinition.def(py::init<const StepBasic_Array1OfProductDefinition &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfProductDefinition.def("Array1", (const StepBasic_Array1OfProductDefinition & (StepBasic_HArray1OfProductDefinition::*)() const ) &StepBasic_HArray1OfProductDefinition::Array1, "None");
	cls_StepBasic_HArray1OfProductDefinition.def("ChangeArray1", (StepBasic_Array1OfProductDefinition & (StepBasic_HArray1OfProductDefinition::*)()) &StepBasic_HArray1OfProductDefinition::ChangeArray1, "None");
	cls_StepBasic_HArray1OfProductDefinition.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfProductDefinition::get_type_name, "None");
	cls_StepBasic_HArray1OfProductDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfProductDefinition::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfProductDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfProductDefinition::*)() const ) &StepBasic_HArray1OfProductDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx
	py::class_<StepBasic_HArray1OfUncertaintyMeasureWithUnit, opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit>, StepBasic_Array1OfUncertaintyMeasureWithUnit, Standard_Transient> cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit(mod, "StepBasic_HArray1OfUncertaintyMeasureWithUnit", "None");
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfUncertaintyMeasureWithUnit::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def(py::init<const StepBasic_Array1OfUncertaintyMeasureWithUnit &>(), py::arg("theOther"));
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def("Array1", (const StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_HArray1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_HArray1OfUncertaintyMeasureWithUnit::Array1, "None");
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def("ChangeArray1", (StepBasic_Array1OfUncertaintyMeasureWithUnit & (StepBasic_HArray1OfUncertaintyMeasureWithUnit::*)()) &StepBasic_HArray1OfUncertaintyMeasureWithUnit::ChangeArray1, "None");
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfUncertaintyMeasureWithUnit::get_type_name, "None");
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfUncertaintyMeasureWithUnit::get_type_descriptor, "None");
	cls_StepBasic_HArray1OfUncertaintyMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfUncertaintyMeasureWithUnit::*)() const ) &StepBasic_HArray1OfUncertaintyMeasureWithUnit::DynamicType, "None");


}
