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
#include <StepFEA_SymmetricTensor43d.hxx>

void bind_StepFEA_SymmetricTensor43d(py::module &mod){

py::class_<StepFEA_SymmetricTensor43d, std::unique_ptr<StepFEA_SymmetricTensor43d>, StepData_SelectType> cls_StepFEA_SymmetricTensor43d(mod, "StepFEA_SymmetricTensor43d", "Representation of STEP SELECT type SymmetricTensor43d");

// Constructors
cls_StepFEA_SymmetricTensor43d.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_SymmetricTensor43d.def_static("operator new_", (void * (*)(size_t)) &StepFEA_SymmetricTensor43d::operator new, "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor43d.def_static("operator delete_", (void (*)(void *)) &StepFEA_SymmetricTensor43d::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor43d.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_SymmetricTensor43d::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor43d.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_SymmetricTensor43d::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor43d.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_SymmetricTensor43d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor43d.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_SymmetricTensor43d::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_SymmetricTensor43d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_SymmetricTensor43d::CaseNum, "return 0", py::arg("ent"));
cls_StepFEA_SymmetricTensor43d.def("CaseMem", (Standard_Integer (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepFEA_SymmetricTensor43d::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> AnisotropicSymmetricTensor43d 2 -> FeaIsotropicSymmetricTensor43d 3 -> FeaIsoOrthotropicSymmetricTensor43d 4 -> FeaTransverseIsotropicSymmetricTensor43d 5 -> FeaColumnNormalisedOrthotropicSymmetricTensor43d 6 -> FeaColumnNormalisedMonoclinicSymmetricTensor43d 0 else", py::arg("ent"));
cls_StepFEA_SymmetricTensor43d.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::NewMember, "None");
cls_StepFEA_SymmetricTensor43d.def("AnisotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::AnisotropicSymmetricTensor43d, "Returns Value as AnisotropicSymmetricTensor43d (or Null if another type)");
// cls_StepFEA_SymmetricTensor43d.def("SetFeaIsotropicSymmetricTensor43d", (void (StepFEA_SymmetricTensor43d::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_SymmetricTensor43d::SetFeaIsotropicSymmetricTensor43d, "None", py::arg("val"));
cls_StepFEA_SymmetricTensor43d.def("FeaIsotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::FeaIsotropicSymmetricTensor43d, "Returns Value as FeaIsotropicSymmetricTensor43d (or Null if another type)");
cls_StepFEA_SymmetricTensor43d.def("FeaIsoOrthotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::FeaIsoOrthotropicSymmetricTensor43d, "Returns Value as FeaIsoOrthotropicSymmetricTensor43d (or Null if another type)");
cls_StepFEA_SymmetricTensor43d.def("FeaTransverseIsotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::FeaTransverseIsotropicSymmetricTensor43d, "Returns Value as FeaTransverseIsotropicSymmetricTensor43d (or Null if another type)");
cls_StepFEA_SymmetricTensor43d.def("FeaColumnNormalisedOrthotropicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::FeaColumnNormalisedOrthotropicSymmetricTensor43d, "Returns Value as FeaColumnNormalisedOrthotropicSymmetricTensor43d (or Null if another type)");
cls_StepFEA_SymmetricTensor43d.def("FeaColumnNormalisedMonoclinicSymmetricTensor43d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor43d::*)() const) &StepFEA_SymmetricTensor43d::FeaColumnNormalisedMonoclinicSymmetricTensor43d, "Returns Value as FeaColumnNormalisedMonoclinicSymmetricTensor43d (or Null if another type)");

// Enums

}