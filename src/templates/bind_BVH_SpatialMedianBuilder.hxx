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
#pragma once

#include <pyOCCT_Common.hxx>
#include <BVH_BinnedBuilder.hxx>
#include <BVH_SpatialMedianBuilder.hxx>
#include <Standard_TypeDef.hxx>

template <typename T, int N>
void bind_BVH_SpatialMedianBuilder(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_SpatialMedianBuilder<T, N>, opencascade::handle<BVH_SpatialMedianBuilder<T, N>>, BVH_BinnedBuilder<T, N, 2>> cls_BVH_SpatialMedianBuilder(mod, name.c_str(), "Performs building of BVH tree using spatial median split algorithm.", local);

// Constructors
cls_BVH_SpatialMedianBuilder.def(py::init<>());
cls_BVH_SpatialMedianBuilder.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
cls_BVH_SpatialMedianBuilder.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
cls_BVH_SpatialMedianBuilder.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theToUseMainAxis"));

}
