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
#include <IntPatch_PointLine.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <IntPatch_Point.hxx>
#include <Standard_Handle.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntPatch_RLine.hxx>
#include <Standard_Type.hxx>
#include <IntPatch_SequenceOfPoint.hxx>

void bind_IntPatch_RLine(py::module &mod){

py::class_<IntPatch_RLine, opencascade::handle<IntPatch_RLine>, IntPatch_PointLine> cls_IntPatch_RLine(mod, "IntPatch_RLine", "Implementation of an intersection line described by a restriction line on one of the surfaces.");

// Constructors
cls_IntPatch_RLine.def(py::init<const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_RLine.def(py::init<const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_RLine.def(py::init<const Standard_Boolean>(), py::arg("Tang"));

// Fields

// Methods
cls_IntPatch_RLine.def("AddVertex", [](IntPatch_RLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); });
cls_IntPatch_RLine.def("AddVertex", (void (IntPatch_RLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_RLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
cls_IntPatch_RLine.def("Replace", (void (IntPatch_RLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_RLine::Replace, "Replaces the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_RLine.def("SetFirstPoint", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::SetFirstPoint, "None", py::arg("IndFirst"));
cls_IntPatch_RLine.def("SetLastPoint", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::SetLastPoint, "None", py::arg("IndLast"));
cls_IntPatch_RLine.def("Add", (void (IntPatch_RLine::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &IntPatch_RLine::Add, "None", py::arg("L"));
cls_IntPatch_RLine.def("IsArcOnS1", (Standard_Boolean (IntPatch_RLine::*)() const) &IntPatch_RLine::IsArcOnS1, "Returns True if the intersection is on the domain of the first patch. Returns False if the intersection is on the domain of the second patch.");
cls_IntPatch_RLine.def("IsArcOnS2", (Standard_Boolean (IntPatch_RLine::*)() const) &IntPatch_RLine::IsArcOnS2, "Returns True if the intersection is on the domain of the first patch. Returns False if the intersection is on the domain of the second patch.");
cls_IntPatch_RLine.def("SetArcOnS1", (void (IntPatch_RLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_RLine::SetArcOnS1, "None", py::arg("A"));
cls_IntPatch_RLine.def("SetArcOnS2", (void (IntPatch_RLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_RLine::SetArcOnS2, "None", py::arg("A"));
// cls_IntPatch_RLine.def("SetParamOnS1", (void (IntPatch_RLine::*)(const Standard_Real, const Standard_Real)) &IntPatch_RLine::SetParamOnS1, "None", py::arg("p1"), py::arg("p2"));
// cls_IntPatch_RLine.def("SetParamOnS2", [](IntPatch_RLine &self, Standard_Real & p1, Standard_Real & p2){ self.SetParamOnS2(p1, p2); return std::tuple<Standard_Real &, Standard_Real &>(p1, p2); }, "None", py::arg("p1"), py::arg("p2"));
cls_IntPatch_RLine.def("ArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_RLine::*)() const) &IntPatch_RLine::ArcOnS1, "Returns the concerned arc.");
cls_IntPatch_RLine.def("ArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_RLine::*)() const) &IntPatch_RLine::ArcOnS2, "Returns the concerned arc.");
cls_IntPatch_RLine.def("ParamOnS1", [](IntPatch_RLine &self, Standard_Real & p1, Standard_Real & p2){ self.ParamOnS1(p1, p2); return std::tuple<Standard_Real &, Standard_Real &>(p1, p2); }, "None", py::arg("p1"), py::arg("p2"));
cls_IntPatch_RLine.def("ParamOnS2", [](IntPatch_RLine &self, Standard_Real & p1, Standard_Real & p2){ self.ParamOnS2(p1, p2); return std::tuple<Standard_Real &, Standard_Real &>(p1, p2); }, "None", py::arg("p1"), py::arg("p2"));
cls_IntPatch_RLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_RLine::*)() const) &IntPatch_RLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
cls_IntPatch_RLine.def("HasLastPoint", (Standard_Boolean (IntPatch_RLine::*)() const) &IntPatch_RLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
cls_IntPatch_RLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_RLine::*)() const) &IntPatch_RLine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
cls_IntPatch_RLine.def("LastPoint", (const IntPatch_Point & (IntPatch_RLine::*)() const) &IntPatch_RLine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
cls_IntPatch_RLine.def("NbVertex", (Standard_Integer (IntPatch_RLine::*)() const) &IntPatch_RLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
cls_IntPatch_RLine.def("Vertex", (const IntPatch_Point & (IntPatch_RLine::*)(const Standard_Integer) const) &IntPatch_RLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_RLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_RLine.def("RemoveVertex", (void (IntPatch_RLine::*)(const Standard_Integer)) &IntPatch_RLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
cls_IntPatch_RLine.def("HasPolygon", (Standard_Boolean (IntPatch_RLine::*)() const) &IntPatch_RLine::HasPolygon, "None");
cls_IntPatch_RLine.def("NbPnts", (Standard_Integer (IntPatch_RLine::*)() const) &IntPatch_RLine::NbPnts, "Returns the number of intersection points.");
cls_IntPatch_RLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_RLine::*)(const Standard_Integer) const) &IntPatch_RLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
cls_IntPatch_RLine.def("SetPoint", (void (IntPatch_RLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_RLine::SetPoint, "Set the Point of index <Index> in the LineOn2S", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_RLine.def("ComputeVertexParameters", (void (IntPatch_RLine::*)(const Standard_Real)) &IntPatch_RLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
cls_IntPatch_RLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_RLine::*)() const) &IntPatch_RLine::Curve, "Returns set of intersection points");
cls_IntPatch_RLine.def("ClearVertexes", (void (IntPatch_RLine::*)()) &IntPatch_RLine::ClearVertexes, "Removes vertices from the line (i.e. cleans svtx member)");
cls_IntPatch_RLine.def("SetCurve", (void (IntPatch_RLine::*)(const opencascade::handle<IntSurf_LineOn2S> &)) &IntPatch_RLine::SetCurve, "None", py::arg("theNewCurve"));
cls_IntPatch_RLine.def("Dump", (void (IntPatch_RLine::*)(const Standard_Integer) const) &IntPatch_RLine::Dump, "if (theMode == 0) then prints the information about WLine if (theMode == 1) then prints the list of 3d-points if (theMode == 2) then prints the list of 2d-points on the 1st surface Otherwise, prints list of 2d-points on the 2nd surface", py::arg("theMode"));
cls_IntPatch_RLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_RLine::get_type_name, "None");
cls_IntPatch_RLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_RLine::get_type_descriptor, "None");
cls_IntPatch_RLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_RLine::*)() const) &IntPatch_RLine::DynamicType, "None");

// Enums

}