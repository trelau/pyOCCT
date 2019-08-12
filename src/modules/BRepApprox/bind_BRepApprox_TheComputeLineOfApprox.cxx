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
#include <BRepApprox_TheMultiLineOfApprox.hxx>
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
#include <BRepApprox_TheComputeLineOfApprox.hxx>

void bind_BRepApprox_TheComputeLineOfApprox(py::module &mod){

py::class_<BRepApprox_TheComputeLineOfApprox, std::unique_ptr<BRepApprox_TheComputeLineOfApprox, Deleter<BRepApprox_TheComputeLineOfApprox>>> cls_BRepApprox_TheComputeLineOfApprox(mod, "BRepApprox_TheComputeLineOfApprox", "None");

// Constructors
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &>(), py::arg("Line"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<>());
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_BRepApprox_TheComputeLineOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheComputeLineOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheComputeLineOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheComputeLineOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheComputeLineOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheComputeLineOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheComputeLineOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheComputeLineOfApprox.def("Interpol", (void (BRepApprox_TheComputeLineOfApprox::*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheComputeLineOfApprox::Interpol, "Constructs an interpolation of the MultiLine <Line> The result will be a C2 curve of degree 3.", py::arg("Line"));
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self) -> void { return self.Init(); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", [](BRepApprox_TheComputeLineOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepApprox_TheComputeLineOfApprox.def("Init", (void (BRepApprox_TheComputeLineOfApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &BRepApprox_TheComputeLineOfApprox::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineOfApprox.def("Perform", (void (BRepApprox_TheComputeLineOfApprox::*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheComputeLineOfApprox::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetParameters", (void (BRepApprox_TheComputeLineOfApprox::*)(const math_Vector &)) &BRepApprox_TheComputeLineOfApprox::SetParameters, "The approximation will begin with the set of parameters <ThePar>.", py::arg("ThePar"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetKnots", (void (BRepApprox_TheComputeLineOfApprox::*)(const TColStd_Array1OfReal &)) &BRepApprox_TheComputeLineOfApprox::SetKnots, "The approximation will be done with the set of knots <Knots>. The multiplicities will be set with the degree and the desired continuity.", py::arg("Knots"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetKnotsAndMultiplicities", (void (BRepApprox_TheComputeLineOfApprox::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &)) &BRepApprox_TheComputeLineOfApprox::SetKnotsAndMultiplicities, "The approximation will be done with the set of knots <Knots> and the multiplicities <Mults>.", py::arg("Knots"), py::arg("Mults"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetDegrees", (void (BRepApprox_TheComputeLineOfApprox::*)(const Standard_Integer, const Standard_Integer)) &BRepApprox_TheComputeLineOfApprox::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetTolerances", (void (BRepApprox_TheComputeLineOfApprox::*)(const Standard_Real, const Standard_Real)) &BRepApprox_TheComputeLineOfApprox::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetContinuity", (void (BRepApprox_TheComputeLineOfApprox::*)(const Standard_Integer)) &BRepApprox_TheComputeLineOfApprox::SetContinuity, "sets the continuity of the spline. if C = 2, the spline will be C2.", py::arg("C"));
cls_BRepApprox_TheComputeLineOfApprox.def("SetConstraints", (void (BRepApprox_TheComputeLineOfApprox::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &BRepApprox_TheComputeLineOfApprox::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_BRepApprox_TheComputeLineOfApprox.def("IsAllApproximated", (Standard_Boolean (BRepApprox_TheComputeLineOfApprox::*)() const) &BRepApprox_TheComputeLineOfApprox::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_BRepApprox_TheComputeLineOfApprox.def("IsToleranceReached", (Standard_Boolean (BRepApprox_TheComputeLineOfApprox::*)() const) &BRepApprox_TheComputeLineOfApprox::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_BRepApprox_TheComputeLineOfApprox.def("Error", [](BRepApprox_TheComputeLineOfApprox &self, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the MultiBSpCurve.", py::arg("tol3d"), py::arg("tol2d"));
cls_BRepApprox_TheComputeLineOfApprox.def("Value", (const AppParCurves_MultiBSpCurve & (BRepApprox_TheComputeLineOfApprox::*)() const) &BRepApprox_TheComputeLineOfApprox::Value, "returns the result of the approximation.");
cls_BRepApprox_TheComputeLineOfApprox.def("ChangeValue", (AppParCurves_MultiBSpCurve & (BRepApprox_TheComputeLineOfApprox::*)()) &BRepApprox_TheComputeLineOfApprox::ChangeValue, "returns the result of the approximation.");
cls_BRepApprox_TheComputeLineOfApprox.def("Parameters", (const TColStd_Array1OfReal & (BRepApprox_TheComputeLineOfApprox::*)() const) &BRepApprox_TheComputeLineOfApprox::Parameters, "returns the new parameters of the approximation corresponding to the points of the MultiBSpCurve.");

// Enums

}