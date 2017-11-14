#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <StepDimTol_AngularityTolerance.hxx>
#include <StepDimTol_CircularRunoutTolerance.hxx>
#include <StepDimTol_CoaxialityTolerance.hxx>
#include <StepRepr_CompositeShapeAspect.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_Datum.hxx>
#include <StepDimTol_CommonDatum.hxx>
#include <StepDimTol_ConcentricityTolerance.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepDimTol_CylindricityTolerance.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_DatumFeature.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <StepDimTol_DatumReference.hxx>
#include <StepDimTol_GeneralDatumReference.hxx>
#include <StepDimTol_DatumReferenceCompartment.hxx>
#include <StepDimTol_DatumReferenceElement.hxx>
#include <StepDimTol_DatumReferenceModifierType.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_DatumReferenceModifierWithValue.hxx>
#include <StepDimTol_HArray1OfDatumReferenceCompartment.hxx>
#include <StepDimTol_DatumSystem.hxx>
#include <StepDimTol_DatumTarget.hxx>
#include <StepDimTol_FlatnessTolerance.hxx>
#include <StepDimTol_DatumOrCommonDatum.hxx>
#include <StepDimTol_HArray1OfDatumReferenceModifier.hxx>
#include <StepDimTol_DatumReferenceModifier.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_GeometricToleranceRelationship.hxx>
#include <StepDimTol_HArray1OfDatumReference.hxx>
#include <StepDimTol_HArray1OfDatumSystemOrReference.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedUnit.hxx>
#include <StepDimTol_AreaUnitType.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedAreaUnit.hxx>
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <StepDimTol_HArray1OfGeometricToleranceModifier.hxx>
#include <StepDimTol_GeometricToleranceWithMaximumTolerance.hxx>
#include <StepDimTol_GeometricToleranceModifier.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRef.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.hxx>
#include <StepDimTol_ModifiedGeometricTolerance.hxx>
#include <StepDimTol_PositionTolerance.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.hxx>
#include <StepDimTol_UnequallyDisposedGeometricTolerance.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthMod.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthMaxTol.hxx>
#include <StepDimTol_LineProfileTolerance.hxx>
#include <StepDimTol_LimitCondition.hxx>
#include <StepDimTol_ToleranceZoneDefinition.hxx>
#include <StepDimTol_NonUniformZoneDefinition.hxx>
#include <StepDimTol_ParallelismTolerance.hxx>
#include <StepDimTol_PerpendicularityTolerance.hxx>
#include <StepDimTol_PlacedDatumTargetFeature.hxx>
#include <StepDimTol_ToleranceZone.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <StepDimTol_ProjectedZoneDefinition.hxx>
#include <StepDimTol_RoundnessTolerance.hxx>
#include <StepDimTol_RunoutZoneOrientation.hxx>
#include <StepDimTol_RunoutZoneDefinition.hxx>
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <StepDimTol_StraightnessTolerance.hxx>
#include <StepDimTol_SurfaceProfileTolerance.hxx>
#include <StepDimTol_SymmetryTolerance.hxx>
#include <StepDimTol_HArray1OfToleranceZoneTarget.hxx>
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <StepDimTol_ToleranceZoneTarget.hxx>
#include <StepDimTol_TotalRunoutTolerance.hxx>
#include <StepData_SelectType.hxx>
#include <StepShape_DimensionalLocation.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepDimTol_SimpleDatumReferenceModifier.hxx>
#include <StepData_SelectInt.hxx>
#include <StepDimTol_SimpleDatumReferenceModifierMember.hxx>
#include <NCollection_Array1.hxx>
#include <StepDimTol_Array1OfDatumReferenceModifier.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepDimTol_DatumSystemOrReference.hxx>
#include <StepDimTol_Array1OfDatumSystemOrReference.hxx>
#include <StepDimTol_Array1OfDatumReference.hxx>
#include <StepDimTol_Array1OfDatumReferenceElement.hxx>
#include <StepDimTol_HArray1OfDatumReferenceElement.hxx>
#include <StepDimTol_Array1OfDatumReferenceCompartment.hxx>
#include <StepDimTol_Array1OfGeometricToleranceModifier.hxx>
#include <StepDimTol_Array1OfToleranceZoneTarget.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <StepDimTol_ShapeToleranceSelect.hxx>

