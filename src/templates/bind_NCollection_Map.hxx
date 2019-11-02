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
#ifndef __NCollection_Map__
#define __NCollection_Map__

#include <NCollection_DefaultHasher.hxx>
#include <NCollection_Map.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_TListNode.hxx>
#include <NCollection_ListNode.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_StlIterator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

template <typename TheKeyType, typename Hasher>
void bind_NCollection_Map(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Map<TheKeyType, Hasher>, NCollection_BaseMap> cls_NCollection_Map(mod, name.c_str(), "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.", local);

// Constructors
cls_NCollection_Map.def(py::init<>());
cls_NCollection_Map.def(py::init<const Standard_Integer>(), py::arg("theNbBuckets"));
cls_NCollection_Map.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theNbBuckets"), py::arg("theAllocator"));
cls_NCollection_Map.def(py::init<const NCollection_Map<TheKeyType, Hasher> &>(), py::arg("theOther"));

// Methods
cls_NCollection_Map.def("cbegin", (typename NCollection_Map<TheKeyType, Hasher>::const_iterator (NCollection_Map<TheKeyType, Hasher>::*)() const) &NCollection_Map<TheKeyType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
cls_NCollection_Map.def("cend", (typename NCollection_Map<TheKeyType, Hasher>::const_iterator (NCollection_Map<TheKeyType, Hasher>::*)() const) &NCollection_Map<TheKeyType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
cls_NCollection_Map.def("Exchange", (void (NCollection_Map<TheKeyType, Hasher>::*)(NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
cls_NCollection_Map.def("Assign", (NCollection_Map<TheKeyType, Hasher> & (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
// cls_NCollection_Map.def("operator=", (NCollection_Map<TheKeyType, Hasher> & (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::operator=, "Assign operator", py::arg("theOther"));
cls_NCollection_Map.def("ReSize", (void (NCollection_Map<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_Map<TheKeyType, Hasher>::ReSize, "ReSize", py::arg("N"));
cls_NCollection_Map.def("Add", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Add, "Add", py::arg("K"));
cls_NCollection_Map.def("Added", (const TheKeyType & (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
cls_NCollection_Map.def("Contains", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &) const) &NCollection_Map<TheKeyType, Hasher>::Contains, "Contains", py::arg("K"));
cls_NCollection_Map.def("Remove", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Remove, "Remove", py::arg("K"));
cls_NCollection_Map.def("Clear", [](NCollection_Map<TheKeyType, Hasher> &self) -> void { return self.Clear(); });
cls_NCollection_Map.def("Clear", (void (NCollection_Map<TheKeyType, Hasher>::*)(const Standard_Boolean)) &NCollection_Map<TheKeyType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
cls_NCollection_Map.def("Clear", (void (NCollection_Map<TheKeyType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Map<TheKeyType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
cls_NCollection_Map.def("Size", (Standard_Integer (NCollection_Map<TheKeyType, Hasher>::*)() const) &NCollection_Map<TheKeyType, Hasher>::Size, "Size");
cls_NCollection_Map.def("IsEqual", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const) &NCollection_Map<TheKeyType, Hasher>::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
cls_NCollection_Map.def("Contains", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const) &NCollection_Map<TheKeyType, Hasher>::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
cls_NCollection_Map.def("Union", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Map.def("Unite", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
cls_NCollection_Map.def("HasIntersection", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const) &NCollection_Map<TheKeyType, Hasher>::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
cls_NCollection_Map.def("Intersection", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Map.def("Intersect", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
cls_NCollection_Map.def("Subtraction", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Map.def("Subtract", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
cls_NCollection_Map.def("Difference", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
cls_NCollection_Map.def("Differ", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

}

#endif