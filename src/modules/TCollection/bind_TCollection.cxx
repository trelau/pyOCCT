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
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TCollection_BaseSequence.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_BasicMap.hxx>
#include <TCollection_MapNode.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TCollection.hxx>

void bind_TCollection(py::module &mod){

py::class_<TCollection, std::unique_ptr<TCollection>> cls_TCollection(mod, "TCollection", "The package <TCollection> provides the services for the transient basic data structures.");

// Constructors

// Fields

// Methods
// cls_TCollection.def_static("operator new_", (void * (*)(size_t)) &TCollection::operator new, "None", py::arg("theSize"));
// cls_TCollection.def_static("operator delete_", (void (*)(void *)) &TCollection::operator delete, "None", py::arg("theAddress"));
// cls_TCollection.def_static("operator new[]_", (void * (*)(size_t)) &TCollection::operator new[], "None", py::arg("theSize"));
// cls_TCollection.def_static("operator delete[]_", (void (*)(void *)) &TCollection::operator delete[], "None", py::arg("theAddress"));
// cls_TCollection.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TCollection.def_static("operator delete_", (void (*)(void *, void *)) &TCollection::operator delete, "None", py::arg(""), py::arg(""));
cls_TCollection.def_static("NextPrimeForMap_", (Standard_Integer (*)(const Standard_Integer)) &TCollection::NextPrimeForMap, "Returns a prime number greater than <I> suitable to dimension a Map. When <I> becomes great there is a limit on the result (today the limit is around 1 000 000). This is not a limit of the number of items but a limit in the number of buckets. i.e. there will be more collisions in the map.", py::arg("I"));

// Enums

}