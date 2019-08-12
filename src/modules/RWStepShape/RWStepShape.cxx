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

void bind_RWStepShape_RWAdvancedBrepShapeRepresentation(py::module &);
void bind_RWStepShape_RWAdvancedFace(py::module &);
void bind_RWStepShape_RWAngularLocation(py::module &);
void bind_RWStepShape_RWAngularSize(py::module &);
void bind_RWStepShape_RWBlock(py::module &);
void bind_RWStepShape_RWBooleanResult(py::module &);
void bind_RWStepShape_RWBoxDomain(py::module &);
void bind_RWStepShape_RWBoxedHalfSpace(py::module &);
void bind_RWStepShape_RWBrepWithVoids(py::module &);
void bind_RWStepShape_RWClosedShell(py::module &);
void bind_RWStepShape_RWCompoundShapeRepresentation(py::module &);
void bind_RWStepShape_RWConnectedEdgeSet(py::module &);
void bind_RWStepShape_RWConnectedFaceSet(py::module &);
void bind_RWStepShape_RWConnectedFaceShapeRepresentation(py::module &);
void bind_RWStepShape_RWConnectedFaceSubSet(py::module &);
void bind_RWStepShape_RWContextDependentShapeRepresentation(py::module &);
void bind_RWStepShape_RWCsgShapeRepresentation(py::module &);
void bind_RWStepShape_RWCsgSolid(py::module &);
void bind_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation(py::module &);
void bind_RWStepShape_RWDimensionalCharacteristicRepresentation(py::module &);
void bind_RWStepShape_RWDimensionalLocation(py::module &);
void bind_RWStepShape_RWDimensionalLocationWithPath(py::module &);
void bind_RWStepShape_RWDimensionalSize(py::module &);
void bind_RWStepShape_RWDimensionalSizeWithPath(py::module &);
void bind_RWStepShape_RWEdge(py::module &);
void bind_RWStepShape_RWEdgeBasedWireframeModel(py::module &);
void bind_RWStepShape_RWEdgeBasedWireframeShapeRepresentation(py::module &);
void bind_RWStepShape_RWEdgeCurve(py::module &);
void bind_RWStepShape_RWEdgeLoop(py::module &);
void bind_RWStepShape_RWExtrudedAreaSolid(py::module &);
void bind_RWStepShape_RWExtrudedFaceSolid(py::module &);
void bind_RWStepShape_RWFace(py::module &);
void bind_RWStepShape_RWFaceBasedSurfaceModel(py::module &);
void bind_RWStepShape_RWFaceBound(py::module &);
void bind_RWStepShape_RWFaceOuterBound(py::module &);
void bind_RWStepShape_RWFaceSurface(py::module &);
void bind_RWStepShape_RWFacetedBrep(py::module &);
void bind_RWStepShape_RWFacetedBrepAndBrepWithVoids(py::module &);
void bind_RWStepShape_RWFacetedBrepShapeRepresentation(py::module &);
void bind_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation(py::module &);
void bind_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation(py::module &);
void bind_RWStepShape_RWGeometricCurveSet(py::module &);
void bind_RWStepShape_RWGeometricSet(py::module &);
void bind_RWStepShape_RWHalfSpaceSolid(py::module &);
void bind_RWStepShape_RWLimitsAndFits(py::module &);
void bind_RWStepShape_RWLoop(py::module &);
void bind_RWStepShape_RWLoopAndPath(py::module &);
void bind_RWStepShape_RWManifoldSolidBrep(py::module &);
void bind_RWStepShape_RWManifoldSurfaceShapeRepresentation(py::module &);
void bind_RWStepShape_RWMeasureQualification(py::module &);
void bind_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem(py::module &);
void bind_RWStepShape_RWNonManifoldSurfaceShapeRepresentation(py::module &);
void bind_RWStepShape_RWOpenShell(py::module &);
void bind_RWStepShape_RWOrientedClosedShell(py::module &);
void bind_RWStepShape_RWOrientedEdge(py::module &);
void bind_RWStepShape_RWOrientedFace(py::module &);
void bind_RWStepShape_RWOrientedOpenShell(py::module &);
void bind_RWStepShape_RWOrientedPath(py::module &);
void bind_RWStepShape_RWPath(py::module &);
void bind_RWStepShape_RWPlusMinusTolerance(py::module &);
void bind_RWStepShape_RWPointRepresentation(py::module &);
void bind_RWStepShape_RWPolyLoop(py::module &);
void bind_RWStepShape_RWPrecisionQualifier(py::module &);
void bind_RWStepShape_RWQualifiedRepresentationItem(py::module &);
void bind_RWStepShape_RWRevolvedAreaSolid(py::module &);
void bind_RWStepShape_RWRevolvedFaceSolid(py::module &);
void bind_RWStepShape_RWRightAngularWedge(py::module &);
void bind_RWStepShape_RWRightCircularCone(py::module &);
void bind_RWStepShape_RWRightCircularCylinder(py::module &);
void bind_RWStepShape_RWSeamEdge(py::module &);
void bind_RWStepShape_RWShapeDefinitionRepresentation(py::module &);
void bind_RWStepShape_RWShapeDimensionRepresentation(py::module &);
void bind_RWStepShape_RWShapeRepresentation(py::module &);
void bind_RWStepShape_RWShapeRepresentationWithParameters(py::module &);
void bind_RWStepShape_RWShellBasedSurfaceModel(py::module &);
void bind_RWStepShape_RWSolidModel(py::module &);
void bind_RWStepShape_RWSolidReplica(py::module &);
void bind_RWStepShape_RWSphere(py::module &);
void bind_RWStepShape_RWSubedge(py::module &);
void bind_RWStepShape_RWSubface(py::module &);
void bind_RWStepShape_RWSweptAreaSolid(py::module &);
void bind_RWStepShape_RWSweptFaceSolid(py::module &);
void bind_RWStepShape_RWToleranceValue(py::module &);
void bind_RWStepShape_RWTopologicalRepresentationItem(py::module &);
void bind_RWStepShape_RWTorus(py::module &);
void bind_RWStepShape_RWTransitionalShapeRepresentation(py::module &);
void bind_RWStepShape_RWTypeQualifier(py::module &);
void bind_RWStepShape_RWValueFormatTypeQualifier(py::module &);
void bind_RWStepShape_RWVertex(py::module &);
void bind_RWStepShape_RWVertexLoop(py::module &);
void bind_RWStepShape_RWVertexPoint(py::module &);

