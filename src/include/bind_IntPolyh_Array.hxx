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
#ifndef __IntPolyh_Array__
#define __IntPolyh_Array__

#include <pyOCCT_Common.hxx>
#include <NCollection_Vector.hxx>
#include <IntPolyh_Array.hxx>
#include <Standard_TypeDef.hxx>

template <typename Type>
void bind_IntPolyh_Array(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<IntPolyh_Array<Type>, std::unique_ptr<IntPolyh_Array<Type>>> cls_IntPolyh_Array(mod, name.c_str(), "Class IntPolyh_Array (dynamic array of objects)", local);

// Constructors
// cls_IntPolyh_Array.def(py::init<>());
// cls_IntPolyh_Array.def(py::init<const Standard_Integer>(), py::arg("aIncrement"));
// cls_IntPolyh_Array.def(py::init<const Standard_Integer>(), py::arg("aN"));
// cls_IntPolyh_Array.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("aN"), py::arg("aIncrement"));

// Fields

// Methods
// cls_IntPolyh_Array.def("operator=", (IntPolyh_Array<Type> & (IntPolyh_Array<Type>::*)(const IntPolyh_Array<Type> &)) &IntPolyh_Array<Type>::operator=, "Assignment operator", py::arg("aOther"));
cls_IntPolyh_Array.def("Copy", (IntPolyh_Array<Type> & (IntPolyh_Array<Type>::*)(const IntPolyh_Array<Type> &)) &IntPolyh_Array<Type>::Copy, "Copy", py::arg("aOther"));
cls_IntPolyh_Array.def("Init", (void (IntPolyh_Array<Type>::*)(const Standard_Integer)) &IntPolyh_Array<Type>::Init, "Init - allocate memory for <aN> items", py::arg("aN"));
cls_IntPolyh_Array.def("IncrementNbItems", (void (IntPolyh_Array<Type>::*)()) &IntPolyh_Array<Type>::IncrementNbItems, "IncrementNbItems - increment the number of stored items");
cls_IntPolyh_Array.def("GetN", (Standard_Integer (IntPolyh_Array<Type>::*)() const) &IntPolyh_Array<Type>::GetN, "GetN - returns the number of 'allocated' items");
cls_IntPolyh_Array.def("NbItems", (Standard_Integer (IntPolyh_Array<Type>::*)() const) &IntPolyh_Array<Type>::NbItems, "NbItems - returns the number of stored items");
cls_IntPolyh_Array.def("SetNbItems", (void (IntPolyh_Array<Type>::*)(const Standard_Integer)) &IntPolyh_Array<Type>::SetNbItems, "set the number of stored items", py::arg("aNb"));
cls_IntPolyh_Array.def("Value", (const Type & (IntPolyh_Array<Type>::*)(const Standard_Integer) const) &IntPolyh_Array<Type>::Value, "query the const value", py::arg("aIndex"));
cls_IntPolyh_Array.def("__getitem__", (const Type & (IntPolyh_Array<Type>::*)(const Standard_Integer) const) &IntPolyh_Array<Type>::operator[], py::is_operator(), "query the const value", py::arg("aIndex"));
cls_IntPolyh_Array.def("ChangeValue", (Type & (IntPolyh_Array<Type>::*)(const Standard_Integer)) &IntPolyh_Array<Type>::ChangeValue, "query the value", py::arg("aIndex"));
cls_IntPolyh_Array.def("__getitem__", (Type & (IntPolyh_Array<Type>::*)(const Standard_Integer)) &IntPolyh_Array<Type>::operator[], py::is_operator(), "query the value", py::arg("aIndex"));
// cls_IntPolyh_Array.def("Dump", (void (IntPolyh_Array<Type>::*)() const) &IntPolyh_Array<Type>::Dump, "dump the contents");

// Enums

}

#endif