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
#ifndef __NCollection_Array1__
#define __NCollection_Array1__

#include <pyOCCT_Common.hxx>
#include <NCollection_Array1.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_StlIterator.hxx>

template <typename TheItemType>
void bind_NCollection_Array1(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Array1<TheItemType>> cls_NCollection_Array1(mod, name.c_str(), "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.", local);

// Constructors
cls_NCollection_Array1.def(py::init<>());
cls_NCollection_Array1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_NCollection_Array1.def(py::init<const NCollection_Array1<TheItemType> &>(), py::arg("theOther"));
// cls_NCollection_Array1.def(py::init<NCollection_Array1<TheItemType> &&>(), py::arg("theOther"));
cls_NCollection_Array1.def(py::init<const TheItemType &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));

// Fields

// Methods
cls_NCollection_Array1.def("begin", (typename NCollection_Array1<TheItemType>::iterator (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::begin, "Returns an iterator pointing to the first element in the array.");
cls_NCollection_Array1.def("end", (typename NCollection_Array1<TheItemType>::iterator (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the array.");
cls_NCollection_Array1.def("cbegin", (typename NCollection_Array1<TheItemType>::const_iterator (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the array.");
cls_NCollection_Array1.def("cend", (typename NCollection_Array1<TheItemType>::const_iterator (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the array.");
cls_NCollection_Array1.def("Init", (void (NCollection_Array1<TheItemType>::*)(const TheItemType &)) &NCollection_Array1<TheItemType>::Init, "Initialise the items with theValue", py::arg("theValue"));
cls_NCollection_Array1.def("Size", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::Size, "Size query");
cls_NCollection_Array1.def("Length", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::Length, "Length query (the same)");
cls_NCollection_Array1.def("IsEmpty", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::IsEmpty, "Return TRUE if array has zero length.");
cls_NCollection_Array1.def("Lower", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::Lower, "Lower bound");
cls_NCollection_Array1.def("Upper", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::Upper, "Upper bound");
cls_NCollection_Array1.def("IsDeletable", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::IsDeletable, "myDeletable flag");
cls_NCollection_Array1.def("IsAllocated", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::IsAllocated, "IsAllocated flag - for naming compatibility");
cls_NCollection_Array1.def("Assign", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(const NCollection_Array1<TheItemType> &)) &NCollection_Array1<TheItemType>::Assign, "Copies data of theOther array to this. This array should be pre-allocated and have the same length as theOther; otherwise exception Standard_DimensionMismatch is thrown.", py::arg("theOther"));
cls_NCollection_Array1.def("Move", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(NCollection_Array1<TheItemType> &)) &NCollection_Array1<TheItemType>::Move, "Move assignment. This array will borrow all the data from theOther. The moved object will keep pointer to the memory buffer and range, but it will not free the buffer on destruction.", py::arg("theOther"));
// cls_NCollection_Array1.def("operator=", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(const NCollection_Array1<TheItemType> &)) &NCollection_Array1<TheItemType>::operator=, "Assignment operator;", py::arg("theOther"));
// cls_NCollection_Array1.def("operator=", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(NCollection_Array1<TheItemType> &&)) &NCollection_Array1<TheItemType>::operator=, "Move assignment operator;", py::arg("theOther"));
cls_NCollection_Array1.def("First", (const TheItemType & (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::First, "Returns first element");
cls_NCollection_Array1.def("ChangeFirst", (TheItemType & (NCollection_Array1<TheItemType>::*)()) &NCollection_Array1<TheItemType>::ChangeFirst, "Returns first element");
cls_NCollection_Array1.def("Last", (const TheItemType & (NCollection_Array1<TheItemType>::*)() const) &NCollection_Array1<TheItemType>::Last, "Returns last element");
cls_NCollection_Array1.def("ChangeLast", (TheItemType & (NCollection_Array1<TheItemType>::*)()) &NCollection_Array1<TheItemType>::ChangeLast, "Returns last element");
cls_NCollection_Array1.def("Value", (const TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer) const) &NCollection_Array1<TheItemType>::Value, "Constant value access", py::arg("theIndex"));
cls_NCollection_Array1.def("__call__", (const TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer) const) &NCollection_Array1<TheItemType>::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
cls_NCollection_Array1.def("ChangeValue", (TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer)) &NCollection_Array1<TheItemType>::ChangeValue, "Variable value access", py::arg("theIndex"));
cls_NCollection_Array1.def("__call__", (TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer)) &NCollection_Array1<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
cls_NCollection_Array1.def("SetValue", (void (NCollection_Array1<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Array1<TheItemType>::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
cls_NCollection_Array1.def("Resize", (void (NCollection_Array1<TheItemType>::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &NCollection_Array1<TheItemType>::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
cls_NCollection_Array1.def("__iter__", [](const NCollection_Array1<TheItemType> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

// Enums

}

#endif