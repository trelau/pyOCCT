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
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepGeom_Placement.hxx>
#include <StepShape_ShapeDimensionRepresentationItem.hxx>

void bind_StepShape_ShapeDimensionRepresentationItem(py::module &mod){

py::class_<StepShape_ShapeDimensionRepresentationItem, std::unique_ptr<StepShape_ShapeDimensionRepresentationItem, Deleter<StepShape_ShapeDimensionRepresentationItem>>, StepData_SelectType> cls_StepShape_ShapeDimensionRepresentationItem(mod, "StepShape_ShapeDimensionRepresentationItem", "None");

// Constructors
cls_StepShape_ShapeDimensionRepresentationItem.def(py::init<>());

// Fields

// Methods
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator new_", (void * (*)(size_t)) &StepShape_ShapeDimensionRepresentationItem::operator new, "None", py::arg("theSize"));
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator delete_", (void (*)(void *)) &StepShape_ShapeDimensionRepresentationItem::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_ShapeDimensionRepresentationItem::operator new[], "None", py::arg("theSize"));
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator delete[]_", (void (*)(void *)) &StepShape_ShapeDimensionRepresentationItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_ShapeDimensionRepresentationItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_ShapeDimensionRepresentationItem.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_ShapeDimensionRepresentationItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_ShapeDimensionRepresentationItem.def("CaseNum", (Standard_Integer (StepShape_ShapeDimensionRepresentationItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_ShapeDimensionRepresentationItem::CaseNum, "Recognizes a ShapeDimensionRepresentationItem Kind Entity that is : 1 -> CompoundRepresentationItem 2 -> DescriptiveRepresentationItem 3 -> MeasureRepresentationItem 4 -> Placement 0 else", py::arg("ent"));
cls_StepShape_ShapeDimensionRepresentationItem.def("CompoundRepresentationItem", (opencascade::handle<StepRepr_CompoundRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const) &StepShape_ShapeDimensionRepresentationItem::CompoundRepresentationItem, "returns Value as a CompoundRepresentationItem (Null if another type)");
cls_StepShape_ShapeDimensionRepresentationItem.def("DescriptiveRepresentationItem", (opencascade::handle<StepRepr_DescriptiveRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const) &StepShape_ShapeDimensionRepresentationItem::DescriptiveRepresentationItem, "returns Value as a DescriptiveRepresentationItem (Null if another type)");
cls_StepShape_ShapeDimensionRepresentationItem.def("MeasureRepresentationItem", (opencascade::handle<StepRepr_MeasureRepresentationItem> (StepShape_ShapeDimensionRepresentationItem::*)() const) &StepShape_ShapeDimensionRepresentationItem::MeasureRepresentationItem, "returns Value as a MeasureRepresentationItem (Null if another type)");
cls_StepShape_ShapeDimensionRepresentationItem.def("Placement", (opencascade::handle<StepGeom_Placement> (StepShape_ShapeDimensionRepresentationItem::*)() const) &StepShape_ShapeDimensionRepresentationItem::Placement, "returns Value as a Placement (Null if another type)");

// Enums

}