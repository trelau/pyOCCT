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
#ifndef __NCollection_SparseArray__
#define __NCollection_SparseArray__

#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_SparseArray.hxx>
#include <Standard_TypeDef.hxx>

template <typename TheItemType>
void bind_NCollection_SparseArray(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_SparseArray<TheItemType>, NCollection_SparseArrayBase> cls_NCollection_SparseArray(mod, name.c_str(), "Dynamically resizable sparse array of objects", local);

// Constructors
cls_NCollection_SparseArray.def(py::init<Standard_Size>(), py::arg("theIncrement"));

// Methods
cls_NCollection_SparseArray.def("Assign", (NCollection_SparseArray<TheItemType> & (NCollection_SparseArray<TheItemType>::*)(const NCollection_SparseArray<TheItemType> &)) &NCollection_SparseArray<TheItemType>::Assign, "Explicit assignment operator", py::arg("theOther"));
cls_NCollection_SparseArray.def("Exchange", (void (NCollection_SparseArray<TheItemType>::*)(NCollection_SparseArray<TheItemType> &)) &NCollection_SparseArray<TheItemType>::Exchange, "Exchange the data of two arrays; can be used primarily to move contents of theOther into the new array in a fast way (without creation of duplicated data)", py::arg("theOther"));
cls_NCollection_SparseArray.def("Value", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const) &NCollection_SparseArray<TheItemType>::Value, "Direct const access to the item", py::arg("theIndex"));
cls_NCollection_SparseArray.def("__call__", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const) &NCollection_SparseArray<TheItemType>::operator(), py::is_operator(), "Const access to the item - operator()", py::arg("theIndex"));
cls_NCollection_SparseArray.def("ChangeValue", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::ChangeValue, "Modification access to the item", py::arg("theIndex"));
cls_NCollection_SparseArray.def("__call__", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::operator(), py::is_operator(), "Access to the item - operator()", py::arg("theIndex"));
cls_NCollection_SparseArray.def("SetValue", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size, const TheItemType &)) &NCollection_SparseArray<TheItemType>::SetValue, "Set a value at specified index method", py::arg("theIndex"), py::arg("theValue"));
cls_NCollection_SparseArray.def("Extent", (Standard_Size (NCollection_SparseArray<TheItemType>::*)() const) &NCollection_SparseArray<TheItemType>::Extent, "Returns number of items in the array");
cls_NCollection_SparseArray.def("IsEmpty", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)() const) &NCollection_SparseArray<TheItemType>::IsEmpty, "Returns True if array is empty");
cls_NCollection_SparseArray.def("Find", (const TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const) &NCollection_SparseArray<TheItemType>::Find, "Direct const access to the item", py::arg("theIndex"));
cls_NCollection_SparseArray.def("ChangeFind", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::ChangeFind, "Modification access to the item", py::arg("theIndex"));
cls_NCollection_SparseArray.def("Bind", (TheItemType & (NCollection_SparseArray<TheItemType>::*)(const Standard_Size, const TheItemType &)) &NCollection_SparseArray<TheItemType>::Bind, "Set a value as explicit method", py::arg("theIndex"), py::arg("theValue"));
cls_NCollection_SparseArray.def("IsBound", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)(const Standard_Size) const) &NCollection_SparseArray<TheItemType>::IsBound, "Returns True if the item is defined", py::arg("theIndex"));
cls_NCollection_SparseArray.def("UnBind", (Standard_Boolean (NCollection_SparseArray<TheItemType>::*)(const Standard_Size)) &NCollection_SparseArray<TheItemType>::UnBind, "Remove the item from array", py::arg("theIndex"));

}

#endif