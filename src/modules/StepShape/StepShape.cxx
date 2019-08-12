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

void bind_StepShape_AngleRelator(py::module &);
void bind_StepShape_BooleanOperator(py::module &);
void bind_StepShape_ShapeDefinitionRepresentation(py::module &);
void bind_StepShape_LimitsAndFits(py::module &);
void bind_StepShape_ShapeRepresentation(py::module &);
void bind_StepShape_AdvancedBrepShapeRepresentation(py::module &);
void bind_StepShape_TopologicalRepresentationItem(py::module &);
void bind_StepShape_FaceBound(py::module &);
void bind_StepShape_Array1OfFaceBound(py::module &);
void bind_StepShape_HArray1OfFaceBound(py::module &);
void bind_StepShape_Face(py::module &);
void bind_StepShape_FaceSurface(py::module &);
void bind_StepShape_AdvancedFace(py::module &);
void bind_StepShape_DimensionalLocation(py::module &);
void bind_StepShape_AngularLocation(py::module &);
void bind_StepShape_DimensionalSize(py::module &);
void bind_StepShape_AngularSize(py::module &);
void bind_StepShape_Vertex(py::module &);
void bind_StepShape_Edge(py::module &);
void bind_StepShape_Array1OfEdge(py::module &);
void bind_StepShape_HArray1OfEdge(py::module &);
void bind_StepShape_ConnectedEdgeSet(py::module &);
void bind_StepShape_Array1OfConnectedEdgeSet(py::module &);
void bind_StepShape_Array1OfFace(py::module &);
void bind_StepShape_HArray1OfFace(py::module &);
void bind_StepShape_ConnectedFaceSet(py::module &);
void bind_StepShape_Array1OfConnectedFaceSet(py::module &);
void bind_StepShape_GeometricSetSelect(py::module &);
void bind_StepShape_Array1OfGeometricSetSelect(py::module &);
void bind_StepShape_ClosedShell(py::module &);
void bind_StepShape_OrientedClosedShell(py::module &);
void bind_StepShape_Array1OfOrientedClosedShell(py::module &);
void bind_StepShape_OrientedEdge(py::module &);
void bind_StepShape_Array1OfOrientedEdge(py::module &);
void bind_StepShape_ShapeDimensionRepresentationItem(py::module &);
void bind_StepShape_Array1OfShapeDimensionRepresentationItem(py::module &);
void bind_StepShape_Shell(py::module &);
void bind_StepShape_Array1OfShell(py::module &);
void bind_StepShape_ValueQualifier(py::module &);
void bind_StepShape_Array1OfValueQualifier(py::module &);
void bind_StepShape_Block(py::module &);
void bind_StepShape_CsgPrimitive(py::module &);
void bind_StepShape_BooleanOperand(py::module &);
void bind_StepShape_BooleanResult(py::module &);
void bind_StepShape_BoxDomain(py::module &);
void bind_StepShape_HalfSpaceSolid(py::module &);
void bind_StepShape_BoxedHalfSpace(py::module &);
void bind_StepShape_HArray1OfOrientedClosedShell(py::module &);
void bind_StepShape_SolidModel(py::module &);
void bind_StepShape_ManifoldSolidBrep(py::module &);
void bind_StepShape_BrepWithVoids(py::module &);
void bind_StepShape_CompoundShapeRepresentation(py::module &);
void bind_StepShape_ConnectedFaceShapeRepresentation(py::module &);
void bind_StepShape_ConnectedFaceSubSet(py::module &);
void bind_StepShape_ContextDependentShapeRepresentation(py::module &);
void bind_StepShape_CsgSelect(py::module &);
void bind_StepShape_CsgShapeRepresentation(py::module &);
void bind_StepShape_CsgSolid(py::module &);
void bind_StepShape_DefinitionalRepresentationAndShapeRepresentation(py::module &);
void bind_StepShape_DimensionalCharacteristic(py::module &);
void bind_StepShape_DimensionalCharacteristicRepresentation(py::module &);
void bind_StepShape_DimensionalLocationWithPath(py::module &);
void bind_StepShape_DimensionalSizeWithPath(py::module &);
void bind_StepShape_DirectedDimensionalLocation(py::module &);
void bind_StepShape_HArray1OfConnectedEdgeSet(py::module &);
void bind_StepShape_EdgeBasedWireframeModel(py::module &);
void bind_StepShape_EdgeBasedWireframeShapeRepresentation(py::module &);
void bind_StepShape_EdgeCurve(py::module &);
void bind_StepShape_HArray1OfOrientedEdge(py::module &);
void bind_StepShape_Loop(py::module &);
void bind_StepShape_EdgeLoop(py::module &);
void bind_StepShape_SweptAreaSolid(py::module &);
void bind_StepShape_ExtrudedAreaSolid(py::module &);
void bind_StepShape_SweptFaceSolid(py::module &);
void bind_StepShape_ExtrudedFaceSolid(py::module &);
void bind_StepShape_HArray1OfConnectedFaceSet(py::module &);
void bind_StepShape_FaceBasedSurfaceModel(py::module &);
void bind_StepShape_FaceOuterBound(py::module &);
void bind_StepShape_FacetedBrep(py::module &);
void bind_StepShape_FacetedBrepAndBrepWithVoids(py::module &);
void bind_StepShape_FacetedBrepShapeRepresentation(py::module &);
void bind_StepShape_GeometricallyBoundedSurfaceShapeRepresentation(py::module &);
void bind_StepShape_GeometricallyBoundedWireframeShapeRepresentation(py::module &);
void bind_StepShape_HArray1OfGeometricSetSelect(py::module &);
void bind_StepShape_GeometricSet(py::module &);
void bind_StepShape_GeometricCurveSet(py::module &);
void bind_StepShape_HArray1OfShapeDimensionRepresentationItem(py::module &);
void bind_StepShape_HArray1OfShell(py::module &);
void bind_StepShape_HArray1OfValueQualifier(py::module &);
void bind_StepShape_LoopAndPath(py::module &);
void bind_StepShape_ManifoldSurfaceShapeRepresentation(py::module &);
void bind_StepShape_MeasureQualification(py::module &);
void bind_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem(py::module &);
void bind_StepShape_NonManifoldSurfaceShapeRepresentation(py::module &);
void bind_StepShape_OpenShell(py::module &);
void bind_StepShape_OrientedFace(py::module &);
void bind_StepShape_OrientedOpenShell(py::module &);
void bind_StepShape_Path(py::module &);
void bind_StepShape_OrientedPath(py::module &);
void bind_StepShape_ToleranceMethodDefinition(py::module &);
void bind_StepShape_PlusMinusTolerance(py::module &);
void bind_StepShape_PointRepresentation(py::module &);
void bind_StepShape_PolyLoop(py::module &);
void bind_StepShape_PrecisionQualifier(py::module &);
void bind_StepShape_QualifiedRepresentationItem(py::module &);
void bind_StepShape_ReversibleTopologyItem(py::module &);
void bind_StepShape_RevolvedAreaSolid(py::module &);
void bind_StepShape_RevolvedFaceSolid(py::module &);
void bind_StepShape_RightAngularWedge(py::module &);
void bind_StepShape_RightCircularCone(py::module &);
void bind_StepShape_RightCircularCylinder(py::module &);
void bind_StepShape_SeamEdge(py::module &);
void bind_StepShape_ShapeDimensionRepresentation(py::module &);
void bind_StepShape_ShapeRepresentationWithParameters(py::module &);
void bind_StepShape_ShellBasedSurfaceModel(py::module &);
void bind_StepShape_SolidReplica(py::module &);
void bind_StepShape_Sphere(py::module &);
void bind_StepShape_Subedge(py::module &);
void bind_StepShape_Subface(py::module &);
void bind_StepShape_SurfaceModel(py::module &);
void bind_StepShape_ToleranceValue(py::module &);
void bind_StepShape_Torus(py::module &);
void bind_StepShape_TransitionalShapeRepresentation(py::module &);
void bind_StepShape_TypeQualifier(py::module &);
void bind_StepShape_ValueFormatTypeQualifier(py::module &);
void bind_StepShape_VertexLoop(py::module &);
void bind_StepShape_VertexPoint(py::module &);

