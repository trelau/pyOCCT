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
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <BRepBuilderAPI_EdgeError.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

void bind_BRepBuilderAPI_MakeEdge(py::module &mod){

py::class_<BRepBuilderAPI_MakeEdge, std::unique_ptr<BRepBuilderAPI_MakeEdge>, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeEdge(mod, "BRepBuilderAPI_MakeEdge", "Provides methods to build edges.");

// Constructors
cls_BRepBuilderAPI_MakeEdge.def(py::init<>());
cls_BRepBuilderAPI_MakeEdge.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("L"), py::arg("S"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "Defines or redefines the arguments for the construction of an edge. This function is currently used after the empty constructor BRepAPI_MakeEdge().", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::IsDone, "Returns true if the edge is built.");
cls_BRepBuilderAPI_MakeEdge.def("Error", (BRepBuilderAPI_EdgeError (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Error, "Returns the construction status - BRepBuilderAPI_EdgeDone if the edge is built, or - another value of the BRepBuilderAPI_EdgeError enumeration indicating the reason of construction failure.");
cls_BRepBuilderAPI_MakeEdge.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakeEdge::*)()) &BRepBuilderAPI_MakeEdge::Edge, "Returns the constructed edge. Exceptions StdFail_NotDone if the edge is not built.");
cls_BRepBuilderAPI_MakeEdge.def("Vertex1", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepBuilderAPI_MakeEdge.def("Vertex2", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Vertex2, "Returns the second vertex of the edge. May be Null.");

// Enums

}