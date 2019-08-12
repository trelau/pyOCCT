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
#include <StepRepr_RepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepRepr_ReprItemAndMeasureWithUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ReprItemAndMeasureWithUnit(py::module &mod){

py::class_<StepRepr_ReprItemAndMeasureWithUnit, opencascade::handle<StepRepr_ReprItemAndMeasureWithUnit>, StepRepr_RepresentationItem> cls_StepRepr_ReprItemAndMeasureWithUnit(mod, "StepRepr_ReprItemAndMeasureWithUnit", "Base class for complex types (MEASURE_REPRESENTATION_ITEM, MEASURE_WITH_UNIT, REPRESENTATION_ITEM, LENGTH_MEASURE_WITH_UNIT/PLANE_ANGLE_MEASURE_WITH_UNIT).");

// Constructors
cls_StepRepr_ReprItemAndMeasureWithUnit.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ReprItemAndMeasureWithUnit.def("Init", (void (StepRepr_ReprItemAndMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ReprItemAndMeasureWithUnit::Init, "None", py::arg("aMWU"), py::arg("aRI"));
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetMeasureRepresentationItem", (opencascade::handle<StepRepr_MeasureRepresentationItem> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetMeasureRepresentationItem, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("SetMeasureWithUnit", (void (StepRepr_ReprItemAndMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ReprItemAndMeasureWithUnit::SetMeasureWithUnit, "None", py::arg("aMWU"));
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetMeasureWithUnit", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetRepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetRepresentationItem, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndMeasureWithUnit::get_type_name, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndMeasureWithUnit::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::DynamicType, "None");

// Enums

}