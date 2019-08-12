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
#include <StepBasic_HArray1OfProductContext.hxx>
#include <StepBasic_ProductContext.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_Product.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Product(py::module &mod){

py::class_<StepBasic_Product, opencascade::handle<StepBasic_Product>, Standard_Transient> cls_StepBasic_Product(mod, "StepBasic_Product", "None");

// Constructors
cls_StepBasic_Product.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Product.def("Init", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfProductContext> &)) &StepBasic_Product::Init, "None", py::arg("aId"), py::arg("aName"), py::arg("aDescription"), py::arg("aFrameOfReference"));
cls_StepBasic_Product.def("SetId", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetId, "None", py::arg("aId"));
cls_StepBasic_Product.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const) &StepBasic_Product::Id, "None");
cls_StepBasic_Product.def("SetName", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetName, "None", py::arg("aName"));
cls_StepBasic_Product.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const) &StepBasic_Product::Name, "None");
cls_StepBasic_Product.def("SetDescription", (void (StepBasic_Product::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Product::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_Product.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Product::*)() const) &StepBasic_Product::Description, "None");
cls_StepBasic_Product.def("SetFrameOfReference", (void (StepBasic_Product::*)(const opencascade::handle<StepBasic_HArray1OfProductContext> &)) &StepBasic_Product::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
cls_StepBasic_Product.def("FrameOfReference", (opencascade::handle<StepBasic_HArray1OfProductContext> (StepBasic_Product::*)() const) &StepBasic_Product::FrameOfReference, "None");
cls_StepBasic_Product.def("FrameOfReferenceValue", (opencascade::handle<StepBasic_ProductContext> (StepBasic_Product::*)(const Standard_Integer) const) &StepBasic_Product::FrameOfReferenceValue, "None", py::arg("num"));
cls_StepBasic_Product.def("NbFrameOfReference", (Standard_Integer (StepBasic_Product::*)() const) &StepBasic_Product::NbFrameOfReference, "None");
cls_StepBasic_Product.def_static("get_type_name_", (const char * (*)()) &StepBasic_Product::get_type_name, "None");
cls_StepBasic_Product.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Product::get_type_descriptor, "None");
cls_StepBasic_Product.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Product::*)() const) &StepBasic_Product::DynamicType, "None");

// Enums

}