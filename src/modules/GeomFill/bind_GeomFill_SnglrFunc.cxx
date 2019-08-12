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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <GeomFill_SnglrFunc.hxx>

void bind_GeomFill_SnglrFunc(py::module &mod){

py::class_<GeomFill_SnglrFunc, std::unique_ptr<GeomFill_SnglrFunc, Deleter<GeomFill_SnglrFunc>>, Adaptor3d_Curve> cls_GeomFill_SnglrFunc(mod, "GeomFill_SnglrFunc", "to represent function C'(t)^C''(t)");

// Constructors
cls_GeomFill_SnglrFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("HC"));

// Fields

// Methods
// cls_GeomFill_SnglrFunc.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SnglrFunc::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SnglrFunc.def_static("operator delete_", (void (*)(void *)) &GeomFill_SnglrFunc::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SnglrFunc::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SnglrFunc.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SnglrFunc::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SnglrFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SnglrFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SnglrFunc.def("SetRatio", (void (GeomFill_SnglrFunc::*)(const Standard_Real)) &GeomFill_SnglrFunc::SetRatio, "None", py::arg("Ratio"));
cls_GeomFill_SnglrFunc.def("FirstParameter", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::FirstParameter, "None");
cls_GeomFill_SnglrFunc.def("LastParameter", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::LastParameter, "None");
cls_GeomFill_SnglrFunc.def("NbIntervals", (Standard_Integer (GeomFill_SnglrFunc::*)(const GeomAbs_Shape) const) &GeomFill_SnglrFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_SnglrFunc.def("Intervals", (void (GeomFill_SnglrFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_SnglrFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_SnglrFunc.def("Value", (gp_Pnt (GeomFill_SnglrFunc::*)(const Standard_Real) const) &GeomFill_SnglrFunc::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_GeomFill_SnglrFunc.def("IsPeriodic", (Standard_Boolean (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::IsPeriodic, "None");
cls_GeomFill_SnglrFunc.def("Period", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::Period, "None");
cls_GeomFill_SnglrFunc.def("D0", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &) const) &GeomFill_SnglrFunc::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_GeomFill_SnglrFunc.def("D1", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_SnglrFunc::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_SnglrFunc.def("D2", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomFill_SnglrFunc::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomFill_SnglrFunc.def("D3", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomFill_SnglrFunc::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_GeomFill_SnglrFunc.def("DN", (gp_Vec (GeomFill_SnglrFunc::*)(const Standard_Real, const Standard_Integer) const) &GeomFill_SnglrFunc::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_GeomFill_SnglrFunc.def("Resolution", (Standard_Real (GeomFill_SnglrFunc::*)(const Standard_Real) const) &GeomFill_SnglrFunc::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomFill_SnglrFunc.def("GetType", (GeomAbs_CurveType (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");

// Enums

}