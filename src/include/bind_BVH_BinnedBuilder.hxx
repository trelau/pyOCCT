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
#ifndef __BVH_BinnedBuilder__
#define __BVH_BinnedBuilder__

#include <pyOCCT_Common.hxx>
#include <BVH_QueueBuilder.hxx>
#include <BVH_BinnedBuilder.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>

template <typename T, int N, int Bins>
void bind_BVH_BinnedBuilder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_BinnedBuilder<T, N, Bins>, opencascade::handle<BVH_BinnedBuilder<T, N, Bins>>, BVH_QueueBuilder<T, N>> cls_BVH_BinnedBuilder(mod, name.c_str(), "Performs construction of BVH tree using binned SAH algorithm. Number of bins controls BVH quality in cost of construction time (greater - better). For optimal results, use 32 - 48 bins. However, reasonable performance is provided even for 4 - 8 bins (it is only 10-20% lower in comparison with optimal settings). Note that multiple threads can be used only with thread safe BVH primitive sets.", local);

// Constructors
cls_BVH_BinnedBuilder.def(py::init<>());
cls_BVH_BinnedBuilder.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
cls_BVH_BinnedBuilder.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
cls_BVH_BinnedBuilder.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theDoMainSplits"));
cls_BVH_BinnedBuilder.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theDoMainSplits"), py::arg("theNumOfThreads"));

// Fields

// Methods

// Enums

}

#endif