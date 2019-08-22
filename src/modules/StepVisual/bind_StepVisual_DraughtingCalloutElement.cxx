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
#include <StepVisual_AnnotationCurveOccurrence.hxx>
#include <StepVisual_AnnotationTextOccurrence.hxx>
#include <StepVisual_TessellatedAnnotationOccurrence.hxx>
#include <StepVisual_AnnotationFillAreaOccurrence.hxx>
#include <StepVisual_DraughtingCalloutElement.hxx>

void bind_StepVisual_DraughtingCalloutElement(py::module &mod){

py::class_<StepVisual_DraughtingCalloutElement, StepData_SelectType> cls_StepVisual_DraughtingCalloutElement(mod, "StepVisual_DraughtingCalloutElement", "None");

// Constructors
cls_StepVisual_DraughtingCalloutElement.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_DraughtingCalloutElement.def_static("operator new_", (void * (*)(size_t)) &StepVisual_DraughtingCalloutElement::operator new, "None", py::arg("theSize"));
// cls_StepVisual_DraughtingCalloutElement.def_static("operator delete_", (void (*)(void *)) &StepVisual_DraughtingCalloutElement::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_DraughtingCalloutElement.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_DraughtingCalloutElement::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_DraughtingCalloutElement.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_DraughtingCalloutElement::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_DraughtingCalloutElement.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_DraughtingCalloutElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_DraughtingCalloutElement.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_DraughtingCalloutElement::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_DraughtingCalloutElement.def("CaseNum", (Standard_Integer (StepVisual_DraughtingCalloutElement::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_DraughtingCalloutElement::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> AnnotationCurveOccurrence 2 -> AnnotationTextOccurrence 3 -> TessellatedAnnotationOccurrence 4 -> AnnotationFillAreaOccurrence 0 else", py::arg("ent"));
cls_StepVisual_DraughtingCalloutElement.def("AnnotationCurveOccurrence", (opencascade::handle<StepVisual_AnnotationCurveOccurrence> (StepVisual_DraughtingCalloutElement::*)() const) &StepVisual_DraughtingCalloutElement::AnnotationCurveOccurrence, "returns Value as a AnnotationCurveOccurrence (Null if another type)");
cls_StepVisual_DraughtingCalloutElement.def("AnnotationTextOccurrence", (opencascade::handle<StepVisual_AnnotationTextOccurrence> (StepVisual_DraughtingCalloutElement::*)() const) &StepVisual_DraughtingCalloutElement::AnnotationTextOccurrence, "returns Value as a AnnotationTextOccurrence");
cls_StepVisual_DraughtingCalloutElement.def("TessellatedAnnotationOccurrence", (opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> (StepVisual_DraughtingCalloutElement::*)() const) &StepVisual_DraughtingCalloutElement::TessellatedAnnotationOccurrence, "returns Value as a TessellatedAnnotationOccurrence");
cls_StepVisual_DraughtingCalloutElement.def("AnnotationFillAreaOccurrence", (opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> (StepVisual_DraughtingCalloutElement::*)() const) &StepVisual_DraughtingCalloutElement::AnnotationFillAreaOccurrence, "returns Value as a AnnotationFillAreaOccurrence");

// Enums

}