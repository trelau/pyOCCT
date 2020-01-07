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
#ifndef __BVH_BaseTraverse__
#define __BVH_BaseTraverse__

#include <Standard_TypeDef.hxx>
#include <BVH_Traverse.hxx>

template <typename MetricType>
void bind_BVH_BaseTraverse(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_BaseTraverse<MetricType>, std::unique_ptr<BVH_BaseTraverse<MetricType>, py::nodelete>> cls_BVH_BaseTraverse(mod, name.c_str(), "Abstract class implementing the base Traverse interface required for selection of the elements from BVH tree.", local);

// Methods
cls_BVH_BaseTraverse.def("IsMetricBetter", (Standard_Boolean (BVH_BaseTraverse<MetricType>::*)(const MetricType &, const MetricType &) const) &BVH_BaseTraverse<MetricType>::IsMetricBetter, "Compares the two metrics and chooses the best one. Returns true if the first metric is better than the second, false otherwise.", py::arg(""), py::arg(""));
cls_BVH_BaseTraverse.def("RejectMetric", (Standard_Boolean (BVH_BaseTraverse<MetricType>::*)(const MetricType &) const) &BVH_BaseTraverse<MetricType>::RejectMetric, "Rejects the node by the metric", py::arg(""));
cls_BVH_BaseTraverse.def("Stop", (Standard_Boolean (BVH_BaseTraverse<MetricType>::*)() const) &BVH_BaseTraverse<MetricType>::Stop, "Returns the flag controlling the tree descend. Returns true if the tree descend should be stopped.");

}

#endif