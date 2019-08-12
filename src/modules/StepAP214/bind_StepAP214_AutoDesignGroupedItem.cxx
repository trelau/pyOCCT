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
#include <StepShape_AdvancedBrepShapeRepresentation.hxx>
#include <StepShape_CsgShapeRepresentation.hxx>
#include <StepShape_FacetedBrepShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedSurfaceShapeRepresentation.hxx>
#include <StepShape_GeometricallyBoundedWireframeShapeRepresentation.hxx>
#include <StepShape_ManifoldSurfaceShapeRepresentation.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <StepVisual_TemplateInstance.hxx>
#include <StepAP214_AutoDesignGroupedItem.hxx>

void bind_StepAP214_AutoDesignGroupedItem(py::module &mod){

py::class_<StepAP214_AutoDesignGroupedItem, std::unique_ptr<StepAP214_AutoDesignGroupedItem, Deleter<StepAP214_AutoDesignGroupedItem>>, StepData_SelectType> cls_StepAP214_AutoDesignGroupedItem(mod, "StepAP214_AutoDesignGroupedItem", "None");

// Constructors
cls_StepAP214_AutoDesignGroupedItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_AutoDesignGroupedItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_AutoDesignGroupedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_AutoDesignGroupedItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_AutoDesignGroupedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_AutoDesignGroupedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_AutoDesignGroupedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_AutoDesignGroupedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_AutoDesignGroupedItem.def("CaseNum", (Standard_Integer (StepAP214_AutoDesignGroupedItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_AutoDesignGroupedItem::CaseNum, "Recognizes a AutoDesignGroupedItem Kind Entity that is : 1 -> AdvancedBrepShapeRepresentation 2 -> CsgShapeRepresentation 3 -> FacetedBrepShapeRepresentation 4 -> GeometricallyBoundedSurfaceShapeRepresentation 5 -> GeometricallyBoundedWireframeShapeRepresentation 6 -> ManifoldSurfaceShapeRepresentation 7 -> Representation 8 -> RepresentationItem 9 -> ShapeAspect 10 -> ShapeRepresentation 11 -> TemplateInstance 0 else", py::arg("ent"));
cls_StepAP214_AutoDesignGroupedItem.def("AdvancedBrepShapeRepresentation", (opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::AdvancedBrepShapeRepresentation, "returns Value as a AdvancedBrepShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("CsgShapeRepresentation", (opencascade::handle<StepShape_CsgShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::CsgShapeRepresentation, "returns Value as a CsgShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("FacetedBrepShapeRepresentation", (opencascade::handle<StepShape_FacetedBrepShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::FacetedBrepShapeRepresentation, "returns Value as a FacetedBrepShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("GeometricallyBoundedSurfaceShapeRepresentation", (opencascade::handle<StepShape_GeometricallyBoundedSurfaceShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::GeometricallyBoundedSurfaceShapeRepresentation, "returns Value as a GeometricallyBoundedSurfaceShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("GeometricallyBoundedWireframeShapeRepresentation", (opencascade::handle<StepShape_GeometricallyBoundedWireframeShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::GeometricallyBoundedWireframeShapeRepresentation, "returns Value as a GeometricallyBoundedWireframeShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ManifoldSurfaceShapeRepresentation", (opencascade::handle<StepShape_ManifoldSurfaceShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ManifoldSurfaceShapeRepresentation, "returns Value as a ManifoldSurfaceShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("ShapeRepresentation", (opencascade::handle<StepShape_ShapeRepresentation> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::ShapeRepresentation, "returns Value as a ShapeRepresentation (Null if another type)");
cls_StepAP214_AutoDesignGroupedItem.def("TemplateInstance", (opencascade::handle<StepVisual_TemplateInstance> (StepAP214_AutoDesignGroupedItem::*)() const) &StepAP214_AutoDesignGroupedItem::TemplateInstance, "returns Value as a TemplateInstance (Null if another type)");

// Enums

}