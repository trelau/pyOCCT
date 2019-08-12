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
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Standard_Type.hxx>

void bind_Adaptor3d_HCurve(py::module &mod){

py::class_<Adaptor3d_HCurve, opencascade::handle<Adaptor3d_HCurve>, Standard_Transient> cls_Adaptor3d_HCurve(mod, "Adaptor3d_HCurve", "Root class for 3D curves manipulated by handles, on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve and those required of the curve by algorithms which use it. Two derived concrete classes are provided: - GeomAdaptor_HCurve for a curve from the Geom package - Adaptor3d_HCurveOnSurface for a curve lying on a surface from the Geom package.");

// Fields

// Methods
cls_Adaptor3d_HCurve.def("Curve", (const Adaptor3d_Curve & (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Curve, "Returns a pointer to the Curve inside the HCurve.");
cls_Adaptor3d_HCurve.def("GetCurve", (Adaptor3d_Curve & (Adaptor3d_HCurve::*)()) &Adaptor3d_HCurve::GetCurve, "Returns a pointer to the Curve inside the HCurve.");
cls_Adaptor3d_HCurve.def("FirstParameter", (Standard_Real (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::FirstParameter, "None");
cls_Adaptor3d_HCurve.def("LastParameter", (Standard_Real (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::LastParameter, "None");
cls_Adaptor3d_HCurve.def("Continuity", (GeomAbs_Shape (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Continuity, "None");
cls_Adaptor3d_HCurve.def("NbIntervals", (Standard_Integer (Adaptor3d_HCurve::*)(const GeomAbs_Shape) const) &Adaptor3d_HCurve::NbIntervals, "None", py::arg("S"));
cls_Adaptor3d_HCurve.def("Intervals", (void (Adaptor3d_HCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_HCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_HCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_HCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_HCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion.", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_HCurve.def("IsClosed", (Standard_Boolean (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::IsClosed, "None");
cls_Adaptor3d_HCurve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::IsPeriodic, "None");
cls_Adaptor3d_HCurve.def("Period", (Standard_Real (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Period, "None");
cls_Adaptor3d_HCurve.def("Value", (gp_Pnt (Adaptor3d_HCurve::*)(const Standard_Real) const) &Adaptor3d_HCurve::Value, "None", py::arg("U"));
cls_Adaptor3d_HCurve.def("D0", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &) const) &Adaptor3d_HCurve::D0, "None", py::arg("U"), py::arg("P"));
cls_Adaptor3d_HCurve.def("D1", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Adaptor3d_HCurve::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor3d_HCurve.def("D2", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_HCurve::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor3d_HCurve.def("D3", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_HCurve::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor3d_HCurve.def("DN", (gp_Vec (Adaptor3d_HCurve::*)(const Standard_Real, const Standard_Integer) const) &Adaptor3d_HCurve::DN, "None", py::arg("U"), py::arg("N"));
cls_Adaptor3d_HCurve.def("Resolution", (Standard_Real (Adaptor3d_HCurve::*)(const Standard_Real) const) &Adaptor3d_HCurve::Resolution, "None", py::arg("R3d"));
cls_Adaptor3d_HCurve.def("GetType", (GeomAbs_CurveType (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::GetType, "None");
cls_Adaptor3d_HCurve.def("Line", (gp_Lin (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Line, "None");
cls_Adaptor3d_HCurve.def("Circle", (gp_Circ (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Circle, "None");
cls_Adaptor3d_HCurve.def("Ellipse", (gp_Elips (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Ellipse, "None");
cls_Adaptor3d_HCurve.def("Hyperbola", (gp_Hypr (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Hyperbola, "None");
cls_Adaptor3d_HCurve.def("Parabola", (gp_Parab (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Parabola, "None");
cls_Adaptor3d_HCurve.def("Degree", (Standard_Integer (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Degree, "None");
cls_Adaptor3d_HCurve.def("IsRational", (Standard_Boolean (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::IsRational, "None");
cls_Adaptor3d_HCurve.def("NbPoles", (Standard_Integer (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::NbPoles, "None");
cls_Adaptor3d_HCurve.def("NbKnots", (Standard_Integer (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::NbKnots, "None");
cls_Adaptor3d_HCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::Bezier, "None");
cls_Adaptor3d_HCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::BSpline, "None");
cls_Adaptor3d_HCurve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::OffsetCurve, "None");
cls_Adaptor3d_HCurve.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HCurve::get_type_name, "None");
cls_Adaptor3d_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HCurve::get_type_descriptor, "None");
cls_Adaptor3d_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HCurve::*)() const) &Adaptor3d_HCurve::DynamicType, "None");

// Enums

}