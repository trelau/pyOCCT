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
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <CDM_ListOfReferences.hxx>
#include <CDM_ReferenceIterator.hxx>

void bind_CDM_ReferenceIterator(py::module &mod){

py::class_<CDM_ReferenceIterator> cls_CDM_ReferenceIterator(mod, "CDM_ReferenceIterator", "None");

// Constructors
cls_CDM_ReferenceIterator.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));

// Fields

// Methods
// cls_CDM_ReferenceIterator.def_static("operator new_", (void * (*)(size_t)) &CDM_ReferenceIterator::operator new, "None", py::arg("theSize"));
// cls_CDM_ReferenceIterator.def_static("operator delete_", (void (*)(void *)) &CDM_ReferenceIterator::operator delete, "None", py::arg("theAddress"));
// cls_CDM_ReferenceIterator.def_static("operator new[]_", (void * (*)(size_t)) &CDM_ReferenceIterator::operator new[], "None", py::arg("theSize"));
// cls_CDM_ReferenceIterator.def_static("operator delete[]_", (void (*)(void *)) &CDM_ReferenceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_CDM_ReferenceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &CDM_ReferenceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CDM_ReferenceIterator.def_static("operator delete_", (void (*)(void *, void *)) &CDM_ReferenceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_CDM_ReferenceIterator.def("More", (Standard_Boolean (CDM_ReferenceIterator::*)() const) &CDM_ReferenceIterator::More, "None");
cls_CDM_ReferenceIterator.def("Next", (void (CDM_ReferenceIterator::*)()) &CDM_ReferenceIterator::Next, "None");
cls_CDM_ReferenceIterator.def("Document", (opencascade::handle<CDM_Document> (CDM_ReferenceIterator::*)() const) &CDM_ReferenceIterator::Document, "None");
cls_CDM_ReferenceIterator.def("ReferenceIdentifier", (Standard_Integer (CDM_ReferenceIterator::*)() const) &CDM_ReferenceIterator::ReferenceIdentifier, "None");
cls_CDM_ReferenceIterator.def("DocumentVersion", (Standard_Integer (CDM_ReferenceIterator::*)() const) &CDM_ReferenceIterator::DocumentVersion, "returns the Document Version in the reference.");

// Enums

}