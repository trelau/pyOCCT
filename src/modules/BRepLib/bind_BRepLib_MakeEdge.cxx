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
#include <BRepLib_EdgeError.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepLib_MakeEdge.hxx>

void bind_BRepLib_MakeEdge(py::module &mod){

py::class_<BRepLib_MakeEdge, std::unique_ptr<BRepLib_MakeEdge, Deleter<BRepLib_MakeEdge>>, BRepLib_MakeShape> cls_BRepLib_MakeEdge(mod, "BRepLib_MakeEdge", "Provides methods to build edges.");

// Constructors
cls_BRepLib_MakeEdge.def(py::init<>());
cls_BRepLib_MakeEdge.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Lin &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Circ &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Elips &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Hypr &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const gp_Parab &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("L"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("L"), py::arg("S"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Fields

// Methods
// cls_BRepLib_MakeEdge.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeEdge::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Init", (void (BRepLib_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepLib_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepLib_MakeEdge.def("Error", (BRepLib_EdgeError (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Error, "Returns the error description when NotDone.");
cls_BRepLib_MakeEdge.def("Edge", (const TopoDS_Edge & (BRepLib_MakeEdge::*)()) &BRepLib_MakeEdge::Edge, "None");
cls_BRepLib_MakeEdge.def("Vertex1", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepLib_MakeEdge.def("Vertex2", (const TopoDS_Vertex & (BRepLib_MakeEdge::*)() const) &BRepLib_MakeEdge::Vertex2, "Returns the second vertex of the edge. May be Null.");

// Enums

}