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
#include <BRep_Builder.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepPrim_FaceBuilder.hxx>

void bind_BRepPrim_FaceBuilder(py::module &mod){

py::class_<BRepPrim_FaceBuilder> cls_BRepPrim_FaceBuilder(mod, "BRepPrim_FaceBuilder", "The FaceBuilder is an algorithm to build a BRep Face from a Geom Surface.");

// Constructors
cls_BRepPrim_FaceBuilder.def(py::init<>());
cls_BRepPrim_FaceBuilder.def(py::init<const BRep_Builder &, const opencascade::handle<Geom_Surface> &>(), py::arg("B"), py::arg("S"));
cls_BRepPrim_FaceBuilder.def(py::init<const BRep_Builder &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));

// Fields

// Methods
// cls_BRepPrim_FaceBuilder.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_FaceBuilder::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_FaceBuilder.def_static("operator delete_", (void (*)(void *)) &BRepPrim_FaceBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_FaceBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_FaceBuilder::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_FaceBuilder.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_FaceBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_FaceBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_FaceBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_FaceBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_FaceBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrim_FaceBuilder.def("Init", (void (BRepPrim_FaceBuilder::*)(const BRep_Builder &, const opencascade::handle<Geom_Surface> &)) &BRepPrim_FaceBuilder::Init, "None", py::arg("B"), py::arg("S"));
cls_BRepPrim_FaceBuilder.def("Init", (void (BRepPrim_FaceBuilder::*)(const BRep_Builder &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepPrim_FaceBuilder::Init, "None", py::arg("B"), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepPrim_FaceBuilder.def("Face", (const TopoDS_Face & (BRepPrim_FaceBuilder::*)() const) &BRepPrim_FaceBuilder::Face, "None");
cls_BRepPrim_FaceBuilder.def("Edge", (const TopoDS_Edge & (BRepPrim_FaceBuilder::*)(const Standard_Integer) const) &BRepPrim_FaceBuilder::Edge, "Returns the edge of index <I> 1 - Edge VMin 2 - Edge UMax 3 - Edge VMax 4 - Edge UMin", py::arg("I"));
cls_BRepPrim_FaceBuilder.def("Vertex", (const TopoDS_Vertex & (BRepPrim_FaceBuilder::*)(const Standard_Integer) const) &BRepPrim_FaceBuilder::Vertex, "Returns the vertex of index <I> 1 - Vertex UMin,VMin 2 - Vertex UMax,VMin 3 - Vertex UMax,VMax 4 - Vertex UMin,VMax", py::arg("I"));

// Enums

}