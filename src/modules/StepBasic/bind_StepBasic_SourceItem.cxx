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
#include <StepData_SelectMember.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_SourceItem.hxx>

void bind_StepBasic_SourceItem(py::module &mod){

py::class_<StepBasic_SourceItem, std::unique_ptr<StepBasic_SourceItem, Deleter<StepBasic_SourceItem>>, StepData_SelectType> cls_StepBasic_SourceItem(mod, "StepBasic_SourceItem", "Representation of STEP SELECT type SourceItem");

// Constructors
cls_StepBasic_SourceItem.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_SourceItem.def_static("operator new_", (void * (*)(size_t)) &StepBasic_SourceItem::operator new, "None", py::arg("theSize"));
// cls_StepBasic_SourceItem.def_static("operator delete_", (void (*)(void *)) &StepBasic_SourceItem::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_SourceItem.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_SourceItem::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_SourceItem.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_SourceItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_SourceItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_SourceItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_SourceItem.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_SourceItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_SourceItem.def("CaseNum", (Standard_Integer (StepBasic_SourceItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_SourceItem::CaseNum, "Recognizes a kind of SourceItem select type 1 -> HAsciiString from TCollection 0 else", py::arg("ent"));
cls_StepBasic_SourceItem.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepBasic_SourceItem::*)() const) &StepBasic_SourceItem::NewMember, "None");
cls_StepBasic_SourceItem.def("Identifier", (opencascade::handle<TCollection_HAsciiString> (StepBasic_SourceItem::*)() const) &StepBasic_SourceItem::Identifier, "Returns Value as Identifier (or Null if another type)");

// Enums

}