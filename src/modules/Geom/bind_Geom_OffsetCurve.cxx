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
#include <Geom_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Standard_Type.hxx>
#include <GeomEvaluator_OffsetCurve.hxx>

void bind_Geom_OffsetCurve(py::module &mod){

py::class_<Geom_OffsetCurve, opencascade::handle<Geom_OffsetCurve>, Geom_Curve> cls_Geom_OffsetCurve(mod, "Geom_OffsetCurve", "This class implements the basis services for an offset curve in 3D space. The Offset curve in this package can be a self intersecting curve even if the basis curve does not self-intersect. The self intersecting portions are not deleted at the construction time. An offset curve is a curve at constant distance (Offset) from a basis curve in a reference direction V. The offset curve takes its parametrization from the basis curve. The Offset curve is in the direction of the normal N defined with the cross product T^V, where the vector T is given by the first derivative on the basis curve with non zero length. The distance offset may be positive or negative to indicate the preferred side of the curve : . distance offset >0 => the curve is in the direction of N . distance offset <0 => the curve is in the direction of - N");

// Constructors
cls_Geom_OffsetCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const gp_Dir &>(), py::arg("C"), py::arg("Offset"), py::arg("V"));
cls_Geom_OffsetCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const gp_Dir &, const Standard_Boolean>(), py::arg("C"), py::arg("Offset"), py::arg("V"), py::arg("isNotCheckC0"));

// Fields

