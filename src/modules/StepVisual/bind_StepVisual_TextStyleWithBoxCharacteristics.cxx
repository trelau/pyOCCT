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
#include <StepVisual_TextStyle.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_TextStyleForDefinedFont.hxx>
#include <StepVisual_HArray1OfBoxCharacteristicSelect.hxx>
#include <StepVisual_BoxCharacteristicSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_TextStyleWithBoxCharacteristics.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_TextStyleWithBoxCharacteristics(py::module &mod){

py::class_<StepVisual_TextStyleWithBoxCharacteristics, opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics>, StepVisual_TextStyle> cls_StepVisual_TextStyleWithBoxCharacteristics(mod, "StepVisual_TextStyleWithBoxCharacteristics", "None");

// Constructors
cls_StepVisual_TextStyleWithBoxCharacteristics.def(py::init<>());

// Fields

// Methods
cls_StepVisual_TextStyleWithBoxCharacteristics.def("Init", (void (StepVisual_TextStyleWithBoxCharacteristics::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &, const opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> &)) &StepVisual_TextStyleWithBoxCharacteristics::Init, "None", py::arg("aName"), py::arg("aCharacterAppearance"), py::arg("aCharacteristics"));
cls_StepVisual_TextStyleWithBoxCharacteristics.def("SetCharacteristics", (void (StepVisual_TextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> &)) &StepVisual_TextStyleWithBoxCharacteristics::SetCharacteristics, "None", py::arg("aCharacteristics"));
cls_StepVisual_TextStyleWithBoxCharacteristics.def("Characteristics", (opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> (StepVisual_TextStyleWithBoxCharacteristics::*)() const) &StepVisual_TextStyleWithBoxCharacteristics::Characteristics, "None");
cls_StepVisual_TextStyleWithBoxCharacteristics.def("CharacteristicsValue", (StepVisual_BoxCharacteristicSelect (StepVisual_TextStyleWithBoxCharacteristics::*)(const Standard_Integer) const) &StepVisual_TextStyleWithBoxCharacteristics::CharacteristicsValue, "None", py::arg("num"));
cls_StepVisual_TextStyleWithBoxCharacteristics.def("NbCharacteristics", (Standard_Integer (StepVisual_TextStyleWithBoxCharacteristics::*)() const) &StepVisual_TextStyleWithBoxCharacteristics::NbCharacteristics, "None");
cls_StepVisual_TextStyleWithBoxCharacteristics.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextStyleWithBoxCharacteristics::get_type_name, "None");
cls_StepVisual_TextStyleWithBoxCharacteristics.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextStyleWithBoxCharacteristics::get_type_descriptor, "None");
cls_StepVisual_TextStyleWithBoxCharacteristics.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextStyleWithBoxCharacteristics::*)() const) &StepVisual_TextStyleWithBoxCharacteristics::DynamicType, "None");

// Enums

}