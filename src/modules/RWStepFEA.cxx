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
#include <StepFEA_AlignedCurve3dElementCoordinateSystem.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_AlignedSurface3dElementCoordinateSystem.hxx>
#include <RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.hxx>
#include <StepFEA_ArbitraryVolume3dElementCoordinateSystem.hxx>
#include <RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.hxx>
#include <StepFEA_ConstantSurface3dElementCoordinateSystem.hxx>
#include <RWStepFEA_RWConstantSurface3dElementCoordinateSystem.hxx>
#include <StepFEA_Curve3dElementProperty.hxx>
#include <RWStepFEA_RWCurve3dElementProperty.hxx>
#include <StepFEA_Curve3dElementRepresentation.hxx>
#include <RWStepFEA_RWCurve3dElementRepresentation.hxx>
#include <StepFEA_CurveElementEndOffset.hxx>
#include <RWStepFEA_RWCurveElementEndOffset.hxx>
#include <StepFEA_CurveElementEndRelease.hxx>
#include <RWStepFEA_RWCurveElementEndRelease.hxx>
#include <StepFEA_CurveElementInterval.hxx>
#include <RWStepFEA_RWCurveElementInterval.hxx>
#include <StepFEA_CurveElementIntervalConstant.hxx>
#include <RWStepFEA_RWCurveElementIntervalConstant.hxx>
#include <StepFEA_CurveElementIntervalLinearlyVarying.hxx>
#include <RWStepFEA_RWCurveElementIntervalLinearlyVarying.hxx>
#include <StepFEA_CurveElementLocation.hxx>
#include <RWStepFEA_RWCurveElementLocation.hxx>
#include <StepFEA_DummyNode.hxx>
#include <RWStepFEA_RWDummyNode.hxx>
#include <StepFEA_ElementGeometricRelationship.hxx>
#include <RWStepFEA_RWElementGeometricRelationship.hxx>
#include <StepFEA_ElementGroup.hxx>
#include <RWStepFEA_RWElementGroup.hxx>
#include <StepFEA_ElementRepresentation.hxx>
#include <RWStepFEA_RWElementRepresentation.hxx>
#include <StepFEA_FeaAreaDensity.hxx>
#include <RWStepFEA_RWFeaAreaDensity.hxx>
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <RWStepFEA_RWFeaAxis2Placement3d.hxx>
#include <StepFEA_FeaCurveSectionGeometricRelationship.hxx>
#include <RWStepFEA_RWFeaCurveSectionGeometricRelationship.hxx>
#include <StepFEA_FeaGroup.hxx>
#include <RWStepFEA_RWFeaGroup.hxx>
#include <StepFEA_FeaLinearElasticity.hxx>
#include <RWStepFEA_RWFeaLinearElasticity.hxx>
#include <StepFEA_FeaMassDensity.hxx>
#include <RWStepFEA_RWFeaMassDensity.hxx>
#include <StepFEA_FeaMaterialPropertyRepresentation.hxx>
#include <RWStepFEA_RWFeaMaterialPropertyRepresentation.hxx>
#include <StepFEA_FeaMaterialPropertyRepresentationItem.hxx>
#include <RWStepFEA_RWFeaMaterialPropertyRepresentationItem.hxx>
#include <StepFEA_FeaModel.hxx>
#include <RWStepFEA_RWFeaModel.hxx>
#include <StepFEA_FeaModel3d.hxx>
#include <RWStepFEA_RWFeaModel3d.hxx>
#include <StepFEA_FeaModelDefinition.hxx>
#include <RWStepFEA_RWFeaModelDefinition.hxx>
#include <StepFEA_FeaMoistureAbsorption.hxx>
#include <RWStepFEA_RWFeaMoistureAbsorption.hxx>
#include <StepFEA_FeaParametricPoint.hxx>
#include <RWStepFEA_RWFeaParametricPoint.hxx>
#include <StepFEA_FeaRepresentationItem.hxx>
#include <RWStepFEA_RWFeaRepresentationItem.hxx>
#include <StepFEA_FeaSecantCoefficientOfLinearThermalExpansion.hxx>
#include <RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.hxx>
#include <StepFEA_FeaShellBendingStiffness.hxx>
#include <RWStepFEA_RWFeaShellBendingStiffness.hxx>
#include <StepFEA_FeaShellMembraneBendingCouplingStiffness.hxx>
#include <RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.hxx>
#include <StepFEA_FeaShellMembraneStiffness.hxx>
#include <RWStepFEA_RWFeaShellMembraneStiffness.hxx>
#include <StepFEA_FeaShellShearStiffness.hxx>
#include <RWStepFEA_RWFeaShellShearStiffness.hxx>
#include <StepFEA_FeaSurfaceSectionGeometricRelationship.hxx>
#include <RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.hxx>
#include <StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion.hxx>
#include <RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.hxx>
#include <StepFEA_FreedomAndCoefficient.hxx>
#include <RWStepFEA_RWFreedomAndCoefficient.hxx>
#include <StepFEA_FreedomsList.hxx>
#include <RWStepFEA_RWFreedomsList.hxx>
#include <StepFEA_GeometricNode.hxx>
#include <RWStepFEA_RWGeometricNode.hxx>
#include <StepFEA_Node.hxx>
#include <RWStepFEA_RWNode.hxx>
#include <StepFEA_NodeDefinition.hxx>
#include <RWStepFEA_RWNodeDefinition.hxx>
#include <StepFEA_NodeGroup.hxx>
#include <RWStepFEA_RWNodeGroup.hxx>
#include <StepFEA_NodeRepresentation.hxx>
#include <RWStepFEA_RWNodeRepresentation.hxx>
#include <StepFEA_NodeSet.hxx>
#include <RWStepFEA_RWNodeSet.hxx>
#include <StepFEA_NodeWithSolutionCoordinateSystem.hxx>
#include <RWStepFEA_RWNodeWithSolutionCoordinateSystem.hxx>
#include <StepFEA_NodeWithVector.hxx>
#include <RWStepFEA_RWNodeWithVector.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateDirection.hxx>
#include <RWStepFEA_RWParametricCurve3dElementCoordinateDirection.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateSystem.hxx>
#include <RWStepFEA_RWParametricCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_ParametricSurface3dElementCoordinateSystem.hxx>
#include <RWStepFEA_RWParametricSurface3dElementCoordinateSystem.hxx>
#include <StepFEA_Surface3dElementRepresentation.hxx>
#include <RWStepFEA_RWSurface3dElementRepresentation.hxx>
#include <StepFEA_Volume3dElementRepresentation.hxx>
#include <RWStepFEA_RWVolume3dElementRepresentation.hxx>