PYBIND11_MODULE(StepShape, mod) {

py::module::import("OCCT.StepRepr");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.StepData");
py::module::import("OCCT.StepBasic");

bind_StepShape_AngleRelator(mod);
bind_StepShape_BooleanOperator(mod);
bind_StepShape_ShapeDefinitionRepresentation(mod);
bind_StepShape_LimitsAndFits(mod);
bind_StepShape_ShapeRepresentation(mod);
bind_StepShape_AdvancedBrepShapeRepresentation(mod);
bind_StepShape_TopologicalRepresentationItem(mod);
bind_StepShape_FaceBound(mod);
bind_StepShape_Array1OfFaceBound(mod);
bind_StepShape_HArray1OfFaceBound(mod);
bind_StepShape_Face(mod);
bind_StepShape_FaceSurface(mod);
bind_StepShape_AdvancedFace(mod);
bind_StepShape_DimensionalLocation(mod);
bind_StepShape_AngularLocation(mod);
bind_StepShape_DimensionalSize(mod);
bind_StepShape_AngularSize(mod);
bind_StepShape_Vertex(mod);
bind_StepShape_Edge(mod);
bind_StepShape_Array1OfEdge(mod);
bind_StepShape_HArray1OfEdge(mod);
bind_StepShape_ConnectedEdgeSet(mod);
bind_StepShape_Array1OfConnectedEdgeSet(mod);
bind_StepShape_Array1OfFace(mod);
bind_StepShape_HArray1OfFace(mod);
bind_StepShape_ConnectedFaceSet(mod);
bind_StepShape_Array1OfConnectedFaceSet(mod);
bind_StepShape_GeometricSetSelect(mod);
bind_StepShape_Array1OfGeometricSetSelect(mod);
bind_StepShape_ClosedShell(mod);
bind_StepShape_OrientedClosedShell(mod);
bind_StepShape_Array1OfOrientedClosedShell(mod);
bind_StepShape_OrientedEdge(mod);
bind_StepShape_Array1OfOrientedEdge(mod);
bind_StepShape_ShapeDimensionRepresentationItem(mod);
bind_StepShape_Array1OfShapeDimensionRepresentationItem(mod);
bind_StepShape_Shell(mod);
bind_StepShape_Array1OfShell(mod);
bind_StepShape_ValueQualifier(mod);
bind_StepShape_Array1OfValueQualifier(mod);
bind_StepShape_Block(mod);
bind_StepShape_CsgPrimitive(mod);
bind_StepShape_BooleanOperand(mod);
bind_StepShape_BooleanResult(mod);
bind_StepShape_BoxDomain(mod);
bind_StepShape_HalfSpaceSolid(mod);
bind_StepShape_BoxedHalfSpace(mod);
bind_StepShape_HArray1OfOrientedClosedShell(mod);
bind_StepShape_SolidModel(mod);
bind_StepShape_ManifoldSolidBrep(mod);
bind_StepShape_BrepWithVoids(mod);
bind_StepShape_CompoundShapeRepresentation(mod);
bind_StepShape_ConnectedFaceShapeRepresentation(mod);
bind_StepShape_ConnectedFaceSubSet(mod);
bind_StepShape_ContextDependentShapeRepresentation(mod);
bind_StepShape_CsgSelect(mod);
bind_StepShape_CsgShapeRepresentation(mod);
bind_StepShape_CsgSolid(mod);
bind_StepShape_DefinitionalRepresentationAndShapeRepresentation(mod);
bind_StepShape_DimensionalCharacteristic(mod);
bind_StepShape_DimensionalCharacteristicRepresentation(mod);
bind_StepShape_DimensionalLocationWithPath(mod);
bind_StepShape_DimensionalSizeWithPath(mod);
bind_StepShape_DirectedDimensionalLocation(mod);
bind_StepShape_HArray1OfConnectedEdgeSet(mod);
bind_StepShape_EdgeBasedWireframeModel(mod);
bind_StepShape_EdgeBasedWireframeShapeRepresentation(mod);
bind_StepShape_EdgeCurve(mod);
bind_StepShape_HArray1OfOrientedEdge(mod);
bind_StepShape_Loop(mod);
bind_StepShape_EdgeLoop(mod);
bind_StepShape_SweptAreaSolid(mod);
bind_StepShape_ExtrudedAreaSolid(mod);
bind_StepShape_SweptFaceSolid(mod);
bind_StepShape_ExtrudedFaceSolid(mod);
bind_StepShape_HArray1OfConnectedFaceSet(mod);
bind_StepShape_FaceBasedSurfaceModel(mod);
bind_StepShape_FaceOuterBound(mod);
bind_StepShape_FacetedBrep(mod);
bind_StepShape_FacetedBrepAndBrepWithVoids(mod);
bind_StepShape_FacetedBrepShapeRepresentation(mod);
bind_StepShape_GeometricallyBoundedSurfaceShapeRepresentation(mod);
bind_StepShape_GeometricallyBoundedWireframeShapeRepresentation(mod);
bind_StepShape_HArray1OfGeometricSetSelect(mod);
bind_StepShape_GeometricSet(mod);
bind_StepShape_GeometricCurveSet(mod);
bind_StepShape_HArray1OfShapeDimensionRepresentationItem(mod);
bind_StepShape_HArray1OfShell(mod);
bind_StepShape_HArray1OfValueQualifier(mod);
bind_StepShape_LoopAndPath(mod);
bind_StepShape_ManifoldSurfaceShapeRepresentation(mod);
bind_StepShape_MeasureQualification(mod);
bind_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem(mod);
bind_StepShape_NonManifoldSurfaceShapeRepresentation(mod);
bind_StepShape_OpenShell(mod);
bind_StepShape_OrientedFace(mod);
bind_StepShape_OrientedOpenShell(mod);
bind_StepShape_Path(mod);
bind_StepShape_OrientedPath(mod);
bind_StepShape_ToleranceMethodDefinition(mod);
bind_StepShape_PlusMinusTolerance(mod);
bind_StepShape_PointRepresentation(mod);
bind_StepShape_PolyLoop(mod);
bind_StepShape_PrecisionQualifier(mod);
bind_StepShape_QualifiedRepresentationItem(mod);
bind_StepShape_ReversibleTopologyItem(mod);
bind_StepShape_RevolvedAreaSolid(mod);
bind_StepShape_RevolvedFaceSolid(mod);
bind_StepShape_RightAngularWedge(mod);
bind_StepShape_RightCircularCone(mod);
bind_StepShape_RightCircularCylinder(mod);
bind_StepShape_SeamEdge(mod);
bind_StepShape_ShapeDimensionRepresentation(mod);
bind_StepShape_ShapeRepresentationWithParameters(mod);
bind_StepShape_ShellBasedSurfaceModel(mod);
bind_StepShape_SolidReplica(mod);
bind_StepShape_Sphere(mod);
bind_StepShape_Subedge(mod);
bind_StepShape_Subface(mod);
bind_StepShape_SurfaceModel(mod);
bind_StepShape_ToleranceValue(mod);
bind_StepShape_Torus(mod);
bind_StepShape_TransitionalShapeRepresentation(mod);
bind_StepShape_TypeQualifier(mod);
bind_StepShape_ValueFormatTypeQualifier(mod);
bind_StepShape_VertexLoop(mod);
bind_StepShape_VertexPoint(mod);

}
