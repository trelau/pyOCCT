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
#include <MAT2d_BiInt.hxx>

void bind_MAT2d_BiInt(py::module &mod){

py::class_<MAT2d_BiInt> cls_MAT2d_BiInt(mod, "MAT2d_BiInt", "BiInt is a set of two integers.");

// Constructors
cls_MAT2d_BiInt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("I1"), py::arg("I2"));

// Fields

// Methods
// cls_MAT2d_BiInt.def_static("operator new_", (void * (*)(size_t)) &MAT2d_BiInt::operator new, "None", py::arg("theSize"));
// cls_MAT2d_BiInt.def_static("operator delete_", (void (*)(void *)) &MAT2d_BiInt::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_BiInt::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_BiInt.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_BiInt::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_BiInt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_BiInt.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_BiInt::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_BiInt.def("FirstIndex", (Standard_Integer (MAT2d_BiInt::*)() const) &MAT2d_BiInt::FirstIndex, "None");
cls_MAT2d_BiInt.def("SecondIndex", (Standard_Integer (MAT2d_BiInt::*)() const) &MAT2d_BiInt::SecondIndex, "None");
cls_MAT2d_BiInt.def("FirstIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::FirstIndex, "None", py::arg("I1"));
cls_MAT2d_BiInt.def("SecondIndex", (void (MAT2d_BiInt::*)(const Standard_Integer)) &MAT2d_BiInt::SecondIndex, "None", py::arg("I2"));
cls_MAT2d_BiInt.def("IsEqual", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const) &MAT2d_BiInt::IsEqual, "None", py::arg("B"));
cls_MAT2d_BiInt.def("__eq__", (Standard_Boolean (MAT2d_BiInt::*)(const MAT2d_BiInt &) const) &MAT2d_BiInt::operator==, py::is_operator(), "None", py::arg("B"));

// Enums

}