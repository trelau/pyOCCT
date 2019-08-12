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
#include <Units_Dimensions.hxx>
#include <Standard_Type.hxx>

void bind_Units_Dimensions(py::module &mod){

py::class_<Units_Dimensions, opencascade::handle<Units_Dimensions>, Standard_Transient> cls_Units_Dimensions(mod, "Units_Dimensions", "This class includes all the methods to create and manipulate the dimensions of the physical quantities.");

// Constructors
cls_Units_Dimensions.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("amass"), py::arg("alength"), py::arg("atime"), py::arg("anelectriccurrent"), py::arg("athermodynamictemperature"), py::arg("anamountofsubstance"), py::arg("aluminousintensity"), py::arg("aplaneangle"), py::arg("asolidangle"));

// Fields

// Methods
cls_Units_Dimensions.def("Mass", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Mass, "Returns the power of mass stored in the dimensions.");
cls_Units_Dimensions.def("Length", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Length, "Returns the power of length stored in the dimensions.");
cls_Units_Dimensions.def("Time", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::Time, "Returns the power of time stored in the dimensions.");
cls_Units_Dimensions.def("ElectricCurrent", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::ElectricCurrent, "Returns the power of electrical intensity (current) stored in the dimensions.");
cls_Units_Dimensions.def("ThermodynamicTemperature", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::ThermodynamicTemperature, "Returns the power of temperature stored in the dimensions.");
cls_Units_Dimensions.def("AmountOfSubstance", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::AmountOfSubstance, "Returns the power of quantity of material (mole) stored in the dimensions.");
cls_Units_Dimensions.def("LuminousIntensity", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::LuminousIntensity, "Returns the power of light intensity stored in the dimensions.");
cls_Units_Dimensions.def("PlaneAngle", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::PlaneAngle, "Returns the power of plane angle stored in the dimensions.");
cls_Units_Dimensions.def("SolidAngle", (Standard_Real (Units_Dimensions::*)() const) &Units_Dimensions::SolidAngle, "Returns the power of solid angle stored in the dimensions.");
cls_Units_Dimensions.def("Quantity", (Standard_CString (Units_Dimensions::*)() const) &Units_Dimensions::Quantity, "Returns the quantity string of the dimension");
cls_Units_Dimensions.def("Multiply", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::Multiply, "Creates and returns a new Dimensions object which is the result of the multiplication of <me> and <adimensions>.", py::arg("adimensions"));
cls_Units_Dimensions.def("Divide", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::Divide, "Creates and returns a new Dimensions object which is the result of the division of <me> by <adimensions>.", py::arg("adimensions"));
cls_Units_Dimensions.def("Power", (opencascade::handle<Units_Dimensions> (Units_Dimensions::*)(const Standard_Real) const) &Units_Dimensions::Power, "Creates and returns a new Dimensions object which is the result of the power of <me> and <anexponent>.", py::arg("anexponent"));
cls_Units_Dimensions.def("IsEqual", (Standard_Boolean (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::IsEqual, "Returns true if <me> and <adimensions> have the same dimensions, false otherwise.", py::arg("adimensions"));
cls_Units_Dimensions.def("IsNotEqual", (Standard_Boolean (Units_Dimensions::*)(const opencascade::handle<Units_Dimensions> &) const) &Units_Dimensions::IsNotEqual, "Returns false if <me> and <adimensions> have the same dimensions, true otherwise.", py::arg("adimensions"));
cls_Units_Dimensions.def("Dump", (void (Units_Dimensions::*)(const Standard_Integer) const) &Units_Dimensions::Dump, "Useful for degugging.", py::arg("ashift"));
cls_Units_Dimensions.def_static("ALess_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALess, "None");
cls_Units_Dimensions.def_static("AMass_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AMass, "None");
cls_Units_Dimensions.def_static("ALength_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALength, "None");
cls_Units_Dimensions.def_static("ATime_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ATime, "None");
cls_Units_Dimensions.def_static("AElectricCurrent_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AElectricCurrent, "None");
cls_Units_Dimensions.def_static("AThermodynamicTemperature_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AThermodynamicTemperature, "None");
cls_Units_Dimensions.def_static("AAmountOfSubstance_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::AAmountOfSubstance, "None");
cls_Units_Dimensions.def_static("ALuminousIntensity_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ALuminousIntensity, "None");
cls_Units_Dimensions.def_static("APlaneAngle_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::APlaneAngle, "None");
cls_Units_Dimensions.def_static("ASolidAngle_", (opencascade::handle<Units_Dimensions> (*)()) &Units_Dimensions::ASolidAngle, "Returns the basic dimensions.");
cls_Units_Dimensions.def_static("get_type_name_", (const char * (*)()) &Units_Dimensions::get_type_name, "None");
cls_Units_Dimensions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Dimensions::get_type_descriptor, "None");
cls_Units_Dimensions.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Dimensions::*)() const) &Units_Dimensions::DynamicType, "None");

// Enums

}