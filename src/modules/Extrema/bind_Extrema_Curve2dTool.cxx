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
#include <Adaptor2d_Curve2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
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
#include <Extrema_Curve2dTool.hxx>

void bind_Extrema_Curve2dTool(py::module &mod){

py::class_<Extrema_Curve2dTool, std::unique_ptr<Extrema_Curve2dTool, Deleter<Extrema_Curve2dTool>>> cls_Extrema_Curve2dTool(mod, "Extrema_Curve2dTool", "None");

// Constructors

// Fields

// Methods
// cls_Extrema_Curve2dTool.def_static("operator new_", (void * (*)(size_t)) &Extrema_Curve2dTool::operator new, "None", py::arg("theSize"));
// cls_Extrema_Curve2dTool.def_static("operator delete_", (void (*)(void *)) &Extrema_Curve2dTool::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_Curve2dTool::operator new[], "None", py::arg("theSize"));
// cls_Extrema_Curve2dTool.def_static("operator delete[]_", (void (*)(void *)) &Extrema_Curve2dTool::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_Curve2dTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_Curve2dTool.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_Curve2dTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_Curve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::FirstParameter, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::LastParameter, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Continuity, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const Adaptor2d_Curve2d &, const GeomAbs_Shape)) &Extrema_Curve2dTool::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("C"), py::arg("S"));
cls_Extrema_Curve2dTool.def_static("Intervals_", (void (*)(const Adaptor2d_Curve2d &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Extrema_Curve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_Extrema_Curve2dTool.def_static("DeflCurvIntervals_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::DeflCurvIntervals, "Returns the parameters bounding the intervals of subdivision of curve according to Curvature deflection. Value of deflection is defined in method.", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsClosed, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsPeriodic, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Period_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Period, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Value_", (gp_Pnt2d (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Extrema_Curve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_Extrema_Curve2dTool.def_static("D0_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &)) &Extrema_Curve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Extrema_Curve2dTool.def_static("D1_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_Extrema_Curve2dTool.def_static("D2_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Extrema_Curve2dTool.def_static("D3_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Extrema_Curve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Extrema_Curve2dTool.def_static("DN_", (gp_Vec2d (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Integer)) &Extrema_Curve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Extrema_Curve2dTool.def_static("Resolution_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Extrema_Curve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_Extrema_Curve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Line_", (gp_Lin2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Line, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Circle_", (gp_Circ2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Circle, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Ellipse, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Hyperbola, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Parabola, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Degree, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("IsRational_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::IsRational, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbPoles_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::NbPoles, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("NbKnots_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::NbKnots, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::Bezier, "None", py::arg("C"));
cls_Extrema_Curve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const Adaptor2d_Curve2d &)) &Extrema_Curve2dTool::BSpline, "None", py::arg("C"));

// Enums

}