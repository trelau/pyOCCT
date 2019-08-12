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
#include <StepRepr_RepresentationMap.hxx>
#include <StepRepr_MappedItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_MappedItem(py::module &mod){

py::class_<StepRepr_MappedItem, opencascade::handle<StepRepr_MappedItem>, StepRepr_RepresentationItem> cls_StepRepr_MappedItem(mod, "StepRepr_MappedItem", "None");

// Constructors
cls_StepRepr_MappedItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_MappedItem.def("Init", (void (StepRepr_MappedItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationMap> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_MappedItem::Init, "None", py::arg("aName"), py::arg("aMappingSource"), py::arg("aMappingTarget"));
cls_StepRepr_MappedItem.def("SetMappingSource", (void (StepRepr_MappedItem::*)(const opencascade::handle<StepRepr_RepresentationMap> &)) &StepRepr_MappedItem::SetMappingSource, "None", py::arg("aMappingSource"));
cls_StepRepr_MappedItem.def("MappingSource", (opencascade::handle<StepRepr_RepresentationMap> (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::MappingSource, "None");
cls_StepRepr_MappedItem.def("SetMappingTarget", (void (StepRepr_MappedItem::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_MappedItem::SetMappingTarget, "None", py::arg("aMappingTarget"));
cls_StepRepr_MappedItem.def("MappingTarget", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::MappingTarget, "None");
cls_StepRepr_MappedItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_MappedItem::get_type_name, "None");
cls_StepRepr_MappedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MappedItem::get_type_descriptor, "None");
cls_StepRepr_MappedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::DynamicType, "None");

// Enums

}