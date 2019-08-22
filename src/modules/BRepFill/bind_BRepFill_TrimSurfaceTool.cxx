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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <BRepFill_TrimSurfaceTool.hxx>

void bind_BRepFill_TrimSurfaceTool(py::module &mod){

py::class_<BRepFill_TrimSurfaceTool> cls_BRepFill_TrimSurfaceTool(mod, "BRepFill_TrimSurfaceTool", "Compute the Pcurves and the 3d curves resulting of the trimming of a face by an extruded surface.");

// Constructors
cls_BRepFill_TrimSurfaceTool.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Bis"), py::arg("Face1"), py::arg("Face2"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Inv1"), py::arg("Inv2"));

// Fields

// Methods
// cls_BRepFill_TrimSurfaceTool.def_static("operator new_", (void * (*)(size_t)) &BRepFill_TrimSurfaceTool::operator new, "None", py::arg("theSize"));
// cls_BRepFill_TrimSurfaceTool.def_static("operator delete_", (void (*)(void *)) &BRepFill_TrimSurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_TrimSurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_TrimSurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_TrimSurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_TrimSurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_TrimSurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_TrimSurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_TrimSurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_TrimSurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_TrimSurfaceTool.def("IntersectWith", (void (BRepFill_TrimSurfaceTool::*)(const TopoDS_Edge &, const TopoDS_Edge &, TColgp_SequenceOfPnt &) const) &BRepFill_TrimSurfaceTool::IntersectWith, "Intersect <Bis> with the projection of the edges <EdgeOnFi> and returns the intersecting parameters on Bis and on the edges P.X() : Parameter on Bis P.Y() : Parameter on EdgeOnF1 P.Z() : Parameter on EdgeOnF2 raises if <Edge> is not a edge of Face1 or Face2.", py::arg("EdgeOnF1"), py::arg("EdgeOnF2"), py::arg("Points"));
cls_BRepFill_TrimSurfaceTool.def("IsOnFace", (Standard_Boolean (BRepFill_TrimSurfaceTool::*)(const gp_Pnt2d &) const) &BRepFill_TrimSurfaceTool::IsOnFace, "returns True if the Line (P, DZ) intersect the Faces", py::arg("Point"));
cls_BRepFill_TrimSurfaceTool.def("ProjOn", (Standard_Real (BRepFill_TrimSurfaceTool::*)(const gp_Pnt2d &, const TopoDS_Edge &) const) &BRepFill_TrimSurfaceTool::ProjOn, "returns the parameter of the point <Point> on the Edge <Edge>, assuming that the point is on the edge.", py::arg("Point"), py::arg("Edge"));
cls_BRepFill_TrimSurfaceTool.def("Project", (void (BRepFill_TrimSurfaceTool::*)(const Standard_Real, const Standard_Real, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, GeomAbs_Shape &) const) &BRepFill_TrimSurfaceTool::Project, "None", py::arg("U1"), py::arg("U2"), py::arg("Curve"), py::arg("PCurve1"), py::arg("PCurve2"), py::arg("myCont"));

// Enums

}