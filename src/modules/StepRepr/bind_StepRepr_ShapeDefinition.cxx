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
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepRepr_ShapeDefinition.hxx>

void bind_StepRepr_ShapeDefinition(py::module &mod){

py::class_<StepRepr_ShapeDefinition, std::unique_ptr<StepRepr_ShapeDefinition>, StepData_SelectType> cls_StepRepr_ShapeDefinition(mod, "StepRepr_ShapeDefinition", "None");

// Constructors
cls_StepRepr_ShapeDefinition.def(py::init<>());

// Fields

// Methods
// cls_StepRepr_ShapeDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_ShapeDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_ShapeDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_ShapeDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_ShapeDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_ShapeDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_ShapeDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_ShapeDefinition.def("CaseNum", (Standard_Integer (StepRepr_ShapeDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_ShapeDefinition::CaseNum, "Recognizes a ShapeDefinition Kind Entity that is : 1 -> ProductDefinitionShape 2 -> ShapeAspect 3 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepRepr_ShapeDefinition.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
cls_StepRepr_ShapeDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepRepr_ShapeDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// Enums

}