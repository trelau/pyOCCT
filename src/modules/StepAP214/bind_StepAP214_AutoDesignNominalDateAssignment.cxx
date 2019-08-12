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
#include <StepBasic_DateAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Date.hxx>
#include <StepBasic_DateRole.hxx>
#include <StepAP214_HArray1OfAutoDesignDatedItem.hxx>
#include <StepAP214_AutoDesignDatedItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignNominalDateAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignNominalDateAssignment(py::module &mod){

py::class_<StepAP214_AutoDesignNominalDateAssignment, opencascade::handle<StepAP214_AutoDesignNominalDateAssignment>, StepBasic_DateAssignment> cls_StepAP214_AutoDesignNominalDateAssignment(mod, "StepAP214_AutoDesignNominalDateAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignNominalDateAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignNominalDateAssignment.def("Init", (void (StepAP214_AutoDesignNominalDateAssignment::*)(const opencascade::handle<StepBasic_Date> &, const opencascade::handle<StepBasic_DateRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignNominalDateAssignment::Init, "None", py::arg("aAssignedDate"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("SetItems", (void (StepAP214_AutoDesignNominalDateAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> &)) &StepAP214_AutoDesignNominalDateAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDatedItem> (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::Items, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def("ItemsValue", (StepAP214_AutoDesignDatedItem (StepAP214_AutoDesignNominalDateAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignNominalDateAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignNominalDateAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::NbItems, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignNominalDateAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignNominalDateAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignNominalDateAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignNominalDateAssignment::*)() const) &StepAP214_AutoDesignNominalDateAssignment::DynamicType, "None");

// Enums

}