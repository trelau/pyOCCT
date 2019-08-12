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
#include <StepAP214_ApprovalItem.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepBasic_Approval.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <StepAP214_OrganizationItem.hxx>

void bind_StepAP214_OrganizationItem(py::module &mod){

py::class_<StepAP214_OrganizationItem, std::unique_ptr<StepAP214_OrganizationItem, Deleter<StepAP214_OrganizationItem>>, StepAP214_ApprovalItem> cls_StepAP214_OrganizationItem(mod, "StepAP214_OrganizationItem", "None");

// Constructors
cls_StepAP214_OrganizationItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_OrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_OrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_OrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_OrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_OrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_OrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_OrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_OrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_OrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_OrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_OrganizationItem.def("CaseNum", (Standard_Integer (StepAP214_OrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_OrganizationItem::CaseNum, "Recognizes a OrganizationItem Kind Entity that is :", py::arg("ent"));
cls_StepAP214_OrganizationItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");
cls_StepAP214_OrganizationItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::Approval, "returns Value as a Approval (Null if another type)");
cls_StepAP214_OrganizationItem.def("AppliedSecurityClassificationAssignment", (opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> (StepAP214_OrganizationItem::*)() const) &StepAP214_OrganizationItem::AppliedSecurityClassificationAssignment, "returns Value as a AppliedSecurityClassificationAssignment (Null if another type)");

// Enums

}