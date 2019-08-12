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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <IntPatch_Point.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_GLine.hxx>
#include <Standard_Type.hxx>
#include <gp_Ax2.hxx>
#include <IntPatch_SequenceOfPoint.hxx>

void bind_IntPatch_GLine(py::module &mod){

py::class_<IntPatch_GLine, opencascade::handle<IntPatch_GLine>, IntPatch_Line> cls_IntPatch_GLine(mod, "IntPatch_GLine", "Implementation of an intersection line represented by a conic.");

// Constructors
cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("L"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("L"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_GLine.def(py::init<const gp_Lin &, const Standard_Boolean>(), py::arg("L"), py::arg("Tang"));
cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("C"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("C"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_GLine.def(py::init<const gp_Circ &, const Standard_Boolean>(), py::arg("C"), py::arg("Tang"));
cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("E"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("E"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_GLine.def(py::init<const gp_Elips &, const Standard_Boolean>(), py::arg("E"), py::arg("Tang"));
cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("P"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("P"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_GLine.def(py::init<const gp_Parab &, const Standard_Boolean>(), py::arg("P"), py::arg("Tang"));
cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("H"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("H"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_GLine.def(py::init<const gp_Hypr &, const Standard_Boolean>(), py::arg("H"), py::arg("Tang"));

// Fields

// Methods
cls_IntPatch_GLine.def("AddVertex", (void (IntPatch_GLine::*)(const IntPatch_Point &)) &IntPatch_GLine::AddVertex, "To add a vertex in the list.", py::arg("Pnt"));
cls_IntPatch_GLine.def("Replace", (void (IntPatch_GLine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_GLine::Replace, "To replace the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_GLine.def("SetFirstPoint", (void (IntPatch_GLine::*)(const Standard_Integer)) &IntPatch_GLine::SetFirstPoint, "None", py::arg("IndFirst"));
cls_IntPatch_GLine.def("SetLastPoint", (void (IntPatch_GLine::*)(const Standard_Integer)) &IntPatch_GLine::SetLastPoint, "None", py::arg("IndLast"));
cls_IntPatch_GLine.def("Line", (gp_Lin (IntPatch_GLine::*)() const) &IntPatch_GLine::Line, "Returns the Lin from gp corresponding to the intersection when ArcType returns IntPatch_Line.");
cls_IntPatch_GLine.def("Circle", (gp_Circ (IntPatch_GLine::*)() const) &IntPatch_GLine::Circle, "Returns the Circ from gp corrsponding to the intersection when ArcType returns IntPatch_Circle.");
cls_IntPatch_GLine.def("Ellipse", (gp_Elips (IntPatch_GLine::*)() const) &IntPatch_GLine::Ellipse, "Returns the Elips from gp corrsponding to the intersection when ArcType returns IntPatch_Ellipse.");
cls_IntPatch_GLine.def("Parabola", (gp_Parab (IntPatch_GLine::*)() const) &IntPatch_GLine::Parabola, "Returns the Parab from gp corrsponding to the intersection when ArcType returns IntPatch_Parabola.");
cls_IntPatch_GLine.def("Hyperbola", (gp_Hypr (IntPatch_GLine::*)() const) &IntPatch_GLine::Hyperbola, "Returns the Hypr from gp corrsponding to the intersection when ArcType returns IntPatch_Hyperbola.");
cls_IntPatch_GLine.def("HasFirstPoint", (Standard_Boolean (IntPatch_GLine::*)() const) &IntPatch_GLine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
cls_IntPatch_GLine.def("HasLastPoint", (Standard_Boolean (IntPatch_GLine::*)() const) &IntPatch_GLine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
cls_IntPatch_GLine.def("FirstPoint", (const IntPatch_Point & (IntPatch_GLine::*)() const) &IntPatch_GLine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
cls_IntPatch_GLine.def("LastPoint", (const IntPatch_Point & (IntPatch_GLine::*)() const) &IntPatch_GLine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
cls_IntPatch_GLine.def("NbVertex", (Standard_Integer (IntPatch_GLine::*)() const) &IntPatch_GLine::NbVertex, "None");
cls_IntPatch_GLine.def("Vertex", (const IntPatch_Point & (IntPatch_GLine::*)(const Standard_Integer) const) &IntPatch_GLine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_GLine.def("ComputeVertexParameters", (void (IntPatch_GLine::*)(const Standard_Real)) &IntPatch_GLine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
cls_IntPatch_GLine.def_static("get_type_name_", (const char * (*)()) &IntPatch_GLine::get_type_name, "None");
cls_IntPatch_GLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_GLine::get_type_descriptor, "None");
cls_IntPatch_GLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_GLine::*)() const) &IntPatch_GLine::DynamicType, "None");

// Enums

}