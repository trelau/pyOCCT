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
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_CompoundRepresentationItem(py::module &mod){

py::class_<StepRepr_CompoundRepresentationItem, opencascade::handle<StepRepr_CompoundRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_CompoundRepresentationItem(mod, "StepRepr_CompoundRepresentationItem", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompoundRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_CompoundRepresentationItem.def("Init", (void (StepRepr_CompoundRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_CompoundRepresentationItem::Init, "None", py::arg("aName"), py::arg("item_element"));
cls_StepRepr_CompoundRepresentationItem.def("ItemElement", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::ItemElement, "None");
cls_StepRepr_CompoundRepresentationItem.def("NbItemElement", (Standard_Integer (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::NbItemElement, "None");
cls_StepRepr_CompoundRepresentationItem.def("SetItemElement", (void (StepRepr_CompoundRepresentationItem::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_CompoundRepresentationItem::SetItemElement, "None", py::arg("item_element"));
cls_StepRepr_CompoundRepresentationItem.def("ItemElementValue", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_CompoundRepresentationItem::*)(const Standard_Integer) const) &StepRepr_CompoundRepresentationItem::ItemElementValue, "None", py::arg("num"));
cls_StepRepr_CompoundRepresentationItem.def("SetItemElementValue", (void (StepRepr_CompoundRepresentationItem::*)(const Standard_Integer, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_CompoundRepresentationItem::SetItemElementValue, "None", py::arg("num"), py::arg("anelement"));
cls_StepRepr_CompoundRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompoundRepresentationItem::get_type_name, "None");
cls_StepRepr_CompoundRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompoundRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_CompoundRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::DynamicType, "None");

// Enums

}