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
#include <BRepAdaptor_Curve.hxx>
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
#include <Standard_Handle.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <HLRBRep_BCurveTool.hxx>

void bind_HLRBRep_BCurveTool(py::module &mod){

py::class_<HLRBRep_BCurveTool> cls_HLRBRep_BCurveTool(mod, "HLRBRep_BCurveTool", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_BCurveTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BCurveTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BCurveTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BCurveTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BCurveTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("LastParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const GeomAbs_Shape)) &HLRBRep_BCurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_HLRBRep_BCurveTool.def_static("Intervals_", (void (*)(const BRepAdaptor_Curve &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BCurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_HLRBRep_BCurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Period_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Period, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Curve &, const Standard_Real)) &HLRBRep_BCurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_HLRBRep_BCurveTool.def_static("D0_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &)) &HLRBRep_BCurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_BCurveTool.def_static("D1_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &HLRBRep_BCurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_BCurveTool.def_static("D2_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_BCurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_BCurveTool.def_static("D3_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BCurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_BCurveTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Curve &, const Standard_Real, const Standard_Integer)) &HLRBRep_BCurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_BCurveTool.def_static("Resolution_", (Standard_Real (*)(const BRepAdaptor_Curve &, const Standard_Real)) &HLRBRep_BCurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_BCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Line_", (gp_Lin (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Line, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Circle_", (gp_Circ (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Circle, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Ellipse_", (gp_Elips (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Parabola_", (gp_Parab (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Degree_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::Degree, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("IsRational_", (Standard_Boolean (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::IsRational, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbPoles_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::NbPoles, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("NbKnots_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &HLRBRep_BCurveTool::NbKnots, "None", py::arg("C"));
cls_HLRBRep_BCurveTool.def_static("Poles_", (void (*)(const BRepAdaptor_Curve &, TColgp_Array1OfPnt &)) &HLRBRep_BCurveTool::Poles, "None", py::arg("C"), py::arg("T"));
cls_HLRBRep_BCurveTool.def_static("PolesAndWeights_", (void (*)(const BRepAdaptor_Curve &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &HLRBRep_BCurveTool::PolesAndWeights, "None", py::arg("C"), py::arg("T"), py::arg("W"));
cls_HLRBRep_BCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep_BCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// Enums

}