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
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
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
#include <BRepBlend_HCurve2dTool.hxx>

void bind_BRepBlend_HCurve2dTool(py::module &mod){

py::class_<BRepBlend_HCurve2dTool> cls_BRepBlend_HCurve2dTool(mod, "BRepBlend_HCurve2dTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepBlend_HCurve2dTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_HCurve2dTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_HCurve2dTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_HCurve2dTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_HCurve2dTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_HCurve2dTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_HCurve2dTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_HCurve2dTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_HCurve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::FirstParameter, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::LastParameter, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Continuity, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const GeomAbs_Shape)) &BRepBlend_HCurve2dTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_BRepBlend_HCurve2dTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepBlend_HCurve2dTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_BRepBlend_HCurve2dTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::IsClosed, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::IsPeriodic, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Period, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Value_", (gp_Pnt2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &BRepBlend_HCurve2dTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_BRepBlend_HCurve2dTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &)) &BRepBlend_HCurve2dTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_BRepBlend_HCurve2dTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepBlend_HCurve2dTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepBlend_HCurve2dTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &BRepBlend_HCurve2dTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBlend_HCurve2dTool.def_static("DN_", (gp_Vec2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer)) &BRepBlend_HCurve2dTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_BRepBlend_HCurve2dTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real)) &BRepBlend_HCurve2dTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_BRepBlend_HCurve2dTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Line_", (gp_Lin2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Line, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Circle_", (gp_Circ2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Circle, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Ellipse_", (gp_Elips2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Ellipse, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Hyperbola, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Parabola_", (gp_Parab2d (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Parabola, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::Bezier, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_HCurve2dTool::BSpline, "None", py::arg("C"));
cls_BRepBlend_HCurve2dTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &BRepBlend_HCurve2dTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// Enums

}