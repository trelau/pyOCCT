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
#include <StepVisual_OverRidingStyledItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <Standard_Transient.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepVisual_HArray1OfStyleContextSelect.hxx>
#include <StepVisual_StyleContextSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_ContextDependentOverRidingStyledItem.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_ContextDependentOverRidingStyledItem(py::module &mod){

py::class_<StepVisual_ContextDependentOverRidingStyledItem, opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem>, StepVisual_OverRidingStyledItem> cls_StepVisual_ContextDependentOverRidingStyledItem(mod, "StepVisual_ContextDependentOverRidingStyledItem", "None");

// Constructors
cls_StepVisual_ContextDependentOverRidingStyledItem.def(py::init<>());

// Fields

// Methods
cls_StepVisual_ContextDependentOverRidingStyledItem.def("Init", (void (StepVisual_ContextDependentOverRidingStyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_StyledItem> &, const opencascade::handle<StepVisual_HArray1OfStyleContextSelect> &)) &StepVisual_ContextDependentOverRidingStyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"), py::arg("aOverRiddenStyle"), py::arg("aStyleContext"));
cls_StepVisual_ContextDependentOverRidingStyledItem.def("SetStyleContext", (void (StepVisual_ContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepVisual_HArray1OfStyleContextSelect> &)) &StepVisual_ContextDependentOverRidingStyledItem::SetStyleContext, "None", py::arg("aStyleContext"));
cls_StepVisual_ContextDependentOverRidingStyledItem.def("StyleContext", (opencascade::handle<StepVisual_HArray1OfStyleContextSelect> (StepVisual_ContextDependentOverRidingStyledItem::*)() const) &StepVisual_ContextDependentOverRidingStyledItem::StyleContext, "None");
cls_StepVisual_ContextDependentOverRidingStyledItem.def("StyleContextValue", (StepVisual_StyleContextSelect (StepVisual_ContextDependentOverRidingStyledItem::*)(const Standard_Integer) const) &StepVisual_ContextDependentOverRidingStyledItem::StyleContextValue, "None", py::arg("num"));
cls_StepVisual_ContextDependentOverRidingStyledItem.def("NbStyleContext", (Standard_Integer (StepVisual_ContextDependentOverRidingStyledItem::*)() const) &StepVisual_ContextDependentOverRidingStyledItem::NbStyleContext, "None");
cls_StepVisual_ContextDependentOverRidingStyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_ContextDependentOverRidingStyledItem::get_type_name, "None");
cls_StepVisual_ContextDependentOverRidingStyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ContextDependentOverRidingStyledItem::get_type_descriptor, "None");
cls_StepVisual_ContextDependentOverRidingStyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ContextDependentOverRidingStyledItem::*)() const) &StepVisual_ContextDependentOverRidingStyledItem::DynamicType, "None");

// Enums

}