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
#pragma once

#include <pyOCCT_Common.hxx>
#include <BVH_Builder.hxx>
#include <BVH_LinearBuilder.hxx>
#include <BVH_Types.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <BVH_Box.hxx>
#include <NCollection_Array1.hxx>
#include <BVH_RadixSorter.hxx>

template <typename T, int N>
void bind_BVH_LinearBuilder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_LinearBuilder<T, N>, opencascade::handle<BVH_LinearBuilder<T, N>>, BVH_Builder<T, N>> cls_BVH_LinearBuilder(mod, name.c_str(), "Performs fast BVH construction using LBVH building approach. Algorithm uses spatial Morton codes to reduce the BVH construction problem to a sorting problem (radix sort -- O(N) complexity). This Linear Bounding Volume Hierarchy (LBVH) builder produces BVH trees of lower quality compared to SAH-based BVH builders but it is over an order of magnitude faster (up to 3M triangles per second).", local);

// Constructors
cls_BVH_LinearBuilder.def(py::init<>());
cls_BVH_LinearBuilder.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
cls_BVH_LinearBuilder.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));

// Methods
cls_BVH_LinearBuilder.def("Build", (void (BVH_LinearBuilder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const) &BVH_LinearBuilder<T, N>::Build, "Builds BVH.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

}
