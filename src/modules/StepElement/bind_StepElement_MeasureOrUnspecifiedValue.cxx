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
#include <StepElement_UnspecifiedValue.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>

void bind_StepElement_MeasureOrUnspecifiedValue(py::module &mod){

py::class_<StepElement_MeasureOrUnspecifiedValue, std::unique_ptr<StepElement_MeasureOrUnspecifiedValue>, StepData_SelectType> cls_StepElement_MeasureOrUnspecifiedValue(mod, "StepElement_MeasureOrUnspecifiedValue", "Representation of STEP SELECT type MeasureOrUnspecifiedValue");

// Constructors
cls_StepElement_MeasureOrUnspecifiedValue.def(py::init<>());

// Fields

// Methods
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t)) &StepElement_MeasureOrUnspecifiedValue::operator new, "None", py::arg("theSize"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_MeasureOrUnspecifiedValue::operator new[], "None", py::arg("theSize"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete[]_", (void (*)(void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_MeasureOrUnspecifiedValue::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_MeasureOrUnspecifiedValue.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_MeasureOrUnspecifiedValue::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_MeasureOrUnspecifiedValue.def("CaseNum", (Standard_Integer (StepElement_MeasureOrUnspecifiedValue::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_MeasureOrUnspecifiedValue::CaseNum, "Recognizes a kind of MeasureOrUnspecifiedValue select type return 0", py::arg("ent"));
cls_StepElement_MeasureOrUnspecifiedValue.def("CaseMem", (Standard_Integer (StepElement_MeasureOrUnspecifiedValue::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_MeasureOrUnspecifiedValue::CaseMem, "Recognizes a items of select member MeasureOrUnspecifiedValueMember 1 -> ContextDependentMeasure 2 -> UnspecifiedValue 0 else", py::arg("ent"));
cls_StepElement_MeasureOrUnspecifiedValue.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::NewMember, "Returns a new select member the type MeasureOrUnspecifiedValueMember");
cls_StepElement_MeasureOrUnspecifiedValue.def("SetContextDependentMeasure", (void (StepElement_MeasureOrUnspecifiedValue::*)(const Standard_Real)) &StepElement_MeasureOrUnspecifiedValue::SetContextDependentMeasure, "Set Value for ContextDependentMeasure", py::arg("aVal"));
cls_StepElement_MeasureOrUnspecifiedValue.def("ContextDependentMeasure", (Standard_Real (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::ContextDependentMeasure, "Returns Value as ContextDependentMeasure (or Null if another type)");
cls_StepElement_MeasureOrUnspecifiedValue.def("SetUnspecifiedValue", (void (StepElement_MeasureOrUnspecifiedValue::*)(const StepElement_UnspecifiedValue)) &StepElement_MeasureOrUnspecifiedValue::SetUnspecifiedValue, "Set Value for UnspecifiedValue", py::arg("aVal"));
cls_StepElement_MeasureOrUnspecifiedValue.def("UnspecifiedValue", (StepElement_UnspecifiedValue (StepElement_MeasureOrUnspecifiedValue::*)() const) &StepElement_MeasureOrUnspecifiedValue::UnspecifiedValue, "Returns Value as UnspecifiedValue (or Null if another type)");

// Enums

}