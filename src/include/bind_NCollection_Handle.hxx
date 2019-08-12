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
#ifndef __NCollection_Handle__
#define __NCollection_Handle__

#include <pyOCCT_Common.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_Handle.hxx>

template <typename T>
void bind_NCollection_Handle(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Handle<T>, std::unique_ptr<NCollection_Handle<T>, Deleter<NCollection_Handle<T>>>> cls_NCollection_Handle(mod, name.c_str(), "Purpose: This template class is used to define Handle adaptor for allocated dynamically objects of arbitrary type.", local);

// Constructors
cls_NCollection_Handle.def(py::init<>());
cls_NCollection_Handle.def(py::init<T *>(), py::arg("theObject"));

// Fields

// Methods
cls_NCollection_Handle.def("get", (T * (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::get, "Cast handle to contained type");
cls_NCollection_Handle.def("get", (const T * (NCollection_Handle<T>::*)() const) &NCollection_Handle<T>::get, "Cast handle to contained type");
// cls_NCollection_Handle.def("operator->", (T * (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::operator->, "Cast handle to contained type");
// cls_NCollection_Handle.def("operator->", (const T * (NCollection_Handle<T>::*)() const) &NCollection_Handle<T>::operator->, "Cast handle to contained type");
cls_NCollection_Handle.def("__mul__", (T & (NCollection_Handle<T>::*)()) &NCollection_Handle<T>::operator*, py::is_operator(), "Cast handle to contained type");
cls_NCollection_Handle.def("__mul__", (const T & (NCollection_Handle<T>::*)() const) &NCollection_Handle<T>::operator*, py::is_operator(), "Cast handle to contained type");
cls_NCollection_Handle.def_static("DownCast_", (NCollection_Handle<T> (*)(const opencascade::handle<Standard_Transient> &)) &NCollection_Handle<T>::DownCast, "Downcast arbitrary Handle to the argument type if contained object is Handle for this type; returns null otherwise", py::arg("theOther"));

// Enums

}

#endif