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
#ifndef __NCollection_List__
#define __NCollection_List__

#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <NCollection_TListNode.hxx>
#include <NCollection_TListIterator.hxx>
#include <NCollection_StlIterator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_ListNode.hxx>

template <typename TheItemType>
void bind_NCollection_List(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_List<TheItemType>, NCollection_BaseList> cls_NCollection_List(mod, name.c_str(), "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.", local);

// Constructors
cls_NCollection_List.def(py::init<>());
cls_NCollection_List.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
cls_NCollection_List.def(py::init<const NCollection_List<TheItemType> &>(), py::arg("theOther"));

// Methods
cls_NCollection_List.def("begin", (typename NCollection_List<TheItemType>::iterator (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::begin, "Returns an iterator pointing to the first element in the list.");
cls_NCollection_List.def("end", (typename NCollection_List<TheItemType>::iterator (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the list.");
cls_NCollection_List.def("cbegin", (typename NCollection_List<TheItemType>::const_iterator (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the list.");
cls_NCollection_List.def("cend", (typename NCollection_List<TheItemType>::const_iterator (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the list.");
cls_NCollection_List.def("Size", (Standard_Integer (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::Size, "Size - Number of items");
cls_NCollection_List.def("Assign", (NCollection_List<TheItemType> & (NCollection_List<TheItemType>::*)(const NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_List.def("operator=", (NCollection_List<TheItemType> & (NCollection_List<TheItemType>::*)(const NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::operator=, "Replacement operator", py::arg("theOther"));
cls_NCollection_List.def("Clear", [](NCollection_List<TheItemType> &self) -> void { return self.Clear(); });
cls_NCollection_List.def("Clear", (void (NCollection_List<TheItemType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_List<TheItemType>::Clear, "Clear this list", py::arg("theAllocator"));
cls_NCollection_List.def("First", (const TheItemType & (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::First, "First item");
cls_NCollection_List.def("First", (TheItemType & (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::First, "First item (non-const)");
cls_NCollection_List.def("Last", (const TheItemType & (NCollection_List<TheItemType>::*)() const) &NCollection_List<TheItemType>::Last, "Last item");
cls_NCollection_List.def("Last", (TheItemType & (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::Last, "Last item (non-const)");
cls_NCollection_List.def("Append", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &)) &NCollection_List<TheItemType>::Append, "Append one item at the end", py::arg("theItem"));
cls_NCollection_List.def("Append", (void (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
cls_NCollection_List.def("Append", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Append, "Append another list at the end. After this operation, theOther list will be cleared.", py::arg("theOther"));
cls_NCollection_List.def("Prepend", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &)) &NCollection_List<TheItemType>::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
cls_NCollection_List.def("Prepend", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
cls_NCollection_List.def("RemoveFirst", (void (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::RemoveFirst, "RemoveFirst item");
cls_NCollection_List.def("Remove", (void (NCollection_List<TheItemType>::*)(typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
cls_NCollection_List.def("InsertBefore", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
cls_NCollection_List.def("InsertBefore", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
cls_NCollection_List.def("InsertAfter", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
cls_NCollection_List.def("InsertAfter", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
cls_NCollection_List.def("Reverse", (void (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::Reverse, "Reverse the list");
cls_NCollection_List.def("__iter__", [](const NCollection_List<TheItemType> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

}

#endif