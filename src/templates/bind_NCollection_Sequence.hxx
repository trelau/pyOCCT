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
#ifndef __NCollection_Sequence__
#define __NCollection_Sequence__

#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_StlIterator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

template <typename TheItemType>
void bind_NCollection_Sequence(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Sequence<TheItemType>, NCollection_BaseSequence> cls_NCollection_Sequence(mod, name.c_str(), "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n", local);

// Constructors
cls_NCollection_Sequence.def(py::init<>());
cls_NCollection_Sequence.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
cls_NCollection_Sequence.def(py::init<const NCollection_Sequence<TheItemType> &>(), py::arg("theOther"));

// Methods
cls_NCollection_Sequence.def("begin", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::begin, "Returns an iterator pointing to the first element in the sequence.");
cls_NCollection_Sequence.def("end", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the sequence.");
cls_NCollection_Sequence.def("cbegin", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
cls_NCollection_Sequence.def("cend", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const) &NCollection_Sequence<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
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

#endif