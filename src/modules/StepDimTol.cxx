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
#include <StepDimTol_GeometricToleranceModifier.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <StepDimTol_DatumReferenceModifierType.hxx>
#include <StepDimTol_SimpleDatumReferenceModifier.hxx>
#include <StepDimTol_AreaUnitType.hxx>
#include <StepDimTol_LimitCondition.hxx>
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepShape_DimensionalLocation.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <Standard_Type.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_DatumReferenceModifierWithValue.hxx>
#include <StepData_SelectInt.hxx>
#include <StepDimTol_SimpleDatumReferenceModifierMember.hxx>
#include <StepDimTol_DatumReferenceModifier.hxx>
#include <NCollection_Array1.hxx>
#include <StepDimTol_Array1OfDatumReferenceModifier.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepDimTol_HArray1OfDatumReferenceModifier.hxx>
#include <StepData_Logical.hxx>
#include <StepDimTol_Datum.hxx>
#include <StepDimTol_DatumSystem.hxx>
#include <StepDimTol_DatumReference.hxx>
#include <StepDimTol_DatumSystemOrReference.hxx>
#include <StepDimTol_Array1OfDatumSystemOrReference.hxx>
#include <StepDimTol_HArray1OfDatumSystemOrReference.hxx>
#include <StepDimTol_Array1OfDatumReference.hxx>
#include <StepDimTol_HArray1OfDatumReference.hxx>
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <StepDimTol_AngularityTolerance.hxx>
#include <StepDimTol_HArray1OfDatumReferenceElement.hxx>
#include <StepDimTol_DatumOrCommonDatum.hxx>
#include <StepDimTol_GeneralDatumReference.hxx>
#include <StepDimTol_DatumReferenceCompartment.hxx>
#include <StepDimTol_Array1OfDatumReferenceCompartment.hxx>
#include <StepDimTol_DatumReferenceElement.hxx>
#include <StepDimTol_Array1OfDatumReferenceElement.hxx>
#include <StepDimTol_Array1OfGeometricToleranceModifier.hxx>
#include <StepDimTol_ToleranceZoneTarget.hxx>
#include <StepDimTol_Array1OfToleranceZoneTarget.hxx>
#include <StepDimTol_CircularRunoutTolerance.hxx>
#include <StepDimTol_CoaxialityTolerance.hxx>
#include <StepRepr_CompositeShapeAspect.hxx>
#include <StepDimTol_CommonDatum.hxx>
#include <StepDimTol_ConcentricityTolerance.hxx>
#include <StepDimTol_CylindricityTolerance.hxx>
#include <StepDimTol_DatumFeature.hxx>
#include <StepDimTol_HArray1OfDatumReferenceCompartment.hxx>
#include <StepDimTol_DatumTarget.hxx>
#include <StepDimTol_FlatnessTolerance.hxx>
#include <StepDimTol_GeometricToleranceRelationship.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedUnit.hxx>
#include <StepDimTol_GeometricToleranceWithDefinedAreaUnit.hxx>
#include <StepDimTol_HArray1OfGeometricToleranceModifier.hxx>
#include <StepDimTol_GeometricToleranceWithModifiers.hxx>
#include <StepDimTol_GeometricToleranceWithMaximumTolerance.hxx>
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
#include <StepDimTol_HArray1OfToleranceZoneTarget.hxx>
#include <StepDimTol_LineProfileTolerance.hxx>
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <StepDimTol_ToleranceZone.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <StepDimTol_ToleranceZoneDefinition.hxx>
#include <StepDimTol_NonUniformZoneDefinition.hxx>
#include <StepDimTol_ParallelismTolerance.hxx>
#include <StepDimTol_PerpendicularityTolerance.hxx>
#include <StepDimTol_PlacedDatumTargetFeature.hxx>
#include <StepDimTol_ProjectedZoneDefinition.hxx>
#include <StepDimTol_RoundnessTolerance.hxx>
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <StepDimTol_RunoutZoneOrientation.hxx>
#include <StepDimTol_RunoutZoneDefinition.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <StepDimTol_ShapeToleranceSelect.hxx>
#include <StepDimTol_StraightnessTolerance.hxx>
#include <StepDimTol_SurfaceProfileTolerance.hxx>
#include <StepDimTol_SymmetryTolerance.hxx>
#include <StepDimTol_TotalRunoutTolerance.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(StepDimTol, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.NCollection");

// ENUM: STEPDIMTOL_GEOMETRICTOLERANCEMODIFIER
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


// ENUM: STEPDIMTOL_GEOMETRICTOLERANCETYPE
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


// ENUM: STEPDIMTOL_DATUMREFERENCEMODIFIERTYPE
py::enum_<StepDimTol_DatumReferenceModifierType>(mod, "StepDimTol_DatumReferenceModifierType", "None")
	.value("StepDimTol_CircularOrCylindrical", StepDimTol_DatumReferenceModifierType::StepDimTol_CircularOrCylindrical)
	.value("StepDimTol_Distance", StepDimTol_DatumReferenceModifierType::StepDimTol_Distance)
	.value("StepDimTol_Projected", StepDimTol_DatumReferenceModifierType::StepDimTol_Projected)
	.value("StepDimTol_Spherical", StepDimTol_DatumReferenceModifierType::StepDimTol_Spherical)
	.export_values();


// ENUM: STEPDIMTOL_SIMPLEDATUMREFERENCEMODIFIER
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


// ENUM: STEPDIMTOL_AREAUNITTYPE
py::enum_<StepDimTol_AreaUnitType>(mod, "StepDimTol_AreaUnitType", "None")
	.value("StepDimTol_Circular", StepDimTol_AreaUnitType::StepDimTol_Circular)
	.value("StepDimTol_Rectangular", StepDimTol_AreaUnitType::StepDimTol_Rectangular)
	.value("StepDimTol_Square", StepDimTol_AreaUnitType::StepDimTol_Square)
	.export_values();


// ENUM: STEPDIMTOL_LIMITCONDITION
py::enum_<StepDimTol_LimitCondition>(mod, "StepDimTol_LimitCondition", "None")
	.value("StepDimTol_MaximumMaterialCondition", StepDimTol_LimitCondition::StepDimTol_MaximumMaterialCondition)
	.value("StepDimTol_LeastMaterialCondition", StepDimTol_LimitCondition::StepDimTol_LeastMaterialCondition)
	.value("StepDimTol_RegardlessOfFeatureSize", StepDimTol_LimitCondition::StepDimTol_RegardlessOfFeatureSize)
	.export_values();


// CLASS: STEPDIMTOL_GEOMETRICTOLERANCETARGET
py::class_<StepDimTol_GeometricToleranceTarget, StepData_SelectType> cls_StepDimTol_GeometricToleranceTarget(mod, "StepDimTol_GeometricToleranceTarget", "None");

// Constructors
cls_StepDimTol_GeometricToleranceTarget.def(py::init<>());

// Methods
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_GeometricToleranceTarget::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete_", (void (*)(void *)) &StepDimTol_GeometricToleranceTarget::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_GeometricToleranceTarget::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_GeometricToleranceTarget::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_GeometricToleranceTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_GeometricToleranceTarget::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_GeometricToleranceTarget.def("CaseNum", (Standard_Integer (StepDimTol_GeometricToleranceTarget::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_GeometricToleranceTarget::CaseNum, "Recognizes a GeometricToleranceTarget Kind Entity that is : 1 -> DimensionalLocation 2 -> DimensionalSize 3 -> ProductDefinitionShape 4 -> ShapeAspect 0 else", py::arg("ent"));
cls_StepDimTol_GeometricToleranceTarget.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::DimensionalLocation, "returns Value as a DimensionalLocation (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCE
py::class_<StepDimTol_GeometricTolerance, opencascade::handle<StepDimTol_GeometricTolerance>, Standard_Transient> cls_StepDimTol_GeometricTolerance(mod, "StepDimTol_GeometricTolerance", "Representation of STEP entity GeometricTolerance");

// Constructors
cls_StepDimTol_GeometricTolerance.def(py::init<>());

// Methods
cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("Init", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Name, "Returns field Name");
cls_StepDimTol_GeometricTolerance.def("SetName", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_GeometricTolerance.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Description, "Returns field Description");
cls_StepDimTol_GeometricTolerance.def("SetDescription", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricTolerance::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepDimTol_GeometricTolerance.def("Magnitude", (opencascade::handle<StepBasic_MeasureWithUnit> (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::Magnitude, "Returns field Magnitude");
cls_StepDimTol_GeometricTolerance.def("SetMagnitude", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepDimTol_GeometricTolerance::SetMagnitude, "Set field Magnitude", py::arg("theMagnitude"));
cls_StepDimTol_GeometricTolerance.def("TolerancedShapeAspect", (StepDimTol_GeometricToleranceTarget (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::TolerancedShapeAspect, "Returns field TolerancedShapeAspect Note: in AP214(203) type of this attribute can be only StepRepr_ShapeAspect");
cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP214", py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def("SetTolerancedShapeAspect", (void (StepDimTol_GeometricTolerance::*)(const StepDimTol_GeometricToleranceTarget &)) &StepDimTol_GeometricTolerance::SetTolerancedShapeAspect, "Set field TolerancedShapeAspect AP242", py::arg("theTolerancedShapeAspect"));
cls_StepDimTol_GeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricTolerance::get_type_name, "None");
cls_StepDimTol_GeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricTolerance::get_type_descriptor, "None");
cls_StepDimTol_GeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricTolerance::*)() const) &StepDimTol_GeometricTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMREFERENCEMODIFIERWITHVALUE
py::class_<StepDimTol_DatumReferenceModifierWithValue, opencascade::handle<StepDimTol_DatumReferenceModifierWithValue>, Standard_Transient> cls_StepDimTol_DatumReferenceModifierWithValue(mod, "StepDimTol_DatumReferenceModifierWithValue", "Representation of STEP entity DatumReferenceModifierWithValue");

// Constructors
cls_StepDimTol_DatumReferenceModifierWithValue.def(py::init<>());

// Methods
cls_StepDimTol_DatumReferenceModifierWithValue.def("Init", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::Init, "Initialize all fields (own and inherited)", py::arg("theModifierType"), py::arg("theModifierValue"));
cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierType", (StepDimTol_DatumReferenceModifierType (StepDimTol_DatumReferenceModifierWithValue::*)() const) &StepDimTol_DatumReferenceModifierWithValue::ModifierType, "Returns field ModifierType");
cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierType", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const StepDimTol_DatumReferenceModifierType &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierType, "Set field ModifierType", py::arg("theModifierType"));
cls_StepDimTol_DatumReferenceModifierWithValue.def("ModifierValue", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_DatumReferenceModifierWithValue::*)()) &StepDimTol_DatumReferenceModifierWithValue::ModifierValue, "Returns field ModifierValue");
cls_StepDimTol_DatumReferenceModifierWithValue.def("SetModifierValue", (void (StepDimTol_DatumReferenceModifierWithValue::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_DatumReferenceModifierWithValue::SetModifierValue, "Set field ModifierValue", py::arg("theModifierValue"));
cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_name, "None");
cls_StepDimTol_DatumReferenceModifierWithValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceModifierWithValue::get_type_descriptor, "None");
cls_StepDimTol_DatumReferenceModifierWithValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceModifierWithValue::*)() const) &StepDimTol_DatumReferenceModifierWithValue::DynamicType, "None");

