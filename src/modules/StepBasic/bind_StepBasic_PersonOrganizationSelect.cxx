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
#include <StepBasic_Person.hxx>
#include <StepBasic_Organization.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonOrganizationSelect.hxx>

void bind_StepBasic_PersonOrganizationSelect(py::module &mod){

py::class_<StepBasic_PersonOrganizationSelect, StepData_SelectType> cls_StepBasic_PersonOrganizationSelect(mod, "StepBasic_PersonOrganizationSelect", "None");

// Constructors
cls_StepBasic_PersonOrganizationSelect.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_PersonOrganizationSelect.def_static("operator new_", (void * (*)(size_t)) &StepBasic_PersonOrganizationSelect::operator new, "None", py::arg("theSize"));
// cls_StepBasic_PersonOrganizationSelect.def_static("operator delete_", (void (*)(void *)) &StepBasic_PersonOrganizationSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_PersonOrganizationSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_PersonOrganizationSelect::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_PersonOrganizationSelect.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_PersonOrganizationSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_PersonOrganizationSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_PersonOrganizationSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_PersonOrganizationSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_PersonOrganizationSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_PersonOrganizationSelect.def("CaseNum", (Standard_Integer (StepBasic_PersonOrganizationSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_PersonOrganizationSelect::CaseNum, "Recognizes a PersonOrganizationSelect Kind Entity that is : 1 -> Person 2 -> Organization 3 -> PersonAndOrganization 0 else", py::arg("ent"));
cls_StepBasic_PersonOrganizationSelect.def("Person", (opencascade::handle<StepBasic_Person> (StepBasic_PersonOrganizationSelect::*)() const) &StepBasic_PersonOrganizationSelect::Person, "returns Value as a Person (Null if another type)");
cls_StepBasic_PersonOrganizationSelect.def("Organization", (opencascade::handle<StepBasic_Organization> (StepBasic_PersonOrganizationSelect::*)() const) &StepBasic_PersonOrganizationSelect::Organization, "returns Value as a Organization (Null if another type)");
cls_StepBasic_PersonOrganizationSelect.def("PersonAndOrganization", (opencascade::handle<StepBasic_PersonAndOrganization> (StepBasic_PersonOrganizationSelect::*)() const) &StepBasic_PersonOrganizationSelect::PersonAndOrganization, "returns Value as a PersonAndOrganization (Null if another type)");

// Enums

}