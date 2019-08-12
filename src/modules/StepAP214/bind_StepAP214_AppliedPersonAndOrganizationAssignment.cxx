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
#include <StepBasic_PersonAndOrganizationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepAP214_HArray1OfPersonAndOrganizationItem.hxx>
#include <StepAP214_PersonAndOrganizationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedPersonAndOrganizationAssignment(py::module &mod){

py::class_<StepAP214_AppliedPersonAndOrganizationAssignment, opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP214_AppliedPersonAndOrganizationAssignment(mod, "StepAP214_AppliedPersonAndOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("Init", (void (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> &)) &StepAP214_AppliedPersonAndOrganizationAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("SetItems", (void (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> &)) &StepAP214_AppliedPersonAndOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfPersonAndOrganizationItem> (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::Items, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("ItemsValue", (StepAP214_PersonAndOrganizationItem (StepAP214_AppliedPersonAndOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedPersonAndOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::NbItems, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedPersonAndOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedPersonAndOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedPersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedPersonAndOrganizationAssignment::*)() const) &StepAP214_AppliedPersonAndOrganizationAssignment::DynamicType, "None");

// Enums

}