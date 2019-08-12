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
#include <StepAP203_HArray1OfDateTimeItem.hxx>
#include <StepAP203_CcDesignDateAndTimeAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_CcDesignDateAndTimeAssignment(py::module &mod){

py::class_<StepAP203_CcDesignDateAndTimeAssignment, opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP203_CcDesignDateAndTimeAssignment(mod, "StepAP203_CcDesignDateAndTimeAssignment", "Representation of STEP entity CcDesignDateAndTimeAssignment");

// Constructors
cls_StepAP203_CcDesignDateAndTimeAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP203_CcDesignDateAndTimeAssignment.def("Init", (void (StepAP203_CcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP203_HArray1OfDateTimeItem> &)) &StepAP203_CcDesignDateAndTimeAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aDateAndTimeAssignment_AssignedDateAndTime"), py::arg("aDateAndTimeAssignment_Role"), py::arg("aItems"));
cls_StepAP203_CcDesignDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP203_HArray1OfDateTimeItem> (StepAP203_CcDesignDateAndTimeAssignment::*)() const) &StepAP203_CcDesignDateAndTimeAssignment::Items, "Returns field Items");
cls_StepAP203_CcDesignDateAndTimeAssignment.def("SetItems", (void (StepAP203_CcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepAP203_HArray1OfDateTimeItem> &)) &StepAP203_CcDesignDateAndTimeAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_CcDesignDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignDateAndTimeAssignment::get_type_name, "None");
cls_StepAP203_CcDesignDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignDateAndTimeAssignment::get_type_descriptor, "None");
cls_StepAP203_CcDesignDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignDateAndTimeAssignment::*)() const) &StepAP203_CcDesignDateAndTimeAssignment::DynamicType, "None");

// Enums

}