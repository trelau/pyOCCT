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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepLib_MakePolygon.hxx>

void bind_BRepLib_MakePolygon(py::module &mod){

py::class_<BRepLib_MakePolygon, BRepLib_MakeShape> cls_BRepLib_MakePolygon(mod, "BRepLib_MakePolygon", "Class to build polygonal wires.");

// Constructors
cls_BRepLib_MakePolygon.def(py::init<>());
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_BRepLib_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("Close"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"));
cls_BRepLib_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("Close"));

// Fields

// Methods
// cls_BRepLib_MakePolygon.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakePolygon::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakePolygon.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakePolygon::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakePolygon::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakePolygon.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakePolygon::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakePolygon::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakePolygon.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakePolygon::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const gp_Pnt &)) &BRepLib_MakePolygon::Add, "None", py::arg("P"));
cls_BRepLib_MakePolygon.def("Add", (void (BRepLib_MakePolygon::*)(const TopoDS_Vertex &)) &BRepLib_MakePolygon::Add, "None", py::arg("V"));
cls_BRepLib_MakePolygon.def("Added", (Standard_Boolean (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::Added, "Returns True if the last vertex or point was succesfully added.");
cls_BRepLib_MakePolygon.def("Close", (void (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Close, "None");
cls_BRepLib_MakePolygon.def("FirstVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::FirstVertex, "None");
cls_BRepLib_MakePolygon.def("LastVertex", (const TopoDS_Vertex & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::LastVertex, "None");
cls_BRepLib_MakePolygon.def("Edge", (const TopoDS_Edge & (BRepLib_MakePolygon::*)() const) &BRepLib_MakePolygon::Edge, "Returns the last edge added to the polygon.");
cls_BRepLib_MakePolygon.def("Wire", (const TopoDS_Wire & (BRepLib_MakePolygon::*)()) &BRepLib_MakePolygon::Wire, "None");

// Enums

}