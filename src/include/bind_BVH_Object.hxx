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
#ifndef __BVH_Object__
#define __BVH_Object__

#include <pyOCCT_Common.hxx>
#include <BVH_Object.hxx>
#include <BVH_Box.hxx>

template <typename T, int N>
void bind_BVH_Object(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Object<T, N>, opencascade::handle<BVH_Object<T, N>>, BVH_ObjectTransient> cls_BVH_Object(mod, name.c_str(), "Abstract geometric object bounded by BVH box.", local);

// Constructors
// cls_BVH_Object.def(py::init<>());

// Fields

// Methods
cls_BVH_Object.def("Box", (BVH_Box<T, N> (BVH_Object<T, N>::*)() const) &BVH_Object<T, N>::Box, "Returns AABB of the geometric object.");

// Enums

}

#endif