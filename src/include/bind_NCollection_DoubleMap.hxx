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
#ifndef __NCollection_DoubleMap__
#define __NCollection_DoubleMap__

#include <pyOCCT_Common.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <NCollection_DoubleMap.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_TListNode.hxx>
#include <NCollection_ListNode.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>

template <typename TheKey1Type, typename TheKey2Type, typename Hasher1, typename Hasher2>
void bind_NCollection_DoubleMap(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>, std::unique_ptr<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>, Deleter<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>>>, NCollection_BaseMap> cls_NCollection_DoubleMap(mod, name.c_str(), "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.", local);

// Constructors
cls_NCollection_DoubleMap.def(py::init<>());
cls_NCollection_DoubleMap.def(py::init<const Standard_Integer>(), py::arg("theNbBuckets"));
cls_NCollection_DoubleMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theNbBuckets"), py::arg("theAllocator"));
cls_NCollection_DoubleMap.def(py::init<const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &>(), py::arg("theOther"));

// Fields

// Methods
cls_NCollection_DoubleMap.def("Exchange", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
cls_NCollection_DoubleMap.def("Assign", (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_DoubleMap.def("operator=", (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_DoubleMap.def("ReSize", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const Standard_Integer)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::ReSize, "ReSize", py::arg("N"));
cls_NCollection_DoubleMap.def("Bind", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &, const TheKey2Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
cls_NCollection_DoubleMap.def("AreBound", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &, const TheKey2Type &) const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
cls_NCollection_DoubleMap.def("IsBound1", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &) const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::IsBound1, "IsBound1", py::arg("theKey1"));
cls_NCollection_DoubleMap.def("IsBound2", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &) const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::IsBound2, "IsBound2", py::arg("theKey2"));
cls_NCollection_DoubleMap.def("UnBind1", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::UnBind1, "UnBind1", py::arg("theKey1"));
cls_NCollection_DoubleMap.def("UnBind2", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::UnBind2, "UnBind2", py::arg("theKey2"));
cls_NCollection_DoubleMap.def("Find1", (const TheKey2Type & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &) const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Find1, "Find1", py::arg("theKey1"));
cls_NCollection_DoubleMap.def("Find2", (const TheKey1Type & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &) const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Find2, "Find2", py::arg("theKey2"));
cls_NCollection_DoubleMap.def("Clear", [](NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &self) -> void { return self.Clear(); });
cls_NCollection_DoubleMap.def("Clear", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const Standard_Boolean)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
cls_NCollection_DoubleMap.def("Clear", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
cls_NCollection_DoubleMap.def("Size", (Standard_Integer (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)() const) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Size, "Size");

// Enums

}

#endif