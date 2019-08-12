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
#ifndef __BVH_QueueBuilder__
#define __BVH_QueueBuilder__

#include <pyOCCT_Common.hxx>
#include <BVH_Builder.hxx>
#include <BVH_QueueBuilder.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <BVH_Box.hxx>
#include <BVH_BuildThread.hxx>
#include <BVH_BuildQueue.hxx>

template <typename T, int N>
void bind_BVH_QueueBuilder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_QueueBuilder<T, N>, opencascade::handle<BVH_QueueBuilder<T, N>>, BVH_Builder<T, N>> cls_BVH_QueueBuilder(mod, name.c_str(), "Abstract BVH builder based on the concept of work queue. Queue based BVH builders support parallelization with a fixed number of threads (maximum efficiency is achieved by setting the number of threads equal to the number of CPU cores plus one). Note that to support parallel mode, a corresponding BVH primitive set should provide thread safe implementations of interface functions (e.g., Swap, Box, Center). Otherwise, the results will be undefined.", local);

// Constructors
cls_BVH_QueueBuilder.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
cls_BVH_QueueBuilder.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theNumOfThreads"));

// Fields

// Methods
cls_BVH_QueueBuilder.def("Build", (void (BVH_QueueBuilder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const) &BVH_QueueBuilder<T, N>::Build, "Builds BVH using specific algorithm.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

// Enums

}

#endif