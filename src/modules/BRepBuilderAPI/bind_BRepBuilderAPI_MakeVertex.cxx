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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepLib_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>

void bind_BRepBuilderAPI_MakeVertex(py::module &mod){

py::class_<BRepBuilderAPI_MakeVertex, std::unique_ptr<BRepBuilderAPI_MakeVertex, Deleter<BRepBuilderAPI_MakeVertex>>, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeVertex(mod, "BRepBuilderAPI_MakeVertex", "Describes functions to build BRepBuilder vertices directly from 3D geometric points. A vertex built using a MakeVertex object is only composed of a 3D point and a default precision value (Precision::Confusion()). Later on, 2D representations can be added, for example, when inserting a vertex in an edge. A MakeVertex object provides a framework for: - defining and implementing the construction of a vertex, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeVertex.def(py::init<const gp_Pnt &>(), py::arg("P"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeVertex::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeVertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeVertex::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeVertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeVertex.def("Vertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakeVertex::*)()) &BRepBuilderAPI_MakeVertex::Vertex, "Returns the constructed vertex.");

// Enums

}