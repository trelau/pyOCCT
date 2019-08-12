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
#include <StepBasic_Contract.hxx>
#include <StepBasic_ContractAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ContractAssignment(py::module &mod){

py::class_<StepBasic_ContractAssignment, opencascade::handle<StepBasic_ContractAssignment>, Standard_Transient> cls_StepBasic_ContractAssignment(mod, "StepBasic_ContractAssignment", "Representation of STEP entity ContractAssignment");

// Constructors
cls_StepBasic_ContractAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ContractAssignment.def("Init", (void (StepBasic_ContractAssignment::*)(const opencascade::handle<StepBasic_Contract> &)) &StepBasic_ContractAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedContract"));
cls_StepBasic_ContractAssignment.def("AssignedContract", (opencascade::handle<StepBasic_Contract> (StepBasic_ContractAssignment::*)() const) &StepBasic_ContractAssignment::AssignedContract, "Returns field AssignedContract");
cls_StepBasic_ContractAssignment.def("SetAssignedContract", (void (StepBasic_ContractAssignment::*)(const opencascade::handle<StepBasic_Contract> &)) &StepBasic_ContractAssignment::SetAssignedContract, "Set field AssignedContract", py::arg("AssignedContract"));
cls_StepBasic_ContractAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ContractAssignment::get_type_name, "None");
cls_StepBasic_ContractAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ContractAssignment::get_type_descriptor, "None");
cls_StepBasic_ContractAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ContractAssignment::*)() const) &StepBasic_ContractAssignment::DynamicType, "None");

// Enums

}