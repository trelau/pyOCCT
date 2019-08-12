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
#include <StepShape_HArray1OfValueQualifier.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ValueQualifier.hxx>
#include <StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem(py::module &mod){

py::class_<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem, opencascade::handle<StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem>, StepRepr_RepresentationItem> cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem(mod, "StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem", "Added for Dimensional Tolerances Complex Type between MeasureRepresentationItem and QualifiedRepresentationItem");

// Constructors
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Init", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &, const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Init, "None", py::arg("aName"), py::arg("aValueComponent"), py::arg("aUnitComponent"), py::arg("qualifiers"));
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetMeasure", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetMeasure, "None", py::arg("Measure"));
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Measure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Measure, "None");
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("Qualifiers", (opencascade::handle<StepShape_HArray1OfValueQualifier> (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::Qualifiers, "None");
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("NbQualifiers", (Standard_Integer (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::NbQualifiers, "None");
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetQualifiers", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const opencascade::handle<StepShape_HArray1OfValueQualifier> &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetQualifiers, "None", py::arg("qualifiers"));
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("QualifiersValue", (StepShape_ValueQualifier (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const Standard_Integer) const) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::QualifiersValue, "None", py::arg("num"));
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("SetQualifiersValue", (void (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)(const Standard_Integer, const StepShape_ValueQualifier &)) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::SetQualifiersValue, "None", py::arg("num"), py::arg("aqualifier"));
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::get_type_name, "None");
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::get_type_descriptor, "None");
cls_StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::*)() const) &StepShape_MeasureRepresentationItemAndQualifiedRepresentationItem::DynamicType, "None");

// Enums

}