PYBIND11_MODULE(RWStepShape, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepShape");

bind_RWStepShape_RWAdvancedBrepShapeRepresentation(mod);
bind_RWStepShape_RWAdvancedFace(mod);
bind_RWStepShape_RWAngularLocation(mod);
bind_RWStepShape_RWAngularSize(mod);
bind_RWStepShape_RWBlock(mod);
bind_RWStepShape_RWBooleanResult(mod);
bind_RWStepShape_RWBoxDomain(mod);
bind_RWStepShape_RWBoxedHalfSpace(mod);
bind_RWStepShape_RWBrepWithVoids(mod);
bind_RWStepShape_RWClosedShell(mod);
bind_RWStepShape_RWCompoundShapeRepresentation(mod);
bind_RWStepShape_RWConnectedEdgeSet(mod);
bind_RWStepShape_RWConnectedFaceSet(mod);
bind_RWStepShape_RWConnectedFaceShapeRepresentation(mod);
bind_RWStepShape_RWConnectedFaceSubSet(mod);
bind_RWStepShape_RWContextDependentShapeRepresentation(mod);
bind_RWStepShape_RWCsgShapeRepresentation(mod);
bind_RWStepShape_RWCsgSolid(mod);
bind_RWStepShape_RWDefinitionalRepresentationAndShapeRepresentation(mod);
bind_RWStepShape_RWDimensionalCharacteristicRepresentation(mod);
bind_RWStepShape_RWDimensionalLocation(mod);
bind_RWStepShape_RWDimensionalLocationWithPath(mod);
bind_RWStepShape_RWDimensionalSize(mod);
bind_RWStepShape_RWDimensionalSizeWithPath(mod);
bind_RWStepShape_RWEdge(mod);
bind_RWStepShape_RWEdgeBasedWireframeModel(mod);
bind_RWStepShape_RWEdgeBasedWireframeShapeRepresentation(mod);
bind_RWStepShape_RWEdgeCurve(mod);
bind_RWStepShape_RWEdgeLoop(mod);
bind_RWStepShape_RWExtrudedAreaSolid(mod);
bind_RWStepShape_RWExtrudedFaceSolid(mod);
bind_RWStepShape_RWFace(mod);
bind_RWStepShape_RWFaceBasedSurfaceModel(mod);
bind_RWStepShape_RWFaceBound(mod);
bind_RWStepShape_RWFaceOuterBound(mod);
bind_RWStepShape_RWFaceSurface(mod);
bind_RWStepShape_RWFacetedBrep(mod);
bind_RWStepShape_RWFacetedBrepAndBrepWithVoids(mod);
bind_RWStepShape_RWFacetedBrepShapeRepresentation(mod);
bind_RWStepShape_RWGeometricallyBoundedSurfaceShapeRepresentation(mod);
bind_RWStepShape_RWGeometricallyBoundedWireframeShapeRepresentation(mod);
bind_RWStepShape_RWGeometricCurveSet(mod);
bind_RWStepShape_RWGeometricSet(mod);
bind_RWStepShape_RWHalfSpaceSolid(mod);
bind_RWStepShape_RWLimitsAndFits(mod);
bind_RWStepShape_RWLoop(mod);
bind_RWStepShape_RWLoopAndPath(mod);
bind_RWStepShape_RWManifoldSolidBrep(mod);
bind_RWStepShape_RWManifoldSurfaceShapeRepresentation(mod);
bind_RWStepShape_RWMeasureQualification(mod);
bind_RWStepShape_RWMeasureRepresentationItemAndQualifiedRepresentationItem(mod);
bind_RWStepShape_RWNonManifoldSurfaceShapeRepresentation(mod);
bind_RWStepShape_RWOpenShell(mod);
bind_RWStepShape_RWOrientedClosedShell(mod);
bind_RWStepShape_RWOrientedEdge(mod);
bind_RWStepShape_RWOrientedFace(mod);
bind_RWStepShape_RWOrientedOpenShell(mod);
bind_RWStepShape_RWOrientedPath(mod);
bind_RWStepShape_RWPath(mod);
bind_RWStepShape_RWPlusMinusTolerance(mod);
bind_RWStepShape_RWPointRepresentation(mod);
bind_RWStepShape_RWPolyLoop(mod);
bind_RWStepShape_RWPrecisionQualifier(mod);
bind_RWStepShape_RWQualifiedRepresentationItem(mod);
bind_RWStepShape_RWRevolvedAreaSolid(mod);
bind_RWStepShape_RWRevolvedFaceSolid(mod);
bind_RWStepShape_RWRightAngularWedge(mod);
bind_RWStepShape_RWRightCircularCone(mod);
bind_RWStepShape_RWRightCircularCylinder(mod);
bind_RWStepShape_RWSeamEdge(mod);
bind_RWStepShape_RWShapeDefinitionRepresentation(mod);
bind_RWStepShape_RWShapeDimensionRepresentation(mod);
bind_RWStepShape_RWShapeRepresentation(mod);
bind_RWStepShape_RWShapeRepresentationWithParameters(mod);
bind_RWStepShape_RWShellBasedSurfaceModel(mod);
bind_RWStepShape_RWSolidModel(mod);
bind_RWStepShape_RWSolidReplica(mod);
bind_RWStepShape_RWSphere(mod);
bind_RWStepShape_RWSubedge(mod);
bind_RWStepShape_RWSubface(mod);
bind_RWStepShape_RWSweptAreaSolid(mod);
bind_RWStepShape_RWSweptFaceSolid(mod);
bind_RWStepShape_RWToleranceValue(mod);
bind_RWStepShape_RWTopologicalRepresentationItem(mod);
bind_RWStepShape_RWTorus(mod);
bind_RWStepShape_RWTransitionalShapeRepresentation(mod);
bind_RWStepShape_RWTypeQualifier(mod);
bind_RWStepShape_RWValueFormatTypeQualifier(mod);
bind_RWStepShape_RWVertex(mod);
bind_RWStepShape_RWVertexLoop(mod);
bind_RWStepShape_RWVertexPoint(mod);

}
