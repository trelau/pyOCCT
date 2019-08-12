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
#ifndef __BVH_ObjectSet__
#define __BVH_ObjectSet__

#include <pyOCCT_Common.hxx>
#include <BVH_Set.hxx>
#include <BVH_ObjectSet.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Object.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>

template <typename T, int N>
void bind_BVH_ObjectSet(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_ObjectSet<T, N>, std::unique_ptr<BVH_ObjectSet<T, N>, Deleter<BVH_ObjectSet<T, N>>>, BVH_Set<T, N>> cls_BVH_ObjectSet(mod, name.c_str(), "Array of abstract entities (bounded by BVH boxes) to built BVH.", local);

// Constructors
cls_BVH_ObjectSet.def(py::init<>());

// Fields

// Methods
cls_BVH_ObjectSet.def("Clear", (void (BVH_ObjectSet<T, N>::*)()) &BVH_ObjectSet<T, N>::Clear, "Removes all geometric objects.");
cls_BVH_ObjectSet.def("Objects", (BVH_ObjectSet<T, N>::BVH_ObjectList & (BVH_ObjectSet<T, N>::*)()) &BVH_ObjectSet<T, N>::Objects, "Returns reference to the array of geometric objects.");
cls_BVH_ObjectSet.def("Objects", (const BVH_ObjectSet<T, N>::BVH_ObjectList & (BVH_ObjectSet<T, N>::*)() const) &BVH_ObjectSet<T, N>::Objects, "Returns reference to the array of geometric objects.");
cls_BVH_ObjectSet.def("Size", (Standard_Integer (BVH_ObjectSet<T, N>::*)() const) &BVH_ObjectSet<T, N>::Size, "Return total number of objects.");
cls_BVH_ObjectSet.def("Box", (BVH_Box<T, N> (BVH_ObjectSet<T, N>::*)(const Standard_Integer) const) &BVH_ObjectSet<T, N>::Box, "Returns AABB of the given object.", py::arg("theIndex"));
cls_BVH_ObjectSet.def("Center", (T (BVH_ObjectSet<T, N>::*)(const Standard_Integer, const Standard_Integer) const) &BVH_ObjectSet<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
cls_BVH_ObjectSet.def("Swap", (void (BVH_ObjectSet<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_ObjectSet<T, N>::Swap, "Performs transposing the two given objects in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

// Enums

}

#endif