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
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec.hxx>
#include <BSplCLib.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_BezierCurve.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_Geom_BezierCurve(py::module &mod){

py::class_<Geom_BezierCurve, opencascade::handle<Geom_BezierCurve>, Geom_BoundedCurve> cls_Geom_BezierCurve(mod, "Geom_BezierCurve", "Describes a rational or non-rational Bezier curve - a non-rational Bezier curve is defined by a table of poles (also called control points), - a rational Bezier curve is defined by a table of poles with varying weights. These data are manipulated by two parallel arrays: - the poles table, which is an array of gp_Pnt points, and - the weights table, which is an array of reals. The bounds of these arrays are 1 and 'the number of 'poles' of the curve. The poles of the curve are 'control points' used to deform the curve. The first pole is the start point of the curve, and the last pole is the end point of the curve. The segment that joins the first pole to the second pole is the tangent to the curve at its start point, and the segment that joins the last pole to the second-from-last pole is the tangent to the curve at its end point. It is more difficult to give a geometric signification to the weights but they are useful for providing the exact representations of arcs of a circle or ellipse. Moreover, if the weights of all poles are equal, the curve is polynomial; it is therefore a non-rational curve. The non-rational curve is a special and frequently used case. The weights are defined and used only in the case of a rational curve. The degree of a Bezier curve is equal to the number of poles, minus 1. It must be greater than or equal to 1. However, the degree of a Geom_BezierCurve curve is limited to a value (25) which is defined and controlled by the system. This value is returned by the function MaxDegree. The parameter range for a Bezier curve is [ 0, 1 ]. If the first and last control points of the Bezier curve are the same point then the curve is closed. For example, to create a closed Bezier curve with four control points, you have to give the set of control points P1, P2, P3 and P1. The continuity of a Bezier curve is infinite. It is not possible to build a Bezier curve with negative weights. We consider that a weight value is zero if it is less than or equal to gp::Resolution(). We also consider that two weight values W1 and W2 are equal if: |W2 - W1| <= gp::Resolution(). Warning - When considering the continuity of a closed Bezier curve at the junction point, remember that a curve of this type is never periodic. This means that the derivatives for the parameter u = 0 have no reason to be the same as the derivatives for the parameter u = 1 even if the curve is closed. - The length of a Bezier curve can be null.");

// Constructors
cls_Geom_BezierCurve.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("CurvePoles"));
cls_Geom_BezierCurve.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("CurvePoles"), py::arg("PoleWeights"));

// Fields

