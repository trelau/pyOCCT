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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_BooleanResult.hxx>
#include <StepShape_CsgPrimitive.hxx>
#include <StepShape_CsgSelect.hxx>

void bind_StepShape_CsgSelect(py::module &mod){

py::class_<StepShape_CsgSelect, std::unique_ptr<StepShape_CsgSelect>> cls_StepShape_CsgSelect(mod, "StepShape_CsgSelect", "None");

// Constructors
cls_StepShape_CsgSelect.def(py::init<>());

// Fields

// Methods
// cls_StepShape_CsgSelect.def_static("operator new_", (void * (*)(size_t)) &StepShape_CsgSelect::operator new, "None", py::arg("theSize"));
// cls_StepShape_CsgSelect.def_static("operator delete_", (void (*)(void *)) &StepShape_CsgSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_CsgSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_CsgSelect::operator new[], "None", py::arg("theSize"));
// cls_StepShape_CsgSelect.def_static("operator delete[]_", (void (*)(void *)) &StepShape_CsgSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_CsgSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_CsgSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_CsgSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_CsgSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_CsgSelect.def("SetTypeOfContent", (void (StepShape_CsgSelect::*)(const Standard_Integer)) &StepShape_CsgSelect::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
cls_StepShape_CsgSelect.def("TypeOfContent", (Standard_Integer (StepShape_CsgSelect::*)() const) &StepShape_CsgSelect::TypeOfContent, "None");
cls_StepShape_CsgSelect.def("BooleanResult", (opencascade::handle<StepShape_BooleanResult> (StepShape_CsgSelect::*)() const) &StepShape_CsgSelect::BooleanResult, "returns Value as a BooleanResult (Null if another type)");
cls_StepShape_CsgSelect.def("SetBooleanResult", (void (StepShape_CsgSelect::*)(const opencascade::handle<StepShape_BooleanResult> &)) &StepShape_CsgSelect::SetBooleanResult, "None", py::arg("aBooleanResult"));
cls_StepShape_CsgSelect.def("CsgPrimitive", (StepShape_CsgPrimitive (StepShape_CsgSelect::*)() const) &StepShape_CsgSelect::CsgPrimitive, "returns Value as a CsgPrimitive (Null if another type)");
cls_StepShape_CsgSelect.def("SetCsgPrimitive", (void (StepShape_CsgSelect::*)(const StepShape_CsgPrimitive &)) &StepShape_CsgSelect::SetCsgPrimitive, "None", py::arg("aCsgPrimitive"));

// Enums

}