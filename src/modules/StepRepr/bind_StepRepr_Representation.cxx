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
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_Representation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_Representation(py::module &mod){

py::class_<StepRepr_Representation, opencascade::handle<StepRepr_Representation>, Standard_Transient> cls_StepRepr_Representation(mod, "StepRepr_Representation", "None");

// Constructors
cls_StepRepr_Representation.def(py::init<>());

// Fields

// Methods
cls_StepRepr_Representation.def("Init", (void (StepRepr_Representation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_Representation::Init, "None", py::arg("aName"), py::arg("aItems"), py::arg("aContextOfItems"));
cls_StepRepr_Representation.def("SetName", (void (StepRepr_Representation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_Representation::SetName, "None", py::arg("aName"));
cls_StepRepr_Representation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_Representation::*)() const) &StepRepr_Representation::Name, "None");
cls_StepRepr_Representation.def("SetItems", (void (StepRepr_Representation::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_Representation::SetItems, "None", py::arg("aItems"));
cls_StepRepr_Representation.def("Items", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepRepr_Representation::*)() const) &StepRepr_Representation::Items, "None");
cls_StepRepr_Representation.def("ItemsValue", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_Representation::*)(const Standard_Integer) const) &StepRepr_Representation::ItemsValue, "None", py::arg("num"));
cls_StepRepr_Representation.def("NbItems", (Standard_Integer (StepRepr_Representation::*)() const) &StepRepr_Representation::NbItems, "None");
cls_StepRepr_Representation.def("SetContextOfItems", (void (StepRepr_Representation::*)(const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_Representation::SetContextOfItems, "None", py::arg("aContextOfItems"));
cls_StepRepr_Representation.def("ContextOfItems", (opencascade::handle<StepRepr_RepresentationContext> (StepRepr_Representation::*)() const) &StepRepr_Representation::ContextOfItems, "None");
cls_StepRepr_Representation.def_static("get_type_name_", (const char * (*)()) &StepRepr_Representation::get_type_name, "None");
cls_StepRepr_Representation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_Representation::get_type_descriptor, "None");
cls_StepRepr_Representation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_Representation::*)() const) &StepRepr_Representation::DynamicType, "None");

// Enums

}