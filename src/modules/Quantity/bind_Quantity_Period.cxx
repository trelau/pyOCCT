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
#include <Quantity_Period.hxx>

void bind_Quantity_Period(py::module &mod){

py::class_<Quantity_Period> cls_Quantity_Period(mod, "Quantity_Period", "Manages date intervals. For example, a Period object gives the interval between two dates. A period is expressed in seconds and microseconds.");

// Constructors
cls_Quantity_Period.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_Quantity_Period.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"));
cls_Quantity_Period.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Period.def(py::init<const Standard_Integer>(), py::arg("ss"));
cls_Quantity_Period.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("ss"), py::arg("mics"));

// Fields

// Methods
// cls_Quantity_Period.def_static("operator new_", (void * (*)(size_t)) &Quantity_Period::operator new, "None", py::arg("theSize"));
// cls_Quantity_Period.def_static("operator delete_", (void (*)(void *)) &Quantity_Period::operator delete, "None", py::arg("theAddress"));
// cls_Quantity_Period.def_static("operator new[]_", (void * (*)(size_t)) &Quantity_Period::operator new[], "None", py::arg("theSize"));
// cls_Quantity_Period.def_static("operator delete[]_", (void (*)(void *)) &Quantity_Period::operator delete[], "None", py::arg("theAddress"));
// cls_Quantity_Period.def_static("operator new_", (void * (*)(size_t, void *)) &Quantity_Period::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Quantity_Period.def_static("operator delete_", (void (*)(void *, void *)) &Quantity_Period::operator delete, "None", py::arg(""), py::arg(""));
cls_Quantity_Period.def("Values", [](Quantity_Period &self, Standard_Integer & dd, Standard_Integer & hh, Standard_Integer & mn, Standard_Integer & ss, Standard_Integer & mis, Standard_Integer & mics){ self.Values(dd, hh, mn, ss, mis, mics); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(dd, hh, mn, ss, mis, mics); }, "Decomposes this period into a number of days,hours, minutes,seconds,milliseconds and microseconds Example of return values: 2 days, 15 hours, 0 minute , 0 second 0 millisecond and 0 microsecond", py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Period.def("Values", [](Quantity_Period &self, Standard_Integer & ss, Standard_Integer & mics){ self.Values(ss, mics); return std::tuple<Standard_Integer &, Standard_Integer &>(ss, mics); }, "Returns the number of seconds in Ss and the number of remainding microseconds in Mics of this period. Example of return values: 3600 seconds and 0 microseconds", py::arg("ss"), py::arg("mics"));
cls_Quantity_Period.def("SetValues", [](Quantity_Period &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3) -> void { return self.SetValues(a0, a1, a2, a3); });
cls_Quantity_Period.def("SetValues", [](Quantity_Period &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4) -> void { return self.SetValues(a0, a1, a2, a3, a4); });
cls_Quantity_Period.def("SetValues", (void (Quantity_Period::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Quantity_Period::SetValues, "Assigns to this period the time interval defined - with dd days, hh hours, mn minutes, ss seconds, mis (defaulted to 0) milliseconds and mics (defaulted to 0) microseconds; or", py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Period.def("SetValues", [](Quantity_Period &self, const Standard_Integer a0) -> void { return self.SetValues(a0); });
cls_Quantity_Period.def("SetValues", (void (Quantity_Period::*)(const Standard_Integer, const Standard_Integer)) &Quantity_Period::SetValues, "Assigns to this period the time interval defined - with Ss seconds and Mics (defaulted to 0) microseconds. Exceptions Quantity_PeriodDefinitionError: - if the number of seconds expressed either by: - dd days, hh hours, mn minutes and ss seconds, or - Ss is less than 0. - if the number of microseconds expressed either by: - mis milliseconds and mics microseconds, or - Mics is less than 0.", py::arg("ss"), py::arg("mics"));
cls_Quantity_Period.def("Subtract", (Quantity_Period (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::Subtract, "Subtracts one Period from another and returns the difference.", py::arg("anOther"));
cls_Quantity_Period.def("__sub__", (Quantity_Period (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::operator-, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Period.def("Add", (Quantity_Period (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::Add, "Adds one Period to another one.", py::arg("anOther"));
cls_Quantity_Period.def("__add__", (Quantity_Period (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::operator+, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Period.def("IsEqual", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::IsEqual, "Returns TRUE if both <me> and <other> are equal.", py::arg("anOther"));
cls_Quantity_Period.def("__eq__", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::operator==, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Period.def("IsShorter", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::IsShorter, "Returns TRUE if <me> is shorter than <other>.", py::arg("anOther"));
cls_Quantity_Period.def("__lt__", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::operator<, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Period.def("IsLonger", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::IsLonger, "Returns TRUE if <me> is longer then <other>.", py::arg("anOther"));
cls_Quantity_Period.def("__gt__", (Standard_Boolean (Quantity_Period::*)(const Quantity_Period &) const) &Quantity_Period::operator>, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Period.def_static("IsValid_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3) -> Standard_Boolean { return Quantity_Period::IsValid(a0, a1, a2, a3); });
cls_Quantity_Period.def_static("IsValid_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4) -> Standard_Boolean { return Quantity_Period::IsValid(a0, a1, a2, a3, a4); });
cls_Quantity_Period.def_static("IsValid_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Quantity_Period::IsValid, "Checks the validity of a Period in form (dd,hh,mn,ss,mil,mic) With: 0 <= dd 0 <= hh 0 <= mn 0 <= ss 0 <= mis 0 <= mics", py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Period.def_static("IsValid_", [](const Standard_Integer a0) -> Standard_Boolean { return Quantity_Period::IsValid(a0); });
cls_Quantity_Period.def_static("IsValid_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &Quantity_Period::IsValid, "Checks the validity of a Period in form (ss,mic) With: 0 <= ss 0 <= mics", py::arg("ss"), py::arg("mics"));

// Enums

}