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
#include <StepDimTol_DatumReferenceModifierWithValue.hxx>
#include <StepDimTol_SimpleDatumReferenceModifierMember.hxx>
#include <StepDimTol_DatumReferenceModifier.hxx>

void bind_StepDimTol_DatumReferenceModifier(py::module &mod){

py::class_<StepDimTol_DatumReferenceModifier, std::unique_ptr<StepDimTol_DatumReferenceModifier, Deleter<StepDimTol_DatumReferenceModifier>>, StepData_SelectType> cls_StepDimTol_DatumReferenceModifier(mod, "StepDimTol_DatumReferenceModifier", "None");

// Constructors
cls_StepDimTol_DatumReferenceModifier.def(py::init<>());

// Fields

// Methods
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new_", (void * (*)(size_t)) &StepDimTol_DatumReferenceModifier::operator new, "None", py::arg("theSize"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete_", (void (*)(void *)) &StepDimTol_DatumReferenceModifier::operator delete, "None", py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new[]_", (void * (*)(size_t)) &StepDimTol_DatumReferenceModifier::operator new[], "None", py::arg("theSize"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete[]_", (void (*)(void *)) &StepDimTol_DatumReferenceModifier::operator delete[], "None", py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator new_", (void * (*)(size_t, void *)) &StepDimTol_DatumReferenceModifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepDimTol_DatumReferenceModifier.def_static("operator delete_", (void (*)(void *, void *)) &StepDimTol_DatumReferenceModifier::operator delete, "None", py::arg(""), py::arg(""));
cls_StepDimTol_DatumReferenceModifier.def("CaseNum", (Standard_Integer (StepDimTol_DatumReferenceModifier::*)(const opencascade::handle<Standard_Transient> &) const) &StepDimTol_DatumReferenceModifier::CaseNum, "Recognizes a DatumReferenceModifier Kind Entity that is : 1 -> DatumReferenceModifierWithValue 2 -> SimpleDatumReferenceModifierMember 0 else", py::arg("ent"));
cls_StepDimTol_DatumReferenceModifier.def("DatumReferenceModifierWithValue", (opencascade::handle<StepDimTol_DatumReferenceModifierWithValue> (StepDimTol_DatumReferenceModifier::*)() const) &StepDimTol_DatumReferenceModifier::DatumReferenceModifierWithValue, "returns Value as a DatumReferenceModifierWithValue (Null if another type)");
cls_StepDimTol_DatumReferenceModifier.def("SimpleDatumReferenceModifierMember", (opencascade::handle<StepDimTol_SimpleDatumReferenceModifierMember> (StepDimTol_DatumReferenceModifier::*)() const) &StepDimTol_DatumReferenceModifier::SimpleDatumReferenceModifierMember, "returns Value as a SimpleDatumReferenceModifierMember (Null if another type)");

// Enums

}