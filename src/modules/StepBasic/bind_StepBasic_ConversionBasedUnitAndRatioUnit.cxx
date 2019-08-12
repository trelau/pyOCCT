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
#include <StepBasic_RatioUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndRatioUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ConversionBasedUnitAndRatioUnit(py::module &mod){

py::class_<StepBasic_ConversionBasedUnitAndRatioUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndRatioUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndRatioUnit(mod, "StepBasic_ConversionBasedUnitAndRatioUnit", "None");

// Constructors
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndRatioUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("SetRatioUnit", (void (StepBasic_ConversionBasedUnitAndRatioUnit::*)(const opencascade::handle<StepBasic_RatioUnit> &)) &StepBasic_ConversionBasedUnitAndRatioUnit::SetRatioUnit, "None", py::arg("aRatioUnit"));
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("RatioUnit", (opencascade::handle<StepBasic_RatioUnit> (StepBasic_ConversionBasedUnitAndRatioUnit::*)() const) &StepBasic_ConversionBasedUnitAndRatioUnit::RatioUnit, "None");
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndRatioUnit::get_type_name, "None");
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndRatioUnit::get_type_descriptor, "None");
cls_StepBasic_ConversionBasedUnitAndRatioUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndRatioUnit::*)() const) &StepBasic_ConversionBasedUnitAndRatioUnit::DynamicType, "None");

// Enums

}