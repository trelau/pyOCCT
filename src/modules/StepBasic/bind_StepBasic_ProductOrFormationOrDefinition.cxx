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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductOrFormationOrDefinition.hxx>

void bind_StepBasic_ProductOrFormationOrDefinition(py::module &mod){

py::class_<StepBasic_ProductOrFormationOrDefinition, std::unique_ptr<StepBasic_ProductOrFormationOrDefinition>, StepData_SelectType> cls_StepBasic_ProductOrFormationOrDefinition(mod, "StepBasic_ProductOrFormationOrDefinition", "Representation of STEP SELECT type ProductOrFormationOrDefinition");

// Constructors
cls_StepBasic_ProductOrFormationOrDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator new_", (void * (*)(size_t)) &StepBasic_ProductOrFormationOrDefinition::operator new, "None", py::arg("theSize"));
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator delete_", (void (*)(void *)) &StepBasic_ProductOrFormationOrDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_ProductOrFormationOrDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_ProductOrFormationOrDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_ProductOrFormationOrDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_ProductOrFormationOrDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_ProductOrFormationOrDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_ProductOrFormationOrDefinition.def("CaseNum", (Standard_Integer (StepBasic_ProductOrFormationOrDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_ProductOrFormationOrDefinition::CaseNum, "Recognizes a kind of ProductOrFormationOrDefinition select type 1 -> Product from StepBasic 2 -> ProductDefinitionFormation from StepBasic 3 -> ProductDefinition from StepBasic 0 else", py::arg("ent"));
cls_StepBasic_ProductOrFormationOrDefinition.def("Product", (opencascade::handle<StepBasic_Product> (StepBasic_ProductOrFormationOrDefinition::*)() const) &StepBasic_ProductOrFormationOrDefinition::Product, "Returns Value as Product (or Null if another type)");
cls_StepBasic_ProductOrFormationOrDefinition.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductOrFormationOrDefinition::*)() const) &StepBasic_ProductOrFormationOrDefinition::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
cls_StepBasic_ProductOrFormationOrDefinition.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductOrFormationOrDefinition::*)() const) &StepBasic_ProductOrFormationOrDefinition::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");

// Enums

}