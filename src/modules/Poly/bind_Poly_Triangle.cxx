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
#include <Poly_Triangle.hxx>

void bind_Poly_Triangle(py::module &mod){

py::class_<Poly_Triangle, std::unique_ptr<Poly_Triangle, Deleter<Poly_Triangle>>> cls_Poly_Triangle(mod, "Poly_Triangle", "Describes a component triangle of a triangulation (Poly_Triangulation object). A Triangle is defined by a triplet of nodes. Each node is an index in the table of nodes specific to an existing triangulation of a shape, and represents a point on the surface.");

// Constructors
cls_Poly_Triangle.def(py::init<>());
cls_Poly_Triangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("N1"), py::arg("N2"), py::arg("N3"));

// Fields

// Methods
// cls_Poly_Triangle.def_static("operator new_", (void * (*)(size_t)) &Poly_Triangle::operator new, "None", py::arg("theSize"));
// cls_Poly_Triangle.def_static("operator delete_", (void (*)(void *)) &Poly_Triangle::operator delete, "None", py::arg("theAddress"));
// cls_Poly_Triangle.def_static("operator new[]_", (void * (*)(size_t)) &Poly_Triangle::operator new[], "None", py::arg("theSize"));
// cls_Poly_Triangle.def_static("operator delete[]_", (void (*)(void *)) &Poly_Triangle::operator delete[], "None", py::arg("theAddress"));
// cls_Poly_Triangle.def_static("operator new_", (void * (*)(size_t, void *)) &Poly_Triangle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Poly_Triangle.def_static("operator delete_", (void (*)(void *, void *)) &Poly_Triangle::operator delete, "None", py::arg(""), py::arg(""));
cls_Poly_Triangle.def("Set", (void (Poly_Triangle::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_Triangle::Set, "Sets the value of the three nodes of this triangle to N1, N2 and N3 respectively.", py::arg("N1"), py::arg("N2"), py::arg("N3"));
cls_Poly_Triangle.def("Set", (void (Poly_Triangle::*)(const Standard_Integer, const Standard_Integer)) &Poly_Triangle::Set, "Sets the value of the Indexth node of this triangle to Node. Raises OutOfRange if Index is not in 1,2,3", py::arg("Index"), py::arg("Node"));
cls_Poly_Triangle.def("Get", [](Poly_Triangle &self, Standard_Integer & N1, Standard_Integer & N2, Standard_Integer & N3){ self.Get(N1, N2, N3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(N1, N2, N3); }, "Returns the node indices of this triangle in N1, N2 and N3.", py::arg("N1"), py::arg("N2"), py::arg("N3"));
cls_Poly_Triangle.def("Value", (Standard_Integer (Poly_Triangle::*)(const Standard_Integer) const) &Poly_Triangle::Value, "Get the node of given Index. Raises OutOfRange from Standard if Index is not in 1,2,3", py::arg("Index"));
cls_Poly_Triangle.def("__call__", (Standard_Integer (Poly_Triangle::*)(const Standard_Integer) const) &Poly_Triangle::operator(), py::is_operator(), "None", py::arg("Index"));
cls_Poly_Triangle.def("ChangeValue", (Standard_Integer & (Poly_Triangle::*)(const Standard_Integer)) &Poly_Triangle::ChangeValue, "Get the node of given Index. Raises OutOfRange if Index is not in 1,2,3", py::arg("Index"));
cls_Poly_Triangle.def("__call__", (Standard_Integer & (Poly_Triangle::*)(const Standard_Integer)) &Poly_Triangle::operator(), py::is_operator(), "None", py::arg("Index"));

// Enums

}