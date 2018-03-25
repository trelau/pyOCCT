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

#include <pyOCCT_Common.hpp>

// FIXME Missing headers in template bindings
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Array2.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <NCollection_CellFilter.hxx>
#include <NCollection_Comparator.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <NCollection_DoubleMap.hxx>
#include <NCollection_UBTree.hxx>
#include <NCollection_EBTree.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_Handle.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_Lerp.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <NCollection_LocalArray.hxx>
#include <NCollection_Map.hxx>
#include <NCollection_Vec4.hxx>
#include <NCollection_Vec3.hxx>
#include <NCollection_Mat4.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Shared.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_SparseArray.hxx>
#include <NCollection_StdAllocator.hxx>
#include <NCollection_StlIterator.hxx>
#include <NCollection_TListIterator.hxx>
#include <NCollection_ListNode.hxx>
#include <NCollection_TListNode.hxx>
#include <NCollection_UBTreeFiller.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_UtfIterator.hxx>
#include <NCollection_UtfString.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
template <typename TheItemType>
void bind_NCollection_Array1(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<NCollection_Array1<TheItemType>, std::unique_ptr<NCollection_Array1<TheItemType>, Deleter<NCollection_Array1<TheItemType>>>> cls(mod, name.c_str(), "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls.def(py::init([] (const NCollection_Array1<TheItemType> &other) {return new NCollection_Array1<TheItemType>(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls.def(py::init<NCollection_Array1<TheItemType> &&>(), py::arg("theOther"));
	cls.def(py::init<const TheItemType &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls.def("begin", (typename NCollection_Array1<TheItemType>::iterator ( NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::begin, "Returns an iterator pointing to the first element in the array.");
	cls.def("end", (typename NCollection_Array1<TheItemType>::iterator (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls.def("cbegin", (typename  NCollection_Array1<TheItemType>::const_iterator (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls.def("cend", (typename NCollection_Array1<TheItemType>::const_iterator (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls.def("Init", (void (NCollection_Array1<TheItemType>::*)(const TheItemType &)) &NCollection_Array1<TheItemType>::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls.def("Size", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::Size, "Size query");
	cls.def("Length", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::Length, "Length query (the same)");
	cls.def("IsEmpty", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::IsEmpty, "Return TRUE if array has zero length.");
	cls.def("Lower", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::Lower, "Lower bound");
	cls.def("Upper", (Standard_Integer (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::Upper, "Upper bound");
	cls.def("IsDeletable", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::IsDeletable, "myDeletable flag");
	cls.def("IsAllocated", (Standard_Boolean (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls.def("Assign", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(const NCollection_Array1<TheItemType> &)) &NCollection_Array1<TheItemType>::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls.def("Move", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(NCollection_Array1<TheItemType> &&)) &NCollection_Array1<TheItemType>::Move, "Move assignment", py::arg("theOther"));
	cls.def("assign", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(const NCollection_Array1<TheItemType> &)) &NCollection_Array1<TheItemType>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls.def("assign", (NCollection_Array1<TheItemType> & (NCollection_Array1<TheItemType>::*)(NCollection_Array1<TheItemType> &&)) &NCollection_Array1<TheItemType>::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls.def("First", (const TheItemType & (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::First, "Returns first element");
	cls.def("ChangeFirst", (TheItemType & (NCollection_Array1<TheItemType>::*)()) &NCollection_Array1<TheItemType>::ChangeFirst, "Returns first element");
	cls.def("Last", (const TheItemType & (NCollection_Array1<TheItemType>::*)() const ) &NCollection_Array1<TheItemType>::Last, "Returns last element");
	cls.def("ChangeLast", (TheItemType & (NCollection_Array1<TheItemType>::*)()) &NCollection_Array1<TheItemType>::ChangeLast, "Returns last element");
	cls.def("Value", (const TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Array1<TheItemType>::Value, "Constant value access", py::arg("theIndex"));
	cls.def("__call__", (const TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Array1<TheItemType>::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls.def("ChangeValue", (TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer)) &NCollection_Array1<TheItemType>::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls.def("__call__", (TheItemType & (NCollection_Array1<TheItemType>::*)(const Standard_Integer)) &NCollection_Array1<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls.def("SetValue", (void (NCollection_Array1<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Array1<TheItemType>::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls.def("Resize", (void (NCollection_Array1<TheItemType>::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &NCollection_Array1<TheItemType>::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls.def("__iter__", [](const NCollection_Array1<TheItemType> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
template <typename TheItemType>
void bind_NCollection_Array2(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<NCollection_Array2<TheItemType>, std::unique_ptr<NCollection_Array2<TheItemType>, Deleter<NCollection_Array2<TheItemType>>>> cls(mod, name.c_str(), "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls.def(py::init([] (const NCollection_Array2<TheItemType> &other) {return new NCollection_Array2<TheItemType>(other);}), "Copy constructor", py::arg("other"));
	cls.def(py::init<const TheItemType &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls.def("Init", (void (NCollection_Array2<TheItemType>::*)(const TheItemType &)) &NCollection_Array2<TheItemType>::Init, "Initialise the values", py::arg("theValue"));
	cls.def("Size", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::Size, "Size (number of items)");
	cls.def("Length", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::Length, "Length (number of items)");
	cls.def("RowLength", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::RowLength, "Returns length of the row, i.e. number of columns");
	cls.def("ColLength", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::ColLength, "Returns length of the column, i.e. number of rows");
	cls.def("LowerRow", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::LowerRow, "LowerRow");
	cls.def("UpperRow", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::UpperRow, "UpperRow");
	cls.def("LowerCol", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::LowerCol, "LowerCol");
	cls.def("UpperCol", (Standard_Integer (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::UpperCol, "UpperCol");
	cls.def("IsDeletable", (Standard_Boolean (NCollection_Array2<TheItemType>::*)() const ) &NCollection_Array2<TheItemType>::IsDeletable, "myDeletable flag");
	cls.def("Assign", (NCollection_Array2<TheItemType> & (NCollection_Array2<TheItemType>::*)(const NCollection_Array2<TheItemType> &)) &NCollection_Array2<TheItemType>::Assign, "Assignment", py::arg("theOther"));
	cls.def("assign", (NCollection_Array2<TheItemType> & (NCollection_Array2<TheItemType>::*)(const NCollection_Array2<TheItemType> &)) &NCollection_Array2<TheItemType>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("Value", (const TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_Array2<TheItemType>::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls.def("__call__", (const TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_Array2<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls.def("ChangeValue", (TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Array2<TheItemType>::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls.def("__call__", (TheItemType & (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Array2<TheItemType>::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls.def("SetValue", (void (NCollection_Array2<TheItemType>::*)(const Standard_Integer, const Standard_Integer, const TheItemType &)) &NCollection_Array2<TheItemType>::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
template <typename Inspector>
void bind_NCollection_CellFilter(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	py::class_<NCollection_CellFilter<Inspector>, std::unique_ptr<NCollection_CellFilter<Inspector>, Deleter<NCollection_CellFilter<Inspector>>>> cls(mod, name.c_str(), "A data structure for sorting geometric objects (called targets) in n-dimensional space into cells, with associated algorithm for fast checking of coincidence (overlapping, intersection, etc.) with other objects (called here bullets).");
	cls.def(py::init<const Standard_Integer>(), py::arg("theDim"));
	cls.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("theDim"), py::arg("theCellSize"));
	cls.def(py::init<const Standard_Integer, const Standard_Real, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theDim"), py::arg("theCellSize"), py::arg("theAlloc"));
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Real>(), py::arg("theCellSize"));
	cls.def(py::init<const Standard_Real, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theCellSize"), py::arg("theAlloc"));
	cls.def("Reset", [](NCollection_CellFilter<Inspector> &self, Standard_Real a0) -> void { return self.Reset(a0); }, py::arg("theCellSize"));
	cls.def("Reset", (void (NCollection_CellFilter<Inspector>::*)(Standard_Real, const opencascade::handle<NCollection_IncAllocator> &)) &NCollection_CellFilter<Inspector>::Reset, "Clear the data structures, set new cell size and allocator", py::arg("theCellSize"), py::arg("theAlloc"));
	cls.def("Reset", [](NCollection_CellFilter<Inspector> &self, NCollection_Array1<Standard_Real> & a0) -> void { return self.Reset(a0); }, py::arg("theCellSize"));
	cls.def("Reset", (void (NCollection_CellFilter<Inspector>::*)(NCollection_Array1<Standard_Real> &, const opencascade::handle<NCollection_IncAllocator> &)) &NCollection_CellFilter<Inspector>::Reset, "Clear the data structures and set new cell sizes and allocator", py::arg("theCellSize"), py::arg("theAlloc"));
	cls.def("Add", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Target &, const typename NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Add, "Adds a target object for further search at a point (into only one cell)", py::arg("theTarget"), py::arg("thePnt"));
	cls.def("Add", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Target &, const typename NCollection_CellFilter<Inspector>::Point &, const typename NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Add, "Adds a target object for further search in the range of cells defined by two points (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point)", py::arg("theTarget"), py::arg("thePntMin"), py::arg("thePntMax"));
	cls.def("Remove", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Target &, const typename NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Remove, "Find a target object at a point and remove it from the structures. For usage of this method 'operator ==' should be defined for Target.", py::arg("theTarget"), py::arg("thePnt"));
	cls.def("Remove", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Target &, const typename NCollection_CellFilter<Inspector>::Point &, const typename NCollection_CellFilter<Inspector>::Point &)) &NCollection_CellFilter<Inspector>::Remove, "Find a target object in the range of cells defined by two points and remove it from the structures (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point). For usage of this method 'operator ==' should be defined for Target.", py::arg("theTarget"), py::arg("thePntMin"), py::arg("thePntMax"));
	cls.def("Inspect", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Point &, Inspector &)) &NCollection_CellFilter<Inspector>::Inspect, "Inspect all targets in the cell corresponding to the given point", py::arg("thePnt"), py::arg("theInspector"));
	cls.def("Inspect", (void (NCollection_CellFilter<Inspector>::*)(const typename NCollection_CellFilter<Inspector>::Point &, const typename NCollection_CellFilter<Inspector>::Point &, Inspector &)) &NCollection_CellFilter<Inspector>::Inspect, "Inspect all targets in the cells range limited by two given points (the first point must have all co-ordinates equal or less than the same co-ordinate of the second point)", py::arg("thePntMin"), py::arg("thePntMax"), py::arg("theInspector"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Comparator.hxx
template <typename TheItemType>
void bind_NCollection_Comparator(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Comparator.hxx
	py::class_<NCollection_Comparator<TheItemType>, std::unique_ptr<NCollection_Comparator<TheItemType>, Deleter<NCollection_Comparator<TheItemType>>>> cls(mod, name.c_str(), "Class to define basic compare operations. Basic implementation use redirection to standard C++ operators. You can use standard C++ templates mechanisms to redefine these methods or to inherit basic implementation to create multiple comparators for same type with different rules.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Real>(), py::arg("theTolerance"));
	cls.def("IsGreater", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const ) &NCollection_Comparator<TheItemType>::IsGreater, "Should return true if Left value is greater than Right", py::arg("theLeft"), py::arg("theRight"));
	cls.def("IsEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const ) &NCollection_Comparator<TheItemType>::IsEqual, "Should return true if values are equal", py::arg("theLeft"), py::arg("theRight"));
	cls.def("IsLower", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const ) &NCollection_Comparator<TheItemType>::IsLower, "Should return true if Left value is lower than Right", py::arg("theLeft"), py::arg("theRight"));
	cls.def("IsLowerEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const ) &NCollection_Comparator<TheItemType>::IsLowerEqual, "None", py::arg("theLeft"), py::arg("theRight"));
	cls.def("IsGreaterEqual", (Standard_Boolean (NCollection_Comparator<TheItemType>::*)(const TheItemType &, const TheItemType &) const ) &NCollection_Comparator<TheItemType>::IsGreaterEqual, "None", py::arg("theLeft"), py::arg("theRight"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
template <typename TheKeyType, typename TheItemType, typename Hasher>
void bind_NCollection_DataMap(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<NCollection_DataMap<TheKeyType, TheItemType, Hasher>, std::unique_ptr<NCollection_DataMap<TheKeyType, TheItemType, Hasher>, Deleter<NCollection_DataMap<TheKeyType, TheItemType, Hasher>>>, NCollection_BaseMap> cls(mod, name.c_str(), "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &other) {return new NCollection_DataMap<TheKeyType, TheItemType, Hasher>(other);}), "Copy constructor", py::arg("other"));
	cls.def("begin", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::begin, "Returns an iterator pointing to the first element in the map.");
	cls.def("end", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls.def("cbegin", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls.def("cend", (typename NCollection_DataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls.def("Exchange", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls.def("Assign", (NCollection_DataMap<TheKeyType, TheItemType, Hasher> & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_DataMap<TheKeyType, TheItemType, Hasher> & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("ReSize", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ReSize, "ReSize", py::arg("N"));
	cls.def("Bind", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls.def("Bound", (TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls.def("IsBound", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::IsBound, "IsBound", py::arg("theKey"));
	cls.def("UnBind", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls.def("Seek", (const TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls.def("Find", (const TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls.def("Find", (Standard_Boolean (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, TheItemType &) const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls.def("__call__", (const TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls.def("ChangeSeek", (TheItemType * (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls.def("ChangeFind", (TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls.def("__call__", (TheItemType & (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls.def("Clear", [](NCollection_DataMap<TheKeyType, TheItemType, Hasher> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Boolean)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls.def("Clear", (void (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls.def("Size", (Standard_Integer (NCollection_DataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_DataMap<TheKeyType, TheItemType, Hasher>::Size, "Size");
	cls.def("__iter__", [](const NCollection_DataMap<TheKeyType, TheItemType, Hasher> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
template <typename TheKeyType>
void bind_NCollection_DefaultHasher(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<NCollection_DefaultHasher<TheKeyType>, std::unique_ptr<NCollection_DefaultHasher<TheKeyType>, Deleter<NCollection_DefaultHasher<TheKeyType>>>> cls(mod, name.c_str(), "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls.def(py::init<>());
	cls.def_static("HashCode_", (Standard_Integer (*)(const TheKeyType &, const Standard_Integer)) &NCollection_DefaultHasher<TheKeyType>::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls.def_static("IsEqual_", (Standard_Boolean (*)(const TheKeyType &, const TheKeyType &)) &NCollection_DefaultHasher<TheKeyType>::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
template <typename TheKey1Type, typename TheKey2Type, typename Hasher1, typename Hasher2>
void bind_NCollection_DoubleMap(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>, std::unique_ptr<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>, Deleter<NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>>>, NCollection_BaseMap> cls(mod, name.c_str(), "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &other) {return new NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>(other);}), "Copy constructor", py::arg("other"));
	cls.def("Exchange", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls.def("Assign", (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("ReSize", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const Standard_Integer)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::ReSize, "ReSize", py::arg("N"));
	cls.def("Bind", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &, const TheKey2Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls.def("AreBound", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &, const TheKey2Type &) const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls.def("IsBound1", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &) const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::IsBound1, "IsBound1", py::arg("theKey1"));
	cls.def("IsBound2", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &) const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::IsBound2, "IsBound2", py::arg("theKey2"));
	cls.def("UnBind1", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::UnBind1, "UnBind1", py::arg("theKey1"));
	cls.def("UnBind2", (Standard_Boolean (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::UnBind2, "UnBind2", py::arg("theKey2"));
	cls.def("Find1", (const TheKey2Type & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey1Type &) const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Find1, "Find1", py::arg("theKey1"));
	cls.def("Find2", (const TheKey1Type & (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const TheKey2Type &) const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Find2, "Find2", py::arg("theKey2"));
	cls.def("Clear", [](NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const Standard_Boolean)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls.def("Clear", (void (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls.def("Size", (Standard_Integer (NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::*)() const ) &NCollection_DoubleMap<TheKey1Type, TheKey2Type, Hasher1, Hasher2>::Size, "Size");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_EBTree.hxx
template <typename TheObjType, typename TheBndType>
void bind_NCollection_EBTree(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_EBTree.hxx
	py::class_<NCollection_EBTree<TheObjType, TheBndType>, std::unique_ptr<NCollection_EBTree<TheObjType, TheBndType>, Deleter<NCollection_EBTree<TheObjType, TheBndType>>>, NCollection_UBTree<TheObjType, TheBndType>> cls(mod, name.c_str(), "The algorithm of unbalanced binary tree of overlapped bounding boxes with the possibility of deleting objects from the tree.");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls.def("Add", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_EBTree<TheObjType, TheBndType>::Add, "Extends the functionality of the parent method by maintaining the map myObjNodeMap. Redefined virtual method", py::arg("theObj"), py::arg("theBnd"));
	cls.def("Remove", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &)) &NCollection_EBTree<TheObjType, TheBndType>::Remove, "Removes the given object and updates the tree.", py::arg("theObj"));
	cls.def("Contains", (Standard_Boolean (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &) const ) &NCollection_EBTree<TheObjType, TheBndType>::Contains, "Returns True if the tree contains the object.", py::arg("theObj"));
	cls.def("FindNode", (const typename NCollection_EBTree<TheObjType, TheBndType>::TreeNode & (NCollection_EBTree<TheObjType, TheBndType>::*)(const TheObjType &) const ) &NCollection_EBTree<TheObjType, TheBndType>::FindNode, "Returns The leaf node containing the object.", py::arg("theObj"));
	cls.def("Clear", [](NCollection_EBTree<TheObjType, TheBndType> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_EBTree<TheObjType, TheBndType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_EBTree<TheObjType, TheBndType>::Clear, "Clears the contents of the tree. Redefined virtual method", py::arg("aNewAlloc"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Handle.hxx
template <typename T>
void bind_NCollection_Handle(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Handle.hxx
	// FIXME Don't bind base class opencascade::handle<Standard_Transient>
	// py::class_<NCollection_Handle<T>, std::unique_ptr<NCollection_Handle<T>, Deleter<NCollection_Handle<T>>>, opencascade::handle<Standard_Transient>> cls(mod, name.c_str(), "Purpose: This template class is used to define Handle adaptor for allocated dynamically objects of arbitrary type.");
	py::class_<NCollection_Handle<T>, std::unique_ptr<NCollection_Handle<T>, Deleter<NCollection_Handle<T>>>> cls(mod, name.c_str(), "Purpose: This template class is used to define Handle adaptor for allocated dynamically objects of arbitrary type.");
	cls.def(py::init<>());
	cls.def(py::init<T *>(), py::arg("theObject"));
	cls.def("get", (T * (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::get, "Cast handle to contained type");
	cls.def("get", (const T * (NCollection_Handle<T>::*)() const ) &NCollection_Handle<T>::get, "Cast handle to contained type");
	// FIXME cls.def("operator->", (T * (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::operator->, "Cast handle to contained type");
	// FIXME cls.def("operator->", (const T * (NCollection_Handle<T>::*)() const ) &NCollection_Handle<T>::operator->, "Cast handle to contained type");
	cls.def("__mul__", (T & (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::operator*, py::is_operator(), "Cast handle to contained type");
	cls.def("__mul__", (const T & (NCollection_Handle<T>::*)() const ) &NCollection_Handle<T>::operator*, py::is_operator(), "Cast handle to contained type");
	cls.def_static("DownCast_", (NCollection_Handle<T> (*)(const opencascade::handle<Standard_Transient> &)) &NCollection_Handle<T>::DownCast, "Downcast arbitrary Handle to the argument type if contained object is Handle for this type; returns null otherwise", py::arg("theOther"));
};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
template <typename TheKeyType, typename TheItemType, typename Hasher>
void bind_NCollection_IndexedDataMap(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>, std::unique_ptr<NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>, Deleter<NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>>>, NCollection_BaseMap> cls(mod, name.c_str(), "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &other) {return new NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>(other);}), "Copy constructor", py::arg("other"));
	cls.def("begin", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::begin, "Returns an iterator pointing to the first element in the map.");
	cls.def("end", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls.def("cbegin", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls.def("cend", (typename NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::const_iterator (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls.def("Exchange", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls.def("Assign", (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("ReSize", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ReSize, "ReSize", py::arg("N"));
	cls.def("Add", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, const TheItemType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls.def("Contains", (Standard_Boolean (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Contains, "Contains", py::arg("theKey1"));
	cls.def("Substitute", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer, const TheKeyType &, const TheItemType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls.def("Swap", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls.def("RemoveLast", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)()) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveLast, "RemoveLast");
	cls.def("RemoveFromIndex", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls.def("RemoveKey", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls.def("FindKey", (const TheKeyType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindKey, "FindKey", py::arg("theKey2"));
	cls.def("FindFromIndex", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls.def("__call__", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls.def("ChangeFromIndex", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls.def("__call__", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls.def("FindIndex", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindIndex, "FindIndex", py::arg("theKey1"));
	cls.def("FindFromKey", (const TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls.def("ChangeFromKey", (TheItemType & (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls.def("Seek", (const TheItemType * (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls.def("ChangeSeek", (TheItemType * (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls.def("FindFromKey", (Standard_Boolean (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const TheKeyType &, TheItemType &) const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls.def("Clear", [](NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const Standard_Boolean)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls.def("Clear", (void (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls.def("Size", (Standard_Integer (NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::*)() const ) &NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher>::Size, "Size");
	cls.def("__iter__", [](const NCollection_IndexedDataMap<TheKeyType, TheItemType, Hasher> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
template <typename TheKeyType, typename Hasher>
void bind_NCollection_IndexedMap(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<NCollection_IndexedMap<TheKeyType, Hasher>, std::unique_ptr<NCollection_IndexedMap<TheKeyType, Hasher>, Deleter<NCollection_IndexedMap<TheKeyType, Hasher>>>, NCollection_BaseMap> cls(mod, name.c_str(), "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_IndexedMap<TheKeyType, Hasher> &other) {return new NCollection_IndexedMap<TheKeyType, Hasher>(other);}), "Copy constructor", py::arg("other"));
	cls.def("cbegin", (typename NCollection_IndexedMap<TheKeyType, Hasher>::const_iterator (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const ) &NCollection_IndexedMap<TheKeyType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls.def("cend", (typename NCollection_IndexedMap<TheKeyType, Hasher>::const_iterator (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const ) &NCollection_IndexedMap<TheKeyType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls.def("Exchange", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls.def("Assign", (NCollection_IndexedMap<TheKeyType, Hasher> & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_IndexedMap<TheKeyType, Hasher> & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const NCollection_IndexedMap<TheKeyType, Hasher> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("ReSize", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::ReSize, "ReSize", py::arg("N"));
	cls.def("Add", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Add, "Add", py::arg("theKey1"));
	cls.def("Contains", (Standard_Boolean (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedMap<TheKeyType, Hasher>::Contains, "Contains", py::arg("theKey1"));
	// FIXME cls.def("Substitute", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer, const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls.def("Swap", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls.def("RemoveLast", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)()) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveLast, "RemoveLast");
	cls.def("RemoveFromIndex", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls.def("RemoveKey", (Standard_Boolean (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_IndexedMap<TheKeyType, Hasher>::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls.def("FindKey", (const TheKeyType & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer) const ) &NCollection_IndexedMap<TheKeyType, Hasher>::FindKey, "FindKey", py::arg("theKey2"));
	cls.def("__call__", (const TheKeyType & (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Integer) const ) &NCollection_IndexedMap<TheKeyType, Hasher>::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls.def("FindIndex", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const TheKeyType &) const ) &NCollection_IndexedMap<TheKeyType, Hasher>::FindIndex, "FindIndex", py::arg("theKey1"));
	cls.def("Clear", [](NCollection_IndexedMap<TheKeyType, Hasher> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const Standard_Boolean)) &NCollection_IndexedMap<TheKeyType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls.def("Clear", (void (NCollection_IndexedMap<TheKeyType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_IndexedMap<TheKeyType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls.def("Size", (Standard_Integer (NCollection_IndexedMap<TheKeyType, Hasher>::*)() const ) &NCollection_IndexedMap<TheKeyType, Hasher>::Size, "Size");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Lerp.hxx
template <typename T>
void bind_NCollection_Lerp(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Lerp.hxx
	py::class_<NCollection_Lerp<T>, std::unique_ptr<NCollection_Lerp<T>, Deleter<NCollection_Lerp<T>>>> cls(mod, name.c_str(), "Simple linear interpolation tool (also known as mix() in GLSL). The main purpose of this template class is making interpolation routines more readable.");
	cls.def(py::init<>());
	cls.def(py::init<const T &, const T &>(), py::arg("theStart"), py::arg("theEnd"));
	cls.def_static("Interpolate_", (T (*)(const T &, const T &, double)) &NCollection_Lerp<T>::Interpolate, "Compute interpolated value between two values.", py::arg("theStart"), py::arg("theEnd"), py::arg("theT"));
	cls.def("Init", (void (NCollection_Lerp<T>::*)(const T &, const T &)) &NCollection_Lerp<T>::Init, "Initialize values.", py::arg("theStart"), py::arg("theEnd"));
	cls.def("Interpolate", (void (NCollection_Lerp<T>::*)(double, T &) const ) &NCollection_Lerp<T>::Interpolate, "Compute interpolated value between two values.", py::arg("theT"), py::arg("theResult"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
template <typename TheItemType>
void bind_NCollection_List(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<NCollection_List<TheItemType>, std::unique_ptr<NCollection_List<TheItemType>, Deleter<NCollection_List<TheItemType>>>, NCollection_BaseList> cls(mod, name.c_str(), "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_List<TheItemType> &other) {return new NCollection_List<TheItemType>(other);}), "Copy constructor", py::arg("other"));
	cls.def("begin", (typename NCollection_List<TheItemType>::iterator (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::begin, "Returns an iterator pointing to the first element in the list.");
	cls.def("end", (typename NCollection_List<TheItemType>::iterator (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls.def("cbegin", (typename NCollection_List<TheItemType>::const_iterator (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls.def("cend", (typename NCollection_List<TheItemType>::const_iterator (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls.def("Size", (Standard_Integer (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::Size, "Size - Number of items");
	cls.def("Assign", (NCollection_List<TheItemType> & (NCollection_List<TheItemType>::*)(const NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_List<TheItemType> & (NCollection_List<TheItemType>::*)(const NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls.def("Clear", [](NCollection_List<TheItemType> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_List<TheItemType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_List<TheItemType>::Clear, "Clear this list", py::arg("theAllocator"));
	cls.def("First", (const TheItemType & (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::First, "First item");
	cls.def("First", (TheItemType & (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::First, "First item (non-const)");
	cls.def("Last", (const TheItemType & (NCollection_List<TheItemType>::*)() const ) &NCollection_List<TheItemType>::Last, "Last item");
	cls.def("Last", (TheItemType & (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::Last, "Last item (non-const)");
	cls.def("Append", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &)) &NCollection_List<TheItemType>::Append, "Append one item at the end", py::arg("theItem"));
	cls.def("Append", (void (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls.def("Append", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Append, "Append another list at the end", py::arg("theOther"));
	cls.def("Prepend", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &)) &NCollection_List<TheItemType>::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls.def("Prepend", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &)) &NCollection_List<TheItemType>::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls.def("RemoveFirst", (void (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::RemoveFirst, "RemoveFirst item");
	cls.def("Remove", (void (NCollection_List<TheItemType>::*)(typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls.def("InsertBefore", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls.def("InsertBefore", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls.def("InsertAfter", (TheItemType & (NCollection_List<TheItemType>::*)(const TheItemType &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls.def("InsertAfter", (void (NCollection_List<TheItemType>::*)(NCollection_List<TheItemType> &, typename NCollection_List<TheItemType>::Iterator &)) &NCollection_List<TheItemType>::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls.def("Reverse", (void (NCollection_List<TheItemType>::*)()) &NCollection_List<TheItemType>::Reverse, "Reverse the list");
	cls.def("__iter__", [](const NCollection_List<TheItemType> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_LocalArray.hxx
template <typename theItem, Standard_Integer MAX_ARRAY_SIZE>
void bind_NCollection_LocalArray(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_LocalArray.hxx
	py::class_<NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>, std::unique_ptr<NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>, Deleter<NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>>>> cls(mod, name.c_str(), "Auxiliary class optimizing creation of array buffer (using stack allocation for small arrays).");
	cls.def(py::init<const size_t>(), py::arg("theSize"));
	cls.def(py::init<>());
	cls.def("Allocate", (void (NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::*)(const size_t)) &NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::Allocate, "None", py::arg("theSize"));
	cls.def("Size", (size_t (NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::*)() const ) &NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::Size, "None");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
template <typename TheKeyType, typename Hasher>
void bind_NCollection_Map(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<NCollection_Map<TheKeyType, Hasher>, std::unique_ptr<NCollection_Map<TheKeyType, Hasher>, Deleter<NCollection_Map<TheKeyType, Hasher>>>, NCollection_BaseMap> cls(mod, name.c_str(), "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_Map<TheKeyType, Hasher> &other) {return new NCollection_Map<TheKeyType, Hasher>(other);}), "Copy constructor", py::arg("other"));
	cls.def("cbegin", (typename NCollection_Map<TheKeyType, Hasher>::const_iterator (NCollection_Map<TheKeyType, Hasher>::*)() const ) &NCollection_Map<TheKeyType, Hasher>::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls.def("cend", (typename NCollection_Map<TheKeyType, Hasher>::const_iterator (NCollection_Map<TheKeyType, Hasher>::*)() const ) &NCollection_Map<TheKeyType, Hasher>::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls.def("Exchange", (void (NCollection_Map<TheKeyType, Hasher>::*)(NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls.def("Assign", (NCollection_Map<TheKeyType, Hasher> & (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_Map<TheKeyType, Hasher> & (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls.def("ReSize", (void (NCollection_Map<TheKeyType, Hasher>::*)(const Standard_Integer)) &NCollection_Map<TheKeyType, Hasher>::ReSize, "ReSize", py::arg("N"));
	cls.def("Add", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Add, "Add", py::arg("K"));
	cls.def("Added", (const TheKeyType & (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls.def("Contains", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &) const ) &NCollection_Map<TheKeyType, Hasher>::Contains, "Contains", py::arg("K"));
	cls.def("Remove", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const TheKeyType &)) &NCollection_Map<TheKeyType, Hasher>::Remove, "Remove", py::arg("K"));
	cls.def("Clear", [](NCollection_Map<TheKeyType, Hasher> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_Map<TheKeyType, Hasher>::*)(const Standard_Boolean)) &NCollection_Map<TheKeyType, Hasher>::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls.def("Clear", (void (NCollection_Map<TheKeyType, Hasher>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Map<TheKeyType, Hasher>::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls.def("Size", (Standard_Integer (NCollection_Map<TheKeyType, Hasher>::*)() const ) &NCollection_Map<TheKeyType, Hasher>::Size, "Size");
	cls.def("IsEqual", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const ) &NCollection_Map<TheKeyType, Hasher>::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls.def("Contains", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const ) &NCollection_Map<TheKeyType, Hasher>::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls.def("Union", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls.def("Unite", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls.def("HasIntersection", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &) const ) &NCollection_Map<TheKeyType, Hasher>::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls.def("Intersection", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls.def("Intersect", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls.def("Subtraction", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls.def("Subtract", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls.def("Difference", (void (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &, const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls.def("Differ", (Standard_Boolean (NCollection_Map<TheKeyType, Hasher>::*)(const NCollection_Map<TheKeyType, Hasher> &)) &NCollection_Map<TheKeyType, Hasher>::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Mat4.hxx
template <typename Element_t>
void bind_NCollection_Mat4(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Mat4.hxx
	py::class_<NCollection_Mat4<Element_t>, std::unique_ptr<NCollection_Mat4<Element_t>, Deleter<NCollection_Mat4<Element_t>>>> cls(mod, name.c_str(), "Generic matrix of 4 x 4 elements. To be used in conjunction with NCollection_Vec4 entities. Originally introduced for 3D space projection and orientation operations.");
	cls.def(py::init<>());
	cls.def_static("Rows_", (size_t (*)()) &NCollection_Mat4<Element_t>::Rows, "Get number of rows.");
	cls.def_static("Cols_", (size_t (*)()) &NCollection_Mat4<Element_t>::Cols, "Get number of columns.");
	cls.def("GetValue", (Element_t (NCollection_Mat4<Element_t>::*)(const size_t, const size_t) const ) &NCollection_Mat4<Element_t>::GetValue, "Get element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls.def("ChangeValue", (Element_t & (NCollection_Mat4<Element_t>::*)(const size_t, const size_t)) &NCollection_Mat4<Element_t>::ChangeValue, "Access element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls.def("SetValue", (void (NCollection_Mat4<Element_t>::*)(const size_t, const size_t, const Element_t)) &NCollection_Mat4<Element_t>::SetValue, "Set value for the element specified by row and columns.", py::arg("theRow"), py::arg("theCol"), py::arg("theValue"));
	cls.def("GetRow", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const size_t) const ) &NCollection_Mat4<Element_t>::GetRow, "Get vector of elements for the specified row.", py::arg("theRow"));
	cls.def("SetRow", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetRow, "Change first 3 row values by the passed vector.", py::arg("theRow"), py::arg("theVec"));
	cls.def("SetRow", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetRow, "Set row values by the passed 4 element vector.", py::arg("theRow"), py::arg("theVec"));
	cls.def("GetColumn", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const size_t) const ) &NCollection_Mat4<Element_t>::GetColumn, "Get vector of elements for the specified column.", py::arg("theCol"));
	cls.def("SetColumn", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetColumn, "Change first 3 column values by the passed vector.", py::arg("theCol"), py::arg("theVec"));
	cls.def("SetColumn", (void (NCollection_Mat4<Element_t>::*)(const size_t, const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetColumn, "Set column values by the passed 4 element vector.", py::arg("theCol"), py::arg("theVec"));
	cls.def("GetDiagonal", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)() const ) &NCollection_Mat4<Element_t>::GetDiagonal, "Get vector of diagonal elements.");
	cls.def("SetDiagonal", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::SetDiagonal, "Change first 3 elements of the diagonal matrix.", py::arg("theVec"));
	cls.def("SetDiagonal", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Mat4<Element_t>::SetDiagonal, "Set diagonal elements of the matrix by the passed vector.", py::arg("theVec"));
	cls.def("InitIdentity", (void (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::InitIdentity, "Initialize the identity matrix.");
	cls.def("IsIdentity", (bool (NCollection_Mat4<Element_t>::*)() const ) &NCollection_Mat4<Element_t>::IsIdentity, "Checks the matrix for identity.");
	cls.def("IsEqual", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::IsEqual, "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator==, py::is_operator(), "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator!=, py::is_operator(), "Check this matrix for non-equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls.def("GetData", (const Element_t * (NCollection_Mat4<Element_t>::*)() const ) &NCollection_Mat4<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
	cls.def("ChangeData", (Element_t * (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::ChangeData, "None");
	cls.def("__mul__", (NCollection_Vec4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Multiply by the vector (M * V).", py::arg("theVec"));
	cls.def("Multiply", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &, const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::Multiply, "Compute matrix multiplication product: A * B.", py::arg("theMatA"), py::arg("theMatB"));
	cls.def("Multiply", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::Multiply, "Compute matrix multiplication.", py::arg("theMat"));
	cls.def("__imul__", (NCollection_Mat4<Element_t> & (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &)) &NCollection_Mat4<Element_t>::operator*=, "Multiply by the another matrix.", py::arg("theMat"));
	cls.def("__mul__", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Compute matrix multiplication product.", py::arg("theMat"));
	cls.def("Multiplied", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::Multiplied, "Compute matrix multiplication product.", py::arg("theMat"));
	cls.def("Multiply", (void (NCollection_Mat4<Element_t>::*)(const Element_t)) &NCollection_Mat4<Element_t>::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls.def("__imul__", (NCollection_Mat4<Element_t> & (NCollection_Mat4<Element_t>::*)(const Element_t)) &NCollection_Mat4<Element_t>::operator*=, "Compute per-element multiplication.", py::arg("theFactor"));
	cls.def("__mul__", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const Element_t) const ) &NCollection_Mat4<Element_t>::operator*, py::is_operator(), "Compute per-element multiplication.", py::arg("theFactor"));
	cls.def("Multiplied", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)(const Element_t) const ) &NCollection_Mat4<Element_t>::Multiplied, "Compute per-element multiplication.", py::arg("theFactor"));
	cls.def("Translate", (void (NCollection_Mat4<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Mat4<Element_t>::Translate, "Translate the matrix on the passed vector.", py::arg("theVec"));
	cls.def("Transposed", (NCollection_Mat4<Element_t> (NCollection_Mat4<Element_t>::*)() const ) &NCollection_Mat4<Element_t>::Transposed, "Transpose the matrix.");
	cls.def("Transpose", (void (NCollection_Mat4<Element_t>::*)()) &NCollection_Mat4<Element_t>::Transpose, "Transpose the matrix.");
	cls.def("Inverted", (bool (NCollection_Mat4<Element_t>::*)(NCollection_Mat4<Element_t> &) const ) &NCollection_Mat4<Element_t>::Inverted, "Compute inverted matrix.", py::arg("theOutMx"));
	cls.def_static("Map_", (NCollection_Mat4<Element_t> & (*)(Element_t *)) &NCollection_Mat4<Element_t>::Map, "Maps plain C array to matrix type.", py::arg("theData"));
	cls.def_static("Map_", (const NCollection_Mat4<Element_t> & (*)(const Element_t *)) &NCollection_Mat4<Element_t>::Map, "Maps plain C array to matrix type.", py::arg("theData"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
template <typename TheItemType>
void bind_NCollection_Sequence(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<NCollection_Sequence<TheItemType>, std::unique_ptr<NCollection_Sequence<TheItemType>, Deleter<NCollection_Sequence<TheItemType>>>, NCollection_BaseSequence> cls(mod, name.c_str(), "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls.def(py::init([] (const NCollection_Sequence<TheItemType> &other) {return new NCollection_Sequence<TheItemType>(other);}), "Copy constructor", py::arg("other"));
	cls.def("begin", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls.def("end", (typename NCollection_Sequence<TheItemType>::iterator (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls.def("cbegin", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls.def("cend", (typename NCollection_Sequence<TheItemType>::const_iterator (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls.def("Size", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::Size, "Number of items");
	cls.def("Length", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::Length, "Number of items");
	cls.def("Lower", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::Lower, "Method for consistency with other collections.");
	cls.def("Upper", (Standard_Integer (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::Upper, "Method for consistency with other collections.");
	cls.def("IsEmpty", (Standard_Boolean (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::IsEmpty, "Empty query");
	cls.def("Reverse", (void (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::Reverse, "Reverse sequence");
	cls.def("Exchange", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Sequence<TheItemType>::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Sequence<TheItemType>::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls.def("Clear", [](NCollection_Sequence<TheItemType> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_Sequence<TheItemType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Sequence<TheItemType>::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls.def("Assign", (NCollection_Sequence<TheItemType> & (NCollection_Sequence<TheItemType>::*)(const NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls.def("assign", (NCollection_Sequence<TheItemType> & (NCollection_Sequence<TheItemType>::*)(const NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(typename NCollection_Sequence<TheItemType>::Iterator &)) &NCollection_Sequence<TheItemType>::Remove, "Remove one item", py::arg("thePosition"));
	cls.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::Remove, "Remove one item", py::arg("theIndex"));
	cls.def("Remove", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const Standard_Integer)) &NCollection_Sequence<TheItemType>::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls.def("Append", (void (NCollection_Sequence<TheItemType>::*)(const TheItemType &)) &NCollection_Sequence<TheItemType>::Append, "Append one item", py::arg("theItem"));
	cls.def("Append", (void (NCollection_Sequence<TheItemType>::*)(NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls.def("Prepend", (void (NCollection_Sequence<TheItemType>::*)(const TheItemType &)) &NCollection_Sequence<TheItemType>::Prepend, "Prepend one item", py::arg("theItem"));
	cls.def("Prepend", (void (NCollection_Sequence<TheItemType>::*)(NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls.def("InsertBefore", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls.def("InsertBefore", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(typename NCollection_Sequence<TheItemType>::Iterator &, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls.def("InsertAfter", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls.def("Split", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, NCollection_Sequence<TheItemType> &)) &NCollection_Sequence<TheItemType>::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls.def("First", (const TheItemType & (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::First, "First item access");
	cls.def("ChangeFirst", (TheItemType & (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::ChangeFirst, "First item access");
	cls.def("Last", (const TheItemType & (NCollection_Sequence<TheItemType>::*)() const ) &NCollection_Sequence<TheItemType>::Last, "Last item access");
	cls.def("ChangeLast", (TheItemType & (NCollection_Sequence<TheItemType>::*)()) &NCollection_Sequence<TheItemType>::ChangeLast, "Last item access");
	cls.def("Value", (const TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Sequence<TheItemType>::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls.def("__call__", (const TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Sequence<TheItemType>::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls.def("ChangeValue", (TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls.def("__call__", (TheItemType & (NCollection_Sequence<TheItemType>::*)(const Standard_Integer)) &NCollection_Sequence<TheItemType>::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls.def("SetValue", (void (NCollection_Sequence<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Sequence<TheItemType>::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls.def("__iter__", [](const NCollection_Sequence<TheItemType> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Shared.hxx
template <typename T, typename = typename std::enable_if<!std::is_base_of<Standard_Transient, T>::value>::type>
void bind_NCollection_Shared(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Shared.hxx
	// FIXME Don't bind. Not sure how to handle this template...
	// py::class_<NCollection_Shared<T, std::enable_if<!std::is_base_of<Standard_Transient, T>::value>::type>, opencascade::handle<NCollection_Shared<T, std::enable_if<!std::is_base_of<Standard_Transient, T>::value>::type>>, Standard_Transient, T> cls(mod, name.c_str(), "Template defining a class derived from the specified base class and Standard_Transient, and supporting OCCT RTTI.");
	// cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_SparseArray.hxx
template <typename TheItemType>
void bind_NCollection_SparseArray(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_SparseArray.hxx
	py::class_<NCollection_SparseArray<TheItemType>, std::unique_ptr<NCollection_SparseArray<TheItemType>, Deleter<NCollection_SparseArray<TheItemType>>>, NCollection_SparseArrayBase> cls(mod, name.c_str(), "Dynamically resizable sparse array of objects");
	cls.def(py::init<Standard_Size>(), py::arg("theIncrement"));
	cls.def("Assign", (NCollection_SparseArray<TheItemType> & (NCollection_SparseArray<TheItemType>::*)(const NCollection_SparseArray<TheItemType> &)) &NCollection_SparseArray<TheItemType>::Assign, "Explicit assignment operator", py::arg("theOther"));
	cls.def("Exchange", (void (NCollection_SparseArray<TheItemType>::*)(NCollection_SparseArray<TheItemType> &)) &NCollection_SparseArray<TheItemType>::Exchange, "Exchange the data of two arrays; can be used primarily to move contents of theOther into the new array in a fast way (without creation of duplicated data)", py::arg("theOther"));
	cls.def("Value", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const ) &NCollection_SparseArray<TheItemType>::Value, "Direct const access to the item", py::arg("theIndex"));
	cls.def("__call__", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const ) &NCollection_SparseArray<TheItemType>::operator(), py::is_operator(), "Const access to the item - operator()", py::arg("theIndex"));
	cls.def("ChangeValue", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::ChangeValue, "Modification access to the item", py::arg("theIndex"));
	cls.def("__call__", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::operator(), py::is_operator(), "Access to the item - operator()", py::arg("theIndex"));
	cls.def("SetValue", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size, const TheItemType &)) &NCollection_SparseArray<TheItemType>::SetValue, "Set a value at specified index method", py::arg("theIndex"), py::arg("theValue"));
	cls.def("Extent", (Standard_Size (NCollection_SparseArray<TheItemType>::*)() const ) &NCollection_SparseArray<TheItemType>::Extent, "Returns number of items in the array");
	cls.def("IsEmpty", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)() const ) &NCollection_SparseArray<TheItemType>::IsEmpty, "Returns True if array is empty");
	cls.def("Find", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const ) &NCollection_SparseArray<TheItemType>::Find, "Direct const access to the item", py::arg("theIndex"));
	cls.def("ChangeFind", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::ChangeFind, "Modification access to the item", py::arg("theIndex"));
	cls.def("Bind", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size, const TheItemType &)) &NCollection_SparseArray<TheItemType>::Bind, "Set a value as explicit method", py::arg("theIndex"), py::arg("theValue"));
	cls.def("IsBound", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const ) &NCollection_SparseArray<TheItemType>::IsBound, "Returns True if the item is defined", py::arg("theIndex"));
	cls.def("UnBind", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::UnBind, "Remove the item from array", py::arg("theIndex"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_StdAllocator.hxx
template <typename T>
void bind_NCollection_StdAllocator(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_StdAllocator.hxx
	py::class_<NCollection_StdAllocator<T>, std::unique_ptr<NCollection_StdAllocator<T>, Deleter<NCollection_StdAllocator<T>>>> cls(mod, name.c_str(), "Implements allocator requirements as defined in ISO C++ Standard 2003, section 20.1.5. The allocator uses instance of the NCollection_BaseAllocator (sub)class for memory allocation/deallocation. The allocator can be used with standard containers (std::vector, std::map, etc) to take advantage of NCollection_IncAllocator which implements memory region concept, and hence to increase performance in specific cases.");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls.def("address", (typename NCollection_StdAllocator<T>::pointer (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::reference) const ) &NCollection_StdAllocator<T>::address, "Returns an object address. Returns &x.", py::arg("x"));
	cls.def("address", (typename NCollection_StdAllocator<T>::const_pointer (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::const_reference) const ) &NCollection_StdAllocator<T>::address, "Returns an object address. Returns &x.", py::arg("x"));
	cls.def("allocate", [](NCollection_StdAllocator<T> &self, typename NCollection_StdAllocator<T>::size_type a0) -> typename NCollection_StdAllocator<T>::pointer { return self.allocate(a0); }, py::arg("n"));
	cls.def("allocate", (typename NCollection_StdAllocator<T>::pointer (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::size_type, const void *)) &NCollection_StdAllocator<T>::allocate, "Allocates memory for n objects. Uses underlying allocator to allocate memory.", py::arg("n"), py::arg(""));
	cls.def("deallocate", (void (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::pointer, typename NCollection_StdAllocator<T>::size_type)) &NCollection_StdAllocator<T>::deallocate, "Frees previously allocated memory. Uses underlying allocator to deallocate memory.", py::arg("p"), py::arg(""));
	cls.def("max_size", (typename NCollection_StdAllocator<T>::size_type (NCollection_StdAllocator<T>::*)() const ) &NCollection_StdAllocator<T>::max_size, "Returns the largest value for which method allocate might succeed.");
	cls.def("construct", (void (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::pointer, typename NCollection_StdAllocator<T>::const_reference)) &NCollection_StdAllocator<T>::construct, "Constructs an object. Uses placement new operator and copy constructor to construct an object.", py::arg("p"), py::arg("val"));
	cls.def("destroy", (void (NCollection_StdAllocator<T>::*)(typename NCollection_StdAllocator<T>::pointer)) &NCollection_StdAllocator<T>::destroy, "Destroys the object. Uses object destructor.", py::arg("p"));
	cls.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_StdAllocator<T>::*)() const ) &NCollection_StdAllocator<T>::Allocator, "Returns an underlying NCollection_BaseAllocator instance. Returns an object specified in the constructor.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_StlIterator.hxx
template <typename Category, typename BaseIterator, typename ItemType, bool IsConstant>
void bind_NCollection_StlIterator(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_StlIterator.hxx
	py::class_<NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>, std::unique_ptr<NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>, Deleter<NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>>>, std::iterator<Category, ItemType, ptrdiff_t, typename opencascade::conditional<IsConstant, const ItemType *, ItemType *>::type, typename opencascade::conditional<IsConstant, const ItemType &, ItemType &>::type>> cls(mod, name.c_str(), "Helper class that allows to use NCollection iterators as STL iterators. NCollection iterator can be extended to STL iterator of any category by adding necessary methods: STL forward iterator requires IsEqual method, STL bidirectional iterator requires Previous method, and STL random access iterator requires Offset and Differ methods. See NCollection_Vector as example of declaring custom STL iterators.");
	cls.def(py::init<>());
	cls.def(py::init<const BaseIterator &>(), py::arg("theIterator"));
	cls.def(py::init<const NCollection_StlIterator<Category, BaseIterator, ItemType, false> &>(), py::arg("theIterator"));
	cls.def("assign", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, false> &)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator=, py::is_operator(), "Assignment of non-const iterator to const one", py::arg("theIterator"));
	cls.def("Iterator", (const BaseIterator & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::Iterator, "Access to NCollection iterator instance");
	cls.def("ChangeIterator", (BaseIterator & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::ChangeIterator, "Access to NCollection iterator instance");
	cls.def("__eq__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator==, py::is_operator(), "Test for equality", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator!=, py::is_operator(), "Test for inequality", py::arg("theOther"));
	cls.def("__mul__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::reference (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator*, py::is_operator(), "Get reference to current item");
	// FIXME cls.def("operator->", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::pointer (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)() const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator->, "Dereferencing operator");
	cls.def("plus_plus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator++, py::is_operator(), "Prefix increment");
	cls.def("plus_plus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(int)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator++, py::is_operator(), "Postfix increment", py::arg(""));
	cls.def("minus_minus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)()) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator--, py::is_operator(), "Prefix decrement");
	cls.def("minus_minus", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(int)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator--, py::is_operator(), "Postfix decrement", py::arg(""));
	cls.def("__iadd__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator+=, "Move forward", py::arg("theOffset"));
	cls.def("__add__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator+, py::is_operator(), "Addition", py::arg("theOffset"));
	cls.def("__isub__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> & (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type)) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-=, "Move backward", py::arg("theOffset"));
	cls.def("__sub__", (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-, py::is_operator(), "Decrease", py::arg("theOffset"));
	cls.def("__sub__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator-, py::is_operator(), "Difference", py::arg("theOther"));
	cls.def("__getitem__", (typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::reference (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(typename NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::difference_type) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator[], py::is_operator(), "Get item at offset from current", py::arg("theOffset"));
	cls.def("__lt__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator<, py::is_operator(), "Comparison", py::arg("theOther"));
	cls.def("__gt__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator>, py::is_operator(), "Comparison", py::arg("theOther"));
	cls.def("__le__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator<=, py::is_operator(), "Comparison", py::arg("theOther"));
	cls.def("__ge__", (bool (NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::*)(const NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant> &) const ) &NCollection_StlIterator<Category, BaseIterator, ItemType, IsConstant>::operator>=, py::is_operator(), "Comparison", py::arg("theOther"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
template <typename TheItemType>
void bind_NCollection_TListIterator(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<NCollection_TListIterator<TheItemType>, std::unique_ptr<NCollection_TListIterator<TheItemType>, Deleter<NCollection_TListIterator<TheItemType>>>> cls(mod, name.c_str(), "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls.def(py::init<>());
	cls.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls.def("More", (Standard_Boolean (NCollection_TListIterator<TheItemType>::*)() const ) &NCollection_TListIterator<TheItemType>::More, "Check end");
	cls.def("Next", (void (NCollection_TListIterator<TheItemType>::*)()) &NCollection_TListIterator<TheItemType>::Next, "Make step");
	cls.def("Value", (const TheItemType & (NCollection_TListIterator<TheItemType>::*)() const ) &NCollection_TListIterator<TheItemType>::Value, "Constant Value access");
	cls.def("Value", (TheItemType & (NCollection_TListIterator<TheItemType>::*)()) &NCollection_TListIterator<TheItemType>::Value, "Non-const Value access");
	cls.def("ChangeValue", (TheItemType & (NCollection_TListIterator<TheItemType>::*)() const ) &NCollection_TListIterator<TheItemType>::ChangeValue, "Non-const Value access");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListNode.hxx
template <typename TheItemType>
void bind_NCollection_TListNode(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListNode.hxx
	py::class_<NCollection_TListNode<TheItemType>, std::unique_ptr<NCollection_TListNode<TheItemType>, Deleter<NCollection_TListNode<TheItemType>>>> cls(mod, name.c_str(), "Purpose: Abstract list node class. Used by BaseList Remark: Internal class");
	cls.def(py::init<const TheItemType &>(), py::arg("theItem"));
	cls.def(py::init<const TheItemType &, NCollection_ListNode *>(), py::arg("theItem"), py::arg("theNext"));
	cls.def("Value", (const TheItemType & (NCollection_TListNode<TheItemType>::*)() const ) &NCollection_TListNode<TheItemType>::Value, "Constant value access");
	cls.def("ChangeValue", (TheItemType & (NCollection_TListNode<TheItemType>::*)()) &NCollection_TListNode<TheItemType>::ChangeValue, "Variable value access");
	cls.def_static("delNode_", (void (*)(NCollection_ListNode *, opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_TListNode<TheItemType>::delNode, "Static deleter to be passed to BaseList", py::arg("theNode"), py::arg("theAl"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTree.hxx
template <typename TheObjType, typename TheBndType>
void bind_NCollection_UBTree(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTree.hxx
	py::class_<NCollection_UBTree<TheObjType, TheBndType>, std::unique_ptr<NCollection_UBTree<TheObjType, TheBndType>, Deleter<NCollection_UBTree<TheObjType, TheBndType>>>> cls(mod, name.c_str(), "The algorithm of unbalanced binary tree of overlapped bounding boxes.");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls.def("Add", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_UBTree<TheObjType, TheBndType>::Add, "Update the tree with a new object and its bounding box.", py::arg("theObj"), py::arg("theBnd"));
	cls.def("Select", (Standard_Integer (NCollection_UBTree<TheObjType, TheBndType>::*)(typename NCollection_UBTree<TheObjType, TheBndType>::Selector &) const ) &NCollection_UBTree<TheObjType, TheBndType>::Select, "Searches in the tree all objects conforming to the given selector. return Number of objects accepted", py::arg("theSelector"));
	cls.def("Clear", [](NCollection_UBTree<TheObjType, TheBndType> &self) -> void { return self.Clear(); });
	cls.def("Clear", (void (NCollection_UBTree<TheObjType, TheBndType>::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_UBTree<TheObjType, TheBndType>::Clear, "Clears the contents of the tree.", py::arg("aNewAlloc"));
	cls.def("IsEmpty", (Standard_Boolean (NCollection_UBTree<TheObjType, TheBndType>::*)() const ) &NCollection_UBTree<TheObjType, TheBndType>::IsEmpty, "None");
	cls.def("Root", (const typename NCollection_UBTree<TheObjType, TheBndType>::TreeNode & (NCollection_UBTree<TheObjType, TheBndType>::*)() const ) &NCollection_UBTree<TheObjType, TheBndType>::Root, "Returns the root node of the tree");
	cls.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_UBTree<TheObjType, TheBndType>::*)() const ) &NCollection_UBTree<TheObjType, TheBndType>::Allocator, "Recommended to be used only in sub-classes.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTreeFiller.hxx
template <typename TheObjType, typename TheBndType>
void bind_NCollection_UBTreeFiller(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTreeFiller.hxx
	py::class_<NCollection_UBTreeFiller<TheObjType, TheBndType>, std::unique_ptr<NCollection_UBTreeFiller<TheObjType, TheBndType>, Deleter<NCollection_UBTreeFiller<TheObjType, TheBndType>>>> cls(mod, name.c_str(), "This class is used to fill an UBTree in a random order. The quality of a tree is much better (from the point of view of the search time) if objects are added to it in a random order to avoid adding a chain of neerby objects one following each other.");
	cls.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &>(), py::arg("theTree"));
	cls.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theTree"), py::arg("theAlloc"));
	cls.def(py::init<typename NCollection_UBTreeFiller<TheObjType, TheBndType>::UBTree &, const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Boolean>(), py::arg("theTree"), py::arg("theAlloc"), py::arg("isFullRandom"));
	cls.def("Add", (void (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)(const TheObjType &, const TheBndType &)) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Add, "Adds a pair (theObj, theBnd) to my sequence", py::arg("theObj"), py::arg("theBnd"));
	cls.def("Fill", (Standard_Integer (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)()) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Fill, "Fills the tree with the objects from my sequence. This method clears the internal buffer of added items making sure that no item would be added twice.");
	cls.def("Reset", (void (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)()) &NCollection_UBTreeFiller<TheObjType, TheBndType>::Reset, "Remove all data from Filler, partculary if the Tree no more needed so the destructor of this Filler should not populate the useless Tree.");
	cls.def("CheckTree", (Standard_Integer (NCollection_UBTreeFiller<TheObjType, TheBndType>::*)(Standard_OStream &)) &NCollection_UBTreeFiller<TheObjType, TheBndType>::CheckTree, "Check the filled tree for the total number of items and the balance outputting these results to ostream.", py::arg("theStream"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
template <typename Type>
void bind_NCollection_UtfIterator(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	py::class_<NCollection_UtfIterator<Type>, std::unique_ptr<NCollection_UtfIterator<Type>, Deleter<NCollection_UtfIterator<Type>>>> cls(mod, name.c_str(), "Template class for Unicode strings support. It defines an iterator and provide correct way to read multi-byte text (UTF-8 and UTF-16) and convert it from one to another. The current value of iterator returned as UTF-32 Unicode code.");
	cls.def(py::init<const Type *>(), py::arg("theString"));
	cls.def("Init", (void (NCollection_UtfIterator<Type>::*)(const Type *)) &NCollection_UtfIterator<Type>::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
	cls.def("plus_plus", (NCollection_UtfIterator<Type> & (NCollection_UtfIterator<Type>::*)()) &NCollection_UtfIterator<Type>::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode character. Notice - no protection against overrun!");
	cls.def("plus_plus", (NCollection_UtfIterator<Type> (NCollection_UtfIterator<Type>::*)(int)) &NCollection_UtfIterator<Type>::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
	cls.def("__eq__", (bool (NCollection_UtfIterator<Type>::*)(const NCollection_UtfIterator<Type> &) const ) &NCollection_UtfIterator<Type>::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
	cls.def("IsValid", (bool (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::IsValid, "Return true if Unicode symbol is within valid range.");
	cls.def("__mul__", (Standard_Utf32Char (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::operator*, py::is_operator(), "Dereference operator.");
	cls.def("BufferHere", (const Type * (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::BufferHere, "Buffer-fetching getter.");
	cls.def("ChangeBufferHere", (Type * (NCollection_UtfIterator<Type>::*)()) &NCollection_UtfIterator<Type>::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
	cls.def("BufferNext", (const Type * (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::BufferNext, "Buffer-fetching getter.");
	cls.def("Index", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::Index, "Returns the index displacement from iterator intialization");
	cls.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
	cls.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
	cls.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
	cls.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_UtfIterator<Type>::*)() const ) &NCollection_UtfIterator<Type>::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
	cls.def("GetUtf8", (Standard_Utf8Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf8Char *) const ) &NCollection_UtfIterator<Type>::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls.def("GetUtf8", (Standard_Utf8UChar * (NCollection_UtfIterator<Type>::*)(Standard_Utf8UChar *) const ) &NCollection_UtfIterator<Type>::GetUtf8, "None", py::arg("theBuffer"));
	cls.def("GetUtf16", (Standard_Utf16Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf16Char *) const ) &NCollection_UtfIterator<Type>::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls.def("GetUtf32", (Standard_Utf32Char * (NCollection_UtfIterator<Type>::*)(Standard_Utf32Char *) const ) &NCollection_UtfIterator<Type>::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
template <typename Type>
void bind_NCollection_UtfString(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	py::class_<NCollection_UtfString<Type>, std::unique_ptr<NCollection_UtfString<Type>, Deleter<NCollection_UtfString<Type>>>> cls(mod, name.c_str(), "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.");
	cls.def(py::init<>());
	cls.def(py::init([] (const NCollection_UtfString<Type> &other) {return new NCollection_UtfString<Type>(other);}), "Copy constructor", py::arg("other"));
	cls.def(py::init<const char *>(), py::arg("theCopyUtf8"));
	cls.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
	cls.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
	cls.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
	cls.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
	cls.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
	cls.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
	cls.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));
	cls.def("Iterator", (NCollection_UtfIterator<Type> (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::Iterator, "None");
	cls.def("Size", (Standard_Integer (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::Size, "Returns the size of the buffer, excluding NULL-termination symbol");
	cls.def("Length", (Standard_Integer (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::Length, "Returns the length of the string in Unicode symbols");
	cls.def("GetChar", (Standard_Utf32Char (NCollection_UtfString<Type>::*)(const Standard_Integer) const ) &NCollection_UtfString<Type>::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls.def("GetCharBuffer", (const Type * (NCollection_UtfString<Type>::*)(const Standard_Integer) const ) &NCollection_UtfString<Type>::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls.def("__getitem__", (Standard_Utf32Char (NCollection_UtfString<Type>::*)(const Standard_Integer) const ) &NCollection_UtfString<Type>::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls.def("FromLocale", [](NCollection_UtfString<Type> &self, const char * a0) -> void { return self.FromLocale(a0); }, py::arg("theString"));
	cls.def("FromLocale", (void (NCollection_UtfString<Type>::*)(const char *, const Standard_Integer)) &NCollection_UtfString<Type>::FromLocale, "Copy from NULL-terminated multibyte string in system locale. You should avoid this function unless extreme necessity.", py::arg("theString"), py::arg("theLength"));
	cls.def("IsEqual", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const ) &NCollection_UtfString<Type>::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
	cls.def("SubString", (NCollection_UtfString<Type> (NCollection_UtfString<Type>::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_UtfString<Type>::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
	cls.def("ToCString", (const Type * (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
	cls.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::ToUtf8, "Returns copy in UTF-8 format");
	cls.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::ToUtf16, "Returns copy in UTF-16 format");
	cls.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::ToUtf32, "Returns copy in UTF-32 format");
	cls.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
	cls.def("ToLocale", (bool (NCollection_UtfString<Type>::*)(char *, const Standard_Integer) const ) &NCollection_UtfString<Type>::ToLocale, "Converts the string into multibyte string. You should avoid this function unless extreme necessity.", py::arg("theBuffer"), py::arg("theSizeBytes"));
	cls.def("IsEmpty", (bool (NCollection_UtfString<Type>::*)() const ) &NCollection_UtfString<Type>::IsEmpty, "Returns true if string is empty");
	cls.def("Clear", (void (NCollection_UtfString<Type>::*)()) &NCollection_UtfString<Type>::Clear, "Zero string.");
	cls.def("assign", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::operator=, py::is_operator(), "Copy from another string.", py::arg("theOther"));
	cls.def("assign", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const char *)) &NCollection_UtfString<Type>::operator=, py::is_operator(), "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
	cls.def("assign", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const Standard_WideChar *)) &NCollection_UtfString<Type>::operator=, py::is_operator(), "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
	cls.def("__iadd__", (NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::operator+=, "Join strings.", py::arg("theAppend"));
	cls.def("__eq__", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const ) &NCollection_UtfString<Type>::operator==, py::is_operator(), "", py::arg("theCompare"));
	cls.def("__ne__", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const ) &NCollection_UtfString<Type>::operator!=, py::is_operator(), "None", py::arg("theCompare"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec2.hxx
template <typename Element_t>
void bind_NCollection_Vec2(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec2.hxx
	py::class_<NCollection_Vec2<Element_t>, std::unique_ptr<NCollection_Vec2<Element_t>, Deleter<NCollection_Vec2<Element_t>>>> cls(mod, name.c_str(), "Defines the 2D-vector template. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls.def(py::init<>());
	cls.def(py::init<const Element_t>(), py::arg("theXY"));
	cls.def(py::init<const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"));
	cls.def_static("Length_", (int (*)()) &NCollection_Vec2<Element_t>::Length, "Returns the number of components.");
	cls.def("SetValues", (void (NCollection_Vec2<Element_t>::*)(const Element_t, const Element_t)) &NCollection_Vec2<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"));
	cls.def("x", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::x, "Alias to 1st component as X coordinate in XY.");
	cls.def("y", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::y, "Alias to 2nd component as Y coordinate in XY.");
	cls.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::xy, "None");
	cls.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::yx, "None");
	cls.def("x", (Element_t & (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::x, "Alias to 1st component as X coordinate in XY.");
	cls.def("y", (Element_t & (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::y, "Alias to 2nd component as Y coordinate in XY.");
	cls.def("IsEqual", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls.def("GetData", (const Element_t * (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
	cls.def("ChangeData", (Element_t * (NCollection_Vec2<Element_t>::*)()) &NCollection_Vec2<Element_t>::ChangeData, "None");
	cls.def("__iadd__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls.def("__isub__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls.def("__sub__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::operator-, py::is_operator(), "Unary -.");
	cls.def("__imul__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &)) &NCollection_Vec2<Element_t>::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls.def("Multiply", (void (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("Multiplied", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const ) &NCollection_Vec2<Element_t>::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("cwiseMin", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls.def("cwiseMax", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	// FIXME cls.def("cwiseAbs", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls.def("maxComp", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::maxComp, "Compute maximum component of the vector.");
	cls.def("minComp", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::minComp, "Compute minimum component of the vector.");
	cls.def("__imul__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("__itruediv__", (NCollection_Vec2<Element_t> & (NCollection_Vec2<Element_t>::*)(const Element_t)) &NCollection_Vec2<Element_t>::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls.def("__mul__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const ) &NCollection_Vec2<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("__truediv__", (NCollection_Vec2<Element_t> (NCollection_Vec2<Element_t>::*)(const Element_t) const ) &NCollection_Vec2<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls.def("Dot", (Element_t (NCollection_Vec2<Element_t>::*)(const NCollection_Vec2<Element_t> &) const ) &NCollection_Vec2<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
	cls.def("Modulus", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::Modulus, "Computes the vector modulus (magnitude, length).");
	cls.def("SquareModulus", (Element_t (NCollection_Vec2<Element_t>::*)() const ) &NCollection_Vec2<Element_t>::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls.def_static("DX_", (NCollection_Vec2<Element_t> (*)()) &NCollection_Vec2<Element_t>::DX, "Constuct DX unit vector.");
	cls.def_static("DY_", (NCollection_Vec2<Element_t> (*)()) &NCollection_Vec2<Element_t>::DY, "Constuct DY unit vector.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec3.hxx
template <typename Element_t>
void bind_NCollection_Vec3(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec3.hxx
	py::class_<NCollection_Vec3<Element_t>, std::unique_ptr<NCollection_Vec3<Element_t>, Deleter<NCollection_Vec3<Element_t>>>> cls(mod, name.c_str(), "Generic 3-components vector. To be used as RGB color pixel or XYZ 3D-point. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls.def(py::init<>());
	cls.def(py::init<Element_t>(), py::arg("theValue"));
	cls.def(py::init<const Element_t, const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls.def(py::init<const NCollection_Vec2<Element_t> &>(), py::arg("theVec2"));
	cls.def_static("Length_", (int (*)()) &NCollection_Vec3<Element_t>::Length, "Returns the number of components.");
	cls.def("SetValues", (void (NCollection_Vec3<Element_t>::*)(const Element_t, const Element_t, const Element_t)) &NCollection_Vec3<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls.def("x", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::x, "Alias to 1st component as X coordinate in XYZ.");
	cls.def("r", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::r, "Alias to 1st component as RED channel in RGB.");
	cls.def("y", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls.def("g", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls.def("z", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls.def("b", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::xy, "None");
	cls.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::yx, "None");
	cls.def("xz", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::xz, "None");
	cls.def("zx", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::zx, "None");
	cls.def("yz", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::yz, "None");
	cls.def("zy", (const NCollection_Vec2<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::zy, "None");
	cls.def("xyz", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::xyz, "None");
	cls.def("xzy", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::xzy, "None");
	cls.def("yxz", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::yxz, "None");
	cls.def("yzx", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::yzx, "None");
	cls.def("zyx", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::zyx, "None");
	cls.def("zxy", (const NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::zxy, "None");
	cls.def("x", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::x, "Alias to 1st component as X coordinate in XYZ.");
	cls.def("r", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::r, "Alias to 1st component as RED channel in RGB.");
	cls.def("y", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls.def("g", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls.def("z", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls.def("b", (Element_t & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls.def("xy", (NCollection_Vec2<Element_t> & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::xy, "Returns XY-components modifiable vector");
	cls.def("yz", (NCollection_Vec2<Element_t> & (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::yz, "Returns YZ-components modifiable vector");
	cls.def("IsEqual", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls.def("GetData", (const Element_t * (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
	cls.def("ChangeData", (Element_t * (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::ChangeData, "None");
	cls.def("__iadd__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls.def("__sub__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::operator-, py::is_operator(), "Unary -.");
	cls.def("__isub__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls.def("Multiply", (void (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("__imul__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls.def("__imul__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("__mul__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t) const ) &NCollection_Vec3<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("Multiplied", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t) const ) &NCollection_Vec3<Element_t>::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls.def("cwiseMin", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls.def("cwiseMax", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	// FIXME cls.def("cwiseAbs", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls.def("maxComp", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::maxComp, "Compute maximum component of the vector.");
	cls.def("minComp", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::minComp, "Compute minimum component of the vector.");
	cls.def("__itruediv__", (NCollection_Vec3<Element_t> & (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls.def("__truediv__", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)(const Element_t)) &NCollection_Vec3<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls.def("Dot", (Element_t (NCollection_Vec3<Element_t>::*)(const NCollection_Vec3<Element_t> &) const ) &NCollection_Vec3<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
	cls.def("Modulus", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::Modulus, "Computes the vector modulus (magnitude, length).");
	cls.def("SquareModulus", (Element_t (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls.def("Normalize", (void (NCollection_Vec3<Element_t>::*)()) &NCollection_Vec3<Element_t>::Normalize, "Normalize the vector.");
	cls.def("Normalized", (NCollection_Vec3<Element_t> (NCollection_Vec3<Element_t>::*)() const ) &NCollection_Vec3<Element_t>::Normalized, "Normalize the vector.");
	cls.def_static("Cross_", (NCollection_Vec3<Element_t> (*)(const NCollection_Vec3<Element_t> &, const NCollection_Vec3<Element_t> &)) &NCollection_Vec3<Element_t>::Cross, "Computes the cross product.", py::arg("theVec1"), py::arg("theVec2"));
	cls.def_static("GetLERP_", (NCollection_Vec3<Element_t> (*)(const NCollection_Vec3<Element_t> &, const NCollection_Vec3<Element_t> &, const Element_t)) &NCollection_Vec3<Element_t>::GetLERP, "Compute linear interpolation between to vectors.", py::arg("theFrom"), py::arg("theTo"), py::arg("theT"));
	cls.def_static("DX_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DX, "Constuct DX unit vector.");
	cls.def_static("DY_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DY, "Constuct DY unit vector.");
	cls.def_static("DZ_", (NCollection_Vec3<Element_t> (*)()) &NCollection_Vec3<Element_t>::DZ, "Constuct DZ unit vector.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec4.hxx
template <typename Element_t>
void bind_NCollection_Vec4(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec4.hxx
	py::class_<NCollection_Vec4<Element_t>, std::unique_ptr<NCollection_Vec4<Element_t>, Deleter<NCollection_Vec4<Element_t>>>> cls(mod, name.c_str(), "Generic 4-components vector. To be used as RGBA color vector or XYZW 3D-point with special W-component for operations with projection / model view matrices. Use this class for 3D-points carefully because declared W-component may results in incorrect results if used without matrices.");
	cls.def(py::init<>());
	cls.def(py::init<const Element_t>(), py::arg("theValue"));
	cls.def(py::init<const Element_t, const Element_t, const Element_t, const Element_t>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls.def(py::init<const NCollection_Vec2<Element_t> &>(), py::arg("theVec2"));
	cls.def(py::init<const NCollection_Vec3<Element_t> &>(), py::arg("theVec3"));
	cls.def(py::init<const NCollection_Vec3<Element_t> &, const Element_t>(), py::arg("theVec3"), py::arg("theAlpha"));
	cls.def_static("Length_", (int (*)()) &NCollection_Vec4<Element_t>::Length, "Returns the number of components.");
	cls.def("SetValues", (void (NCollection_Vec4<Element_t>::*)(const Element_t, const Element_t, const Element_t, const Element_t)) &NCollection_Vec4<Element_t>::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls.def("x", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::x, "Alias to 1st component as X coordinate in XYZW.");
	cls.def("r", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::r, "Alias to 1st component as RED channel in RGBA.");
	cls.def("y", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls.def("g", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls.def("z", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls.def("b", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls.def("w", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::w, "Alias to 4th component as W coordinate in XYZW.");
	cls.def("a", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls.def("xy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xy, "None");
	cls.def("yx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yx, "None");
	cls.def("xz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xz, "None");
	cls.def("zx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zx, "None");
	cls.def("xw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xw, "None");
	cls.def("wx", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wx, "None");
	cls.def("yz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yz, "None");
	cls.def("zy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zy, "None");
	cls.def("yw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yw, "None");
	cls.def("wy", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wy, "None");
	cls.def("zw", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zw, "None");
	cls.def("wz", (const NCollection_Vec2<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wz, "None");
	cls.def("xyz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xyz, "None");
	cls.def("xzy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xzy, "None");
	cls.def("yxz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yxz, "None");
	cls.def("yzx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yzx, "None");
	cls.def("zyx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zyx, "None");
	cls.def("zxy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zxy, "None");
	cls.def("xyw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xyw, "None");
	cls.def("xwy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xwy, "None");
	cls.def("yxw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yxw, "None");
	cls.def("ywx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::ywx, "None");
	cls.def("wyx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wyx, "None");
	cls.def("wxy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wxy, "None");
	cls.def("xzw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xzw, "None");
	cls.def("xwz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::xwz, "None");
	cls.def("zxw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zxw, "None");
	cls.def("zwx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zwx, "None");
	cls.def("wzx", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wzx, "None");
	cls.def("wxz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wxz, "None");
	cls.def("yzw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::yzw, "None");
	cls.def("ywz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::ywz, "None");
	cls.def("zyw", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zyw, "None");
	cls.def("zwy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::zwy, "None");
	cls.def("wzy", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wzy, "None");
	cls.def("wyz", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::wyz, "None");
	cls.def("rgb", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::rgb, "None");
	cls.def("rbg", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::rbg, "None");
	cls.def("grb", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::grb, "None");
	cls.def("gbr", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::gbr, "None");
	cls.def("bgr", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::bgr, "None");
	cls.def("brg", (const NCollection_Vec3<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::brg, "None");
	cls.def("x", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::x, "Alias to 1st component as X coordinate in XYZW.");
	cls.def("r", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::r, "Alias to 1st component as RED channel in RGBA.");
	cls.def("y", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls.def("g", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls.def("z", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls.def("b", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls.def("w", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::w, "Alias to 4th component as W coordinate in XYZW.");
	cls.def("a", (Element_t & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls.def("xy", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::xy, "Returns XY-components modifiable vector");
	cls.def("yz", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::yz, "Returns YZ-components modifiable vector");
	cls.def("zw", (NCollection_Vec2<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::zw, "Returns YZ-components modifiable vector");
	cls.def("xyz", (NCollection_Vec3<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::xyz, "Returns XYZ-components modifiable vector");
	cls.def("yzw", (NCollection_Vec3<Element_t> & (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::yzw, "Returns YZW-components modifiable vector");
	cls.def("IsEqual", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls.def("__eq__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls.def("__ne__", (bool (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls.def("GetData", (const Element_t * (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::GetData, "Raw access to the data (for OpenGL exchange).");
	cls.def("ChangeData", (Element_t * (NCollection_Vec4<Element_t>::*)()) &NCollection_Vec4<Element_t>::ChangeData, "None");
	cls.def("__iadd__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls.def("__sub__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::operator-, py::is_operator(), "Unary -.");
	cls.def("__isub__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls.def("__imul__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &)) &NCollection_Vec4<Element_t>::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls.def("Multiply", (void (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls.def("__imul__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator*=, "Compute per-component multiplication.", py::arg("theFactor"));
	cls.def("__mul__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t) const ) &NCollection_Vec4<Element_t>::operator*, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
	cls.def("Multiplied", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t) const ) &NCollection_Vec4<Element_t>::Multiplied, "Compute per-component multiplication.", py::arg("theFactor"));
	cls.def("cwiseMin", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls.def("cwiseMax", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	// FIXME cls.def("cwiseAbs", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls.def("maxComp", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::maxComp, "Compute maximum component of the vector.");
	cls.def("minComp", (Element_t (NCollection_Vec4<Element_t>::*)() const ) &NCollection_Vec4<Element_t>::minComp, "Compute minimum component of the vector.");
	cls.def("Dot", (Element_t (NCollection_Vec4<Element_t>::*)(const NCollection_Vec4<Element_t> &) const ) &NCollection_Vec4<Element_t>::Dot, "Computes the dot product.", py::arg("theOther"));
	cls.def("__itruediv__", (NCollection_Vec4<Element_t> & (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls.def("__truediv__", (NCollection_Vec4<Element_t> (NCollection_Vec4<Element_t>::*)(const Element_t)) &NCollection_Vec4<Element_t>::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vector.hxx
template <typename TheItemType>
void bind_NCollection_Vector(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vector.hxx
	py::class_<NCollection_Vector<TheItemType>, std::unique_ptr<NCollection_Vector<TheItemType>, Deleter<NCollection_Vector<TheItemType>>>, NCollection_BaseVector> cls(mod, name.c_str(), "Class NCollection_Vector (dynamic array of objects)");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls.def(py::init([] (const NCollection_Vector<TheItemType> &other) {return new NCollection_Vector<TheItemType>(other);}), "Copy constructor", py::arg("other"));
	cls.def("begin", (typename NCollection_Vector<TheItemType>::iterator (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::begin, "Returns an iterator pointing to the first element in the vector.");
	cls.def("end", (typename NCollection_Vector<TheItemType>::iterator (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the vector.");
	cls.def("cbegin", (typename NCollection_Vector<TheItemType>::const_iterator (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the vector.");
	cls.def("cend", (typename NCollection_Vector<TheItemType>::const_iterator (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the vector.");
	cls.def("Length", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::Length, "Total number of items");
	cls.def("Size", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::Size, "Total number of items in the vector");
	cls.def("Lower", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::Lower, "Method for consistency with other collections.");
	cls.def("Upper", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::Upper, "Method for consistency with other collections.");
	cls.def("IsEmpty", (Standard_Boolean (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::IsEmpty, "Empty query");
	cls.def("Assign", [](NCollection_Vector<TheItemType> &self, const NCollection_Vector<TheItemType> & a0) -> void { return self.Assign(a0); }, py::arg("theOther"));
	cls.def("Assign", (void (NCollection_Vector<TheItemType>::*)(const NCollection_Vector<TheItemType> &, const Standard_Boolean)) &NCollection_Vector<TheItemType>::Assign, "Assignment to the collection of the same type", py::arg("theOther"), py::arg("theOwnAllocator"));
	cls.def("assign", (NCollection_Vector<TheItemType> & (NCollection_Vector<TheItemType>::*)(const NCollection_Vector<TheItemType> &)) &NCollection_Vector<TheItemType>::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls.def("Append", (TheItemType & (NCollection_Vector<TheItemType>::*)(const TheItemType &)) &NCollection_Vector<TheItemType>::Append, "Append", py::arg("theValue"));
	cls.def("__call__", (const TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Vector<TheItemType>::operator(), py::is_operator(), "Operator() - query the const value", py::arg("theIndex"));
	cls.def("Value", (const TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer) const ) &NCollection_Vector<TheItemType>::Value, "None", py::arg("theIndex"));
	cls.def("First", (const TheItemType & (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::First, "Returns first element");
	cls.def("ChangeFirst", (TheItemType & (NCollection_Vector<TheItemType>::*)()) &NCollection_Vector<TheItemType>::ChangeFirst, "Returns first element");
	cls.def("Last", (const TheItemType & (NCollection_Vector<TheItemType>::*)() const ) &NCollection_Vector<TheItemType>::Last, "Returns last element");
	cls.def("ChangeLast", (TheItemType & (NCollection_Vector<TheItemType>::*)()) &NCollection_Vector<TheItemType>::ChangeLast, "Returns last element");
	cls.def("__call__", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer)) &NCollection_Vector<TheItemType>::operator(), py::is_operator(), "Operator() - query the value", py::arg("theIndex"));
	cls.def("ChangeValue", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer)) &NCollection_Vector<TheItemType>::ChangeValue, "None", py::arg("theIndex"));
	cls.def("SetValue", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Vector<TheItemType>::SetValue, "SetValue () - set or append a value", py::arg("theIndex"), py::arg("theValue"));
	cls.def("__iter__", [](const NCollection_Vector<TheItemType> &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

};

#endif
