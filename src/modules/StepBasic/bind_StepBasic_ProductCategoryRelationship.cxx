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
#include <StepBasic_ProductCategory.hxx>
#include <StepBasic_ProductCategoryRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductCategoryRelationship(py::module &mod){

py::class_<StepBasic_ProductCategoryRelationship, opencascade::handle<StepBasic_ProductCategoryRelationship>, Standard_Transient> cls_StepBasic_ProductCategoryRelationship(mod, "StepBasic_ProductCategoryRelationship", "Representation of STEP entity ProductCategoryRelationship");

// Constructors
cls_StepBasic_ProductCategoryRelationship.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductCategoryRelationship.def("Init", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductCategory> &, const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aCategory"), py::arg("aSubCategory"));
cls_StepBasic_ProductCategoryRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::Name, "Returns field Name");
cls_StepBasic_ProductCategoryRelationship.def("SetName", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategoryRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_ProductCategoryRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::Description, "Returns field Description");
cls_StepBasic_ProductCategoryRelationship.def("SetDescription", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategoryRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_ProductCategoryRelationship.def("HasDescription", (Standard_Boolean (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::HasDescription, "Returns True if optional field Description is defined");
cls_StepBasic_ProductCategoryRelationship.def("Category", (opencascade::handle<StepBasic_ProductCategory> (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::Category, "Returns field Category");
cls_StepBasic_ProductCategoryRelationship.def("SetCategory", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::SetCategory, "Set field Category", py::arg("Category"));
cls_StepBasic_ProductCategoryRelationship.def("SubCategory", (opencascade::handle<StepBasic_ProductCategory> (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::SubCategory, "Returns field SubCategory");
cls_StepBasic_ProductCategoryRelationship.def("SetSubCategory", (void (StepBasic_ProductCategoryRelationship::*)(const opencascade::handle<StepBasic_ProductCategory> &)) &StepBasic_ProductCategoryRelationship::SetSubCategory, "Set field SubCategory", py::arg("SubCategory"));
cls_StepBasic_ProductCategoryRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductCategoryRelationship::get_type_name, "None");
cls_StepBasic_ProductCategoryRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductCategoryRelationship::get_type_descriptor, "None");
cls_StepBasic_ProductCategoryRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductCategoryRelationship::*)() const) &StepBasic_ProductCategoryRelationship::DynamicType, "None");

// Enums

}