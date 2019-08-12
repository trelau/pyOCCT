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

void bind_StepFEA_EnumeratedDegreeOfFreedom(py::module &);
void bind_StepFEA_CoordinateSystemType(py::module &);
void bind_StepFEA_CurveEdge(py::module &);
void bind_StepFEA_ElementVolume(py::module &);
void bind_StepFEA_UnspecifiedValue(py::module &);
void bind_StepFEA_ElementOrElementGroup(py::module &);
void bind_StepFEA_ElementGeometricRelationship(py::module &);
void bind_StepFEA_SequenceOfElementGeometricRelationship(py::module &);
void bind_StepFEA_HSequenceOfElementGeometricRelationship(py::module &);
void bind_StepFEA_NodeRepresentation(py::module &);
void bind_StepFEA_Array1OfNodeRepresentation(py::module &);
void bind_StepFEA_HArray1OfNodeRepresentation(py::module &);
void bind_StepFEA_ElementRepresentation(py::module &);
void bind_StepFEA_SequenceOfElementRepresentation(py::module &);
void bind_StepFEA_HSequenceOfElementRepresentation(py::module &);
void bind_StepFEA_FeaRepresentationItem(py::module &);
void bind_StepFEA_AlignedCurve3dElementCoordinateSystem(py::module &);
void bind_StepFEA_AlignedSurface3dElementCoordinateSystem(py::module &);
void bind_StepFEA_ArbitraryVolume3dElementCoordinateSystem(py::module &);
void bind_StepFEA_CurveElementEndCoordinateSystem(py::module &);
void bind_StepFEA_CurveElementEndOffset(py::module &);
void bind_StepFEA_Array1OfCurveElementEndOffset(py::module &);
void bind_StepFEA_CurveElementEndRelease(py::module &);
void bind_StepFEA_Array1OfCurveElementEndRelease(py::module &);
void bind_StepFEA_CurveElementInterval(py::module &);
void bind_StepFEA_Array1OfCurveElementInterval(py::module &);
void bind_StepFEA_DegreeOfFreedom(py::module &);
void bind_StepFEA_Array1OfDegreeOfFreedom(py::module &);
void bind_StepFEA_Array1OfElementRepresentation(py::module &);
void bind_StepFEA_ConstantSurface3dElementCoordinateSystem(py::module &);
void bind_StepFEA_HArray1OfCurveElementInterval(py::module &);
void bind_StepFEA_HArray1OfCurveElementEndOffset(py::module &);
void bind_StepFEA_HArray1OfCurveElementEndRelease(py::module &);
void bind_StepFEA_Curve3dElementProperty(py::module &);
void bind_StepFEA_Curve3dElementRepresentation(py::module &);
void bind_StepFEA_CurveElementIntervalConstant(py::module &);
void bind_StepFEA_CurveElementIntervalLinearlyVarying(py::module &);
void bind_StepFEA_CurveElementLocation(py::module &);
void bind_StepFEA_DegreeOfFreedomMember(py::module &);
void bind_StepFEA_DummyNode(py::module &);
void bind_StepFEA_HArray1OfElementRepresentation(py::module &);
void bind_StepFEA_FeaGroup(py::module &);
void bind_StepFEA_ElementGroup(py::module &);
void bind_StepFEA_FeaMaterialPropertyRepresentationItem(py::module &);
void bind_StepFEA_FeaAreaDensity(py::module &);
void bind_StepFEA_FeaAxis2Placement3d(py::module &);
void bind_StepFEA_FeaCurveSectionGeometricRelationship(py::module &);
void bind_StepFEA_SymmetricTensor43d(py::module &);
void bind_StepFEA_FeaLinearElasticity(py::module &);
void bind_StepFEA_FeaMassDensity(py::module &);
void bind_StepFEA_FeaMaterialPropertyRepresentation(py::module &);
void bind_StepFEA_FeaModel(py::module &);
void bind_StepFEA_FeaModel3d(py::module &);
void bind_StepFEA_FeaModelDefinition(py::module &);
void bind_StepFEA_SymmetricTensor23d(py::module &);
void bind_StepFEA_FeaMoistureAbsorption(py::module &);
void bind_StepFEA_FeaParametricPoint(py::module &);
void bind_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion(py::module &);
void bind_StepFEA_SymmetricTensor42d(py::module &);
void bind_StepFEA_FeaShellBendingStiffness(py::module &);
void bind_StepFEA_FeaShellMembraneBendingCouplingStiffness(py::module &);
void bind_StepFEA_FeaShellMembraneStiffness(py::module &);
void bind_StepFEA_SymmetricTensor22d(py::module &);
void bind_StepFEA_FeaShellShearStiffness(py::module &);
void bind_StepFEA_FeaSurfaceSectionGeometricRelationship(py::module &);
void bind_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion(py::module &);
void bind_StepFEA_FreedomAndCoefficient(py::module &);
void bind_StepFEA_HArray1OfDegreeOfFreedom(py::module &);
void bind_StepFEA_FreedomsList(py::module &);
void bind_StepFEA_GeometricNode(py::module &);
void bind_StepFEA_SequenceOfCurve3dElementProperty(py::module &);
void bind_StepFEA_HSequenceOfCurve3dElementProperty(py::module &);
void bind_StepFEA_SequenceOfNodeRepresentation(py::module &);
void bind_StepFEA_HSequenceOfNodeRepresentation(py::module &);
void bind_StepFEA_Node(py::module &);
void bind_StepFEA_NodeDefinition(py::module &);
void bind_StepFEA_NodeGroup(py::module &);
void bind_StepFEA_NodeSet(py::module &);
void bind_StepFEA_NodeWithSolutionCoordinateSystem(py::module &);
void bind_StepFEA_NodeWithVector(py::module &);
void bind_StepFEA_ParametricCurve3dElementCoordinateDirection(py::module &);
void bind_StepFEA_ParametricCurve3dElementCoordinateSystem(py::module &);
void bind_StepFEA_ParametricSurface3dElementCoordinateSystem(py::module &);
void bind_StepFEA_Surface3dElementRepresentation(py::module &);
void bind_StepFEA_SymmetricTensor23dMember(py::module &);
void bind_StepFEA_SymmetricTensor43dMember(py::module &);
void bind_StepFEA_Volume3dElementRepresentation(py::module &);

