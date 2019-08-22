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
#include <TColStd_HArray1OfReal.hxx>
#include <StepFEA_SymmetricTensor23d.hxx>

void bind_StepFEA_SymmetricTensor23d(py::module &mod){

py::class_<StepFEA_SymmetricTensor23d, StepData_SelectType> cls_StepFEA_SymmetricTensor23d(mod, "StepFEA_SymmetricTensor23d", "Representation of STEP SELECT type SymmetricTensor23d");

// Constructors
cls_StepFEA_SymmetricTensor23d.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_SymmetricTensor23d.def_static("operator new_", (void * (*)(size_t)) &StepFEA_SymmetricTensor23d::operator new, "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor23d.def_static("operator delete_", (void (*)(void *)) &StepFEA_SymmetricTensor23d::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor23d.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_SymmetricTensor23d::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor23d.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_SymmetricTensor23d::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor23d.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_SymmetricTensor23d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor23d.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_SymmetricTensor23d::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_SymmetricTensor23d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_SymmetricTensor23d::CaseNum, "Recognizes a kind of SymmetricTensor23d select type return 0", py::arg("ent"));
cls_StepFEA_SymmetricTensor23d.def("CaseMem", (Standard_Integer (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepFEA_SymmetricTensor23d::CaseMem, "Recognizes a items of select member SymmetricTensor23dMember 1 -> IsotropicSymmetricTensor23d 2 -> OrthotropicSymmetricTensor23d 3 -> AnisotropicSymmetricTensor23d 0 else", py::arg("ent"));
cls_StepFEA_SymmetricTensor23d.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_SymmetricTensor23d::*)() const) &StepFEA_SymmetricTensor23d::NewMember, "Returns a new select member the type SymmetricTensor23dMember");
cls_StepFEA_SymmetricTensor23d.def("SetIsotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const Standard_Real)) &StepFEA_SymmetricTensor23d::SetIsotropicSymmetricTensor23d, "Set Value for IsotropicSymmetricTensor23d", py::arg("aVal"));
cls_StepFEA_SymmetricTensor23d.def("IsotropicSymmetricTensor23d", (Standard_Real (StepFEA_SymmetricTensor23d::*)() const) &StepFEA_SymmetricTensor23d::IsotropicSymmetricTensor23d, "Returns Value as IsotropicSymmetricTensor23d (or Null if another type)");
cls_StepFEA_SymmetricTensor23d.def("SetOrthotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor23d::SetOrthotropicSymmetricTensor23d, "Set Value for OrthotropicSymmetricTensor23d", py::arg("aVal"));
cls_StepFEA_SymmetricTensor23d.def("OrthotropicSymmetricTensor23d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor23d::*)() const) &StepFEA_SymmetricTensor23d::OrthotropicSymmetricTensor23d, "Returns Value as OrthotropicSymmetricTensor23d (or Null if another type)");
cls_StepFEA_SymmetricTensor23d.def("SetAnisotropicSymmetricTensor23d", (void (StepFEA_SymmetricTensor23d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor23d::SetAnisotropicSymmetricTensor23d, "Set Value for AnisotropicSymmetricTensor23d", py::arg("aVal"));
cls_StepFEA_SymmetricTensor23d.def("AnisotropicSymmetricTensor23d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor23d::*)() const) &StepFEA_SymmetricTensor23d::AnisotropicSymmetricTensor23d, "Returns Value as AnisotropicSymmetricTensor23d (or Null if another type)");

// Enums

}