// CLASS: STEPDIMTOL_SIMPLEDATUMREFERENCEMODIFIERMEMBER
py::class_<StepDimTol_SimpleDatumReferenceModifierMember, opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember>, StepData_SelectInt> cls_StepDimTol_SimpleDatumReferenceModifierMember(mod, "StepDimTol_SimpleDatumReferenceModifierMember", "Defines SimpleDatumReferenceModifier as unique member of DatumReferenceModifier Works with an EnumTool");

// Constructors
cls_StepDimTol_SimpleDatumReferenceModifierMember.def(py::init<>());

// Methods
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("HasName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::HasName, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Name", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Name, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetName", (Standard_Boolean (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetName, "None", py::arg(""));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Kind", (Standard_Integer (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Kind, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("EnumText", (Standard_CString (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::EnumText, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetEnumText", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const Standard_Integer, const Standard_CString)) &StepDimTol_SimpleDatumReferenceModifierMember::SetEnumText, "None", py::arg("theValue"), py::arg("theText"));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("SetValue", (void (StepDimTol_SimpleDatumReferenceModifierMember::*)(const StepDimTol_SimpleDatumReferenceModifier)) &StepDimTol_SimpleDatumReferenceModifierMember::SetValue, "None", py::arg("theValue"));
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("Value", (StepDimTol_SimpleDatumReferenceModifier (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::Value, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_name, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SimpleDatumReferenceModifierMember::get_type_descriptor, "None");
cls_StepDimTol_SimpleDatumReferenceModifierMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SimpleDatumReferenceModifierMember::*)() const) &StepDimTol_SimpleDatumReferenceModifierMember::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMREFERENCEMODIFIER
py::class_<StepDimTol_DatumReferenceModifier, StepData_SelectType> cls_StepDimTol_DatumReferenceModifier(mod, "StepDimTol_DatumReferenceModifier", "None");

// Constructors
cls_StepDimTol_DatumReferenceModifier.def(py::init<>());

// Methods
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_DatumReferenceModifier::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete_", (void (*)(void *)) &StepDimTol_DatumReferenceModifier::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_DatumReferenceModifier::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_DatumReferenceModifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_DatumReferenceModifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_DatumReferenceModifier::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_DatumReferenceModifier.def("CaseNum", (Standard_Integer (StepDimTol_DatumReferenceModifier::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_DatumReferenceModifier::CaseNum, "Recognizes a DatumReferenceModifier Kind Entity that is : 1 -> DatumReferenceModifierWithValue 2 -> SimpleDatumReferenceModifierMember 0 else", py::arg("ent"));
cls_StepDimTol_DatumReferenceModifier.def("DatumReferenceModifierWithValue", (opencascade::handle<StepDimTol_DatumReferenceModifierWithValue> (StepDimTol_DatumReferenceModifier::*)() const) &StepDimTol_DatumReferenceModifier::DatumReferenceModifierWithValue, "returns Value as a DatumReferenceModifierWithValue (Null if another type)");
cls_StepDimTol_DatumReferenceModifier.def("SimpleDatumReferenceModifierMember", (opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember> (StepDimTol_DatumReferenceModifier::*)() const) &StepDimTol_DatumReferenceModifier::SimpleDatumReferenceModifierMember, "returns Value as a SimpleDatumReferenceModifierMember (Null if another type)");

// TYPEDEF: STEPDIMTOL_ARRAY1OFDATUMREFERENCEMODIFIER
bind_NCollection_Array1<StepDimTol_DatumReferenceModifier>(mod, "StepDimTol_Array1OfDatumReferenceModifier", py::module_local(false));

// CLASS: STEPDIMTOL_HARRAY1OFDATUMREFERENCEMODIFIER
py::class_<StepDimTol_HArray1OfDatumReferenceModifier, opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier>, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceModifier(mod, "StepDimTol_HArray1OfDatumReferenceModifier", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceModifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfDatumReferenceModifier.def(py::init<const StepDimTol_Array1OfDatumReferenceModifier &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceModifier::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceModifier::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceModifier::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceModifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfDatumReferenceModifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfDatumReferenceModifier::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceModifier::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceModifier::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfDatumReferenceModifier.def("Array1", (const StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_HArray1OfDatumReferenceModifier::*)() const) &StepDimTol_HArray1OfDatumReferenceModifier::Array1, "None");
cls_StepDimTol_HArray1OfDatumReferenceModifier.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceModifier & (StepDimTol_HArray1OfDatumReferenceModifier::*)()) &StepDimTol_HArray1OfDatumReferenceModifier::ChangeArray1, "None");
cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceModifier::get_type_name, "None");
cls_StepDimTol_HArray1OfDatumReferenceModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceModifier::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfDatumReferenceModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceModifier::*)() const) &StepDimTol_HArray1OfDatumReferenceModifier::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUM
py::class_<StepDimTol_Datum, opencascade::handle<StepDimTol_Datum>, StepRepr_ShapeAspect> cls_StepDimTol_Datum(mod, "StepDimTol_Datum", "Representation of STEP entity Datum");

// Constructors
cls_StepDimTol_Datum.def(py::init<>());

// Methods
cls_StepDimTol_Datum.def("Init", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theIdentification"));
cls_StepDimTol_Datum.def("Identification", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_Datum::*)() const) &StepDimTol_Datum::Identification, "Returns field Identification");
cls_StepDimTol_Datum.def("SetIdentification", (void (StepDimTol_Datum::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_Datum::SetIdentification, "Set field Identification", py::arg("theIdentification"));
cls_StepDimTol_Datum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_Datum::get_type_name, "None");
cls_StepDimTol_Datum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_Datum::get_type_descriptor, "None");
cls_StepDimTol_Datum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_Datum::*)() const) &StepDimTol_Datum::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMSYSTEMORREFERENCE
py::class_<StepDimTol_DatumSystemOrReference, StepData_SelectType> cls_StepDimTol_DatumSystemOrReference(mod, "StepDimTol_DatumSystemOrReference", "None");

// Constructors
cls_StepDimTol_DatumSystemOrReference.def(py::init<>());

// Methods
// cls_StepDimTol_DatumSystemOrReference.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_DatumSystemOrReference::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_DatumSystemOrReference.def_static("operator delete_", (void (*)(void *)) &StepDimTol_DatumSystemOrReference::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_DatumSystemOrReference.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_DatumSystemOrReference::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_DatumSystemOrReference.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_DatumSystemOrReference::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_DatumSystemOrReference.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_DatumSystemOrReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_DatumSystemOrReference.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_DatumSystemOrReference::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_DatumSystemOrReference.def("CaseNum", (Standard_Integer (StepDimTol_DatumSystemOrReference::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_DatumSystemOrReference::CaseNum, "Recognizes a DatumSystemOrReference Kind Entity that is : 1 -> DatumSystem 2 -> DatumReference 0 else", py::arg("ent"));
cls_StepDimTol_DatumSystemOrReference.def("DatumSystem", (opencascade::handle<StepDimTol_DatumSystem> (StepDimTol_DatumSystemOrReference::*)() const) &StepDimTol_DatumSystemOrReference::DatumSystem, "returns Value as a DatumSystem (Null if another type)");
cls_StepDimTol_DatumSystemOrReference.def("DatumReference", (opencascade::handle<StepDimTol_DatumReference> (StepDimTol_DatumSystemOrReference::*)() const) &StepDimTol_DatumSystemOrReference::DatumReference, "returns Value as a DatumReference (Null if another type)");

// TYPEDEF: STEPDIMTOL_ARRAY1OFDATUMSYSTEMORREFERENCE
bind_NCollection_Array1<StepDimTol_DatumSystemOrReference>(mod, "StepDimTol_Array1OfDatumSystemOrReference", py::module_local(false));

// CLASS: STEPDIMTOL_HARRAY1OFDATUMSYSTEMORREFERENCE
py::class_<StepDimTol_HArray1OfDatumSystemOrReference, opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference>, Standard_Transient> cls_StepDimTol_HArray1OfDatumSystemOrReference(mod, "StepDimTol_HArray1OfDatumSystemOrReference", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumSystemOrReference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfDatumSystemOrReference.def(py::init<const StepDimTol_Array1OfDatumSystemOrReference &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumSystemOrReference::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfDatumSystemOrReference::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumSystemOrReference::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfDatumSystemOrReference::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfDatumSystemOrReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfDatumSystemOrReference::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumSystemOrReference::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumSystemOrReference::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfDatumSystemOrReference.def("Array1", (const StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_HArray1OfDatumSystemOrReference::*)() const) &StepDimTol_HArray1OfDatumSystemOrReference::Array1, "None");
cls_StepDimTol_HArray1OfDatumSystemOrReference.def("ChangeArray1", (StepDimTol_Array1OfDatumSystemOrReference & (StepDimTol_HArray1OfDatumSystemOrReference::*)()) &StepDimTol_HArray1OfDatumSystemOrReference::ChangeArray1, "None");
cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumSystemOrReference::get_type_name, "None");
cls_StepDimTol_HArray1OfDatumSystemOrReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumSystemOrReference::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfDatumSystemOrReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumSystemOrReference::*)() const) &StepDimTol_HArray1OfDatumSystemOrReference::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMREFERENCE
py::class_<StepDimTol_DatumReference, opencascade::handle<StepDimTol_DatumReference>, Standard_Transient> cls_StepDimTol_DatumReference(mod, "StepDimTol_DatumReference", "Representation of STEP entity DatumReference");

