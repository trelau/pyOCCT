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
#ifndef __NCollection_Vector__
#define __NCollection_Vector__

#include <pyOCCT_Common.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_StlIterator.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

template <typename TheItemType>
void bind_NCollection_Vector(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Vector<TheItemType>, std::unique_ptr<NCollection_Vector<TheItemType>, Deleter<NCollection_Vector<TheItemType>>>, NCollection_BaseVector> cls_NCollection_Vector(mod, name.c_str(), "Class NCollection_Vector (dynamic array of objects)", local);

// Constructors
cls_NCollection_Vector.def(py::init<>());
cls_NCollection_Vector.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
cls_NCollection_Vector.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
cls_NCollection_Vector.def(py::init<const NCollection_Vector<TheItemType> &>(), py::arg("theOther"));

// Fields

// Methods
cls_NCollection_Vector.def("begin", (NCollection_Vector<TheItemType>::iterator (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::begin, "Returns an iterator pointing to the first element in the vector.");
cls_NCollection_Vector.def("end", (NCollection_Vector<TheItemType>::iterator (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::end, "Returns an iterator referring to the past-the-end element in the vector.");
cls_NCollection_Vector.def("cbegin", (NCollection_Vector<TheItemType>::const_iterator (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::cbegin, "Returns a const iterator pointing to the first element in the vector.");
cls_NCollection_Vector.def("cend", (NCollection_Vector<TheItemType>::const_iterator (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::cend, "Returns a const iterator referring to the past-the-end element in the vector.");
cls_NCollection_Vector.def("Length", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::Length, "Total number of items");
cls_NCollection_Vector.def("Size", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::Size, "Total number of items in the vector");
cls_NCollection_Vector.def("Lower", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::Lower, "Method for consistency with other collections.");
cls_NCollection_Vector.def("Upper", (Standard_Integer (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::Upper, "Method for consistency with other collections.");
cls_NCollection_Vector.def("IsEmpty", (Standard_Boolean (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::IsEmpty, "Empty query");
cls_NCollection_Vector.def("Assign", [](NCollection_Vector<TheItemType> &self, const NCollection_Vector<TheItemType> & a0) -> void { return self.Assign(a0); });
cls_NCollection_Vector.def("Assign", (void (NCollection_Vector<TheItemType>::*)(const NCollection_Vector<TheItemType> &, const Standard_Boolean)) &NCollection_Vector<TheItemType>::Assign, "Assignment to the collection of the same type", py::arg("theOther"), py::arg("theOwnAllocator"));
// cls_NCollection_Vector.def("operator=", (NCollection_Vector<TheItemType> & (NCollection_Vector<TheItemType>::*)(const NCollection_Vector<TheItemType> &)) &NCollection_Vector<TheItemType>::operator=, "Assignment operator", py::arg("theOther"));
cls_NCollection_Vector.def("Append", (TheItemType & (NCollection_Vector<TheItemType>::*)(const TheItemType &)) &NCollection_Vector<TheItemType>::Append, "Append", py::arg("theValue"));
cls_NCollection_Vector.def("Appended", (TheItemType & (NCollection_Vector<TheItemType>::*)()) &NCollection_Vector<TheItemType>::Appended, "Appends an empty value and returns the reference to it");
cls_NCollection_Vector.def("__call__", (const TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer) const) &NCollection_Vector<TheItemType>::operator(), py::is_operator(), "Operator() - query the const value", py::arg("theIndex"));
cls_NCollection_Vector.def("Value", (const TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer) const) &NCollection_Vector<TheItemType>::Value, "None", py::arg("theIndex"));
cls_NCollection_Vector.def("First", (const TheItemType & (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::First, "Returns first element");
cls_NCollection_Vector.def("ChangeFirst", (TheItemType & (NCollection_Vector<TheItemType>::*)()) &NCollection_Vector<TheItemType>::ChangeFirst, "Returns first element");
cls_NCollection_Vector.def("Last", (const TheItemType & (NCollection_Vector<TheItemType>::*)() const) &NCollection_Vector<TheItemType>::Last, "Returns last element");
cls_NCollection_Vector.def("ChangeLast", (TheItemType & (NCollection_Vector<TheItemType>::*)()) &NCollection_Vector<TheItemType>::ChangeLast, "Returns last element");
cls_NCollection_Vector.def("__call__", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer)) &NCollection_Vector<TheItemType>::operator(), py::is_operator(), "Operator() - query the value", py::arg("theIndex"));
cls_NCollection_Vector.def("ChangeValue", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer)) &NCollection_Vector<TheItemType>::ChangeValue, "None", py::arg("theIndex"));
cls_NCollection_Vector.def("SetValue", (TheItemType & (NCollection_Vector<TheItemType>::*)(const Standard_Integer, const TheItemType &)) &NCollection_Vector<TheItemType>::SetValue, "SetValue () - set or append a value", py::arg("theIndex"), py::arg("theValue"));
cls_NCollection_Vector.def("__iter__", [](const NCollection_Vector<TheItemType> &self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

// Enums

}

#endif