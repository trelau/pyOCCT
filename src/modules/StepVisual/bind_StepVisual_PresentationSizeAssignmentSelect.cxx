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
#include <StepVisual_PresentationView.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <StepVisual_AreaInSet.hxx>
#include <StepVisual_PresentationSizeAssignmentSelect.hxx>

void bind_StepVisual_PresentationSizeAssignmentSelect(py::module &mod){

py::class_<StepVisual_PresentationSizeAssignmentSelect, std::unique_ptr<StepVisual_PresentationSizeAssignmentSelect>, StepData_SelectType> cls_StepVisual_PresentationSizeAssignmentSelect(mod, "StepVisual_PresentationSizeAssignmentSelect", "None");

// Constructors
cls_StepVisual_PresentationSizeAssignmentSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_PresentationSizeAssignmentSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_PresentationSizeAssignmentSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_PresentationSizeAssignmentSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_PresentationSizeAssignmentSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_PresentationSizeAssignmentSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_PresentationSizeAssignmentSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_PresentationSizeAssignmentSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_PresentationSizeAssignmentSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationSizeAssignmentSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_PresentationSizeAssignmentSelect::CaseNum, "Recognizes a PresentationSizeAssignmentSelect Kind Entity that is : 1 -> PresentationView 2 -> PresentationArea 3 -> AreaInSet 0 else", py::arg("ent"));
cls_StepVisual_PresentationSizeAssignmentSelect.def("PresentationView", (opencascade::handle<StepVisual_PresentationView> (StepVisual_PresentationSizeAssignmentSelect::*)() const) &StepVisual_PresentationSizeAssignmentSelect::PresentationView, "returns Value as a PresentationView (Null if another type)");
cls_StepVisual_PresentationSizeAssignmentSelect.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_PresentationSizeAssignmentSelect::*)() const) &StepVisual_PresentationSizeAssignmentSelect::PresentationArea, "returns Value as a PresentationArea (Null if another type)");
cls_StepVisual_PresentationSizeAssignmentSelect.def("AreaInSet", (opencascade::handle<StepVisual_AreaInSet> (StepVisual_PresentationSizeAssignmentSelect::*)() const) &StepVisual_PresentationSizeAssignmentSelect::AreaInSet, "returns Value as a AreaInSet (Null if another type)");

// Enums

}