PYBIND11_MODULE(StepDimTol, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceModifier.hxx
	py::enum_<StepDimTol_GeometricToleranceModifier>(mod, "StepDimTol_GeometricToleranceModifier", "None")
		.value("StepDimTol_GTMAnyCrossSection", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMAnyCrossSection)
		.value("StepDimTol_GTMCommonZone", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMCommonZone)
		.value("StepDimTol_GTMEachRadialElement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMEachRadialElement)
		.value("StepDimTol_GTMFreeState", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMFreeState)
		.value("StepDimTol_GTMLeastMaterialRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMLeastMaterialRequirement)
		.value("StepDimTol_GTMLineElement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMLineElement)
		.value("StepDimTol_GTMMajorDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMajorDiameter)
		.value("StepDimTol_GTMMaximumMaterialRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMaximumMaterialRequirement)
		.value("StepDimTol_GTMMinorDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMinorDiameter)
		.value("StepDimTol_GTMNotConvex", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMNotConvex)
		.value("StepDimTol_GTMPitchDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMPitchDiameter)
		.value("StepDimTol_GTMReciprocityRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMReciprocityRequirement)
		.value("StepDimTol_GTMSeparateRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMSeparateRequirement)
		.value("StepDimTol_GTMStatisticalTolerance", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMStatisticalTolerance)
		.value("StepDimTol_GTMTangentPlane", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMTangentPlane)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceType.hxx
	py::enum_<StepDimTol_GeometricToleranceType>(mod, "StepDimTol_GeometricToleranceType", "None")
		.value("StepDimTol_GTTAngularityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTAngularityTolerance)
		.value("StepDimTol_GTTCircularRunoutTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCircularRunoutTolerance)
		.value("StepDimTol_GTTCoaxialityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCoaxialityTolerance)
		.value("StepDimTol_GTTConcentricityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTConcentricityTolerance)
		.value("StepDimTol_GTTCylindricityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCylindricityTolerance)
		.value("StepDimTol_GTTFlatnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTFlatnessTolerance)
		.value("StepDimTol_GTTLineProfileTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTLineProfileTolerance)
		.value("StepDimTol_GTTParallelismTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTParallelismTolerance)
		.value("StepDimTol_GTTPerpendicularityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTPerpendicularityTolerance)
		.value("StepDimTol_GTTPositionTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTPositionTolerance)
		.value("StepDimTol_GTTRoundnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTRoundnessTolerance)
		.value("StepDimTol_GTTStraightnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTStraightnessTolerance)
		.value("StepDimTol_GTTSurfaceProfileTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTSurfaceProfileTolerance)
		.value("StepDimTol_GTTSymmetryTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTSymmetryTolerance)
		.value("StepDimTol_GTTTotalRunoutTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTTotalRunoutTolerance)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReferenceModifierType.hxx
	py::enum_<StepDimTol_DatumReferenceModifierType>(mod, "StepDimTol_DatumReferenceModifierType", "None")
		.value("StepDimTol_CircularOrCylindrical", StepDimTol_DatumReferenceModifierType::StepDimTol_CircularOrCylindrical)
		.value("StepDimTol_Distance", StepDimTol_DatumReferenceModifierType::StepDimTol_Distance)
		.value("StepDimTol_Projected", StepDimTol_DatumReferenceModifierType::StepDimTol_Projected)
		.value("StepDimTol_Spherical", StepDimTol_DatumReferenceModifierType::StepDimTol_Spherical)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_SimpleDatumReferenceModifier.hxx
	py::enum_<StepDimTol_SimpleDatumReferenceModifier>(mod, "StepDimTol_SimpleDatumReferenceModifier", "None")
		.value("StepDimTol_SDRMAnyCrossSection", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMAnyCrossSection)
		.value("StepDimTol_SDRMAnyLongitudinalSection", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMAnyLongitudinalSection)
		.value("StepDimTol_SDRMBasic", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMBasic)
		.value("StepDimTol_SDRMContactingFeature", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMContactingFeature)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintU", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintU)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintV", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintV)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintW", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintW)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintX", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintX)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintY", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintY)
		.value("StepDimTol_SDRMDegreeOfFreedomConstraintZ", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintZ)
		.value("StepDimTol_SDRMDistanceVariable", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDistanceVariable)
		.value("StepDimTol_SDRMFreeState", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMFreeState)
		.value("StepDimTol_SDRMLeastMaterialRequirement", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMLeastMaterialRequirement)
		.value("StepDimTol_SDRMLine", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMLine)
		.value("StepDimTol_SDRMMajorDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMajorDiameter)
		.value("StepDimTol_SDRMMaximumMaterialRequirement", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMaximumMaterialRequirement)
		.value("StepDimTol_SDRMMinorDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMinorDiameter)
		.value("StepDimTol_SDRMOrientation", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMOrientation)
		.value("StepDimTol_SDRMPitchDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPitchDiameter)
		.value("StepDimTol_SDRMPlane", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPlane)
		.value("StepDimTol_SDRMPoint", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPoint)
		.value("StepDimTol_SDRMTranslation", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMTranslation)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_AreaUnitType.hxx
	py::enum_<StepDimTol_AreaUnitType>(mod, "StepDimTol_AreaUnitType", "None")
		.value("StepDimTol_Circular", StepDimTol_AreaUnitType::StepDimTol_Circular)
		.value("StepDimTol_Rectangular", StepDimTol_AreaUnitType::StepDimTol_Rectangular)
		.value("StepDimTol_Square", StepDimTol_AreaUnitType::StepDimTol_Square)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_LimitCondition.hxx
	py::enum_<StepDimTol_LimitCondition>(mod, "StepDimTol_LimitCondition", "None")
		.value("StepDimTol_MaximumMaterialCondition", StepDimTol_LimitCondition::StepDimTol_MaximumMaterialCondition)
		.value("StepDimTol_LeastMaterialCondition", StepDimTol_LimitCondition::StepDimTol_LeastMaterialCondition)
		.value("StepDimTol_RegardlessOfFeatureSize", StepDimTol_LimitCondition::StepDimTol_RegardlessOfFeatureSize)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricTolerance.hxx
	py::class_<StepDimTol_GeometricTolerance, opencascade::handle<StepDimTol_GeometricTolerance>, Standard_Transient> cls_StepDimTol_GeometricTolerance(mod, "StepDimTol_GeometricTolerance", "Representation of STEP entity GeometricTolerance");
	cls_StepDimTol_GeometricTolerance.def(py::init<>());
	cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
	cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
	cls_StepDimTol_GeometricTolerance.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const ) &StepDimTol_GeometricTolerance::Name, "Returns field Name");
	cls_StepDimTol_GeometricTolerance.def("SetName", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetName, "Set field Name", py::arg("theName"));
	cls_StepDimTol_GeometricTolerance.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const ) &StepDimTol_GeometricTolerance::Description, "Returns field Description");
	cls_StepDimTol_GeometricTolerance.def("SetDescription", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetDescription, "Set field Description", py::arg("theDescription"));
	cls_StepDimTol_GeometricTolerance.def("Magnitude", (opencascade::handle<StepBasic_MeasureWithUnit> (StepDimTol_GeometricTolerance::*)() const ) &StepDimTol_GeometricTolerance::Magnitude, "Returns field Magnitude");
	cls_StepDimTol_GeometricTolerance.def("SetMagnitude", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepDimTol_GeometricTolerance::SetMagnitude, "Set field Magnitude", py::arg("theMagnitude"));
	cls_StepDimTol_GeometricTolerance.def("TolerancedShapeAspect", (StepDimTol_GeometricToleranceTarget (StepDimTol_GeometricTolerance::*)() const ) &StepDimTol_GeometricTolerance::TolerancedShapeAspect, "Returns field TolerancedShapeAspect Note: in AP214(203) type of this attribute can be only StepRepr_ShapeAspect");
	cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP214", py::arg("theTolerancedShapeAspect"));
	cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP242", py::arg("theTolerancedShapeAspect"));
	cls_StepDimTol_GeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricTolerance::get_type_name, "None");
	cls_StepDimTol_GeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricTolerance::get_type_descriptor, "None");
	cls_StepDimTol_GeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricTolerance::*)() const ) &StepDimTol_GeometricTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceWithDatumReference.hxx
	py::class_<StepDimTol_GeometricToleranceWithDatumReference, opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDatumReference(mod, "StepDimTol_GeometricToleranceWithDatumReference", "Representation of STEP entity GeometricToleranceWithDatumReference");
	cls_StepDimTol_GeometricToleranceWithDatumReference.def(py::init<>());
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystem", (opencascade::handle<StepDimTol_HArray1OfDatumReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const ) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystem, "Returns field DatumSystem AP214");
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystemAP242", (opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const ) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystemAP242, "Returns field DatumSystem AP242");
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP214", py::arg("theDatumSystem"));
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP242", py::arg("theDatumSystem"));
	cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceWithDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDatumReference::*)() const ) &StepDimTol_GeometricToleranceWithDatumReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_CoaxialityTolerance.hxx
	py::class_<StepDimTol_CoaxialityTolerance, opencascade::handle<StepDimTol_CoaxialityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_CoaxialityTolerance(mod, "StepDimTol_CoaxialityTolerance", "Representation of STEP entity CoaxialityTolerance");
	cls_StepDimTol_CoaxialityTolerance.def(py::init<>());
	cls_StepDimTol_CoaxialityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CoaxialityTolerance::get_type_name, "None");
	cls_StepDimTol_CoaxialityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CoaxialityTolerance::get_type_descriptor, "None");
	cls_StepDimTol_CoaxialityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CoaxialityTolerance::*)() const ) &StepDimTol_CoaxialityTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_CommonDatum.hxx
	py::class_<StepDimTol_CommonDatum, opencascade::handle<StepDimTol_CommonDatum>, StepRepr_CompositeShapeAspect> cls_StepDimTol_CommonDatum(mod, "StepDimTol_CommonDatum", "Representation of STEP entity CommonDatum");
	cls_StepDimTol_CommonDatum.def(py::init<>());
	cls_StepDimTol_CommonDatum.def("Init", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_CommonDatum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theDatum_Name"), py::arg("theDatum_Description"), py::arg("theDatum_OfShape"), py::arg("theDatum_ProductDefinitional"), py::arg("theDatum_Identification"));
	cls_StepDimTol_CommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_CommonDatum::*)() const ) &StepDimTol_CommonDatum::Datum, "Returns data for supertype Datum");
	cls_StepDimTol_CommonDatum.def("SetDatum", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_CommonDatum::SetDatum, "Set data for supertype Datum", py::arg("theDatum"));
	cls_StepDimTol_CommonDatum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CommonDatum::get_type_name, "None");
	cls_StepDimTol_CommonDatum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CommonDatum::get_type_descriptor, "None");
	cls_StepDimTol_CommonDatum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CommonDatum::*)() const ) &StepDimTol_CommonDatum::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ConcentricityTolerance.hxx
	py::class_<StepDimTol_ConcentricityTolerance, opencascade::handle<StepDimTol_ConcentricityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_ConcentricityTolerance(mod, "StepDimTol_ConcentricityTolerance", "Representation of STEP entity ConcentricityTolerance");
	cls_StepDimTol_ConcentricityTolerance.def(py::init<>());
	cls_StepDimTol_ConcentricityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ConcentricityTolerance::get_type_name, "None");
	cls_StepDimTol_ConcentricityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ConcentricityTolerance::get_type_descriptor, "None");
	cls_StepDimTol_ConcentricityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ConcentricityTolerance::*)() const ) &StepDimTol_ConcentricityTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_CylindricityTolerance.hxx
	py::class_<StepDimTol_CylindricityTolerance, opencascade::handle<StepDimTol_CylindricityTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_CylindricityTolerance(mod, "StepDimTol_CylindricityTolerance", "Representation of STEP entity CylindricityTolerance");
	cls_StepDimTol_CylindricityTolerance.def(py::init<>());
	cls_StepDimTol_CylindricityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CylindricityTolerance::get_type_name, "None");
	cls_StepDimTol_CylindricityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CylindricityTolerance::get_type_descriptor, "None");
	cls_StepDimTol_CylindricityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CylindricityTolerance::*)() const ) &StepDimTol_CylindricityTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_Datum.hxx
	py::class_<StepDimTol_Datum, opencascade::handle<StepDimTol_Datum>, StepRepr_ShapeAspect> cls_StepDimTol_Datum(mod, "StepDimTol_Datum", "Representation of STEP entity Datum");
	cls_StepDimTol_Datum.def(py::init<>());
	cls_StepDimTol_Datum.def("Init", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theIdentification"));
	cls_StepDimTol_Datum.def("Identification", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_Datum::*)() const ) &StepDimTol_Datum::Identification, "Returns field Identification");
	cls_StepDimTol_Datum.def("SetIdentification", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::SetIdentification, "Set field Identification", py::arg("theIdentification"));
	cls_StepDimTol_Datum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_Datum::get_type_name, "None");
	cls_StepDimTol_Datum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_Datum::get_type_descriptor, "None");
	cls_StepDimTol_Datum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_Datum::*)() const ) &StepDimTol_Datum::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumFeature.hxx
	py::class_<StepDimTol_DatumFeature, opencascade::handle<StepDimTol_DatumFeature>, StepRepr_ShapeAspect> cls_StepDimTol_DatumFeature(mod, "StepDimTol_DatumFeature", "Representation of STEP entity DatumFeature");
	cls_StepDimTol_DatumFeature.def(py::init<>());
	cls_StepDimTol_DatumFeature.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumFeature::get_type_name, "None");
	cls_StepDimTol_DatumFeature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumFeature::get_type_descriptor, "None");
	cls_StepDimTol_DatumFeature.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumFeature::*)() const ) &StepDimTol_DatumFeature::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReference.hxx
	py::class_<StepDimTol_DatumReference, opencascade::handle<StepDimTol_DatumReference>, Standard_Transient> cls_StepDimTol_DatumReference(mod, "StepDimTol_DatumReference", "Representation of STEP entity DatumReference");
	cls_StepDimTol_DatumReference.def(py::init<>());
	cls_StepDimTol_DatumReference.def("Init", (void (StepDimTol_DatumReference::*)(const Standard_Integer, const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::Init, "Initialize all fields (own and inherited)", py::arg("thePrecedence"), py::arg("theReferencedDatum"));
	cls_StepDimTol_DatumReference.def("Precedence", (Standard_Integer (StepDimTol_DatumReference::*)() const ) &StepDimTol_DatumReference::Precedence, "Returns field Precedence");
	cls_StepDimTol_DatumReference.def("SetPrecedence", (void (StepDimTol_DatumReference::*)(const Standard_Integer)) &StepDimTol_DatumReference::SetPrecedence, "Set field Precedence", py::arg("thePrecedence"));
	cls_StepDimTol_DatumReference.def("ReferencedDatum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumReference::*)() const ) &StepDimTol_DatumReference::ReferencedDatum, "Returns field ReferencedDatum");
	cls_StepDimTol_DatumReference.def("SetReferencedDatum", (void (StepDimTol_DatumReference::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::SetReferencedDatum, "Set field ReferencedDatum", py::arg("theReferencedDatum"));
	cls_StepDimTol_DatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReference::get_type_name, "None");
	cls_StepDimTol_DatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReference::get_type_descriptor, "None");
	cls_StepDimTol_DatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReference::*)() const ) &StepDimTol_DatumReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeneralDatumReference.hxx
	py::class_<StepDimTol_GeneralDatumReference, opencascade::handle<StepDimTol_GeneralDatumReference>, StepRepr_ShapeAspect> cls_StepDimTol_GeneralDatumReference(mod, "StepDimTol_GeneralDatumReference", "Representation of STEP entity GeneralDatumReference");
	cls_StepDimTol_GeneralDatumReference.def(py::init<>());
	cls_StepDimTol_GeneralDatumReference.def("Init", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const StepDimTol_DatumOrCommonDatum &, const Standard_Boolean, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theBase"), py::arg("theHasModifiers"), py::arg("theModifiers"));
	cls_StepDimTol_GeneralDatumReference.def("Base", (StepDimTol_DatumOrCommonDatum (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Base, "Returns field Base");
	cls_StepDimTol_GeneralDatumReference.def("SetBase", (void (StepDimTol_GeneralDatumReference::*)(const StepDimTol_DatumOrCommonDatum &)) &StepDimTol_GeneralDatumReference::SetBase, "Set field Base", py::arg("theBase"));
	cls_StepDimTol_GeneralDatumReference.def("HasModifiers", (Standard_Boolean (StepDimTol_GeneralDatumReference::*)() const ) &StepDimTol_GeneralDatumReference::HasModifiers, "Indicates is field Modifiers exist");
	cls_StepDimTol_GeneralDatumReference.def("Modifiers", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Modifiers, "Returns field Modifiers");
	cls_StepDimTol_GeneralDatumReference.def("SetModifiers", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::SetModifiers, "Set field Modifiers", py::arg("theModifiers"));
	cls_StepDimTol_GeneralDatumReference.def("NbModifiers", (Standard_Integer (StepDimTol_GeneralDatumReference::*)() const ) &StepDimTol_GeneralDatumReference::NbModifiers, "Returns number of Modifiers");
	cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (StepDimTol_DatumReferenceModifier (StepDimTol_GeneralDatumReference::*)(const Standard_Integer) const ) &StepDimTol_GeneralDatumReference::ModifiersValue, "Returns Modifiers with the given number", py::arg("theNum"));
	cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (void (StepDimTol_GeneralDatumReference::*)(const Standard_Integer, const StepDimTol_DatumReferenceModifier &)) &StepDimTol_GeneralDatumReference::ModifiersValue, "Sets Modifiers with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepDimTol_GeneralDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeneralDatumReference::get_type_name, "None");
	cls_StepDimTol_GeneralDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeneralDatumReference::get_type_descriptor, "None");
	cls_StepDimTol_GeneralDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeneralDatumReference::*)() const ) &StepDimTol_GeneralDatumReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReferenceElement.hxx
	py::class_<StepDimTol_DatumReferenceElement, opencascade::handle<StepDimTol_DatumReferenceElement>, StepDimTol_GeneralDatumReference> cls_StepDimTol_DatumReferenceElement(mod, "StepDimTol_DatumReferenceElement", "Representation of STEP entity DatumReferenceElement");
	cls_StepDimTol_DatumReferenceElement.def(py::init<>());
	cls_StepDimTol_DatumReferenceElement.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceElement::get_type_name, "None");
	cls_StepDimTol_DatumReferenceElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceElement::get_type_descriptor, "None");
	cls_StepDimTol_DatumReferenceElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceElement::*)() const ) &StepDimTol_DatumReferenceElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReferenceModifierWithValue.hxx
	py::class_<StepDimTol_DatumReferenceModifierWithValue, opencascade::handle<StepDimTol_DatumReferenceModifierWithValue>, Standard_Transient> cls_StepDimTol_DatumReferenceModifierWithValue(mod, "StepDimTol_DatumReferenceModifierWithValue", "Representation of STEP entity DatumReferenceModifierWithValue");
	cls_StepDimTol_DatumReferenceModifierWithValue.def(py::init<>());
	cls_StepDimTol_DatumReferenceModifierWithValue.def("Init", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::Init, "Initialize all fields (own and inherited)", py::arg("theModifierType"), py::arg("theModifierValue"));
	cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierType", (StepDimTol_DatumReferenceModifierType (StepDimTol_DatumReferenceModifierWithValue::*)() const ) &StepDimTol_DatumReferenceModifierWithValue::ModifierType, "Returns field ModifierType");
	cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierType", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierType, "Set field ModifierType", py::arg("theModifierType"));
	cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierValue", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_DatumReferenceModifierWithValue::*)()) &StepDimTol_DatumReferenceModifierWithValue::ModifierValue, "Returns field ModifierValue");
	cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierValue", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierValue, "Set field ModifierValue", py::arg("theModifierValue"));
	cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_name, "None");
	cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_descriptor, "None");
	cls_StepDimTol_DatumReferenceModifierWithValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceModifierWithValue::*)() const ) &StepDimTol_DatumReferenceModifierWithValue::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumSystem.hxx
	py::class_<StepDimTol_DatumSystem, opencascade::handle<StepDimTol_DatumSystem>, StepRepr_ShapeAspect> cls_StepDimTol_DatumSystem(mod, "StepDimTol_DatumSystem", "Representation of STEP entity DatumSystem");
	cls_StepDimTol_DatumSystem.def(py::init<>());
	cls_StepDimTol_DatumSystem.def("Init", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theConstituents"));
	cls_StepDimTol_DatumSystem.def("Constituents", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> (StepDimTol_DatumSystem::*)()) &StepDimTol_DatumSystem::Constituents, "Returns field Constituents");
	cls_StepDimTol_DatumSystem.def("SetConstituents", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::SetConstituents, "Set field Constituents", py::arg("theConstituents"));
	cls_StepDimTol_DatumSystem.def("NbConstituents", (Standard_Integer (StepDimTol_DatumSystem::*)() const ) &StepDimTol_DatumSystem::NbConstituents, "Returns number of Constituents");
	cls_StepDimTol_DatumSystem.def("ConstituentsValue", (opencascade::handle<StepDimTol_DatumReferenceCompartment> (StepDimTol_DatumSystem::*)(const Standard_Integer) const ) &StepDimTol_DatumSystem::ConstituentsValue, "Returns Constituents with the given number", py::arg("num"));
	cls_StepDimTol_DatumSystem.def("ConstituentsValue", (void (StepDimTol_DatumSystem::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &)) &StepDimTol_DatumSystem::ConstituentsValue, "Sets Constituents with given number", py::arg("num"), py::arg("theItem"));
	cls_StepDimTol_DatumSystem.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumSystem::get_type_name, "None");
	cls_StepDimTol_DatumSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumSystem::get_type_descriptor, "None");
	cls_StepDimTol_DatumSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumSystem::*)() const ) &StepDimTol_DatumSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumTarget.hxx
	py::class_<StepDimTol_DatumTarget, opencascade::handle<StepDimTol_DatumTarget>, StepRepr_ShapeAspect> cls_StepDimTol_DatumTarget(mod, "StepDimTol_DatumTarget", "Representation of STEP entity DatumTarget");
	cls_StepDimTol_DatumTarget.def(py::init<>());
	cls_StepDimTol_DatumTarget.def("Init", (void (StepDimTol_DatumTarget::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_DatumTarget::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theTargetId"));
	cls_StepDimTol_DatumTarget.def("TargetId", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_DatumTarget::*)() const ) &StepDimTol_DatumTarget::TargetId, "Returns field TargetId");
	cls_StepDimTol_DatumTarget.def("SetTargetId", (void (StepDimTol_DatumTarget::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_DatumTarget::SetTargetId, "Set field TargetId", py::arg("theTargetId"));
	cls_StepDimTol_DatumTarget.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumTarget::get_type_name, "None");
	cls_StepDimTol_DatumTarget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumTarget::get_type_descriptor, "None");
	cls_StepDimTol_DatumTarget.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumTarget::*)() const ) &StepDimTol_DatumTarget::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_FlatnessTolerance.hxx
	py::class_<StepDimTol_FlatnessTolerance, opencascade::handle<StepDimTol_FlatnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_FlatnessTolerance(mod, "StepDimTol_FlatnessTolerance", "Representation of STEP entity FlatnessTolerance");
	cls_StepDimTol_FlatnessTolerance.def(py::init<>());
	cls_StepDimTol_FlatnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_FlatnessTolerance::get_type_name, "None");
	cls_StepDimTol_FlatnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_FlatnessTolerance::get_type_descriptor, "None");
	cls_StepDimTol_FlatnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_FlatnessTolerance::*)() const ) &StepDimTol_FlatnessTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReferenceCompartment.hxx
	py::class_<StepDimTol_DatumReferenceCompartment, opencascade::handle<StepDimTol_DatumReferenceCompartment>, StepDimTol_GeneralDatumReference> cls_StepDimTol_DatumReferenceCompartment(mod, "StepDimTol_DatumReferenceCompartment", "Representation of STEP entity DatumReferenceCompartment");
	cls_StepDimTol_DatumReferenceCompartment.def(py::init<>());
	cls_StepDimTol_DatumReferenceCompartment.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceCompartment::get_type_name, "None");
	cls_StepDimTol_DatumReferenceCompartment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceCompartment::get_type_descriptor, "None");
	cls_StepDimTol_DatumReferenceCompartment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceCompartment::*)() const ) &StepDimTol_DatumReferenceCompartment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_CircularRunoutTolerance.hxx
	py::class_<StepDimTol_CircularRunoutTolerance, opencascade::handle<StepDimTol_CircularRunoutTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_CircularRunoutTolerance(mod, "StepDimTol_CircularRunoutTolerance", "Representation of STEP entity CircularRunoutTolerance");
	cls_StepDimTol_CircularRunoutTolerance.def(py::init<>());
	cls_StepDimTol_CircularRunoutTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CircularRunoutTolerance::get_type_name, "None");
	cls_StepDimTol_CircularRunoutTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CircularRunoutTolerance::get_type_descriptor, "None");
	cls_StepDimTol_CircularRunoutTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CircularRunoutTolerance::*)() const ) &StepDimTol_CircularRunoutTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceRelationship.hxx
	py::class_<StepDimTol_GeometricToleranceRelationship, opencascade::handle<StepDimTol_GeometricToleranceRelationship>, Standard_Transient> cls_StepDimTol_GeometricToleranceRelationship(mod, "StepDimTol_GeometricToleranceRelationship", "Representation of STEP entity GeometricToleranceRelationship");
	cls_StepDimTol_GeometricToleranceRelationship.def(py::init<>());
	cls_StepDimTol_GeometricToleranceRelationship.def("Init", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepDimTol_GeometricTolerance> &, const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theRelatingGeometricTolerance"), py::arg("theRelatedGeometricTolerance"));
	cls_StepDimTol_GeometricToleranceRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const ) &StepDimTol_GeometricToleranceRelationship::Name, "Returns field Name");
	cls_StepDimTol_GeometricToleranceRelationship.def("SetName", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetName, "Set field Name", py::arg("theName"));
	cls_StepDimTol_GeometricToleranceRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const ) &StepDimTol_GeometricToleranceRelationship::Description, "Returns field Description");
	cls_StepDimTol_GeometricToleranceRelationship.def("SetDescription", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetDescription, "Set field Description", py::arg("theDescription"));
	cls_StepDimTol_GeometricToleranceRelationship.def("RelatingGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const ) &StepDimTol_GeometricToleranceRelationship::RelatingGeometricTolerance, "Returns field RelatingGeometricTolerance");
	cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatingGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatingGeometricTolerance, "Set field RelatingGeometricTolerance", py::arg("theRelatingGeometricTolerance"));
	cls_StepDimTol_GeometricToleranceRelationship.def("RelatedGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const ) &StepDimTol_GeometricToleranceRelationship::RelatedGeometricTolerance, "Returns field RelatedGeometricTolerance");
	cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatedGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatedGeometricTolerance, "Set field RelatedGeometricTolerance", py::arg("theRelatedGeometricTolerance"));
	cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceRelationship::*)() const ) &StepDimTol_GeometricToleranceRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_AngularityTolerance.hxx
	py::class_<StepDimTol_AngularityTolerance, opencascade::handle<StepDimTol_AngularityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_AngularityTolerance(mod, "StepDimTol_AngularityTolerance", "Representation of STEP entity AngularityTolerance");
	cls_StepDimTol_AngularityTolerance.def(py::init<>());
	cls_StepDimTol_AngularityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_AngularityTolerance::get_type_name, "None");
	cls_StepDimTol_AngularityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_AngularityTolerance::get_type_descriptor, "None");
	cls_StepDimTol_AngularityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_AngularityTolerance::*)() const ) &StepDimTol_AngularityTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceWithDefinedUnit.hxx
	py::class_<StepDimTol_GeometricToleranceWithDefinedUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDefinedUnit(mod, "StepDimTol_GeometricToleranceWithDefinedUnit", "Representation of STEP entity GeometricToleranceWithDefinedUnit");
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def(py::init<>());
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("UnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedUnit::UnitSize, "Returns field UnitSize");
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("SetUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::SetUnitSize, "Set field UnitSize", py::arg("theUnitSize"));
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceWithDefinedAreaUnit.hxx
	py::class_<StepDimTol_GeometricToleranceWithDefinedAreaUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit>, StepDimTol_GeometricToleranceWithDefinedUnit> cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit(mod, "StepDimTol_GeometricToleranceWithDefinedAreaUnit", "Representation of STEP entity GeometricToleranceWithDefinedAreaUnit");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def(py::init<>());
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_AreaUnitType, const Standard_Boolean, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"), py::arg("theAreaType"), py::arg("theHasSecondUnitSize"), py::arg("theSecondUnitSize"));
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("AreaType", (StepDimTol_AreaUnitType (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::AreaType, "Returns field AreaType");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetAreaType", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const StepDimTol_AreaUnitType)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetAreaType, "Set field AreaType", py::arg("theAreaType"));
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SecondUnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SecondUnitSize, "Returns field SecondUnitSize");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetSecondUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetSecondUnitSize, "Set field SecondUnitSize", py::arg("theSecondUnitSize"));
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("HasSecondUnitSize", (Standard_Boolean (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::HasSecondUnitSize, "Indicates if SecondUnitSize field exist");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const ) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceWithModifiers.hxx
	py::class_<StepDimTol_GeometricToleranceWithModifiers, opencascade::handle<StepDimTol_GeometricToleranceWithModifiers>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithModifiers(mod, "StepDimTol_GeometricToleranceWithModifiers", "Representation of STEP entity GeometricToleranceWithModifiers");
	cls_StepDimTol_GeometricToleranceWithModifiers.def(py::init<>());
	cls_StepDimTol_GeometricToleranceWithModifiers.def("Init", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &)) &StepDimTol_GeometricToleranceWithModifiers::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theModifiers"));
	cls_StepDimTol_GeometricToleranceWithModifiers.def("Modifiers", (opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> (StepDimTol_GeometricToleranceWithModifiers::*)() const ) &StepDimTol_GeometricToleranceWithModifiers::Modifiers, "Returns field Modifiers");
	cls_StepDimTol_GeometricToleranceWithModifiers.def("SetModifiers", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &)) &StepDimTol_GeometricToleranceWithModifiers::SetModifiers, "Set field Modifiers", py::arg("theModifiers"));
	cls_StepDimTol_GeometricToleranceWithModifiers.def("NbModifiers", (Standard_Integer (StepDimTol_GeometricToleranceWithModifiers::*)() const ) &StepDimTol_GeometricToleranceWithModifiers::NbModifiers, "Returns number of modifiers");
	cls_StepDimTol_GeometricToleranceWithModifiers.def("ModifierValue", (StepDimTol_GeometricToleranceModifier (StepDimTol_GeometricToleranceWithModifiers::*)(const Standard_Integer) const ) &StepDimTol_GeometricToleranceWithModifiers::ModifierValue, "Returns modifier with the given number", py::arg("theNum"));
	cls_StepDimTol_GeometricToleranceWithModifiers.def("SetModifierValue", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const Standard_Integer, const StepDimTol_GeometricToleranceModifier)) &StepDimTol_GeometricToleranceWithModifiers::SetModifierValue, "Sets modifier with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepDimTol_GeometricToleranceWithModifiers.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithModifiers::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceWithModifiers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithModifiers::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceWithModifiers.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithModifiers::*)() const ) &StepDimTol_GeometricToleranceWithModifiers::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceWithMaximumTolerance.hxx
	py::class_<StepDimTol_GeometricToleranceWithMaximumTolerance, opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance>, StepDimTol_GeometricToleranceWithModifiers> cls_StepDimTol_GeometricToleranceWithMaximumTolerance(mod, "StepDimTol_GeometricToleranceWithMaximumTolerance", "Representation of STEP entity GeometricToleranceWithMaximumTolerance");
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def(py::init<>());
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("Init", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theModifiers"), py::arg("theUnitSize"));
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("MaximumUpperTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const ) &StepDimTol_GeometricToleranceWithMaximumTolerance::MaximumUpperTolerance, "Returns field MaximumUpperTolerance");
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("SetMaximumUpperTolerance", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::SetMaximumUpperTolerance, "Set field MaximumUpperTolerance", py::arg("theMaximumUpperTolerance"));
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_name, "None");
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_descriptor, "None");
	cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const ) &StepDimTol_GeometricToleranceWithMaximumTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthDatRef.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthDatRef, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRef>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRef(mod, "StepDimTol_GeoTolAndGeoTolWthDatRef", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRef::SetGeometricToleranceWithDatumReference, "None", py::arg("theGTWDR"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRef::GetGeometricToleranceWithDatumReference, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::SetGeometricToleranceType, "None", py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRef::GetToleranceType, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRef::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRef::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theGTWM"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aGTWM"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceWithDatumReference, "None", py::arg("theGTWDR"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetGeometricToleranceWithDatumReference, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceWithModifiers", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceWithModifiers, "None", py::arg("theGTWM"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetGeometricToleranceWithModifiers", (opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetGeometricToleranceWithModifiers, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceType, "None", py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetToleranceType, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol>, StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theGTWM"), py::arg("theMaxTol"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aGTWM"), py::arg("theMaxTol"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("SetMaxTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::SetMaxTolerance, "None", py::arg("theMaxTol"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("GetMaxTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::GetMaxTolerance, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetGeometricToleranceWithDatumReference, "None", py::arg("aGTWDR"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetGeometricToleranceWithDatumReference, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetModifiedGeometricTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetModifiedGeometricTolerance, "None", py::arg("aMGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetModifiedGeometricTolerance", (opencascade::handle<StepDimTol_ModifiedGeometricTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetModifiedGeometricTolerance, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetPositionTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_PositionTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetPositionTolerance, "None", py::arg("aPT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetPositionTolerance", (opencascade::handle<StepDimTol_PositionTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetPositionTolerance, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol>, StepDimTol_GeoTolAndGeoTolWthDatRef> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theType"), py::arg("theUDGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("theType"), py::arg("theUDGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("SetUnequallyDisposedGeometricTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::SetUnequallyDisposedGeometricTolerance, "None", py::arg("theUDGT"));
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("GetUnequallyDisposedGeometricTolerance", (opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::GetUnequallyDisposedGeometricTolerance, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthMod.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthMod, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthMod(mod, "StepDimTol_GeoTolAndGeoTolWthMod", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWM"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWM"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceWithModifiers", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceWithModifiers, "None", py::arg("theGTWM"));
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetGeometricToleranceWithModifiers", (opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> (StepDimTol_GeoTolAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthMod::GetGeometricToleranceWithModifiers, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceType, "None", py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthMod::GetToleranceType, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthMod::*)() const ) &StepDimTol_GeoTolAndGeoTolWthMod::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeoTolAndGeoTolWthMaxTol.hxx
	py::class_<StepDimTol_GeoTolAndGeoTolWthMaxTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMaxTol>, StepDimTol_GeoTolAndGeoTolWthMod> cls_StepDimTol_GeoTolAndGeoTolWthMaxTol(mod, "StepDimTol_GeoTolAndGeoTolWthMaxTol", "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def(py::init<>());
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWM"), py::arg("theMaxTol"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWM"), py::arg("theMaxTol"), py::arg("theType"));
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("SetMaxTolerance", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::SetMaxTolerance, "None", py::arg("theMaxTol"));
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("GetMaxTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::GetMaxTolerance, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::get_type_name, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::get_type_descriptor, "None");
	cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)() const ) &StepDimTol_GeoTolAndGeoTolWthMaxTol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_LineProfileTolerance.hxx
	py::class_<StepDimTol_LineProfileTolerance, opencascade::handle<StepDimTol_LineProfileTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_LineProfileTolerance(mod, "StepDimTol_LineProfileTolerance", "Representation of STEP entity LineProfileTolerance");
	cls_StepDimTol_LineProfileTolerance.def(py::init<>());
	cls_StepDimTol_LineProfileTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_LineProfileTolerance::get_type_name, "None");
	cls_StepDimTol_LineProfileTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_LineProfileTolerance::get_type_descriptor, "None");
	cls_StepDimTol_LineProfileTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_LineProfileTolerance::*)() const ) &StepDimTol_LineProfileTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ModifiedGeometricTolerance.hxx
	py::class_<StepDimTol_ModifiedGeometricTolerance, opencascade::handle<StepDimTol_ModifiedGeometricTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_ModifiedGeometricTolerance(mod, "StepDimTol_ModifiedGeometricTolerance", "Representation of STEP entity ModifiedGeometricTolerance");
	cls_StepDimTol_ModifiedGeometricTolerance.def(py::init<>());
	cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
	cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
	cls_StepDimTol_ModifiedGeometricTolerance.def("Modifier", (StepDimTol_LimitCondition (StepDimTol_ModifiedGeometricTolerance::*)() const ) &StepDimTol_ModifiedGeometricTolerance::Modifier, "Returns field Modifier");
	cls_StepDimTol_ModifiedGeometricTolerance.def("SetModifier", (void (StepDimTol_ModifiedGeometricTolerance::*)(const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::SetModifier, "Set field Modifier", py::arg("theModifier"));
	cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_name, "None");
	cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_descriptor, "None");
	cls_StepDimTol_ModifiedGeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ModifiedGeometricTolerance::*)() const ) &StepDimTol_ModifiedGeometricTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ToleranceZoneDefinition.hxx
	py::class_<StepDimTol_ToleranceZoneDefinition, opencascade::handle<StepDimTol_ToleranceZoneDefinition>, Standard_Transient> cls_StepDimTol_ToleranceZoneDefinition(mod, "StepDimTol_ToleranceZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");
	cls_StepDimTol_ToleranceZoneDefinition.def(py::init<>());
	cls_StepDimTol_ToleranceZoneDefinition.def("Init", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"));
	cls_StepDimTol_ToleranceZoneDefinition.def("Boundaries", (opencascade::handle<StepRepr_HArray1OfShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)() const ) &StepDimTol_ToleranceZoneDefinition::Boundaries, "Returns field Boundaries");
	cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundaries", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundaries, "Set field Boundaries", py::arg("theBoundaries"));
	cls_StepDimTol_ToleranceZoneDefinition.def("NbBoundaries", (Standard_Integer (StepDimTol_ToleranceZoneDefinition::*)() const ) &StepDimTol_ToleranceZoneDefinition::NbBoundaries, "Returns number of Boundaries");
	cls_StepDimTol_ToleranceZoneDefinition.def("BoundariesValue", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer) const ) &StepDimTol_ToleranceZoneDefinition::BoundariesValue, "Returns Boundaries with the given number", py::arg("theNum"));
	cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundariesValue", (void (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundariesValue, "Sets Boundaries with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepDimTol_ToleranceZoneDefinition.def("Zone", (opencascade::handle<StepDimTol_ToleranceZone> (StepDimTol_ToleranceZoneDefinition::*)()) &StepDimTol_ToleranceZoneDefinition::Zone, "Returns field Zone");
	cls_StepDimTol_ToleranceZoneDefinition.def("SetZone", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &)) &StepDimTol_ToleranceZoneDefinition::SetZone, "Set field Zone", py::arg("theZone"));
	cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_name, "None");
	cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_descriptor, "None");
	cls_StepDimTol_ToleranceZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneDefinition::*)() const ) &StepDimTol_ToleranceZoneDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ParallelismTolerance.hxx
	py::class_<StepDimTol_ParallelismTolerance, opencascade::handle<StepDimTol_ParallelismTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_ParallelismTolerance(mod, "StepDimTol_ParallelismTolerance", "Representation of STEP entity ParallelismTolerance");
	cls_StepDimTol_ParallelismTolerance.def(py::init<>());
	cls_StepDimTol_ParallelismTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ParallelismTolerance::get_type_name, "None");
	cls_StepDimTol_ParallelismTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ParallelismTolerance::get_type_descriptor, "None");
	cls_StepDimTol_ParallelismTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ParallelismTolerance::*)() const ) &StepDimTol_ParallelismTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_PerpendicularityTolerance.hxx
	py::class_<StepDimTol_PerpendicularityTolerance, opencascade::handle<StepDimTol_PerpendicularityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_PerpendicularityTolerance(mod, "StepDimTol_PerpendicularityTolerance", "Representation of STEP entity PerpendicularityTolerance");
	cls_StepDimTol_PerpendicularityTolerance.def(py::init<>());
	cls_StepDimTol_PerpendicularityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PerpendicularityTolerance::get_type_name, "None");
	cls_StepDimTol_PerpendicularityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PerpendicularityTolerance::get_type_descriptor, "None");
	cls_StepDimTol_PerpendicularityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PerpendicularityTolerance::*)() const ) &StepDimTol_PerpendicularityTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_PlacedDatumTargetFeature.hxx
	py::class_<StepDimTol_PlacedDatumTargetFeature, opencascade::handle<StepDimTol_PlacedDatumTargetFeature>, StepDimTol_DatumTarget> cls_StepDimTol_PlacedDatumTargetFeature(mod, "StepDimTol_PlacedDatumTargetFeature", "Representation of STEP entity PlacedDatumTargetFeature");
	cls_StepDimTol_PlacedDatumTargetFeature.def(py::init<>());
	cls_StepDimTol_PlacedDatumTargetFeature.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PlacedDatumTargetFeature::get_type_name, "None");
	cls_StepDimTol_PlacedDatumTargetFeature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PlacedDatumTargetFeature::get_type_descriptor, "None");
	cls_StepDimTol_PlacedDatumTargetFeature.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PlacedDatumTargetFeature::*)() const ) &StepDimTol_PlacedDatumTargetFeature::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_PositionTolerance.hxx
	py::class_<StepDimTol_PositionTolerance, opencascade::handle<StepDimTol_PositionTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_PositionTolerance(mod, "StepDimTol_PositionTolerance", "Representation of STEP entity PositionTolerance");
	cls_StepDimTol_PositionTolerance.def(py::init<>());
	cls_StepDimTol_PositionTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PositionTolerance::get_type_name, "None");
	cls_StepDimTol_PositionTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PositionTolerance::get_type_descriptor, "None");
	cls_StepDimTol_PositionTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PositionTolerance::*)() const ) &StepDimTol_PositionTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ProjectedZoneDefinition.hxx
	py::class_<StepDimTol_ProjectedZoneDefinition, opencascade::handle<StepDimTol_ProjectedZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_ProjectedZoneDefinition(mod, "StepDimTol_ProjectedZoneDefinition", "Representation of STEP entity ProjectedZoneDefinition");
	cls_StepDimTol_ProjectedZoneDefinition.def(py::init<>());
	cls_StepDimTol_ProjectedZoneDefinition.def("Init", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theProjectionEnd"), py::arg("theProjectionLength"));
	cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionEnd", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ProjectedZoneDefinition::*)() const ) &StepDimTol_ProjectedZoneDefinition::ProjectionEnd, "Returns field ProjectionEnd");
	cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionEnd", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionEnd, "Set field ProjectionEnd", py::arg("theProjectionEnd"));
	cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionLength", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_ProjectedZoneDefinition::*)()) &StepDimTol_ProjectedZoneDefinition::ProjectionLength, "Returns field ProjectionLength");
	cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionLength", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionLength, "Set field ProjectionLength", py::arg("theProjectionLength"));
	cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_name, "None");
	cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_descriptor, "None");
	cls_StepDimTol_ProjectedZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ProjectedZoneDefinition::*)() const ) &StepDimTol_ProjectedZoneDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_RoundnessTolerance.hxx
	py::class_<StepDimTol_RoundnessTolerance, opencascade::handle<StepDimTol_RoundnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_RoundnessTolerance(mod, "StepDimTol_RoundnessTolerance", "Representation of STEP entity RoundnessTolerance");
	cls_StepDimTol_RoundnessTolerance.def(py::init<>());
	cls_StepDimTol_RoundnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RoundnessTolerance::get_type_name, "None");
	cls_StepDimTol_RoundnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RoundnessTolerance::get_type_descriptor, "None");
	cls_StepDimTol_RoundnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RoundnessTolerance::*)() const ) &StepDimTol_RoundnessTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_RunoutZoneDefinition.hxx
	py::class_<StepDimTol_RunoutZoneDefinition, opencascade::handle<StepDimTol_RunoutZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_RunoutZoneDefinition(mod, "StepDimTol_RunoutZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");
	cls_StepDimTol_RunoutZoneDefinition.def(py::init<>());
	cls_StepDimTol_RunoutZoneDefinition.def("Init", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theOrientation"));
	cls_StepDimTol_RunoutZoneDefinition.def("Orientation", (opencascade::handle<StepDimTol_RunoutZoneOrientation> (StepDimTol_RunoutZoneDefinition::*)() const ) &StepDimTol_RunoutZoneDefinition::Orientation, "Returns field Orientation");
	cls_StepDimTol_RunoutZoneDefinition.def("SetOrientation", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::SetOrientation, "Set field Orientation", py::arg("theOrientation"));
	cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneDefinition::get_type_name, "None");
	cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneDefinition::get_type_descriptor, "None");
	cls_StepDimTol_RunoutZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneDefinition::*)() const ) &StepDimTol_RunoutZoneDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_RunoutZoneOrientation.hxx
	py::class_<StepDimTol_RunoutZoneOrientation, opencascade::handle<StepDimTol_RunoutZoneOrientation>, Standard_Transient> cls_StepDimTol_RunoutZoneOrientation(mod, "StepDimTol_RunoutZoneOrientation", "Added for Dimensional Tolerances");
	cls_StepDimTol_RunoutZoneOrientation.def(py::init<>());
	cls_StepDimTol_RunoutZoneOrientation.def("Init", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::Init, "Init all field own and inherited", py::arg("theAngle"));
	cls_StepDimTol_RunoutZoneOrientation.def("Angle", (opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> (StepDimTol_RunoutZoneOrientation::*)()) &StepDimTol_RunoutZoneOrientation::Angle, "Returns field Angle");
	cls_StepDimTol_RunoutZoneOrientation.def("SetAngle", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::SetAngle, "Set field Angle", py::arg("theAngle"));
	cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneOrientation::get_type_name, "None");
	cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneOrientation::get_type_descriptor, "None");
	cls_StepDimTol_RunoutZoneOrientation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneOrientation::*)() const ) &StepDimTol_RunoutZoneOrientation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_StraightnessTolerance.hxx
	py::class_<StepDimTol_StraightnessTolerance, opencascade::handle<StepDimTol_StraightnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_StraightnessTolerance(mod, "StepDimTol_StraightnessTolerance", "Representation of STEP entity StraightnessTolerance");
	cls_StepDimTol_StraightnessTolerance.def(py::init<>());
	cls_StepDimTol_StraightnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_StraightnessTolerance::get_type_name, "None");
	cls_StepDimTol_StraightnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_StraightnessTolerance::get_type_descriptor, "None");
	cls_StepDimTol_StraightnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_StraightnessTolerance::*)() const ) &StepDimTol_StraightnessTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_SurfaceProfileTolerance.hxx
	py::class_<StepDimTol_SurfaceProfileTolerance, opencascade::handle<StepDimTol_SurfaceProfileTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_SurfaceProfileTolerance(mod, "StepDimTol_SurfaceProfileTolerance", "Representation of STEP entity SurfaceProfileTolerance");
	cls_StepDimTol_SurfaceProfileTolerance.def(py::init<>());
	cls_StepDimTol_SurfaceProfileTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SurfaceProfileTolerance::get_type_name, "None");
	cls_StepDimTol_SurfaceProfileTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SurfaceProfileTolerance::get_type_descriptor, "None");
	cls_StepDimTol_SurfaceProfileTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SurfaceProfileTolerance::*)() const ) &StepDimTol_SurfaceProfileTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_SymmetryTolerance.hxx
	py::class_<StepDimTol_SymmetryTolerance, opencascade::handle<StepDimTol_SymmetryTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_SymmetryTolerance(mod, "StepDimTol_SymmetryTolerance", "Representation of STEP entity SymmetryTolerance");
	cls_StepDimTol_SymmetryTolerance.def(py::init<>());
	cls_StepDimTol_SymmetryTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SymmetryTolerance::get_type_name, "None");
	cls_StepDimTol_SymmetryTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SymmetryTolerance::get_type_descriptor, "None");
	cls_StepDimTol_SymmetryTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SymmetryTolerance::*)() const ) &StepDimTol_SymmetryTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ToleranceZone.hxx
	py::class_<StepDimTol_ToleranceZone, opencascade::handle<StepDimTol_ToleranceZone>, StepRepr_ShapeAspect> cls_StepDimTol_ToleranceZone(mod, "StepDimTol_ToleranceZone", "Representation of STEP entity ToleranceZone");
	cls_StepDimTol_ToleranceZone.def(py::init<>());
	cls_StepDimTol_ToleranceZone.def("Init", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theDefiningTolerance"), py::arg("theForm"));
	cls_StepDimTol_ToleranceZone.def("DefiningTolerance", (opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> (StepDimTol_ToleranceZone::*)() const ) &StepDimTol_ToleranceZone::DefiningTolerance, "Returns field DefiningTolerance");
	cls_StepDimTol_ToleranceZone.def("SetDefiningTolerance", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &)) &StepDimTol_ToleranceZone::SetDefiningTolerance, "Set field DefiningTolerance", py::arg("theDefiningTolerance"));
	cls_StepDimTol_ToleranceZone.def("NbDefiningTolerances", (Standard_Integer (StepDimTol_ToleranceZone::*)() const ) &StepDimTol_ToleranceZone::NbDefiningTolerances, "Returns number of Defining Tolerances");
	cls_StepDimTol_ToleranceZone.def("DefiningToleranceValue", (StepDimTol_ToleranceZoneTarget (StepDimTol_ToleranceZone::*)(const Standard_Integer) const ) &StepDimTol_ToleranceZone::DefiningToleranceValue, "Returns Defining Tolerance with the given number", py::arg("theNum"));
	cls_StepDimTol_ToleranceZone.def("SetDefiningToleranceValue", (void (StepDimTol_ToleranceZone::*)(const Standard_Integer, const StepDimTol_ToleranceZoneTarget &)) &StepDimTol_ToleranceZone::SetDefiningToleranceValue, "Sets Defining Tolerance with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepDimTol_ToleranceZone.def("Form", (opencascade::handle<StepDimTol_ToleranceZoneForm> (StepDimTol_ToleranceZone::*)()) &StepDimTol_ToleranceZone::Form, "Returns field Form");
	cls_StepDimTol_ToleranceZone.def("SetForm", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::SetForm, "Set field Form", py::arg("theForm"));
	cls_StepDimTol_ToleranceZone.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZone::get_type_name, "None");
	cls_StepDimTol_ToleranceZone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZone::get_type_descriptor, "None");
	cls_StepDimTol_ToleranceZone.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZone::*)() const ) &StepDimTol_ToleranceZone::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_NonUniformZoneDefinition.hxx
	py::class_<StepDimTol_NonUniformZoneDefinition, opencascade::handle<StepDimTol_NonUniformZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_NonUniformZoneDefinition(mod, "StepDimTol_NonUniformZoneDefinition", "Representation of STEP entity NonUniformZoneDefinition");
	cls_StepDimTol_NonUniformZoneDefinition.def(py::init<>());
	cls_StepDimTol_NonUniformZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_NonUniformZoneDefinition::get_type_name, "None");
	cls_StepDimTol_NonUniformZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_NonUniformZoneDefinition::get_type_descriptor, "None");
	cls_StepDimTol_NonUniformZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_NonUniformZoneDefinition::*)() const ) &StepDimTol_NonUniformZoneDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ToleranceZoneForm.hxx
	py::class_<StepDimTol_ToleranceZoneForm, opencascade::handle<StepDimTol_ToleranceZoneForm>, Standard_Transient> cls_StepDimTol_ToleranceZoneForm(mod, "StepDimTol_ToleranceZoneForm", "Added for Dimensional Tolerances");
	cls_StepDimTol_ToleranceZoneForm.def(py::init<>());
	cls_StepDimTol_ToleranceZoneForm.def("Init", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::Init, "Init all field own and inherited", py::arg("theName"));
	cls_StepDimTol_ToleranceZoneForm.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_ToleranceZoneForm::*)()) &StepDimTol_ToleranceZoneForm::Name, "Returns field Name");
	cls_StepDimTol_ToleranceZoneForm.def("SetName", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::SetName, "Set field Name", py::arg("theName"));
	cls_StepDimTol_ToleranceZoneForm.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneForm::get_type_name, "None");
	cls_StepDimTol_ToleranceZoneForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneForm::get_type_descriptor, "None");
	cls_StepDimTol_ToleranceZoneForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneForm::*)() const ) &StepDimTol_ToleranceZoneForm::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_TotalRunoutTolerance.hxx
	py::class_<StepDimTol_TotalRunoutTolerance, opencascade::handle<StepDimTol_TotalRunoutTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_TotalRunoutTolerance(mod, "StepDimTol_TotalRunoutTolerance", "Representation of STEP entity TotalRunoutTolerance");
	cls_StepDimTol_TotalRunoutTolerance.def(py::init<>());
	cls_StepDimTol_TotalRunoutTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_TotalRunoutTolerance::get_type_name, "None");
	cls_StepDimTol_TotalRunoutTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_TotalRunoutTolerance::get_type_descriptor, "None");
	cls_StepDimTol_TotalRunoutTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_TotalRunoutTolerance::*)() const ) &StepDimTol_TotalRunoutTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_UnequallyDisposedGeometricTolerance.hxx
	py::class_<StepDimTol_UnequallyDisposedGeometricTolerance, opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_UnequallyDisposedGeometricTolerance(mod, "StepDimTol_UnequallyDisposedGeometricTolerance", "Representation of STEP entity UnequallyDisposedGeometricTolerance");
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def(py::init<>());
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("Init", (void (StepDimTol_UnequallyDisposedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_UnequallyDisposedGeometricTolerance::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theDisplacement"));
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("Displacement", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_UnequallyDisposedGeometricTolerance::*)() const ) &StepDimTol_UnequallyDisposedGeometricTolerance::Displacement, "Returns field Displacement");
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("SetDisplacement", (void (StepDimTol_UnequallyDisposedGeometricTolerance::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_UnequallyDisposedGeometricTolerance::SetDisplacement, "Set field Displacement", py::arg("theDisplacement"));
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_UnequallyDisposedGeometricTolerance::get_type_name, "None");
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_UnequallyDisposedGeometricTolerance::get_type_descriptor, "None");
	cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_UnequallyDisposedGeometricTolerance::*)() const ) &StepDimTol_UnequallyDisposedGeometricTolerance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_GeometricToleranceTarget.hxx
	py::class_<StepDimTol_GeometricToleranceTarget, std::unique_ptr<StepDimTol_GeometricToleranceTarget, Deleter<StepDimTol_GeometricToleranceTarget>>, StepData_SelectType> cls_StepDimTol_GeometricToleranceTarget(mod, "StepDimTol_GeometricToleranceTarget", "None");
	cls_StepDimTol_GeometricToleranceTarget.def(py::init<>());
	cls_StepDimTol_GeometricToleranceTarget.def("CaseNum", (Standard_Integer (StepDimTol_GeometricToleranceTarget::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_GeometricToleranceTarget::CaseNum, "Recognizes a GeometricToleranceTarget Kind Entity that is : 1 -> DimensionalLocation 2 -> DimensionalSize 3 -> ProductDefinitionShape 4 -> ShapeAspect 0 else", py::arg("ent"));
	cls_StepDimTol_GeometricToleranceTarget.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepDimTol_GeometricToleranceTarget::*)() const ) &StepDimTol_GeometricToleranceTarget::DimensionalLocation, "returns Value as a DimensionalLocation (Null if another type)");
	cls_StepDimTol_GeometricToleranceTarget.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepDimTol_GeometricToleranceTarget::*)() const ) &StepDimTol_GeometricToleranceTarget::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
	cls_StepDimTol_GeometricToleranceTarget.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepDimTol_GeometricToleranceTarget::*)() const ) &StepDimTol_GeometricToleranceTarget::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
	cls_StepDimTol_GeometricToleranceTarget.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_GeometricToleranceTarget::*)() const ) &StepDimTol_GeometricToleranceTarget::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_SimpleDatumReferenceModifierMember.hxx
	py::class_<StepDimTol_SimpleDatumReferenceModifierMember, opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember>, StepData_SelectInt> cls_StepDimTol_SimpleDatumReferenceModifierMember(mod, "StepDimTol_SimpleDatumReferenceModifierMember", "Defines SimpleDatumReferenceModifier as unique member of DatumReferenceModifier Works with an EnumTool");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def(py::init<>());
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("HasName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::HasName, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Name", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::Name, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetName, "None", py::arg(""));
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Kind", (Standard_Integer (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::Kind, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("EnumText", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::EnumText, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetEnumText", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_Integer, const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetEnumText, "None", py::arg("theValue"), py::arg("theText"));
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetValue", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const StepDimTol_SimpleDatumReferenceModifier)) &StepDimTol_SimpleDatumReferenceModifierMember::SetValue, "None", py::arg("theValue"));
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Value", (StepDimTol_SimpleDatumReferenceModifier (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::Value, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_name, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_descriptor, "None");
	cls_StepDimTol_SimpleDatumReferenceModifierMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SimpleDatumReferenceModifierMember::*)() const ) &StepDimTol_SimpleDatumReferenceModifierMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumReferenceModifier.hxx
	py::class_<StepDimTol_DatumReferenceModifier, std::unique_ptr<StepDimTol_DatumReferenceModifier, Deleter<StepDimTol_DatumReferenceModifier>>, StepData_SelectType> cls_StepDimTol_DatumReferenceModifier(mod, "StepDimTol_DatumReferenceModifier", "None");
	cls_StepDimTol_DatumReferenceModifier.def(py::init<>());
	cls_StepDimTol_DatumReferenceModifier.def("CaseNum", (Standard_Integer (StepDimTol_DatumReferenceModifier::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_DatumReferenceModifier::CaseNum, "Recognizes a DatumReferenceModifier Kind Entity that is : 1 -> DatumReferenceModifierWithValue 2 -> SimpleDatumReferenceModifierMember 0 else", py::arg("ent"));
	cls_StepDimTol_DatumReferenceModifier.def("DatumReferenceModifierWithValue", (opencascade::handle<StepDimTol_DatumReferenceModifierWithValue> (StepDimTol_DatumReferenceModifier::*)() const ) &StepDimTol_DatumReferenceModifier::DatumReferenceModifierWithValue, "returns Value as a DatumReferenceModifierWithValue (Null if another type)");
	cls_StepDimTol_DatumReferenceModifier.def("SimpleDatumReferenceModifierMember", (opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember> (StepDimTol_DatumReferenceModifier::*)() const ) &StepDimTol_DatumReferenceModifier::SimpleDatumReferenceModifierMember, "returns Value as a SimpleDatumReferenceModifierMember (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfDatumReferenceModifier, std::unique_ptr<StepDimTol_Array1OfDatumReferenceModifier, Deleter<StepDimTol_Array1OfDatumReferenceModifier>>> cls_StepDimTol_Array1OfDatumReferenceModifier(mod, "StepDimTol_Array1OfDatumReferenceModifier", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def(py::init<>());
	cls_StepDimTol_Array1OfDatumReferenceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def(py::init([] (const StepDimTol_Array1OfDatumReferenceModifier &other) {return new StepDimTol_Array1OfDatumReferenceModifier(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceModifier.def(py::init<StepDimTol_Array1OfDatumReferenceModifier &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def(py::init<const StepDimTol_DatumReferenceModifier &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("begin", (StepDimTol_Array1OfDatumReferenceModifier::iterator (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("end", (StepDimTol_Array1OfDatumReferenceModifier::iterator (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("cbegin", (StepDimTol_Array1OfDatumReferenceModifier::const_iterator (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("cend", (StepDimTol_Array1OfDatumReferenceModifier::const_iterator (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Init", (void (StepDimTol_Array1OfDatumReferenceModifier::*)(const StepDimTol_DatumReferenceModifier &)) &StepDimTol_Array1OfDatumReferenceModifier::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Size", (Standard_Integer (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::Size, "Size query");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Length", (Standard_Integer (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Lower", (Standard_Integer (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::Lower, "Lower bound");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Upper", (Standard_Integer (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::Upper, "Upper bound");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Assign", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const StepDimTol_Array1OfDatumReferenceModifier &)) &StepDimTol_Array1OfDatumReferenceModifier::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceModifier.def("Move", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(StepDimTol_Array1OfDatumReferenceModifier &&)) &StepDimTol_Array1OfDatumReferenceModifier::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("assign", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const StepDimTol_Array1OfDatumReferenceModifier &)) &StepDimTol_Array1OfDatumReferenceModifier::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceModifier.def("assign", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(StepDimTol_Array1OfDatumReferenceModifier &&)) &StepDimTol_Array1OfDatumReferenceModifier::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("First", (const StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::First, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("ChangeFirst", (StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)()) &StepDimTol_Array1OfDatumReferenceModifier::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Last", (const StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)() const ) &StepDimTol_Array1OfDatumReferenceModifier::Last, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("ChangeLast", (StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)()) &StepDimTol_Array1OfDatumReferenceModifier::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Value", (const StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceModifier::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("__call__", (const StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceModifier::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("ChangeValue", (StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceModifier::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("__call__", (StepDimTol_DatumReferenceModifier & (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceModifier::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("SetValue", (void (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer, const StepDimTol_DatumReferenceModifier &)) &StepDimTol_Array1OfDatumReferenceModifier::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("Resize", (void (StepDimTol_Array1OfDatumReferenceModifier::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfDatumReferenceModifier::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfDatumReferenceModifier.def("__iter__", [](const StepDimTol_Array1OfDatumReferenceModifier &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumSystemOrReference.hxx
	py::class_<StepDimTol_DatumSystemOrReference, std::unique_ptr<StepDimTol_DatumSystemOrReference, Deleter<StepDimTol_DatumSystemOrReference>>, StepData_SelectType> cls_StepDimTol_DatumSystemOrReference(mod, "StepDimTol_DatumSystemOrReference", "None");
	cls_StepDimTol_DatumSystemOrReference.def(py::init<>());
	cls_StepDimTol_DatumSystemOrReference.def("CaseNum", (Standard_Integer (StepDimTol_DatumSystemOrReference::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_DatumSystemOrReference::CaseNum, "Recognizes a DatumSystemOrReference Kind Entity that is : 1 -> DatumSystem 2 -> DatumReference 0 else", py::arg("ent"));
	cls_StepDimTol_DatumSystemOrReference.def("DatumSystem", (opencascade::handle<StepDimTol_DatumSystem> (StepDimTol_DatumSystemOrReference::*)() const ) &StepDimTol_DatumSystemOrReference::DatumSystem, "returns Value as a DatumSystem (Null if another type)");
	cls_StepDimTol_DatumSystemOrReference.def("DatumReference", (opencascade::handle<StepDimTol_DatumReference> (StepDimTol_DatumSystemOrReference::*)() const ) &StepDimTol_DatumSystemOrReference::DatumReference, "returns Value as a DatumReference (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfDatumSystemOrReference, std::unique_ptr<StepDimTol_Array1OfDatumSystemOrReference, Deleter<StepDimTol_Array1OfDatumSystemOrReference>>> cls_StepDimTol_Array1OfDatumSystemOrReference(mod, "StepDimTol_Array1OfDatumSystemOrReference", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def(py::init<>());
	cls_StepDimTol_Array1OfDatumSystemOrReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def(py::init([] (const StepDimTol_Array1OfDatumSystemOrReference &other) {return new StepDimTol_Array1OfDatumSystemOrReference(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfDatumSystemOrReference.def(py::init<StepDimTol_Array1OfDatumSystemOrReference &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def(py::init<const StepDimTol_DatumSystemOrReference &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("begin", (StepDimTol_Array1OfDatumSystemOrReference::iterator (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("end", (StepDimTol_Array1OfDatumSystemOrReference::iterator (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("cbegin", (StepDimTol_Array1OfDatumSystemOrReference::const_iterator (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("cend", (StepDimTol_Array1OfDatumSystemOrReference::const_iterator (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Init", (void (StepDimTol_Array1OfDatumSystemOrReference::*)(const StepDimTol_DatumSystemOrReference &)) &StepDimTol_Array1OfDatumSystemOrReference::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Size", (Standard_Integer (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::Size, "Size query");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Length", (Standard_Integer (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Lower", (Standard_Integer (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::Lower, "Lower bound");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Upper", (Standard_Integer (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::Upper, "Upper bound");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Assign", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const StepDimTol_Array1OfDatumSystemOrReference &)) &StepDimTol_Array1OfDatumSystemOrReference::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumSystemOrReference.def("Move", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(StepDimTol_Array1OfDatumSystemOrReference &&)) &StepDimTol_Array1OfDatumSystemOrReference::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("assign", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const StepDimTol_Array1OfDatumSystemOrReference &)) &StepDimTol_Array1OfDatumSystemOrReference::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumSystemOrReference.def("assign", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(StepDimTol_Array1OfDatumSystemOrReference &&)) &StepDimTol_Array1OfDatumSystemOrReference::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("First", (const StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::First, "Returns first element");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("ChangeFirst", (StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)()) &StepDimTol_Array1OfDatumSystemOrReference::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Last", (const StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)() const ) &StepDimTol_Array1OfDatumSystemOrReference::Last, "Returns last element");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("ChangeLast", (StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)()) &StepDimTol_Array1OfDatumSystemOrReference::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Value", (const StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumSystemOrReference::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("__call__", (const StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumSystemOrReference::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("ChangeValue", (StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumSystemOrReference::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("__call__", (StepDimTol_DatumSystemOrReference & (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumSystemOrReference::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("SetValue", (void (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer, const StepDimTol_DatumSystemOrReference &)) &StepDimTol_Array1OfDatumSystemOrReference::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("Resize", (void (StepDimTol_Array1OfDatumSystemOrReference::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfDatumSystemOrReference::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfDatumSystemOrReference.def("__iter__", [](const StepDimTol_Array1OfDatumSystemOrReference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfDatumReference, std::unique_ptr<StepDimTol_Array1OfDatumReference, Deleter<StepDimTol_Array1OfDatumReference>>> cls_StepDimTol_Array1OfDatumReference(mod, "StepDimTol_Array1OfDatumReference", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfDatumReference.def(py::init<>());
	cls_StepDimTol_Array1OfDatumReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReference.def(py::init([] (const StepDimTol_Array1OfDatumReference &other) {return new StepDimTol_Array1OfDatumReference(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfDatumReference.def(py::init<StepDimTol_Array1OfDatumReference &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReference.def(py::init<const opencascade::handle<StepDimTol_DatumReference> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReference.def("begin", (StepDimTol_Array1OfDatumReference::iterator (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReference.def("end", (StepDimTol_Array1OfDatumReference::iterator (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReference.def("cbegin", (StepDimTol_Array1OfDatumReference::const_iterator (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReference.def("cend", (StepDimTol_Array1OfDatumReference::const_iterator (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReference.def("Init", (void (StepDimTol_Array1OfDatumReference::*)(const opencascade::handle<StepDimTol_DatumReference> &)) &StepDimTol_Array1OfDatumReference::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfDatumReference.def("Size", (Standard_Integer (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::Size, "Size query");
	cls_StepDimTol_Array1OfDatumReference.def("Length", (Standard_Integer (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfDatumReference.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfDatumReference.def("Lower", (Standard_Integer (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::Lower, "Lower bound");
	cls_StepDimTol_Array1OfDatumReference.def("Upper", (Standard_Integer (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::Upper, "Upper bound");
	cls_StepDimTol_Array1OfDatumReference.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfDatumReference.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfDatumReference.def("Assign", (StepDimTol_Array1OfDatumReference & (StepDimTol_Array1OfDatumReference::*)(const StepDimTol_Array1OfDatumReference &)) &StepDimTol_Array1OfDatumReference::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReference.def("Move", (StepDimTol_Array1OfDatumReference & (StepDimTol_Array1OfDatumReference::*)(StepDimTol_Array1OfDatumReference &&)) &StepDimTol_Array1OfDatumReference::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReference.def("assign", (StepDimTol_Array1OfDatumReference & (StepDimTol_Array1OfDatumReference::*)(const StepDimTol_Array1OfDatumReference &)) &StepDimTol_Array1OfDatumReference::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReference.def("assign", (StepDimTol_Array1OfDatumReference & (StepDimTol_Array1OfDatumReference::*)(StepDimTol_Array1OfDatumReference &&)) &StepDimTol_Array1OfDatumReference::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReference.def("First", (const opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::First, "Returns first element");
	cls_StepDimTol_Array1OfDatumReference.def("ChangeFirst", (opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)()) &StepDimTol_Array1OfDatumReference::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfDatumReference.def("Last", (const opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)() const ) &StepDimTol_Array1OfDatumReference::Last, "Returns last element");
	cls_StepDimTol_Array1OfDatumReference.def("ChangeLast", (opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)()) &StepDimTol_Array1OfDatumReference::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfDatumReference.def("Value", (const opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReference::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReference.def("__call__", (const opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReference::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReference.def("ChangeValue", (opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReference::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReference.def("__call__", (opencascade::handle<StepDimTol_DatumReference> & (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReference::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReference.def("SetValue", (void (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReference> &)) &StepDimTol_Array1OfDatumReference::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfDatumReference.def("Resize", (void (StepDimTol_Array1OfDatumReference::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfDatumReference::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfDatumReference.def("__iter__", [](const StepDimTol_Array1OfDatumReference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfDatumReferenceElement, std::unique_ptr<StepDimTol_Array1OfDatumReferenceElement, Deleter<StepDimTol_Array1OfDatumReferenceElement>>> cls_StepDimTol_Array1OfDatumReferenceElement(mod, "StepDimTol_Array1OfDatumReferenceElement", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def(py::init<>());
	cls_StepDimTol_Array1OfDatumReferenceElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def(py::init([] (const StepDimTol_Array1OfDatumReferenceElement &other) {return new StepDimTol_Array1OfDatumReferenceElement(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceElement.def(py::init<StepDimTol_Array1OfDatumReferenceElement &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def(py::init<const opencascade::handle<StepDimTol_DatumReferenceElement> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("begin", (StepDimTol_Array1OfDatumReferenceElement::iterator (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("end", (StepDimTol_Array1OfDatumReferenceElement::iterator (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("cbegin", (StepDimTol_Array1OfDatumReferenceElement::const_iterator (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("cend", (StepDimTol_Array1OfDatumReferenceElement::const_iterator (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Init", (void (StepDimTol_Array1OfDatumReferenceElement::*)(const opencascade::handle<StepDimTol_DatumReferenceElement> &)) &StepDimTol_Array1OfDatumReferenceElement::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Size", (Standard_Integer (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::Size, "Size query");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Length", (Standard_Integer (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Lower", (Standard_Integer (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::Lower, "Lower bound");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Upper", (Standard_Integer (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::Upper, "Upper bound");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Assign", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_Array1OfDatumReferenceElement::*)(const StepDimTol_Array1OfDatumReferenceElement &)) &StepDimTol_Array1OfDatumReferenceElement::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceElement.def("Move", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_Array1OfDatumReferenceElement::*)(StepDimTol_Array1OfDatumReferenceElement &&)) &StepDimTol_Array1OfDatumReferenceElement::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("assign", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_Array1OfDatumReferenceElement::*)(const StepDimTol_Array1OfDatumReferenceElement &)) &StepDimTol_Array1OfDatumReferenceElement::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceElement.def("assign", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_Array1OfDatumReferenceElement::*)(StepDimTol_Array1OfDatumReferenceElement &&)) &StepDimTol_Array1OfDatumReferenceElement::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("First", (const opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::First, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("ChangeFirst", (opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)()) &StepDimTol_Array1OfDatumReferenceElement::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Last", (const opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)() const ) &StepDimTol_Array1OfDatumReferenceElement::Last, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("ChangeLast", (opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)()) &StepDimTol_Array1OfDatumReferenceElement::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Value", (const opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceElement::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("__call__", (const opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceElement::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("ChangeValue", (opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceElement::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("__call__", (opencascade::handle<StepDimTol_DatumReferenceElement> & (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceElement::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("SetValue", (void (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReferenceElement> &)) &StepDimTol_Array1OfDatumReferenceElement::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("Resize", (void (StepDimTol_Array1OfDatumReferenceElement::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfDatumReferenceElement::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfDatumReferenceElement.def("__iter__", [](const StepDimTol_Array1OfDatumReferenceElement &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_DatumOrCommonDatum.hxx
	py::class_<StepDimTol_DatumOrCommonDatum, std::unique_ptr<StepDimTol_DatumOrCommonDatum, Deleter<StepDimTol_DatumOrCommonDatum>>, StepData_SelectType> cls_StepDimTol_DatumOrCommonDatum(mod, "StepDimTol_DatumOrCommonDatum", "None");
	cls_StepDimTol_DatumOrCommonDatum.def(py::init<>());
	cls_StepDimTol_DatumOrCommonDatum.def("CaseNum", (Standard_Integer (StepDimTol_DatumOrCommonDatum::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_DatumOrCommonDatum::CaseNum, "Recognizes a DatumOrCommonDatum Kind Entity that is : 1 -> Datum 2 -> CommonDatumList 0 else", py::arg("ent"));
	cls_StepDimTol_DatumOrCommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumOrCommonDatum::*)() const ) &StepDimTol_DatumOrCommonDatum::Datum, "returns Value as a Datum (Null if another type)");
	cls_StepDimTol_DatumOrCommonDatum.def("CommonDatumList", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceElement> (StepDimTol_DatumOrCommonDatum::*)() const ) &StepDimTol_DatumOrCommonDatum::CommonDatumList, "returns Value as a CommonDatumList (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ToleranceZoneTarget.hxx
	py::class_<StepDimTol_ToleranceZoneTarget, std::unique_ptr<StepDimTol_ToleranceZoneTarget, Deleter<StepDimTol_ToleranceZoneTarget>>, StepData_SelectType> cls_StepDimTol_ToleranceZoneTarget(mod, "StepDimTol_ToleranceZoneTarget", "None");
	cls_StepDimTol_ToleranceZoneTarget.def(py::init<>());
	cls_StepDimTol_ToleranceZoneTarget.def("CaseNum", (Standard_Integer (StepDimTol_ToleranceZoneTarget::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_ToleranceZoneTarget::CaseNum, "Recognizes a ToleranceZoneTarget Kind Entity that is : 1 -> DimensionalLocation 2 -> DimensionalSize 3 -> GeometricTolerance 4 -> GeneralDatumReference 0 else", py::arg("ent"));
	cls_StepDimTol_ToleranceZoneTarget.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepDimTol_ToleranceZoneTarget::*)() const ) &StepDimTol_ToleranceZoneTarget::DimensionalLocation, "returns Value as a DimensionalLocation (Null if another type)");
	cls_StepDimTol_ToleranceZoneTarget.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepDimTol_ToleranceZoneTarget::*)() const ) &StepDimTol_ToleranceZoneTarget::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
	cls_StepDimTol_ToleranceZoneTarget.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_ToleranceZoneTarget::*)() const ) &StepDimTol_ToleranceZoneTarget::GeometricTolerance, "returns Value as a GeometricTolerance (Null if another type)");
	cls_StepDimTol_ToleranceZoneTarget.def("GeneralDatumReference", (opencascade::handle<StepDimTol_GeneralDatumReference> (StepDimTol_ToleranceZoneTarget::*)() const ) &StepDimTol_ToleranceZoneTarget::GeneralDatumReference, "returns Value as a GeneralDatumReference (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfDatumReferenceCompartment, std::unique_ptr<StepDimTol_Array1OfDatumReferenceCompartment, Deleter<StepDimTol_Array1OfDatumReferenceCompartment>>> cls_StepDimTol_Array1OfDatumReferenceCompartment(mod, "StepDimTol_Array1OfDatumReferenceCompartment", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def(py::init<>());
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def(py::init([] (const StepDimTol_Array1OfDatumReferenceCompartment &other) {return new StepDimTol_Array1OfDatumReferenceCompartment(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceCompartment.def(py::init<StepDimTol_Array1OfDatumReferenceCompartment &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def(py::init<const opencascade::handle<StepDimTol_DatumReferenceCompartment> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("begin", (StepDimTol_Array1OfDatumReferenceCompartment::iterator (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("end", (StepDimTol_Array1OfDatumReferenceCompartment::iterator (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("cbegin", (StepDimTol_Array1OfDatumReferenceCompartment::const_iterator (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("cend", (StepDimTol_Array1OfDatumReferenceCompartment::const_iterator (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Init", (void (StepDimTol_Array1OfDatumReferenceCompartment::*)(const opencascade::handle<StepDimTol_DatumReferenceCompartment> &)) &StepDimTol_Array1OfDatumReferenceCompartment::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Size", (Standard_Integer (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::Size, "Size query");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Length", (Standard_Integer (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Lower", (Standard_Integer (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::Lower, "Lower bound");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Upper", (Standard_Integer (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::Upper, "Upper bound");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Assign", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const StepDimTol_Array1OfDatumReferenceCompartment &)) &StepDimTol_Array1OfDatumReferenceCompartment::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Move", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_Array1OfDatumReferenceCompartment::*)(StepDimTol_Array1OfDatumReferenceCompartment &&)) &StepDimTol_Array1OfDatumReferenceCompartment::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("assign", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const StepDimTol_Array1OfDatumReferenceCompartment &)) &StepDimTol_Array1OfDatumReferenceCompartment::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfDatumReferenceCompartment.def("assign", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_Array1OfDatumReferenceCompartment::*)(StepDimTol_Array1OfDatumReferenceCompartment &&)) &StepDimTol_Array1OfDatumReferenceCompartment::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("First", (const opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::First, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("ChangeFirst", (opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)()) &StepDimTol_Array1OfDatumReferenceCompartment::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Last", (const opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)() const ) &StepDimTol_Array1OfDatumReferenceCompartment::Last, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("ChangeLast", (opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)()) &StepDimTol_Array1OfDatumReferenceCompartment::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Value", (const opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceCompartment::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("__call__", (const opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer) const ) &StepDimTol_Array1OfDatumReferenceCompartment::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("ChangeValue", (opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceCompartment::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("__call__", (opencascade::handle<StepDimTol_DatumReferenceCompartment> & (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer)) &StepDimTol_Array1OfDatumReferenceCompartment::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("SetValue", (void (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &)) &StepDimTol_Array1OfDatumReferenceCompartment::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("Resize", (void (StepDimTol_Array1OfDatumReferenceCompartment::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfDatumReferenceCompartment::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfDatumReferenceCompartment.def("__iter__", [](const StepDimTol_Array1OfDatumReferenceCompartment &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfGeometricToleranceModifier, std::unique_ptr<StepDimTol_Array1OfGeometricToleranceModifier, Deleter<StepDimTol_Array1OfGeometricToleranceModifier>>> cls_StepDimTol_Array1OfGeometricToleranceModifier(mod, "StepDimTol_Array1OfGeometricToleranceModifier", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def(py::init<>());
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def(py::init([] (const StepDimTol_Array1OfGeometricToleranceModifier &other) {return new StepDimTol_Array1OfGeometricToleranceModifier(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfGeometricToleranceModifier.def(py::init<StepDimTol_Array1OfGeometricToleranceModifier &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def(py::init<const StepDimTol_GeometricToleranceModifier &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("begin", (StepDimTol_Array1OfGeometricToleranceModifier::iterator (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("end", (StepDimTol_Array1OfGeometricToleranceModifier::iterator (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("cbegin", (StepDimTol_Array1OfGeometricToleranceModifier::const_iterator (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("cend", (StepDimTol_Array1OfGeometricToleranceModifier::const_iterator (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Init", (void (StepDimTol_Array1OfGeometricToleranceModifier::*)(const StepDimTol_GeometricToleranceModifier &)) &StepDimTol_Array1OfGeometricToleranceModifier::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Size", (Standard_Integer (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::Size, "Size query");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Length", (Standard_Integer (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Lower", (Standard_Integer (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::Lower, "Lower bound");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Upper", (Standard_Integer (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::Upper, "Upper bound");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Assign", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const StepDimTol_Array1OfGeometricToleranceModifier &)) &StepDimTol_Array1OfGeometricToleranceModifier::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Move", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(StepDimTol_Array1OfGeometricToleranceModifier &&)) &StepDimTol_Array1OfGeometricToleranceModifier::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("assign", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const StepDimTol_Array1OfGeometricToleranceModifier &)) &StepDimTol_Array1OfGeometricToleranceModifier::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfGeometricToleranceModifier.def("assign", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(StepDimTol_Array1OfGeometricToleranceModifier &&)) &StepDimTol_Array1OfGeometricToleranceModifier::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("First", (const StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::First, "Returns first element");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("ChangeFirst", (StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)()) &StepDimTol_Array1OfGeometricToleranceModifier::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Last", (const StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)() const ) &StepDimTol_Array1OfGeometricToleranceModifier::Last, "Returns last element");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("ChangeLast", (StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)()) &StepDimTol_Array1OfGeometricToleranceModifier::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Value", (const StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer) const ) &StepDimTol_Array1OfGeometricToleranceModifier::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("__call__", (const StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer) const ) &StepDimTol_Array1OfGeometricToleranceModifier::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("ChangeValue", (StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer)) &StepDimTol_Array1OfGeometricToleranceModifier::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("__call__", (StepDimTol_GeometricToleranceModifier & (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer)) &StepDimTol_Array1OfGeometricToleranceModifier::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("SetValue", (void (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer, const StepDimTol_GeometricToleranceModifier &)) &StepDimTol_Array1OfGeometricToleranceModifier::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("Resize", (void (StepDimTol_Array1OfGeometricToleranceModifier::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfGeometricToleranceModifier::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfGeometricToleranceModifier.def("__iter__", [](const StepDimTol_Array1OfGeometricToleranceModifier &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepDimTol_Array1OfToleranceZoneTarget, std::unique_ptr<StepDimTol_Array1OfToleranceZoneTarget, Deleter<StepDimTol_Array1OfToleranceZoneTarget>>> cls_StepDimTol_Array1OfToleranceZoneTarget(mod, "StepDimTol_Array1OfToleranceZoneTarget", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def(py::init<>());
	cls_StepDimTol_Array1OfToleranceZoneTarget.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def(py::init([] (const StepDimTol_Array1OfToleranceZoneTarget &other) {return new StepDimTol_Array1OfToleranceZoneTarget(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepDimTol_Array1OfToleranceZoneTarget.def(py::init<StepDimTol_Array1OfToleranceZoneTarget &&>(), py::arg("theOther"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def(py::init<const StepDimTol_ToleranceZoneTarget &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("begin", (StepDimTol_Array1OfToleranceZoneTarget::iterator (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("end", (StepDimTol_Array1OfToleranceZoneTarget::iterator (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("cbegin", (StepDimTol_Array1OfToleranceZoneTarget::const_iterator (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("cend", (StepDimTol_Array1OfToleranceZoneTarget::const_iterator (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Init", (void (StepDimTol_Array1OfToleranceZoneTarget::*)(const StepDimTol_ToleranceZoneTarget &)) &StepDimTol_Array1OfToleranceZoneTarget::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Size", (Standard_Integer (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::Size, "Size query");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Length", (Standard_Integer (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::Length, "Length query (the same)");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("IsEmpty", (Standard_Boolean (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Lower", (Standard_Integer (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::Lower, "Lower bound");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Upper", (Standard_Integer (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::Upper, "Upper bound");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("IsDeletable", (Standard_Boolean (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::IsDeletable, "myDeletable flag");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("IsAllocated", (Standard_Boolean (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Assign", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const StepDimTol_Array1OfToleranceZoneTarget &)) &StepDimTol_Array1OfToleranceZoneTarget::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfToleranceZoneTarget.def("Move", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(StepDimTol_Array1OfToleranceZoneTarget &&)) &StepDimTol_Array1OfToleranceZoneTarget::Move, "Move assignment", py::arg("theOther"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("assign", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const StepDimTol_Array1OfToleranceZoneTarget &)) &StepDimTol_Array1OfToleranceZoneTarget::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepDimTol_Array1OfToleranceZoneTarget.def("assign", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(StepDimTol_Array1OfToleranceZoneTarget &&)) &StepDimTol_Array1OfToleranceZoneTarget::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("First", (const StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::First, "Returns first element");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("ChangeFirst", (StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)()) &StepDimTol_Array1OfToleranceZoneTarget::ChangeFirst, "Returns first element");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Last", (const StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)() const ) &StepDimTol_Array1OfToleranceZoneTarget::Last, "Returns last element");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("ChangeLast", (StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)()) &StepDimTol_Array1OfToleranceZoneTarget::ChangeLast, "Returns last element");
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Value", (const StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer) const ) &StepDimTol_Array1OfToleranceZoneTarget::Value, "Constant value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("__call__", (const StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer) const ) &StepDimTol_Array1OfToleranceZoneTarget::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("ChangeValue", (StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer)) &StepDimTol_Array1OfToleranceZoneTarget::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("__call__", (StepDimTol_ToleranceZoneTarget & (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer)) &StepDimTol_Array1OfToleranceZoneTarget::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("SetValue", (void (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer, const StepDimTol_ToleranceZoneTarget &)) &StepDimTol_Array1OfToleranceZoneTarget::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("Resize", (void (StepDimTol_Array1OfToleranceZoneTarget::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepDimTol_Array1OfToleranceZoneTarget::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepDimTol_Array1OfToleranceZoneTarget.def("__iter__", [](const StepDimTol_Array1OfToleranceZoneTarget &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_ShapeToleranceSelect.hxx
	py::class_<StepDimTol_ShapeToleranceSelect, std::unique_ptr<StepDimTol_ShapeToleranceSelect, Deleter<StepDimTol_ShapeToleranceSelect>>, StepData_SelectType> cls_StepDimTol_ShapeToleranceSelect(mod, "StepDimTol_ShapeToleranceSelect", "Representation of STEP SELECT type ShapeToleranceSelect");
	cls_StepDimTol_ShapeToleranceSelect.def(py::init<>());
	cls_StepDimTol_ShapeToleranceSelect.def("CaseNum", (Standard_Integer (StepDimTol_ShapeToleranceSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepDimTol_ShapeToleranceSelect::CaseNum, "Recognizes a kind of ShapeToleranceSelect select type 1 -> GeometricTolerance from StepDimTol 2 -> PlusMinusTolerance from StepShape 0 else", py::arg("ent"));
	cls_StepDimTol_ShapeToleranceSelect.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_ShapeToleranceSelect::*)() const ) &StepDimTol_ShapeToleranceSelect::GeometricTolerance, "Returns Value as GeometricTolerance (or Null if another type)");
	cls_StepDimTol_ShapeToleranceSelect.def("PlusMinusTolerance", (opencascade::handle<StepShape_PlusMinusTolerance> (StepDimTol_ShapeToleranceSelect::*)() const ) &StepDimTol_ShapeToleranceSelect::PlusMinusTolerance, "Returns Value as PlusMinusTolerance (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfDatumReferenceModifier.hxx
	py::class_<StepDimTol_HArray1OfDatumReferenceModifier, opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier>, StepDimTol_Array1OfDatumReferenceModifier, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceModifier(mod, "StepDimTol_HArray1OfDatumReferenceModifier", "None");
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceModifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const StepDimTol_Array1OfDatumReferenceModifier &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def("Array1", (const StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_HArray1OfDatumReferenceModifier::*)() const ) &StepDimTol_HArray1OfDatumReferenceModifier::Array1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_HArray1OfDatumReferenceModifier::*)()) &StepDimTol_HArray1OfDatumReferenceModifier::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceModifier::get_type_name, "None");
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceModifier::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfDatumReferenceModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceModifier::*)() const ) &StepDimTol_HArray1OfDatumReferenceModifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfDatumSystemOrReference.hxx
	py::class_<StepDimTol_HArray1OfDatumSystemOrReference, opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference>, StepDimTol_Array1OfDatumSystemOrReference, Standard_Transient> cls_StepDimTol_HArray1OfDatumSystemOrReference(mod, "StepDimTol_HArray1OfDatumSystemOrReference", "None");
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumSystemOrReference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const StepDimTol_Array1OfDatumSystemOrReference &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def("Array1", (const StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_HArray1OfDatumSystemOrReference::*)() const ) &StepDimTol_HArray1OfDatumSystemOrReference::Array1, "None");
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def("ChangeArray1", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_HArray1OfDatumSystemOrReference::*)()) &StepDimTol_HArray1OfDatumSystemOrReference::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumSystemOrReference::get_type_name, "None");
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumSystemOrReference::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfDatumSystemOrReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumSystemOrReference::*)() const ) &StepDimTol_HArray1OfDatumSystemOrReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfDatumReference.hxx
	py::class_<StepDimTol_HArray1OfDatumReference, opencascade::handle<StepDimTol_HArray1OfDatumReference>, StepDimTol_Array1OfDatumReference, Standard_Transient> cls_StepDimTol_HArray1OfDatumReference(mod, "StepDimTol_HArray1OfDatumReference", "None");
	cls_StepDimTol_HArray1OfDatumReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfDatumReference.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfDatumReference.def(py::init<const StepDimTol_Array1OfDatumReference &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfDatumReference.def("Array1", (const StepDimTol_Array1OfDatumReference & (StepDimTol_HArray1OfDatumReference::*)() const ) &StepDimTol_HArray1OfDatumReference::Array1, "None");
	cls_StepDimTol_HArray1OfDatumReference.def("ChangeArray1", (StepDimTol_Array1OfDatumReference & (StepDimTol_HArray1OfDatumReference::*)()) &StepDimTol_HArray1OfDatumReference::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReference::get_type_name, "None");
	cls_StepDimTol_HArray1OfDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReference::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReference::*)() const ) &StepDimTol_HArray1OfDatumReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfDatumReferenceCompartment.hxx
	py::class_<StepDimTol_HArray1OfDatumReferenceCompartment, opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment>, StepDimTol_Array1OfDatumReferenceCompartment, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceCompartment(mod, "StepDimTol_HArray1OfDatumReferenceCompartment", "None");
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceCompartment::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const StepDimTol_Array1OfDatumReferenceCompartment &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("Array1", (const StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_HArray1OfDatumReferenceCompartment::*)() const ) &StepDimTol_HArray1OfDatumReferenceCompartment::Array1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_HArray1OfDatumReferenceCompartment::*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::get_type_name, "None");
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceCompartment::*)() const ) &StepDimTol_HArray1OfDatumReferenceCompartment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfDatumReferenceElement.hxx
	py::class_<StepDimTol_HArray1OfDatumReferenceElement, opencascade::handle<StepDimTol_HArray1OfDatumReferenceElement>, StepDimTol_Array1OfDatumReferenceElement, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceElement(mod, "StepDimTol_HArray1OfDatumReferenceElement", "None");
	cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceElement::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const StepDimTol_Array1OfDatumReferenceElement &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfDatumReferenceElement.def("Array1", (const StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_HArray1OfDatumReferenceElement::*)() const ) &StepDimTol_HArray1OfDatumReferenceElement::Array1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceElement.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_HArray1OfDatumReferenceElement::*)()) &StepDimTol_HArray1OfDatumReferenceElement::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceElement::get_type_name, "None");
	cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceElement::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfDatumReferenceElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceElement::*)() const ) &StepDimTol_HArray1OfDatumReferenceElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfGeometricToleranceModifier.hxx
	py::class_<StepDimTol_HArray1OfGeometricToleranceModifier, opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier>, StepDimTol_Array1OfGeometricToleranceModifier, Standard_Transient> cls_StepDimTol_HArray1OfGeometricToleranceModifier(mod, "StepDimTol_HArray1OfGeometricToleranceModifier", "None");
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfGeometricToleranceModifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const StepDimTol_Array1OfGeometricToleranceModifier &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("Array1", (const StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const ) &StepDimTol_HArray1OfGeometricToleranceModifier::Array1, "None");
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("ChangeArray1", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_name, "None");
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const ) &StepDimTol_HArray1OfGeometricToleranceModifier::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepDimTol_HArray1OfToleranceZoneTarget.hxx
	py::class_<StepDimTol_HArray1OfToleranceZoneTarget, opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget>, StepDimTol_Array1OfToleranceZoneTarget, Standard_Transient> cls_StepDimTol_HArray1OfToleranceZoneTarget(mod, "StepDimTol_HArray1OfToleranceZoneTarget", "None");
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfToleranceZoneTarget::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const StepDimTol_Array1OfToleranceZoneTarget &>(), py::arg("theOther"));
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def("Array1", (const StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_HArray1OfToleranceZoneTarget::*)() const ) &StepDimTol_HArray1OfToleranceZoneTarget::Array1, "None");
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def("ChangeArray1", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_HArray1OfToleranceZoneTarget::*)()) &StepDimTol_HArray1OfToleranceZoneTarget::ChangeArray1, "None");
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfToleranceZoneTarget::get_type_name, "None");
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfToleranceZoneTarget::get_type_descriptor, "None");
	cls_StepDimTol_HArray1OfToleranceZoneTarget.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfToleranceZoneTarget::*)() const ) &StepDimTol_HArray1OfToleranceZoneTarget::DynamicType, "None");


}
