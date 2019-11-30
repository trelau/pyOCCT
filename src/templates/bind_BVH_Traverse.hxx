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
#ifndef __BVH_Traverse__
#define __BVH_Traverse__

#include <bind_BVH_BaseTraverse.hxx>
#include <BVH_Traverse.hxx>
#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Tree.hxx>

template <typename NumType, int Dimension, typename BVHSetType, typename MetricType>
void bind_BVH_Traverse(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_BaseTraverse<MetricType>(mod, "BVH_Traverse_Base", py::module_local());

py::class_<BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>, BVH_BaseTraverse<MetricType>> cls_BVH_Traverse(mod, name.c_str(), "Abstract class implementing the traverse of the single binary tree. Selection of the data from the tree is performed by the rules defined in the Accept/Reject methods. See description of the required methods in the comments above.", local);

// Constructors
// cls_BVH_Traverse.def(py::init<>());

// Methods
cls_BVH_Traverse.def("SetBVHSet", (void (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)(BVHSetType *)) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::SetBVHSet, "Sets the BVH Set containing the BVH tree", py::arg("theBVHSet"));
cls_BVH_Traverse.def("AcceptMetric", (Standard_Boolean (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)(const MetricType &) const) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::AcceptMetric, "Basing on the given metric, checks if the whole branch may be accepted without any further checks. Returns true if the metric is accepted, false otherwise.", py::arg(""));
cls_BVH_Traverse.def("RejectNode", (Standard_Boolean (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)(const typename BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, const typename BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, MetricType &) const) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::RejectNode, "Rejection of the node by bounding box. Metric is computed to choose the best branch. Returns true if the node should be rejected, false otherwise.", py::arg("theCornerMin"), py::arg("theCornerMax"), py::arg("theMetric"));
cls_BVH_Traverse.def("Accept", (Standard_Boolean (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)(const Standard_Integer, const MetricType &)) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::Accept, "Leaf element acceptance. Metric of the parent leaf-node is passed to avoid the check on the element and accept it unconditionally. Returns true if the element has been accepted, false otherwise.", py::arg("theIndex"), py::arg("theMetric"));
cls_BVH_Traverse.def("Select", (Standard_Integer (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)()) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::Select, "Selection of the elements from the BVH tree by the rules defined in Accept/Reject methods. The method requires the BVHSet containing BVH tree to be set. Returns the number of accepted elements.");
cls_BVH_Traverse.def("Select", (Standard_Integer (BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::*)(const opencascade::handle<BVH_Tree<NumType, Dimension> > &)) &BVH_Traverse<NumType, Dimension, BVHSetType, MetricType>::Select, "Performs selection of the elements from the BVH tree by the rules defined in Accept/Reject methods. Returns the number of accepted elements.", py::arg("theBVH"));

}

#endif