// Constructors
cls_StepDimTol_DatumReference.def(py::init<>());

// Methods
cls_StepDimTol_DatumReference.def("Init", (void (StepDimTol_DatumReference::*)(const Standard_Integer, const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::Init, "Initialize all fields (own and inherited)", py::arg("thePrecedence"), py::arg("theReferencedDatum"));
cls_StepDimTol_DatumReference.def("Precedence", (Standard_Integer (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::Precedence, "Returns field Precedence");
cls_StepDimTol_DatumReference.def("SetPrecedence", (void (StepDimTol_DatumReference::*)(const Standard_Integer)) &StepDimTol_DatumReference::SetPrecedence, "Set field Precedence", py::arg("thePrecedence"));
cls_StepDimTol_DatumReference.def("ReferencedDatum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::ReferencedDatum, "Returns field ReferencedDatum");
cls_StepDimTol_DatumReference.def("SetReferencedDatum", (void (StepDimTol_DatumReference::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_DatumReference::SetReferencedDatum, "Set field ReferencedDatum", py::arg("theReferencedDatum"));
cls_StepDimTol_DatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReference::get_type_name, "None");
cls_StepDimTol_DatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReference::get_type_descriptor, "None");
cls_StepDimTol_DatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReference::*)() const) &StepDimTol_DatumReference::DynamicType, "None");

// TYPEDEF: STEPDIMTOL_ARRAY1OFDATUMREFERENCE
bind_NCollection_Array1<opencascade::handle<StepDimTol_DatumReference> >(mod, "StepDimTol_Array1OfDatumReference", py::module_local(false));

// CLASS: STEPDIMTOL_HARRAY1OFDATUMREFERENCE
py::class_<StepDimTol_HArray1OfDatumReference, opencascade::handle<StepDimTol_HArray1OfDatumReference>, Standard_Transient> cls_StepDimTol_HArray1OfDatumReference(mod, "StepDimTol_HArray1OfDatumReference", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfDatumReference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfDatumReference.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfDatumReference.def(py::init<const StepDimTol_Array1OfDatumReference &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReference::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReference::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReference::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReference::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfDatumReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfDatumReference::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReference::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfDatumReference.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReference::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfDatumReference.def("Array1", (const StepDimTol_Array1OfDatumReference & (StepDimTol_HArray1OfDatumReference::*)() const) &StepDimTol_HArray1OfDatumReference::Array1, "None");
cls_StepDimTol_HArray1OfDatumReference.def("ChangeArray1", (StepDimTol_Array1OfDatumReference & (StepDimTol_HArray1OfDatumReference::*)()) &StepDimTol_HArray1OfDatumReference::ChangeArray1, "None");
cls_StepDimTol_HArray1OfDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReference::get_type_name, "None");
cls_StepDimTol_HArray1OfDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReference::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReference::*)() const) &StepDimTol_HArray1OfDatumReference::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCEWITHDATUMREFERENCE
py::class_<StepDimTol_GeometricToleranceWithDatumReference, opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDatumReference(mod, "StepDimTol_GeometricToleranceWithDatumReference", "Representation of STEP entity GeometricToleranceWithDatumReference");

// Constructors
cls_StepDimTol_GeometricToleranceWithDatumReference.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystem", (opencascade::handle<StepDimTol_HArray1OfDatumReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystem, "Returns field DatumSystem AP214");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystemAP242", (opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystemAP242, "Returns field DatumSystem AP242");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP214", py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP242", py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DynamicType, "None");

// CLASS: STEPDIMTOL_ANGULARITYTOLERANCE
py::class_<StepDimTol_AngularityTolerance, opencascade::handle<StepDimTol_AngularityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_AngularityTolerance(mod, "StepDimTol_AngularityTolerance", "Representation of STEP entity AngularityTolerance");

// Constructors
cls_StepDimTol_AngularityTolerance.def(py::init<>());

// Methods
cls_StepDimTol_AngularityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_AngularityTolerance::get_type_name, "None");
cls_StepDimTol_AngularityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_AngularityTolerance::get_type_descriptor, "None");
cls_StepDimTol_AngularityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_AngularityTolerance::*)() const) &StepDimTol_AngularityTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMORCOMMONDATUM
py::class_<StepDimTol_DatumOrCommonDatum, StepData_SelectType> cls_StepDimTol_DatumOrCommonDatum(mod, "StepDimTol_DatumOrCommonDatum", "None");

// Constructors
cls_StepDimTol_DatumOrCommonDatum.def(py::init<>());

// Methods
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_DatumOrCommonDatum::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete_", (void (*)(void *)) &StepDimTol_DatumOrCommonDatum::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_DatumOrCommonDatum::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_DatumOrCommonDatum::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_DatumOrCommonDatum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_DatumOrCommonDatum.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_DatumOrCommonDatum::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_DatumOrCommonDatum.def("CaseNum", (Standard_Integer (StepDimTol_DatumOrCommonDatum::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_DatumOrCommonDatum::CaseNum, "Recognizes a DatumOrCommonDatum Kind Entity that is : 1 -> Datum 2 -> CommonDatumList 0 else", py::arg("ent"));
cls_StepDimTol_DatumOrCommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_DatumOrCommonDatum::*)() const) &StepDimTol_DatumOrCommonDatum::Datum, "returns Value as a Datum (Null if another type)");
cls_StepDimTol_DatumOrCommonDatum.def("CommonDatumList", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceElement> (StepDimTol_DatumOrCommonDatum::*)() const) &StepDimTol_DatumOrCommonDatum::CommonDatumList, "returns Value as a CommonDatumList (Null if another type)");

// CLASS: STEPDIMTOL_GENERALDATUMREFERENCE
py::class_<StepDimTol_GeneralDatumReference, opencascade::handle<StepDimTol_GeneralDatumReference>, StepRepr_ShapeAspect> cls_StepDimTol_GeneralDatumReference(mod, "StepDimTol_GeneralDatumReference", "Representation of STEP entity GeneralDatumReference");

// Constructors
cls_StepDimTol_GeneralDatumReference.def(py::init<>());

// Methods
cls_StepDimTol_GeneralDatumReference.def("Init", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const StepDimTol_DatumOrCommonDatum &, const Standard_Boolean, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theBase"), py::arg("theHasModifiers"), py::arg("theModifiers"));
cls_StepDimTol_GeneralDatumReference.def("Base", (StepDimTol_DatumOrCommonDatum (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Base, "Returns field Base");
cls_StepDimTol_GeneralDatumReference.def("SetBase", (void (StepDimTol_GeneralDatumReference::*)(const StepDimTol_DatumOrCommonDatum &)) &StepDimTol_GeneralDatumReference::SetBase, "Set field Base", py::arg("theBase"));
cls_StepDimTol_GeneralDatumReference.def("HasModifiers", (Standard_Boolean (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::HasModifiers, "Indicates is field Modifiers exist");
cls_StepDimTol_GeneralDatumReference.def("Modifiers", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> (StepDimTol_GeneralDatumReference::*)()) &StepDimTol_GeneralDatumReference::Modifiers, "Returns field Modifiers");
cls_StepDimTol_GeneralDatumReference.def("SetModifiers", (void (StepDimTol_GeneralDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> &)) &StepDimTol_GeneralDatumReference::SetModifiers, "Set field Modifiers", py::arg("theModifiers"));
cls_StepDimTol_GeneralDatumReference.def("NbModifiers", (Standard_Integer (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::NbModifiers, "Returns number of Modifiers");
cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (StepDimTol_DatumReferenceModifier (StepDimTol_GeneralDatumReference::*)(const Standard_Integer) const) &StepDimTol_GeneralDatumReference::ModifiersValue, "Returns Modifiers with the given number", py::arg("theNum"));
cls_StepDimTol_GeneralDatumReference.def("ModifiersValue", (void (StepDimTol_GeneralDatumReference::*)(const Standard_Integer, const StepDimTol_DatumReferenceModifier &)) &StepDimTol_GeneralDatumReference::ModifiersValue, "Sets Modifiers with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_GeneralDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeneralDatumReference::get_type_name, "None");
cls_StepDimTol_GeneralDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeneralDatumReference::get_type_descriptor, "None");
cls_StepDimTol_GeneralDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeneralDatumReference::*)() const) &StepDimTol_GeneralDatumReference::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMREFERENCECOMPARTMENT
py::class_<StepDimTol_DatumReferenceCompartment, opencascade::handle<StepDimTol_DatumReferenceCompartment>, StepDimTol_GeneralDatumReference> cls_StepDimTol_DatumReferenceCompartment(mod, "StepDimTol_DatumReferenceCompartment", "Representation of STEP entity DatumReferenceCompartment");

// Constructors
cls_StepDimTol_DatumReferenceCompartment.def(py::init<>());

// Methods
cls_StepDimTol_DatumReferenceCompartment.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceCompartment::get_type_name, "None");
cls_StepDimTol_DatumReferenceCompartment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceCompartment::get_type_descriptor, "None");
cls_StepDimTol_DatumReferenceCompartment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceCompartment::*)() const) &StepDimTol_DatumReferenceCompartment::DynamicType, "None");

// TYPEDEF: STEPDIMTOL_ARRAY1OFDATUMREFERENCECOMPARTMENT
bind_NCollection_Array1<opencascade::handle<StepDimTol_DatumReferenceCompartment> >(mod, "StepDimTol_Array1OfDatumReferenceCompartment", py::module_local(false));

// CLASS: STEPDIMTOL_DATUMREFERENCEELEMENT
py::class_<StepDimTol_DatumReferenceElement, opencascade::handle<StepDimTol_DatumReferenceElement>, StepDimTol_GeneralDatumReference> cls_StepDimTol_DatumReferenceElement(mod, "StepDimTol_DatumReferenceElement", "Representation of STEP entity DatumReferenceElement");

// Constructors
cls_StepDimTol_DatumReferenceElement.def(py::init<>());

