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
#include <StepGeom_Point.hxx>
#include <StepGeom_Curve.hxx>
#include <StepGeom_Surface.hxx>
#include <StepShape_GeometricSetSelect.hxx>

void bind_StepShape_GeometricSetSelect(py::module &mod){

py::class_<StepShape_GeometricSetSelect, std::unique_ptr<StepShape_GeometricSetSelect>, StepData_SelectType> cls_StepShape_GeometricSetSelect(mod, "StepShape_GeometricSetSelect", "None");

// Constructors
cls_StepShape_GeometricSetSelect.def(py::init<>());

// Fields

// Methods
// cls_StepShape_GeometricSetSelect.def_static("operator new_", (void * (*)(size_t)) &StepShape_GeometricSetSelect::operator new, "None", py::arg("theSize"));
// cls_StepShape_GeometricSetSelect.def_static("operator delete_", (void (*)(void *)) &StepShape_GeometricSetSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_GeometricSetSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_GeometricSetSelect::operator new[], "None", py::arg("theSize"));
// cls_StepShape_GeometricSetSelect.def_static("operator delete[]_", (void (*)(void *)) &StepShape_GeometricSetSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_GeometricSetSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_GeometricSetSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_GeometricSetSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_GeometricSetSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_GeometricSetSelect.def("CaseNum", (Standard_Integer (StepShape_GeometricSetSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_GeometricSetSelect::CaseNum, "Recognizes a GeometricSetSelect Kind Entity that is : 1 -> Point 2 -> Curve 3 -> Surface 0 else", py::arg("ent"));
cls_StepShape_GeometricSetSelect.def("Point", (opencascade::handle<StepGeom_Point> (StepShape_GeometricSetSelect::*)() const) &StepShape_GeometricSetSelect::Point, "returns Value as a Point (Null if another type)");
cls_StepShape_GeometricSetSelect.def("Curve", (opencascade::handle<StepGeom_Curve> (StepShape_GeometricSetSelect::*)() const) &StepShape_GeometricSetSelect::Curve, "returns Value as a Curve (Null if another type)");
cls_StepShape_GeometricSetSelect.def("Surface", (opencascade::handle<StepGeom_Surface> (StepShape_GeometricSetSelect::*)() const) &StepShape_GeometricSetSelect::Surface, "returns Value as a Surface (Null if another type)");

// Enums

}