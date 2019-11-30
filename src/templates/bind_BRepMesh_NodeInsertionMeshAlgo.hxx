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
#ifndef __BRepMesh_NodeInsertionMeshAlgo__
#define __BRepMesh_NodeInsertionMeshAlgo__

#include <BRepMesh_NodeInsertionMeshAlgo.hxx>
#include <IMeshData_Types.hxx>
#include <IMeshTools_Parameters.hxx>
#include <NCollection_Sequence.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <BRepMesh_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_Classifier.hxx>
#include <NCollection_IncAllocator.hxx>
#include <TopoDS_Vertex.hxx>

template <typename RangeSplitter, typename BaseAlgo>
void bind_BRepMesh_NodeInsertionMeshAlgo(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BRepMesh_NodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>, BaseAlgo> cls_BRepMesh_NodeInsertionMeshAlgo(mod, name.c_str(), "Extends base meshing algo in order to enable possibility of addition of free vertices into the mesh.", local);

// Constructors
cls_BRepMesh_NodeInsertionMeshAlgo.def(py::init<>());

// Methods
cls_BRepMesh_NodeInsertionMeshAlgo.def("Perform", (void (BRepMesh_NodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &BRepMesh_NodeInsertionMeshAlgo<RangeSplitter, BaseAlgo>::Perform, "Performs processing of the given face.", py::arg("theDFace"), py::arg("theParameters"));

}

#endif