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
#include <TColStd_HArray1OfReal.hxx>
#include <StepFEA_SymmetricTensor22d.hxx>

void bind_StepFEA_SymmetricTensor22d(py::module &mod){

py::class_<StepFEA_SymmetricTensor22d, std::unique_ptr<StepFEA_SymmetricTensor22d>, StepData_SelectType> cls_StepFEA_SymmetricTensor22d(mod, "StepFEA_SymmetricTensor22d", "Representation of STEP SELECT type SymmetricTensor22d");

// Constructors
cls_StepFEA_SymmetricTensor22d.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_SymmetricTensor22d.def_static("operator new_", (void * (*)(size_t)) &StepFEA_SymmetricTensor22d::operator new, "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor22d.def_static("operator delete_", (void (*)(void *)) &StepFEA_SymmetricTensor22d::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor22d.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_SymmetricTensor22d::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_SymmetricTensor22d.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_SymmetricTensor22d::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor22d.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_SymmetricTensor22d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_SymmetricTensor22d.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_SymmetricTensor22d::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_SymmetricTensor22d.def("CaseNum", (Standard_Integer (StepFEA_SymmetricTensor22d::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_SymmetricTensor22d::CaseNum, "Recognizes a kind of SymmetricTensor22d select type 1 -> HArray1OfReal from TColStd 0 else", py::arg("ent"));
cls_StepFEA_SymmetricTensor22d.def("AnisotropicSymmetricTensor22d", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_SymmetricTensor22d::*)() const) &StepFEA_SymmetricTensor22d::AnisotropicSymmetricTensor22d, "Returns Value as AnisotropicSymmetricTensor22d (or Null if another type)");

// Enums

}