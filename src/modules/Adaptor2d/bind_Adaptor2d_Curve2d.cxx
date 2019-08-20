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
#include <Adaptor2d_Curve2d.hxx>

void bind_Adaptor2d_Curve2d(py::module &mod){

py::class_<Adaptor2d_Curve2d, std::unique_ptr<Adaptor2d_Curve2d>> cls_Adaptor2d_Curve2d(mod, "Adaptor2d_Curve2d", "Root class for 2D curves on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve, and those required of the curve by algorithms, which use it. A derived concrete class is provided: Geom2dAdaptor_Curve for a curve from the Geom2d package.");

// Constructors

// Fields

// Methods
// cls_Adaptor2d_Curve2d.def_static("operator new_", (void * (*)(size_t)) &Adaptor2d_Curve2d::operator new, "None", py::arg("theSize"));
// cls_Adaptor2d_Curve2d.def_static("operator delete_", (void (*)(void *)) &Adaptor2d_Curve2d::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor2d_Curve2d.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor2d_Curve2d::operator new[], "None", py::arg("theSize"));
// cls_Adaptor2d_Curve2d.def_static("operator delete[]_", (void (*)(void *)) &Adaptor2d_Curve2d::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor2d_Curve2d.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor2d_Curve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor2d_Curve2d.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor2d_Curve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor2d_Curve2d.def("FirstParameter", (Standard_Real (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::FirstParameter, "None");
cls_Adaptor2d_Curve2d.def("LastParameter", (Standard_Real (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::LastParameter, "None");
cls_Adaptor2d_Curve2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Continuity, "None");
cls_Adaptor2d_Curve2d.def("NbIntervals", (Standard_Integer (Adaptor2d_Curve2d::*)(const GeomAbs_Shape) const) &Adaptor2d_Curve2d::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_Adaptor2d_Curve2d.def("Intervals", (void (Adaptor2d_Curve2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor2d_Curve2d::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor2d_Curve2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_Curve2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor2d_Curve2d::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor2d_Curve2d.def("IsClosed", (Standard_Boolean (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::IsClosed, "None");
cls_Adaptor2d_Curve2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::IsPeriodic, "None");
cls_Adaptor2d_Curve2d.def("Period", (Standard_Real (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Period, "None");
cls_Adaptor2d_Curve2d.def("Value", (gp_Pnt2d (Adaptor2d_Curve2d::*)(const Standard_Real) const) &Adaptor2d_Curve2d::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_Adaptor2d_Curve2d.def("D0", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &) const) &Adaptor2d_Curve2d::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_Adaptor2d_Curve2d.def("D1", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Adaptor2d_Curve2d::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor2d_Curve2d.def("D2", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_Curve2d::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor2d_Curve2d.def("D3", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_Curve2d::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor2d_Curve2d.def("DN", (gp_Vec2d (Adaptor2d_Curve2d::*)(const Standard_Real, const Standard_Integer) const) &Adaptor2d_Curve2d::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Adaptor2d_Curve2d.def("Resolution", (Standard_Real (Adaptor2d_Curve2d::*)(const Standard_Real) const) &Adaptor2d_Curve2d::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor2d_Curve2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_Adaptor2d_Curve2d.def("Line", (gp_Lin2d (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Line, "None");
cls_Adaptor2d_Curve2d.def("Circle", (gp_Circ2d (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Circle, "None");
cls_Adaptor2d_Curve2d.def("Ellipse", (gp_Elips2d (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Ellipse, "None");
cls_Adaptor2d_Curve2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Hyperbola, "None");
cls_Adaptor2d_Curve2d.def("Parabola", (gp_Parab2d (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Parabola, "None");
cls_Adaptor2d_Curve2d.def("Degree", (Standard_Integer (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Degree, "None");
cls_Adaptor2d_Curve2d.def("IsRational", (Standard_Boolean (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::IsRational, "None");
cls_Adaptor2d_Curve2d.def("NbPoles", (Standard_Integer (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::NbPoles, "None");
cls_Adaptor2d_Curve2d.def("NbKnots", (Standard_Integer (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::NbKnots, "None");
cls_Adaptor2d_Curve2d.def("NbSamples", (Standard_Integer (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::NbSamples, "None");
cls_Adaptor2d_Curve2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::Bezier, "None");
cls_Adaptor2d_Curve2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_Curve2d::*)() const) &Adaptor2d_Curve2d::BSpline, "None");

// Enums

}