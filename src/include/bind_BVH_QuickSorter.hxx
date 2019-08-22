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
#ifndef __BVH_QuickSorter__
#define __BVH_QuickSorter__

#include <pyOCCT_Common.hxx>
#include <BVH_Sorter.hxx>
#include <BVH_QuickSorter.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Set.hxx>

template <typename T, int N>
void bind_BVH_QuickSorter(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_QuickSorter<T, N>, BVH_Sorter<T, N>> cls_BVH_QuickSorter(mod, name.c_str(), "Performs centroid-based sorting of abstract set along the given axis (X - 0, Y - 1, Z - 2) using quick sort.", local);

// Constructors
cls_BVH_QuickSorter.def(py::init<>());
cls_BVH_QuickSorter.def(py::init<const Standard_Integer>(), py::arg("theAxis"));

// Fields

// Methods
cls_BVH_QuickSorter.def("Perform", (void (BVH_QuickSorter<T, N>::*)(BVH_Set<T, N> *)) &BVH_QuickSorter<T, N>::Perform, "Sorts the set.", py::arg("theSet"));
cls_BVH_QuickSorter.def("Perform", (void (BVH_QuickSorter<T, N>::*)(BVH_Set<T, N> *, const Standard_Integer, const Standard_Integer)) &BVH_QuickSorter<T, N>::Perform, "Sorts the given (inclusive) range in the set.", py::arg("theSet"), py::arg("theStart"), py::arg("theFinal"));

// Enums

}

#endif