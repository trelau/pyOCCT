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
#include <StepBasic_Date.hxx>
#include <StepBasic_LocalTime.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateTimeSelect.hxx>

void bind_StepBasic_DateTimeSelect(py::module &mod){

py::class_<StepBasic_DateTimeSelect, std::unique_ptr<StepBasic_DateTimeSelect, Deleter<StepBasic_DateTimeSelect>>, StepData_SelectType> cls_StepBasic_DateTimeSelect(mod, "StepBasic_DateTimeSelect", "None");

// Constructors
cls_StepBasic_DateTimeSelect.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_DateTimeSelect.def_static("operator new_", (void * (*)(size_t)) &StepBasic_DateTimeSelect::operator new, "None", py::arg("theSize"));
// cls_StepBasic_DateTimeSelect.def_static("operator delete_", (void (*)(void *)) &StepBasic_DateTimeSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_DateTimeSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_DateTimeSelect::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_DateTimeSelect.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_DateTimeSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_DateTimeSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_DateTimeSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_DateTimeSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_DateTimeSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_DateTimeSelect.def("CaseNum", (Standard_Integer (StepBasic_DateTimeSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_DateTimeSelect::CaseNum, "Recognizes a DateTimeSelect Kind Entity that is : 1 -> Date 2 -> LocalTime 3 -> DateAndTime 0 else", py::arg("ent"));
cls_StepBasic_DateTimeSelect.def("Date", (opencascade::handle<StepBasic_Date> (StepBasic_DateTimeSelect::*)() const) &StepBasic_DateTimeSelect::Date, "returns Value as a Date (Null if another type)");
cls_StepBasic_DateTimeSelect.def("LocalTime", (opencascade::handle<StepBasic_LocalTime> (StepBasic_DateTimeSelect::*)() const) &StepBasic_DateTimeSelect::LocalTime, "returns Value as a LocalTime (Null if another type)");
cls_StepBasic_DateTimeSelect.def("DateAndTime", (opencascade::handle<StepBasic_DateAndTime> (StepBasic_DateTimeSelect::*)() const) &StepBasic_DateTimeSelect::DateAndTime, "returns Value as a DateAndTime (Null if another type)");

// Enums

}