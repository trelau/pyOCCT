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
#include <StepVisual_HArray1OfInvisibleItem.hxx>
#include <StepVisual_InvisibleItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_Invisibility.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_Invisibility(py::module &mod){

py::class_<StepVisual_Invisibility, opencascade::handle<StepVisual_Invisibility>, Standard_Transient> cls_StepVisual_Invisibility(mod, "StepVisual_Invisibility", "None");

// Constructors
cls_StepVisual_Invisibility.def(py::init<>());

// Fields

// Methods
cls_StepVisual_Invisibility.def("Init", (void (StepVisual_Invisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &)) &StepVisual_Invisibility::Init, "None", py::arg("aInvisibleItems"));
cls_StepVisual_Invisibility.def("SetInvisibleItems", (void (StepVisual_Invisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &)) &StepVisual_Invisibility::SetInvisibleItems, "None", py::arg("aInvisibleItems"));
cls_StepVisual_Invisibility.def("InvisibleItems", (opencascade::handle<StepVisual_HArray1OfInvisibleItem> (StepVisual_Invisibility::*)() const) &StepVisual_Invisibility::InvisibleItems, "None");
cls_StepVisual_Invisibility.def("InvisibleItemsValue", (StepVisual_InvisibleItem (StepVisual_Invisibility::*)(const Standard_Integer) const) &StepVisual_Invisibility::InvisibleItemsValue, "None", py::arg("num"));
cls_StepVisual_Invisibility.def("NbInvisibleItems", (Standard_Integer (StepVisual_Invisibility::*)() const) &StepVisual_Invisibility::NbInvisibleItems, "None");
cls_StepVisual_Invisibility.def_static("get_type_name_", (const char * (*)()) &StepVisual_Invisibility::get_type_name, "None");
cls_StepVisual_Invisibility.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_Invisibility::get_type_descriptor, "None");
cls_StepVisual_Invisibility.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_Invisibility::*)() const) &StepVisual_Invisibility::DynamicType, "None");

// Enums

}