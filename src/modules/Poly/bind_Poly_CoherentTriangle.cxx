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
#include <Standard_TypeDef.hxx>
#include <Poly_CoherentTriangle.hxx>
#include <Poly_CoherentLink.hxx>
#include <Poly_CoherentTriangulation.hxx>

void bind_Poly_CoherentTriangle(py::module &mod){

py::class_<Poly_CoherentTriangle, std::unique_ptr<Poly_CoherentTriangle>> cls_Poly_CoherentTriangle(mod, "Poly_CoherentTriangle", "Data class used in Poly_CoherentTriangultion. Implements a triangle with references to its neighbours.");

// Constructors
cls_Poly_CoherentTriangle.def(py::init<>());
cls_Poly_CoherentTriangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));

// Fields

// Methods
cls_Poly_CoherentTriangle.def("Node", (Standard_Integer (Poly_CoherentTriangle::*)(const Standard_Integer) const) &Poly_CoherentTriangle::Node, "Query the node index in the position given by the parameter 'ind'", py::arg("ind"));
cls_Poly_CoherentTriangle.def("IsEmpty", (Standard_Boolean (Poly_CoherentTriangle::*)() const) &Poly_CoherentTriangle::IsEmpty, "Query if this is a valid triangle.");
cls_Poly_CoherentTriangle.def("SetConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(const Standard_Integer, Poly_CoherentTriangle &)) &Poly_CoherentTriangle::SetConnection, "Create connection with another triangle theTri. This method creates both connections: in this triangle and in theTri. You do not need to call the same method on triangle theTr.", py::arg("iConn"), py::arg("theTr"));
cls_Poly_CoherentTriangle.def("SetConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangle::SetConnection, "Create connection with another triangle theTri. This method creates both connections: in this triangle and in theTri. This method is slower than the previous one, because it makes analysis what sides of both triangles are connected.", py::arg("theTri"));
cls_Poly_CoherentTriangle.def("RemoveConnection", (void (Poly_CoherentTriangle::*)(const Standard_Integer)) &Poly_CoherentTriangle::RemoveConnection, "Remove the connection with the given index.", py::arg("iConn"));
cls_Poly_CoherentTriangle.def("RemoveConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangle::RemoveConnection, "Remove the connection with the given Triangle.", py::arg("theTri"));
cls_Poly_CoherentTriangle.def("NConnections", (Standard_Integer (Poly_CoherentTriangle::*)() const) &Poly_CoherentTriangle::NConnections, "Query the number of connected triangles.");
cls_Poly_CoherentTriangle.def("GetConnectedNode", (Standard_Integer (Poly_CoherentTriangle::*)(const Standard_Integer) const) &Poly_CoherentTriangle::GetConnectedNode, "Query the connected node on the given side. Returns -1 if there is no connection on the specified side.", py::arg("iConn"));
cls_Poly_CoherentTriangle.def("GetConnectedTri", (const Poly_CoherentTriangle * (Poly_CoherentTriangle::*)(const Standard_Integer) const) &Poly_CoherentTriangle::GetConnectedTri, "Query the connected triangle on the given side. Returns NULL if there is no connection on the specified side.", py::arg("iConn"));
cls_Poly_CoherentTriangle.def("GetLink", (const Poly_CoherentLink * (Poly_CoherentTriangle::*)(const Standard_Integer) const) &Poly_CoherentTriangle::GetLink, "Query the Link associate with the given side of the Triangle. May return NULL if there are no links in the triangulation.", py::arg("iLink"));
cls_Poly_CoherentTriangle.def("FindConnection", (Standard_Integer (Poly_CoherentTriangle::*)(const Poly_CoherentTriangle &) const) &Poly_CoherentTriangle::FindConnection, "Retuns the index of the connection with the given triangle, or -1 if not found.", py::arg(""));

// Enums

}