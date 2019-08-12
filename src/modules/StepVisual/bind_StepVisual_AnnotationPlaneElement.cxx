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
#include <StepVisual_DraughtingCallout.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepVisual_AnnotationPlaneElement.hxx>

void bind_StepVisual_AnnotationPlaneElement(py::module &mod){

py::class_<StepVisual_AnnotationPlaneElement, std::unique_ptr<StepVisual_AnnotationPlaneElement, Deleter<StepVisual_AnnotationPlaneElement>>, StepData_SelectType> cls_StepVisual_AnnotationPlaneElement(mod, "StepVisual_AnnotationPlaneElement", "None");

// Constructors
cls_StepVisual_AnnotationPlaneElement.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_AnnotationPlaneElement.def_static("operator new_", (void * (*)(size_t)) &StepVisual_AnnotationPlaneElement::operator new, "None", py::arg("theSize"));
// cls_StepVisual_AnnotationPlaneElement.def_static("operator delete_", (void (*)(void *)) &StepVisual_AnnotationPlaneElement::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_AnnotationPlaneElement.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_AnnotationPlaneElement::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_AnnotationPlaneElement.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_AnnotationPlaneElement::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_AnnotationPlaneElement.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_AnnotationPlaneElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_AnnotationPlaneElement.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_AnnotationPlaneElement::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_AnnotationPlaneElement.def("CaseNum", (Standard_Integer (StepVisual_AnnotationPlaneElement::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_AnnotationPlaneElement::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> DraughtingCallout 2 -> StyledItem 0 else", py::arg("ent"));
cls_StepVisual_AnnotationPlaneElement.def("DraughtingCallout", (opencascade::handle<StepVisual_DraughtingCallout> (StepVisual_AnnotationPlaneElement::*)() const) &StepVisual_AnnotationPlaneElement::DraughtingCallout, "returns Value as a DraughtingCallout (Null if another type)");
cls_StepVisual_AnnotationPlaneElement.def("StyledItem", (opencascade::handle<StepVisual_StyledItem> (StepVisual_AnnotationPlaneElement::*)() const) &StepVisual_AnnotationPlaneElement::StyledItem, "returns Value as a StyledItem (Null if another type)");

// Enums

}