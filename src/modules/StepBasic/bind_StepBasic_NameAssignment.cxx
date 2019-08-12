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
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_NameAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_NameAssignment(py::module &mod){

py::class_<StepBasic_NameAssignment, opencascade::handle<StepBasic_NameAssignment>, Standard_Transient> cls_StepBasic_NameAssignment(mod, "StepBasic_NameAssignment", "Representation of STEP entity NameAssignment");

// Constructors
cls_StepBasic_NameAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_NameAssignment.def("Init", (void (StepBasic_NameAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_NameAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedName"));
cls_StepBasic_NameAssignment.def("AssignedName", (opencascade::handle<TCollection_HAsciiString> (StepBasic_NameAssignment::*)() const) &StepBasic_NameAssignment::AssignedName, "Returns field AssignedName");
cls_StepBasic_NameAssignment.def("SetAssignedName", (void (StepBasic_NameAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_NameAssignment::SetAssignedName, "Set field AssignedName", py::arg("AssignedName"));
cls_StepBasic_NameAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_NameAssignment::get_type_name, "None");
cls_StepBasic_NameAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_NameAssignment::get_type_descriptor, "None");
cls_StepBasic_NameAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_NameAssignment::*)() const) &StepBasic_NameAssignment::DynamicType, "None");

// Enums

}