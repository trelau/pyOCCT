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
#ifndef __BVH_Triangulation__
#define __BVH_Triangulation__

#include <bind_BVH_PrimitiveSet.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_Triangulation.hxx>
#include <BVH_Types.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Builder.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>

template <typename T, int N>
void bind_BVH_Triangulation(py::module &mod, std::string const &name, py::module_local const &local){

bind_BVH_PrimitiveSet<T, N>(mod, "BVH_Triangulation_Base", py::module_local());

py::class_<BVH_Triangulation<T, N>, opencascade::handle<BVH_Triangulation<T, N>>, BVH_PrimitiveSet<T, N>> cls_BVH_Triangulation(mod, name.c_str(), "Triangulation as an example of BVH primitive set.", local);

// Constructors
cls_BVH_Triangulation.def(py::init<>());
cls_BVH_Triangulation.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));

// Fields
cls_BVH_Triangulation.def_readwrite("Vertices", &BVH_Triangulation<T, N>::Vertices, "Array of vertex coordinates.");
cls_BVH_Triangulation.def_readwrite("Elements", &BVH_Triangulation<T, N>::Elements, "Array of indices of triangle vertices.");

// Methods
cls_BVH_Triangulation.def("Size", (Standard_Integer (BVH_Triangulation<T, N>::*)() const) &BVH_Triangulation<T, N>::Size, "Returns total number of triangles.");
cls_BVH_Triangulation.def("Box", (BVH_Box<T, N> (BVH_Triangulation<T, N>::*)(const Standard_Integer) const) &BVH_Triangulation<T, N>::Box, "Returns AABB of the given triangle.", py::arg("theIndex"));
cls_BVH_Triangulation.def("Center", (T (BVH_Triangulation<T, N>::*)(const Standard_Integer, const Standard_Integer) const) &BVH_Triangulation<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
cls_BVH_Triangulation.def("Swap", (void (BVH_Triangulation<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_Triangulation<T, N>::Swap, "Performs transposing the two given triangles in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

}

#endif