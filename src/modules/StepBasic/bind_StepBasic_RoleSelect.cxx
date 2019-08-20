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
#include <StepBasic_ActionAssignment.hxx>
#include <StepBasic_ActionRequestAssignment.hxx>
#include <StepBasic_ApprovalAssignment.hxx>
#include <StepBasic_ApprovalDateTime.hxx>
#include <StepBasic_CertificationAssignment.hxx>
#include <StepBasic_ContractAssignment.hxx>
#include <StepBasic_DocumentReference.hxx>
#include <StepBasic_EffectivityAssignment.hxx>
#include <StepBasic_GroupAssignment.hxx>
#include <StepBasic_NameAssignment.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <StepBasic_RoleSelect.hxx>

void bind_StepBasic_RoleSelect(py::module &mod){

py::class_<StepBasic_RoleSelect, std::unique_ptr<StepBasic_RoleSelect>, StepData_SelectType> cls_StepBasic_RoleSelect(mod, "StepBasic_RoleSelect", "Representation of STEP SELECT type RoleSelect");

// Constructors
cls_StepBasic_RoleSelect.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_RoleSelect.def_static("operator new_", (void * (*)(size_t)) &StepBasic_RoleSelect::operator new, "None", py::arg("theSize"));
// cls_StepBasic_RoleSelect.def_static("operator delete_", (void (*)(void *)) &StepBasic_RoleSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_RoleSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_RoleSelect::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_RoleSelect.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_RoleSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_RoleSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_RoleSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_RoleSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_RoleSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_RoleSelect.def("CaseNum", (Standard_Integer (StepBasic_RoleSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_RoleSelect::CaseNum, "Recognizes a kind of RoleSelect select type 1 -> ActionAssignment from StepBasic 2 -> ActionRequestAssignment from StepBasic 3 -> ApprovalAssignment from StepBasic 4 -> ApprovalDateTime from StepBasic 5 -> CertificationAssignment from StepBasic 6 -> ContractAssignment from StepBasic 7 -> DocumentReference from StepBasic 8 -> EffectivityAssignment from StepBasic 9 -> GroupAssignment from StepBasic 10 -> NameAssignment from StepBasic 11 -> SecurityClassificationAssignment from StepBasic 0 else", py::arg("ent"));
cls_StepBasic_RoleSelect.def("ActionAssignment", (opencascade::handle<StepBasic_ActionAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::ActionAssignment, "Returns Value as ActionAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("ActionRequestAssignment", (opencascade::handle<StepBasic_ActionRequestAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::ActionRequestAssignment, "Returns Value as ActionRequestAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("ApprovalAssignment", (opencascade::handle<StepBasic_ApprovalAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::ApprovalAssignment, "Returns Value as ApprovalAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("ApprovalDateTime", (opencascade::handle<StepBasic_ApprovalDateTime> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::ApprovalDateTime, "Returns Value as ApprovalDateTime (or Null if another type)");
cls_StepBasic_RoleSelect.def("CertificationAssignment", (opencascade::handle<StepBasic_CertificationAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::CertificationAssignment, "Returns Value as CertificationAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("ContractAssignment", (opencascade::handle<StepBasic_ContractAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::ContractAssignment, "Returns Value as ContractAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("DocumentReference", (opencascade::handle<StepBasic_DocumentReference> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::DocumentReference, "Returns Value as DocumentReference (or Null if another type)");
cls_StepBasic_RoleSelect.def("EffectivityAssignment", (opencascade::handle<StepBasic_EffectivityAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::EffectivityAssignment, "Returns Value as EffectivityAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("GroupAssignment", (opencascade::handle<StepBasic_GroupAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::GroupAssignment, "Returns Value as GroupAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("NameAssignment", (opencascade::handle<StepBasic_NameAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::NameAssignment, "Returns Value as NameAssignment (or Null if another type)");
cls_StepBasic_RoleSelect.def("SecurityClassificationAssignment", (opencascade::handle<StepBasic_SecurityClassificationAssignment> (StepBasic_RoleSelect::*)() const) &StepBasic_RoleSelect::SecurityClassificationAssignment, "Returns Value as SecurityClassificationAssignment (or Null if another type)");

// Enums

}