PYBIND11_MODULE(StepFEA, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepElement");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepGeom");

bind_StepFEA_EnumeratedDegreeOfFreedom(mod);
bind_StepFEA_CoordinateSystemType(mod);
bind_StepFEA_CurveEdge(mod);
bind_StepFEA_ElementVolume(mod);
bind_StepFEA_UnspecifiedValue(mod);
bind_StepFEA_ElementOrElementGroup(mod);
bind_StepFEA_ElementGeometricRelationship(mod);
bind_StepFEA_SequenceOfElementGeometricRelationship(mod);
bind_StepFEA_HSequenceOfElementGeometricRelationship(mod);
bind_StepFEA_NodeRepresentation(mod);
bind_StepFEA_Array1OfNodeRepresentation(mod);
bind_StepFEA_HArray1OfNodeRepresentation(mod);
bind_StepFEA_ElementRepresentation(mod);
bind_StepFEA_SequenceOfElementRepresentation(mod);
bind_StepFEA_HSequenceOfElementRepresentation(mod);
bind_StepFEA_FeaRepresentationItem(mod);
bind_StepFEA_AlignedCurve3dElementCoordinateSystem(mod);
bind_StepFEA_AlignedSurface3dElementCoordinateSystem(mod);
bind_StepFEA_ArbitraryVolume3dElementCoordinateSystem(mod);
bind_StepFEA_CurveElementEndCoordinateSystem(mod);
bind_StepFEA_CurveElementEndOffset(mod);
bind_StepFEA_Array1OfCurveElementEndOffset(mod);
bind_StepFEA_CurveElementEndRelease(mod);
bind_StepFEA_Array1OfCurveElementEndRelease(mod);
bind_StepFEA_CurveElementInterval(mod);
bind_StepFEA_Array1OfCurveElementInterval(mod);
bind_StepFEA_DegreeOfFreedom(mod);
bind_StepFEA_Array1OfDegreeOfFreedom(mod);
bind_StepFEA_Array1OfElementRepresentation(mod);
bind_StepFEA_ConstantSurface3dElementCoordinateSystem(mod);
bind_StepFEA_HArray1OfCurveElementInterval(mod);
bind_StepFEA_HArray1OfCurveElementEndOffset(mod);
bind_StepFEA_HArray1OfCurveElementEndRelease(mod);
bind_StepFEA_Curve3dElementProperty(mod);
bind_StepFEA_Curve3dElementRepresentation(mod);
bind_StepFEA_CurveElementIntervalConstant(mod);
bind_StepFEA_CurveElementIntervalLinearlyVarying(mod);
bind_StepFEA_CurveElementLocation(mod);
bind_StepFEA_DegreeOfFreedomMember(mod);
bind_StepFEA_DummyNode(mod);
bind_StepFEA_HArray1OfElementRepresentation(mod);
bind_StepFEA_FeaGroup(mod);
bind_StepFEA_ElementGroup(mod);
bind_StepFEA_FeaMaterialPropertyRepresentationItem(mod);
bind_StepFEA_FeaAreaDensity(mod);
bind_StepFEA_FeaAxis2Placement3d(mod);
bind_StepFEA_FeaCurveSectionGeometricRelationship(mod);
bind_StepFEA_SymmetricTensor43d(mod);
bind_StepFEA_FeaLinearElasticity(mod);
bind_StepFEA_FeaMassDensity(mod);
bind_StepFEA_FeaMaterialPropertyRepresentation(mod);
bind_StepFEA_FeaModel(mod);
bind_StepFEA_FeaModel3d(mod);
bind_StepFEA_FeaModelDefinition(mod);
bind_StepFEA_SymmetricTensor23d(mod);
bind_StepFEA_FeaMoistureAbsorption(mod);
bind_StepFEA_FeaParametricPoint(mod);
bind_StepFEA_FeaSecantCoefficientOfLinearThermalExpansion(mod);
bind_StepFEA_SymmetricTensor42d(mod);
bind_StepFEA_FeaShellBendingStiffness(mod);
bind_StepFEA_FeaShellMembraneBendingCouplingStiffness(mod);
bind_StepFEA_FeaShellMembraneStiffness(mod);
bind_StepFEA_SymmetricTensor22d(mod);
bind_StepFEA_FeaShellShearStiffness(mod);
bind_StepFEA_FeaSurfaceSectionGeometricRelationship(mod);
bind_StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion(mod);
bind_StepFEA_FreedomAndCoefficient(mod);
bind_StepFEA_HArray1OfDegreeOfFreedom(mod);
bind_StepFEA_FreedomsList(mod);
bind_StepFEA_GeometricNode(mod);
bind_StepFEA_SequenceOfCurve3dElementProperty(mod);
bind_StepFEA_HSequenceOfCurve3dElementProperty(mod);
bind_StepFEA_SequenceOfNodeRepresentation(mod);
bind_StepFEA_HSequenceOfNodeRepresentation(mod);
bind_StepFEA_Node(mod);
bind_StepFEA_NodeDefinition(mod);
bind_StepFEA_NodeGroup(mod);
bind_StepFEA_NodeSet(mod);
bind_StepFEA_NodeWithSolutionCoordinateSystem(mod);
bind_StepFEA_NodeWithVector(mod);
bind_StepFEA_ParametricCurve3dElementCoordinateDirection(mod);
bind_StepFEA_ParametricCurve3dElementCoordinateSystem(mod);
bind_StepFEA_ParametricSurface3dElementCoordinateSystem(mod);
bind_StepFEA_Surface3dElementRepresentation(mod);
bind_StepFEA_SymmetricTensor23dMember(mod);
bind_StepFEA_SymmetricTensor43dMember(mod);
bind_StepFEA_Volume3dElementRepresentation(mod);

}
