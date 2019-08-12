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
#include <Geom_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Curve(py::module &mod){

py::class_<Geom_Curve, opencascade::handle<Geom_Curve>, Geom_Geometry> cls_Geom_Curve(mod, "Geom_Curve", "The abstract class Curve describes the common behavior of curves in 3D space. The Geom package provides numerous concrete classes of derived curves, including lines, circles, conics, Bezier or BSpline curves, etc. The main characteristic of these curves is that they are parameterized. The Geom_Curve class shows: - how to work with the parametric equation of a curve in order to calculate the point of parameter u, together with the vector tangent and the derivative vectors of order 2, 3,..., N at this point; - how to obtain general information about the curve (for example, level of continuity, closed characteristics, periodicity, bounds of the parameter field); - how the parameter changes when a geometric transformation is applied to the curve or when the orientation of the curve is inverted. All curves must have a geometric continuity: a curve is at least 'C0'. Generally, this property is checked at the time of construction or when the curve is edited. Where this is not the case, the documentation states so explicitly. Warning The Geom package does not prevent the construction of curves with null length or curves which self-intersect.");

// Fields

// Methods
cls_Geom_Curve.def("Reverse", (void (Geom_Curve::*)()) &Geom_Curve::Reverse, "Changes the direction of parametrization of <me>. The 'FirstParameter' and the 'LastParameter' are not changed but the orientation of the curve is modified. If the curve is bounded the StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
cls_Geom_Curve.def("ReversedParameter", (Standard_Real (Geom_Curve::*)(const Standard_Real) const) &Geom_Curve::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Geom_Curve.def("TransformedParameter", (Standard_Real (Geom_Curve::*)(const Standard_Real, const gp_Trsf &) const) &Geom_Curve::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>.", py::arg("U"), py::arg("T"));
cls_Geom_Curve.def("ParametricTransformation", (Standard_Real (Geom_Curve::*)(const gp_Trsf &) const) &Geom_Curve::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom_Curve.def("Reversed", (opencascade::handle<Geom_Curve> (Geom_Curve::*)() const) &Geom_Curve::Reversed, "Returns a copy of <me> reversed.");
cls_Geom_Curve.def("FirstParameter", (Standard_Real (Geom_Curve::*)() const) &Geom_Curve::FirstParameter, "Returns the value of the first parameter. Warnings : It can be RealFirst from package Standard if the curve is infinite");
cls_Geom_Curve.def("LastParameter", (Standard_Real (Geom_Curve::*)() const) &Geom_Curve::LastParameter, "Returns the value of the last parameter. Warnings : It can be RealLast from package Standard if the curve is infinite");
cls_Geom_Curve.def("IsClosed", (Standard_Boolean (Geom_Curve::*)() const) &Geom_Curve::IsClosed, "Returns true if the curve is closed. Some curves such as circle are always closed, others such as line are never closed (by definition). Some Curves such as OffsetCurve can be closed or not. These curves are considered as closed if the distance between the first point and the last point of the curve is lower or equal to the Resolution from package gp wich is a fixed criterion independant of the application.");
cls_Geom_Curve.def("IsPeriodic", (Standard_Boolean (Geom_Curve::*)() const) &Geom_Curve::IsPeriodic, "Is the parametrization of the curve periodic ? It is possible only if the curve is closed and if the following relation is satisfied : for each parametric value U the distance between the point P(u) and the point P (u + T) is lower or equal to Resolution from package gp, T is the period and must be a constant. There are three possibilities : . the curve is never periodic by definition (SegmentLine) . the curve is always periodic by definition (Circle) . the curve can be defined as periodic (BSpline). In this case a function SetPeriodic allows you to give the shape of the curve. The general rule for this case is : if a curve can be periodic or not the default periodicity set is non periodic and you have to turn (explicitly) the curve into a periodic curve if you want the curve to be periodic.");
cls_Geom_Curve.def("Period", (Standard_Real (Geom_Curve::*)() const) &Geom_Curve::Period, "Returns the period of this curve. Exceptions Standard_NoSuchObject if this curve is not periodic.");
cls_Geom_Curve.def("Continuity", (GeomAbs_Shape (Geom_Curve::*)() const) &Geom_Curve::Continuity, "It is the global continuity of the curve C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, G1 : tangency continuity all along the Curve, G2 : curvature continuity all along the Curve, CN : the order of continuity is infinite.");
cls_Geom_Curve.def("IsCN", (Standard_Boolean (Geom_Curve::*)(const Standard_Integer) const) &Geom_Curve::IsCN, "Returns true if the degree of continuity of this curve is at least N. Exceptions - Standard_RangeError if N is less than 0.", py::arg("N"));
cls_Geom_Curve.def("D0", (void (Geom_Curve::*)(const Standard_Real, gp_Pnt &) const) &Geom_Curve::D0, "Returns in P the point of parameter U. If the curve is periodic then the returned point is P(U) with U = Ustart + (U - Uend) where Ustart and Uend are the parametric bounds of the curve.", py::arg("U"), py::arg("P"));
cls_Geom_Curve.def("D1", (void (Geom_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Curve::D1, "Returns the point P of parameter U and the first derivative V1. Raised if the continuity of the curve is not C1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Curve.def("D2", (void (Geom_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the curve is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Curve.def("D3", (void (Geom_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the curve is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Curve.def("DN", (gp_Vec (Geom_Curve::*)(const Standard_Real, const Standard_Integer) const) &Geom_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the curve is not CN.", py::arg("U"), py::arg("N"));
cls_Geom_Curve.def("Value", (gp_Pnt (Geom_Curve::*)(const Standard_Real) const) &Geom_Curve::Value, "Computes the point of parameter U on <me>. If the curve is periodic then the returned point is P(U) with U = Ustart + (U - Uend) where Ustart and Uend are the parametric bounds of the curve. it is implemented with D0.", py::arg("U"));
cls_Geom_Curve.def_static("get_type_name_", (const char * (*)()) &Geom_Curve::get_type_name, "None");
cls_Geom_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Curve::get_type_descriptor, "None");
cls_Geom_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Curve::*)() const) &Geom_Curve::DynamicType, "None");

// Enums

}