// Methods
cls_StepDimTol_DatumReferenceElement.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumReferenceElement::get_type_name, "None");
cls_StepDimTol_DatumReferenceElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumReferenceElement::get_type_descriptor, "None");
cls_StepDimTol_DatumReferenceElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumReferenceElement::*)() const) &StepDimTol_DatumReferenceElement::DynamicType, "None");

// TYPEDEF: STEPDIMTOL_ARRAY1OFDATUMREFERENCEELEMENT
bind_NCollection_Array1<opencascade::handle<StepDimTol_DatumReferenceElement> >(mod, "StepDimTol_Array1OfDatumReferenceElement", py::module_local(false));

// TYPEDEF: STEPDIMTOL_ARRAY1OFGEOMETRICTOLERANCEMODIFIER
bind_NCollection_Array1<StepDimTol_GeometricToleranceModifier>(mod, "StepDimTol_Array1OfGeometricToleranceModifier", py::module_local(false));

// CLASS: STEPDIMTOL_TOLERANCEZONETARGET
py::class_<StepDimTol_ToleranceZoneTarget, StepData_SelectType> cls_StepDimTol_ToleranceZoneTarget(mod, "StepDimTol_ToleranceZoneTarget", "None");

// Constructors
cls_StepDimTol_ToleranceZoneTarget.def(py::init<>());

// Methods
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_ToleranceZoneTarget::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator delete_", (void (*)(void *)) &StepDimTol_ToleranceZoneTarget::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_ToleranceZoneTarget::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_ToleranceZoneTarget::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_ToleranceZoneTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_ToleranceZoneTarget.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_ToleranceZoneTarget::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_ToleranceZoneTarget.def("CaseNum", (Standard_Integer (StepDimTol_ToleranceZoneTarget::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_ToleranceZoneTarget::CaseNum, "Recognizes a ToleranceZoneTarget Kind Entity that is : 1 -> DimensionalLocation 2 -> DimensionalSize 3 -> GeometricTolerance 4 -> GeneralDatumReference 0 else", py::arg("ent"));
cls_StepDimTol_ToleranceZoneTarget.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepDimTol_ToleranceZoneTarget::*)() const) &StepDimTol_ToleranceZoneTarget::DimensionalLocation, "returns Value as a DimensionalLocation (Null if another type)");
cls_StepDimTol_ToleranceZoneTarget.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepDimTol_ToleranceZoneTarget::*)() const) &StepDimTol_ToleranceZoneTarget::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepDimTol_ToleranceZoneTarget.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_ToleranceZoneTarget::*)() const) &StepDimTol_ToleranceZoneTarget::GeometricTolerance, "returns Value as a GeometricTolerance (Null if another type)");
cls_StepDimTol_ToleranceZoneTarget.def("GeneralDatumReference", (opencascade::handle<StepDimTol_GeneralDatumReference> (StepDimTol_ToleranceZoneTarget::*)() const) &StepDimTol_ToleranceZoneTarget::GeneralDatumReference, "returns Value as a GeneralDatumReference (Null if another type)");

// TYPEDEF: STEPDIMTOL_ARRAY1OFTOLERANCEZONETARGET
bind_NCollection_Array1<StepDimTol_ToleranceZoneTarget>(mod, "StepDimTol_Array1OfToleranceZoneTarget", py::module_local(false));

// CLASS: STEPDIMTOL_CIRCULARRUNOUTTOLERANCE
py::class_<StepDimTol_CircularRunoutTolerance, opencascade::handle<StepDimTol_CircularRunoutTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_CircularRunoutTolerance(mod, "StepDimTol_CircularRunoutTolerance", "Representation of STEP entity CircularRunoutTolerance");

// Constructors
cls_StepDimTol_CircularRunoutTolerance.def(py::init<>());

// Methods
cls_StepDimTol_CircularRunoutTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CircularRunoutTolerance::get_type_name, "None");
cls_StepDimTol_CircularRunoutTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CircularRunoutTolerance::get_type_descriptor, "None");
cls_StepDimTol_CircularRunoutTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CircularRunoutTolerance::*)() const) &StepDimTol_CircularRunoutTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_COAXIALITYTOLERANCE
py::class_<StepDimTol_CoaxialityTolerance, opencascade::handle<StepDimTol_CoaxialityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_CoaxialityTolerance(mod, "StepDimTol_CoaxialityTolerance", "Representation of STEP entity CoaxialityTolerance");

// Constructors
cls_StepDimTol_CoaxialityTolerance.def(py::init<>());

// Methods
cls_StepDimTol_CoaxialityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CoaxialityTolerance::get_type_name, "None");
cls_StepDimTol_CoaxialityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CoaxialityTolerance::get_type_descriptor, "None");
cls_StepDimTol_CoaxialityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CoaxialityTolerance::*)() const) &StepDimTol_CoaxialityTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_COMMONDATUM
py::class_<StepDimTol_CommonDatum, opencascade::handle<StepDimTol_CommonDatum>, StepRepr_CompositeShapeAspect> cls_StepDimTol_CommonDatum(mod, "StepDimTol_CommonDatum", "Representation of STEP entity CommonDatum");

// Constructors
cls_StepDimTol_CommonDatum.def(py::init<>());

// Methods
cls_StepDimTol_CommonDatum.def("Init", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_CommonDatum::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theDatum_Name"), py::arg("theDatum_Description"), py::arg("theDatum_OfShape"), py::arg("theDatum_ProductDefinitional"), py::arg("theDatum_Identification"));
cls_StepDimTol_CommonDatum.def("Datum", (opencascade::handle<StepDimTol_Datum> (StepDimTol_CommonDatum::*)() const) &StepDimTol_CommonDatum::Datum, "Returns data for supertype Datum");
cls_StepDimTol_CommonDatum.def("SetDatum", (void (StepDimTol_CommonDatum::*)(const opencascade::handle<StepDimTol_Datum> &)) &StepDimTol_CommonDatum::SetDatum, "Set data for supertype Datum", py::arg("theDatum"));
cls_StepDimTol_CommonDatum.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CommonDatum::get_type_name, "None");
cls_StepDimTol_CommonDatum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CommonDatum::get_type_descriptor, "None");
cls_StepDimTol_CommonDatum.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CommonDatum::*)() const) &StepDimTol_CommonDatum::DynamicType, "None");

// CLASS: STEPDIMTOL_CONCENTRICITYTOLERANCE
py::class_<StepDimTol_ConcentricityTolerance, opencascade::handle<StepDimTol_ConcentricityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_ConcentricityTolerance(mod, "StepDimTol_ConcentricityTolerance", "Representation of STEP entity ConcentricityTolerance");

// Constructors
cls_StepDimTol_ConcentricityTolerance.def(py::init<>());

// Methods
cls_StepDimTol_ConcentricityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ConcentricityTolerance::get_type_name, "None");
cls_StepDimTol_ConcentricityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ConcentricityTolerance::get_type_descriptor, "None");
cls_StepDimTol_ConcentricityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ConcentricityTolerance::*)() const) &StepDimTol_ConcentricityTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_CYLINDRICITYTOLERANCE
py::class_<StepDimTol_CylindricityTolerance, opencascade::handle<StepDimTol_CylindricityTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_CylindricityTolerance(mod, "StepDimTol_CylindricityTolerance", "Representation of STEP entity CylindricityTolerance");

// Constructors
cls_StepDimTol_CylindricityTolerance.def(py::init<>());

// Methods
cls_StepDimTol_CylindricityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_CylindricityTolerance::get_type_name, "None");
cls_StepDimTol_CylindricityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_CylindricityTolerance::get_type_descriptor, "None");
cls_StepDimTol_CylindricityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_CylindricityTolerance::*)() const) &StepDimTol_CylindricityTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMFEATURE
py::class_<StepDimTol_DatumFeature, opencascade::handle<StepDimTol_DatumFeature>, StepRepr_ShapeAspect> cls_StepDimTol_DatumFeature(mod, "StepDimTol_DatumFeature", "Representation of STEP entity DatumFeature");

// Constructors
cls_StepDimTol_DatumFeature.def(py::init<>());

// Methods
cls_StepDimTol_DatumFeature.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumFeature::get_type_name, "None");
cls_StepDimTol_DatumFeature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumFeature::get_type_descriptor, "None");
cls_StepDimTol_DatumFeature.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumFeature::*)() const) &StepDimTol_DatumFeature::DynamicType, "None");

// CLASS: STEPDIMTOL_HARRAY1OFDATUMREFERENCECOMPARTMENT
py::class_<StepDimTol_HArray1OfDatumReferenceCompartment, opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment>, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceCompartment(mod, "StepDimTol_HArray1OfDatumReferenceCompartment", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceCompartment::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def(py::init<const StepDimTol_Array1OfDatumReferenceCompartment &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceCompartment::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("Array1", (const StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_HArray1OfDatumReferenceCompartment::*)() const) &StepDimTol_HArray1OfDatumReferenceCompartment::Array1, "None");
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceCompartment & (StepDimTol_HArray1OfDatumReferenceCompartment::*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::ChangeArray1, "None");
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::get_type_name, "None");
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceCompartment::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfDatumReferenceCompartment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceCompartment::*)() const) &StepDimTol_HArray1OfDatumReferenceCompartment::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMSYSTEM
py::class_<StepDimTol_DatumSystem, opencascade::handle<StepDimTol_DatumSystem>, StepRepr_ShapeAspect> cls_StepDimTol_DatumSystem(mod, "StepDimTol_DatumSystem", "Representation of STEP entity DatumSystem");

// Constructors
cls_StepDimTol_DatumSystem.def(py::init<>());

