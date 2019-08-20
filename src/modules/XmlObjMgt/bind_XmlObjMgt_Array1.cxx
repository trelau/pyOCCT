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
#include <XmlObjMgt_Element.hxx>
#include <XmlObjMgt_DOMString.hxx>
#include <XmlObjMgt_Array1.hxx>

void bind_XmlObjMgt_Array1(py::module &mod){

py::class_<XmlObjMgt_Array1, std::unique_ptr<XmlObjMgt_Array1>> cls_XmlObjMgt_Array1(mod, "XmlObjMgt_Array1", "The class Array1 represents unidimensionnal array of fixed size known at run time. The range of the index is user defined. Warning: Programs clients of such class must be independant of the range of the first element. Then, a C++ for loop must be written like this for (i = A->Lower(); i <= A->Upper(); i++)");

// Constructors
cls_XmlObjMgt_Array1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Low"), py::arg("Up"));
cls_XmlObjMgt_Array1.def(py::init<const XmlObjMgt_Element &, const XmlObjMgt_DOMString &>(), py::arg("theParent"), py::arg("theName"));

// Fields

// Methods
// cls_XmlObjMgt_Array1.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt_Array1::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt_Array1.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt_Array1::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt_Array1::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt_Array1.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt_Array1::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt_Array1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt_Array1.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt_Array1::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt_Array1.def("CreateArrayElement", (void (XmlObjMgt_Array1::*)(XmlObjMgt_Element &, const XmlObjMgt_DOMString &)) &XmlObjMgt_Array1::CreateArrayElement, "Create DOM_Element representing the array, under 'theParent'", py::arg("theParent"), py::arg("theName"));
cls_XmlObjMgt_Array1.def("Element", (const XmlObjMgt_Element & (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Element, "Returns the DOM element of <me>.");
cls_XmlObjMgt_Array1.def("Length", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Length, "Returns the number of elements of <me>.");
cls_XmlObjMgt_Array1.def("Lower", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Lower, "Returns the lower bound.");
cls_XmlObjMgt_Array1.def("Upper", (Standard_Integer (XmlObjMgt_Array1::*)() const) &XmlObjMgt_Array1::Upper, "Returns the upper bound.");
cls_XmlObjMgt_Array1.def("SetValue", (void (XmlObjMgt_Array1::*)(const Standard_Integer, XmlObjMgt_Element &)) &XmlObjMgt_Array1::SetValue, "Set the <Index>th element of the array to <Value>.", py::arg("Index"), py::arg("Value"));
cls_XmlObjMgt_Array1.def("Value", (XmlObjMgt_Element (XmlObjMgt_Array1::*)(const Standard_Integer) const) &XmlObjMgt_Array1::Value, "Returns the value of <Index>th element of the array.", py::arg("Index"));

// Enums

}