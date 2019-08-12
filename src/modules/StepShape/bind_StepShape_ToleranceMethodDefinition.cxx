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
#include <StepShape_ToleranceValue.hxx>
#include <StepShape_LimitsAndFits.hxx>
#include <StepShape_ToleranceMethodDefinition.hxx>

void bind_StepShape_ToleranceMethodDefinition(py::module &mod){

py::class_<StepShape_ToleranceMethodDefinition, std::unique_ptr<StepShape_ToleranceMethodDefinition, Deleter<StepShape_ToleranceMethodDefinition>>, StepData_SelectType> cls_StepShape_ToleranceMethodDefinition(mod, "StepShape_ToleranceMethodDefinition", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_ToleranceMethodDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepShape_ToleranceMethodDefinition.def_static("operator new_", (void * (*)(size_t)) &StepShape_ToleranceMethodDefinition::operator new, "None", py::arg("theSize"));
// cls_StepShape_ToleranceMethodDefinition.def_static("operator delete_", (void (*)(void *)) &StepShape_ToleranceMethodDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_ToleranceMethodDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_ToleranceMethodDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepShape_ToleranceMethodDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepShape_ToleranceMethodDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_ToleranceMethodDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_ToleranceMethodDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_ToleranceMethodDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_ToleranceMethodDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_ToleranceMethodDefinition.def("CaseNum", (Standard_Integer (StepShape_ToleranceMethodDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_ToleranceMethodDefinition::CaseNum, "Recognizes a kind of ValueQualifier Select Type : 1 -> ToleranceValue from StepShape 2 -> LimitsAndFits from StepShape", py::arg("ent"));
cls_StepShape_ToleranceMethodDefinition.def("ToleranceValue", (opencascade::handle<StepShape_ToleranceValue> (StepShape_ToleranceMethodDefinition::*)() const) &StepShape_ToleranceMethodDefinition::ToleranceValue, "Returns Value as ToleranceValue");
cls_StepShape_ToleranceMethodDefinition.def("LimitsAndFits", (opencascade::handle<StepShape_LimitsAndFits> (StepShape_ToleranceMethodDefinition::*)() const) &StepShape_ToleranceMethodDefinition::LimitsAndFits, "Returns Value as LimitsAndFits");

// Enums

}