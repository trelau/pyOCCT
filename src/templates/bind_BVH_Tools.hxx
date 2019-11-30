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
#ifndef __BVH_Tools__
#define __BVH_Tools__

#include <BVH_Types.hxx>
#include <BVH_Tools.hxx>
#include <BVH_Box.hxx>

template <typename T, int N>
void bind_BVH_Tools(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Tools<T, N>> cls_BVH_Tools(mod, name.c_str(), "Defines a set of static methods operating with points and bounding boxes.", local);

// Constructors
cls_BVH_Tools.def(py::init<>());

// Methods
cls_BVH_Tools.def_static("BoxBoxSquareDistance_", (T (*)(const BVH_Box<T, N> &, const BVH_Box<T, N> &)) &BVH_Tools<T, N>::BoxBoxSquareDistance, "Computes Square distance between Axis aligned bounding boxes", py::arg("theBox1"), py::arg("theBox2"));
cls_BVH_Tools.def_static("BoxBoxSquareDistance_", (T (*)(const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &)) &BVH_Tools<T, N>::BoxBoxSquareDistance, "Computes Square distance between Axis aligned bounding boxes", py::arg("theCMin1"), py::arg("theCMax1"), py::arg("theCMin2"), py::arg("theCMax2"));
cls_BVH_Tools.def_static("PointBoxSquareDistance_", (T (*)(const typename BVH_Tools<T, N>::BVH_VecNt &, const BVH_Box<T, N> &)) &BVH_Tools<T, N>::PointBoxSquareDistance, "Computes square distance between point and bounding box", py::arg("thePoint"), py::arg("theBox"));
cls_BVH_Tools.def_static("PointBoxSquareDistance_", (T (*)(const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &)) &BVH_Tools<T, N>::PointBoxSquareDistance, "Computes square distance between point and bounding box", py::arg("thePoint"), py::arg("theCMin"), py::arg("theCMax"));
cls_BVH_Tools.def_static("PointTriangleSquareDistance_", (T (*)(const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &, const typename BVH_Tools<T, N>::BVH_VecNt &)) &BVH_Tools<T, N>::PointTriangleSquareDistance, "Computes square distance between point and triangle", py::arg("thePoint"), py::arg("theNode0"), py::arg("theNode1"), py::arg("theNode2"));

}

#endif