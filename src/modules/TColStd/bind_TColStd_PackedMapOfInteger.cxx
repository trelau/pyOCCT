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
#include <pyOCCT_Common.hxx>
#include <TCollection_BasicMap.hxx>
#include <Standard.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Standard_OStream.hxx>

void bind_TColStd_PackedMapOfInteger(py::module &mod){

py::class_<TColStd_PackedMapOfInteger> cls_TColStd_PackedMapOfInteger(mod, "TColStd_PackedMapOfInteger", "Optimized Map of integer values. Each block of 32 integers is stored in 8 bytes in memory.");

// Constructors
cls_TColStd_PackedMapOfInteger.def(py::init<>());
cls_TColStd_PackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TColStd_PackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_PackedMapOfInteger.def_static("operator new_", (void * (*)(size_t)) &TColStd_PackedMapOfInteger::operator new, "None", py::arg("theSize"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete_", (void (*)(void *)) &TColStd_PackedMapOfInteger::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_PackedMapOfInteger::operator new[], "None", py::arg("theSize"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete[]_", (void (*)(void *)) &TColStd_PackedMapOfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_PackedMapOfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_PackedMapOfInteger::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_PackedMapOfInteger.def("operator=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator=, "None", py::arg("Other"));
cls_TColStd_PackedMapOfInteger.def("Assign", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Assign, "None", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("ReSize", (void (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::ReSize, "None", py::arg("NbBuckets"));
cls_TColStd_PackedMapOfInteger.def("Clear", (void (TColStd_PackedMapOfInteger::*)()) &TColStd_PackedMapOfInteger::Clear, "None");
cls_TColStd_PackedMapOfInteger.def("Add", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Add, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("Contains", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer) const) &TColStd_PackedMapOfInteger::Contains, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("Remove", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Remove, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("NbBuckets", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::NbBuckets, "None");
cls_TColStd_PackedMapOfInteger.def("Extent", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::Extent, "None");
cls_TColStd_PackedMapOfInteger.def("IsEmpty", (Standard_Boolean (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::IsEmpty, "None");
cls_TColStd_PackedMapOfInteger.def("Statistics", (void (TColStd_PackedMapOfInteger::*)(Standard_OStream &) const) &TColStd_PackedMapOfInteger::Statistics, "None", py::arg("outStream"));
cls_TColStd_PackedMapOfInteger.def("GetMinimalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::GetMinimalMapped, "Query the minimal contained key value.");
cls_TColStd_PackedMapOfInteger.def("GetMaximalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::GetMaximalMapped, "Query the maximal contained key value.");
cls_TColStd_PackedMapOfInteger.def("Union", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps. The new Map contains the values that are contained either in the first map or in the second map or in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Unite", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator|=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator|=, "Overloaded operator version of Unite().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Intersection", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous contents of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands. The order of operands makes no difference; the method minimizes internally the number of iterations using the smallest map for the loop.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Intersect", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator&=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator&=, "Overloaded operator version of Intersect().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Subtraction", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as the first operand.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Subtract", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands.", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__isub__", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator-=, py::is_operator(), "Overloaded operator version of Subtract().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Difference", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Differ", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator^=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator^=, "Overloaded operator version of Differ().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("IsEqual", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::IsEqual, "Returns True if this map is equal to the given one, i.e. they contain the same sets of elements", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__eq__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::operator==, py::is_operator(), "Overloaded operator version of IsEqual().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("IsSubset", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::IsSubset, "Returns True if this map is subset of the given one, i.e. all elements contained in this map is contained also in the operand map. if this map is empty that this method returns true for any operand map.", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__le__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::operator<=, py::is_operator(), "Overloaded operator version of IsSubset().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("HasIntersection", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::HasIntersection, "Returns True if this map has common items with the given one.", py::arg(""));

// Enums

}