PYBIND11_MODULE(RWStepFEA, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepFEA");

// CLASS: RWSTEPFEA_RWALIGNEDCURVE3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWAlignedCurve3dElementCoordinateSystem> cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem(mod, "RWStepFEA_RWAlignedCurve3dElementCoordinateSystem", "Read & Write tool for AlignedCurve3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem> &) const) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::ReadStep, "Reads AlignedCurve3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem> &) const) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::WriteStep, "Writes AlignedCurve3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWAlignedCurve3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWAlignedCurve3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWALIGNEDSURFACE3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWAlignedSurface3dElementCoordinateSystem> cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem(mod, "RWStepFEA_RWAlignedSurface3dElementCoordinateSystem", "Read & Write tool for AlignedSurface3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_AlignedSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::ReadStep, "Reads AlignedSurface3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_AlignedSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::WriteStep, "Writes AlignedSurface3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWAlignedSurface3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_AlignedSurface3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWAlignedSurface3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWARBITRARYVOLUME3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem> cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem(mod, "RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem", "Read & Write tool for ArbitraryVolume3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ArbitraryVolume3dElementCoordinateSystem> &) const) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::ReadStep, "Reads ArbitraryVolume3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ArbitraryVolume3dElementCoordinateSystem> &) const) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::WriteStep, "Writes ArbitraryVolume3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_ArbitraryVolume3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWArbitraryVolume3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCONSTANTSURFACE3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWConstantSurface3dElementCoordinateSystem> cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem(mod, "RWStepFEA_RWConstantSurface3dElementCoordinateSystem", "Read & Write tool for ConstantSurface3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWConstantSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ConstantSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::ReadStep, "Reads ConstantSurface3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWConstantSurface3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ConstantSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::WriteStep, "Writes ConstantSurface3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWConstantSurface3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWConstantSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_ConstantSurface3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWConstantSurface3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVE3DELEMENTPROPERTY
py::class_<RWStepFEA_RWCurve3dElementProperty> cls_RWStepFEA_RWCurve3dElementProperty(mod, "RWStepFEA_RWCurve3dElementProperty", "Read & Write tool for Curve3dElementProperty");

// Constructors
cls_RWStepFEA_RWCurve3dElementProperty.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurve3dElementProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurve3dElementProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurve3dElementProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurve3dElementProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurve3dElementProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurve3dElementProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurve3dElementProperty.def("ReadStep", (void (RWStepFEA_RWCurve3dElementProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Curve3dElementProperty> &) const) &RWStepFEA_RWCurve3dElementProperty::ReadStep, "Reads Curve3dElementProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurve3dElementProperty.def("WriteStep", (void (RWStepFEA_RWCurve3dElementProperty::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Curve3dElementProperty> &) const) &RWStepFEA_RWCurve3dElementProperty::WriteStep, "Writes Curve3dElementProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurve3dElementProperty.def("Share", (void (RWStepFEA_RWCurve3dElementProperty::*)(const opencascade::handle<StepFEA_Curve3dElementProperty> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurve3dElementProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVE3DELEMENTREPRESENTATION
py::class_<RWStepFEA_RWCurve3dElementRepresentation> cls_RWStepFEA_RWCurve3dElementRepresentation(mod, "RWStepFEA_RWCurve3dElementRepresentation", "Read & Write tool for Curve3dElementRepresentation");

// Constructors
cls_RWStepFEA_RWCurve3dElementRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurve3dElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurve3dElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurve3dElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurve3dElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurve3dElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurve3dElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurve3dElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurve3dElementRepresentation.def("ReadStep", (void (RWStepFEA_RWCurve3dElementRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Curve3dElementRepresentation> &) const) &RWStepFEA_RWCurve3dElementRepresentation::ReadStep, "Reads Curve3dElementRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurve3dElementRepresentation.def("WriteStep", (void (RWStepFEA_RWCurve3dElementRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Curve3dElementRepresentation> &) const) &RWStepFEA_RWCurve3dElementRepresentation::WriteStep, "Writes Curve3dElementRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurve3dElementRepresentation.def("Share", (void (RWStepFEA_RWCurve3dElementRepresentation::*)(const opencascade::handle<StepFEA_Curve3dElementRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurve3dElementRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTENDOFFSET
py::class_<RWStepFEA_RWCurveElementEndOffset> cls_RWStepFEA_RWCurveElementEndOffset(mod, "RWStepFEA_RWCurveElementEndOffset", "Read & Write tool for CurveElementEndOffset");

// Constructors
cls_RWStepFEA_RWCurveElementEndOffset.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndOffset::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndOffset::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementEndOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementEndOffset.def("ReadStep", (void (RWStepFEA_RWCurveElementEndOffset::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementEndOffset> &) const) &RWStepFEA_RWCurveElementEndOffset::ReadStep, "Reads CurveElementEndOffset", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndOffset.def("WriteStep", (void (RWStepFEA_RWCurveElementEndOffset::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementEndOffset> &) const) &RWStepFEA_RWCurveElementEndOffset::WriteStep, "Writes CurveElementEndOffset", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndOffset.def("Share", (void (RWStepFEA_RWCurveElementEndOffset::*)(const opencascade::handle<StepFEA_CurveElementEndOffset> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementEndOffset::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTENDRELEASE
py::class_<RWStepFEA_RWCurveElementEndRelease> cls_RWStepFEA_RWCurveElementEndRelease(mod, "RWStepFEA_RWCurveElementEndRelease", "Read & Write tool for CurveElementEndRelease");

// Constructors
cls_RWStepFEA_RWCurveElementEndRelease.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndRelease::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndRelease::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndRelease::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndRelease::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementEndRelease::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndRelease.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementEndRelease::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementEndRelease.def("ReadStep", (void (RWStepFEA_RWCurveElementEndRelease::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementEndRelease> &) const) &RWStepFEA_RWCurveElementEndRelease::ReadStep, "Reads CurveElementEndRelease", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndRelease.def("WriteStep", (void (RWStepFEA_RWCurveElementEndRelease::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementEndRelease> &) const) &RWStepFEA_RWCurveElementEndRelease::WriteStep, "Writes CurveElementEndRelease", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndRelease.def("Share", (void (RWStepFEA_RWCurveElementEndRelease::*)(const opencascade::handle<StepFEA_CurveElementEndRelease> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementEndRelease::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTINTERVAL
py::class_<RWStepFEA_RWCurveElementInterval> cls_RWStepFEA_RWCurveElementInterval(mod, "RWStepFEA_RWCurveElementInterval", "Read & Write tool for CurveElementInterval");

// Constructors
cls_RWStepFEA_RWCurveElementInterval.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementInterval::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementInterval::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementInterval::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementInterval::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementInterval::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementInterval.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementInterval::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementInterval.def("ReadStep", (void (RWStepFEA_RWCurveElementInterval::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementInterval> &) const) &RWStepFEA_RWCurveElementInterval::ReadStep, "Reads CurveElementInterval", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementInterval.def("WriteStep", (void (RWStepFEA_RWCurveElementInterval::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementInterval> &) const) &RWStepFEA_RWCurveElementInterval::WriteStep, "Writes CurveElementInterval", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementInterval.def("Share", (void (RWStepFEA_RWCurveElementInterval::*)(const opencascade::handle<StepFEA_CurveElementInterval> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementInterval::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTINTERVALCONSTANT
py::class_<RWStepFEA_RWCurveElementIntervalConstant> cls_RWStepFEA_RWCurveElementIntervalConstant(mod, "RWStepFEA_RWCurveElementIntervalConstant", "Read & Write tool for CurveElementIntervalConstant");

// Constructors
cls_RWStepFEA_RWCurveElementIntervalConstant.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementIntervalConstant::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementIntervalConstant::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementIntervalConstant::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementIntervalConstant::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementIntervalConstant::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalConstant.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementIntervalConstant::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementIntervalConstant.def("ReadStep", (void (RWStepFEA_RWCurveElementIntervalConstant::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementIntervalConstant> &) const) &RWStepFEA_RWCurveElementIntervalConstant::ReadStep, "Reads CurveElementIntervalConstant", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementIntervalConstant.def("WriteStep", (void (RWStepFEA_RWCurveElementIntervalConstant::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementIntervalConstant> &) const) &RWStepFEA_RWCurveElementIntervalConstant::WriteStep, "Writes CurveElementIntervalConstant", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementIntervalConstant.def("Share", (void (RWStepFEA_RWCurveElementIntervalConstant::*)(const opencascade::handle<StepFEA_CurveElementIntervalConstant> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementIntervalConstant::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTINTERVALLINEARLYVARYING
py::class_<RWStepFEA_RWCurveElementIntervalLinearlyVarying> cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying(mod, "RWStepFEA_RWCurveElementIntervalLinearlyVarying", "Read & Write tool for CurveElementIntervalLinearlyVarying");

// Constructors
cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def("ReadStep", (void (RWStepFEA_RWCurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementIntervalLinearlyVarying> &) const) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::ReadStep, "Reads CurveElementIntervalLinearlyVarying", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def("WriteStep", (void (RWStepFEA_RWCurveElementIntervalLinearlyVarying::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementIntervalLinearlyVarying> &) const) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::WriteStep, "Writes CurveElementIntervalLinearlyVarying", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementIntervalLinearlyVarying.def("Share", (void (RWStepFEA_RWCurveElementIntervalLinearlyVarying::*)(const opencascade::handle<StepFEA_CurveElementIntervalLinearlyVarying> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementIntervalLinearlyVarying::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWCURVEELEMENTLOCATION
py::class_<RWStepFEA_RWCurveElementLocation> cls_RWStepFEA_RWCurveElementLocation(mod, "RWStepFEA_RWCurveElementLocation", "Read & Write tool for CurveElementLocation");

// Constructors
cls_RWStepFEA_RWCurveElementLocation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementLocation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementLocation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementLocation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementLocation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementLocation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementLocation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementLocation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementLocation.def("ReadStep", (void (RWStepFEA_RWCurveElementLocation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementLocation> &) const) &RWStepFEA_RWCurveElementLocation::ReadStep, "Reads CurveElementLocation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementLocation.def("WriteStep", (void (RWStepFEA_RWCurveElementLocation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementLocation> &) const) &RWStepFEA_RWCurveElementLocation::WriteStep, "Writes CurveElementLocation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementLocation.def("Share", (void (RWStepFEA_RWCurveElementLocation::*)(const opencascade::handle<StepFEA_CurveElementLocation> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementLocation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWDUMMYNODE
py::class_<RWStepFEA_RWDummyNode> cls_RWStepFEA_RWDummyNode(mod, "RWStepFEA_RWDummyNode", "Read & Write tool for DummyNode");

// Constructors
cls_RWStepFEA_RWDummyNode.def(py::init<>());

// Methods
// cls_RWStepFEA_RWDummyNode.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWDummyNode::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWDummyNode.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWDummyNode::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWDummyNode.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWDummyNode::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWDummyNode.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWDummyNode::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWDummyNode.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWDummyNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWDummyNode.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWDummyNode::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWDummyNode.def("ReadStep", (void (RWStepFEA_RWDummyNode::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_DummyNode> &) const) &RWStepFEA_RWDummyNode::ReadStep, "Reads DummyNode", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWDummyNode.def("WriteStep", (void (RWStepFEA_RWDummyNode::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_DummyNode> &) const) &RWStepFEA_RWDummyNode::WriteStep, "Writes DummyNode", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWDummyNode.def("Share", (void (RWStepFEA_RWDummyNode::*)(const opencascade::handle<StepFEA_DummyNode> &, Interface_EntityIterator &) const) &RWStepFEA_RWDummyNode::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWELEMENTGEOMETRICRELATIONSHIP
py::class_<RWStepFEA_RWElementGeometricRelationship> cls_RWStepFEA_RWElementGeometricRelationship(mod, "RWStepFEA_RWElementGeometricRelationship", "Read & Write tool for ElementGeometricRelationship");

// Constructors
cls_RWStepFEA_RWElementGeometricRelationship.def(py::init<>());

// Methods
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWElementGeometricRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWElementGeometricRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWElementGeometricRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWElementGeometricRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWElementGeometricRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWElementGeometricRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWElementGeometricRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWElementGeometricRelationship.def("ReadStep", (void (RWStepFEA_RWElementGeometricRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ElementGeometricRelationship> &) const) &RWStepFEA_RWElementGeometricRelationship::ReadStep, "Reads ElementGeometricRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWElementGeometricRelationship.def("WriteStep", (void (RWStepFEA_RWElementGeometricRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ElementGeometricRelationship> &) const) &RWStepFEA_RWElementGeometricRelationship::WriteStep, "Writes ElementGeometricRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWElementGeometricRelationship.def("Share", (void (RWStepFEA_RWElementGeometricRelationship::*)(const opencascade::handle<StepFEA_ElementGeometricRelationship> &, Interface_EntityIterator &) const) &RWStepFEA_RWElementGeometricRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWELEMENTGROUP
py::class_<RWStepFEA_RWElementGroup> cls_RWStepFEA_RWElementGroup(mod, "RWStepFEA_RWElementGroup", "Read & Write tool for ElementGroup");

// Constructors
cls_RWStepFEA_RWElementGroup.def(py::init<>());

// Methods
// cls_RWStepFEA_RWElementGroup.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWElementGroup::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementGroup.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWElementGroup::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementGroup.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWElementGroup::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementGroup.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWElementGroup::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementGroup.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWElementGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWElementGroup.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWElementGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWElementGroup.def("ReadStep", (void (RWStepFEA_RWElementGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ElementGroup> &) const) &RWStepFEA_RWElementGroup::ReadStep, "Reads ElementGroup", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWElementGroup.def("WriteStep", (void (RWStepFEA_RWElementGroup::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ElementGroup> &) const) &RWStepFEA_RWElementGroup::WriteStep, "Writes ElementGroup", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWElementGroup.def("Share", (void (RWStepFEA_RWElementGroup::*)(const opencascade::handle<StepFEA_ElementGroup> &, Interface_EntityIterator &) const) &RWStepFEA_RWElementGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWELEMENTREPRESENTATION
py::class_<RWStepFEA_RWElementRepresentation> cls_RWStepFEA_RWElementRepresentation(mod, "RWStepFEA_RWElementRepresentation", "Read & Write tool for ElementRepresentation");

// Constructors
cls_RWStepFEA_RWElementRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWElementRepresentation.def("ReadStep", (void (RWStepFEA_RWElementRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ElementRepresentation> &) const) &RWStepFEA_RWElementRepresentation::ReadStep, "Reads ElementRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWElementRepresentation.def("WriteStep", (void (RWStepFEA_RWElementRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ElementRepresentation> &) const) &RWStepFEA_RWElementRepresentation::WriteStep, "Writes ElementRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWElementRepresentation.def("Share", (void (RWStepFEA_RWElementRepresentation::*)(const opencascade::handle<StepFEA_ElementRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWElementRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAAREADENSITY
py::class_<RWStepFEA_RWFeaAreaDensity> cls_RWStepFEA_RWFeaAreaDensity(mod, "RWStepFEA_RWFeaAreaDensity", "Read & Write tool for FeaAreaDensity");

// Constructors
cls_RWStepFEA_RWFeaAreaDensity.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaAreaDensity::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaAreaDensity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaAreaDensity::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaAreaDensity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaAreaDensity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAreaDensity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaAreaDensity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaAreaDensity.def("ReadStep", (void (RWStepFEA_RWFeaAreaDensity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaAreaDensity> &) const) &RWStepFEA_RWFeaAreaDensity::ReadStep, "Reads FeaAreaDensity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaAreaDensity.def("WriteStep", (void (RWStepFEA_RWFeaAreaDensity::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaAreaDensity> &) const) &RWStepFEA_RWFeaAreaDensity::WriteStep, "Writes FeaAreaDensity", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaAreaDensity.def("Share", (void (RWStepFEA_RWFeaAreaDensity::*)(const opencascade::handle<StepFEA_FeaAreaDensity> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaAreaDensity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAAXIS2PLACEMENT3D
py::class_<RWStepFEA_RWFeaAxis2Placement3d> cls_RWStepFEA_RWFeaAxis2Placement3d(mod, "RWStepFEA_RWFeaAxis2Placement3d", "Read & Write tool for FeaAxis2Placement3d");

// Constructors
cls_RWStepFEA_RWFeaAxis2Placement3d.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaAxis2Placement3d::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaAxis2Placement3d::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("ReadStep", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &) const) &RWStepFEA_RWFeaAxis2Placement3d::ReadStep, "Reads FeaAxis2Placement3d", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("WriteStep", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &) const) &RWStepFEA_RWFeaAxis2Placement3d::WriteStep, "Writes FeaAxis2Placement3d", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("Share", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaAxis2Placement3d::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEACURVESECTIONGEOMETRICRELATIONSHIP
py::class_<RWStepFEA_RWFeaCurveSectionGeometricRelationship> cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship(mod, "RWStepFEA_RWFeaCurveSectionGeometricRelationship", "Read & Write tool for FeaCurveSectionGeometricRelationship");

// Constructors
cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def("ReadStep", (void (RWStepFEA_RWFeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaCurveSectionGeometricRelationship> &) const) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::ReadStep, "Reads FeaCurveSectionGeometricRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def("WriteStep", (void (RWStepFEA_RWFeaCurveSectionGeometricRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaCurveSectionGeometricRelationship> &) const) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::WriteStep, "Writes FeaCurveSectionGeometricRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaCurveSectionGeometricRelationship.def("Share", (void (RWStepFEA_RWFeaCurveSectionGeometricRelationship::*)(const opencascade::handle<StepFEA_FeaCurveSectionGeometricRelationship> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaCurveSectionGeometricRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAGROUP
py::class_<RWStepFEA_RWFeaGroup> cls_RWStepFEA_RWFeaGroup(mod, "RWStepFEA_RWFeaGroup", "Read & Write tool for FeaGroup");

// Constructors
cls_RWStepFEA_RWFeaGroup.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaGroup.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaGroup::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaGroup.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaGroup::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaGroup.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaGroup::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaGroup.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaGroup::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaGroup.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaGroup.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaGroup.def("ReadStep", (void (RWStepFEA_RWFeaGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaGroup> &) const) &RWStepFEA_RWFeaGroup::ReadStep, "Reads FeaGroup", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaGroup.def("WriteStep", (void (RWStepFEA_RWFeaGroup::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaGroup> &) const) &RWStepFEA_RWFeaGroup::WriteStep, "Writes FeaGroup", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaGroup.def("Share", (void (RWStepFEA_RWFeaGroup::*)(const opencascade::handle<StepFEA_FeaGroup> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEALINEARELASTICITY
py::class_<RWStepFEA_RWFeaLinearElasticity> cls_RWStepFEA_RWFeaLinearElasticity(mod, "RWStepFEA_RWFeaLinearElasticity", "Read & Write tool for FeaLinearElasticity");

// Constructors
cls_RWStepFEA_RWFeaLinearElasticity.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaLinearElasticity::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaLinearElasticity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaLinearElasticity::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaLinearElasticity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaLinearElasticity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaLinearElasticity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaLinearElasticity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaLinearElasticity.def("ReadStep", (void (RWStepFEA_RWFeaLinearElasticity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaLinearElasticity> &) const) &RWStepFEA_RWFeaLinearElasticity::ReadStep, "Reads FeaLinearElasticity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaLinearElasticity.def("WriteStep", (void (RWStepFEA_RWFeaLinearElasticity::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaLinearElasticity> &) const) &RWStepFEA_RWFeaLinearElasticity::WriteStep, "Writes FeaLinearElasticity", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaLinearElasticity.def("Share", (void (RWStepFEA_RWFeaLinearElasticity::*)(const opencascade::handle<StepFEA_FeaLinearElasticity> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaLinearElasticity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMASSDENSITY
py::class_<RWStepFEA_RWFeaMassDensity> cls_RWStepFEA_RWFeaMassDensity(mod, "RWStepFEA_RWFeaMassDensity", "Read & Write tool for FeaMassDensity");

// Constructors
cls_RWStepFEA_RWFeaMassDensity.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaMassDensity::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaMassDensity::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaMassDensity::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaMassDensity::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaMassDensity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMassDensity.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaMassDensity::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaMassDensity.def("ReadStep", (void (RWStepFEA_RWFeaMassDensity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaMassDensity> &) const) &RWStepFEA_RWFeaMassDensity::ReadStep, "Reads FeaMassDensity", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaMassDensity.def("WriteStep", (void (RWStepFEA_RWFeaMassDensity::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaMassDensity> &) const) &RWStepFEA_RWFeaMassDensity::WriteStep, "Writes FeaMassDensity", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaMassDensity.def("Share", (void (RWStepFEA_RWFeaMassDensity::*)(const opencascade::handle<StepFEA_FeaMassDensity> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaMassDensity::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMATERIALPROPERTYREPRESENTATION
py::class_<RWStepFEA_RWFeaMaterialPropertyRepresentation> cls_RWStepFEA_RWFeaMaterialPropertyRepresentation(mod, "RWStepFEA_RWFeaMaterialPropertyRepresentation", "Read & Write tool for FeaMaterialPropertyRepresentation");

// Constructors
cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def("ReadStep", (void (RWStepFEA_RWFeaMaterialPropertyRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentation> &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentation::ReadStep, "Reads FeaMaterialPropertyRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def("WriteStep", (void (RWStepFEA_RWFeaMaterialPropertyRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentation> &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentation::WriteStep, "Writes FeaMaterialPropertyRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentation.def("Share", (void (RWStepFEA_RWFeaMaterialPropertyRepresentation::*)(const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMATERIALPROPERTYREPRESENTATIONITEM
py::class_<RWStepFEA_RWFeaMaterialPropertyRepresentationItem> cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem(mod, "RWStepFEA_RWFeaMaterialPropertyRepresentationItem", "Read & Write tool for FeaMaterialPropertyRepresentationItem");

// Constructors
cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def("ReadStep", (void (RWStepFEA_RWFeaMaterialPropertyRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentationItem> &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::ReadStep, "Reads FeaMaterialPropertyRepresentationItem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def("WriteStep", (void (RWStepFEA_RWFeaMaterialPropertyRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentationItem> &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::WriteStep, "Writes FeaMaterialPropertyRepresentationItem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaMaterialPropertyRepresentationItem.def("Share", (void (RWStepFEA_RWFeaMaterialPropertyRepresentationItem::*)(const opencascade::handle<StepFEA_FeaMaterialPropertyRepresentationItem> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaMaterialPropertyRepresentationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMODEL
py::class_<RWStepFEA_RWFeaModel> cls_RWStepFEA_RWFeaModel(mod, "RWStepFEA_RWFeaModel", "Read & Write tool for FeaModel");

// Constructors
cls_RWStepFEA_RWFeaModel.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaModel.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaModel::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModel.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaModel::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaModel::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModel.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaModel::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaModel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaModel::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaModel.def("ReadStep", (void (RWStepFEA_RWFeaModel::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaModel> &) const) &RWStepFEA_RWFeaModel::ReadStep, "Reads FeaModel", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaModel.def("WriteStep", (void (RWStepFEA_RWFeaModel::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaModel> &) const) &RWStepFEA_RWFeaModel::WriteStep, "Writes FeaModel", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaModel.def("Share", (void (RWStepFEA_RWFeaModel::*)(const opencascade::handle<StepFEA_FeaModel> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaModel::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMODEL3D
py::class_<RWStepFEA_RWFeaModel3d> cls_RWStepFEA_RWFeaModel3d(mod, "RWStepFEA_RWFeaModel3d", "Read & Write tool for FeaModel3d");

// Constructors
cls_RWStepFEA_RWFeaModel3d.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaModel3d.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaModel3d::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModel3d.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaModel3d::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel3d.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaModel3d::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModel3d.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaModel3d::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel3d.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaModel3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModel3d.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaModel3d::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaModel3d.def("ReadStep", (void (RWStepFEA_RWFeaModel3d::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaModel3d> &) const) &RWStepFEA_RWFeaModel3d::ReadStep, "Reads FeaModel3d", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaModel3d.def("WriteStep", (void (RWStepFEA_RWFeaModel3d::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaModel3d> &) const) &RWStepFEA_RWFeaModel3d::WriteStep, "Writes FeaModel3d", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaModel3d.def("Share", (void (RWStepFEA_RWFeaModel3d::*)(const opencascade::handle<StepFEA_FeaModel3d> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaModel3d::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMODELDEFINITION
py::class_<RWStepFEA_RWFeaModelDefinition> cls_RWStepFEA_RWFeaModelDefinition(mod, "RWStepFEA_RWFeaModelDefinition", "Read & Write tool for FeaModelDefinition");

// Constructors
cls_RWStepFEA_RWFeaModelDefinition.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaModelDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaModelDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaModelDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaModelDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaModelDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaModelDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaModelDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaModelDefinition.def("ReadStep", (void (RWStepFEA_RWFeaModelDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaModelDefinition> &) const) &RWStepFEA_RWFeaModelDefinition::ReadStep, "Reads FeaModelDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaModelDefinition.def("WriteStep", (void (RWStepFEA_RWFeaModelDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaModelDefinition> &) const) &RWStepFEA_RWFeaModelDefinition::WriteStep, "Writes FeaModelDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaModelDefinition.def("Share", (void (RWStepFEA_RWFeaModelDefinition::*)(const opencascade::handle<StepFEA_FeaModelDefinition> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaModelDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAMOISTUREABSORPTION
py::class_<RWStepFEA_RWFeaMoistureAbsorption> cls_RWStepFEA_RWFeaMoistureAbsorption(mod, "RWStepFEA_RWFeaMoistureAbsorption", "Read & Write tool for FeaMoistureAbsorption");

// Constructors
cls_RWStepFEA_RWFeaMoistureAbsorption.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaMoistureAbsorption::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaMoistureAbsorption::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaMoistureAbsorption::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaMoistureAbsorption::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaMoistureAbsorption::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaMoistureAbsorption.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaMoistureAbsorption::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaMoistureAbsorption.def("ReadStep", (void (RWStepFEA_RWFeaMoistureAbsorption::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaMoistureAbsorption> &) const) &RWStepFEA_RWFeaMoistureAbsorption::ReadStep, "Reads FeaMoistureAbsorption", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaMoistureAbsorption.def("WriteStep", (void (RWStepFEA_RWFeaMoistureAbsorption::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaMoistureAbsorption> &) const) &RWStepFEA_RWFeaMoistureAbsorption::WriteStep, "Writes FeaMoistureAbsorption", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaMoistureAbsorption.def("Share", (void (RWStepFEA_RWFeaMoistureAbsorption::*)(const opencascade::handle<StepFEA_FeaMoistureAbsorption> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaMoistureAbsorption::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAPARAMETRICPOINT
py::class_<RWStepFEA_RWFeaParametricPoint> cls_RWStepFEA_RWFeaParametricPoint(mod, "RWStepFEA_RWFeaParametricPoint", "Read & Write tool for FeaParametricPoint");

// Constructors
cls_RWStepFEA_RWFeaParametricPoint.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaParametricPoint::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaParametricPoint::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaParametricPoint::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaParametricPoint::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaParametricPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaParametricPoint.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaParametricPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaParametricPoint.def("ReadStep", (void (RWStepFEA_RWFeaParametricPoint::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaParametricPoint> &) const) &RWStepFEA_RWFeaParametricPoint::ReadStep, "Reads FeaParametricPoint", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaParametricPoint.def("WriteStep", (void (RWStepFEA_RWFeaParametricPoint::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaParametricPoint> &) const) &RWStepFEA_RWFeaParametricPoint::WriteStep, "Writes FeaParametricPoint", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaParametricPoint.def("Share", (void (RWStepFEA_RWFeaParametricPoint::*)(const opencascade::handle<StepFEA_FeaParametricPoint> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaParametricPoint::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEAREPRESENTATIONITEM
py::class_<RWStepFEA_RWFeaRepresentationItem> cls_RWStepFEA_RWFeaRepresentationItem(mod, "RWStepFEA_RWFeaRepresentationItem", "Read & Write tool for FeaRepresentationItem");

// Constructors
cls_RWStepFEA_RWFeaRepresentationItem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaRepresentationItem.def("ReadStep", (void (RWStepFEA_RWFeaRepresentationItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaRepresentationItem> &) const) &RWStepFEA_RWFeaRepresentationItem::ReadStep, "Reads FeaRepresentationItem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaRepresentationItem.def("WriteStep", (void (RWStepFEA_RWFeaRepresentationItem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaRepresentationItem> &) const) &RWStepFEA_RWFeaRepresentationItem::WriteStep, "Writes FeaRepresentationItem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaRepresentationItem.def("Share", (void (RWStepFEA_RWFeaRepresentationItem::*)(const opencascade::handle<StepFEA_FeaRepresentationItem> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaRepresentationItem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASECANTCOEFFICIENTOFLINEARTHERMALEXPANSION
py::class_<RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion> cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion(mod, "RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion", "Read & Write tool for FeaSecantCoefficientOfLinearThermalExpansion");

// Constructors
cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def("ReadStep", (void (RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaSecantCoefficientOfLinearThermalExpansion> &) const) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::ReadStep, "Reads FeaSecantCoefficientOfLinearThermalExpansion", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def("WriteStep", (void (RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaSecantCoefficientOfLinearThermalExpansion> &) const) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::WriteStep, "Writes FeaSecantCoefficientOfLinearThermalExpansion", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion.def("Share", (void (RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<StepFEA_FeaSecantCoefficientOfLinearThermalExpansion> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaSecantCoefficientOfLinearThermalExpansion::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASHELLBENDINGSTIFFNESS
py::class_<RWStepFEA_RWFeaShellBendingStiffness> cls_RWStepFEA_RWFeaShellBendingStiffness(mod, "RWStepFEA_RWFeaShellBendingStiffness", "Read & Write tool for FeaShellBendingStiffness");

// Constructors
cls_RWStepFEA_RWFeaShellBendingStiffness.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellBendingStiffness::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellBendingStiffness::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("ReadStep", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaShellBendingStiffness> &) const) &RWStepFEA_RWFeaShellBendingStiffness::ReadStep, "Reads FeaShellBendingStiffness", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("WriteStep", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaShellBendingStiffness> &) const) &RWStepFEA_RWFeaShellBendingStiffness::WriteStep, "Writes FeaShellBendingStiffness", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("Share", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(const opencascade::handle<StepFEA_FeaShellBendingStiffness> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaShellBendingStiffness::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASHELLMEMBRANEBENDINGCOUPLINGSTIFFNESS
py::class_<RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness> cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness(mod, "RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness", "Read & Write tool for FeaShellMembraneBendingCouplingStiffness");

// Constructors
cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def("ReadStep", (void (RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaShellMembraneBendingCouplingStiffness> &) const) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::ReadStep, "Reads FeaShellMembraneBendingCouplingStiffness", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def("WriteStep", (void (RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaShellMembraneBendingCouplingStiffness> &) const) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::WriteStep, "Writes FeaShellMembraneBendingCouplingStiffness", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness.def("Share", (void (RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::*)(const opencascade::handle<StepFEA_FeaShellMembraneBendingCouplingStiffness> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaShellMembraneBendingCouplingStiffness::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASHELLMEMBRANESTIFFNESS
py::class_<RWStepFEA_RWFeaShellMembraneStiffness> cls_RWStepFEA_RWFeaShellMembraneStiffness(mod, "RWStepFEA_RWFeaShellMembraneStiffness", "Read & Write tool for FeaShellMembraneStiffness");

// Constructors
cls_RWStepFEA_RWFeaShellMembraneStiffness.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellMembraneStiffness::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaShellMembraneStiffness::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellMembraneStiffness::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaShellMembraneStiffness::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaShellMembraneStiffness::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellMembraneStiffness.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaShellMembraneStiffness::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaShellMembraneStiffness.def("ReadStep", (void (RWStepFEA_RWFeaShellMembraneStiffness::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaShellMembraneStiffness> &) const) &RWStepFEA_RWFeaShellMembraneStiffness::ReadStep, "Reads FeaShellMembraneStiffness", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellMembraneStiffness.def("WriteStep", (void (RWStepFEA_RWFeaShellMembraneStiffness::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaShellMembraneStiffness> &) const) &RWStepFEA_RWFeaShellMembraneStiffness::WriteStep, "Writes FeaShellMembraneStiffness", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellMembraneStiffness.def("Share", (void (RWStepFEA_RWFeaShellMembraneStiffness::*)(const opencascade::handle<StepFEA_FeaShellMembraneStiffness> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaShellMembraneStiffness::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASHELLSHEARSTIFFNESS
py::class_<RWStepFEA_RWFeaShellShearStiffness> cls_RWStepFEA_RWFeaShellShearStiffness(mod, "RWStepFEA_RWFeaShellShearStiffness", "Read & Write tool for FeaShellShearStiffness");

// Constructors
cls_RWStepFEA_RWFeaShellShearStiffness.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellShearStiffness::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaShellShearStiffness::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellShearStiffness::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaShellShearStiffness::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaShellShearStiffness::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellShearStiffness.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaShellShearStiffness::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaShellShearStiffness.def("ReadStep", (void (RWStepFEA_RWFeaShellShearStiffness::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaShellShearStiffness> &) const) &RWStepFEA_RWFeaShellShearStiffness::ReadStep, "Reads FeaShellShearStiffness", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellShearStiffness.def("WriteStep", (void (RWStepFEA_RWFeaShellShearStiffness::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaShellShearStiffness> &) const) &RWStepFEA_RWFeaShellShearStiffness::WriteStep, "Writes FeaShellShearStiffness", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellShearStiffness.def("Share", (void (RWStepFEA_RWFeaShellShearStiffness::*)(const opencascade::handle<StepFEA_FeaShellShearStiffness> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaShellShearStiffness::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEASURFACESECTIONGEOMETRICRELATIONSHIP
py::class_<RWStepFEA_RWFeaSurfaceSectionGeometricRelationship> cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship(mod, "RWStepFEA_RWFeaSurfaceSectionGeometricRelationship", "Read & Write tool for FeaSurfaceSectionGeometricRelationship");

// Constructors
cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def("ReadStep", (void (RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaSurfaceSectionGeometricRelationship> &) const) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::ReadStep, "Reads FeaSurfaceSectionGeometricRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def("WriteStep", (void (RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaSurfaceSectionGeometricRelationship> &) const) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::WriteStep, "Writes FeaSurfaceSectionGeometricRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaSurfaceSectionGeometricRelationship.def("Share", (void (RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::*)(const opencascade::handle<StepFEA_FeaSurfaceSectionGeometricRelationship> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaSurfaceSectionGeometricRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFEATANGENTIALCOEFFICIENTOFLINEARTHERMALEXPANSION
py::class_<RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion> cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion(mod, "RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion", "Read & Write tool for FeaTangentialCoefficientOfLinearThermalExpansion");

// Constructors
cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def("ReadStep", (void (RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion> &) const) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::ReadStep, "Reads FeaTangentialCoefficientOfLinearThermalExpansion", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def("WriteStep", (void (RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion> &) const) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::WriteStep, "Writes FeaTangentialCoefficientOfLinearThermalExpansion", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion.def("Share", (void (RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::*)(const opencascade::handle<StepFEA_FeaTangentialCoefficientOfLinearThermalExpansion> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaTangentialCoefficientOfLinearThermalExpansion::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFREEDOMANDCOEFFICIENT
py::class_<RWStepFEA_RWFreedomAndCoefficient> cls_RWStepFEA_RWFreedomAndCoefficient(mod, "RWStepFEA_RWFreedomAndCoefficient", "Read & Write tool for FreedomAndCoefficient");

// Constructors
cls_RWStepFEA_RWFreedomAndCoefficient.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFreedomAndCoefficient::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFreedomAndCoefficient::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFreedomAndCoefficient::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFreedomAndCoefficient::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFreedomAndCoefficient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomAndCoefficient.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFreedomAndCoefficient::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFreedomAndCoefficient.def("ReadStep", (void (RWStepFEA_RWFreedomAndCoefficient::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FreedomAndCoefficient> &) const) &RWStepFEA_RWFreedomAndCoefficient::ReadStep, "Reads FreedomAndCoefficient", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFreedomAndCoefficient.def("WriteStep", (void (RWStepFEA_RWFreedomAndCoefficient::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FreedomAndCoefficient> &) const) &RWStepFEA_RWFreedomAndCoefficient::WriteStep, "Writes FreedomAndCoefficient", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFreedomAndCoefficient.def("Share", (void (RWStepFEA_RWFreedomAndCoefficient::*)(const opencascade::handle<StepFEA_FreedomAndCoefficient> &, Interface_EntityIterator &) const) &RWStepFEA_RWFreedomAndCoefficient::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWFREEDOMSLIST
py::class_<RWStepFEA_RWFreedomsList> cls_RWStepFEA_RWFreedomsList(mod, "RWStepFEA_RWFreedomsList", "Read & Write tool for FreedomsList");

// Constructors
cls_RWStepFEA_RWFreedomsList.def(py::init<>());

// Methods
// cls_RWStepFEA_RWFreedomsList.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFreedomsList::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFreedomsList.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFreedomsList::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomsList.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFreedomsList::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFreedomsList.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFreedomsList::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomsList.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFreedomsList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFreedomsList.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFreedomsList::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFreedomsList.def("ReadStep", (void (RWStepFEA_RWFreedomsList::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FreedomsList> &) const) &RWStepFEA_RWFreedomsList::ReadStep, "Reads FreedomsList", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFreedomsList.def("WriteStep", (void (RWStepFEA_RWFreedomsList::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FreedomsList> &) const) &RWStepFEA_RWFreedomsList::WriteStep, "Writes FreedomsList", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFreedomsList.def("Share", (void (RWStepFEA_RWFreedomsList::*)(const opencascade::handle<StepFEA_FreedomsList> &, Interface_EntityIterator &) const) &RWStepFEA_RWFreedomsList::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWGEOMETRICNODE
py::class_<RWStepFEA_RWGeometricNode> cls_RWStepFEA_RWGeometricNode(mod, "RWStepFEA_RWGeometricNode", "Read & Write tool for GeometricNode");

// Constructors
cls_RWStepFEA_RWGeometricNode.def(py::init<>());

// Methods
// cls_RWStepFEA_RWGeometricNode.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWGeometricNode::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWGeometricNode.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWGeometricNode::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWGeometricNode.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWGeometricNode::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWGeometricNode.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWGeometricNode::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWGeometricNode.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWGeometricNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWGeometricNode.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWGeometricNode::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWGeometricNode.def("ReadStep", (void (RWStepFEA_RWGeometricNode::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_GeometricNode> &) const) &RWStepFEA_RWGeometricNode::ReadStep, "Reads GeometricNode", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWGeometricNode.def("WriteStep", (void (RWStepFEA_RWGeometricNode::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_GeometricNode> &) const) &RWStepFEA_RWGeometricNode::WriteStep, "Writes GeometricNode", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWGeometricNode.def("Share", (void (RWStepFEA_RWGeometricNode::*)(const opencascade::handle<StepFEA_GeometricNode> &, Interface_EntityIterator &) const) &RWStepFEA_RWGeometricNode::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODE
py::class_<RWStepFEA_RWNode> cls_RWStepFEA_RWNode(mod, "RWStepFEA_RWNode", "Read & Write tool for Node");

// Constructors
cls_RWStepFEA_RWNode.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNode.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNode::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNode.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNode::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNode.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNode::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNode.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNode::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNode.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNode.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNode::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNode.def("ReadStep", (void (RWStepFEA_RWNode::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Node> &) const) &RWStepFEA_RWNode::ReadStep, "Reads Node", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNode.def("WriteStep", (void (RWStepFEA_RWNode::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Node> &) const) &RWStepFEA_RWNode::WriteStep, "Writes Node", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNode.def("Share", (void (RWStepFEA_RWNode::*)(const opencascade::handle<StepFEA_Node> &, Interface_EntityIterator &) const) &RWStepFEA_RWNode::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODEDEFINITION
py::class_<RWStepFEA_RWNodeDefinition> cls_RWStepFEA_RWNodeDefinition(mod, "RWStepFEA_RWNodeDefinition", "Read & Write tool for NodeDefinition");

// Constructors
cls_RWStepFEA_RWNodeDefinition.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeDefinition.def("ReadStep", (void (RWStepFEA_RWNodeDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeDefinition> &) const) &RWStepFEA_RWNodeDefinition::ReadStep, "Reads NodeDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeDefinition.def("WriteStep", (void (RWStepFEA_RWNodeDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeDefinition> &) const) &RWStepFEA_RWNodeDefinition::WriteStep, "Writes NodeDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeDefinition.def("Share", (void (RWStepFEA_RWNodeDefinition::*)(const opencascade::handle<StepFEA_NodeDefinition> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODEGROUP
py::class_<RWStepFEA_RWNodeGroup> cls_RWStepFEA_RWNodeGroup(mod, "RWStepFEA_RWNodeGroup", "Read & Write tool for NodeGroup");

// Constructors
cls_RWStepFEA_RWNodeGroup.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeGroup.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeGroup::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeGroup.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeGroup::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeGroup.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeGroup::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeGroup.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeGroup::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeGroup.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeGroup.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeGroup.def("ReadStep", (void (RWStepFEA_RWNodeGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeGroup> &) const) &RWStepFEA_RWNodeGroup::ReadStep, "Reads NodeGroup", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeGroup.def("WriteStep", (void (RWStepFEA_RWNodeGroup::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeGroup> &) const) &RWStepFEA_RWNodeGroup::WriteStep, "Writes NodeGroup", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeGroup.def("Share", (void (RWStepFEA_RWNodeGroup::*)(const opencascade::handle<StepFEA_NodeGroup> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODEREPRESENTATION
py::class_<RWStepFEA_RWNodeRepresentation> cls_RWStepFEA_RWNodeRepresentation(mod, "RWStepFEA_RWNodeRepresentation", "Read & Write tool for NodeRepresentation");

// Constructors
cls_RWStepFEA_RWNodeRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeRepresentation.def("ReadStep", (void (RWStepFEA_RWNodeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeRepresentation> &) const) &RWStepFEA_RWNodeRepresentation::ReadStep, "Reads NodeRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeRepresentation.def("WriteStep", (void (RWStepFEA_RWNodeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeRepresentation> &) const) &RWStepFEA_RWNodeRepresentation::WriteStep, "Writes NodeRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeRepresentation.def("Share", (void (RWStepFEA_RWNodeRepresentation::*)(const opencascade::handle<StepFEA_NodeRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODESET
py::class_<RWStepFEA_RWNodeSet> cls_RWStepFEA_RWNodeSet(mod, "RWStepFEA_RWNodeSet", "Read & Write tool for NodeSet");

// Constructors
cls_RWStepFEA_RWNodeSet.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeSet.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeSet::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeSet.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeSet::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeSet.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeSet::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeSet.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeSet::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeSet.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeSet.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeSet.def("ReadStep", (void (RWStepFEA_RWNodeSet::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeSet> &) const) &RWStepFEA_RWNodeSet::ReadStep, "Reads NodeSet", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeSet.def("WriteStep", (void (RWStepFEA_RWNodeSet::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeSet> &) const) &RWStepFEA_RWNodeSet::WriteStep, "Writes NodeSet", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeSet.def("Share", (void (RWStepFEA_RWNodeSet::*)(const opencascade::handle<StepFEA_NodeSet> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeSet::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODEWITHSOLUTIONCOORDINATESYSTEM
py::class_<RWStepFEA_RWNodeWithSolutionCoordinateSystem> cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem(mod, "RWStepFEA_RWNodeWithSolutionCoordinateSystem", "Read & Write tool for NodeWithSolutionCoordinateSystem");

// Constructors
cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWNodeWithSolutionCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeWithSolutionCoordinateSystem> &) const) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::ReadStep, "Reads NodeWithSolutionCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWNodeWithSolutionCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeWithSolutionCoordinateSystem> &) const) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::WriteStep, "Writes NodeWithSolutionCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeWithSolutionCoordinateSystem.def("Share", (void (RWStepFEA_RWNodeWithSolutionCoordinateSystem::*)(const opencascade::handle<StepFEA_NodeWithSolutionCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeWithSolutionCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWNODEWITHVECTOR
py::class_<RWStepFEA_RWNodeWithVector> cls_RWStepFEA_RWNodeWithVector(mod, "RWStepFEA_RWNodeWithVector", "Read & Write tool for NodeWithVector");

// Constructors
cls_RWStepFEA_RWNodeWithVector.def(py::init<>());

// Methods
// cls_RWStepFEA_RWNodeWithVector.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWNodeWithVector::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeWithVector.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWNodeWithVector::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithVector.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWNodeWithVector::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWNodeWithVector.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWNodeWithVector::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithVector.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWNodeWithVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWNodeWithVector.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWNodeWithVector::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWNodeWithVector.def("ReadStep", (void (RWStepFEA_RWNodeWithVector::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_NodeWithVector> &) const) &RWStepFEA_RWNodeWithVector::ReadStep, "Reads NodeWithVector", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWNodeWithVector.def("WriteStep", (void (RWStepFEA_RWNodeWithVector::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_NodeWithVector> &) const) &RWStepFEA_RWNodeWithVector::WriteStep, "Writes NodeWithVector", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWNodeWithVector.def("Share", (void (RWStepFEA_RWNodeWithVector::*)(const opencascade::handle<StepFEA_NodeWithVector> &, Interface_EntityIterator &) const) &RWStepFEA_RWNodeWithVector::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWPARAMETRICCURVE3DELEMENTCOORDINATEDIRECTION
py::class_<RWStepFEA_RWParametricCurve3dElementCoordinateDirection> cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection(mod, "RWStepFEA_RWParametricCurve3dElementCoordinateDirection", "Read & Write tool for ParametricCurve3dElementCoordinateDirection");

// Constructors
cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def(py::init<>());

// Methods
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def("ReadStep", (void (RWStepFEA_RWParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::ReadStep, "Reads ParametricCurve3dElementCoordinateDirection", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def("WriteStep", (void (RWStepFEA_RWParametricCurve3dElementCoordinateDirection::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::WriteStep, "Writes ParametricCurve3dElementCoordinateDirection", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateDirection.def("Share", (void (RWStepFEA_RWParametricCurve3dElementCoordinateDirection::*)(const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateDirection> &, Interface_EntityIterator &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateDirection::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWPARAMETRICCURVE3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWParametricCurve3dElementCoordinateSystem> cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem(mod, "RWStepFEA_RWParametricCurve3dElementCoordinateSystem", "Read & Write tool for ParametricCurve3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWParametricCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem> &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::ReadStep, "Reads ParametricCurve3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWParametricCurve3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem> &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::WriteStep, "Writes ParametricCurve3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWParametricCurve3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWParametricCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWParametricCurve3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWPARAMETRICSURFACE3DELEMENTCOORDINATESYSTEM
py::class_<RWStepFEA_RWParametricSurface3dElementCoordinateSystem> cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem(mod, "RWStepFEA_RWParametricSurface3dElementCoordinateSystem", "Read & Write tool for ParametricSurface3dElementCoordinateSystem");

// Constructors
cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def(py::init<>());

// Methods
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def("ReadStep", (void (RWStepFEA_RWParametricSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_ParametricSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::ReadStep, "Reads ParametricSurface3dElementCoordinateSystem", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def("WriteStep", (void (RWStepFEA_RWParametricSurface3dElementCoordinateSystem::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_ParametricSurface3dElementCoordinateSystem> &) const) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::WriteStep, "Writes ParametricSurface3dElementCoordinateSystem", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWParametricSurface3dElementCoordinateSystem.def("Share", (void (RWStepFEA_RWParametricSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_ParametricSurface3dElementCoordinateSystem> &, Interface_EntityIterator &) const) &RWStepFEA_RWParametricSurface3dElementCoordinateSystem::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWSURFACE3DELEMENTREPRESENTATION
py::class_<RWStepFEA_RWSurface3dElementRepresentation> cls_RWStepFEA_RWSurface3dElementRepresentation(mod, "RWStepFEA_RWSurface3dElementRepresentation", "Read & Write tool for Surface3dElementRepresentation");

// Constructors
cls_RWStepFEA_RWSurface3dElementRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWSurface3dElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWSurface3dElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWSurface3dElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWSurface3dElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWSurface3dElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWSurface3dElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWSurface3dElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWSurface3dElementRepresentation.def("ReadStep", (void (RWStepFEA_RWSurface3dElementRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Surface3dElementRepresentation> &) const) &RWStepFEA_RWSurface3dElementRepresentation::ReadStep, "Reads Surface3dElementRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWSurface3dElementRepresentation.def("WriteStep", (void (RWStepFEA_RWSurface3dElementRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Surface3dElementRepresentation> &) const) &RWStepFEA_RWSurface3dElementRepresentation::WriteStep, "Writes Surface3dElementRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWSurface3dElementRepresentation.def("Share", (void (RWStepFEA_RWSurface3dElementRepresentation::*)(const opencascade::handle<StepFEA_Surface3dElementRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWSurface3dElementRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPFEA_RWVOLUME3DELEMENTREPRESENTATION
py::class_<RWStepFEA_RWVolume3dElementRepresentation> cls_RWStepFEA_RWVolume3dElementRepresentation(mod, "RWStepFEA_RWVolume3dElementRepresentation", "Read & Write tool for Volume3dElementRepresentation");

// Constructors
cls_RWStepFEA_RWVolume3dElementRepresentation.def(py::init<>());

// Methods
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWVolume3dElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWVolume3dElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("ReadStep", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Volume3dElementRepresentation> &) const) &RWStepFEA_RWVolume3dElementRepresentation::ReadStep, "Reads Volume3dElementRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("WriteStep", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Volume3dElementRepresentation> &) const) &RWStepFEA_RWVolume3dElementRepresentation::WriteStep, "Writes Volume3dElementRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("Share", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(const opencascade::handle<StepFEA_Volume3dElementRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWVolume3dElementRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
