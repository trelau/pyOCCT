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
#include <AppDef_MultiLine.hxx>
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
#include <AppDef_BSplineCompute.hxx>

void bind_AppDef_BSplineCompute(py::module &mod){

py::class_<AppDef_BSplineCompute, std::unique_ptr<AppDef_BSplineCompute, Deleter<AppDef_BSplineCompute>>> cls_AppDef_BSplineCompute(mod, "AppDef_BSplineCompute", "None");

// Constructors
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &>(), py::arg("Line"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def(py::init<>());
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_BSplineCompute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_AppDef_BSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSplineCompute.def("Interpol", (void (AppDef_BSplineCompute::*)(const AppDef_MultiLine &)) &AppDef_BSplineCompute::Interpol, "Constructs an interpolation of the MultiLine <Line> The result will be a C2 curve of degree 3.", py::arg("Line"));
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self) -> void { return self.Init(); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_AppDef_BSplineCompute.def("Init", [](AppDef_BSplineCompute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_AppDef_BSplineCompute.def("Init", (void (AppDef_BSplineCompute::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &AppDef_BSplineCompute::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_BSplineCompute.def("Perform", (void (AppDef_BSplineCompute::*)(const AppDef_MultiLine &)) &AppDef_BSplineCompute::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_AppDef_BSplineCompute.def("SetParameters", (void (AppDef_BSplineCompute::*)(const math_Vector &)) &AppDef_BSplineCompute::SetParameters, "The approximation will begin with the set of parameters <ThePar>.", py::arg("ThePar"));
cls_AppDef_BSplineCompute.def("SetKnots", (void (AppDef_BSplineCompute::*)(const TColStd_Array1OfReal &)) &AppDef_BSplineCompute::SetKnots, "The approximation will be done with the set of knots <Knots>. The multiplicities will be set with the degree and the desired continuity.", py::arg("Knots"));
cls_AppDef_BSplineCompute.def("SetKnotsAndMultiplicities", (void (AppDef_BSplineCompute::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &)) &AppDef_BSplineCompute::SetKnotsAndMultiplicities, "The approximation will be done with the set of knots <Knots> and the multiplicities <Mults>.", py::arg("Knots"), py::arg("Mults"));
cls_AppDef_BSplineCompute.def("SetDegrees", (void (AppDef_BSplineCompute::*)(const Standard_Integer, const Standard_Integer)) &AppDef_BSplineCompute::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_BSplineCompute.def("SetTolerances", (void (AppDef_BSplineCompute::*)(const Standard_Real, const Standard_Real)) &AppDef_BSplineCompute::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_BSplineCompute.def("SetContinuity", (void (AppDef_BSplineCompute::*)(const Standard_Integer)) &AppDef_BSplineCompute::SetContinuity, "sets the continuity of the spline. if C = 2, the spline will be C2.", py::arg("C"));
cls_AppDef_BSplineCompute.def("SetConstraints", (void (AppDef_BSplineCompute::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &AppDef_BSplineCompute::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_AppDef_BSplineCompute.def("IsAllApproximated", (Standard_Boolean (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_AppDef_BSplineCompute.def("IsToleranceReached", (Standard_Boolean (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_AppDef_BSplineCompute.def("Error", [](AppDef_BSplineCompute &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the MultiBSpCurve.", py::arg("tol3d"), py::arg("tol2d"));
cls_AppDef_BSplineCompute.def("Value", (const AppParCurves_MultiBSpCurve & (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::Value, "returns the result of the approximation.");
cls_AppDef_BSplineCompute.def("ChangeValue", (AppParCurves_MultiBSpCurve & (AppDef_BSplineCompute::*)()) &AppDef_BSplineCompute::ChangeValue, "returns the result of the approximation.");
cls_AppDef_BSplineCompute.def("Parameters", (const TColStd_Array1OfReal & (AppDef_BSplineCompute::*)() const) &AppDef_BSplineCompute::Parameters, "returns the new parameters of the approximation corresponding to the points of the MultiBSpCurve.");

// Enums

}