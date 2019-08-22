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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepLib_MakePolygon.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

void bind_BRepBuilderAPI_MakePolygon(py::module &mod){

py::class_<BRepBuilderAPI_MakePolygon, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakePolygon(mod, "BRepBuilderAPI_MakePolygon", "Describes functions to build polygonal wires. A polygonal wire can be built from any number of points or vertices, and consists of a sequence of connected rectilinear edges. When a point or vertex is added to the polygon if it is identic to the previous point no edge is built. The method added can be used to test it. Construction of a Polygonal Wire You can construct: - a complete polygonal wire by defining all its points or vertices (limited to four), or - an empty polygonal wire and add its points or vertices in sequence (unlimited number). A MakePolygon object provides a framework for: - initializing the construction of a polygonal wire, - adding points or vertices to the polygonal wire under construction, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakePolygon.def(py::init<>());
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("Close"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakePolygon::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakePolygon::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakePolygon::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakePolygon::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakePolygon::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakePolygon::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakePolygon.def("Add", (void (BRepBuilderAPI_MakePolygon::*)(const gp_Pnt &)) &BRepBuilderAPI_MakePolygon::Add, "None", py::arg("P"));
cls_BRepBuilderAPI_MakePolygon.def("Add", (void (BRepBuilderAPI_MakePolygon::*)(const TopoDS_Vertex &)) &BRepBuilderAPI_MakePolygon::Add, "Adds the point P or the vertex V at the end of the polygonal wire under construction. A vertex is automatically created on the point P. Warning - When P or V is coincident to the previous vertex, no edge is built. The method Added can be used to test for this. Neither P nor V is checked to verify that it is coincident with another vertex than the last one, of the polygonal wire under construction. It is also possible to add vertices on a closed polygon (built for example by using a constructor which declares the polygon closed, or after the use of the Close function). Consequently, be careful using this function: you might create: - a polygonal wire with two consecutive coincident edges, or - a non manifold polygonal wire. - P or V is not checked to verify if it is coincident with another vertex but the last one, of the polygonal wire under construction. It is also possible to add vertices on a closed polygon (built for example by using a constructor which declares the polygon closed, or after the use of the Close function). Consequently, be careful when using this function: you might create: - a polygonal wire with two consecutive coincident edges, or - a non-manifold polygonal wire.", py::arg("V"));
cls_BRepBuilderAPI_MakePolygon.def("Added", (Standard_Boolean (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::Added, "Returns true if the last vertex added to the constructed polygonal wire is not coincident with the previous one.");
cls_BRepBuilderAPI_MakePolygon.def("Close", (void (BRepBuilderAPI_MakePolygon::*)()) &BRepBuilderAPI_MakePolygon::Close, "Closes the polygonal wire under construction. Note - this is equivalent to adding the first vertex to the polygonal wire under construction.");
cls_BRepBuilderAPI_MakePolygon.def("FirstVertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::FirstVertex, "None");
cls_BRepBuilderAPI_MakePolygon.def("LastVertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::LastVertex, "Returns the first or the last vertex of the polygonal wire under construction. If the constructed polygonal wire is closed, the first and the last vertices are identical.");
cls_BRepBuilderAPI_MakePolygon.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::IsDone, "Returns true if this algorithm contains a valid polygonal wire (i.e. if there is at least one edge). IsDone returns false if fewer than two vertices have been chained together by this construction algorithm.");
cls_BRepBuilderAPI_MakePolygon.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::Edge, "Returns the edge built between the last two points or vertices added to the constructed polygonal wire under construction. Warning If there is only one vertex in the polygonal wire, the result is a null edge.");
cls_BRepBuilderAPI_MakePolygon.def("Wire", (const TopoDS_Wire & (BRepBuilderAPI_MakePolygon::*)()) &BRepBuilderAPI_MakePolygon::Wire, "Returns the constructed polygonal wire, or the already built part of the polygonal wire under construction. Exceptions StdFail_NotDone if the wire is not built, i.e. if fewer than two vertices have been chained together by this construction algorithm.");

// Enums

}