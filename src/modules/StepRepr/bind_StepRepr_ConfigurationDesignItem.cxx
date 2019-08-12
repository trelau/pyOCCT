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
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepRepr_ConfigurationDesignItem.hxx>

void bind_StepRepr_ConfigurationDesignItem(py::module &mod){

py::class_<StepRepr_ConfigurationDesignItem, std::unique_ptr<StepRepr_ConfigurationDesignItem, Deleter<StepRepr_ConfigurationDesignItem>>, StepData_SelectType> cls_StepRepr_ConfigurationDesignItem(mod, "StepRepr_ConfigurationDesignItem", "Representation of STEP SELECT type ConfigurationDesignItem");

// Constructors
cls_StepRepr_ConfigurationDesignItem.def(py::init<>());

// Fields

// Methods
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new_", (void * (*)(size_t)) &StepRepr_ConfigurationDesignItem::operator new, "None", py::arg("theSize"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete_", (void (*)(void *)) &StepRepr_ConfigurationDesignItem::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_ConfigurationDesignItem::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_ConfigurationDesignItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_ConfigurationDesignItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_ConfigurationDesignItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_ConfigurationDesignItem.def("CaseNum", (Standard_Integer (StepRepr_ConfigurationDesignItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_ConfigurationDesignItem::CaseNum, "Recognizes a kind of ConfigurationDesignItem select type 1 -> ProductDefinition from StepBasic 2 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
cls_StepRepr_ConfigurationDesignItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepRepr_ConfigurationDesignItem::*)() const) &StepRepr_ConfigurationDesignItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepRepr_ConfigurationDesignItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepRepr_ConfigurationDesignItem::*)() const) &StepRepr_ConfigurationDesignItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

// Enums

}