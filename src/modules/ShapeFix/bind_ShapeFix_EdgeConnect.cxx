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
#include <TopoDS_Shape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <ShapeFix_EdgeConnect.hxx>

void bind_ShapeFix_EdgeConnect(py::module &mod){

py::class_<ShapeFix_EdgeConnect, std::unique_ptr<ShapeFix_EdgeConnect, Deleter<ShapeFix_EdgeConnect>>> cls_ShapeFix_EdgeConnect(mod, "ShapeFix_EdgeConnect", "Rebuilds edges to connect with new vertices, was moved from ShapeBuild. Makes vertices to be shared to connect edges, updates positions and tolerances for shared vertices. Accepts edges bounded by two vertices each.");

// Constructors
cls_ShapeFix_EdgeConnect.def(py::init<>());

// Fields

// Methods
// cls_ShapeFix_EdgeConnect.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_EdgeConnect::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_EdgeConnect.def_static("operator delete_", (void (*)(void *)) &ShapeFix_EdgeConnect::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_EdgeConnect.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_EdgeConnect::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_EdgeConnect.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_EdgeConnect::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_EdgeConnect.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_EdgeConnect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_EdgeConnect.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_EdgeConnect::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_EdgeConnect.def("Add", (void (ShapeFix_EdgeConnect::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &ShapeFix_EdgeConnect::Add, "Adds information on connectivity between start vertex of second edge and end vertex of first edge, taking edges orientation into account", py::arg("aFirst"), py::arg("aSecond"));
cls_ShapeFix_EdgeConnect.def("Add", (void (ShapeFix_EdgeConnect::*)(const TopoDS_Shape &)) &ShapeFix_EdgeConnect::Add, "Adds connectivity information for the whole shape. Note: edges in wires must be well ordered Note: flag Closed should be set for closed wires", py::arg("aShape"));
cls_ShapeFix_EdgeConnect.def("Build", (void (ShapeFix_EdgeConnect::*)()) &ShapeFix_EdgeConnect::Build, "Builds shared vertices, updates their positions and tolerances");
cls_ShapeFix_EdgeConnect.def("Clear", (void (ShapeFix_EdgeConnect::*)()) &ShapeFix_EdgeConnect::Clear, "Clears internal data structure");

// Enums

}