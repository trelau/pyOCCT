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
#ifndef __BVH_Transform__
#define __BVH_Transform__

#include <pyOCCT_Common.hxx>
#include <BVH_Properties.hxx>
#include <BVH_Types.hxx>
#include <BVH_Box.hxx>

template <typename T, int N>
void bind_BVH_Transform(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Transform<T, N>, opencascade::handle<BVH_Transform<T, N>>, BVH_Properties> cls_BVH_Transform(mod, name.c_str(), "Stores transform properties of geometric object.", local);

// Constructors
cls_BVH_Transform.def(py::init<>());
cls_BVH_Transform.def(py::init<const typename BVH_Transform<T, N>::BVH_MatNt &>(), py::arg("theTransform"));

// Fields

// Methods
cls_BVH_Transform.def("Transform", (const typename BVH_Transform<T, N>::BVH_MatNt & (BVH_Transform<T, N>::*)() const) &BVH_Transform<T, N>::Transform, "Returns transformation matrix.");
cls_BVH_Transform.def("SetTransform", (void (BVH_Transform<T, N>::*)(const typename BVH_Transform<T, N>::BVH_MatNt &)) &BVH_Transform<T, N>::SetTransform, "Sets new transformation matrix.", py::arg("theTransform"));
cls_BVH_Transform.def("Inversed", (const typename BVH_Transform<T, N>::BVH_MatNt & (BVH_Transform<T, N>::*)() const) &BVH_Transform<T, N>::Inversed, "Returns inversed transformation matrix.");
cls_BVH_Transform.def("Apply", (BVH_Box<T, N> (BVH_Transform<T, N>::*)(const BVH_Box<T, N> &) const) &BVH_Transform<T, N>::Apply, "Applies transformation matrix to bounding box.", py::arg("theBox"));

// Enums

}

#endif