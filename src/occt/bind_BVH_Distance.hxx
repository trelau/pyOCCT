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
#ifndef __BVH_Distance__
#define __BVH_Distance__

#include <BVH_Traverse.hxx>
#include <BVH_Distance.hxx>
#include <Standard_TypeDef.hxx>

template <typename NumType, int Dimension, typename ObjectType, typename BVHSetType>
void bind_BVH_Distance(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>, BVH_Traverse<NumType, Dimension, BVHSetType, NumType>> cls_BVH_Distance(mod, name.c_str(), "Abstract class for computation of the min distance between some Object and elements of BVH tree. To use this class it is required to define two methods: - *RejectNode* to compute distance from the object to bounding box - *Accept* to compute distance from the object to the element of tree", local);

// Constructors
cls_BVH_Distance.def(py::init<>());

// Methods
cls_BVH_Distance.def("SetObject", (void (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)(const ObjectType &)) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::SetObject, "Sets the object to which the distance is required", py::arg("theObject"));
cls_BVH_Distance.def("ComputeDistance", (NumType (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)()) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::ComputeDistance, "Computes the distance between object and BVH tree");
cls_BVH_Distance.def("IsDone", (Standard_Boolean (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)() const) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::IsDone, "Returns IsDone flag");
cls_BVH_Distance.def("Distance", (NumType (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)() const) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::Distance, "Returns the computed distance");
cls_BVH_Distance.def("IsMetricBetter", (Standard_Boolean (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)(const NumType &, const NumType &) const) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::IsMetricBetter, "Compares the two metrics and chooses the best one", py::arg("theLeft"), py::arg("theRight"));
cls_BVH_Distance.def("RejectMetric", (Standard_Boolean (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)(const NumType &) const) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::RejectMetric, "Rejects the branch by the metric", py::arg("theMetric"));
cls_BVH_Distance.def("Stop", (Standard_Boolean (BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::*)() const) &BVH_Distance<NumType, Dimension, ObjectType, BVHSetType>::Stop, "Returns the flag controlling the tree descend");

}

#endif