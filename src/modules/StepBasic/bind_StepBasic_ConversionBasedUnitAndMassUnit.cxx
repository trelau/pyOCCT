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
#include <StepBasic_MassUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndMassUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ConversionBasedUnitAndMassUnit(py::module &mod){

py::class_<StepBasic_ConversionBasedUnitAndMassUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndMassUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndMassUnit(mod, "StepBasic_ConversionBasedUnitAndMassUnit", "None");

// Constructors
cls_StepBasic_ConversionBasedUnitAndMassUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ConversionBasedUnitAndMassUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndMassUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnitAndMassUnit.def("SetMassUnit", (void (StepBasic_ConversionBasedUnitAndMassUnit::*)(const opencascade::handle<StepBasic_MassUnit> &)) &StepBasic_ConversionBasedUnitAndMassUnit::SetMassUnit, "None", py::arg("aMassUnit"));
cls_StepBasic_ConversionBasedUnitAndMassUnit.def("MassUnit", (opencascade::handle<StepBasic_MassUnit> (StepBasic_ConversionBasedUnitAndMassUnit::*)() const) &StepBasic_ConversionBasedUnitAndMassUnit::MassUnit, "None");
cls_StepBasic_ConversionBasedUnitAndMassUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndMassUnit::get_type_name, "None");
cls_StepBasic_ConversionBasedUnitAndMassUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndMassUnit::get_type_descriptor, "None");
cls_StepBasic_ConversionBasedUnitAndMassUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndMassUnit::*)() const) &StepBasic_ConversionBasedUnitAndMassUnit::DynamicType, "None");

// Enums

}