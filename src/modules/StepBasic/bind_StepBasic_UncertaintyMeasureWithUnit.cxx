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
#include <StepBasic_MeasureWithUnit.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_UncertaintyMeasureWithUnit(py::module &mod){

py::class_<StepBasic_UncertaintyMeasureWithUnit, opencascade::handle<StepBasic_UncertaintyMeasureWithUnit>, StepBasic_MeasureWithUnit> cls_StepBasic_UncertaintyMeasureWithUnit(mod, "StepBasic_UncertaintyMeasureWithUnit", "None");

// Constructors
cls_StepBasic_UncertaintyMeasureWithUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_UncertaintyMeasureWithUnit.def("Init", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::Init, "None", py::arg("aValueComponent"), py::arg("aUnitComponent"), py::arg("aName"), py::arg("aDescription"));
cls_StepBasic_UncertaintyMeasureWithUnit.def("SetName", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::SetName, "None", py::arg("aName"));
cls_StepBasic_UncertaintyMeasureWithUnit.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_UncertaintyMeasureWithUnit::*)() const) &StepBasic_UncertaintyMeasureWithUnit::Name, "None");
cls_StepBasic_UncertaintyMeasureWithUnit.def("SetDescription", (void (StepBasic_UncertaintyMeasureWithUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_UncertaintyMeasureWithUnit::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_UncertaintyMeasureWithUnit.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_UncertaintyMeasureWithUnit::*)() const) &StepBasic_UncertaintyMeasureWithUnit::Description, "None");
cls_StepBasic_UncertaintyMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_UncertaintyMeasureWithUnit::get_type_name, "None");
cls_StepBasic_UncertaintyMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_UncertaintyMeasureWithUnit::get_type_descriptor, "None");
cls_StepBasic_UncertaintyMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_UncertaintyMeasureWithUnit::*)() const) &StepBasic_UncertaintyMeasureWithUnit::DynamicType, "None");

// Enums

}