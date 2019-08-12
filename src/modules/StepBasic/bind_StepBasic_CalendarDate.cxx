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
#include <StepBasic_Date.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_CalendarDate.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_CalendarDate(py::module &mod){

py::class_<StepBasic_CalendarDate, opencascade::handle<StepBasic_CalendarDate>, StepBasic_Date> cls_StepBasic_CalendarDate(mod, "StepBasic_CalendarDate", "None");

// Constructors
cls_StepBasic_CalendarDate.def(py::init<>());

// Fields

// Methods
cls_StepBasic_CalendarDate.def("Init", (void (StepBasic_CalendarDate::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &StepBasic_CalendarDate::Init, "None", py::arg("aYearComponent"), py::arg("aDayComponent"), py::arg("aMonthComponent"));
cls_StepBasic_CalendarDate.def("SetDayComponent", (void (StepBasic_CalendarDate::*)(const Standard_Integer)) &StepBasic_CalendarDate::SetDayComponent, "None", py::arg("aDayComponent"));
cls_StepBasic_CalendarDate.def("DayComponent", (Standard_Integer (StepBasic_CalendarDate::*)() const) &StepBasic_CalendarDate::DayComponent, "None");
cls_StepBasic_CalendarDate.def("SetMonthComponent", (void (StepBasic_CalendarDate::*)(const Standard_Integer)) &StepBasic_CalendarDate::SetMonthComponent, "None", py::arg("aMonthComponent"));
cls_StepBasic_CalendarDate.def("MonthComponent", (Standard_Integer (StepBasic_CalendarDate::*)() const) &StepBasic_CalendarDate::MonthComponent, "None");
cls_StepBasic_CalendarDate.def_static("get_type_name_", (const char * (*)()) &StepBasic_CalendarDate::get_type_name, "None");
cls_StepBasic_CalendarDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CalendarDate::get_type_descriptor, "None");
cls_StepBasic_CalendarDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CalendarDate::*)() const) &StepBasic_CalendarDate::DynamicType, "None");

// Enums

}