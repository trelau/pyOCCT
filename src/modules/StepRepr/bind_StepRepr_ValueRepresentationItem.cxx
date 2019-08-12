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
#include <StepRepr_ValueRepresentationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ValueRepresentationItem(py::module &mod){

py::class_<StepRepr_ValueRepresentationItem, opencascade::handle<StepRepr_ValueRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_ValueRepresentationItem(mod, "StepRepr_ValueRepresentationItem", "None");

// Constructors
cls_StepRepr_ValueRepresentationItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ValueRepresentationItem.def("Init", (void (StepRepr_ValueRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepRepr_ValueRepresentationItem::Init, "None", py::arg("theName"), py::arg("theValueComponentMember"));
cls_StepRepr_ValueRepresentationItem.def("SetValueComponentMember", (void (StepRepr_ValueRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepRepr_ValueRepresentationItem::SetValueComponentMember, "None", py::arg("theValueComponentMember"));
cls_StepRepr_ValueRepresentationItem.def("ValueComponentMember", (opencascade::handle<StepBasic_MeasureValueMember> (StepRepr_ValueRepresentationItem::*)() const) &StepRepr_ValueRepresentationItem::ValueComponentMember, "None");
cls_StepRepr_ValueRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_ValueRepresentationItem::get_type_name, "None");
cls_StepRepr_ValueRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ValueRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_ValueRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ValueRepresentationItem::*)() const) &StepRepr_ValueRepresentationItem::DynamicType, "None");

// Enums

}