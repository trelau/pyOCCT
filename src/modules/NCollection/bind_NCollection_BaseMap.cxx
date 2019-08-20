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
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_ListNode.hxx>
#include <Standard_OStream.hxx>

void bind_NCollection_BaseMap(py::module &mod){

py::class_<NCollection_BaseMap, std::unique_ptr<NCollection_BaseMap, py::nodelete>> cls_NCollection_BaseMap(mod, "NCollection_BaseMap", "Purpose: This is a base class for all Maps: Map DataMap DoubleMap IndexedMap IndexedDataMap Provides utilitites for managing the buckets.");

// Constructors

// Fields

// Methods
// cls_NCollection_BaseMap.def_static("operator new_", (void * (*)(size_t)) &NCollection_BaseMap::operator new, "None", py::arg("theSize"));
// cls_NCollection_BaseMap.def_static("operator delete_", (void (*)(void *)) &NCollection_BaseMap::operator delete, "None", py::arg("theAddress"));
// cls_NCollection_BaseMap.def_static("operator new[]_", (void * (*)(size_t)) &NCollection_BaseMap::operator new[], "None", py::arg("theSize"));
// cls_NCollection_BaseMap.def_static("operator delete[]_", (void (*)(void *)) &NCollection_BaseMap::operator delete[], "None", py::arg("theAddress"));
// cls_NCollection_BaseMap.def_static("operator new_", (void * (*)(size_t, void *)) &NCollection_BaseMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NCollection_BaseMap.def_static("operator delete_", (void (*)(void *, void *)) &NCollection_BaseMap::operator delete, "None", py::arg(""), py::arg(""));
// cls_NCollection_BaseMap.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseMap::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_NCollection_BaseMap.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_BaseMap::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_NCollection_BaseMap.def("NbBuckets", (Standard_Integer (NCollection_BaseMap::*)() const) &NCollection_BaseMap::NbBuckets, "NbBuckets");
cls_NCollection_BaseMap.def("Extent", (Standard_Integer (NCollection_BaseMap::*)() const) &NCollection_BaseMap::Extent, "Extent");
cls_NCollection_BaseMap.def("IsEmpty", (Standard_Boolean (NCollection_BaseMap::*)() const) &NCollection_BaseMap::IsEmpty, "IsEmpty");
cls_NCollection_BaseMap.def("Statistics", (void (NCollection_BaseMap::*)(Standard_OStream &) const) &NCollection_BaseMap::Statistics, "Statistics", py::arg("S"));
cls_NCollection_BaseMap.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseMap::*)() const) &NCollection_BaseMap::Allocator, "Returns attached allocator");

// Enums

// Nested classes
py::class_<NCollection_BaseMap::Iterator, std::unique_ptr<NCollection_BaseMap::Iterator>> cls_Iterator(cls_NCollection_BaseMap, "Iterator", "Memory allocation");

// Constructors

// Fields

// Methods
cls_Iterator.def("Initialize", (void (NCollection_BaseMap::Iterator::*)(const NCollection_BaseMap &)) &NCollection_BaseMap::Iterator::Initialize, "Initialize", py::arg("theMap"));
cls_Iterator.def("Reset", (void (NCollection_BaseMap::Iterator::*)()) &NCollection_BaseMap::Iterator::Reset, "Reset");
cls_Iterator.def("IsEqual", (Standard_Boolean (NCollection_BaseMap::Iterator::*)(const NCollection_BaseMap::Iterator &) const) &NCollection_BaseMap::Iterator::IsEqual, "Performs comparison of two iterators.", py::arg("theOther"));

// Enums

}