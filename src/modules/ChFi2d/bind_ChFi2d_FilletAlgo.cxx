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
#include <TopoDS_Wire.hxx>
#include <gp_Pln.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <ChFi2d_FilletAlgo.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <Geom2d_Curve.hxx>
#include <TColStd_ListOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_ChFi2d_FilletAlgo(py::module &mod){

py::class_<ChFi2d_FilletAlgo, std::unique_ptr<ChFi2d_FilletAlgo, Deleter<ChFi2d_FilletAlgo>>> cls_ChFi2d_FilletAlgo(mod, "ChFi2d_FilletAlgo", "Algorithm that creates fillet edge: arc tangent to two edges in the start and in the end vertices. Initial edges must be located on the plane and must be connected by the end or start points (shared vertices are not obligatory). Created fillet arc is created with the given radius, that is useful in sketcher applications.");

// Constructors
cls_ChFi2d_FilletAlgo.def(py::init<>());
cls_ChFi2d_FilletAlgo.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_FilletAlgo.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));

// Fields

// Methods
cls_ChFi2d_FilletAlgo.def("Init", (void (ChFi2d_FilletAlgo::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_FilletAlgo::Init, "Initializes a fillet algorithm: accepts a wire consisting of two edges in a plane.", py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_FilletAlgo.def("Init", (void (ChFi2d_FilletAlgo::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_FilletAlgo::Init, "Initializes a fillet algorithm: accepts two edges in a plane.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
cls_ChFi2d_FilletAlgo.def("Perform", (Standard_Boolean (ChFi2d_FilletAlgo::*)(const Standard_Real)) &ChFi2d_FilletAlgo::Perform, "Constructs a fillet edge. Returns true, if at least one result was found", py::arg("theRadius"));
cls_ChFi2d_FilletAlgo.def("NbResults", (Standard_Integer (ChFi2d_FilletAlgo::*)(const gp_Pnt &)) &ChFi2d_FilletAlgo::NbResults, "Returns number of possible solutions. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"));
cls_ChFi2d_FilletAlgo.def("Result", [](ChFi2d_FilletAlgo &self, const gp_Pnt & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> TopoDS_Edge { return self.Result(a0, a1, a2); });
cls_ChFi2d_FilletAlgo.def("Result", (TopoDS_Edge (ChFi2d_FilletAlgo::*)(const gp_Pnt &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Integer)) &ChFi2d_FilletAlgo::Result, "Returns result (fillet edge, modified edge1, modified edge2), neares to the given point <thePoint> if iSolution == -1. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("iSolution"));

// Enums

}