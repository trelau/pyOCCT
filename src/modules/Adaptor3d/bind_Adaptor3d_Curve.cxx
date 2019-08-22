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
#include <Adaptor3d_Curve.hxx>

void bind_Adaptor3d_Curve(py::module &mod){

py::class_<Adaptor3d_Curve> cls_Adaptor3d_Curve(mod, "Adaptor3d_Curve", "Root class for 3D curves on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve and those required of the curve by algorithms which use it. Two derived concrete classes are provided: - GeomAdaptor_Curve for a curve from the Geom package - Adaptor3d_CurveOnSurface for a curve lying on a surface from the Geom package.");

// Constructors

// Fields

// Methods
// cls_Adaptor3d_Curve.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_Curve::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_Curve.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_Curve::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_Curve.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_Curve::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_Curve.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_Curve.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_Curve.def("FirstParameter", (Standard_Real (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::FirstParameter, "None");
cls_Adaptor3d_Curve.def("LastParameter", (Standard_Real (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::LastParameter, "None");
cls_Adaptor3d_Curve.def("Continuity", (GeomAbs_Shape (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Continuity, "None");
cls_Adaptor3d_Curve.def("NbIntervals", (Standard_Integer (Adaptor3d_Curve::*)(const GeomAbs_Shape) const) &Adaptor3d_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Adaptor3d_Curve.def("Intervals", (void (Adaptor3d_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_Curve.def("IsClosed", (Standard_Boolean (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::IsClosed, "None");
cls_Adaptor3d_Curve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::IsPeriodic, "None");
cls_Adaptor3d_Curve.def("Period", (Standard_Real (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Period, "None");
cls_Adaptor3d_Curve.def("Value", (gp_Pnt (Adaptor3d_Curve::*)(const Standard_Real) const) &Adaptor3d_Curve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_Adaptor3d_Curve.def("D0", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &) const) &Adaptor3d_Curve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_Adaptor3d_Curve.def("D1", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Adaptor3d_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor3d_Curve.def("D2", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor3d_Curve.def("D3", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor3d_Curve.def("DN", (gp_Vec (Adaptor3d_Curve::*)(const Standard_Real, const Standard_Integer) const) &Adaptor3d_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Adaptor3d_Curve.def("Resolution", (Standard_Real (Adaptor3d_Curve::*)(const Standard_Real) const) &Adaptor3d_Curve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor3d_Curve.def("GetType", (GeomAbs_CurveType (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_Adaptor3d_Curve.def("Line", (gp_Lin (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Line, "None");
cls_Adaptor3d_Curve.def("Circle", (gp_Circ (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Circle, "None");
cls_Adaptor3d_Curve.def("Ellipse", (gp_Elips (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Ellipse, "None");
cls_Adaptor3d_Curve.def("Hyperbola", (gp_Hypr (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Hyperbola, "None");
cls_Adaptor3d_Curve.def("Parabola", (gp_Parab (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Parabola, "None");
cls_Adaptor3d_Curve.def("Degree", (Standard_Integer (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Degree, "None");
cls_Adaptor3d_Curve.def("IsRational", (Standard_Boolean (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::IsRational, "None");
cls_Adaptor3d_Curve.def("NbPoles", (Standard_Integer (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::NbPoles, "None");
cls_Adaptor3d_Curve.def("NbKnots", (Standard_Integer (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::NbKnots, "None");
cls_Adaptor3d_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::Bezier, "None");
cls_Adaptor3d_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::BSpline, "None");
cls_Adaptor3d_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (Adaptor3d_Curve::*)() const) &Adaptor3d_Curve::OffsetCurve, "None");

// Enums

}