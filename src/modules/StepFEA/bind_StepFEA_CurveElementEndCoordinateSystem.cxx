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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <StepFEA_AlignedCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_ParametricCurve3dElementCoordinateSystem.hxx>
#include <StepFEA_CurveElementEndCoordinateSystem.hxx>

void bind_StepFEA_CurveElementEndCoordinateSystem(py::module &mod){

py::class_<StepFEA_CurveElementEndCoordinateSystem, StepData_SelectType> cls_StepFEA_CurveElementEndCoordinateSystem(mod, "StepFEA_CurveElementEndCoordinateSystem", "Representation of STEP SELECT type CurveElementEndCoordinateSystem");

// Constructors
cls_StepFEA_CurveElementEndCoordinateSystem.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator new_", (void * (*)(size_t)) &StepFEA_CurveElementEndCoordinateSystem::operator new, "None", py::arg("theSize"));
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator delete_", (void (*)(void *)) &StepFEA_CurveElementEndCoordinateSystem::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_CurveElementEndCoordinateSystem::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_CurveElementEndCoordinateSystem::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_CurveElementEndCoordinateSystem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_CurveElementEndCoordinateSystem.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_CurveElementEndCoordinateSystem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_CurveElementEndCoordinateSystem.def("CaseNum", (Standard_Integer (StepFEA_CurveElementEndCoordinateSystem::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_CurveElementEndCoordinateSystem::CaseNum, "Recognizes a kind of CurveElementEndCoordinateSystem select type 1 -> FeaAxis2Placement3d from StepFEA 2 -> AlignedCurve3dElementCoordinateSystem from StepFEA 3 -> ParametricCurve3dElementCoordinateSystem from StepFEA 0 else", py::arg("ent"));
cls_StepFEA_CurveElementEndCoordinateSystem.def("FeaAxis2Placement3d", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_CurveElementEndCoordinateSystem::*)() const) &StepFEA_CurveElementEndCoordinateSystem::FeaAxis2Placement3d, "Returns Value as FeaAxis2Placement3d (or Null if another type)");
cls_StepFEA_CurveElementEndCoordinateSystem.def("AlignedCurve3dElementCoordinateSystem", (opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem> (StepFEA_CurveElementEndCoordinateSystem::*)() const) &StepFEA_CurveElementEndCoordinateSystem::AlignedCurve3dElementCoordinateSystem, "Returns Value as AlignedCurve3dElementCoordinateSystem (or Null if another type)");
cls_StepFEA_CurveElementEndCoordinateSystem.def("ParametricCurve3dElementCoordinateSystem", (opencascade::handle<StepFEA_ParametricCurve3dElementCoordinateSystem> (StepFEA_CurveElementEndCoordinateSystem::*)() const) &StepFEA_CurveElementEndCoordinateSystem::ParametricCurve3dElementCoordinateSystem, "Returns Value as ParametricCurve3dElementCoordinateSystem (or Null if another type)");

// Enums

}