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
#include <Standard_Transient.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_Adaptor2d_HCurve2d(py::module &mod){

py::class_<Adaptor2d_HCurve2d, opencascade::handle<Adaptor2d_HCurve2d>, Standard_Transient> cls_Adaptor2d_HCurve2d(mod, "Adaptor2d_HCurve2d", "Root class for 2D curves manipulated by handles, on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve, and those required of the curve by algorithms, which use it. A derived specific class is provided: Geom2dAdaptor_HCurve for a curve from the Geom2d package.");

// Fields

// Methods
cls_Adaptor2d_HCurve2d.def("Curve2d", (const Adaptor2d_Curve2d & (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Curve2d, "Returns a reference to the Curve2d inside the HCurve2d.");
cls_Adaptor2d_HCurve2d.def("FirstParameter", (Standard_Real (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::FirstParameter, "None");
cls_Adaptor2d_HCurve2d.def("LastParameter", (Standard_Real (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::LastParameter, "None");
cls_Adaptor2d_HCurve2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Continuity, "None");
cls_Adaptor2d_HCurve2d.def("NbIntervals", (Standard_Integer (Adaptor2d_HCurve2d::*)(const GeomAbs_Shape) const) &Adaptor2d_HCurve2d::NbIntervals, "None", py::arg("S"));
cls_Adaptor2d_HCurve2d.def("Intervals", (void (Adaptor2d_HCurve2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor2d_HCurve2d::Intervals, "None", py::arg("T"), py::arg("S"));
cls_Adaptor2d_HCurve2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_HCurve2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor2d_HCurve2d::Trim, "If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor2d_HCurve2d.def("IsClosed", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::IsClosed, "None");
cls_Adaptor2d_HCurve2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::IsPeriodic, "None");
cls_Adaptor2d_HCurve2d.def("Period", (Standard_Real (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Period, "None");
cls_Adaptor2d_HCurve2d.def("Value", (gp_Pnt2d (Adaptor2d_HCurve2d::*)(const Standard_Real) const) &Adaptor2d_HCurve2d::Value, "None", py::arg("U"));
cls_Adaptor2d_HCurve2d.def("D0", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &) const) &Adaptor2d_HCurve2d::D0, "None", py::arg("U"), py::arg("P"));
cls_Adaptor2d_HCurve2d.def("D1", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Adaptor2d_HCurve2d::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor2d_HCurve2d.def("D2", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_HCurve2d::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor2d_HCurve2d.def("D3", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_HCurve2d::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor2d_HCurve2d.def("DN", (gp_Vec2d (Adaptor2d_HCurve2d::*)(const Standard_Real, const Standard_Integer) const) &Adaptor2d_HCurve2d::DN, "None", py::arg("U"), py::arg("N"));
cls_Adaptor2d_HCurve2d.def("Resolution", (Standard_Real (Adaptor2d_HCurve2d::*)(const Standard_Real) const) &Adaptor2d_HCurve2d::Resolution, "None", py::arg("R3d"));
cls_Adaptor2d_HCurve2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::GetType, "None");
cls_Adaptor2d_HCurve2d.def("Line", (gp_Lin2d (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Line, "None");
cls_Adaptor2d_HCurve2d.def("Circle", (gp_Circ2d (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Circle, "None");
cls_Adaptor2d_HCurve2d.def("Ellipse", (gp_Elips2d (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Ellipse, "None");
cls_Adaptor2d_HCurve2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Hyperbola, "None");
cls_Adaptor2d_HCurve2d.def("Parabola", (gp_Parab2d (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Parabola, "None");
cls_Adaptor2d_HCurve2d.def("Degree", (Standard_Integer (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Degree, "None");
cls_Adaptor2d_HCurve2d.def("IsRational", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::IsRational, "None");
cls_Adaptor2d_HCurve2d.def("NbPoles", (Standard_Integer (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::NbPoles, "None");
cls_Adaptor2d_HCurve2d.def("NbKnots", (Standard_Integer (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::NbKnots, "None");
cls_Adaptor2d_HCurve2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::Bezier, "None");
cls_Adaptor2d_HCurve2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::BSpline, "None");
cls_Adaptor2d_HCurve2d.def_static("get_type_name_", (const char * (*)()) &Adaptor2d_HCurve2d::get_type_name, "None");
cls_Adaptor2d_HCurve2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor2d_HCurve2d::get_type_descriptor, "None");
cls_Adaptor2d_HCurve2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor2d_HCurve2d::*)() const) &Adaptor2d_HCurve2d::DynamicType, "None");

// Enums

}