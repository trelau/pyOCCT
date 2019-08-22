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
#include <NCollection_Map.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <CDM_DocumentHasher.hxx>
#include <CDM_MapOfDocument.hxx>

void bind_CDM_MapIteratorOfMapOfDocument(py::module &mod){

py::class_<NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator, NCollection_BaseMap::Iterator> cls_CDM_MapIteratorOfMapOfDocument(mod, "CDM_MapIteratorOfMapOfDocument", "Implementation of the Iterator interface.");

// Constructors
cls_CDM_MapIteratorOfMapOfDocument.def(py::init<>());
cls_CDM_MapIteratorOfMapOfDocument.def(py::init<const NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > > &>(), py::arg("theMap"));

// Fields

// Methods
cls_CDM_MapIteratorOfMapOfDocument.def("More", (Standard_Boolean (NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::*)() const) &NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::More, "Query if the end of collection is reached by iterator");
cls_CDM_MapIteratorOfMapOfDocument.def("Next", (void (NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::*)()) &NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::Next, "Make a step along the collection");
cls_CDM_MapIteratorOfMapOfDocument.def("Value", (const opencascade::handle<CDM_Document> & (NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::*)() const) &NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::Value, "Value inquiry");
cls_CDM_MapIteratorOfMapOfDocument.def("Key", (const opencascade::handle<CDM_Document> & (NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::*)() const) &NCollection_Map<opencascade::handle<CDM_Document>, NCollection_DefaultHasher<opencascade::handle<CDM_Document> > >::Iterator::Key, "Key");

// Enums

}