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
#ifndef __BVH_ParallelDistanceFieldBuilder__
#define __BVH_ParallelDistanceFieldBuilder__

#include <BVH_Geometry.hxx>
#include <BVH_DistanceField.hxx>
#include <Standard_TypeDef.hxx>

template <typename T, int N>
void bind_BVH_ParallelDistanceFieldBuilder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_ParallelDistanceFieldBuilder<T, N>> cls_BVH_ParallelDistanceFieldBuilder(mod, name.c_str(), "Tool object for parallel construction of distance field (uses Intel TBB).", local);

// Constructors
cls_BVH_ParallelDistanceFieldBuilder.def(py::init<BVH_DistanceField<T, N> *, BVH_Geometry<T, N> *>(), py::arg("theOutField"), py::arg("theGeometry"));

// Methods
cls_BVH_ParallelDistanceFieldBuilder.def("__call__", (void (BVH_ParallelDistanceFieldBuilder<T, N>::*)(const Standard_Integer) const) &BVH_ParallelDistanceFieldBuilder<T, N>::operator(), py::is_operator(), "None", py::arg("theIndex"));

}

#endif