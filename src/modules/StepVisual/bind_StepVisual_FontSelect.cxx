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
#include <StepVisual_PreDefinedTextFont.hxx>
#include <StepVisual_ExternallyDefinedTextFont.hxx>
#include <StepVisual_FontSelect.hxx>

void bind_StepVisual_FontSelect(py::module &mod){

py::class_<StepVisual_FontSelect, std::unique_ptr<StepVisual_FontSelect>, StepData_SelectType> cls_StepVisual_FontSelect(mod, "StepVisual_FontSelect", "None");

// Constructors
cls_StepVisual_FontSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_FontSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_FontSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_FontSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_FontSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_FontSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_FontSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_FontSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_FontSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_FontSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_FontSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_FontSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_FontSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_FontSelect.def("CaseNum", (Standard_Integer (StepVisual_FontSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_FontSelect::CaseNum, "Recognizes a FontSelect Kind Entity that is : 1 -> PreDefinedTextFont 2 -> ExternallyDefinedTextFont 0 else", py::arg("ent"));
cls_StepVisual_FontSelect.def("PreDefinedTextFont", (opencascade::handle<StepVisual_PreDefinedTextFont> (StepVisual_FontSelect::*)() const) &StepVisual_FontSelect::PreDefinedTextFont, "returns Value as a PreDefinedTextFont (Null if another type)");
cls_StepVisual_FontSelect.def("ExternallyDefinedTextFont", (opencascade::handle<StepVisual_ExternallyDefinedTextFont> (StepVisual_FontSelect::*)() const) &StepVisual_FontSelect::ExternallyDefinedTextFont, "returns Value as a ExternallyDefinedTextFont (Null if another type)");

// Enums

}