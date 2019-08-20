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
#include <StepRepr_ItemDefinedTransformation.hxx>
#include <StepRepr_FunctionallyDefinedTransformation.hxx>
#include <StepRepr_Transformation.hxx>

void bind_StepRepr_Transformation(py::module &mod){

py::class_<StepRepr_Transformation, std::unique_ptr<StepRepr_Transformation>, StepData_SelectType> cls_StepRepr_Transformation(mod, "StepRepr_Transformation", "None");

// Constructors
cls_StepRepr_Transformation.def(py::init<>());

// Fields

// Methods
// cls_StepRepr_Transformation.def_static("operator new_", (void * (*)(size_t)) &StepRepr_Transformation::operator new, "None", py::arg("theSize"));
// cls_StepRepr_Transformation.def_static("operator delete_", (void (*)(void *)) &StepRepr_Transformation::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_Transformation::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_Transformation.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_Transformation::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_Transformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_Transformation::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_Transformation.def("CaseNum", (Standard_Integer (StepRepr_Transformation::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_Transformation::CaseNum, "Recognizes a Transformation Kind Entity that is : 1 -> ItemDefinedTransformation 2 -> FunctionallyDefinedTransformation 0 else", py::arg("ent"));
cls_StepRepr_Transformation.def("ItemDefinedTransformation", (opencascade::handle<StepRepr_ItemDefinedTransformation> (StepRepr_Transformation::*)() const) &StepRepr_Transformation::ItemDefinedTransformation, "returns Value as a ItemDefinedTransformation (Null if another type)");
cls_StepRepr_Transformation.def("FunctionallyDefinedTransformation", (opencascade::handle<StepRepr_FunctionallyDefinedTransformation> (StepRepr_Transformation::*)() const) &StepRepr_Transformation::FunctionallyDefinedTransformation, "returns Value as a FunctionallyDefinedTransformation (Null if another type)");

// Enums

}