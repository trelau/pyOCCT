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
#include <Standard_TypeDef.hxx>
#include <Geom2d_Geometry.hxx>
#include <gp_Trsf2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec2d.hxx>
#include <Bisector_BisecPC.hxx>
#include <Standard_Type.hxx>
#include <TColStd_SequenceOfReal.hxx>

void bind_Bisector_BisecPC(py::module &mod){

py::class_<Bisector_BisecPC, opencascade::handle<Bisector_BisecPC>, Bisector_Curve> cls_Bisector_BisecPC(mod, "Bisector_BisecPC", "Provides the bisector between a point and a curve. the curvature on the curve has to be monoton. the point can't be on the curve exept at the extremitys.");

// Constructors
cls_Bisector_BisecPC.def(py::init<>());
cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"));
cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("DistMax"));
cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("UMin"), py::arg("UMax"));

// Fields

// Methods
cls_Bisector_BisecPC.def("Perform", [](Bisector_BisecPC &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_Bisector_BisecPC.def("Perform", (void (Bisector_BisecPC::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &Bisector_BisecPC::Perform, "Construct the bisector between the point <P> and the curve <Cu>. <Side> = 1. if the bisector curve is on the Left of <Cu> else <Side> = -1. <DistMax> is used to trim the bisector.The distance between the points of the bisector and <Cu> is smaller than <DistMax>.", py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("DistMax"));
cls_Bisector_BisecPC.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IsExtendAtStart, "Returns True if the bisector is extended at start.");
cls_Bisector_BisecPC.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IsExtendAtEnd, "Returns True if the bisector is extended at end.");
cls_Bisector_BisecPC.def("Reverse", (void (Bisector_BisecPC::*)()) &Bisector_BisecPC::Reverse, "Changes the direction of parametrization of <me>. The orientation of the curve is modified. If the curve is bounded the StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
cls_Bisector_BisecPC.def("ReversedParameter", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const) &Bisector_BisecPC::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Bisector_BisecPC.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecPC::*)() const) &Bisector_BisecPC::Copy, "None");
cls_Bisector_BisecPC.def("Transform", (void (Bisector_BisecPC::*)(const gp_Trsf2d &)) &Bisector_BisecPC::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations.", py::arg("T"));
cls_Bisector_BisecPC.def("IsCN", (Standard_Boolean (Bisector_BisecPC::*)(const Standard_Integer) const) &Bisector_BisecPC::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
cls_Bisector_BisecPC.def("FirstParameter", (Standard_Real (Bisector_BisecPC::*)() const) &Bisector_BisecPC::FirstParameter, "Value of the first parameter.");
cls_Bisector_BisecPC.def("LastParameter", (Standard_Real (Bisector_BisecPC::*)() const) &Bisector_BisecPC::LastParameter, "Value of the last parameter.");
cls_Bisector_BisecPC.def("Continuity", (GeomAbs_Shape (Bisector_BisecPC::*)() const) &Bisector_BisecPC::Continuity, "None");
cls_Bisector_BisecPC.def("NbIntervals", (Standard_Integer (Bisector_BisecPC::*)() const) &Bisector_BisecPC::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
cls_Bisector_BisecPC.def("IntervalFirst", (Standard_Real (Bisector_BisecPC::*)(const Standard_Integer) const) &Bisector_BisecPC::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecPC.def("IntervalLast", (Standard_Real (Bisector_BisecPC::*)(const Standard_Integer) const) &Bisector_BisecPC::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
cls_Bisector_BisecPC.def("IntervalContinuity", (GeomAbs_Shape (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IntervalContinuity, "None");
cls_Bisector_BisecPC.def("IsClosed", (Standard_Boolean (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IsClosed, "None");
cls_Bisector_BisecPC.def("IsPeriodic", (Standard_Boolean (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IsPeriodic, "None");
cls_Bisector_BisecPC.def("Distance", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const) &Bisector_BisecPC::Distance, "Returns the distance between the point of parameter U on <me> and my point or my curve.", py::arg("U"));
cls_Bisector_BisecPC.def("D0", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &) const) &Bisector_BisecPC::D0, "None", py::arg("U"), py::arg("P"));
cls_Bisector_BisecPC.def("D1", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Bisector_BisecPC::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Bisector_BisecPC.def("D2", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecPC::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Bisector_BisecPC.def("D3", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Bisector_BisecPC::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Bisector_BisecPC.def("DN", (gp_Vec2d (Bisector_BisecPC::*)(const Standard_Real, const Standard_Integer) const) &Bisector_BisecPC::DN, "None", py::arg("U"), py::arg("N"));
cls_Bisector_BisecPC.def("Dump", [](Bisector_BisecPC &self) -> void { return self.Dump(); });
cls_Bisector_BisecPC.def("Dump", [](Bisector_BisecPC &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_Bisector_BisecPC.def("Dump", (void (Bisector_BisecPC::*)(const Standard_Integer, const Standard_Integer) const) &Bisector_BisecPC::Dump, "None", py::arg("Deep"), py::arg("Offset"));
cls_Bisector_BisecPC.def("LinkBisCurve", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const) &Bisector_BisecPC::LinkBisCurve, "Returns the parameter on the curve1 of the projection of the point of parameter U on <me>.", py::arg("U"));
cls_Bisector_BisecPC.def("LinkCurveBis", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const) &Bisector_BisecPC::LinkCurveBis, "Returns the reciproque of LinkBisCurve.", py::arg("U"));
cls_Bisector_BisecPC.def("Parameter", (Standard_Real (Bisector_BisecPC::*)(const gp_Pnt2d &) const) &Bisector_BisecPC::Parameter, "Returns the parameter on <me> corresponding to <P>.", py::arg("P"));
cls_Bisector_BisecPC.def("IsEmpty", (Standard_Boolean (Bisector_BisecPC::*)() const) &Bisector_BisecPC::IsEmpty, "Returns <True> if the bisector is empty.");
cls_Bisector_BisecPC.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecPC::get_type_name, "None");
cls_Bisector_BisecPC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecPC::get_type_descriptor, "None");
cls_Bisector_BisecPC.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecPC::*)() const) &Bisector_BisecPC::DynamicType, "None");

// Enums

}