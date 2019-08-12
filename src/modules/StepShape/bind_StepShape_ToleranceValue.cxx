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
#include <Standard_Handle.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepShape_ToleranceValue.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ToleranceValue(py::module &mod){

py::class_<StepShape_ToleranceValue, opencascade::handle<StepShape_ToleranceValue>, Standard_Transient> cls_StepShape_ToleranceValue(mod, "StepShape_ToleranceValue", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_ToleranceValue.def(py::init<>());

// Fields

// Methods
cls_StepShape_ToleranceValue.def("Init", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::Init, "None", py::arg("lower_bound"), py::arg("upper_bound"));
cls_StepShape_ToleranceValue.def("LowerBound", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_ToleranceValue::*)() const) &StepShape_ToleranceValue::LowerBound, "None");
cls_StepShape_ToleranceValue.def("SetLowerBound", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::SetLowerBound, "None", py::arg("lower_bound"));
cls_StepShape_ToleranceValue.def("UpperBound", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_ToleranceValue::*)() const) &StepShape_ToleranceValue::UpperBound, "None");
cls_StepShape_ToleranceValue.def("SetUpperBound", (void (StepShape_ToleranceValue::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_ToleranceValue::SetUpperBound, "None", py::arg("upper_bound"));
cls_StepShape_ToleranceValue.def_static("get_type_name_", (const char * (*)()) &StepShape_ToleranceValue::get_type_name, "None");
cls_StepShape_ToleranceValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ToleranceValue::get_type_descriptor, "None");
cls_StepShape_ToleranceValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ToleranceValue::*)() const) &StepShape_ToleranceValue::DynamicType, "None");

// Enums

}