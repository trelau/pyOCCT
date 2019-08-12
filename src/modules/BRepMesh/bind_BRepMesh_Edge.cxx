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
#include <BRepMesh_OrientedEdge.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <BRepMesh_Edge.hxx>

void bind_BRepMesh_Edge(py::module &mod){

py::class_<BRepMesh_Edge, std::unique_ptr<BRepMesh_Edge, Deleter<BRepMesh_Edge>>, BRepMesh_OrientedEdge> cls_BRepMesh_Edge(mod, "BRepMesh_Edge", "Light weighted structure representing link of the mesh.");

// Constructors
cls_BRepMesh_Edge.def(py::init<>());
cls_BRepMesh_Edge.def(py::init<const Standard_Integer, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theFirstNode"), py::arg("theLastNode"), py::arg("theMovability"));

// Fields

// Methods
cls_BRepMesh_Edge.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Edge::*)() const) &BRepMesh_Edge::Movability, "Returns movability flag of the Link.");
cls_BRepMesh_Edge.def("SetMovability", (void (BRepMesh_Edge::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Edge::SetMovability, "Sets movability flag of the Link.", py::arg("theMovability"));
cls_BRepMesh_Edge.def("IsSameOrientation", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::IsSameOrientation, "Checks if the given edge and this one have the same orientation.", py::arg("theOther"));
cls_BRepMesh_Edge.def("IsEqual", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::IsEqual, "Checks for equality with another edge.", py::arg("theOther"));
cls_BRepMesh_Edge.def("__eq__", (Standard_Boolean (BRepMesh_Edge::*)(const BRepMesh_Edge &) const) &BRepMesh_Edge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// Enums

}