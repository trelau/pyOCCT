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
#include <StepAP203_Change.hxx>
#include <StepAP203_StartWork.hxx>
#include <StepAP203_ChangeRequest.hxx>
#include <StepAP203_StartRequest.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_Contract.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepAP203_PersonOrganizationItem.hxx>

void bind_StepAP203_PersonOrganizationItem(py::module &mod){

py::class_<StepAP203_PersonOrganizationItem, StepData_SelectType> cls_StepAP203_PersonOrganizationItem(mod, "StepAP203_PersonOrganizationItem", "Representation of STEP SELECT type PersonOrganizationItem");

// Constructors
cls_StepAP203_PersonOrganizationItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP203_PersonOrganizationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP203_PersonOrganizationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP203_PersonOrganizationItem.def_static("operator delete_", (void (*)(void *)) &StepAP203_PersonOrganizationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP203_PersonOrganizationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP203_PersonOrganizationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP203_PersonOrganizationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP203_PersonOrganizationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP203_PersonOrganizationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP203_PersonOrganizationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP203_PersonOrganizationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP203_PersonOrganizationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP203_PersonOrganizationItem.def("CaseNum", (Standard_Integer (StepAP203_PersonOrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP203_PersonOrganizationItem::CaseNum, "Recognizes a kind of PersonOrganizationItem select type 1 -> Change from StepAP203 2 -> StartWork from StepAP203 3 -> ChangeRequest from StepAP203 4 -> StartRequest from StepAP203 5 -> ConfigurationItem from StepRepr 6 -> Product from StepBasic 7 -> ProductDefinitionFormation from StepBasic 8 -> ProductDefinition from StepBasic 9 -> Contract from StepBasic 10 -> SecurityClassification from StepBasic 0 else", py::arg("ent"));
cls_StepAP203_PersonOrganizationItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::Change, "Returns Value as Change (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::StartWork, "Returns Value as StartWork (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("ConfigurationItem", (opencascade::handle<StepRepr_ConfigurationItem> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::ConfigurationItem, "Returns Value as ConfigurationItem (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("Product", (opencascade::handle<StepBasic_Product> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::Product, "Returns Value as Product (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::Contract, "Returns Value as Contract (or Null if another type)");
cls_StepAP203_PersonOrganizationItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_PersonOrganizationItem::*)() const) &StepAP203_PersonOrganizationItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");

// Enums

}