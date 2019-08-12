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
#include <IntAna_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <IntPatch_Point.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_ALine.hxx>
#include <Standard_Type.hxx>
#include <IntPatch_SequenceOfPoint.hxx>

void bind_IntPatch_ALine(py::module &mod){

py::class_<IntPatch_ALine, opencascade::handle<IntPatch_ALine>, IntPatch_Line> cls_IntPatch_ALine(mod, "IntPatch_ALine", "Implementation of an intersection line described by a parametrised curve.");

// Constructors
cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean, const IntSurf_TypeTrans, const IntSurf_TypeTrans>(), py::arg("C"), py::arg("Tang"), py::arg("Trans1"), py::arg("Trans2"));
cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean, const IntSurf_Situation, const IntSurf_Situation>(), py::arg("C"), py::arg("Tang"), py::arg("Situ1"), py::arg("Situ2"));
cls_IntPatch_ALine.def(py::init<const IntAna_Curve &, const Standard_Boolean>(), py::arg("C"), py::arg("Tang"));

// Fields

// Methods
cls_IntPatch_ALine.def("AddVertex", (void (IntPatch_ALine::*)(const IntPatch_Point &)) &IntPatch_ALine::AddVertex, "To add a vertex in the list.", py::arg("Pnt"));
cls_IntPatch_ALine.def("Replace", (void (IntPatch_ALine::*)(const Standard_Integer, const IntPatch_Point &)) &IntPatch_ALine::Replace, "Replaces the element of range Index in the list of points.", py::arg("Index"), py::arg("Pnt"));
cls_IntPatch_ALine.def("SetFirstPoint", (void (IntPatch_ALine::*)(const Standard_Integer)) &IntPatch_ALine::SetFirstPoint, "None", py::arg("IndFirst"));
cls_IntPatch_ALine.def("SetLastPoint", (void (IntPatch_ALine::*)(const Standard_Integer)) &IntPatch_ALine::SetLastPoint, "None", py::arg("IndLast"));
cls_IntPatch_ALine.def("FirstParameter", [](IntPatch_ALine &self, Standard_Boolean & IsIncluded){ Standard_Real rv = self.FirstParameter(IsIncluded); return std::tuple<Standard_Real, Standard_Boolean &>(rv, IsIncluded); }, "Returns the first parameter on the intersection line. If IsIncluded returns True, Value and D1 methods can be call with a parameter equal to FirstParamater. Otherwise, the parameter must be greater than FirstParameter.", py::arg("IsIncluded"));
cls_IntPatch_ALine.def("LastParameter", [](IntPatch_ALine &self, Standard_Boolean & IsIncluded){ Standard_Real rv = self.LastParameter(IsIncluded); return std::tuple<Standard_Real, Standard_Boolean &>(rv, IsIncluded); }, "Returns the last parameter on the intersection line. If IsIncluded returns True, Value and D1 methods can be call with a parameter equal to LastParamater. Otherwise, the parameter must be less than LastParameter.", py::arg("IsIncluded"));
cls_IntPatch_ALine.def("Value", (gp_Pnt (IntPatch_ALine::*)(const Standard_Real)) &IntPatch_ALine::Value, "Returns the point of parameter U on the analytic intersection line.", py::arg("U"));
cls_IntPatch_ALine.def("D1", (Standard_Boolean (IntPatch_ALine::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &IntPatch_ALine::D1, "Returns Standard_True when the derivative at parameter U is defined on the analytic intersection line. In that case, Du is the derivative. Returns Standard_False when it is not possible to evaluate the derivative. In both cases, P is the point at parameter U on the intersection.", py::arg("U"), py::arg("P"), py::arg("Du"));
cls_IntPatch_ALine.def("FindParameter", [](IntPatch_ALine &self, const gp_Pnt & P, Standard_Real & Para){ Standard_Boolean rv = self.FindParameter(P, Para); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Para); }, "Tries to find the parameter of the point P on the curve. If the method returns False, the 'projection' is impossible, and the value of Para is not significant. If the method returns True, Para is the parameter of the nearest intersection between the curve and the iso-theta containing P.", py::arg("P"), py::arg("Para"));
cls_IntPatch_ALine.def("HasFirstPoint", (Standard_Boolean (IntPatch_ALine::*)() const) &IntPatch_ALine::HasFirstPoint, "Returns True if the line has a known First point. This point is given by the method FirstPoint().");
cls_IntPatch_ALine.def("HasLastPoint", (Standard_Boolean (IntPatch_ALine::*)() const) &IntPatch_ALine::HasLastPoint, "Returns True if the line has a known Last point. This point is given by the method LastPoint().");
cls_IntPatch_ALine.def("FirstPoint", (const IntPatch_Point & (IntPatch_ALine::*)() const) &IntPatch_ALine::FirstPoint, "Returns the IntPoint corresponding to the FirstPoint. An exception is raised when HasFirstPoint returns False.");
cls_IntPatch_ALine.def("LastPoint", (const IntPatch_Point & (IntPatch_ALine::*)() const) &IntPatch_ALine::LastPoint, "Returns the IntPoint corresponding to the LastPoint. An exception is raised when HasLastPoint returns False.");
cls_IntPatch_ALine.def("NbVertex", (Standard_Integer (IntPatch_ALine::*)() const) &IntPatch_ALine::NbVertex, "None");
cls_IntPatch_ALine.def("Vertex", (const IntPatch_Point & (IntPatch_ALine::*)(const Standard_Integer) const) &IntPatch_ALine::Vertex, "Returns the vertex of range Index on the line.", py::arg("Index"));
cls_IntPatch_ALine.def("ComputeVertexParameters", (void (IntPatch_ALine::*)(const Standard_Real)) &IntPatch_ALine::ComputeVertexParameters, "Set the parameters of all the vertex on the line. if a vertex is already in the line, its parameter is modified else a new point in the line is inserted.", py::arg("Tol"));
cls_IntPatch_ALine.def("Curve", (const IntAna_Curve & (IntPatch_ALine::*)() const) &IntPatch_ALine::Curve, "None");
cls_IntPatch_ALine.def_static("get_type_name_", (const char * (*)()) &IntPatch_ALine::get_type_name, "None");
cls_IntPatch_ALine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_ALine::get_type_descriptor, "None");
cls_IntPatch_ALine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_ALine::*)() const) &IntPatch_ALine::DynamicType, "None");

// Enums

}