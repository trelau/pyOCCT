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
#include <gp_Lin.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <HLRBRep_LineTool.hxx>

void bind_HLRBRep_LineTool(py::module &mod){

py::class_<HLRBRep_LineTool, std::unique_ptr<HLRBRep_LineTool>> cls_HLRBRep_LineTool(mod, "HLRBRep_LineTool", "The LineTool class provides class methods to access the methodes of the Line.");

// Constructors

// Fields

// Methods
// cls_HLRBRep_LineTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_LineTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_LineTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_LineTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_LineTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_LineTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_LineTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_LineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_LineTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_LineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_LineTool.def_static("FirstParameter_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::FirstParameter, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("LastParameter_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::LastParameter, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Continuity_", (GeomAbs_Shape (*)(const gp_Lin &)) &HLRBRep_LineTool::Continuity, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("NbIntervals_", (Standard_Integer (*)(const gp_Lin &, const GeomAbs_Shape)) &HLRBRep_LineTool::NbIntervals, "If necessary, breaks the line in intervals of continuity <S>. And returns the number of intervals.", py::arg("C"), py::arg("S"));
cls_HLRBRep_LineTool.def_static("Intervals_", (void (*)(const gp_Lin &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_LineTool::Intervals, "Sets the current working interval.", py::arg("C"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_LineTool.def_static("IntervalFirst_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IntervalLast_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalLast, "Returns the last parameter of the current interval.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IntervalContinuity_", (GeomAbs_Shape (*)(const gp_Lin &)) &HLRBRep_LineTool::IntervalContinuity, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IsClosed_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsClosed, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsPeriodic, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Period_", (Standard_Real (*)(const gp_Lin &)) &HLRBRep_LineTool::Period, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Value_", (gp_Pnt (*)(const gp_Lin &, const Standard_Real)) &HLRBRep_LineTool::Value, "Computes the point of parameter U on the line.", py::arg("C"), py::arg("U"));
cls_HLRBRep_LineTool.def_static("D0_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &)) &HLRBRep_LineTool::D0, "Computes the point of parameter U on the line.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_HLRBRep_LineTool.def_static("D1_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &)) &HLRBRep_LineTool::D1, "Computes the point of parameter U on the line with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_HLRBRep_LineTool.def_static("D2_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_LineTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_HLRBRep_LineTool.def_static("D3_", (void (*)(const gp_Lin &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_LineTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_HLRBRep_LineTool.def_static("DN_", (gp_Vec (*)(const gp_Lin &, const Standard_Real, const Standard_Integer)) &HLRBRep_LineTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_HLRBRep_LineTool.def_static("Resolution_", (Standard_Real (*)(const gp_Lin &, const Standard_Real)) &HLRBRep_LineTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_HLRBRep_LineTool.def_static("GetType_", (GeomAbs_CurveType (*)(const gp_Lin &)) &HLRBRep_LineTool::GetType, "Returns the type of the line in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Line_", (gp_Lin (*)(const gp_Lin &)) &HLRBRep_LineTool::Line, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Circle_", (gp_Circ (*)(const gp_Lin &)) &HLRBRep_LineTool::Circle, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Ellipse_", (gp_Elips (*)(const gp_Lin &)) &HLRBRep_LineTool::Ellipse, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Hyperbola_", (gp_Hypr (*)(const gp_Lin &)) &HLRBRep_LineTool::Hyperbola, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Parabola_", (gp_Parab (*)(const gp_Lin &)) &HLRBRep_LineTool::Parabola, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const gp_Lin &)) &HLRBRep_LineTool::Bezier, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const gp_Lin &)) &HLRBRep_LineTool::BSpline, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Degree_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::Degree, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("NbPoles_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::NbPoles, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("Poles_", (void (*)(const gp_Lin &, TColgp_Array1OfPnt &)) &HLRBRep_LineTool::Poles, "None", py::arg("C"), py::arg("TP"));
cls_HLRBRep_LineTool.def_static("IsRational_", (Standard_Boolean (*)(const gp_Lin &)) &HLRBRep_LineTool::IsRational, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("PolesAndWeights_", (void (*)(const gp_Lin &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &HLRBRep_LineTool::PolesAndWeights, "None", py::arg("C"), py::arg("TP"), py::arg("TW"));
cls_HLRBRep_LineTool.def_static("NbKnots_", (Standard_Integer (*)(const gp_Lin &)) &HLRBRep_LineTool::NbKnots, "None", py::arg("C"));
cls_HLRBRep_LineTool.def_static("KnotsAndMultiplicities_", (void (*)(const gp_Lin &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &)) &HLRBRep_LineTool::KnotsAndMultiplicities, "None", py::arg("C"), py::arg("TK"), py::arg("TM"));
cls_HLRBRep_LineTool.def_static("NbSamples_", (Standard_Integer (*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &HLRBRep_LineTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_HLRBRep_LineTool.def_static("SamplePars_", (void (*)(const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, opencascade::handle<TColStd_HArray1OfReal> &)) &HLRBRep_LineTool::SamplePars, "None", py::arg("C"), py::arg("U0"), py::arg("U1"), py::arg("Defl"), py::arg("NbMin"), py::arg("Pars"));

// Enums

}