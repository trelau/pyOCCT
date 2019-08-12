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
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_MapIteratorOfPackedMapOfInteger.hxx>

void bind_TColStd_MapIteratorOfPackedMapOfInteger(py::module &mod){

py::class_<TColStd_PackedMapOfInteger::Iterator, std::unique_ptr<TColStd_PackedMapOfInteger::Iterator, Deleter<TColStd_PackedMapOfInteger::Iterator>>, TCollection_BasicMapIterator> cls_TColStd_MapIteratorOfPackedMapOfInteger(mod, "TColStd_MapIteratorOfPackedMapOfInteger", "Iterator of class TColStd_PackedMapOfInteger.");

// Constructors
cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<>());
cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theMap"));

// Fields

// Methods
cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Initialize", (void (TColStd_PackedMapOfInteger::Iterator::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Iterator::Initialize, "Re-initialize with the same or another Map instance.", py::arg("theMap"));
cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Reset", (void (TColStd_PackedMapOfInteger::Iterator::*)()) &TColStd_PackedMapOfInteger::Iterator::Reset, "Restart the iteration");
cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Key", (Standard_Integer (TColStd_PackedMapOfInteger::Iterator::*)() const) &TColStd_PackedMapOfInteger::Iterator::Key, "Query the iterated key.");
cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Next", (void (TColStd_PackedMapOfInteger::Iterator::*)()) &TColStd_PackedMapOfInteger::Iterator::Next, "Increment the iterator");

// Enums

}