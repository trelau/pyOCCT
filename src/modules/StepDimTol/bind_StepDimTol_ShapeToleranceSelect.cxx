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
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <StepDimTol_ShapeToleranceSelect.hxx>

void bind_StepDimTol_ShapeToleranceSelect(py::module &mod){

py::class_<StepDimTol_ShapeToleranceSelect, std::unique_ptr<StepDimTol_ShapeToleranceSelect>, StepData_SelectType> cls_StepDimTol_ShapeToleranceSelect(mod, "StepDimTol_ShapeToleranceSelect", "Representation of STEP SELECT type ShapeToleranceSelect");

// Constructors
cls_StepDimTol_ShapeToleranceSelect.def(py::init<>());

// Fields

// Methods
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_ShapeToleranceSelect::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete_", (void (*)(void *)) &StepDimTol_ShapeToleranceSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_ShapeToleranceSelect::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_ShapeToleranceSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_ShapeToleranceSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_ShapeToleranceSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_ShapeToleranceSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_ShapeToleranceSelect.def("CaseNum", (Standard_Integer (StepDimTol_ShapeToleranceSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_ShapeToleranceSelect::CaseNum, "Recognizes a kind of ShapeToleranceSelect select type 1 -> GeometricTolerance from StepDimTol 2 -> PlusMinusTolerance from StepShape 0 else", py::arg("ent"));
cls_StepDimTol_ShapeToleranceSelect.def("GeometricTolerance", (opencascade::handle<StepDimTol_GeometricTolerance> (StepDimTol_ShapeToleranceSelect::*)() const) &StepDimTol_ShapeToleranceSelect::GeometricTolerance, "Returns Value as GeometricTolerance (or Null if another type)");
cls_StepDimTol_ShapeToleranceSelect.def("PlusMinusTolerance", (opencascade::handle<StepShape_PlusMinusTolerance> (StepDimTol_ShapeToleranceSelect::*)() const) &StepDimTol_ShapeToleranceSelect::PlusMinusTolerance, "Returns Value as PlusMinusTolerance (or Null if another type)");

// Enums

}