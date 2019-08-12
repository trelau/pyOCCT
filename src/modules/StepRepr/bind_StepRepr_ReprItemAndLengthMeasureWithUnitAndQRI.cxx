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
#include <StepRepr_ReprItemAndMeasureWithUnitAndQRI.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI(py::module &mod){

py::class_<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI, opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI>, StepRepr_ReprItemAndMeasureWithUnitAndQRI> cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI(mod, "StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI", "None");

// Constructors
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("SetLengthMeasureWithUnit", (void (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::SetLengthMeasureWithUnit, "None", py::arg("aLMWU"));
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("GetLengthMeasureWithUnit", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::GetLengthMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::get_type_name, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::DynamicType, "None");

// Enums

}