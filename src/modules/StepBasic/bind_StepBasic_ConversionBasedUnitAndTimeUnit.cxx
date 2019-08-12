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
#include <StepBasic_ConversionBasedUnit.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepBasic_TimeUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndTimeUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ConversionBasedUnitAndTimeUnit(py::module &mod){

py::class_<StepBasic_ConversionBasedUnitAndTimeUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndTimeUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndTimeUnit(mod, "StepBasic_ConversionBasedUnitAndTimeUnit", "None");

// Constructors
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndTimeUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("SetTimeUnit", (void (StepBasic_ConversionBasedUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_TimeUnit> &)) &StepBasic_ConversionBasedUnitAndTimeUnit::SetTimeUnit, "None", py::arg("aTimeUnit"));
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("TimeUnit", (opencascade::handle<StepBasic_TimeUnit> (StepBasic_ConversionBasedUnitAndTimeUnit::*)() const) &StepBasic_ConversionBasedUnitAndTimeUnit::TimeUnit, "None");
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndTimeUnit::get_type_name, "None");
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndTimeUnit::get_type_descriptor, "None");
cls_StepBasic_ConversionBasedUnitAndTimeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndTimeUnit::*)() const) &StepBasic_ConversionBasedUnitAndTimeUnit::DynamicType, "None");

// Enums

}