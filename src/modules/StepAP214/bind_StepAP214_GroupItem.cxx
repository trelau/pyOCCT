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
#include <StepBasic_GroupRelationship.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_RepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepAP214_GroupItem.hxx>

void bind_StepAP214_GroupItem(py::module &mod){

py::class_<StepAP214_GroupItem, StepData_SelectType> cls_StepAP214_GroupItem(mod, "StepAP214_GroupItem", "None");

// Constructors
cls_StepAP214_GroupItem.def(py::init<>());

// Fields

// Methods
// cls_StepAP214_GroupItem.def_static("operator new_", (void * (*)(size_t)) &StepAP214_GroupItem::operator new, "None", py::arg("theSize"));
// cls_StepAP214_GroupItem.def_static("operator delete_", (void (*)(void *)) &StepAP214_GroupItem::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214_GroupItem::operator new[], "None", py::arg("theSize"));
// cls_StepAP214_GroupItem.def_static("operator delete[]_", (void (*)(void *)) &StepAP214_GroupItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214_GroupItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214_GroupItem.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214_GroupItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214_GroupItem.def("CaseNum", (Standard_Integer (StepAP214_GroupItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepAP214_GroupItem::CaseNum, "Recognizes a GroupItem Kind Entity that is : 1 -> GeometricRepresentationItem 2 -> GroupRelationship 3 -> MappedItem 4 -> ProductDefinition 5 -> ProductDefinitionFormation 6 -> PropertyDefinitionRepresentation 7 -> Representation 8 -> RepresentationItem 9 -> RepresentationRelationshipWithTransformation 10 -> ShapeAspect 11 -> ShapeAspectRelationship 12 -> ShapeRepresentationRelationship 13 -> StyledItem 14 -> TopologicalRepresentationItem 0 else", py::arg("ent"));
cls_StepAP214_GroupItem.def("GeometricRepresentationItem", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::GeometricRepresentationItem, "returns Value as a GeometricRepresentationItem (Null if another type)");
cls_StepAP214_GroupItem.def("GroupRelationship", (opencascade::handle<StepBasic_GroupRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::GroupRelationship, "returns Value as a GroupRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("MappedItem", (opencascade::handle<StepRepr_MappedItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::MappedItem, "returns Value as a MappedItem (Null if another type)");
cls_StepAP214_GroupItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepAP214_GroupItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ProductDefinitionFormation, "returns Value as a ProductDefinitionFormation (Null if another type)");
cls_StepAP214_GroupItem.def("PropertyDefinitionRepresentation", (opencascade::handle<StepRepr_PropertyDefinitionRepresentation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::PropertyDefinitionRepresentation, "returns Value as a PropertyDefinitionRepresentation (Null if another type)");
cls_StepAP214_GroupItem.def("Representation", (opencascade::handle<StepRepr_Representation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::Representation, "returns Value as a Representation (Null if another type)");
cls_StepAP214_GroupItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
cls_StepAP214_GroupItem.def("RepresentationRelationshipWithTransformation", (opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::RepresentationRelationshipWithTransformation, "returns Value as a RepresentationRelationshipWithTransformation (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("ShapeRepresentationRelationship", (opencascade::handle<StepRepr_ShapeRepresentationRelationship> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::ShapeRepresentationRelationship, "returns Value as a ShapeRepresentationRelationship (Null if another type)");
cls_StepAP214_GroupItem.def("StyledItem", (opencascade::handle<StepVisual_StyledItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::StyledItem, "returns Value as a StyledItem (Null if another type)");
cls_StepAP214_GroupItem.def("TopologicalRepresentationItem", (opencascade::handle<StepShape_TopologicalRepresentationItem> (StepAP214_GroupItem::*)() const) &StepAP214_GroupItem::TopologicalRepresentationItem, "returns Value as a TopologicalRepresentationItem (Null if another type)");

// Enums

}