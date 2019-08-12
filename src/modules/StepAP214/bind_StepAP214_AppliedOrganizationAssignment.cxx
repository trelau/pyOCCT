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
#include <StepBasic_OrganizationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_OrganizationRole.hxx>
#include <StepAP214_HArray1OfOrganizationItem.hxx>
#include <StepAP214_OrganizationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AppliedOrganizationAssignment(py::module &mod){

py::class_<StepAP214_AppliedOrganizationAssignment, opencascade::handle<StepAP214_AppliedOrganizationAssignment>, StepBasic_OrganizationAssignment> cls_StepAP214_AppliedOrganizationAssignment(mod, "StepAP214_AppliedOrganizationAssignment", "None");

// Constructors
cls_StepAP214_AppliedOrganizationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AppliedOrganizationAssignment.def("Init", (void (StepAP214_AppliedOrganizationAssignment::*)(const opencascade::handle<StepBasic_Organization> &, const opencascade::handle<StepBasic_OrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfOrganizationItem> &)) &StepAP214_AppliedOrganizationAssignment::Init, "None", py::arg("aAssignedOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AppliedOrganizationAssignment.def("SetItems", (void (StepAP214_AppliedOrganizationAssignment::*)(const opencascade::handle<StepAP214_HArray1OfOrganizationItem> &)) &StepAP214_AppliedOrganizationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AppliedOrganizationAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfOrganizationItem> (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::Items, "None");
cls_StepAP214_AppliedOrganizationAssignment.def("ItemsValue", (StepAP214_OrganizationItem (StepAP214_AppliedOrganizationAssignment::*)(const Standard_Integer) const) &StepAP214_AppliedOrganizationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AppliedOrganizationAssignment.def("NbItems", (Standard_Integer (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::NbItems, "None");
cls_StepAP214_AppliedOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AppliedOrganizationAssignment::get_type_name, "None");
cls_StepAP214_AppliedOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AppliedOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP214_AppliedOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AppliedOrganizationAssignment::*)() const) &StepAP214_AppliedOrganizationAssignment::DynamicType, "None");

// Enums

}