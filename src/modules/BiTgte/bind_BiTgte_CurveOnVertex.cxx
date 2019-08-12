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
#include <TopoDS_Vertex.hxx>
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
#include <BiTgte_CurveOnVertex.hxx>

void bind_BiTgte_CurveOnVertex(py::module &mod){

py::class_<BiTgte_CurveOnVertex, std::unique_ptr<BiTgte_CurveOnVertex, Deleter<BiTgte_CurveOnVertex>>, Adaptor3d_Curve> cls_BiTgte_CurveOnVertex(mod, "BiTgte_CurveOnVertex", "private class used to create a filler rolling on an edge.");

// Constructors
cls_BiTgte_CurveOnVertex.def(py::init<>());
cls_BiTgte_CurveOnVertex.def(py::init<const TopoDS_Edge &, const TopoDS_Vertex &>(), py::arg("EonF"), py::arg("V"));

// Fields

// Methods
// cls_BiTgte_CurveOnVertex.def_static("operator new_", (void * (*)(size_t)) &BiTgte_CurveOnVertex::operator new, "None", py::arg("theSize"));
// cls_BiTgte_CurveOnVertex.def_static("operator delete_", (void (*)(void *)) &BiTgte_CurveOnVertex::operator delete, "None", py::arg("theAddress"));
// cls_BiTgte_CurveOnVertex.def_static("operator new[]_", (void * (*)(size_t)) &BiTgte_CurveOnVertex::operator new[], "None", py::arg("theSize"));
// cls_BiTgte_CurveOnVertex.def_static("operator delete[]_", (void (*)(void *)) &BiTgte_CurveOnVertex::operator delete[], "None", py::arg("theAddress"));
// cls_BiTgte_CurveOnVertex.def_static("operator new_", (void * (*)(size_t, void *)) &BiTgte_CurveOnVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BiTgte_CurveOnVertex.def_static("operator delete_", (void (*)(void *, void *)) &BiTgte_CurveOnVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BiTgte_CurveOnVertex.def("Init", (void (BiTgte_CurveOnVertex::*)(const TopoDS_Edge &, const TopoDS_Vertex &)) &BiTgte_CurveOnVertex::Init, "None", py::arg("EonF"), py::arg("V"));
cls_BiTgte_CurveOnVertex.def("FirstParameter", (Standard_Real (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::FirstParameter, "None");
cls_BiTgte_CurveOnVertex.def("LastParameter", (Standard_Real (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::LastParameter, "None");
cls_BiTgte_CurveOnVertex.def("Continuity", (GeomAbs_Shape (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Continuity, "None");
cls_BiTgte_CurveOnVertex.def("NbIntervals", (Standard_Integer (BiTgte_CurveOnVertex::*)(const GeomAbs_Shape) const) &BiTgte_CurveOnVertex::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BiTgte_CurveOnVertex.def("Intervals", (void (BiTgte_CurveOnVertex::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BiTgte_CurveOnVertex::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BiTgte_CurveOnVertex.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BiTgte_CurveOnVertex::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BiTgte_CurveOnVertex::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BiTgte_CurveOnVertex.def("IsClosed", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::IsClosed, "None");
cls_BiTgte_CurveOnVertex.def("IsPeriodic", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::IsPeriodic, "None");
cls_BiTgte_CurveOnVertex.def("Period", (Standard_Real (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Period, "None");
cls_BiTgte_CurveOnVertex.def("Value", (gp_Pnt (BiTgte_CurveOnVertex::*)(const Standard_Real) const) &BiTgte_CurveOnVertex::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_BiTgte_CurveOnVertex.def("D0", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &) const) &BiTgte_CurveOnVertex::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_BiTgte_CurveOnVertex.def("D1", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &BiTgte_CurveOnVertex::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_BiTgte_CurveOnVertex.def("D2", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BiTgte_CurveOnVertex::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BiTgte_CurveOnVertex.def("D3", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BiTgte_CurveOnVertex::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BiTgte_CurveOnVertex.def("DN", (gp_Vec (BiTgte_CurveOnVertex::*)(const Standard_Real, const Standard_Integer) const) &BiTgte_CurveOnVertex::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_BiTgte_CurveOnVertex.def("Resolution", (Standard_Real (BiTgte_CurveOnVertex::*)(const Standard_Real) const) &BiTgte_CurveOnVertex::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_BiTgte_CurveOnVertex.def("GetType", (GeomAbs_CurveType (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_BiTgte_CurveOnVertex.def("Line", (gp_Lin (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Line, "None");
cls_BiTgte_CurveOnVertex.def("Circle", (gp_Circ (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Circle, "None");
cls_BiTgte_CurveOnVertex.def("Ellipse", (gp_Elips (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Ellipse, "None");
cls_BiTgte_CurveOnVertex.def("Hyperbola", (gp_Hypr (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Hyperbola, "None");
cls_BiTgte_CurveOnVertex.def("Parabola", (gp_Parab (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Parabola, "None");
cls_BiTgte_CurveOnVertex.def("Degree", (Standard_Integer (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Degree, "None");
cls_BiTgte_CurveOnVertex.def("IsRational", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::IsRational, "None");
cls_BiTgte_CurveOnVertex.def("NbPoles", (Standard_Integer (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::NbPoles, "None");
cls_BiTgte_CurveOnVertex.def("NbKnots", (Standard_Integer (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::NbKnots, "None");
cls_BiTgte_CurveOnVertex.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::Bezier, "None");
cls_BiTgte_CurveOnVertex.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BiTgte_CurveOnVertex::*)() const) &BiTgte_CurveOnVertex::BSpline, "None");

// Enums

}