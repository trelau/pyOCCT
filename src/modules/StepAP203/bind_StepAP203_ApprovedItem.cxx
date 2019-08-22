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
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepAP203_ChangeRequest.hxx>
#include <StepAP203_Change.hxx>
#include <StepAP203_StartRequest.hxx>
#include <StepAP203_StartWork.hxx>
#include <StepBasic_Certification.hxx>
#include <StepBasic_Contract.hxx>
#include <StepAP203_ApprovedItem.hxx>

void bind_StepAP203_ApprovedItem(py::module &mod){

py::class_<StepAP203_ApprovedItem, StepData_SelectType> cls_StepAP203_ApprovedItem(mod, "StepAP203_ApprovedItem", "Representation of STEP SELECT type ApprovedItem");

// Constructors
cls_StepAP203_ApprovedItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP203_ApprovedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP203_ApprovedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP203_ApprovedItem.def_static("operator delete_", (void (*)(void *)) &StepAP203_ApprovedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP203_ApprovedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP203_ApprovedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP203_ApprovedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP203_ApprovedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP203_ApprovedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP203_ApprovedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP203_ApprovedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP203_ApprovedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP203_ApprovedItem.def("CaseNum", (Standard_Integer (StepAP203_ApprovedItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP203_ApprovedItem::CaseNum, "Recognizes a kind of ApprovedItem select type 1 -> ProductDefinitionFormation from StepBasic 2 -> ProductDefinition from StepBasic 3 -> ConfigurationEffectivity from StepRepr 4 -> ConfigurationItem from StepRepr 5 -> SecurityClassification from StepBasic 6 -> ChangeRequest from StepAP203 7 -> Change from StepAP203 8 -> StartRequest from StepAP203 9 -> StartWork from StepAP203 10 -> Certification from StepBasic 11 -> Contract from StepBasic 0 else", py::arg("ent"));
cls_StepAP203_ApprovedItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
cls_StepAP203_ApprovedItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepAP203_ApprovedItem.def("ConfigurationEffectivity", (opencascade::handle<StepRepr_ConfigurationEffectivity> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::ConfigurationEffectivity, "Returns Value as ConfigurationEffectivity (or Null if another type)");
cls_StepAP203_ApprovedItem.def("ConfigurationItem", (opencascade::handle<StepRepr_ConfigurationItem> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::ConfigurationItem, "Returns Value as ConfigurationItem (or Null if another type)");
cls_StepAP203_ApprovedItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
cls_StepAP203_ApprovedItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
cls_StepAP203_ApprovedItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::Change, "Returns Value as Change (or Null if another type)");
cls_StepAP203_ApprovedItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
cls_StepAP203_ApprovedItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::StartWork, "Returns Value as StartWork (or Null if another type)");
cls_StepAP203_ApprovedItem.def("Certification", (opencascade::handle<StepBasic_Certification> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::Certification, "Returns Value as Certification (or Null if another type)");
cls_StepAP203_ApprovedItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_ApprovedItem::*)() const) &StepAP203_ApprovedItem::Contract, "Returns Value as Contract (or Null if another type)");

// Enums

}