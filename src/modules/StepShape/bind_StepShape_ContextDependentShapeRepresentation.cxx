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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_ContextDependentShapeRepresentation(py::module &mod){

py::class_<StepShape_ContextDependentShapeRepresentation, opencascade::handle<StepShape_ContextDependentShapeRepresentation>, Standard_Transient> cls_StepShape_ContextDependentShapeRepresentation(mod, "StepShape_ContextDependentShapeRepresentation", "None");

// Constructors
cls_StepShape_ContextDependentShapeRepresentation.def(py::init<>());

// Fields

// Methods
cls_StepShape_ContextDependentShapeRepresentation.def("Init", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationship> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepShape_ContextDependentShapeRepresentation::Init, "None", py::arg("aRepRel"), py::arg("aProRel"));
cls_StepShape_ContextDependentShapeRepresentation.def("RepresentationRelation", (opencascade::handle<StepRepr_ShapeRepresentationRelationship> (StepShape_ContextDependentShapeRepresentation::*)() const) &StepShape_ContextDependentShapeRepresentation::RepresentationRelation, "None");
cls_StepShape_ContextDependentShapeRepresentation.def("SetRepresentationRelation", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ShapeRepresentationRelationship> &)) &StepShape_ContextDependentShapeRepresentation::SetRepresentationRelation, "None", py::arg("aRepRel"));
cls_StepShape_ContextDependentShapeRepresentation.def("RepresentedProductRelation", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepShape_ContextDependentShapeRepresentation::*)() const) &StepShape_ContextDependentShapeRepresentation::RepresentedProductRelation, "None");
cls_StepShape_ContextDependentShapeRepresentation.def("SetRepresentedProductRelation", (void (StepShape_ContextDependentShapeRepresentation::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepShape_ContextDependentShapeRepresentation::SetRepresentedProductRelation, "None", py::arg("aProRel"));
cls_StepShape_ContextDependentShapeRepresentation.def_static("get_type_name_", (const char * (*)()) &StepShape_ContextDependentShapeRepresentation::get_type_name, "None");
cls_StepShape_ContextDependentShapeRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_ContextDependentShapeRepresentation::get_type_descriptor, "None");
cls_StepShape_ContextDependentShapeRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_ContextDependentShapeRepresentation::*)() const) &StepShape_ContextDependentShapeRepresentation::DynamicType, "None");

// Enums

}