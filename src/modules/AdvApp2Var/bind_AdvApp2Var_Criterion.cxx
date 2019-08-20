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
#include <AdvApp2Var_Patch.hxx>
#include <AdvApp2Var_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApp2Var_CriterionType.hxx>
#include <AdvApp2Var_CriterionRepartition.hxx>
#include <AdvApp2Var_Criterion.hxx>

void bind_AdvApp2Var_Criterion(py::module &mod){

py::class_<AdvApp2Var_Criterion, std::unique_ptr<AdvApp2Var_Criterion>> cls_AdvApp2Var_Criterion(mod, "AdvApp2Var_Criterion", "this class contains a given criterion to be satisfied");

// Fields

// Methods
// cls_AdvApp2Var_Criterion.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Criterion::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Criterion.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Criterion::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Criterion::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Criterion.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Criterion::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Criterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Criterion::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Criterion.def("Value", (void (AdvApp2Var_Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const) &AdvApp2Var_Criterion::Value, "None", py::arg("P"), py::arg("C"));
cls_AdvApp2Var_Criterion.def("IsSatisfied", (Standard_Boolean (AdvApp2Var_Criterion::*)(const AdvApp2Var_Patch &) const) &AdvApp2Var_Criterion::IsSatisfied, "None", py::arg("P"));
cls_AdvApp2Var_Criterion.def("MaxValue", (Standard_Real (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::MaxValue, "None");
cls_AdvApp2Var_Criterion.def("Type", (AdvApp2Var_CriterionType (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::Type, "None");
cls_AdvApp2Var_Criterion.def("Repartition", (AdvApp2Var_CriterionRepartition (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::Repartition, "None");

// Enums

}