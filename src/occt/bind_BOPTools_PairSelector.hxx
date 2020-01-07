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
#ifndef __BOPTools_PairSelector__
#define __BOPTools_PairSelector__

#include <BVH_Traverse.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_BoxSet.hxx>
#include <BOPTools_PairSelector.hxx>
#include <BVH_Types.hxx>

template <int Dimension>
void bind_BOPTools_PairSelector(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BOPTools_PairSelector<Dimension>, BVH_PairTraverse<Standard_Real, Dimension, BVH_BoxSet<Standard_Real, Dimension, Standard_Integer> >> cls_BOPTools_PairSelector(mod, name.c_str(), "Template Selector for selection of the elements from two BVH trees.", local);

// Constructors
cls_BOPTools_PairSelector.def(py::init<>());

// Methods
cls_BOPTools_PairSelector.def("Clear", (void (BOPTools_PairSelector<Dimension>::*)()) &BOPTools_PairSelector<Dimension>::Clear, "Clears the indices");
cls_BOPTools_PairSelector.def("Sort", (void (BOPTools_PairSelector<Dimension>::*)()) &BOPTools_PairSelector<Dimension>::Sort, "Sorts the indices");
cls_BOPTools_PairSelector.def("SetSame", (void (BOPTools_PairSelector<Dimension>::*)(const Standard_Boolean)) &BOPTools_PairSelector<Dimension>::SetSame, "Tells to selector that BVH trees are the same. If the flag is set to true the resulting vector will contain only unique pairs (mirrored pairs will be rejected, e.g. (1, 2) will be taken, (2, 1) will be rejected) and will not contain pairs in which IDs are the same (pair (1, 1) will be rejected). If it is required to have a full vector of pairs even for the same BVH trees, just keep the false value of this flag.", py::arg("theIsSame"));
cls_BOPTools_PairSelector.def("Pairs", (const std::vector<PairIDs> & (BOPTools_PairSelector<Dimension>::*)() const) &BOPTools_PairSelector<Dimension>::Pairs, "Returns the list of accepted indices");
cls_BOPTools_PairSelector.def("RejectNode", [](BOPTools_PairSelector<Dimension> &self, const typename BOPTools_PairSelector<Dimension>::BVH_VecNd & theCMin1, const typename BOPTools_PairSelector<Dimension>::BVH_VecNd & theCMax1, const typename BOPTools_PairSelector<Dimension>::BVH_VecNd & theCMin2, const typename BOPTools_PairSelector<Dimension>::BVH_VecNd & theCMax2, Standard_Real & a0){ Standard_Boolean rv = self.RejectNode(theCMin1, theCMax1, theCMin2, theCMax2, a0); return std::tuple<Standard_Boolean, Standard_Real &>(rv, a0); }, "Basing on the bounding boxes of the nodes checks if the pair of nodes should be rejected.", py::arg("theCMin1"), py::arg("theCMax1"), py::arg("theCMin2"), py::arg("theCMax2"), py::arg(""));
cls_BOPTools_PairSelector.def("RejectElement", (Standard_Boolean (BOPTools_PairSelector<Dimension>::*)(const Standard_Integer, const Standard_Integer)) &BOPTools_PairSelector<Dimension>::RejectElement, "Checks if the pair of elements should be rejected.", py::arg("theID1"), py::arg("theID2"));
cls_BOPTools_PairSelector.def("Accept", (Standard_Boolean (BOPTools_PairSelector<Dimension>::*)(const Standard_Integer, const Standard_Integer)) &BOPTools_PairSelector<Dimension>::Accept, "Checks and accepts the pair of elements.", py::arg("theID1"), py::arg("theID2"));

}

#endif