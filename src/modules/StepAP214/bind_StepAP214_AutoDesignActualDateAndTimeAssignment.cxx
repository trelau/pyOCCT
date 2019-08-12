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
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepAP214_HArray1OfAutoDesignDateAndTimeItem.hxx>
#include <StepAP214_AutoDesignDateAndTimeItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignActualDateAndTimeAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignActualDateAndTimeAssignment(py::module &mod){

py::class_<StepAP214_AutoDesignActualDateAndTimeAssignment, opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP214_AutoDesignActualDateAndTimeAssignment(mod, "StepAP214_AutoDesignActualDateAndTimeAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("Init", (void (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignActualDateAndTimeAssignment::Init, "None", py::arg("aAssignedDateAndTime"), py::arg("aRole"), py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("SetItems", (void (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> &)) &StepAP214_AutoDesignActualDateAndTimeAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignDateAndTimeItem> (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::Items, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("ItemsValue", (StepAP214_AutoDesignDateAndTimeItem (StepAP214_AutoDesignActualDateAndTimeAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignActualDateAndTimeAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::NbItems, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignActualDateAndTimeAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignActualDateAndTimeAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignActualDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignActualDateAndTimeAssignment::*)() const) &StepAP214_AutoDesignActualDateAndTimeAssignment::DynamicType, "None");

// Enums

}