// Methods
cls_StepDimTol_DatumSystem.def("Init", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theConstituents"));
cls_StepDimTol_DatumSystem.def("Constituents", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> (StepDimTol_DatumSystem::*)()) &StepDimTol_DatumSystem::Constituents, "Returns field Constituents");
cls_StepDimTol_DatumSystem.def("SetConstituents", (void (StepDimTol_DatumSystem::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReferenceCompartment> &)) &StepDimTol_DatumSystem::SetConstituents, "Set field Constituents", py::arg("theConstituents"));
cls_StepDimTol_DatumSystem.def("NbConstituents", (Standard_Integer (StepDimTol_DatumSystem::*)() const) &StepDimTol_DatumSystem::NbConstituents, "Returns number of Constituents");
cls_StepDimTol_DatumSystem.def("ConstituentsValue", (opencascade::handle<StepDimTol_DatumReferenceCompartment> (StepDimTol_DatumSystem::*)(const Standard_Integer) const) &StepDimTol_DatumSystem::ConstituentsValue, "Returns Constituents with the given number", py::arg("num"));
cls_StepDimTol_DatumSystem.def("ConstituentsValue", (void (StepDimTol_DatumSystem::*)(const Standard_Integer, const opencascade::handle<StepDimTol_DatumReferenceCompartment> &)) &StepDimTol_DatumSystem::ConstituentsValue, "Sets Constituents with given number", py::arg("num"), py::arg("theItem"));
cls_StepDimTol_DatumSystem.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumSystem::get_type_name, "None");
cls_StepDimTol_DatumSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumSystem::get_type_descriptor, "None");
cls_StepDimTol_DatumSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumSystem::*)() const) &StepDimTol_DatumSystem::DynamicType, "None");

// CLASS: STEPDIMTOL_DATUMTARGET
py::class_<StepDimTol_DatumTarget, opencascade::handle<StepDimTol_DatumTarget>, StepRepr_ShapeAspect> cls_StepDimTol_DatumTarget(mod, "StepDimTol_DatumTarget", "Representation of STEP entity DatumTarget");

// Constructors
cls_StepDimTol_DatumTarget.def(py::init<>());

// Methods
cls_StepDimTol_DatumTarget.def("Init", (void (StepDimTol_DatumTarget::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_DatumTarget::Init, "Initialize all fields (own and inherited)", py::arg("theShapeAspect_Name"), py::arg("theShapeAspect_Description"), py::arg("theShapeAspect_OfShape"), py::arg("theShapeAspect_ProductDefinitional"), py::arg("theTargetId"));
cls_StepDimTol_DatumTarget.def("TargetId", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_DatumTarget::*)() const) &StepDimTol_DatumTarget::TargetId, "Returns field TargetId");
cls_StepDimTol_DatumTarget.def("SetTargetId", (void (StepDimTol_DatumTarget::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_DatumTarget::SetTargetId, "Set field TargetId", py::arg("theTargetId"));
cls_StepDimTol_DatumTarget.def_static("get_type_name_", (const char * (*)()) &StepDimTol_DatumTarget::get_type_name, "None");
cls_StepDimTol_DatumTarget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_DatumTarget::get_type_descriptor, "None");
cls_StepDimTol_DatumTarget.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_DatumTarget::*)() const) &StepDimTol_DatumTarget::DynamicType, "None");

// CLASS: STEPDIMTOL_FLATNESSTOLERANCE
py::class_<StepDimTol_FlatnessTolerance, opencascade::handle<StepDimTol_FlatnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_FlatnessTolerance(mod, "StepDimTol_FlatnessTolerance", "Representation of STEP entity FlatnessTolerance");

// Constructors
cls_StepDimTol_FlatnessTolerance.def(py::init<>());

// Methods
cls_StepDimTol_FlatnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_FlatnessTolerance::get_type_name, "None");
cls_StepDimTol_FlatnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_FlatnessTolerance::get_type_descriptor, "None");
cls_StepDimTol_FlatnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_FlatnessTolerance::*)() const) &StepDimTol_FlatnessTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCERELATIONSHIP
py::class_<StepDimTol_GeometricToleranceRelationship, opencascade::handle<StepDimTol_GeometricToleranceRelationship>, Standard_Transient> cls_StepDimTol_GeometricToleranceRelationship(mod, "StepDimTol_GeometricToleranceRelationship", "Representation of STEP entity GeometricToleranceRelationship");

// Constructors
cls_StepDimTol_GeometricToleranceRelationship.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceRelationship.def("Init", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepDimTol_GeometricTolerance> &, const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theRelatingGeometricTolerance"), py::arg("theRelatedGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::Name, "Returns field Name");
cls_StepDimTol_GeometricToleranceRelationship.def("SetName", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_GeometricToleranceRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::Description, "Returns field Description");
cls_StepDimTol_GeometricToleranceRelationship.def("SetDescription", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_GeometricToleranceRelationship::SetDescription, "Set field Description", py::arg("theDescription"));
cls_StepDimTol_GeometricToleranceRelationship.def("RelatingGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::RelatingGeometricTolerance, "Returns field RelatingGeometricTolerance");
cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatingGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatingGeometricTolerance, "Set field RelatingGeometricTolerance", py::arg("theRelatingGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def("RelatedGeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::RelatedGeometricTolerance, "Returns field RelatedGeometricTolerance");
cls_StepDimTol_GeometricToleranceRelationship.def("SetRelatedGeometricTolerance", (void (StepDimTol_GeometricToleranceRelationship::*)(const opencascade::handle<StepDimTol_GeometricTolerance> &)) &StepDimTol_GeometricToleranceRelationship::SetRelatedGeometricTolerance, "Set field RelatedGeometricTolerance", py::arg("theRelatedGeometricTolerance"));
cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_name, "None");
cls_StepDimTol_GeometricToleranceRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceRelationship::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceRelationship::*)() const) &StepDimTol_GeometricToleranceRelationship::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCEWITHDEFINEDUNIT
py::class_<StepDimTol_GeometricToleranceWithDefinedUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedUnit>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDefinedUnit(mod, "StepDimTol_GeometricToleranceWithDefinedUnit", "Representation of STEP entity GeometricToleranceWithDefinedUnit");

