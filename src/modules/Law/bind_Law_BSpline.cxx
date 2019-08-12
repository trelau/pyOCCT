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
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomAbs_BSplKnotDistribution.hxx>
#include <Standard_Handle.hxx>
#include <Law_BSpline.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_Law_BSpline(py::module &mod){

py::class_<Law_BSpline, opencascade::handle<Law_BSpline>, Standard_Transient> cls_Law_BSpline(mod, "Law_BSpline", "Definition of the 1D B_spline curve.");

// Constructors
cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("Poles"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"));
cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Boolean>(), py::arg("Poles"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"), py::arg("Periodic"));
cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("Poles"), py::arg("Weights"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"));
cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Boolean>(), py::arg("Poles"), py::arg("Weights"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"), py::arg("Periodic"));

// Fields

// Methods
cls_Law_BSpline.def("IncreaseDegree", (void (Law_BSpline::*)(const Standard_Integer)) &Law_BSpline::IncreaseDegree, "Increase the degree to <Degree>. Nothing is done if <Degree> is lower or equal to the current degree.", py::arg("Degree"));
cls_Law_BSpline.def("IncreaseMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncreaseMultiplicity, "Increases the multiplicity of the knot <Index> to <M>.", py::arg("Index"), py::arg("M"));
cls_Law_BSpline.def("IncreaseMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncreaseMultiplicity, "Increases the multiplicities of the knots in [I1,I2] to <M>.", py::arg("I1"), py::arg("I2"), py::arg("M"));
cls_Law_BSpline.def("IncrementMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncrementMultiplicity, "Increment the multiplicities of the knots in [I1,I2] by <M>.", py::arg("I1"), py::arg("I2"), py::arg("M"));
cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0) -> void { return self.InsertKnot(a0); });
cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0, const Standard_Integer a1) -> void { return self.InsertKnot(a0, a1); });
cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.InsertKnot(a0, a1, a2); });
cls_Law_BSpline.def("InsertKnot", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &Law_BSpline::InsertKnot, "Inserts a knot value in the sequence of knots. If <U> is an existing knot the multiplicity is increased by <M>.", py::arg("U"), py::arg("M"), py::arg("ParametricTolerance"), py::arg("Add"));
cls_Law_BSpline.def("InsertKnots", [](Law_BSpline &self, const TColStd_Array1OfReal & a0, const TColStd_Array1OfInteger & a1) -> void { return self.InsertKnots(a0, a1); });
cls_Law_BSpline.def("InsertKnots", [](Law_BSpline &self, const TColStd_Array1OfReal & a0, const TColStd_Array1OfInteger & a1, const Standard_Real a2) -> void { return self.InsertKnots(a0, a1, a2); });
cls_Law_BSpline.def("InsertKnots", (void (Law_BSpline::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Real, const Standard_Boolean)) &Law_BSpline::InsertKnots, "Inserts a set of knots values in the sequence of knots.", py::arg("Knots"), py::arg("Mults"), py::arg("ParametricTolerance"), py::arg("Add"));
cls_Law_BSpline.def("RemoveKnot", (Standard_Boolean (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Law_BSpline::RemoveKnot, "Decrement the knots multiplicity to <M>. If M is 0 the knot is removed. The Poles sequence is modified.", py::arg("Index"), py::arg("M"), py::arg("Tolerance"));
cls_Law_BSpline.def("Reverse", (void (Law_BSpline::*)()) &Law_BSpline::Reverse, "Changes the direction of parametrization of <me>. The Knot sequence is modified, the FirstParameter and the LastParameter are not modified. The StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
cls_Law_BSpline.def("ReversedParameter", (Standard_Real (Law_BSpline::*)(const Standard_Real) const) &Law_BSpline::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
cls_Law_BSpline.def("Segment", (void (Law_BSpline::*)(const Standard_Real, const Standard_Real)) &Law_BSpline::Segment, "Segments the curve between U1 and U2. The control points are modified, the first and the last point are not the same. Warnings : Even if <me> is not closed it can become closed after the segmentation for example if U1 or U2 are out of the bounds of the curve <me> or if the curve makes loop. After the segmentation the length of a curve can be null. raises if U2 < U1.", py::arg("U1"), py::arg("U2"));
cls_Law_BSpline.def("SetKnot", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetKnot, "Changes the knot of range Index. The multiplicity of the knot is not modified. Raised if K >= Knots(Index+1) or K <= Knots(Index-1). Raised if Index < 1 || Index > NbKnots", py::arg("Index"), py::arg("K"));
cls_Law_BSpline.def("SetKnots", (void (Law_BSpline::*)(const TColStd_Array1OfReal &)) &Law_BSpline::SetKnots, "Changes all the knots of the curve The multiplicity of the knots are not modified.", py::arg("K"));
cls_Law_BSpline.def("SetKnot", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real, const Standard_Integer)) &Law_BSpline::SetKnot, "Changes the knot of range Index with its multiplicity. You can increase the multiplicity of a knot but it is not allowed to decrease the multiplicity of an existing knot.", py::arg("Index"), py::arg("K"), py::arg("M"));
cls_Law_BSpline.def("PeriodicNormalization", [](Law_BSpline &self, Standard_Real & U){ self.PeriodicNormalization(U); return U; }, "returns the parameter normalized within the period if the curve is periodic : otherwise does not do anything", py::arg("U"));
cls_Law_BSpline.def("SetPeriodic", (void (Law_BSpline::*)()) &Law_BSpline::SetPeriodic, "Makes a closed B-spline into a periodic curve. The curve is periodic if the knot sequence is periodic and if the curve is closed (The tolerance criterion is Resolution from gp). The period T is equal to Knot(LastUKnotIndex) - Knot(FirstUKnotIndex). A periodic B-spline can be uniform or not. Raised if the curve is not closed.");
cls_Law_BSpline.def("SetOrigin", (void (Law_BSpline::*)(const Standard_Integer)) &Law_BSpline::SetOrigin, "Set the origin of a periodic curve at Knot(index) KnotVector and poles are modified. Raised if the curve is not periodic Raised if index not in the range [FirstUKnotIndex , LastUKnotIndex]", py::arg("Index"));
cls_Law_BSpline.def("SetNotPeriodic", (void (Law_BSpline::*)()) &Law_BSpline::SetNotPeriodic, "Makes a non periodic curve. If the curve was non periodic the curve is not modified.");
cls_Law_BSpline.def("SetPole", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetPole, "Substitutes the Pole of range Index with P.", py::arg("Index"), py::arg("P"));
cls_Law_BSpline.def("SetPole", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Law_BSpline::SetPole, "Substitutes the pole and the weight of range Index. If the curve <me> is not rational it can become rational If the curve was rational it can become non rational", py::arg("Index"), py::arg("P"), py::arg("Weight"));
cls_Law_BSpline.def("SetWeight", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetWeight, "Changes the weight for the pole of range Index. If the curve was non rational it can become rational. If the curve was rational it can become non rational.", py::arg("Index"), py::arg("Weight"));
cls_Law_BSpline.def("IsCN", (Standard_Boolean (Law_BSpline::*)(const Standard_Integer) const) &Law_BSpline::IsCN, "Returns the continuity of the curve, the curve is at least C0. Raised if N < 0.", py::arg("N"));
cls_Law_BSpline.def("IsClosed", (Standard_Boolean (Law_BSpline::*)() const) &Law_BSpline::IsClosed, "Returns true if the distance between the first point and the last point of the curve is lower or equal to Resolution from package gp. Warnings : The first and the last point can be different from the first pole and the last pole of the curve.");
cls_Law_BSpline.def("IsPeriodic", (Standard_Boolean (Law_BSpline::*)() const) &Law_BSpline::IsPeriodic, "Returns True if the curve is periodic.");
cls_Law_BSpline.def("IsRational", (Standard_Boolean (Law_BSpline::*)() const) &Law_BSpline::IsRational, "Returns True if the weights are not identical. The tolerance criterion is Epsilon of the class Real.");
cls_Law_BSpline.def("Continuity", (GeomAbs_Shape (Law_BSpline::*)() const) &Law_BSpline::Continuity, "Returns the global continuity of the curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, CN : the order of continuity is infinite. For a B-spline curve of degree d if a knot Ui has a multiplicity p the B-spline curve is only Cd-p continuous at Ui. So the global continuity of the curve can't be greater than Cd-p where p is the maximum multiplicity of the interior Knots. In the interior of a knot span the curve is infinitely continuously differentiable.");
cls_Law_BSpline.def("Degree", (Standard_Integer (Law_BSpline::*)() const) &Law_BSpline::Degree, "Computation of value and derivatives");
cls_Law_BSpline.def("Value", (Standard_Real (Law_BSpline::*)(const Standard_Real) const) &Law_BSpline::Value, "None", py::arg("U"));
cls_Law_BSpline.def("D0", [](Law_BSpline &self, const Standard_Real U, Standard_Real & P){ self.D0(U, P); return P; }, "None", py::arg("U"), py::arg("P"));
cls_Law_BSpline.def("D1", [](Law_BSpline &self, const Standard_Real U, Standard_Real & P, Standard_Real & V1){ self.D1(U, P, V1); return std::tuple<Standard_Real &, Standard_Real &>(P, V1); }, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Law_BSpline.def("D2", [](Law_BSpline &self, const Standard_Real U, Standard_Real & P, Standard_Real & V1, Standard_Real & V2){ self.D2(U, P, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(P, V1, V2); }, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Law_BSpline.def("D3", [](Law_BSpline &self, const Standard_Real U, Standard_Real & P, Standard_Real & V1, Standard_Real & V2, Standard_Real & V3){ self.D3(U, P, V1, V2, V3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(P, V1, V2, V3); }, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Law_BSpline.def("DN", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer) const) &Law_BSpline::DN, "The following functions computes the point of parameter U and the derivatives at this point on the B-spline curve arc defined between the knot FromK1 and the knot ToK2. U can be out of bounds [Knot (FromK1), Knot (ToK2)] but for the computation we only use the definition of the curve between these two knots. This method is useful to compute local derivative, if the order of continuity of the whole curve is not greater enough. Inside the parametric domain Knot (FromK1), Knot (ToK2) the evaluations are the same as if we consider the whole definition of the curve. Of course the evaluations are different outside this parametric domain.", py::arg("U"), py::arg("N"));
cls_Law_BSpline.def("LocalValue", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Law_BSpline::LocalValue, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"));
cls_Law_BSpline.def("LocalD0", [](Law_BSpline &self, const Standard_Real U, const Standard_Integer FromK1, const Standard_Integer ToK2, Standard_Real & P){ self.LocalD0(U, FromK1, ToK2, P); return P; }, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"));
cls_Law_BSpline.def("LocalD1", [](Law_BSpline &self, const Standard_Real U, const Standard_Integer FromK1, const Standard_Integer ToK2, Standard_Real & P, Standard_Real & V1){ self.LocalD1(U, FromK1, ToK2, P, V1); return std::tuple<Standard_Real &, Standard_Real &>(P, V1); }, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"));
cls_Law_BSpline.def("LocalD2", [](Law_BSpline &self, const Standard_Real U, const Standard_Integer FromK1, const Standard_Integer ToK2, Standard_Real & P, Standard_Real & V1, Standard_Real & V2){ self.LocalD2(U, FromK1, ToK2, P, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(P, V1, V2); }, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Law_BSpline.def("LocalD3", [](Law_BSpline &self, const Standard_Real U, const Standard_Integer FromK1, const Standard_Integer ToK2, Standard_Real & P, Standard_Real & V1, Standard_Real & V2, Standard_Real & V3){ self.LocalD3(U, FromK1, ToK2, P, V1, V2, V3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(P, V1, V2, V3); }, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Law_BSpline.def("LocalDN", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &Law_BSpline::LocalDN, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("N"));
cls_Law_BSpline.def("EndPoint", (Standard_Real (Law_BSpline::*)() const) &Law_BSpline::EndPoint, "Returns the last point of the curve. Warnings : The last point of the curve is different from the last pole of the curve if the multiplicity of the last knot is lower than Degree.");
cls_Law_BSpline.def("FirstUKnotIndex", (Standard_Integer (Law_BSpline::*)() const) &Law_BSpline::FirstUKnotIndex, "For a B-spline curve the first parameter (which gives the start point of the curve) is a knot value but if the multiplicity of the first knot index is lower than Degree + 1 it is not the first knot of the curve. This method computes the index of the knot corresponding to the first parameter.");
cls_Law_BSpline.def("FirstParameter", (Standard_Real (Law_BSpline::*)() const) &Law_BSpline::FirstParameter, "Computes the parametric value of the start point of the curve. It is a knot value.");
cls_Law_BSpline.def("Knot", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const) &Law_BSpline::Knot, "Returns the knot of range Index. When there is a knot with a multiplicity greater than 1 the knot is not repeated. The method Multiplicity can be used to get the multiplicity of the Knot. Raised if Index < 1 or Index > NbKnots", py::arg("Index"));
cls_Law_BSpline.def("Knots", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const) &Law_BSpline::Knots, "returns the knot values of the B-spline curve;", py::arg("K"));
cls_Law_BSpline.def("KnotSequence", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const) &Law_BSpline::KnotSequence, "Returns the knots sequence. In this sequence the knots with a multiplicity greater than 1 are repeated. Example : K = {k1, k1, k1, k2, k3, k3, k4, k4, k4}", py::arg("K"));
cls_Law_BSpline.def("KnotDistribution", (GeomAbs_BSplKnotDistribution (Law_BSpline::*)() const) &Law_BSpline::KnotDistribution, "Returns NonUniform or Uniform or QuasiUniform or PiecewiseBezier. If all the knots differ by a positive constant from the preceding knot the BSpline Curve can be : - Uniform if all the knots are of multiplicity 1, - QuasiUniform if all the knots are of multiplicity 1 except for the first and last knot which are of multiplicity Degree + 1, - PiecewiseBezier if the first and last knots have multiplicity Degree + 1 and if interior knots have multiplicity Degree A piecewise Bezier with only two knots is a BezierCurve. else the curve is non uniform. The tolerance criterion is Epsilon from class Real.");
cls_Law_BSpline.def("LastUKnotIndex", (Standard_Integer (Law_BSpline::*)() const) &Law_BSpline::LastUKnotIndex, "For a BSpline curve the last parameter (which gives the end point of the curve) is a knot value but if the multiplicity of the last knot index is lower than Degree + 1 it is not the last knot of the curve. This method computes the index of the knot corresponding to the last parameter.");
cls_Law_BSpline.def("LastParameter", (Standard_Real (Law_BSpline::*)() const) &Law_BSpline::LastParameter, "Computes the parametric value of the end point of the curve. It is a knot value.");
cls_Law_BSpline.def("LocateU", [](Law_BSpline &self, const Standard_Real U, const Standard_Real ParametricTolerance, Standard_Integer & I1, Standard_Integer & I2, const Standard_Boolean WithKnotRepetition){ self.LocateU(U, ParametricTolerance, I1, I2, WithKnotRepetition); return std::tuple<Standard_Integer &, Standard_Integer &>(I1, I2); }, "Locates the parametric value U in the sequence of knots. If 'WithKnotRepetition' is True we consider the knot's representation with repetition of multiple knot value, otherwise we consider the knot's representation with no repetition of multiple knot values. Knots (I1) <= U <= Knots (I2) . if I1 = I2 U is a knot value (the tolerance criterion ParametricTolerance is used). . if I1 < 1 => U < Knots (1) - Abs(ParametricTolerance) . if I2 > NbKnots => U > Knots (NbKnots) + Abs(ParametricTolerance)", py::arg("U"), py::arg("ParametricTolerance"), py::arg("I1"), py::arg("I2"), py::arg("WithKnotRepetition"));
cls_Law_BSpline.def("Multiplicity", (Standard_Integer (Law_BSpline::*)(const Standard_Integer) const) &Law_BSpline::Multiplicity, "Returns the multiplicity of the knots of range Index. Raised if Index < 1 or Index > NbKnots", py::arg("Index"));
cls_Law_BSpline.def("Multiplicities", (void (Law_BSpline::*)(TColStd_Array1OfInteger &) const) &Law_BSpline::Multiplicities, "Returns the multiplicity of the knots of the curve.", py::arg("M"));
cls_Law_BSpline.def("NbKnots", (Standard_Integer (Law_BSpline::*)() const) &Law_BSpline::NbKnots, "Returns the number of knots. This method returns the number of knot without repetition of multiple knots.");
cls_Law_BSpline.def("NbPoles", (Standard_Integer (Law_BSpline::*)() const) &Law_BSpline::NbPoles, "Returns the number of poles");
cls_Law_BSpline.def("Pole", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const) &Law_BSpline::Pole, "Returns the pole of range Index. Raised if Index < 1 or Index > NbPoles.", py::arg("Index"));
cls_Law_BSpline.def("Poles", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const) &Law_BSpline::Poles, "Returns the poles of the B-spline curve;", py::arg("P"));
cls_Law_BSpline.def("StartPoint", (Standard_Real (Law_BSpline::*)() const) &Law_BSpline::StartPoint, "Returns the start point of the curve. Warnings : This point is different from the first pole of the curve if the multiplicity of the first knot is lower than Degree.");
cls_Law_BSpline.def("Weight", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const) &Law_BSpline::Weight, "Returns the weight of the pole of range Index . Raised if Index < 1 or Index > NbPoles.", py::arg("Index"));
cls_Law_BSpline.def("Weights", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const) &Law_BSpline::Weights, "Returns the weights of the B-spline curve;", py::arg("W"));
cls_Law_BSpline.def_static("MaxDegree_", (Standard_Integer (*)()) &Law_BSpline::MaxDegree, "Returns the value of the maximum degree of the normalized B-spline basis functions in this package.");
cls_Law_BSpline.def("MovePointAndTangent", [](Law_BSpline &self, const Standard_Real U, const Standard_Real NewValue, const Standard_Real Derivative, const Standard_Real Tolerance, const Standard_Integer StartingCondition, const Standard_Integer EndingCondition, Standard_Integer & ErrorStatus){ self.MovePointAndTangent(U, NewValue, Derivative, Tolerance, StartingCondition, EndingCondition, ErrorStatus); return ErrorStatus; }, "Changes the value of the Law at parameter U to NewValue. and makes its derivative at U be derivative. StartingCondition = -1 means first can move EndingCondition = -1 means last point can move StartingCondition = 0 means the first point cannot move EndingCondition = 0 means the last point cannot move StartingCondition = 1 means the first point and tangent cannot move EndingCondition = 1 means the last point and tangent cannot move and so forth ErrorStatus != 0 means that there are not enought degree of freedom with the constrain to deform the curve accordingly", py::arg("U"), py::arg("NewValue"), py::arg("Derivative"), py::arg("Tolerance"), py::arg("StartingCondition"), py::arg("EndingCondition"), py::arg("ErrorStatus"));
cls_Law_BSpline.def("Resolution", [](Law_BSpline &self, const Standard_Real Tolerance3D, Standard_Real & UTolerance){ self.Resolution(Tolerance3D, UTolerance); return UTolerance; }, "given Tolerance3D returns UTolerance such that if f(t) is the curve we have | t1 - t0| < Utolerance ===> |f(t1) - f(t0)| < Tolerance3D", py::arg("Tolerance3D"), py::arg("UTolerance"));
cls_Law_BSpline.def("Copy", (opencascade::handle<Law_BSpline> (Law_BSpline::*)() const) &Law_BSpline::Copy, "None");
cls_Law_BSpline.def_static("get_type_name_", (const char * (*)()) &Law_BSpline::get_type_name, "None");
cls_Law_BSpline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_BSpline::get_type_descriptor, "None");
cls_Law_BSpline.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_BSpline::*)() const) &Law_BSpline::DynamicType, "None");

// Enums

}