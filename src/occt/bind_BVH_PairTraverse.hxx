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
#ifndef __BVH_PairTraverse__
#define __BVH_PairTraverse__

#include <BVH_Traverse.hxx>
#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Tree.hxx>

template <typename NumType, int Dimension, typename BVHSetType, typename MetricType>
void bind_BVH_PairTraverse(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>, BVH_BaseTraverse<MetricType>> cls_BVH_PairTraverse(mod, name.c_str(), "Abstract class implementing the parallel traverse of two binary trees. Selection of the data from the trees is performed by the rules defined in the Accept/Reject methods. See description of the required methods in the comments above.", local);

// Constructors
cls_BVH_PairTraverse.def(py::init<>());

// Methods
cls_BVH_PairTraverse.def("SetBVHSets", (void (BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::*)(BVHSetType *, BVHSetType *)) &BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::SetBVHSets, "Sets the BVH Sets containing the BVH trees", py::arg("theBVHSet1"), py::arg("theBVHSet2"));
cls_BVH_PairTraverse.def("RejectNode", (Standard_Boolean (BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::*)(const typename BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, const typename BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, const typename BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, const typename BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::BVH_VecNt &, MetricType &) const) &BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::RejectNode, "Rejection of the pair of nodes by bounding boxes. Metric is computed to choose the best branch. Returns true if the pair of nodes should be rejected, false otherwise.", py::arg("theCornerMin1"), py::arg("theCornerMax1"), py::arg("theCornerMin2"), py::arg("theCornerMax2"), py::arg("theMetric"));
cls_BVH_PairTraverse.def("Accept", (Standard_Boolean (BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::*)(const Standard_Integer, const Standard_Integer)) &BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::Accept, "Leaf element acceptance. Returns true if the pair of elements is accepted, false otherwise.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BVH_PairTraverse.def("Select", (Standard_Integer (BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::*)()) &BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::Select, "Selection of the pairs of elements of two BVH trees by the rules defined in Accept/Reject methods. The method requires the BVHSets containing BVH trees to be set. Returns the number of accepted pairs of elements.");
cls_BVH_PairTraverse.def("Select", (Standard_Integer (BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::*)(const opencascade::handle<BVH_Tree<NumType, Dimension> > &, const opencascade::handle<BVH_Tree<NumType, Dimension> > &)) &BVH_PairTraverse<NumType, Dimension, BVHSetType, MetricType>::Select, "Performs selection of the elements from two BVH trees by the rules defined in Accept/Reject methods. Returns the number of accepted pairs of elements.", py::arg("theBVH1"), py::arg("theBVH2"));

}

#endif