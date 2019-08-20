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
#include <StepShape_DimensionalLocation.hxx>
#include <StepShape_DimensionalSize.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>

void bind_StepDimTol_GeometricToleranceTarget(py::module &mod){

py::class_<StepDimTol_GeometricToleranceTarget, std::unique_ptr<StepDimTol_GeometricToleranceTarget>, StepData_SelectType> cls_StepDimTol_GeometricToleranceTarget(mod, "StepDimTol_GeometricToleranceTarget", "None");

// Constructors
cls_StepDimTol_GeometricToleranceTarget.def(py::init<>());

// Fields

// Methods
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_GeometricToleranceTarget::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete_", (void (*)(void *)) &StepDimTol_GeometricToleranceTarget::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_GeometricToleranceTarget::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_GeometricToleranceTarget::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_GeometricToleranceTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_GeometricToleranceTarget.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_GeometricToleranceTarget::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_GeometricToleranceTarget.def("CaseNum", (Standard_Integer (StepDimTol_GeometricToleranceTarget::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_GeometricToleranceTarget::CaseNum, "Recognizes a GeometricToleranceTarget Kind Entity that is : 1 -> DimensionalLocation 2 -> DimensionalSize 3 -> ProductDefinitionShape 4 -> ShapeAspect 0 else", py::arg("ent"));
cls_StepDimTol_GeometricToleranceTarget.def("DimensionalLocation", (opencascade::handle<StepShape_DimensionalLocation> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::DimensionalLocation, "returns Value as a DimensionalLocation (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("DimensionalSize", (opencascade::handle<StepShape_DimensionalSize> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::DimensionalSize, "returns Value as a DimensionalSize (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
cls_StepDimTol_GeometricToleranceTarget.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_GeometricToleranceTarget::*)() const) &StepDimTol_GeometricToleranceTarget::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");

// Enums

}