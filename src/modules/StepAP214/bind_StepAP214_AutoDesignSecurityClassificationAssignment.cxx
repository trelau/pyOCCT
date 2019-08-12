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
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepBasic_HArray1OfApproval.hxx>
#include <StepBasic_Approval.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignSecurityClassificationAssignment(py::module &mod){

py::class_<StepAP214_AutoDesignSecurityClassificationAssignment, opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment>, StepBasic_SecurityClassificationAssignment> cls_StepAP214_AutoDesignSecurityClassificationAssignment(mod, "StepAP214_AutoDesignSecurityClassificationAssignment", "None");

// Constructors
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("Init", (void (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &, const opencascade::handle<StepBasic_HArray1OfApproval> &)) &StepAP214_AutoDesignSecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"), py::arg("aItems"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("SetItems", (void (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_HArray1OfApproval> &)) &StepAP214_AutoDesignSecurityClassificationAssignment::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("Items", (opencascade::handle<StepBasic_HArray1OfApproval> (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::Items, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("ItemsValue", (opencascade::handle<StepBasic_Approval> (StepAP214_AutoDesignSecurityClassificationAssignment::*)(const Standard_Integer) const) &StepAP214_AutoDesignSecurityClassificationAssignment::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("NbItems", (Standard_Integer (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::NbItems, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignSecurityClassificationAssignment::get_type_name, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignSecurityClassificationAssignment::get_type_descriptor, "None");
cls_StepAP214_AutoDesignSecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignSecurityClassificationAssignment::*)() const) &StepAP214_AutoDesignSecurityClassificationAssignment::DynamicType, "None");

// Enums

}