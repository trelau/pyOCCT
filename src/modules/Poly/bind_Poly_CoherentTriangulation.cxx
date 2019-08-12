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
#include <Poly_CoherentTriangulation.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Poly_Triangulation.hxx>
#include <NCollection_List.hxx>
#include <gp_XYZ.hxx>
#include <Poly_CoherentNode.hxx>
#include <Poly_CoherentTriangle.hxx>
#include <Poly_CoherentLink.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_Type.hxx>

void bind_Poly_CoherentTriangulation(py::module &mod){

py::class_<Poly_CoherentTriangulation, opencascade::handle<Poly_CoherentTriangulation>, Standard_Transient> cls_Poly_CoherentTriangulation(mod, "Poly_CoherentTriangulation", "Triangulation structure that allows to: Store the connectivity of each triangle with up to 3 neighbouring ones and with the corresponding 3rd nodes on them, Store the connectivity of each node with all triangles that share this node Add nodes and triangles to the structure, Find all triangles sharing a single or a couple of nodes Remove triangles from structure Optionally create Links between pairs of nodes according to the current triangulation. Convert from/to Poly_Triangulation structure.");

// Constructors
cls_Poly_CoherentTriangulation.def(py::init<>());
cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));
cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theTriangulation"), py::arg("theAlloc"));

// Fields

