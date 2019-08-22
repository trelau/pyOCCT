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
#include <Adaptor3d_Curve.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
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
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>

void bind_Adaptor3d_CurveOnSurface(py::module &mod){

py::class_<Adaptor3d_CurveOnSurface, Adaptor3d_Curve> cls_Adaptor3d_CurveOnSurface(mod, "Adaptor3d_CurveOnSurface", "An interface between the services provided by a curve lying on a surface from the package Geom and those required of the curve by algorithms which use it. The curve is defined as a 2D curve from the Geom2d package, in the parametric space of the surface.");

// Constructors
cls_Adaptor3d_CurveOnSurface.def(py::init<>());
cls_Adaptor3d_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
cls_Adaptor3d_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
// cls_Adaptor3d_CurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_CurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_CurveOnSurface.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_CurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_CurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_CurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_CurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_CurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_CurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_CurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_CurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_CurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_CurveOnSurface::Load, "Changes the surface.", py::arg("S"));
cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_CurveOnSurface::Load, "Changes the 2d curve.", py::arg("C"));
cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_CurveOnSurface::Load, "Load both curve and surface.", py::arg("C"), py::arg("S"));
cls_Adaptor3d_CurveOnSurface.def("GetCurve", (const opencascade::handle<Adaptor2d_HCurve2d> & (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::GetCurve, "None");
cls_Adaptor3d_CurveOnSurface.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::GetSurface, "None");
cls_Adaptor3d_CurveOnSurface.def("ChangeCurve", (opencascade::handle<Adaptor2d_HCurve2d> & (Adaptor3d_CurveOnSurface::*)()) &Adaptor3d_CurveOnSurface::ChangeCurve, "None");
cls_Adaptor3d_CurveOnSurface.def("ChangeSurface", (opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_CurveOnSurface::*)()) &Adaptor3d_CurveOnSurface::ChangeSurface, "None");
cls_Adaptor3d_CurveOnSurface.def("FirstParameter", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::FirstParameter, "None");
cls_Adaptor3d_CurveOnSurface.def("LastParameter", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::LastParameter, "None");
cls_Adaptor3d_CurveOnSurface.def("Continuity", (GeomAbs_Shape (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Continuity, "None");
cls_Adaptor3d_CurveOnSurface.def("NbIntervals", (Standard_Integer (Adaptor3d_CurveOnSurface::*)(const GeomAbs_Shape) const) &Adaptor3d_CurveOnSurface::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Adaptor3d_CurveOnSurface.def("Intervals", (void (Adaptor3d_CurveOnSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_CurveOnSurface::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_CurveOnSurface.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_CurveOnSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_CurveOnSurface::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_CurveOnSurface.def("IsClosed", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::IsClosed, "None");
cls_Adaptor3d_CurveOnSurface.def("IsPeriodic", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::IsPeriodic, "None");
cls_Adaptor3d_CurveOnSurface.def("Period", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Period, "None");
cls_Adaptor3d_CurveOnSurface.def("Value", (gp_Pnt (Adaptor3d_CurveOnSurface::*)(const Standard_Real) const) &Adaptor3d_CurveOnSurface::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_Adaptor3d_CurveOnSurface.def("D0", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &) const) &Adaptor3d_CurveOnSurface::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_Adaptor3d_CurveOnSurface.def("D1", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Adaptor3d_CurveOnSurface::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor3d_CurveOnSurface.def("D2", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_CurveOnSurface::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor3d_CurveOnSurface.def("D3", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_CurveOnSurface::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor3d_CurveOnSurface.def("DN", (gp_Vec (Adaptor3d_CurveOnSurface::*)(const Standard_Real, const Standard_Integer) const) &Adaptor3d_CurveOnSurface::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Adaptor3d_CurveOnSurface.def("Resolution", (Standard_Real (Adaptor3d_CurveOnSurface::*)(const Standard_Real) const) &Adaptor3d_CurveOnSurface::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor3d_CurveOnSurface.def("GetType", (GeomAbs_CurveType (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_Adaptor3d_CurveOnSurface.def("Line", (gp_Lin (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Line, "None");
cls_Adaptor3d_CurveOnSurface.def("Circle", (gp_Circ (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Circle, "None");
cls_Adaptor3d_CurveOnSurface.def("Ellipse", (gp_Elips (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Ellipse, "None");
cls_Adaptor3d_CurveOnSurface.def("Hyperbola", (gp_Hypr (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Hyperbola, "None");
cls_Adaptor3d_CurveOnSurface.def("Parabola", (gp_Parab (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Parabola, "None");
cls_Adaptor3d_CurveOnSurface.def("Degree", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Degree, "None");
cls_Adaptor3d_CurveOnSurface.def("IsRational", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::IsRational, "None");
cls_Adaptor3d_CurveOnSurface.def("NbPoles", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::NbPoles, "None");
cls_Adaptor3d_CurveOnSurface.def("NbKnots", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::NbKnots, "None");
cls_Adaptor3d_CurveOnSurface.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::Bezier, "None");
cls_Adaptor3d_CurveOnSurface.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_CurveOnSurface::*)() const) &Adaptor3d_CurveOnSurface::BSpline, "None");

// Enums

}