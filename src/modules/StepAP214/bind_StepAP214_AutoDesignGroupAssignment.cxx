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
#include <StepAP214_HArray1OfAutoDesignGroupedItem.hxx>
#include <StepAP214_AutoDesignGroupedItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignGroupAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignGroupAssignment(py::module &mod){

py::class_<StepAP214_AutoDesignGroupAssignment, opencascade::handle<StepAP214_AutoDesignGroupAssignment>, StepBasic_GroupAssignment> cls_StepAP214_AutoDesignGroupAssignment(mod, "StepAP214_AutoDesignGroupAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignGroupAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignGroupAssignment.def("Init", (void (StepAP214_AutoDesignGroupAssignment::*)(const opencascade::handle<StepBasic_Group> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> &)) &StepAP214_AutoDesignGroupAssignment::Init, "None", py::arg("aAssignedGroup"), py::arg("aItems"));
cls_StepAP214_AutoDesignGroupAssignment.def("SetItems", (void (StepAP214_AutoDesignGroupAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> &)) &StepAP214_AutoDesignGroupAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignGroupAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignGroupedItem> (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::Items, "None");
cls_StepAP214_AutoDesignGroupAssignment.def("ItemsValue", (StepAP214_AutoDesignGroupedItem (StepAP214_AutoDesignGroupAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignGroupAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignGroupAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::NbItems, "None");
cls_StepAP214_AutoDesignGroupAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignGroupAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignGroupAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignGroupAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignGroupAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignGroupAssignment::*)() const) &StepAP214_AutoDesignGroupAssignment::DynamicType, "None");

// Enums

}