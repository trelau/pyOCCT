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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <AppParCurves_Constraint.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
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
#include <ProjLib_Projector.hxx>
#include <ProjLib_ProjectedCurve.hxx>

void bind_ProjLib_ProjectedCurve(py::module &mod){

py::class_<ProjLib_ProjectedCurve, Adaptor2d_Curve2d> cls_ProjLib_ProjectedCurve(mod, "ProjLib_ProjectedCurve", "Compute the 2d-curve. Try to solve the particular case if possible. Otherwize, an approximation is done. For approximation some parameters are used, including required tolerance of approximation. Tolerance is maximal possible value of 3d deviation of 3d projection of projected curve from 'exact' 3d projection. Since algorithm searches 2d curve on surface, required 2d tolerance is computed from 3d tolerance with help of U,V resolutions of surface. 3d and 2d tolerances have sence only for curves on surface, it defines precision of projecting and approximation and have nothing to do with distance between the projected curve and the surface.");

// Constructors
cls_ProjLib_ProjectedCurve.def(py::init<>());
cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));
cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("Tol"));

// Fields

// Methods
// cls_ProjLib_ProjectedCurve.def_static("operator new_", (void * (*)(size_t)) &ProjLib_ProjectedCurve::operator new, "None", py::arg("theSize"));
// cls_ProjLib_ProjectedCurve.def_static("operator delete_", (void (*)(void *)) &ProjLib_ProjectedCurve::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_ProjectedCurve.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_ProjectedCurve::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_ProjectedCurve.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_ProjectedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_ProjectedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_ProjectedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_ProjectedCurve.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_ProjectedCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_ProjectedCurve.def("Load", (void (ProjLib_ProjectedCurve::*)(const Standard_Real)) &ProjLib_ProjectedCurve::Load, "Changes the tolerance used to project the curve on the surface", py::arg("Tolerance"));
cls_ProjLib_ProjectedCurve.def("Load", (void (ProjLib_ProjectedCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ProjectedCurve::Load, "Changes the Surface.", py::arg("S"));
cls_ProjLib_ProjectedCurve.def("Perform", (void (ProjLib_ProjectedCurve::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &ProjLib_ProjectedCurve::Perform, "Performs projecting for given curve. If projecting uses approximation, approximation parameters can be set before by corresponding methods SetDegree(...), SetMaxSegmets(...), SetBndPnt(...), SetMaxDist(...)", py::arg("C"));
cls_ProjLib_ProjectedCurve.def("SetDegree", (void (ProjLib_ProjectedCurve::*)(const Standard_Integer, const Standard_Integer)) &ProjLib_ProjectedCurve::SetDegree, "Set min and max possible degree of result BSpline curve2d, which is got by approximation. If theDegMin/Max < 0, algorithm uses values that are chosen depending of types curve 3d and surface.", py::arg("theDegMin"), py::arg("theDegMax"));
cls_ProjLib_ProjectedCurve.def("SetMaxSegments", (void (ProjLib_ProjectedCurve::*)(const Standard_Integer)) &ProjLib_ProjectedCurve::SetMaxSegments, "Set the parameter, which defines maximal value of parametric intervals the projected curve can be cut for approximation. If theMaxSegments < 0, algorithm uses default value = 1000.", py::arg("theMaxSegments"));
cls_ProjLib_ProjectedCurve.def("SetBndPnt", (void (ProjLib_ProjectedCurve::*)(const AppParCurves_Constraint)) &ProjLib_ProjectedCurve::SetBndPnt, "Set the parameter, which defines type of boundary condition between segments during approximation. It can be AppParCurves_PassPoint or AppParCurves_TangencyPoint. Default value is AppParCurves_TangencyPoint;", py::arg("theBndPnt"));
cls_ProjLib_ProjectedCurve.def("SetMaxDist", (void (ProjLib_ProjectedCurve::*)(const Standard_Real)) &ProjLib_ProjectedCurve::SetMaxDist, "Set the parameter, which degines maximal possible distance between projected curve and surface. It uses only for projecting on not analytical surfaces. If theMaxDist < 0, algoritm uses default value 100.*Tolerance. If real distance between curve and surface more then theMaxDist, algorithm stops working.", py::arg("theMaxDist"));
cls_ProjLib_ProjectedCurve.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::GetSurface, "None");
cls_ProjLib_ProjectedCurve.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::GetCurve, "None");
cls_ProjLib_ProjectedCurve.def("GetTolerance", (Standard_Real (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::GetTolerance, "returns the tolerance reached if an approximation is Done.");
cls_ProjLib_ProjectedCurve.def("FirstParameter", (Standard_Real (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::FirstParameter, "None");
cls_ProjLib_ProjectedCurve.def("LastParameter", (Standard_Real (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::LastParameter, "None");
cls_ProjLib_ProjectedCurve.def("Continuity", (GeomAbs_Shape (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Continuity, "None");
cls_ProjLib_ProjectedCurve.def("NbIntervals", (Standard_Integer (ProjLib_ProjectedCurve::*)(const GeomAbs_Shape) const) &ProjLib_ProjectedCurve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_ProjLib_ProjectedCurve.def("Intervals", (void (ProjLib_ProjectedCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &ProjLib_ProjectedCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_ProjLib_ProjectedCurve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_ProjectedCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &ProjLib_ProjectedCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_ProjLib_ProjectedCurve.def("IsClosed", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::IsClosed, "None");
cls_ProjLib_ProjectedCurve.def("IsPeriodic", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::IsPeriodic, "None");
cls_ProjLib_ProjectedCurve.def("Period", (Standard_Real (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Period, "None");
cls_ProjLib_ProjectedCurve.def("Value", (gp_Pnt2d (ProjLib_ProjectedCurve::*)(const Standard_Real) const) &ProjLib_ProjectedCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_ProjLib_ProjectedCurve.def("D0", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &) const) &ProjLib_ProjectedCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_ProjLib_ProjectedCurve.def("D1", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &ProjLib_ProjectedCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_ProjLib_ProjectedCurve.def("D2", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &ProjLib_ProjectedCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ProjLib_ProjectedCurve.def("D3", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &ProjLib_ProjectedCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_ProjLib_ProjectedCurve.def("DN", (gp_Vec2d (ProjLib_ProjectedCurve::*)(const Standard_Real, const Standard_Integer) const) &ProjLib_ProjectedCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_ProjLib_ProjectedCurve.def("Resolution", (Standard_Real (ProjLib_ProjectedCurve::*)(const Standard_Real) const) &ProjLib_ProjectedCurve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_ProjLib_ProjectedCurve.def("GetType", (GeomAbs_CurveType (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
cls_ProjLib_ProjectedCurve.def("Line", (gp_Lin2d (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Line, "None");
cls_ProjLib_ProjectedCurve.def("Circle", (gp_Circ2d (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Circle, "None");
cls_ProjLib_ProjectedCurve.def("Ellipse", (gp_Elips2d (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Ellipse, "None");
cls_ProjLib_ProjectedCurve.def("Hyperbola", (gp_Hypr2d (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Hyperbola, "None");
cls_ProjLib_ProjectedCurve.def("Parabola", (gp_Parab2d (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Parabola, "None");
cls_ProjLib_ProjectedCurve.def("Degree", (Standard_Integer (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Degree, "None");
cls_ProjLib_ProjectedCurve.def("IsRational", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::IsRational, "None");
cls_ProjLib_ProjectedCurve.def("NbPoles", (Standard_Integer (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::NbPoles, "None");
cls_ProjLib_ProjectedCurve.def("NbKnots", (Standard_Integer (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::NbKnots, "None");
cls_ProjLib_ProjectedCurve.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::Bezier, "Warning ! This will NOT make a copy of the -- Bezier Curve - If you want to modify -- the Curve please make a copy yourself -- Also it will NOT trim the surface to -- myFirst/Last.");
cls_ProjLib_ProjectedCurve.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ProjectedCurve::*)() const) &ProjLib_ProjectedCurve::BSpline, "Warning ! This will NOT make a copy of the BSpline Curve - If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");

// Enums

}