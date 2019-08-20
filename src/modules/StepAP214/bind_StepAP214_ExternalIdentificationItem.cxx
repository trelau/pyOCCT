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
#include <StepBasic_DocumentFile.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepBasic_Approval.hxx>
#include <StepBasic_ApprovalStatus.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_OrganizationalAddress.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepGeom_TrimmedCurve.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <StepBasic_DateAssignment.hxx>
#include <StepAP214_ExternalIdentificationItem.hxx>

void bind_StepAP214_ExternalIdentificationItem(py::module &mod){

py::class_<StepAP214_ExternalIdentificationItem, std::unique_ptr<StepAP214_ExternalIdentificationItem>, StepData_SelectType> cls_StepAP214_ExternalIdentificationItem(mod, "StepAP214_ExternalIdentificationItem", "Representation of STEP SELECT type ExternalIdentificationItem");

// Constructors
cls_StepAP214_ExternalIdentificationItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_ExternalIdentificationItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_ExternalIdentificationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_ExternalIdentificationItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_ExternalIdentificationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_ExternalIdentificationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_ExternalIdentificationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_ExternalIdentificationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_ExternalIdentificationItem.def("CaseNum", (Standard_Integer (StepAP214_ExternalIdentificationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_ExternalIdentificationItem::CaseNum, "Recognizes a kind of ExternalIdentificationItem select type 1 -> DocumentFile from StepBasic 2 -> ExternallyDefinedClass from StepAP214 3 -> ExternallyDefinedGeneralProperty from StepAP214 4 -> ProductDefinition from StepBasic 5 -> AppliedOrganizationAssignment from AP214 6 -> AppliedPersonAndOrganizationAssignment from AP214 7 -> Approval from StepBasic 8 -> ApprovalStatus from StepBasic 9 -> ExternalSource from StepBasic 10 -> OrganizationalAddress from StepBasic 11 -> SecurityClassification from StepBasic 12 -> TrimmedCurve from StepGeom 13 -> VersionedActionRequest from StepBasic 14 -> DateAndTimeAssignment from StepBasic 15 -> DateAssignment from StepBasic 0 else", py::arg("ent"));
cls_StepAP214_ExternalIdentificationItem.def("DocumentFile", (opencascade::handle<StepBasic_DocumentFile> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DocumentFile, "Returns Value as DocumentFile (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternallyDefinedClass", (opencascade::handle<StepAP214_ExternallyDefinedClass> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternallyDefinedClass, "Returns Value as ExternallyDefinedClass (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternallyDefinedGeneralProperty", (opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternallyDefinedGeneralProperty, "Returns Value as ExternallyDefinedGeneralProperty (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("AppliedOrganizationAssignment", (opencascade::handle<StepAP214_AppliedOrganizationAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::AppliedOrganizationAssignment, "Returns Value as AppliedOrganizationAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("AppliedPersonAndOrganizationAssignment", (opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::AppliedPersonAndOrganizationAssignment, "Returns Value as AppliedPersonAndOrganizationAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("Approval", (opencascade::handle<StepBasic_Approval> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::Approval, "Returns Value as Approval (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ApprovalStatus", (opencascade::handle<StepBasic_ApprovalStatus> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ApprovalStatus, "Returns Value as ApprovalStatus (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("ExternalSource", (opencascade::handle<StepBasic_ExternalSource> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::ExternalSource, "Returns Value as ExternalSource (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("OrganizationalAddress", (opencascade::handle<StepBasic_OrganizationalAddress> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::OrganizationalAddress, "Returns Value as OrganizationalAddress (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("TrimmedCurve", (opencascade::handle<StepGeom_TrimmedCurve> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::TrimmedCurve, "Returns Value as TrimmedCurve (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("VersionedActionRequest", (opencascade::handle<StepBasic_VersionedActionRequest> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::VersionedActionRequest, "Returns Value as VersionedActionRequest (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("DateAndTimeAssignment", (opencascade::handle<StepBasic_DateAndTimeAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DateAndTimeAssignment, "Returns Value as DateAndTimeAssignment (or Null if another type)");
cls_StepAP214_ExternalIdentificationItem.def("DateAssignment", (opencascade::handle<StepBasic_DateAssignment> (StepAP214_ExternalIdentificationItem::*)() const) &StepAP214_ExternalIdentificationItem::DateAssignment, "Returns Value as DateAssignment (or Null if another type)");

// Enums

}