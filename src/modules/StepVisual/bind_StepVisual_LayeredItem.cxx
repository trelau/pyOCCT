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
#include <StepVisual_PresentationRepresentation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepVisual_LayeredItem.hxx>

void bind_StepVisual_LayeredItem(py::module &mod){

py::class_<StepVisual_LayeredItem, StepData_SelectType> cls_StepVisual_LayeredItem(mod, "StepVisual_LayeredItem", "None");

// Constructors
cls_StepVisual_LayeredItem.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_LayeredItem.def_static("operator new_", (void * (*)(size_t)) &StepVisual_LayeredItem::operator new, "None", py::arg("theSize"));
// cls_StepVisual_LayeredItem.def_static("operator delete_", (void (*)(void *)) &StepVisual_LayeredItem::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_LayeredItem.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_LayeredItem::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_LayeredItem.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_LayeredItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_LayeredItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_LayeredItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_LayeredItem.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_LayeredItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_LayeredItem.def("CaseNum", (Standard_Integer (StepVisual_LayeredItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_LayeredItem::CaseNum, "Recognizes a LayeredItem Kind Entity that is : 1 -> PresentationRepresentation 2 -> RepresentationItem 0 else", py::arg("ent"));
cls_StepVisual_LayeredItem.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_LayeredItem::*)() const) &StepVisual_LayeredItem::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");
cls_StepVisual_LayeredItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_LayeredItem::*)() const) &StepVisual_LayeredItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");

// Enums

}