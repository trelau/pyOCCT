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
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <PCDM_Reference.hxx>

void bind_PCDM_Reference(py::module &mod){

py::class_<PCDM_Reference, std::unique_ptr<PCDM_Reference>> cls_PCDM_Reference(mod, "PCDM_Reference", "None");

// Constructors
cls_PCDM_Reference.def(py::init<>());
cls_PCDM_Reference.def(py::init<const Standard_Integer, const TCollection_ExtendedString &, const Standard_Integer>(), py::arg("aReferenceIdentifier"), py::arg("aFileName"), py::arg("aDocumentVersion"));

// Fields

// Methods
// cls_PCDM_Reference.def_static("operator new_", (void * (*)(size_t)) &PCDM_Reference::operator new, "None", py::arg("theSize"));
// cls_PCDM_Reference.def_static("operator delete_", (void (*)(void *)) &PCDM_Reference::operator delete, "None", py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator new[]_", (void * (*)(size_t)) &PCDM_Reference::operator new[], "None", py::arg("theSize"));
// cls_PCDM_Reference.def_static("operator delete[]_", (void (*)(void *)) &PCDM_Reference::operator delete[], "None", py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator new_", (void * (*)(size_t, void *)) &PCDM_Reference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator delete_", (void (*)(void *, void *)) &PCDM_Reference::operator delete, "None", py::arg(""), py::arg(""));
cls_PCDM_Reference.def("ReferenceIdentifier", (Standard_Integer (PCDM_Reference::*)() const) &PCDM_Reference::ReferenceIdentifier, "None");
cls_PCDM_Reference.def("FileName", (TCollection_ExtendedString (PCDM_Reference::*)() const) &PCDM_Reference::FileName, "None");
cls_PCDM_Reference.def("DocumentVersion", (Standard_Integer (PCDM_Reference::*)() const) &PCDM_Reference::DocumentVersion, "None");

// Enums

}