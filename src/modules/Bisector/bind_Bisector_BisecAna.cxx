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
#include <Bisector_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_Geometry.hxx>
#include <gp_Trsf2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <Bisector_BisecAna.hxx>
#include <Standard_Type.hxx>
#include <GccInt_Bisec.hxx>

void bind_Bisector_BisecAna(py::module &mod){

py::class_<Bisector_BisecAna, opencascade::handle<Bisector_BisecAna>, Bisector_Curve> cls_Bisector_BisecAna(mod, "Bisector_BisecAna", "This class provides the bisecting line between two geometric elements.The elements are Circles,Lines or Points.");

// Constructors
cls_Bisector_BisecAna.def(py::init<>());

// Fields

// Methods
cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const GeomAbs_JoinType a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const GeomAbs_JoinType, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curves <Cu1> and <Cu2>. <oncurve> is True if the point <P> is common to <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("jointype"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curve <Cu1> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curve <Cu> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the two points <Pnt1> and <Pnt2>.", py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_BisecAna.def("Init", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_TrimmedCurve> &)) &Bisector_BisecAna::Init, "None", py::arg("bisector"));
cls_Bisector_BisecAna.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecAna::*)() const) &Bisector_BisecAna::IsExtendAtStart, "None");
cls_Bisector_BisecAna.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecAna::*)() const) &Bisector_BisecAna::IsExtendAtEnd, "None");
cls_Bisector_BisecAna.def("SetTrim", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &)) &Bisector_BisecAna::SetTrim, "Trim <me> by a domain defined by the curve <Cu>. This domain is the set of the points which are nearest from <Cu> than the extremitis of <Cu>.", py::arg("Cu"));
cls_Bisector_BisecAna.def("SetTrim", (void (Bisector_BisecAna::*)(const Standard_Real, const Standard_Real)) &Bisector_BisecAna::SetTrim, "Trim <me> by a domain defined by uf and ul", py::arg("uf"), py::arg("ul"));
cls_Bisector_BisecAna.def("Reverse", (void (Bisector_BisecAna::*)()) &Bisector_BisecAna::Reverse, "None");
cls_Bisector_BisecAna.def("ReversedParameter", (Standard_Real (Bisector_BisecAna::*)(const Standard_Real) const) &Bisector_BisecAna::ReversedParameter, "None", py::arg("U"));
cls_Bisector_BisecAna.def("IsCN", (Standard_Boolean (Bisector_BisecAna::*)(const Standard_Integer) const) &Bisector_BisecAna::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
cls_Bisector_BisecAna.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecAna::*)() const) &Bisector_BisecAna::Copy, "None");
cls_Bisector_BisecAna.def("Transform", (void (Bisector_BisecAna::*)(const gp_Trsf2d &)) &Bisector_BisecAna::Transform, "None", py::arg("T"));
cls_Bisector_BisecAna.def("FirstParameter", (Standard_Real (Bisector_BisecAna::*)() const) &Bisector_BisecAna::FirstParameter, "None");
cls_Bisector_BisecAna.def("LastParameter", (Standard_Real (Bisector_BisecAna::*)() const) &Bisector_BisecAna::LastParameter, "None");
cls_Bisector_BisecAna.def("IsClosed", (Standard_Boolean (Bisector_BisecAna::*)() const) &Bisector_BisecAna::IsClosed, "None");
cls_Bisector_BisecAna.def("IsPeriodic", (Standard_Boolean (Bisector_BisecAna::*)() const) &Bisector_BisecAna::IsPeriodic, "None");
cls_Bisector_BisecAna.def("Continuity", (GeomAbs_Shape (Bisector_BisecAna::*)() const) &Bisector_BisecAna::Continuity, "None");
cls_Bisector_BisecAna.def("D0", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &) const) &Bisector_BisecAna::D0, "None", py::arg("U"), py::arg("P"));
cls_Bisector_BisecAna.def("D1", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Bisector_BisecAna::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Bisector_BisecAna.def("D2", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecAna::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Bisector_BisecAna.def("D3", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecAna::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Bisector_BisecAna.def("DN", (gp_Vec2d (Bisector_BisecAna::*)(const Standard_Real, const Standard_Integer) const) &Bisector_BisecAna::DN, "None", py::arg("U"), py::arg("N"));
cls_Bisector_BisecAna.def("Geom2dCurve", (opencascade::handle<Geom2d_Curve> (Bisector_BisecAna::*)() const) &Bisector_BisecAna::Geom2dCurve, "None");
cls_Bisector_BisecAna.def("Parameter", (Standard_Real (Bisector_BisecAna::*)(const gp_Pnt2d &) const) &Bisector_BisecAna::Parameter, "None", py::arg("P"));
cls_Bisector_BisecAna.def("ParameterOfStartPoint", (Standard_Real (Bisector_BisecAna::*)() const) &Bisector_BisecAna::ParameterOfStartPoint, "None");
cls_Bisector_BisecAna.def("ParameterOfEndPoint", (Standard_Real (Bisector_BisecAna::*)() const) &Bisector_BisecAna::ParameterOfEndPoint, "None");
cls_Bisector_BisecAna.def("NbIntervals", (Standard_Integer (Bisector_BisecAna::*)() const) &Bisector_BisecAna::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
cls_Bisector_BisecAna.def("IntervalFirst", (Standard_Real (Bisector_BisecAna::*)(const Standard_Integer) const) &Bisector_BisecAna::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecAna.def("IntervalLast", (Standard_Real (Bisector_BisecAna::*)(const Standard_Integer) const) &Bisector_BisecAna::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecAna.def("Dump", [](Bisector_BisecAna &self) -> void { return self.Dump(); });
cls_Bisector_BisecAna.def("Dump", [](Bisector_BisecAna &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_Bisector_BisecAna.def("Dump", (void (Bisector_BisecAna::*)(const Standard_Integer, const Standard_Integer) const) &Bisector_BisecAna::Dump, "None", py::arg("Deep"), py::arg("Offset"));
cls_Bisector_BisecAna.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecAna::get_type_name, "None");
cls_Bisector_BisecAna.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecAna::get_type_descriptor, "None");
cls_Bisector_BisecAna.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecAna::*)() const) &Bisector_BisecAna::DynamicType, "None");

// Enums

}