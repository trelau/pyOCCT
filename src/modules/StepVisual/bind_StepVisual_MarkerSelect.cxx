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
#include <StepData_SelectMember.hxx>
#include <StepVisual_MarkerMember.hxx>
#include <StepVisual_MarkerSelect.hxx>

void bind_StepVisual_MarkerSelect(py::module &mod){

py::class_<StepVisual_MarkerSelect, StepData_SelectType> cls_StepVisual_MarkerSelect(mod, "StepVisual_MarkerSelect", "None");

// Constructors
cls_StepVisual_MarkerSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_MarkerSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_MarkerSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_MarkerSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_MarkerSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_MarkerSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_MarkerSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_MarkerSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_MarkerSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_MarkerSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_MarkerSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_MarkerSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_MarkerSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_MarkerSelect.def("CaseNum", (Standard_Integer (StepVisual_MarkerSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_MarkerSelect::CaseNum, "Recognizes a MarkerSelect Kind Entity that is : 0 else", py::arg("ent"));
cls_StepVisual_MarkerSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepVisual_MarkerSelect::*)() const) &StepVisual_MarkerSelect::NewMember, "Returns a new MarkerMember");
cls_StepVisual_MarkerSelect.def("CaseMem", (Standard_Integer (StepVisual_MarkerSelect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepVisual_MarkerSelect::CaseMem, "Returns 1 for a SelectMember enum, named MARKER_TYPE", py::arg("sm"));
cls_StepVisual_MarkerSelect.def("MarkerMember", (opencascade::handle<StepVisual_MarkerMember> (StepVisual_MarkerSelect::*)() const) &StepVisual_MarkerSelect::MarkerMember, "Gives access to the MarkerMember in order to get/set its value");

// Enums

}