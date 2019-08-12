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
#include <StepBasic_ProductCategory.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_HArray1OfProduct.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductRelatedProductCategory(py::module &mod){

py::class_<StepBasic_ProductRelatedProductCategory, opencascade::handle<StepBasic_ProductRelatedProductCategory>, StepBasic_ProductCategory> cls_StepBasic_ProductRelatedProductCategory(mod, "StepBasic_ProductRelatedProductCategory", "None");

// Constructors
cls_StepBasic_ProductRelatedProductCategory.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductRelatedProductCategory.def("Init", (void (StepBasic_ProductRelatedProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfProduct> &)) &StepBasic_ProductRelatedProductCategory::Init, "None", py::arg("aName"), py::arg("hasAdescription"), py::arg("aDescription"), py::arg("aProducts"));
cls_StepBasic_ProductRelatedProductCategory.def("SetProducts", (void (StepBasic_ProductRelatedProductCategory::*)(const opencascade::handle<StepBasic_HArray1OfProduct> &)) &StepBasic_ProductRelatedProductCategory::SetProducts, "None", py::arg("aProducts"));
cls_StepBasic_ProductRelatedProductCategory.def("Products", (opencascade::handle<StepBasic_HArray1OfProduct> (StepBasic_ProductRelatedProductCategory::*)() const) &StepBasic_ProductRelatedProductCategory::Products, "None");
cls_StepBasic_ProductRelatedProductCategory.def("ProductsValue", (opencascade::handle<StepBasic_Product> (StepBasic_ProductRelatedProductCategory::*)(const Standard_Integer) const) &StepBasic_ProductRelatedProductCategory::ProductsValue, "None", py::arg("num"));
cls_StepBasic_ProductRelatedProductCategory.def("NbProducts", (Standard_Integer (StepBasic_ProductRelatedProductCategory::*)() const) &StepBasic_ProductRelatedProductCategory::NbProducts, "None");
cls_StepBasic_ProductRelatedProductCategory.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductRelatedProductCategory::get_type_name, "None");
cls_StepBasic_ProductRelatedProductCategory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductRelatedProductCategory::get_type_descriptor, "None");
cls_StepBasic_ProductRelatedProductCategory.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductRelatedProductCategory::*)() const) &StepBasic_ProductRelatedProductCategory::DynamicType, "None");

// Enums

}