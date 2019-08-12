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
#include <Standard_Transient.hxx>
#include <StepShape_ToleranceMethodDefinition.hxx>
#include <StepShape_DimensionalCharacteristic.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_PlusMinusTolerance.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_PlusMinusTolerance(py::module &mod){

py::class_<StepShape_PlusMinusTolerance, opencascade::handle<StepShape_PlusMinusTolerance>, Standard_Transient> cls_StepShape_PlusMinusTolerance(mod, "StepShape_PlusMinusTolerance", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_PlusMinusTolerance.def(py::init<>());

// Fields

// Methods
cls_StepShape_PlusMinusTolerance.def("Init", (void (StepShape_PlusMinusTolerance::*)(const StepShape_ToleranceMethodDefinition &, const StepShape_DimensionalCharacteristic &)) &StepShape_PlusMinusTolerance::Init, "None", py::arg("range"), py::arg("toleranced_dimension"));
cls_StepShape_PlusMinusTolerance.def("Range", (StepShape_ToleranceMethodDefinition (StepShape_PlusMinusTolerance::*)() const) &StepShape_PlusMinusTolerance::Range, "None");
cls_StepShape_PlusMinusTolerance.def("SetRange", (void (StepShape_PlusMinusTolerance::*)(const StepShape_ToleranceMethodDefinition &)) &StepShape_PlusMinusTolerance::SetRange, "None", py::arg("range"));
cls_StepShape_PlusMinusTolerance.def("TolerancedDimension", (StepShape_DimensionalCharacteristic (StepShape_PlusMinusTolerance::*)() const) &StepShape_PlusMinusTolerance::TolerancedDimension, "None");
cls_StepShape_PlusMinusTolerance.def("SetTolerancedDimension", (void (StepShape_PlusMinusTolerance::*)(const StepShape_DimensionalCharacteristic &)) &StepShape_PlusMinusTolerance::SetTolerancedDimension, "None", py::arg("toleranced_dimension"));
cls_StepShape_PlusMinusTolerance.def_static("get_type_name_", (const char * (*)()) &StepShape_PlusMinusTolerance::get_type_name, "None");
cls_StepShape_PlusMinusTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PlusMinusTolerance::get_type_descriptor, "None");
cls_StepShape_PlusMinusTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PlusMinusTolerance::*)() const) &StepShape_PlusMinusTolerance::DynamicType, "None");

// Enums

}