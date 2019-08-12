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
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepVisual_PresentationSet.hxx>
#include <StepVisual_StyleContextSelect.hxx>

void bind_StepVisual_StyleContextSelect(py::module &mod){

py::class_<StepVisual_StyleContextSelect, std::unique_ptr<StepVisual_StyleContextSelect, Deleter<StepVisual_StyleContextSelect>>, StepData_SelectType> cls_StepVisual_StyleContextSelect(mod, "StepVisual_StyleContextSelect", "None");

// Constructors
cls_StepVisual_StyleContextSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_StyleContextSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_StyleContextSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_StyleContextSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_StyleContextSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_StyleContextSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_StyleContextSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_StyleContextSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_StyleContextSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_StyleContextSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_StyleContextSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_StyleContextSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_StyleContextSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_StyleContextSelect.def("CaseNum", (Standard_Integer (StepVisual_StyleContextSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_StyleContextSelect::CaseNum, "Recognizes a StyleContextSelect Kind Entity that is : 1 -> Representation 2 -> RepresentationItem 3 -> PresentationSet 0 else", py::arg("ent"));
cls_StepVisual_StyleContextSelect.def("Representation", (opencascade::handle<StepRepr_Representation> (StepVisual_StyleContextSelect::*)() const) &StepVisual_StyleContextSelect::Representation, "returns Value as a Representation (Null if another type)");
cls_StepVisual_StyleContextSelect.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_StyleContextSelect::*)() const) &StepVisual_StyleContextSelect::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
cls_StepVisual_StyleContextSelect.def("PresentationSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_StyleContextSelect::*)() const) &StepVisual_StyleContextSelect::PresentationSet, "returns Value as a PresentationSet (Null if another type)");

// Enums

}