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
#include <Adaptor3d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Extrema_CurveTool.hxx>

void bind_Extrema_CurveTool(py::module &mod){

py::class_<Extrema_CurveTool> cls_Extrema_CurveTool(mod, "Extrema_CurveTool", "None");

// Constructors

// Fields

// Methods
// cls_Extrema_CurveTool.def_static("operator new_", (void * (*)(size_t)) &Extrema_CurveTool::operator new, "None", py::arg("theSize"));
// cls_Extrema_CurveTool.def_static("operator delete_", (void (*)(void *)) &Extrema_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::FirstParameter, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::LastParameter, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Continuity, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbIntervals_", (Standard_Integer (*)(Adaptor3d_Curve &, const GeomAbs_Shape)) &Extrema_CurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("C"), py::arg("S"));
cls_Extrema_CurveTool.def_static("Intervals_", (void (*)(Adaptor3d_Curve &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Extrema_CurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_Extrema_CurveTool.def_static("DeflCurvIntervals_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::DeflCurvIntervals, "Returns the parameters bounding the intervals of subdivision of curve according to Curvature deflection. Value of deflection is defined in method.", py::arg("C"));
cls_Extrema_CurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::IsPeriodic, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Period_", (Standard_Real (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Period, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Resolution_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &Extrema_CurveTool::Resolution, "None", py::arg("C"), py::arg("R3d"));
cls_Extrema_CurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::GetType, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Value_", (gp_Pnt (*)(const Adaptor3d_Curve &, const Standard_Real)) &Extrema_CurveTool::Value, "None", py::arg("C"), py::arg("U"));
cls_Extrema_CurveTool.def_static("D0_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &)) &Extrema_CurveTool::D0, "None", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Extrema_CurveTool.def_static("D1_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &Extrema_CurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_Extrema_CurveTool.def_static("D2_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &Extrema_CurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Extrema_CurveTool.def_static("D3_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Extrema_CurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Extrema_CurveTool.def_static("DN_", (gp_Vec (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Integer)) &Extrema_CurveTool::DN, "None", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Extrema_CurveTool.def_static("Line_", (gp_Lin (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Line, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Circle_", (gp_Circ (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Circle, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Ellipse_", (gp_Elips (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Ellipse, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Hyperbola, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Parabola_", (gp_Parab (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Parabola, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Degree, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("IsRational_", (Standard_Boolean (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::IsRational, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbPoles_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::NbPoles, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("NbKnots_", (Standard_Integer (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::NbKnots, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::Bezier, "None", py::arg("C"));
cls_Extrema_CurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const Adaptor3d_Curve &)) &Extrema_CurveTool::BSpline, "None", py::arg("C"));

// Enums

}