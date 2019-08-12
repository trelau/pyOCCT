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
#ifndef __NCollection_EBTree__
#define __NCollection_EBTree__

#include <pyOCCT_Common.hxx>
#include <NCollection_UBTree.hxx>
#include <NCollection_EBTree.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_DataMap.hxx>

template <typename TheObjType, typename TheBndType>
void bind_NCollection_EBTree(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_EBTree<TheObjType, TheBndType>, std::unique_ptr<NCollection_EBTree<TheObjType, TheBndType>, Deleter<NCollection_EBTree<TheObjType, TheBndType>>>, NCollection_UBTree<TheObjType, TheBndType>> cls_NCollection_EBTree(mod, name.c_str(), "The algorithm of unbalanced binary tree of overlapped bounding boxes with the possibility of deleting objects from the tree.", local);

// Constructors
cls_NCollection_EBTree.def(py::init<>());
cls_NCollection_EBTree.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_NCollection_EBTree.def("Add", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_EBTree<TheObjType, TheBndType>::Add, "Updates the tree with a new object and its bounding box. Extends the functionality of the parent method by maintaining the map myObjNodeMap. Redefined virtual method.", py::arg("theObj"), py::arg("theBnd"));
cls_NCollection_EBTree.def("Remove", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &)) &NCollection_EBTree<TheObjType, TheBndType>::Remove, "Removes the given object and updates the tree.", py::arg("theObj"));
cls_NCollection_EBTree.def("Contains", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &) const) &NCollection_EBTree<TheObjType, TheBndType>::Contains, "Returns True if the tree contains the object.", py::arg("theObj"));
cls_NCollection_EBTree.def("FindNode", (const NCollection_EBTree<TheObjType, TheBndType>::TreeNode & (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &) const) &NCollection_EBTree<TheObjType, TheBndType>::FindNode, "Returns The leaf node containing the object.", py::arg("theObj"));
cls_NCollection_EBTree.def("Clear", [](NCollection_EBTree<TheObjType, TheBndType> &self) -> void { return self.Clear(); });
cls_NCollection_EBTree.def("Clear", (void (NCollection_EBTree<TheObjType, TheBndType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_EBTree<TheObjType, TheBndType>::Clear, "Clears the contents of the tree. Redefined virtual method", py::arg("aNewAlloc"));

// Enums

}

#endif