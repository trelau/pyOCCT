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
#include <StepBasic_CharacterizedObject.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <StepRepr_CharacterizedDefinition.hxx>

void bind_StepRepr_CharacterizedDefinition(py::module &mod){

py::class_<StepRepr_CharacterizedDefinition, StepData_SelectType> cls_StepRepr_CharacterizedDefinition(mod, "StepRepr_CharacterizedDefinition", "Representation of STEP SELECT type CharacterizedDefinition");

// Constructors
cls_StepRepr_CharacterizedDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepRepr_CharacterizedDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_CharacterizedDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_CharacterizedDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_CharacterizedDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_CharacterizedDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_CharacterizedDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_CharacterizedDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_CharacterizedDefinition.def("CaseNum", (Standard_Integer (StepRepr_CharacterizedDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_CharacterizedDefinition::CaseNum, "Recognizes a kind of CharacterizedDefinition select type 1 -> CharacterizedObject from StepBasic 2 -> ProductDefinition from StepBasic 3 -> ProductDefinitionRelationship from StepBasic 4 -> ProductDefinitionShape from StepRepr 5 -> ShapeAspect from StepRepr 6 -> ShapeAspectRelationship from StepRepr 7 -> DocumentFile from StepBasic 0 else", py::arg("ent"));
cls_StepRepr_CharacterizedDefinition.def("CharacterizedObject", (opencascade::handle<StepBasic_CharacterizedObject> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::CharacterizedObject, "Returns Value as CharacterizedObject (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinitionRelationship, "Returns Value as ProductDefinitionRelationship (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinitionShape, "Returns Value as ProductDefinitionShape (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ShapeAspect, "Returns Value as ShapeAspect (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ShapeAspectRelationship, "Returns Value as ShapeAspectRelationship (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("DocumentFile", (opencascade::handle<StepBasic_DocumentFile> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::DocumentFile, "Returns Value as DocumentFile (or Null if another type)");

// Enums

}