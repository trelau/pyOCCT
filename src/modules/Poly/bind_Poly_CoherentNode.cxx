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
#include <gp_XYZ.hxx>
#include <Precision.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Poly_CoherentTriangle.hxx>
#include <Poly_CoherentTriPtr.hxx>
#include <Standard_OStream.hxx>
#include <Poly_CoherentNode.hxx>

void bind_Poly_CoherentNode(py::module &mod){

py::class_<Poly_CoherentNode, std::unique_ptr<Poly_CoherentNode, Deleter<Poly_CoherentNode>>, gp_XYZ> cls_Poly_CoherentNode(mod, "Poly_CoherentNode", "Node of coherent triangulation. Contains: Coordinates of a 3D point defining the node location 2D point coordinates List of triangles that use this Node Integer index, normally the index of the node in the original triangulation");

// Constructors
cls_Poly_CoherentNode.def(py::init<>());
cls_Poly_CoherentNode.def(py::init<const gp_XYZ &>(), py::arg("thePnt"));

// Fields

// Methods
cls_Poly_CoherentNode.def("SetUV", (void (Poly_CoherentNode::*)(const Standard_Real, const Standard_Real)) &Poly_CoherentNode::SetUV, "Set the UV coordinates of the Node.", py::arg("theU"), py::arg("theV"));
cls_Poly_CoherentNode.def("GetU", (Standard_Real (Poly_CoherentNode::*)() const) &Poly_CoherentNode::GetU, "Get U coordinate of the Node.");
cls_Poly_CoherentNode.def("GetV", (Standard_Real (Poly_CoherentNode::*)() const) &Poly_CoherentNode::GetV, "Get V coordinate of the Node.");
cls_Poly_CoherentNode.def("SetNormal", (void (Poly_CoherentNode::*)(const gp_XYZ &)) &Poly_CoherentNode::SetNormal, "Define the normal vector in the Node.", py::arg("theVector"));
cls_Poly_CoherentNode.def("HasNormal", (Standard_Boolean (Poly_CoherentNode::*)() const) &Poly_CoherentNode::HasNormal, "Query if the Node contains a normal vector.");
cls_Poly_CoherentNode.def("GetNormal", (gp_XYZ (Poly_CoherentNode::*)() const) &Poly_CoherentNode::GetNormal, "Get the stored normal in the node.");
cls_Poly_CoherentNode.def("SetIndex", (void (Poly_CoherentNode::*)(const Standard_Integer)) &Poly_CoherentNode::SetIndex, "Set the value of node Index.", py::arg("theIndex"));
cls_Poly_CoherentNode.def("GetIndex", (Standard_Integer (Poly_CoherentNode::*)() const) &Poly_CoherentNode::GetIndex, "Get the value of node Index.");
cls_Poly_CoherentNode.def("IsFreeNode", (Standard_Boolean (Poly_CoherentNode::*)() const) &Poly_CoherentNode::IsFreeNode, "Check if this is a free node, i.e., a node without a single incident triangle.");
cls_Poly_CoherentNode.def("Clear", (void (Poly_CoherentNode::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::Clear, "Reset the Node to void.", py::arg(""));
cls_Poly_CoherentNode.def("AddTriangle", (void (Poly_CoherentNode::*)(const Poly_CoherentTriangle &, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::AddTriangle, "Connect a triangle to this Node.", py::arg("theTri"), py::arg("theA"));
cls_Poly_CoherentNode.def("RemoveTriangle", (Standard_Boolean (Poly_CoherentNode::*)(const Poly_CoherentTriangle &, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::RemoveTriangle, "Disconnect a triangle from this Node.", py::arg("theTri"), py::arg("theA"));
cls_Poly_CoherentNode.def("TriangleIterator", (Poly_CoherentTriPtr::Iterator (Poly_CoherentNode::*)() const) &Poly_CoherentNode::TriangleIterator, "Create an iterator of incident triangles.");
cls_Poly_CoherentNode.def("Dump", (void (Poly_CoherentNode::*)(Standard_OStream &) const) &Poly_CoherentNode::Dump, "None", py::arg("theStream"));

// Enums

}