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

void bind_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWConstantSurface3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWCurve3dElementProperty(py::module &);
void bind_RWStepFEA_RWCurve3dElementRepresentation(py::module &);
void bind_RWStepFEA_RWCurveElementEndOffset(py::module &);
void bind_RWStepFEA_RWCurveElementEndRelease(py::module &);
void bind_RWStepFEA_RWCurveElementInterval(py::module &);
void bind_RWStepFEA_RWCurveElementIntervalConstant(py::module &);
void bind_RWStepFEA_RWCurveElementIntervalLinearlyVarying(py::module &);
void bind_RWStepFEA_RWCurveElementLocation(py::module &);
void bind_RWStepFEA_RWDummyNode(py::module &);
void bind_RWStepFEA_RWElementGeometricRelationship(py::module &);
void bind_RWStepFEA_RWElementGroup(py::module &);
void bind_RWStepFEA_RWElementRepresentation(py::module &);
void bind_RWStepFEA_RWFeaAreaDensity(py::module &);
void bind_RWStepFEA_RWFeaAxis2Placement3d(py::module &);
void bind_RWStepFEA_RWFeaCurveSectionGeometricRelationship(py::module &);
void bind_RWStepFEA_RWFeaGroup(py::module &);
void bind_RWStepFEA_RWFeaLinearElasticity(py::module &);
void bind_RWStepFEA_RWFeaMassDensity(py::module &);
void bind_RWStepFEA_RWFeaMaterialPropertyRepresentation(py::module &);
void bind_RWStepFEA_RWFeaMaterialPropertyRepresentationItem(py::module &);
void bind_RWStepFEA_RWFeaModel(py::module &);
void bind_RWStepFEA_RWFeaModel3d(py::module &);
void bind_RWStepFEA_RWFeaModelDefinition(py::module &);
void bind_RWStepFEA_RWFeaMoistureAbsorption(py::module &);
void bind_RWStepFEA_RWFeaParametricPoint(py::module &);
void bind_RWStepFEA_RWFeaRepresentationItem(py::module &);
void bind_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion(py::module &);
void bind_RWStepFEA_RWFeaShellBendingStiffness(py::module &);
void bind_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness(py::module &);
void bind_RWStepFEA_RWFeaShellMembraneStiffness(py::module &);
void bind_RWStepFEA_RWFeaShellShearStiffness(py::module &);
void bind_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship(py::module &);
void bind_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion(py::module &);
void bind_RWStepFEA_RWFreedomAndCoefficient(py::module &);
void bind_RWStepFEA_RWFreedomsList(py::module &);
void bind_RWStepFEA_RWGeometricNode(py::module &);
void bind_RWStepFEA_RWNode(py::module &);
void bind_RWStepFEA_RWNodeDefinition(py::module &);
void bind_RWStepFEA_RWNodeGroup(py::module &);
void bind_RWStepFEA_RWNodeRepresentation(py::module &);
void bind_RWStepFEA_RWNodeSet(py::module &);
void bind_RWStepFEA_RWNodeWithSolutionCoordinateSystem(py::module &);
void bind_RWStepFEA_RWNodeWithVector(py::module &);
void bind_RWStepFEA_RWParametricCurve3dElementCoordinateDirection(py::module &);
void bind_RWStepFEA_RWParametricCurve3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWParametricSurface3dElementCoordinateSystem(py::module &);
void bind_RWStepFEA_RWSurface3dElementRepresentation(py::module &);
void bind_RWStepFEA_RWVolume3dElementRepresentation(py::module &);

PYBIND11_MODULE(RWStepFEA, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepFEA");

bind_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWConstantSurface3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWCurve3dElementProperty(mod);
bind_RWStepFEA_RWCurve3dElementRepresentation(mod);
bind_RWStepFEA_RWCurveElementEndOffset(mod);
bind_RWStepFEA_RWCurveElementEndRelease(mod);
bind_RWStepFEA_RWCurveElementInterval(mod);
bind_RWStepFEA_RWCurveElementIntervalConstant(mod);
bind_RWStepFEA_RWCurveElementIntervalLinearlyVarying(mod);
bind_RWStepFEA_RWCurveElementLocation(mod);
bind_RWStepFEA_RWDummyNode(mod);
bind_RWStepFEA_RWElementGeometricRelationship(mod);
bind_RWStepFEA_RWElementGroup(mod);
bind_RWStepFEA_RWElementRepresentation(mod);
bind_RWStepFEA_RWFeaAreaDensity(mod);
bind_RWStepFEA_RWFeaAxis2Placement3d(mod);
bind_RWStepFEA_RWFeaCurveSectionGeometricRelationship(mod);
bind_RWStepFEA_RWFeaGroup(mod);
bind_RWStepFEA_RWFeaLinearElasticity(mod);
bind_RWStepFEA_RWFeaMassDensity(mod);
bind_RWStepFEA_RWFeaMaterialPropertyRepresentation(mod);
bind_RWStepFEA_RWFeaMaterialPropertyRepresentationItem(mod);
bind_RWStepFEA_RWFeaModel(mod);
bind_RWStepFEA_RWFeaModel3d(mod);
bind_RWStepFEA_RWFeaModelDefinition(mod);
bind_RWStepFEA_RWFeaMoistureAbsorption(mod);
bind_RWStepFEA_RWFeaParametricPoint(mod);
bind_RWStepFEA_RWFeaRepresentationItem(mod);
bind_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion(mod);
bind_RWStepFEA_RWFeaShellBendingStiffness(mod);
bind_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness(mod);
bind_RWStepFEA_RWFeaShellMembraneStiffness(mod);
bind_RWStepFEA_RWFeaShellShearStiffness(mod);
bind_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship(mod);
bind_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion(mod);
bind_RWStepFEA_RWFreedomAndCoefficient(mod);
bind_RWStepFEA_RWFreedomsList(mod);
bind_RWStepFEA_RWGeometricNode(mod);
bind_RWStepFEA_RWNode(mod);
bind_RWStepFEA_RWNodeDefinition(mod);
bind_RWStepFEA_RWNodeGroup(mod);
bind_RWStepFEA_RWNodeRepresentation(mod);
bind_RWStepFEA_RWNodeSet(mod);
bind_RWStepFEA_RWNodeWithSolutionCoordinateSystem(mod);
bind_RWStepFEA_RWNodeWithVector(mod);
bind_RWStepFEA_RWParametricCurve3dElementCoordinateDirection(mod);
bind_RWStepFEA_RWParametricCurve3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWParametricSurface3dElementCoordinateSystem(mod);
bind_RWStepFEA_RWSurface3dElementRepresentation(mod);
bind_RWStepFEA_RWVolume3dElementRepresentation(mod);

}
