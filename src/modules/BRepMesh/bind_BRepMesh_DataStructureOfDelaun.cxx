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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_Vertex.hxx>
#include <BRepMesh.hxx>
#include <BRepMesh_Edge.hxx>
#include <BRepMesh_PairOfIndex.hxx>
#include <BRepMesh_Triangle.hxx>
#include <Standard_OStream.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <Standard_Type.hxx>

void bind_BRepMesh_DataStructureOfDelaun(py::module &mod){

py::class_<BRepMesh_DataStructureOfDelaun, opencascade::handle<BRepMesh_DataStructureOfDelaun>, Standard_Transient> cls_BRepMesh_DataStructureOfDelaun(mod, "BRepMesh_DataStructureOfDelaun", "Describes the data structure necessary for the mesh algorithms in two dimensions plane or on surface by meshing in UV space.");

// Constructors
cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
cls_BRepMesh_DataStructureOfDelaun.def(py::init<const opencascade::handle<NCollection_IncAllocator> &, const Standard_Integer>(), py::arg("theAllocator"), py::arg("theReservedNodeSize"));

// Fields

// Methods
cls_BRepMesh_DataStructureOfDelaun.def("NbNodes", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbNodes, "Returns number of nodes.");
cls_BRepMesh_DataStructureOfDelaun.def("AddNode", [](BRepMesh_DataStructureOfDelaun &self, const BRepMesh_Vertex & a0) -> Standard_Integer { return self.AddNode(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("AddNode", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::AddNode, "Adds node to the mesh if it is not already in the mesh.", py::arg("theNode"), py::arg("isForceAdd"));
cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given node.", py::arg("theNode"));
cls_BRepMesh_DataStructureOfDelaun.def("GetNode", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetNode, "Get node by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("__call__", (const BRepMesh_Vertex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::operator(), py::is_operator(), "Alias for GetNode.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteNode", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Vertex &)) &BRepMesh_DataStructureOfDelaun::SubstituteNode, "Substitutes the node with the given index by new one.", py::arg("theIndex"), py::arg("theNewNode"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveNode(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("RemoveNode", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveNode, "Removes node from the mesh in case if it has no connected links and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
cls_BRepMesh_DataStructureOfDelaun.def("LinksConnectedTo", (const BRepMesh::ListOfInteger & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const) &BRepMesh_DataStructureOfDelaun::LinksConnectedTo, "Get list of links attached to the node with the given index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("NbLinks", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbLinks, "Returns number of links.");
cls_BRepMesh_DataStructureOfDelaun.def("AddLink", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::AddLink, "Adds link to the mesh if it is not already in the mesh.", py::arg("theLink"));
cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Edge &) const) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given link.", py::arg("theLink"));
cls_BRepMesh_DataStructureOfDelaun.def("GetLink", (const BRepMesh_Edge & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetLink, "Get link by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("LinksOfDomain", (const BRepMesh::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::LinksOfDomain, "Returns map of indices of links registered in mesh.");
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteLink", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Edge &)) &BRepMesh_DataStructureOfDelaun::SubstituteLink, "Substitutes the link with the given index by new one.", py::arg("theIndex"), py::arg("theNewLink"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", [](BRepMesh_DataStructureOfDelaun &self, const Standard_Integer a0) -> void { return self.RemoveLink(a0); });
cls_BRepMesh_DataStructureOfDelaun.def("RemoveLink", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const Standard_Boolean)) &BRepMesh_DataStructureOfDelaun::RemoveLink, "Removes link from the mesh in case if it has no connected elements and its type is Free.", py::arg("theIndex"), py::arg("isForce"));
cls_BRepMesh_DataStructureOfDelaun.def("ElementsConnectedTo", (const BRepMesh_PairOfIndex & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer) const) &BRepMesh_DataStructureOfDelaun::ElementsConnectedTo, "Returns indices of elements conected to the link with the given index.", py::arg("theLinkIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("NbElements", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::NbElements, "Returns number of links.");
cls_BRepMesh_DataStructureOfDelaun.def("AddElement", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::AddElement, "Adds element to the mesh if it is not already in the mesh.", py::arg("theElement"));
cls_BRepMesh_DataStructureOfDelaun.def("IndexOf", (Standard_Integer (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &) const) &BRepMesh_DataStructureOfDelaun::IndexOf, "Finds the index of the given element.", py::arg("theElement"));
cls_BRepMesh_DataStructureOfDelaun.def("GetElement", (const BRepMesh_Triangle & (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::GetElement, "Get element by the index.", py::arg("theIndex"));
cls_BRepMesh_DataStructureOfDelaun.def("ElementsOfDomain", (const BRepMesh::MapOfInteger & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::ElementsOfDomain, "Returns map of indices of elements registered in mesh.");
cls_BRepMesh_DataStructureOfDelaun.def("SubstituteElement", (Standard_Boolean (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer, const BRepMesh_Triangle &)) &BRepMesh_DataStructureOfDelaun::SubstituteElement, "Substitutes the element with the given index by new one.", py::arg("theIndex"), py::arg("theNewElement"));
cls_BRepMesh_DataStructureOfDelaun.def("RemoveElement", (void (BRepMesh_DataStructureOfDelaun::*)(const Standard_Integer)) &BRepMesh_DataStructureOfDelaun::RemoveElement, "Removes element from the mesh.", py::arg("theIndex"));
// cls_BRepMesh_DataStructureOfDelaun.def("ElementNodes", (void (BRepMesh_DataStructureOfDelaun::*)(const BRepMesh_Triangle &, Standard_Integer (&)[3])) &BRepMesh_DataStructureOfDelaun::ElementNodes, "Returns indices of nodes forming the given element.", py::arg("theElement"), py::arg("theNodes"));
cls_BRepMesh_DataStructureOfDelaun.def("Statistics", (void (BRepMesh_DataStructureOfDelaun::*)(Standard_OStream &) const) &BRepMesh_DataStructureOfDelaun::Statistics, "Dumps information about this structure.", py::arg("theStream"));
cls_BRepMesh_DataStructureOfDelaun.def("Allocator", (const opencascade::handle<NCollection_IncAllocator> & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::Allocator, "Returns memory allocator used by the structure.");
cls_BRepMesh_DataStructureOfDelaun.def("Data", (BRepMesh::HVertexTool & (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::Data, "Gives the data structure for initialization of cell size and tolerance.");
cls_BRepMesh_DataStructureOfDelaun.def("ClearDomain", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDomain, "Removes all elements.");
cls_BRepMesh_DataStructureOfDelaun.def("ClearDeleted", (void (BRepMesh_DataStructureOfDelaun::*)()) &BRepMesh_DataStructureOfDelaun::ClearDeleted, "Substitutes deleted items by the last one from corresponding map to have only non-deleted elements, links or nodes in the structure.");
cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_name_", (const char * (*)()) &BRepMesh_DataStructureOfDelaun::get_type_name, "None");
cls_BRepMesh_DataStructureOfDelaun.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMesh_DataStructureOfDelaun::get_type_descriptor, "None");
cls_BRepMesh_DataStructureOfDelaun.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMesh_DataStructureOfDelaun::*)() const) &BRepMesh_DataStructureOfDelaun::DynamicType, "None");

// Enums

}