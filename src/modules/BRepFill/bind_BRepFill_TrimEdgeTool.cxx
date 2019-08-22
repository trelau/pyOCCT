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
#include <Bisector_Bisec.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <GeomAbs_JoinType.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <BRepFill_TrimEdgeTool.hxx>

void bind_BRepFill_TrimEdgeTool(py::module &mod){

py::class_<BRepFill_TrimEdgeTool> cls_BRepFill_TrimEdgeTool(mod, "BRepFill_TrimEdgeTool", "Geometric Tool using to construct Offset Wires.");

// Constructors
cls_BRepFill_TrimEdgeTool.def(py::init<>());
cls_BRepFill_TrimEdgeTool.def(py::init<const Bisector_Bisec &, const opencascade::handle<Geom2d_Geometry> &, const opencascade::handle<Geom2d_Geometry> &, const Standard_Real>(), py::arg("Bisec"), py::arg("S1"), py::arg("S2"), py::arg("Offset"));

// Fields

// Methods
// cls_BRepFill_TrimEdgeTool.def_static("operator new_", (void * (*)(size_t)) &BRepFill_TrimEdgeTool::operator new, "None", py::arg("theSize"));
// cls_BRepFill_TrimEdgeTool.def_static("operator delete_", (void (*)(void *)) &BRepFill_TrimEdgeTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_TrimEdgeTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_TrimEdgeTool::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_TrimEdgeTool.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_TrimEdgeTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_TrimEdgeTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_TrimEdgeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_TrimEdgeTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_TrimEdgeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_TrimEdgeTool.def("IntersectWith", (void (BRepFill_TrimEdgeTool::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Vertex &, const TopoDS_Vertex &, const GeomAbs_JoinType, const Standard_Boolean, TColgp_SequenceOfPnt &)) &BRepFill_TrimEdgeTool::IntersectWith, "None", py::arg("Edge1"), py::arg("Edge2"), py::arg("InitShape1"), py::arg("InitShape2"), py::arg("End1"), py::arg("End2"), py::arg("theJoinType"), py::arg("IsOpenResult"), py::arg("Params"));
cls_BRepFill_TrimEdgeTool.def("AddOrConfuse", (void (BRepFill_TrimEdgeTool::*)(const Standard_Boolean, const TopoDS_Edge &, const TopoDS_Edge &, TColgp_SequenceOfPnt &) const) &BRepFill_TrimEdgeTool::AddOrConfuse, "None", py::arg("Start"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Params"));
cls_BRepFill_TrimEdgeTool.def("IsInside", (Standard_Boolean (BRepFill_TrimEdgeTool::*)(const gp_Pnt2d &) const) &BRepFill_TrimEdgeTool::IsInside, "None", py::arg("P"));

// Enums

}