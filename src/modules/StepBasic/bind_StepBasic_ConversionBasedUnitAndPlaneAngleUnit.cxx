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
#include <StepBasic_PlaneAngleUnit.hxx>
#include <StepBasic_ConversionBasedUnitAndPlaneAngleUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ConversionBasedUnitAndPlaneAngleUnit(py::module &mod){

py::class_<StepBasic_ConversionBasedUnitAndPlaneAngleUnit, opencascade::handle<StepBasic_ConversionBasedUnitAndPlaneAngleUnit>, StepBasic_ConversionBasedUnit> cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit(mod, "StepBasic_ConversionBasedUnitAndPlaneAngleUnit", "None");

// Constructors
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("Init", (void (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("SetPlaneAngleUnit", (void (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)(const opencascade::handle<StepBasic_PlaneAngleUnit> &)) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::SetPlaneAngleUnit, "None", py::arg("aPlaneAngleUnit"));
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("PlaneAngleUnit", (opencascade::handle<StepBasic_PlaneAngleUnit> (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)() const) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::PlaneAngleUnit, "None");
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::get_type_name, "None");
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::get_type_descriptor, "None");
cls_StepBasic_ConversionBasedUnitAndPlaneAngleUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnitAndPlaneAngleUnit::*)() const) &StepBasic_ConversionBasedUnitAndPlaneAngleUnit::DynamicType, "None");

// Enums

}