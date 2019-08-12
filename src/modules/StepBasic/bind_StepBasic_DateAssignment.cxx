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
#include <StepBasic_DateRole.hxx>
#include <StepBasic_DateAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_DateAssignment(py::module &mod){

py::class_<StepBasic_DateAssignment, opencascade::handle<StepBasic_DateAssignment>, Standard_Transient> cls_StepBasic_DateAssignment(mod, "StepBasic_DateAssignment", "None");

// Constructors

// Fields

// Methods
cls_StepBasic_DateAssignment.def("Init", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &)) &StepBasic_DateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"));
cls_StepBasic_DateAssignment.def("SetAssignedDate", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_Date> &)) &StepBasic_DateAssignment::SetAssignedDate, "None", py::arg("aAssignedDate"));
cls_StepBasic_DateAssignment.def("AssignedDate", (opencascade::handle<StepBasic_Date> (StepBasic_DateAssignment::*)() const) &StepBasic_DateAssignment::AssignedDate, "None");
cls_StepBasic_DateAssignment.def("SetRole", (void (StepBasic_DateAssignment::*)(const opencascade::handle<StepBasic_DateRole> &)) &StepBasic_DateAssignment::SetRole, "None", py::arg("aRole"));
cls_StepBasic_DateAssignment.def("Role", (opencascade::handle<StepBasic_DateRole> (StepBasic_DateAssignment::*)() const) &StepBasic_DateAssignment::Role, "None");
cls_StepBasic_DateAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_DateAssignment::get_type_name, "None");
cls_StepBasic_DateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_DateAssignment::get_type_descriptor, "None");
cls_StepBasic_DateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_DateAssignment::*)() const) &StepBasic_DateAssignment::DynamicType, "None");

// Enums

}