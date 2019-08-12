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
#include <StepVisual_CurveStyleFont.hxx>
#include <StepVisual_PreDefinedCurveFont.hxx>
#include <StepVisual_ExternallyDefinedCurveFont.hxx>
#include <StepVisual_CurveStyleFontSelect.hxx>

void bind_StepVisual_CurveStyleFontSelect(py::module &mod){

py::class_<StepVisual_CurveStyleFontSelect, std::unique_ptr<StepVisual_CurveStyleFontSelect, Deleter<StepVisual_CurveStyleFontSelect>>, StepData_SelectType> cls_StepVisual_CurveStyleFontSelect(mod, "StepVisual_CurveStyleFontSelect", "None");

// Constructors
cls_StepVisual_CurveStyleFontSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_CurveStyleFontSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_CurveStyleFontSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_CurveStyleFontSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_CurveStyleFontSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_CurveStyleFontSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_CurveStyleFontSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_CurveStyleFontSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_CurveStyleFontSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_CurveStyleFontSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_CurveStyleFontSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_CurveStyleFontSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_CurveStyleFontSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_CurveStyleFontSelect.def("CaseNum", (Standard_Integer (StepVisual_CurveStyleFontSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_CurveStyleFontSelect::CaseNum, "Recognizes a CurveStyleFontSelect Kind Entity that is : 1 -> CurveStyleFont 2 -> PreDefinedCurveFont 3 -> ExternallyDefinedCurveFont 0 else", py::arg("ent"));
cls_StepVisual_CurveStyleFontSelect.def("CurveStyleFont", (opencascade::handle<StepVisual_CurveStyleFont> (StepVisual_CurveStyleFontSelect::*)() const) &StepVisual_CurveStyleFontSelect::CurveStyleFont, "returns Value as a CurveStyleFont (Null if another type)");
cls_StepVisual_CurveStyleFontSelect.def("PreDefinedCurveFont", (opencascade::handle<StepVisual_PreDefinedCurveFont> (StepVisual_CurveStyleFontSelect::*)() const) &StepVisual_CurveStyleFontSelect::PreDefinedCurveFont, "returns Value as a PreDefinedCurveFont (Null if another type)");
cls_StepVisual_CurveStyleFontSelect.def("ExternallyDefinedCurveFont", (opencascade::handle<StepVisual_ExternallyDefinedCurveFont> (StepVisual_CurveStyleFontSelect::*)() const) &StepVisual_CurveStyleFontSelect::ExternallyDefinedCurveFont, "returns Value as a ExternallyDefinedCurveFont (Null if another type)");

// Enums

}