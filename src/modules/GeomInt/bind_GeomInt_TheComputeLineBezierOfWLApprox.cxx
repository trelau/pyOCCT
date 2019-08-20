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
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Approx_SequenceOfHArray1OfReal.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <GeomInt_TheComputeLineBezierOfWLApprox.hxx>

void bind_GeomInt_TheComputeLineBezierOfWLApprox(py::module &mod){

py::class_<GeomInt_TheComputeLineBezierOfWLApprox, std::unique_ptr<GeomInt_TheComputeLineBezierOfWLApprox>> cls_GeomInt_TheComputeLineBezierOfWLApprox(mod, "GeomInt_TheComputeLineBezierOfWLApprox", "None");

// Constructors
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &>(), py::arg("Line"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<>());
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_TheComputeLineBezierOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_TheComputeLineBezierOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_TheComputeLineBezierOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_TheComputeLineBezierOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_TheComputeLineBezierOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_TheComputeLineBezierOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_TheComputeLineBezierOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self) -> void { return self.Init(); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Init", (void (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &GeomInt_TheComputeLineBezierOfWLApprox::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Perform", (void (GeomInt_TheComputeLineBezierOfWLApprox::*)(const GeomInt_TheMultiLineOfWLApprox &)) &GeomInt_TheComputeLineBezierOfWLApprox::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("SetDegrees", (void (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Integer, const Standard_Integer)) &GeomInt_TheComputeLineBezierOfWLApprox::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("SetTolerances", (void (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Real, const Standard_Real)) &GeomInt_TheComputeLineBezierOfWLApprox::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("SetConstraints", (void (GeomInt_TheComputeLineBezierOfWLApprox::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &GeomInt_TheComputeLineBezierOfWLApprox::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("IsAllApproximated", (Standard_Boolean (GeomInt_TheComputeLineBezierOfWLApprox::*)() const) &GeomInt_TheComputeLineBezierOfWLApprox::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("IsToleranceReached", (Standard_Boolean (GeomInt_TheComputeLineBezierOfWLApprox::*)() const) &GeomInt_TheComputeLineBezierOfWLApprox::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Error", [](GeomInt_TheComputeLineBezierOfWLApprox &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("NbMultiCurves", (Standard_Integer (GeomInt_TheComputeLineBezierOfWLApprox::*)() const) &GeomInt_TheComputeLineBezierOfWLApprox::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Value", [](GeomInt_TheComputeLineBezierOfWLApprox &self) -> const AppParCurves_MultiCurve & { return self.Value(); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Value", (const AppParCurves_MultiCurve & (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Integer) const) &GeomInt_TheComputeLineBezierOfWLApprox::Value, "returns the result of the approximation.", py::arg("Index"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("ChangeValue", [](GeomInt_TheComputeLineBezierOfWLApprox &self) -> AppParCurves_MultiCurve & { return self.ChangeValue(); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("ChangeValue", (AppParCurves_MultiCurve & (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Integer)) &GeomInt_TheComputeLineBezierOfWLApprox::ChangeValue, "returns the result of the approximation.", py::arg("Index"));
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("SplineValue", (const AppParCurves_MultiBSpCurve & (GeomInt_TheComputeLineBezierOfWLApprox::*)()) &GeomInt_TheComputeLineBezierOfWLApprox::SplineValue, "returns the result of the approximation.");
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Parametrization", (Approx_ParametrizationType (GeomInt_TheComputeLineBezierOfWLApprox::*)() const) &GeomInt_TheComputeLineBezierOfWLApprox::Parametrization, "returns the type of parametrization");
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Parameters", [](GeomInt_TheComputeLineBezierOfWLApprox &self) -> const TColStd_Array1OfReal & { return self.Parameters(); });
cls_GeomInt_TheComputeLineBezierOfWLApprox.def("Parameters", (const TColStd_Array1OfReal & (GeomInt_TheComputeLineBezierOfWLApprox::*)(const Standard_Integer) const) &GeomInt_TheComputeLineBezierOfWLApprox::Parameters, "returns the new parameters of the approximation corresponding to the points of the multicurve <Index>.", py::arg("Index"));

// Enums

}