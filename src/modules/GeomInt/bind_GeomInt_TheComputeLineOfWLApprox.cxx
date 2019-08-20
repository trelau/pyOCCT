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
#include <GeomInt_TheMultiLineOfWLApprox.hxx>
#include <Standard_TypeDef.hxx>
#include <Approx_ParametrizationType.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <GeomInt_TheComputeLineOfWLApprox.hxx>

void bind_GeomInt_TheComputeLineOfWLApprox(py::module &mod){

py::class_<GeomInt_TheComputeLineOfWLApprox, std::unique_ptr<GeomInt_TheComputeLineOfWLApprox>> cls_GeomInt_TheComputeLineOfWLApprox(mod, "GeomInt_TheComputeLineOfWLApprox", "None");

// Constructors
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &>(), py::arg("Line"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<>());
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_GeomInt_TheComputeLineOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheComputeLineOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheComputeLineOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheComputeLineOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheComputeLineOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheComputeLineOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheComputeLineOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheComputeLineOfWLApprox.def("Interpol", (void (GeomInt_TheComputeLineOfWLApprox::*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheComputeLineOfWLApprox::Interpol, "Constructs an interpolation of the MultiLine <Line> The result will be a C2 curve of degree 3.", py::arg("Line"));
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self) -> void { return self.Init(); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", [](GeomInt_TheComputeLineOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_TheComputeLineOfWLApprox.def("Init", (void (GeomInt_TheComputeLineOfWLApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &GeomInt_TheComputeLineOfWLApprox::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_GeomInt_TheComputeLineOfWLApprox.def("Perform", (void (GeomInt_TheComputeLineOfWLApprox::*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheComputeLineOfWLApprox::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetParameters", (void (GeomInt_TheComputeLineOfWLApprox::*)(const math_Vector &)) &GeomInt_TheComputeLineOfWLApprox::SetParameters, "The approximation will begin with the set of parameters <ThePar>.", py::arg("ThePar"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetKnots", (void (GeomInt_TheComputeLineOfWLApprox::*)(const TColStd_Array1OfReal &)) &GeomInt_TheComputeLineOfWLApprox::SetKnots, "The approximation will be done with the set of knots <Knots>. The multiplicities will be set with the degree and the desired continuity.", py::arg("Knots"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetKnotsAndMultiplicities", (void (GeomInt_TheComputeLineOfWLApprox::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &)) &GeomInt_TheComputeLineOfWLApprox::SetKnotsAndMultiplicities, "The approximation will be done with the set of knots <Knots> and the multiplicities <Mults>.", py::arg("Knots"), py::arg("Mults"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetDegrees", (void (GeomInt_TheComputeLineOfWLApprox::*)(const Standard_Integer, const Standard_Integer)) &GeomInt_TheComputeLineOfWLApprox::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetTolerances", (void (GeomInt_TheComputeLineOfWLApprox::*)(const Standard_Real, const Standard_Real)) &GeomInt_TheComputeLineOfWLApprox::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetContinuity", (void (GeomInt_TheComputeLineOfWLApprox::*)(const Standard_Integer)) &GeomInt_TheComputeLineOfWLApprox::SetContinuity, "sets the continuity of the spline. if C = 2, the spline will be C2.", py::arg("C"));
cls_GeomInt_TheComputeLineOfWLApprox.def("SetConstraints", (void (GeomInt_TheComputeLineOfWLApprox::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &GeomInt_TheComputeLineOfWLApprox::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_GeomInt_TheComputeLineOfWLApprox.def("IsAllApproximated", (Standard_Boolean (GeomInt_TheComputeLineOfWLApprox::*)() const) &GeomInt_TheComputeLineOfWLApprox::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_GeomInt_TheComputeLineOfWLApprox.def("IsToleranceReached", (Standard_Boolean (GeomInt_TheComputeLineOfWLApprox::*)() const) &GeomInt_TheComputeLineOfWLApprox::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_GeomInt_TheComputeLineOfWLApprox.def("Error", [](GeomInt_TheComputeLineOfWLApprox &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the MultiBSpCurve.", py::arg("tol3d"), py::arg("tol2d"));
cls_GeomInt_TheComputeLineOfWLApprox.def("Value", (const AppParCurves_MultiBSpCurve & (GeomInt_TheComputeLineOfWLApprox::*)() const) &GeomInt_TheComputeLineOfWLApprox::Value, "returns the result of the approximation.");
cls_GeomInt_TheComputeLineOfWLApprox.def("ChangeValue", (AppParCurves_MultiBSpCurve & (GeomInt_TheComputeLineOfWLApprox::*)()) &GeomInt_TheComputeLineOfWLApprox::ChangeValue, "returns the result of the approximation.");
cls_GeomInt_TheComputeLineOfWLApprox.def("Parameters", (const TColStd_Array1OfReal & (GeomInt_TheComputeLineOfWLApprox::*)() const) &GeomInt_TheComputeLineOfWLApprox::Parameters, "returns the new parameters of the approximation corresponding to the points of the MultiBSpCurve.");

// Enums

}