// Methods
cls_Poly_CoherentTriangulation.def("GetTriangulation", (opencascade::handle<Poly_Triangulation> (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::GetTriangulation, "Create an instance of Poly_Triangulation from this object.");
cls_Poly_CoherentTriangulation.def("RemoveDegenerated", [](Poly_CoherentTriangulation &self, const Standard_Real a0) -> Standard_Boolean { return self.RemoveDegenerated(a0); });
cls_Poly_CoherentTriangulation.def("RemoveDegenerated", (Standard_Boolean (Poly_CoherentTriangulation::*)(const Standard_Real, NCollection_List<Poly_CoherentTriangulation::TwoIntegers> *)) &Poly_CoherentTriangulation::RemoveDegenerated, "Find and remove degenerated triangles in Triangulation.", py::arg("theTol"), py::arg("pLstRemovedNode"));
cls_Poly_CoherentTriangulation.def("GetFreeNodes", (Standard_Boolean (Poly_CoherentTriangulation::*)(NCollection_List<Standard_Integer> &) const) &Poly_CoherentTriangulation::GetFreeNodes, "Create a list of free nodes. These nodes may appear as a result of any custom mesh decimation or RemoveDegenerated() call. This analysis is necessary if you support additional data structures based on the triangulation (e.g., edges on the surface boundary).", py::arg("lstNodes"));
cls_Poly_CoherentTriangulation.def("MaxNode", (Standard_Integer (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::MaxNode, "Query the index of the last node in the triangulation");
cls_Poly_CoherentTriangulation.def("MaxTriangle", (Standard_Integer (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::MaxTriangle, "Query the index of the last triangle in the triangulation");
cls_Poly_CoherentTriangulation.def("SetDeflection", (void (Poly_CoherentTriangulation::*)(const Standard_Real)) &Poly_CoherentTriangulation::SetDeflection, "Set the Deflection value as the parameter of the given triangulation.", py::arg("theDefl"));
cls_Poly_CoherentTriangulation.def("Deflection", (Standard_Real (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::Deflection, "Query the Deflection parameter (default value 0. -- if never initialized)");
cls_Poly_CoherentTriangulation.def("SetNode", [](Poly_CoherentTriangulation &self, const gp_XYZ & a0) -> Standard_Integer { return self.SetNode(a0); });
cls_Poly_CoherentTriangulation.def("SetNode", (Standard_Integer (Poly_CoherentTriangulation::*)(const gp_XYZ &, const Standard_Integer)) &Poly_CoherentTriangulation::SetNode, "Initialize a node", py::arg("thePnt"), py::arg("iN"));
cls_Poly_CoherentTriangulation.def("Node", (const Poly_CoherentNode & (Poly_CoherentTriangulation::*)(const Standard_Integer) const) &Poly_CoherentTriangulation::Node, "Get the node at the given index 'i'.", py::arg("i"));
cls_Poly_CoherentTriangulation.def("ChangeNode", (Poly_CoherentNode & (Poly_CoherentTriangulation::*)(const Standard_Integer)) &Poly_CoherentTriangulation::ChangeNode, "Get the node at the given index 'i'.", py::arg("i"));
cls_Poly_CoherentTriangulation.def("NNodes", (Standard_Integer (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::NNodes, "Query the total number of active nodes (i.e. nodes used by 1 or more triangles)");
cls_Poly_CoherentTriangulation.def("Triangle", (const Poly_CoherentTriangle & (Poly_CoherentTriangulation::*)(const Standard_Integer) const) &Poly_CoherentTriangulation::Triangle, "Get the triangle at the given index 'i'.", py::arg("i"));
cls_Poly_CoherentTriangulation.def("NTriangles", (Standard_Integer (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::NTriangles, "Query the total number of active triangles (i.e. triangles that refer nodes, non-empty ones)");
cls_Poly_CoherentTriangulation.def("NLinks", (Standard_Integer (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::NLinks, "Query the total number of active Links.");
cls_Poly_CoherentTriangulation.def("RemoveTriangle", (Standard_Boolean (Poly_CoherentTriangulation::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangulation::RemoveTriangle, "Removal of a single triangle from the triangulation.", py::arg("theTr"));
cls_Poly_CoherentTriangulation.def("RemoveLink", (void (Poly_CoherentTriangulation::*)(Poly_CoherentLink &)) &Poly_CoherentTriangulation::RemoveLink, "Removal of a single link from the triangulation.", py::arg("theLink"));
cls_Poly_CoherentTriangulation.def("AddTriangle", (Poly_CoherentTriangle * (Poly_CoherentTriangulation::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_CoherentTriangulation::AddTriangle, "Add a triangle to the triangulation.", py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));
cls_Poly_CoherentTriangulation.def("ReplaceNodes", (Standard_Boolean (Poly_CoherentTriangulation::*)(Poly_CoherentTriangle &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_CoherentTriangulation::ReplaceNodes, "Replace nodes in the given triangle.", py::arg("theTriangle"), py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));
cls_Poly_CoherentTriangulation.def("AddLink", (Poly_CoherentLink * (Poly_CoherentTriangulation::*)(const Poly_CoherentTriangle &, const Standard_Integer)) &Poly_CoherentTriangulation::AddLink, "Add a single link to triangulation, based on a triangle and its side index. This method does not check for coincidence with already present links.", py::arg("theTri"), py::arg("theConn"));
// cls_Poly_CoherentTriangulation.def("FindTriangle", (Standard_Boolean (Poly_CoherentTriangulation::*)(const Poly_CoherentLink &, const Poly_CoherentTriangle *[2]) const) &Poly_CoherentTriangulation::FindTriangle, "Find one or two triangles that share the given couple of nodes.", py::arg("theLink"), py::arg("pTri"));
cls_Poly_CoherentTriangulation.def("ComputeLinks", (Standard_Integer (Poly_CoherentTriangulation::*)()) &Poly_CoherentTriangulation::ComputeLinks, "(Re)Calculate all links in this Triangulation.");
cls_Poly_CoherentTriangulation.def("ClearLinks", (void (Poly_CoherentTriangulation::*)()) &Poly_CoherentTriangulation::ClearLinks, "Clear all Links data from the Triangulation data.");
cls_Poly_CoherentTriangulation.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::Allocator, "Query the allocator of elements, this allocator can be used for other objects");
cls_Poly_CoherentTriangulation.def("Clone", (opencascade::handle<Poly_CoherentTriangulation> (Poly_CoherentTriangulation::*)(const opencascade::handle<NCollection_BaseAllocator> &) const) &Poly_CoherentTriangulation::Clone, "Create a copy of this Triangulation, using the given allocator.", py::arg("theAlloc"));
cls_Poly_CoherentTriangulation.def("Dump", (void (Poly_CoherentTriangulation::*)(Standard_OStream &) const) &Poly_CoherentTriangulation::Dump, "Debugging output.", py::arg(""));
cls_Poly_CoherentTriangulation.def_static("get_type_name_", (const char * (*)()) &Poly_CoherentTriangulation::get_type_name, "None");
cls_Poly_CoherentTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_CoherentTriangulation::get_type_descriptor, "None");
cls_Poly_CoherentTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_CoherentTriangulation::*)() const) &Poly_CoherentTriangulation::DynamicType, "None");

// Enums

}