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
#include <Quantity_Date.hxx>

void bind_Quantity_Date(py::module &mod){

py::class_<Quantity_Date> cls_Quantity_Date(mod, "Quantity_Date", "This class provides services to manage date information. A date represents the following time intervals: year, month, day, hour, minute, second, millisecond and microsecond. Current time is expressed in elapsed seconds and microseconds beginning from 00:00 GMT, January 1, 1979 (zero hour). The valid date can only be later than this one. Note: a Period object gives the interval between two dates.");

// Constructors
cls_Quantity_Date.def(py::init<>());
cls_Quantity_Date.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("mm"), py::arg("dd"), py::arg("yyyy"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_Quantity_Date.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("mm"), py::arg("dd"), py::arg("yyyy"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"));
cls_Quantity_Date.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("mm"), py::arg("dd"), py::arg("yyyy"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));

// Fields

// Methods
// cls_Quantity_Date.def_static("operator new_", (void * (*)(size_t)) &Quantity_Date::operator new, "None", py::arg("theSize"));
// cls_Quantity_Date.def_static("operator delete_", (void (*)(void *)) &Quantity_Date::operator delete, "None", py::arg("theAddress"));
// cls_Quantity_Date.def_static("operator new[]_", (void * (*)(size_t)) &Quantity_Date::operator new[], "None", py::arg("theSize"));
// cls_Quantity_Date.def_static("operator delete[]_", (void (*)(void *)) &Quantity_Date::operator delete[], "None", py::arg("theAddress"));
// cls_Quantity_Date.def_static("operator new_", (void * (*)(size_t, void *)) &Quantity_Date::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Quantity_Date.def_static("operator delete_", (void (*)(void *, void *)) &Quantity_Date::operator delete, "None", py::arg(""), py::arg(""));
cls_Quantity_Date.def("Values", [](Quantity_Date &self, Standard_Integer & mm, Standard_Integer & dd, Standard_Integer & yy, Standard_Integer & hh, Standard_Integer & mn, Standard_Integer & ss, Standard_Integer & mis, Standard_Integer & mics){ self.Values(mm, dd, yy, hh, mn, ss, mis, mics); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(mm, dd, yy, hh, mn, ss, mis, mics); }, "Gets a complete Date. - in mm - the month, - in dd - the day, - in yyyy - the year, - in hh - the hour, - in mn - the minute, - in ss - the second, - in mis - the millisecond, and - in mics - the microsecond", py::arg("mm"), py::arg("dd"), py::arg("yy"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Date.def("SetValues", [](Quantity_Date &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> void { return self.SetValues(a0, a1, a2, a3, a4, a5); });
cls_Quantity_Date.def("SetValues", [](Quantity_Date &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Integer a6) -> void { return self.SetValues(a0, a1, a2, a3, a4, a5, a6); });
cls_Quantity_Date.def("SetValues", (void (Quantity_Date::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Quantity_Date::SetValues, "Assigns to this date the year yyyy, the month mm, the day dd, the hour hh, the minute mn, the second ss, the millisecond mis (defaulted to 0) and the microsecond mics (defaulted to 0). Exceptions Quantity_DateDefinitionError if mm, dd, hh, mn, ss, mis and mics are not components of a valid date.", py::arg("mm"), py::arg("dd"), py::arg("yy"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Date.def("Difference", (Quantity_Period (Quantity_Date::*)(const Quantity_Date &)) &Quantity_Date::Difference, "Subtracts one Date from another one to find the period between and returns the value. The result is the absolute value between the difference of two dates.", py::arg("anOther"));
cls_Quantity_Date.def("Subtract", (Quantity_Date (Quantity_Date::*)(const Quantity_Period &)) &Quantity_Date::Subtract, "Subtracts a period from a Date and returns the new Date. Raises an exception if the result date is anterior to Jan 1, 1979.", py::arg("aPeriod"));
cls_Quantity_Date.def("__sub__", (Quantity_Date (Quantity_Date::*)(const Quantity_Period &)) &Quantity_Date::operator-, py::is_operator(), "None", py::arg("aPeriod"));
cls_Quantity_Date.def("Add", (Quantity_Date (Quantity_Date::*)(const Quantity_Period &)) &Quantity_Date::Add, "Adds a Period to a Date and returns the new Date.", py::arg("aPeriod"));
cls_Quantity_Date.def("__add__", (Quantity_Date (Quantity_Date::*)(const Quantity_Period &)) &Quantity_Date::operator+, py::is_operator(), "None", py::arg("aPeriod"));
cls_Quantity_Date.def("Year", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Year, "Returns year of a Date.");
cls_Quantity_Date.def("Month", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Month, "Returns month of a Date.");
cls_Quantity_Date.def("Day", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Day, "Returns Day of a Date.");
cls_Quantity_Date.def("Hour", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Hour, "Returns Hour of a Date.");
cls_Quantity_Date.def("Minute", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Minute, "Returns minute of a Date.");
cls_Quantity_Date.def("Second", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::Second, "Returns seconde of a Date.");
cls_Quantity_Date.def("MilliSecond", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::MilliSecond, "Returns millisecond of a Date.");
cls_Quantity_Date.def("MicroSecond", (Standard_Integer (Quantity_Date::*)()) &Quantity_Date::MicroSecond, "Returns microsecond of a Date.");
cls_Quantity_Date.def("IsEqual", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::IsEqual, "Returns TRUE if both <me> and <other> are equal. This method is an alias of operator ==.", py::arg("anOther"));
cls_Quantity_Date.def("__eq__", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::operator==, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Date.def("IsEarlier", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::IsEarlier, "Returns TRUE if <me> is earlier than <other>.", py::arg("anOther"));
cls_Quantity_Date.def("__lt__", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::operator<, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Date.def("IsLater", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::IsLater, "Returns TRUE if <me> is later then <other>.", py::arg("anOther"));
cls_Quantity_Date.def("__gt__", (Standard_Boolean (Quantity_Date::*)(const Quantity_Date &) const) &Quantity_Date::operator>, py::is_operator(), "None", py::arg("anOther"));
cls_Quantity_Date.def_static("IsValid_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> Standard_Boolean { return Quantity_Date::IsValid(a0, a1, a2, a3, a4, a5); });
cls_Quantity_Date.def_static("IsValid_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Integer a6) -> Standard_Boolean { return Quantity_Date::IsValid(a0, a1, a2, a3, a4, a5, a6); });
cls_Quantity_Date.def_static("IsValid_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Quantity_Date::IsValid, "Checks the validity of a date - returns true if a date defined from the year yyyy, the month mm, the day dd, the hour hh, the minute mn, the second ss, the millisecond mis (defaulted to 0) and the microsecond mics (defaulted to 0) is valid. A date must satisfy the conditions above: - yyyy is greater than or equal to 1979, - mm lies within the range [1, 12] (with 1 corresponding to January and 12 to December), - dd lies within a valid range for the month mm (from 1 to 28, 29, 30 or 31 depending on mm and whether yyyy is a leap year or not), - hh lies within the range [0, 23], - mn lies within the range [0, 59], - ss lies within the range [0, 59], - mis lies within the range [0, 999], - mics lies within the range [0, 999].C", py::arg("mm"), py::arg("dd"), py::arg("yy"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("mis"), py::arg("mics"));
cls_Quantity_Date.def_static("IsLeap_", (Standard_Boolean (*)(const Standard_Integer)) &Quantity_Date::IsLeap, "Returns true if a year is a leap year. The leap years are divisable by 4 and not by 100 except the years divisable by 400.", py::arg("yy"));

// Enums

}