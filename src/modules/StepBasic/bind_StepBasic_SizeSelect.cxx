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
#include <StepBasic_SizeSelect.hxx>

void bind_StepBasic_SizeSelect(py::module &mod){

py::class_<StepBasic_SizeSelect, StepData_SelectType> cls_StepBasic_SizeSelect(mod, "StepBasic_SizeSelect", "None");

// Constructors
cls_StepBasic_SizeSelect.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_SizeSelect.def_static("operator new_", (void * (*)(size_t)) &StepBasic_SizeSelect::operator new, "None", py::arg("theSize"));
// cls_StepBasic_SizeSelect.def_static("operator delete_", (void (*)(void *)) &StepBasic_SizeSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_SizeSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_SizeSelect::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_SizeSelect.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_SizeSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_SizeSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_SizeSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_SizeSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_SizeSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_SizeSelect.def("CaseNum", (Standard_Integer (StepBasic_SizeSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_SizeSelect::CaseNum, "Recognizes a TrimmingSelect Kind Entity that is : 1 -> SizeMember 0 else (i.e. Real)", py::arg("ent"));
cls_StepBasic_SizeSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepBasic_SizeSelect::*)() const) &StepBasic_SizeSelect::NewMember, "Returns a SizeMember (POSITIVE_LENGTH_MEASURE) as preferred");
cls_StepBasic_SizeSelect.def("CaseMem", (Standard_Integer (StepBasic_SizeSelect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepBasic_SizeSelect::CaseMem, "Recognizes a SelectMember as Real, named as PARAMETER_VALUE 1 -> PositiveLengthMeasure i.e. Real 0 else (i.e. Entity)", py::arg("ent"));
cls_StepBasic_SizeSelect.def("SetRealValue", (void (StepBasic_SizeSelect::*)(const Standard_Real)) &StepBasic_SizeSelect::SetRealValue, "None", py::arg("aReal"));
cls_StepBasic_SizeSelect.def("RealValue", (Standard_Real (StepBasic_SizeSelect::*)() const) &StepBasic_SizeSelect::RealValue, "returns Value as a Real (Null if another type)");

// Enums

}