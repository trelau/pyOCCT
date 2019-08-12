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
#ifndef __BVH_Builder__
#define __BVH_Builder__

#include <pyOCCT_Common.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>

template <typename T, int N>
void bind_BVH_Builder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Builder<T, N>, opencascade::handle<BVH_Builder<T, N>>, BVH_BuilderTransient> cls_BVH_Builder(mod, name.c_str(), "Performs construction of BVH tree using bounding boxes (AABBs) of abstract objects.", local);

// Constructors

// Fields

// Methods
cls_BVH_Builder.def("Build", (void (BVH_Builder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const) &BVH_Builder<T, N>::Build, "Builds BVH using specific algorithm.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

// Enums

}

#endif