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
#include <StepAP203_HArray1OfPersonOrganizationItem.hxx>
#include <StepAP203_CcDesignPersonAndOrganizationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepAP203_CcDesignPersonAndOrganizationAssignment(py::module &mod){

py::class_<StepAP203_CcDesignPersonAndOrganizationAssignment, opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP203_CcDesignPersonAndOrganizationAssignment(mod, "StepAP203_CcDesignPersonAndOrganizationAssignment", "Representation of STEP entity CcDesignPersonAndOrganizationAssignment");

// Constructors
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("Init", (void (StepAP203_CcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> &)) &StepAP203_CcDesignPersonAndOrganizationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aPersonAndOrganizationAssignment_AssignedPersonAndOrganization"), py::arg("aPersonAndOrganizationAssignment_Role"), py::arg("aItems"));
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("Items", (opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> (StepAP203_CcDesignPersonAndOrganizationAssignment::*)() const) &StepAP203_CcDesignPersonAndOrganizationAssignment::Items, "Returns field Items");
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("SetItems", (void (StepAP203_CcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> &)) &StepAP203_CcDesignPersonAndOrganizationAssignment::SetItems, "Set field Items", py::arg("Items"));
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignPersonAndOrganizationAssignment::get_type_name, "None");
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignPersonAndOrganizationAssignment::get_type_descriptor, "None");
cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignPersonAndOrganizationAssignment::*)() const) &StepAP203_CcDesignPersonAndOrganizationAssignment::DynamicType, "None");

// Enums

}