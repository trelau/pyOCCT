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
#include <BRepPrim_Builder.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepPrim_Direction.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Lin.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BRepPrim_GWedge.hxx>

void bind_BRepPrim_GWedge(py::module &mod){

py::class_<BRepPrim_GWedge, std::unique_ptr<BRepPrim_GWedge, Deleter<BRepPrim_GWedge>>> cls_BRepPrim_GWedge(mod, "BRepPrim_GWedge", "A wedge is defined by :");

// Constructors
cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("xmin"), py::arg("ymin"), py::arg("zmin"), py::arg("z2min"), py::arg("x2min"), py::arg("xmax"), py::arg("ymax"), py::arg("zmax"), py::arg("z2max"), py::arg("x2max"));

// Fields

// Methods
// cls_BRepPrim_GWedge.def_static("operator new_", (void * (*)(size_t)) &BRepPrim_GWedge::operator new, "None", py::arg("theSize"));
// cls_BRepPrim_GWedge.def_static("operator delete_", (void (*)(void *)) &BRepPrim_GWedge::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrim_GWedge.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrim_GWedge::operator new[], "None", py::arg("theSize"));
// cls_BRepPrim_GWedge.def_static("operator delete[]_", (void (*)(void *)) &BRepPrim_GWedge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrim_GWedge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrim_GWedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrim_GWedge.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrim_GWedge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrim_GWedge.def("Axes", (gp_Ax2 (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::Axes, "Returns the coordinates system from <me>.");
cls_BRepPrim_GWedge.def("GetXMin", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetXMin, "Returns Xmin value from <me>.");
cls_BRepPrim_GWedge.def("GetYMin", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetYMin, "Returns YMin value from <me>.");
cls_BRepPrim_GWedge.def("GetZMin", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetZMin, "Returns ZMin value from <me>.");
cls_BRepPrim_GWedge.def("GetZ2Min", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetZ2Min, "Returns Z2Min value from <me>.");
cls_BRepPrim_GWedge.def("GetX2Min", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetX2Min, "Returns X2Min value from <me>.");
cls_BRepPrim_GWedge.def("GetXMax", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetXMax, "Returns XMax value from <me>.");
cls_BRepPrim_GWedge.def("GetYMax", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetYMax, "Returns YMax value from <me>.");
cls_BRepPrim_GWedge.def("GetZMax", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetZMax, "Returns ZMax value from <me>.");
cls_BRepPrim_GWedge.def("GetZ2Max", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetZ2Max, "Returns Z2Max value from <me>.");
cls_BRepPrim_GWedge.def("GetX2Max", (Standard_Real (BRepPrim_GWedge::*)() const) &BRepPrim_GWedge::GetX2Max, "Returns X2Max value from <me>.");
cls_BRepPrim_GWedge.def("Open", (void (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Open, "Opens <me> in <d1> direction. A face and its edges or vertices are said nonexistant.", py::arg("d1"));
cls_BRepPrim_GWedge.def("Close", (void (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Close, "Closes <me> in <d1> direction. A face and its edges or vertices are said existant.", py::arg("d1"));
cls_BRepPrim_GWedge.def("IsInfinite", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const) &BRepPrim_GWedge::IsInfinite, "Returns True if <me> is open in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("Shell", (const TopoDS_Shell & (BRepPrim_GWedge::*)()) &BRepPrim_GWedge::Shell, "Returns the Shell containing the Faces of <me>.");
cls_BRepPrim_GWedge.def("HasFace", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const) &BRepPrim_GWedge::HasFace, "Returns True if <me> has a Face in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("Face", (const TopoDS_Face & (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Face, "Returns the Face of <me> located in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("Plane", (gp_Pln (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Plane, "Returns the plane of the Face of <me> located in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("HasWire", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const) &BRepPrim_GWedge::HasWire, "Returns True if <me> has a Wire in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("Wire", (const TopoDS_Wire & (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Wire, "Returns the Wire of <me> located in <d1> direction.", py::arg("d1"));
cls_BRepPrim_GWedge.def("HasEdge", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction) const) &BRepPrim_GWedge::HasEdge, "Returns True if <me> has an Edge in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
cls_BRepPrim_GWedge.def("Edge", (const TopoDS_Edge & (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Edge, "Returns the Edge of <me> located in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
cls_BRepPrim_GWedge.def("Line", (gp_Lin (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Line, "Returns the line of the Edge of <me> located in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
cls_BRepPrim_GWedge.def("HasVertex", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction) const) &BRepPrim_GWedge::HasVertex, "Returns True if <me> has a Vertex in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));
cls_BRepPrim_GWedge.def("Vertex", (const TopoDS_Vertex & (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Vertex, "Returns the Vertex of <me> located in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));
cls_BRepPrim_GWedge.def("Point", (gp_Pnt (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Point, "Returns the point of the Vertex of <me> located in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));

// Enums

}