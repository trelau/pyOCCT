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
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <ChFi2d_ChamferAPI.hxx>

void bind_ChFi2d_ChamferAPI(py::module &mod){

py::class_<ChFi2d_ChamferAPI> cls_ChFi2d_ChamferAPI(mod, "ChFi2d_ChamferAPI", "A class making a chamfer between two linear edges.");

// Constructors
cls_ChFi2d_ChamferAPI.def(py::init<>());
cls_ChFi2d_ChamferAPI.def(py::init<const TopoDS_Wire &>(), py::arg("theWire"));
cls_ChFi2d_ChamferAPI.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theEdge1"), py::arg("theEdge2"));

// Fields

// Methods
cls_ChFi2d_ChamferAPI.def("Init", (void (ChFi2d_ChamferAPI::*)(const TopoDS_Wire &)) &ChFi2d_ChamferAPI::Init, "Initializes the class by a wire consisting of two libear edges.", py::arg("theWire"));
cls_ChFi2d_ChamferAPI.def("Init", (void (ChFi2d_ChamferAPI::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &ChFi2d_ChamferAPI::Init, "Initializes the class by two linear edges.", py::arg("theEdge1"), py::arg("theEdge2"));
cls_ChFi2d_ChamferAPI.def("Perform", (Standard_Boolean (ChFi2d_ChamferAPI::*)()) &ChFi2d_ChamferAPI::Perform, "Constructs a chamfer edge. Returns true if the edge is constructed.");
cls_ChFi2d_ChamferAPI.def("Result", (TopoDS_Edge (ChFi2d_ChamferAPI::*)(TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_ChamferAPI::Result, "None", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theLength1"), py::arg("theLength2"));

// Enums

}