// Methods
cls_Geom_BezierCurve.def("Increase", (void (Geom_BezierCurve::*)(const Standard_Integer)) &Geom_BezierCurve::Increase, "Increases the degree of a bezier curve. Degree is the new degree of <me>. Raises ConstructionError if Degree is greater than MaxDegree or lower than 2 or lower than the initial degree of <me>.", py::arg("Degree"));
cls_Geom_BezierCurve.def("InsertPoleAfter", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &)) &Geom_BezierCurve::InsertPoleAfter, "Inserts a pole P after the pole of range Index. If the curve <me> is rational the weight value for the new pole of range Index is 1.0. raised if Index is not in the range [1, NbPoles]", py::arg("Index"), py::arg("P"));
cls_Geom_BezierCurve.def("InsertPoleAfter", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &, const Standard_Real)) &Geom_BezierCurve::InsertPoleAfter, "Inserts a pole with its weight in the set of poles after the pole of range Index. If the curve was non rational it can become rational if all the weights are not identical. Raised if Index is not in the range [1, NbPoles]", py::arg("Index"), py::arg("P"), py::arg("Weight"));
cls_Geom_BezierCurve.def("InsertPoleBefore", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &)) &Geom_BezierCurve::InsertPoleBefore, "Inserts a pole P before the pole of range Index. If the curve <me> is rational the weight value for the new pole of range Index is 1.0. Raised if Index is not in the range [1, NbPoles]", py::arg("Index"), py::arg("P"));
cls_Geom_BezierCurve.def("InsertPoleBefore", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &, const Standard_Real)) &Geom_BezierCurve::InsertPoleBefore, "Inserts a pole with its weight in the set of poles after the pole of range Index. If the curve was non rational it can become rational if all the weights are not identical. Raised if Index is not in the range [1, NbPoles]", py::arg("Index"), py::arg("P"), py::arg("Weight"));
cls_Geom_BezierCurve.def("RemovePole", (void (Geom_BezierCurve::*)(const Standard_Integer)) &Geom_BezierCurve::RemovePole, "Removes the pole of range Index. If the curve was rational it can become non rational. Raised if Index is not in the range [1, NbPoles] Raised if Degree is lower than 2.", py::arg("Index"));
cls_Geom_BezierCurve.def("Reverse", (void (Geom_BezierCurve::*)()) &Geom_BezierCurve::Reverse, "Reverses the direction of parametrization of <me> Value (NewU) = Value (1 - OldU)");
cls_Geom_BezierCurve.def("ReversedParameter", (Standard_Real (Geom_BezierCurve::*)(const Standard_Real) const) &Geom_BezierCurve::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Geom_BezierCurve.def("Segment", (void (Geom_BezierCurve::*)(const Standard_Real, const Standard_Real)) &Geom_BezierCurve::Segment, "Segments the curve between U1 and U2 which can be out of the bounds of the curve. The curve is oriented from U1 to U2. The control points are modified, the first and the last point are not the same but the parametrization range is [0, 1] else it could not be a Bezier curve. Warnings : Even if <me> is not closed it can become closed after the segmentation for example if U1 or U2 are out of the bounds of the curve <me> or if the curve makes loop. After the segmentation the length of a curve can be null.", py::arg("U1"), py::arg("U2"));
cls_Geom_BezierCurve.def("SetPole", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &)) &Geom_BezierCurve::SetPole, "Substitutes the pole of range index with P. If the curve <me> is rational the weight of range Index is not modified. raiseD if Index is not in the range [1, NbPoles]", py::arg("Index"), py::arg("P"));
cls_Geom_BezierCurve.def("SetPole", (void (Geom_BezierCurve::*)(const Standard_Integer, const gp_Pnt &, const Standard_Real)) &Geom_BezierCurve::SetPole, "Substitutes the pole and the weights of range Index. If the curve <me> is not rational it can become rational if all the weights are not identical. If the curve was rational it can become non rational if all the weights are identical. Raised if Index is not in the range [1, NbPoles] Raised if Weight <= Resolution from package gp", py::arg("Index"), py::arg("P"), py::arg("Weight"));
cls_Geom_BezierCurve.def("SetWeight", (void (Geom_BezierCurve::*)(const Standard_Integer, const Standard_Real)) &Geom_BezierCurve::SetWeight, "Changes the weight of the pole of range Index. If the curve <me> is not rational it can become rational if all the weights are not identical. If the curve was rational it can become non rational if all the weights are identical. Raised if Index is not in the range [1, NbPoles] Raised if Weight <= Resolution from package gp", py::arg("Index"), py::arg("Weight"));
cls_Geom_BezierCurve.def("IsClosed", (Standard_Boolean (Geom_BezierCurve::*)() const) &Geom_BezierCurve::IsClosed, "Returns True if the distance between the first point and the last point of the curve is lower or equal to the Resolution from package gp.");
cls_Geom_BezierCurve.def("IsCN", (Standard_Boolean (Geom_BezierCurve::*)(const Standard_Integer) const) &Geom_BezierCurve::IsCN, "Continuity of the curve, returns True.", py::arg("N"));
cls_Geom_BezierCurve.def("IsPeriodic", (Standard_Boolean (Geom_BezierCurve::*)() const) &Geom_BezierCurve::IsPeriodic, "Returns True if the parametrization of a curve is periodic. (P(u) = P(u + T) T = constante)");
cls_Geom_BezierCurve.def("IsRational", (Standard_Boolean (Geom_BezierCurve::*)() const) &Geom_BezierCurve::IsRational, "Returns false if all the weights are identical. The tolerance criterion is Resolution from package gp.");
cls_Geom_BezierCurve.def("Continuity", (GeomAbs_Shape (Geom_BezierCurve::*)() const) &Geom_BezierCurve::Continuity, "a Bezier curve is CN");
cls_Geom_BezierCurve.def("Degree", (Standard_Integer (Geom_BezierCurve::*)() const) &Geom_BezierCurve::Degree, "Returns the polynomial degree of the curve. it is the number of poles - 1 point P and derivatives (V1, V2, V3) computation The Bezier Curve has a Polynomial representation so the parameter U can be out of the bounds of the curve.");
cls_Geom_BezierCurve.def("D0", (void (Geom_BezierCurve::*)(const Standard_Real, gp_Pnt &) const) &Geom_BezierCurve::D0, "None", py::arg("U"), py::arg("P"));
cls_Geom_BezierCurve.def("D1", (void (Geom_BezierCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_BezierCurve::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_BezierCurve.def("D2", (void (Geom_BezierCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_BezierCurve::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_BezierCurve.def("D3", (void (Geom_BezierCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_BezierCurve::D3, "For this Bezier curve, computes - the point P of parameter U, or - the point P and one or more of the following values: - V1, the first derivative vector, - V2, the second derivative vector, - V3, the third derivative vector. Note: the parameter U can be outside the bounds of the curve.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_BezierCurve.def("DN", (gp_Vec (Geom_BezierCurve::*)(const Standard_Real, const Standard_Integer) const) &Geom_BezierCurve::DN, "For the point of parameter U of this Bezier curve, computes the vector corresponding to the Nth derivative. Note: the parameter U can be outside the bounds of the curve. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom_BezierCurve.def("StartPoint", (gp_Pnt (Geom_BezierCurve::*)() const) &Geom_BezierCurve::StartPoint, "Returns Value (U=0.), it is the first control point of the curve.");
cls_Geom_BezierCurve.def("EndPoint", (gp_Pnt (Geom_BezierCurve::*)() const) &Geom_BezierCurve::EndPoint, "Returns Value (U=1.), it is the last control point of the Bezier curve.");
cls_Geom_BezierCurve.def("FirstParameter", (Standard_Real (Geom_BezierCurve::*)() const) &Geom_BezierCurve::FirstParameter, "Returns the value of the first parameter of this Bezier curve. This is 0.0, which gives the start point of this Bezier curve");
cls_Geom_BezierCurve.def("LastParameter", (Standard_Real (Geom_BezierCurve::*)() const) &Geom_BezierCurve::LastParameter, "Returns the value of the last parameter of this Bezier curve. This is 1.0, which gives the end point of this Bezier curve.");
cls_Geom_BezierCurve.def("NbPoles", (Standard_Integer (Geom_BezierCurve::*)() const) &Geom_BezierCurve::NbPoles, "Returns the number of poles of this Bezier curve.");
cls_Geom_BezierCurve.def("Pole", (const gp_Pnt & (Geom_BezierCurve::*)(const Standard_Integer) const) &Geom_BezierCurve::Pole, "Returns the pole of range Index. Raised if Index is not in the range [1, NbPoles]", py::arg("Index"));
cls_Geom_BezierCurve.def("Poles", (void (Geom_BezierCurve::*)(TColgp_Array1OfPnt &) const) &Geom_BezierCurve::Poles, "Returns all the poles of the curve.", py::arg("P"));
cls_Geom_BezierCurve.def("Poles", (const TColgp_Array1OfPnt & (Geom_BezierCurve::*)() const) &Geom_BezierCurve::Poles, "Returns all the poles of the curve.");
cls_Geom_BezierCurve.def("Weight", (Standard_Real (Geom_BezierCurve::*)(const Standard_Integer) const) &Geom_BezierCurve::Weight, "Returns the weight of range Index. Raised if Index is not in the range [1, NbPoles]", py::arg("Index"));
cls_Geom_BezierCurve.def("Weights", (void (Geom_BezierCurve::*)(TColStd_Array1OfReal &) const) &Geom_BezierCurve::Weights, "Returns all the weights of the curve.", py::arg("W"));
cls_Geom_BezierCurve.def("Weights", (const TColStd_Array1OfReal * (Geom_BezierCurve::*)() const) &Geom_BezierCurve::Weights, "Returns all the weights of the curve.");
cls_Geom_BezierCurve.def("Transform", (void (Geom_BezierCurve::*)(const gp_Trsf &)) &Geom_BezierCurve::Transform, "Applies the transformation T to this Bezier curve.", py::arg("T"));
cls_Geom_BezierCurve.def_static("MaxDegree_", (Standard_Integer (*)()) &Geom_BezierCurve::MaxDegree, "Returns the value of the maximum polynomial degree of any Geom_BezierCurve curve. This value is 25.");
cls_Geom_BezierCurve.def("Resolution", [](Geom_BezierCurve &self, const Standard_Real Tolerance3D, Standard_Real & UTolerance){ self.Resolution(Tolerance3D, UTolerance); return UTolerance; }, "Computes for this Bezier curve the parametric tolerance UTolerance for a given 3D tolerance Tolerance3D. If f(t) is the equation of this Bezier curve, UTolerance ensures that: |t1-t0| < UTolerance ===> |f(t1)-f(t0)| < Tolerance3D", py::arg("Tolerance3D"), py::arg("UTolerance"));
cls_Geom_BezierCurve.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_BezierCurve::*)() const) &Geom_BezierCurve::Copy, "Creates a new object which is a copy of this Bezier curve.");
cls_Geom_BezierCurve.def_static("get_type_name_", (const char * (*)()) &Geom_BezierCurve::get_type_name, "None");
cls_Geom_BezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_BezierCurve::get_type_descriptor, "None");
cls_Geom_BezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_BezierCurve::*)() const) &Geom_BezierCurve::DynamicType, "None");

// Enums

}