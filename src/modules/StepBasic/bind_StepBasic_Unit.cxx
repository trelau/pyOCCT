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
#include <StepBasic_NamedUnit.hxx>
#include <StepBasic_DerivedUnit.hxx>
#include <StepBasic_Unit.hxx>

void bind_StepBasic_Unit(py::module &mod){

py::class_<StepBasic_Unit, std::unique_ptr<StepBasic_Unit>, StepData_SelectType> cls_StepBasic_Unit(mod, "StepBasic_Unit", "Implements a select type unit (NamedUnit or DerivedUnit)");

// Constructors
cls_StepBasic_Unit.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_Unit.def_static("operator new_", (void * (*)(size_t)) &StepBasic_Unit::operator new, "None", py::arg("theSize"));
// cls_StepBasic_Unit.def_static("operator delete_", (void (*)(void *)) &StepBasic_Unit::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_Unit.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_Unit::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_Unit.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_Unit::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_Unit.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_Unit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_Unit.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_Unit::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_Unit.def("CaseNum", (Standard_Integer (StepBasic_Unit::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_Unit::CaseNum, "Recognizes a type of Unit Entity 1 -> NamedUnit 2 -> DerivedUnit", py::arg("ent"));
cls_StepBasic_Unit.def("NamedUnit", (opencascade::handle<StepBasic_NamedUnit> (StepBasic_Unit::*)() const) &StepBasic_Unit::NamedUnit, "returns Value as a NamedUnit (Null if another type)");
cls_StepBasic_Unit.def("DerivedUnit", (opencascade::handle<StepBasic_DerivedUnit> (StepBasic_Unit::*)() const) &StepBasic_Unit::DerivedUnit, "returns Value as a DerivedUnit (Null if another type)");

// Enums

}