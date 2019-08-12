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
#ifndef __BVH_Set__
#define __BVH_Set__

#include <pyOCCT_Common.hxx>
#include <BVH_Box.hxx>
#include <BVH_Set.hxx>
#include <Standard_TypeDef.hxx>

template <typename T, int N>
void bind_BVH_Set(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Set<T, N>, std::unique_ptr<BVH_Set<T, N>, Deleter<BVH_Set<T, N>>>> cls_BVH_Set(mod, name.c_str(), "Set of abstract entities (bounded by BVH boxes). This is the minimal geometry interface needed to construct BVH.", local);

// Constructors
cls_BVH_Set.def(py::init<>());

// Fields

// Methods
cls_BVH_Set.def("Box", (BVH_Box<T, N> (BVH_Set<T, N>::*)() const) &BVH_Set<T, N>::Box, "Returns AABB of the entire set of objects.");
cls_BVH_Set.def("Size", (Standard_Integer (BVH_Set<T, N>::*)() const) &BVH_Set<T, N>::Size, "Returns total number of objects.");
cls_BVH_Set.def("Box", (BVH_Box<T, N> (BVH_Set<T, N>::*)(const Standard_Integer) const) &BVH_Set<T, N>::Box, "Returns AABB of the given object.", py::arg("theIndex"));
cls_BVH_Set.def("Center", (T (BVH_Set<T, N>::*)(const Standard_Integer, const Standard_Integer) const) &BVH_Set<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
cls_BVH_Set.def("Swap", (void (BVH_Set<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_Set<T, N>::Swap, "Performs transposing the two given objects in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

// Enums

}

#endif