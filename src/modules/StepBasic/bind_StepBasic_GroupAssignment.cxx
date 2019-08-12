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
#include <StepBasic_Group.hxx>
#include <StepBasic_GroupAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_GroupAssignment(py::module &mod){

py::class_<StepBasic_GroupAssignment, opencascade::handle<StepBasic_GroupAssignment>, Standard_Transient> cls_StepBasic_GroupAssignment(mod, "StepBasic_GroupAssignment", "Representation of STEP entity GroupAssignment");

// Constructors
cls_StepBasic_GroupAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_GroupAssignment.def("Init", (void (StepBasic_GroupAssignment::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedGroup"));
cls_StepBasic_GroupAssignment.def("AssignedGroup", (opencascade::handle<StepBasic_Group> (StepBasic_GroupAssignment::*)() const) &StepBasic_GroupAssignment::AssignedGroup, "Returns field AssignedGroup");
cls_StepBasic_GroupAssignment.def("SetAssignedGroup", (void (StepBasic_GroupAssignment::*)(const opencascade::handle<StepBasic_Group> &)) &StepBasic_GroupAssignment::SetAssignedGroup, "Set field AssignedGroup", py::arg("AssignedGroup"));
cls_StepBasic_GroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_GroupAssignment::get_type_name, "None");
cls_StepBasic_GroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_GroupAssignment::get_type_descriptor, "None");
cls_StepBasic_GroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_GroupAssignment::*)() const) &StepBasic_GroupAssignment::DynamicType, "None");

// Enums

}