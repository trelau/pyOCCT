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
#ifndef __BVH_IndexedBoxSet__
#define __BVH_IndexedBoxSet__

#include <Standard_TypeDef.hxx>
#include <BVH_BoxSet.hxx>
#include <BVH_IndexedBoxSet.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Box.hxx>

template <typename NumType, int Dimension, typename DataType>
void bind_BVH_IndexedBoxSet(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_IndexedBoxSet<NumType, Dimension, DataType>, opencascade::handle<BVH_IndexedBoxSet<NumType, Dimension, DataType>>, BVH_BoxSet<NumType, Dimension, DataType>> cls_BVH_IndexedBoxSet(mod, name.c_str(), "Implements easy to use interfaces for adding the elements into BVH tree and its following construction. To make it more effective it is better to set the number of elements that are going to be added into BVH tree. It uses the indirect indexing for accessing the elements and their boxes which allows using heavy data types as elements with better efficiency during BVH construction and just a bit slower selection time. Due to better BVH tree construction time the class will be more efficient than BVH_BoxSet on the operations where just a few selections from the tree required.", local);

// Constructors
cls_BVH_IndexedBoxSet.def(py::init<>());
cls_BVH_IndexedBoxSet.def(py::init<const opencascade::handle<BVH_Builder<NumType, Dimension> > &>(), py::arg("theBuilder"));

// Methods
cls_BVH_IndexedBoxSet.def("SetSize", (void (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)(const Standard_Size)) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::SetSize, "Sets the expected size of BVH tree", py::arg("theSize"));
cls_BVH_IndexedBoxSet.def("Add", (void (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)(const DataType &, const BVH_Box<NumType, Dimension> &)) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::Add, "Adds the element into BVH", py::arg("theElement"), py::arg("theBox"));
cls_BVH_IndexedBoxSet.def("Clear", (void (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)()) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::Clear, "Clears the vectors of elements and boxes");
cls_BVH_IndexedBoxSet.def("Box", (BVH_Box<NumType, Dimension> (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer) const) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::Box, "Returns the bounding box with the given index.", py::arg("theIndex"));
cls_BVH_IndexedBoxSet.def("Swap", (void (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer, const Standard_Integer)) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::Swap, "Swaps indices of two specified boxes.", py::arg("theIndex1"), py::arg("theIndex2"));
cls_BVH_IndexedBoxSet.def("Element", (DataType (BVH_IndexedBoxSet<NumType, Dimension, DataType>::*)(const Standard_Integer) const) &BVH_IndexedBoxSet<NumType, Dimension, DataType>::Element, "Returns the Element with the index theIndex.", py::arg("theIndex"));

}

#endif