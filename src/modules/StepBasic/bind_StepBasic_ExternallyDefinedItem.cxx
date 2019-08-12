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
#include <StepBasic_SourceItem.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ExternallyDefinedItem(py::module &mod){

py::class_<StepBasic_ExternallyDefinedItem, opencascade::handle<StepBasic_ExternallyDefinedItem>, Standard_Transient> cls_StepBasic_ExternallyDefinedItem(mod, "StepBasic_ExternallyDefinedItem", "Representation of STEP entity ExternallyDefinedItem");

// Constructors
cls_StepBasic_ExternallyDefinedItem.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ExternallyDefinedItem.def("Init", (void (StepBasic_ExternallyDefinedItem::*)(const StepBasic_SourceItem &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternallyDefinedItem::Init, "Initialize all fields (own and inherited)", py::arg("aItemId"), py::arg("aSource"));
cls_StepBasic_ExternallyDefinedItem.def("ItemId", (StepBasic_SourceItem (StepBasic_ExternallyDefinedItem::*)() const) &StepBasic_ExternallyDefinedItem::ItemId, "Returns field ItemId");
cls_StepBasic_ExternallyDefinedItem.def("SetItemId", (void (StepBasic_ExternallyDefinedItem::*)(const StepBasic_SourceItem &)) &StepBasic_ExternallyDefinedItem::SetItemId, "Set field ItemId", py::arg("ItemId"));
cls_StepBasic_ExternallyDefinedItem.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ExternallyDefinedItem::*)() const) &StepBasic_ExternallyDefinedItem::Source, "Returns field Source");
cls_StepBasic_ExternallyDefinedItem.def("SetSource", (void (StepBasic_ExternallyDefinedItem::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternallyDefinedItem::SetSource, "Set field Source", py::arg("Source"));
cls_StepBasic_ExternallyDefinedItem.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternallyDefinedItem::get_type_name, "None");
cls_StepBasic_ExternallyDefinedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternallyDefinedItem::get_type_descriptor, "None");
cls_StepBasic_ExternallyDefinedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternallyDefinedItem::*)() const) &StepBasic_ExternallyDefinedItem::DynamicType, "None");

// Enums

}