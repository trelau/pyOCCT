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
#include <ChFi2d_AnaFilletAlgo.hxx>

void bind_ChFi2d_AnaFilletAlgo(py::module &mod){

py::class_<ChFi2d_AnaFilletAlgo, std::unique_ptr<ChFi2d_AnaFilletAlgo, Deleter<ChFi2d_AnaFilletAlgo>>> cls_ChFi2d_AnaFilletAlgo(mod, "ChFi2d_AnaFilletAlgo", "An analytical algorithm for calculation of the fillets. It is implemented for segments and arcs of circle only.");

// Constructors
cls_ChFi2d_AnaFilletAlgo.def(py::init<>());
cls_ChFi2d_AnaFilletAlgo.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_AnaFilletAlgo.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));

// Fields

// Methods
cls_ChFi2d_AnaFilletAlgo.def("Init", (void (ChFi2d_AnaFilletAlgo::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_AnaFilletAlgo::Init, "Initializes the class by a wire consisting of two edges.", py::arg("theWire"), py::arg("thePlane"));
cls_ChFi2d_AnaFilletAlgo.def("Init", (void (ChFi2d_AnaFilletAlgo::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_AnaFilletAlgo::Init, "Initializes the class by two edges.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
cls_ChFi2d_AnaFilletAlgo.def("Perform", (Standard_Boolean (ChFi2d_AnaFilletAlgo::*)(const Standard_Real)) &ChFi2d_AnaFilletAlgo::Perform, "Calculates a fillet.", py::arg("radius"));
cls_ChFi2d_AnaFilletAlgo.def("Result", (const TopoDS_Edge & (ChFi2d_AnaFilletAlgo::*)(TopoDS_Edge &, TopoDS_Edge &)) &ChFi2d_AnaFilletAlgo::Result, "Retrieves a result (fillet and shrinked neighbours).", py::arg("e1"), py::arg("e2"));

// Enums

}