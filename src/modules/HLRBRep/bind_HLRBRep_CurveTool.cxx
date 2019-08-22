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
#include <Standard_Handle.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <HLRBRep_CurveTool.hxx>

void bind_HLRBRep_CurveTool(py::module &mod){

py::class_<HLRBRep_CurveTool> cls_HLRBRep_CurveTool(mod, "HLRBRep_CurveTool", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_CurveTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CurveTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CurveTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const Standard_Address)) &HLRBRep_CurveTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Intervals_", (void (*)(const Standard_Address, TColStd_Array1OfReal &)) &HLRBRep_CurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"));
cls_HLRBRep_CurveTool.def_static("GetInterval_", [](const Standard_Address C, const Standard_Integer Index, const TColStd_Array1OfReal & Tab, Standard_Real & U1, Standard_Real & U2){ HLRBRep_CurveTool::GetInterval(C, Index, Tab, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "output the bounds of interval of index <Index> used if Type == Composite.", py::arg("C"), py::arg("Index"), py::arg("Tab"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep_CurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_CurveTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const Standard_Address)) &HLRBRep_CurveTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Period_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::Period, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Value_", (gp_Pnt2d (*)(const Standard_Address, const Standard_Real)) &HLRBRep_CurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_HLRBRep_CurveTool.def_static("D0_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &)) &HLRBRep_CurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_CurveTool.def_static("D1_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_CurveTool.def_static("D2_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_CurveTool.def_static("D3_", (void (*)(const Standard_Address, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &HLRBRep_CurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_CurveTool.def_static("DN_", (gp_Vec2d (*)(const Standard_Address, const Standard_Real, const Standard_Integer)) &HLRBRep_CurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_CurveTool.def_static("Resolution_", (Standard_Real (*)(const Standard_Address, const Standard_Real)) &HLRBRep_CurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_CurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Standard_Address)) &HLRBRep_CurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("TheType_", (GeomAbs_CurveType (*)(const Standard_Address)) &HLRBRep_CurveTool::TheType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Line_", (gp_Lin2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Line, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Circle_", (gp_Circ2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Circle, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Ellipse_", (gp_Elips2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Parabola_", (gp_Parab2d (*)(const Standard_Address)) &HLRBRep_CurveTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Bezier_", (opencascade::handle<Geom2d_BezierCurve> (*)(const Standard_Address)) &HLRBRep_CurveTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("BSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const Standard_Address)) &HLRBRep_CurveTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("EpsX_", (Standard_Real (*)(const Standard_Address)) &HLRBRep_CurveTool::EpsX, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Standard_Address, const Standard_Real, const Standard_Real)) &HLRBRep_CurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_HLRBRep_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::NbSamples, "None", py::arg("C"));
cls_HLRBRep_CurveTool.def_static("Degree_", (Standard_Integer (*)(const Standard_Address)) &HLRBRep_CurveTool::Degree, "None", py::arg("C"));

// Enums

}