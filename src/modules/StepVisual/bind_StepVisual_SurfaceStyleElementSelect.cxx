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
#include <StepVisual_SurfaceStyleFillArea.hxx>
#include <StepVisual_SurfaceStyleBoundary.hxx>
#include <StepVisual_SurfaceStyleParameterLine.hxx>
#include <StepVisual_SurfaceStyleElementSelect.hxx>

void bind_StepVisual_SurfaceStyleElementSelect(py::module &mod){

py::class_<StepVisual_SurfaceStyleElementSelect, std::unique_ptr<StepVisual_SurfaceStyleElementSelect, Deleter<StepVisual_SurfaceStyleElementSelect>>, StepData_SelectType> cls_StepVisual_SurfaceStyleElementSelect(mod, "StepVisual_SurfaceStyleElementSelect", "None");

// Constructors
cls_StepVisual_SurfaceStyleElementSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_SurfaceStyleElementSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_SurfaceStyleElementSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_SurfaceStyleElementSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_SurfaceStyleElementSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_SurfaceStyleElementSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_SurfaceStyleElementSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_SurfaceStyleElementSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_SurfaceStyleElementSelect.def("CaseNum", (Standard_Integer (StepVisual_SurfaceStyleElementSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_SurfaceStyleElementSelect::CaseNum, "Recognizes a SurfaceStyleElementSelect Kind Entity that is : 1 -> SurfaceStyleFillArea 2 -> SurfaceStyleBoundary 3 -> SurfaceStyleParameterLine 4 -> SurfaceStyleSilhouette 5 -> SurfaceStyleSegmentationCurve 6 -> SurfaceStyleControlGrid 0 else", py::arg("ent"));
cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleFillArea", (opencascade::handle<StepVisual_SurfaceStyleFillArea> (StepVisual_SurfaceStyleElementSelect::*)() const) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleFillArea, "returns Value as a SurfaceStyleFillArea (Null if another type)");
cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleBoundary", (opencascade::handle<StepVisual_SurfaceStyleBoundary> (StepVisual_SurfaceStyleElementSelect::*)() const) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleBoundary, "returns Value as a SurfaceStyleBoundary (Null if another type)");
cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleParameterLine", (opencascade::handle<StepVisual_SurfaceStyleParameterLine> (StepVisual_SurfaceStyleElementSelect::*)() const) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleParameterLine, "returns Value as a SurfaceStyleParameterLine (Null if another type)");

// Enums

}