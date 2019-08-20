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
#ifndef __NCollection_TListNode__
#define __NCollection_TListNode__

#include <pyOCCT_Common.hxx>
#include <NCollection_ListNode.hxx>
#include <NCollection_TListNode.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

template <typename TheItemType>
void bind_NCollection_TListNode(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_TListNode<TheItemType>, std::unique_ptr<NCollection_TListNode<TheItemType>>, NCollection_ListNode> cls_NCollection_TListNode(mod, name.c_str(), "Purpose: Abstract list node class. Used by BaseList Remark: Internal class", local);

// Constructors
cls_NCollection_TListNode.def(py::init<const TheItemType &>(), py::arg("theItem"));
cls_NCollection_TListNode.def(py::init<const TheItemType &, NCollection_ListNode *>(), py::arg("theItem"), py::arg("theNext"));

// Fields

// Methods
cls_NCollection_TListNode.def("Value", (const TheItemType & (NCollection_TListNode<TheItemType>::*)() const) &NCollection_TListNode<TheItemType>::Value, "Constant value access");
cls_NCollection_TListNode.def("ChangeValue", (TheItemType & (NCollection_TListNode<TheItemType>::*)()) &NCollection_TListNode<TheItemType>::ChangeValue, "Variable value access");
cls_NCollection_TListNode.def_static("delNode_", (void (*)(NCollection_ListNode *, opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_TListNode<TheItemType>::delNode, "Static deleter to be passed to BaseList", py::arg("theNode"), py::arg("theAl"));

// Enums

}

#endif