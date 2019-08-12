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
#include <StepAP203_ChangeRequest.hxx>
#include <StepAP203_StartRequest.hxx>
#include <StepAP203_Change.hxx>
#include <StepAP203_StartWork.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepBasic_Contract.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepBasic_Certification.hxx>
#include <StepAP203_DateTimeItem.hxx>

void bind_StepAP203_DateTimeItem(py::module &mod){

py::class_<StepAP203_DateTimeItem, std::unique_ptr<StepAP203_DateTimeItem, Deleter<StepAP203_DateTimeItem>>, StepData_SelectType> cls_StepAP203_DateTimeItem(mod, "StepAP203_DateTimeItem", "Representation of STEP SELECT type DateTimeItem");

// Constructors
cls_StepAP203_DateTimeItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP203_DateTimeItem.def_static("operator new_", (void * (*)(size_t)) &StepAP203_DateTimeItem::operator new, "None", py::arg("theSize"));
// cls_StepAP203_DateTimeItem.def_static("operator delete_", (void (*)(void *)) &StepAP203_DateTimeItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP203_DateTimeItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP203_DateTimeItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP203_DateTimeItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP203_DateTimeItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP203_DateTimeItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP203_DateTimeItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP203_DateTimeItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP203_DateTimeItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP203_DateTimeItem.def("CaseNum", (Standard_Integer (StepAP203_DateTimeItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP203_DateTimeItem::CaseNum, "Recognizes a kind of DateTimeItem select type 1 -> ProductDefinition from StepBasic 2 -> ChangeRequest from StepAP203 3 -> StartRequest from StepAP203 4 -> Change from StepAP203 5 -> StartWork from StepAP203 6 -> ApprovalPersonOrganization from StepBasic 7 -> Contract from StepBasic 8 -> SecurityClassification from StepBasic 9 -> Certification from StepBasic 0 else", py::arg("ent"));
cls_StepAP203_DateTimeItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepAP203_DateTimeItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
cls_StepAP203_DateTimeItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
cls_StepAP203_DateTimeItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::Change, "Returns Value as Change (or Null if another type)");
cls_StepAP203_DateTimeItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::StartWork, "Returns Value as StartWork (or Null if another type)");
cls_StepAP203_DateTimeItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::ApprovalPersonOrganization, "Returns Value as ApprovalPersonOrganization (or Null if another type)");
cls_StepAP203_DateTimeItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::Contract, "Returns Value as Contract (or Null if another type)");
cls_StepAP203_DateTimeItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
cls_StepAP203_DateTimeItem.def("Certification", (opencascade::handle<StepBasic_Certification> (StepAP203_DateTimeItem::*)() const) &StepAP203_DateTimeItem::Certification, "Returns Value as Certification (or Null if another type)");

// Enums

}