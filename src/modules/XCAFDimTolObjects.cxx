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
#include <XCAFDimTolObjects_DimensionModif.hxx>
#include <XCAFDimTolObjects_DatumSingleModif.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>
#include <XCAFDimTolObjects_DimensionGrade.hxx>
#include <XCAFDimTolObjects_DimensionType.hxx>
#include <XCAFDimTolObjects_DatumTargetType.hxx>
#include <XCAFDimTolObjects_DimensionQualifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceType.hxx>
#include <XCAFDimTolObjects_GeomToleranceTypeValue.hxx>
#include <XCAFDimTolObjects_GeomToleranceMatReqModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceZoneModif.hxx>
#include <XCAFDimTolObjects_ToleranceZoneAffectedPlane.hxx>
#include <NCollection_Sequence.hxx>
#include <XCAFDimTolObjects_DimensionModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <XCAFDimTolObjects_GeomToleranceObjectSequence.hxx>
#include <XCAFDimTolObjects_GeomToleranceModifiersSequence.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pln.hxx>
#include <Standard_Type.hxx>
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <XCAFDimTolObjects_DatumObjectSequence.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <XCAFDimTolObjects_DataMapOfToleranceDatum.hxx>
#include <XCAFDimTolObjects_DimensionObject.hxx>
#include <XCAFDimTolObjects_DimensionObjectSequence.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Dir.hxx>
#include <NCollection_Vector.hxx>
#include <Standard.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <XCAFDimTolObjects_Tool.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(XCAFDimTolObjects, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDocStd");

