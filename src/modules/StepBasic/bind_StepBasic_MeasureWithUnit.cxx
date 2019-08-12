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
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_MeasureWithUnit(py::module &mod){

py::class_<StepBasic_MeasureWithUnit, opencascade::handle<StepBasic_MeasureWithUnit>, Standard_Transient> cls_StepBasic_MeasureWithUnit(mod, "StepBasic_MeasureWithUnit", "None");

// Constructors
cls_StepBasic_MeasureWithUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_MeasureWithUnit.def("Init", (void (StepBasic_MeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &)) &StepBasic_MeasureWithUnit::Init, "None", py::arg("aValueComponent"), py::arg("aUnitComponent"));
cls_StepBasic_MeasureWithUnit.def("SetValueComponent", (void (StepBasic_MeasureWithUnit::*)(const Standard_Real)) &StepBasic_MeasureWithUnit::SetValueComponent, "None", py::arg("aValueComponent"));
cls_StepBasic_MeasureWithUnit.def("ValueComponent", (Standard_Real (StepBasic_MeasureWithUnit::*)() const) &StepBasic_MeasureWithUnit::ValueComponent, "None");
cls_StepBasic_MeasureWithUnit.def("ValueComponentMember", (opencascade::handle<StepBasic_MeasureValueMember> (StepBasic_MeasureWithUnit::*)() const) &StepBasic_MeasureWithUnit::ValueComponentMember, "None");
cls_StepBasic_MeasureWithUnit.def("SetValueComponentMember", (void (StepBasic_MeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepBasic_MeasureWithUnit::SetValueComponentMember, "None", py::arg("val"));
cls_StepBasic_MeasureWithUnit.def("SetUnitComponent", (void (StepBasic_MeasureWithUnit::*)(const StepBasic_Unit &)) &StepBasic_MeasureWithUnit::SetUnitComponent, "None", py::arg("aUnitComponent"));
cls_StepBasic_MeasureWithUnit.def("UnitComponent", (StepBasic_Unit (StepBasic_MeasureWithUnit::*)() const) &StepBasic_MeasureWithUnit::UnitComponent, "None");
cls_StepBasic_MeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_MeasureWithUnit::get_type_name, "None");
cls_StepBasic_MeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_MeasureWithUnit::get_type_descriptor, "None");
cls_StepBasic_MeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_MeasureWithUnit::*)() const) &StepBasic_MeasureWithUnit::DynamicType, "None");

// Enums

}