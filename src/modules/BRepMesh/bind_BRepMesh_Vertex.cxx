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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <BRepMesh_Vertex.hxx>
#include <Precision.hxx>

void bind_BRepMesh_Vertex(py::module &mod){

py::class_<BRepMesh_Vertex, std::unique_ptr<BRepMesh_Vertex, Deleter<BRepMesh_Vertex>>> cls_BRepMesh_Vertex(mod, "BRepMesh_Vertex", "Light weighted structure representing vertex of the mesh in parametric space. Vertex could be associated with 3d point stored in external map.");

// Constructors
cls_BRepMesh_Vertex.def(py::init<>());
cls_BRepMesh_Vertex.def(py::init<const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom>(), py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
cls_BRepMesh_Vertex.def(py::init<const Standard_Real, const Standard_Real, const BRepMesh_DegreeOfFreedom>(), py::arg("theU"), py::arg("theV"), py::arg("theMovability"));

// Fields

// Methods
// cls_BRepMesh_Vertex.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Vertex::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Vertex.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Vertex::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Vertex.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Vertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Vertex.def("Initialize", (void (BRepMesh_Vertex::*)(const gp_XY &, const Standard_Integer, const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::Initialize, "Initializes vertex associated with point in 3d space.", py::arg("theUV"), py::arg("theLocation3d"), py::arg("theMovability"));
cls_BRepMesh_Vertex.def("Coord", (const gp_XY & (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Coord, "Returns position of the vertex in parametric space.");
cls_BRepMesh_Vertex.def("ChangeCoord", (gp_XY & (BRepMesh_Vertex::*)()) &BRepMesh_Vertex::ChangeCoord, "Returns position of the vertex in parametric space for modification.");
cls_BRepMesh_Vertex.def("Location3d", (Standard_Integer (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Location3d, "Returns index of 3d point associated with the vertex.");
cls_BRepMesh_Vertex.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Vertex::*)() const) &BRepMesh_Vertex::Movability, "Returns movability of the vertex.");
cls_BRepMesh_Vertex.def("SetMovability", (void (BRepMesh_Vertex::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Vertex::SetMovability, "Sets movability of the vertex.", py::arg("theMovability"));
cls_BRepMesh_Vertex.def("HashCode", (Standard_Integer (BRepMesh_Vertex::*)(const Standard_Integer) const) &BRepMesh_Vertex::HashCode, "Returns hash code for this vertex.", py::arg("Upper"));
cls_BRepMesh_Vertex.def("IsEqual", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const) &BRepMesh_Vertex::IsEqual, "Checks for equality with another vertex.", py::arg("theOther"));
cls_BRepMesh_Vertex.def("__eq__", (Standard_Boolean (BRepMesh_Vertex::*)(const BRepMesh_Vertex &) const) &BRepMesh_Vertex::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// Enums

}