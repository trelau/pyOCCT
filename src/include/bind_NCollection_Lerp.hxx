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
#ifndef __NCollection_Lerp__
#define __NCollection_Lerp__

#include <pyOCCT_Common.hxx>
#include <NCollection_Lerp.hxx>

template <typename T>
void bind_NCollection_Lerp(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_Lerp<T>, std::unique_ptr<NCollection_Lerp<T>, Deleter<NCollection_Lerp<T>>>> cls_NCollection_Lerp(mod, name.c_str(), "Simple linear interpolation tool (also known as mix() in GLSL). The main purpose of this template class is making interpolation routines more readable.", local);

// Constructors
cls_NCollection_Lerp.def(py::init<>());
cls_NCollection_Lerp.def(py::init<const T &, const T &>(), py::arg("theStart"), py::arg("theEnd"));

// Fields

// Methods
cls_NCollection_Lerp.def_static("Interpolate_", (T (*)(const T &, const T &, double)) &NCollection_Lerp<T>::Interpolate, "Compute interpolated value between two values.", py::arg("theStart"), py::arg("theEnd"), py::arg("theT"));
cls_NCollection_Lerp.def("Init", (void (NCollection_Lerp<T>::*)(const T &, const T &)) &NCollection_Lerp<T>::Init, "Initialize values.", py::arg("theStart"), py::arg("theEnd"));
cls_NCollection_Lerp.def("Interpolate", (void (NCollection_Lerp<T>::*)(double, T &) const) &NCollection_Lerp<T>::Interpolate, "Compute interpolated value between two values.", py::arg("theT"), py::arg("theResult"));

// Enums

}

#endif