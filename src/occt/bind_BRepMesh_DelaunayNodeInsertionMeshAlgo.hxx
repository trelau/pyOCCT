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
#ifndef __BRepMesh_DelaunayNodeInsertionMeshAlgo__
#define __BRepMesh_DelaunayNodeInsertionMeshAlgo__

#include <BRepMesh_NodeInsertionMeshAlgo.hxx>
#include <BRepMesh_DelaunayNodeInsertionMeshAlgo.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_Delaun.hxx>
#include <Standard_Handle.hxx>
#include <IMeshData_Types.hxx>

template <typename RangeSplitter, typename BaseAlgo>
void bind_BRepMesh_DelaunayNodeInsertionMeshAlgo(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>, BRepMesh_NodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>> cls_BRepMesh_DelaunayNodeInsertionMeshAlgo(mod, name.c_str(), "Extends base Delaunay meshing algo in order to enable possibility of addition of free vertices and internal nodes into the mesh.", local);

// Constructors
cls_BRepMesh_DelaunayNodeInsertionMeshAlgo.def(py::init<>());

// Methods
cls_BRepMesh_DelaunayNodeInsertionMeshAlgo.def("IsPreProcessSurfaceNodes", (Standard_Boolean (BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::*)() const) &BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::IsPreProcessSurfaceNodes, "Returns PreProcessSurfaceNodes flag.");
cls_BRepMesh_DelaunayNodeInsertionMeshAlgo.def("SetPreProcessSurfaceNodes", (void (BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::*)(const Standard_Boolean)) &BRepMesh_DelaunayNodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::SetPreProcessSurfaceNodes, "Sets PreProcessSurfaceNodes flag. If TRUE, registers surface nodes before generation of base mesh. If FALSE, inserts surface nodes after generation of base mesh.", py::arg("isPreProcessSurfaceNodes"));

}

#endif