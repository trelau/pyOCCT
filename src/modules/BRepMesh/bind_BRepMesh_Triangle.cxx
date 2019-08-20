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
#include <Standard_TypeDef.hxx>
#include <BRepMesh_DegreeOfFreedom.hxx>
#include <BRepMesh_Triangle.hxx>

void bind_BRepMesh_Triangle(py::module &mod){

py::class_<BRepMesh_Triangle, std::unique_ptr<BRepMesh_Triangle>> cls_BRepMesh_Triangle(mod, "BRepMesh_Triangle", "Light weighted structure representing triangle of mesh consisting of oriented links.");

// Constructors
cls_BRepMesh_Triangle.def(py::init<>());
// cls_BRepMesh_Triangle.def(py::init<const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom>(), py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));

// Fields

// Methods
// cls_BRepMesh_Triangle.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Triangle::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Triangle.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Triangle::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Triangle::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Triangle.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Triangle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Triangle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Triangle.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Triangle::operator delete, "None", py::arg(""), py::arg(""));
// cls_BRepMesh_Triangle.def("Initialize", (void (BRepMesh_Triangle::*)(const Standard_Integer (&)[3], const Standard_Boolean (&)[3], const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::Initialize, "Initializes the triangle by the given parameters.", py::arg("theEdges"), py::arg("theOrientations"), py::arg("theMovability"));
// cls_BRepMesh_Triangle.def("Edges", (void (BRepMesh_Triangle::*)(Standard_Integer (&)[3], Standard_Boolean (&)[3]) const) &BRepMesh_Triangle::Edges, "Gets edges with orientations composing the triangle.", py::arg("theEdges"), py::arg("theOrientations"));
cls_BRepMesh_Triangle.def("Movability", (BRepMesh_DegreeOfFreedom (BRepMesh_Triangle::*)() const) &BRepMesh_Triangle::Movability, "Returns movability of the triangle.");
cls_BRepMesh_Triangle.def("SetMovability", (void (BRepMesh_Triangle::*)(const BRepMesh_DegreeOfFreedom)) &BRepMesh_Triangle::SetMovability, "Sets movability of the triangle.", py::arg("theMovability"));
cls_BRepMesh_Triangle.def("HashCode", (Standard_Integer (BRepMesh_Triangle::*)(const Standard_Integer) const) &BRepMesh_Triangle::HashCode, "Returns hash code for this triangle.", py::arg("theUpper"));
cls_BRepMesh_Triangle.def("IsEqual", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const) &BRepMesh_Triangle::IsEqual, "Checks for equality with another triangle.", py::arg("theOther"));
cls_BRepMesh_Triangle.def("__eq__", (Standard_Boolean (BRepMesh_Triangle::*)(const BRepMesh_Triangle &) const) &BRepMesh_Triangle::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("theOther"));

// Enums

}