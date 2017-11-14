#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <XCAFDimTolObjects_DimensionModif.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDimTolObjects_DimensionModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumSingleModif.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>
#include <XCAFDimTolObjects_DimensionGrade.hxx>
#include <XCAFDimTolObjects_DimensionType.hxx>
#include <XCAFDimTolObjects_DatumTargetType.hxx>
#include <XCAFDimTolObjects_DimensionQualifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceType.hxx>
#include <XCAFDimTolObjects_GeomToleranceTypeValue.hxx>
#include <Standard_Transient.hxx>
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <XCAFDimTolObjects_GeomToleranceMatReqModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceZoneModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceModifiersSequence.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Type.hxx>
#include <XCAFDimTolObjects_GeomToleranceObjectSequence.hxx>
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <XCAFDimTolObjects_DatumObjectSequence.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <XCAFDimTolObjects_DataMapOfToleranceDatum.hxx>
#include <XCAFDimTolObjects_DimensionObject.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Dir.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <XCAFDimTolObjects_DimensionObjectSequence.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFDimTolObjects_Tool.hxx>

PYBIND11_MODULE(XCAFDimTolObjects, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TDocStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionModif.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DatumSingleModif.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DatumModifWithValue.hxx
	py::enum_<XCAFDimTolObjects_DatumModifWithValue>(mod, "XCAFDimTolObjects_DatumModifWithValue", "Defines modifirs")
		.value("XCAFDimTolObjects_DatumModifWithValue_None", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_None)
		.value("XCAFDimTolObjects_DatumModifWithValue_CircularOrCylindrical", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_CircularOrCylindrical)
		.value("XCAFDimTolObjects_DatumModifWithValue_Distance", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Distance)
		.value("XCAFDimTolObjects_DatumModifWithValue_Projected", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Projected)
		.value("XCAFDimTolObjects_DatumModifWithValue_Spherical", XCAFDimTolObjects_DatumModifWithValue::XCAFDimTolObjects_DatumModifWithValue_Spherical)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionFormVariance.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionGrade.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionType.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DatumTargetType.hxx
	py::enum_<XCAFDimTolObjects_DatumTargetType>(mod, "XCAFDimTolObjects_DatumTargetType", "Defines types of dimension")
		.value("XCAFDimTolObjects_DatumTargetType_Point", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Point)
		.value("XCAFDimTolObjects_DatumTargetType_Line", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Line)
		.value("XCAFDimTolObjects_DatumTargetType_Rectangle", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Rectangle)
		.value("XCAFDimTolObjects_DatumTargetType_Circle", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Circle)
		.value("XCAFDimTolObjects_DatumTargetType_Area", XCAFDimTolObjects_DatumTargetType::XCAFDimTolObjects_DatumTargetType_Area)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionQualifier.hxx
	py::enum_<XCAFDimTolObjects_DimensionQualifier>(mod, "XCAFDimTolObjects_DimensionQualifier", "Defines types of qualifier")
		.value("XCAFDimTolObjects_DimensionQualifier_None", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_None)
		.value("XCAFDimTolObjects_DimensionQualifier_Min", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Min)
		.value("XCAFDimTolObjects_DimensionQualifier_Max", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Max)
		.value("XCAFDimTolObjects_DimensionQualifier_Avg", XCAFDimTolObjects_DimensionQualifier::XCAFDimTolObjects_DimensionQualifier_Avg)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceModif.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceType.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceTypeValue.hxx
	py::enum_<XCAFDimTolObjects_GeomToleranceTypeValue>(mod, "XCAFDimTolObjects_GeomToleranceTypeValue", "Defines types of value of tolerane")
		.value("XCAFDimTolObjects_GeomToleranceTypeValue_None", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_None)
		.value("XCAFDimTolObjects_GeomToleranceTypeValue_Diameter", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_Diameter)
		.value("XCAFDimTolObjects_GeomToleranceTypeValue_SphericalDiameter", XCAFDimTolObjects_GeomToleranceTypeValue::XCAFDimTolObjects_GeomToleranceTypeValue_SphericalDiameter)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceMatReqModif.hxx
	py::enum_<XCAFDimTolObjects_GeomToleranceMatReqModif>(mod, "XCAFDimTolObjects_GeomToleranceMatReqModif", "Defines types of material requirement")
		.value("XCAFDimTolObjects_GeomToleranceMatReqModif_None", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_None)
		.value("XCAFDimTolObjects_GeomToleranceMatReqModif_M", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_M)
		.value("XCAFDimTolObjects_GeomToleranceMatReqModif_L", XCAFDimTolObjects_GeomToleranceMatReqModif::XCAFDimTolObjects_GeomToleranceMatReqModif_L)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceZoneModif.hxx
	py::enum_<XCAFDimTolObjects_GeomToleranceZoneModif>(mod, "XCAFDimTolObjects_GeomToleranceZoneModif", "Defines types of zone")
		.value("XCAFDimTolObjects_GeomToleranceZoneModif_None", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_None)
		.value("XCAFDimTolObjects_GeomToleranceZoneModif_Projected", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_Projected)
		.value("XCAFDimTolObjects_GeomToleranceZoneModif_Runout", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_Runout)
		.value("XCAFDimTolObjects_GeomToleranceZoneModif_NonUniform", XCAFDimTolObjects_GeomToleranceZoneModif::XCAFDimTolObjects_GeomToleranceZoneModif_NonUniform)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_GeomToleranceObject.hxx
	py::class_<XCAFDimTolObjects_GeomToleranceObject, opencascade::handle<XCAFDimTolObjects_GeomToleranceObject>, Standard_Transient> cls_XCAFDimTolObjects_GeomToleranceObject(mod, "XCAFDimTolObjects_GeomToleranceObject", "attribute to store dimension and tolerance");
	cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<>());
	cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &>(), py::arg("theObj"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetType", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceType)) &XCAFDimTolObjects_GeomToleranceObject::SetType, "None", py::arg("theType"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetType", (XCAFDimTolObjects_GeomToleranceType (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetType, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetTypeOfValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceTypeValue)) &XCAFDimTolObjects_GeomToleranceObject::SetTypeOfValue, "None", py::arg("theTypeOfValue"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetTypeOfValue", (XCAFDimTolObjects_GeomToleranceTypeValue (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetTypeOfValue, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValue, "None", py::arg("theValue"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetValue, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaterialRequirementModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceMatReqModif)) &XCAFDimTolObjects_GeomToleranceObject::SetMaterialRequirementModifier, "None", py::arg("theMatReqModif"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaterialRequirementModifier", (XCAFDimTolObjects_GeomToleranceMatReqModif (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetMaterialRequirementModifier, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceZoneModif)) &XCAFDimTolObjects_GeomToleranceObject::SetZoneModifier, "None", py::arg("theZoneModif"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetZoneModifier", (XCAFDimTolObjects_GeomToleranceZoneModif (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetZoneModifier, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValueOfZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValueOfZoneModifier, "None", py::arg("theValue"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValueOfZoneModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetValueOfZoneModifier, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetModifiers", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceObject::SetModifiers, "None", py::arg("theModifiers"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("AddModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModif)) &XCAFDimTolObjects_GeomToleranceObject::AddModifier, "None", py::arg("theModifier"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetModifiers", (XCAFDimTolObjects_GeomToleranceModifiersSequence (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetModifiers, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaxValueModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetMaxValueModifier, "None", py::arg("theModifier"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaxValueModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetMaxValueModifier, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAxis", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2)) &XCAFDimTolObjects_GeomToleranceObject::SetAxis, "None", py::arg("theAxis"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAxis", (gp_Ax2 (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetAxis, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("HasAxis", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::HasAxis, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_GeomToleranceObject::SetPlane, "None", py::arg("thePlane"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetPlane, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPoint", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPoint, "None", py::arg("thePnt"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetPoint, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPointTextAttach, "None", py::arg("thePntText"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetPointTextAttach, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::HasPlane, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::HasPoint, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::HasPointText, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPresentation", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_GeomToleranceObject::SetPresentation, "Set graphical presentation for object", py::arg("thePresentation"), py::arg("thePresentationName"));
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetPresentation, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::GetPresentationName, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_name, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_descriptor, "None");
	cls_XCAFDimTolObjects_GeomToleranceObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_GeomToleranceObject::*)() const ) &XCAFDimTolObjects_GeomToleranceObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DatumObject.hxx
	py::class_<XCAFDimTolObjects_DatumObject, opencascade::handle<XCAFDimTolObjects_DatumObject>, Standard_Transient> cls_XCAFDimTolObjects_DatumObject(mod, "XCAFDimTolObjects_DatumObject", "object to store datum");
	cls_XCAFDimTolObjects_DatumObject.def(py::init<>());
	cls_XCAFDimTolObjects_DatumObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DatumObject> &>(), py::arg("theObj"));
	cls_XCAFDimTolObjects_DatumObject.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetName, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetName", (void (XCAFDimTolObjects_DatumObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetName, "None", py::arg("theTag"));
	cls_XCAFDimTolObjects_DatumObject.def("GetModifiers", (XCAFDimTolObjects_DatumModifiersSequence (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetModifiers, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetModifiers", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumObject::SetModifiers, "None", py::arg("theModifiers"));
	cls_XCAFDimTolObjects_DatumObject.def("GetModifierWithValue", (void (XCAFDimTolObjects_DatumObject::*)(XCAFDimTolObjects_DatumModifWithValue &, Standard_Real &) const ) &XCAFDimTolObjects_DatumObject::GetModifierWithValue, "None", py::arg("theModifier"), py::arg("theValue"));
	cls_XCAFDimTolObjects_DatumObject.def("SetModifierWithValue", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifWithValue, const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetModifierWithValue, "None", py::arg("theModifier"), py::arg("theValue"));
	cls_XCAFDimTolObjects_DatumObject.def("AddModifier", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumSingleModif)) &XCAFDimTolObjects_DatumObject::AddModifier, "None", py::arg("theModifier"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTarget", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTarget, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &)) &XCAFDimTolObjects_DatumObject::SetDatumTarget, "None", py::arg("theShape"));
	cls_XCAFDimTolObjects_DatumObject.def("GetPosition", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPosition, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetPosition", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetPosition, "None", py::arg("thePosition"));
	cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "None");
	cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Boolean)) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "None", py::arg("theIsDT"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetType", (XCAFDimTolObjects_DatumTargetType (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTargetType, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetType", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumTargetType)) &XCAFDimTolObjects_DatumObject::SetDatumTargetType, "None", py::arg("theType"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetAxis", (gp_Ax2 (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTargetAxis, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetAxis", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetDatumTargetAxis, "None", py::arg("theAxis"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetLength", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTargetLength, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetLength", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetLength, "None", py::arg("theLength"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetWidth", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTargetWidth, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetWidth", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetWidth, "None", py::arg("theWidth"));
	cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetNumber", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetDatumTargetNumber, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetNumber", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetDatumTargetNumber, "None", py::arg("theNumber"));
	cls_XCAFDimTolObjects_DatumObject.def("SetPlane", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetPlane, "None", py::arg("thePlane"));
	cls_XCAFDimTolObjects_DatumObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPlane, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetPoint", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPoint, "None", py::arg("thePnt"));
	cls_XCAFDimTolObjects_DatumObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPoint, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPointTextAttach, "None", py::arg("thePntText"));
	cls_XCAFDimTolObjects_DatumObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPointTextAttach, "None");
	cls_XCAFDimTolObjects_DatumObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::HasPlane, "None");
	cls_XCAFDimTolObjects_DatumObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::HasPoint, "None");
	cls_XCAFDimTolObjects_DatumObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::HasPointText, "None");
	cls_XCAFDimTolObjects_DatumObject.def("SetPresentation", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetPresentation, "Set graphical presentation for object", py::arg("thePresentation"), py::arg("thePresentationName"));
	cls_XCAFDimTolObjects_DatumObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPresentation, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_DatumObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::GetPresentationName, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_DatumObject.def("HasDatumTargetParams", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)()) &XCAFDimTolObjects_DatumObject::HasDatumTargetParams, "Returns true if datum has valid parameters for datum target (width, length, circle radius etc)");
	cls_XCAFDimTolObjects_DatumObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DatumObject::get_type_name, "None");
	cls_XCAFDimTolObjects_DatumObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DatumObject::get_type_descriptor, "None");
	cls_XCAFDimTolObjects_DatumObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DatumObject::*)() const ) &XCAFDimTolObjects_DatumObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_DimensionObject.hxx
	py::class_<XCAFDimTolObjects_DimensionObject, opencascade::handle<XCAFDimTolObjects_DimensionObject>, Standard_Transient> cls_XCAFDimTolObjects_DimensionObject(mod, "XCAFDimTolObjects_DimensionObject", "object to store dimension");
	cls_XCAFDimTolObjects_DimensionObject.def(py::init<>());
	cls_XCAFDimTolObjects_DimensionObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DimensionObject> &>(), py::arg("theObj"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetQualifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionQualifier)) &XCAFDimTolObjects_DimensionObject::SetQualifier, "None", py::arg("theQualifier"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetQualifier", (XCAFDimTolObjects_DimensionQualifier (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetQualifier, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("HasQualifier", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasQualifier, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetType", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionType)) &XCAFDimTolObjects_DimensionObject::SetType, "None", py::arg("theTyupe"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetType", (XCAFDimTolObjects_DimensionType (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetType, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetValue, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("GetValues", (opencascade::handle<TColStd_HArray1OfReal> (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetValues, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetValue", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetValue, "None", py::arg("theValue"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetValues", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &XCAFDimTolObjects_DimensionObject::SetValues, "None", py::arg("theValue"));
	cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithRange", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::IsDimWithRange, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetUpperBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperBound, "None", py::arg("theUpperBound"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetLowerBound", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerBound, "None", py::arg("theLowerBound"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetUpperBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetUpperBound, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("GetLowerBound", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetLowerBound, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithPlusMinusTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::IsDimWithPlusMinusTolerance, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetUpperTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetUpperTolValue, "None", py::arg("theUperTolValue"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetLowerTolValue", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const Standard_Real)) &XCAFDimTolObjects_DimensionObject::SetLowerTolValue, "None", py::arg("theLowerTolValue"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetUpperTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetUpperTolValue, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("GetLowerTolValue", (Standard_Real (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetLowerTolValue, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("IsDimWithClassOfTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::IsDimWithClassOfTolerance, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetClassOfTolerance", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Boolean, const XCAFDimTolObjects_DimensionFormVariance, const XCAFDimTolObjects_DimensionGrade)) &XCAFDimTolObjects_DimensionObject::SetClassOfTolerance, "None", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetClassOfTolerance", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(Standard_Boolean &, XCAFDimTolObjects_DimensionFormVariance &, XCAFDimTolObjects_DimensionGrade &) const ) &XCAFDimTolObjects_DimensionObject::GetClassOfTolerance, "None", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetNbOfDecimalPlaces", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::SetNbOfDecimalPlaces, "None", py::arg("theL"), py::arg("theR"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetNbOfDecimalPlaces", (void (XCAFDimTolObjects_DimensionObject::*)(Standard_Integer &, Standard_Integer &) const ) &XCAFDimTolObjects_DimensionObject::GetNbOfDecimalPlaces, "None", py::arg("theL"), py::arg("theR"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetModifiers", (XCAFDimTolObjects_DimensionModifiersSequence (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetModifiers, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetModifiers", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionObject::SetModifiers, "None", py::arg("theModifiers"));
	cls_XCAFDimTolObjects_DimensionObject.def("AddModifier", (void (XCAFDimTolObjects_DimensionObject::*)(const XCAFDimTolObjects_DimensionModif)) &XCAFDimTolObjects_DimensionObject::AddModifier, "None", py::arg("theModifier"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPath", (TopoDS_Edge (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPath, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetPath", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Edge &)) &XCAFDimTolObjects_DimensionObject::SetPath, "None", py::arg("thePath"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(gp_Dir &) const ) &XCAFDimTolObjects_DimensionObject::GetDirection, "None", py::arg("theDir"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetDirection", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)(const gp_Dir &)) &XCAFDimTolObjects_DimensionObject::SetDirection, "None", py::arg("theDir"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPoints", (opencascade::handle<TColgp_HArray1OfPnt> (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPoints, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DimensionObject::SetPointTextAttach, "None", py::arg("thePntText"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPointTextAttach, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("HasTextPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasTextPoint, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetPlane", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DimensionObject::SetPlane, "None", py::arg("thePlane"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPlane, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasPlane, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasPoint, "Returns true, if connection point exists (for dimesional_size), if connection point for first shape exists (for dimensional_location)");
	cls_XCAFDimTolObjects_DimensionObject.def("HasPoint2", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasPoint2, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetPoint", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint, "Set connection point (for dimesional_size), Set connection point for first shape (for dimensional_location)", py::arg("thePnt"));
	cls_XCAFDimTolObjects_DimensionObject.def("SetPoint2", (void (XCAFDimTolObjects_DimensionObject::*)(const gp_Pnt)) &XCAFDimTolObjects_DimensionObject::SetPoint2, "None", py::arg("thePnt"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPoint", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPoint, "Get connection point (for dimesional_size), Get connection point for first shape (for dimensional_location)");
	cls_XCAFDimTolObjects_DimensionObject.def("GetPoint2", (gp_Pnt (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPoint2, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("SetPresentation", (void (XCAFDimTolObjects_DimensionObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DimensionObject::SetPresentation, "Set graphical presentation for object", py::arg("thePresentation"), py::arg("thePresentationName"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPresentation, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_DimensionObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::GetPresentationName, "Returns graphical presentation of the object");
	cls_XCAFDimTolObjects_DimensionObject.def("HasDescriptions", (Standard_Boolean (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::HasDescriptions, "Returns true, if the object has descriptions");
	cls_XCAFDimTolObjects_DimensionObject.def("NbDescriptions", (Standard_Integer (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::NbDescriptions, "Returns number of descriptions");
	cls_XCAFDimTolObjects_DimensionObject.def("GetDescription", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionObject::GetDescription, "Returns description with the given number", py::arg("theNumber"));
	cls_XCAFDimTolObjects_DimensionObject.def("GetDescriptionName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionObject::GetDescriptionName, "Returns name of description with the given number", py::arg("theNumber"));
	cls_XCAFDimTolObjects_DimensionObject.def("RemoveDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObject::RemoveDescription, "Remove description with the given number", py::arg("theNumber"));
	cls_XCAFDimTolObjects_DimensionObject.def("AddDescription", (void (XCAFDimTolObjects_DimensionObject::*)(const opencascade::handle<TCollection_HAsciiString>, const opencascade::handle<TCollection_HAsciiString>)) &XCAFDimTolObjects_DimensionObject::AddDescription, "Add new description", py::arg("theDescription"), py::arg("theName"));
	cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DimensionObject::get_type_name, "None");
	cls_XCAFDimTolObjects_DimensionObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DimensionObject::get_type_descriptor, "None");
	cls_XCAFDimTolObjects_DimensionObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DimensionObject::*)() const ) &XCAFDimTolObjects_DimensionObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFDimTolObjects_Tool.hxx
	py::class_<XCAFDimTolObjects_Tool, std::unique_ptr<XCAFDimTolObjects_Tool, Deleter<XCAFDimTolObjects_Tool>>> cls_XCAFDimTolObjects_Tool(mod, "XCAFDimTolObjects_Tool", "None");
	cls_XCAFDimTolObjects_Tool.def(py::init<const opencascade::handle<TDocStd_Document> &>(), py::arg("theDoc"));
	cls_XCAFDimTolObjects_Tool.def("GetDimensions", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_DimensionObjectSequence &) const ) &XCAFDimTolObjects_Tool::GetDimensions, "Returns a sequence of Dimensions currently stored in the DGTtable", py::arg("theDimensionObjectSequence"));
	cls_XCAFDimTolObjects_Tool.def("GetRefDimensions", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_DimensionObjectSequence &) const ) &XCAFDimTolObjects_Tool::GetRefDimensions, "Returns all Dimensions defined for Shape", py::arg("theShape"), py::arg("theDimensions"));
	cls_XCAFDimTolObjects_Tool.def("GetGeomTolerances", (void (XCAFDimTolObjects_Tool::*)(XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const ) &XCAFDimTolObjects_Tool::GetGeomTolerances, "Returns a sequence of Tolerancess currently stored in the DGTtable", py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
	cls_XCAFDimTolObjects_Tool.def("GetRefGeomTolerances", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, XCAFDimTolObjects_GeomToleranceObjectSequence &, XCAFDimTolObjects_DatumObjectSequence &, XCAFDimTolObjects_DataMapOfToleranceDatum &) const ) &XCAFDimTolObjects_Tool::GetRefGeomTolerances, "Returns all GeomTolerances defined for Shape", py::arg("theShape"), py::arg("theGeomToleranceObjectSequence"), py::arg("theDatumObjectSequence"), py::arg("theMap"));
	cls_XCAFDimTolObjects_Tool.def("GetRefDatum", (Standard_Boolean (XCAFDimTolObjects_Tool::*)(const TopoDS_Shape &, opencascade::handle<XCAFDimTolObjects_DatumObject> &) const ) &XCAFDimTolObjects_Tool::GetRefDatum, "Returns DatumObject defined for Shape", py::arg("theShape"), py::arg("theDatum"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_DimensionModifiersSequence, std::unique_ptr<XCAFDimTolObjects_DimensionModifiersSequence, Deleter<XCAFDimTolObjects_DimensionModifiersSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_DimensionModifiersSequence(mod, "XCAFDimTolObjects_DimensionModifiersSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def(py::init<>());
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def(py::init([] (const XCAFDimTolObjects_DimensionModifiersSequence &other) {return new XCAFDimTolObjects_DimensionModifiersSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("begin", (XCAFDimTolObjects_DimensionModifiersSequence::iterator (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("end", (XCAFDimTolObjects_DimensionModifiersSequence::iterator (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("cbegin", (XCAFDimTolObjects_DimensionModifiersSequence::const_iterator (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("cend", (XCAFDimTolObjects_DimensionModifiersSequence::const_iterator (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Reverse", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)()) &XCAFDimTolObjects_DimensionModifiersSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Exchange", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionModifiersSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DimensionModifiersSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Clear", [](XCAFDimTolObjects_DimensionModifiersSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Clear", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DimensionModifiersSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Assign", (XCAFDimTolObjects_DimensionModifiersSequence & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("assign", (XCAFDimTolObjects_DimensionModifiersSequence & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(XCAFDimTolObjects_DimensionModifiersSequence::Iterator &)) &XCAFDimTolObjects_DimensionModifiersSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionModifiersSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionModifiersSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Append", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Append", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(XCAFDimTolObjects_DimensionModifiersSequence::Iterator &, const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Split", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionModifiersSequence &)) &XCAFDimTolObjects_DimensionModifiersSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("First", (const XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::First, "First item access");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("ChangeFirst", (XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)()) &XCAFDimTolObjects_DimensionModifiersSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Last", (const XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)() const ) &XCAFDimTolObjects_DimensionModifiersSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("ChangeLast", (XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)()) &XCAFDimTolObjects_DimensionModifiersSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("Value", (const XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionModifiersSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("__call__", (const XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionModifiersSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("ChangeValue", (XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionModifiersSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("__call__", (XCAFDimTolObjects_DimensionModif & (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionModifiersSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("SetValue", (void (XCAFDimTolObjects_DimensionModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DimensionModif &)) &XCAFDimTolObjects_DimensionModifiersSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionModifiersSequence.def("__iter__", [](const XCAFDimTolObjects_DimensionModifiersSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_DatumModifiersSequence, std::unique_ptr<XCAFDimTolObjects_DatumModifiersSequence, Deleter<XCAFDimTolObjects_DatumModifiersSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_DatumModifiersSequence(mod, "XCAFDimTolObjects_DatumModifiersSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def(py::init<>());
	cls_XCAFDimTolObjects_DatumModifiersSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def(py::init([] (const XCAFDimTolObjects_DatumModifiersSequence &other) {return new XCAFDimTolObjects_DatumModifiersSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("begin", (XCAFDimTolObjects_DatumModifiersSequence::iterator (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("end", (XCAFDimTolObjects_DatumModifiersSequence::iterator (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("cbegin", (XCAFDimTolObjects_DatumModifiersSequence::const_iterator (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("cend", (XCAFDimTolObjects_DatumModifiersSequence::const_iterator (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Reverse", (void (XCAFDimTolObjects_DatumModifiersSequence::*)()) &XCAFDimTolObjects_DatumModifiersSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Exchange", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DatumModifiersSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DatumModifiersSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Clear", [](XCAFDimTolObjects_DatumModifiersSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Clear", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DatumModifiersSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Assign", (XCAFDimTolObjects_DatumModifiersSequence & (XCAFDimTolObjects_DatumModifiersSequence::*)(const XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("assign", (XCAFDimTolObjects_DatumModifiersSequence & (XCAFDimTolObjects_DatumModifiersSequence::*)(const XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(XCAFDimTolObjects_DatumModifiersSequence::Iterator &)) &XCAFDimTolObjects_DatumModifiersSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumModifiersSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Remove", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DatumModifiersSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Append", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Append", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(XCAFDimTolObjects_DatumModifiersSequence::Iterator &, const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Split", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumModifiersSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("First", (const XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::First, "First item access");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("ChangeFirst", (XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)()) &XCAFDimTolObjects_DatumModifiersSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Last", (const XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)() const ) &XCAFDimTolObjects_DatumModifiersSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("ChangeLast", (XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)()) &XCAFDimTolObjects_DatumModifiersSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("Value", (const XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DatumModifiersSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("__call__", (const XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DatumModifiersSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("ChangeValue", (XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumModifiersSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("__call__", (XCAFDimTolObjects_DatumSingleModif & (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumModifiersSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("SetValue", (void (XCAFDimTolObjects_DatumModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_DatumSingleModif &)) &XCAFDimTolObjects_DatumModifiersSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumModifiersSequence.def("__iter__", [](const XCAFDimTolObjects_DatumModifiersSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_GeomToleranceObjectSequence, std::unique_ptr<XCAFDimTolObjects_GeomToleranceObjectSequence, Deleter<XCAFDimTolObjects_GeomToleranceObjectSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_GeomToleranceObjectSequence(mod, "XCAFDimTolObjects_GeomToleranceObjectSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def(py::init<>());
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def(py::init([] (const XCAFDimTolObjects_GeomToleranceObjectSequence &other) {return new XCAFDimTolObjects_GeomToleranceObjectSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("begin", (XCAFDimTolObjects_GeomToleranceObjectSequence::iterator (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("end", (XCAFDimTolObjects_GeomToleranceObjectSequence::iterator (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("cbegin", (XCAFDimTolObjects_GeomToleranceObjectSequence::const_iterator (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("cend", (XCAFDimTolObjects_GeomToleranceObjectSequence::const_iterator (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Reverse", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)()) &XCAFDimTolObjects_GeomToleranceObjectSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Exchange", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Clear", [](XCAFDimTolObjects_GeomToleranceObjectSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Clear", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Assign", (XCAFDimTolObjects_GeomToleranceObjectSequence & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("assign", (XCAFDimTolObjects_GeomToleranceObjectSequence & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(XCAFDimTolObjects_GeomToleranceObjectSequence::Iterator &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Append", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Append", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Prepend", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Prepend", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(XCAFDimTolObjects_GeomToleranceObjectSequence::Iterator &, const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Split", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceObjectSequence &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("First", (const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::First, "First item access");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("ChangeFirst", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)()) &XCAFDimTolObjects_GeomToleranceObjectSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Last", (const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("ChangeLast", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)()) &XCAFDimTolObjects_GeomToleranceObjectSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("Value", (const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("__call__", (const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_GeomToleranceObjectSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("ChangeValue", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceObjectSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("__call__", (opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> & (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceObjectSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("SetValue", (void (XCAFDimTolObjects_GeomToleranceObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_GeomToleranceObjectSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceObjectSequence.def("__iter__", [](const XCAFDimTolObjects_GeomToleranceObjectSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_GeomToleranceModifiersSequence, std::unique_ptr<XCAFDimTolObjects_GeomToleranceModifiersSequence, Deleter<XCAFDimTolObjects_GeomToleranceModifiersSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_GeomToleranceModifiersSequence(mod, "XCAFDimTolObjects_GeomToleranceModifiersSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def(py::init<>());
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def(py::init([] (const XCAFDimTolObjects_GeomToleranceModifiersSequence &other) {return new XCAFDimTolObjects_GeomToleranceModifiersSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("begin", (XCAFDimTolObjects_GeomToleranceModifiersSequence::iterator (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("end", (XCAFDimTolObjects_GeomToleranceModifiersSequence::iterator (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("cbegin", (XCAFDimTolObjects_GeomToleranceModifiersSequence::const_iterator (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("cend", (XCAFDimTolObjects_GeomToleranceModifiersSequence::const_iterator (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Reverse", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)()) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Exchange", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Clear", [](XCAFDimTolObjects_GeomToleranceModifiersSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Clear", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Assign", (XCAFDimTolObjects_GeomToleranceModifiersSequence & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("assign", (XCAFDimTolObjects_GeomToleranceModifiersSequence & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(XCAFDimTolObjects_GeomToleranceModifiersSequence::Iterator &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Remove", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Append", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Append", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Prepend", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("InsertBefore", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(XCAFDimTolObjects_GeomToleranceModifiersSequence::Iterator &, const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("InsertAfter", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Split", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("First", (const XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::First, "First item access");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("ChangeFirst", (XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)()) &XCAFDimTolObjects_GeomToleranceModifiersSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Last", (const XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)() const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("ChangeLast", (XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)()) &XCAFDimTolObjects_GeomToleranceModifiersSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("Value", (const XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("__call__", (const XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_GeomToleranceModifiersSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("ChangeValue", (XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("__call__", (XCAFDimTolObjects_GeomToleranceModif & (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("SetValue", (void (XCAFDimTolObjects_GeomToleranceModifiersSequence::*)(const Standard_Integer, const XCAFDimTolObjects_GeomToleranceModif &)) &XCAFDimTolObjects_GeomToleranceModifiersSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_GeomToleranceModifiersSequence.def("__iter__", [](const XCAFDimTolObjects_GeomToleranceModifiersSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_DatumObjectSequence, std::unique_ptr<XCAFDimTolObjects_DatumObjectSequence, Deleter<XCAFDimTolObjects_DatumObjectSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_DatumObjectSequence(mod, "XCAFDimTolObjects_DatumObjectSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_DatumObjectSequence.def(py::init<>());
	cls_XCAFDimTolObjects_DatumObjectSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def(py::init([] (const XCAFDimTolObjects_DatumObjectSequence &other) {return new XCAFDimTolObjects_DatumObjectSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("begin", (XCAFDimTolObjects_DatumObjectSequence::iterator (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("end", (XCAFDimTolObjects_DatumObjectSequence::iterator (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("cbegin", (XCAFDimTolObjects_DatumObjectSequence::const_iterator (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("cend", (XCAFDimTolObjects_DatumObjectSequence::const_iterator (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Reverse", (void (XCAFDimTolObjects_DatumObjectSequence::*)()) &XCAFDimTolObjects_DatumObjectSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Exchange", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DatumObjectSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DatumObjectSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Clear", [](XCAFDimTolObjects_DatumObjectSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Clear", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DatumObjectSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Assign", (XCAFDimTolObjects_DatumObjectSequence & (XCAFDimTolObjects_DatumObjectSequence::*)(const XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("assign", (XCAFDimTolObjects_DatumObjectSequence & (XCAFDimTolObjects_DatumObjectSequence::*)(const XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Remove", (void (XCAFDimTolObjects_DatumObjectSequence::*)(XCAFDimTolObjects_DatumObjectSequence::Iterator &)) &XCAFDimTolObjects_DatumObjectSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Remove", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObjectSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Remove", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DatumObjectSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Append", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Append", (void (XCAFDimTolObjects_DatumObjectSequence::*)(XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Prepend", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Prepend", (void (XCAFDimTolObjects_DatumObjectSequence::*)(XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumObjectSequence::*)(XCAFDimTolObjects_DatumObjectSequence::Iterator &, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Split", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DatumObjectSequence &)) &XCAFDimTolObjects_DatumObjectSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("First", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::First, "First item access");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("ChangeFirst", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)()) &XCAFDimTolObjects_DatumObjectSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Last", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)() const ) &XCAFDimTolObjects_DatumObjectSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("ChangeLast", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)()) &XCAFDimTolObjects_DatumObjectSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_DatumObjectSequence.def("Value", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DatumObjectSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("__call__", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DatumObjectSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("ChangeValue", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObjectSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("__call__", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObjectSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("SetValue", (void (XCAFDimTolObjects_DatumObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DatumObjectSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DatumObjectSequence.def("__iter__", [](const XCAFDimTolObjects_DatumObjectSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XCAFDimTolObjects_DataMapOfToleranceDatum, std::unique_ptr<XCAFDimTolObjects_DataMapOfToleranceDatum, Deleter<XCAFDimTolObjects_DataMapOfToleranceDatum>>, NCollection_BaseMap> cls_XCAFDimTolObjects_DataMapOfToleranceDatum(mod, "XCAFDimTolObjects_DataMapOfToleranceDatum", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def(py::init<>());
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def(py::init([] (const XCAFDimTolObjects_DataMapOfToleranceDatum &other) {return new XCAFDimTolObjects_DataMapOfToleranceDatum(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("begin", (XCAFDimTolObjects_DataMapOfToleranceDatum::iterator (XCAFDimTolObjects_DataMapOfToleranceDatum::*)() const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("end", (XCAFDimTolObjects_DataMapOfToleranceDatum::iterator (XCAFDimTolObjects_DataMapOfToleranceDatum::*)() const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("cbegin", (XCAFDimTolObjects_DataMapOfToleranceDatum::const_iterator (XCAFDimTolObjects_DataMapOfToleranceDatum::*)() const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("cend", (XCAFDimTolObjects_DataMapOfToleranceDatum::const_iterator (XCAFDimTolObjects_DataMapOfToleranceDatum::*)() const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Exchange", (void (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(XCAFDimTolObjects_DataMapOfToleranceDatum &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Assign", (XCAFDimTolObjects_DataMapOfToleranceDatum & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const XCAFDimTolObjects_DataMapOfToleranceDatum &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("assign", (XCAFDimTolObjects_DataMapOfToleranceDatum & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const XCAFDimTolObjects_DataMapOfToleranceDatum &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("ReSize", (void (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const Standard_Integer)) &XCAFDimTolObjects_DataMapOfToleranceDatum::ReSize, "ReSize", py::arg("N"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Bind", (Standard_Boolean (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Bound", (opencascade::handle<XCAFDimTolObjects_DatumObject> * (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &, const opencascade::handle<XCAFDimTolObjects_DatumObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("IsBound", (Standard_Boolean (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &) const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::IsBound, "IsBound", py::arg("theKey"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("UnBind", (Standard_Boolean (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Seek", (const opencascade::handle<XCAFDimTolObjects_DatumObject> * (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &) const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Find", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &) const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Find", (Standard_Boolean (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &, opencascade::handle<XCAFDimTolObjects_DatumObject> &) const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("__call__", (const opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &) const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("ChangeSeek", (opencascade::handle<XCAFDimTolObjects_DatumObject> * (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("ChangeFind", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("__call__", (opencascade::handle<XCAFDimTolObjects_DatumObject> & (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Clear", [](XCAFDimTolObjects_DataMapOfToleranceDatum &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Clear", (void (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const Standard_Boolean)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Clear", (void (XCAFDimTolObjects_DataMapOfToleranceDatum::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DataMapOfToleranceDatum::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("Size", (Standard_Integer (XCAFDimTolObjects_DataMapOfToleranceDatum::*)() const ) &XCAFDimTolObjects_DataMapOfToleranceDatum::Size, "Size");
	cls_XCAFDimTolObjects_DataMapOfToleranceDatum.def("__iter__", [](const XCAFDimTolObjects_DataMapOfToleranceDatum &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XCAFDimTolObjects_DimensionObjectSequence, std::unique_ptr<XCAFDimTolObjects_DimensionObjectSequence, Deleter<XCAFDimTolObjects_DimensionObjectSequence>>, NCollection_BaseSequence> cls_XCAFDimTolObjects_DimensionObjectSequence(mod, "XCAFDimTolObjects_DimensionObjectSequence", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def(py::init<>());
	cls_XCAFDimTolObjects_DimensionObjectSequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def(py::init([] (const XCAFDimTolObjects_DimensionObjectSequence &other) {return new XCAFDimTolObjects_DimensionObjectSequence(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("begin", (XCAFDimTolObjects_DimensionObjectSequence::iterator (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("end", (XCAFDimTolObjects_DimensionObjectSequence::iterator (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("cbegin", (XCAFDimTolObjects_DimensionObjectSequence::const_iterator (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("cend", (XCAFDimTolObjects_DimensionObjectSequence::const_iterator (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Size", (Standard_Integer (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::Size, "Number of items");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Length", (Standard_Integer (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::Length, "Number of items");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Lower", (Standard_Integer (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::Lower, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Upper", (Standard_Integer (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::Upper, "Method for consistency with other collections.");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("IsEmpty", (Standard_Boolean (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::IsEmpty, "Empty query");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Reverse", (void (XCAFDimTolObjects_DimensionObjectSequence::*)()) &XCAFDimTolObjects_DimensionObjectSequence::Reverse, "Reverse sequence");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Exchange", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionObjectSequence::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DimensionObjectSequence::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Clear", [](XCAFDimTolObjects_DimensionObjectSequence &self) -> void { return self.Clear(); });
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Clear", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFDimTolObjects_DimensionObjectSequence::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Assign", (XCAFDimTolObjects_DimensionObjectSequence & (XCAFDimTolObjects_DimensionObjectSequence::*)(const XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("assign", (XCAFDimTolObjects_DimensionObjectSequence & (XCAFDimTolObjects_DimensionObjectSequence::*)(const XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Remove", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(XCAFDimTolObjects_DimensionObjectSequence::Iterator &)) &XCAFDimTolObjects_DimensionObjectSequence::Remove, "Remove one item", py::arg("thePosition"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Remove", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObjectSequence::Remove, "Remove one item", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Remove", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, const Standard_Integer)) &XCAFDimTolObjects_DimensionObjectSequence::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Append", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::Append, "Append one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Append", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Prepend", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Prepend", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("InsertBefore", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(XCAFDimTolObjects_DimensionObjectSequence::Iterator &, const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("InsertAfter", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Split", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, XCAFDimTolObjects_DimensionObjectSequence &)) &XCAFDimTolObjects_DimensionObjectSequence::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("First", (const opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::First, "First item access");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("ChangeFirst", (opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)()) &XCAFDimTolObjects_DimensionObjectSequence::ChangeFirst, "First item access");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Last", (const opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)() const ) &XCAFDimTolObjects_DimensionObjectSequence::Last, "Last item access");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("ChangeLast", (opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)()) &XCAFDimTolObjects_DimensionObjectSequence::ChangeLast, "Last item access");
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("Value", (const opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionObjectSequence::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("__call__", (const opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer) const ) &XCAFDimTolObjects_DimensionObjectSequence::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("ChangeValue", (opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObjectSequence::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("__call__", (opencascade::handle<XCAFDimTolObjects_DimensionObject> & (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer)) &XCAFDimTolObjects_DimensionObjectSequence::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("SetValue", (void (XCAFDimTolObjects_DimensionObjectSequence::*)(const Standard_Integer, const opencascade::handle<XCAFDimTolObjects_DimensionObject> &)) &XCAFDimTolObjects_DimensionObjectSequence::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XCAFDimTolObjects_DimensionObjectSequence.def("__iter__", [](const XCAFDimTolObjects_DimensionObjectSequence &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
