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
#include <StepVisual_PresentationSet.hxx>
#include <StepVisual_PresentationRepresentationSelect.hxx>

void bind_StepVisual_PresentationRepresentationSelect(py::module &mod){

py::class_<StepVisual_PresentationRepresentationSelect, StepData_SelectType> cls_StepVisual_PresentationRepresentationSelect(mod, "StepVisual_PresentationRepresentationSelect", "None");

// Constructors
cls_StepVisual_PresentationRepresentationSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_PresentationRepresentationSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_PresentationRepresentationSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_PresentationRepresentationSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_PresentationRepresentationSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_PresentationRepresentationSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_PresentationRepresentationSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_PresentationRepresentationSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_PresentationRepresentationSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationRepresentationSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_PresentationRepresentationSelect::CaseNum, "Recognizes a PresentationRepresentationSelect Kind Entity that is : 1 -> PresentationRepresentation 2 -> PresentationSet 0 else", py::arg("ent"));
cls_StepVisual_PresentationRepresentationSelect.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_PresentationRepresentationSelect::*)() const) &StepVisual_PresentationRepresentationSelect::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");
cls_StepVisual_PresentationRepresentationSelect.def("PresentationSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_PresentationRepresentationSelect::*)() const) &StepVisual_PresentationRepresentationSelect::PresentationSet, "returns Value as a PresentationSet (Null if another type)");

// Enums

}