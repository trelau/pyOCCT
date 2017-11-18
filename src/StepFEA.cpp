#include <pyOCCT_Common.hpp>

#include <StepFEA_FeaRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <Standard_Type.hxx>
#include <StepFEA_AlignedCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_AlignedSurface3dElementCoordinateSystem.hxx>
#include <StepFEA_ArbitraryVolume3dElementCoordinateSystem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepFEA_ConstantSurface3dElementCoordinateSystem.hxx>
#include <Standard_Transient.hxx>
#include <StepFEA_HArray1OfCurveElementInterval.hxx>
#include <StepFEA_HArray1OfCurveElementEndOffset.hxx>
#include <StepFEA_HArray1OfCurveElementEndRelease.hxx>
#include <StepFEA_Curve3dElementProperty.hxx>
#include <StepFEA_ElementRepresentation.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepFEA_HArray1OfNodeRepresentation.hxx>
#include <StepFEA_FeaModel3d.hxx>
#include <StepElement_Curve3dElementDescriptor.hxx>
#include <StepElement_ElementMaterial.hxx>
#include <StepFEA_Curve3dElementRepresentation.hxx>
#include <StepFEA_CurveElementEndCoordinateSystem.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepFEA_CurveElementEndOffset.hxx>
#include <StepElement_HArray1OfCurveElementEndReleasePacket.hxx>
#include <StepFEA_CurveElementEndRelease.hxx>
#include <StepFEA_CurveElementLocation.hxx>
#include <StepBasic_EulerAngles.hxx>
#include <StepFEA_CurveElementInterval.hxx>
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <StepFEA_CurveElementIntervalConstant.hxx>
#include <StepElement_HArray1OfCurveElementSectionDefinition.hxx>
#include <StepFEA_CurveElementIntervalLinearlyVarying.hxx>
#include <StepFEA_FeaParametricPoint.hxx>
#include <StepFEA_NodeRepresentation.hxx>
#include <StepFEA_DummyNode.hxx>
#include <StepFEA_ElementOrElementGroup.hxx>
#include <StepElement_AnalysisItemWithinRepresentation.hxx>
#include <StepElement_ElementAspect.hxx>
#include <StepFEA_ElementGeometricRelationship.hxx>
#include <StepFEA_FeaGroup.hxx>
#include <StepFEA_FeaModel.hxx>
#include <StepFEA_HArray1OfElementRepresentation.hxx>
#include <StepFEA_ElementGroup.hxx>
#include <StepRepr_Representation.hxx>
#include <StepFEA_FeaMaterialPropertyRepresentationItem.hxx>
#include <StepFEA_FeaAreaDensity.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_Direction.hxx>
#include <StepFEA_CoordinateSystemType.hxx>
#include <StepFEA_FeaCurveSectionGeometricRelationship.hxx>
#include <StepBasic_Group.hxx>
#include <StepFEA_SymmetricTensor43d.hxx>
#include <StepFEA_FeaLinearElasticity.hxx>
#include <StepFEA_FeaMassDensity.hxx>
#include <StepRepr_MaterialPropertyRepresentation.hxx>
#include <StepFEA_FeaMaterialPropertyRepresentation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepFEA_FeaModelDefinition.hxx>
#include <StepFEA_SymmetricTensor23d.hxx>
#include <StepFEA_FeaMoistureAbsorption.hxx>
#include <StepGeom_Point.hxx>
#include <StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.hxx>
#include <StepFEA_SymmetricTensor42d.hxx>
#include <StepFEA_FeaShellBendingStiffness.hxx>
#include <StepFEA_FeaShellMembraneBendingCouplingStiffness.hxx>
#include <StepFEA_FeaShellMembraneStiffness.hxx>
#include <StepFEA_SymmetricTensor22d.hxx>
#include <StepFEA_FeaShellShearStiffness.hxx>
#include <StepElement_SurfaceSection.hxx>
#include <StepFEA_FeaSurfaceSectionGeometricRelationship.hxx>
#include <StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.hxx>
#include <StepFEA_DegreeOfFreedom.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <StepFEA_FreedomAndCoefficient.hxx>
#include <StepFEA_HArray1OfDegreeOfFreedom.hxx>
#include <StepFEA_FreedomsList.hxx>
#include <StepFEA_GeometricNode.hxx>
#include <StepFEA_Node.hxx>
#include <StepFEA_NodeDefinition.hxx>
#include <StepFEA_NodeGroup.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepFEA_NodeSet.hxx>
#include <StepFEA_NodeWithSolutionCoordinateSystem.hxx>
#include <StepFEA_NodeWithVector.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateDirection.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_ParametricSurface3dElementCoordinateSystem.hxx>
#include <StepElement_Surface3dElementDescriptor.hxx>
#include <StepElement_SurfaceElementProperty.hxx>
#include <StepFEA_Surface3dElementRepresentation.hxx>
#include <StepElement_Volume3dElementDescriptor.hxx>
#include <StepFEA_Volume3dElementRepresentation.hxx>
#include <StepData_SelectType.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StepFEA_SequenceOfElementGeometricRelationship.hxx>
#include <StepFEA_HSequenceOfElementGeometricRelationship.hxx>
#include <NCollection_Array1.hxx>
#include <StepFEA_Array1OfNodeRepresentation.hxx>
#include <StepFEA_SequenceOfElementRepresentation.hxx>
#include <StepFEA_HSequenceOfElementRepresentation.hxx>
#include <StepFEA_Array1OfCurveElementEndOffset.hxx>
#include <StepFEA_Array1OfCurveElementEndRelease.hxx>
#include <StepFEA_Array1OfCurveElementInterval.hxx>
#include <StepFEA_EnumeratedDegreeOfFreedom.hxx>
#include <StepData_SelectMember.hxx>
#include <StepFEA_Array1OfDegreeOfFreedom.hxx>
#include <StepFEA_Array1OfElementRepresentation.hxx>
#include <StepFEA_CurveEdge.hxx>
#include <StepData_SelectNamed.hxx>
#include <StepFEA_DegreeOfFreedomMember.hxx>
#include <StepFEA_ElementVolume.hxx>
#include <StepFEA_SequenceOfCurve3dElementProperty.hxx>
#include <StepFEA_HSequenceOfCurve3dElementProperty.hxx>
#include <StepFEA_SequenceOfNodeRepresentation.hxx>
#include <StepFEA_HSequenceOfNodeRepresentation.hxx>
#include <StepData_SelectArrReal.hxx>
#include <StepFEA_SymmetricTensor23dMember.hxx>
#include <StepFEA_SymmetricTensor43dMember.hxx>
#include <StepFEA_UnspecifiedValue.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(StepFEA, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.StepElement");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.StepGeom");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_EnumeratedDegreeOfFreedom.hxx
	py::enum_<StepFEA_EnumeratedDegreeOfFreedom>(mod, "StepFEA_EnumeratedDegreeOfFreedom", "None")
		.value("StepFEA_XTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_XTranslation)
		.value("StepFEA_YTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_YTranslation)
		.value("StepFEA_ZTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_ZTranslation)
		.value("StepFEA_XRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_XRotation)
		.value("StepFEA_YRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_YRotation)
		.value("StepFEA_ZRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_ZRotation)
		.value("StepFEA_Warp", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_Warp)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CoordinateSystemType.hxx
	py::enum_<StepFEA_CoordinateSystemType>(mod, "StepFEA_CoordinateSystemType", "None")
		.value("StepFEA_Cartesian", StepFEA_CoordinateSystemType::StepFEA_Cartesian)
		.value("StepFEA_Cylindrical", StepFEA_CoordinateSystemType::StepFEA_Cylindrical)
		.value("StepFEA_Spherical", StepFEA_CoordinateSystemType::StepFEA_Spherical)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveEdge.hxx
	py::enum_<StepFEA_CurveEdge>(mod, "StepFEA_CurveEdge", "None")
		.value("StepFEA_ElementEdge", StepFEA_CurveEdge::StepFEA_ElementEdge)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ElementVolume.hxx
	py::enum_<StepFEA_ElementVolume>(mod, "StepFEA_ElementVolume", "None")
		.value("StepFEA_Volume", StepFEA_ElementVolume::StepFEA_Volume)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_UnspecifiedValue.hxx
	py::enum_<StepFEA_UnspecifiedValue>(mod, "StepFEA_UnspecifiedValue", "None")
		.value("StepFEA_Unspecified", StepFEA_UnspecifiedValue::StepFEA_Unspecified)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaRepresentationItem.hxx
	py::class_<StepFEA_FeaRepresentationItem, opencascade::handle<StepFEA_FeaRepresentationItem>, StepRepr_RepresentationItem> cls_StepFEA_FeaRepresentationItem(mod, "StepFEA_FeaRepresentationItem", "Representation of STEP entity FeaRepresentationItem");
	cls_StepFEA_FeaRepresentationItem.def(py::init<>());
	cls_StepFEA_FeaRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaRepresentationItem::get_type_name, "None");
	cls_StepFEA_FeaRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaRepresentationItem::get_type_descriptor, "None");
	cls_StepFEA_FeaRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaRepresentationItem::*)() const ) &StepFEA_FeaRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_AlignedSurface3dElementCoordinateSystem.hxx
	py::class_<StepFEA_AlignedSurface3dElementCoordinateSystem, opencascade::handle<StepFEA_AlignedSurface3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_AlignedSurface3dElementCoordinateSystem(mod, "StepFEA_AlignedSurface3dElementCoordinateSystem", "Representation of STEP entity AlignedSurface3dElementCoordinateSystem");
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("Init", (void (StepFEA_AlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedSurface3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinateSystem"));
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("CoordinateSystem", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_AlignedSurface3dElementCoordinateSystem::*)() const ) &StepFEA_AlignedSurface3dElementCoordinateSystem::CoordinateSystem, "Returns field CoordinateSystem");
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("SetCoordinateSystem", (void (StepFEA_AlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedSurface3dElementCoordinateSystem::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_AlignedSurface3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_AlignedSurface3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_AlignedSurface3dElementCoordinateSystem::*)() const ) &StepFEA_AlignedSurface3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ArbitraryVolume3dElementCoordinateSystem.hxx
	py::class_<StepFEA_ArbitraryVolume3dElementCoordinateSystem, opencascade::handle<StepFEA_ArbitraryVolume3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem(mod, "StepFEA_ArbitraryVolume3dElementCoordinateSystem", "Representation of STEP entity ArbitraryVolume3dElementCoordinateSystem");
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def("Init", (void (StepFEA_ArbitraryVolume3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinateSystem"));
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def("CoordinateSystem", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_ArbitraryVolume3dElementCoordinateSystem::*)() const ) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::CoordinateSystem, "Returns field CoordinateSystem");
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def("SetCoordinateSystem", (void (StepFEA_ArbitraryVolume3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_ArbitraryVolume3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ArbitraryVolume3dElementCoordinateSystem::*)() const ) &StepFEA_ArbitraryVolume3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ConstantSurface3dElementCoordinateSystem.hxx
	py::class_<StepFEA_ConstantSurface3dElementCoordinateSystem, opencascade::handle<StepFEA_ConstantSurface3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_ConstantSurface3dElementCoordinateSystem(mod, "StepFEA_ConstantSurface3dElementCoordinateSystem", "Representation of STEP entity ConstantSurface3dElementCoordinateSystem");
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("Init", (void (StepFEA_ConstantSurface3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Real)) &StepFEA_ConstantSurface3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aAxis"), py::arg("aAngle"));
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("Axis", (Standard_Integer (StepFEA_ConstantSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ConstantSurface3dElementCoordinateSystem::Axis, "Returns field Axis");
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("SetAxis", (void (StepFEA_ConstantSurface3dElementCoordinateSystem::*)(const Standard_Integer)) &StepFEA_ConstantSurface3dElementCoordinateSystem::SetAxis, "Set field Axis", py::arg("Axis"));
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("Angle", (Standard_Real (StepFEA_ConstantSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ConstantSurface3dElementCoordinateSystem::Angle, "Returns field Angle");
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("SetAngle", (void (StepFEA_ConstantSurface3dElementCoordinateSystem::*)(const Standard_Real)) &StepFEA_ConstantSurface3dElementCoordinateSystem::SetAngle, "Set field Angle", py::arg("Angle"));
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_ConstantSurface3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ConstantSurface3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_ConstantSurface3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ConstantSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ConstantSurface3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Curve3dElementProperty.hxx
	py::class_<StepFEA_Curve3dElementProperty, opencascade::handle<StepFEA_Curve3dElementProperty>, Standard_Transient> cls_StepFEA_Curve3dElementProperty(mod, "StepFEA_Curve3dElementProperty", "Representation of STEP entity Curve3dElementProperty");
	cls_StepFEA_Curve3dElementProperty.def(py::init<>());
	cls_StepFEA_Curve3dElementProperty.def("Init", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_HArray1OfCurveElementInterval> &, const opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> &, const opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> &)) &StepFEA_Curve3dElementProperty::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyId"), py::arg("aDescription"), py::arg("aIntervalDefinitions"), py::arg("aEndOffsets"), py::arg("aEndReleases"));
	cls_StepFEA_Curve3dElementProperty.def("PropertyId", (opencascade::handle<TCollection_HAsciiString> (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::PropertyId, "Returns field PropertyId");
	cls_StepFEA_Curve3dElementProperty.def("SetPropertyId", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_Curve3dElementProperty::SetPropertyId, "Set field PropertyId", py::arg("PropertyId"));
	cls_StepFEA_Curve3dElementProperty.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::Description, "Returns field Description");
	cls_StepFEA_Curve3dElementProperty.def("SetDescription", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_Curve3dElementProperty::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepFEA_Curve3dElementProperty.def("IntervalDefinitions", (opencascade::handle<StepFEA_HArray1OfCurveElementInterval> (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::IntervalDefinitions, "Returns field IntervalDefinitions");
	cls_StepFEA_Curve3dElementProperty.def("SetIntervalDefinitions", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementInterval> &)) &StepFEA_Curve3dElementProperty::SetIntervalDefinitions, "Set field IntervalDefinitions", py::arg("IntervalDefinitions"));
	cls_StepFEA_Curve3dElementProperty.def("EndOffsets", (opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::EndOffsets, "Returns field EndOffsets");
	cls_StepFEA_Curve3dElementProperty.def("SetEndOffsets", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset> &)) &StepFEA_Curve3dElementProperty::SetEndOffsets, "Set field EndOffsets", py::arg("EndOffsets"));
	cls_StepFEA_Curve3dElementProperty.def("EndReleases", (opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::EndReleases, "Returns field EndReleases");
	cls_StepFEA_Curve3dElementProperty.def("SetEndReleases", (void (StepFEA_Curve3dElementProperty::*)(const opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease> &)) &StepFEA_Curve3dElementProperty::SetEndReleases, "Set field EndReleases", py::arg("EndReleases"));
	cls_StepFEA_Curve3dElementProperty.def_static("get_type_name_", (const char * (*)()) &StepFEA_Curve3dElementProperty::get_type_name, "None");
	cls_StepFEA_Curve3dElementProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Curve3dElementProperty::get_type_descriptor, "None");
	cls_StepFEA_Curve3dElementProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Curve3dElementProperty::*)() const ) &StepFEA_Curve3dElementProperty::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ElementRepresentation.hxx
	py::class_<StepFEA_ElementRepresentation, opencascade::handle<StepFEA_ElementRepresentation>, StepRepr_Representation> cls_StepFEA_ElementRepresentation(mod, "StepFEA_ElementRepresentation", "Representation of STEP entity ElementRepresentation");
	cls_StepFEA_ElementRepresentation.def(py::init<>());
	cls_StepFEA_ElementRepresentation.def("Init", (void (StepFEA_ElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_ElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aNodeList"));
	cls_StepFEA_ElementRepresentation.def("NodeList", (opencascade::handle<StepFEA_HArray1OfNodeRepresentation> (StepFEA_ElementRepresentation::*)() const ) &StepFEA_ElementRepresentation::NodeList, "Returns field NodeList");
	cls_StepFEA_ElementRepresentation.def("SetNodeList", (void (StepFEA_ElementRepresentation::*)(const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_ElementRepresentation::SetNodeList, "Set field NodeList", py::arg("NodeList"));
	cls_StepFEA_ElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementRepresentation::get_type_name, "None");
	cls_StepFEA_ElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_ElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementRepresentation::*)() const ) &StepFEA_ElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementEndOffset.hxx
	py::class_<StepFEA_CurveElementEndOffset, opencascade::handle<StepFEA_CurveElementEndOffset>, Standard_Transient> cls_StepFEA_CurveElementEndOffset(mod, "StepFEA_CurveElementEndOffset", "Representation of STEP entity CurveElementEndOffset");
	cls_StepFEA_CurveElementEndOffset.def(py::init<>());
	cls_StepFEA_CurveElementEndOffset.def("Init", (void (StepFEA_CurveElementEndOffset::*)(const StepFEA_CurveElementEndCoordinateSystem &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_CurveElementEndOffset::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinateSystem"), py::arg("aOffsetVector"));
	cls_StepFEA_CurveElementEndOffset.def("CoordinateSystem", (StepFEA_CurveElementEndCoordinateSystem (StepFEA_CurveElementEndOffset::*)() const ) &StepFEA_CurveElementEndOffset::CoordinateSystem, "Returns field CoordinateSystem");
	cls_StepFEA_CurveElementEndOffset.def("SetCoordinateSystem", (void (StepFEA_CurveElementEndOffset::*)(const StepFEA_CurveElementEndCoordinateSystem &)) &StepFEA_CurveElementEndOffset::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
	cls_StepFEA_CurveElementEndOffset.def("OffsetVector", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_CurveElementEndOffset::*)() const ) &StepFEA_CurveElementEndOffset::OffsetVector, "Returns field OffsetVector");
	cls_StepFEA_CurveElementEndOffset.def("SetOffsetVector", (void (StepFEA_CurveElementEndOffset::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_CurveElementEndOffset::SetOffsetVector, "Set field OffsetVector", py::arg("OffsetVector"));
	cls_StepFEA_CurveElementEndOffset.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementEndOffset::get_type_name, "None");
	cls_StepFEA_CurveElementEndOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementEndOffset::get_type_descriptor, "None");
	cls_StepFEA_CurveElementEndOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementEndOffset::*)() const ) &StepFEA_CurveElementEndOffset::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementEndRelease.hxx
	py::class_<StepFEA_CurveElementEndRelease, opencascade::handle<StepFEA_CurveElementEndRelease>, Standard_Transient> cls_StepFEA_CurveElementEndRelease(mod, "StepFEA_CurveElementEndRelease", "Representation of STEP entity CurveElementEndRelease");
	cls_StepFEA_CurveElementEndRelease.def(py::init<>());
	cls_StepFEA_CurveElementEndRelease.def("Init", (void (StepFEA_CurveElementEndRelease::*)(const StepFEA_CurveElementEndCoordinateSystem &, const opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> &)) &StepFEA_CurveElementEndRelease::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinateSystem"), py::arg("aReleases"));
	cls_StepFEA_CurveElementEndRelease.def("CoordinateSystem", (StepFEA_CurveElementEndCoordinateSystem (StepFEA_CurveElementEndRelease::*)() const ) &StepFEA_CurveElementEndRelease::CoordinateSystem, "Returns field CoordinateSystem");
	cls_StepFEA_CurveElementEndRelease.def("SetCoordinateSystem", (void (StepFEA_CurveElementEndRelease::*)(const StepFEA_CurveElementEndCoordinateSystem &)) &StepFEA_CurveElementEndRelease::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
	cls_StepFEA_CurveElementEndRelease.def("Releases", (opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> (StepFEA_CurveElementEndRelease::*)() const ) &StepFEA_CurveElementEndRelease::Releases, "Returns field Releases");
	cls_StepFEA_CurveElementEndRelease.def("SetReleases", (void (StepFEA_CurveElementEndRelease::*)(const opencascade::handle<StepElement_HArray1OfCurveElementEndReleasePacket> &)) &StepFEA_CurveElementEndRelease::SetReleases, "Set field Releases", py::arg("Releases"));
	cls_StepFEA_CurveElementEndRelease.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementEndRelease::get_type_name, "None");
	cls_StepFEA_CurveElementEndRelease.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementEndRelease::get_type_descriptor, "None");
	cls_StepFEA_CurveElementEndRelease.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementEndRelease::*)() const ) &StepFEA_CurveElementEndRelease::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementInterval.hxx
	py::class_<StepFEA_CurveElementInterval, opencascade::handle<StepFEA_CurveElementInterval>, Standard_Transient> cls_StepFEA_CurveElementInterval(mod, "StepFEA_CurveElementInterval", "Representation of STEP entity CurveElementInterval");
	cls_StepFEA_CurveElementInterval.def(py::init<>());
	cls_StepFEA_CurveElementInterval.def("Init", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &)) &StepFEA_CurveElementInterval::Init, "Initialize all fields (own and inherited)", py::arg("aFinishPosition"), py::arg("aEuAngles"));
	cls_StepFEA_CurveElementInterval.def("FinishPosition", (opencascade::handle<StepFEA_CurveElementLocation> (StepFEA_CurveElementInterval::*)() const ) &StepFEA_CurveElementInterval::FinishPosition, "Returns field FinishPosition");
	cls_StepFEA_CurveElementInterval.def("SetFinishPosition", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepFEA_CurveElementLocation> &)) &StepFEA_CurveElementInterval::SetFinishPosition, "Set field FinishPosition", py::arg("FinishPosition"));
	cls_StepFEA_CurveElementInterval.def("EuAngles", (opencascade::handle<StepBasic_EulerAngles> (StepFEA_CurveElementInterval::*)() const ) &StepFEA_CurveElementInterval::EuAngles, "Returns field EuAngles");
	cls_StepFEA_CurveElementInterval.def("SetEuAngles", (void (StepFEA_CurveElementInterval::*)(const opencascade::handle<StepBasic_EulerAngles> &)) &StepFEA_CurveElementInterval::SetEuAngles, "Set field EuAngles", py::arg("EuAngles"));
	cls_StepFEA_CurveElementInterval.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementInterval::get_type_name, "None");
	cls_StepFEA_CurveElementInterval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementInterval::get_type_descriptor, "None");
	cls_StepFEA_CurveElementInterval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementInterval::*)() const ) &StepFEA_CurveElementInterval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementIntervalConstant.hxx
	py::class_<StepFEA_CurveElementIntervalConstant, opencascade::handle<StepFEA_CurveElementIntervalConstant>, StepFEA_CurveElementInterval> cls_StepFEA_CurveElementIntervalConstant(mod, "StepFEA_CurveElementIntervalConstant", "Representation of STEP entity CurveElementIntervalConstant");
	cls_StepFEA_CurveElementIntervalConstant.def(py::init<>());
	cls_StepFEA_CurveElementIntervalConstant.def("Init", (void (StepFEA_CurveElementIntervalConstant::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &, const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalConstant::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementInterval_FinishPosition"), py::arg("aCurveElementInterval_EuAngles"), py::arg("aSection"));
	cls_StepFEA_CurveElementIntervalConstant.def("Section", (opencascade::handle<StepElement_CurveElementSectionDefinition> (StepFEA_CurveElementIntervalConstant::*)() const ) &StepFEA_CurveElementIntervalConstant::Section, "Returns field Section");
	cls_StepFEA_CurveElementIntervalConstant.def("SetSection", (void (StepFEA_CurveElementIntervalConstant::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalConstant::SetSection, "Set field Section", py::arg("Section"));
	cls_StepFEA_CurveElementIntervalConstant.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementIntervalConstant::get_type_name, "None");
	cls_StepFEA_CurveElementIntervalConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementIntervalConstant::get_type_descriptor, "None");
	cls_StepFEA_CurveElementIntervalConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementIntervalConstant::*)() const ) &StepFEA_CurveElementIntervalConstant::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementIntervalLinearlyVarying.hxx
	py::class_<StepFEA_CurveElementIntervalLinearlyVarying, opencascade::handle<StepFEA_CurveElementIntervalLinearlyVarying>, StepFEA_CurveElementInterval> cls_StepFEA_CurveElementIntervalLinearlyVarying(mod, "StepFEA_CurveElementIntervalLinearlyVarying", "Representation of STEP entity CurveElementIntervalLinearlyVarying");
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def(py::init<>());
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def("Init", (void (StepFEA_CurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, const opencascade::handle<StepBasic_EulerAngles> &, const opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalLinearlyVarying::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementInterval_FinishPosition"), py::arg("aCurveElementInterval_EuAngles"), py::arg("aSections"));
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def("Sections", (opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> (StepFEA_CurveElementIntervalLinearlyVarying::*)() const ) &StepFEA_CurveElementIntervalLinearlyVarying::Sections, "Returns field Sections");
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def("SetSections", (void (StepFEA_CurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepElement_HArray1OfCurveElementSectionDefinition> &)) &StepFEA_CurveElementIntervalLinearlyVarying::SetSections, "Set field Sections", py::arg("Sections"));
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementIntervalLinearlyVarying::get_type_name, "None");
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementIntervalLinearlyVarying::get_type_descriptor, "None");
	cls_StepFEA_CurveElementIntervalLinearlyVarying.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementIntervalLinearlyVarying::*)() const ) &StepFEA_CurveElementIntervalLinearlyVarying::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementLocation.hxx
	py::class_<StepFEA_CurveElementLocation, opencascade::handle<StepFEA_CurveElementLocation>, Standard_Transient> cls_StepFEA_CurveElementLocation(mod, "StepFEA_CurveElementLocation", "Representation of STEP entity CurveElementLocation");
	cls_StepFEA_CurveElementLocation.def(py::init<>());
	cls_StepFEA_CurveElementLocation.def("Init", (void (StepFEA_CurveElementLocation::*)(const opencascade::handle<StepFEA_FeaParametricPoint> &)) &StepFEA_CurveElementLocation::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinate"));
	cls_StepFEA_CurveElementLocation.def("Coordinate", (opencascade::handle<StepFEA_FeaParametricPoint> (StepFEA_CurveElementLocation::*)() const ) &StepFEA_CurveElementLocation::Coordinate, "Returns field Coordinate");
	cls_StepFEA_CurveElementLocation.def("SetCoordinate", (void (StepFEA_CurveElementLocation::*)(const opencascade::handle<StepFEA_FeaParametricPoint> &)) &StepFEA_CurveElementLocation::SetCoordinate, "Set field Coordinate", py::arg("Coordinate"));
	cls_StepFEA_CurveElementLocation.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementLocation::get_type_name, "None");
	cls_StepFEA_CurveElementLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementLocation::get_type_descriptor, "None");
	cls_StepFEA_CurveElementLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementLocation::*)() const ) &StepFEA_CurveElementLocation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeRepresentation.hxx
	py::class_<StepFEA_NodeRepresentation, opencascade::handle<StepFEA_NodeRepresentation>, StepRepr_Representation> cls_StepFEA_NodeRepresentation(mod, "StepFEA_NodeRepresentation", "Representation of STEP entity NodeRepresentation");
	cls_StepFEA_NodeRepresentation.def(py::init<>());
	cls_StepFEA_NodeRepresentation.def("Init", (void (StepFEA_NodeRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_NodeRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aModelRef"));
	cls_StepFEA_NodeRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel> (StepFEA_NodeRepresentation::*)() const ) &StepFEA_NodeRepresentation::ModelRef, "Returns field ModelRef");
	cls_StepFEA_NodeRepresentation.def("SetModelRef", (void (StepFEA_NodeRepresentation::*)(const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_NodeRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
	cls_StepFEA_NodeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeRepresentation::get_type_name, "None");
	cls_StepFEA_NodeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeRepresentation::get_type_descriptor, "None");
	cls_StepFEA_NodeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeRepresentation::*)() const ) &StepFEA_NodeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ElementGeometricRelationship.hxx
	py::class_<StepFEA_ElementGeometricRelationship, opencascade::handle<StepFEA_ElementGeometricRelationship>, Standard_Transient> cls_StepFEA_ElementGeometricRelationship(mod, "StepFEA_ElementGeometricRelationship", "Representation of STEP entity ElementGeometricRelationship");
	cls_StepFEA_ElementGeometricRelationship.def(py::init<>());
	cls_StepFEA_ElementGeometricRelationship.def("Init", (void (StepFEA_ElementGeometricRelationship::*)(const StepFEA_ElementOrElementGroup &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &, const StepElement_ElementAspect &)) &StepFEA_ElementGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aElementRef"), py::arg("aItem"), py::arg("aAspect"));
	cls_StepFEA_ElementGeometricRelationship.def("ElementRef", (StepFEA_ElementOrElementGroup (StepFEA_ElementGeometricRelationship::*)() const ) &StepFEA_ElementGeometricRelationship::ElementRef, "Returns field ElementRef");
	cls_StepFEA_ElementGeometricRelationship.def("SetElementRef", (void (StepFEA_ElementGeometricRelationship::*)(const StepFEA_ElementOrElementGroup &)) &StepFEA_ElementGeometricRelationship::SetElementRef, "Set field ElementRef", py::arg("ElementRef"));
	cls_StepFEA_ElementGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_ElementGeometricRelationship::*)() const ) &StepFEA_ElementGeometricRelationship::Item, "Returns field Item");
	cls_StepFEA_ElementGeometricRelationship.def("SetItem", (void (StepFEA_ElementGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_ElementGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
	cls_StepFEA_ElementGeometricRelationship.def("Aspect", (StepElement_ElementAspect (StepFEA_ElementGeometricRelationship::*)() const ) &StepFEA_ElementGeometricRelationship::Aspect, "Returns field Aspect");
	cls_StepFEA_ElementGeometricRelationship.def("SetAspect", (void (StepFEA_ElementGeometricRelationship::*)(const StepElement_ElementAspect &)) &StepFEA_ElementGeometricRelationship::SetAspect, "Set field Aspect", py::arg("Aspect"));
	cls_StepFEA_ElementGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementGeometricRelationship::get_type_name, "None");
	cls_StepFEA_ElementGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementGeometricRelationship::get_type_descriptor, "None");
	cls_StepFEA_ElementGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementGeometricRelationship::*)() const ) &StepFEA_ElementGeometricRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaGroup.hxx
	py::class_<StepFEA_FeaGroup, opencascade::handle<StepFEA_FeaGroup>, StepBasic_Group> cls_StepFEA_FeaGroup(mod, "StepFEA_FeaGroup", "Representation of STEP entity FeaGroup");
	cls_StepFEA_FeaGroup.def(py::init<>());
	cls_StepFEA_FeaGroup.def("Init", (void (StepFEA_FeaGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_FeaGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aModelRef"));
	cls_StepFEA_FeaGroup.def("ModelRef", (opencascade::handle<StepFEA_FeaModel> (StepFEA_FeaGroup::*)() const ) &StepFEA_FeaGroup::ModelRef, "Returns field ModelRef");
	cls_StepFEA_FeaGroup.def("SetModelRef", (void (StepFEA_FeaGroup::*)(const opencascade::handle<StepFEA_FeaModel> &)) &StepFEA_FeaGroup::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
	cls_StepFEA_FeaGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaGroup::get_type_name, "None");
	cls_StepFEA_FeaGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaGroup::get_type_descriptor, "None");
	cls_StepFEA_FeaGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaGroup::*)() const ) &StepFEA_FeaGroup::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Curve3dElementRepresentation.hxx
	py::class_<StepFEA_Curve3dElementRepresentation, opencascade::handle<StepFEA_Curve3dElementRepresentation>, StepFEA_ElementRepresentation> cls_StepFEA_Curve3dElementRepresentation(mod, "StepFEA_Curve3dElementRepresentation", "Representation of STEP entity Curve3dElementRepresentation");
	cls_StepFEA_Curve3dElementRepresentation.def(py::init<>());
	cls_StepFEA_Curve3dElementRepresentation.def("Init", (void (StepFEA_Curve3dElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &, const opencascade::handle<StepFEA_FeaModel3d> &, const opencascade::handle<StepElement_Curve3dElementDescriptor> &, const opencascade::handle<StepFEA_Curve3dElementProperty> &, const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Curve3dElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aElementRepresentation_NodeList"), py::arg("aModelRef"), py::arg("aElementDescriptor"), py::arg("aProperty"), py::arg("aMaterial"));
	cls_StepFEA_Curve3dElementRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel3d> (StepFEA_Curve3dElementRepresentation::*)() const ) &StepFEA_Curve3dElementRepresentation::ModelRef, "Returns field ModelRef");
	cls_StepFEA_Curve3dElementRepresentation.def("SetModelRef", (void (StepFEA_Curve3dElementRepresentation::*)(const opencascade::handle<StepFEA_FeaModel3d> &)) &StepFEA_Curve3dElementRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
	cls_StepFEA_Curve3dElementRepresentation.def("ElementDescriptor", (opencascade::handle<StepElement_Curve3dElementDescriptor> (StepFEA_Curve3dElementRepresentation::*)() const ) &StepFEA_Curve3dElementRepresentation::ElementDescriptor, "Returns field ElementDescriptor");
	cls_StepFEA_Curve3dElementRepresentation.def("SetElementDescriptor", (void (StepFEA_Curve3dElementRepresentation::*)(const opencascade::handle<StepElement_Curve3dElementDescriptor> &)) &StepFEA_Curve3dElementRepresentation::SetElementDescriptor, "Set field ElementDescriptor", py::arg("ElementDescriptor"));
	cls_StepFEA_Curve3dElementRepresentation.def("Property", (opencascade::handle<StepFEA_Curve3dElementProperty> (StepFEA_Curve3dElementRepresentation::*)() const ) &StepFEA_Curve3dElementRepresentation::Property, "Returns field Property");
	cls_StepFEA_Curve3dElementRepresentation.def("SetProperty", (void (StepFEA_Curve3dElementRepresentation::*)(const opencascade::handle<StepFEA_Curve3dElementProperty> &)) &StepFEA_Curve3dElementRepresentation::SetProperty, "Set field Property", py::arg("Property"));
	cls_StepFEA_Curve3dElementRepresentation.def("Material", (opencascade::handle<StepElement_ElementMaterial> (StepFEA_Curve3dElementRepresentation::*)() const ) &StepFEA_Curve3dElementRepresentation::Material, "Returns field Material");
	cls_StepFEA_Curve3dElementRepresentation.def("SetMaterial", (void (StepFEA_Curve3dElementRepresentation::*)(const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Curve3dElementRepresentation::SetMaterial, "Set field Material", py::arg("Material"));
	cls_StepFEA_Curve3dElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_Curve3dElementRepresentation::get_type_name, "None");
	cls_StepFEA_Curve3dElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Curve3dElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_Curve3dElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Curve3dElementRepresentation::*)() const ) &StepFEA_Curve3dElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaMaterialPropertyRepresentationItem.hxx
	py::class_<StepFEA_FeaMaterialPropertyRepresentationItem, opencascade::handle<StepFEA_FeaMaterialPropertyRepresentationItem>, StepRepr_RepresentationItem> cls_StepFEA_FeaMaterialPropertyRepresentationItem(mod, "StepFEA_FeaMaterialPropertyRepresentationItem", "Representation of STEP entity FeaMaterialPropertyRepresentationItem");
	cls_StepFEA_FeaMaterialPropertyRepresentationItem.def(py::init<>());
	cls_StepFEA_FeaMaterialPropertyRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMaterialPropertyRepresentationItem::get_type_name, "None");
	cls_StepFEA_FeaMaterialPropertyRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMaterialPropertyRepresentationItem::get_type_descriptor, "None");
	cls_StepFEA_FeaMaterialPropertyRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMaterialPropertyRepresentationItem::*)() const ) &StepFEA_FeaMaterialPropertyRepresentationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaAxis2Placement3d.hxx
	py::class_<StepFEA_FeaAxis2Placement3d, opencascade::handle<StepFEA_FeaAxis2Placement3d>, StepGeom_Axis2Placement3d> cls_StepFEA_FeaAxis2Placement3d(mod, "StepFEA_FeaAxis2Placement3d", "Representation of STEP entity FeaAxis2Placement3d");
	cls_StepFEA_FeaAxis2Placement3d.def(py::init<>());
	cls_StepFEA_FeaAxis2Placement3d.def("Init", (void (StepFEA_FeaAxis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const StepFEA_CoordinateSystemType, const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaAxis2Placement3d::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aPlacement_Location"), py::arg("hasAxis2Placement3d_Axis"), py::arg("aAxis2Placement3d_Axis"), py::arg("hasAxis2Placement3d_RefDirection"), py::arg("aAxis2Placement3d_RefDirection"), py::arg("aSystemType"), py::arg("aDescription"));
	cls_StepFEA_FeaAxis2Placement3d.def("SystemType", (StepFEA_CoordinateSystemType (StepFEA_FeaAxis2Placement3d::*)() const ) &StepFEA_FeaAxis2Placement3d::SystemType, "Returns field SystemType");
	cls_StepFEA_FeaAxis2Placement3d.def("SetSystemType", (void (StepFEA_FeaAxis2Placement3d::*)(const StepFEA_CoordinateSystemType)) &StepFEA_FeaAxis2Placement3d::SetSystemType, "Set field SystemType", py::arg("SystemType"));
	cls_StepFEA_FeaAxis2Placement3d.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaAxis2Placement3d::*)() const ) &StepFEA_FeaAxis2Placement3d::Description, "Returns field Description");
	cls_StepFEA_FeaAxis2Placement3d.def("SetDescription", (void (StepFEA_FeaAxis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaAxis2Placement3d::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepFEA_FeaAxis2Placement3d.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaAxis2Placement3d::get_type_name, "None");
	cls_StepFEA_FeaAxis2Placement3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaAxis2Placement3d::get_type_descriptor, "None");
	cls_StepFEA_FeaAxis2Placement3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaAxis2Placement3d::*)() const ) &StepFEA_FeaAxis2Placement3d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaCurveSectionGeometricRelationship.hxx
	py::class_<StepFEA_FeaCurveSectionGeometricRelationship, opencascade::handle<StepFEA_FeaCurveSectionGeometricRelationship>, Standard_Transient> cls_StepFEA_FeaCurveSectionGeometricRelationship(mod, "StepFEA_FeaCurveSectionGeometricRelationship", "Representation of STEP entity FeaCurveSectionGeometricRelationship");
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def(py::init<>());
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("Init", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaCurveSectionGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aSectionRef"), py::arg("aItem"));
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SectionRef", (opencascade::handle<StepElement_CurveElementSectionDefinition> (StepFEA_FeaCurveSectionGeometricRelationship::*)() const ) &StepFEA_FeaCurveSectionGeometricRelationship::SectionRef, "Returns field SectionRef");
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SetSectionRef", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_CurveElementSectionDefinition> &)) &StepFEA_FeaCurveSectionGeometricRelationship::SetSectionRef, "Set field SectionRef", py::arg("SectionRef"));
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_FeaCurveSectionGeometricRelationship::*)() const ) &StepFEA_FeaCurveSectionGeometricRelationship::Item, "Returns field Item");
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("SetItem", (void (StepFEA_FeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaCurveSectionGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaCurveSectionGeometricRelationship::get_type_name, "None");
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaCurveSectionGeometricRelationship::get_type_descriptor, "None");
	cls_StepFEA_FeaCurveSectionGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaCurveSectionGeometricRelationship::*)() const ) &StepFEA_FeaCurveSectionGeometricRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ElementGroup.hxx
	py::class_<StepFEA_ElementGroup, opencascade::handle<StepFEA_ElementGroup>, StepFEA_FeaGroup> cls_StepFEA_ElementGroup(mod, "StepFEA_ElementGroup", "Representation of STEP entity ElementGroup");
	cls_StepFEA_ElementGroup.def(py::init<>());
	cls_StepFEA_ElementGroup.def("Init", (void (StepFEA_ElementGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &, const opencascade::handle<StepFEA_HArray1OfElementRepresentation> &)) &StepFEA_ElementGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aFeaGroup_ModelRef"), py::arg("aElements"));
	cls_StepFEA_ElementGroup.def("Elements", (opencascade::handle<StepFEA_HArray1OfElementRepresentation> (StepFEA_ElementGroup::*)() const ) &StepFEA_ElementGroup::Elements, "Returns field Elements");
	cls_StepFEA_ElementGroup.def("SetElements", (void (StepFEA_ElementGroup::*)(const opencascade::handle<StepFEA_HArray1OfElementRepresentation> &)) &StepFEA_ElementGroup::SetElements, "Set field Elements", py::arg("Elements"));
	cls_StepFEA_ElementGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_ElementGroup::get_type_name, "None");
	cls_StepFEA_ElementGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ElementGroup::get_type_descriptor, "None");
	cls_StepFEA_ElementGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ElementGroup::*)() const ) &StepFEA_ElementGroup::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaLinearElasticity.hxx
	py::class_<StepFEA_FeaLinearElasticity, opencascade::handle<StepFEA_FeaLinearElasticity>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaLinearElasticity(mod, "StepFEA_FeaLinearElasticity", "Representation of STEP entity FeaLinearElasticity");
	cls_StepFEA_FeaLinearElasticity.def(py::init<>());
	cls_StepFEA_FeaLinearElasticity.def("Init", (void (StepFEA_FeaLinearElasticity::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor43d &)) &StepFEA_FeaLinearElasticity::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaLinearElasticity.def("FeaConstants", (StepFEA_SymmetricTensor43d (StepFEA_FeaLinearElasticity::*)() const ) &StepFEA_FeaLinearElasticity::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaLinearElasticity.def("SetFeaConstants", (void (StepFEA_FeaLinearElasticity::*)(const StepFEA_SymmetricTensor43d &)) &StepFEA_FeaLinearElasticity::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaLinearElasticity.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaLinearElasticity::get_type_name, "None");
	cls_StepFEA_FeaLinearElasticity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaLinearElasticity::get_type_descriptor, "None");
	cls_StepFEA_FeaLinearElasticity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaLinearElasticity::*)() const ) &StepFEA_FeaLinearElasticity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaMassDensity.hxx
	py::class_<StepFEA_FeaMassDensity, opencascade::handle<StepFEA_FeaMassDensity>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaMassDensity(mod, "StepFEA_FeaMassDensity", "Representation of STEP entity FeaMassDensity");
	cls_StepFEA_FeaMassDensity.def(py::init<>());
	cls_StepFEA_FeaMassDensity.def("Init", (void (StepFEA_FeaMassDensity::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepFEA_FeaMassDensity::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstant"));
	cls_StepFEA_FeaMassDensity.def("FeaConstant", (Standard_Real (StepFEA_FeaMassDensity::*)() const ) &StepFEA_FeaMassDensity::FeaConstant, "Returns field FeaConstant");
	cls_StepFEA_FeaMassDensity.def("SetFeaConstant", (void (StepFEA_FeaMassDensity::*)(const Standard_Real)) &StepFEA_FeaMassDensity::SetFeaConstant, "Set field FeaConstant", py::arg("FeaConstant"));
	cls_StepFEA_FeaMassDensity.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMassDensity::get_type_name, "None");
	cls_StepFEA_FeaMassDensity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMassDensity::get_type_descriptor, "None");
	cls_StepFEA_FeaMassDensity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMassDensity::*)() const ) &StepFEA_FeaMassDensity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaMaterialPropertyRepresentation.hxx
	py::class_<StepFEA_FeaMaterialPropertyRepresentation, opencascade::handle<StepFEA_FeaMaterialPropertyRepresentation>, StepRepr_MaterialPropertyRepresentation> cls_StepFEA_FeaMaterialPropertyRepresentation(mod, "StepFEA_FeaMaterialPropertyRepresentation", "Representation of STEP entity FeaMaterialPropertyRepresentation");
	cls_StepFEA_FeaMaterialPropertyRepresentation.def(py::init<>());
	cls_StepFEA_FeaMaterialPropertyRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMaterialPropertyRepresentation::get_type_name, "None");
	cls_StepFEA_FeaMaterialPropertyRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMaterialPropertyRepresentation::get_type_descriptor, "None");
	cls_StepFEA_FeaMaterialPropertyRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMaterialPropertyRepresentation::*)() const ) &StepFEA_FeaMaterialPropertyRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaAreaDensity.hxx
	py::class_<StepFEA_FeaAreaDensity, opencascade::handle<StepFEA_FeaAreaDensity>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaAreaDensity(mod, "StepFEA_FeaAreaDensity", "Representation of STEP entity FeaAreaDensity");
	cls_StepFEA_FeaAreaDensity.def(py::init<>());
	cls_StepFEA_FeaAreaDensity.def("Init", (void (StepFEA_FeaAreaDensity::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real)) &StepFEA_FeaAreaDensity::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstant"));
	cls_StepFEA_FeaAreaDensity.def("FeaConstant", (Standard_Real (StepFEA_FeaAreaDensity::*)() const ) &StepFEA_FeaAreaDensity::FeaConstant, "Returns field FeaConstant");
	cls_StepFEA_FeaAreaDensity.def("SetFeaConstant", (void (StepFEA_FeaAreaDensity::*)(const Standard_Real)) &StepFEA_FeaAreaDensity::SetFeaConstant, "Set field FeaConstant", py::arg("FeaConstant"));
	cls_StepFEA_FeaAreaDensity.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaAreaDensity::get_type_name, "None");
	cls_StepFEA_FeaAreaDensity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaAreaDensity::get_type_descriptor, "None");
	cls_StepFEA_FeaAreaDensity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaAreaDensity::*)() const ) &StepFEA_FeaAreaDensity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaModel.hxx
	py::class_<StepFEA_FeaModel, opencascade::handle<StepFEA_FeaModel>, StepRepr_Representation> cls_StepFEA_FeaModel(mod, "StepFEA_FeaModel", "Representation of STEP entity FeaModel");
	cls_StepFEA_FeaModel.def(py::init<>());
	cls_StepFEA_FeaModel.def("Init", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aCreatingSoftware"), py::arg("aIntendedAnalysisCode"), py::arg("aDescription"), py::arg("aAnalysisType"));
	cls_StepFEA_FeaModel.def("CreatingSoftware", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const ) &StepFEA_FeaModel::CreatingSoftware, "Returns field CreatingSoftware");
	cls_StepFEA_FeaModel.def("SetCreatingSoftware", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetCreatingSoftware, "Set field CreatingSoftware", py::arg("CreatingSoftware"));
	cls_StepFEA_FeaModel.def("IntendedAnalysisCode", (opencascade::handle<TColStd_HArray1OfAsciiString> (StepFEA_FeaModel::*)() const ) &StepFEA_FeaModel::IntendedAnalysisCode, "Returns field IntendedAnalysisCode");
	cls_StepFEA_FeaModel.def("SetIntendedAnalysisCode", (void (StepFEA_FeaModel::*)(const opencascade::handle<TColStd_HArray1OfAsciiString> &)) &StepFEA_FeaModel::SetIntendedAnalysisCode, "Set field IntendedAnalysisCode", py::arg("IntendedAnalysisCode"));
	cls_StepFEA_FeaModel.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const ) &StepFEA_FeaModel::Description, "Returns field Description");
	cls_StepFEA_FeaModel.def("SetDescription", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetDescription, "Set field Description", py::arg("Description"));
	cls_StepFEA_FeaModel.def("AnalysisType", (opencascade::handle<TCollection_HAsciiString> (StepFEA_FeaModel::*)() const ) &StepFEA_FeaModel::AnalysisType, "Returns field AnalysisType");
	cls_StepFEA_FeaModel.def("SetAnalysisType", (void (StepFEA_FeaModel::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_FeaModel::SetAnalysisType, "Set field AnalysisType", py::arg("AnalysisType"));
	cls_StepFEA_FeaModel.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModel::get_type_name, "None");
	cls_StepFEA_FeaModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModel::get_type_descriptor, "None");
	cls_StepFEA_FeaModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModel::*)() const ) &StepFEA_FeaModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaModel3d.hxx
	py::class_<StepFEA_FeaModel3d, opencascade::handle<StepFEA_FeaModel3d>, StepFEA_FeaModel> cls_StepFEA_FeaModel3d(mod, "StepFEA_FeaModel3d", "Representation of STEP entity FeaModel3d");
	cls_StepFEA_FeaModel3d.def(py::init<>());
	cls_StepFEA_FeaModel3d.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModel3d::get_type_name, "None");
	cls_StepFEA_FeaModel3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModel3d::get_type_descriptor, "None");
	cls_StepFEA_FeaModel3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModel3d::*)() const ) &StepFEA_FeaModel3d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaModelDefinition.hxx
	py::class_<StepFEA_FeaModelDefinition, opencascade::handle<StepFEA_FeaModelDefinition>, StepRepr_ShapeAspect> cls_StepFEA_FeaModelDefinition(mod, "StepFEA_FeaModelDefinition", "Representation of STEP entity FeaModelDefinition");
	cls_StepFEA_FeaModelDefinition.def(py::init<>());
	cls_StepFEA_FeaModelDefinition.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModelDefinition::get_type_name, "None");
	cls_StepFEA_FeaModelDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModelDefinition::get_type_descriptor, "None");
	cls_StepFEA_FeaModelDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModelDefinition::*)() const ) &StepFEA_FeaModelDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaMoistureAbsorption.hxx
	py::class_<StepFEA_FeaMoistureAbsorption, opencascade::handle<StepFEA_FeaMoistureAbsorption>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaMoistureAbsorption(mod, "StepFEA_FeaMoistureAbsorption", "Representation of STEP entity FeaMoistureAbsorption");
	cls_StepFEA_FeaMoistureAbsorption.def(py::init<>());
	cls_StepFEA_FeaMoistureAbsorption.def("Init", (void (StepFEA_FeaMoistureAbsorption::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaMoistureAbsorption::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaMoistureAbsorption.def("FeaConstants", (StepFEA_SymmetricTensor23d (StepFEA_FeaMoistureAbsorption::*)() const ) &StepFEA_FeaMoistureAbsorption::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaMoistureAbsorption.def("SetFeaConstants", (void (StepFEA_FeaMoistureAbsorption::*)(const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaMoistureAbsorption::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaMoistureAbsorption.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaMoistureAbsorption::get_type_name, "None");
	cls_StepFEA_FeaMoistureAbsorption.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaMoistureAbsorption::get_type_descriptor, "None");
	cls_StepFEA_FeaMoistureAbsorption.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaMoistureAbsorption::*)() const ) &StepFEA_FeaMoistureAbsorption::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaParametricPoint.hxx
	py::class_<StepFEA_FeaParametricPoint, opencascade::handle<StepFEA_FeaParametricPoint>, StepGeom_Point> cls_StepFEA_FeaParametricPoint(mod, "StepFEA_FeaParametricPoint", "Representation of STEP entity FeaParametricPoint");
	cls_StepFEA_FeaParametricPoint.def(py::init<>());
	cls_StepFEA_FeaParametricPoint.def("Init", (void (StepFEA_FeaParametricPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_FeaParametricPoint::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinates"));
	cls_StepFEA_FeaParametricPoint.def("Coordinates", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_FeaParametricPoint::*)() const ) &StepFEA_FeaParametricPoint::Coordinates, "Returns field Coordinates");
	cls_StepFEA_FeaParametricPoint.def("SetCoordinates", (void (StepFEA_FeaParametricPoint::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_FeaParametricPoint::SetCoordinates, "Set field Coordinates", py::arg("Coordinates"));
	cls_StepFEA_FeaParametricPoint.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaParametricPoint::get_type_name, "None");
	cls_StepFEA_FeaParametricPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaParametricPoint::get_type_descriptor, "None");
	cls_StepFEA_FeaParametricPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaParametricPoint::*)() const ) &StepFEA_FeaParametricPoint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_AlignedCurve3dElementCoordinateSystem.hxx
	py::class_<StepFEA_AlignedCurve3dElementCoordinateSystem, opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_AlignedCurve3dElementCoordinateSystem(mod, "StepFEA_AlignedCurve3dElementCoordinateSystem", "Representation of STEP entity AlignedCurve3dElementCoordinateSystem");
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("Init", (void (StepFEA_AlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedCurve3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinateSystem"));
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("CoordinateSystem", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_AlignedCurve3dElementCoordinateSystem::*)() const ) &StepFEA_AlignedCurve3dElementCoordinateSystem::CoordinateSystem, "Returns field CoordinateSystem");
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("SetCoordinateSystem", (void (StepFEA_AlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedCurve3dElementCoordinateSystem::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_AlignedCurve3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_AlignedCurve3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_AlignedCurve3dElementCoordinateSystem::*)() const ) &StepFEA_AlignedCurve3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.hxx
	py::class_<StepFEA_FeaSecantCoefficientOfLinearThermalExpansion, opencascade::handle<StepFEA_FeaSecantCoefficientOfLinearThermalExpansion>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion(mod, "StepFEA_FeaSecantCoefficientOfLinearThermalExpansion", "Representation of STEP entity FeaSecantCoefficientOfLinearThermalExpansion");
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def(py::init<>());
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("Init", (void (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor23d &, const Standard_Real)) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"), py::arg("aReferenceTemperature"));
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("FeaConstants", (StepFEA_SymmetricTensor23d (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)() const ) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("SetFeaConstants", (void (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)(const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("ReferenceTemperature", (Standard_Real (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)() const ) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::ReferenceTemperature, "Returns field ReferenceTemperature");
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("SetReferenceTemperature", (void (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)(const Standard_Real)) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::SetReferenceTemperature, "Set field ReferenceTemperature", py::arg("ReferenceTemperature"));
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::get_type_name, "None");
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::get_type_descriptor, "None");
	cls_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::*)() const ) &StepFEA_FeaSecantCoefficientOfLinearThermalExpansion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaShellBendingStiffness.hxx
	py::class_<StepFEA_FeaShellBendingStiffness, opencascade::handle<StepFEA_FeaShellBendingStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellBendingStiffness(mod, "StepFEA_FeaShellBendingStiffness", "Representation of STEP entity FeaShellBendingStiffness");
	cls_StepFEA_FeaShellBendingStiffness.def(py::init<>());
	cls_StepFEA_FeaShellBendingStiffness.def("Init", (void (StepFEA_FeaShellBendingStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellBendingStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaShellBendingStiffness.def("FeaConstants", (StepFEA_SymmetricTensor42d (StepFEA_FeaShellBendingStiffness::*)() const ) &StepFEA_FeaShellBendingStiffness::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaShellBendingStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellBendingStiffness::*)(const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellBendingStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaShellBendingStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellBendingStiffness::get_type_name, "None");
	cls_StepFEA_FeaShellBendingStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellBendingStiffness::get_type_descriptor, "None");
	cls_StepFEA_FeaShellBendingStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellBendingStiffness::*)() const ) &StepFEA_FeaShellBendingStiffness::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaShellMembraneBendingCouplingStiffness.hxx
	py::class_<StepFEA_FeaShellMembraneBendingCouplingStiffness, opencascade::handle<StepFEA_FeaShellMembraneBendingCouplingStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellMembraneBendingCouplingStiffness(mod, "StepFEA_FeaShellMembraneBendingCouplingStiffness", "Representation of STEP entity FeaShellMembraneBendingCouplingStiffness");
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def(py::init<>());
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("Init", (void (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneBendingCouplingStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("FeaConstants", (StepFEA_SymmetricTensor42d (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)() const ) &StepFEA_FeaShellMembraneBendingCouplingStiffness::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)(const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneBendingCouplingStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellMembraneBendingCouplingStiffness::get_type_name, "None");
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellMembraneBendingCouplingStiffness::get_type_descriptor, "None");
	cls_StepFEA_FeaShellMembraneBendingCouplingStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellMembraneBendingCouplingStiffness::*)() const ) &StepFEA_FeaShellMembraneBendingCouplingStiffness::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaShellMembraneStiffness.hxx
	py::class_<StepFEA_FeaShellMembraneStiffness, opencascade::handle<StepFEA_FeaShellMembraneStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellMembraneStiffness(mod, "StepFEA_FeaShellMembraneStiffness", "Representation of STEP entity FeaShellMembraneStiffness");
	cls_StepFEA_FeaShellMembraneStiffness.def(py::init<>());
	cls_StepFEA_FeaShellMembraneStiffness.def("Init", (void (StepFEA_FeaShellMembraneStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaShellMembraneStiffness.def("FeaConstants", (StepFEA_SymmetricTensor42d (StepFEA_FeaShellMembraneStiffness::*)() const ) &StepFEA_FeaShellMembraneStiffness::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaShellMembraneStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellMembraneStiffness::*)(const StepFEA_SymmetricTensor42d &)) &StepFEA_FeaShellMembraneStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaShellMembraneStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellMembraneStiffness::get_type_name, "None");
	cls_StepFEA_FeaShellMembraneStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellMembraneStiffness::get_type_descriptor, "None");
	cls_StepFEA_FeaShellMembraneStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellMembraneStiffness::*)() const ) &StepFEA_FeaShellMembraneStiffness::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaShellShearStiffness.hxx
	py::class_<StepFEA_FeaShellShearStiffness, opencascade::handle<StepFEA_FeaShellShearStiffness>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaShellShearStiffness(mod, "StepFEA_FeaShellShearStiffness", "Representation of STEP entity FeaShellShearStiffness");
	cls_StepFEA_FeaShellShearStiffness.def(py::init<>());
	cls_StepFEA_FeaShellShearStiffness.def("Init", (void (StepFEA_FeaShellShearStiffness::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor22d &)) &StepFEA_FeaShellShearStiffness::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaShellShearStiffness.def("FeaConstants", (StepFEA_SymmetricTensor22d (StepFEA_FeaShellShearStiffness::*)() const ) &StepFEA_FeaShellShearStiffness::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaShellShearStiffness.def("SetFeaConstants", (void (StepFEA_FeaShellShearStiffness::*)(const StepFEA_SymmetricTensor22d &)) &StepFEA_FeaShellShearStiffness::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaShellShearStiffness.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaShellShearStiffness::get_type_name, "None");
	cls_StepFEA_FeaShellShearStiffness.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaShellShearStiffness::get_type_descriptor, "None");
	cls_StepFEA_FeaShellShearStiffness.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaShellShearStiffness::*)() const ) &StepFEA_FeaShellShearStiffness::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaSurfaceSectionGeometricRelationship.hxx
	py::class_<StepFEA_FeaSurfaceSectionGeometricRelationship, opencascade::handle<StepFEA_FeaSurfaceSectionGeometricRelationship>, Standard_Transient> cls_StepFEA_FeaSurfaceSectionGeometricRelationship(mod, "StepFEA_FeaSurfaceSectionGeometricRelationship", "Representation of STEP entity FeaSurfaceSectionGeometricRelationship");
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def(py::init<>());
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("Init", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_SurfaceSection> &, const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aSectionRef"), py::arg("aItem"));
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SectionRef", (opencascade::handle<StepElement_SurfaceSection> (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const ) &StepFEA_FeaSurfaceSectionGeometricRelationship::SectionRef, "Returns field SectionRef");
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SetSectionRef", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::SetSectionRef, "Set field SectionRef", py::arg("SectionRef"));
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("Item", (opencascade::handle<StepElement_AnalysisItemWithinRepresentation> (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const ) &StepFEA_FeaSurfaceSectionGeometricRelationship::Item, "Returns field Item");
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("SetItem", (void (StepFEA_FeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepElement_AnalysisItemWithinRepresentation> &)) &StepFEA_FeaSurfaceSectionGeometricRelationship::SetItem, "Set field Item", py::arg("Item"));
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaSurfaceSectionGeometricRelationship::get_type_name, "None");
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaSurfaceSectionGeometricRelationship::get_type_descriptor, "None");
	cls_StepFEA_FeaSurfaceSectionGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaSurfaceSectionGeometricRelationship::*)() const ) &StepFEA_FeaSurfaceSectionGeometricRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.hxx
	py::class_<StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion, opencascade::handle<StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion>, StepFEA_FeaMaterialPropertyRepresentationItem> cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion(mod, "StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion", "Representation of STEP entity FeaTangentialCoefficientOfLinearThermalExpansion");
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def(py::init<>());
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def("Init", (void (StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aFeaConstants"));
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def("FeaConstants", (StepFEA_SymmetricTensor23d (StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::*)() const ) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::FeaConstants, "Returns field FeaConstants");
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def("SetFeaConstants", (void (StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::*)(const StepFEA_SymmetricTensor23d &)) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::SetFeaConstants, "Set field FeaConstants", py::arg("FeaConstants"));
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::get_type_name, "None");
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::get_type_descriptor, "None");
	cls_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::*)() const ) &StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FreedomAndCoefficient.hxx
	py::class_<StepFEA_FreedomAndCoefficient, opencascade::handle<StepFEA_FreedomAndCoefficient>, Standard_Transient> cls_StepFEA_FreedomAndCoefficient(mod, "StepFEA_FreedomAndCoefficient", "Representation of STEP entity FreedomAndCoefficient");
	cls_StepFEA_FreedomAndCoefficient.def(py::init<>());
	cls_StepFEA_FreedomAndCoefficient.def("Init", (void (StepFEA_FreedomAndCoefficient::*)(const StepFEA_DegreeOfFreedom &, const StepElement_MeasureOrUnspecifiedValue &)) &StepFEA_FreedomAndCoefficient::Init, "Initialize all fields (own and inherited)", py::arg("aFreedom"), py::arg("aA"));
	cls_StepFEA_FreedomAndCoefficient.def("Freedom", (StepFEA_DegreeOfFreedom (StepFEA_FreedomAndCoefficient::*)() const ) &StepFEA_FreedomAndCoefficient::Freedom, "Returns field Freedom");
	cls_StepFEA_FreedomAndCoefficient.def("SetFreedom", (void (StepFEA_FreedomAndCoefficient::*)(const StepFEA_DegreeOfFreedom &)) &StepFEA_FreedomAndCoefficient::SetFreedom, "Set field Freedom", py::arg("Freedom"));
	cls_StepFEA_FreedomAndCoefficient.def("A", (StepElement_MeasureOrUnspecifiedValue (StepFEA_FreedomAndCoefficient::*)() const ) &StepFEA_FreedomAndCoefficient::A, "Returns field A");
	cls_StepFEA_FreedomAndCoefficient.def("SetA", (void (StepFEA_FreedomAndCoefficient::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepFEA_FreedomAndCoefficient::SetA, "Set field A", py::arg("A"));
	cls_StepFEA_FreedomAndCoefficient.def_static("get_type_name_", (const char * (*)()) &StepFEA_FreedomAndCoefficient::get_type_name, "None");
	cls_StepFEA_FreedomAndCoefficient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FreedomAndCoefficient::get_type_descriptor, "None");
	cls_StepFEA_FreedomAndCoefficient.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FreedomAndCoefficient::*)() const ) &StepFEA_FreedomAndCoefficient::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_FreedomsList.hxx
	py::class_<StepFEA_FreedomsList, opencascade::handle<StepFEA_FreedomsList>, Standard_Transient> cls_StepFEA_FreedomsList(mod, "StepFEA_FreedomsList", "Representation of STEP entity FreedomsList");
	cls_StepFEA_FreedomsList.def(py::init<>());
	cls_StepFEA_FreedomsList.def("Init", (void (StepFEA_FreedomsList::*)(const opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> &)) &StepFEA_FreedomsList::Init, "Initialize all fields (own and inherited)", py::arg("aFreedoms"));
	cls_StepFEA_FreedomsList.def("Freedoms", (opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> (StepFEA_FreedomsList::*)() const ) &StepFEA_FreedomsList::Freedoms, "Returns field Freedoms");
	cls_StepFEA_FreedomsList.def("SetFreedoms", (void (StepFEA_FreedomsList::*)(const opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom> &)) &StepFEA_FreedomsList::SetFreedoms, "Set field Freedoms", py::arg("Freedoms"));
	cls_StepFEA_FreedomsList.def_static("get_type_name_", (const char * (*)()) &StepFEA_FreedomsList::get_type_name, "None");
	cls_StepFEA_FreedomsList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FreedomsList::get_type_descriptor, "None");
	cls_StepFEA_FreedomsList.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FreedomsList::*)() const ) &StepFEA_FreedomsList::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_GeometricNode.hxx
	py::class_<StepFEA_GeometricNode, opencascade::handle<StepFEA_GeometricNode>, StepFEA_NodeRepresentation> cls_StepFEA_GeometricNode(mod, "StepFEA_GeometricNode", "Representation of STEP entity GeometricNode");
	cls_StepFEA_GeometricNode.def(py::init<>());
	cls_StepFEA_GeometricNode.def_static("get_type_name_", (const char * (*)()) &StepFEA_GeometricNode::get_type_name, "None");
	cls_StepFEA_GeometricNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_GeometricNode::get_type_descriptor, "None");
	cls_StepFEA_GeometricNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_GeometricNode::*)() const ) &StepFEA_GeometricNode::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Node.hxx
	py::class_<StepFEA_Node, opencascade::handle<StepFEA_Node>, StepFEA_NodeRepresentation> cls_StepFEA_Node(mod, "StepFEA_Node", "Representation of STEP entity Node");
	cls_StepFEA_Node.def(py::init<>());
	cls_StepFEA_Node.def_static("get_type_name_", (const char * (*)()) &StepFEA_Node::get_type_name, "None");
	cls_StepFEA_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Node::get_type_descriptor, "None");
	cls_StepFEA_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Node::*)() const ) &StepFEA_Node::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeDefinition.hxx
	py::class_<StepFEA_NodeDefinition, opencascade::handle<StepFEA_NodeDefinition>, StepRepr_ShapeAspect> cls_StepFEA_NodeDefinition(mod, "StepFEA_NodeDefinition", "Representation of STEP entity NodeDefinition");
	cls_StepFEA_NodeDefinition.def(py::init<>());
	cls_StepFEA_NodeDefinition.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeDefinition::get_type_name, "None");
	cls_StepFEA_NodeDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeDefinition::get_type_descriptor, "None");
	cls_StepFEA_NodeDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeDefinition::*)() const ) &StepFEA_NodeDefinition::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeGroup.hxx
	py::class_<StepFEA_NodeGroup, opencascade::handle<StepFEA_NodeGroup>, StepFEA_FeaGroup> cls_StepFEA_NodeGroup(mod, "StepFEA_NodeGroup", "Representation of STEP entity NodeGroup");
	cls_StepFEA_NodeGroup.def(py::init<>());
	cls_StepFEA_NodeGroup.def("Init", (void (StepFEA_NodeGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaModel> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("aGroup_Description"), py::arg("aFeaGroup_ModelRef"), py::arg("aNodes"));
	cls_StepFEA_NodeGroup.def("Nodes", (opencascade::handle<StepFEA_HArray1OfNodeRepresentation> (StepFEA_NodeGroup::*)() const ) &StepFEA_NodeGroup::Nodes, "Returns field Nodes");
	cls_StepFEA_NodeGroup.def("SetNodes", (void (StepFEA_NodeGroup::*)(const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeGroup::SetNodes, "Set field Nodes", py::arg("Nodes"));
	cls_StepFEA_NodeGroup.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeGroup::get_type_name, "None");
	cls_StepFEA_NodeGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeGroup::get_type_descriptor, "None");
	cls_StepFEA_NodeGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeGroup::*)() const ) &StepFEA_NodeGroup::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_DummyNode.hxx
	py::class_<StepFEA_DummyNode, opencascade::handle<StepFEA_DummyNode>, StepFEA_NodeRepresentation> cls_StepFEA_DummyNode(mod, "StepFEA_DummyNode", "Representation of STEP entity DummyNode");
	cls_StepFEA_DummyNode.def(py::init<>());
	cls_StepFEA_DummyNode.def_static("get_type_name_", (const char * (*)()) &StepFEA_DummyNode::get_type_name, "None");
	cls_StepFEA_DummyNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_DummyNode::get_type_descriptor, "None");
	cls_StepFEA_DummyNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_DummyNode::*)() const ) &StepFEA_DummyNode::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeSet.hxx
	py::class_<StepFEA_NodeSet, opencascade::handle<StepFEA_NodeSet>, StepGeom_GeometricRepresentationItem> cls_StepFEA_NodeSet(mod, "StepFEA_NodeSet", "Representation of STEP entity NodeSet");
	cls_StepFEA_NodeSet.def(py::init<>());
	cls_StepFEA_NodeSet.def("Init", (void (StepFEA_NodeSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeSet::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aNodes"));
	cls_StepFEA_NodeSet.def("Nodes", (opencascade::handle<StepFEA_HArray1OfNodeRepresentation> (StepFEA_NodeSet::*)() const ) &StepFEA_NodeSet::Nodes, "Returns field Nodes");
	cls_StepFEA_NodeSet.def("SetNodes", (void (StepFEA_NodeSet::*)(const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &)) &StepFEA_NodeSet::SetNodes, "Set field Nodes", py::arg("Nodes"));
	cls_StepFEA_NodeSet.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeSet::get_type_name, "None");
	cls_StepFEA_NodeSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeSet::get_type_descriptor, "None");
	cls_StepFEA_NodeSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeSet::*)() const ) &StepFEA_NodeSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeWithSolutionCoordinateSystem.hxx
	py::class_<StepFEA_NodeWithSolutionCoordinateSystem, opencascade::handle<StepFEA_NodeWithSolutionCoordinateSystem>, StepFEA_Node> cls_StepFEA_NodeWithSolutionCoordinateSystem(mod, "StepFEA_NodeWithSolutionCoordinateSystem", "Representation of STEP entity NodeWithSolutionCoordinateSystem");
	cls_StepFEA_NodeWithSolutionCoordinateSystem.def(py::init<>());
	cls_StepFEA_NodeWithSolutionCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeWithSolutionCoordinateSystem::get_type_name, "None");
	cls_StepFEA_NodeWithSolutionCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeWithSolutionCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_NodeWithSolutionCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeWithSolutionCoordinateSystem::*)() const ) &StepFEA_NodeWithSolutionCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_NodeWithVector.hxx
	py::class_<StepFEA_NodeWithVector, opencascade::handle<StepFEA_NodeWithVector>, StepFEA_Node> cls_StepFEA_NodeWithVector(mod, "StepFEA_NodeWithVector", "Representation of STEP entity NodeWithVector");
	cls_StepFEA_NodeWithVector.def(py::init<>());
	cls_StepFEA_NodeWithVector.def_static("get_type_name_", (const char * (*)()) &StepFEA_NodeWithVector::get_type_name, "None");
	cls_StepFEA_NodeWithVector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_NodeWithVector::get_type_descriptor, "None");
	cls_StepFEA_NodeWithVector.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_NodeWithVector::*)() const ) &StepFEA_NodeWithVector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ParametricCurve3dElementCoordinateDirection.hxx
	py::class_<StepFEA_ParametricCurve3dElementCoordinateDirection, opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection>, StepFEA_FeaRepresentationItem> cls_StepFEA_ParametricCurve3dElementCoordinateDirection(mod, "StepFEA_ParametricCurve3dElementCoordinateDirection", "Representation of STEP entity ParametricCurve3dElementCoordinateDirection");
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def(py::init<>());
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("Init", (void (StepFEA_ParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Direction> &)) &StepFEA_ParametricCurve3dElementCoordinateDirection::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientation"));
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("Orientation", (opencascade::handle<StepGeom_Direction> (StepFEA_ParametricCurve3dElementCoordinateDirection::*)() const ) &StepFEA_ParametricCurve3dElementCoordinateDirection::Orientation, "Returns field Orientation");
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("SetOrientation", (void (StepFEA_ParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<StepGeom_Direction> &)) &StepFEA_ParametricCurve3dElementCoordinateDirection::SetOrientation, "Set field Orientation", py::arg("Orientation"));
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def_static("get_type_name_", (const char * (*)()) &StepFEA_ParametricCurve3dElementCoordinateDirection::get_type_name, "None");
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ParametricCurve3dElementCoordinateDirection::get_type_descriptor, "None");
	cls_StepFEA_ParametricCurve3dElementCoordinateDirection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ParametricCurve3dElementCoordinateDirection::*)() const ) &StepFEA_ParametricCurve3dElementCoordinateDirection::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ParametricCurve3dElementCoordinateSystem.hxx
	py::class_<StepFEA_ParametricCurve3dElementCoordinateSystem, opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_ParametricCurve3dElementCoordinateSystem(mod, "StepFEA_ParametricCurve3dElementCoordinateSystem", "Representation of STEP entity ParametricCurve3dElementCoordinateSystem");
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def("Init", (void (StepFEA_ParametricCurve3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> &)) &StepFEA_ParametricCurve3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aDirection"));
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def("Direction", (opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> (StepFEA_ParametricCurve3dElementCoordinateSystem::*)() const ) &StepFEA_ParametricCurve3dElementCoordinateSystem::Direction, "Returns field Direction");
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def("SetDirection", (void (StepFEA_ParametricCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> &)) &StepFEA_ParametricCurve3dElementCoordinateSystem::SetDirection, "Set field Direction", py::arg("Direction"));
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_ParametricCurve3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ParametricCurve3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_ParametricCurve3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ParametricCurve3dElementCoordinateSystem::*)() const ) &StepFEA_ParametricCurve3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ParametricSurface3dElementCoordinateSystem.hxx
	py::class_<StepFEA_ParametricSurface3dElementCoordinateSystem, opencascade::handle<StepFEA_ParametricSurface3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_ParametricSurface3dElementCoordinateSystem(mod, "StepFEA_ParametricSurface3dElementCoordinateSystem", "Representation of STEP entity ParametricSurface3dElementCoordinateSystem");
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def(py::init<>());
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Init", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Real)) &StepFEA_ParametricSurface3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aAxis"), py::arg("aAngle"));
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Axis", (Standard_Integer (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ParametricSurface3dElementCoordinateSystem::Axis, "Returns field Axis");
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("SetAxis", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const Standard_Integer)) &StepFEA_ParametricSurface3dElementCoordinateSystem::SetAxis, "Set field Axis", py::arg("Axis"));
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Angle", (Standard_Real (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ParametricSurface3dElementCoordinateSystem::Angle, "Returns field Angle");
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("SetAngle", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const Standard_Real)) &StepFEA_ParametricSurface3dElementCoordinateSystem::SetAngle, "Set field Angle", py::arg("Angle"));
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_ParametricSurface3dElementCoordinateSystem::get_type_name, "None");
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ParametricSurface3dElementCoordinateSystem::get_type_descriptor, "None");
	cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const ) &StepFEA_ParametricSurface3dElementCoordinateSystem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Surface3dElementRepresentation.hxx
	py::class_<StepFEA_Surface3dElementRepresentation, opencascade::handle<StepFEA_Surface3dElementRepresentation>, StepFEA_ElementRepresentation> cls_StepFEA_Surface3dElementRepresentation(mod, "StepFEA_Surface3dElementRepresentation", "Representation of STEP entity Surface3dElementRepresentation");
	cls_StepFEA_Surface3dElementRepresentation.def(py::init<>());
	cls_StepFEA_Surface3dElementRepresentation.def("Init", (void (StepFEA_Surface3dElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &, const opencascade::handle<StepFEA_FeaModel3d> &, const opencascade::handle<StepElement_Surface3dElementDescriptor> &, const opencascade::handle<StepElement_SurfaceElementProperty> &, const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Surface3dElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aElementRepresentation_NodeList"), py::arg("aModelRef"), py::arg("aElementDescriptor"), py::arg("aProperty"), py::arg("aMaterial"));
	cls_StepFEA_Surface3dElementRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel3d> (StepFEA_Surface3dElementRepresentation::*)() const ) &StepFEA_Surface3dElementRepresentation::ModelRef, "Returns field ModelRef");
	cls_StepFEA_Surface3dElementRepresentation.def("SetModelRef", (void (StepFEA_Surface3dElementRepresentation::*)(const opencascade::handle<StepFEA_FeaModel3d> &)) &StepFEA_Surface3dElementRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
	cls_StepFEA_Surface3dElementRepresentation.def("ElementDescriptor", (opencascade::handle<StepElement_Surface3dElementDescriptor> (StepFEA_Surface3dElementRepresentation::*)() const ) &StepFEA_Surface3dElementRepresentation::ElementDescriptor, "Returns field ElementDescriptor");
	cls_StepFEA_Surface3dElementRepresentation.def("SetElementDescriptor", (void (StepFEA_Surface3dElementRepresentation::*)(const opencascade::handle<StepElement_Surface3dElementDescriptor> &)) &StepFEA_Surface3dElementRepresentation::SetElementDescriptor, "Set field ElementDescriptor", py::arg("ElementDescriptor"));
	cls_StepFEA_Surface3dElementRepresentation.def("Property", (opencascade::handle<StepElement_SurfaceElementProperty> (StepFEA_Surface3dElementRepresentation::*)() const ) &StepFEA_Surface3dElementRepresentation::Property, "Returns field Property");
	cls_StepFEA_Surface3dElementRepresentation.def("SetProperty", (void (StepFEA_Surface3dElementRepresentation::*)(const opencascade::handle<StepElement_SurfaceElementProperty> &)) &StepFEA_Surface3dElementRepresentation::SetProperty, "Set field Property", py::arg("Property"));
	cls_StepFEA_Surface3dElementRepresentation.def("Material", (opencascade::handle<StepElement_ElementMaterial> (StepFEA_Surface3dElementRepresentation::*)() const ) &StepFEA_Surface3dElementRepresentation::Material, "Returns field Material");
	cls_StepFEA_Surface3dElementRepresentation.def("SetMaterial", (void (StepFEA_Surface3dElementRepresentation::*)(const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Surface3dElementRepresentation::SetMaterial, "Set field Material", py::arg("Material"));
	cls_StepFEA_Surface3dElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_Surface3dElementRepresentation::get_type_name, "None");
	cls_StepFEA_Surface3dElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Surface3dElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_Surface3dElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Surface3dElementRepresentation::*)() const ) &StepFEA_Surface3dElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Volume3dElementRepresentation.hxx
	py::class_<StepFEA_Volume3dElementRepresentation, opencascade::handle<StepFEA_Volume3dElementRepresentation>, StepFEA_ElementRepresentation> cls_StepFEA_Volume3dElementRepresentation(mod, "StepFEA_Volume3dElementRepresentation", "Representation of STEP entity Volume3dElementRepresentation");
	cls_StepFEA_Volume3dElementRepresentation.def(py::init<>());
	cls_StepFEA_Volume3dElementRepresentation.def("Init", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepFEA_HArray1OfNodeRepresentation> &, const opencascade::handle<StepFEA_FeaModel3d> &, const opencascade::handle<StepElement_Volume3dElementDescriptor> &, const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Volume3dElementRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentation_Name"), py::arg("aRepresentation_Items"), py::arg("aRepresentation_ContextOfItems"), py::arg("aElementRepresentation_NodeList"), py::arg("aModelRef"), py::arg("aElementDescriptor"), py::arg("aMaterial"));
	cls_StepFEA_Volume3dElementRepresentation.def("ModelRef", (opencascade::handle<StepFEA_FeaModel3d> (StepFEA_Volume3dElementRepresentation::*)() const ) &StepFEA_Volume3dElementRepresentation::ModelRef, "Returns field ModelRef");
	cls_StepFEA_Volume3dElementRepresentation.def("SetModelRef", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepFEA_FeaModel3d> &)) &StepFEA_Volume3dElementRepresentation::SetModelRef, "Set field ModelRef", py::arg("ModelRef"));
	cls_StepFEA_Volume3dElementRepresentation.def("ElementDescriptor", (opencascade::handle<StepElement_Volume3dElementDescriptor> (StepFEA_Volume3dElementRepresentation::*)() const ) &StepFEA_Volume3dElementRepresentation::ElementDescriptor, "Returns field ElementDescriptor");
	cls_StepFEA_Volume3dElementRepresentation.def("SetElementDescriptor", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepElement_Volume3dElementDescriptor> &)) &StepFEA_Volume3dElementRepresentation::SetElementDescriptor, "Set field ElementDescriptor", py::arg("ElementDescriptor"));
	cls_StepFEA_Volume3dElementRepresentation.def("Material", (opencascade::handle<StepElement_ElementMaterial> (StepFEA_Volume3dElementRepresentation::*)() const ) &StepFEA_Volume3dElementRepresentation::Material, "Returns field Material");
	cls_StepFEA_Volume3dElementRepresentation.def("SetMaterial", (void (StepFEA_Volume3dElementRepresentation::*)(const opencascade::handle<StepElement_ElementMaterial> &)) &StepFEA_Volume3dElementRepresentation::SetMaterial, "Set field Material", py::arg("Material"));
	cls_StepFEA_Volume3dElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_Volume3dElementRepresentation::get_type_name, "None");
	cls_StepFEA_Volume3dElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_Volume3dElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_Volume3dElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_Volume3dElementRepresentation::*)() const ) &StepFEA_Volume3dElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_ElementOrElementGroup.hxx
	py::class_<StepFEA_ElementOrElementGroup, std::unique_ptr<StepFEA_ElementOrElementGroup, Deleter<StepFEA_ElementOrElementGroup>>, StepData_SelectType> cls_StepFEA_ElementOrElementGroup(mod, "StepFEA_ElementOrElementGroup", "Representation of STEP SELECT type ElementOrElementGroup");
	cls_StepFEA_ElementOrElementGroup.def(py::init<>());
	cls_StepFEA_ElementOrElementGroup.def("CaseNum", (Standard_Integer (StepFEA_ElementOrElementGroup::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_ElementOrElementGroup::CaseNum, "Recognizes a kind of ElementOrElementGroup select type 1 -> ElementRepresentation from StepFEA 2 -> ElementGroup from StepFEA 0 else", py::arg("ent"));
	cls_StepFEA_ElementOrElementGroup.def("ElementRepresentation", (opencascade::handle<StepFEA_ElementRepresentation> (StepFEA_ElementOrElementGroup::*)() const ) &StepFEA_ElementOrElementGroup::ElementRepresentation, "Returns Value as ElementRepresentation (or Null if another type)");
	cls_StepFEA_ElementOrElementGroup.def("ElementGroup", (opencascade::handle<StepFEA_ElementGroup> (StepFEA_ElementOrElementGroup::*)() const ) &StepFEA_ElementOrElementGroup::ElementGroup, "Returns Value as ElementGroup (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SequenceOfElementGeometricRelationship.hxx
	bind_NCollection_Sequence<opencascade::handle<StepFEA_ElementGeometricRelationship> >(mod, "StepFEA_SequenceOfElementGeometricRelationship");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfNodeRepresentation.hxx
	bind_NCollection_Array1<opencascade::handle<StepFEA_NodeRepresentation> >(mod, "StepFEA_Array1OfNodeRepresentation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SequenceOfElementRepresentation.hxx
	bind_NCollection_Sequence<opencascade::handle<StepFEA_ElementRepresentation> >(mod, "StepFEA_SequenceOfElementRepresentation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_CurveElementEndCoordinateSystem.hxx
	py::class_<StepFEA_CurveElementEndCoordinateSystem, std::unique_ptr<StepFEA_CurveElementEndCoordinateSystem, Deleter<StepFEA_CurveElementEndCoordinateSystem>>, StepData_SelectType> cls_StepFEA_CurveElementEndCoordinateSystem(mod, "StepFEA_CurveElementEndCoordinateSystem", "Representation of STEP SELECT type CurveElementEndCoordinateSystem");
	cls_StepFEA_CurveElementEndCoordinateSystem.def(py::init<>());
	cls_StepFEA_CurveElementEndCoordinateSystem.def("CaseNum", (Standard_Integer (StepFEA_CurveElementEndCoordinateSystem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_CurveElementEndCoordinateSystem::CaseNum, "Recognizes a kind of CurveElementEndCoordinateSystem select type 1 -> FeaAxis2Placement3d from StepFEA 2 -> AlignedCurve3dElementCoordinateSystem from StepFEA 3 -> ParametricCurve3dElementCoordinateSystem from StepFEA 0 else", py::arg("ent"));
	cls_StepFEA_CurveElementEndCoordinateSystem.def("FeaAxis2Placement3d", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_CurveElementEndCoordinateSystem::*)() const ) &StepFEA_CurveElementEndCoordinateSystem::FeaAxis2Placement3d, "Returns Value as FeaAxis2Placement3d (or Null if another type)");
	cls_StepFEA_CurveElementEndCoordinateSystem.def("AlignedCurve3dElementCoordinateSystem", (opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem> (StepFEA_CurveElementEndCoordinateSystem::*)() const ) &StepFEA_CurveElementEndCoordinateSystem::AlignedCurve3dElementCoordinateSystem, "Returns Value as AlignedCurve3dElementCoordinateSystem (or Null if another type)");
	cls_StepFEA_CurveElementEndCoordinateSystem.def("ParametricCurve3dElementCoordinateSystem", (opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem> (StepFEA_CurveElementEndCoordinateSystem::*)() const ) &StepFEA_CurveElementEndCoordinateSystem::ParametricCurve3dElementCoordinateSystem, "Returns Value as ParametricCurve3dElementCoordinateSystem (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_DegreeOfFreedom.hxx
	py::class_<StepFEA_DegreeOfFreedom, std::unique_ptr<StepFEA_DegreeOfFreedom, Deleter<StepFEA_DegreeOfFreedom>>, StepData_SelectType> cls_StepFEA_DegreeOfFreedom(mod, "StepFEA_DegreeOfFreedom", "Representation of STEP SELECT type DegreeOfFreedom");
	cls_StepFEA_DegreeOfFreedom.def(py::init<>());
	cls_StepFEA_DegreeOfFreedom.def("CaseNum", (Standard_Integer (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_DegreeOfFreedom::CaseNum, "Recognizes a kind of CurveElementFreedom select type return 0", py::arg("ent"));
	cls_StepFEA_DegreeOfFreedom.def("CaseMem", (Standard_Integer (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<StepData_SelectMember> &) const ) &StepFEA_DegreeOfFreedom::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> EnumeratedCurveElementFreedom 2 -> ApplicationDefinedDegreeOfFreedom 0 else", py::arg("ent"));
	cls_StepFEA_DegreeOfFreedom.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_DegreeOfFreedom::*)() const ) &StepFEA_DegreeOfFreedom::NewMember, "Returns a new select member the type CurveElementFreedomMember");
	cls_StepFEA_DegreeOfFreedom.def("SetEnumeratedDegreeOfFreedom", (void (StepFEA_DegreeOfFreedom::*)(const StepFEA_EnumeratedDegreeOfFreedom)) &StepFEA_DegreeOfFreedom::SetEnumeratedDegreeOfFreedom, "Returns Value as EnumeratedDegreeOfFreedom (or Null if another type)", py::arg("aVal"));
	cls_StepFEA_DegreeOfFreedom.def("EnumeratedDegreeOfFreedom", (StepFEA_EnumeratedDegreeOfFreedom (StepFEA_DegreeOfFreedom::*)() const ) &StepFEA_DegreeOfFreedom::EnumeratedDegreeOfFreedom, "Returns Value as EnumeratedDegreeOfFreedom (or Null if another type)");
	cls_StepFEA_DegreeOfFreedom.def("SetApplicationDefinedDegreeOfFreedom", (void (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_DegreeOfFreedom::SetApplicationDefinedDegreeOfFreedom, "Set Value for ApplicationDefinedDegreeOfFreedom", py::arg("aVal"));
	cls_StepFEA_DegreeOfFreedom.def("ApplicationDefinedDegreeOfFreedom", (opencascade::handle<TCollection_HAsciiString> (StepFEA_DegreeOfFreedom::*)() const ) &StepFEA_DegreeOfFreedom::ApplicationDefinedDegreeOfFreedom, "Returns Value as ApplicationDefinedDegreeOfFreedom (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfCurveElementInterval.hxx
	bind_NCollection_Array1<opencascade::handle<StepFEA_CurveElementInterval> >(mod, "StepFEA_Array1OfCurveElementInterval");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfCurveElementEndOffset.hxx
	bind_NCollection_Array1<opencascade::handle<StepFEA_CurveElementEndOffset> >(mod, "StepFEA_Array1OfCurveElementEndOffset");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfCurveElementEndRelease.hxx
	bind_NCollection_Array1<opencascade::handle<StepFEA_CurveElementEndRelease> >(mod, "StepFEA_Array1OfCurveElementEndRelease");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_DegreeOfFreedomMember.hxx
	py::class_<StepFEA_DegreeOfFreedomMember, opencascade::handle<StepFEA_DegreeOfFreedomMember>, StepData_SelectNamed> cls_StepFEA_DegreeOfFreedomMember(mod, "StepFEA_DegreeOfFreedomMember", "Representation of member for STEP SELECT type CurveElementFreedom");
	cls_StepFEA_DegreeOfFreedomMember.def(py::init<>());
	cls_StepFEA_DegreeOfFreedomMember.def("HasName", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)() const ) &StepFEA_DegreeOfFreedomMember::HasName, "Returns True if has name");
	cls_StepFEA_DegreeOfFreedomMember.def("Name", (Standard_CString (StepFEA_DegreeOfFreedomMember::*)() const ) &StepFEA_DegreeOfFreedomMember::Name, "Returns set name");
	cls_StepFEA_DegreeOfFreedomMember.def("SetName", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)(const Standard_CString)) &StepFEA_DegreeOfFreedomMember::SetName, "Set name", py::arg("name"));
	cls_StepFEA_DegreeOfFreedomMember.def("Matches", (Standard_Boolean (StepFEA_DegreeOfFreedomMember::*)(const Standard_CString) const ) &StepFEA_DegreeOfFreedomMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
	cls_StepFEA_DegreeOfFreedomMember.def_static("get_type_name_", (const char * (*)()) &StepFEA_DegreeOfFreedomMember::get_type_name, "None");
	cls_StepFEA_DegreeOfFreedomMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_DegreeOfFreedomMember::get_type_descriptor, "None");
	cls_StepFEA_DegreeOfFreedomMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_DegreeOfFreedomMember::*)() const ) &StepFEA_DegreeOfFreedomMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfElementRepresentation.hxx
	bind_NCollection_Array1<opencascade::handle<StepFEA_ElementRepresentation> >(mod, "StepFEA_Array1OfElementRepresentation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor43d.hxx
	py::class_<StepFEA_SymmetricTensor43d, std::unique_ptr<StepFEA_SymmetricTensor43d, Deleter<StepFEA_SymmetricTensor43d>>, StepData_SelectType> cls_StepFEA_SymmetricTensor43d(mod, "StepFEA_SymmetricTensor43d", "Representation of STEP SELECT type SymmetricTensor43d");
	cls_StepFEA_SymmetricTensor43d.def(py::init<>());
	cls_StepFEA_SymmetricTensor43d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_SymmetricTensor43d::CaseNum, "return 0", py::arg("ent"));
	cls_StepFEA_SymmetricTensor43d.def("CaseMem", (Standard_Integer (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<StepData_SelectMember> &) const ) &StepFEA_SymmetricTensor43d::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> AnisotropicSymmetricTensor43d 2 -> FeaIsotropicSymmetricTensor43d 3 -> FeaIsoOrthotropicSymmetricTensor43d 4 -> FeaTransverseIsotropicSymmetricTensor43d 5 -> FeaColumnNormalisedOrthotropicSymmetricTensor43d 6 -> FeaColumnNormalisedMonoclinicSymmetricTensor43d 0 else", py::arg("ent"));
	cls_StepFEA_SymmetricTensor43d.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::NewMember, "None");
	cls_StepFEA_SymmetricTensor43d.def("AnisotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::AnisotropicSymmetricTensor43d, "Returns Value as AnisotropicSymmetricTensor43d (or Null if another type)");
	cls_StepFEA_SymmetricTensor43d.def("SetFeaIsotropicSymmetricTensor43d", (void (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor43d::SetFeaIsotropicSymmetricTensor43d, "None", py::arg("val"));
	cls_StepFEA_SymmetricTensor43d.def("FeaIsotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::FeaIsotropicSymmetricTensor43d, "Returns Value as FeaIsotropicSymmetricTensor43d (or Null if another type)");
	cls_StepFEA_SymmetricTensor43d.def("FeaIsoOrthotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::FeaIsoOrthotropicSymmetricTensor43d, "Returns Value as FeaIsoOrthotropicSymmetricTensor43d (or Null if another type)");
	cls_StepFEA_SymmetricTensor43d.def("FeaTransverseIsotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::FeaTransverseIsotropicSymmetricTensor43d, "Returns Value as FeaTransverseIsotropicSymmetricTensor43d (or Null if another type)");
	cls_StepFEA_SymmetricTensor43d.def("FeaColumnNormalisedOrthotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::FeaColumnNormalisedOrthotropicSymmetricTensor43d, "Returns Value as FeaColumnNormalisedOrthotropicSymmetricTensor43d (or Null if another type)");
	cls_StepFEA_SymmetricTensor43d.def("FeaColumnNormalisedMonoclinicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const ) &StepFEA_SymmetricTensor43d::FeaColumnNormalisedMonoclinicSymmetricTensor43d, "Returns Value as FeaColumnNormalisedMonoclinicSymmetricTensor43d (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor23d.hxx
	py::class_<StepFEA_SymmetricTensor23d, std::unique_ptr<StepFEA_SymmetricTensor23d, Deleter<StepFEA_SymmetricTensor23d>>, StepData_SelectType> cls_StepFEA_SymmetricTensor23d(mod, "StepFEA_SymmetricTensor23d", "Representation of STEP SELECT type SymmetricTensor23d");
	cls_StepFEA_SymmetricTensor23d.def(py::init<>());
	cls_StepFEA_SymmetricTensor23d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_SymmetricTensor23d::CaseNum, "Recognizes a kind of SymmetricTensor23d select type return 0", py::arg("ent"));
	cls_StepFEA_SymmetricTensor23d.def("CaseMem", (Standard_Integer (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<StepData_SelectMember> &) const ) &StepFEA_SymmetricTensor23d::CaseMem, "Recognizes a items of select member SymmetricTensor23dMember 1 -> IsotropicSymmetricTensor23d 2 -> OrthotropicSymmetricTensor23d 3 -> AnisotropicSymmetricTensor23d 0 else", py::arg("ent"));
	cls_StepFEA_SymmetricTensor23d.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_SymmetricTensor23d::*)() const ) &StepFEA_SymmetricTensor23d::NewMember, "Returns a new select member the type SymmetricTensor23dMember");
	cls_StepFEA_SymmetricTensor23d.def("SetIsotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const Standard_Real)) &StepFEA_SymmetricTensor23d::SetIsotropicSymmetricTensor23d, "Set Value for IsotropicSymmetricTensor23d", py::arg("aVal"));
	cls_StepFEA_SymmetricTensor23d.def("IsotropicSymmetricTensor23d", (Standard_Real (StepFEA_SymmetricTensor23d::*)() const ) &StepFEA_SymmetricTensor23d::IsotropicSymmetricTensor23d, "Returns Value as IsotropicSymmetricTensor23d (or Null if another type)");
	cls_StepFEA_SymmetricTensor23d.def("SetOrthotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor23d::SetOrthotropicSymmetricTensor23d, "Set Value for OrthotropicSymmetricTensor23d", py::arg("aVal"));
	cls_StepFEA_SymmetricTensor23d.def("OrthotropicSymmetricTensor23d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor23d::*)() const ) &StepFEA_SymmetricTensor23d::OrthotropicSymmetricTensor23d, "Returns Value as OrthotropicSymmetricTensor23d (or Null if another type)");
	cls_StepFEA_SymmetricTensor23d.def("SetAnisotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor23d::SetAnisotropicSymmetricTensor23d, "Set Value for AnisotropicSymmetricTensor23d", py::arg("aVal"));
	cls_StepFEA_SymmetricTensor23d.def("AnisotropicSymmetricTensor23d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor23d::*)() const ) &StepFEA_SymmetricTensor23d::AnisotropicSymmetricTensor23d, "Returns Value as AnisotropicSymmetricTensor23d (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor42d.hxx
	py::class_<StepFEA_SymmetricTensor42d, std::unique_ptr<StepFEA_SymmetricTensor42d, Deleter<StepFEA_SymmetricTensor42d>>, StepData_SelectType> cls_StepFEA_SymmetricTensor42d(mod, "StepFEA_SymmetricTensor42d", "Representation of STEP SELECT type SymmetricTensor42d");
	cls_StepFEA_SymmetricTensor42d.def(py::init<>());
	cls_StepFEA_SymmetricTensor42d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor42d::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_SymmetricTensor42d::CaseNum, "Recognizes a kind of SymmetricTensor42d select type 1 -> HArray1OfReal from TColStd 0 else", py::arg("ent"));
	cls_StepFEA_SymmetricTensor42d.def("AnisotropicSymmetricTensor42d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor42d::*)() const ) &StepFEA_SymmetricTensor42d::AnisotropicSymmetricTensor42d, "Returns Value as AnisotropicSymmetricTensor42d (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor22d.hxx
	py::class_<StepFEA_SymmetricTensor22d, std::unique_ptr<StepFEA_SymmetricTensor22d, Deleter<StepFEA_SymmetricTensor22d>>, StepData_SelectType> cls_StepFEA_SymmetricTensor22d(mod, "StepFEA_SymmetricTensor22d", "Representation of STEP SELECT type SymmetricTensor22d");
	cls_StepFEA_SymmetricTensor22d.def(py::init<>());
	cls_StepFEA_SymmetricTensor22d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor22d::*)(const opencascade::handle<Standard_Transient> &) const ) &StepFEA_SymmetricTensor22d::CaseNum, "Recognizes a kind of SymmetricTensor22d select type 1 -> HArray1OfReal from TColStd 0 else", py::arg("ent"));
	cls_StepFEA_SymmetricTensor22d.def("AnisotropicSymmetricTensor22d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor22d::*)() const ) &StepFEA_SymmetricTensor22d::AnisotropicSymmetricTensor22d, "Returns Value as AnisotropicSymmetricTensor22d (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_Array1OfDegreeOfFreedom.hxx
	bind_NCollection_Array1<StepFEA_DegreeOfFreedom>(mod, "StepFEA_Array1OfDegreeOfFreedom");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SequenceOfCurve3dElementProperty.hxx
	bind_NCollection_Sequence<opencascade::handle<StepFEA_Curve3dElementProperty> >(mod, "StepFEA_SequenceOfCurve3dElementProperty");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SequenceOfNodeRepresentation.hxx
	bind_NCollection_Sequence<opencascade::handle<StepFEA_NodeRepresentation> >(mod, "StepFEA_SequenceOfNodeRepresentation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor23dMember.hxx
	py::class_<StepFEA_SymmetricTensor23dMember, opencascade::handle<StepFEA_SymmetricTensor23dMember>, StepData_SelectArrReal> cls_StepFEA_SymmetricTensor23dMember(mod, "StepFEA_SymmetricTensor23dMember", "Representation of member for STEP SELECT type SymmetricTensor23d");
	cls_StepFEA_SymmetricTensor23dMember.def(py::init<>());
	cls_StepFEA_SymmetricTensor23dMember.def("HasName", (Standard_Boolean (StepFEA_SymmetricTensor23dMember::*)() const ) &StepFEA_SymmetricTensor23dMember::HasName, "Returns True if has name");
	cls_StepFEA_SymmetricTensor23dMember.def("Name", (Standard_CString (StepFEA_SymmetricTensor23dMember::*)() const ) &StepFEA_SymmetricTensor23dMember::Name, "Returns set name");
	cls_StepFEA_SymmetricTensor23dMember.def("SetName", (Standard_Boolean (StepFEA_SymmetricTensor23dMember::*)(const Standard_CString)) &StepFEA_SymmetricTensor23dMember::SetName, "Set name", py::arg("name"));
	cls_StepFEA_SymmetricTensor23dMember.def("Matches", (Standard_Boolean (StepFEA_SymmetricTensor23dMember::*)(const Standard_CString) const ) &StepFEA_SymmetricTensor23dMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
	cls_StepFEA_SymmetricTensor23dMember.def_static("get_type_name_", (const char * (*)()) &StepFEA_SymmetricTensor23dMember::get_type_name, "None");
	cls_StepFEA_SymmetricTensor23dMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_SymmetricTensor23dMember::get_type_descriptor, "None");
	cls_StepFEA_SymmetricTensor23dMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_SymmetricTensor23dMember::*)() const ) &StepFEA_SymmetricTensor23dMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_SymmetricTensor43dMember.hxx
	py::class_<StepFEA_SymmetricTensor43dMember, opencascade::handle<StepFEA_SymmetricTensor43dMember>, StepData_SelectArrReal> cls_StepFEA_SymmetricTensor43dMember(mod, "StepFEA_SymmetricTensor43dMember", "Representation of member for STEP SELECT type SymmetricTensor43d");
	cls_StepFEA_SymmetricTensor43dMember.def(py::init<>());
	cls_StepFEA_SymmetricTensor43dMember.def("HasName", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)() const ) &StepFEA_SymmetricTensor43dMember::HasName, "Returns True if has name");
	cls_StepFEA_SymmetricTensor43dMember.def("Name", (Standard_CString (StepFEA_SymmetricTensor43dMember::*)() const ) &StepFEA_SymmetricTensor43dMember::Name, "Returns set name");
	cls_StepFEA_SymmetricTensor43dMember.def("SetName", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)(const Standard_CString)) &StepFEA_SymmetricTensor43dMember::SetName, "Set name", py::arg("name"));
	cls_StepFEA_SymmetricTensor43dMember.def("Matches", (Standard_Boolean (StepFEA_SymmetricTensor43dMember::*)(const Standard_CString) const ) &StepFEA_SymmetricTensor43dMember::Matches, "Tells if the name of a SelectMember matches a given one;", py::arg("name"));
	cls_StepFEA_SymmetricTensor43dMember.def_static("get_type_name_", (const char * (*)()) &StepFEA_SymmetricTensor43dMember::get_type_name, "None");
	cls_StepFEA_SymmetricTensor43dMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_SymmetricTensor43dMember::get_type_descriptor, "None");
	cls_StepFEA_SymmetricTensor43dMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_SymmetricTensor43dMember::*)() const ) &StepFEA_SymmetricTensor43dMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HSequenceOfElementGeometricRelationship.hxx
	py::class_<StepFEA_HSequenceOfElementGeometricRelationship, opencascade::handle<StepFEA_HSequenceOfElementGeometricRelationship>, StepFEA_SequenceOfElementGeometricRelationship, Standard_Transient> cls_StepFEA_HSequenceOfElementGeometricRelationship(mod, "StepFEA_HSequenceOfElementGeometricRelationship", "None");
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def(py::init<>());
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def(py::init<const StepFEA_SequenceOfElementGeometricRelationship &>(), py::arg("theOther"));
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def("Sequence", (const StepFEA_SequenceOfElementGeometricRelationship & (StepFEA_HSequenceOfElementGeometricRelationship::*)() const ) &StepFEA_HSequenceOfElementGeometricRelationship::Sequence, "None");
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def("Append", (void (StepFEA_HSequenceOfElementGeometricRelationship::*)(const StepFEA_SequenceOfElementGeometricRelationship::value_type &)) &StepFEA_HSequenceOfElementGeometricRelationship::Append, "None", py::arg("theItem"));
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def("Append", (void (StepFEA_HSequenceOfElementGeometricRelationship::*)(StepFEA_SequenceOfElementGeometricRelationship &)) &StepFEA_HSequenceOfElementGeometricRelationship::Append, "None", py::arg("theSequence"));
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def("ChangeSequence", (StepFEA_SequenceOfElementGeometricRelationship & (StepFEA_HSequenceOfElementGeometricRelationship::*)()) &StepFEA_HSequenceOfElementGeometricRelationship::ChangeSequence, "None");
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def_static("get_type_name_", (const char * (*)()) &StepFEA_HSequenceOfElementGeometricRelationship::get_type_name, "None");
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HSequenceOfElementGeometricRelationship::get_type_descriptor, "None");
	cls_StepFEA_HSequenceOfElementGeometricRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HSequenceOfElementGeometricRelationship::*)() const ) &StepFEA_HSequenceOfElementGeometricRelationship::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfNodeRepresentation.hxx
	py::class_<StepFEA_HArray1OfNodeRepresentation, opencascade::handle<StepFEA_HArray1OfNodeRepresentation>, StepFEA_Array1OfNodeRepresentation, Standard_Transient> cls_StepFEA_HArray1OfNodeRepresentation(mod, "StepFEA_HArray1OfNodeRepresentation", "None");
	cls_StepFEA_HArray1OfNodeRepresentation.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfNodeRepresentation.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfNodeRepresentation::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfNodeRepresentation.def(py::init<const StepFEA_Array1OfNodeRepresentation &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfNodeRepresentation.def("Array1", (const StepFEA_Array1OfNodeRepresentation & (StepFEA_HArray1OfNodeRepresentation::*)() const ) &StepFEA_HArray1OfNodeRepresentation::Array1, "None");
	cls_StepFEA_HArray1OfNodeRepresentation.def("ChangeArray1", (StepFEA_Array1OfNodeRepresentation & (StepFEA_HArray1OfNodeRepresentation::*)()) &StepFEA_HArray1OfNodeRepresentation::ChangeArray1, "None");
	cls_StepFEA_HArray1OfNodeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfNodeRepresentation::get_type_name, "None");
	cls_StepFEA_HArray1OfNodeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfNodeRepresentation::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfNodeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfNodeRepresentation::*)() const ) &StepFEA_HArray1OfNodeRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HSequenceOfElementRepresentation.hxx
	py::class_<StepFEA_HSequenceOfElementRepresentation, opencascade::handle<StepFEA_HSequenceOfElementRepresentation>, StepFEA_SequenceOfElementRepresentation, Standard_Transient> cls_StepFEA_HSequenceOfElementRepresentation(mod, "StepFEA_HSequenceOfElementRepresentation", "None");
	cls_StepFEA_HSequenceOfElementRepresentation.def(py::init<>());
	cls_StepFEA_HSequenceOfElementRepresentation.def(py::init<const StepFEA_SequenceOfElementRepresentation &>(), py::arg("theOther"));
	cls_StepFEA_HSequenceOfElementRepresentation.def("Sequence", (const StepFEA_SequenceOfElementRepresentation & (StepFEA_HSequenceOfElementRepresentation::*)() const ) &StepFEA_HSequenceOfElementRepresentation::Sequence, "None");
	cls_StepFEA_HSequenceOfElementRepresentation.def("Append", (void (StepFEA_HSequenceOfElementRepresentation::*)(const StepFEA_SequenceOfElementRepresentation::value_type &)) &StepFEA_HSequenceOfElementRepresentation::Append, "None", py::arg("theItem"));
	cls_StepFEA_HSequenceOfElementRepresentation.def("Append", (void (StepFEA_HSequenceOfElementRepresentation::*)(StepFEA_SequenceOfElementRepresentation &)) &StepFEA_HSequenceOfElementRepresentation::Append, "None", py::arg("theSequence"));
	cls_StepFEA_HSequenceOfElementRepresentation.def("ChangeSequence", (StepFEA_SequenceOfElementRepresentation & (StepFEA_HSequenceOfElementRepresentation::*)()) &StepFEA_HSequenceOfElementRepresentation::ChangeSequence, "None");
	cls_StepFEA_HSequenceOfElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_HSequenceOfElementRepresentation::get_type_name, "None");
	cls_StepFEA_HSequenceOfElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HSequenceOfElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_HSequenceOfElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HSequenceOfElementRepresentation::*)() const ) &StepFEA_HSequenceOfElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfCurveElementEndOffset.hxx
	py::class_<StepFEA_HArray1OfCurveElementEndOffset, opencascade::handle<StepFEA_HArray1OfCurveElementEndOffset>, StepFEA_Array1OfCurveElementEndOffset, Standard_Transient> cls_StepFEA_HArray1OfCurveElementEndOffset(mod, "StepFEA_HArray1OfCurveElementEndOffset", "None");
	cls_StepFEA_HArray1OfCurveElementEndOffset.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfCurveElementEndOffset.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfCurveElementEndOffset::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfCurveElementEndOffset.def(py::init<const StepFEA_Array1OfCurveElementEndOffset &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfCurveElementEndOffset.def("Array1", (const StepFEA_Array1OfCurveElementEndOffset & (StepFEA_HArray1OfCurveElementEndOffset::*)() const ) &StepFEA_HArray1OfCurveElementEndOffset::Array1, "None");
	cls_StepFEA_HArray1OfCurveElementEndOffset.def("ChangeArray1", (StepFEA_Array1OfCurveElementEndOffset & (StepFEA_HArray1OfCurveElementEndOffset::*)()) &StepFEA_HArray1OfCurveElementEndOffset::ChangeArray1, "None");
	cls_StepFEA_HArray1OfCurveElementEndOffset.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfCurveElementEndOffset::get_type_name, "None");
	cls_StepFEA_HArray1OfCurveElementEndOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfCurveElementEndOffset::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfCurveElementEndOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfCurveElementEndOffset::*)() const ) &StepFEA_HArray1OfCurveElementEndOffset::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfCurveElementEndRelease.hxx
	py::class_<StepFEA_HArray1OfCurveElementEndRelease, opencascade::handle<StepFEA_HArray1OfCurveElementEndRelease>, StepFEA_Array1OfCurveElementEndRelease, Standard_Transient> cls_StepFEA_HArray1OfCurveElementEndRelease(mod, "StepFEA_HArray1OfCurveElementEndRelease", "None");
	cls_StepFEA_HArray1OfCurveElementEndRelease.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfCurveElementEndRelease.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfCurveElementEndRelease::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfCurveElementEndRelease.def(py::init<const StepFEA_Array1OfCurveElementEndRelease &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfCurveElementEndRelease.def("Array1", (const StepFEA_Array1OfCurveElementEndRelease & (StepFEA_HArray1OfCurveElementEndRelease::*)() const ) &StepFEA_HArray1OfCurveElementEndRelease::Array1, "None");
	cls_StepFEA_HArray1OfCurveElementEndRelease.def("ChangeArray1", (StepFEA_Array1OfCurveElementEndRelease & (StepFEA_HArray1OfCurveElementEndRelease::*)()) &StepFEA_HArray1OfCurveElementEndRelease::ChangeArray1, "None");
	cls_StepFEA_HArray1OfCurveElementEndRelease.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfCurveElementEndRelease::get_type_name, "None");
	cls_StepFEA_HArray1OfCurveElementEndRelease.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfCurveElementEndRelease::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfCurveElementEndRelease.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfCurveElementEndRelease::*)() const ) &StepFEA_HArray1OfCurveElementEndRelease::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfCurveElementInterval.hxx
	py::class_<StepFEA_HArray1OfCurveElementInterval, opencascade::handle<StepFEA_HArray1OfCurveElementInterval>, StepFEA_Array1OfCurveElementInterval, Standard_Transient> cls_StepFEA_HArray1OfCurveElementInterval(mod, "StepFEA_HArray1OfCurveElementInterval", "None");
	cls_StepFEA_HArray1OfCurveElementInterval.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfCurveElementInterval.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfCurveElementInterval::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfCurveElementInterval.def(py::init<const StepFEA_Array1OfCurveElementInterval &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfCurveElementInterval.def("Array1", (const StepFEA_Array1OfCurveElementInterval & (StepFEA_HArray1OfCurveElementInterval::*)() const ) &StepFEA_HArray1OfCurveElementInterval::Array1, "None");
	cls_StepFEA_HArray1OfCurveElementInterval.def("ChangeArray1", (StepFEA_Array1OfCurveElementInterval & (StepFEA_HArray1OfCurveElementInterval::*)()) &StepFEA_HArray1OfCurveElementInterval::ChangeArray1, "None");
	cls_StepFEA_HArray1OfCurveElementInterval.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfCurveElementInterval::get_type_name, "None");
	cls_StepFEA_HArray1OfCurveElementInterval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfCurveElementInterval::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfCurveElementInterval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfCurveElementInterval::*)() const ) &StepFEA_HArray1OfCurveElementInterval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfDegreeOfFreedom.hxx
	py::class_<StepFEA_HArray1OfDegreeOfFreedom, opencascade::handle<StepFEA_HArray1OfDegreeOfFreedom>, StepFEA_Array1OfDegreeOfFreedom, Standard_Transient> cls_StepFEA_HArray1OfDegreeOfFreedom(mod, "StepFEA_HArray1OfDegreeOfFreedom", "None");
	cls_StepFEA_HArray1OfDegreeOfFreedom.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfDegreeOfFreedom.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfDegreeOfFreedom::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfDegreeOfFreedom.def(py::init<const StepFEA_Array1OfDegreeOfFreedom &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfDegreeOfFreedom.def("Array1", (const StepFEA_Array1OfDegreeOfFreedom & (StepFEA_HArray1OfDegreeOfFreedom::*)() const ) &StepFEA_HArray1OfDegreeOfFreedom::Array1, "None");
	cls_StepFEA_HArray1OfDegreeOfFreedom.def("ChangeArray1", (StepFEA_Array1OfDegreeOfFreedom & (StepFEA_HArray1OfDegreeOfFreedom::*)()) &StepFEA_HArray1OfDegreeOfFreedom::ChangeArray1, "None");
	cls_StepFEA_HArray1OfDegreeOfFreedom.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfDegreeOfFreedom::get_type_name, "None");
	cls_StepFEA_HArray1OfDegreeOfFreedom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfDegreeOfFreedom::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfDegreeOfFreedom.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfDegreeOfFreedom::*)() const ) &StepFEA_HArray1OfDegreeOfFreedom::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HArray1OfElementRepresentation.hxx
	py::class_<StepFEA_HArray1OfElementRepresentation, opencascade::handle<StepFEA_HArray1OfElementRepresentation>, StepFEA_Array1OfElementRepresentation, Standard_Transient> cls_StepFEA_HArray1OfElementRepresentation(mod, "StepFEA_HArray1OfElementRepresentation", "None");
	cls_StepFEA_HArray1OfElementRepresentation.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepFEA_HArray1OfElementRepresentation.def(py::init<const Standard_Integer, const Standard_Integer, const StepFEA_Array1OfElementRepresentation::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepFEA_HArray1OfElementRepresentation.def(py::init<const StepFEA_Array1OfElementRepresentation &>(), py::arg("theOther"));
	cls_StepFEA_HArray1OfElementRepresentation.def("Array1", (const StepFEA_Array1OfElementRepresentation & (StepFEA_HArray1OfElementRepresentation::*)() const ) &StepFEA_HArray1OfElementRepresentation::Array1, "None");
	cls_StepFEA_HArray1OfElementRepresentation.def("ChangeArray1", (StepFEA_Array1OfElementRepresentation & (StepFEA_HArray1OfElementRepresentation::*)()) &StepFEA_HArray1OfElementRepresentation::ChangeArray1, "None");
	cls_StepFEA_HArray1OfElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_HArray1OfElementRepresentation::get_type_name, "None");
	cls_StepFEA_HArray1OfElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HArray1OfElementRepresentation::get_type_descriptor, "None");
	cls_StepFEA_HArray1OfElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HArray1OfElementRepresentation::*)() const ) &StepFEA_HArray1OfElementRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HSequenceOfCurve3dElementProperty.hxx
	py::class_<StepFEA_HSequenceOfCurve3dElementProperty, opencascade::handle<StepFEA_HSequenceOfCurve3dElementProperty>, StepFEA_SequenceOfCurve3dElementProperty, Standard_Transient> cls_StepFEA_HSequenceOfCurve3dElementProperty(mod, "StepFEA_HSequenceOfCurve3dElementProperty", "None");
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def(py::init<>());
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def(py::init<const StepFEA_SequenceOfCurve3dElementProperty &>(), py::arg("theOther"));
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def("Sequence", (const StepFEA_SequenceOfCurve3dElementProperty & (StepFEA_HSequenceOfCurve3dElementProperty::*)() const ) &StepFEA_HSequenceOfCurve3dElementProperty::Sequence, "None");
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def("Append", (void (StepFEA_HSequenceOfCurve3dElementProperty::*)(const StepFEA_SequenceOfCurve3dElementProperty::value_type &)) &StepFEA_HSequenceOfCurve3dElementProperty::Append, "None", py::arg("theItem"));
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def("Append", (void (StepFEA_HSequenceOfCurve3dElementProperty::*)(StepFEA_SequenceOfCurve3dElementProperty &)) &StepFEA_HSequenceOfCurve3dElementProperty::Append, "None", py::arg("theSequence"));
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def("ChangeSequence", (StepFEA_SequenceOfCurve3dElementProperty & (StepFEA_HSequenceOfCurve3dElementProperty::*)()) &StepFEA_HSequenceOfCurve3dElementProperty::ChangeSequence, "None");
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def_static("get_type_name_", (const char * (*)()) &StepFEA_HSequenceOfCurve3dElementProperty::get_type_name, "None");
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HSequenceOfCurve3dElementProperty::get_type_descriptor, "None");
	cls_StepFEA_HSequenceOfCurve3dElementProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HSequenceOfCurve3dElementProperty::*)() const ) &StepFEA_HSequenceOfCurve3dElementProperty::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFEA_HSequenceOfNodeRepresentation.hxx
	py::class_<StepFEA_HSequenceOfNodeRepresentation, opencascade::handle<StepFEA_HSequenceOfNodeRepresentation>, StepFEA_SequenceOfNodeRepresentation, Standard_Transient> cls_StepFEA_HSequenceOfNodeRepresentation(mod, "StepFEA_HSequenceOfNodeRepresentation", "None");
	cls_StepFEA_HSequenceOfNodeRepresentation.def(py::init<>());
	cls_StepFEA_HSequenceOfNodeRepresentation.def(py::init<const StepFEA_SequenceOfNodeRepresentation &>(), py::arg("theOther"));
	cls_StepFEA_HSequenceOfNodeRepresentation.def("Sequence", (const StepFEA_SequenceOfNodeRepresentation & (StepFEA_HSequenceOfNodeRepresentation::*)() const ) &StepFEA_HSequenceOfNodeRepresentation::Sequence, "None");
	cls_StepFEA_HSequenceOfNodeRepresentation.def("Append", (void (StepFEA_HSequenceOfNodeRepresentation::*)(const StepFEA_SequenceOfNodeRepresentation::value_type &)) &StepFEA_HSequenceOfNodeRepresentation::Append, "None", py::arg("theItem"));
	cls_StepFEA_HSequenceOfNodeRepresentation.def("Append", (void (StepFEA_HSequenceOfNodeRepresentation::*)(StepFEA_SequenceOfNodeRepresentation &)) &StepFEA_HSequenceOfNodeRepresentation::Append, "None", py::arg("theSequence"));
	cls_StepFEA_HSequenceOfNodeRepresentation.def("ChangeSequence", (StepFEA_SequenceOfNodeRepresentation & (StepFEA_HSequenceOfNodeRepresentation::*)()) &StepFEA_HSequenceOfNodeRepresentation::ChangeSequence, "None");
	cls_StepFEA_HSequenceOfNodeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_HSequenceOfNodeRepresentation::get_type_name, "None");
	cls_StepFEA_HSequenceOfNodeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HSequenceOfNodeRepresentation::get_type_descriptor, "None");
	cls_StepFEA_HSequenceOfNodeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HSequenceOfNodeRepresentation::*)() const ) &StepFEA_HSequenceOfNodeRepresentation::DynamicType, "None");


}
