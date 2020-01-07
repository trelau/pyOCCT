/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#ifndef __NCollection_Templates_Header__
#define __NCollection_Templates_Header__

#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_StlIterator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_NoSuchObject.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <NCollection_DataMap.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_TListNode.hxx>
#include <NCollection_ListNode.hxx>

template <typename TheItemType>
void bind_NCollection_Sequence(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Sequence<TheItemType>, NCollection_BaseSequence> cls_NCollection_Sequence(mod, name.c_str(), "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n", local);

// Constructors
cls_NCollection_Sequence.def(py::init<>());
cls_NCollection_Sequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
cls_NCollection_Sequence.def(py::init<const NCollection_Sequence<TheItemType> &>(), py::arg("theOther"));

// Methods
// cls_NCollection_Sequence.def("begin", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::begin, "Returns an iterator pointing to the first element in the sequence.");
// cls_NCollection_Sequence.def("end", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the sequence.");
// cls_NCollection_Sequence.def("cbegin", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
// cls_NCollection_Sequence.def("cend", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
cls_NCollection_Sequence.def("Size", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::Size, "Number of items");
cls_NCollection_Sequence.def("Length", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::Length, "Number of items");
cls_NCollection_Sequence.def("Lower", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::Lower, "Method for consistency with other collections.");
cls_NCollection_Sequence.def("Upper", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::Upper, "Method for consistency with other collections.");
cls_NCollection_Sequence.def("IsEmpty", (Standard_Boolean (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::IsEmpty, "Empty query");
cls_NCollection_Sequence.def("Reverse", (void (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::Reverse, "Reverse sequence");
cls_NCollection_Sequence.def("Exchange", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Sequence<TheItemType>::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
cls_NCollection_Sequence.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Sequence<TheItemType>::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
cls_NCollection_Sequence.def("Clear", [](NCollection_Sequence<TheItemType> &self) -> void { return self.Clear(); });
cls_NCollection_Sequence.def("Clear", (void (NCollection_Sequence<TheItemType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Sequence<TheItemType>::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
cls_NCollection_Sequence.def("Assign", (NCollection_Sequence<TheItemType> & (NCollection_Sequence<TheItemType>::*)(const NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_Sequence.def("operator=", (NCollection_Sequence<TheItemType> & (NCollection_Sequence<TheItemType>::*)(const NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::operator=, "Replacement operator", py::arg("theOther"));
cls_NCollection_Sequence.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(typename NCollection_Sequence<TheItemType>::Iterator &)) &NCollection_Sequence<TheItemType>::Remove, "Remove one item", py::arg("thePosition"));
cls_NCollection_Sequence.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::Remove, "Remove one item", py::arg("theIndex"));
cls_NCollection_Sequence.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Sequence<TheItemType>::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
cls_NCollection_Sequence.def("Append", (void (NCollection_Sequence<TheItemType>::*)(const TheItemType &)) &NCollection_Sequence<TheItemType>::Append, "Append one item", py::arg("theItem"));
cls_NCollection_Sequence.def("Append", (void (NCollection_Sequence<TheItemType>::*)(NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
cls_NCollection_Sequence.def("Prepend", (void (NCollection_Sequence<TheItemType>::*)(const TheItemType &)) &NCollection_Sequence<TheItemType>::Prepend, "Prepend one item", py::arg("theItem"));
cls_NCollection_Sequence.def("Prepend", (void (NCollection_Sequence<TheItemType>::*)(NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
cls_NCollection_Sequence.def("InsertBefore", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
cls_NCollection_Sequence.def("InsertBefore", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::InsertBefore, "InsertBefore theIndex another sequence (making it empty)", py::arg("theIndex"), py::arg("theSeq"));
cls_NCollection_Sequence.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(typename NCollection_Sequence<TheItemType>::Iterator &, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
cls_NCollection_Sequence.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter theIndex another sequence (making it empty)", py::arg("theIndex"), py::arg("theSeq"));
cls_NCollection_Sequence.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
cls_NCollection_Sequence.def("Split", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
cls_NCollection_Sequence.def("First", (const TheItemType & (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::First, "First item access");
cls_NCollection_Sequence.def("ChangeFirst", (TheItemType & (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::ChangeFirst, "First item access");
cls_NCollection_Sequence.def("Last", (const TheItemType & (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::Last, "Last item access");
cls_NCollection_Sequence.def("ChangeLast", (TheItemType & (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::ChangeLast, "Last item access");
cls_NCollection_Sequence.def("Value", (const TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer) const) &NCollection_Sequence<TheItemType>::Value, "Constant item access by theIndex", py::arg("theIndex"));
cls_NCollection_Sequence.def("__call__", (const TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer) const) &NCollection_Sequence<TheItemType>::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
cls_NCollection_Sequence.def("ChangeValue", (TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
cls_NCollection_Sequence.def("__call__", (TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
cls_NCollection_Sequence.def("SetValue", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
cls_NCollection_Sequence.def("__iter__", [](const NCollection_Sequence<TheItemType> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}

template <typename TheKeyType, typename TheItemType, typename Hasher>
void bind_NCollection_DataMap(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_DataMap<TheKeyType, TheItemType, Hasher>, NCollection_BaseMap> cls_NCollection_DataMap(mod, name.c_str(), "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.", local);

// Constructors
cls_NCollection_DataMap.def(py::init<>());
cls_NCollection_DataMap.def(py::init<const Standard_Integer>(), py::arg("theNbBuckets"));
cls_NCollection_DataMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theNbBuckets"), py::arg("theAllocator"));
cls_NCollection_DataMap.def(py::init<const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &>(), py::arg("theOther"));

// Methods
// cls_NCollection_DataMap.def("begin", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::begin, "Returns an iterator pointing to the first element in the map.");
// cls_NCollection_DataMap.def("end", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::end, "Returns an iterator referring to the past-the-end element in the map.");
// cls_NCollection_DataMap.def("cbegin", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
// cls_NCollection_DataMap.def("cend", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
cls_NCollection_DataMap.def("Exchange", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
cls_NCollection_DataMap.def("Assign", (NCollection_DataMap<TheKeyType, TheItemType, Hasher> & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_DataMap.def("operator=", (NCollection_DataMap<TheKeyType, TheItemType, Hasher> & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_DataMap.def("ReSize", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ReSize, "ReSize", py::arg("N"));
cls_NCollection_DataMap.def("Bind", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Bind, "Bind binds Item to Key in map.", py::arg("theKey"), py::arg("theItem"));
// cls_NCollection_DataMap.def("Bound", (TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
cls_NCollection_DataMap.def("IsBound", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::IsBound, "IsBound", py::arg("theKey"));
cls_NCollection_DataMap.def("UnBind", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
// cls_NCollection_DataMap.def("Seek", (const TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
cls_NCollection_DataMap.def("Find", (const TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
cls_NCollection_DataMap.def("Find", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, TheItemType &) const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
cls_NCollection_DataMap.def("__call__", (const TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
// cls_NCollection_DataMap.def("ChangeSeek", (TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
cls_NCollection_DataMap.def("ChangeFind", (TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
cls_NCollection_DataMap.def("__call__", (TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
cls_NCollection_DataMap.def("Clear", [](NCollection_DataMap<TheKeyType, TheItemType, Hasher> &self) -> void { return self.Clear(); });
cls_NCollection_DataMap.def("Clear", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Boolean)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
cls_NCollection_DataMap.def("Clear", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
cls_NCollection_DataMap.def("Size", (Standard_Integer (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Size, "Size");
cls_NCollection_DataMap.def("__iter__", [](const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}

#endif