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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <StepData_StepModel.hxx>
#include <IFSelect_Signature.hxx>
#include <IFSelect_SelectSignature.hxx>
#include <STEPEdit_EditContext.hxx>
#include <STEPEdit_EditSDR.hxx>
#include <STEPEdit.hxx>

void bind_STEPEdit(py::module &mod){

py::class_<STEPEdit, std::unique_ptr<STEPEdit, Deleter<STEPEdit>>> cls_STEPEdit(mod, "STEPEdit", "Provides tools to exploit and edit a set of STEP data : editors, selections ..");

// Constructors

// Fields

// Methods
// cls_STEPEdit.def_static("operator new_", (void * (*)(size_t)) &STEPEdit::operator new, "None", py::arg("theSize"));
// cls_STEPEdit.def_static("operator delete_", (void (*)(void *)) &STEPEdit::operator delete, "None", py::arg("theAddress"));
// cls_STEPEdit.def_static("operator new[]_", (void * (*)(size_t)) &STEPEdit::operator new[], "None", py::arg("theSize"));
// cls_STEPEdit.def_static("operator delete[]_", (void (*)(void *)) &STEPEdit::operator delete[], "None", py::arg("theAddress"));
// cls_STEPEdit.def_static("operator new_", (void * (*)(size_t, void *)) &STEPEdit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPEdit.def_static("operator delete_", (void (*)(void *, void *)) &STEPEdit::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPEdit.def_static("Protocol_", (opencascade::handle<Interface_Protocol> (*)()) &STEPEdit::Protocol, "Returns a Protocol fit for STEP (creates the first time)");
cls_STEPEdit.def_static("NewModel_", (opencascade::handle<StepData_StepModel> (*)()) &STEPEdit::NewModel, "Returns a new empty StepModel fit for STEP i.e. with its header determined from Protocol");
cls_STEPEdit.def_static("SignType_", (opencascade::handle<IFSelect_Signature> (*)()) &STEPEdit::SignType, "Returns a SignType fit for STEP (creates the first time)");
cls_STEPEdit.def_static("NewSelectSDR_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectSDR, "Creates a Selection for ShapeDefinitionRepresentation By default searches among root entities");
cls_STEPEdit.def_static("NewSelectPlacedItem_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectPlacedItem, "Creates a Selection for Placed Items, i.e. MappedItem or ContextDependentShapeRepresentation, which itself refers to a RepresentationRelationship with possible subtypes (Shape... and/or ...WithTransformation) By default in the whole StepModel");
cls_STEPEdit.def_static("NewSelectShapeRepr_", (opencascade::handle<IFSelect_SelectSignature> (*)()) &STEPEdit::NewSelectShapeRepr, "Creates a Selection for ShapeRepresentation and its sub-types, plus ContextDependentShapeRepresentation (which is not a sub-type of ShapeRepresentation) By default in the whole StepModel");

// Enums

}