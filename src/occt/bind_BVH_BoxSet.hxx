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
#ifndef __BVH_BoxSet__
#define __BVH_BoxSet__

#include <bind_BVH_PrimitiveSet.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_BoxSet.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Box.hxx>

template <typename NumType, int Dimension, typename DataType>
void bind_BVH_BoxSet(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_PrimitiveSet<NumType, Dimension>(mod, "BVH_BoxSet_Base", py::module_local());

py::class_<BVH_BoxSet<NumType, Dimension, DataType>, opencascade::handle<BVH_BoxSet<NumType, Dimension, DataType>>, BVH_PrimitiveSet<NumType, Dimension>> cls_BVH_BoxSet(mod, name.c_str(), "Implements easy to use interfaces for adding the elements into BVH tree and its following construction. To make it more effective it is better to set the number of elements that are going to be added into BVH tree. For better efficiency on heavy data types it is recommended to use either BHV_IndexedBoxSet which uses indirect indexing for accessing the elements and their boxes or set the element to be an index of the real element in the application's internal data structures.", local);

// Constructors
cls_BVH_BoxSet.def(py::init<>());
cls_BVH_BoxSet.def(py::init<const opencascade::handle<BVH_Builder<NumType, Dimension> > &>(), py::arg("theBuilder"));

// Methods
cls_BVH_BoxSet.def("SetSize", (void (BVH_BoxSet<NumType, Dimension, DataType>::*)(const Standard_Size)) &BVH_BoxSet<NumType, Dimension, DataType>::SetSize, "Sets the expected size of BVH tree", py::arg("theSize"));
cls_BVH_BoxSet.def("Add", (void (BVH_BoxSet<NumType, Dimension, DataType>::*)(const DataType &, const BVH_Box<NumType, Dimension> &)) &BVH_BoxSet<NumType, Dimension, DataType>::Add, "Adds the element into BVH", py::arg("theElement"), py::arg("theBox"));
cls_BVH_BoxSet.def("Build", (void (BVH_BoxSet<NumType, Dimension, DataType>::*)()) &BVH_BoxSet<NumType, Dimension, DataType>::Build, "BVH construction");
cls_BVH_BoxSet.def("Clear", (void (BVH_BoxSet<NumType, Dimension, DataType>::*)()) &BVH_BoxSet<NumType, Dimension, DataType>::Clear, "Clears the vectors of elements and boxes");
cls_BVH_BoxSet.def("Box", (BVH_Box<NumType, Dimension> (BVH_BoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer) const) &BVH_BoxSet<NumType, Dimension, DataType>::Box, "Returns the bounding box with the given index.", py::arg("theIndex"));
cls_BVH_BoxSet.def("Center", (Standard_Real (BVH_BoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer, const Standard_Integer) const) &BVH_BoxSet<NumType, Dimension, DataType>::Center, "Returns centroid position along specified axis.", py::arg("theIndex"), py::arg("theAxis"));
cls_BVH_BoxSet.def("Size", (Standard_Integer (BVH_BoxSet<NumType, Dimension, DataType>::*)() const) &BVH_BoxSet<NumType, Dimension, DataType>::Size, "Returns the number of boxes.");
cls_BVH_BoxSet.def("Swap", (void (BVH_BoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer, const Standard_Integer)) &BVH_BoxSet<NumType, Dimension, DataType>::Swap, "Swaps indices of two specified boxes.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BVH_BoxSet.def("Element", (DataType (BVH_BoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer) const) &BVH_BoxSet<NumType, Dimension, DataType>::Element, "Returns the Element with the index theIndex.", py::arg("theIndex"));

}

#endif