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
#include <Standard_Handle.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <IntPatch_Point.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntPatch_WLine.hxx>
#include <Standard_Type.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <Bnd_Box2d.hxx>
#include <Bnd_Box.hxx>

void bind_IntPatch_WLine(py::module &mod){

py::class_<IntPatch_WLine, opencascade::handle<IntPatch_WLine>, IntPatch_PointLine> cls_IntPatch_WLine(mod, "IntPatch_WLine", "Definition of set of points as a result of the intersection between 2 parametrised patches.");

// Constructors
cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("Line"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("Line"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_WLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean>(), py::arg("Line"), py::arg("Tang"));

// Fields

// Methods
cls_IntPatch_WLine.def("AddVertex", [](IntPatch_WLine &self, const IntPatch_Point & a0) -> void { return self.AddVertex(a0); });
cls_IntPatch_WLine.def("AddVertex", (void (IntPatch_WLine::*)(const IntPatch_Point &, const Standard_Boolean)) &IntPatch_WLine::AddVertex, "Adds a vertex in the list. If theIsPrepend == TRUE the new vertex will be added before the first element of vertices sequence. Otherwise, to the end of the sequence", py::arg("Pnt"), py::arg("theIsPrepend"));
cls_IntPatch_WLine.def("SetPoint", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::SetPoint, "Set the Point of index <Index> in the LineOn2S", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_WLine.def("Replace", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::Replace, "Replaces the element of range Index in the list of points. The exception OutOfRange is raised when Index <= 0 or Index > NbVertex.", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_WLine.def("SetFirstPoint", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::SetFirstPoint, "None", py::arg("IndFirst"));
cls_IntPatch_WLine.def("SetLastPoint", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::SetLastPoint, "None", py::arg("IndLast"));
cls_IntPatch_WLine.def("NbPnts", (Standard_Integer (IntPatch_WLine::*)() const) &IntPatch_WLine::NbPnts, "Returns the number of intersection points.");
cls_IntPatch_WLine.def("Point", (const IntSurf_PntOn2S & (IntPatch_WLine::*)(const Standard_Integer) const) &IntPatch_WLine::Point, "Returns the intersection point of range Index.", py::arg("Index"));
cls_IntPatch_WLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_WLine::*)() const) &IntPatch_WLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
cls_IntPatch_WLine.def("HasLastPoint", (Standard_Boolean (IntPatch_WLine::*)() const) &IntPatch_WLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
cls_IntPatch_WLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_WLine::*)() const) &IntPatch_WLine::FirstPoint, "Returns the Point corresponding to the FirstPoint.");
cls_IntPatch_WLine.def("LastPoint", (const IntPatch_Point & (IntPatch_WLine::*)() const) &IntPatch_WLine::LastPoint, "Returns the Point corresponding to the LastPoint.");
cls_IntPatch_WLine.def("FirstPoint", [](IntPatch_WLine &self, Standard_Integer & Indfirst){ const IntPatch_Point & rv = self.FirstPoint(Indfirst); return std::tuple<const IntPatch_Point &, Standard_Integer &>(rv, Indfirst); }, "Returns the Point corresponding to the FirstPoint. Indfirst is the index of the first in the list of vertices.", py::arg("Indfirst"));
cls_IntPatch_WLine.def("LastPoint", [](IntPatch_WLine &self, Standard_Integer & Indlast){ const IntPatch_Point & rv = self.LastPoint(Indlast); return std::tuple<const IntPatch_Point &, Standard_Integer &>(rv, Indlast); }, "Returns the Point corresponding to the LastPoint. Indlast is the index of the last in the list of vertices.", py::arg("Indlast"));
cls_IntPatch_WLine.def("NbVertex", (Standard_Integer (IntPatch_WLine::*)() const) &IntPatch_WLine::NbVertex, "Returns number of vertices (IntPatch_Point) of the line");
cls_IntPatch_WLine.def("Vertex", (const IntPatch_Point & (IntPatch_WLine::*)(const Standard_Integer) const) &IntPatch_WLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_WLine.def("ChangeVertex", (IntPatch_Point & (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::ChangeVertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_WLine.def("ComputeVertexParameters", (void (IntPatch_WLine::*)(const Standard_Real)) &IntPatch_WLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
cls_IntPatch_WLine.def("Curve", (opencascade::handle<IntSurf_LineOn2S> (IntPatch_WLine::*)() const) &IntPatch_WLine::Curve, "Returns set of intersection points");
cls_IntPatch_WLine.def("IsOutSurf1Box", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt2d &)) &IntPatch_WLine::IsOutSurf1Box, "None", py::arg("P1"));
cls_IntPatch_WLine.def("IsOutSurf2Box", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt2d &)) &IntPatch_WLine::IsOutSurf2Box, "None", py::arg("P1"));
cls_IntPatch_WLine.def("IsOutBox", (Standard_Boolean (IntPatch_WLine::*)(const gp_Pnt &)) &IntPatch_WLine::IsOutBox, "None", py::arg("P"));
cls_IntPatch_WLine.def("SetPeriod", (void (IntPatch_WLine::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_WLine::SetPeriod, "None", py::arg("pu1"), py::arg("pv1"), py::arg("pu2"), py::arg("pv2"));
cls_IntPatch_WLine.def("U1Period", (Standard_Real (IntPatch_WLine::*)() const) &IntPatch_WLine::U1Period, "None");
cls_IntPatch_WLine.def("V1Period", (Standard_Real (IntPatch_WLine::*)() const) &IntPatch_WLine::V1Period, "None");
cls_IntPatch_WLine.def("U2Period", (Standard_Real (IntPatch_WLine::*)() const) &IntPatch_WLine::U2Period, "None");
cls_IntPatch_WLine.def("V2Period", (Standard_Real (IntPatch_WLine::*)() const) &IntPatch_WLine::V2Period, "None");
cls_IntPatch_WLine.def("SetArcOnS1", (void (IntPatch_WLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_WLine::SetArcOnS1, "None", py::arg("A"));
cls_IntPatch_WLine.def("HasArcOnS1", (Standard_Boolean (IntPatch_WLine::*)() const) &IntPatch_WLine::HasArcOnS1, "None");
cls_IntPatch_WLine.def("GetArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_WLine::*)() const) &IntPatch_WLine::GetArcOnS1, "None");
cls_IntPatch_WLine.def("SetArcOnS2", (void (IntPatch_WLine::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_WLine::SetArcOnS2, "None", py::arg("A"));
cls_IntPatch_WLine.def("HasArcOnS2", (Standard_Boolean (IntPatch_WLine::*)() const) &IntPatch_WLine::HasArcOnS2, "None");
cls_IntPatch_WLine.def("GetArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_WLine::*)() const) &IntPatch_WLine::GetArcOnS2, "None");
cls_IntPatch_WLine.def("ClearVertexes", (void (IntPatch_WLine::*)()) &IntPatch_WLine::ClearVertexes, "Removes vertices from the line (i.e. cleans svtx member)");
cls_IntPatch_WLine.def("RemoveVertex", (void (IntPatch_WLine::*)(const Standard_Integer)) &IntPatch_WLine::RemoveVertex, "Removes single vertex from the line", py::arg("theIndex"));
cls_IntPatch_WLine.def("InsertVertexBefore", (void (IntPatch_WLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_WLine::InsertVertexBefore, "None", py::arg("theIndex"), py::arg("thePnt"));
cls_IntPatch_WLine.def("Dump", (void (IntPatch_WLine::*)(const Standard_Integer) const) &IntPatch_WLine::Dump, "if (theMode == 0) then prints the information about WLine if (theMode == 1) then prints the list of 3d-points if (theMode == 2) then prints the list of 2d-points on the 1st surface Otherwise, prints list of 2d-points on the 2nd surface", py::arg("theMode"));
cls_IntPatch_WLine.def("EnablePurging", (void (IntPatch_WLine::*)(const Standard_Boolean)) &IntPatch_WLine::EnablePurging, "Allows or forbides purging of existing WLine", py::arg("theIsEnabled"));
cls_IntPatch_WLine.def("IsPurgingAllowed", (Standard_Boolean (IntPatch_WLine::*)()) &IntPatch_WLine::IsPurgingAllowed, "Returns TRUE if purging is allowed or forbiden for existing WLine");
cls_IntPatch_WLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_WLine::get_type_name, "None");
cls_IntPatch_WLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_WLine::get_type_descriptor, "None");
cls_IntPatch_WLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_WLine::*)() const) &IntPatch_WLine::DynamicType, "None");

// Enums

}