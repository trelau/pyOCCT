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
#include <AppDef_Compute.hxx>

void bind_AppDef_Compute(py::module &mod){

py::class_<AppDef_Compute, std::unique_ptr<AppDef_Compute>> cls_AppDef_Compute(mod, "AppDef_Compute", "None");

// Constructors
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &>(), py::arg("Line"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const AppDef_MultiLine &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_AppDef_Compute.def(py::init<>());
cls_AppDef_Compute.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_AppDef_Compute.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_AppDef_Compute.def_static("operator new_", (void * (*)(size_t)) &AppDef_Compute::operator new, "None", py::arg("theSize"));
// cls_AppDef_Compute.def_static("operator delete_", (void (*)(void *)) &AppDef_Compute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_Compute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_Compute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_Compute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_Compute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_Compute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_Compute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self) -> void { return self.Init(); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_AppDef_Compute.def("Init", [](AppDef_Compute &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_AppDef_Compute.def("Init", (void (AppDef_Compute::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &AppDef_Compute::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_AppDef_Compute.def("Perform", (void (AppDef_Compute::*)(const AppDef_MultiLine &)) &AppDef_Compute::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_AppDef_Compute.def("SetDegrees", (void (AppDef_Compute::*)(const Standard_Integer, const Standard_Integer)) &AppDef_Compute::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_AppDef_Compute.def("SetTolerances", (void (AppDef_Compute::*)(const Standard_Real, const Standard_Real)) &AppDef_Compute::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_AppDef_Compute.def("SetConstraints", (void (AppDef_Compute::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &AppDef_Compute::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_AppDef_Compute.def("IsAllApproximated", (Standard_Boolean (AppDef_Compute::*)() const) &AppDef_Compute::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_AppDef_Compute.def("IsToleranceReached", (Standard_Boolean (AppDef_Compute::*)() const) &AppDef_Compute::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_AppDef_Compute.def("Error", [](AppDef_Compute &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_AppDef_Compute.def("NbMultiCurves", (Standard_Integer (AppDef_Compute::*)() const) &AppDef_Compute::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_AppDef_Compute.def("Value", [](AppDef_Compute &self) -> const AppParCurves_MultiCurve & { return self.Value(); });
cls_AppDef_Compute.def("Value", (const AppParCurves_MultiCurve & (AppDef_Compute::*)(const Standard_Integer) const) &AppDef_Compute::Value, "returns the result of the approximation.", py::arg("Index"));
cls_AppDef_Compute.def("ChangeValue", [](AppDef_Compute &self) -> AppParCurves_MultiCurve & { return self.ChangeValue(); });
cls_AppDef_Compute.def("ChangeValue", (AppParCurves_MultiCurve & (AppDef_Compute::*)(const Standard_Integer)) &AppDef_Compute::ChangeValue, "returns the result of the approximation.", py::arg("Index"));
cls_AppDef_Compute.def("SplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_Compute::*)()) &AppDef_Compute::SplineValue, "returns the result of the approximation.");
cls_AppDef_Compute.def("Parametrization", (Approx_ParametrizationType (AppDef_Compute::*)() const) &AppDef_Compute::Parametrization, "returns the type of parametrization");
cls_AppDef_Compute.def("Parameters", [](AppDef_Compute &self) -> const TColStd_Array1OfReal & { return self.Parameters(); });
cls_AppDef_Compute.def("Parameters", (const TColStd_Array1OfReal & (AppDef_Compute::*)(const Standard_Integer) const) &AppDef_Compute::Parameters, "returns the new parameters of the approximation corresponding to the points of the multicurve <Index>.", py::arg("Index"));

// Enums

}