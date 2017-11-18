#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepShape_AdvancedBrepShapeRepresentation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepShape_RWAdvancedBrepShapeRepresentation.hxx>
#include <StepShape_AdvancedFace.hxx>
#include <RWStepShape_RWAdvancedFace.hxx>
#include <StepShape_AngularLocation.hxx>
#include <RWStepShape_RWAngularLocation.hxx>
#include <StepShape_AngularSize.hxx>
#include <RWStepShape_RWAngularSize.hxx>
#include <StepShape_Block.hxx>
#include <RWStepShape_RWBlock.hxx>
#include <StepShape_BooleanResult.hxx>
#include <RWStepShape_RWBooleanResult.hxx>
#include <StepShape_BoxDomain.hxx>
#include <RWStepShape_RWBoxDomain.hxx>
#include <StepShape_BoxedHalfSpace.hxx>
#include <RWStepShape_RWBoxedHalfSpace.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <Interface_ShareTool.hxx>
#include <RWStepShape_RWBrepWithVoids.hxx>
#include <StepShape_ClosedShell.hxx>
#include <RWStepShape_RWClosedShell.hxx>
#include <StepShape_CompoundShapeRepresentation.hxx>
#include <RWStepShape_RWCompoundShapeRepresentation.hxx>
#include <StepShape_ConnectedEdgeSet.hxx>
#include <RWStepShape_RWConnectedEdgeSet.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <RWStepShape_RWConnectedFaceSet.hxx>
#include <StepShape_ConnectedFaceShapeRepresentation.hxx>
#include <RWStepShape_RWConnectedFaceShapeRepresentation.hxx>
#include <StepShape_ConnectedFaceSubSet.hxx>
#include <RWStepShape_RWConnectedFaceSubSet.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <RWStepShape_RWContextDependentShapeRepresentation.hxx>
#include <StepShape_CsgShapeRepresentation.hxx>
#include <RWStepShape_RWCsgShapeRepresentation.hxx>
#include <StepShape_CsgSolid.hxx>
#include <RWStepShape_RWCsgSolid.hxx>
#include <StepShape_DefinitionalRepresentationAndShapeRepresentation.hxx>
#include <RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.hxx>
#include <StepShape_DimensionalCharacteristicRepresentation.hxx>
#include <RWStepShape_RWDimensionalCharacteristicRepresentation.hxx>
#include <StepShape_DimensionalLocation.hxx>
#include <RWStepShape_RWDimensionalLocation.hxx>
#include <StepShape_DimensionalLocationWithPath.hxx>
#include <RWStepShape_RWDimensionalLocationWithPath.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <RWStepShape_RWDimensionalSize.hxx>
#include <StepShape_DimensionalSizeWithPath.hxx>
#include <RWStepShape_RWDimensionalSizeWithPath.hxx>
#include <StepShape_Edge.hxx>
#include <RWStepShape_RWEdge.hxx>
#include <StepShape_EdgeBasedWireframeModel.hxx>
#include <RWStepShape_RWEdgeBasedWireframeModel.hxx>
#include <StepShape_EdgeBasedWireframeShapeRepresentation.hxx>
#include <RWStepShape_RWEdgeBasedWireframeShapeRepresentation.hxx>
#include <StepShape_EdgeCurve.hxx>
#include <RWStepShape_RWEdgeCurve.hxx>
#include <StepShape_EdgeLoop.hxx>
#include <RWStepShape_RWEdgeLoop.hxx>
#include <StepShape_ExtrudedAreaSolid.hxx>
#include <RWStepShape_RWExtrudedAreaSolid.hxx>
#include <StepShape_ExtrudedFaceSolid.hxx>
#include <RWStepShape_RWExtrudedFaceSolid.hxx>
#include <StepShape_Face.hxx>
#include <RWStepShape_RWFace.hxx>
#include <StepShape_FaceBasedSurfaceModel.hxx>
#include <RWStepShape_RWFaceBasedSurfaceModel.hxx>
#include <StepShape_FaceBound.hxx>
#include <RWStepShape_RWFaceBound.hxx>
#include <StepShape_FaceOuterBound.hxx>
#include <RWStepShape_RWFaceOuterBound.hxx>
#include <StepShape_FaceSurface.hxx>
#include <RWStepShape_RWFaceSurface.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <RWStepShape_RWFacetedBrep.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <RWStepShape_RWFacetedBrepAndBrepWithVoids.hxx>
#include <StepShape_FacetedBrepShapeRepresentation.hxx>
#include <RWStepShape_RWFacetedBrepShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedSurfaceShapeRepresentation.hxx>
#include <RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedWireframeShapeRepresentation.hxx>
#include <RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.hxx>
#include <StepShape_GeometricCurveSet.hxx>
#include <RWStepShape_RWGeometricCurveSet.hxx>
#include <StepShape_GeometricSet.hxx>
#include <RWStepShape_RWGeometricSet.hxx>
#include <StepShape_HalfSpaceSolid.hxx>
#include <RWStepShape_RWHalfSpaceSolid.hxx>
#include <StepShape_LimitsAndFits.hxx>
#include <RWStepShape_RWLimitsAndFits.hxx>
#include <StepShape_Loop.hxx>
#include <RWStepShape_RWLoop.hxx>
#include <StepShape_LoopAndPath.hxx>
#include <RWStepShape_RWLoopAndPath.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <RWStepShape_RWManifoldSolidBrep.hxx>
#include <StepShape_ManifoldSurfaceShapeRepresentation.hxx>
#include <RWStepShape_RWManifoldSurfaceShapeRepresentation.hxx>
#include <StepShape_MeasureQualification.hxx>
#include <RWStepShape_RWMeasureQualification.hxx>
#include <StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.hxx>
#include <RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.hxx>
#include <StepShape_NonManifoldSurfaceShapeRepresentation.hxx>
#include <RWStepShape_RWNonManifoldSurfaceShapeRepresentation.hxx>
#include <StepShape_OpenShell.hxx>
#include <RWStepShape_RWOpenShell.hxx>
#include <StepShape_OrientedClosedShell.hxx>
#include <RWStepShape_RWOrientedClosedShell.hxx>
#include <StepShape_OrientedEdge.hxx>
#include <RWStepShape_RWOrientedEdge.hxx>
#include <StepShape_OrientedFace.hxx>
#include <RWStepShape_RWOrientedFace.hxx>
#include <StepShape_OrientedOpenShell.hxx>
#include <RWStepShape_RWOrientedOpenShell.hxx>
#include <StepShape_OrientedPath.hxx>
#include <RWStepShape_RWOrientedPath.hxx>
#include <StepShape_Path.hxx>
#include <RWStepShape_RWPath.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <RWStepShape_RWPlusMinusTolerance.hxx>
#include <StepShape_PointRepresentation.hxx>
#include <RWStepShape_RWPointRepresentation.hxx>
#include <StepShape_PolyLoop.hxx>
#include <RWStepShape_RWPolyLoop.hxx>
#include <StepShape_PrecisionQualifier.hxx>
#include <RWStepShape_RWPrecisionQualifier.hxx>
#include <StepShape_QualifiedRepresentationItem.hxx>
#include <RWStepShape_RWQualifiedRepresentationItem.hxx>
#include <StepShape_RevolvedAreaSolid.hxx>
#include <RWStepShape_RWRevolvedAreaSolid.hxx>
#include <StepShape_RevolvedFaceSolid.hxx>
#include <RWStepShape_RWRevolvedFaceSolid.hxx>
#include <StepShape_RightAngularWedge.hxx>
#include <RWStepShape_RWRightAngularWedge.hxx>
#include <StepShape_RightCircularCone.hxx>
#include <RWStepShape_RWRightCircularCone.hxx>
#include <StepShape_RightCircularCylinder.hxx>
#include <RWStepShape_RWRightCircularCylinder.hxx>
#include <StepShape_SeamEdge.hxx>
#include <RWStepShape_RWSeamEdge.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <RWStepShape_RWShapeDefinitionRepresentation.hxx>
#include <StepShape_ShapeDimensionRepresentation.hxx>
#include <RWStepShape_RWShapeDimensionRepresentation.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <RWStepShape_RWShapeRepresentation.hxx>
#include <StepShape_ShapeRepresentationWithParameters.hxx>
#include <RWStepShape_RWShapeRepresentationWithParameters.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <RWStepShape_RWShellBasedSurfaceModel.hxx>
#include <StepShape_SolidModel.hxx>
#include <RWStepShape_RWSolidModel.hxx>
#include <StepShape_SolidReplica.hxx>
#include <RWStepShape_RWSolidReplica.hxx>
#include <StepShape_Sphere.hxx>
#include <RWStepShape_RWSphere.hxx>
#include <StepShape_Subedge.hxx>
#include <RWStepShape_RWSubedge.hxx>
#include <StepShape_Subface.hxx>
#include <RWStepShape_RWSubface.hxx>
#include <StepShape_SweptAreaSolid.hxx>
#include <RWStepShape_RWSweptAreaSolid.hxx>
#include <StepShape_SweptFaceSolid.hxx>
#include <RWStepShape_RWSweptFaceSolid.hxx>
#include <StepShape_ToleranceValue.hxx>
#include <RWStepShape_RWToleranceValue.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <RWStepShape_RWTopologicalRepresentationItem.hxx>
#include <StepShape_Torus.hxx>
#include <RWStepShape_RWTorus.hxx>
#include <StepShape_TransitionalShapeRepresentation.hxx>
#include <RWStepShape_RWTransitionalShapeRepresentation.hxx>
#include <StepShape_TypeQualifier.hxx>
#include <RWStepShape_RWTypeQualifier.hxx>
#include <StepShape_ValueFormatTypeQualifier.hxx>
#include <RWStepShape_RWValueFormatTypeQualifier.hxx>
#include <StepShape_Vertex.hxx>
#include <RWStepShape_RWVertex.hxx>
#include <StepShape_VertexLoop.hxx>
#include <RWStepShape_RWVertexLoop.hxx>
#include <StepShape_VertexPoint.hxx>
#include <RWStepShape_RWVertexPoint.hxx>

