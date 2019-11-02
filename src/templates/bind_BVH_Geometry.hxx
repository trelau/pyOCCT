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
#ifndef __BVH_Geometry__
#define __BVH_Geometry__

#include <bind_BVH_ObjectSet.hxx>
#include <BVH_ObjectSet.hxx>
#include <BVH_Geometry.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>
#include <BVH_Tree.hxx>

template <typename T, int N>
void bind_BVH_Geometry(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_ObjectSet<T, N>(mod, "BVH_Geometry_Base", py::module_local());

py::class_<BVH_Geometry<T, N>, BVH_ObjectSet<T, N>> cls_BVH_Geometry(mod, name.c_str(), "BVH geometry as a set of abstract geometric objects organized with bounding volume hierarchy (BVH).", local);

// Constructors
cls_BVH_Geometry.def(py::init<>());
cls_BVH_Geometry.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));

// Methods
cls_BVH_Geometry.def("IsDirty", (Standard_Boolean (BVH_Geometry<T, N>::*)() const) &BVH_Geometry<T, N>::IsDirty, "Returns TRUE if geometry state should be updated.");
cls_BVH_Geometry.def("MarkDirty", (void (BVH_Geometry<T, N>::*)()) &BVH_Geometry<T, N>::MarkDirty, "Marks geometry as outdated.");
cls_BVH_Geometry.def("Box", (BVH_Box<T, N> (BVH_Geometry<T, N>::*)() const) &BVH_Geometry<T, N>::Box, "Returns AABB of the whole geometry.");
cls_BVH_Geometry.def("BVH", (const opencascade::handle<BVH_Tree<T, N> > & (BVH_Geometry<T, N>::*)()) &BVH_Geometry<T, N>::BVH, "Returns BVH tree (and builds it if necessary).");
cls_BVH_Geometry.def("Builder", (const opencascade::handle<BVH_Builder<T, N> > & (BVH_Geometry<T, N>::*)() const) &BVH_Geometry<T, N>::Builder, "Returns the method (builder) used to construct BVH.");
cls_BVH_Geometry.def("SetBuilder", (void (BVH_Geometry<T, N>::*)(const opencascade::handle<BVH_Builder<T, N> > &)) &BVH_Geometry<T, N>::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));

}

#endif