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
#ifndef __NCollection_IndexedMap__
#define __NCollection_IndexedMap__

#include <pyOCCT_Common.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_TListNode.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_ListNode.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_StlIterator.hxx>

template <typename TheKeyType, typename Hasher>
void bind_NCollection_IndexedMap(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_IndexedMap<TheKeyType, Hasher>, std::unique_ptr<NCollection_IndexedMap<TheKeyType, Hasher>, Deleter<NCollection_IndexedMap<TheKeyType, Hasher>>>, NCollection_BaseMap> cls_NCollection_IndexedMap(mod, name.c_str(), "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.", local);

// Constructors
cls_NCollection_IndexedMap.def(py::init<>());
cls_NCollection_IndexedMap.def(py::init<const Standard_Integer>(), py::arg("theNbBuckets"));
cls_NCollection_IndexedMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theNbBuckets"), py::arg("theAllocator"));
cls_NCollection_IndexedMap.def(py::init<const NCollection_IndexedMap<TheKeyType, Hasher> &>(), py::arg("theOther"));

// Fields

// Methods
cls_NCollection_IndexedMap.def("cbegin", (NCollection_IndexedMap<TheKeyType, Hasher>::const_iterator (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const) &NCollection_IndexedMap<TheKeyType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
cls_NCollection_IndexedMap.def("cend", (NCollection_IndexedMap<TheKeyType, Hasher>::const_iterator (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const) &NCollection_IndexedMap<TheKeyType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
cls_NCollection_IndexedMap.def("Exchange", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
cls_NCollection_IndexedMap.def("Assign", (NCollection_IndexedMap<TheKeyType, Hasher> & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_IndexedMap.def("operator=", (NCollection_IndexedMap<TheKeyType, Hasher> & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_IndexedMap.def("ReSize", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::ReSize, "ReSize", py::arg("theExtent"));
cls_NCollection_IndexedMap.def("Add", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Add, "Add", py::arg("theKey1"));
cls_NCollection_IndexedMap.def("Contains", (Standard_Boolean (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedMap<TheKeyType, Hasher>::Contains, "Contains", py::arg("theKey1"));
cls_NCollection_IndexedMap.def("Substitute", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer, const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
cls_NCollection_IndexedMap.def("Swap", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_NCollection_IndexedMap.def("RemoveLast", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)()) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveLast, "RemoveLast");
cls_NCollection_IndexedMap.def("RemoveFromIndex", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theIndex"));
cls_NCollection_IndexedMap.def("RemoveKey", (Standard_Boolean (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
cls_NCollection_IndexedMap.def("FindKey", (const TheKeyType & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer) const) &NCollection_IndexedMap<TheKeyType, Hasher>::FindKey, "FindKey", py::arg("theIndex"));
cls_NCollection_IndexedMap.def("__call__", (const TheKeyType & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer) const) &NCollection_IndexedMap<TheKeyType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theIndex"));
cls_NCollection_IndexedMap.def("FindIndex", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedMap<TheKeyType, Hasher>::FindIndex, "FindIndex", py::arg("theKey1"));
cls_NCollection_IndexedMap.def("Clear", [](NCollection_IndexedMap<TheKeyType, Hasher> &self) -> void { return self.Clear(); });
cls_NCollection_IndexedMap.def("Clear", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Boolean)) &NCollection_IndexedMap<TheKeyType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
cls_NCollection_IndexedMap.def("Clear", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
cls_NCollection_IndexedMap.def("Size", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const) &NCollection_IndexedMap<TheKeyType, Hasher>::Size, "Size");

// Enums

}

#endif