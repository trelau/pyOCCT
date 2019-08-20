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
#include <Standard_Handle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <BRepMesh_PairOfPolygon.hxx>

void bind_BRepMesh_PairOfPolygon(py::module &mod){

py::class_<BRepMesh_PairOfPolygon, std::unique_ptr<BRepMesh_PairOfPolygon>> cls_BRepMesh_PairOfPolygon(mod, "BRepMesh_PairOfPolygon", "None");

// Constructors
cls_BRepMesh_PairOfPolygon.def(py::init<>());

// Fields

// Methods
// cls_BRepMesh_PairOfPolygon.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_PairOfPolygon::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_PairOfPolygon.def_static("operator delete_", (void (*)(void *)) &BRepMesh_PairOfPolygon::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_PairOfPolygon.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_PairOfPolygon::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_PairOfPolygon.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_PairOfPolygon::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_PairOfPolygon.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_PairOfPolygon::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_PairOfPolygon.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_PairOfPolygon::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_PairOfPolygon.def("Clear", (void (BRepMesh_PairOfPolygon::*)()) &BRepMesh_PairOfPolygon::Clear, "Clears pair handles.");
cls_BRepMesh_PairOfPolygon.def("Prepend", (void (BRepMesh_PairOfPolygon::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepMesh_PairOfPolygon::Prepend, "Sets the first element of the pair. If last element is empty, also assignes the given polygon to it.", py::arg("thePolygon"));
cls_BRepMesh_PairOfPolygon.def("Append", (void (BRepMesh_PairOfPolygon::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepMesh_PairOfPolygon::Append, "Sets the last element of the pair. If first element is empty, also assignes the given polygon to it.", py::arg("thePolygon"));
cls_BRepMesh_PairOfPolygon.def("First", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRepMesh_PairOfPolygon::*)() const) &BRepMesh_PairOfPolygon::First, "Returns first polygon on triangulation.");
cls_BRepMesh_PairOfPolygon.def("Last", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRepMesh_PairOfPolygon::*)() const) &BRepMesh_PairOfPolygon::Last, "Returns last polygon on triangulation.");

// Enums

}