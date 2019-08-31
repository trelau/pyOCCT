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
#ifndef __NCollection_IndexedDataMap__
#define __NCollection_IndexedDataMap__

#include <NCollection_DefaultHasher.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_TListNode.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_ListNode.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_StlIterator.hxx>

template <typename TheKeyType, typename TheItemType, typename Hasher>
void bind_NCollection_IndexedDataMap(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>, NCollection_BaseMap> cls_NCollection_IndexedDataMap(mod, name.c_str(), "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.", local);

// Constructors
cls_NCollection_IndexedDataMap.def(py::init<>());
cls_NCollection_IndexedDataMap.def(py::init<const Standard_Integer>(), py::arg("theNbBuckets"));
cls_NCollection_IndexedDataMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theNbBuckets"), py::arg("theAllocator"));
cls_NCollection_IndexedDataMap.def(py::init<const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &>(), py::arg("theOther"));

// Methods
cls_NCollection_IndexedDataMap.def("begin", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::begin, "Returns an iterator pointing to the first element in the map.");
cls_NCollection_IndexedDataMap.def("end", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::end, "Returns an iterator referring to the past-the-end element in the map.");
cls_NCollection_IndexedDataMap.def("cbegin", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
cls_NCollection_IndexedDataMap.def("cend", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
cls_NCollection_IndexedDataMap.def("Exchange", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
cls_NCollection_IndexedDataMap.def("Assign", (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_IndexedDataMap.def("operator=", (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_IndexedDataMap.def("ReSize", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ReSize, "ReSize", py::arg("N"));
cls_NCollection_IndexedDataMap.def("Add", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Add, "Returns the Index of already bound Key or appends new Key with specified Item value.", py::arg("theKey1"), py::arg("theItem"));
cls_NCollection_IndexedDataMap.def("Contains", (Standard_Boolean (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Contains, "Contains", py::arg("theKey1"));
cls_NCollection_IndexedDataMap.def("Substitute", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer, const TheKeyType &, const TheItemType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
cls_NCollection_IndexedDataMap.def("Swap", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_NCollection_IndexedDataMap.def("RemoveLast", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)()) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveLast, "RemoveLast");
cls_NCollection_IndexedDataMap.def("RemoveFromIndex", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("RemoveKey", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
cls_NCollection_IndexedDataMap.def("FindKey", (const TheKeyType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindKey, "FindKey", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("FindFromIndex", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromIndex, "FindFromIndex", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("__call__", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("ChangeFromIndex", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeFromIndex, "ChangeFromIndex", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("__call__", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theIndex"));
cls_NCollection_IndexedDataMap.def("FindIndex", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindIndex, "FindIndex", py::arg("theKey1"));
cls_NCollection_IndexedDataMap.def("FindFromKey", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromKey, "FindFromKey", py::arg("theKey1"));
cls_NCollection_IndexedDataMap.def("ChangeFromKey", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
// cls_NCollection_IndexedDataMap.def("Seek", (const TheItemType * (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
// cls_NCollection_IndexedDataMap.def("ChangeSeek", (TheItemType * (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
cls_NCollection_IndexedDataMap.def("FindFromKey", (Standard_Boolean (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, TheItemType &) const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
cls_NCollection_IndexedDataMap.def("Clear", [](NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &self) -> void { return self.Clear(); });
cls_NCollection_IndexedDataMap.def("Clear", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Boolean)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
cls_NCollection_IndexedDataMap.def("Clear", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
cls_NCollection_IndexedDataMap.def("Size", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Size, "Size");
cls_NCollection_IndexedDataMap.def("__iter__", [](const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}

#endif