PYBIND11_MODULE(RWStepShape, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepShape");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWAdvancedBrepShapeRepresentation.hxx
	py::class_<RWStepShape_RWAdvancedBrepShapeRepresentation, std::unique_ptr<RWStepShape_RWAdvancedBrepShapeRepresentation, Deleter<RWStepShape_RWAdvancedBrepShapeRepresentation>>> cls_RWStepShape_RWAdvancedBrepShapeRepresentation(mod, "RWStepShape_RWAdvancedBrepShapeRepresentation", "Read & Write Module for AdvancedBrepShapeRepresentation");
	cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("ReadStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const ) &RWStepShape_RWAdvancedBrepShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("WriteStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const ) &RWStepShape_RWAdvancedBrepShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("Share", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWAdvancedBrepShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWAdvancedFace.hxx
	py::class_<RWStepShape_RWAdvancedFace, std::unique_ptr<RWStepShape_RWAdvancedFace, Deleter<RWStepShape_RWAdvancedFace>>> cls_RWStepShape_RWAdvancedFace(mod, "RWStepShape_RWAdvancedFace", "Read & Write Module for AdvancedFace");
	cls_RWStepShape_RWAdvancedFace.def(py::init<>());
	cls_RWStepShape_RWAdvancedFace.def("ReadStep", (void (RWStepShape_RWAdvancedFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AdvancedFace> &) const ) &RWStepShape_RWAdvancedFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWAdvancedFace.def("WriteStep", (void (RWStepShape_RWAdvancedFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AdvancedFace> &) const ) &RWStepShape_RWAdvancedFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWAdvancedFace.def("Share", (void (RWStepShape_RWAdvancedFace::*)(const opencascade::handle<StepShape_AdvancedFace> &, Interface_EntityIterator &) const ) &RWStepShape_RWAdvancedFace::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWAngularLocation.hxx
	py::class_<RWStepShape_RWAngularLocation, std::unique_ptr<RWStepShape_RWAngularLocation, Deleter<RWStepShape_RWAngularLocation>>> cls_RWStepShape_RWAngularLocation(mod, "RWStepShape_RWAngularLocation", "Read & Write tool for AngularLocation");
	cls_RWStepShape_RWAngularLocation.def(py::init<>());
	cls_RWStepShape_RWAngularLocation.def("ReadStep", (void (RWStepShape_RWAngularLocation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AngularLocation> &) const ) &RWStepShape_RWAngularLocation::ReadStep, "Reads AngularLocation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWAngularLocation.def("WriteStep", (void (RWStepShape_RWAngularLocation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AngularLocation> &) const ) &RWStepShape_RWAngularLocation::WriteStep, "Writes AngularLocation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWAngularLocation.def("Share", (void (RWStepShape_RWAngularLocation::*)(const opencascade::handle<StepShape_AngularLocation> &, Interface_EntityIterator &) const ) &RWStepShape_RWAngularLocation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWAngularSize.hxx
	py::class_<RWStepShape_RWAngularSize, std::unique_ptr<RWStepShape_RWAngularSize, Deleter<RWStepShape_RWAngularSize>>> cls_RWStepShape_RWAngularSize(mod, "RWStepShape_RWAngularSize", "Read & Write tool for AngularSize");
	cls_RWStepShape_RWAngularSize.def(py::init<>());
	cls_RWStepShape_RWAngularSize.def("ReadStep", (void (RWStepShape_RWAngularSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AngularSize> &) const ) &RWStepShape_RWAngularSize::ReadStep, "Reads AngularSize", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWAngularSize.def("WriteStep", (void (RWStepShape_RWAngularSize::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AngularSize> &) const ) &RWStepShape_RWAngularSize::WriteStep, "Writes AngularSize", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWAngularSize.def("Share", (void (RWStepShape_RWAngularSize::*)(const opencascade::handle<StepShape_AngularSize> &, Interface_EntityIterator &) const ) &RWStepShape_RWAngularSize::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWBlock.hxx
	py::class_<RWStepShape_RWBlock, std::unique_ptr<RWStepShape_RWBlock, Deleter<RWStepShape_RWBlock>>> cls_RWStepShape_RWBlock(mod, "RWStepShape_RWBlock", "Read & Write Module for Block");
	cls_RWStepShape_RWBlock.def(py::init<>());
	cls_RWStepShape_RWBlock.def("ReadStep", (void (RWStepShape_RWBlock::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Block> &) const ) &RWStepShape_RWBlock::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWBlock.def("WriteStep", (void (RWStepShape_RWBlock::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Block> &) const ) &RWStepShape_RWBlock::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWBlock.def("Share", (void (RWStepShape_RWBlock::*)(const opencascade::handle<StepShape_Block> &, Interface_EntityIterator &) const ) &RWStepShape_RWBlock::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWBooleanResult.hxx
	py::class_<RWStepShape_RWBooleanResult, std::unique_ptr<RWStepShape_RWBooleanResult, Deleter<RWStepShape_RWBooleanResult>>> cls_RWStepShape_RWBooleanResult(mod, "RWStepShape_RWBooleanResult", "Read & Write Module for BooleanResult");
	cls_RWStepShape_RWBooleanResult.def(py::init<>());
	cls_RWStepShape_RWBooleanResult.def("ReadStep", (void (RWStepShape_RWBooleanResult::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BooleanResult> &) const ) &RWStepShape_RWBooleanResult::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWBooleanResult.def("WriteStep", (void (RWStepShape_RWBooleanResult::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BooleanResult> &) const ) &RWStepShape_RWBooleanResult::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWBooleanResult.def("Share", (void (RWStepShape_RWBooleanResult::*)(const opencascade::handle<StepShape_BooleanResult> &, Interface_EntityIterator &) const ) &RWStepShape_RWBooleanResult::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWBoxDomain.hxx
	py::class_<RWStepShape_RWBoxDomain, std::unique_ptr<RWStepShape_RWBoxDomain, Deleter<RWStepShape_RWBoxDomain>>> cls_RWStepShape_RWBoxDomain(mod, "RWStepShape_RWBoxDomain", "Read & Write Module for BoxDomain");
	cls_RWStepShape_RWBoxDomain.def(py::init<>());
	cls_RWStepShape_RWBoxDomain.def("ReadStep", (void (RWStepShape_RWBoxDomain::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BoxDomain> &) const ) &RWStepShape_RWBoxDomain::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWBoxDomain.def("WriteStep", (void (RWStepShape_RWBoxDomain::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BoxDomain> &) const ) &RWStepShape_RWBoxDomain::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWBoxDomain.def("Share", (void (RWStepShape_RWBoxDomain::*)(const opencascade::handle<StepShape_BoxDomain> &, Interface_EntityIterator &) const ) &RWStepShape_RWBoxDomain::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWBoxedHalfSpace.hxx
	py::class_<RWStepShape_RWBoxedHalfSpace, std::unique_ptr<RWStepShape_RWBoxedHalfSpace, Deleter<RWStepShape_RWBoxedHalfSpace>>> cls_RWStepShape_RWBoxedHalfSpace(mod, "RWStepShape_RWBoxedHalfSpace", "Read & Write Module for BoxedHalfSpace");
	cls_RWStepShape_RWBoxedHalfSpace.def(py::init<>());
	cls_RWStepShape_RWBoxedHalfSpace.def("ReadStep", (void (RWStepShape_RWBoxedHalfSpace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BoxedHalfSpace> &) const ) &RWStepShape_RWBoxedHalfSpace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWBoxedHalfSpace.def("WriteStep", (void (RWStepShape_RWBoxedHalfSpace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BoxedHalfSpace> &) const ) &RWStepShape_RWBoxedHalfSpace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWBoxedHalfSpace.def("Share", (void (RWStepShape_RWBoxedHalfSpace::*)(const opencascade::handle<StepShape_BoxedHalfSpace> &, Interface_EntityIterator &) const ) &RWStepShape_RWBoxedHalfSpace::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWBrepWithVoids.hxx
	py::class_<RWStepShape_RWBrepWithVoids, std::unique_ptr<RWStepShape_RWBrepWithVoids, Deleter<RWStepShape_RWBrepWithVoids>>> cls_RWStepShape_RWBrepWithVoids(mod, "RWStepShape_RWBrepWithVoids", "Read & Write Module for BrepWithVoids");
	cls_RWStepShape_RWBrepWithVoids.def(py::init<>());
	cls_RWStepShape_RWBrepWithVoids.def("ReadStep", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BrepWithVoids> &) const ) &RWStepShape_RWBrepWithVoids::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWBrepWithVoids.def("WriteStep", (void (RWStepShape_RWBrepWithVoids::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BrepWithVoids> &) const ) &RWStepShape_RWBrepWithVoids::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWBrepWithVoids.def("Share", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &, Interface_EntityIterator &) const ) &RWStepShape_RWBrepWithVoids::Share, "None", py::arg("ent"), py::arg("iter"));
	cls_RWStepShape_RWBrepWithVoids.def("Check", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &RWStepShape_RWBrepWithVoids::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWClosedShell.hxx
	py::class_<RWStepShape_RWClosedShell, std::unique_ptr<RWStepShape_RWClosedShell, Deleter<RWStepShape_RWClosedShell>>> cls_RWStepShape_RWClosedShell(mod, "RWStepShape_RWClosedShell", "Read & Write Module for ClosedShell");
	cls_RWStepShape_RWClosedShell.def(py::init<>());
	cls_RWStepShape_RWClosedShell.def("ReadStep", (void (RWStepShape_RWClosedShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ClosedShell> &) const ) &RWStepShape_RWClosedShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWClosedShell.def("WriteStep", (void (RWStepShape_RWClosedShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ClosedShell> &) const ) &RWStepShape_RWClosedShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWClosedShell.def("Share", (void (RWStepShape_RWClosedShell::*)(const opencascade::handle<StepShape_ClosedShell> &, Interface_EntityIterator &) const ) &RWStepShape_RWClosedShell::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWCompoundShapeRepresentation.hxx
	py::class_<RWStepShape_RWCompoundShapeRepresentation, std::unique_ptr<RWStepShape_RWCompoundShapeRepresentation, Deleter<RWStepShape_RWCompoundShapeRepresentation>>> cls_RWStepShape_RWCompoundShapeRepresentation(mod, "RWStepShape_RWCompoundShapeRepresentation", "Read & Write tool for CompoundShapeRepresentation");
	cls_RWStepShape_RWCompoundShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWCompoundShapeRepresentation.def("ReadStep", (void (RWStepShape_RWCompoundShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CompoundShapeRepresentation> &) const ) &RWStepShape_RWCompoundShapeRepresentation::ReadStep, "Reads CompoundShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWCompoundShapeRepresentation.def("WriteStep", (void (RWStepShape_RWCompoundShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CompoundShapeRepresentation> &) const ) &RWStepShape_RWCompoundShapeRepresentation::WriteStep, "Writes CompoundShapeRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWCompoundShapeRepresentation.def("Share", (void (RWStepShape_RWCompoundShapeRepresentation::*)(const opencascade::handle<StepShape_CompoundShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWCompoundShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWConnectedEdgeSet.hxx
	py::class_<RWStepShape_RWConnectedEdgeSet, std::unique_ptr<RWStepShape_RWConnectedEdgeSet, Deleter<RWStepShape_RWConnectedEdgeSet>>> cls_RWStepShape_RWConnectedEdgeSet(mod, "RWStepShape_RWConnectedEdgeSet", "Read & Write tool for ConnectedEdgeSet");
	cls_RWStepShape_RWConnectedEdgeSet.def(py::init<>());
	cls_RWStepShape_RWConnectedEdgeSet.def("ReadStep", (void (RWStepShape_RWConnectedEdgeSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedEdgeSet> &) const ) &RWStepShape_RWConnectedEdgeSet::ReadStep, "Reads ConnectedEdgeSet", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWConnectedEdgeSet.def("WriteStep", (void (RWStepShape_RWConnectedEdgeSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedEdgeSet> &) const ) &RWStepShape_RWConnectedEdgeSet::WriteStep, "Writes ConnectedEdgeSet", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWConnectedEdgeSet.def("Share", (void (RWStepShape_RWConnectedEdgeSet::*)(const opencascade::handle<StepShape_ConnectedEdgeSet> &, Interface_EntityIterator &) const ) &RWStepShape_RWConnectedEdgeSet::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWConnectedFaceSet.hxx
	py::class_<RWStepShape_RWConnectedFaceSet, std::unique_ptr<RWStepShape_RWConnectedFaceSet, Deleter<RWStepShape_RWConnectedFaceSet>>> cls_RWStepShape_RWConnectedFaceSet(mod, "RWStepShape_RWConnectedFaceSet", "Read & Write Module for ConnectedFaceSet");
	cls_RWStepShape_RWConnectedFaceSet.def(py::init<>());
	cls_RWStepShape_RWConnectedFaceSet.def("ReadStep", (void (RWStepShape_RWConnectedFaceSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceSet> &) const ) &RWStepShape_RWConnectedFaceSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceSet.def("WriteStep", (void (RWStepShape_RWConnectedFaceSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceSet> &) const ) &RWStepShape_RWConnectedFaceSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceSet.def("Share", (void (RWStepShape_RWConnectedFaceSet::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &, Interface_EntityIterator &) const ) &RWStepShape_RWConnectedFaceSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWConnectedFaceShapeRepresentation.hxx
	py::class_<RWStepShape_RWConnectedFaceShapeRepresentation, std::unique_ptr<RWStepShape_RWConnectedFaceShapeRepresentation, Deleter<RWStepShape_RWConnectedFaceShapeRepresentation>>> cls_RWStepShape_RWConnectedFaceShapeRepresentation(mod, "RWStepShape_RWConnectedFaceShapeRepresentation", "Read & Write tool for ConnectedFaceShapeRepresentation");
	cls_RWStepShape_RWConnectedFaceShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &) const ) &RWStepShape_RWConnectedFaceShapeRepresentation::ReadStep, "Reads ConnectedFaceShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &) const ) &RWStepShape_RWConnectedFaceShapeRepresentation::WriteStep, "Writes ConnectedFaceShapeRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("Share", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWConnectedFaceShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWConnectedFaceSubSet.hxx
	py::class_<RWStepShape_RWConnectedFaceSubSet, std::unique_ptr<RWStepShape_RWConnectedFaceSubSet, Deleter<RWStepShape_RWConnectedFaceSubSet>>> cls_RWStepShape_RWConnectedFaceSubSet(mod, "RWStepShape_RWConnectedFaceSubSet", "Read & Write tool for ConnectedFaceSubSet");
	cls_RWStepShape_RWConnectedFaceSubSet.def(py::init<>());
	cls_RWStepShape_RWConnectedFaceSubSet.def("ReadStep", (void (RWStepShape_RWConnectedFaceSubSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceSubSet> &) const ) &RWStepShape_RWConnectedFaceSubSet::ReadStep, "Reads ConnectedFaceSubSet", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceSubSet.def("WriteStep", (void (RWStepShape_RWConnectedFaceSubSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceSubSet> &) const ) &RWStepShape_RWConnectedFaceSubSet::WriteStep, "Writes ConnectedFaceSubSet", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWConnectedFaceSubSet.def("Share", (void (RWStepShape_RWConnectedFaceSubSet::*)(const opencascade::handle<StepShape_ConnectedFaceSubSet> &, Interface_EntityIterator &) const ) &RWStepShape_RWConnectedFaceSubSet::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWContextDependentShapeRepresentation.hxx
	py::class_<RWStepShape_RWContextDependentShapeRepresentation, std::unique_ptr<RWStepShape_RWContextDependentShapeRepresentation, Deleter<RWStepShape_RWContextDependentShapeRepresentation>>> cls_RWStepShape_RWContextDependentShapeRepresentation(mod, "RWStepShape_RWContextDependentShapeRepresentation", "Read & Write Module for ContextDependentShapeRepresentation");
	cls_RWStepShape_RWContextDependentShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWContextDependentShapeRepresentation.def("ReadStep", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &) const ) &RWStepShape_RWContextDependentShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWContextDependentShapeRepresentation.def("WriteStep", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &) const ) &RWStepShape_RWContextDependentShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWContextDependentShapeRepresentation.def("Share", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWContextDependentShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWCsgShapeRepresentation.hxx
	py::class_<RWStepShape_RWCsgShapeRepresentation, std::unique_ptr<RWStepShape_RWCsgShapeRepresentation, Deleter<RWStepShape_RWCsgShapeRepresentation>>> cls_RWStepShape_RWCsgShapeRepresentation(mod, "RWStepShape_RWCsgShapeRepresentation", "Read & Write Module for CsgShapeRepresentation");
	cls_RWStepShape_RWCsgShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWCsgShapeRepresentation.def("ReadStep", (void (RWStepShape_RWCsgShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CsgShapeRepresentation> &) const ) &RWStepShape_RWCsgShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWCsgShapeRepresentation.def("WriteStep", (void (RWStepShape_RWCsgShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CsgShapeRepresentation> &) const ) &RWStepShape_RWCsgShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWCsgShapeRepresentation.def("Share", (void (RWStepShape_RWCsgShapeRepresentation::*)(const opencascade::handle<StepShape_CsgShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWCsgShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWCsgSolid.hxx
	py::class_<RWStepShape_RWCsgSolid, std::unique_ptr<RWStepShape_RWCsgSolid, Deleter<RWStepShape_RWCsgSolid>>> cls_RWStepShape_RWCsgSolid(mod, "RWStepShape_RWCsgSolid", "Read & Write Module for CsgSolid");
	cls_RWStepShape_RWCsgSolid.def(py::init<>());
	cls_RWStepShape_RWCsgSolid.def("ReadStep", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CsgSolid> &) const ) &RWStepShape_RWCsgSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWCsgSolid.def("WriteStep", (void (RWStepShape_RWCsgSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CsgSolid> &) const ) &RWStepShape_RWCsgSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWCsgSolid.def("Share", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepShape_CsgSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWCsgSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.hxx
	py::class_<RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation, std::unique_ptr<RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation, Deleter<RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation>>> cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation(mod, "RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation", "Read & Write Module for ConversionBasedUnitAndLengthUnit");
	cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("ReadStep", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &) const ) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("WriteStep", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &) const ) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("Share", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDimensionalCharacteristicRepresentation.hxx
	py::class_<RWStepShape_RWDimensionalCharacteristicRepresentation, std::unique_ptr<RWStepShape_RWDimensionalCharacteristicRepresentation, Deleter<RWStepShape_RWDimensionalCharacteristicRepresentation>>> cls_RWStepShape_RWDimensionalCharacteristicRepresentation(mod, "RWStepShape_RWDimensionalCharacteristicRepresentation", "Read & Write tool for DimensionalCharacteristicRepresentation");
	cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def(py::init<>());
	cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("ReadStep", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &) const ) &RWStepShape_RWDimensionalCharacteristicRepresentation::ReadStep, "Reads DimensionalCharacteristicRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("WriteStep", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &) const ) &RWStepShape_RWDimensionalCharacteristicRepresentation::WriteStep, "Writes DimensionalCharacteristicRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("Share", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWDimensionalCharacteristicRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDimensionalLocation.hxx
	py::class_<RWStepShape_RWDimensionalLocation, std::unique_ptr<RWStepShape_RWDimensionalLocation, Deleter<RWStepShape_RWDimensionalLocation>>> cls_RWStepShape_RWDimensionalLocation(mod, "RWStepShape_RWDimensionalLocation", "Read & Write tool for DimensionalLocation");
	cls_RWStepShape_RWDimensionalLocation.def(py::init<>());
	cls_RWStepShape_RWDimensionalLocation.def("ReadStep", (void (RWStepShape_RWDimensionalLocation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalLocation> &) const ) &RWStepShape_RWDimensionalLocation::ReadStep, "Reads DimensionalLocation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalLocation.def("WriteStep", (void (RWStepShape_RWDimensionalLocation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalLocation> &) const ) &RWStepShape_RWDimensionalLocation::WriteStep, "Writes DimensionalLocation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalLocation.def("Share", (void (RWStepShape_RWDimensionalLocation::*)(const opencascade::handle<StepShape_DimensionalLocation> &, Interface_EntityIterator &) const ) &RWStepShape_RWDimensionalLocation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDimensionalLocationWithPath.hxx
	py::class_<RWStepShape_RWDimensionalLocationWithPath, std::unique_ptr<RWStepShape_RWDimensionalLocationWithPath, Deleter<RWStepShape_RWDimensionalLocationWithPath>>> cls_RWStepShape_RWDimensionalLocationWithPath(mod, "RWStepShape_RWDimensionalLocationWithPath", "Read & Write tool for DimensionalLocationWithPath");
	cls_RWStepShape_RWDimensionalLocationWithPath.def(py::init<>());
	cls_RWStepShape_RWDimensionalLocationWithPath.def("ReadStep", (void (RWStepShape_RWDimensionalLocationWithPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalLocationWithPath> &) const ) &RWStepShape_RWDimensionalLocationWithPath::ReadStep, "Reads DimensionalLocationWithPath", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalLocationWithPath.def("WriteStep", (void (RWStepShape_RWDimensionalLocationWithPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalLocationWithPath> &) const ) &RWStepShape_RWDimensionalLocationWithPath::WriteStep, "Writes DimensionalLocationWithPath", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalLocationWithPath.def("Share", (void (RWStepShape_RWDimensionalLocationWithPath::*)(const opencascade::handle<StepShape_DimensionalLocationWithPath> &, Interface_EntityIterator &) const ) &RWStepShape_RWDimensionalLocationWithPath::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDimensionalSize.hxx
	py::class_<RWStepShape_RWDimensionalSize, std::unique_ptr<RWStepShape_RWDimensionalSize, Deleter<RWStepShape_RWDimensionalSize>>> cls_RWStepShape_RWDimensionalSize(mod, "RWStepShape_RWDimensionalSize", "Read & Write tool for DimensionalSize");
	cls_RWStepShape_RWDimensionalSize.def(py::init<>());
	cls_RWStepShape_RWDimensionalSize.def("ReadStep", (void (RWStepShape_RWDimensionalSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalSize> &) const ) &RWStepShape_RWDimensionalSize::ReadStep, "Reads DimensionalSize", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalSize.def("WriteStep", (void (RWStepShape_RWDimensionalSize::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalSize> &) const ) &RWStepShape_RWDimensionalSize::WriteStep, "Writes DimensionalSize", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalSize.def("Share", (void (RWStepShape_RWDimensionalSize::*)(const opencascade::handle<StepShape_DimensionalSize> &, Interface_EntityIterator &) const ) &RWStepShape_RWDimensionalSize::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWDimensionalSizeWithPath.hxx
	py::class_<RWStepShape_RWDimensionalSizeWithPath, std::unique_ptr<RWStepShape_RWDimensionalSizeWithPath, Deleter<RWStepShape_RWDimensionalSizeWithPath>>> cls_RWStepShape_RWDimensionalSizeWithPath(mod, "RWStepShape_RWDimensionalSizeWithPath", "Read & Write tool for DimensionalSizeWithPath");
	cls_RWStepShape_RWDimensionalSizeWithPath.def(py::init<>());
	cls_RWStepShape_RWDimensionalSizeWithPath.def("ReadStep", (void (RWStepShape_RWDimensionalSizeWithPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalSizeWithPath> &) const ) &RWStepShape_RWDimensionalSizeWithPath::ReadStep, "Reads DimensionalSizeWithPath", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalSizeWithPath.def("WriteStep", (void (RWStepShape_RWDimensionalSizeWithPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalSizeWithPath> &) const ) &RWStepShape_RWDimensionalSizeWithPath::WriteStep, "Writes DimensionalSizeWithPath", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWDimensionalSizeWithPath.def("Share", (void (RWStepShape_RWDimensionalSizeWithPath::*)(const opencascade::handle<StepShape_DimensionalSizeWithPath> &, Interface_EntityIterator &) const ) &RWStepShape_RWDimensionalSizeWithPath::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWEdge.hxx
	py::class_<RWStepShape_RWEdge, std::unique_ptr<RWStepShape_RWEdge, Deleter<RWStepShape_RWEdge>>> cls_RWStepShape_RWEdge(mod, "RWStepShape_RWEdge", "Read & Write Module for Edge");
	cls_RWStepShape_RWEdge.def(py::init<>());
	cls_RWStepShape_RWEdge.def("ReadStep", (void (RWStepShape_RWEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Edge> &) const ) &RWStepShape_RWEdge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWEdge.def("WriteStep", (void (RWStepShape_RWEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Edge> &) const ) &RWStepShape_RWEdge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWEdge.def("Share", (void (RWStepShape_RWEdge::*)(const opencascade::handle<StepShape_Edge> &, Interface_EntityIterator &) const ) &RWStepShape_RWEdge::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWEdgeBasedWireframeModel.hxx
	py::class_<RWStepShape_RWEdgeBasedWireframeModel, std::unique_ptr<RWStepShape_RWEdgeBasedWireframeModel, Deleter<RWStepShape_RWEdgeBasedWireframeModel>>> cls_RWStepShape_RWEdgeBasedWireframeModel(mod, "RWStepShape_RWEdgeBasedWireframeModel", "Read & Write tool for EdgeBasedWireframeModel");
	cls_RWStepShape_RWEdgeBasedWireframeModel.def(py::init<>());
	cls_RWStepShape_RWEdgeBasedWireframeModel.def("ReadStep", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeBasedWireframeModel> &) const ) &RWStepShape_RWEdgeBasedWireframeModel::ReadStep, "Reads EdgeBasedWireframeModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWEdgeBasedWireframeModel.def("WriteStep", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeBasedWireframeModel> &) const ) &RWStepShape_RWEdgeBasedWireframeModel::WriteStep, "Writes EdgeBasedWireframeModel", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWEdgeBasedWireframeModel.def("Share", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(const opencascade::handle<StepShape_EdgeBasedWireframeModel> &, Interface_EntityIterator &) const ) &RWStepShape_RWEdgeBasedWireframeModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWEdgeBasedWireframeShapeRepresentation.hxx
	py::class_<RWStepShape_RWEdgeBasedWireframeShapeRepresentation, std::unique_ptr<RWStepShape_RWEdgeBasedWireframeShapeRepresentation, Deleter<RWStepShape_RWEdgeBasedWireframeShapeRepresentation>>> cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation(mod, "RWStepShape_RWEdgeBasedWireframeShapeRepresentation", "Read & Write tool for EdgeBasedWireframeShapeRepresentation");
	cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("ReadStep", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &) const ) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::ReadStep, "Reads EdgeBasedWireframeShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("WriteStep", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &) const ) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::WriteStep, "Writes EdgeBasedWireframeShapeRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("Share", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWEdgeCurve.hxx
	py::class_<RWStepShape_RWEdgeCurve, std::unique_ptr<RWStepShape_RWEdgeCurve, Deleter<RWStepShape_RWEdgeCurve>>> cls_RWStepShape_RWEdgeCurve(mod, "RWStepShape_RWEdgeCurve", "Read & Write Module for EdgeCurve Check added by CKY , 7-OCT-1996");
	cls_RWStepShape_RWEdgeCurve.def(py::init<>());
	cls_RWStepShape_RWEdgeCurve.def("ReadStep", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeCurve> &) const ) &RWStepShape_RWEdgeCurve::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWEdgeCurve.def("WriteStep", (void (RWStepShape_RWEdgeCurve::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeCurve> &) const ) &RWStepShape_RWEdgeCurve::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWEdgeCurve.def("Share", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepShape_EdgeCurve> &, Interface_EntityIterator &) const ) &RWStepShape_RWEdgeCurve::Share, "None", py::arg("ent"), py::arg("iter"));
	cls_RWStepShape_RWEdgeCurve.def("Check", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepShape_EdgeCurve> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &RWStepShape_RWEdgeCurve::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWEdgeLoop.hxx
	py::class_<RWStepShape_RWEdgeLoop, std::unique_ptr<RWStepShape_RWEdgeLoop, Deleter<RWStepShape_RWEdgeLoop>>> cls_RWStepShape_RWEdgeLoop(mod, "RWStepShape_RWEdgeLoop", "Read & Write Module for EdgeLoop Check added by CKY , 7-OCT-1996");
	cls_RWStepShape_RWEdgeLoop.def(py::init<>());
	cls_RWStepShape_RWEdgeLoop.def("ReadStep", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeLoop> &) const ) &RWStepShape_RWEdgeLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWEdgeLoop.def("WriteStep", (void (RWStepShape_RWEdgeLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeLoop> &) const ) &RWStepShape_RWEdgeLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWEdgeLoop.def("Share", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepShape_EdgeLoop> &, Interface_EntityIterator &) const ) &RWStepShape_RWEdgeLoop::Share, "None", py::arg("ent"), py::arg("iter"));
	cls_RWStepShape_RWEdgeLoop.def("Check", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepShape_EdgeLoop> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &RWStepShape_RWEdgeLoop::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWExtrudedAreaSolid.hxx
	py::class_<RWStepShape_RWExtrudedAreaSolid, std::unique_ptr<RWStepShape_RWExtrudedAreaSolid, Deleter<RWStepShape_RWExtrudedAreaSolid>>> cls_RWStepShape_RWExtrudedAreaSolid(mod, "RWStepShape_RWExtrudedAreaSolid", "Read & Write Module for ExtrudedAreaSolid");
	cls_RWStepShape_RWExtrudedAreaSolid.def(py::init<>());
	cls_RWStepShape_RWExtrudedAreaSolid.def("ReadStep", (void (RWStepShape_RWExtrudedAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ExtrudedAreaSolid> &) const ) &RWStepShape_RWExtrudedAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWExtrudedAreaSolid.def("WriteStep", (void (RWStepShape_RWExtrudedAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ExtrudedAreaSolid> &) const ) &RWStepShape_RWExtrudedAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWExtrudedAreaSolid.def("Share", (void (RWStepShape_RWExtrudedAreaSolid::*)(const opencascade::handle<StepShape_ExtrudedAreaSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWExtrudedAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWExtrudedFaceSolid.hxx
	py::class_<RWStepShape_RWExtrudedFaceSolid, std::unique_ptr<RWStepShape_RWExtrudedFaceSolid, Deleter<RWStepShape_RWExtrudedFaceSolid>>> cls_RWStepShape_RWExtrudedFaceSolid(mod, "RWStepShape_RWExtrudedFaceSolid", "Read & Write Module for ExtrudedFaceSolid");
	cls_RWStepShape_RWExtrudedFaceSolid.def(py::init<>());
	cls_RWStepShape_RWExtrudedFaceSolid.def("ReadStep", (void (RWStepShape_RWExtrudedFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ExtrudedFaceSolid> &) const ) &RWStepShape_RWExtrudedFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWExtrudedFaceSolid.def("WriteStep", (void (RWStepShape_RWExtrudedFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ExtrudedFaceSolid> &) const ) &RWStepShape_RWExtrudedFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWExtrudedFaceSolid.def("Share", (void (RWStepShape_RWExtrudedFaceSolid::*)(const opencascade::handle<StepShape_ExtrudedFaceSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWExtrudedFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFace.hxx
	py::class_<RWStepShape_RWFace, std::unique_ptr<RWStepShape_RWFace, Deleter<RWStepShape_RWFace>>> cls_RWStepShape_RWFace(mod, "RWStepShape_RWFace", "Read & Write Module for Face");
	cls_RWStepShape_RWFace.def(py::init<>());
	cls_RWStepShape_RWFace.def("ReadStep", (void (RWStepShape_RWFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Face> &) const ) &RWStepShape_RWFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFace.def("WriteStep", (void (RWStepShape_RWFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Face> &) const ) &RWStepShape_RWFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFace.def("Share", (void (RWStepShape_RWFace::*)(const opencascade::handle<StepShape_Face> &, Interface_EntityIterator &) const ) &RWStepShape_RWFace::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFaceBasedSurfaceModel.hxx
	py::class_<RWStepShape_RWFaceBasedSurfaceModel, std::unique_ptr<RWStepShape_RWFaceBasedSurfaceModel, Deleter<RWStepShape_RWFaceBasedSurfaceModel>>> cls_RWStepShape_RWFaceBasedSurfaceModel(mod, "RWStepShape_RWFaceBasedSurfaceModel", "Read & Write tool for FaceBasedSurfaceModel");
	cls_RWStepShape_RWFaceBasedSurfaceModel.def(py::init<>());
	cls_RWStepShape_RWFaceBasedSurfaceModel.def("ReadStep", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceBasedSurfaceModel> &) const ) &RWStepShape_RWFaceBasedSurfaceModel::ReadStep, "Reads FaceBasedSurfaceModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFaceBasedSurfaceModel.def("WriteStep", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceBasedSurfaceModel> &) const ) &RWStepShape_RWFaceBasedSurfaceModel::WriteStep, "Writes FaceBasedSurfaceModel", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFaceBasedSurfaceModel.def("Share", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(const opencascade::handle<StepShape_FaceBasedSurfaceModel> &, Interface_EntityIterator &) const ) &RWStepShape_RWFaceBasedSurfaceModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFaceBound.hxx
	py::class_<RWStepShape_RWFaceBound, std::unique_ptr<RWStepShape_RWFaceBound, Deleter<RWStepShape_RWFaceBound>>> cls_RWStepShape_RWFaceBound(mod, "RWStepShape_RWFaceBound", "Read & Write Module for FaceBound Check added by CKY , 7-OCT-1996");
	cls_RWStepShape_RWFaceBound.def(py::init<>());
	cls_RWStepShape_RWFaceBound.def("ReadStep", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceBound> &) const ) &RWStepShape_RWFaceBound::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFaceBound.def("WriteStep", (void (RWStepShape_RWFaceBound::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceBound> &) const ) &RWStepShape_RWFaceBound::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFaceBound.def("Share", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, Interface_EntityIterator &) const ) &RWStepShape_RWFaceBound::Share, "None", py::arg("ent"), py::arg("iter"));
	cls_RWStepShape_RWFaceBound.def("Check", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &RWStepShape_RWFaceBound::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFaceOuterBound.hxx
	py::class_<RWStepShape_RWFaceOuterBound, std::unique_ptr<RWStepShape_RWFaceOuterBound, Deleter<RWStepShape_RWFaceOuterBound>>> cls_RWStepShape_RWFaceOuterBound(mod, "RWStepShape_RWFaceOuterBound", "Read & Write Module for FaceOuterBound");
	cls_RWStepShape_RWFaceOuterBound.def(py::init<>());
	cls_RWStepShape_RWFaceOuterBound.def("ReadStep", (void (RWStepShape_RWFaceOuterBound::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceOuterBound> &) const ) &RWStepShape_RWFaceOuterBound::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFaceOuterBound.def("WriteStep", (void (RWStepShape_RWFaceOuterBound::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceOuterBound> &) const ) &RWStepShape_RWFaceOuterBound::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFaceOuterBound.def("Share", (void (RWStepShape_RWFaceOuterBound::*)(const opencascade::handle<StepShape_FaceOuterBound> &, Interface_EntityIterator &) const ) &RWStepShape_RWFaceOuterBound::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFaceSurface.hxx
	py::class_<RWStepShape_RWFaceSurface, std::unique_ptr<RWStepShape_RWFaceSurface, Deleter<RWStepShape_RWFaceSurface>>> cls_RWStepShape_RWFaceSurface(mod, "RWStepShape_RWFaceSurface", "Read & Write Module for FaceSurface");
	cls_RWStepShape_RWFaceSurface.def(py::init<>());
	cls_RWStepShape_RWFaceSurface.def("ReadStep", (void (RWStepShape_RWFaceSurface::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceSurface> &) const ) &RWStepShape_RWFaceSurface::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFaceSurface.def("WriteStep", (void (RWStepShape_RWFaceSurface::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceSurface> &) const ) &RWStepShape_RWFaceSurface::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFaceSurface.def("Share", (void (RWStepShape_RWFaceSurface::*)(const opencascade::handle<StepShape_FaceSurface> &, Interface_EntityIterator &) const ) &RWStepShape_RWFaceSurface::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFacetedBrep.hxx
	py::class_<RWStepShape_RWFacetedBrep, std::unique_ptr<RWStepShape_RWFacetedBrep, Deleter<RWStepShape_RWFacetedBrep>>> cls_RWStepShape_RWFacetedBrep(mod, "RWStepShape_RWFacetedBrep", "Read & Write Module for FacetedBrep");
	cls_RWStepShape_RWFacetedBrep.def(py::init<>());
	cls_RWStepShape_RWFacetedBrep.def("ReadStep", (void (RWStepShape_RWFacetedBrep::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrep> &) const ) &RWStepShape_RWFacetedBrep::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrep.def("WriteStep", (void (RWStepShape_RWFacetedBrep::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrep> &) const ) &RWStepShape_RWFacetedBrep::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrep.def("Share", (void (RWStepShape_RWFacetedBrep::*)(const opencascade::handle<StepShape_FacetedBrep> &, Interface_EntityIterator &) const ) &RWStepShape_RWFacetedBrep::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFacetedBrepAndBrepWithVoids.hxx
	py::class_<RWStepShape_RWFacetedBrepAndBrepWithVoids, std::unique_ptr<RWStepShape_RWFacetedBrepAndBrepWithVoids, Deleter<RWStepShape_RWFacetedBrepAndBrepWithVoids>>> cls_RWStepShape_RWFacetedBrepAndBrepWithVoids(mod, "RWStepShape_RWFacetedBrepAndBrepWithVoids", "Read & Write Module for FacetedBrepAndBrepWithVoids");
	cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def(py::init<>());
	cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("ReadStep", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &) const ) &RWStepShape_RWFacetedBrepAndBrepWithVoids::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("WriteStep", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &) const ) &RWStepShape_RWFacetedBrepAndBrepWithVoids::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("Share", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, Interface_EntityIterator &) const ) &RWStepShape_RWFacetedBrepAndBrepWithVoids::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWFacetedBrepShapeRepresentation.hxx
	py::class_<RWStepShape_RWFacetedBrepShapeRepresentation, std::unique_ptr<RWStepShape_RWFacetedBrepShapeRepresentation, Deleter<RWStepShape_RWFacetedBrepShapeRepresentation>>> cls_RWStepShape_RWFacetedBrepShapeRepresentation(mod, "RWStepShape_RWFacetedBrepShapeRepresentation", "Read & Write Module for FacetedBrepShapeRepresentation");
	cls_RWStepShape_RWFacetedBrepShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("ReadStep", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &) const ) &RWStepShape_RWFacetedBrepShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("WriteStep", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &) const ) &RWStepShape_RWFacetedBrepShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("Share", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWFacetedBrepShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.hxx
	py::class_<RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation, std::unique_ptr<RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation, Deleter<RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation>>> cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation(mod, "RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation", "Read & Write Module for GeometricallyBoundedSurfaceShapeRepresentation");
	cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &) const ) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &) const ) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.hxx
	py::class_<RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation, std::unique_ptr<RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation, Deleter<RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation>>> cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation(mod, "RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation", "Read & Write Module for GeometricallyBoundedWireframeShapeRepresentation");
	cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("ReadStep", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &) const ) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("WriteStep", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &) const ) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("Share", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWGeometricCurveSet.hxx
	py::class_<RWStepShape_RWGeometricCurveSet, std::unique_ptr<RWStepShape_RWGeometricCurveSet, Deleter<RWStepShape_RWGeometricCurveSet>>> cls_RWStepShape_RWGeometricCurveSet(mod, "RWStepShape_RWGeometricCurveSet", "Read & Write Module for GeometricCurveSet");
	cls_RWStepShape_RWGeometricCurveSet.def(py::init<>());
	cls_RWStepShape_RWGeometricCurveSet.def("ReadStep", (void (RWStepShape_RWGeometricCurveSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricCurveSet> &) const ) &RWStepShape_RWGeometricCurveSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWGeometricCurveSet.def("WriteStep", (void (RWStepShape_RWGeometricCurveSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricCurveSet> &) const ) &RWStepShape_RWGeometricCurveSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWGeometricCurveSet.def("Share", (void (RWStepShape_RWGeometricCurveSet::*)(const opencascade::handle<StepShape_GeometricCurveSet> &, Interface_EntityIterator &) const ) &RWStepShape_RWGeometricCurveSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWGeometricSet.hxx
	py::class_<RWStepShape_RWGeometricSet, std::unique_ptr<RWStepShape_RWGeometricSet, Deleter<RWStepShape_RWGeometricSet>>> cls_RWStepShape_RWGeometricSet(mod, "RWStepShape_RWGeometricSet", "Read & Write Module for GeometricSet");
	cls_RWStepShape_RWGeometricSet.def(py::init<>());
	cls_RWStepShape_RWGeometricSet.def("ReadStep", (void (RWStepShape_RWGeometricSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricSet> &) const ) &RWStepShape_RWGeometricSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWGeometricSet.def("WriteStep", (void (RWStepShape_RWGeometricSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricSet> &) const ) &RWStepShape_RWGeometricSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWGeometricSet.def("Share", (void (RWStepShape_RWGeometricSet::*)(const opencascade::handle<StepShape_GeometricSet> &, Interface_EntityIterator &) const ) &RWStepShape_RWGeometricSet::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWHalfSpaceSolid.hxx
	py::class_<RWStepShape_RWHalfSpaceSolid, std::unique_ptr<RWStepShape_RWHalfSpaceSolid, Deleter<RWStepShape_RWHalfSpaceSolid>>> cls_RWStepShape_RWHalfSpaceSolid(mod, "RWStepShape_RWHalfSpaceSolid", "Read & Write Module for HalfSpaceSolid");
	cls_RWStepShape_RWHalfSpaceSolid.def(py::init<>());
	cls_RWStepShape_RWHalfSpaceSolid.def("ReadStep", (void (RWStepShape_RWHalfSpaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_HalfSpaceSolid> &) const ) &RWStepShape_RWHalfSpaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWHalfSpaceSolid.def("WriteStep", (void (RWStepShape_RWHalfSpaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_HalfSpaceSolid> &) const ) &RWStepShape_RWHalfSpaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWHalfSpaceSolid.def("Share", (void (RWStepShape_RWHalfSpaceSolid::*)(const opencascade::handle<StepShape_HalfSpaceSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWHalfSpaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWLimitsAndFits.hxx
	py::class_<RWStepShape_RWLimitsAndFits, std::unique_ptr<RWStepShape_RWLimitsAndFits, Deleter<RWStepShape_RWLimitsAndFits>>> cls_RWStepShape_RWLimitsAndFits(mod, "RWStepShape_RWLimitsAndFits", "Read & Write Module for LimitsAndFits");
	cls_RWStepShape_RWLimitsAndFits.def(py::init<>());
	cls_RWStepShape_RWLimitsAndFits.def("ReadStep", (void (RWStepShape_RWLimitsAndFits::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_LimitsAndFits> &) const ) &RWStepShape_RWLimitsAndFits::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWLimitsAndFits.def("WriteStep", (void (RWStepShape_RWLimitsAndFits::*)(StepData_StepWriter &, const opencascade::handle<StepShape_LimitsAndFits> &) const ) &RWStepShape_RWLimitsAndFits::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWLoop.hxx
	py::class_<RWStepShape_RWLoop, std::unique_ptr<RWStepShape_RWLoop, Deleter<RWStepShape_RWLoop>>> cls_RWStepShape_RWLoop(mod, "RWStepShape_RWLoop", "Read & Write Module for Loop");
	cls_RWStepShape_RWLoop.def(py::init<>());
	cls_RWStepShape_RWLoop.def("ReadStep", (void (RWStepShape_RWLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Loop> &) const ) &RWStepShape_RWLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWLoop.def("WriteStep", (void (RWStepShape_RWLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Loop> &) const ) &RWStepShape_RWLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWLoopAndPath.hxx
	py::class_<RWStepShape_RWLoopAndPath, std::unique_ptr<RWStepShape_RWLoopAndPath, Deleter<RWStepShape_RWLoopAndPath>>> cls_RWStepShape_RWLoopAndPath(mod, "RWStepShape_RWLoopAndPath", "Read & Write Module for LoopAndPath");
	cls_RWStepShape_RWLoopAndPath.def(py::init<>());
	cls_RWStepShape_RWLoopAndPath.def("ReadStep", (void (RWStepShape_RWLoopAndPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_LoopAndPath> &) const ) &RWStepShape_RWLoopAndPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWLoopAndPath.def("WriteStep", (void (RWStepShape_RWLoopAndPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_LoopAndPath> &) const ) &RWStepShape_RWLoopAndPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWLoopAndPath.def("Share", (void (RWStepShape_RWLoopAndPath::*)(const opencascade::handle<StepShape_LoopAndPath> &, Interface_EntityIterator &) const ) &RWStepShape_RWLoopAndPath::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWManifoldSolidBrep.hxx
	py::class_<RWStepShape_RWManifoldSolidBrep, std::unique_ptr<RWStepShape_RWManifoldSolidBrep, Deleter<RWStepShape_RWManifoldSolidBrep>>> cls_RWStepShape_RWManifoldSolidBrep(mod, "RWStepShape_RWManifoldSolidBrep", "Read & Write Module for ManifoldSolidBrep");
	cls_RWStepShape_RWManifoldSolidBrep.def(py::init<>());
	cls_RWStepShape_RWManifoldSolidBrep.def("ReadStep", (void (RWStepShape_RWManifoldSolidBrep::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ManifoldSolidBrep> &) const ) &RWStepShape_RWManifoldSolidBrep::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWManifoldSolidBrep.def("WriteStep", (void (RWStepShape_RWManifoldSolidBrep::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ManifoldSolidBrep> &) const ) &RWStepShape_RWManifoldSolidBrep::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWManifoldSolidBrep.def("Share", (void (RWStepShape_RWManifoldSolidBrep::*)(const opencascade::handle<StepShape_ManifoldSolidBrep> &, Interface_EntityIterator &) const ) &RWStepShape_RWManifoldSolidBrep::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWManifoldSurfaceShapeRepresentation.hxx
	py::class_<RWStepShape_RWManifoldSurfaceShapeRepresentation, std::unique_ptr<RWStepShape_RWManifoldSurfaceShapeRepresentation, Deleter<RWStepShape_RWManifoldSurfaceShapeRepresentation>>> cls_RWStepShape_RWManifoldSurfaceShapeRepresentation(mod, "RWStepShape_RWManifoldSurfaceShapeRepresentation", "Read & Write Module for ManifoldSurfaceShapeRepresentation");
	cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &) const ) &RWStepShape_RWManifoldSurfaceShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &) const ) &RWStepShape_RWManifoldSurfaceShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWManifoldSurfaceShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWMeasureQualification.hxx
	py::class_<RWStepShape_RWMeasureQualification, std::unique_ptr<RWStepShape_RWMeasureQualification, Deleter<RWStepShape_RWMeasureQualification>>> cls_RWStepShape_RWMeasureQualification(mod, "RWStepShape_RWMeasureQualification", "Read & Write Module for MeasureQualification");
	cls_RWStepShape_RWMeasureQualification.def(py::init<>());
	cls_RWStepShape_RWMeasureQualification.def("ReadStep", (void (RWStepShape_RWMeasureQualification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_MeasureQualification> &) const ) &RWStepShape_RWMeasureQualification::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWMeasureQualification.def("WriteStep", (void (RWStepShape_RWMeasureQualification::*)(StepData_StepWriter &, const opencascade::handle<StepShape_MeasureQualification> &) const ) &RWStepShape_RWMeasureQualification::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWMeasureQualification.def("Share", (void (RWStepShape_RWMeasureQualification::*)(const opencascade::handle<StepShape_MeasureQualification> &, Interface_EntityIterator &) const ) &RWStepShape_RWMeasureQualification::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.hxx
	py::class_<RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem, std::unique_ptr<RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem, Deleter<RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem>>> cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem(mod, "RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem", "Read & Write Module for MeasureRepresentationItemAndQualifiedRepresentationItem");
	cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def(py::init<>());
	cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("ReadStep", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &) const ) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("WriteStep", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &) const ) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("Share", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &, Interface_EntityIterator &) const ) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWNonManifoldSurfaceShapeRepresentation.hxx
	py::class_<RWStepShape_RWNonManifoldSurfaceShapeRepresentation, std::unique_ptr<RWStepShape_RWNonManifoldSurfaceShapeRepresentation, Deleter<RWStepShape_RWNonManifoldSurfaceShapeRepresentation>>> cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation(mod, "RWStepShape_RWNonManifoldSurfaceShapeRepresentation", "Read & Write tool for NonManifoldSurfaceShapeRepresentation");
	cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &) const ) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::ReadStep, "Reads NonManifoldSurfaceShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &) const ) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::WriteStep, "Writes NonManifoldSurfaceShapeRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOpenShell.hxx
	py::class_<RWStepShape_RWOpenShell, std::unique_ptr<RWStepShape_RWOpenShell, Deleter<RWStepShape_RWOpenShell>>> cls_RWStepShape_RWOpenShell(mod, "RWStepShape_RWOpenShell", "Read & Write Module for OpenShell");
	cls_RWStepShape_RWOpenShell.def(py::init<>());
	cls_RWStepShape_RWOpenShell.def("ReadStep", (void (RWStepShape_RWOpenShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OpenShell> &) const ) &RWStepShape_RWOpenShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOpenShell.def("WriteStep", (void (RWStepShape_RWOpenShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OpenShell> &) const ) &RWStepShape_RWOpenShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOpenShell.def("Share", (void (RWStepShape_RWOpenShell::*)(const opencascade::handle<StepShape_OpenShell> &, Interface_EntityIterator &) const ) &RWStepShape_RWOpenShell::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOrientedClosedShell.hxx
	py::class_<RWStepShape_RWOrientedClosedShell, std::unique_ptr<RWStepShape_RWOrientedClosedShell, Deleter<RWStepShape_RWOrientedClosedShell>>> cls_RWStepShape_RWOrientedClosedShell(mod, "RWStepShape_RWOrientedClosedShell", "Read & Write Module for OrientedClosedShell");
	cls_RWStepShape_RWOrientedClosedShell.def(py::init<>());
	cls_RWStepShape_RWOrientedClosedShell.def("ReadStep", (void (RWStepShape_RWOrientedClosedShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedClosedShell> &) const ) &RWStepShape_RWOrientedClosedShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOrientedClosedShell.def("WriteStep", (void (RWStepShape_RWOrientedClosedShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedClosedShell> &) const ) &RWStepShape_RWOrientedClosedShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOrientedClosedShell.def("Share", (void (RWStepShape_RWOrientedClosedShell::*)(const opencascade::handle<StepShape_OrientedClosedShell> &, Interface_EntityIterator &) const ) &RWStepShape_RWOrientedClosedShell::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOrientedEdge.hxx
	py::class_<RWStepShape_RWOrientedEdge, std::unique_ptr<RWStepShape_RWOrientedEdge, Deleter<RWStepShape_RWOrientedEdge>>> cls_RWStepShape_RWOrientedEdge(mod, "RWStepShape_RWOrientedEdge", "Read & Write Module for OrientedEdge");
	cls_RWStepShape_RWOrientedEdge.def(py::init<>());
	cls_RWStepShape_RWOrientedEdge.def("ReadStep", (void (RWStepShape_RWOrientedEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedEdge> &) const ) &RWStepShape_RWOrientedEdge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOrientedEdge.def("WriteStep", (void (RWStepShape_RWOrientedEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedEdge> &) const ) &RWStepShape_RWOrientedEdge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOrientedEdge.def("Share", (void (RWStepShape_RWOrientedEdge::*)(const opencascade::handle<StepShape_OrientedEdge> &, Interface_EntityIterator &) const ) &RWStepShape_RWOrientedEdge::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOrientedFace.hxx
	py::class_<RWStepShape_RWOrientedFace, std::unique_ptr<RWStepShape_RWOrientedFace, Deleter<RWStepShape_RWOrientedFace>>> cls_RWStepShape_RWOrientedFace(mod, "RWStepShape_RWOrientedFace", "Read & Write Module for OrientedFace");
	cls_RWStepShape_RWOrientedFace.def(py::init<>());
	cls_RWStepShape_RWOrientedFace.def("ReadStep", (void (RWStepShape_RWOrientedFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedFace> &) const ) &RWStepShape_RWOrientedFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOrientedFace.def("WriteStep", (void (RWStepShape_RWOrientedFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedFace> &) const ) &RWStepShape_RWOrientedFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOrientedFace.def("Share", (void (RWStepShape_RWOrientedFace::*)(const opencascade::handle<StepShape_OrientedFace> &, Interface_EntityIterator &) const ) &RWStepShape_RWOrientedFace::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOrientedOpenShell.hxx
	py::class_<RWStepShape_RWOrientedOpenShell, std::unique_ptr<RWStepShape_RWOrientedOpenShell, Deleter<RWStepShape_RWOrientedOpenShell>>> cls_RWStepShape_RWOrientedOpenShell(mod, "RWStepShape_RWOrientedOpenShell", "Read & Write Module for OrientedOpenShell");
	cls_RWStepShape_RWOrientedOpenShell.def(py::init<>());
	cls_RWStepShape_RWOrientedOpenShell.def("ReadStep", (void (RWStepShape_RWOrientedOpenShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedOpenShell> &) const ) &RWStepShape_RWOrientedOpenShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOrientedOpenShell.def("WriteStep", (void (RWStepShape_RWOrientedOpenShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedOpenShell> &) const ) &RWStepShape_RWOrientedOpenShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOrientedOpenShell.def("Share", (void (RWStepShape_RWOrientedOpenShell::*)(const opencascade::handle<StepShape_OrientedOpenShell> &, Interface_EntityIterator &) const ) &RWStepShape_RWOrientedOpenShell::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWOrientedPath.hxx
	py::class_<RWStepShape_RWOrientedPath, std::unique_ptr<RWStepShape_RWOrientedPath, Deleter<RWStepShape_RWOrientedPath>>> cls_RWStepShape_RWOrientedPath(mod, "RWStepShape_RWOrientedPath", "Read & Write Module for OrientedPath");
	cls_RWStepShape_RWOrientedPath.def(py::init<>());
	cls_RWStepShape_RWOrientedPath.def("ReadStep", (void (RWStepShape_RWOrientedPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedPath> &) const ) &RWStepShape_RWOrientedPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWOrientedPath.def("WriteStep", (void (RWStepShape_RWOrientedPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedPath> &) const ) &RWStepShape_RWOrientedPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWOrientedPath.def("Share", (void (RWStepShape_RWOrientedPath::*)(const opencascade::handle<StepShape_OrientedPath> &, Interface_EntityIterator &) const ) &RWStepShape_RWOrientedPath::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWPath.hxx
	py::class_<RWStepShape_RWPath, std::unique_ptr<RWStepShape_RWPath, Deleter<RWStepShape_RWPath>>> cls_RWStepShape_RWPath(mod, "RWStepShape_RWPath", "Read & Write Module for Path");
	cls_RWStepShape_RWPath.def(py::init<>());
	cls_RWStepShape_RWPath.def("ReadStep", (void (RWStepShape_RWPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Path> &) const ) &RWStepShape_RWPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWPath.def("WriteStep", (void (RWStepShape_RWPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Path> &) const ) &RWStepShape_RWPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWPath.def("Share", (void (RWStepShape_RWPath::*)(const opencascade::handle<StepShape_Path> &, Interface_EntityIterator &) const ) &RWStepShape_RWPath::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWPlusMinusTolerance.hxx
	py::class_<RWStepShape_RWPlusMinusTolerance, std::unique_ptr<RWStepShape_RWPlusMinusTolerance, Deleter<RWStepShape_RWPlusMinusTolerance>>> cls_RWStepShape_RWPlusMinusTolerance(mod, "RWStepShape_RWPlusMinusTolerance", "Read & Write Module for PlusMinusTolerance");
	cls_RWStepShape_RWPlusMinusTolerance.def(py::init<>());
	cls_RWStepShape_RWPlusMinusTolerance.def("ReadStep", (void (RWStepShape_RWPlusMinusTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PlusMinusTolerance> &) const ) &RWStepShape_RWPlusMinusTolerance::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWPlusMinusTolerance.def("WriteStep", (void (RWStepShape_RWPlusMinusTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PlusMinusTolerance> &) const ) &RWStepShape_RWPlusMinusTolerance::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWPlusMinusTolerance.def("Share", (void (RWStepShape_RWPlusMinusTolerance::*)(const opencascade::handle<StepShape_PlusMinusTolerance> &, Interface_EntityIterator &) const ) &RWStepShape_RWPlusMinusTolerance::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWPointRepresentation.hxx
	py::class_<RWStepShape_RWPointRepresentation, std::unique_ptr<RWStepShape_RWPointRepresentation, Deleter<RWStepShape_RWPointRepresentation>>> cls_RWStepShape_RWPointRepresentation(mod, "RWStepShape_RWPointRepresentation", "Read & Write tool for PointRepresentation");
	cls_RWStepShape_RWPointRepresentation.def(py::init<>());
	cls_RWStepShape_RWPointRepresentation.def("ReadStep", (void (RWStepShape_RWPointRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PointRepresentation> &) const ) &RWStepShape_RWPointRepresentation::ReadStep, "Reads PointRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWPointRepresentation.def("WriteStep", (void (RWStepShape_RWPointRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PointRepresentation> &) const ) &RWStepShape_RWPointRepresentation::WriteStep, "Writes PointRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWPointRepresentation.def("Share", (void (RWStepShape_RWPointRepresentation::*)(const opencascade::handle<StepShape_PointRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWPointRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWPolyLoop.hxx
	py::class_<RWStepShape_RWPolyLoop, std::unique_ptr<RWStepShape_RWPolyLoop, Deleter<RWStepShape_RWPolyLoop>>> cls_RWStepShape_RWPolyLoop(mod, "RWStepShape_RWPolyLoop", "Read & Write Module for PolyLoop");
	cls_RWStepShape_RWPolyLoop.def(py::init<>());
	cls_RWStepShape_RWPolyLoop.def("ReadStep", (void (RWStepShape_RWPolyLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PolyLoop> &) const ) &RWStepShape_RWPolyLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWPolyLoop.def("WriteStep", (void (RWStepShape_RWPolyLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PolyLoop> &) const ) &RWStepShape_RWPolyLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWPolyLoop.def("Share", (void (RWStepShape_RWPolyLoop::*)(const opencascade::handle<StepShape_PolyLoop> &, Interface_EntityIterator &) const ) &RWStepShape_RWPolyLoop::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWPrecisionQualifier.hxx
	py::class_<RWStepShape_RWPrecisionQualifier, std::unique_ptr<RWStepShape_RWPrecisionQualifier, Deleter<RWStepShape_RWPrecisionQualifier>>> cls_RWStepShape_RWPrecisionQualifier(mod, "RWStepShape_RWPrecisionQualifier", "Read & Write Module for PrecisionQualifier");
	cls_RWStepShape_RWPrecisionQualifier.def(py::init<>());
	cls_RWStepShape_RWPrecisionQualifier.def("ReadStep", (void (RWStepShape_RWPrecisionQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PrecisionQualifier> &) const ) &RWStepShape_RWPrecisionQualifier::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWPrecisionQualifier.def("WriteStep", (void (RWStepShape_RWPrecisionQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PrecisionQualifier> &) const ) &RWStepShape_RWPrecisionQualifier::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWQualifiedRepresentationItem.hxx
	py::class_<RWStepShape_RWQualifiedRepresentationItem, std::unique_ptr<RWStepShape_RWQualifiedRepresentationItem, Deleter<RWStepShape_RWQualifiedRepresentationItem>>> cls_RWStepShape_RWQualifiedRepresentationItem(mod, "RWStepShape_RWQualifiedRepresentationItem", "Read & Write Module for QualifiedRepresentationItem");
	cls_RWStepShape_RWQualifiedRepresentationItem.def(py::init<>());
	cls_RWStepShape_RWQualifiedRepresentationItem.def("ReadStep", (void (RWStepShape_RWQualifiedRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_QualifiedRepresentationItem> &) const ) &RWStepShape_RWQualifiedRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWQualifiedRepresentationItem.def("WriteStep", (void (RWStepShape_RWQualifiedRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_QualifiedRepresentationItem> &) const ) &RWStepShape_RWQualifiedRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWQualifiedRepresentationItem.def("Share", (void (RWStepShape_RWQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_QualifiedRepresentationItem> &, Interface_EntityIterator &) const ) &RWStepShape_RWQualifiedRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWRevolvedAreaSolid.hxx
	py::class_<RWStepShape_RWRevolvedAreaSolid, std::unique_ptr<RWStepShape_RWRevolvedAreaSolid, Deleter<RWStepShape_RWRevolvedAreaSolid>>> cls_RWStepShape_RWRevolvedAreaSolid(mod, "RWStepShape_RWRevolvedAreaSolid", "Read & Write Module for RevolvedAreaSolid");
	cls_RWStepShape_RWRevolvedAreaSolid.def(py::init<>());
	cls_RWStepShape_RWRevolvedAreaSolid.def("ReadStep", (void (RWStepShape_RWRevolvedAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RevolvedAreaSolid> &) const ) &RWStepShape_RWRevolvedAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWRevolvedAreaSolid.def("WriteStep", (void (RWStepShape_RWRevolvedAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RevolvedAreaSolid> &) const ) &RWStepShape_RWRevolvedAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWRevolvedAreaSolid.def("Share", (void (RWStepShape_RWRevolvedAreaSolid::*)(const opencascade::handle<StepShape_RevolvedAreaSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWRevolvedAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWRevolvedFaceSolid.hxx
	py::class_<RWStepShape_RWRevolvedFaceSolid, std::unique_ptr<RWStepShape_RWRevolvedFaceSolid, Deleter<RWStepShape_RWRevolvedFaceSolid>>> cls_RWStepShape_RWRevolvedFaceSolid(mod, "RWStepShape_RWRevolvedFaceSolid", "None");
	cls_RWStepShape_RWRevolvedFaceSolid.def(py::init<>());
	cls_RWStepShape_RWRevolvedFaceSolid.def("ReadStep", (void (RWStepShape_RWRevolvedFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RevolvedFaceSolid> &) const ) &RWStepShape_RWRevolvedFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWRevolvedFaceSolid.def("WriteStep", (void (RWStepShape_RWRevolvedFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RevolvedFaceSolid> &) const ) &RWStepShape_RWRevolvedFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWRevolvedFaceSolid.def("Share", (void (RWStepShape_RWRevolvedFaceSolid::*)(const opencascade::handle<StepShape_RevolvedFaceSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWRevolvedFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWRightAngularWedge.hxx
	py::class_<RWStepShape_RWRightAngularWedge, std::unique_ptr<RWStepShape_RWRightAngularWedge, Deleter<RWStepShape_RWRightAngularWedge>>> cls_RWStepShape_RWRightAngularWedge(mod, "RWStepShape_RWRightAngularWedge", "Read & Write Module for RightAngularWedge");
	cls_RWStepShape_RWRightAngularWedge.def(py::init<>());
	cls_RWStepShape_RWRightAngularWedge.def("ReadStep", (void (RWStepShape_RWRightAngularWedge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightAngularWedge> &) const ) &RWStepShape_RWRightAngularWedge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWRightAngularWedge.def("WriteStep", (void (RWStepShape_RWRightAngularWedge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightAngularWedge> &) const ) &RWStepShape_RWRightAngularWedge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWRightAngularWedge.def("Share", (void (RWStepShape_RWRightAngularWedge::*)(const opencascade::handle<StepShape_RightAngularWedge> &, Interface_EntityIterator &) const ) &RWStepShape_RWRightAngularWedge::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWRightCircularCone.hxx
	py::class_<RWStepShape_RWRightCircularCone, std::unique_ptr<RWStepShape_RWRightCircularCone, Deleter<RWStepShape_RWRightCircularCone>>> cls_RWStepShape_RWRightCircularCone(mod, "RWStepShape_RWRightCircularCone", "Read & Write Module for RightCircularCone");
	cls_RWStepShape_RWRightCircularCone.def(py::init<>());
	cls_RWStepShape_RWRightCircularCone.def("ReadStep", (void (RWStepShape_RWRightCircularCone::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightCircularCone> &) const ) &RWStepShape_RWRightCircularCone::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWRightCircularCone.def("WriteStep", (void (RWStepShape_RWRightCircularCone::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightCircularCone> &) const ) &RWStepShape_RWRightCircularCone::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWRightCircularCone.def("Share", (void (RWStepShape_RWRightCircularCone::*)(const opencascade::handle<StepShape_RightCircularCone> &, Interface_EntityIterator &) const ) &RWStepShape_RWRightCircularCone::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWRightCircularCylinder.hxx
	py::class_<RWStepShape_RWRightCircularCylinder, std::unique_ptr<RWStepShape_RWRightCircularCylinder, Deleter<RWStepShape_RWRightCircularCylinder>>> cls_RWStepShape_RWRightCircularCylinder(mod, "RWStepShape_RWRightCircularCylinder", "Read & Write Module for RightCircularCylinder");
	cls_RWStepShape_RWRightCircularCylinder.def(py::init<>());
	cls_RWStepShape_RWRightCircularCylinder.def("ReadStep", (void (RWStepShape_RWRightCircularCylinder::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightCircularCylinder> &) const ) &RWStepShape_RWRightCircularCylinder::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWRightCircularCylinder.def("WriteStep", (void (RWStepShape_RWRightCircularCylinder::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightCircularCylinder> &) const ) &RWStepShape_RWRightCircularCylinder::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWRightCircularCylinder.def("Share", (void (RWStepShape_RWRightCircularCylinder::*)(const opencascade::handle<StepShape_RightCircularCylinder> &, Interface_EntityIterator &) const ) &RWStepShape_RWRightCircularCylinder::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSeamEdge.hxx
	py::class_<RWStepShape_RWSeamEdge, std::unique_ptr<RWStepShape_RWSeamEdge, Deleter<RWStepShape_RWSeamEdge>>> cls_RWStepShape_RWSeamEdge(mod, "RWStepShape_RWSeamEdge", "Read & Write tool for SeamEdge");
	cls_RWStepShape_RWSeamEdge.def(py::init<>());
	cls_RWStepShape_RWSeamEdge.def("ReadStep", (void (RWStepShape_RWSeamEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SeamEdge> &) const ) &RWStepShape_RWSeamEdge::ReadStep, "Reads SeamEdge", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSeamEdge.def("WriteStep", (void (RWStepShape_RWSeamEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SeamEdge> &) const ) &RWStepShape_RWSeamEdge::WriteStep, "Writes SeamEdge", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSeamEdge.def("Share", (void (RWStepShape_RWSeamEdge::*)(const opencascade::handle<StepShape_SeamEdge> &, Interface_EntityIterator &) const ) &RWStepShape_RWSeamEdge::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWShapeDefinitionRepresentation.hxx
	py::class_<RWStepShape_RWShapeDefinitionRepresentation, std::unique_ptr<RWStepShape_RWShapeDefinitionRepresentation, Deleter<RWStepShape_RWShapeDefinitionRepresentation>>> cls_RWStepShape_RWShapeDefinitionRepresentation(mod, "RWStepShape_RWShapeDefinitionRepresentation", "Read & Write tool for ShapeDefinitionRepresentation");
	cls_RWStepShape_RWShapeDefinitionRepresentation.def(py::init<>());
	cls_RWStepShape_RWShapeDefinitionRepresentation.def("ReadStep", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &) const ) &RWStepShape_RWShapeDefinitionRepresentation::ReadStep, "Reads ShapeDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWShapeDefinitionRepresentation.def("WriteStep", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &) const ) &RWStepShape_RWShapeDefinitionRepresentation::WriteStep, "Writes ShapeDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWShapeDefinitionRepresentation.def("Share", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWShapeDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWShapeDimensionRepresentation.hxx
	py::class_<RWStepShape_RWShapeDimensionRepresentation, std::unique_ptr<RWStepShape_RWShapeDimensionRepresentation, Deleter<RWStepShape_RWShapeDimensionRepresentation>>> cls_RWStepShape_RWShapeDimensionRepresentation(mod, "RWStepShape_RWShapeDimensionRepresentation", "Read & Write tool for ShapeDimensionRepresentation");
	cls_RWStepShape_RWShapeDimensionRepresentation.def(py::init<>());
	cls_RWStepShape_RWShapeDimensionRepresentation.def("ReadStep", (void (RWStepShape_RWShapeDimensionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &) const ) &RWStepShape_RWShapeDimensionRepresentation::ReadStep, "Reads ShapeDimensionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWShapeDimensionRepresentation.def("WriteStep", (void (RWStepShape_RWShapeDimensionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &) const ) &RWStepShape_RWShapeDimensionRepresentation::WriteStep, "Writes ShapeDimensionRepresentation", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWShapeDimensionRepresentation.def("Share", (void (RWStepShape_RWShapeDimensionRepresentation::*)(const opencascade::handle<StepShape_ShapeDimensionRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWShapeDimensionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWShapeRepresentation.hxx
	py::class_<RWStepShape_RWShapeRepresentation, std::unique_ptr<RWStepShape_RWShapeRepresentation, Deleter<RWStepShape_RWShapeRepresentation>>> cls_RWStepShape_RWShapeRepresentation(mod, "RWStepShape_RWShapeRepresentation", "Read & Write Module for ShapeRepresentation");
	cls_RWStepShape_RWShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWShapeRepresentation.def("ReadStep", (void (RWStepShape_RWShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeRepresentation> &) const ) &RWStepShape_RWShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWShapeRepresentation.def("WriteStep", (void (RWStepShape_RWShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeRepresentation> &) const ) &RWStepShape_RWShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWShapeRepresentation.def("Share", (void (RWStepShape_RWShapeRepresentation::*)(const opencascade::handle<StepShape_ShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWShapeRepresentationWithParameters.hxx
	py::class_<RWStepShape_RWShapeRepresentationWithParameters, std::unique_ptr<RWStepShape_RWShapeRepresentationWithParameters, Deleter<RWStepShape_RWShapeRepresentationWithParameters>>> cls_RWStepShape_RWShapeRepresentationWithParameters(mod, "RWStepShape_RWShapeRepresentationWithParameters", "Read & Write tool for ShapeRepresentationWithParameters");
	cls_RWStepShape_RWShapeRepresentationWithParameters.def(py::init<>());
	cls_RWStepShape_RWShapeRepresentationWithParameters.def("ReadStep", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &) const ) &RWStepShape_RWShapeRepresentationWithParameters::ReadStep, "Reads ShapeRepresentationWithParameters", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWShapeRepresentationWithParameters.def("WriteStep", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &) const ) &RWStepShape_RWShapeRepresentationWithParameters::WriteStep, "Writes ShapeRepresentationWithParameters", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWShapeRepresentationWithParameters.def("Share", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &, Interface_EntityIterator &) const ) &RWStepShape_RWShapeRepresentationWithParameters::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWShellBasedSurfaceModel.hxx
	py::class_<RWStepShape_RWShellBasedSurfaceModel, std::unique_ptr<RWStepShape_RWShellBasedSurfaceModel, Deleter<RWStepShape_RWShellBasedSurfaceModel>>> cls_RWStepShape_RWShellBasedSurfaceModel(mod, "RWStepShape_RWShellBasedSurfaceModel", "Read & Write Module for ShellBasedSurfaceModel");
	cls_RWStepShape_RWShellBasedSurfaceModel.def(py::init<>());
	cls_RWStepShape_RWShellBasedSurfaceModel.def("ReadStep", (void (RWStepShape_RWShellBasedSurfaceModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShellBasedSurfaceModel> &) const ) &RWStepShape_RWShellBasedSurfaceModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWShellBasedSurfaceModel.def("WriteStep", (void (RWStepShape_RWShellBasedSurfaceModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShellBasedSurfaceModel> &) const ) &RWStepShape_RWShellBasedSurfaceModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWShellBasedSurfaceModel.def("Share", (void (RWStepShape_RWShellBasedSurfaceModel::*)(const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, Interface_EntityIterator &) const ) &RWStepShape_RWShellBasedSurfaceModel::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSolidModel.hxx
	py::class_<RWStepShape_RWSolidModel, std::unique_ptr<RWStepShape_RWSolidModel, Deleter<RWStepShape_RWSolidModel>>> cls_RWStepShape_RWSolidModel(mod, "RWStepShape_RWSolidModel", "Read & Write Module for SolidModel");
	cls_RWStepShape_RWSolidModel.def(py::init<>());
	cls_RWStepShape_RWSolidModel.def("ReadStep", (void (RWStepShape_RWSolidModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SolidModel> &) const ) &RWStepShape_RWSolidModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSolidModel.def("WriteStep", (void (RWStepShape_RWSolidModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SolidModel> &) const ) &RWStepShape_RWSolidModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSolidReplica.hxx
	py::class_<RWStepShape_RWSolidReplica, std::unique_ptr<RWStepShape_RWSolidReplica, Deleter<RWStepShape_RWSolidReplica>>> cls_RWStepShape_RWSolidReplica(mod, "RWStepShape_RWSolidReplica", "Read & Write Module for SolidReplica");
	cls_RWStepShape_RWSolidReplica.def(py::init<>());
	cls_RWStepShape_RWSolidReplica.def("ReadStep", (void (RWStepShape_RWSolidReplica::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SolidReplica> &) const ) &RWStepShape_RWSolidReplica::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSolidReplica.def("WriteStep", (void (RWStepShape_RWSolidReplica::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SolidReplica> &) const ) &RWStepShape_RWSolidReplica::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSolidReplica.def("Share", (void (RWStepShape_RWSolidReplica::*)(const opencascade::handle<StepShape_SolidReplica> &, Interface_EntityIterator &) const ) &RWStepShape_RWSolidReplica::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSphere.hxx
	py::class_<RWStepShape_RWSphere, std::unique_ptr<RWStepShape_RWSphere, Deleter<RWStepShape_RWSphere>>> cls_RWStepShape_RWSphere(mod, "RWStepShape_RWSphere", "Read & Write Module for Sphere");
	cls_RWStepShape_RWSphere.def(py::init<>());
	cls_RWStepShape_RWSphere.def("ReadStep", (void (RWStepShape_RWSphere::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Sphere> &) const ) &RWStepShape_RWSphere::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSphere.def("WriteStep", (void (RWStepShape_RWSphere::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Sphere> &) const ) &RWStepShape_RWSphere::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSphere.def("Share", (void (RWStepShape_RWSphere::*)(const opencascade::handle<StepShape_Sphere> &, Interface_EntityIterator &) const ) &RWStepShape_RWSphere::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSubedge.hxx
	py::class_<RWStepShape_RWSubedge, std::unique_ptr<RWStepShape_RWSubedge, Deleter<RWStepShape_RWSubedge>>> cls_RWStepShape_RWSubedge(mod, "RWStepShape_RWSubedge", "Read & Write tool for Subedge");
	cls_RWStepShape_RWSubedge.def(py::init<>());
	cls_RWStepShape_RWSubedge.def("ReadStep", (void (RWStepShape_RWSubedge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Subedge> &) const ) &RWStepShape_RWSubedge::ReadStep, "Reads Subedge", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSubedge.def("WriteStep", (void (RWStepShape_RWSubedge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Subedge> &) const ) &RWStepShape_RWSubedge::WriteStep, "Writes Subedge", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSubedge.def("Share", (void (RWStepShape_RWSubedge::*)(const opencascade::handle<StepShape_Subedge> &, Interface_EntityIterator &) const ) &RWStepShape_RWSubedge::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSubface.hxx
	py::class_<RWStepShape_RWSubface, std::unique_ptr<RWStepShape_RWSubface, Deleter<RWStepShape_RWSubface>>> cls_RWStepShape_RWSubface(mod, "RWStepShape_RWSubface", "Read & Write tool for Subface");
	cls_RWStepShape_RWSubface.def(py::init<>());
	cls_RWStepShape_RWSubface.def("ReadStep", (void (RWStepShape_RWSubface::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Subface> &) const ) &RWStepShape_RWSubface::ReadStep, "Reads Subface", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSubface.def("WriteStep", (void (RWStepShape_RWSubface::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Subface> &) const ) &RWStepShape_RWSubface::WriteStep, "Writes Subface", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSubface.def("Share", (void (RWStepShape_RWSubface::*)(const opencascade::handle<StepShape_Subface> &, Interface_EntityIterator &) const ) &RWStepShape_RWSubface::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSweptAreaSolid.hxx
	py::class_<RWStepShape_RWSweptAreaSolid, std::unique_ptr<RWStepShape_RWSweptAreaSolid, Deleter<RWStepShape_RWSweptAreaSolid>>> cls_RWStepShape_RWSweptAreaSolid(mod, "RWStepShape_RWSweptAreaSolid", "Read & Write Module for SweptAreaSolid");
	cls_RWStepShape_RWSweptAreaSolid.def(py::init<>());
	cls_RWStepShape_RWSweptAreaSolid.def("ReadStep", (void (RWStepShape_RWSweptAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SweptAreaSolid> &) const ) &RWStepShape_RWSweptAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSweptAreaSolid.def("WriteStep", (void (RWStepShape_RWSweptAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SweptAreaSolid> &) const ) &RWStepShape_RWSweptAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSweptAreaSolid.def("Share", (void (RWStepShape_RWSweptAreaSolid::*)(const opencascade::handle<StepShape_SweptAreaSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWSweptAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWSweptFaceSolid.hxx
	py::class_<RWStepShape_RWSweptFaceSolid, std::unique_ptr<RWStepShape_RWSweptFaceSolid, Deleter<RWStepShape_RWSweptFaceSolid>>> cls_RWStepShape_RWSweptFaceSolid(mod, "RWStepShape_RWSweptFaceSolid", "Read & Write Module for SweptFaceSolid");
	cls_RWStepShape_RWSweptFaceSolid.def(py::init<>());
	cls_RWStepShape_RWSweptFaceSolid.def("ReadStep", (void (RWStepShape_RWSweptFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SweptFaceSolid> &) const ) &RWStepShape_RWSweptFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWSweptFaceSolid.def("WriteStep", (void (RWStepShape_RWSweptFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SweptFaceSolid> &) const ) &RWStepShape_RWSweptFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWSweptFaceSolid.def("Share", (void (RWStepShape_RWSweptFaceSolid::*)(const opencascade::handle<StepShape_SweptFaceSolid> &, Interface_EntityIterator &) const ) &RWStepShape_RWSweptFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWToleranceValue.hxx
	py::class_<RWStepShape_RWToleranceValue, std::unique_ptr<RWStepShape_RWToleranceValue, Deleter<RWStepShape_RWToleranceValue>>> cls_RWStepShape_RWToleranceValue(mod, "RWStepShape_RWToleranceValue", "Read & Write Module for ToleranceValue");
	cls_RWStepShape_RWToleranceValue.def(py::init<>());
	cls_RWStepShape_RWToleranceValue.def("ReadStep", (void (RWStepShape_RWToleranceValue::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ToleranceValue> &) const ) &RWStepShape_RWToleranceValue::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWToleranceValue.def("WriteStep", (void (RWStepShape_RWToleranceValue::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ToleranceValue> &) const ) &RWStepShape_RWToleranceValue::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWToleranceValue.def("Share", (void (RWStepShape_RWToleranceValue::*)(const opencascade::handle<StepShape_ToleranceValue> &, Interface_EntityIterator &) const ) &RWStepShape_RWToleranceValue::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWTopologicalRepresentationItem.hxx
	py::class_<RWStepShape_RWTopologicalRepresentationItem, std::unique_ptr<RWStepShape_RWTopologicalRepresentationItem, Deleter<RWStepShape_RWTopologicalRepresentationItem>>> cls_RWStepShape_RWTopologicalRepresentationItem(mod, "RWStepShape_RWTopologicalRepresentationItem", "Read & Write Module for TopologicalRepresentationItem");
	cls_RWStepShape_RWTopologicalRepresentationItem.def(py::init<>());
	cls_RWStepShape_RWTopologicalRepresentationItem.def("ReadStep", (void (RWStepShape_RWTopologicalRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &) const ) &RWStepShape_RWTopologicalRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWTopologicalRepresentationItem.def("WriteStep", (void (RWStepShape_RWTopologicalRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &) const ) &RWStepShape_RWTopologicalRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWTorus.hxx
	py::class_<RWStepShape_RWTorus, std::unique_ptr<RWStepShape_RWTorus, Deleter<RWStepShape_RWTorus>>> cls_RWStepShape_RWTorus(mod, "RWStepShape_RWTorus", "Read & Write Module for Torus");
	cls_RWStepShape_RWTorus.def(py::init<>());
	cls_RWStepShape_RWTorus.def("ReadStep", (void (RWStepShape_RWTorus::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Torus> &) const ) &RWStepShape_RWTorus::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWTorus.def("WriteStep", (void (RWStepShape_RWTorus::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Torus> &) const ) &RWStepShape_RWTorus::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWTorus.def("Share", (void (RWStepShape_RWTorus::*)(const opencascade::handle<StepShape_Torus> &, Interface_EntityIterator &) const ) &RWStepShape_RWTorus::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWTransitionalShapeRepresentation.hxx
	py::class_<RWStepShape_RWTransitionalShapeRepresentation, std::unique_ptr<RWStepShape_RWTransitionalShapeRepresentation, Deleter<RWStepShape_RWTransitionalShapeRepresentation>>> cls_RWStepShape_RWTransitionalShapeRepresentation(mod, "RWStepShape_RWTransitionalShapeRepresentation", "Read & Write Module for TransitionalShapeRepresentation");
	cls_RWStepShape_RWTransitionalShapeRepresentation.def(py::init<>());
	cls_RWStepShape_RWTransitionalShapeRepresentation.def("ReadStep", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TransitionalShapeRepresentation> &) const ) &RWStepShape_RWTransitionalShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWTransitionalShapeRepresentation.def("WriteStep", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TransitionalShapeRepresentation> &) const ) &RWStepShape_RWTransitionalShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWTransitionalShapeRepresentation.def("Share", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(const opencascade::handle<StepShape_TransitionalShapeRepresentation> &, Interface_EntityIterator &) const ) &RWStepShape_RWTransitionalShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWTypeQualifier.hxx
	py::class_<RWStepShape_RWTypeQualifier, std::unique_ptr<RWStepShape_RWTypeQualifier, Deleter<RWStepShape_RWTypeQualifier>>> cls_RWStepShape_RWTypeQualifier(mod, "RWStepShape_RWTypeQualifier", "Read & Write Module for TypeQualifier");
	cls_RWStepShape_RWTypeQualifier.def(py::init<>());
	cls_RWStepShape_RWTypeQualifier.def("ReadStep", (void (RWStepShape_RWTypeQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TypeQualifier> &) const ) &RWStepShape_RWTypeQualifier::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWTypeQualifier.def("WriteStep", (void (RWStepShape_RWTypeQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TypeQualifier> &) const ) &RWStepShape_RWTypeQualifier::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWValueFormatTypeQualifier.hxx
	py::class_<RWStepShape_RWValueFormatTypeQualifier, std::unique_ptr<RWStepShape_RWValueFormatTypeQualifier, Deleter<RWStepShape_RWValueFormatTypeQualifier>>> cls_RWStepShape_RWValueFormatTypeQualifier(mod, "RWStepShape_RWValueFormatTypeQualifier", "Read & Write tool for ValueFormatTypeQualifier");
	cls_RWStepShape_RWValueFormatTypeQualifier.def(py::init<>());
	cls_RWStepShape_RWValueFormatTypeQualifier.def("ReadStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const ) &RWStepShape_RWValueFormatTypeQualifier::ReadStep, "Reads ValueFormatTypeQualifier", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWValueFormatTypeQualifier.def("WriteStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const ) &RWStepShape_RWValueFormatTypeQualifier::WriteStep, "Writes ValueFormatTypeQualifier", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWVertex.hxx
	py::class_<RWStepShape_RWVertex, std::unique_ptr<RWStepShape_RWVertex, Deleter<RWStepShape_RWVertex>>> cls_RWStepShape_RWVertex(mod, "RWStepShape_RWVertex", "Read & Write Module for Vertex");
	cls_RWStepShape_RWVertex.def(py::init<>());
	cls_RWStepShape_RWVertex.def("ReadStep", (void (RWStepShape_RWVertex::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Vertex> &) const ) &RWStepShape_RWVertex::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWVertex.def("WriteStep", (void (RWStepShape_RWVertex::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Vertex> &) const ) &RWStepShape_RWVertex::WriteStep, "None", py::arg("SW"), py::arg("ent"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWVertexLoop.hxx
	py::class_<RWStepShape_RWVertexLoop, std::unique_ptr<RWStepShape_RWVertexLoop, Deleter<RWStepShape_RWVertexLoop>>> cls_RWStepShape_RWVertexLoop(mod, "RWStepShape_RWVertexLoop", "Read & Write Module for VertexLoop");
	cls_RWStepShape_RWVertexLoop.def(py::init<>());
	cls_RWStepShape_RWVertexLoop.def("ReadStep", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_VertexLoop> &) const ) &RWStepShape_RWVertexLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWVertexLoop.def("WriteStep", (void (RWStepShape_RWVertexLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_VertexLoop> &) const ) &RWStepShape_RWVertexLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWVertexLoop.def("Share", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepShape_VertexLoop> &, Interface_EntityIterator &) const ) &RWStepShape_RWVertexLoop::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepShape_RWVertexPoint.hxx
	py::class_<RWStepShape_RWVertexPoint, std::unique_ptr<RWStepShape_RWVertexPoint, Deleter<RWStepShape_RWVertexPoint>>> cls_RWStepShape_RWVertexPoint(mod, "RWStepShape_RWVertexPoint", "Read & Write Module for VertexPoint");
	cls_RWStepShape_RWVertexPoint.def(py::init<>());
	cls_RWStepShape_RWVertexPoint.def("ReadStep", (void (RWStepShape_RWVertexPoint::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_VertexPoint> &) const ) &RWStepShape_RWVertexPoint::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepShape_RWVertexPoint.def("WriteStep", (void (RWStepShape_RWVertexPoint::*)(StepData_StepWriter &, const opencascade::handle<StepShape_VertexPoint> &) const ) &RWStepShape_RWVertexPoint::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepShape_RWVertexPoint.def("Share", (void (RWStepShape_RWVertexPoint::*)(const opencascade::handle<StepShape_VertexPoint> &, Interface_EntityIterator &) const ) &RWStepShape_RWVertexPoint::Share, "None", py::arg("ent"), py::arg("iter"));


}
