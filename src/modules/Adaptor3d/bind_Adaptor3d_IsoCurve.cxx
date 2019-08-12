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
#include <GeomAbs_IsoType.hxx>
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
#include <Adaptor3d_IsoCurve.hxx>

void bind_Adaptor3d_IsoCurve(py::module &mod){

py::class_<Adaptor3d_IsoCurve, std::unique_ptr<Adaptor3d_IsoCurve, Deleter<Adaptor3d_IsoCurve>>, Adaptor3d_Curve> cls_Adaptor3d_IsoCurve(mod, "Adaptor3d_IsoCurve", "Defines an isoparametric curve on a surface. The type of isoparametric curve (U or V) is defined with the enumeration IsoType from GeomAbs if NoneIso is given an error is raised.");

// Constructors
cls_Adaptor3d_IsoCurve.def(py::init<>());
cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_IsoType, const Standard_Real>(), py::arg("S"), py::arg("Iso"), py::arg("Param"));
cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Iso"), py::arg("Param"), py::arg("WFirst"), py::arg("WLast"));

// Fields

// Methods
// cls_Adaptor3d_IsoCurve.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_IsoCurve::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_IsoCurve.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_IsoCurve::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_IsoCurve.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_IsoCurve::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_IsoCurve.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_IsoCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_IsoCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_IsoCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_IsoCurve.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_IsoCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_IsoCurve::Load, "Changes the surface. The iso is reset to NoneIso.", py::arg("S"));
cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const GeomAbs_IsoType, const Standard_Real)) &Adaptor3d_IsoCurve::Load, "Changes the iso on the current surface.", py::arg("Iso"), py::arg("Param"));
cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_IsoCurve::Load, "Changes the iso on the current surface.", py::arg("Iso"), py::arg("Param"), py::arg("WFirst"), py::arg("WLast"));
cls_Adaptor3d_IsoCurve.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Surface, "None");
cls_Adaptor3d_IsoCurve.def("Iso", (GeomAbs_IsoType (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Iso, "None");
cls_Adaptor3d_IsoCurve.def("Parameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Parameter, "None");
cls_Adaptor3d_IsoCurve.def("FirstParameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::FirstParameter, "None");
cls_Adaptor3d_IsoCurve.def("LastParameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::LastParameter, "None");
cls_Adaptor3d_IsoCurve.def("Continuity", (GeomAbs_Shape (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Continuity, "None");
cls_Adaptor3d_IsoCurve.def("NbIntervals", (Standard_Integer (Adaptor3d_IsoCurve::*)(const GeomAbs_Shape) const) &Adaptor3d_IsoCurve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Adaptor3d_IsoCurve.def("Intervals", (void (Adaptor3d_IsoCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_IsoCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_IsoCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_IsoCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_IsoCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_IsoCurve.def("IsClosed", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::IsClosed, "None");
cls_Adaptor3d_IsoCurve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::IsPeriodic, "None");
cls_Adaptor3d_IsoCurve.def("Period", (Standard_Real (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Period, "None");
cls_Adaptor3d_IsoCurve.def("Value", (gp_Pnt (Adaptor3d_IsoCurve::*)(const Standard_Real) const) &Adaptor3d_IsoCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_Adaptor3d_IsoCurve.def("D0", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &) const) &Adaptor3d_IsoCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_Adaptor3d_IsoCurve.def("D1", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Adaptor3d_IsoCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_Adaptor3d_IsoCurve.def("D2", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_IsoCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor3d_IsoCurve.def("D3", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_IsoCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor3d_IsoCurve.def("DN", (gp_Vec (Adaptor3d_IsoCurve::*)(const Standard_Real, const Standard_Integer) const) &Adaptor3d_IsoCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Adaptor3d_IsoCurve.def("Resolution", (Standard_Real (Adaptor3d_IsoCurve::*)(const Standard_Real) const) &Adaptor3d_IsoCurve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor3d_IsoCurve.def("GetType", (GeomAbs_CurveType (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_Adaptor3d_IsoCurve.def("Line", (gp_Lin (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Line, "None");
cls_Adaptor3d_IsoCurve.def("Circle", (gp_Circ (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Circle, "None");
cls_Adaptor3d_IsoCurve.def("Ellipse", (gp_Elips (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Ellipse, "None");
cls_Adaptor3d_IsoCurve.def("Hyperbola", (gp_Hypr (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Hyperbola, "None");
cls_Adaptor3d_IsoCurve.def("Parabola", (gp_Parab (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Parabola, "None");
cls_Adaptor3d_IsoCurve.def("Degree", (Standard_Integer (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Degree, "None");
cls_Adaptor3d_IsoCurve.def("IsRational", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::IsRational, "None");
cls_Adaptor3d_IsoCurve.def("NbPoles", (Standard_Integer (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::NbPoles, "None");
cls_Adaptor3d_IsoCurve.def("NbKnots", (Standard_Integer (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::NbKnots, "None");
cls_Adaptor3d_IsoCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::Bezier, "None");
cls_Adaptor3d_IsoCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_IsoCurve::*)() const) &Adaptor3d_IsoCurve::BSpline, "None");

// Enums

}