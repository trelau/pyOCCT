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
#include <gp_Ax3.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
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
#include <ProjLib_ProjectOnPlane.hxx>

void bind_ProjLib_ProjectOnPlane(py::module &mod){

py::class_<ProjLib_ProjectOnPlane, std::unique_ptr<ProjLib_ProjectOnPlane>, Adaptor3d_Curve> cls_ProjLib_ProjectOnPlane(mod, "ProjLib_ProjectOnPlane", "Class used to project a 3d curve on a plane. The result will be a 3d curve.");

// Constructors
cls_ProjLib_ProjectOnPlane.def(py::init<>());
cls_ProjLib_ProjectOnPlane.def(py::init<const gp_Ax3 &>(), py::arg("Pl"));
cls_ProjLib_ProjectOnPlane.def(py::init<const gp_Ax3 &, const gp_Dir &>(), py::arg("Pl"), py::arg("D"));

// Fields

// Methods
// cls_ProjLib_ProjectOnPlane.def_static("operator new_", (void * (*)(size_t)) &ProjLib_ProjectOnPlane::operator new, "None", py::arg("theSize"));
// cls_ProjLib_ProjectOnPlane.def_static("operator delete_", (void (*)(void *)) &ProjLib_ProjectOnPlane::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_ProjectOnPlane.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_ProjectOnPlane::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_ProjectOnPlane.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_ProjectOnPlane::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_ProjectOnPlane.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_ProjectOnPlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_ProjectOnPlane.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_ProjectOnPlane::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_ProjectOnPlane.def("Load", [](ProjLib_ProjectOnPlane &self, const opencascade::handle<Adaptor3d_HCurve> & a0, const Standard_Real a1) -> void { return self.Load(a0, a1); });
cls_ProjLib_ProjectOnPlane.def("Load", (void (ProjLib_ProjectOnPlane::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Boolean)) &ProjLib_ProjectOnPlane::Load, "Sets the Curve and perform the projection. if <KeepParametrization> is true, the parametrization of the Projected Curve <PC> will be the same as the parametrization of the initial curve <C>. It meens: proj(C(u)) = PC(u) for each u. Otherwize, the parametrization may change.", py::arg("C"), py::arg("Tolerance"), py::arg("KeepParametrization"));
cls_ProjLib_ProjectOnPlane.def("GetPlane", (const gp_Ax3 & (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::GetPlane, "None");
cls_ProjLib_ProjectOnPlane.def("GetDirection", (const gp_Dir & (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::GetDirection, "None");
cls_ProjLib_ProjectOnPlane.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::GetCurve, "None");
cls_ProjLib_ProjectOnPlane.def("GetResult", (const opencascade::handle<GeomAdaptor_HCurve> & (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::GetResult, "None");
cls_ProjLib_ProjectOnPlane.def("FirstParameter", (Standard_Real (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::FirstParameter, "None");
cls_ProjLib_ProjectOnPlane.def("LastParameter", (Standard_Real (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::LastParameter, "None");
cls_ProjLib_ProjectOnPlane.def("Continuity", (GeomAbs_Shape (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Continuity, "None");
cls_ProjLib_ProjectOnPlane.def("NbIntervals", (Standard_Integer (ProjLib_ProjectOnPlane::*)(const GeomAbs_Shape) const) &ProjLib_ProjectOnPlane::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_ProjLib_ProjectOnPlane.def("Intervals", (void (ProjLib_ProjectOnPlane::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &ProjLib_ProjectOnPlane::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_ProjLib_ProjectOnPlane.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (ProjLib_ProjectOnPlane::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &ProjLib_ProjectOnPlane::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_ProjLib_ProjectOnPlane.def("IsClosed", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::IsClosed, "None");
cls_ProjLib_ProjectOnPlane.def("IsPeriodic", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::IsPeriodic, "None");
cls_ProjLib_ProjectOnPlane.def("Period", (Standard_Real (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Period, "None");
cls_ProjLib_ProjectOnPlane.def("Value", (gp_Pnt (ProjLib_ProjectOnPlane::*)(const Standard_Real) const) &ProjLib_ProjectOnPlane::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_ProjLib_ProjectOnPlane.def("D0", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &) const) &ProjLib_ProjectOnPlane::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_ProjLib_ProjectOnPlane.def("D1", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &ProjLib_ProjectOnPlane::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_ProjLib_ProjectOnPlane.def("D2", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &ProjLib_ProjectOnPlane::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ProjLib_ProjectOnPlane.def("D3", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &ProjLib_ProjectOnPlane::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_ProjLib_ProjectOnPlane.def("DN", (gp_Vec (ProjLib_ProjectOnPlane::*)(const Standard_Real, const Standard_Integer) const) &ProjLib_ProjectOnPlane::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_ProjLib_ProjectOnPlane.def("Resolution", (Standard_Real (ProjLib_ProjectOnPlane::*)(const Standard_Real) const) &ProjLib_ProjectOnPlane::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_ProjLib_ProjectOnPlane.def("GetType", (GeomAbs_CurveType (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_ProjLib_ProjectOnPlane.def("Line", (gp_Lin (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Line, "None");
cls_ProjLib_ProjectOnPlane.def("Circle", (gp_Circ (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Circle, "None");
cls_ProjLib_ProjectOnPlane.def("Ellipse", (gp_Elips (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Ellipse, "None");
cls_ProjLib_ProjectOnPlane.def("Hyperbola", (gp_Hypr (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Hyperbola, "None");
cls_ProjLib_ProjectOnPlane.def("Parabola", (gp_Parab (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Parabola, "None");
cls_ProjLib_ProjectOnPlane.def("Degree", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Degree, "None");
cls_ProjLib_ProjectOnPlane.def("IsRational", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::IsRational, "None");
cls_ProjLib_ProjectOnPlane.def("NbPoles", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::NbPoles, "None");
cls_ProjLib_ProjectOnPlane.def("NbKnots", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::NbKnots, "None");
cls_ProjLib_ProjectOnPlane.def("Bezier", (opencascade::handle<Geom_BezierCurve> (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::Bezier, "Warning ! this will NOT make a copy of the Bezier Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
cls_ProjLib_ProjectOnPlane.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ProjLib_ProjectOnPlane::*)() const) &ProjLib_ProjectOnPlane::BSpline, "Warning ! this will NOT make a copy of the BSpline Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");

// Enums

}