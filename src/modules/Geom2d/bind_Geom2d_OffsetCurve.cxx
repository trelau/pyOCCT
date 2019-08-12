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
#include <Geom2d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_OffsetCurve.hxx>
#include <Standard_Type.hxx>
#include <Geom2dEvaluator_OffsetCurve.hxx>

void bind_Geom2d_OffsetCurve(py::module &mod){

py::class_<Geom2d_OffsetCurve, opencascade::handle<Geom2d_OffsetCurve>, Geom2d_Curve> cls_Geom2d_OffsetCurve(mod, "Geom2d_OffsetCurve", "This class implements the basis services for the creation, edition, modification and evaluation of planar offset curve. The offset curve is obtained by offsetting by distance along the normal to a basis curve defined in 2D space. The offset curve in this package can be a self intersecting curve even if the basis curve does not self-intersect. The self intersecting portions are not deleted at the construction time. An offset curve is a curve at constant distance (Offset) from a basis curve and the offset curve takes its parametrization from the basis curve. The Offset curve is in the direction of the normal to the basis curve N. The distance offset may be positive or negative to indicate the preferred side of the curve : . distance offset >0 => the curve is in the direction of N . distance offset >0 => the curve is in the direction of - N On the Offset curve : Value(u) = BasisCurve.Value(U) + (Offset * (T ^ Z)) / ||T ^ Z|| where T is the tangent vector to the basis curve and Z the direction of the normal vector to the plane of the curve, N = T ^ Z defines the offset direction and should not have null length.");

// Constructors
cls_Geom2d_OffsetCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("C"), py::arg("Offset"));
cls_Geom2d_OffsetCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Offset"), py::arg("isNotCheckC0"));

// Fields

