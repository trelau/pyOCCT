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
#include <Geom_BoundedCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Standard_Type.hxx>

void bind_Geom_TrimmedCurve(py::module &mod){

py::class_<Geom_TrimmedCurve, opencascade::handle<Geom_TrimmedCurve>, Geom_BoundedCurve> cls_Geom_TrimmedCurve(mod, "Geom_TrimmedCurve", "Describes a portion of a curve (termed the 'basis curve') limited by two parameter values inside the parametric domain of the basis curve. The trimmed curve is defined by: - the basis curve, and - the two parameter values which limit it. The trimmed curve can either have the same orientation as the basis curve or the opposite orientation.");

// Constructors
cls_Geom_TrimmedCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_Geom_TrimmedCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Sense"));
cls_Geom_TrimmedCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Sense"), py::arg("theAdjustPeriodic"));

// Fields

// Methods
cls_Geom_TrimmedCurve.def("Reverse", (void (Geom_TrimmedCurve::*)()) &Geom_TrimmedCurve::Reverse, "Changes the orientation of this trimmed curve. As a result: - the basis curve is reversed, - the start point of the initial curve becomes the end point of the reversed curve, - the end point of the initial curve becomes the start point of the reversed curve, - the first and last parameters are recomputed. If the trimmed curve was defined by: - a basis curve whose parameter range is [ 0., 1. ], - the two trim values U1 (first parameter) and U2 (last parameter), the reversed trimmed curve is defined by: - the reversed basis curve, whose parameter range is still [ 0., 1. ], - the two trim values 1. - U2 (first parameter) and 1. - U1 (last parameter).");
cls_Geom_TrimmedCurve.def("ReversedParameter", (Standard_Real (Geom_TrimmedCurve::*)(const Standard_Real) const) &Geom_TrimmedCurve::ReversedParameter, "Computes the parameter on the reversed curve for the point of parameter U on this trimmed curve.", py::arg("U"));
cls_Geom_TrimmedCurve.def("SetTrim", [](Geom_TrimmedCurve &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTrim(a0, a1); });
cls_Geom_TrimmedCurve.def("SetTrim", [](Geom_TrimmedCurve &self, const Standard_Real a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.SetTrim(a0, a1, a2); });
cls_Geom_TrimmedCurve.def("SetTrim", (void (Geom_TrimmedCurve::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &Geom_TrimmedCurve::SetTrim, "Changes this trimmed curve, by redefining the parameter values U1 and U2 which limit its basis curve. Note: If the basis curve is periodic, the trimmed curve has the same orientation as the basis curve if Sense is true (default value) or the opposite orientation if Sense is false. Warning If the basis curve is periodic and theAdjustPeriodic is True, the bounds of the trimmed curve may be different from U1 and U2 if the parametric origin of the basis curve is within the arc of the trimmed curve. In this case, the modified parameter will be equal to U1 or U2 plus or minus the period. When theAdjustPeriodic is False, parameters U1 and U2 will be the same, without adjustment into the first period. Exceptions Standard_ConstructionError if: - the basis curve is not periodic, and either U1 or U2 are outside the bounds of the basis curve, or - U1 is equal to U2.", py::arg("U1"), py::arg("U2"), py::arg("Sense"), py::arg("theAdjustPeriodic"));
cls_Geom_TrimmedCurve.def("BasisCurve", (opencascade::handle<Geom_Curve> (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::BasisCurve, "Returns the basis curve. Warning This function does not return a constant reference. Consequently, any modification of the returned value directly modifies the trimmed curve.");
cls_Geom_TrimmedCurve.def("Continuity", (GeomAbs_Shape (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::Continuity, "Returns the continuity of the curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, CN : the order of continuity is infinite.");
cls_Geom_TrimmedCurve.def("IsCN", (Standard_Boolean (Geom_TrimmedCurve::*)(const Standard_Integer) const) &Geom_TrimmedCurve::IsCN, "Returns true if the degree of continuity of the basis curve of this trimmed curve is at least N. A trimmed curve is at least 'C0' continuous. Warnings : The continuity of the trimmed curve can be greater than the continuity of the basis curve because you consider only a part of the basis curve. Raised if N < 0.", py::arg("N"));
cls_Geom_TrimmedCurve.def("EndPoint", (gp_Pnt (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::EndPoint, "Returns the end point of <me>. This point is the evaluation of the curve for the 'LastParameter'.");
cls_Geom_TrimmedCurve.def("FirstParameter", (Standard_Real (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::FirstParameter, "Returns the value of the first parameter of <me>. The first parameter is the parameter of the 'StartPoint' of the trimmed curve.");
cls_Geom_TrimmedCurve.def("IsClosed", (Standard_Boolean (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::IsClosed, "Returns True if the distance between the StartPoint and the EndPoint is lower or equal to Resolution from package gp.");
cls_Geom_TrimmedCurve.def("IsPeriodic", (Standard_Boolean (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::IsPeriodic, "Always returns FALSE (independently of the type of basis curve).");
cls_Geom_TrimmedCurve.def("Period", (Standard_Real (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::Period, "Returns the period of the basis curve of this trimmed curve. Exceptions Standard_NoSuchObject if the basis curve is not periodic.");
cls_Geom_TrimmedCurve.def("LastParameter", (Standard_Real (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::LastParameter, "Returns the value of the last parameter of <me>. The last parameter is the parameter of the 'EndPoint' of the trimmed curve.");
cls_Geom_TrimmedCurve.def("StartPoint", (gp_Pnt (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::StartPoint, "Returns the start point of <me>. This point is the evaluation of the curve from the 'FirstParameter'. value and derivatives Warnings : The returned derivatives have the same orientation as the derivatives of the basis curve even if the trimmed curve has not the same orientation as the basis curve.");
cls_Geom_TrimmedCurve.def("D0", (void (Geom_TrimmedCurve::*)(const Standard_Real, gp_Pnt &) const) &Geom_TrimmedCurve::D0, "Returns in P the point of parameter U.", py::arg("U"), py::arg("P"));
cls_Geom_TrimmedCurve.def("D1", (void (Geom_TrimmedCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_TrimmedCurve::D1, "Raised if the continuity of the curve is not C1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_TrimmedCurve.def("D2", (void (Geom_TrimmedCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_TrimmedCurve::D2, "Raised if the continuity of the curve is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_TrimmedCurve.def("D3", (void (Geom_TrimmedCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_TrimmedCurve::D3, "Raised if the continuity of the curve is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_TrimmedCurve.def("DN", (gp_Vec (Geom_TrimmedCurve::*)(const Standard_Real, const Standard_Integer) const) &Geom_TrimmedCurve::DN, "N is the order of derivation. Raised if the continuity of the curve is not CN. Raised if N < 1. geometric transformations", py::arg("U"), py::arg("N"));
cls_Geom_TrimmedCurve.def("Transform", (void (Geom_TrimmedCurve::*)(const gp_Trsf &)) &Geom_TrimmedCurve::Transform, "Applies the transformation T to this trimmed curve. Warning The basis curve is also modified.", py::arg("T"));
cls_Geom_TrimmedCurve.def("TransformedParameter", (Standard_Real (Geom_TrimmedCurve::*)(const Standard_Real, const gp_Trsf &) const) &Geom_TrimmedCurve::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>.", py::arg("U"), py::arg("T"));
cls_Geom_TrimmedCurve.def("ParametricTransformation", (Standard_Real (Geom_TrimmedCurve::*)(const gp_Trsf &) const) &Geom_TrimmedCurve::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom_TrimmedCurve.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::Copy, "Creates a new object which is a copy of this trimmed curve.");
cls_Geom_TrimmedCurve.def_static("get_type_name_", (const char * (*)()) &Geom_TrimmedCurve::get_type_name, "None");
cls_Geom_TrimmedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_TrimmedCurve::get_type_descriptor, "None");
cls_Geom_TrimmedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_TrimmedCurve::*)() const) &Geom_TrimmedCurve::DynamicType, "None");

// Enums

}