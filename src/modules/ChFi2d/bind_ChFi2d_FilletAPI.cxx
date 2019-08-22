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
#include <ChFi2d_AnaFilletAlgo.hxx>
#include <ChFi2d_FilletAPI.hxx>

void bind_ChFi2d_FilletAPI(py::module &mod){

py::class_<ChFi2d_FilletAPI> cls_ChFi2d_FilletAPI(mod, "ChFi2d_FilletAPI", "An interface class for 2D fillets. Open CASCADE provides two algorithms for 2D fillets: ChFi2d_Builder - it constructs a fillet or chamfer for linear and circular edges of a face. ChFi2d_FilletAPI - it encapsulates two algorithms: ChFi2d_AnaFilletAlgo - analytical constructor of the fillet. It works only for linear and circular edges, having a common point. ChFi2d_FilletAlgo - iteration recursive method constructing the fillet edge for any type of edges including ellipses and b-splines. The edges may even have no common point.");

// Constructors
cls_ChFi2d_FilletAPI.def(py::init<>());
cls_ChFi2d_FilletAPI.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_FilletAPI.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));

// Fields

// Methods
cls_ChFi2d_FilletAPI.def("Init", (void (ChFi2d_FilletAPI::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_FilletAPI::Init, "Initializes a fillet algorithm: accepts a wire consisting of two edges in a plane.", py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_FilletAPI.def("Init", (void (ChFi2d_FilletAPI::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_FilletAPI::Init, "Initializes a fillet algorithm: accepts two edges in a plane.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
cls_ChFi2d_FilletAPI.def("Perform", (Standard_Boolean (ChFi2d_FilletAPI::*)(const Standard_Real)) &ChFi2d_FilletAPI::Perform, "Constructs a fillet edge. Returns true if at least one result was found.", py::arg("theRadius"));
cls_ChFi2d_FilletAPI.def("NbResults", (Standard_Integer (ChFi2d_FilletAPI::*)(const gp_Pnt &)) &ChFi2d_FilletAPI::NbResults, "Returns number of possible solutions. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"));
cls_ChFi2d_FilletAPI.def("Result", [](ChFi2d_FilletAPI &self, const gp_Pnt & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> TopoDS_Edge { return self.Result(a0, a1, a2); });
cls_ChFi2d_FilletAPI.def("Result", (TopoDS_Edge (ChFi2d_FilletAPI::*)(const gp_Pnt &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Integer)) &ChFi2d_FilletAPI::Result, "Returns result (fillet edge, modified edge1, modified edge2), nearest to the given point <thePoint> if iSolution == -1 <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("iSolution"));

// Enums

}