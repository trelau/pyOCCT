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
#include <Standard_Type.hxx>

void bind_StepBasic_ProductCategory(py::module &mod){

py::class_<StepBasic_ProductCategory, opencascade::handle<StepBasic_ProductCategory>, Standard_Transient> cls_StepBasic_ProductCategory(mod, "StepBasic_ProductCategory", "None");

// Constructors
cls_StepBasic_ProductCategory.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductCategory.def("Init", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::Init, "None", py::arg("aName"), py::arg("hasAdescription"), py::arg("aDescription"));
cls_StepBasic_ProductCategory.def("SetName", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::SetName, "None", py::arg("aName"));
cls_StepBasic_ProductCategory.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategory::*)() const) &StepBasic_ProductCategory::Name, "None");
cls_StepBasic_ProductCategory.def("SetDescription", (void (StepBasic_ProductCategory::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductCategory::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_ProductCategory.def("UnSetDescription", (void (StepBasic_ProductCategory::*)()) &StepBasic_ProductCategory::UnSetDescription, "None");
cls_StepBasic_ProductCategory.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductCategory::*)() const) &StepBasic_ProductCategory::Description, "None");
cls_StepBasic_ProductCategory.def("HasDescription", (Standard_Boolean (StepBasic_ProductCategory::*)() const) &StepBasic_ProductCategory::HasDescription, "None");
cls_StepBasic_ProductCategory.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductCategory::get_type_name, "None");
cls_StepBasic_ProductCategory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductCategory::get_type_descriptor, "None");
cls_StepBasic_ProductCategory.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductCategory::*)() const) &StepBasic_ProductCategory::DynamicType, "None");

// Enums

}