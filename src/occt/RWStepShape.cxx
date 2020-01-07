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

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepShape");

// CLASS: RWSTEPSHAPE_RWADVANCEDBREPSHAPEREPRESENTATION
py::class_<RWStepShape_RWAdvancedBrepShapeRepresentation> cls_RWStepShape_RWAdvancedBrepShapeRepresentation(mod, "RWStepShape_RWAdvancedBrepShapeRepresentation", "Read & Write Module for AdvancedBrepShapeRepresentation");

// Constructors
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("ReadStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("WriteStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("Share", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWADVANCEDFACE
py::class_<RWStepShape_RWAdvancedFace> cls_RWStepShape_RWAdvancedFace(mod, "RWStepShape_RWAdvancedFace", "Read & Write Module for AdvancedFace");

// Constructors
cls_RWStepShape_RWAdvancedFace.def(py::init<>());

// Methods
// cls_RWStepShape_RWAdvancedFace.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWAdvancedFace::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedFace.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWAdvancedFace::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedFace.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWAdvancedFace::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedFace.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWAdvancedFace::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedFace.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWAdvancedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedFace.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWAdvancedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWAdvancedFace.def("ReadStep", (void (RWStepShape_RWAdvancedFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AdvancedFace> &) const) &RWStepShape_RWAdvancedFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWAdvancedFace.def("WriteStep", (void (RWStepShape_RWAdvancedFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AdvancedFace> &) const) &RWStepShape_RWAdvancedFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWAdvancedFace.def("Share", (void (RWStepShape_RWAdvancedFace::*)(const opencascade::handle<StepShape_AdvancedFace> &, Interface_EntityIterator &) const) &RWStepShape_RWAdvancedFace::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWANGULARLOCATION
py::class_<RWStepShape_RWAngularLocation> cls_RWStepShape_RWAngularLocation(mod, "RWStepShape_RWAngularLocation", "Read & Write tool for AngularLocation");

// Constructors
cls_RWStepShape_RWAngularLocation.def(py::init<>());

// Methods
// cls_RWStepShape_RWAngularLocation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWAngularLocation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWAngularLocation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWAngularLocation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWAngularLocation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWAngularLocation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWAngularLocation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWAngularLocation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWAngularLocation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWAngularLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWAngularLocation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWAngularLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWAngularLocation.def("ReadStep", (void (RWStepShape_RWAngularLocation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AngularLocation> &) const) &RWStepShape_RWAngularLocation::ReadStep, "Reads AngularLocation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWAngularLocation.def("WriteStep", (void (RWStepShape_RWAngularLocation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AngularLocation> &) const) &RWStepShape_RWAngularLocation::WriteStep, "Writes AngularLocation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWAngularLocation.def("Share", (void (RWStepShape_RWAngularLocation::*)(const opencascade::handle<StepShape_AngularLocation> &, Interface_EntityIterator &) const) &RWStepShape_RWAngularLocation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWANGULARSIZE
py::class_<RWStepShape_RWAngularSize> cls_RWStepShape_RWAngularSize(mod, "RWStepShape_RWAngularSize", "Read & Write tool for AngularSize");

// Constructors
cls_RWStepShape_RWAngularSize.def(py::init<>());

// Methods
// cls_RWStepShape_RWAngularSize.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWAngularSize::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWAngularSize.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWAngularSize::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWAngularSize.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWAngularSize::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWAngularSize.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWAngularSize::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWAngularSize.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWAngularSize::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWAngularSize.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWAngularSize::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWAngularSize.def("ReadStep", (void (RWStepShape_RWAngularSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AngularSize> &) const) &RWStepShape_RWAngularSize::ReadStep, "Reads AngularSize", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWAngularSize.def("WriteStep", (void (RWStepShape_RWAngularSize::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AngularSize> &) const) &RWStepShape_RWAngularSize::WriteStep, "Writes AngularSize", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWAngularSize.def("Share", (void (RWStepShape_RWAngularSize::*)(const opencascade::handle<StepShape_AngularSize> &, Interface_EntityIterator &) const) &RWStepShape_RWAngularSize::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWBLOCK
py::class_<RWStepShape_RWBlock> cls_RWStepShape_RWBlock(mod, "RWStepShape_RWBlock", "Read & Write Module for Block");

// Constructors
cls_RWStepShape_RWBlock.def(py::init<>());

// Methods
// cls_RWStepShape_RWBlock.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWBlock::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWBlock.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWBlock::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWBlock.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWBlock::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWBlock.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWBlock::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWBlock.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWBlock::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWBlock.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWBlock::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWBlock.def("ReadStep", (void (RWStepShape_RWBlock::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Block> &) const) &RWStepShape_RWBlock::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWBlock.def("WriteStep", (void (RWStepShape_RWBlock::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Block> &) const) &RWStepShape_RWBlock::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWBlock.def("Share", (void (RWStepShape_RWBlock::*)(const opencascade::handle<StepShape_Block> &, Interface_EntityIterator &) const) &RWStepShape_RWBlock::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWBOOLEANRESULT
py::class_<RWStepShape_RWBooleanResult> cls_RWStepShape_RWBooleanResult(mod, "RWStepShape_RWBooleanResult", "Read & Write Module for BooleanResult");

// Constructors
cls_RWStepShape_RWBooleanResult.def(py::init<>());

// Methods
// cls_RWStepShape_RWBooleanResult.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWBooleanResult::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWBooleanResult.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWBooleanResult::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWBooleanResult.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWBooleanResult::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWBooleanResult.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWBooleanResult::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWBooleanResult.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWBooleanResult::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWBooleanResult.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWBooleanResult::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWBooleanResult.def("ReadStep", (void (RWStepShape_RWBooleanResult::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BooleanResult> &) const) &RWStepShape_RWBooleanResult::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWBooleanResult.def("WriteStep", (void (RWStepShape_RWBooleanResult::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BooleanResult> &) const) &RWStepShape_RWBooleanResult::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWBooleanResult.def("Share", (void (RWStepShape_RWBooleanResult::*)(const opencascade::handle<StepShape_BooleanResult> &, Interface_EntityIterator &) const) &RWStepShape_RWBooleanResult::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWBOXDOMAIN
py::class_<RWStepShape_RWBoxDomain> cls_RWStepShape_RWBoxDomain(mod, "RWStepShape_RWBoxDomain", "Read & Write Module for BoxDomain");

// Constructors
cls_RWStepShape_RWBoxDomain.def(py::init<>());

// Methods
// cls_RWStepShape_RWBoxDomain.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWBoxDomain::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWBoxDomain.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWBoxDomain::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWBoxDomain.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWBoxDomain::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWBoxDomain.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWBoxDomain::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWBoxDomain.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWBoxDomain::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWBoxDomain.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWBoxDomain::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWBoxDomain.def("ReadStep", (void (RWStepShape_RWBoxDomain::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BoxDomain> &) const) &RWStepShape_RWBoxDomain::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWBoxDomain.def("WriteStep", (void (RWStepShape_RWBoxDomain::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BoxDomain> &) const) &RWStepShape_RWBoxDomain::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWBoxDomain.def("Share", (void (RWStepShape_RWBoxDomain::*)(const opencascade::handle<StepShape_BoxDomain> &, Interface_EntityIterator &) const) &RWStepShape_RWBoxDomain::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWBOXEDHALFSPACE
py::class_<RWStepShape_RWBoxedHalfSpace> cls_RWStepShape_RWBoxedHalfSpace(mod, "RWStepShape_RWBoxedHalfSpace", "Read & Write Module for BoxedHalfSpace");

// Constructors
cls_RWStepShape_RWBoxedHalfSpace.def(py::init<>());

// Methods
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWBoxedHalfSpace::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWBoxedHalfSpace::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWBoxedHalfSpace::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWBoxedHalfSpace::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWBoxedHalfSpace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWBoxedHalfSpace.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWBoxedHalfSpace::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWBoxedHalfSpace.def("ReadStep", (void (RWStepShape_RWBoxedHalfSpace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BoxedHalfSpace> &) const) &RWStepShape_RWBoxedHalfSpace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWBoxedHalfSpace.def("WriteStep", (void (RWStepShape_RWBoxedHalfSpace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BoxedHalfSpace> &) const) &RWStepShape_RWBoxedHalfSpace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWBoxedHalfSpace.def("Share", (void (RWStepShape_RWBoxedHalfSpace::*)(const opencascade::handle<StepShape_BoxedHalfSpace> &, Interface_EntityIterator &) const) &RWStepShape_RWBoxedHalfSpace::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWBREPWITHVOIDS
py::class_<RWStepShape_RWBrepWithVoids> cls_RWStepShape_RWBrepWithVoids(mod, "RWStepShape_RWBrepWithVoids", "Read & Write Module for BrepWithVoids");

// Constructors
cls_RWStepShape_RWBrepWithVoids.def(py::init<>());

// Methods
// cls_RWStepShape_RWBrepWithVoids.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWBrepWithVoids::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWBrepWithVoids.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWBrepWithVoids::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWBrepWithVoids.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWBrepWithVoids::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWBrepWithVoids.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWBrepWithVoids::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWBrepWithVoids.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWBrepWithVoids::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWBrepWithVoids.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWBrepWithVoids::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWBrepWithVoids.def("ReadStep", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_BrepWithVoids> &) const) &RWStepShape_RWBrepWithVoids::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWBrepWithVoids.def("WriteStep", (void (RWStepShape_RWBrepWithVoids::*)(StepData_StepWriter &, const opencascade::handle<StepShape_BrepWithVoids> &) const) &RWStepShape_RWBrepWithVoids::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWBrepWithVoids.def("Share", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &, Interface_EntityIterator &) const) &RWStepShape_RWBrepWithVoids::Share, "None", py::arg("ent"), py::arg("iter"));
cls_RWStepShape_RWBrepWithVoids.def("Check", (void (RWStepShape_RWBrepWithVoids::*)(const opencascade::handle<StepShape_BrepWithVoids> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepShape_RWBrepWithVoids::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

// CLASS: RWSTEPSHAPE_RWCLOSEDSHELL
py::class_<RWStepShape_RWClosedShell> cls_RWStepShape_RWClosedShell(mod, "RWStepShape_RWClosedShell", "Read & Write Module for ClosedShell");

// Constructors
cls_RWStepShape_RWClosedShell.def(py::init<>());

// Methods
// cls_RWStepShape_RWClosedShell.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWClosedShell::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWClosedShell.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWClosedShell::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWClosedShell.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWClosedShell::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWClosedShell.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWClosedShell::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWClosedShell.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWClosedShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWClosedShell.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWClosedShell::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWClosedShell.def("ReadStep", (void (RWStepShape_RWClosedShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ClosedShell> &) const) &RWStepShape_RWClosedShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWClosedShell.def("WriteStep", (void (RWStepShape_RWClosedShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ClosedShell> &) const) &RWStepShape_RWClosedShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWClosedShell.def("Share", (void (RWStepShape_RWClosedShell::*)(const opencascade::handle<StepShape_ClosedShell> &, Interface_EntityIterator &) const) &RWStepShape_RWClosedShell::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCOMPOUNDSHAPEREPRESENTATION
py::class_<RWStepShape_RWCompoundShapeRepresentation> cls_RWStepShape_RWCompoundShapeRepresentation(mod, "RWStepShape_RWCompoundShapeRepresentation", "Read & Write tool for CompoundShapeRepresentation");

// Constructors
cls_RWStepShape_RWCompoundShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWCompoundShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWCompoundShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWCompoundShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWCompoundShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWCompoundShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWCompoundShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWCompoundShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWCompoundShapeRepresentation.def("ReadStep", (void (RWStepShape_RWCompoundShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CompoundShapeRepresentation> &) const) &RWStepShape_RWCompoundShapeRepresentation::ReadStep, "Reads CompoundShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWCompoundShapeRepresentation.def("WriteStep", (void (RWStepShape_RWCompoundShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CompoundShapeRepresentation> &) const) &RWStepShape_RWCompoundShapeRepresentation::WriteStep, "Writes CompoundShapeRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWCompoundShapeRepresentation.def("Share", (void (RWStepShape_RWCompoundShapeRepresentation::*)(const opencascade::handle<StepShape_CompoundShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWCompoundShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCONNECTEDEDGESET
py::class_<RWStepShape_RWConnectedEdgeSet> cls_RWStepShape_RWConnectedEdgeSet(mod, "RWStepShape_RWConnectedEdgeSet", "Read & Write tool for ConnectedEdgeSet");

// Constructors
cls_RWStepShape_RWConnectedEdgeSet.def(py::init<>());

// Methods
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWConnectedEdgeSet::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWConnectedEdgeSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWConnectedEdgeSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWConnectedEdgeSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWConnectedEdgeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWConnectedEdgeSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWConnectedEdgeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWConnectedEdgeSet.def("ReadStep", (void (RWStepShape_RWConnectedEdgeSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedEdgeSet> &) const) &RWStepShape_RWConnectedEdgeSet::ReadStep, "Reads ConnectedEdgeSet", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWConnectedEdgeSet.def("WriteStep", (void (RWStepShape_RWConnectedEdgeSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedEdgeSet> &) const) &RWStepShape_RWConnectedEdgeSet::WriteStep, "Writes ConnectedEdgeSet", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWConnectedEdgeSet.def("Share", (void (RWStepShape_RWConnectedEdgeSet::*)(const opencascade::handle<StepShape_ConnectedEdgeSet> &, Interface_EntityIterator &) const) &RWStepShape_RWConnectedEdgeSet::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCONNECTEDFACESET
py::class_<RWStepShape_RWConnectedFaceSet> cls_RWStepShape_RWConnectedFaceSet(mod, "RWStepShape_RWConnectedFaceSet", "Read & Write Module for ConnectedFaceSet");

// Constructors
cls_RWStepShape_RWConnectedFaceSet.def(py::init<>());

// Methods
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceSet::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWConnectedFaceSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWConnectedFaceSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWConnectedFaceSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWConnectedFaceSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWConnectedFaceSet.def("ReadStep", (void (RWStepShape_RWConnectedFaceSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceSet> &) const) &RWStepShape_RWConnectedFaceSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceSet.def("WriteStep", (void (RWStepShape_RWConnectedFaceSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceSet> &) const) &RWStepShape_RWConnectedFaceSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceSet.def("Share", (void (RWStepShape_RWConnectedFaceSet::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &, Interface_EntityIterator &) const) &RWStepShape_RWConnectedFaceSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCONNECTEDFACESHAPEREPRESENTATION
py::class_<RWStepShape_RWConnectedFaceShapeRepresentation> cls_RWStepShape_RWConnectedFaceShapeRepresentation(mod, "RWStepShape_RWConnectedFaceShapeRepresentation", "Read & Write tool for ConnectedFaceShapeRepresentation");

// Constructors
cls_RWStepShape_RWConnectedFaceShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWConnectedFaceShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &) const) &RWStepShape_RWConnectedFaceShapeRepresentation::ReadStep, "Reads ConnectedFaceShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &) const) &RWStepShape_RWConnectedFaceShapeRepresentation::WriteStep, "Writes ConnectedFaceShapeRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceShapeRepresentation.def("Share", (void (RWStepShape_RWConnectedFaceShapeRepresentation::*)(const opencascade::handle<StepShape_ConnectedFaceShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWConnectedFaceShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCONNECTEDFACESUBSET
py::class_<RWStepShape_RWConnectedFaceSubSet> cls_RWStepShape_RWConnectedFaceSubSet(mod, "RWStepShape_RWConnectedFaceSubSet", "Read & Write tool for ConnectedFaceSubSet");

// Constructors
cls_RWStepShape_RWConnectedFaceSubSet.def(py::init<>());

// Methods
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceSubSet::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWConnectedFaceSubSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWConnectedFaceSubSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWConnectedFaceSubSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWConnectedFaceSubSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWConnectedFaceSubSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWConnectedFaceSubSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWConnectedFaceSubSet.def("ReadStep", (void (RWStepShape_RWConnectedFaceSubSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ConnectedFaceSubSet> &) const) &RWStepShape_RWConnectedFaceSubSet::ReadStep, "Reads ConnectedFaceSubSet", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceSubSet.def("WriteStep", (void (RWStepShape_RWConnectedFaceSubSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ConnectedFaceSubSet> &) const) &RWStepShape_RWConnectedFaceSubSet::WriteStep, "Writes ConnectedFaceSubSet", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWConnectedFaceSubSet.def("Share", (void (RWStepShape_RWConnectedFaceSubSet::*)(const opencascade::handle<StepShape_ConnectedFaceSubSet> &, Interface_EntityIterator &) const) &RWStepShape_RWConnectedFaceSubSet::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCONTEXTDEPENDENTSHAPEREPRESENTATION
py::class_<RWStepShape_RWContextDependentShapeRepresentation> cls_RWStepShape_RWContextDependentShapeRepresentation(mod, "RWStepShape_RWContextDependentShapeRepresentation", "Read & Write Module for ContextDependentShapeRepresentation");

// Constructors
cls_RWStepShape_RWContextDependentShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWContextDependentShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWContextDependentShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWContextDependentShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWContextDependentShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWContextDependentShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWContextDependentShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWContextDependentShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWContextDependentShapeRepresentation.def("ReadStep", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &) const) &RWStepShape_RWContextDependentShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWContextDependentShapeRepresentation.def("WriteStep", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &) const) &RWStepShape_RWContextDependentShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWContextDependentShapeRepresentation.def("Share", (void (RWStepShape_RWContextDependentShapeRepresentation::*)(const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWContextDependentShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCSGSHAPEREPRESENTATION
py::class_<RWStepShape_RWCsgShapeRepresentation> cls_RWStepShape_RWCsgShapeRepresentation(mod, "RWStepShape_RWCsgShapeRepresentation", "Read & Write Module for CsgShapeRepresentation");

// Constructors
cls_RWStepShape_RWCsgShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWCsgShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWCsgShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWCsgShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWCsgShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWCsgShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWCsgShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWCsgShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWCsgShapeRepresentation.def("ReadStep", (void (RWStepShape_RWCsgShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CsgShapeRepresentation> &) const) &RWStepShape_RWCsgShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWCsgShapeRepresentation.def("WriteStep", (void (RWStepShape_RWCsgShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CsgShapeRepresentation> &) const) &RWStepShape_RWCsgShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWCsgShapeRepresentation.def("Share", (void (RWStepShape_RWCsgShapeRepresentation::*)(const opencascade::handle<StepShape_CsgShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWCsgShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWCSGSOLID
py::class_<RWStepShape_RWCsgSolid> cls_RWStepShape_RWCsgSolid(mod, "RWStepShape_RWCsgSolid", "Read & Write Module for CsgSolid");

// Constructors
cls_RWStepShape_RWCsgSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWCsgSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWCsgSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWCsgSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWCsgSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWCsgSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWCsgSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWCsgSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWCsgSolid.def("ReadStep", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CsgSolid> &) const) &RWStepShape_RWCsgSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWCsgSolid.def("WriteStep", (void (RWStepShape_RWCsgSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CsgSolid> &) const) &RWStepShape_RWCsgSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWCsgSolid.def("Share", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepShape_CsgSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWCsgSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDEFINITIONALREPRESENTATIONANDSHAPEREPRESENTATION
py::class_<RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation> cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation(mod, "RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation", "Read & Write Module for ConversionBasedUnitAndLengthUnit");

// Constructors
cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("ReadStep", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &) const) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("WriteStep", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &) const) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation.def("Share", (void (RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::*)(const opencascade::handle<StepShape_DefinitionalRepresentationAndShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDIMENSIONALCHARACTERISTICREPRESENTATION
py::class_<RWStepShape_RWDimensionalCharacteristicRepresentation> cls_RWStepShape_RWDimensionalCharacteristicRepresentation(mod, "RWStepShape_RWDimensionalCharacteristicRepresentation", "Read & Write tool for DimensionalCharacteristicRepresentation");

// Constructors
cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDimensionalCharacteristicRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("ReadStep", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &) const) &RWStepShape_RWDimensionalCharacteristicRepresentation::ReadStep, "Reads DimensionalCharacteristicRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("WriteStep", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &) const) &RWStepShape_RWDimensionalCharacteristicRepresentation::WriteStep, "Writes DimensionalCharacteristicRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDimensionalCharacteristicRepresentation.def("Share", (void (RWStepShape_RWDimensionalCharacteristicRepresentation::*)(const opencascade::handle<StepShape_DimensionalCharacteristicRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWDimensionalCharacteristicRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDIMENSIONALLOCATION
py::class_<RWStepShape_RWDimensionalLocation> cls_RWStepShape_RWDimensionalLocation(mod, "RWStepShape_RWDimensionalLocation", "Read & Write tool for DimensionalLocation");

// Constructors
cls_RWStepShape_RWDimensionalLocation.def(py::init<>());

// Methods
// cls_RWStepShape_RWDimensionalLocation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDimensionalLocation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalLocation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDimensionalLocation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDimensionalLocation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalLocation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDimensionalLocation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDimensionalLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDimensionalLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDimensionalLocation.def("ReadStep", (void (RWStepShape_RWDimensionalLocation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalLocation> &) const) &RWStepShape_RWDimensionalLocation::ReadStep, "Reads DimensionalLocation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDimensionalLocation.def("WriteStep", (void (RWStepShape_RWDimensionalLocation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalLocation> &) const) &RWStepShape_RWDimensionalLocation::WriteStep, "Writes DimensionalLocation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDimensionalLocation.def("Share", (void (RWStepShape_RWDimensionalLocation::*)(const opencascade::handle<StepShape_DimensionalLocation> &, Interface_EntityIterator &) const) &RWStepShape_RWDimensionalLocation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDIMENSIONALLOCATIONWITHPATH
py::class_<RWStepShape_RWDimensionalLocationWithPath> cls_RWStepShape_RWDimensionalLocationWithPath(mod, "RWStepShape_RWDimensionalLocationWithPath", "Read & Write tool for DimensionalLocationWithPath");

// Constructors
cls_RWStepShape_RWDimensionalLocationWithPath.def(py::init<>());

// Methods
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDimensionalLocationWithPath::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDimensionalLocationWithPath::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDimensionalLocationWithPath::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDimensionalLocationWithPath::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDimensionalLocationWithPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalLocationWithPath.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDimensionalLocationWithPath::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDimensionalLocationWithPath.def("ReadStep", (void (RWStepShape_RWDimensionalLocationWithPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalLocationWithPath> &) const) &RWStepShape_RWDimensionalLocationWithPath::ReadStep, "Reads DimensionalLocationWithPath", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDimensionalLocationWithPath.def("WriteStep", (void (RWStepShape_RWDimensionalLocationWithPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalLocationWithPath> &) const) &RWStepShape_RWDimensionalLocationWithPath::WriteStep, "Writes DimensionalLocationWithPath", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDimensionalLocationWithPath.def("Share", (void (RWStepShape_RWDimensionalLocationWithPath::*)(const opencascade::handle<StepShape_DimensionalLocationWithPath> &, Interface_EntityIterator &) const) &RWStepShape_RWDimensionalLocationWithPath::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDIMENSIONALSIZE
py::class_<RWStepShape_RWDimensionalSize> cls_RWStepShape_RWDimensionalSize(mod, "RWStepShape_RWDimensionalSize", "Read & Write tool for DimensionalSize");

// Constructors
cls_RWStepShape_RWDimensionalSize.def(py::init<>());

// Methods
// cls_RWStepShape_RWDimensionalSize.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDimensionalSize::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalSize.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDimensionalSize::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSize.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDimensionalSize::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalSize.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDimensionalSize::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSize.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDimensionalSize::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSize.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDimensionalSize::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDimensionalSize.def("ReadStep", (void (RWStepShape_RWDimensionalSize::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalSize> &) const) &RWStepShape_RWDimensionalSize::ReadStep, "Reads DimensionalSize", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDimensionalSize.def("WriteStep", (void (RWStepShape_RWDimensionalSize::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalSize> &) const) &RWStepShape_RWDimensionalSize::WriteStep, "Writes DimensionalSize", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDimensionalSize.def("Share", (void (RWStepShape_RWDimensionalSize::*)(const opencascade::handle<StepShape_DimensionalSize> &, Interface_EntityIterator &) const) &RWStepShape_RWDimensionalSize::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWDIMENSIONALSIZEWITHPATH
py::class_<RWStepShape_RWDimensionalSizeWithPath> cls_RWStepShape_RWDimensionalSizeWithPath(mod, "RWStepShape_RWDimensionalSizeWithPath", "Read & Write tool for DimensionalSizeWithPath");

// Constructors
cls_RWStepShape_RWDimensionalSizeWithPath.def(py::init<>());

// Methods
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWDimensionalSizeWithPath::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWDimensionalSizeWithPath::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWDimensionalSizeWithPath::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWDimensionalSizeWithPath::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWDimensionalSizeWithPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWDimensionalSizeWithPath.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWDimensionalSizeWithPath::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWDimensionalSizeWithPath.def("ReadStep", (void (RWStepShape_RWDimensionalSizeWithPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_DimensionalSizeWithPath> &) const) &RWStepShape_RWDimensionalSizeWithPath::ReadStep, "Reads DimensionalSizeWithPath", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWDimensionalSizeWithPath.def("WriteStep", (void (RWStepShape_RWDimensionalSizeWithPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_DimensionalSizeWithPath> &) const) &RWStepShape_RWDimensionalSizeWithPath::WriteStep, "Writes DimensionalSizeWithPath", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWDimensionalSizeWithPath.def("Share", (void (RWStepShape_RWDimensionalSizeWithPath::*)(const opencascade::handle<StepShape_DimensionalSizeWithPath> &, Interface_EntityIterator &) const) &RWStepShape_RWDimensionalSizeWithPath::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWEDGE
py::class_<RWStepShape_RWEdge> cls_RWStepShape_RWEdge(mod, "RWStepShape_RWEdge", "Read & Write Module for Edge");

// Constructors
cls_RWStepShape_RWEdge.def(py::init<>());

// Methods
// cls_RWStepShape_RWEdge.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWEdge::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWEdge.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWEdge::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdge.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWEdge::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWEdge.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWEdge::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdge.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWEdge.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWEdge.def("ReadStep", (void (RWStepShape_RWEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Edge> &) const) &RWStepShape_RWEdge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWEdge.def("WriteStep", (void (RWStepShape_RWEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Edge> &) const) &RWStepShape_RWEdge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWEdge.def("Share", (void (RWStepShape_RWEdge::*)(const opencascade::handle<StepShape_Edge> &, Interface_EntityIterator &) const) &RWStepShape_RWEdge::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWEDGEBASEDWIREFRAMEMODEL
py::class_<RWStepShape_RWEdgeBasedWireframeModel> cls_RWStepShape_RWEdgeBasedWireframeModel(mod, "RWStepShape_RWEdgeBasedWireframeModel", "Read & Write tool for EdgeBasedWireframeModel");

// Constructors
cls_RWStepShape_RWEdgeBasedWireframeModel.def(py::init<>());

// Methods
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWEdgeBasedWireframeModel::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWEdgeBasedWireframeModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWEdgeBasedWireframeModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWEdgeBasedWireframeModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWEdgeBasedWireframeModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWEdgeBasedWireframeModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWEdgeBasedWireframeModel.def("ReadStep", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeBasedWireframeModel> &) const) &RWStepShape_RWEdgeBasedWireframeModel::ReadStep, "Reads EdgeBasedWireframeModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWEdgeBasedWireframeModel.def("WriteStep", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeBasedWireframeModel> &) const) &RWStepShape_RWEdgeBasedWireframeModel::WriteStep, "Writes EdgeBasedWireframeModel", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWEdgeBasedWireframeModel.def("Share", (void (RWStepShape_RWEdgeBasedWireframeModel::*)(const opencascade::handle<StepShape_EdgeBasedWireframeModel> &, Interface_EntityIterator &) const) &RWStepShape_RWEdgeBasedWireframeModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWEDGEBASEDWIREFRAMESHAPEREPRESENTATION
py::class_<RWStepShape_RWEdgeBasedWireframeShapeRepresentation> cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation(mod, "RWStepShape_RWEdgeBasedWireframeShapeRepresentation", "Read & Write tool for EdgeBasedWireframeShapeRepresentation");

// Constructors
cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("ReadStep", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &) const) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::ReadStep, "Reads EdgeBasedWireframeShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("WriteStep", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &) const) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::WriteStep, "Writes EdgeBasedWireframeShapeRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWEdgeBasedWireframeShapeRepresentation.def("Share", (void (RWStepShape_RWEdgeBasedWireframeShapeRepresentation::*)(const opencascade::handle<StepShape_EdgeBasedWireframeShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWEdgeBasedWireframeShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWEDGECURVE
py::class_<RWStepShape_RWEdgeCurve> cls_RWStepShape_RWEdgeCurve(mod, "RWStepShape_RWEdgeCurve", "Read & Write Module for EdgeCurve Check added by CKY , 7-OCT-1996");

// Constructors
cls_RWStepShape_RWEdgeCurve.def(py::init<>());

// Methods
// cls_RWStepShape_RWEdgeCurve.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWEdgeCurve::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeCurve.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWEdgeCurve::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeCurve.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWEdgeCurve::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeCurve.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWEdgeCurve::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeCurve.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWEdgeCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWEdgeCurve.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWEdgeCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWEdgeCurve.def("ReadStep", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeCurve> &) const) &RWStepShape_RWEdgeCurve::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWEdgeCurve.def("WriteStep", (void (RWStepShape_RWEdgeCurve::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeCurve> &) const) &RWStepShape_RWEdgeCurve::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWEdgeCurve.def("Share", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepShape_EdgeCurve> &, Interface_EntityIterator &) const) &RWStepShape_RWEdgeCurve::Share, "None", py::arg("ent"), py::arg("iter"));
cls_RWStepShape_RWEdgeCurve.def("Check", (void (RWStepShape_RWEdgeCurve::*)(const opencascade::handle<StepShape_EdgeCurve> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepShape_RWEdgeCurve::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

// CLASS: RWSTEPSHAPE_RWEDGELOOP
py::class_<RWStepShape_RWEdgeLoop> cls_RWStepShape_RWEdgeLoop(mod, "RWStepShape_RWEdgeLoop", "Read & Write Module for EdgeLoop Check added by CKY , 7-OCT-1996");

// Constructors
cls_RWStepShape_RWEdgeLoop.def(py::init<>());

// Methods
// cls_RWStepShape_RWEdgeLoop.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWEdgeLoop::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeLoop.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWEdgeLoop::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeLoop.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWEdgeLoop::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWEdgeLoop.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWEdgeLoop::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWEdgeLoop.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWEdgeLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWEdgeLoop.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWEdgeLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWEdgeLoop.def("ReadStep", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_EdgeLoop> &) const) &RWStepShape_RWEdgeLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWEdgeLoop.def("WriteStep", (void (RWStepShape_RWEdgeLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_EdgeLoop> &) const) &RWStepShape_RWEdgeLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWEdgeLoop.def("Share", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepShape_EdgeLoop> &, Interface_EntityIterator &) const) &RWStepShape_RWEdgeLoop::Share, "None", py::arg("ent"), py::arg("iter"));
cls_RWStepShape_RWEdgeLoop.def("Check", (void (RWStepShape_RWEdgeLoop::*)(const opencascade::handle<StepShape_EdgeLoop> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepShape_RWEdgeLoop::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

// CLASS: RWSTEPSHAPE_RWEXTRUDEDAREASOLID
py::class_<RWStepShape_RWExtrudedAreaSolid> cls_RWStepShape_RWExtrudedAreaSolid(mod, "RWStepShape_RWExtrudedAreaSolid", "Read & Write Module for ExtrudedAreaSolid");

// Constructors
cls_RWStepShape_RWExtrudedAreaSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWExtrudedAreaSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWExtrudedAreaSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWExtrudedAreaSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWExtrudedAreaSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWExtrudedAreaSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedAreaSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWExtrudedAreaSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWExtrudedAreaSolid.def("ReadStep", (void (RWStepShape_RWExtrudedAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ExtrudedAreaSolid> &) const) &RWStepShape_RWExtrudedAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWExtrudedAreaSolid.def("WriteStep", (void (RWStepShape_RWExtrudedAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ExtrudedAreaSolid> &) const) &RWStepShape_RWExtrudedAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWExtrudedAreaSolid.def("Share", (void (RWStepShape_RWExtrudedAreaSolid::*)(const opencascade::handle<StepShape_ExtrudedAreaSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWExtrudedAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWEXTRUDEDFACESOLID
py::class_<RWStepShape_RWExtrudedFaceSolid> cls_RWStepShape_RWExtrudedFaceSolid(mod, "RWStepShape_RWExtrudedFaceSolid", "Read & Write Module for ExtrudedFaceSolid");

// Constructors
cls_RWStepShape_RWExtrudedFaceSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWExtrudedFaceSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWExtrudedFaceSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWExtrudedFaceSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWExtrudedFaceSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWExtrudedFaceSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWExtrudedFaceSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWExtrudedFaceSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWExtrudedFaceSolid.def("ReadStep", (void (RWStepShape_RWExtrudedFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ExtrudedFaceSolid> &) const) &RWStepShape_RWExtrudedFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWExtrudedFaceSolid.def("WriteStep", (void (RWStepShape_RWExtrudedFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ExtrudedFaceSolid> &) const) &RWStepShape_RWExtrudedFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWExtrudedFaceSolid.def("Share", (void (RWStepShape_RWExtrudedFaceSolid::*)(const opencascade::handle<StepShape_ExtrudedFaceSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWExtrudedFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACE
py::class_<RWStepShape_RWFace> cls_RWStepShape_RWFace(mod, "RWStepShape_RWFace", "Read & Write Module for Face");

// Constructors
cls_RWStepShape_RWFace.def(py::init<>());

// Methods
// cls_RWStepShape_RWFace.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFace::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFace.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFace::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFace.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFace::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFace.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFace::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFace.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFace.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFace::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFace.def("ReadStep", (void (RWStepShape_RWFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Face> &) const) &RWStepShape_RWFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFace.def("WriteStep", (void (RWStepShape_RWFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Face> &) const) &RWStepShape_RWFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFace.def("Share", (void (RWStepShape_RWFace::*)(const opencascade::handle<StepShape_Face> &, Interface_EntityIterator &) const) &RWStepShape_RWFace::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACEBASEDSURFACEMODEL
py::class_<RWStepShape_RWFaceBasedSurfaceModel> cls_RWStepShape_RWFaceBasedSurfaceModel(mod, "RWStepShape_RWFaceBasedSurfaceModel", "Read & Write tool for FaceBasedSurfaceModel");

// Constructors
cls_RWStepShape_RWFaceBasedSurfaceModel.def(py::init<>());

// Methods
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFaceBasedSurfaceModel::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFaceBasedSurfaceModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFaceBasedSurfaceModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFaceBasedSurfaceModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFaceBasedSurfaceModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFaceBasedSurfaceModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFaceBasedSurfaceModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFaceBasedSurfaceModel.def("ReadStep", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceBasedSurfaceModel> &) const) &RWStepShape_RWFaceBasedSurfaceModel::ReadStep, "Reads FaceBasedSurfaceModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFaceBasedSurfaceModel.def("WriteStep", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceBasedSurfaceModel> &) const) &RWStepShape_RWFaceBasedSurfaceModel::WriteStep, "Writes FaceBasedSurfaceModel", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFaceBasedSurfaceModel.def("Share", (void (RWStepShape_RWFaceBasedSurfaceModel::*)(const opencascade::handle<StepShape_FaceBasedSurfaceModel> &, Interface_EntityIterator &) const) &RWStepShape_RWFaceBasedSurfaceModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACEBOUND
py::class_<RWStepShape_RWFaceBound> cls_RWStepShape_RWFaceBound(mod, "RWStepShape_RWFaceBound", "Read & Write Module for FaceBound Check added by CKY , 7-OCT-1996");

// Constructors
cls_RWStepShape_RWFaceBound.def(py::init<>());

// Methods
// cls_RWStepShape_RWFaceBound.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFaceBound::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFaceBound::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFaceBound::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFaceBound::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFaceBound::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFaceBound.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFaceBound::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFaceBound.def("ReadStep", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceBound> &) const) &RWStepShape_RWFaceBound::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFaceBound.def("WriteStep", (void (RWStepShape_RWFaceBound::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceBound> &) const) &RWStepShape_RWFaceBound::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFaceBound.def("Share", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, Interface_EntityIterator &) const) &RWStepShape_RWFaceBound::Share, "None", py::arg("ent"), py::arg("iter"));
cls_RWStepShape_RWFaceBound.def("Check", (void (RWStepShape_RWFaceBound::*)(const opencascade::handle<StepShape_FaceBound> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &RWStepShape_RWFaceBound::Check, "None", py::arg("ent"), py::arg("shares"), py::arg("ach"));

// CLASS: RWSTEPSHAPE_RWFACEOUTERBOUND
py::class_<RWStepShape_RWFaceOuterBound> cls_RWStepShape_RWFaceOuterBound(mod, "RWStepShape_RWFaceOuterBound", "Read & Write Module for FaceOuterBound");

// Constructors
cls_RWStepShape_RWFaceOuterBound.def(py::init<>());

// Methods
// cls_RWStepShape_RWFaceOuterBound.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFaceOuterBound::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceOuterBound.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFaceOuterBound::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceOuterBound.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFaceOuterBound::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceOuterBound.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFaceOuterBound::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceOuterBound.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFaceOuterBound::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFaceOuterBound.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFaceOuterBound::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFaceOuterBound.def("ReadStep", (void (RWStepShape_RWFaceOuterBound::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceOuterBound> &) const) &RWStepShape_RWFaceOuterBound::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFaceOuterBound.def("WriteStep", (void (RWStepShape_RWFaceOuterBound::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceOuterBound> &) const) &RWStepShape_RWFaceOuterBound::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFaceOuterBound.def("Share", (void (RWStepShape_RWFaceOuterBound::*)(const opencascade::handle<StepShape_FaceOuterBound> &, Interface_EntityIterator &) const) &RWStepShape_RWFaceOuterBound::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACESURFACE
py::class_<RWStepShape_RWFaceSurface> cls_RWStepShape_RWFaceSurface(mod, "RWStepShape_RWFaceSurface", "Read & Write Module for FaceSurface");

// Constructors
cls_RWStepShape_RWFaceSurface.def(py::init<>());

// Methods
// cls_RWStepShape_RWFaceSurface.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFaceSurface::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceSurface.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFaceSurface::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceSurface.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFaceSurface::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFaceSurface.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFaceSurface::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFaceSurface.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFaceSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFaceSurface.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFaceSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFaceSurface.def("ReadStep", (void (RWStepShape_RWFaceSurface::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FaceSurface> &) const) &RWStepShape_RWFaceSurface::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFaceSurface.def("WriteStep", (void (RWStepShape_RWFaceSurface::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FaceSurface> &) const) &RWStepShape_RWFaceSurface::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFaceSurface.def("Share", (void (RWStepShape_RWFaceSurface::*)(const opencascade::handle<StepShape_FaceSurface> &, Interface_EntityIterator &) const) &RWStepShape_RWFaceSurface::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACETEDBREP
py::class_<RWStepShape_RWFacetedBrep> cls_RWStepShape_RWFacetedBrep(mod, "RWStepShape_RWFacetedBrep", "Read & Write Module for FacetedBrep");

// Constructors
cls_RWStepShape_RWFacetedBrep.def(py::init<>());

// Methods
// cls_RWStepShape_RWFacetedBrep.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrep::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrep.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFacetedBrep::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrep.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrep::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrep.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFacetedBrep::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrep.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFacetedBrep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrep.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFacetedBrep::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFacetedBrep.def("ReadStep", (void (RWStepShape_RWFacetedBrep::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrep> &) const) &RWStepShape_RWFacetedBrep::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrep.def("WriteStep", (void (RWStepShape_RWFacetedBrep::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrep> &) const) &RWStepShape_RWFacetedBrep::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrep.def("Share", (void (RWStepShape_RWFacetedBrep::*)(const opencascade::handle<StepShape_FacetedBrep> &, Interface_EntityIterator &) const) &RWStepShape_RWFacetedBrep::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACETEDBREPANDBREPWITHVOIDS
py::class_<RWStepShape_RWFacetedBrepAndBrepWithVoids> cls_RWStepShape_RWFacetedBrepAndBrepWithVoids(mod, "RWStepShape_RWFacetedBrepAndBrepWithVoids", "Read & Write Module for FacetedBrepAndBrepWithVoids");

// Constructors
cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def(py::init<>());

// Methods
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFacetedBrepAndBrepWithVoids::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("ReadStep", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &) const) &RWStepShape_RWFacetedBrepAndBrepWithVoids::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("WriteStep", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &) const) &RWStepShape_RWFacetedBrepAndBrepWithVoids::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrepAndBrepWithVoids.def("Share", (void (RWStepShape_RWFacetedBrepAndBrepWithVoids::*)(const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, Interface_EntityIterator &) const) &RWStepShape_RWFacetedBrepAndBrepWithVoids::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWFACETEDBREPSHAPEREPRESENTATION
py::class_<RWStepShape_RWFacetedBrepShapeRepresentation> cls_RWStepShape_RWFacetedBrepShapeRepresentation(mod, "RWStepShape_RWFacetedBrepShapeRepresentation", "Read & Write Module for FacetedBrepShapeRepresentation");

// Constructors
cls_RWStepShape_RWFacetedBrepShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWFacetedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWFacetedBrepShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("ReadStep", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &) const) &RWStepShape_RWFacetedBrepShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("WriteStep", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &) const) &RWStepShape_RWFacetedBrepShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWFacetedBrepShapeRepresentation.def("Share", (void (RWStepShape_RWFacetedBrepShapeRepresentation::*)(const opencascade::handle<StepShape_FacetedBrepShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWFacetedBrepShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWGEOMETRICALLYBOUNDEDSURFACESHAPEREPRESENTATION
py::class_<RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation> cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation(mod, "RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation", "Read & Write Module for GeometricallyBoundedSurfaceShapeRepresentation");

// Constructors
cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &) const) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &) const) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWGEOMETRICALLYBOUNDEDWIREFRAMESHAPEREPRESENTATION
py::class_<RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation> cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation(mod, "RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation", "Read & Write Module for GeometricallyBoundedWireframeShapeRepresentation");

// Constructors
cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("ReadStep", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &) const) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("WriteStep", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &) const) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation.def("Share", (void (RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::*)(const opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWGEOMETRICCURVESET
py::class_<RWStepShape_RWGeometricCurveSet> cls_RWStepShape_RWGeometricCurveSet(mod, "RWStepShape_RWGeometricCurveSet", "Read & Write Module for GeometricCurveSet");

// Constructors
cls_RWStepShape_RWGeometricCurveSet.def(py::init<>());

// Methods
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWGeometricCurveSet::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWGeometricCurveSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWGeometricCurveSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWGeometricCurveSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWGeometricCurveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWGeometricCurveSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWGeometricCurveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWGeometricCurveSet.def("ReadStep", (void (RWStepShape_RWGeometricCurveSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricCurveSet> &) const) &RWStepShape_RWGeometricCurveSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWGeometricCurveSet.def("WriteStep", (void (RWStepShape_RWGeometricCurveSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricCurveSet> &) const) &RWStepShape_RWGeometricCurveSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWGeometricCurveSet.def("Share", (void (RWStepShape_RWGeometricCurveSet::*)(const opencascade::handle<StepShape_GeometricCurveSet> &, Interface_EntityIterator &) const) &RWStepShape_RWGeometricCurveSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWGEOMETRICSET
py::class_<RWStepShape_RWGeometricSet> cls_RWStepShape_RWGeometricSet(mod, "RWStepShape_RWGeometricSet", "Read & Write Module for GeometricSet");

// Constructors
cls_RWStepShape_RWGeometricSet.def(py::init<>());

// Methods
// cls_RWStepShape_RWGeometricSet.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWGeometricSet::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricSet.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWGeometricSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWGeometricSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWGeometricSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWGeometricSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWGeometricSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWGeometricSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWGeometricSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWGeometricSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWGeometricSet.def("ReadStep", (void (RWStepShape_RWGeometricSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_GeometricSet> &) const) &RWStepShape_RWGeometricSet::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWGeometricSet.def("WriteStep", (void (RWStepShape_RWGeometricSet::*)(StepData_StepWriter &, const opencascade::handle<StepShape_GeometricSet> &) const) &RWStepShape_RWGeometricSet::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWGeometricSet.def("Share", (void (RWStepShape_RWGeometricSet::*)(const opencascade::handle<StepShape_GeometricSet> &, Interface_EntityIterator &) const) &RWStepShape_RWGeometricSet::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWHALFSPACESOLID
py::class_<RWStepShape_RWHalfSpaceSolid> cls_RWStepShape_RWHalfSpaceSolid(mod, "RWStepShape_RWHalfSpaceSolid", "Read & Write Module for HalfSpaceSolid");

// Constructors
cls_RWStepShape_RWHalfSpaceSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWHalfSpaceSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWHalfSpaceSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWHalfSpaceSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWHalfSpaceSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWHalfSpaceSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWHalfSpaceSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWHalfSpaceSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWHalfSpaceSolid.def("ReadStep", (void (RWStepShape_RWHalfSpaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_HalfSpaceSolid> &) const) &RWStepShape_RWHalfSpaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWHalfSpaceSolid.def("WriteStep", (void (RWStepShape_RWHalfSpaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_HalfSpaceSolid> &) const) &RWStepShape_RWHalfSpaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWHalfSpaceSolid.def("Share", (void (RWStepShape_RWHalfSpaceSolid::*)(const opencascade::handle<StepShape_HalfSpaceSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWHalfSpaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWLIMITSANDFITS
py::class_<RWStepShape_RWLimitsAndFits> cls_RWStepShape_RWLimitsAndFits(mod, "RWStepShape_RWLimitsAndFits", "Read & Write Module for LimitsAndFits");

// Constructors
cls_RWStepShape_RWLimitsAndFits.def(py::init<>());

// Methods
// cls_RWStepShape_RWLimitsAndFits.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWLimitsAndFits::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWLimitsAndFits.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWLimitsAndFits::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWLimitsAndFits.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWLimitsAndFits::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWLimitsAndFits.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWLimitsAndFits::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWLimitsAndFits.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWLimitsAndFits::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWLimitsAndFits.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWLimitsAndFits::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWLimitsAndFits.def("ReadStep", (void (RWStepShape_RWLimitsAndFits::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_LimitsAndFits> &) const) &RWStepShape_RWLimitsAndFits::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWLimitsAndFits.def("WriteStep", (void (RWStepShape_RWLimitsAndFits::*)(StepData_StepWriter &, const opencascade::handle<StepShape_LimitsAndFits> &) const) &RWStepShape_RWLimitsAndFits::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWLOOP
py::class_<RWStepShape_RWLoop> cls_RWStepShape_RWLoop(mod, "RWStepShape_RWLoop", "Read & Write Module for Loop");

// Constructors
cls_RWStepShape_RWLoop.def(py::init<>());

// Methods
// cls_RWStepShape_RWLoop.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWLoop::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWLoop.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWLoop::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWLoop.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWLoop::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWLoop.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWLoop::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWLoop.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWLoop.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWLoop.def("ReadStep", (void (RWStepShape_RWLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Loop> &) const) &RWStepShape_RWLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWLoop.def("WriteStep", (void (RWStepShape_RWLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Loop> &) const) &RWStepShape_RWLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWLOOPANDPATH
py::class_<RWStepShape_RWLoopAndPath> cls_RWStepShape_RWLoopAndPath(mod, "RWStepShape_RWLoopAndPath", "Read & Write Module for LoopAndPath");

// Constructors
cls_RWStepShape_RWLoopAndPath.def(py::init<>());

// Methods
// cls_RWStepShape_RWLoopAndPath.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWLoopAndPath::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWLoopAndPath.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWLoopAndPath::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWLoopAndPath.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWLoopAndPath::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWLoopAndPath.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWLoopAndPath::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWLoopAndPath.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWLoopAndPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWLoopAndPath.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWLoopAndPath::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWLoopAndPath.def("ReadStep", (void (RWStepShape_RWLoopAndPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_LoopAndPath> &) const) &RWStepShape_RWLoopAndPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWLoopAndPath.def("WriteStep", (void (RWStepShape_RWLoopAndPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_LoopAndPath> &) const) &RWStepShape_RWLoopAndPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWLoopAndPath.def("Share", (void (RWStepShape_RWLoopAndPath::*)(const opencascade::handle<StepShape_LoopAndPath> &, Interface_EntityIterator &) const) &RWStepShape_RWLoopAndPath::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWMANIFOLDSOLIDBREP
py::class_<RWStepShape_RWManifoldSolidBrep> cls_RWStepShape_RWManifoldSolidBrep(mod, "RWStepShape_RWManifoldSolidBrep", "Read & Write Module for ManifoldSolidBrep");

// Constructors
cls_RWStepShape_RWManifoldSolidBrep.def(py::init<>());

// Methods
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWManifoldSolidBrep::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWManifoldSolidBrep::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWManifoldSolidBrep::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWManifoldSolidBrep::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWManifoldSolidBrep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSolidBrep.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWManifoldSolidBrep::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWManifoldSolidBrep.def("ReadStep", (void (RWStepShape_RWManifoldSolidBrep::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ManifoldSolidBrep> &) const) &RWStepShape_RWManifoldSolidBrep::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWManifoldSolidBrep.def("WriteStep", (void (RWStepShape_RWManifoldSolidBrep::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ManifoldSolidBrep> &) const) &RWStepShape_RWManifoldSolidBrep::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWManifoldSolidBrep.def("Share", (void (RWStepShape_RWManifoldSolidBrep::*)(const opencascade::handle<StepShape_ManifoldSolidBrep> &, Interface_EntityIterator &) const) &RWStepShape_RWManifoldSolidBrep::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWMANIFOLDSURFACESHAPEREPRESENTATION
py::class_<RWStepShape_RWManifoldSurfaceShapeRepresentation> cls_RWStepShape_RWManifoldSurfaceShapeRepresentation(mod, "RWStepShape_RWManifoldSurfaceShapeRepresentation", "Read & Write Module for ManifoldSurfaceShapeRepresentation");

// Constructors
cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWManifoldSurfaceShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &) const) &RWStepShape_RWManifoldSurfaceShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &) const) &RWStepShape_RWManifoldSurfaceShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWManifoldSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWManifoldSurfaceShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWMEASUREQUALIFICATION
py::class_<RWStepShape_RWMeasureQualification> cls_RWStepShape_RWMeasureQualification(mod, "RWStepShape_RWMeasureQualification", "Read & Write Module for MeasureQualification");

// Constructors
cls_RWStepShape_RWMeasureQualification.def(py::init<>());

// Methods
// cls_RWStepShape_RWMeasureQualification.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWMeasureQualification::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWMeasureQualification.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWMeasureQualification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWMeasureQualification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWMeasureQualification::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWMeasureQualification.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWMeasureQualification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWMeasureQualification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWMeasureQualification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWMeasureQualification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWMeasureQualification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWMeasureQualification.def("ReadStep", (void (RWStepShape_RWMeasureQualification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_MeasureQualification> &) const) &RWStepShape_RWMeasureQualification::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWMeasureQualification.def("WriteStep", (void (RWStepShape_RWMeasureQualification::*)(StepData_StepWriter &, const opencascade::handle<StepShape_MeasureQualification> &) const) &RWStepShape_RWMeasureQualification::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWMeasureQualification.def("Share", (void (RWStepShape_RWMeasureQualification::*)(const opencascade::handle<StepShape_MeasureQualification> &, Interface_EntityIterator &) const) &RWStepShape_RWMeasureQualification::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWMEASUREREPRESENTATIONITEMANDQUALIFIEDREPRESENTATIONITEM
py::class_<RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem> cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem(mod, "RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem", "Read & Write Module for MeasureRepresentationItemAndQualifiedRepresentationItem");

// Constructors
cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("ReadStep", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &) const) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("WriteStep", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &) const) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem.def("Share", (void (RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem> &, Interface_EntityIterator &) const) &RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWNONMANIFOLDSURFACESHAPEREPRESENTATION
py::class_<RWStepShape_RWNonManifoldSurfaceShapeRepresentation> cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation(mod, "RWStepShape_RWNonManifoldSurfaceShapeRepresentation", "Read & Write tool for NonManifoldSurfaceShapeRepresentation");

// Constructors
cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("ReadStep", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &) const) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::ReadStep, "Reads NonManifoldSurfaceShapeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("WriteStep", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &) const) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::WriteStep, "Writes NonManifoldSurfaceShapeRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWNonManifoldSurfaceShapeRepresentation.def("Share", (void (RWStepShape_RWNonManifoldSurfaceShapeRepresentation::*)(const opencascade::handle<StepShape_NonManifoldSurfaceShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWNonManifoldSurfaceShapeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWOPENSHELL
py::class_<RWStepShape_RWOpenShell> cls_RWStepShape_RWOpenShell(mod, "RWStepShape_RWOpenShell", "Read & Write Module for OpenShell");

// Constructors
cls_RWStepShape_RWOpenShell.def(py::init<>());

// Methods
// cls_RWStepShape_RWOpenShell.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOpenShell::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOpenShell.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOpenShell::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOpenShell.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOpenShell::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOpenShell.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOpenShell::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOpenShell.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOpenShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOpenShell.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOpenShell::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOpenShell.def("ReadStep", (void (RWStepShape_RWOpenShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OpenShell> &) const) &RWStepShape_RWOpenShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOpenShell.def("WriteStep", (void (RWStepShape_RWOpenShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OpenShell> &) const) &RWStepShape_RWOpenShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOpenShell.def("Share", (void (RWStepShape_RWOpenShell::*)(const opencascade::handle<StepShape_OpenShell> &, Interface_EntityIterator &) const) &RWStepShape_RWOpenShell::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWORIENTEDCLOSEDSHELL
py::class_<RWStepShape_RWOrientedClosedShell> cls_RWStepShape_RWOrientedClosedShell(mod, "RWStepShape_RWOrientedClosedShell", "Read & Write Module for OrientedClosedShell");

// Constructors
cls_RWStepShape_RWOrientedClosedShell.def(py::init<>());

// Methods
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOrientedClosedShell::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOrientedClosedShell::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOrientedClosedShell::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOrientedClosedShell::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOrientedClosedShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOrientedClosedShell.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOrientedClosedShell::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOrientedClosedShell.def("ReadStep", (void (RWStepShape_RWOrientedClosedShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedClosedShell> &) const) &RWStepShape_RWOrientedClosedShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOrientedClosedShell.def("WriteStep", (void (RWStepShape_RWOrientedClosedShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedClosedShell> &) const) &RWStepShape_RWOrientedClosedShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOrientedClosedShell.def("Share", (void (RWStepShape_RWOrientedClosedShell::*)(const opencascade::handle<StepShape_OrientedClosedShell> &, Interface_EntityIterator &) const) &RWStepShape_RWOrientedClosedShell::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWORIENTEDEDGE
py::class_<RWStepShape_RWOrientedEdge> cls_RWStepShape_RWOrientedEdge(mod, "RWStepShape_RWOrientedEdge", "Read & Write Module for OrientedEdge");

// Constructors
cls_RWStepShape_RWOrientedEdge.def(py::init<>());

// Methods
// cls_RWStepShape_RWOrientedEdge.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOrientedEdge::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedEdge.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOrientedEdge::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedEdge.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOrientedEdge::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedEdge.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOrientedEdge::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedEdge.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOrientedEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOrientedEdge.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOrientedEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOrientedEdge.def("ReadStep", (void (RWStepShape_RWOrientedEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedEdge> &) const) &RWStepShape_RWOrientedEdge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOrientedEdge.def("WriteStep", (void (RWStepShape_RWOrientedEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedEdge> &) const) &RWStepShape_RWOrientedEdge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOrientedEdge.def("Share", (void (RWStepShape_RWOrientedEdge::*)(const opencascade::handle<StepShape_OrientedEdge> &, Interface_EntityIterator &) const) &RWStepShape_RWOrientedEdge::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWORIENTEDFACE
py::class_<RWStepShape_RWOrientedFace> cls_RWStepShape_RWOrientedFace(mod, "RWStepShape_RWOrientedFace", "Read & Write Module for OrientedFace");

// Constructors
cls_RWStepShape_RWOrientedFace.def(py::init<>());

// Methods
// cls_RWStepShape_RWOrientedFace.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOrientedFace::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedFace.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOrientedFace::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedFace.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOrientedFace::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedFace.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOrientedFace::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedFace.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOrientedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOrientedFace.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOrientedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOrientedFace.def("ReadStep", (void (RWStepShape_RWOrientedFace::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedFace> &) const) &RWStepShape_RWOrientedFace::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOrientedFace.def("WriteStep", (void (RWStepShape_RWOrientedFace::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedFace> &) const) &RWStepShape_RWOrientedFace::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOrientedFace.def("Share", (void (RWStepShape_RWOrientedFace::*)(const opencascade::handle<StepShape_OrientedFace> &, Interface_EntityIterator &) const) &RWStepShape_RWOrientedFace::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWORIENTEDOPENSHELL
py::class_<RWStepShape_RWOrientedOpenShell> cls_RWStepShape_RWOrientedOpenShell(mod, "RWStepShape_RWOrientedOpenShell", "Read & Write Module for OrientedOpenShell");

// Constructors
cls_RWStepShape_RWOrientedOpenShell.def(py::init<>());

// Methods
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOrientedOpenShell::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOrientedOpenShell::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOrientedOpenShell::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOrientedOpenShell::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOrientedOpenShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOrientedOpenShell.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOrientedOpenShell::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOrientedOpenShell.def("ReadStep", (void (RWStepShape_RWOrientedOpenShell::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedOpenShell> &) const) &RWStepShape_RWOrientedOpenShell::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOrientedOpenShell.def("WriteStep", (void (RWStepShape_RWOrientedOpenShell::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedOpenShell> &) const) &RWStepShape_RWOrientedOpenShell::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOrientedOpenShell.def("Share", (void (RWStepShape_RWOrientedOpenShell::*)(const opencascade::handle<StepShape_OrientedOpenShell> &, Interface_EntityIterator &) const) &RWStepShape_RWOrientedOpenShell::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWORIENTEDPATH
py::class_<RWStepShape_RWOrientedPath> cls_RWStepShape_RWOrientedPath(mod, "RWStepShape_RWOrientedPath", "Read & Write Module for OrientedPath");

// Constructors
cls_RWStepShape_RWOrientedPath.def(py::init<>());

// Methods
// cls_RWStepShape_RWOrientedPath.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWOrientedPath::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedPath.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWOrientedPath::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedPath.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWOrientedPath::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWOrientedPath.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWOrientedPath::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWOrientedPath.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWOrientedPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWOrientedPath.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWOrientedPath::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWOrientedPath.def("ReadStep", (void (RWStepShape_RWOrientedPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_OrientedPath> &) const) &RWStepShape_RWOrientedPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWOrientedPath.def("WriteStep", (void (RWStepShape_RWOrientedPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_OrientedPath> &) const) &RWStepShape_RWOrientedPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWOrientedPath.def("Share", (void (RWStepShape_RWOrientedPath::*)(const opencascade::handle<StepShape_OrientedPath> &, Interface_EntityIterator &) const) &RWStepShape_RWOrientedPath::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWPATH
py::class_<RWStepShape_RWPath> cls_RWStepShape_RWPath(mod, "RWStepShape_RWPath", "Read & Write Module for Path");

// Constructors
cls_RWStepShape_RWPath.def(py::init<>());

// Methods
// cls_RWStepShape_RWPath.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWPath::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWPath.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWPath::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWPath.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWPath::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWPath.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWPath::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWPath.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWPath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWPath.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWPath::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWPath.def("ReadStep", (void (RWStepShape_RWPath::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Path> &) const) &RWStepShape_RWPath::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWPath.def("WriteStep", (void (RWStepShape_RWPath::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Path> &) const) &RWStepShape_RWPath::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWPath.def("Share", (void (RWStepShape_RWPath::*)(const opencascade::handle<StepShape_Path> &, Interface_EntityIterator &) const) &RWStepShape_RWPath::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWPLUSMINUSTOLERANCE
py::class_<RWStepShape_RWPlusMinusTolerance> cls_RWStepShape_RWPlusMinusTolerance(mod, "RWStepShape_RWPlusMinusTolerance", "Read & Write Module for PlusMinusTolerance");

// Constructors
cls_RWStepShape_RWPlusMinusTolerance.def(py::init<>());

// Methods
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWPlusMinusTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWPlusMinusTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWPlusMinusTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWPlusMinusTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWPlusMinusTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWPlusMinusTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWPlusMinusTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWPlusMinusTolerance.def("ReadStep", (void (RWStepShape_RWPlusMinusTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PlusMinusTolerance> &) const) &RWStepShape_RWPlusMinusTolerance::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWPlusMinusTolerance.def("WriteStep", (void (RWStepShape_RWPlusMinusTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PlusMinusTolerance> &) const) &RWStepShape_RWPlusMinusTolerance::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWPlusMinusTolerance.def("Share", (void (RWStepShape_RWPlusMinusTolerance::*)(const opencascade::handle<StepShape_PlusMinusTolerance> &, Interface_EntityIterator &) const) &RWStepShape_RWPlusMinusTolerance::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWPOINTREPRESENTATION
py::class_<RWStepShape_RWPointRepresentation> cls_RWStepShape_RWPointRepresentation(mod, "RWStepShape_RWPointRepresentation", "Read & Write tool for PointRepresentation");

// Constructors
cls_RWStepShape_RWPointRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWPointRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWPointRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWPointRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWPointRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWPointRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWPointRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWPointRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWPointRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWPointRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWPointRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWPointRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWPointRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWPointRepresentation.def("ReadStep", (void (RWStepShape_RWPointRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PointRepresentation> &) const) &RWStepShape_RWPointRepresentation::ReadStep, "Reads PointRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWPointRepresentation.def("WriteStep", (void (RWStepShape_RWPointRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PointRepresentation> &) const) &RWStepShape_RWPointRepresentation::WriteStep, "Writes PointRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWPointRepresentation.def("Share", (void (RWStepShape_RWPointRepresentation::*)(const opencascade::handle<StepShape_PointRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWPointRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWPOLYLOOP
py::class_<RWStepShape_RWPolyLoop> cls_RWStepShape_RWPolyLoop(mod, "RWStepShape_RWPolyLoop", "Read & Write Module for PolyLoop");

// Constructors
cls_RWStepShape_RWPolyLoop.def(py::init<>());

// Methods
// cls_RWStepShape_RWPolyLoop.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWPolyLoop::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWPolyLoop.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWPolyLoop::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWPolyLoop.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWPolyLoop::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWPolyLoop.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWPolyLoop::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWPolyLoop.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWPolyLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWPolyLoop.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWPolyLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWPolyLoop.def("ReadStep", (void (RWStepShape_RWPolyLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PolyLoop> &) const) &RWStepShape_RWPolyLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWPolyLoop.def("WriteStep", (void (RWStepShape_RWPolyLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PolyLoop> &) const) &RWStepShape_RWPolyLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWPolyLoop.def("Share", (void (RWStepShape_RWPolyLoop::*)(const opencascade::handle<StepShape_PolyLoop> &, Interface_EntityIterator &) const) &RWStepShape_RWPolyLoop::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWPRECISIONQUALIFIER
py::class_<RWStepShape_RWPrecisionQualifier> cls_RWStepShape_RWPrecisionQualifier(mod, "RWStepShape_RWPrecisionQualifier", "Read & Write Module for PrecisionQualifier");

// Constructors
cls_RWStepShape_RWPrecisionQualifier.def(py::init<>());

// Methods
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWPrecisionQualifier::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWPrecisionQualifier::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWPrecisionQualifier::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWPrecisionQualifier::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWPrecisionQualifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWPrecisionQualifier.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWPrecisionQualifier::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWPrecisionQualifier.def("ReadStep", (void (RWStepShape_RWPrecisionQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_PrecisionQualifier> &) const) &RWStepShape_RWPrecisionQualifier::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWPrecisionQualifier.def("WriteStep", (void (RWStepShape_RWPrecisionQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_PrecisionQualifier> &) const) &RWStepShape_RWPrecisionQualifier::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWQUALIFIEDREPRESENTATIONITEM
py::class_<RWStepShape_RWQualifiedRepresentationItem> cls_RWStepShape_RWQualifiedRepresentationItem(mod, "RWStepShape_RWQualifiedRepresentationItem", "Read & Write Module for QualifiedRepresentationItem");

// Constructors
cls_RWStepShape_RWQualifiedRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWQualifiedRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWQualifiedRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWQualifiedRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWQualifiedRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWQualifiedRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWQualifiedRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWQualifiedRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWQualifiedRepresentationItem.def("ReadStep", (void (RWStepShape_RWQualifiedRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_QualifiedRepresentationItem> &) const) &RWStepShape_RWQualifiedRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWQualifiedRepresentationItem.def("WriteStep", (void (RWStepShape_RWQualifiedRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_QualifiedRepresentationItem> &) const) &RWStepShape_RWQualifiedRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWQualifiedRepresentationItem.def("Share", (void (RWStepShape_RWQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_QualifiedRepresentationItem> &, Interface_EntityIterator &) const) &RWStepShape_RWQualifiedRepresentationItem::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWREVOLVEDAREASOLID
py::class_<RWStepShape_RWRevolvedAreaSolid> cls_RWStepShape_RWRevolvedAreaSolid(mod, "RWStepShape_RWRevolvedAreaSolid", "Read & Write Module for RevolvedAreaSolid");

// Constructors
cls_RWStepShape_RWRevolvedAreaSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWRevolvedAreaSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWRevolvedAreaSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWRevolvedAreaSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWRevolvedAreaSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWRevolvedAreaSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedAreaSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWRevolvedAreaSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWRevolvedAreaSolid.def("ReadStep", (void (RWStepShape_RWRevolvedAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RevolvedAreaSolid> &) const) &RWStepShape_RWRevolvedAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWRevolvedAreaSolid.def("WriteStep", (void (RWStepShape_RWRevolvedAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RevolvedAreaSolid> &) const) &RWStepShape_RWRevolvedAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWRevolvedAreaSolid.def("Share", (void (RWStepShape_RWRevolvedAreaSolid::*)(const opencascade::handle<StepShape_RevolvedAreaSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWRevolvedAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWREVOLVEDFACESOLID
py::class_<RWStepShape_RWRevolvedFaceSolid> cls_RWStepShape_RWRevolvedFaceSolid(mod, "RWStepShape_RWRevolvedFaceSolid", "None");

// Constructors
cls_RWStepShape_RWRevolvedFaceSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWRevolvedFaceSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWRevolvedFaceSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWRevolvedFaceSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWRevolvedFaceSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWRevolvedFaceSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWRevolvedFaceSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWRevolvedFaceSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWRevolvedFaceSolid.def("ReadStep", (void (RWStepShape_RWRevolvedFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RevolvedFaceSolid> &) const) &RWStepShape_RWRevolvedFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWRevolvedFaceSolid.def("WriteStep", (void (RWStepShape_RWRevolvedFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RevolvedFaceSolid> &) const) &RWStepShape_RWRevolvedFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWRevolvedFaceSolid.def("Share", (void (RWStepShape_RWRevolvedFaceSolid::*)(const opencascade::handle<StepShape_RevolvedFaceSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWRevolvedFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWRIGHTANGULARWEDGE
py::class_<RWStepShape_RWRightAngularWedge> cls_RWStepShape_RWRightAngularWedge(mod, "RWStepShape_RWRightAngularWedge", "Read & Write Module for RightAngularWedge");

// Constructors
cls_RWStepShape_RWRightAngularWedge.def(py::init<>());

// Methods
// cls_RWStepShape_RWRightAngularWedge.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWRightAngularWedge::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWRightAngularWedge.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWRightAngularWedge::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightAngularWedge.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWRightAngularWedge::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWRightAngularWedge.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWRightAngularWedge::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightAngularWedge.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWRightAngularWedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWRightAngularWedge.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWRightAngularWedge::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWRightAngularWedge.def("ReadStep", (void (RWStepShape_RWRightAngularWedge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightAngularWedge> &) const) &RWStepShape_RWRightAngularWedge::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWRightAngularWedge.def("WriteStep", (void (RWStepShape_RWRightAngularWedge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightAngularWedge> &) const) &RWStepShape_RWRightAngularWedge::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWRightAngularWedge.def("Share", (void (RWStepShape_RWRightAngularWedge::*)(const opencascade::handle<StepShape_RightAngularWedge> &, Interface_EntityIterator &) const) &RWStepShape_RWRightAngularWedge::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWRIGHTCIRCULARCONE
py::class_<RWStepShape_RWRightCircularCone> cls_RWStepShape_RWRightCircularCone(mod, "RWStepShape_RWRightCircularCone", "Read & Write Module for RightCircularCone");

// Constructors
cls_RWStepShape_RWRightCircularCone.def(py::init<>());

// Methods
// cls_RWStepShape_RWRightCircularCone.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWRightCircularCone::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWRightCircularCone.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWRightCircularCone::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCone.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWRightCircularCone::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWRightCircularCone.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWRightCircularCone::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCone.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWRightCircularCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCone.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWRightCircularCone::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWRightCircularCone.def("ReadStep", (void (RWStepShape_RWRightCircularCone::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightCircularCone> &) const) &RWStepShape_RWRightCircularCone::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWRightCircularCone.def("WriteStep", (void (RWStepShape_RWRightCircularCone::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightCircularCone> &) const) &RWStepShape_RWRightCircularCone::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWRightCircularCone.def("Share", (void (RWStepShape_RWRightCircularCone::*)(const opencascade::handle<StepShape_RightCircularCone> &, Interface_EntityIterator &) const) &RWStepShape_RWRightCircularCone::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWRIGHTCIRCULARCYLINDER
py::class_<RWStepShape_RWRightCircularCylinder> cls_RWStepShape_RWRightCircularCylinder(mod, "RWStepShape_RWRightCircularCylinder", "Read & Write Module for RightCircularCylinder");

// Constructors
cls_RWStepShape_RWRightCircularCylinder.def(py::init<>());

// Methods
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWRightCircularCylinder::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWRightCircularCylinder::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWRightCircularCylinder::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWRightCircularCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWRightCircularCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWRightCircularCylinder.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWRightCircularCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWRightCircularCylinder.def("ReadStep", (void (RWStepShape_RWRightCircularCylinder::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_RightCircularCylinder> &) const) &RWStepShape_RWRightCircularCylinder::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWRightCircularCylinder.def("WriteStep", (void (RWStepShape_RWRightCircularCylinder::*)(StepData_StepWriter &, const opencascade::handle<StepShape_RightCircularCylinder> &) const) &RWStepShape_RWRightCircularCylinder::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWRightCircularCylinder.def("Share", (void (RWStepShape_RWRightCircularCylinder::*)(const opencascade::handle<StepShape_RightCircularCylinder> &, Interface_EntityIterator &) const) &RWStepShape_RWRightCircularCylinder::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSEAMEDGE
py::class_<RWStepShape_RWSeamEdge> cls_RWStepShape_RWSeamEdge(mod, "RWStepShape_RWSeamEdge", "Read & Write tool for SeamEdge");

// Constructors
cls_RWStepShape_RWSeamEdge.def(py::init<>());

// Methods
// cls_RWStepShape_RWSeamEdge.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSeamEdge::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSeamEdge.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSeamEdge::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSeamEdge.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSeamEdge::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSeamEdge.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSeamEdge::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSeamEdge.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSeamEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSeamEdge.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSeamEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSeamEdge.def("ReadStep", (void (RWStepShape_RWSeamEdge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SeamEdge> &) const) &RWStepShape_RWSeamEdge::ReadStep, "Reads SeamEdge", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSeamEdge.def("WriteStep", (void (RWStepShape_RWSeamEdge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SeamEdge> &) const) &RWStepShape_RWSeamEdge::WriteStep, "Writes SeamEdge", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSeamEdge.def("Share", (void (RWStepShape_RWSeamEdge::*)(const opencascade::handle<StepShape_SeamEdge> &, Interface_EntityIterator &) const) &RWStepShape_RWSeamEdge::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSHAPEDEFINITIONREPRESENTATION
py::class_<RWStepShape_RWShapeDefinitionRepresentation> cls_RWStepShape_RWShapeDefinitionRepresentation(mod, "RWStepShape_RWShapeDefinitionRepresentation", "Read & Write tool for ShapeDefinitionRepresentation");

// Constructors
cls_RWStepShape_RWShapeDefinitionRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWShapeDefinitionRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWShapeDefinitionRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWShapeDefinitionRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWShapeDefinitionRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWShapeDefinitionRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWShapeDefinitionRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWShapeDefinitionRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWShapeDefinitionRepresentation.def("ReadStep", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &) const) &RWStepShape_RWShapeDefinitionRepresentation::ReadStep, "Reads ShapeDefinitionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWShapeDefinitionRepresentation.def("WriteStep", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &) const) &RWStepShape_RWShapeDefinitionRepresentation::WriteStep, "Writes ShapeDefinitionRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWShapeDefinitionRepresentation.def("Share", (void (RWStepShape_RWShapeDefinitionRepresentation::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWShapeDefinitionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSHAPEDIMENSIONREPRESENTATION
py::class_<RWStepShape_RWShapeDimensionRepresentation> cls_RWStepShape_RWShapeDimensionRepresentation(mod, "RWStepShape_RWShapeDimensionRepresentation", "Read & Write tool for ShapeDimensionRepresentation");

// Constructors
cls_RWStepShape_RWShapeDimensionRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWShapeDimensionRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWShapeDimensionRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWShapeDimensionRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWShapeDimensionRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWShapeDimensionRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWShapeDimensionRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWShapeDimensionRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWShapeDimensionRepresentation.def("ReadStep", (void (RWStepShape_RWShapeDimensionRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &) const) &RWStepShape_RWShapeDimensionRepresentation::ReadStep, "Reads ShapeDimensionRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWShapeDimensionRepresentation.def("WriteStep", (void (RWStepShape_RWShapeDimensionRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeDimensionRepresentation> &) const) &RWStepShape_RWShapeDimensionRepresentation::WriteStep, "Writes ShapeDimensionRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWShapeDimensionRepresentation.def("Share", (void (RWStepShape_RWShapeDimensionRepresentation::*)(const opencascade::handle<StepShape_ShapeDimensionRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWShapeDimensionRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSHAPEREPRESENTATION
py::class_<RWStepShape_RWShapeRepresentation> cls_RWStepShape_RWShapeRepresentation(mod, "RWStepShape_RWShapeRepresentation", "Read & Write Module for ShapeRepresentation");

// Constructors
cls_RWStepShape_RWShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWShapeRepresentation.def("ReadStep", (void (RWStepShape_RWShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeRepresentation> &) const) &RWStepShape_RWShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWShapeRepresentation.def("WriteStep", (void (RWStepShape_RWShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeRepresentation> &) const) &RWStepShape_RWShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWShapeRepresentation.def("Share", (void (RWStepShape_RWShapeRepresentation::*)(const opencascade::handle<StepShape_ShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSHAPEREPRESENTATIONWITHPARAMETERS
py::class_<RWStepShape_RWShapeRepresentationWithParameters> cls_RWStepShape_RWShapeRepresentationWithParameters(mod, "RWStepShape_RWShapeRepresentationWithParameters", "Read & Write tool for ShapeRepresentationWithParameters");

// Constructors
cls_RWStepShape_RWShapeRepresentationWithParameters.def(py::init<>());

// Methods
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWShapeRepresentationWithParameters::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWShapeRepresentationWithParameters::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWShapeRepresentationWithParameters::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWShapeRepresentationWithParameters::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWShapeRepresentationWithParameters::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWShapeRepresentationWithParameters.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWShapeRepresentationWithParameters::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWShapeRepresentationWithParameters.def("ReadStep", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &) const) &RWStepShape_RWShapeRepresentationWithParameters::ReadStep, "Reads ShapeRepresentationWithParameters", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWShapeRepresentationWithParameters.def("WriteStep", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &) const) &RWStepShape_RWShapeRepresentationWithParameters::WriteStep, "Writes ShapeRepresentationWithParameters", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWShapeRepresentationWithParameters.def("Share", (void (RWStepShape_RWShapeRepresentationWithParameters::*)(const opencascade::handle<StepShape_ShapeRepresentationWithParameters> &, Interface_EntityIterator &) const) &RWStepShape_RWShapeRepresentationWithParameters::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSHELLBASEDSURFACEMODEL
py::class_<RWStepShape_RWShellBasedSurfaceModel> cls_RWStepShape_RWShellBasedSurfaceModel(mod, "RWStepShape_RWShellBasedSurfaceModel", "Read & Write Module for ShellBasedSurfaceModel");

// Constructors
cls_RWStepShape_RWShellBasedSurfaceModel.def(py::init<>());

// Methods
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWShellBasedSurfaceModel::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWShellBasedSurfaceModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWShellBasedSurfaceModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWShellBasedSurfaceModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWShellBasedSurfaceModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWShellBasedSurfaceModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWShellBasedSurfaceModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWShellBasedSurfaceModel.def("ReadStep", (void (RWStepShape_RWShellBasedSurfaceModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ShellBasedSurfaceModel> &) const) &RWStepShape_RWShellBasedSurfaceModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWShellBasedSurfaceModel.def("WriteStep", (void (RWStepShape_RWShellBasedSurfaceModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ShellBasedSurfaceModel> &) const) &RWStepShape_RWShellBasedSurfaceModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWShellBasedSurfaceModel.def("Share", (void (RWStepShape_RWShellBasedSurfaceModel::*)(const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, Interface_EntityIterator &) const) &RWStepShape_RWShellBasedSurfaceModel::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSOLIDMODEL
py::class_<RWStepShape_RWSolidModel> cls_RWStepShape_RWSolidModel(mod, "RWStepShape_RWSolidModel", "Read & Write Module for SolidModel");

// Constructors
cls_RWStepShape_RWSolidModel.def(py::init<>());

// Methods
// cls_RWStepShape_RWSolidModel.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSolidModel::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSolidModel.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSolidModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSolidModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSolidModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSolidModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSolidModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSolidModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSolidModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSolidModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSolidModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSolidModel.def("ReadStep", (void (RWStepShape_RWSolidModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SolidModel> &) const) &RWStepShape_RWSolidModel::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSolidModel.def("WriteStep", (void (RWStepShape_RWSolidModel::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SolidModel> &) const) &RWStepShape_RWSolidModel::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWSOLIDREPLICA
py::class_<RWStepShape_RWSolidReplica> cls_RWStepShape_RWSolidReplica(mod, "RWStepShape_RWSolidReplica", "Read & Write Module for SolidReplica");

// Constructors
cls_RWStepShape_RWSolidReplica.def(py::init<>());

// Methods
// cls_RWStepShape_RWSolidReplica.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSolidReplica::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSolidReplica.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSolidReplica::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSolidReplica.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSolidReplica::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSolidReplica.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSolidReplica::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSolidReplica.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSolidReplica::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSolidReplica.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSolidReplica::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSolidReplica.def("ReadStep", (void (RWStepShape_RWSolidReplica::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SolidReplica> &) const) &RWStepShape_RWSolidReplica::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSolidReplica.def("WriteStep", (void (RWStepShape_RWSolidReplica::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SolidReplica> &) const) &RWStepShape_RWSolidReplica::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSolidReplica.def("Share", (void (RWStepShape_RWSolidReplica::*)(const opencascade::handle<StepShape_SolidReplica> &, Interface_EntityIterator &) const) &RWStepShape_RWSolidReplica::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSPHERE
py::class_<RWStepShape_RWSphere> cls_RWStepShape_RWSphere(mod, "RWStepShape_RWSphere", "Read & Write Module for Sphere");

// Constructors
cls_RWStepShape_RWSphere.def(py::init<>());

// Methods
// cls_RWStepShape_RWSphere.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSphere::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSphere.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSphere::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSphere.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSphere::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSphere.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSphere::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSphere.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSphere.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSphere::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSphere.def("ReadStep", (void (RWStepShape_RWSphere::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Sphere> &) const) &RWStepShape_RWSphere::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSphere.def("WriteStep", (void (RWStepShape_RWSphere::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Sphere> &) const) &RWStepShape_RWSphere::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSphere.def("Share", (void (RWStepShape_RWSphere::*)(const opencascade::handle<StepShape_Sphere> &, Interface_EntityIterator &) const) &RWStepShape_RWSphere::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSUBEDGE
py::class_<RWStepShape_RWSubedge> cls_RWStepShape_RWSubedge(mod, "RWStepShape_RWSubedge", "Read & Write tool for Subedge");

// Constructors
cls_RWStepShape_RWSubedge.def(py::init<>());

// Methods
// cls_RWStepShape_RWSubedge.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSubedge::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSubedge.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSubedge::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSubedge.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSubedge::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSubedge.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSubedge::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSubedge.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSubedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSubedge.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSubedge::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSubedge.def("ReadStep", (void (RWStepShape_RWSubedge::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Subedge> &) const) &RWStepShape_RWSubedge::ReadStep, "Reads Subedge", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSubedge.def("WriteStep", (void (RWStepShape_RWSubedge::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Subedge> &) const) &RWStepShape_RWSubedge::WriteStep, "Writes Subedge", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSubedge.def("Share", (void (RWStepShape_RWSubedge::*)(const opencascade::handle<StepShape_Subedge> &, Interface_EntityIterator &) const) &RWStepShape_RWSubedge::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSUBFACE
py::class_<RWStepShape_RWSubface> cls_RWStepShape_RWSubface(mod, "RWStepShape_RWSubface", "Read & Write tool for Subface");

// Constructors
cls_RWStepShape_RWSubface.def(py::init<>());

// Methods
// cls_RWStepShape_RWSubface.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSubface::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSubface.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSubface::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSubface.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSubface::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSubface.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSubface::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSubface.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSubface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSubface.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSubface::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSubface.def("ReadStep", (void (RWStepShape_RWSubface::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Subface> &) const) &RWStepShape_RWSubface::ReadStep, "Reads Subface", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSubface.def("WriteStep", (void (RWStepShape_RWSubface::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Subface> &) const) &RWStepShape_RWSubface::WriteStep, "Writes Subface", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSubface.def("Share", (void (RWStepShape_RWSubface::*)(const opencascade::handle<StepShape_Subface> &, Interface_EntityIterator &) const) &RWStepShape_RWSubface::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSWEPTAREASOLID
py::class_<RWStepShape_RWSweptAreaSolid> cls_RWStepShape_RWSweptAreaSolid(mod, "RWStepShape_RWSweptAreaSolid", "Read & Write Module for SweptAreaSolid");

// Constructors
cls_RWStepShape_RWSweptAreaSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSweptAreaSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSweptAreaSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSweptAreaSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSweptAreaSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSweptAreaSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSweptAreaSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSweptAreaSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSweptAreaSolid.def("ReadStep", (void (RWStepShape_RWSweptAreaSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SweptAreaSolid> &) const) &RWStepShape_RWSweptAreaSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSweptAreaSolid.def("WriteStep", (void (RWStepShape_RWSweptAreaSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SweptAreaSolid> &) const) &RWStepShape_RWSweptAreaSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSweptAreaSolid.def("Share", (void (RWStepShape_RWSweptAreaSolid::*)(const opencascade::handle<StepShape_SweptAreaSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWSweptAreaSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWSWEPTFACESOLID
py::class_<RWStepShape_RWSweptFaceSolid> cls_RWStepShape_RWSweptFaceSolid(mod, "RWStepShape_RWSweptFaceSolid", "Read & Write Module for SweptFaceSolid");

// Constructors
cls_RWStepShape_RWSweptFaceSolid.def(py::init<>());

// Methods
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWSweptFaceSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWSweptFaceSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWSweptFaceSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWSweptFaceSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWSweptFaceSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWSweptFaceSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWSweptFaceSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWSweptFaceSolid.def("ReadStep", (void (RWStepShape_RWSweptFaceSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_SweptFaceSolid> &) const) &RWStepShape_RWSweptFaceSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWSweptFaceSolid.def("WriteStep", (void (RWStepShape_RWSweptFaceSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_SweptFaceSolid> &) const) &RWStepShape_RWSweptFaceSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWSweptFaceSolid.def("Share", (void (RWStepShape_RWSweptFaceSolid::*)(const opencascade::handle<StepShape_SweptFaceSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWSweptFaceSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWTOLERANCEVALUE
py::class_<RWStepShape_RWToleranceValue> cls_RWStepShape_RWToleranceValue(mod, "RWStepShape_RWToleranceValue", "Read & Write Module for ToleranceValue");

// Constructors
cls_RWStepShape_RWToleranceValue.def(py::init<>());

// Methods
// cls_RWStepShape_RWToleranceValue.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWToleranceValue::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWToleranceValue.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWToleranceValue::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWToleranceValue.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWToleranceValue::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWToleranceValue.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWToleranceValue::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWToleranceValue.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWToleranceValue::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWToleranceValue.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWToleranceValue::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWToleranceValue.def("ReadStep", (void (RWStepShape_RWToleranceValue::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ToleranceValue> &) const) &RWStepShape_RWToleranceValue::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWToleranceValue.def("WriteStep", (void (RWStepShape_RWToleranceValue::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ToleranceValue> &) const) &RWStepShape_RWToleranceValue::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWToleranceValue.def("Share", (void (RWStepShape_RWToleranceValue::*)(const opencascade::handle<StepShape_ToleranceValue> &, Interface_EntityIterator &) const) &RWStepShape_RWToleranceValue::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWTOPOLOGICALREPRESENTATIONITEM
py::class_<RWStepShape_RWTopologicalRepresentationItem> cls_RWStepShape_RWTopologicalRepresentationItem(mod, "RWStepShape_RWTopologicalRepresentationItem", "Read & Write Module for TopologicalRepresentationItem");

// Constructors
cls_RWStepShape_RWTopologicalRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWTopologicalRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWTopologicalRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWTopologicalRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWTopologicalRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWTopologicalRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWTopologicalRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWTopologicalRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWTopologicalRepresentationItem.def("ReadStep", (void (RWStepShape_RWTopologicalRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &) const) &RWStepShape_RWTopologicalRepresentationItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWTopologicalRepresentationItem.def("WriteStep", (void (RWStepShape_RWTopologicalRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &) const) &RWStepShape_RWTopologicalRepresentationItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWTORUS
py::class_<RWStepShape_RWTorus> cls_RWStepShape_RWTorus(mod, "RWStepShape_RWTorus", "Read & Write Module for Torus");

// Constructors
cls_RWStepShape_RWTorus.def(py::init<>());

// Methods
// cls_RWStepShape_RWTorus.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWTorus::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWTorus.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWTorus::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWTorus.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWTorus::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWTorus.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWTorus::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWTorus.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWTorus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWTorus.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWTorus::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWTorus.def("ReadStep", (void (RWStepShape_RWTorus::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Torus> &) const) &RWStepShape_RWTorus::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWTorus.def("WriteStep", (void (RWStepShape_RWTorus::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Torus> &) const) &RWStepShape_RWTorus::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWTorus.def("Share", (void (RWStepShape_RWTorus::*)(const opencascade::handle<StepShape_Torus> &, Interface_EntityIterator &) const) &RWStepShape_RWTorus::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWTRANSITIONALSHAPEREPRESENTATION
py::class_<RWStepShape_RWTransitionalShapeRepresentation> cls_RWStepShape_RWTransitionalShapeRepresentation(mod, "RWStepShape_RWTransitionalShapeRepresentation", "Read & Write Module for TransitionalShapeRepresentation");

// Constructors
cls_RWStepShape_RWTransitionalShapeRepresentation.def(py::init<>());

// Methods
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWTransitionalShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWTransitionalShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWTransitionalShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWTransitionalShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWTransitionalShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWTransitionalShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWTransitionalShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWTransitionalShapeRepresentation.def("ReadStep", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TransitionalShapeRepresentation> &) const) &RWStepShape_RWTransitionalShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWTransitionalShapeRepresentation.def("WriteStep", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TransitionalShapeRepresentation> &) const) &RWStepShape_RWTransitionalShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWTransitionalShapeRepresentation.def("Share", (void (RWStepShape_RWTransitionalShapeRepresentation::*)(const opencascade::handle<StepShape_TransitionalShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWTransitionalShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWTYPEQUALIFIER
py::class_<RWStepShape_RWTypeQualifier> cls_RWStepShape_RWTypeQualifier(mod, "RWStepShape_RWTypeQualifier", "Read & Write Module for TypeQualifier");

// Constructors
cls_RWStepShape_RWTypeQualifier.def(py::init<>());

// Methods
// cls_RWStepShape_RWTypeQualifier.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWTypeQualifier::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWTypeQualifier.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWTypeQualifier::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWTypeQualifier.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWTypeQualifier::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWTypeQualifier.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWTypeQualifier::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWTypeQualifier.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWTypeQualifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWTypeQualifier.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWTypeQualifier::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWTypeQualifier.def("ReadStep", (void (RWStepShape_RWTypeQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_TypeQualifier> &) const) &RWStepShape_RWTypeQualifier::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWTypeQualifier.def("WriteStep", (void (RWStepShape_RWTypeQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_TypeQualifier> &) const) &RWStepShape_RWTypeQualifier::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWVALUEFORMATTYPEQUALIFIER
py::class_<RWStepShape_RWValueFormatTypeQualifier> cls_RWStepShape_RWValueFormatTypeQualifier(mod, "RWStepShape_RWValueFormatTypeQualifier", "Read & Write tool for ValueFormatTypeQualifier");

// Constructors
cls_RWStepShape_RWValueFormatTypeQualifier.def(py::init<>());

// Methods
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWValueFormatTypeQualifier::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWValueFormatTypeQualifier::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWValueFormatTypeQualifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWValueFormatTypeQualifier.def("ReadStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const) &RWStepShape_RWValueFormatTypeQualifier::ReadStep, "Reads ValueFormatTypeQualifier", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWValueFormatTypeQualifier.def("WriteStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const) &RWStepShape_RWValueFormatTypeQualifier::WriteStep, "Writes ValueFormatTypeQualifier", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWVERTEX
py::class_<RWStepShape_RWVertex> cls_RWStepShape_RWVertex(mod, "RWStepShape_RWVertex", "Read & Write Module for Vertex");

// Constructors
cls_RWStepShape_RWVertex.def(py::init<>());

// Methods
// cls_RWStepShape_RWVertex.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWVertex::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWVertex.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWVertex::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertex.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWVertex::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWVertex.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWVertex::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertex.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWVertex.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWVertex.def("ReadStep", (void (RWStepShape_RWVertex::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_Vertex> &) const) &RWStepShape_RWVertex::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWVertex.def("WriteStep", (void (RWStepShape_RWVertex::*)(StepData_StepWriter &, const opencascade::handle<StepShape_Vertex> &) const) &RWStepShape_RWVertex::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// CLASS: RWSTEPSHAPE_RWVERTEXLOOP
py::class_<RWStepShape_RWVertexLoop> cls_RWStepShape_RWVertexLoop(mod, "RWStepShape_RWVertexLoop", "Read & Write Module for VertexLoop");

// Constructors
cls_RWStepShape_RWVertexLoop.def(py::init<>());

// Methods
// cls_RWStepShape_RWVertexLoop.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWVertexLoop::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWVertexLoop::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWVertexLoop::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWVertexLoop::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWVertexLoop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWVertexLoop.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWVertexLoop::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWVertexLoop.def("ReadStep", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_VertexLoop> &) const) &RWStepShape_RWVertexLoop::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWVertexLoop.def("WriteStep", (void (RWStepShape_RWVertexLoop::*)(StepData_StepWriter &, const opencascade::handle<StepShape_VertexLoop> &) const) &RWStepShape_RWVertexLoop::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWVertexLoop.def("Share", (void (RWStepShape_RWVertexLoop::*)(const opencascade::handle<StepShape_VertexLoop> &, Interface_EntityIterator &) const) &RWStepShape_RWVertexLoop::Share, "None", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPSHAPE_RWVERTEXPOINT
py::class_<RWStepShape_RWVertexPoint> cls_RWStepShape_RWVertexPoint(mod, "RWStepShape_RWVertexPoint", "Read & Write Module for VertexPoint");

// Constructors
cls_RWStepShape_RWVertexPoint.def(py::init<>());

// Methods
// cls_RWStepShape_RWVertexPoint.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWVertexPoint::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexPoint.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWVertexPoint::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexPoint.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWVertexPoint::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWVertexPoint.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWVertexPoint::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWVertexPoint.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWVertexPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWVertexPoint.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWVertexPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWVertexPoint.def("ReadStep", (void (RWStepShape_RWVertexPoint::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_VertexPoint> &) const) &RWStepShape_RWVertexPoint::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWVertexPoint.def("WriteStep", (void (RWStepShape_RWVertexPoint::*)(StepData_StepWriter &, const opencascade::handle<StepShape_VertexPoint> &) const) &RWStepShape_RWVertexPoint::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWVertexPoint.def("Share", (void (RWStepShape_RWVertexPoint::*)(const opencascade::handle<StepShape_VertexPoint> &, Interface_EntityIterator &) const) &RWStepShape_RWVertexPoint::Share, "None", py::arg("ent"), py::arg("iter"));


}
