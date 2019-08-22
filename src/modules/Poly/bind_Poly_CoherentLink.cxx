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
#include <Poly_CoherentTriangulation.hxx>
#include <Poly_CoherentLink.hxx>

void bind_Poly_CoherentLink(py::module &mod){

py::class_<Poly_CoherentLink> cls_Poly_CoherentLink(mod, "Poly_CoherentLink", "Link between two mesh nodes that is created by existing triangle(s). Keeps reference to the opposite node of each incident triangle. The referred node with index '0' is always on the left side of the link, the one with the index '1' is always on the right side. It is possible to find both incident triangles using the method Poly_CoherentTriangulation::FindTriangle(). Any Link can store an arbitrary pointer that is called Attribute.");

// Constructors
cls_Poly_CoherentLink.def(py::init<>());
cls_Poly_CoherentLink.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("iNode0"), py::arg("iNode1"));
cls_Poly_CoherentLink.def(py::init<const Poly_CoherentTriangle &, Standard_Integer>(), py::arg("theTri"), py::arg("iSide"));

// Fields

// Methods
cls_Poly_CoherentLink.def("Node", (Standard_Integer (Poly_CoherentLink::*)(const Standard_Integer) const) &Poly_CoherentLink::Node, "Return the node index in the current triangulation.", py::arg("ind"));
cls_Poly_CoherentLink.def("OppositeNode", (Standard_Integer (Poly_CoherentLink::*)(const Standard_Integer) const) &Poly_CoherentLink::OppositeNode, "Return the opposite node (belonging to the left or right incident triangle) index in the current triangulation.", py::arg("ind"));
cls_Poly_CoherentLink.def("GetAttribute", (Standard_Address (Poly_CoherentLink::*)() const) &Poly_CoherentLink::GetAttribute, "Query the attribute of the Link.");
cls_Poly_CoherentLink.def("SetAttribute", (void (Poly_CoherentLink::*)(const Standard_Address)) &Poly_CoherentLink::SetAttribute, "Set the attribute of the Link.", py::arg("theAtt"));
cls_Poly_CoherentLink.def("IsEmpty", (Standard_Boolean (Poly_CoherentLink::*)() const) &Poly_CoherentLink::IsEmpty, "Query the status of the link - if it is an invalid one. An invalid link has Node members equal to -1.");
cls_Poly_CoherentLink.def("Nullify", (void (Poly_CoherentLink::*)()) &Poly_CoherentLink::Nullify, "Invalidate this Link.");

// Enums

}