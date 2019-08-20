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
#include <StepBasic_GeneralProperty.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_PropertyDefinitionRelationship.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepRepr_RepresentedDefinition.hxx>

void bind_StepRepr_RepresentedDefinition(py::module &mod){

py::class_<StepRepr_RepresentedDefinition, std::unique_ptr<StepRepr_RepresentedDefinition>, StepData_SelectType> cls_StepRepr_RepresentedDefinition(mod, "StepRepr_RepresentedDefinition", "Representation of STEP SELECT type RepresentedDefinition");

// Constructors
cls_StepRepr_RepresentedDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepRepr_RepresentedDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_RepresentedDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_RepresentedDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_RepresentedDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_RepresentedDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_RepresentedDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_RepresentedDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_RepresentedDefinition.def("CaseNum", (Standard_Integer (StepRepr_RepresentedDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_RepresentedDefinition::CaseNum, "Recognizes a kind of RepresentedDefinition select type 1 -> GeneralProperty from StepBasic 2 -> PropertyDefinition from StepRepr 3 -> PropertyDefinitionRelationship from StepRepr 4 -> ShapeAspect from StepRepr 5 -> ShapeAspectRelationship from StepRepr 0 else", py::arg("ent"));
cls_StepRepr_RepresentedDefinition.def("GeneralProperty", (opencascade::handle<StepBasic_GeneralProperty> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::GeneralProperty, "Returns Value as GeneralProperty (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::PropertyDefinition, "Returns Value as PropertyDefinition (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("PropertyDefinitionRelationship", (opencascade::handle<StepRepr_PropertyDefinitionRelationship> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::PropertyDefinitionRelationship, "Returns Value as PropertyDefinitionRelationship (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::ShapeAspect, "Returns Value as ShapeAspect (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::ShapeAspectRelationship, "Returns Value as ShapeAspectRelationship (or Null if another type)");

// Enums

}