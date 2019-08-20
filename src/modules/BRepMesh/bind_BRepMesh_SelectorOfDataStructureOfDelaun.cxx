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
#include <Standard_Handle.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <BRepMesh_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_Edge.hxx>
#include <BRepMesh_Triangle.hxx>
#include <BRepMesh_SelectorOfDataStructureOfDelaun.hxx>
#include <BRepMesh.hxx>
#include <NCollection_IncAllocator.hxx>

void bind_BRepMesh_SelectorOfDataStructureOfDelaun(py::module &mod){

py::class_<BRepMesh_SelectorOfDataStructureOfDelaun, std::unique_ptr<BRepMesh_SelectorOfDataStructureOfDelaun>> cls_BRepMesh_SelectorOfDataStructureOfDelaun(mod, "BRepMesh_SelectorOfDataStructureOfDelaun", "Describes a selector and an iterator on a selector of components of a mesh.");

// Constructors
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<>());
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def(py::init<const opencascade::handle<BRepMesh_DataStructureOfDelaun> &>(), py::arg("theMesh"));

// Fields

// Methods
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator delete_", (void (*)(void *)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_SelectorOfDataStructureOfDelaun.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_SelectorOfDataStructureOfDelaun::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Initialize", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const opencascade::handle<BRepMesh_DataStructureOfDelaun> &)) &BRepMesh_SelectorOfDataStructureOfDelaun::Initialize, "Initializes selector by the mesh.", py::arg("theMesh"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Vertex &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given node.", py::arg("theNode"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfNode", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfNode, "Selects all neighboring elements of node with the given index.", py::arg("theNodeIndex"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Edge &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given link.", py::arg("theLink"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfLink", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfLink, "Selects all neighboring elements of link with the given index.", py::arg("theLinkIndex"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Selects all neighboring elements of the given element.", py::arg("theElement"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOfElement", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOfElement, "Selects all neighboring elements by nodes of the given element.", py::arg("theElementIndex"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursByEdgeOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursByEdgeOf, "Selects all neighboring elements by links of the given element.", py::arg("theElement"));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("NeighboursOf", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)(const BRepMesh_SelectorOfDataStructureOfDelaun &)) &BRepMesh_SelectorOfDataStructureOfDelaun::NeighboursOf, "Adds a level of neighbours by edge to the selector.", py::arg(""));
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("AddNeighbours", (void (BRepMesh_SelectorOfDataStructureOfDelaun::*)()) &BRepMesh_SelectorOfDataStructureOfDelaun::AddNeighbours, "Adds a level of neighbours by edge the selector.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Nodes", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Nodes, "Returns selected nodes.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Links", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Links, "Returns selected links.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("Elements", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::Elements, "Returns selected elements.");
cls_BRepMesh_SelectorOfDataStructureOfDelaun.def("FrontierLinks", (const BRepMesh::MapOfInteger & (BRepMesh_SelectorOfDataStructureOfDelaun::*)() const) &BRepMesh_SelectorOfDataStructureOfDelaun::FrontierLinks, "Gives the list of incices of frontier links.");

// Enums

}