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
#include <StepBasic_SiUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_TimeUnit.hxx>
#include <StepBasic_SiUnitAndTimeUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_SiUnitAndTimeUnit(py::module &mod){

py::class_<StepBasic_SiUnitAndTimeUnit, opencascade::handle<StepBasic_SiUnitAndTimeUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndTimeUnit(mod, "StepBasic_SiUnitAndTimeUnit", "None");

// Constructors
cls_StepBasic_SiUnitAndTimeUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_SiUnitAndTimeUnit.def("Init", (void (StepBasic_SiUnitAndTimeUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndTimeUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
cls_StepBasic_SiUnitAndTimeUnit.def("SetTimeUnit", (void (StepBasic_SiUnitAndTimeUnit::*)(const opencascade::handle<StepBasic_TimeUnit> &)) &StepBasic_SiUnitAndTimeUnit::SetTimeUnit, "None", py::arg("aTimeUnit"));
cls_StepBasic_SiUnitAndTimeUnit.def("TimeUnit", (opencascade::handle<StepBasic_TimeUnit> (StepBasic_SiUnitAndTimeUnit::*)() const) &StepBasic_SiUnitAndTimeUnit::TimeUnit, "None");
cls_StepBasic_SiUnitAndTimeUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndTimeUnit::get_type_name, "None");
cls_StepBasic_SiUnitAndTimeUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndTimeUnit::get_type_descriptor, "None");
cls_StepBasic_SiUnitAndTimeUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndTimeUnit::*)() const) &StepBasic_SiUnitAndTimeUnit::DynamicType, "None");

// Enums

}