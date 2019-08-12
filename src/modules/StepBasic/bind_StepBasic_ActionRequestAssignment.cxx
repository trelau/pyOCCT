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
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepBasic_ActionRequestAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ActionRequestAssignment(py::module &mod){

py::class_<StepBasic_ActionRequestAssignment, opencascade::handle<StepBasic_ActionRequestAssignment>, Standard_Transient> cls_StepBasic_ActionRequestAssignment(mod, "StepBasic_ActionRequestAssignment", "Representation of STEP entity ActionRequestAssignment");

// Constructors
cls_StepBasic_ActionRequestAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ActionRequestAssignment.def("Init", (void (StepBasic_ActionRequestAssignment::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedActionRequest"));
cls_StepBasic_ActionRequestAssignment.def("AssignedActionRequest", (opencascade::handle<StepBasic_VersionedActionRequest> (StepBasic_ActionRequestAssignment::*)() const) &StepBasic_ActionRequestAssignment::AssignedActionRequest, "Returns field AssignedActionRequest");
cls_StepBasic_ActionRequestAssignment.def("SetAssignedActionRequest", (void (StepBasic_ActionRequestAssignment::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &)) &StepBasic_ActionRequestAssignment::SetAssignedActionRequest, "Set field AssignedActionRequest", py::arg("AssignedActionRequest"));
cls_StepBasic_ActionRequestAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ActionRequestAssignment::get_type_name, "None");
cls_StepBasic_ActionRequestAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ActionRequestAssignment::get_type_descriptor, "None");
cls_StepBasic_ActionRequestAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ActionRequestAssignment::*)() const) &StepBasic_ActionRequestAssignment::DynamicType, "None");

// Enums

}