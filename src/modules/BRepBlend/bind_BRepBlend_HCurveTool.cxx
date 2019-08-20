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
#include <Adaptor3d_HCurve.hxx>
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
#include <BRepBlend_HCurveTool.hxx>

void bind_BRepBlend_HCurveTool(py::module &mod){

py::class_<BRepBlend_HCurveTool, std::unique_ptr<BRepBlend_HCurveTool>> cls_BRepBlend_HCurveTool(mod, "BRepBlend_HCurveTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepBlend_HCurveTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_HCurveTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_HCurveTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_HCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_HCurveTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_HCurveTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_HCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_HCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_HCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_HCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_HCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::FirstParameter, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::LastParameter, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Continuity, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const GeomAbs_Shape)) &BRepBlend_HCurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_BRepBlend_HCurveTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepBlend_HCurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_BRepBlend_HCurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::IsClosed, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::IsPeriodic, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Period, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Value_", (gp_Pnt (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &BRepBlend_HCurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_BRepBlend_HCurveTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &)) &BRepBlend_HCurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_BRepBlend_HCurveTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &BRepBlend_HCurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepBlend_HCurveTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepBlend_HCurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepBlend_HCurveTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepBlend_HCurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBlend_HCurveTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Integer)) &BRepBlend_HCurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_BRepBlend_HCurveTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &BRepBlend_HCurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_BRepBlend_HCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Line_", (gp_Lin (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Line, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Circle_", (gp_Circ (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Circle, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Ellipse_", (gp_Elips (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Ellipse, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Hyperbola, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Parabola_", (gp_Parab (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Parabola, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::Bezier, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &BRepBlend_HCurveTool::BSpline, "None", py::arg("C"));
cls_BRepBlend_HCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &BRepBlend_HCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));

// Enums

}