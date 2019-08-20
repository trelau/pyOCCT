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
#include <BRepLib_MakeShape.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepLib_MakeVertex.hxx>

void bind_BRepLib_MakeVertex(py::module &mod){

py::class_<BRepLib_MakeVertex, std::unique_ptr<BRepLib_MakeVertex>, BRepLib_MakeShape> cls_BRepLib_MakeVertex(mod, "BRepLib_MakeVertex", "Provides methods to build vertices.");

// Constructors
cls_BRepLib_MakeVertex.def(py::init<const gp_Pnt &>(), py::arg("P"));

// Fields

// Methods
// cls_BRepLib_MakeVertex.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeVertex::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeVertex.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeVertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeVertex::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeVertex.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeVertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeVertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeVertex.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeVertex::*)()) &BRepLib_MakeVertex::Vertex, "None");

// Enums

}