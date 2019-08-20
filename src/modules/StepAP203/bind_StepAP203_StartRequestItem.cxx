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
#include <StepAP203_StartRequestItem.hxx>

void bind_StepAP203_StartRequestItem(py::module &mod){

py::class_<StepAP203_StartRequestItem, std::unique_ptr<StepAP203_StartRequestItem>, StepData_SelectType> cls_StepAP203_StartRequestItem(mod, "StepAP203_StartRequestItem", "Representation of STEP SELECT type StartRequestItem");

// Constructors
cls_StepAP203_StartRequestItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP203_StartRequestItem.def_static("operator new_", (void * (*)(size_t)) &StepAP203_StartRequestItem::operator new, "None", py::arg("theSize"));
// cls_StepAP203_StartRequestItem.def_static("operator delete_", (void (*)(void *)) &StepAP203_StartRequestItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP203_StartRequestItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP203_StartRequestItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP203_StartRequestItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP203_StartRequestItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP203_StartRequestItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP203_StartRequestItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP203_StartRequestItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP203_StartRequestItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP203_StartRequestItem.def("CaseNum", (Standard_Integer (StepAP203_StartRequestItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP203_StartRequestItem::CaseNum, "Recognizes a kind of StartRequestItem select type 1 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
cls_StepAP203_StartRequestItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_StartRequestItem::*)() const) &StepAP203_StartRequestItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

// Enums

}