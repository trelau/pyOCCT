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
#ifndef __BVH_PrimitiveSet__
#define __BVH_PrimitiveSet__

#include <pyOCCT_Common.hxx>
#include <BVH_Object.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_Set.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Box.hxx>
#include <BVH_Tree.hxx>

template <typename T, int N>
void bind_BVH_PrimitiveSet(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_PrimitiveSet<T, N>, opencascade::handle<BVH_PrimitiveSet<T, N>>> cls_BVH_PrimitiveSet(mod, name.c_str(), "Set of abstract geometric primitives organized with bounding volume hierarchy (BVH). Unlike an object set, this collection is designed for storing structural elements of a single object (such as triangles in the object triangulation). Because there may be a large number of such elements, the implementations of this interface should be sufficiently optimized.", py::multiple_inheritance(), local);

// Constructors
// cls_BVH_PrimitiveSet.def(py::init<>());
// cls_BVH_PrimitiveSet.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));

// Fields

// Methods
cls_BVH_PrimitiveSet.def("Box", (BVH_Box<T, N> (BVH_PrimitiveSet<T, N>::*)() const) &BVH_PrimitiveSet<T, N>::Box, "Returns AABB of primitive set.");
cls_BVH_PrimitiveSet.def("BVH", (const opencascade::handle<BVH_Tree<T, N> > & (BVH_PrimitiveSet<T, N>::*)()) &BVH_PrimitiveSet<T, N>::BVH, "Returns BVH tree (and builds it if necessary).");
cls_BVH_PrimitiveSet.def("Builder", (const opencascade::handle<BVH_Builder<T, N> > & (BVH_PrimitiveSet<T, N>::*)() const) &BVH_PrimitiveSet<T, N>::Builder, "Returns the method (builder) used to construct BVH.");
cls_BVH_PrimitiveSet.def("SetBuilder", (void (BVH_PrimitiveSet<T, N>::*)(const opencascade::handle<BVH_Builder<T, N> > &)) &BVH_PrimitiveSet<T, N>::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));

// Enums

}

#endif