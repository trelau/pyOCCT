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
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DateAndTimeAssignment(py::module &mod){

py::class_<StepBasic_DateAndTimeAssignment, opencascade::handle<StepBasic_DateAndTimeAssignment>, Standard_Transient> cls_StepBasic_DateAndTimeAssignment(mod, "StepBasic_DateAndTimeAssignment", "None");

// Constructors

// Fields

// Methods
cls_StepBasic_DateAndTimeAssignment.def("Init", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &)) &StepBasic_DateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"));
cls_StepBasic_DateAndTimeAssignment.def("SetAssignedDateAndTime", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &)) &StepBasic_DateAndTimeAssignment::SetAssignedDateAndTime, "None", py::arg("aAssignedDateAndTime"));
cls_StepBasic_DateAndTimeAssignment.def("AssignedDateAndTime", (opencascade::handle<StepBasic_DateAndTime> (StepBasic_DateAndTimeAssignment::*)() const) &StepBasic_DateAndTimeAssignment::AssignedDateAndTime, "None");
cls_StepBasic_DateAndTimeAssignment.def("SetRole", (void (StepBasic_DateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateTimeRole> &)) &StepBasic_DateAndTimeAssignment::SetRole, "None", py::arg("aRole"));
cls_StepBasic_DateAndTimeAssignment.def("Role", (opencascade::handle<StepBasic_DateTimeRole> (StepBasic_DateAndTimeAssignment::*)() const) &StepBasic_DateAndTimeAssignment::Role, "None");
cls_StepBasic_DateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAndTimeAssignment::get_type_name, "None");
cls_StepBasic_DateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAndTimeAssignment::get_type_descriptor, "None");
cls_StepBasic_DateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAndTimeAssignment::*)() const) &StepBasic_DateAndTimeAssignment::DynamicType, "None");

// Enums

}