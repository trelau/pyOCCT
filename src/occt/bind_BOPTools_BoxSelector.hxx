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
#ifndef __BOPTools_BoxSelector__
#define __BOPTools_BoxSelector__

#include <bind_BVH_Traverse.hxx>
#include <BVH_Traverse.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_BoxSet.hxx>
#include <BVH_Types.hxx>
#include <BVH_Box.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <BOPTools_BoxSelector.hxx>

template <int Dimension>
void bind_BOPTools_BoxSelector(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_Traverse<Standard_Real, Dimension, BVH_BoxSet<Standard_Real, Dimension, Standard_Integer>, Standard_Boolean>(mod, "BOPTools_BoxSelector_Base", py::module_local());

py::class_<BOPTools_BoxSelector<Dimension>, BVH_Traverse<Standard_Real, Dimension, BVH_BoxSet<Standard_Real, Dimension, Standard_Integer>, Standard_Boolean>> cls_BOPTools_BoxSelector(mod, name.c_str(), "Template Selector for elements selection from BVH tree.", local);

// Constructors
cls_BOPTools_BoxSelector.def(py::init<>());

// Methods
cls_BOPTools_BoxSelector.def("Clear", (void (BOPTools_BoxSelector<Dimension>::*)()) &BOPTools_BoxSelector<Dimension>::Clear, "Clears the indices");
cls_BOPTools_BoxSelector.def("SetBox", (void (BOPTools_BoxSelector<Dimension>::*)(const BVH_Box<Standard_Real, Dimension> &)) &BOPTools_BoxSelector<Dimension>::SetBox, "Sets the box", py::arg("theBox"));
cls_BOPTools_BoxSelector.def("Indices", (const TColStd_ListOfInteger & (BOPTools_BoxSelector<Dimension>::*)() const) &BOPTools_BoxSelector<Dimension>::Indices, "Returns the list of accepted indices");
cls_BOPTools_BoxSelector.def("RejectNode", [](BOPTools_BoxSelector<Dimension> &self, const typename BOPTools_BoxSelector<Dimension>::BVH_VecNd & theCMin, const typename BOPTools_BoxSelector<Dimension>::BVH_VecNd & theCMax, Standard_Boolean & theIsInside){ Standard_Boolean rv = self.RejectNode(theCMin, theCMax, theIsInside); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theIsInside); }, "Checks if the box should be rejected", py::arg("theCMin"), py::arg("theCMax"), py::arg("theIsInside"));
cls_BOPTools_BoxSelector.def("RejectElement", (Standard_Boolean (BOPTools_BoxSelector<Dimension>::*)(const Standard_Integer)) &BOPTools_BoxSelector<Dimension>::RejectElement, "Checks if the element should be rejected", py::arg("theIndex"));
cls_BOPTools_BoxSelector.def("AcceptMetric", (Standard_Boolean (BOPTools_BoxSelector<Dimension>::*)(const Standard_Boolean &) const) &BOPTools_BoxSelector<Dimension>::AcceptMetric, "Checks if the metric of the node may be accepted", py::arg("theIsInside"));
cls_BOPTools_BoxSelector.def("Accept", (Standard_Boolean (BOPTools_BoxSelector<Dimension>::*)(const Standard_Integer, const Standard_Boolean &)) &BOPTools_BoxSelector<Dimension>::Accept, "Accepts the element with the index <theIndex> in BVH tree", py::arg("theIndex"), py::arg("theIsInside"));

}

#endif