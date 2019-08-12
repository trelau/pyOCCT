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
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <StepAP214_AutoDesignDatedItem.hxx>

void bind_StepAP214_AutoDesignDatedItem(py::module &mod){

py::class_<StepAP214_AutoDesignDatedItem, std::unique_ptr<StepAP214_AutoDesignDatedItem, Deleter<StepAP214_AutoDesignDatedItem>>, StepData_SelectType> cls_StepAP214_AutoDesignDatedItem(mod, "StepAP214_AutoDesignDatedItem", "None");

// Constructors
cls_StepAP214_AutoDesignDatedItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignDatedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignDatedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignDatedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignDatedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignDatedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignDatedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignDatedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignDatedItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignDatedItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignDatedItem::CaseNum, "Recognizes a AutoDesignDatedItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AutoDesignDateAndPersonAssignment 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignDatedItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_AutoDesignDatedItem.def("AutoDesignDateAndPersonAssignment", (opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::AutoDesignDateAndPersonAssignment, "returns Value as a AutoDesignDateAndPersonAssignment (Null if another type)");
cls_StepAP214_AutoDesignDatedItem.def("ProductDefinitionEffectivity", (opencascade::handle<StepBasic_ProductDefinitionEffectivity> (StepAP214_AutoDesignDatedItem::*)() const) &StepAP214_AutoDesignDatedItem::ProductDefinitionEffectivity, "returns Value as a ProductDefinitionEffectivity");

// Enums

}