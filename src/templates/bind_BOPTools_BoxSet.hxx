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
#ifndef __BOPTools_BoxSet__
#define __BOPTools_BoxSet__

#include <bind_BVH_BoxSet.hxx>
#include <BVH_BoxSet.hxx>
#include <BOPTools_BoxTree.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>

template <typename NumType, int Dimension, typename DataType>
void bind_BOPTools_BoxSet(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_BoxSet<NumType, Dimension, DataType>(mod, "BOPTools_BoxSet_Base", py::module_local());

py::class_<BOPTools_BoxSet<NumType, Dimension, DataType>, opencascade::handle<BOPTools_BoxSet<NumType, Dimension, DataType>>, BVH_BoxSet<NumType, Dimension, DataType>> cls_BOPTools_BoxSet(mod, name.c_str(), "Redefines BoxSet to use the Linear builder by default", local);

// Constructors
cls_BOPTools_BoxSet.def(py::init<>());
cls_BOPTools_BoxSet.def(py::init<const opencascade::handle<BVH_Builder<NumType, Dimension> > &>(), py::arg("theBuilder"));

}

#endif