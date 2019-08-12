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
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <Standard_Transient.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_StyledItemTarget.hxx>
#include <StepVisual_StyledItem.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_StyledItem(py::module &mod){

py::class_<StepVisual_StyledItem, opencascade::handle<StepVisual_StyledItem>, StepRepr_RepresentationItem> cls_StepVisual_StyledItem(mod, "StepVisual_StyledItem", "None");

// Constructors
cls_StepVisual_StyledItem.def(py::init<>());

// Fields

// Methods
cls_StepVisual_StyledItem.def("Init", (void (StepVisual_StyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &)) &StepVisual_StyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"));
cls_StepVisual_StyledItem.def("SetStyles", (void (StepVisual_StyledItem::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &)) &StepVisual_StyledItem::SetStyles, "None", py::arg("aStyles"));
cls_StepVisual_StyledItem.def("Styles", (opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> (StepVisual_StyledItem::*)() const) &StepVisual_StyledItem::Styles, "None");
cls_StepVisual_StyledItem.def("StylesValue", (opencascade::handle<StepVisual_PresentationStyleAssignment> (StepVisual_StyledItem::*)(const Standard_Integer) const) &StepVisual_StyledItem::StylesValue, "None", py::arg("num"));
cls_StepVisual_StyledItem.def("NbStyles", (Standard_Integer (StepVisual_StyledItem::*)() const) &StepVisual_StyledItem::NbStyles, "None");
cls_StepVisual_StyledItem.def("SetItem", (void (StepVisual_StyledItem::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepVisual_StyledItem::SetItem, "None", py::arg("aItem"));
cls_StepVisual_StyledItem.def("Item", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_StyledItem::*)() const) &StepVisual_StyledItem::Item, "None");
cls_StepVisual_StyledItem.def("SetItem", (void (StepVisual_StyledItem::*)(const StepVisual_StyledItemTarget &)) &StepVisual_StyledItem::SetItem, "None", py::arg("aItem"));
cls_StepVisual_StyledItem.def("ItemAP242", (StepVisual_StyledItemTarget (StepVisual_StyledItem::*)() const) &StepVisual_StyledItem::ItemAP242, "None");
cls_StepVisual_StyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_StyledItem::get_type_name, "None");
cls_StepVisual_StyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_StyledItem::get_type_descriptor, "None");
cls_StepVisual_StyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_StyledItem::*)() const) &StepVisual_StyledItem::DynamicType, "None");

// Enums

}