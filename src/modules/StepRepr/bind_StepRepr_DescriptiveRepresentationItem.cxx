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
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_DescriptiveRepresentationItem(py::module &mod){

py::class_<StepRepr_DescriptiveRepresentationItem, opencascade::handle<StepRepr_DescriptiveRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_DescriptiveRepresentationItem(mod, "StepRepr_DescriptiveRepresentationItem", "None");

// Constructors
cls_StepRepr_DescriptiveRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_DescriptiveRepresentationItem.def("Init", (void (StepRepr_DescriptiveRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DescriptiveRepresentationItem::Init, "None", py::arg("aName"), py::arg("aDescription"));
cls_StepRepr_DescriptiveRepresentationItem.def("SetDescription", (void (StepRepr_DescriptiveRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DescriptiveRepresentationItem::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_DescriptiveRepresentationItem.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DescriptiveRepresentationItem::*)() const) &StepRepr_DescriptiveRepresentationItem::Description, "None");
cls_StepRepr_DescriptiveRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_DescriptiveRepresentationItem::get_type_name, "None");
cls_StepRepr_DescriptiveRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DescriptiveRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_DescriptiveRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DescriptiveRepresentationItem::*)() const) &StepRepr_DescriptiveRepresentationItem::DynamicType, "None");

// Enums

}