// Methods
cls_Geom2d_OffsetCurve.def("Reverse", (void (Geom2d_OffsetCurve::*)()) &Geom2d_OffsetCurve::Reverse, "Changes the direction of parametrization of <me>. As a result: - the basis curve is reversed, - the start point of the initial curve becomes the end point of the reversed curve, - the end point of the initial curve becomes the start point of the reversed curve, and - the first and last parameters are recomputed.");
cls_Geom2d_OffsetCurve.def("ReversedParameter", (Standard_Real (Geom2d_OffsetCurve::*)(const Standard_Real) const) &Geom2d_OffsetCurve::ReversedParameter, "Computes the parameter on the reversed curve for the point of parameter U on this offset curve.", py::arg("U"));
cls_Geom2d_OffsetCurve.def("SetBasisCurve", [](Geom2d_OffsetCurve &self, const opencascade::handle<Geom2d_Curve> & a0) -> void { return self.SetBasisCurve(a0); });
cls_Geom2d_OffsetCurve.def("SetBasisCurve", (void (Geom2d_OffsetCurve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean)) &Geom2d_OffsetCurve::SetBasisCurve, "Changes this offset curve by assigning C as the basis curve from which it is built. If isNotCheckC0 = TRUE checking if basis curve has C0-continuity is not made. Exceptions if isNotCheckC0 = false, Standard_ConstructionError if the curve C is not at least 'C1' continuous.", py::arg("C"), py::arg("isNotCheckC0"));
cls_Geom2d_OffsetCurve.def("SetOffsetValue", (void (Geom2d_OffsetCurve::*)(const Standard_Real)) &Geom2d_OffsetCurve::SetOffsetValue, "Changes this offset curve by assigning D as the offset value.", py::arg("D"));
cls_Geom2d_OffsetCurve.def("BasisCurve", (opencascade::handle<Geom2d_Curve> (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::BasisCurve, "Returns the basis curve of this offset curve. The basis curve can be an offset curve.");
cls_Geom2d_OffsetCurve.def("Continuity", (GeomAbs_Shape (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::Continuity, "Continuity of the Offset curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, G1 : tangency continuity all along the Curve, G2 : curvature continuity all along the Curve, CN : the order of continuity is infinite. Warnings : Returns the continuity of the basis curve - 1. The offset curve must have a unique normal direction defined at any point. Value and derivatives");
cls_Geom2d_OffsetCurve.def("D0", (void (Geom2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_OffsetCurve::D0, "Warning! this should not be called if the basis curve is not at least C1. Nevertheless if used on portion where the curve is C1, it is OK", py::arg("U"), py::arg("P"));
cls_Geom2d_OffsetCurve.def("D1", (void (Geom2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_OffsetCurve::D1, "Warning! this should not be called if the continuity of the basis curve is not C2. Nevertheless, it's OK to use it on portion where the curve is C2", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_OffsetCurve.def("D2", (void (Geom2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_OffsetCurve::D2, "Warning! This should not be called if the continuity of the basis curve is not C3. Nevertheless, it's OK to use it on portion where the curve is C3", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_OffsetCurve.def("D3", (void (Geom2d_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_OffsetCurve::D3, "Warning! This should not be called if the continuity of the basis curve is not C4. Nevertheless, it's OK to use it on portion where the curve is C4", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_OffsetCurve.def("DN", (gp_Vec2d (Geom2d_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_OffsetCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Warning! this should not be called raises UndefunedDerivative if the continuity of the basis curve is not CN+1. Nevertheless, it's OK to use it on portion where the curve is CN+1 raises RangeError if N < 1. raises NotImplemented if N > 3. The following functions compute the value and derivatives on the offset curve and returns the derivatives on the basis curve too. The computation of the value and derivatives on the basis curve are used to evaluate the offset curve Warnings : The exception UndefinedValue or UndefinedDerivative is raised if it is not possible to compute a unique offset direction.", py::arg("U"), py::arg("N"));
cls_Geom2d_OffsetCurve.def("FirstParameter", (Standard_Real (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::FirstParameter, "Returns the value of the first parameter of this offset curve. The first parameter corresponds to the start point of the curve. Note: the first and last parameters of this offset curve are also the ones of its basis curve.");
cls_Geom2d_OffsetCurve.def("LastParameter", (Standard_Real (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::LastParameter, "Returns the value of the last parameter of this offset curve. The last parameter corresponds to the end point. Note: the first and last parameters of this offset curve are also the ones of its basis curve.");
cls_Geom2d_OffsetCurve.def("Offset", (Standard_Real (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::Offset, "Returns the offset value of this offset curve.");
cls_Geom2d_OffsetCurve.def("IsClosed", (Standard_Boolean (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::IsClosed, "Returns True if the distance between the start point and the end point of the curve is lower or equal to Resolution from package gp.");
cls_Geom2d_OffsetCurve.def("IsCN", (Standard_Boolean (Geom2d_OffsetCurve::*)(const Standard_Integer) const) &Geom2d_OffsetCurve::IsCN, "Is the order of continuity of the curve N ? Warnings : This method answer True if the continuity of the basis curve is N + 1. We suppose in this class that a normal direction to the basis curve (used to compute the offset curve) is defined at any point on the basis curve. Raised if N < 0.", py::arg("N"));
cls_Geom2d_OffsetCurve.def("IsPeriodic", (Standard_Boolean (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::IsPeriodic, "Is the parametrization of a curve is periodic ? If the basis curve is a circle or an ellipse the corresponding OffsetCurve is periodic. If the basis curve can't be periodic (for example BezierCurve) the OffsetCurve can't be periodic.");
cls_Geom2d_OffsetCurve.def("Period", (Standard_Real (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::Period, "Returns the period of this offset curve, i.e. the period of the basis curve of this offset curve. Exceptions Standard_NoSuchObject if the basis curve is not periodic.");
cls_Geom2d_OffsetCurve.def("Transform", (void (Geom2d_OffsetCurve::*)(const gp_Trsf2d &)) &Geom2d_OffsetCurve::Transform, "Applies the transformation T to this offset curve. Note: the basis curve is also modified.", py::arg("T"));
cls_Geom2d_OffsetCurve.def("TransformedParameter", (Standard_Real (Geom2d_OffsetCurve::*)(const Standard_Real, const gp_Trsf2d &) const) &Geom2d_OffsetCurve::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>.", py::arg("U"), py::arg("T"));
cls_Geom2d_OffsetCurve.def("ParametricTransformation", (Standard_Real (Geom2d_OffsetCurve::*)(const gp_Trsf2d &) const) &Geom2d_OffsetCurve::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom2d_OffsetCurve.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::Copy, "Creates a new object, which is a copy of this offset curve.");
cls_Geom2d_OffsetCurve.def("GetBasisCurveContinuity", (GeomAbs_Shape (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::GetBasisCurveContinuity, "Returns continuity of the basis curve.");
cls_Geom2d_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &Geom2d_OffsetCurve::get_type_name, "None");
cls_Geom2d_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_OffsetCurve::get_type_descriptor, "None");
cls_Geom2d_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_OffsetCurve::*)() const) &Geom2d_OffsetCurve::DynamicType, "None");

// Enums

}