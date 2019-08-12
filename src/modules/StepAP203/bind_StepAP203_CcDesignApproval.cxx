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
#include <StepBasic_ApprovalAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Approval.hxx>
#include <StepAP203_HArray1OfApprovedItem.hxx>
#include <StepAP203_CcDesignApproval.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_CcDesignApproval(py::module &mod){

py::class_<StepAP203_CcDesignApproval, opencascade::handle<StepAP203_CcDesignApproval>, StepBasic_ApprovalAssignment> cls_StepAP203_CcDesignApproval(mod, "StepAP203_CcDesignApproval", "Representation of STEP entity CcDesignApproval");

// Constructors
cls_StepAP203_CcDesignApproval.def(py::init<>());

// Fields

// Methods
cls_StepAP203_CcDesignApproval.def("Init", (void (StepAP203_CcDesignApproval::*)(const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepAP203_HArray1OfApprovedItem> &)) &StepAP203_CcDesignApproval::Init, "Initialize all fields (own and inherited)", py::arg("aApprovalAssignment_AssignedApproval"), py::arg("aItems"));
cls_StepAP203_CcDesignApproval.def("Items", (opencascade::handle<StepAP203_HArray1OfApprovedItem> (StepAP203_CcDesignApproval::*)() const) &StepAP203_CcDesignApproval::Items, "Returns field Items");
cls_StepAP203_CcDesignApproval.def("SetItems", (void (StepAP203_CcDesignApproval::*)(const opencascade::handle<StepAP203_HArray1OfApprovedItem> &)) &StepAP203_CcDesignApproval::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_CcDesignApproval.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignApproval::get_type_name, "None");
cls_StepAP203_CcDesignApproval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignApproval::get_type_descriptor, "None");
cls_StepAP203_CcDesignApproval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignApproval::*)() const) &StepAP203_CcDesignApproval::DynamicType, "None");

// Enums

}