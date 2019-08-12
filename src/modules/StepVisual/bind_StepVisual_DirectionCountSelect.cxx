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
#include <StepVisual_DirectionCountSelect.hxx>

void bind_StepVisual_DirectionCountSelect(py::module &mod){

py::class_<StepVisual_DirectionCountSelect, std::unique_ptr<StepVisual_DirectionCountSelect, Deleter<StepVisual_DirectionCountSelect>>> cls_StepVisual_DirectionCountSelect(mod, "StepVisual_DirectionCountSelect", "None");

// Constructors
cls_StepVisual_DirectionCountSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_DirectionCountSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_DirectionCountSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_DirectionCountSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_DirectionCountSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_DirectionCountSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_DirectionCountSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_DirectionCountSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_DirectionCountSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_DirectionCountSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_DirectionCountSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_DirectionCountSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_DirectionCountSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_DirectionCountSelect.def("SetTypeOfContent", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
cls_StepVisual_DirectionCountSelect.def("TypeOfContent", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const) &StepVisual_DirectionCountSelect::TypeOfContent, "None");
cls_StepVisual_DirectionCountSelect.def("UDirectionCount", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const) &StepVisual_DirectionCountSelect::UDirectionCount, "None");
cls_StepVisual_DirectionCountSelect.def("SetUDirectionCount", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetUDirectionCount, "None", py::arg("aUDirectionCount"));
cls_StepVisual_DirectionCountSelect.def("VDirectionCount", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const) &StepVisual_DirectionCountSelect::VDirectionCount, "None");
cls_StepVisual_DirectionCountSelect.def("SetVDirectionCount", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetVDirectionCount, "None", py::arg("aUDirectionCount"));

// Enums

}