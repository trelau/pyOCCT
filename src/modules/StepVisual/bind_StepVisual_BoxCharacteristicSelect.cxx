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
#include <StepVisual_BoxCharacteristicSelect.hxx>

void bind_StepVisual_BoxCharacteristicSelect(py::module &mod){

py::class_<StepVisual_BoxCharacteristicSelect, std::unique_ptr<StepVisual_BoxCharacteristicSelect>> cls_StepVisual_BoxCharacteristicSelect(mod, "StepVisual_BoxCharacteristicSelect", "None");

// Constructors
cls_StepVisual_BoxCharacteristicSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_BoxCharacteristicSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_BoxCharacteristicSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_BoxCharacteristicSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_BoxCharacteristicSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_BoxCharacteristicSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_BoxCharacteristicSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_BoxCharacteristicSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_BoxCharacteristicSelect.def("TypeOfContent", (Standard_Integer (StepVisual_BoxCharacteristicSelect::*)() const) &StepVisual_BoxCharacteristicSelect::TypeOfContent, "None");
cls_StepVisual_BoxCharacteristicSelect.def("SetTypeOfContent", (void (StepVisual_BoxCharacteristicSelect::*)(const Standard_Integer)) &StepVisual_BoxCharacteristicSelect::SetTypeOfContent, "None", py::arg("aType"));
cls_StepVisual_BoxCharacteristicSelect.def("RealValue", (Standard_Real (StepVisual_BoxCharacteristicSelect::*)() const) &StepVisual_BoxCharacteristicSelect::RealValue, "None");
cls_StepVisual_BoxCharacteristicSelect.def("SetRealValue", (void (StepVisual_BoxCharacteristicSelect::*)(const Standard_Real)) &StepVisual_BoxCharacteristicSelect::SetRealValue, "None", py::arg("aValue"));

// Enums

}