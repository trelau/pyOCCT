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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <BRepTools_Quilt.hxx>

void bind_BRepTools_Quilt(py::module &mod){

py::class_<BRepTools_Quilt, std::unique_ptr<BRepTools_Quilt>> cls_BRepTools_Quilt(mod, "BRepTools_Quilt", "A Tool to glue faces at common edges and reconstruct shells.");

// Constructors
cls_BRepTools_Quilt.def(py::init<>());

// Fields

// Methods
// cls_BRepTools_Quilt.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Quilt::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Quilt.def_static("operator delete_", (void (*)(void *)) &BRepTools_Quilt::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Quilt::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Quilt.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Quilt::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Quilt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Quilt::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Quilt.def("Bind", (void (BRepTools_Quilt::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepTools_Quilt::Bind, "Binds <Enew> to be the new edge instead of <Eold>.", py::arg("Eold"), py::arg("Enew"));
cls_BRepTools_Quilt.def("Bind", (void (BRepTools_Quilt::*)(const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepTools_Quilt::Bind, "Binds <VNew> to be a new vertex instead of <Vold>.", py::arg("Vold"), py::arg("Vnew"));
cls_BRepTools_Quilt.def("Add", (void (BRepTools_Quilt::*)(const TopoDS_Shape &)) &BRepTools_Quilt::Add, "Add the faces of <S> to the Quilt, the faces containing bounded edges are copied.", py::arg("S"));
cls_BRepTools_Quilt.def("IsCopied", (Standard_Boolean (BRepTools_Quilt::*)(const TopoDS_Shape &) const) &BRepTools_Quilt::IsCopied, "Returns True if <S> has been copied (<S> is a vertex, an edge or a face)", py::arg("S"));
cls_BRepTools_Quilt.def("Copy", (const TopoDS_Shape & (BRepTools_Quilt::*)(const TopoDS_Shape &) const) &BRepTools_Quilt::Copy, "Returns the shape substitued to <S> in the Quilt.", py::arg("S"));
cls_BRepTools_Quilt.def("Shells", (TopoDS_Shape (BRepTools_Quilt::*)() const) &BRepTools_Quilt::Shells, "Returns a Compound of shells made from the current set of faces. The shells will be flagged as closed or not closed.");

// Enums

}