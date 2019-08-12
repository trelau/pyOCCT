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
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_MeasureRepresentationItem(py::module &mod){

py::class_<StepRepr_MeasureRepresentationItem, opencascade::handle<StepRepr_MeasureRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_MeasureRepresentationItem(mod, "StepRepr_MeasureRepresentationItem", "Implements a measure_representation_item entity which is used for storing validation properties (e.g. area) for shapes");

// Constructors
cls_StepRepr_MeasureRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_MeasureRepresentationItem.def("Init", (void (StepRepr_MeasureRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &)) &StepRepr_MeasureRepresentationItem::Init, "Init all fields", py::arg("aName"), py::arg("aValueComponent"), py::arg("aUnitComponent"));
cls_StepRepr_MeasureRepresentationItem.def("SetMeasure", (void (StepRepr_MeasureRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MeasureRepresentationItem::SetMeasure, "None", py::arg("Measure"));
cls_StepRepr_MeasureRepresentationItem.def("Measure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_MeasureRepresentationItem::*)() const) &StepRepr_MeasureRepresentationItem::Measure, "None");
cls_StepRepr_MeasureRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_MeasureRepresentationItem::get_type_name, "None");
cls_StepRepr_MeasureRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MeasureRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_MeasureRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MeasureRepresentationItem::*)() const) &StepRepr_MeasureRepresentationItem::DynamicType, "None");

// Enums

}