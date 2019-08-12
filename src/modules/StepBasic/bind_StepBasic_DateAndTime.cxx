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
#include <Standard_Handle.hxx>
#include <StepBasic_Date.hxx>
#include <StepBasic_LocalTime.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DateAndTime(py::module &mod){

py::class_<StepBasic_DateAndTime, opencascade::handle<StepBasic_DateAndTime>, Standard_Transient> cls_StepBasic_DateAndTime(mod, "StepBasic_DateAndTime", "None");

// Constructors
cls_StepBasic_DateAndTime.def(py::init<>());

// Fields

// Methods
cls_StepBasic_DateAndTime.def("Init", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_LocalTime> &)) &StepBasic_DateAndTime::Init, "None", py::arg("aDateComponent"), py::arg("aTimeComponent"));
cls_StepBasic_DateAndTime.def("SetDateComponent", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_Date> &)) &StepBasic_DateAndTime::SetDateComponent, "None", py::arg("aDateComponent"));
cls_StepBasic_DateAndTime.def("DateComponent", (opencascade::handle<StepBasic_Date> (StepBasic_DateAndTime::*)() const) &StepBasic_DateAndTime::DateComponent, "None");
cls_StepBasic_DateAndTime.def("SetTimeComponent", (void (StepBasic_DateAndTime::*)(const opencascade::handle<StepBasic_LocalTime> &)) &StepBasic_DateAndTime::SetTimeComponent, "None", py::arg("aTimeComponent"));
cls_StepBasic_DateAndTime.def("TimeComponent", (opencascade::handle<StepBasic_LocalTime> (StepBasic_DateAndTime::*)() const) &StepBasic_DateAndTime::TimeComponent, "None");
cls_StepBasic_DateAndTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAndTime::get_type_name, "None");
cls_StepBasic_DateAndTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAndTime::get_type_descriptor, "None");
cls_StepBasic_DateAndTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAndTime::*)() const) &StepBasic_DateAndTime::DynamicType, "None");

// Enums

}