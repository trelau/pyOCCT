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
#include <TopoDS_Edge.hxx>
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
#include <Geom_Curve.hxx>
#include <BiTgte_CurveOnEdge.hxx>

void bind_BiTgte_CurveOnEdge(py::module &mod){

py::class_<BiTgte_CurveOnEdge, std::unique_ptr<BiTgte_CurveOnEdge, Deleter<BiTgte_CurveOnEdge>>, Adaptor3d_Curve> cls_BiTgte_CurveOnEdge(mod, "BiTgte_CurveOnEdge", "private class used to create a filler rolling on an edge.");

// Constructors
cls_BiTgte_CurveOnEdge.def(py::init<>());
cls_BiTgte_CurveOnEdge.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("EonF"), py::arg("Edge"));

// Fields

// Methods
// cls_BiTgte_CurveOnEdge.def_static("operator new_", (void * (*)(size_t)) &BiTgte_CurveOnEdge::operator new, "None", py::arg("theSize"));
// cls_BiTgte_CurveOnEdge.def_static("operator delete_", (void (*)(void *)) &BiTgte_CurveOnEdge::operator delete, "None", py::arg("theAddress"));
// cls_BiTgte_CurveOnEdge.def_static("operator new[]_", (void * (*)(size_t)) &BiTgte_CurveOnEdge::operator new[], "None", py::arg("theSize"));
// cls_BiTgte_CurveOnEdge.def_static("operator delete[]_", (void (*)(void *)) &BiTgte_CurveOnEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BiTgte_CurveOnEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BiTgte_CurveOnEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BiTgte_CurveOnEdge.def_static("operator delete_", (void (*)(void *, void *)) &BiTgte_CurveOnEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BiTgte_CurveOnEdge.def("Init", (void (BiTgte_CurveOnEdge::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BiTgte_CurveOnEdge::Init, "None", py::arg("EonF"), py::arg("Edge"));
cls_BiTgte_CurveOnEdge.def("FirstParameter", (Standard_Real (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::FirstParameter, "None");
cls_BiTgte_CurveOnEdge.def("LastParameter", (Standard_Real (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::LastParameter, "None");
cls_BiTgte_CurveOnEdge.def("Continuity", (GeomAbs_Shape (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Continuity, "None");
cls_BiTgte_CurveOnEdge.def("NbIntervals", (Standard_Integer (BiTgte_CurveOnEdge::*)(const GeomAbs_Shape) const) &BiTgte_CurveOnEdge::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BiTgte_CurveOnEdge.def("Intervals", (void (BiTgte_CurveOnEdge::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BiTgte_CurveOnEdge::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BiTgte_CurveOnEdge.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BiTgte_CurveOnEdge::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BiTgte_CurveOnEdge::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BiTgte_CurveOnEdge.def("IsClosed", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::IsClosed, "None");
cls_BiTgte_CurveOnEdge.def("IsPeriodic", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::IsPeriodic, "None");
cls_BiTgte_CurveOnEdge.def("Period", (Standard_Real (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Period, "None");
cls_BiTgte_CurveOnEdge.def("Value", (gp_Pnt (BiTgte_CurveOnEdge::*)(const Standard_Real) const) &BiTgte_CurveOnEdge::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_BiTgte_CurveOnEdge.def("D0", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &) const) &BiTgte_CurveOnEdge::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_BiTgte_CurveOnEdge.def("D1", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &BiTgte_CurveOnEdge::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_BiTgte_CurveOnEdge.def("D2", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BiTgte_CurveOnEdge::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BiTgte_CurveOnEdge.def("D3", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BiTgte_CurveOnEdge::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BiTgte_CurveOnEdge.def("DN", (gp_Vec (BiTgte_CurveOnEdge::*)(const Standard_Real, const Standard_Integer) const) &BiTgte_CurveOnEdge::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_BiTgte_CurveOnEdge.def("Resolution", (Standard_Real (BiTgte_CurveOnEdge::*)(const Standard_Real) const) &BiTgte_CurveOnEdge::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_BiTgte_CurveOnEdge.def("GetType", (GeomAbs_CurveType (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_BiTgte_CurveOnEdge.def("Line", (gp_Lin (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Line, "None");
cls_BiTgte_CurveOnEdge.def("Circle", (gp_Circ (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Circle, "None");
cls_BiTgte_CurveOnEdge.def("Ellipse", (gp_Elips (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Ellipse, "None");
cls_BiTgte_CurveOnEdge.def("Hyperbola", (gp_Hypr (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Hyperbola, "None");
cls_BiTgte_CurveOnEdge.def("Parabola", (gp_Parab (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Parabola, "None");
cls_BiTgte_CurveOnEdge.def("Degree", (Standard_Integer (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Degree, "None");
cls_BiTgte_CurveOnEdge.def("IsRational", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::IsRational, "None");
cls_BiTgte_CurveOnEdge.def("NbPoles", (Standard_Integer (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::NbPoles, "None");
cls_BiTgte_CurveOnEdge.def("NbKnots", (Standard_Integer (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::NbKnots, "None");
cls_BiTgte_CurveOnEdge.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::Bezier, "None");
cls_BiTgte_CurveOnEdge.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BiTgte_CurveOnEdge::*)() const) &BiTgte_CurveOnEdge::BSpline, "None");

// Enums

}