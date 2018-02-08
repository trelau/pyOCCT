/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Adaptor2d_Curve2d.hxx>
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
#include <Standard_Type.hxx>
#include <Adaptor2d_Curve2dPtr.hxx>
#include <gp_Dir2d.hxx>
#include <Adaptor2d_Line2d.hxx>
#include <Adaptor2d_HLine2d.hxx>
#include <Adaptor2d_OffsetCurve.hxx>
#include <Adaptor2d_HOffsetCurve.hxx>

PYBIND11_MODULE(Adaptor2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_HCurve2d.hxx
	py::class_<Adaptor2d_HCurve2d, opencascade::handle<Adaptor2d_HCurve2d>, Standard_Transient> cls_Adaptor2d_HCurve2d(mod, "Adaptor2d_HCurve2d", "Root class for 2D curves manipulated by handles, on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve, and those required of the curve by algorithms, which use it. A derived specific class is provided: Geom2dAdaptor_HCurve for a curve from the Geom2d package.");
	cls_Adaptor2d_HCurve2d.def("Curve2d", (const Adaptor2d_Curve2d & (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Curve2d, "Returns a reference to the Curve2d inside the HCurve2d.");
	cls_Adaptor2d_HCurve2d.def("FirstParameter", (Standard_Real (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::FirstParameter, "None");
	cls_Adaptor2d_HCurve2d.def("LastParameter", (Standard_Real (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::LastParameter, "None");
	cls_Adaptor2d_HCurve2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Continuity, "None");
	cls_Adaptor2d_HCurve2d.def("NbIntervals", (Standard_Integer (Adaptor2d_HCurve2d::*)(const GeomAbs_Shape) const ) &Adaptor2d_HCurve2d::NbIntervals, "None", py::arg("S"));
	cls_Adaptor2d_HCurve2d.def("Intervals", (void (Adaptor2d_HCurve2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor2d_HCurve2d::Intervals, "None", py::arg("T"), py::arg("S"));
	cls_Adaptor2d_HCurve2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_HCurve2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor2d_HCurve2d::Trim, "If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor2d_HCurve2d.def("IsClosed", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::IsClosed, "None");
	cls_Adaptor2d_HCurve2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::IsPeriodic, "None");
	cls_Adaptor2d_HCurve2d.def("Period", (Standard_Real (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Period, "None");
	cls_Adaptor2d_HCurve2d.def("Value", (gp_Pnt2d (Adaptor2d_HCurve2d::*)(const Standard_Real) const ) &Adaptor2d_HCurve2d::Value, "None", py::arg("U"));
	cls_Adaptor2d_HCurve2d.def("D0", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &) const ) &Adaptor2d_HCurve2d::D0, "None", py::arg("U"), py::arg("P"));
	cls_Adaptor2d_HCurve2d.def("D1", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Adaptor2d_HCurve2d::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor2d_HCurve2d.def("D2", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_HCurve2d::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor2d_HCurve2d.def("D3", (void (Adaptor2d_HCurve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_HCurve2d::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor2d_HCurve2d.def("DN", (gp_Vec2d (Adaptor2d_HCurve2d::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor2d_HCurve2d::DN, "None", py::arg("U"), py::arg("N"));
	cls_Adaptor2d_HCurve2d.def("Resolution", (Standard_Real (Adaptor2d_HCurve2d::*)(const Standard_Real) const ) &Adaptor2d_HCurve2d::Resolution, "None", py::arg("R3d"));
	cls_Adaptor2d_HCurve2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::GetType, "None");
	cls_Adaptor2d_HCurve2d.def("Line", (gp_Lin2d (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Line, "None");
	cls_Adaptor2d_HCurve2d.def("Circle", (gp_Circ2d (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Circle, "None");
	cls_Adaptor2d_HCurve2d.def("Ellipse", (gp_Elips2d (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Ellipse, "None");
	cls_Adaptor2d_HCurve2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Hyperbola, "None");
	cls_Adaptor2d_HCurve2d.def("Parabola", (gp_Parab2d (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Parabola, "None");
	cls_Adaptor2d_HCurve2d.def("Degree", (Standard_Integer (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Degree, "None");
	cls_Adaptor2d_HCurve2d.def("IsRational", (Standard_Boolean (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::IsRational, "None");
	cls_Adaptor2d_HCurve2d.def("NbPoles", (Standard_Integer (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::NbPoles, "None");
	cls_Adaptor2d_HCurve2d.def("NbKnots", (Standard_Integer (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::NbKnots, "None");
	cls_Adaptor2d_HCurve2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::Bezier, "None");
	cls_Adaptor2d_HCurve2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::BSpline, "None");
	cls_Adaptor2d_HCurve2d.def_static("get_type_name_", (const char * (*)()) &Adaptor2d_HCurve2d::get_type_name, "None");
	cls_Adaptor2d_HCurve2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor2d_HCurve2d::get_type_descriptor, "None");
	cls_Adaptor2d_HCurve2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor2d_HCurve2d::*)() const ) &Adaptor2d_HCurve2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_Curve2d.hxx
	py::class_<Adaptor2d_Curve2d, std::unique_ptr<Adaptor2d_Curve2d, Deleter<Adaptor2d_Curve2d>>> cls_Adaptor2d_Curve2d(mod, "Adaptor2d_Curve2d", "Root class for 2D curves on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve, and those required of the curve by algorithms, which use it. A derived concrete class is provided: Geom2dAdaptor_Curve for a curve from the Geom2d package.");
	cls_Adaptor2d_Curve2d.def(py::init<>());
	cls_Adaptor2d_Curve2d.def("FirstParameter", (Standard_Real (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::FirstParameter, "None");
	cls_Adaptor2d_Curve2d.def("LastParameter", (Standard_Real (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::LastParameter, "None");
	cls_Adaptor2d_Curve2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Continuity, "None");
	cls_Adaptor2d_Curve2d.def("NbIntervals", (Standard_Integer (Adaptor2d_Curve2d::*)(const GeomAbs_Shape) const ) &Adaptor2d_Curve2d::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_Adaptor2d_Curve2d.def("Intervals", (void (Adaptor2d_Curve2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor2d_Curve2d::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor2d_Curve2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_Curve2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor2d_Curve2d::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor2d_Curve2d.def("IsClosed", (Standard_Boolean (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::IsClosed, "None");
	cls_Adaptor2d_Curve2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::IsPeriodic, "None");
	cls_Adaptor2d_Curve2d.def("Period", (Standard_Real (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Period, "None");
	cls_Adaptor2d_Curve2d.def("Value", (gp_Pnt2d (Adaptor2d_Curve2d::*)(const Standard_Real) const ) &Adaptor2d_Curve2d::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_Adaptor2d_Curve2d.def("D0", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &) const ) &Adaptor2d_Curve2d::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_Adaptor2d_Curve2d.def("D1", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Adaptor2d_Curve2d::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor2d_Curve2d.def("D2", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_Curve2d::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor2d_Curve2d.def("D3", (void (Adaptor2d_Curve2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_Curve2d::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor2d_Curve2d.def("DN", (gp_Vec2d (Adaptor2d_Curve2d::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor2d_Curve2d::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Adaptor2d_Curve2d.def("Resolution", (Standard_Real (Adaptor2d_Curve2d::*)(const Standard_Real) const ) &Adaptor2d_Curve2d::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor2d_Curve2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_Adaptor2d_Curve2d.def("Line", (gp_Lin2d (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Line, "None");
	cls_Adaptor2d_Curve2d.def("Circle", (gp_Circ2d (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Circle, "None");
	cls_Adaptor2d_Curve2d.def("Ellipse", (gp_Elips2d (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Ellipse, "None");
	cls_Adaptor2d_Curve2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Hyperbola, "None");
	cls_Adaptor2d_Curve2d.def("Parabola", (gp_Parab2d (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Parabola, "None");
	cls_Adaptor2d_Curve2d.def("Degree", (Standard_Integer (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Degree, "None");
	cls_Adaptor2d_Curve2d.def("IsRational", (Standard_Boolean (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::IsRational, "None");
	cls_Adaptor2d_Curve2d.def("NbPoles", (Standard_Integer (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::NbPoles, "None");
	cls_Adaptor2d_Curve2d.def("NbKnots", (Standard_Integer (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::NbKnots, "None");
	cls_Adaptor2d_Curve2d.def("NbSamples", (Standard_Integer (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::NbSamples, "None");
	cls_Adaptor2d_Curve2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::Bezier, "None");
	cls_Adaptor2d_Curve2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_Curve2d::*)() const ) &Adaptor2d_Curve2d::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_Line2d.hxx
	py::class_<Adaptor2d_Line2d, std::unique_ptr<Adaptor2d_Line2d, Deleter<Adaptor2d_Line2d>>, Adaptor2d_Curve2d> cls_Adaptor2d_Line2d(mod, "Adaptor2d_Line2d", "Use by the TopolTool to trim a surface.");
	cls_Adaptor2d_Line2d.def(py::init<>());
	cls_Adaptor2d_Line2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("D"), py::arg("UFirst"), py::arg("ULast"));
	cls_Adaptor2d_Line2d.def("Load", (void (Adaptor2d_Line2d::*)(const gp_Lin2d &)) &Adaptor2d_Line2d::Load, "None", py::arg("L"));
	cls_Adaptor2d_Line2d.def("Load", (void (Adaptor2d_Line2d::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &Adaptor2d_Line2d::Load, "None", py::arg("L"), py::arg("UFirst"), py::arg("ULast"));
	cls_Adaptor2d_Line2d.def("FirstParameter", (Standard_Real (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::FirstParameter, "None");
	cls_Adaptor2d_Line2d.def("LastParameter", (Standard_Real (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::LastParameter, "None");
	cls_Adaptor2d_Line2d.def("Continuity", (GeomAbs_Shape (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Continuity, "None");
	cls_Adaptor2d_Line2d.def("NbIntervals", (Standard_Integer (Adaptor2d_Line2d::*)(const GeomAbs_Shape) const ) &Adaptor2d_Line2d::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_Adaptor2d_Line2d.def("Intervals", (void (Adaptor2d_Line2d::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor2d_Line2d::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor2d_Line2d.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_Line2d::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor2d_Line2d::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor2d_Line2d.def("IsClosed", (Standard_Boolean (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::IsClosed, "None");
	cls_Adaptor2d_Line2d.def("IsPeriodic", (Standard_Boolean (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::IsPeriodic, "None");
	cls_Adaptor2d_Line2d.def("Period", (Standard_Real (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Period, "None");
	cls_Adaptor2d_Line2d.def("Value", (gp_Pnt2d (Adaptor2d_Line2d::*)(const Standard_Real) const ) &Adaptor2d_Line2d::Value, "None", py::arg("X"));
	cls_Adaptor2d_Line2d.def("D0", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &) const ) &Adaptor2d_Line2d::D0, "None", py::arg("X"), py::arg("P"));
	cls_Adaptor2d_Line2d.def("D1", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Adaptor2d_Line2d::D1, "None", py::arg("X"), py::arg("P"), py::arg("V"));
	cls_Adaptor2d_Line2d.def("D2", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_Line2d::D2, "None", py::arg("X"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor2d_Line2d.def("D3", (void (Adaptor2d_Line2d::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_Line2d::D3, "None", py::arg("X"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor2d_Line2d.def("DN", (gp_Vec2d (Adaptor2d_Line2d::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor2d_Line2d::DN, "None", py::arg("U"), py::arg("N"));
	cls_Adaptor2d_Line2d.def("Resolution", (Standard_Real (Adaptor2d_Line2d::*)(const Standard_Real) const ) &Adaptor2d_Line2d::Resolution, "None", py::arg("R3d"));
	cls_Adaptor2d_Line2d.def("GetType", (GeomAbs_CurveType (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::GetType, "None");
	cls_Adaptor2d_Line2d.def("Line", (gp_Lin2d (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Line, "None");
	cls_Adaptor2d_Line2d.def("Circle", (gp_Circ2d (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Circle, "None");
	cls_Adaptor2d_Line2d.def("Ellipse", (gp_Elips2d (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Ellipse, "None");
	cls_Adaptor2d_Line2d.def("Hyperbola", (gp_Hypr2d (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Hyperbola, "None");
	cls_Adaptor2d_Line2d.def("Parabola", (gp_Parab2d (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Parabola, "None");
	cls_Adaptor2d_Line2d.def("Degree", (Standard_Integer (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Degree, "None");
	cls_Adaptor2d_Line2d.def("IsRational", (Standard_Boolean (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::IsRational, "None");
	cls_Adaptor2d_Line2d.def("NbPoles", (Standard_Integer (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::NbPoles, "None");
	cls_Adaptor2d_Line2d.def("NbKnots", (Standard_Integer (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::NbKnots, "None");
	cls_Adaptor2d_Line2d.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::Bezier, "None");
	cls_Adaptor2d_Line2d.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_Line2d::*)() const ) &Adaptor2d_Line2d::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_HLine2d.hxx
	py::class_<Adaptor2d_HLine2d, opencascade::handle<Adaptor2d_HLine2d>, Adaptor2d_HCurve2d> cls_Adaptor2d_HLine2d(mod, "Adaptor2d_HLine2d", "None");
	cls_Adaptor2d_HLine2d.def(py::init<>());
	cls_Adaptor2d_HLine2d.def(py::init<const Adaptor2d_Line2d &>(), py::arg("C"));
	cls_Adaptor2d_HLine2d.def("Set", (void (Adaptor2d_HLine2d::*)(const Adaptor2d_Line2d &)) &Adaptor2d_HLine2d::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_Adaptor2d_HLine2d.def("Curve2d", (const Adaptor2d_Curve2d & (Adaptor2d_HLine2d::*)() const ) &Adaptor2d_HLine2d::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_Adaptor2d_HLine2d.def("ChangeCurve2d", (Adaptor2d_Line2d & (Adaptor2d_HLine2d::*)()) &Adaptor2d_HLine2d::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_Adaptor2d_HLine2d.def_static("get_type_name_", (const char * (*)()) &Adaptor2d_HLine2d::get_type_name, "None");
	cls_Adaptor2d_HLine2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor2d_HLine2d::get_type_descriptor, "None");
	cls_Adaptor2d_HLine2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor2d_HLine2d::*)() const ) &Adaptor2d_HLine2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_OffsetCurve.hxx
	py::class_<Adaptor2d_OffsetCurve, std::unique_ptr<Adaptor2d_OffsetCurve, Deleter<Adaptor2d_OffsetCurve>>, Adaptor2d_Curve2d> cls_Adaptor2d_OffsetCurve(mod, "Adaptor2d_OffsetCurve", "Defines an Offset curve (algorithmic 2d curve).");
	cls_Adaptor2d_OffsetCurve.def(py::init<>());
	cls_Adaptor2d_OffsetCurve.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &>(), py::arg("C"));
	cls_Adaptor2d_OffsetCurve.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real>(), py::arg("C"), py::arg("Offset"));
	cls_Adaptor2d_OffsetCurve.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Offset"), py::arg("WFirst"), py::arg("WLast"));
	cls_Adaptor2d_OffsetCurve.def("Load", (void (Adaptor2d_OffsetCurve::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor2d_OffsetCurve::Load, "Changes the curve. The Offset is reset to 0.", py::arg("S"));
	cls_Adaptor2d_OffsetCurve.def("Load", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real)) &Adaptor2d_OffsetCurve::Load, "Changes the Offset on the current Curve.", py::arg("Offset"));
	cls_Adaptor2d_OffsetCurve.def("Load", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor2d_OffsetCurve::Load, "Changes the Offset Curve on the current Curve.", py::arg("Offset"), py::arg("WFirst"), py::arg("WLast"));
	cls_Adaptor2d_OffsetCurve.def("Curve", (const opencascade::handle<Adaptor2d_HCurve2d> & (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Curve, "None");
	cls_Adaptor2d_OffsetCurve.def("Offset", (Standard_Real (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Offset, "None");
	cls_Adaptor2d_OffsetCurve.def("FirstParameter", (Standard_Real (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::FirstParameter, "None");
	cls_Adaptor2d_OffsetCurve.def("LastParameter", (Standard_Real (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::LastParameter, "None");
	cls_Adaptor2d_OffsetCurve.def("Continuity", (GeomAbs_Shape (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Continuity, "None");
	cls_Adaptor2d_OffsetCurve.def("NbIntervals", (Standard_Integer (Adaptor2d_OffsetCurve::*)(const GeomAbs_Shape) const ) &Adaptor2d_OffsetCurve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_Adaptor2d_OffsetCurve.def("Intervals", (void (Adaptor2d_OffsetCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor2d_OffsetCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor2d_OffsetCurve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor2d_OffsetCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor2d_OffsetCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor2d_OffsetCurve.def("IsClosed", (Standard_Boolean (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::IsClosed, "None");
	cls_Adaptor2d_OffsetCurve.def("IsPeriodic", (Standard_Boolean (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::IsPeriodic, "None");
	cls_Adaptor2d_OffsetCurve.def("Period", (Standard_Real (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Period, "None");
	cls_Adaptor2d_OffsetCurve.def("Value", (gp_Pnt2d (Adaptor2d_OffsetCurve::*)(const Standard_Real) const ) &Adaptor2d_OffsetCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_Adaptor2d_OffsetCurve.def("D0", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &) const ) &Adaptor2d_OffsetCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_Adaptor2d_OffsetCurve.def("D1", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Adaptor2d_OffsetCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor2d_OffsetCurve.def("D2", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_OffsetCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor2d_OffsetCurve.def("D3", (void (Adaptor2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Adaptor2d_OffsetCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor2d_OffsetCurve.def("DN", (gp_Vec2d (Adaptor2d_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor2d_OffsetCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Adaptor2d_OffsetCurve.def("Resolution", (Standard_Real (Adaptor2d_OffsetCurve::*)(const Standard_Real) const ) &Adaptor2d_OffsetCurve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor2d_OffsetCurve.def("GetType", (GeomAbs_CurveType (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_Adaptor2d_OffsetCurve.def("Line", (gp_Lin2d (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Line, "None");
	cls_Adaptor2d_OffsetCurve.def("Circle", (gp_Circ2d (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Circle, "None");
	cls_Adaptor2d_OffsetCurve.def("Ellipse", (gp_Elips2d (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Ellipse, "None");
	cls_Adaptor2d_OffsetCurve.def("Hyperbola", (gp_Hypr2d (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Hyperbola, "None");
	cls_Adaptor2d_OffsetCurve.def("Parabola", (gp_Parab2d (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Parabola, "None");
	cls_Adaptor2d_OffsetCurve.def("Degree", (Standard_Integer (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Degree, "None");
	cls_Adaptor2d_OffsetCurve.def("IsRational", (Standard_Boolean (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::IsRational, "None");
	cls_Adaptor2d_OffsetCurve.def("NbPoles", (Standard_Integer (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::NbPoles, "None");
	cls_Adaptor2d_OffsetCurve.def("NbKnots", (Standard_Integer (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::NbKnots, "None");
	cls_Adaptor2d_OffsetCurve.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::Bezier, "None");
	cls_Adaptor2d_OffsetCurve.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Adaptor2d_OffsetCurve::*)() const ) &Adaptor2d_OffsetCurve::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_HOffsetCurve.hxx
	py::class_<Adaptor2d_HOffsetCurve, opencascade::handle<Adaptor2d_HOffsetCurve>, Adaptor2d_HCurve2d> cls_Adaptor2d_HOffsetCurve(mod, "Adaptor2d_HOffsetCurve", "None");
	cls_Adaptor2d_HOffsetCurve.def(py::init<>());
	cls_Adaptor2d_HOffsetCurve.def(py::init<const Adaptor2d_OffsetCurve &>(), py::arg("C"));
	cls_Adaptor2d_HOffsetCurve.def("Set", (void (Adaptor2d_HOffsetCurve::*)(const Adaptor2d_OffsetCurve &)) &Adaptor2d_HOffsetCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_Adaptor2d_HOffsetCurve.def("Curve2d", (const Adaptor2d_Curve2d & (Adaptor2d_HOffsetCurve::*)() const ) &Adaptor2d_HOffsetCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_Adaptor2d_HOffsetCurve.def("ChangeCurve2d", (Adaptor2d_OffsetCurve & (Adaptor2d_HOffsetCurve::*)()) &Adaptor2d_HOffsetCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_Adaptor2d_HOffsetCurve.def_static("get_type_name_", (const char * (*)()) &Adaptor2d_HOffsetCurve::get_type_name, "None");
	cls_Adaptor2d_HOffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor2d_HOffsetCurve::get_type_descriptor, "None");
	cls_Adaptor2d_HOffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor2d_HOffsetCurve::*)() const ) &Adaptor2d_HOffsetCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor2d_Curve2dPtr.hxx

}
