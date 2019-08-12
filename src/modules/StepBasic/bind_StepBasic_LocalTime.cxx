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
#include <StepBasic_CoordinatedUniversalTimeOffset.hxx>
#include <StepBasic_LocalTime.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_LocalTime(py::module &mod){

py::class_<StepBasic_LocalTime, opencascade::handle<StepBasic_LocalTime>, Standard_Transient> cls_StepBasic_LocalTime(mod, "StepBasic_LocalTime", "None");

// Constructors
cls_StepBasic_LocalTime.def(py::init<>());

// Fields

// Methods
cls_StepBasic_LocalTime.def("Init", (void (StepBasic_LocalTime::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, const Standard_Boolean, const Standard_Real, const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &)) &StepBasic_LocalTime::Init, "None", py::arg("aHourComponent"), py::arg("hasAminuteComponent"), py::arg("aMinuteComponent"), py::arg("hasAsecondComponent"), py::arg("aSecondComponent"), py::arg("aZone"));
cls_StepBasic_LocalTime.def("SetHourComponent", (void (StepBasic_LocalTime::*)(const Standard_Integer)) &StepBasic_LocalTime::SetHourComponent, "None", py::arg("aHourComponent"));
cls_StepBasic_LocalTime.def("HourComponent", (Standard_Integer (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::HourComponent, "None");
cls_StepBasic_LocalTime.def("SetMinuteComponent", (void (StepBasic_LocalTime::*)(const Standard_Integer)) &StepBasic_LocalTime::SetMinuteComponent, "None", py::arg("aMinuteComponent"));
cls_StepBasic_LocalTime.def("UnSetMinuteComponent", (void (StepBasic_LocalTime::*)()) &StepBasic_LocalTime::UnSetMinuteComponent, "None");
cls_StepBasic_LocalTime.def("MinuteComponent", (Standard_Integer (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::MinuteComponent, "None");
cls_StepBasic_LocalTime.def("HasMinuteComponent", (Standard_Boolean (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::HasMinuteComponent, "None");
cls_StepBasic_LocalTime.def("SetSecondComponent", (void (StepBasic_LocalTime::*)(const Standard_Real)) &StepBasic_LocalTime::SetSecondComponent, "None", py::arg("aSecondComponent"));
cls_StepBasic_LocalTime.def("UnSetSecondComponent", (void (StepBasic_LocalTime::*)()) &StepBasic_LocalTime::UnSetSecondComponent, "None");
cls_StepBasic_LocalTime.def("SecondComponent", (Standard_Real (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::SecondComponent, "None");
cls_StepBasic_LocalTime.def("HasSecondComponent", (Standard_Boolean (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::HasSecondComponent, "None");
cls_StepBasic_LocalTime.def("SetZone", (void (StepBasic_LocalTime::*)(const opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> &)) &StepBasic_LocalTime::SetZone, "None", py::arg("aZone"));
cls_StepBasic_LocalTime.def("Zone", (opencascade::handle<StepBasic_CoordinatedUniversalTimeOffset> (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::Zone, "None");
cls_StepBasic_LocalTime.def_static("get_type_name_", (const char * (*)()) &StepBasic_LocalTime::get_type_name, "None");
cls_StepBasic_LocalTime.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_LocalTime::get_type_descriptor, "None");
cls_StepBasic_LocalTime.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_LocalTime::*)() const) &StepBasic_LocalTime::DynamicType, "None");

// Enums

}