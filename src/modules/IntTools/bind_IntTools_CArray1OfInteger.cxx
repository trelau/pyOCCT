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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_CArray1OfInteger.hxx>

void bind_IntTools_CArray1OfInteger(py::module &mod){

py::class_<IntTools_CArray1OfInteger> cls_IntTools_CArray1OfInteger(mod, "IntTools_CArray1OfInteger", "None");

// Constructors
cls_IntTools_CArray1OfInteger.def(py::init<>());
cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer>(), py::arg("Length"));
cls_IntTools_CArray1OfInteger.def(py::init<const Standard_Integer &, const Standard_Integer>(), py::arg("Item"), py::arg("Length"));

// Fields

// Methods
// cls_IntTools_CArray1OfInteger.def_static("operator new_", (void * (*)(size_t)) &IntTools_CArray1OfInteger::operator new, "None", py::arg("theSize"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete_", (void (*)(void *)) &IntTools_CArray1OfInteger::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CArray1OfInteger::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CArray1OfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CArray1OfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CArray1OfInteger.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CArray1OfInteger::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CArray1OfInteger.def("Init", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Init, "Initializes the array with a given value.", py::arg("V"));
cls_IntTools_CArray1OfInteger.def("Resize", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::Resize, "destroy current content and realloc the new size does nothing if Length() == theLength", py::arg("theNewLength"));
cls_IntTools_CArray1OfInteger.def("Destroy", (void (IntTools_CArray1OfInteger::*)()) &IntTools_CArray1OfInteger::Destroy, "Frees the allocated area corresponding to the array.");
cls_IntTools_CArray1OfInteger.def("Length", (Standard_Integer (IntTools_CArray1OfInteger::*)() const) &IntTools_CArray1OfInteger::Length, "Returns the number of elements of <me>.");
cls_IntTools_CArray1OfInteger.def("Append", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer &)) &IntTools_CArray1OfInteger::Append, "None", py::arg("Value"));
cls_IntTools_CArray1OfInteger.def("SetValue", (void (IntTools_CArray1OfInteger::*)(const Standard_Integer, const Standard_Integer &)) &IntTools_CArray1OfInteger::SetValue, "Sets the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
cls_IntTools_CArray1OfInteger.def("Value", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const) &IntTools_CArray1OfInteger::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("__call__", (const Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer) const) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("ChangeValue", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::ChangeValue, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("__call__", (Standard_Integer & (IntTools_CArray1OfInteger::*)(const Standard_Integer)) &IntTools_CArray1OfInteger::operator(), py::is_operator(), "None", py::arg("Index"));
cls_IntTools_CArray1OfInteger.def("IsEqual", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const) &IntTools_CArray1OfInteger::IsEqual, "Applys the == operator on each array item", py::arg("Other"));
cls_IntTools_CArray1OfInteger.def("__eq__", (Standard_Boolean (IntTools_CArray1OfInteger::*)(const IntTools_CArray1OfInteger &) const) &IntTools_CArray1OfInteger::operator==, py::is_operator(), "None", py::arg("Other"));

// Enums

}