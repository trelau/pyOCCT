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
#include <BRepMesh_OrientedEdge.hxx>

void bind_BRepMesh_OrientedEdge(py::module &mod){

py::class_<BRepMesh_OrientedEdge, std::unique_ptr<BRepMesh_OrientedEdge, Deleter<BRepMesh_OrientedEdge>>> cls_BRepMesh_OrientedEdge(mod, "BRepMesh_OrientedEdge", "Light weighted structure representing simple link.");

// Constructors
cls_BRepMesh_OrientedEdge.def(py::init<>());
cls_BRepMesh_OrientedEdge.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theFirstNode"), py::arg("theLastNode"));

// Fields

// Methods
// cls_BRepMesh_OrientedEdge.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_OrientedEdge::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete_", (void (*)(void *)) &BRepMesh_OrientedEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_OrientedEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_OrientedEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_OrientedEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_OrientedEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_OrientedEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_OrientedEdge.def("FirstNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const) &BRepMesh_OrientedEdge::FirstNode, "Returns index of first node of the Link.");
cls_BRepMesh_OrientedEdge.def("LastNode", (Standard_Integer (BRepMesh_OrientedEdge::*)() const) &BRepMesh_OrientedEdge::LastNode, "Returns index of last node of the Link.");
cls_BRepMesh_OrientedEdge.def("HashCode", (Standard_Integer (BRepMesh_OrientedEdge::*)(const Standard_Integer) const) &BRepMesh_OrientedEdge::HashCode, "Returns hash code for this edge.", py::arg("theUpper"));
cls_BRepMesh_OrientedEdge.def("IsEqual", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const) &BRepMesh_OrientedEdge::IsEqual, "Checks this and other edge for equality.", py::arg("theOther"));
cls_BRepMesh_OrientedEdge.def("__eq__", (Standard_Boolean (BRepMesh_OrientedEdge::*)(const BRepMesh_OrientedEdge &) const) &BRepMesh_OrientedEdge::operator==, py::is_operator(), "Alias for IsEqual.", py::arg("Other"));

// Enums

}