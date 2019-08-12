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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DimensionalExponents(py::module &mod){

py::class_<StepBasic_DimensionalExponents, opencascade::handle<StepBasic_DimensionalExponents>, Standard_Transient> cls_StepBasic_DimensionalExponents(mod, "StepBasic_DimensionalExponents", "None");

// Constructors
cls_StepBasic_DimensionalExponents.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DimensionalExponents.def("Init", (void (StepBasic_DimensionalExponents::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &StepBasic_DimensionalExponents::Init, "None", py::arg("aLengthExponent"), py::arg("aMassExponent"), py::arg("aTimeExponent"), py::arg("aElectricCurrentExponent"), py::arg("aThermodynamicTemperatureExponent"), py::arg("aAmountOfSubstanceExponent"), py::arg("aLuminousIntensityExponent"));
cls_StepBasic_DimensionalExponents.def("SetLengthExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetLengthExponent, "None", py::arg("aLengthExponent"));
cls_StepBasic_DimensionalExponents.def("LengthExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::LengthExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetMassExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetMassExponent, "None", py::arg("aMassExponent"));
cls_StepBasic_DimensionalExponents.def("MassExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::MassExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetTimeExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetTimeExponent, "None", py::arg("aTimeExponent"));
cls_StepBasic_DimensionalExponents.def("TimeExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::TimeExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetElectricCurrentExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetElectricCurrentExponent, "None", py::arg("aElectricCurrentExponent"));
cls_StepBasic_DimensionalExponents.def("ElectricCurrentExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::ElectricCurrentExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetThermodynamicTemperatureExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetThermodynamicTemperatureExponent, "None", py::arg("aThermodynamicTemperatureExponent"));
cls_StepBasic_DimensionalExponents.def("ThermodynamicTemperatureExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::ThermodynamicTemperatureExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetAmountOfSubstanceExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetAmountOfSubstanceExponent, "None", py::arg("aAmountOfSubstanceExponent"));
cls_StepBasic_DimensionalExponents.def("AmountOfSubstanceExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::AmountOfSubstanceExponent, "None");
cls_StepBasic_DimensionalExponents.def("SetLuminousIntensityExponent", (void (StepBasic_DimensionalExponents::*)(const Standard_Real)) &StepBasic_DimensionalExponents::SetLuminousIntensityExponent, "None", py::arg("aLuminousIntensityExponent"));
cls_StepBasic_DimensionalExponents.def("LuminousIntensityExponent", (Standard_Real (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::LuminousIntensityExponent, "None");
cls_StepBasic_DimensionalExponents.def_static("get_type_name_", (const char * (*)()) &StepBasic_DimensionalExponents::get_type_name, "None");
cls_StepBasic_DimensionalExponents.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DimensionalExponents::get_type_descriptor, "None");
cls_StepBasic_DimensionalExponents.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DimensionalExponents::*)() const) &StepBasic_DimensionalExponents::DynamicType, "None");

// Enums

}