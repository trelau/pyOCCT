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
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_ConfigurationItem(py::module &mod){

py::class_<StepRepr_ConfigurationItem, opencascade::handle<StepRepr_ConfigurationItem>, Standard_Transient> cls_StepRepr_ConfigurationItem(mod, "StepRepr_ConfigurationItem", "Representation of STEP entity ConfigurationItem");

// Constructors
cls_StepRepr_ConfigurationItem.def(py::init<>());

// Fields

// Methods
cls_StepRepr_ConfigurationItem.def("Init", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductConcept> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aItemConcept"), py::arg("hasPurpose"), py::arg("aPurpose"));
cls_StepRepr_ConfigurationItem.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Id, "Returns field Id");
cls_StepRepr_ConfigurationItem.def("SetId", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetId, "Set field Id", py::arg("Id"));
cls_StepRepr_ConfigurationItem.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Name, "Returns field Name");
cls_StepRepr_ConfigurationItem.def("SetName", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ConfigurationItem.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Description, "Returns field Description");
cls_StepRepr_ConfigurationItem.def("SetDescription", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ConfigurationItem.def("HasDescription", (Standard_Boolean (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ConfigurationItem.def("ItemConcept", (opencascade::handle<StepRepr_ProductConcept> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::ItemConcept, "Returns field ItemConcept");
cls_StepRepr_ConfigurationItem.def("SetItemConcept", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<StepRepr_ProductConcept> &)) &StepRepr_ConfigurationItem::SetItemConcept, "Set field ItemConcept", py::arg("ItemConcept"));
cls_StepRepr_ConfigurationItem.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Purpose, "Returns field Purpose");
cls_StepRepr_ConfigurationItem.def("SetPurpose", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepRepr_ConfigurationItem.def("HasPurpose", (Standard_Boolean (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::HasPurpose, "Returns True if optional field Purpose is defined");
cls_StepRepr_ConfigurationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationItem::get_type_name, "None");
cls_StepRepr_ConfigurationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationItem::get_type_descriptor, "None");
cls_StepRepr_ConfigurationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::DynamicType, "None");

// Enums

}