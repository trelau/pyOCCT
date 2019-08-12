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
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionReference.hxx>
#include <StepBasic_ProductDefinitionReferenceWithLocalRepresentation.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>

void bind_StepBasic_ProductDefinitionOrReference(py::module &mod){

py::class_<StepBasic_ProductDefinitionOrReference, std::unique_ptr<StepBasic_ProductDefinitionOrReference, Deleter<StepBasic_ProductDefinitionOrReference>>, StepData_SelectType> cls_StepBasic_ProductDefinitionOrReference(mod, "StepBasic_ProductDefinitionOrReference", "None");

// Constructors
cls_StepBasic_ProductDefinitionOrReference.def(py::init<>());

// Fields

// Methods
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator new_", (void * (*)(size_t)) &StepBasic_ProductDefinitionOrReference::operator new, "None", py::arg("theSize"));
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator delete_", (void (*)(void *)) &StepBasic_ProductDefinitionOrReference::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_ProductDefinitionOrReference::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_ProductDefinitionOrReference::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_ProductDefinitionOrReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_ProductDefinitionOrReference.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_ProductDefinitionOrReference::operator delete, "None", py::arg(""), py::arg(""));
cls_StepBasic_ProductDefinitionOrReference.def("CaseNum", (Standard_Integer (StepBasic_ProductDefinitionOrReference::*)(const opencascade::handle<Standard_Transient> &) const) &StepBasic_ProductDefinitionOrReference::CaseNum, "Recognizes a ProductDefinitionOrReference Kind Entity that is : 1 -> ProductDefinition 2 -> ProductDefinitionReference 3 -> ProductDefinitionReferenceWithLocalPresentation 0 else", py::arg("ent"));
cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepBasic_ProductDefinitionOrReference::*)() const) &StepBasic_ProductDefinitionOrReference::ProductDefinition, "returns Value as a ProductDefinition (Null if another type)");
cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinitionReference", (opencascade::handle<StepBasic_ProductDefinitionReference> (StepBasic_ProductDefinitionOrReference::*)() const) &StepBasic_ProductDefinitionOrReference::ProductDefinitionReference, "returns Value as a ProductDefinitionReference (Null if another type)");
cls_StepBasic_ProductDefinitionOrReference.def("ProductDefinitionReferenceWithLocalRepresentation", (opencascade::handle<StepBasic_ProductDefinitionReferenceWithLocalRepresentation> (StepBasic_ProductDefinitionOrReference::*)() const) &StepBasic_ProductDefinitionOrReference::ProductDefinitionReferenceWithLocalRepresentation, "returns Value as a ProductDefinitionReferenceWithLocalRepresentation (Null if another type)");

// Enums

}