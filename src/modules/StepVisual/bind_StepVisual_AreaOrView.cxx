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
#include <StepVisual_PresentationArea.hxx>
#include <StepVisual_PresentationView.hxx>
#include <StepVisual_AreaOrView.hxx>

void bind_StepVisual_AreaOrView(py::module &mod){

py::class_<StepVisual_AreaOrView, std::unique_ptr<StepVisual_AreaOrView>, StepData_SelectType> cls_StepVisual_AreaOrView(mod, "StepVisual_AreaOrView", "None");

// Constructors
cls_StepVisual_AreaOrView.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_AreaOrView.def_static("operator new_", (void * (*)(size_t)) &StepVisual_AreaOrView::operator new, "None", py::arg("theSize"));
// cls_StepVisual_AreaOrView.def_static("operator delete_", (void (*)(void *)) &StepVisual_AreaOrView::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_AreaOrView.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_AreaOrView::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_AreaOrView.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_AreaOrView::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_AreaOrView.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_AreaOrView::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_AreaOrView.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_AreaOrView::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_AreaOrView.def("CaseNum", (Standard_Integer (StepVisual_AreaOrView::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_AreaOrView::CaseNum, "Recognizes a AreaOrView Kind Entity that is : 1 -> PresentationArea 2 -> PresentationView 0 else", py::arg("ent"));
cls_StepVisual_AreaOrView.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_AreaOrView::*)() const) &StepVisual_AreaOrView::PresentationArea, "returns Value as a PresentationArea (Null if another type)");
cls_StepVisual_AreaOrView.def("PresentationView", (opencascade::handle<StepVisual_PresentationView> (StepVisual_AreaOrView::*)() const) &StepVisual_AreaOrView::PresentationView, "returns Value as a PresentationView (Null if another type)");

// Enums

}