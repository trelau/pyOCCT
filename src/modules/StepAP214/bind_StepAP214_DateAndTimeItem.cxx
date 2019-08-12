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
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_DateAndTimeItem.hxx>

void bind_StepAP214_DateAndTimeItem(py::module &mod){

py::class_<StepAP214_DateAndTimeItem, std::unique_ptr<StepAP214_DateAndTimeItem, Deleter<StepAP214_DateAndTimeItem>>, StepAP214_ApprovalItem> cls_StepAP214_DateAndTimeItem(mod, "StepAP214_DateAndTimeItem", "None");

// Constructors
cls_StepAP214_DateAndTimeItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_DateAndTimeItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_DateAndTimeItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_DateAndTimeItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_DateAndTimeItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_DateAndTimeItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_DateAndTimeItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_DateAndTimeItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_DateAndTimeItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_DateAndTimeItem.def("CaseNum", (Standard_Integer (StepAP214_DateAndTimeItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_DateAndTimeItem::CaseNum, "Recognizes a DateAndTimeItem Kind Entity that is : 1 -> ApprovalPersonOrganization 2 -> AppliedDateAndPersonAssignment 3 -> AppliedOrganizationAssignment 4 -> AssemblyComponentUsageSubstitute 5 -> DocumentFile 6 -> Effectivity 7 -> MaterialDesignation 8 -> MechanicalDesignGeometricPresentationRepresentation 9 -> PresentationArea 10 -> Product 11 -> ProductDefinition 12 -> ProductDefinitionFormation 13 -> ProductDefinitionRelationship 14 -> PropertyDefinition 15 -> ShapeRepresentation 16 -> SecurityClassification 0 else", py::arg("ent"));
cls_StepAP214_DateAndTimeItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::ApprovalPersonOrganization, "returns Value as a ApprovalPersonOrganization (Null if another type)");
cls_StepAP214_DateAndTimeItem.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::AppliedPersonAndOrganizationAssignment, "returns Value as a AppliedDateAndPersonAssignment (Null if another type)");
cls_StepAP214_DateAndTimeItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_DateAndTimeItem::*)() const) &StepAP214_DateAndTimeItem::AppliedOrganizationAssignment, "returns Value as a AppliedOrganizationAssignment (Null if another type)");

// Enums

}