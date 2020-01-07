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
#ifndef __BVH_PairDistance__
#define __BVH_PairDistance__

#include <BVH_Traverse.hxx>
#include <BVH_PairDistance.hxx>
#include <BVH_Tools.hxx>
#include <Standard_TypeDef.hxx>

template <typename NumType, int Dimension, typename BVHSetType>
void bind_BVH_PairDistance(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_PairDistance<NumType, Dimension, BVHSetType>, BVH_PairTraverse<NumType, Dimension, BVHSetType, NumType>> cls_BVH_PairDistance(mod, name.c_str(), "Abstract class for computation of the min distance between elements of two BVH trees. To use this class it is required to define only the method *Accept* to compute the distance between elements of the trees.", local);

// Constructors
cls_BVH_PairDistance.def(py::init<>());

// Methods
cls_BVH_PairDistance.def("ComputeDistance", (NumType (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)()) &BVH_PairDistance<NumType, Dimension, BVHSetType>::ComputeDistance, "Computes the distance between two BVH trees");
cls_BVH_PairDistance.def("IsDone", (Standard_Boolean (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)() const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::IsDone, "Returns IsDone flag");
cls_BVH_PairDistance.def("Distance", (NumType (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)() const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::Distance, "Returns the computed distance");
cls_BVH_PairDistance.def("IsMetricBetter", (Standard_Boolean (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)(const NumType &, const NumType &) const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::IsMetricBetter, "Compares the two metrics and chooses the best one", py::arg("theLeft"), py::arg("theRight"));
cls_BVH_PairDistance.def("RejectNode", (Standard_Boolean (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)(const typename BVH_PairDistance<NumType, Dimension, BVHSetType>::BVH_VecNt &, const typename BVH_PairDistance<NumType, Dimension, BVHSetType>::BVH_VecNt &, const typename BVH_PairDistance<NumType, Dimension, BVHSetType>::BVH_VecNt &, const typename BVH_PairDistance<NumType, Dimension, BVHSetType>::BVH_VecNt &, NumType &) const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::RejectNode, "Computes the distance between boxes of the nodes", py::arg("theCornerMin1"), py::arg("theCornerMax1"), py::arg("theCornerMin2"), py::arg("theCornerMax2"), py::arg("theMetric"));
cls_BVH_PairDistance.def("RejectMetric", (Standard_Boolean (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)(const NumType &) const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::RejectMetric, "Rejects the branch by the metric", py::arg("theMetric"));
cls_BVH_PairDistance.def("Stop", (Standard_Boolean (BVH_PairDistance<NumType, Dimension, BVHSetType>::*)() const) &BVH_PairDistance<NumType, Dimension, BVHSetType>::Stop, "Returns the flag controlling the tree descend");

}

#endif