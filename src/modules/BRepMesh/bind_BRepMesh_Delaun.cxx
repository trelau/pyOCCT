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
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <BRepMesh.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh_Edge.hxx>
#include <BRepMesh_Triangle.hxx>
#include <BRepMesh_CircleTool.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Vec2d.hxx>
#include <Bnd_B2d.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepMesh_Delaun.hxx>
#include <gp_XY.hxx>
#include <BRepMesh_GeomTool.hxx>

void bind_BRepMesh_Delaun(py::module &mod){

py::class_<BRepMesh_Delaun, std::unique_ptr<BRepMesh_Delaun, Deleter<BRepMesh_Delaun>>> cls_BRepMesh_Delaun(mod, "BRepMesh_Delaun", "Compute the Delaunay's triangulation with the algorithm of Watson.");

// Constructors
cls_BRepMesh_Delaun.def(py::init<BRepMesh::Array1OfVertexOfDelaun &>(), py::arg("theVertices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, BRepMesh::Array1OfVertexOfDelaun &>(), py::arg("theOldMesh"), py::arg("theVertices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, BRepMesh::Array1OfInteger &>(), py::arg("theOldMesh"), py::arg("theVertexIndices"));
cls_BRepMesh_Delaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, BRepMesh::Array1OfInteger &, const Standard_Integer, const Standard_Integer>(), py::arg("theOldMesh"), py::arg("theVertexIndices"), py::arg("theCellsCountU"), py::arg("theCellsCountV"));

// Fields

// Methods
// cls_BRepMesh_Delaun.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Delaun::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Delaun.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Delaun::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Delaun::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Delaun.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Delaun::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Delaun::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Delaun.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Delaun::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Delaun.def("Init", (void (BRepMesh_Delaun::*)(BRepMesh::Array1OfVertexOfDelaun &)) &BRepMesh_Delaun::Init, "Initializes the triangulation with an array of vertices.", py::arg("theVertices"));
cls_BRepMesh_Delaun.def("RemoveVertex", (void (BRepMesh_Delaun::*)(const BRepMesh_Vertex &)) &BRepMesh_Delaun::RemoveVertex, "Removes a vertex from the triangulation.", py::arg("theVertex"));
cls_BRepMesh_Delaun.def("AddVertices", (void (BRepMesh_Delaun::*)(BRepMesh::Array1OfVertexOfDelaun &)) &BRepMesh_Delaun::AddVertices, "Adds some vertices into the triangulation.", py::arg("theVertices"));
cls_BRepMesh_Delaun.def("UseEdge", (Standard_Boolean (BRepMesh_Delaun::*)(const Standard_Integer)) &BRepMesh_Delaun::UseEdge, "Modify mesh to use the edge.", py::arg("theEdge"));
cls_BRepMesh_Delaun.def("Result", (const opencascade::handle<BRepMesh_DataStructureOfDelaun> & (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Result, "Gives the Mesh data structure.");
// cls_BRepMesh_Delaun.def("Frontier", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Frontier, "Gives the list of frontier edges.");
// cls_BRepMesh_Delaun.def("InternalEdges", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::InternalEdges, "Gives the list of internal edges.");
// cls_BRepMesh_Delaun.def("FreeEdges", (BRepMesh::HMapOfInteger (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::FreeEdges, "Gives the list of free edges used only one time");
cls_BRepMesh_Delaun.def("GetVertex", (const BRepMesh_Vertex & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetVertex, "Gives vertex with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("GetEdge", (const BRepMesh_Edge & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetEdge, "Gives edge with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("GetTriangle", (const BRepMesh_Triangle & (BRepMesh_Delaun::*)(const Standard_Integer) const) &BRepMesh_Delaun::GetTriangle, "Gives triangle with the given index", py::arg("theIndex"));
cls_BRepMesh_Delaun.def("Circles", (const BRepMesh_CircleTool & (BRepMesh_Delaun::*)() const) &BRepMesh_Delaun::Circles, "Returns tool used to build mesh consistent to Delaunay criteria.");
cls_BRepMesh_Delaun.def("Contains", [](BRepMesh_Delaun &self, const Standard_Integer theTriangleId, const BRepMesh_Vertex & theVertex, const Standard_Real theSqTolerance, Standard_Integer & theEdgeOn){ Standard_Boolean rv = self.Contains(theTriangleId, theVertex, theSqTolerance, theEdgeOn); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, theEdgeOn); }, "Test is the given triangle contains the given vertex.", py::arg("theTriangleId"), py::arg("theVertex"), py::arg("theSqTolerance"), py::arg("theEdgeOn"));

// Enums

}