// ENUM: XCAFDIMTOLOBJECTS_DIMENSIONMODIF
py::enum_<XCAFDimTolObjects_DimensionModif>(mod, "XCAFDimTolObjects_DimensionModif", "Defines modifirs")
	.value("XCAFDimTolObjects_DimensionModif_ControlledRadius", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_ControlledRadius)
	.value("XCAFDimTolObjects_DimensionModif_Square", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_Square)
	.value("XCAFDimTolObjects_DimensionModif_StatisticalTolerance", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_StatisticalTolerance)
	.value("XCAFDimTolObjects_DimensionModif_ContinuousFeature", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_ContinuousFeature)
	.value("XCAFDimTolObjects_DimensionModif_TwoPointSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_TwoPointSize)
	.value("XCAFDimTolObjects_DimensionModif_LocalSizeDefinedBySphere", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_LocalSizeDefinedBySphere)
	.value("XCAFDimTolObjects_DimensionModif_LeastSquaresAssociationCriterion", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_LeastSquaresAssociationCriterion)
	.value("XCAFDimTolObjects_DimensionModif_MaximumInscribedAssociation", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MaximumInscribedAssociation)
	.value("XCAFDimTolObjects_DimensionModif_MinimumCircumscribedAssociation", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MinimumCircumscribedAssociation)
	.value("XCAFDimTolObjects_DimensionModif_CircumferenceDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_CircumferenceDiameter)
	.value("XCAFDimTolObjects_DimensionModif_AreaDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AreaDiameter)
	.value("XCAFDimTolObjects_DimensionModif_VolumeDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_VolumeDiameter)
	.value("XCAFDimTolObjects_DimensionModif_MaximumSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MaximumSize)
	.value("XCAFDimTolObjects_DimensionModif_MinimumSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MinimumSize)
	.value("XCAFDimTolObjects_DimensionModif_AverageSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AverageSize)
	.value("XCAFDimTolObjects_DimensionModif_MedianSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MedianSize)
	.value("XCAFDimTolObjects_DimensionModif_MidRangeSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MidRangeSize)
	.value("XCAFDimTolObjects_DimensionModif_RangeOfSizes", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_RangeOfSizes)
	.value("XCAFDimTolObjects_DimensionModif_AnyRestrictedPortionOfFeature", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AnyRestrictedPortionOfFeature)
	.value("XCAFDimTolObjects_DimensionModif_AnyCrossSection", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AnyCrossSection)
	.value("XCAFDimTolObjects_DimensionModif_SpecificFixedCrossSection", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_SpecificFixedCrossSection)
	.value("XCAFDimTolObjects_DimensionModif_CommonTolerance", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_CommonTolerance)
	.value("XCAFDimTolObjects_DimensionModif_FreeStateCondition", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_FreeStateCondition)
	.value("XCAFDimTolObjects_DimensionModif_Between", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_Between)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DATUMSINGLEMODIF
py::enum_<XCAFDimTolObjects_DatumSingleModif>(mod, "XCAFDimTolObjects_DatumSingleModif", "Defines modifirs")
	.value("XCAFDimTolObjects_DatumSingleModif_AnyCrossSection", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_AnyCrossSection)
	.value("XCAFDimTolObjects_DatumSingleModif_Any_LongitudinalSection", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Any_LongitudinalSection)
	.value("XCAFDimTolObjects_DatumSingleModif_Basic", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Basic)
	.value("XCAFDimTolObjects_DatumSingleModif_ContactingFeature", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_ContactingFeature)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintU", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintU)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintV", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintV)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintW", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintW)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintX", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintX)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintY", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintY)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintZ", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintZ)
	.value("XCAFDimTolObjects_DatumSingleModif_DistanceVariable", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DistanceVariable)
	.value("XCAFDimTolObjects_DatumSingleModif_FreeState", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_FreeState)
	.value("XCAFDimTolObjects_DatumSingleModif_LeastMaterialRequirement", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_LeastMaterialRequirement)
	.value("XCAFDimTolObjects_DatumSingleModif_Line", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Line)
	.value("XCAFDimTolObjects_DatumSingleModif_MajorDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MajorDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_MaximumMaterialRequirement", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MaximumMaterialRequirement)
	.value("XCAFDimTolObjects_DatumSingleModif_MinorDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MinorDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_Orientation", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Orientation)
	.value("XCAFDimTolObjects_DatumSingleModif_PitchDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_PitchDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_Plane", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Plane)
	.value("XCAFDimTolObjects_DatumSingleModif_Point", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Point)
	.value("XCAFDimTolObjects_DatumSingleModif_Translation", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Translation)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DATUMMODIFWITHVALUE
py::enum_<XCAFDimTolObjects_DatumModifWithValue>(mod, "XCAFDimTolObjects_DatumModifWithValue", "Defines modifirs")
	.value("XCAFDimTolObjects_DatumModifWithValue_None", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_None)
	.value("XCAFDimTolObjects_DatumModifWithValue_CircularOrCylindrical", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_CircularOrCylindrical)
	.value("XCAFDimTolObjects_DatumModifWithValue_Distance", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Distance)
	.value("XCAFDimTolObjects_DatumModifWithValue_Projected", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Projected)
	.value("XCAFDimTolObjects_DatumModifWithValue_Spherical", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Spherical)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DIMENSIONFORMVARIANCE
py::enum_<XCAFDimTolObjects_DimensionFormVariance>(mod, "XCAFDimTolObjects_DimensionFormVariance", "Defines value of form variance")
	.value("XCAFDimTolObjects_DimensionFormVariance_None", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_None)
	.value("XCAFDimTolObjects_DimensionFormVariance_A", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_A)
	.value("XCAFDimTolObjects_DimensionFormVariance_B", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_B)
	.value("XCAFDimTolObjects_DimensionFormVariance_C", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_C)
	.value("XCAFDimTolObjects_DimensionFormVariance_CD", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_CD)
	.value("XCAFDimTolObjects_DimensionFormVariance_D", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_D)
	.value("XCAFDimTolObjects_DimensionFormVariance_E", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_E)
	.value("XCAFDimTolObjects_DimensionFormVariance_EF", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_EF)
	.value("XCAFDimTolObjects_DimensionFormVariance_F", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_F)
	.value("XCAFDimTolObjects_DimensionFormVariance_FG", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_FG)
	.value("XCAFDimTolObjects_DimensionFormVariance_G", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_G)
	.value("XCAFDimTolObjects_DimensionFormVariance_H", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_H)
	.value("XCAFDimTolObjects_DimensionFormVariance_JS", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_JS)
	.value("XCAFDimTolObjects_DimensionFormVariance_J", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_J)
	.value("XCAFDimTolObjects_DimensionFormVariance_K", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_K)
	.value("XCAFDimTolObjects_DimensionFormVariance_M", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_M)
	.value("XCAFDimTolObjects_DimensionFormVariance_N", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_N)
	.value("XCAFDimTolObjects_DimensionFormVariance_P", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_P)
	.value("XCAFDimTolObjects_DimensionFormVariance_R", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_R)
	.value("XCAFDimTolObjects_DimensionFormVariance_S", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_S)
	.value("XCAFDimTolObjects_DimensionFormVariance_T", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_T)
	.value("XCAFDimTolObjects_DimensionFormVariance_U", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_U)
	.value("XCAFDimTolObjects_DimensionFormVariance_V", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_V)
	.value("XCAFDimTolObjects_DimensionFormVariance_X", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_X)
	.value("XCAFDimTolObjects_DimensionFormVariance_Y", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_Y)
	.value("XCAFDimTolObjects_DimensionFormVariance_Z", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_Z)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZA", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZA)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZB", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZB)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZC", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZC)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DIMENSIONGRADE
py::enum_<XCAFDimTolObjects_DimensionGrade>(mod, "XCAFDimTolObjects_DimensionGrade", "Defines value of grade")
	.value("XCAFDimTolObjects_DimensionGrade_IT01", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT01)
	.value("XCAFDimTolObjects_DimensionGrade_IT0", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT0)
	.value("XCAFDimTolObjects_DimensionGrade_IT1", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT1)
	.value("XCAFDimTolObjects_DimensionGrade_IT2", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT2)
	.value("XCAFDimTolObjects_DimensionGrade_IT3", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT3)
	.value("XCAFDimTolObjects_DimensionGrade_IT4", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT4)
	.value("XCAFDimTolObjects_DimensionGrade_IT5", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT5)
	.value("XCAFDimTolObjects_DimensionGrade_IT6", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT6)
	.value("XCAFDimTolObjects_DimensionGrade_IT7", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT7)
	.value("XCAFDimTolObjects_DimensionGrade_IT8", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT8)
	.value("XCAFDimTolObjects_DimensionGrade_IT9", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT9)
	.value("XCAFDimTolObjects_DimensionGrade_IT10", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT10)
	.value("XCAFDimTolObjects_DimensionGrade_IT11", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT11)
	.value("XCAFDimTolObjects_DimensionGrade_IT12", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT12)
	.value("XCAFDimTolObjects_DimensionGrade_IT13", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT13)
	.value("XCAFDimTolObjects_DimensionGrade_IT14", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT14)
	.value("XCAFDimTolObjects_DimensionGrade_IT15", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT15)
	.value("XCAFDimTolObjects_DimensionGrade_IT16", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT16)
	.value("XCAFDimTolObjects_DimensionGrade_IT17", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT17)
	.value("XCAFDimTolObjects_DimensionGrade_IT18", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT18)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DIMENSIONTYPE
py::enum_<XCAFDimTolObjects_DimensionType>(mod, "XCAFDimTolObjects_DimensionType", "Defines types of dimension")
	.value("XCAFDimTolObjects_DimensionType_Location_None", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_None)
	.value("XCAFDimTolObjects_DimensionType_Location_CurvedDistance", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_CurvedDistance)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromCenterToOuter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromCenterToOuter)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromCenterToInner", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromCenterToInner)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToCenter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToCenter)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToOuter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToOuter)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToInner", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromOuterToInner)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToCenter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToCenter)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToOuter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToOuter)
	.value("XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToInner", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_LinearDistance_FromInnerToInner)
	.value("XCAFDimTolObjects_DimensionType_Location_Angular", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_Angular)
	.value("XCAFDimTolObjects_DimensionType_Location_Oriented", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_Oriented)
	.value("XCAFDimTolObjects_DimensionType_Location_WithPath", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Location_WithPath)
	.value("XCAFDimTolObjects_DimensionType_Size_CurveLength", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_CurveLength)
	.value("XCAFDimTolObjects_DimensionType_Size_Diameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_Diameter)
	.value("XCAFDimTolObjects_DimensionType_Size_SphericalDiameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_SphericalDiameter)
	.value("XCAFDimTolObjects_DimensionType_Size_Radius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_Radius)
	.value("XCAFDimTolObjects_DimensionType_Size_SphericalRadius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_SphericalRadius)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalMinorDiameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalMinorDiameter)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalMajorDiameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalMajorDiameter)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalMinorRadius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalMinorRadius)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalMajorRadius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalMajorRadius)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalHighMajorDiameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalHighMajorDiameter)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalLowMajorDiameter", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalLowMajorDiameter)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalHighMajorRadius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalHighMajorRadius)
	.value("XCAFDimTolObjects_DimensionType_Size_ToroidalLowMajorRadius", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_ToroidalLowMajorRadius)
	.value("XCAFDimTolObjects_DimensionType_Size_Thickness", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_Thickness)
	.value("XCAFDimTolObjects_DimensionType_Size_Angular", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_Angular)
	.value("XCAFDimTolObjects_DimensionType_Size_WithPath", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_Size_WithPath)
	.value("XCAFDimTolObjects_DimensionType_CommonLabel", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_CommonLabel)
	.value("XCAFDimTolObjects_DimensionType_DimensionPresentation", XCAFDimTolObjects_DimensionType::XCAFDimTolObjects_DimensionType_DimensionPresentation)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DATUMTARGETTYPE
py::enum_<XCAFDimTolObjects_DatumTargetType>(mod, "XCAFDimTolObjects_DatumTargetType", "Defines types of dimension")
	.value("XCAFDimTolObjects_DatumTargetType_Point", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Point)
	.value("XCAFDimTolObjects_DatumTargetType_Line", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Line)
	.value("XCAFDimTolObjects_DatumTargetType_Rectangle", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Rectangle)
	.value("XCAFDimTolObjects_DatumTargetType_Circle", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Circle)
	.value("XCAFDimTolObjects_DatumTargetType_Area", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Area)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_DIMENSIONQUALIFIER
py::enum_<XCAFDimTolObjects_DimensionQualifier>(mod, "XCAFDimTolObjects_DimensionQualifier", "Defines types of qualifier")
	.value("XCAFDimTolObjects_DimensionQualifier_None", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_None)
	.value("XCAFDimTolObjects_DimensionQualifier_Min", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Min)
	.value("XCAFDimTolObjects_DimensionQualifier_Max", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Max)
	.value("XCAFDimTolObjects_DimensionQualifier_Avg", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Avg)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_GEOMTOLERANCEMODIF
py::enum_<XCAFDimTolObjects_GeomToleranceModif>(mod, "XCAFDimTolObjects_GeomToleranceModif", "Defines modifirs")
	.value("XCAFDimTolObjects_GeomToleranceModif_Any_Cross_Section", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Any_Cross_Section)
	.value("XCAFDimTolObjects_GeomToleranceModif_Common_Zone", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Common_Zone)
	.value("XCAFDimTolObjects_GeomToleranceModif_Each_Radial_Element", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Each_Radial_Element)
	.value("XCAFDimTolObjects_GeomToleranceModif_Free_State", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Free_State)
	.value("XCAFDimTolObjects_GeomToleranceModif_Least_Material_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Least_Material_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Line_Element", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Line_Element)
	.value("XCAFDimTolObjects_GeomToleranceModif_Major_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Major_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Maximum_Material_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Maximum_Material_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Minor_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Minor_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Not_Convex", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Not_Convex)
	.value("XCAFDimTolObjects_GeomToleranceModif_Pitch_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Pitch_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Reciprocity_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Reciprocity_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Separate_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Separate_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Statistical_Tolerance", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Statistical_Tolerance)
	.value("XCAFDimTolObjects_GeomToleranceModif_Tangent_Plane", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Tangent_Plane)
	.value("XCAFDimTolObjects_GeomToleranceModif_All_Around", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_All_Around)
	.value("XCAFDimTolObjects_GeomToleranceModif_All_Over", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_All_Over)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_GEOMTOLERANCETYPE
py::enum_<XCAFDimTolObjects_GeomToleranceType>(mod, "XCAFDimTolObjects_GeomToleranceType", "Defines types of geom tolerance")
	.value("XCAFDimTolObjects_GeomToleranceType_None", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_None)
	.value("XCAFDimTolObjects_GeomToleranceType_Angularity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Angularity)
	.value("XCAFDimTolObjects_GeomToleranceType_CircularRunout", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_CircularRunout)
	.value("XCAFDimTolObjects_GeomToleranceType_CircularityOrRoundness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_CircularityOrRoundness)
	.value("XCAFDimTolObjects_GeomToleranceType_Coaxiality", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Coaxiality)
	.value("XCAFDimTolObjects_GeomToleranceType_Concentricity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Concentricity)
	.value("XCAFDimTolObjects_GeomToleranceType_Cylindricity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Cylindricity)
	.value("XCAFDimTolObjects_GeomToleranceType_Flatness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Flatness)
	.value("XCAFDimTolObjects_GeomToleranceType_Parallelism", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Parallelism)
	.value("XCAFDimTolObjects_GeomToleranceType_Perpendicularity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Perpendicularity)
	.value("XCAFDimTolObjects_GeomToleranceType_Position", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Position)
	.value("XCAFDimTolObjects_GeomToleranceType_ProfileOfLine", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_ProfileOfLine)
	.value("XCAFDimTolObjects_GeomToleranceType_ProfileOfSurface", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_ProfileOfSurface)
	.value("XCAFDimTolObjects_GeomToleranceType_Straightness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Straightness)
	.value("XCAFDimTolObjects_GeomToleranceType_Symmetry", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Symmetry)
	.value("XCAFDimTolObjects_GeomToleranceType_TotalRunout", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_TotalRunout)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_GEOMTOLERANCETYPEVALUE
py::enum_<XCAFDimTolObjects_GeomToleranceTypeValue>(mod, "XCAFDimTolObjects_GeomToleranceTypeValue", "Defines types of value of tolerane")
	.value("XCAFDimTolObjects_GeomToleranceTypeValue_None", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_None)
	.value("XCAFDimTolObjects_GeomToleranceTypeValue_Diameter", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceTypeValue_SphericalDiameter", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_SphericalDiameter)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_GEOMTOLERANCEMATREQMODIF
py::enum_<XCAFDimTolObjects_GeomToleranceMatReqModif>(mod, "XCAFDimTolObjects_GeomToleranceMatReqModif", "Defines types of material requirement")
	.value("XCAFDimTolObjects_GeomToleranceMatReqModif_None", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_None)
	.value("XCAFDimTolObjects_GeomToleranceMatReqModif_M", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_M)
	.value("XCAFDimTolObjects_GeomToleranceMatReqModif_L", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_L)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_GEOMTOLERANCEZONEMODIF
py::enum_<XCAFDimTolObjects_GeomToleranceZoneModif>(mod, "XCAFDimTolObjects_GeomToleranceZoneModif", "Defines types of zone")
	.value("XCAFDimTolObjects_GeomToleranceZoneModif_None", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_None)
	.value("XCAFDimTolObjects_GeomToleranceZoneModif_Projected", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_Projected)
	.value("XCAFDimTolObjects_GeomToleranceZoneModif_Runout", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_Runout)
	.value("XCAFDimTolObjects_GeomToleranceZoneModif_NonUniform", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_NonUniform)
	.export_values();


// ENUM: XCAFDIMTOLOBJECTS_TOLERANCEZONEAFFECTEDPLANE
py::enum_<XCAFDimTolObjects_ToleranceZoneAffectedPlane>(mod, "XCAFDimTolObjects_ToleranceZoneAffectedPlane", "Defines types of tolerance zone affected plane")
	.value("XCAFDimTolObjects_ToleranceZoneAffectedPlane_None", XCAFDimTolObjects_ToleranceZoneAffectedPlane::XCAFDimTolObjects_ToleranceZoneAffectedPlane_None)
	.value("XCAFDimTolObjects_ToleranceZoneAffectedPlane_Intersection", XCAFDimTolObjects_ToleranceZoneAffectedPlane::XCAFDimTolObjects_ToleranceZoneAffectedPlane_Intersection)
	.value("XCAFDimTolObjects_ToleranceZoneAffectedPlane_Orientation", XCAFDimTolObjects_ToleranceZoneAffectedPlane::XCAFDimTolObjects_ToleranceZoneAffectedPlane_Orientation)
	.export_values();


// TYPEDEF: XCAFDIMTOLOBJECTS_DIMENSIONMODIFIERSSEQUENCE
bind_NCollection_Sequence<XCAFDimTolObjects_DimensionModif>(mod, "XCAFDimTolObjects_DimensionModifiersSequence", py::module_local(false));

// TYPEDEF: XCAFDIMTOLOBJECTS_DATUMMODIFIERSSEQUENCE
bind_NCollection_Sequence<XCAFDimTolObjects_DatumSingleModif>(mod, "XCAFDimTolObjects_DatumModifiersSequence", py::module_local(false));

// TYPEDEF: XCAFDIMTOLOBJECTS_GEOMTOLERANCEOBJECTSEQUENCE
bind_NCollection_Sequence<opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> >(mod, "XCAFDimTolObjects_GeomToleranceObjectSequence", py::module_local(false));

// TYPEDEF: XCAFDIMTOLOBJECTS_GEOMTOLERANCEMODIFIERSSEQUENCE
bind_NCollection_Sequence<XCAFDimTolObjects_GeomToleranceModif>(mod, "XCAFDimTolObjects_GeomToleranceModifiersSequence", py::module_local(false));

// CLASS: XCAFDIMTOLOBJECTS_GEOMTOLERANCEOBJECT
py::class_<XCAFDimTolObjects_GeomToleranceObject, opencascade::handle<XCAFDimTolObjects_GeomToleranceObject>, Standard_Transient> cls_XCAFDimTolObjects_GeomToleranceObject(mod, "XCAFDimTolObjects_GeomToleranceObject", "Access object to store dimension and tolerance");

// Constructors
cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<>());
cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &>(), py::arg("theObj"));

// Methods
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetSemanticName", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_GeomToleranceObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetType", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceType)) &XCAFDimTolObjects_GeomToleranceObject::SetType, "Sets type of the object.", py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetType", (XCAFDimTolObjects_GeomToleranceType (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetType, "Returns type of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetTypeOfValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceTypeValue)) &XCAFDimTolObjects_GeomToleranceObject::SetTypeOfValue, "Sets type of tolerance value.", py::arg("theTypeOfValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetTypeOfValue", (XCAFDimTolObjects_GeomToleranceTypeValue (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetTypeOfValue, "Returns type of tolerance value.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValue, "Sets tolerance value.", py::arg("theValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetValue, "Returns tolerance value.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaterialRequirementModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceMatReqModif)) &XCAFDimTolObjects_GeomToleranceObject::SetMaterialRequirementModifier, "Sets material requirement of the tolerance.", py::arg("theMatReqModif"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaterialRequirementModifier", (XCAFDimTolObjects_GeomToleranceMatReqModif (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetMaterialRequirementModifier, "Returns material requirement of the tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceZoneModif)) &XCAFDimTolObjects_GeomToleranceObject::SetZoneModifier, "Sets tolerance zone.", py::arg("theZoneModif"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetZoneModifier", (XCAFDimTolObjects_GeomToleranceZoneModif (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetZoneModifier, "Returns tolerance zone.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValueOfZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValueOfZoneModifier, "Sets value associated with tolerance zone.", py::arg("theValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValueOfZoneModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetValueOfZoneModifier, "Returns value associated with tolerance zone.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetModifiers", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceObject::SetModifiers, "Sets new sequence of tolerance modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("AddModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModif)) &XCAFDimTolObjects_GeomToleranceObject::AddModifier, "Adds a tolerance modifier to the sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetModifiers", (XCAFDimTolObjects_GeomToleranceModifiersSequence (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetModifiers, "Returns a sequence of modifiers of the tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaxValueModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetMaxValueModifier, "Sets the maximal upper tolerance value for tolerance with modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaxValueModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetMaxValueModifier, "Returns the maximal upper tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAxis", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2)) &XCAFDimTolObjects_GeomToleranceObject::SetAxis, "None", py::arg("theAxis"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAxis", (gp_Ax2 (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAxis, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasAxis", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasAxis, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_GeomToleranceObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPoint", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPoint, "Sets reference point.", py::arg("thePnt"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPoint, "Returns reference point.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPointTextAttach, "Sets text position.", py::arg("thePntText"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPointTextAttach, "Returns the text position.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPlane, "Returns True if the object has annotation plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPoint, "Returns True if reference point is specified.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPointText, "Returns True if text position is specified.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPresentation", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_GeomToleranceObject::SetPresentation, "Set graphical presentation for object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPresentationName, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasAffectedPlane", (bool (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasAffectedPlane, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAffectedPlaneType", (XCAFDimTolObjects_ToleranceZoneAffectedPlane (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAffectedPlaneType, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlaneType", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_ToleranceZoneAffectedPlane)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlaneType, "None", py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pln &)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlane, "Sets affected plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pln &, const XCAFDimTolObjects_ToleranceZoneAffectedPlane)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlane, "Sets affected plane.", py::arg("thePlane"), py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAffectedPlane", (const gp_Pln & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAffectedPlane, "Returns affected plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_name, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::DynamicType, "None");

// TYPEDEF: XCAFDIMTOLOBJECTS_DATUMOBJECTSEQUENCE
bind_NCollection_Sequence<opencascade::handle<XCAFDimTolObjects_DatumObject> >(mod, "XCAFDimTolObjects_DatumObjectSequence", py::module_local(false));

// CLASS: XCAFDIMTOLOBJECTS_DATUMOBJECT
py::class_<XCAFDimTolObjects_DatumObject, opencascade::handle<XCAFDimTolObjects_DatumObject>, Standard_Transient> cls_XCAFDimTolObjects_DatumObject(mod, "XCAFDimTolObjects_DatumObject", "Access object to store datum");

// Constructors
cls_XCAFDimTolObjects_DatumObject.def(py::init<>());
cls_XCAFDimTolObjects_DatumObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DatumObject> &>(), py::arg("theObj"));

// Methods
cls_XCAFDimTolObjects_DatumObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_DatumObject.def("SetSemanticName", (void (XCAFDimTolObjects_DatumObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_DatumObject.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetName, "Returns datum name.");
cls_XCAFDimTolObjects_DatumObject.def("SetName", (void (XCAFDimTolObjects_DatumObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetName, "Sets datum name.", py::arg("theTag"));
cls_XCAFDimTolObjects_DatumObject.def("GetModifiers", (XCAFDimTolObjects_DatumModifiersSequence (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetModifiers, "Returns a sequence of modifiers of the datum.");
cls_XCAFDimTolObjects_DatumObject.def("SetModifiers", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumObject::SetModifiers, "Sets new sequence of datum modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_DatumObject.def("GetModifierWithValue", [](XCAFDimTolObjects_DatumObject &self, XCAFDimTolObjects_DatumModifWithValue & theModifier, Standard_Real & theValue){ self.GetModifierWithValue(theModifier, theValue); return theValue; }, "Retrieves datum modifier with value.", py::arg("theModifier"), py::arg("theValue"));
cls_XCAFDimTolObjects_DatumObject.def("SetModifierWithValue", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifWithValue, const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetModifierWithValue, "Sets datum modifier with value.", py::arg("theModifier"), py::arg("theValue"));
cls_XCAFDimTolObjects_DatumObject.def("AddModifier", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumSingleModif)) &XCAFDimTolObjects_DatumObject::AddModifier, "Adds a modifier to the datum sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTarget", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTarget, "Returns datum target shape.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &)) &XCAFDimTolObjects_DatumObject::SetDatumTarget, "Sets datum target shape.", py::arg("theShape"));
cls_XCAFDimTolObjects_DatumObject.def("GetPosition", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPosition, "Returns datum position in the related geometric tolerance object.");
cls_XCAFDimTolObjects_DatumObject.def("SetPosition", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetPosition, "Sets datum position in the related geometric tolerance object.", py::arg("thePosition"));
cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "Returns True if the datum target is specified.");
cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Boolean)) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "Sets or drops the datum target indicator.", py::arg("theIsDT"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetType", (XCAFDimTolObjects_DatumTargetType (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetType, "Returns datum target type");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetType", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumTargetType)) &XCAFDimTolObjects_DatumObject::SetDatumTargetType, "Sets datum target to point, line, rectangle, circle or area type.", py::arg("theType"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetAxis", (gp_Ax2 (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetAxis, "Returns datum target axis. The Z axis of the datum placement denotes the normal of the surface pointing away from the material.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetAxis", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetDatumTargetAxis, "Sets datum target axis.", py::arg("theAxis"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetLength", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetLength, "Returns datum target length for line and rectangle types. The length along the X axis of the datum placement.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetLength", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetLength, "Sets datum target length.", py::arg("theLength"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetWidth", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetWidth, "Returns datum target width for rectangle type. The width along the derived Y axis, with the placement itself positioned at the centre of the rectangle.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetWidth", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetWidth, "Sets datum target width.", py::arg("theWidth"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetNumber", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetNumber, "Returns datum target number.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetNumber", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetDatumTargetNumber, "Sets datum target number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DatumObject.def("SetPlane", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_DatumObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_DatumObject.def("SetPoint", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPoint, "Sets a point on the datum target shape.", py::arg("thePnt"));
cls_XCAFDimTolObjects_DatumObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPoint, "Gets point on the datum shape.");
cls_XCAFDimTolObjects_DatumObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPointTextAttach, "Sets a position of the datum text.", py::arg("thePntText"));
cls_XCAFDimTolObjects_DatumObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPointTextAttach, "Gets datum text position.");
cls_XCAFDimTolObjects_DatumObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPlane, "Returns True if the datum has annotation plane.");
cls_XCAFDimTolObjects_DatumObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPoint, "Returns True if point on the datum target is specified.");
cls_XCAFDimTolObjects_DatumObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPointText, "Returns True if the datum text position is specified.");
cls_XCAFDimTolObjects_DatumObject.def("SetPresentation", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetPresentation, "Set graphical presentation for object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_DatumObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DatumObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPresentationName, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DatumObject.def("HasDatumTargetParams", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)()) &XCAFDimTolObjects_DatumObject::HasDatumTargetParams, "Returns True if the datum has valid parameters for datum target (width, length, circle radius etc)");
cls_XCAFDimTolObjects_DatumObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DatumObject::get_type_name, "None");
cls_XCAFDimTolObjects_DatumObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DatumObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_DatumObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::DynamicType, "None");

// TYPEDEF: XCAFDIMTOLOBJECTS_DATAMAPOFTOLERANCEDATUM
bind_NCollection_DataMap<opencascade::handle<XCAFDimTolObjects_GeomToleranceObject>, opencascade::handle<XCAFDimTolObjects_DatumObject>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "XCAFDimTolObjects_DataMapOfToleranceDatum", py::module_local(false));

// TYPEDEF: XCAFDIMTOLOBJECTS_DIMENSIONOBJECTSEQUENCE
bind_NCollection_Sequence<opencascade::handle<XCAFDimTolObjects_DimensionObject> >(mod, "XCAFDimTolObjects_DimensionObjectSequence", py::module_local(false));

// CLASS: XCAFDIMTOLOBJECTS_DIMENSIONOBJECT
py::class_<XCAFDimTolObjects_DimensionObject, opencascade::handle<XCAFDimTolObjects_DimensionObject>, Standard_Transient> cls_XCAFDimTolObjects_DimensionObject(mod, "XCAFDimTolObjects_DimensionObject", "Access object to store dimension data");

// Constructors
cls_XCAFDimTolObjects_DimensionObject.def(py::init<>());
cls_XCAFDimTolObjects_DimensionObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DimensionObject> &>(), py::arg("theObj"));

// Methods
cls_XCAFDimTolObjects_DimensionObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_DimensionObject.def("SetSemanticName", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DimensionObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_DimensionObject.def("SetQualifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionQualifier)) &XCAFDimTolObjects_DimensionObject::SetQualifier, "Sets dimension qualifier as min., max. or average.", py::arg("theQualifier"));
cls_XCAFDimTolObjects_DimensionObject.def("GetQualifier", (XCAFDimTolObjects_DimensionQualifier (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetQualifier, "Returns dimension qualifier.");
cls_XCAFDimTolObjects_DimensionObject.def("HasQualifier", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasQualifier, "Returns True if the object has dimension qualifier.");
cls_XCAFDimTolObjects_DimensionObject.def("SetType", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionType)) &XCAFDimTolObjects_DimensionObject::SetType, "Sets a specific type of dimension.", py::arg("theTyupe"));
cls_XCAFDimTolObjects_DimensionObject.def("GetType", (XCAFDimTolObjects_DimensionType (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetType, "Returns dimension type.");
cls_XCAFDimTolObjects_DimensionObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetValue, "Returns the main dimension value. It will be the middle value in case of range dimension.");
cls_XCAFDimTolObjects_DimensionObject.def("GetValues", (opencascade::handle<TColStd_HArray1OfReal> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetValues, "Returns raw array of dimension values");
cls_XCAFDimTolObjects_DimensionObject.def("SetValue", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetValue, "Sets the main dimension value. Overwrites previous values.", py::arg("theValue"));
cls_XCAFDimTolObjects_DimensionObject.def("SetValues", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &XCAFDimTolObjects_DimensionObject::SetValues, "Replaces current raw array of dimension values with theValues array.", py::arg("theValue"));
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithRange", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithRange, "Returns True if the dimension is of range kind. Dimension is of range kind if its values array contains two elements defining lower and upper bounds.");
cls_XCAFDimTolObjects_DimensionObject.def("SetUpperBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperBound, "Sets the upper bound of the range dimension, otherwise resets it to an empty range with the specified upper bound.", py::arg("theUpperBound"));
cls_XCAFDimTolObjects_DimensionObject.def("SetLowerBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerBound, "Sets the lower bound of the range dimension, otherwise resets it to an empty range with the specified lower bound.", py::arg("theLowerBound"));
cls_XCAFDimTolObjects_DimensionObject.def("GetUpperBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetUpperBound, "Returns the upper bound of the range dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("GetLowerBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetLowerBound, "Returns the lower bound of the range dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithPlusMinusTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithPlusMinusTolerance, "Returns True if the dimension is of +/- tolerance kind. Dimension is of +/- tolerance kind if its values array contains three elements defining the main value and the lower/upper tolerances.");
cls_XCAFDimTolObjects_DimensionObject.def("SetUpperTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperTolValue, "Sets the upper value of the toleranced dimension, otherwise resets a simple dimension to toleranced one with the specified lower/upper tolerances. Returns False in case of range dimension.", py::arg("theUperTolValue"));
cls_XCAFDimTolObjects_DimensionObject.def("SetLowerTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerTolValue, "Sets the lower value of the toleranced dimension, otherwise resets a simple dimension to toleranced one with the specified lower/upper tolerances. Returns False in case of range dimension.", py::arg("theLowerTolValue"));
cls_XCAFDimTolObjects_DimensionObject.def("GetUpperTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetUpperTolValue, "Returns the lower value of the toleranced dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("GetLowerTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetLowerTolValue, "Returns the upper value of the toleranced dimension, otherwise - zero.");
cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithClassOfTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::IsDimWithClassOfTolerance, "Returns True if the form variance was set to not XCAFDimTolObjects_DimensionFormVariance_None value.");
cls_XCAFDimTolObjects_DimensionObject.def("SetClassOfTolerance", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Boolean, const XCAFDimTolObjects_DimensionFormVariance, const XCAFDimTolObjects_DimensionGrade)) &XCAFDimTolObjects_DimensionObject::SetClassOfTolerance, "Sets tolerance class of the dimension.", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
cls_XCAFDimTolObjects_DimensionObject.def("GetClassOfTolerance", [](XCAFDimTolObjects_DimensionObject &self, Standard_Boolean & theHole, XCAFDimTolObjects_DimensionFormVariance & theFormVariance, XCAFDimTolObjects_DimensionGrade & theGrade){ Standard_Boolean rv = self.GetClassOfTolerance(theHole, theFormVariance, theGrade); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theHole); }, "Retrieves tolerance class parameters of the dimension. Returns True if the dimension is toleranced.", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
cls_XCAFDimTolObjects_DimensionObject.def("SetNbOfDecimalPlaces", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::SetNbOfDecimalPlaces, "Sets the number of places to the left and right of the decimal point respectively.", py::arg("theL"), py::arg("theR"));
cls_XCAFDimTolObjects_DimensionObject.def("GetNbOfDecimalPlaces", [](XCAFDimTolObjects_DimensionObject &self, Standard_Integer & theL, Standard_Integer & theR){ self.GetNbOfDecimalPlaces(theL, theR); return std::tuple<Standard_Integer &, Standard_Integer &>(theL, theR); }, "Returns the number of places to the left and right of the decimal point respectively.", py::arg("theL"), py::arg("theR"));
cls_XCAFDimTolObjects_DimensionObject.def("GetModifiers", (XCAFDimTolObjects_DimensionModifiersSequence (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetModifiers, "Returns a sequence of modifiers of the dimension.");
cls_XCAFDimTolObjects_DimensionObject.def("SetModifiers", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionObject::SetModifiers, "Sets new sequence of dimension modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_DimensionObject.def("AddModifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModif)) &XCAFDimTolObjects_DimensionObject::AddModifier, "Adds a modifier to the dimension sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPath", (TopoDS_Edge (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPath, "Returns a 'curve' along which the dimension is measured.");
cls_XCAFDimTolObjects_DimensionObject.def("SetPath", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Edge &)) &XCAFDimTolObjects_DimensionObject::SetPath, "Sets a 'curve' along which the dimension is measured.", py::arg("thePath"));
cls_XCAFDimTolObjects_DimensionObject.def("GetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(gp_Dir &) const) &XCAFDimTolObjects_DimensionObject::GetDirection, "Returns the orientation of the dimension in annotation plane.", py::arg("theDir"));
cls_XCAFDimTolObjects_DimensionObject.def("SetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const gp_Dir &)) &XCAFDimTolObjects_DimensionObject::SetDirection, "Sets an orientation of the dimension in annotation plane.", py::arg("theDir"));
cls_XCAFDimTolObjects_DimensionObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DimensionObject::SetPointTextAttach, "Sets position of the dimension text.", py::arg("thePntText"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPointTextAttach, "Returns position of the dimension text.");
cls_XCAFDimTolObjects_DimensionObject.def("HasTextPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasTextPoint, "Returns True if the position of dimension text is specified.");
cls_XCAFDimTolObjects_DimensionObject.def("SetPlane", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DimensionObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_DimensionObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPlane, "Returns True if the object has annotation plane.");
cls_XCAFDimTolObjects_DimensionObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPoint, "Returns true, if connection point exists (for dimesional_size), if connection point for the first shape exists (for dimensional_location).");
cls_XCAFDimTolObjects_DimensionObject.def("HasPoint2", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasPoint2, "None");
cls_XCAFDimTolObjects_DimensionObject.def("SetPoint", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint, "Set connection point (for dimesional_size), Set connection point for the first shape (for dimensional_location).", py::arg("thePnt"));
cls_XCAFDimTolObjects_DimensionObject.def("SetPoint2", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint2, "None", py::arg("thePnt"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPoint", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPoint, "Get connection point (for dimesional_size), Get connection point for the first shape (for dimensional_location).");
cls_XCAFDimTolObjects_DimensionObject.def("GetPoint2", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPoint2, "None");
cls_XCAFDimTolObjects_DimensionObject.def("SetPresentation", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DimensionObject::SetPresentation, "Set graphical presentation for the object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_DimensionObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DimensionObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::GetPresentationName, "Returns graphical presentation of the object");
cls_XCAFDimTolObjects_DimensionObject.def("HasDescriptions", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::HasDescriptions, "Returns true, if the object has descriptions.");
cls_XCAFDimTolObjects_DimensionObject.def("NbDescriptions", (Standard_Integer (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::NbDescriptions, "Returns number of descriptions.");
cls_XCAFDimTolObjects_DimensionObject.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const) &XCAFDimTolObjects_DimensionObject::GetDescription, "Returns description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("GetDescriptionName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const) &XCAFDimTolObjects_DimensionObject::GetDescriptionName, "Returns name of description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("RemoveDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::RemoveDescription, "Remove description with the given number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DimensionObject.def("AddDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TCollection_HAsciiString>, const opencascade::handle<TCollection_HAsciiString>)) &XCAFDimTolObjects_DimensionObject::AddDescription, "Add new description.", py::arg("theDescription"), py::arg("theName"));
cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DimensionObject::get_type_name, "None");
cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DimensionObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_DimensionObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DimensionObject::*)() const) &XCAFDimTolObjects_DimensionObject::DynamicType, "None");

// CLASS: XCAFDIMTOLOBJECTS_TOOL
py::class_<XCAFDimTolObjects_Tool> cls_XCAFDimTolObjects_Tool(mod, "XCAFDimTolObjects_Tool", "None");

// Constructors
cls_XCAFDimTolObjects_Tool.def(py::init<const opencascade::handle<TDocStd_Document> &>(), py::arg("theDoc"));

// Methods
// cls_XCAFDimTolObjects_Tool.def_static("operator new_", (void * (*)(size_t)) &XCAFDimTolObjects_Tool::operator new, "None", py::arg("theSize"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete_", (void (*)(void *)) &XCAFDimTolObjects_Tool::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDimTolObjects_Tool::operator new[], "None", py::arg("theSize"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete[]_", (void (*)(void *)) &XCAFDimTolObjects_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDimTolObjects_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDimTolObjects_Tool.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDimTolObjects_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDimTolObjects_Tool.def("GetDimensions", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_DimensionObjectSequence &) const) &XCAFDimTolObjects_Tool::GetDimensions, "Returns a sequence of Dimensions currently stored in the GD&T table", py::arg("theDimensionObjectSequence"));
cls_XCAFDimTolObjects_Tool.def("GetRefDimensions", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_DimensionObjectSequence &) const) &XCAFDimTolObjects_Tool::GetRefDimensions, "Returns all Dimensions defined for Shape", py::arg("theShape"), py::arg("theDimensions"));
cls_XCAFDimTolObjects_Tool.def("GetGeomTolerances", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const) &XCAFDimTolObjects_Tool::GetGeomTolerances, "Returns a sequence of Tolerances currently stored in the GD&T table", py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
cls_XCAFDimTolObjects_Tool.def("GetRefGeomTolerances", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const) &XCAFDimTolObjects_Tool::GetRefGeomTolerances, "Returns all GeomTolerances defined for Shape", py::arg("theShape"), py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
cls_XCAFDimTolObjects_Tool.def("GetRefDatum", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, opencascade::handle<XCAFDimTolObjects_DatumObject> &) const) &XCAFDimTolObjects_Tool::GetRefDatum, "Returns DatumObject defined for Shape", py::arg("theShape"), py::arg("theDatum"));


}
