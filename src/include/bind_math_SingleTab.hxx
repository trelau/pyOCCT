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
#ifndef __math_SingleTab__
#define __math_SingleTab__

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <math_SingleTab.hxx>

template <typename T>
void bind_math_SingleTab(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<math_SingleTab<T>, std::unique_ptr<math_SingleTab<T>>> cls_math_SingleTab(mod, name.c_str(), "None", local);

// Constructors
cls_math_SingleTab.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("LowerIndex"), py::arg("UpperIndex"));
cls_math_SingleTab.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerIndex"), py::arg("UpperIndex"));
cls_math_SingleTab.def(py::init<const math_SingleTab<T> &>(), py::arg("Other"));

// Fields

// Methods
// cls_math_SingleTab.def_static("operator new_", (void * (*)(size_t)) &math_SingleTab<T>::operator new, "None", py::arg("theSize"));
// cls_math_SingleTab.def_static("operator delete_", (void (*)(void *)) &math_SingleTab<T>::operator delete, "None", py::arg("theAddress"));
// cls_math_SingleTab.def_static("operator new[]_", (void * (*)(size_t)) &math_SingleTab<T>::operator new[], "None", py::arg("theSize"));
// cls_math_SingleTab.def_static("operator delete[]_", (void (*)(void *)) &math_SingleTab<T>::operator delete[], "None", py::arg("theAddress"));
// cls_math_SingleTab.def_static("operator new_", (void * (*)(size_t, void *)) &math_SingleTab<T>::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_SingleTab.def_static("operator delete_", (void (*)(void *, void *)) &math_SingleTab<T>::operator delete, "None", py::arg(""), py::arg(""));
cls_math_SingleTab.def("Init", (void (math_SingleTab<T>::*)(const T)) &math_SingleTab<T>::Init, "None", py::arg("InitValue"));
cls_math_SingleTab.def("Copy", (void (math_SingleTab<T>::*)(math_SingleTab<T> &) const) &math_SingleTab<T>::Copy, "None", py::arg("Other"));
cls_math_SingleTab.def("SetLower", (void (math_SingleTab<T>::*)(const Standard_Integer)) &math_SingleTab<T>::SetLower, "None", py::arg("LowerIndex"));
cls_math_SingleTab.def("Value", (T & (math_SingleTab<T>::*)(const Standard_Integer) const) &math_SingleTab<T>::Value, "None", py::arg("Index"));
cls_math_SingleTab.def("__call__", (T & (math_SingleTab<T>::*)(const Standard_Integer) const) &math_SingleTab<T>::operator(), py::is_operator(), "None", py::arg("Index"));
cls_math_SingleTab.def("Free", (void (math_SingleTab<T>::*)()) &math_SingleTab<T>::Free, "None");

// Enums

}

#endif