// Constructors
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP214", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::Init, "Initialize all fields (own and inherited) AP242", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("UnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedUnit::UnitSize, "Returns field UnitSize");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("SetUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedUnit::SetUnitSize, "Set field UnitSize", py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedUnit::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDefinedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedUnit::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCEWITHDEFINEDAREAUNIT
py::class_<StepDimTol_GeometricToleranceWithDefinedAreaUnit, opencascade::handle<StepDimTol_GeometricToleranceWithDefinedAreaUnit>, StepDimTol_GeometricToleranceWithDefinedUnit> cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit(mod, "StepDimTol_GeometricToleranceWithDefinedAreaUnit", "Representation of STEP entity GeometricToleranceWithDefinedAreaUnit");

// Constructors
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("Init", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_AreaUnitType, const Standard_Boolean, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theUnitSize"), py::arg("theAreaType"), py::arg("theHasSecondUnitSize"), py::arg("theSecondUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("AreaType", (StepDimTol_AreaUnitType (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::AreaType, "Returns field AreaType");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetAreaType", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const StepDimTol_AreaUnitType)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetAreaType, "Set field AreaType", py::arg("theAreaType"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SecondUnitSize", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SecondUnitSize, "Returns field SecondUnitSize");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("SetSecondUnitSize", (void (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::SetSecondUnitSize, "Set field SecondUnitSize", py::arg("theSecondUnitSize"));
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("HasSecondUnitSize", (Standard_Boolean (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::HasSecondUnitSize, "Indicates if SecondUnitSize field exist");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDefinedAreaUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDefinedAreaUnit::*)() const) &StepDimTol_GeometricToleranceWithDefinedAreaUnit::DynamicType, "None");

// CLASS: STEPDIMTOL_HARRAY1OFGEOMETRICTOLERANCEMODIFIER
py::class_<StepDimTol_HArray1OfGeometricToleranceModifier, opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier>, Standard_Transient> cls_StepDimTol_HArray1OfGeometricToleranceModifier(mod, "StepDimTol_HArray1OfGeometricToleranceModifier", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfGeometricToleranceModifier::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def(py::init<const StepDimTol_Array1OfGeometricToleranceModifier &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfGeometricToleranceModifier::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("Array1", (const StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const) &StepDimTol_HArray1OfGeometricToleranceModifier::Array1, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("ChangeArray1", (StepDimTol_Array1OfGeometricToleranceModifier & (StepDimTol_HArray1OfGeometricToleranceModifier::*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::ChangeArray1, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_name, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfGeometricToleranceModifier::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfGeometricToleranceModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfGeometricToleranceModifier::*)() const) &StepDimTol_HArray1OfGeometricToleranceModifier::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCEWITHMODIFIERS
py::class_<StepDimTol_GeometricToleranceWithModifiers, opencascade::handle<StepDimTol_GeometricToleranceWithModifiers>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithModifiers(mod, "StepDimTol_GeometricToleranceWithModifiers", "Representation of STEP entity GeometricToleranceWithModifiers");

// Constructors
cls_StepDimTol_GeometricToleranceWithModifiers.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceWithModifiers.def("Init", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &)) &StepDimTol_GeometricToleranceWithModifiers::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theModifiers"));
cls_StepDimTol_GeometricToleranceWithModifiers.def("Modifiers", (opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> (StepDimTol_GeometricToleranceWithModifiers::*)() const) &StepDimTol_GeometricToleranceWithModifiers::Modifiers, "Returns field Modifiers");
cls_StepDimTol_GeometricToleranceWithModifiers.def("SetModifiers", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &)) &StepDimTol_GeometricToleranceWithModifiers::SetModifiers, "Set field Modifiers", py::arg("theModifiers"));
cls_StepDimTol_GeometricToleranceWithModifiers.def("NbModifiers", (Standard_Integer (StepDimTol_GeometricToleranceWithModifiers::*)() const) &StepDimTol_GeometricToleranceWithModifiers::NbModifiers, "Returns number of modifiers");
cls_StepDimTol_GeometricToleranceWithModifiers.def("ModifierValue", (StepDimTol_GeometricToleranceModifier (StepDimTol_GeometricToleranceWithModifiers::*)(const Standard_Integer) const) &StepDimTol_GeometricToleranceWithModifiers::ModifierValue, "Returns modifier with the given number", py::arg("theNum"));
cls_StepDimTol_GeometricToleranceWithModifiers.def("SetModifierValue", (void (StepDimTol_GeometricToleranceWithModifiers::*)(const Standard_Integer, const StepDimTol_GeometricToleranceModifier)) &StepDimTol_GeometricToleranceWithModifiers::SetModifierValue, "Sets modifier with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_GeometricToleranceWithModifiers.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithModifiers::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithModifiers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithModifiers::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithModifiers.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithModifiers::*)() const) &StepDimTol_GeometricToleranceWithModifiers::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOMETRICTOLERANCEWITHMAXIMUMTOLERANCE
py::class_<StepDimTol_GeometricToleranceWithMaximumTolerance, opencascade::handle<StepDimTol_GeometricToleranceWithMaximumTolerance>, StepDimTol_GeometricToleranceWithModifiers> cls_StepDimTol_GeometricToleranceWithMaximumTolerance(mod, "StepDimTol_GeometricToleranceWithMaximumTolerance", "Representation of STEP entity GeometricToleranceWithMaximumTolerance");

// Constructors
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def(py::init<>());

// Methods
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("Init", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfGeometricToleranceModifier> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theModifiers"), py::arg("theUnitSize"));
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("MaximumUpperTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const) &StepDimTol_GeometricToleranceWithMaximumTolerance::MaximumUpperTolerance, "Returns field MaximumUpperTolerance");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("SetMaximumUpperTolerance", (void (StepDimTol_GeometricToleranceWithMaximumTolerance::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeometricToleranceWithMaximumTolerance::SetMaximumUpperTolerance, "Set field MaximumUpperTolerance", py::arg("theMaximumUpperTolerance"));
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithMaximumTolerance::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithMaximumTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithMaximumTolerance::*)() const) &StepDimTol_GeometricToleranceWithMaximumTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHDATREF
py::class_<StepDimTol_GeoTolAndGeoTolWthDatRef, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRef>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRef(mod, "StepDimTol_GeoTolAndGeoTolWthDatRef", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRef::SetGeometricToleranceWithDatumReference, "None", py::arg("theGTWDR"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRef::GetGeometricToleranceWithDatumReference, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthDatRef::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRef::SetGeometricToleranceType, "None", py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRef::GetToleranceType, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRef::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRef::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRef.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRef::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRef::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHDATREFANDGEOTOLWTHMOD
py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceWithDatumReference, "None", py::arg("theGTWDR"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetGeometricToleranceWithDatumReference, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceWithModifiers", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceWithModifiers, "None", py::arg("theGTWM"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetGeometricToleranceWithModifiers", (opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetGeometricToleranceWithModifiers, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::SetGeometricToleranceType, "None", py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::GetToleranceType, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHDATREFANDGEOTOLWTHMAXTOL
py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol>, StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMod> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("SetMaxTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)(opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::SetMaxTolerance, "None", py::arg("theMaxTol"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("GetMaxTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::GetMaxTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndGeoTolWthMaxTol::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHDATREFANDMODGEOTOLANDPOSTOL
py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetGeometricToleranceWithDatumReference, "None", py::arg("aGTWDR"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetGeometricToleranceWithDatumReference, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetModifiedGeometricTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetModifiedGeometricTolerance, "None", py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetModifiedGeometricTolerance", (opencascade::handle<StepDimTol_ModifiedGeometricTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetModifiedGeometricTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetPositionTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_PositionTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetPositionTolerance, "None", py::arg("aPT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetPositionTolerance", (opencascade::handle<StepDimTol_PositionTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetPositionTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHDATREFANDUNEQDISGEOTOL
py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol>, StepDimTol_GeoTolAndGeoTolWthDatRef> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWDR"), py::arg("theType"), py::arg("theUDGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const StepDimTol_GeometricToleranceType, const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("theType"), py::arg("theUDGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("SetUnequallyDisposedGeometricTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)(const opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::SetUnequallyDisposedGeometricTolerance, "None", py::arg("theUDGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("GetUnequallyDisposedGeometricTolerance", (opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::GetUnequallyDisposedGeometricTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndUneqDisGeoTol::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHMOD
py::class_<StepDimTol_GeoTolAndGeoTolWthMod, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMod>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthMod(mod, "StepDimTol_GeoTolAndGeoTolWthMod", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthMod.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWM"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceWithModifiers", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceWithModifiers, "None", py::arg("theGTWM"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetGeometricToleranceWithModifiers", (opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::GetGeometricToleranceWithModifiers, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("SetGeometricToleranceType", (void (StepDimTol_GeoTolAndGeoTolWthMod::*)(const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMod::SetGeometricToleranceType, "None", py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("GetToleranceType", (StepDimTol_GeometricToleranceType (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::GetToleranceType, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthMod::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMod.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthMod::*)() const) &StepDimTol_GeoTolAndGeoTolWthMod::DynamicType, "None");

// CLASS: STEPDIMTOL_GEOTOLANDGEOTOLWTHMAXTOL
py::class_<StepDimTol_GeoTolAndGeoTolWthMaxTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthMaxTol>, StepDimTol_GeoTolAndGeoTolWthMod> cls_StepDimTol_GeoTolAndGeoTolWthMaxTol(mod, "StepDimTol_GeoTolAndGeoTolWthMaxTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def(py::init<>());

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::Init, "None", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithModifiers> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &, const StepDimTol_GeometricToleranceType)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWM"), py::arg("theMaxTol"), py::arg("theType"));
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("SetMaxTolerance", (void (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)(opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_GeoTolAndGeoTolWthMaxTol::SetMaxTolerance, "None", py::arg("theMaxTol"));
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("GetMaxTolerance", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::GetMaxTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthMaxTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthMaxTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthMaxTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthMaxTol::DynamicType, "None");

// CLASS: STEPDIMTOL_HARRAY1OFDATUMREFERENCEELEMENT
py::class_<StepDimTol_HArray1OfDatumReferenceElement, opencascade::handle<StepDimTol_HArray1OfDatumReferenceElement>, Standard_Transient> cls_StepDimTol_HArray1OfDatumReferenceElement(mod, "StepDimTol_HArray1OfDatumReferenceElement", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfDatumReferenceElement::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfDatumReferenceElement.def(py::init<const StepDimTol_Array1OfDatumReferenceElement &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceElement::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceElement::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfDatumReferenceElement::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfDatumReferenceElement::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfDatumReferenceElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfDatumReferenceElement::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceElement::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfDatumReferenceElement::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfDatumReferenceElement.def("Array1", (const StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_HArray1OfDatumReferenceElement::*)() const) &StepDimTol_HArray1OfDatumReferenceElement::Array1, "None");
cls_StepDimTol_HArray1OfDatumReferenceElement.def("ChangeArray1", (StepDimTol_Array1OfDatumReferenceElement & (StepDimTol_HArray1OfDatumReferenceElement::*)()) &StepDimTol_HArray1OfDatumReferenceElement::ChangeArray1, "None");
cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfDatumReferenceElement::get_type_name, "None");
cls_StepDimTol_HArray1OfDatumReferenceElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfDatumReferenceElement::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfDatumReferenceElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfDatumReferenceElement::*)() const) &StepDimTol_HArray1OfDatumReferenceElement::DynamicType, "None");

// CLASS: STEPDIMTOL_HARRAY1OFTOLERANCEZONETARGET
py::class_<StepDimTol_HArray1OfToleranceZoneTarget, opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget>, Standard_Transient> cls_StepDimTol_HArray1OfToleranceZoneTarget(mod, "StepDimTol_HArray1OfToleranceZoneTarget", "None", py::multiple_inheritance());

// Constructors
cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const Standard_Integer, const Standard_Integer, const StepDimTol_Array1OfToleranceZoneTarget::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepDimTol_HArray1OfToleranceZoneTarget.def(py::init<const StepDimTol_Array1OfToleranceZoneTarget &>(), py::arg("theOther"));

// Methods
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_HArray1OfToleranceZoneTarget::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator delete_", (void (*)(void *)) &StepDimTol_HArray1OfToleranceZoneTarget::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_HArray1OfToleranceZoneTarget::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_HArray1OfToleranceZoneTarget::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_HArray1OfToleranceZoneTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_HArray1OfToleranceZoneTarget::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfToleranceZoneTarget::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepDimTol_HArray1OfToleranceZoneTarget::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepDimTol_HArray1OfToleranceZoneTarget.def("Array1", (const StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_HArray1OfToleranceZoneTarget::*)() const) &StepDimTol_HArray1OfToleranceZoneTarget::Array1, "None");
cls_StepDimTol_HArray1OfToleranceZoneTarget.def("ChangeArray1", (StepDimTol_Array1OfToleranceZoneTarget & (StepDimTol_HArray1OfToleranceZoneTarget::*)()) &StepDimTol_HArray1OfToleranceZoneTarget::ChangeArray1, "None");
cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("get_type_name_", (const char * (*)()) &StepDimTol_HArray1OfToleranceZoneTarget::get_type_name, "None");
cls_StepDimTol_HArray1OfToleranceZoneTarget.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_HArray1OfToleranceZoneTarget::get_type_descriptor, "None");
cls_StepDimTol_HArray1OfToleranceZoneTarget.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_HArray1OfToleranceZoneTarget::*)() const) &StepDimTol_HArray1OfToleranceZoneTarget::DynamicType, "None");

// CLASS: STEPDIMTOL_LINEPROFILETOLERANCE
py::class_<StepDimTol_LineProfileTolerance, opencascade::handle<StepDimTol_LineProfileTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_LineProfileTolerance(mod, "StepDimTol_LineProfileTolerance", "Representation of STEP entity LineProfileTolerance");

// Constructors
cls_StepDimTol_LineProfileTolerance.def(py::init<>());

// Methods
cls_StepDimTol_LineProfileTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_LineProfileTolerance::get_type_name, "None");
cls_StepDimTol_LineProfileTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_LineProfileTolerance::get_type_descriptor, "None");
cls_StepDimTol_LineProfileTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_LineProfileTolerance::*)() const) &StepDimTol_LineProfileTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_MODIFIEDGEOMETRICTOLERANCE
py::class_<StepDimTol_ModifiedGeometricTolerance, opencascade::handle<StepDimTol_ModifiedGeometricTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_ModifiedGeometricTolerance(mod, "StepDimTol_ModifiedGeometricTolerance", "Representation of STEP entity ModifiedGeometricTolerance");

// Constructors
cls_StepDimTol_ModifiedGeometricTolerance.def(py::init<>());

// Methods
cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def("Init", (void (StepDimTol_ModifiedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def("Modifier", (StepDimTol_LimitCondition (StepDimTol_ModifiedGeometricTolerance::*)() const) &StepDimTol_ModifiedGeometricTolerance::Modifier, "Returns field Modifier");
cls_StepDimTol_ModifiedGeometricTolerance.def("SetModifier", (void (StepDimTol_ModifiedGeometricTolerance::*)(const StepDimTol_LimitCondition)) &StepDimTol_ModifiedGeometricTolerance::SetModifier, "Set field Modifier", py::arg("theModifier"));
cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_name, "None");
cls_StepDimTol_ModifiedGeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ModifiedGeometricTolerance::get_type_descriptor, "None");
cls_StepDimTol_ModifiedGeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ModifiedGeometricTolerance::*)() const) &StepDimTol_ModifiedGeometricTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_TOLERANCEZONEFORM
py::class_<StepDimTol_ToleranceZoneForm, opencascade::handle<StepDimTol_ToleranceZoneForm>, Standard_Transient> cls_StepDimTol_ToleranceZoneForm(mod, "StepDimTol_ToleranceZoneForm", "Added for Dimensional Tolerances");

// Constructors
cls_StepDimTol_ToleranceZoneForm.def(py::init<>());

// Methods
cls_StepDimTol_ToleranceZoneForm.def("Init", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::Init, "Init all field own and inherited", py::arg("theName"));
cls_StepDimTol_ToleranceZoneForm.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepDimTol_ToleranceZoneForm::*)()) &StepDimTol_ToleranceZoneForm::Name, "Returns field Name");
cls_StepDimTol_ToleranceZoneForm.def("SetName", (void (StepDimTol_ToleranceZoneForm::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepDimTol_ToleranceZoneForm::SetName, "Set field Name", py::arg("theName"));
cls_StepDimTol_ToleranceZoneForm.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneForm::get_type_name, "None");
cls_StepDimTol_ToleranceZoneForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneForm::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZoneForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneForm::*)() const) &StepDimTol_ToleranceZoneForm::DynamicType, "None");

// CLASS: STEPDIMTOL_TOLERANCEZONE
py::class_<StepDimTol_ToleranceZone, opencascade::handle<StepDimTol_ToleranceZone>, StepRepr_ShapeAspect> cls_StepDimTol_ToleranceZone(mod, "StepDimTol_ToleranceZone", "Representation of STEP entity ToleranceZone");

// Constructors
cls_StepDimTol_ToleranceZone.def(py::init<>());

// Methods
cls_StepDimTol_ToleranceZone.def("Init", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theDefiningTolerance"), py::arg("theForm"));
cls_StepDimTol_ToleranceZone.def("DefiningTolerance", (opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::DefiningTolerance, "Returns field DefiningTolerance");
cls_StepDimTol_ToleranceZone.def("SetDefiningTolerance", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_HArray1OfToleranceZoneTarget> &)) &StepDimTol_ToleranceZone::SetDefiningTolerance, "Set field DefiningTolerance", py::arg("theDefiningTolerance"));
cls_StepDimTol_ToleranceZone.def("NbDefiningTolerances", (Standard_Integer (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::NbDefiningTolerances, "Returns number of Defining Tolerances");
cls_StepDimTol_ToleranceZone.def("DefiningToleranceValue", (StepDimTol_ToleranceZoneTarget (StepDimTol_ToleranceZone::*)(const Standard_Integer) const) &StepDimTol_ToleranceZone::DefiningToleranceValue, "Returns Defining Tolerance with the given number", py::arg("theNum"));
cls_StepDimTol_ToleranceZone.def("SetDefiningToleranceValue", (void (StepDimTol_ToleranceZone::*)(const Standard_Integer, const StepDimTol_ToleranceZoneTarget &)) &StepDimTol_ToleranceZone::SetDefiningToleranceValue, "Sets Defining Tolerance with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_ToleranceZone.def("Form", (opencascade::handle<StepDimTol_ToleranceZoneForm> (StepDimTol_ToleranceZone::*)()) &StepDimTol_ToleranceZone::Form, "Returns field Form");
cls_StepDimTol_ToleranceZone.def("SetForm", (void (StepDimTol_ToleranceZone::*)(const opencascade::handle<StepDimTol_ToleranceZoneForm> &)) &StepDimTol_ToleranceZone::SetForm, "Set field Form", py::arg("theForm"));
cls_StepDimTol_ToleranceZone.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZone::get_type_name, "None");
cls_StepDimTol_ToleranceZone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZone::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZone.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZone::*)() const) &StepDimTol_ToleranceZone::DynamicType, "None");

