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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepRepr_Representation.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepVisual_StyledItemTarget.hxx>

void bind_StepVisual_StyledItemTarget(py::module &mod){

py::class_<StepVisual_StyledItemTarget, StepData_SelectType> cls_StepVisual_StyledItemTarget(mod, "StepVisual_StyledItemTarget", "None");

// Constructors
cls_StepVisual_StyledItemTarget.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_StyledItemTarget.def_static("operator new_", (void * (*)(size_t)) &StepVisual_StyledItemTarget::operator new, "None", py::arg("theSize"));
// cls_StepVisual_StyledItemTarget.def_static("operator delete_", (void (*)(void *)) &StepVisual_StyledItemTarget::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_StyledItemTarget.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_StyledItemTarget::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_StyledItemTarget.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_StyledItemTarget::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_StyledItemTarget.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_StyledItemTarget::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_StyledItemTarget.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_StyledItemTarget::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_StyledItemTarget.def("CaseNum", (Standard_Integer (StepVisual_StyledItemTarget::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_StyledItemTarget::CaseNum, "Recognizes a StyledItemTarget Kind Entity that is : 1 -> GeometricRepresentationItem 2 -> MappedItem 3 -> Representation 4 -> TopologicalRepresentationItem 0 else", py::arg("ent"));
cls_StepVisual_StyledItemTarget.def("GeometricRepresentationItem", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepVisual_StyledItemTarget::*)() const) &StepVisual_StyledItemTarget::GeometricRepresentationItem, "returns Value as a GeometricRepresentationItem (Null if another type)");
cls_StepVisual_StyledItemTarget.def("MappedItem", (opencascade::handle<StepRepr_MappedItem> (StepVisual_StyledItemTarget::*)() const) &StepVisual_StyledItemTarget::MappedItem, "returns Value as a MappedItem (Null if another type)");
cls_StepVisual_StyledItemTarget.def("Representation", (opencascade::handle<StepRepr_Representation> (StepVisual_StyledItemTarget::*)() const) &StepVisual_StyledItemTarget::Representation, "returns Value as a Representation (Null if another type)");
cls_StepVisual_StyledItemTarget.def("TopologicalRepresentationItem", (opencascade::handle<StepShape_TopologicalRepresentationItem> (StepVisual_StyledItemTarget::*)() const) &StepVisual_StyledItemTarget::TopologicalRepresentationItem, "returns Value as a TopologicalRepresentationItem (Null if another type)");

// Enums

}