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
#include <StepVisual_StyledItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <Standard_Transient.hxx>
#include <StepVisual_OverRidingStyledItem.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_OverRidingStyledItem(py::module &mod){

py::class_<StepVisual_OverRidingStyledItem, opencascade::handle<StepVisual_OverRidingStyledItem>, StepVisual_StyledItem> cls_StepVisual_OverRidingStyledItem(mod, "StepVisual_OverRidingStyledItem", "None");

// Constructors
cls_StepVisual_OverRidingStyledItem.def(py::init<>());

// Fields

// Methods
cls_StepVisual_OverRidingStyledItem.def("Init", (void (StepVisual_OverRidingStyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_StyledItem> &)) &StepVisual_OverRidingStyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"), py::arg("aOverRiddenStyle"));
cls_StepVisual_OverRidingStyledItem.def("SetOverRiddenStyle", (void (StepVisual_OverRidingStyledItem::*)(const opencascade::handle<StepVisual_StyledItem> &)) &StepVisual_OverRidingStyledItem::SetOverRiddenStyle, "None", py::arg("aOverRiddenStyle"));
cls_StepVisual_OverRidingStyledItem.def("OverRiddenStyle", (opencascade::handle<StepVisual_StyledItem> (StepVisual_OverRidingStyledItem::*)() const) &StepVisual_OverRidingStyledItem::OverRiddenStyle, "None");
cls_StepVisual_OverRidingStyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_OverRidingStyledItem::get_type_name, "None");
cls_StepVisual_OverRidingStyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_OverRidingStyledItem::get_type_descriptor, "None");
cls_StepVisual_OverRidingStyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_OverRidingStyledItem::*)() const) &StepVisual_OverRidingStyledItem::DynamicType, "None");

// Enums

}