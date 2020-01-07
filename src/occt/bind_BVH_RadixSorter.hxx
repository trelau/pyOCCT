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
#ifndef __BVH_RadixSorter__
#define __BVH_RadixSorter__

#include <BVH_Sorter.hxx>
#include <BVH_RadixSorter.hxx>
#include <BVH_Types.hxx>
#include <BVH_Box.hxx>
#include <BVH_Set.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>

template <typename T, int N>
void bind_BVH_RadixSorter(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_RadixSorter<T, N>, BVH_Sorter<T, N>> cls_BVH_RadixSorter(mod, name.c_str(), "Performs radix sort of a BVH primitive set using 10-bit Morton codes (or 1024 x 1024 x 1024 grid).", local);

// Constructors
cls_BVH_RadixSorter.def(py::init<const BVH_Box<T, N> &>(), py::arg("theBox"));

// Methods
cls_BVH_RadixSorter.def("Perform", (void (BVH_RadixSorter<T, N>::*)(BVH_Set<T, N> *)) &BVH_RadixSorter<T, N>::Perform, "Sorts the set.", py::arg("theSet"));
cls_BVH_RadixSorter.def("Perform", (void (BVH_RadixSorter<T, N>::*)(BVH_Set<T, N> *, const Standard_Integer, const Standard_Integer)) &BVH_RadixSorter<T, N>::Perform, "Sorts the given (inclusive) range in the set.", py::arg("theSet"), py::arg("theStart"), py::arg("theFinal"));
cls_BVH_RadixSorter.def("EncodedLinks", (const NCollection_Array1<BVH_EncodedLink> & (BVH_RadixSorter<T, N>::*)() const) &BVH_RadixSorter<T, N>::EncodedLinks, "Returns Morton codes assigned to BVH primitives.");

}

#endif