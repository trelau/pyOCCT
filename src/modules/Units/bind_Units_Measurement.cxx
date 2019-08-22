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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_Token.hxx>
#include <Units_Measurement.hxx>

void bind_Units_Measurement(py::module &mod){

py::class_<Units_Measurement> cls_Units_Measurement(mod, "Units_Measurement", "This class defines a measurement which is the association of a real value and a unit.");

// Constructors
cls_Units_Measurement.def(py::init<>());
cls_Units_Measurement.def(py::init<const Standard_Real, const opencascade::handle<Units_Token> &>(), py::arg("avalue"), py::arg("atoken"));
cls_Units_Measurement.def(py::init<const Standard_Real, const Standard_CString>(), py::arg("avalue"), py::arg("aunit"));

// Fields

// Methods
// cls_Units_Measurement.def_static("operator new_", (void * (*)(size_t)) &Units_Measurement::operator new, "None", py::arg("theSize"));
// cls_Units_Measurement.def_static("operator delete_", (void (*)(void *)) &Units_Measurement::operator delete, "None", py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator new[]_", (void * (*)(size_t)) &Units_Measurement::operator new[], "None", py::arg("theSize"));
// cls_Units_Measurement.def_static("operator delete[]_", (void (*)(void *)) &Units_Measurement::operator delete[], "None", py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator new_", (void * (*)(size_t, void *)) &Units_Measurement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_Measurement.def_static("operator delete_", (void (*)(void *, void *)) &Units_Measurement::operator delete, "None", py::arg(""), py::arg(""));
cls_Units_Measurement.def("Convert", (void (Units_Measurement::*)(const Standard_CString)) &Units_Measurement::Convert, "Converts (if possible) the measurement object into another unit. <aunit> must have the same dimensionality as the unit contained in the token <thetoken>.", py::arg("aunit"));
cls_Units_Measurement.def("Integer", (Units_Measurement (Units_Measurement::*)() const) &Units_Measurement::Integer, "Returns a Measurement object with the integer value of the measurement contained in <me>.");
cls_Units_Measurement.def("Fractional", (Units_Measurement (Units_Measurement::*)() const) &Units_Measurement::Fractional, "Returns a Measurement object with the fractional value of the measurement contained in <me>.");
cls_Units_Measurement.def("Measurement", (Standard_Real (Units_Measurement::*)() const) &Units_Measurement::Measurement, "Returns the value of the measurement.");
cls_Units_Measurement.def("Token", (opencascade::handle<Units_Token> (Units_Measurement::*)() const) &Units_Measurement::Token, "Returns the token contained in <me>.");
cls_Units_Measurement.def("Add", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Add, "Returns (if it is possible) a measurement which is the addition of <me> and <ameasurement>. The chosen returned unit is the unit of <me>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__add__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator+, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Subtract", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Subtract, "Returns (if it is possible) a measurement which is the subtraction of <me> and <ameasurement>. The chosen returned unit is the unit of <me>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__sub__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator-, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Multiply", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Multiply, "Returns a measurement which is the multiplication of <me> and <ameasurement>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__mul__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator*, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Multiply", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Multiply, "Returns a measurement which is the multiplication of <me> with the value <avalue>.", py::arg("avalue"));
cls_Units_Measurement.def("__mul__", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::operator*, py::is_operator(), "None", py::arg("avalue"));
cls_Units_Measurement.def("Divide", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::Divide, "Returns a measurement which is the division of <me> by <ameasurement>.", py::arg("ameasurement"));
cls_Units_Measurement.def("__truediv__", (Units_Measurement (Units_Measurement::*)(const Units_Measurement &) const) &Units_Measurement::operator/, py::is_operator(), "None", py::arg("ameasurement"));
cls_Units_Measurement.def("Divide", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Divide, "Returns a measurement which is the division of <me> by the constant <avalue>.", py::arg("avalue"));
cls_Units_Measurement.def("__truediv__", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::operator/, py::is_operator(), "None", py::arg("avalue"));
cls_Units_Measurement.def("Power", (Units_Measurement (Units_Measurement::*)(const Standard_Real) const) &Units_Measurement::Power, "Returns a measurement which is <me> powered <anexponent>.", py::arg("anexponent"));
cls_Units_Measurement.def("HasToken", (Standard_Boolean (Units_Measurement::*)() const) &Units_Measurement::HasToken, "None");
cls_Units_Measurement.def("Dump", (void (Units_Measurement::*)() const) &Units_Measurement::Dump, "Useful for debugging.");

// Enums

}