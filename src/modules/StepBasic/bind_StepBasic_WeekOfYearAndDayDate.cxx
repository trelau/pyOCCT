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
#include <StepBasic_WeekOfYearAndDayDate.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_WeekOfYearAndDayDate(py::module &mod){

py::class_<StepBasic_WeekOfYearAndDayDate, opencascade::handle<StepBasic_WeekOfYearAndDayDate>, StepBasic_Date> cls_StepBasic_WeekOfYearAndDayDate(mod, "StepBasic_WeekOfYearAndDayDate", "None");

// Constructors
cls_StepBasic_WeekOfYearAndDayDate.def(py::init<>());

// Fields

// Methods
cls_StepBasic_WeekOfYearAndDayDate.def("Init", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::Init, "None", py::arg("aYearComponent"), py::arg("aWeekComponent"), py::arg("hasAdayComponent"), py::arg("aDayComponent"));
cls_StepBasic_WeekOfYearAndDayDate.def("SetWeekComponent", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::SetWeekComponent, "None", py::arg("aWeekComponent"));
cls_StepBasic_WeekOfYearAndDayDate.def("WeekComponent", (Standard_Integer (StepBasic_WeekOfYearAndDayDate::*)() const) &StepBasic_WeekOfYearAndDayDate::WeekComponent, "None");
cls_StepBasic_WeekOfYearAndDayDate.def("SetDayComponent", (void (StepBasic_WeekOfYearAndDayDate::*)(const Standard_Integer)) &StepBasic_WeekOfYearAndDayDate::SetDayComponent, "None", py::arg("aDayComponent"));
cls_StepBasic_WeekOfYearAndDayDate.def("UnSetDayComponent", (void (StepBasic_WeekOfYearAndDayDate::*)()) &StepBasic_WeekOfYearAndDayDate::UnSetDayComponent, "None");
cls_StepBasic_WeekOfYearAndDayDate.def("DayComponent", (Standard_Integer (StepBasic_WeekOfYearAndDayDate::*)() const) &StepBasic_WeekOfYearAndDayDate::DayComponent, "None");
cls_StepBasic_WeekOfYearAndDayDate.def("HasDayComponent", (Standard_Boolean (StepBasic_WeekOfYearAndDayDate::*)() const) &StepBasic_WeekOfYearAndDayDate::HasDayComponent, "None");
cls_StepBasic_WeekOfYearAndDayDate.def_static("get_type_name_", (const char * (*)()) &StepBasic_WeekOfYearAndDayDate::get_type_name, "None");
cls_StepBasic_WeekOfYearAndDayDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_WeekOfYearAndDayDate::get_type_descriptor, "None");
cls_StepBasic_WeekOfYearAndDayDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_WeekOfYearAndDayDate::*)() const) &StepBasic_WeekOfYearAndDayDate::DynamicType, "None");

// Enums

}