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
#include <BRepCheck_Result.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepCheck_Status.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Edge.hxx>
#include <Standard_Type.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <Adaptor3d_HCurve.hxx>

void bind_BRepCheck_Edge(py::module &mod){

py::class_<BRepCheck_Edge, opencascade::handle<BRepCheck_Edge>, BRepCheck_Result> cls_BRepCheck_Edge(mod, "BRepCheck_Edge", "None");

// Constructors
cls_BRepCheck_Edge.def(py::init<const TopoDS_Edge &>(), py::arg("E"));

// Fields

// Methods
cls_BRepCheck_Edge.def("InContext", (void (BRepCheck_Edge::*)(const TopoDS_Shape &)) &BRepCheck_Edge::InContext, "None", py::arg("ContextShape"));
cls_BRepCheck_Edge.def("Minimum", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Minimum, "None");
cls_BRepCheck_Edge.def("Blind", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Blind, "None");
cls_BRepCheck_Edge.def("GeometricControls", (Standard_Boolean (BRepCheck_Edge::*)() const) &BRepCheck_Edge::GeometricControls, "None");
cls_BRepCheck_Edge.def("GeometricControls", (void (BRepCheck_Edge::*)(const Standard_Boolean)) &BRepCheck_Edge::GeometricControls, "None", py::arg("B"));
cls_BRepCheck_Edge.def("Tolerance", (Standard_Real (BRepCheck_Edge::*)()) &BRepCheck_Edge::Tolerance, "None");
cls_BRepCheck_Edge.def("SetStatus", (void (BRepCheck_Edge::*)(const BRepCheck_Status)) &BRepCheck_Edge::SetStatus, "Sets status of Edge;", py::arg("theStatus"));
cls_BRepCheck_Edge.def("CheckPolygonOnTriangulation", (BRepCheck_Status (BRepCheck_Edge::*)(const TopoDS_Edge &)) &BRepCheck_Edge::CheckPolygonOnTriangulation, "Checks, if polygon on triangulation of heEdge is out of 3D-curve of this edge.", py::arg("theEdge"));
cls_BRepCheck_Edge.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Edge::get_type_name, "None");
cls_BRepCheck_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Edge::get_type_descriptor, "None");
cls_BRepCheck_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Edge::*)() const) &BRepCheck_Edge::DynamicType, "None");

// Enums

}