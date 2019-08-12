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
#include <StepBasic_Effectivity.hxx>
#include <StepBasic_EffectivityAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_EffectivityAssignment(py::module &mod){

py::class_<StepBasic_EffectivityAssignment, opencascade::handle<StepBasic_EffectivityAssignment>, Standard_Transient> cls_StepBasic_EffectivityAssignment(mod, "StepBasic_EffectivityAssignment", "Representation of STEP entity EffectivityAssignment");

// Constructors
cls_StepBasic_EffectivityAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_EffectivityAssignment.def("Init", (void (StepBasic_EffectivityAssignment::*)(const opencascade::handle<StepBasic_Effectivity> &)) &StepBasic_EffectivityAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aAssignedEffectivity"));
cls_StepBasic_EffectivityAssignment.def("AssignedEffectivity", (opencascade::handle<StepBasic_Effectivity> (StepBasic_EffectivityAssignment::*)() const) &StepBasic_EffectivityAssignment::AssignedEffectivity, "Returns field AssignedEffectivity");
cls_StepBasic_EffectivityAssignment.def("SetAssignedEffectivity", (void (StepBasic_EffectivityAssignment::*)(const opencascade::handle<StepBasic_Effectivity> &)) &StepBasic_EffectivityAssignment::SetAssignedEffectivity, "Set field AssignedEffectivity", py::arg("AssignedEffectivity"));
cls_StepBasic_EffectivityAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_EffectivityAssignment::get_type_name, "None");
cls_StepBasic_EffectivityAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_EffectivityAssignment::get_type_descriptor, "None");
cls_StepBasic_EffectivityAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_EffectivityAssignment::*)() const) &StepBasic_EffectivityAssignment::DynamicType, "None");

// Enums

}