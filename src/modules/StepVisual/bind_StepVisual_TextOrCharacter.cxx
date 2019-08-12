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
#include <StepVisual_AnnotationText.hxx>
#include <StepVisual_CompositeText.hxx>
#include <StepVisual_TextLiteral.hxx>
#include <StepVisual_TextOrCharacter.hxx>

void bind_StepVisual_TextOrCharacter(py::module &mod){

py::class_<StepVisual_TextOrCharacter, std::unique_ptr<StepVisual_TextOrCharacter, Deleter<StepVisual_TextOrCharacter>>, StepData_SelectType> cls_StepVisual_TextOrCharacter(mod, "StepVisual_TextOrCharacter", "None");

// Constructors
cls_StepVisual_TextOrCharacter.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_TextOrCharacter.def_static("operator new_", (void * (*)(size_t)) &StepVisual_TextOrCharacter::operator new, "None", py::arg("theSize"));
// cls_StepVisual_TextOrCharacter.def_static("operator delete_", (void (*)(void *)) &StepVisual_TextOrCharacter::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_TextOrCharacter.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_TextOrCharacter::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_TextOrCharacter.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_TextOrCharacter::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_TextOrCharacter.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_TextOrCharacter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_TextOrCharacter.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_TextOrCharacter::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_TextOrCharacter.def("CaseNum", (Standard_Integer (StepVisual_TextOrCharacter::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_TextOrCharacter::CaseNum, "Recognizes a TextOrCharacter Kind Entity that is : 1 -> AnnotationText 2 -> CompositeText 3 -> TextLiteral 0 else", py::arg("ent"));
cls_StepVisual_TextOrCharacter.def("AnnotationText", (opencascade::handle<StepVisual_AnnotationText> (StepVisual_TextOrCharacter::*)() const) &StepVisual_TextOrCharacter::AnnotationText, "returns Value as a AnnotationText (Null if another type)");
cls_StepVisual_TextOrCharacter.def("CompositeText", (opencascade::handle<StepVisual_CompositeText> (StepVisual_TextOrCharacter::*)() const) &StepVisual_TextOrCharacter::CompositeText, "returns Value as a CompositeText (Null if another type)");
cls_StepVisual_TextOrCharacter.def("TextLiteral", (opencascade::handle<StepVisual_TextLiteral> (StepVisual_TextOrCharacter::*)() const) &StepVisual_TextOrCharacter::TextLiteral, "returns Value as a TextLiteral (Null if another type)");

// Enums

}