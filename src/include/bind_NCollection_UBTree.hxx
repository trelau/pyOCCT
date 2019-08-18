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
#ifndef __NCollection_UBTree__
#define __NCollection_UBTree__

#include <pyOCCT_Common.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_UBTree.hxx>

template <typename TheObjType, typename TheBndType>
void bind_NCollection_UBTree(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_UBTree<TheObjType, TheBndType>, std::unique_ptr<NCollection_UBTree<TheObjType, TheBndType>, Deleter<NCollection_UBTree<TheObjType, TheBndType>>>> cls_NCollection_UBTree(mod, name.c_str(), "The algorithm of unbalanced binary tree of overlapped bounding boxes.", local);

// Constructors
cls_NCollection_UBTree.def(py::init<>());
cls_NCollection_UBTree.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_NCollection_UBTree.def_static("operator new_", (void * (*)(size_t)) &NCollection_UBTree<TheObjType, TheBndType>::operator new, "None", py::arg("theSize"));
// cls_NCollection_UBTree.def_static("operator delete_", (void (*)(void *)) &NCollection_UBTree<TheObjType, TheBndType>::operator delete, "None", py::arg("theAddress"));
// cls_NCollection_UBTree.def_static("operator new[]_", (void * (*)(size_t)) &NCollection_UBTree<TheObjType, TheBndType>::operator new[], "None", py::arg("theSize"));
// cls_NCollection_UBTree.def_static("operator delete[]_", (void (*)(void *)) &NCollection_UBTree<TheObjType, TheBndType>::operator delete[], "None", py::arg("theAddress"));
// cls_NCollection_UBTree.def_static("operator new_", (void * (*)(size_t, void *)) &NCollection_UBTree<TheObjType, TheBndType>::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NCollection_UBTree.def_static("operator delete_", (void (*)(void *, void *)) &NCollection_UBTree<TheObjType, TheBndType>::operator delete, "None", py::arg(""), py::arg(""));
// cls_NCollection_UBTree.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_UBTree<TheObjType, TheBndType>::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_NCollection_UBTree.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_UBTree<TheObjType, TheBndType>::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_NCollection_UBTree.def("Add", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_UBTree<TheObjType, TheBndType>::Add, "Update the tree with a new object and its bounding box.", py::arg("theObj"), py::arg("theBnd"));
cls_NCollection_UBTree.def("Select", (Standard_Integer (NCollection_UBTree<TheObjType, TheBndType>::*)(typename NCollection_UBTree<TheObjType, TheBndType>::Selector &) const) &NCollection_UBTree<TheObjType, TheBndType>::Select, "Searches in the tree all objects conforming to the given selector. return Number of objects accepted", py::arg("theSelector"));
cls_NCollection_UBTree.def("Clear", [](NCollection_UBTree<TheObjType, TheBndType> &self) -> void { return self.Clear(); });
cls_NCollection_UBTree.def("Clear", (void (NCollection_UBTree<TheObjType, TheBndType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_UBTree<TheObjType, TheBndType>::Clear, "Clears the contents of the tree.", py::arg("aNewAlloc"));
cls_NCollection_UBTree.def("IsEmpty", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::*)() const) &NCollection_UBTree<TheObjType, TheBndType>::IsEmpty, "None");
cls_NCollection_UBTree.def("Root", (const typename NCollection_UBTree<TheObjType, TheBndType>::TreeNode & (NCollection_UBTree<TheObjType, TheBndType>::*)() const) &NCollection_UBTree<TheObjType, TheBndType>::Root, "Returns the root node of the tree");
cls_NCollection_UBTree.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_UBTree<TheObjType, TheBndType>::*)() const) &NCollection_UBTree<TheObjType, TheBndType>::Allocator, "Recommended to be used only in sub-classes.");

// Enums

// Nested classes
py::class_<NCollection_UBTree<TheObjType, TheBndType>::Selector, std::unique_ptr<NCollection_UBTree<TheObjType, TheBndType>::Selector, Deleter<NCollection_UBTree<TheObjType, TheBndType>::Selector>>> cls_Selector(cls_NCollection_UBTree, "Selector", "Class defining the minimal interface of selector.", local);

// Fields

// Methods
cls_Selector.def("Reject", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::Selector::*)(const TheBndType &) const) &NCollection_UBTree<TheObjType, TheBndType>::Selector::Reject, "Rejection base on the bounding type.", py::arg(""));
cls_Selector.def("Accept", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::Selector::*)(const TheObjType &)) &NCollection_UBTree<TheObjType, TheBndType>::Selector::Accept, "Confirm the object while making necessary tests on it. This method is called when the bounding box of the object conforms to the conditions (see Reject()). It is also supposed to keep record of accepted objects.", py::arg(""));
cls_Selector.def("Stop", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::Selector::*)() const) &NCollection_UBTree<TheObjType, TheBndType>::Selector::Stop, "This condition is checked after each call to Accept().");

// Enums

}

#endif