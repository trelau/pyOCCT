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
#include <IntPatch_Line.hxx>
#include <IntPatch_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <Standard_Handle.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPatch_PointLine.hxx>
#include <Standard_Type.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>

void bind_IntPatch_PointLine(py::module &mod){

py::class_<IntPatch_PointLine, opencascade::handle<IntPatch_PointLine>, IntPatch_Line> cls_IntPatch_PointLine(mod, "IntPatch_PointLine", "Definition of an intersection line between two surfaces. A line defined by a set of points (e.g. coming from a walking algorithm) as defined in the class WLine or RLine (Restriction line).");

// Fields

// Methods
cls_IntPatch_PointLine.def("AddVertex", [](IntPatch_PointLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); });
cls_IntPatch_PointLine.def("AddVertex", (void (IntPatch_PointLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_PointLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
cls_IntPatch_PointLine.def("NbPnts", (Standard_Integer (IntPatch_PointLine::*)() const) &IntPatch_PointLine::NbPnts, "Returns the number of intersection points.");
cls_IntPatch_PointLine.def("NbVertex", (Standard_Integer (IntPatch_PointLine::*)() const) &IntPatch_PointLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
cls_IntPatch_PointLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_PointLine::*)(const Standard_Integer) const) &IntPatch_PointLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
cls_IntPatch_PointLine.def("Vertex", (const IntPatch_Point & (IntPatch_PointLine::*)(const Standard_Integer) const) &IntPatch_PointLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_PointLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_PointLine::*)(const Standard_Integer)) &IntPatch_PointLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_PointLine.def("ClearVertexes", (void (IntPatch_PointLine::*)()) &IntPatch_PointLine::ClearVertexes, "Removes vertices from the line");
cls_IntPatch_PointLine.def("RemoveVertex", (void (IntPatch_PointLine::*)(const Standard_Integer)) &IntPatch_PointLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
cls_IntPatch_PointLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_PointLine::*)() const) &IntPatch_PointLine::Curve, "Returns set of intersection points");
cls_IntPatch_PointLine.def_static("CurvatureRadiusOfIntersLine_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_PntOn2S &)) &IntPatch_PointLine::CurvatureRadiusOfIntersLine, "Returns the radius of curvature of the intersection line in given point. Returns negative value if computation is not possible.", py::arg("theS1"), py::arg("theS2"), py::arg("theUVPoint"));
cls_IntPatch_PointLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_PointLine::get_type_name, "None");
cls_IntPatch_PointLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_PointLine::get_type_descriptor, "None");
cls_IntPatch_PointLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_PointLine::*)() const) &IntPatch_PointLine::DynamicType, "None");

// Enums

}