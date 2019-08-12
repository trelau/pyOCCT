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
#include <StepAP214_HArray1OfAutoDesignDateAndPersonItem.hxx>
#include <StepAP214_AutoDesignDateAndPersonItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignDateAndPersonAssignment(py::module &mod){

py::class_<StepAP214_AutoDesignDateAndPersonAssignment, opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP214_AutoDesignDateAndPersonAssignment(mod, "StepAP214_AutoDesignDateAndPersonAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignDateAndPersonAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("Init", (void (StepAP214_AutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> &)) &StepAP214_AutoDesignDateAndPersonAssignment::Init, "None", py::arg("aAssignedPersonAndOrganization"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("SetItems", (void (StepAP214_AutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> &)) &StepAP214_AutoDesignDateAndPersonAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndPersonItem> (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::Items, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("ItemsValue", (StepAP214_AutoDesignDateAndPersonItem (StepAP214_AutoDesignDateAndPersonAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignDateAndPersonAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::NbItems, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignDateAndPersonAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignDateAndPersonAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignDateAndPersonAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignDateAndPersonAssignment::*)() const) &StepAP214_AutoDesignDateAndPersonAssignment::DynamicType, "None");

// Enums

}