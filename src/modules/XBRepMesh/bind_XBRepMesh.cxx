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
#include <TopoDS_Shape.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <XBRepMesh.hxx>

void bind_XBRepMesh(py::module &mod){

py::class_<XBRepMesh, std::unique_ptr<XBRepMesh, Deleter<XBRepMesh>>> cls_XBRepMesh(mod, "XBRepMesh", "None");

// Constructors

// Fields

// Methods
// cls_XBRepMesh.def_static("operator new_", (void * (*)(size_t)) &XBRepMesh::operator new, "None", py::arg("theSize"));
// cls_XBRepMesh.def_static("operator delete_", (void (*)(void *)) &XBRepMesh::operator delete, "None", py::arg("theAddress"));
// cls_XBRepMesh.def_static("operator new[]_", (void * (*)(size_t)) &XBRepMesh::operator new[], "None", py::arg("theSize"));
// cls_XBRepMesh.def_static("operator delete[]_", (void (*)(void *)) &XBRepMesh::operator delete[], "None", py::arg("theAddress"));
// cls_XBRepMesh.def_static("operator new_", (void * (*)(size_t, void *)) &XBRepMesh::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XBRepMesh.def_static("operator delete_", (void (*)(void *, void *)) &XBRepMesh::operator delete, "None", py::arg(""), py::arg(""));
// cls_XBRepMesh.def_static("Discret_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, BRepMesh_DiscretRoot *&)) &XBRepMesh::Discret, "None", py::arg("theShape"), py::arg("theDeflection"), py::arg("theAngle"), py::arg("theAlgo"));

// Enums

}