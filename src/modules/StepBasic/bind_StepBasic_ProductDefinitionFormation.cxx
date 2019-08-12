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
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionFormation(py::module &mod){

py::class_<StepBasic_ProductDefinitionFormation, opencascade::handle<StepBasic_ProductDefinitionFormation>, Standard_Transient> cls_StepBasic_ProductDefinitionFormation(mod, "StepBasic_ProductDefinitionFormation", "None");

// Constructors
cls_StepBasic_ProductDefinitionFormation.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionFormation.def("Init", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_Product> &)) &StepBasic_ProductDefinitionFormation::Init, "None", py::arg("aId"), py::arg("aDescription"), py::arg("aOfProduct"));
cls_StepBasic_ProductDefinitionFormation.def("SetId", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormation::SetId, "None", py::arg("aId"));
cls_StepBasic_ProductDefinitionFormation.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormation::*)() const) &StepBasic_ProductDefinitionFormation::Id, "None");
cls_StepBasic_ProductDefinitionFormation.def("SetDescription", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormation::SetDescription, "None", py::arg("aDescription"));
cls_StepBasic_ProductDefinitionFormation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormation::*)() const) &StepBasic_ProductDefinitionFormation::Description, "None");
cls_StepBasic_ProductDefinitionFormation.def("SetOfProduct", (void (StepBasic_ProductDefinitionFormation::*)(const opencascade::handle<StepBasic_Product> &)) &StepBasic_ProductDefinitionFormation::SetOfProduct, "None", py::arg("aOfProduct"));
cls_StepBasic_ProductDefinitionFormation.def("OfProduct", (opencascade::handle<StepBasic_Product> (StepBasic_ProductDefinitionFormation::*)() const) &StepBasic_ProductDefinitionFormation::OfProduct, "None");
cls_StepBasic_ProductDefinitionFormation.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormation::get_type_name, "None");
cls_StepBasic_ProductDefinitionFormation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormation::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionFormation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormation::*)() const) &StepBasic_ProductDefinitionFormation::DynamicType, "None");

// Enums

}