// Methods
cls_Geom_OffsetCurve.def("Reverse", (void (Geom_OffsetCurve::*)()) &Geom_OffsetCurve::Reverse, "Changes the orientation of this offset curve. As a result: - the basis curve is reversed, - the start point of the initial curve becomes the end point of the reversed curve, - the end point of the initial curve becomes the start point of the reversed curve, and - the first and last parameters are recomputed.");
cls_Geom_OffsetCurve.def("ReversedParameter", (Standard_Real (Geom_OffsetCurve::*)(const Standard_Real) const) &Geom_OffsetCurve::ReversedParameter, "Computes the parameter on the reversed curve for the point of parameter U on this offset curve.", py::arg("U"));
cls_Geom_OffsetCurve.def("SetBasisCurve", [](Geom_OffsetCurve &self, const opencascade::handle<Geom_Curve> & a0) -> void { return self.SetBasisCurve(a0); });
cls_Geom_OffsetCurve.def("SetBasisCurve", (void (Geom_OffsetCurve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Boolean)) &Geom_OffsetCurve::SetBasisCurve, "Changes this offset curve by assigning C as the basis curve from which it is built. If isNotCheckC0 = TRUE checking if basis curve has C0-continuity is not made. Exceptions Standard_ConstructionError if the curve C is not at least 'C1' continuous.", py::arg("C"), py::arg("isNotCheckC0"));
cls_Geom_OffsetCurve.def("SetDirection", (void (Geom_OffsetCurve::*)(const gp_Dir &)) &Geom_OffsetCurve::SetDirection, "Changes this offset curve by assigning V as the reference vector used to compute the offset direction.", py::arg("V"));
cls_Geom_OffsetCurve.def("SetOffsetValue", (void (Geom_OffsetCurve::*)(const Standard_Real)) &Geom_OffsetCurve::SetOffsetValue, "Changes this offset curve by assigning D as the offset value.", py::arg("D"));
cls_Geom_OffsetCurve.def("BasisCurve", (opencascade::handle<Geom_Curve> (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::BasisCurve, "Returns the basis curve of this offset curve. Note: The basis curve can be an offset curve.");
cls_Geom_OffsetCurve.def("Continuity", (GeomAbs_Shape (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::Continuity, "Returns the global continuity of this offset curve as a value of the GeomAbs_Shape enumeration. The degree of continuity of this offset curve is equal to the degree of continuity of the basis curve minus 1. Continuity of the Offset curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, G1 : tangency continuity all along the Curve, G2 : curvature continuity all along the Curve, CN : the order of continuity is infinite. Warnings : Returns the continuity of the basis curve - 1. The offset curve must have a unique offset direction defined at any point.");
cls_Geom_OffsetCurve.def("Direction", (const gp_Dir & (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::Direction, "Returns the reference vector of this offset curve. Value and derivatives Warnings : The exception UndefinedValue or UndefinedDerivative is raised if it is not possible to compute a unique offset direction. If T is the first derivative with not null length and V the offset direction the relation ||T(U) ^ V|| != 0 must be satisfied to evaluate the offset curve. No check is done at the creation time and we suppose in this package that the offset curve is well defined.");
cls_Geom_OffsetCurve.def("D0", (void (Geom_OffsetCurve::*)(const Standard_Real, gp_Pnt &) const) &Geom_OffsetCurve::D0, "Warning! this should not be called if the basis curve is not at least C1. Nevertheless if used on portion where the curve is C1, it is OK", py::arg("U"), py::arg("P"));
cls_Geom_OffsetCurve.def("D1", (void (Geom_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_OffsetCurve::D1, "Warning! this should not be called if the continuity of the basis curve is not C2. Nevertheless, it's OK to use it on portion where the curve is C2", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_OffsetCurve.def("D2", (void (Geom_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_OffsetCurve::D2, "Warning! this should not be called if the continuity of the basis curve is not C3. Nevertheless, it's OK to use it on portion where the curve is C3", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_OffsetCurve.def("D3", (void (Geom_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_OffsetCurve::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_OffsetCurve.def("DN", (gp_Vec (Geom_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const) &Geom_OffsetCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N.", py::arg("U"), py::arg("N"));
cls_Geom_OffsetCurve.def("FirstParameter", (Standard_Real (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::FirstParameter, "Returns the value of the first parameter of this offset curve. The first parameter corresponds to the start point of the curve. Note: the first and last parameters of this offset curve are also the ones of its basis curve.");
cls_Geom_OffsetCurve.def("LastParameter", (Standard_Real (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::LastParameter, "Returns the value of the last parameter of this offset curve. The last parameter corresponds to the end point. Note: the first and last parameters of this offset curve are also the ones of its basis curve.");
cls_Geom_OffsetCurve.def("Offset", (Standard_Real (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::Offset, "Returns the offset value of this offset curve.");
cls_Geom_OffsetCurve.def("IsClosed", (Standard_Boolean (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::IsClosed, "Returns True if the distance between the start point and the end point of the curve is lower or equal to Resolution from package gp.");
cls_Geom_OffsetCurve.def("IsCN", (Standard_Boolean (Geom_OffsetCurve::*)(const Standard_Integer) const) &Geom_OffsetCurve::IsCN, "Returns true if the degree of continuity of the basis curve of this offset curve is at least N + 1. This method answer True if the continuity of the basis curve is N + 1. We suppose in this class that a normal direction to the basis curve (used to compute the offset curve) is defined at any point on the basis curve. Raised if N < 0.", py::arg("N"));
cls_Geom_OffsetCurve.def("IsPeriodic", (Standard_Boolean (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::IsPeriodic, "Returns true if this offset curve is periodic, i.e. if the basis curve of this offset curve is periodic.");
cls_Geom_OffsetCurve.def("Period", (Standard_Real (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::Period, "Returns the period of this offset curve, i.e. the period of the basis curve of this offset curve. Exceptions Standard_NoSuchObject if the basis curve is not periodic.");
cls_Geom_OffsetCurve.def("Transform", (void (Geom_OffsetCurve::*)(const gp_Trsf &)) &Geom_OffsetCurve::Transform, "Applies the transformation T to this offset curve. Note: the basis curve is also modified.", py::arg("T"));
cls_Geom_OffsetCurve.def("TransformedParameter", (Standard_Real (Geom_OffsetCurve::*)(const Standard_Real, const gp_Trsf &) const) &Geom_OffsetCurve::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>. me->Transformed(T)->Value(me->TransformedParameter(U,T)) is the same point as me->Value(U).Transformed(T) This methods calls the basis curve method.", py::arg("U"), py::arg("T"));
cls_Geom_OffsetCurve.def("ParametricTransformation", (Standard_Real (Geom_OffsetCurve::*)(const gp_Trsf &) const) &Geom_OffsetCurve::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom_OffsetCurve.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::Copy, "Creates a new object which is a copy of this offset curve.");
cls_Geom_OffsetCurve.def("GetBasisCurveContinuity", (GeomAbs_Shape (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::GetBasisCurveContinuity, "Returns continuity of the basis curve.");
cls_Geom_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &Geom_OffsetCurve::get_type_name, "None");
cls_Geom_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_OffsetCurve::get_type_descriptor, "None");
cls_Geom_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_OffsetCurve::*)() const) &Geom_OffsetCurve::DynamicType, "None");

// Enums

}