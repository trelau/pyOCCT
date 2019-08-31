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
#ifndef __BVH_Bin__
#define __BVH_Bin__

#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>
#include <BVH_BinnedBuilder.hxx>

template <typename T, int N>
void bind_BVH_Bin(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Bin<T, N>> cls_BVH_Bin(mod, name.c_str(), "Stores parameters of single bin (slice of AABB).", local);

// Constructors
cls_BVH_Bin.def(py::init<>());

// Fields
cls_BVH_Bin.def_readwrite("Count", &BVH_Bin<T, N>::Count, "Number of primitives in the bin");
cls_BVH_Bin.def_readwrite("Box", &BVH_Bin<T, N>::Box, "AABB of primitives in the bin");

}

#endif