// CLASS: STEPDIMTOL_TOLERANCEZONEDEFINITION
py::class_<StepDimTol_ToleranceZoneDefinition, opencascade::handle<StepDimTol_ToleranceZoneDefinition>, Standard_Transient> cls_StepDimTol_ToleranceZoneDefinition(mod, "StepDimTol_ToleranceZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");

// Constructors
cls_StepDimTol_ToleranceZoneDefinition.def(py::init<>());

// Methods
cls_StepDimTol_ToleranceZoneDefinition.def("Init", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"));
cls_StepDimTol_ToleranceZoneDefinition.def("Boundaries", (opencascade::handle<StepRepr_HArray1OfShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::Boundaries, "Returns field Boundaries");
cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundaries", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundaries, "Set field Boundaries", py::arg("theBoundaries"));
cls_StepDimTol_ToleranceZoneDefinition.def("NbBoundaries", (Standard_Integer (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::NbBoundaries, "Returns number of Boundaries");
cls_StepDimTol_ToleranceZoneDefinition.def("BoundariesValue", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer) const) &StepDimTol_ToleranceZoneDefinition::BoundariesValue, "Returns Boundaries with the given number", py::arg("theNum"));
cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundariesValue", (void (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundariesValue, "Sets Boundaries with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_ToleranceZoneDefinition.def("Zone", (opencascade::handle<StepDimTol_ToleranceZone> (StepDimTol_ToleranceZoneDefinition::*)()) &StepDimTol_ToleranceZoneDefinition::Zone, "Returns field Zone");
cls_StepDimTol_ToleranceZoneDefinition.def("SetZone", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &)) &StepDimTol_ToleranceZoneDefinition::SetZone, "Set field Zone", py::arg("theZone"));
cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_name, "None");
cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::DynamicType, "None");

// CLASS: STEPDIMTOL_NONUNIFORMZONEDEFINITION
py::class_<StepDimTol_NonUniformZoneDefinition, opencascade::handle<StepDimTol_NonUniformZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_NonUniformZoneDefinition(mod, "StepDimTol_NonUniformZoneDefinition", "Representation of STEP entity NonUniformZoneDefinition");

// Constructors
cls_StepDimTol_NonUniformZoneDefinition.def(py::init<>());

// Methods
cls_StepDimTol_NonUniformZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_NonUniformZoneDefinition::get_type_name, "None");
cls_StepDimTol_NonUniformZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_NonUniformZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_NonUniformZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_NonUniformZoneDefinition::*)() const) &StepDimTol_NonUniformZoneDefinition::DynamicType, "None");

// CLASS: STEPDIMTOL_PARALLELISMTOLERANCE
py::class_<StepDimTol_ParallelismTolerance, opencascade::handle<StepDimTol_ParallelismTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_ParallelismTolerance(mod, "StepDimTol_ParallelismTolerance", "Representation of STEP entity ParallelismTolerance");

// Constructors
cls_StepDimTol_ParallelismTolerance.def(py::init<>());

// Methods
cls_StepDimTol_ParallelismTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ParallelismTolerance::get_type_name, "None");
cls_StepDimTol_ParallelismTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ParallelismTolerance::get_type_descriptor, "None");
cls_StepDimTol_ParallelismTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ParallelismTolerance::*)() const) &StepDimTol_ParallelismTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_PERPENDICULARITYTOLERANCE
py::class_<StepDimTol_PerpendicularityTolerance, opencascade::handle<StepDimTol_PerpendicularityTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_PerpendicularityTolerance(mod, "StepDimTol_PerpendicularityTolerance", "Representation of STEP entity PerpendicularityTolerance");

// Constructors
cls_StepDimTol_PerpendicularityTolerance.def(py::init<>());

// Methods
cls_StepDimTol_PerpendicularityTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PerpendicularityTolerance::get_type_name, "None");
cls_StepDimTol_PerpendicularityTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PerpendicularityTolerance::get_type_descriptor, "None");
cls_StepDimTol_PerpendicularityTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PerpendicularityTolerance::*)() const) &StepDimTol_PerpendicularityTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_PLACEDDATUMTARGETFEATURE
py::class_<StepDimTol_PlacedDatumTargetFeature, opencascade::handle<StepDimTol_PlacedDatumTargetFeature>, StepDimTol_DatumTarget> cls_StepDimTol_PlacedDatumTargetFeature(mod, "StepDimTol_PlacedDatumTargetFeature", "Representation of STEP entity PlacedDatumTargetFeature");

// Constructors
cls_StepDimTol_PlacedDatumTargetFeature.def(py::init<>());

// Methods
cls_StepDimTol_PlacedDatumTargetFeature.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PlacedDatumTargetFeature::get_type_name, "None");
cls_StepDimTol_PlacedDatumTargetFeature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PlacedDatumTargetFeature::get_type_descriptor, "None");
cls_StepDimTol_PlacedDatumTargetFeature.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PlacedDatumTargetFeature::*)() const) &StepDimTol_PlacedDatumTargetFeature::DynamicType, "None");

// CLASS: STEPDIMTOL_POSITIONTOLERANCE
py::class_<StepDimTol_PositionTolerance, opencascade::handle<StepDimTol_PositionTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_PositionTolerance(mod, "StepDimTol_PositionTolerance", "Representation of STEP entity PositionTolerance");

// Constructors
cls_StepDimTol_PositionTolerance.def(py::init<>());

// Methods
cls_StepDimTol_PositionTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_PositionTolerance::get_type_name, "None");
cls_StepDimTol_PositionTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_PositionTolerance::get_type_descriptor, "None");
cls_StepDimTol_PositionTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_PositionTolerance::*)() const) &StepDimTol_PositionTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_PROJECTEDZONEDEFINITION
py::class_<StepDimTol_ProjectedZoneDefinition, opencascade::handle<StepDimTol_ProjectedZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_ProjectedZoneDefinition(mod, "StepDimTol_ProjectedZoneDefinition", "Representation of STEP entity ProjectedZoneDefinition");

