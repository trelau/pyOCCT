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
#include <StepBasic_Group.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepAP214_RepItemGroup.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_RepItemGroup(py::module &mod){

py::class_<StepAP214_RepItemGroup, opencascade::handle<StepAP214_RepItemGroup>, StepBasic_Group> cls_StepAP214_RepItemGroup(mod, "StepAP214_RepItemGroup", "Representation of STEP entity RepItemGroup");

// Constructors
cls_StepAP214_RepItemGroup.def(py::init<>());

// Fields

// Methods
cls_StepAP214_RepItemGroup.def("Init", (void (StepAP214_RepItemGroup::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepAP214_RepItemGroup::Init, "Initialize all fields (own and inherited)", py::arg("aGroup_Name"), py::arg("hasGroup_Description"), py::arg("aGroup_Description"), py::arg("aRepresentationItem_Name"));
cls_StepAP214_RepItemGroup.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_RepItemGroup::*)() const) &StepAP214_RepItemGroup::RepresentationItem, "Returns data for supertype RepresentationItem");
cls_StepAP214_RepItemGroup.def("SetRepresentationItem", (void (StepAP214_RepItemGroup::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepAP214_RepItemGroup::SetRepresentationItem, "Set data for supertype RepresentationItem", py::arg("RepresentationItem"));
cls_StepAP214_RepItemGroup.def_static("get_type_name_", (const char * (*)()) &StepAP214_RepItemGroup::get_type_name, "None");
cls_StepAP214_RepItemGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_RepItemGroup::get_type_descriptor, "None");
cls_StepAP214_RepItemGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_RepItemGroup::*)() const) &StepAP214_RepItemGroup::DynamicType, "None");

// Enums

}