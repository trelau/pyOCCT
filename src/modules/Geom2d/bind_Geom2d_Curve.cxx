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
#include <Geom2d_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Curve(py::module &mod){

py::class_<Geom2d_Curve, opencascade::handle<Geom2d_Curve>, Geom2d_Geometry> cls_Geom2d_Curve(mod, "Geom2d_Curve", "The abstract class Curve describes the common behavior of curves in 2D space. The Geom2d package provides numerous concrete classes of derived curves, including lines, circles, conics, Bezier or BSpline curves, etc. The main characteristic of these curves is that they are parameterized. The Geom2d_Curve class shows: - how to work with the parametric equation of a curve in order to calculate the point of parameter u, together with the vector tangent and the derivative vectors of order 2, 3,..., N at this point; - how to obtain general information about the curve (for example, level of continuity, closed characteristics, periodicity, bounds of the parameter field); - how the parameter changes when a geometric transformation is applied to the curve or when the orientation of the curve is inverted. All curves must have a geometric continuity: a curve is at least 'C0'. Generally, this property is checked at the time of construction or when the curve is edited. Where this is not the case, the documentation explicitly states so. Warning The Geom2d package does not prevent the construction of curves with null length or curves which self-intersect.");

// Fields

// Methods
cls_Geom2d_Curve.def("Reverse", (void (Geom2d_Curve::*)()) &Geom2d_Curve::Reverse, "Changes the direction of parametrization of <me>. The 'FirstParameter' and the 'LastParameter' are not changed but the orientation of the curve is modified. If the curve is bounded the StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
cls_Geom2d_Curve.def("ReversedParameter", (Standard_Real (Geom2d_Curve::*)(const Standard_Real) const) &Geom2d_Curve::ReversedParameter, "Computes the parameter on the reversed curve for the point of parameter U on this curve. Note: The point of parameter U on this curve is identical to the point of parameter ReversedParameter(U) on the reversed curve.", py::arg("U"));
cls_Geom2d_Curve.def("TransformedParameter", (Standard_Real (Geom2d_Curve::*)(const Standard_Real, const gp_Trsf2d &) const) &Geom2d_Curve::TransformedParameter, "Computes the parameter on the curve transformed by T for the point of parameter U on this curve. Note: this function generally returns U but it can be redefined (for example, on a line).", py::arg("U"), py::arg("T"));
cls_Geom2d_Curve.def("ParametricTransformation", (Standard_Real (Geom2d_Curve::*)(const gp_Trsf2d &) const) &Geom2d_Curve::ParametricTransformation, "Returns the coefficient required to compute the parametric transformation of this curve when transformation T is applied. This coefficient is the ratio between the parameter of a point on this curve and the parameter of the transformed point on the new curve transformed by T. Note: this function generally returns 1. but it can be redefined (for example, on a line).", py::arg("T"));
cls_Geom2d_Curve.def("Reversed", (opencascade::handle<Geom2d_Curve> (Geom2d_Curve::*)() const) &Geom2d_Curve::Reversed, "Creates a reversed duplicate Changes the orientation of this curve. The first and last parameters are not changed, but the parametric direction of the curve is reversed. If the curve is bounded: - the start point of the initial curve becomes the end point of the reversed curve, and - the end point of the initial curve becomes the start point of the reversed curve. - Reversed creates a new curve.");
cls_Geom2d_Curve.def("FirstParameter", (Standard_Real (Geom2d_Curve::*)() const) &Geom2d_Curve::FirstParameter, "Returns the value of the first parameter. Warnings : It can be RealFirst or RealLast from package Standard if the curve is infinite");
cls_Geom2d_Curve.def("LastParameter", (Standard_Real (Geom2d_Curve::*)() const) &Geom2d_Curve::LastParameter, "Value of the last parameter. Warnings : It can be RealFirst or RealLast from package Standard if the curve is infinite");
cls_Geom2d_Curve.def("IsClosed", (Standard_Boolean (Geom2d_Curve::*)() const) &Geom2d_Curve::IsClosed, "Returns true if the curve is closed. Examples : Some curves such as circle are always closed, others such as line are never closed (by definition). Some Curves such as OffsetCurve can be closed or not. These curves are considered as closed if the distance between the first point and the last point of the curve is lower or equal to the Resolution from package gp wich is a fixed criterion independant of the application.");
cls_Geom2d_Curve.def("IsPeriodic", (Standard_Boolean (Geom2d_Curve::*)() const) &Geom2d_Curve::IsPeriodic, "Returns true if the parameter of the curve is periodic. It is possible only if the curve is closed and if the following relation is satisfied : for each parametric value U the distance between the point P(u) and the point P (u + T) is lower or equal to Resolution from package gp, T is the period and must be a constant. There are three possibilities : . the curve is never periodic by definition (SegmentLine) . the curve is always periodic by definition (Circle) . the curve can be defined as periodic (BSpline). In this case a function SetPeriodic allows you to give the shape of the curve. The general rule for this case is : if a curve can be periodic or not the default periodicity set is non periodic and you have to turn (explicitly) the curve into a periodic curve if you want the curve to be periodic.");
cls_Geom2d_Curve.def("Period", (Standard_Real (Geom2d_Curve::*)() const) &Geom2d_Curve::Period, "Returns thne period of this curve. raises if the curve is not periodic");
cls_Geom2d_Curve.def("Continuity", (GeomAbs_Shape (Geom2d_Curve::*)() const) &Geom2d_Curve::Continuity, "It is the global continuity of the curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, G1 : tangency continuity all along the Curve, G2 : curvature continuity all along the Curve, CN : the order of continuity is infinite.");
cls_Geom2d_Curve.def("IsCN", (Standard_Boolean (Geom2d_Curve::*)(const Standard_Integer) const) &Geom2d_Curve::IsCN, "Returns true if the degree of continuity of this curve is at least N. Exceptions Standard_RangeError if N is less than 0.", py::arg("N"));
cls_Geom2d_Curve.def("D0", (void (Geom2d_Curve::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Curve::D0, "Returns in P the point of parameter U. If the curve is periodic then the returned point is P(U) with U = Ustart + (U - Uend) where Ustart and Uend are the parametric bounds of the curve.", py::arg("U"), py::arg("P"));
cls_Geom2d_Curve.def("D1", (void (Geom2d_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Curve::D1, "Returns the point P of parameter U and the first derivative V1. Raised if the continuity of the curve is not C1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Curve.def("D2", (void (Geom2d_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the curve is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Curve.def("D3", (void (Geom2d_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the curve is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Curve.def("DN", (gp_Vec2d (Geom2d_Curve::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Curve::DN, "For the point of parameter U of this curve, computes the vector corresponding to the Nth derivative. Exceptions StdFail_UndefinedDerivative if: - the continuity of the curve is not 'CN', or - the derivative vector cannot be computed easily; this is the case with specific types of curve (for example, a rational BSpline curve where N is greater than 3). Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Curve.def("Value", (gp_Pnt2d (Geom2d_Curve::*)(const Standard_Real) const) &Geom2d_Curve::Value, "Computes the point of parameter U on <me>. If the curve is periodic then the returned point is P(U) with U = Ustart + (U - Uend) where Ustart and Uend are the parametric bounds of the curve.", py::arg("U"));
cls_Geom2d_Curve.def_static("get_type_name_", (const char * (*)()) &Geom2d_Curve::get_type_name, "None");
cls_Geom2d_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Curve::get_type_descriptor, "None");
cls_Geom2d_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Curve::*)() const) &Geom2d_Curve::DynamicType, "None");

// Enums

}