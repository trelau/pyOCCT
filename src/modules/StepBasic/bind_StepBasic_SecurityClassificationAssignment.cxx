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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_SecurityClassificationAssignment(py::module &mod){

py::class_<StepBasic_SecurityClassificationAssignment, opencascade::handle<StepBasic_SecurityClassificationAssignment>, Standard_Transient> cls_StepBasic_SecurityClassificationAssignment(mod, "StepBasic_SecurityClassificationAssignment", "None");

// Constructors

// Fields

// Methods
cls_StepBasic_SecurityClassificationAssignment.def("Init", (void (StepBasic_SecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &)) &StepBasic_SecurityClassificationAssignment::Init, "None", py::arg("aAssignedSecurityClassification"));
cls_StepBasic_SecurityClassificationAssignment.def("SetAssignedSecurityClassification", (void (StepBasic_SecurityClassificationAssignment::*)(const opencascade::handle<StepBasic_SecurityClassification> &)) &StepBasic_SecurityClassificationAssignment::SetAssignedSecurityClassification, "None", py::arg("aAssignedSecurityClassification"));
cls_StepBasic_SecurityClassificationAssignment.def("AssignedSecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepBasic_SecurityClassificationAssignment::*)() const) &StepBasic_SecurityClassificationAssignment::AssignedSecurityClassification, "None");
cls_StepBasic_SecurityClassificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_SecurityClassificationAssignment::get_type_name, "None");
cls_StepBasic_SecurityClassificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SecurityClassificationAssignment::get_type_descriptor, "None");
cls_StepBasic_SecurityClassificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SecurityClassificationAssignment::*)() const) &StepBasic_SecurityClassificationAssignment::DynamicType, "None");

// Enums

}