// Constructors
cls_StepDimTol_ProjectedZoneDefinition.def(py::init<>());

// Methods
cls_StepDimTol_ProjectedZoneDefinition.def("Init", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theProjectionEnd"), py::arg("theProjectionLength"));
cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionEnd", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ProjectedZoneDefinition::*)() const) &StepDimTol_ProjectedZoneDefinition::ProjectionEnd, "Returns field ProjectionEnd");
cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionEnd", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionEnd, "Set field ProjectionEnd", py::arg("theProjectionEnd"));
cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionLength", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_ProjectedZoneDefinition::*)()) &StepDimTol_ProjectedZoneDefinition::ProjectionLength, "Returns field ProjectionLength");
cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionLength", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionLength, "Set field ProjectionLength", py::arg("theProjectionLength"));
cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_name, "None");
cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_ProjectedZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ProjectedZoneDefinition::*)() const) &StepDimTol_ProjectedZoneDefinition::DynamicType, "None");

// CLASS: STEPDIMTOL_ROUNDNESSTOLERANCE
py::class_<StepDimTol_RoundnessTolerance, opencascade::handle<StepDimTol_RoundnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_RoundnessTolerance(mod, "StepDimTol_RoundnessTolerance", "Representation of STEP entity RoundnessTolerance");

// Constructors
cls_StepDimTol_RoundnessTolerance.def(py::init<>());

// Methods
cls_StepDimTol_RoundnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RoundnessTolerance::get_type_name, "None");
cls_StepDimTol_RoundnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RoundnessTolerance::get_type_descriptor, "None");
cls_StepDimTol_RoundnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RoundnessTolerance::*)() const) &StepDimTol_RoundnessTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_RUNOUTZONEORIENTATION
py::class_<StepDimTol_RunoutZoneOrientation, opencascade::handle<StepDimTol_RunoutZoneOrientation>, Standard_Transient> cls_StepDimTol_RunoutZoneOrientation(mod, "StepDimTol_RunoutZoneOrientation", "Added for Dimensional Tolerances");

// Constructors
cls_StepDimTol_RunoutZoneOrientation.def(py::init<>());

// Methods
cls_StepDimTol_RunoutZoneOrientation.def("Init", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::Init, "Init all field own and inherited", py::arg("theAngle"));
cls_StepDimTol_RunoutZoneOrientation.def("Angle", (opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> (StepDimTol_RunoutZoneOrientation::*)()) &StepDimTol_RunoutZoneOrientation::Angle, "Returns field Angle");
cls_StepDimTol_RunoutZoneOrientation.def("SetAngle", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::SetAngle, "Set field Angle", py::arg("theAngle"));
cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneOrientation::get_type_name, "None");
cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneOrientation::get_type_descriptor, "None");
cls_StepDimTol_RunoutZoneOrientation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneOrientation::*)() const) &StepDimTol_RunoutZoneOrientation::DynamicType, "None");

// CLASS: STEPDIMTOL_RUNOUTZONEDEFINITION
py::class_<StepDimTol_RunoutZoneDefinition, opencascade::handle<StepDimTol_RunoutZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_RunoutZoneDefinition(mod, "StepDimTol_RunoutZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");

// Constructors
cls_StepDimTol_RunoutZoneDefinition.def(py::init<>());

// Methods
cls_StepDimTol_RunoutZoneDefinition.def("Init", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theOrientation"));
cls_StepDimTol_RunoutZoneDefinition.def("Orientation", (opencascade::handle<StepDimTol_RunoutZoneOrientation> (StepDimTol_RunoutZoneDefinition::*)() const) &StepDimTol_RunoutZoneDefinition::Orientation, "Returns field Orientation");
cls_StepDimTol_RunoutZoneDefinition.def("SetOrientation", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::SetOrientation, "Set field Orientation", py::arg("theOrientation"));
cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneDefinition::get_type_name, "None");
cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_RunoutZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneDefinition::*)() const) &StepDimTol_RunoutZoneDefinition::DynamicType, "None");

// CLASS: STEPDIMTOL_SHAPETOLERANCESELECT
py::class_<StepDimTol_ShapeToleranceSelect, StepData_SelectType> cls_StepDimTol_ShapeToleranceSelect(mod, "StepDimTol_ShapeToleranceSelect", "Representation of STEP SELECT type ShapeToleranceSelect");

// Constructors
cls_StepDimTol_ShapeToleranceSelect.def(py::init<>());

// Methods
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_ShapeToleranceSelect::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete_", (void (*)(void *)) &StepDimTol_ShapeToleranceSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_ShapeToleranceSelect::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_ShapeToleranceSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_ShapeToleranceSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_ShapeToleranceSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_ShapeToleranceSelect.def("CaseNum", (Standard_Integer (StepDimTol_ShapeToleranceSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_ShapeToleranceSelect::CaseNum, "Recognizes a kind of ShapeToleranceSelect select type 1 -> GeometricTolerance from StepDimTol 2 -> PlusMinusTolerance from StepShape 0 else", py::arg("ent"));
cls_StepDimTol_ShapeToleranceSelect.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_ShapeToleranceSelect::*)() const) &StepDimTol_ShapeToleranceSelect::GeometricTolerance, "Returns Value as GeometricTolerance (or Null if another type)");
cls_StepDimTol_ShapeToleranceSelect.def("PlusMinusTolerance", (opencascade::handle<StepShape_PlusMinusTolerance> (StepDimTol_ShapeToleranceSelect::*)() const) &StepDimTol_ShapeToleranceSelect::PlusMinusTolerance, "Returns Value as PlusMinusTolerance (or Null if another type)");

// CLASS: STEPDIMTOL_STRAIGHTNESSTOLERANCE
py::class_<StepDimTol_StraightnessTolerance, opencascade::handle<StepDimTol_StraightnessTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_StraightnessTolerance(mod, "StepDimTol_StraightnessTolerance", "Representation of STEP entity StraightnessTolerance");

// Constructors
cls_StepDimTol_StraightnessTolerance.def(py::init<>());

// Methods
cls_StepDimTol_StraightnessTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_StraightnessTolerance::get_type_name, "None");
cls_StepDimTol_StraightnessTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_StraightnessTolerance::get_type_descriptor, "None");
cls_StepDimTol_StraightnessTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_StraightnessTolerance::*)() const) &StepDimTol_StraightnessTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_SURFACEPROFILETOLERANCE
py::class_<StepDimTol_SurfaceProfileTolerance, opencascade::handle<StepDimTol_SurfaceProfileTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_SurfaceProfileTolerance(mod, "StepDimTol_SurfaceProfileTolerance", "Representation of STEP entity SurfaceProfileTolerance");

// Constructors
cls_StepDimTol_SurfaceProfileTolerance.def(py::init<>());

// Methods
cls_StepDimTol_SurfaceProfileTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SurfaceProfileTolerance::get_type_name, "None");
cls_StepDimTol_SurfaceProfileTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SurfaceProfileTolerance::get_type_descriptor, "None");
cls_StepDimTol_SurfaceProfileTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SurfaceProfileTolerance::*)() const) &StepDimTol_SurfaceProfileTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_SYMMETRYTOLERANCE
py::class_<StepDimTol_SymmetryTolerance, opencascade::handle<StepDimTol_SymmetryTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_SymmetryTolerance(mod, "StepDimTol_SymmetryTolerance", "Representation of STEP entity SymmetryTolerance");

// Constructors
cls_StepDimTol_SymmetryTolerance.def(py::init<>());

// Methods
cls_StepDimTol_SymmetryTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_SymmetryTolerance::get_type_name, "None");
cls_StepDimTol_SymmetryTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_SymmetryTolerance::get_type_descriptor, "None");
cls_StepDimTol_SymmetryTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_SymmetryTolerance::*)() const) &StepDimTol_SymmetryTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_TOTALRUNOUTTOLERANCE
py::class_<StepDimTol_TotalRunoutTolerance, opencascade::handle<StepDimTol_TotalRunoutTolerance>, StepDimTol_GeometricToleranceWithDatumReference> cls_StepDimTol_TotalRunoutTolerance(mod, "StepDimTol_TotalRunoutTolerance", "Representation of STEP entity TotalRunoutTolerance");

// Constructors
cls_StepDimTol_TotalRunoutTolerance.def(py::init<>());

// Methods
cls_StepDimTol_TotalRunoutTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_TotalRunoutTolerance::get_type_name, "None");
cls_StepDimTol_TotalRunoutTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_TotalRunoutTolerance::get_type_descriptor, "None");
cls_StepDimTol_TotalRunoutTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_TotalRunoutTolerance::*)() const) &StepDimTol_TotalRunoutTolerance::DynamicType, "None");

// CLASS: STEPDIMTOL_UNEQUALLYDISPOSEDGEOMETRICTOLERANCE
py::class_<StepDimTol_UnequallyDisposedGeometricTolerance, opencascade::handle<StepDimTol_UnequallyDisposedGeometricTolerance>, StepDimTol_GeometricTolerance> cls_StepDimTol_UnequallyDisposedGeometricTolerance(mod, "StepDimTol_UnequallyDisposedGeometricTolerance", "Representation of STEP entity UnequallyDisposedGeometricTolerance");

// Constructors
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def(py::init<>());

// Methods
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("Init", (void (StepDimTol_UnequallyDisposedGeometricTolerance::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_UnequallyDisposedGeometricTolerance::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theMagnitude"), py::arg("theTolerancedShapeAspect"), py::arg("theDisplacement"));
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("Displacement", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_UnequallyDisposedGeometricTolerance::*)() const) &StepDimTol_UnequallyDisposedGeometricTolerance::Displacement, "Returns field Displacement");
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("SetDisplacement", (void (StepDimTol_UnequallyDisposedGeometricTolerance::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_UnequallyDisposedGeometricTolerance::SetDisplacement, "Set field Displacement", py::arg("theDisplacement"));
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def_static("get_type_name_", (const char * (*)()) &StepDimTol_UnequallyDisposedGeometricTolerance::get_type_name, "None");
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_UnequallyDisposedGeometricTolerance::get_type_descriptor, "None");
cls_StepDimTol_UnequallyDisposedGeometricTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_UnequallyDisposedGeometricTolerance::*)() const) &StepDimTol_UnequallyDisposedGeometricTolerance::DynamicType, "None");


}
