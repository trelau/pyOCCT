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
#include <StepBasic_GroupAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Group.hxx>
#include <StepAP214_HArray1OfGroupItem.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedGroupAssignment(py::module &mod){

py::class_<StepAP214_AppliedGroupAssignment, opencascade::handle<StepAP214_AppliedGroupAssignment>, StepBasic_GroupAssignment> cls_StepAP214_AppliedGroupAssignment(mod, "StepAP214_AppliedGroupAssignment", "Representation of STEP entity AppliedGroupAssignment");

// Constructors
cls_StepAP214_AppliedGroupAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedGroupAssignment.def("Init", (void (StepAP214_AppliedGroupAssignment::*)(const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepAP214_HArray1OfGroupItem> &)) &StepAP214_AppliedGroupAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aGroupAssignment_AssignedGroup"), py::arg("aItems"));
cls_StepAP214_AppliedGroupAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfGroupItem> (StepAP214_AppliedGroupAssignment::*)() const) &StepAP214_AppliedGroupAssignment::Items, "Returns field Items");
cls_StepAP214_AppliedGroupAssignment.def("SetItems", (void (StepAP214_AppliedGroupAssignment::*)(const opencascade::handle<StepAP214_HArray1OfGroupItem> &)) &StepAP214_AppliedGroupAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP214_AppliedGroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedGroupAssignment::get_type_name, "None");
cls_StepAP214_AppliedGroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedGroupAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedGroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedGroupAssignment::*)() const) &StepAP214_AppliedGroupAssignment::DynamicType, "None");

// Enums

}