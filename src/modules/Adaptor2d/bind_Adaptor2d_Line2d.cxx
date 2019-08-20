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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <gp_Ax2d.hxx>
#include <Adaptor2d_Line2d.hxx>

void bind_Adaptor2d_Line2d(py::module &mod){

py::class_<Adaptor2d_Line2d, std::unique_ptr<Adaptor2d_Line2d>, Adaptor2d_Curve2d> cls_Adaptor2d_Line2d(mod, "Adaptor2d_Line2d", "Use by the TopolTool to trim a surface.");

// Constructors
cls_Adaptor2d_Line2d.def(py::init<>());
cls_Adaptor2d_Line2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("D"), py::arg("UFirst"), py::arg("ULast"));

// Fields

// Methods
// cls_Adaptor2d_Line2d.def_static("operator new_", (void * (*)(size_t)) &Adaptor2d_Line2d::operator new, "None", py::arg("theSize"));
// cls_Adaptor2d_Line2d.def_static("operator delete_", (void (*)(void *)) &Adaptor2d_Line2d::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor2d_Line2d.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor2d_Line2d::operator new[], "None", py::arg("theSize"));
// cls_Adaptor2d_Line2d.def_static("operator delete[]_", (void (*)(void *)) &Adaptor2d_Line2d::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor2d_Line2d.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor2d_Line2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor2d_Line2d.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor2d_Line2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor2d_Line2d.def("Load", (void (Adaptor2d_Line2d::*)(const gp_Lin2d &)) &Adaptor2d_Line2d::Load, "None", py::arg("L"));
cls_Adaptor2d_Line2d.def("Load", (void (Adaptor2d_Line2d::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &Adaptor2d_Line2d::Load, "None", py::arg("L"), py::arg("UFirst"), py::arg("ULast"));
cls_Adaptor2d_Line2d.def("FirstParameter", (Standard_Real (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::FirstParameter, "None");
cls_Adaptor2d_Line2d.def("LastParameter", (Standard_Real (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::LastParameter, "None");
cls_Adaptor2d_Line2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Continuity, "None");
cls_Adaptor2d_Line2d.def("NbIntervals", (Standard_Integer (Adaptor2d_Line2d::*)(const GeomAbs_Shape) const) &Adaptor2d_Line2d::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_Adaptor2d_Line2d.def("Intervals", (void (Adaptor2d_Line2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor2d_Line2d::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Adaptor2d_Line2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_Line2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor2d_Line2d::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor2d_Line2d.def("IsClosed", (Standard_Boolean (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::IsClosed, "None");
cls_Adaptor2d_Line2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::IsPeriodic, "None");
cls_Adaptor2d_Line2d.def("Period", (Standard_Real (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Period, "None");
cls_Adaptor2d_Line2d.def("Value", (gp_Pnt2d (Adaptor2d_Line2d::*)(const Standard_Real) const) &Adaptor2d_Line2d::Value, "None", py::arg("X"));
cls_Adaptor2d_Line2d.def("D0", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &) const) &Adaptor2d_Line2d::D0, "None", py::arg("X"), py::arg("P"));
cls_Adaptor2d_Line2d.def("D1", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Adaptor2d_Line2d::D1, "None", py::arg("X"), py::arg("P"), py::arg("V"));
cls_Adaptor2d_Line2d.def("D2", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_Line2d::D2, "None", py::arg("X"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Adaptor2d_Line2d.def("D3", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Adaptor2d_Line2d::D3, "None", py::arg("X"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Adaptor2d_Line2d.def("DN", (gp_Vec2d (Adaptor2d_Line2d::*)(const Standard_Real, const Standard_Integer) const) &Adaptor2d_Line2d::DN, "None", py::arg("U"), py::arg("N"));
cls_Adaptor2d_Line2d.def("Resolution", (Standard_Real (Adaptor2d_Line2d::*)(const Standard_Real) const) &Adaptor2d_Line2d::Resolution, "None", py::arg("R3d"));
cls_Adaptor2d_Line2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::GetType, "None");
cls_Adaptor2d_Line2d.def("Line", (gp_Lin2d (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Line, "None");
cls_Adaptor2d_Line2d.def("Circle", (gp_Circ2d (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Circle, "None");
cls_Adaptor2d_Line2d.def("Ellipse", (gp_Elips2d (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Ellipse, "None");
cls_Adaptor2d_Line2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Hyperbola, "None");
cls_Adaptor2d_Line2d.def("Parabola", (gp_Parab2d (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Parabola, "None");
cls_Adaptor2d_Line2d.def("Degree", (Standard_Integer (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Degree, "None");
cls_Adaptor2d_Line2d.def("IsRational", (Standard_Boolean (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::IsRational, "None");
cls_Adaptor2d_Line2d.def("NbPoles", (Standard_Integer (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::NbPoles, "None");
cls_Adaptor2d_Line2d.def("NbKnots", (Standard_Integer (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::NbKnots, "None");
cls_Adaptor2d_Line2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::Bezier, "None");
cls_Adaptor2d_Line2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_Line2d::*)() const) &Adaptor2d_Line2d::BSpline, "None");

// Enums

}