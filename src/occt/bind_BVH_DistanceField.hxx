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
#ifndef __BVH_DistanceField__
#define __BVH_DistanceField__

#include <BVH_DistanceField.hxx>
#include <BVH_Types.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Geometry.hxx>

template <typename T, int N>
void bind_BVH_DistanceField(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_DistanceField<T, N>> cls_BVH_DistanceField(mod, name.c_str(), "Tool object for building 3D distance field from the set of BVH triangulations. Distance field is a scalar field that measures the distance from a given point to some object, including optional information about the inside and outside of the structure. Distance fields are used as alternative surface representations (like polygons or NURBS).", local);

// Constructors
cls_BVH_DistanceField.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("theMaximumSize"), py::arg("theComputeSign"));

// Methods
cls_BVH_DistanceField.def("Build", (Standard_Boolean (BVH_DistanceField<T, N>::*)(BVH_Geometry<T, N> &)) &BVH_DistanceField<T, N>::Build, "Builds 3D distance field from BVH geometry.", py::arg("theGeometry"));
cls_BVH_DistanceField.def("IsParallel", (Standard_Boolean (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::IsParallel, "Returns parallel flag.");
cls_BVH_DistanceField.def("SetParallel", (void (BVH_DistanceField<T, N>::*)(const Standard_Boolean)) &BVH_DistanceField<T, N>::SetParallel, "Set parallel flag contolling possibility of parallel execution.", py::arg("isParallel"));
cls_BVH_DistanceField.def("PackedData", (const T * (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::PackedData, "Returns packed voxel data.");
cls_BVH_DistanceField.def("Voxel", (T & (BVH_DistanceField<T, N>::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BVH_DistanceField<T, N>::Voxel, "Returns distance value for the given voxel.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_BVH_DistanceField.def("Voxel", (T (BVH_DistanceField<T, N>::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &BVH_DistanceField<T, N>::Voxel, "Returns distance value for the given voxel.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_BVH_DistanceField.def("DimensionX", (Standard_Integer (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::DimensionX, "Returns size of voxel grid in X dimension.");
cls_BVH_DistanceField.def("DimensionY", (Standard_Integer (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::DimensionY, "Returns size of voxel grid in Y dimension.");
cls_BVH_DistanceField.def("DimensionZ", (Standard_Integer (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::DimensionZ, "Returns size of voxel grid in Z dimension.");
cls_BVH_DistanceField.def("VoxelSize", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::VoxelSize, "Returns size of single voxel.");
cls_BVH_DistanceField.def("CornerMin", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::CornerMin, "Returns minimum corner of voxel grid.");
cls_BVH_DistanceField.def("CornerMax", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const) &BVH_DistanceField<T, N>::CornerMax, "Returns maximum corner of voxel grid.");

}

#endif