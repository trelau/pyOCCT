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
#include <Geom_Curve.hxx>
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
#include <Geom_OffsetCurve.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <BSplCLib_Cache.hxx>
#include <GeomEvaluator_Curve.hxx>
#include <GeomAdaptor_Curve.hxx>

void bind_GeomAdaptor_Curve(py::module &mod){

py::class_<GeomAdaptor_Curve, Adaptor3d_Curve> cls_GeomAdaptor_Curve(mod, "GeomAdaptor_Curve", "This class provides an interface between the services provided by any curve from the package Geom and those required of the curve by algorithms which use it. Creation of the loaded curve the curve is C1 by piece.");

// Constructors
cls_GeomAdaptor_Curve.def(py::init<>());
cls_GeomAdaptor_Curve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));
cls_GeomAdaptor_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UFirst"), py::arg("ULast"));

// Fields

// Methods
// cls_GeomAdaptor_Curve.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor_Curve::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor_Curve.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor_Curve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor_Curve::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor_Curve.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor_Curve.def("Load", (void (GeomAdaptor_Curve::*)(const opencascade::handle<Geom_Curve> &)) &GeomAdaptor_Curve::Load, "None", py::arg("C"));
cls_GeomAdaptor_Curve.def("Load", (void (GeomAdaptor_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAdaptor_Curve::Load, "ConstructionError is raised if Ufirst>Ulast", py::arg("C"), py::arg("UFirst"), py::arg("ULast"));
cls_GeomAdaptor_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Curve, "Provides a curve inherited from Hcurve from Adaptor. This is inherited to provide easy to use constructors.");
cls_GeomAdaptor_Curve.def("FirstParameter", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::FirstParameter, "None");
cls_GeomAdaptor_Curve.def("LastParameter", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::LastParameter, "None");
cls_GeomAdaptor_Curve.def("Continuity", (GeomAbs_Shape (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Continuity, "None");
cls_GeomAdaptor_Curve.def("NbIntervals", (Standard_Integer (GeomAdaptor_Curve::*)(const GeomAbs_Shape) const) &GeomAdaptor_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_Curve.def("Intervals", (void (GeomAdaptor_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (GeomAdaptor_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_Curve.def("IsClosed", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsClosed, "None");
cls_GeomAdaptor_Curve.def("IsPeriodic", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsPeriodic, "None");
cls_GeomAdaptor_Curve.def("Period", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Period, "None");
cls_GeomAdaptor_Curve.def("Value", (gp_Pnt (GeomAdaptor_Curve::*)(const Standard_Real) const) &GeomAdaptor_Curve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
cls_GeomAdaptor_Curve.def("D0", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &) const) &GeomAdaptor_Curve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
cls_GeomAdaptor_Curve.def("D1", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomAdaptor_Curve::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomAdaptor_Curve.def("D2", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomAdaptor_Curve.def("D3", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_GeomAdaptor_Curve.def("DN", (gp_Vec (GeomAdaptor_Curve::*)(const Standard_Real, const Standard_Integer) const) &GeomAdaptor_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Warning : On the specific case of BSplineCurve: if the curve is cut in interval of continuity CN, the derivatives are computed on the current interval. else the derivatives are computed on the basis curve. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_GeomAdaptor_Curve.def("Resolution", (Standard_Real (GeomAdaptor_Curve::*)(const Standard_Real) const) &GeomAdaptor_Curve::Resolution, "returns the parametric resolution", py::arg("R3d"));
cls_GeomAdaptor_Curve.def("GetType", (GeomAbs_CurveType (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::GetType, "None");
cls_GeomAdaptor_Curve.def("Line", (gp_Lin (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Line, "None");
cls_GeomAdaptor_Curve.def("Circle", (gp_Circ (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Circle, "None");
cls_GeomAdaptor_Curve.def("Ellipse", (gp_Elips (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Ellipse, "None");
cls_GeomAdaptor_Curve.def("Hyperbola", (gp_Hypr (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Hyperbola, "None");
cls_GeomAdaptor_Curve.def("Parabola", (gp_Parab (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Parabola, "None");
cls_GeomAdaptor_Curve.def("Degree", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Degree, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("IsRational", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsRational, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("NbPoles", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::NbPoles, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("NbKnots", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::NbKnots, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Bezier, "this will NOT make a copy of the Bezier Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
cls_GeomAdaptor_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::BSpline, "this will NOT make a copy of the BSpline Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
cls_GeomAdaptor_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::OffsetCurve, "None");

// Enums

}