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
#ifndef __BRepMesh_DelaunayDeflectionControlMeshAlgo__
#define __BRepMesh_DelaunayDeflectionControlMeshAlgo__

#include <BRepMesh_DelaunayNodeInsertionMeshAlgo.hxx>
#include <BRepMesh_DelaunayDeflectionControlMeshAlgo.hxx>
#include <BRepMesh_Delaun.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <BRepMesh_Triangle.hxx>
#include <Standard_Handle.hxx>
#include <IMeshData_Types.hxx>
#include <BRepMesh_CircleTool.hxx>

template <typename RangeSplitter, typename BaseAlgo>
void bind_BRepMesh_DelaunayDeflectionControlMeshAlgo(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BRepMesh_DelaunayDeflectionControlMeshAlgo<RangeSplitter, BaseAlgo>, BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>> cls_BRepMesh_DelaunayDeflectionControlMeshAlgo(mod, name.c_str(), "Extends node insertion Delaunay meshing algo in order to control deflection of generated trianges. Splits triangles failing the check.", local);

// Constructors
cls_BRepMesh_DelaunayDeflectionControlMeshAlgo.def(py::init<>());

}

#endif