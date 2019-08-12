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
#include <StepBasic_ApprovalStatus.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_Approval.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Approval(py::module &mod){

py::class_<StepBasic_Approval, opencascade::handle<StepBasic_Approval>, Standard_Transient> cls_StepBasic_Approval(mod, "StepBasic_Approval", "None");

// Constructors
cls_StepBasic_Approval.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Approval.def("Init", (void (StepBasic_Approval::*)(const opencascade::handle<StepBasic_ApprovalStatus> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Approval::Init, "None", py::arg("aStatus"), py::arg("aLevel"));
cls_StepBasic_Approval.def("SetStatus", (void (StepBasic_Approval::*)(const opencascade::handle<StepBasic_ApprovalStatus> &)) &StepBasic_Approval::SetStatus, "None", py::arg("aStatus"));
cls_StepBasic_Approval.def("Status", (opencascade::handle<StepBasic_ApprovalStatus> (StepBasic_Approval::*)() const) &StepBasic_Approval::Status, "None");
cls_StepBasic_Approval.def("SetLevel", (void (StepBasic_Approval::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Approval::SetLevel, "None", py::arg("aLevel"));
cls_StepBasic_Approval.def("Level", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Approval::*)() const) &StepBasic_Approval::Level, "None");
cls_StepBasic_Approval.def_static("get_type_name_", (const char * (*)()) &StepBasic_Approval::get_type_name, "None");
cls_StepBasic_Approval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Approval::get_type_descriptor, "None");
cls_StepBasic_Approval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Approval::*)() const) &StepBasic_Approval::DynamicType, "None");

// Enums

}