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
#include <BRepApprox_TheComputeLineBezierOfApprox.hxx>

void bind_BRepApprox_TheComputeLineBezierOfApprox(py::module &mod){

py::class_<BRepApprox_TheComputeLineBezierOfApprox, std::unique_ptr<BRepApprox_TheComputeLineBezierOfApprox, Deleter<BRepApprox_TheComputeLineBezierOfApprox>>> cls_BRepApprox_TheComputeLineBezierOfApprox(mod, "BRepApprox_TheComputeLineBezierOfApprox", "None");

// Constructors
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &>(), py::arg("Line"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &>(), py::arg("Line"), py::arg("Parameters"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Line"), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &>(), py::arg("Parameters"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("Parameters"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<>());
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));

// Fields

// Methods
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_TheComputeLineBezierOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_TheComputeLineBezierOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_TheComputeLineBezierOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_TheComputeLineBezierOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_TheComputeLineBezierOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_TheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_TheComputeLineBezierOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self) -> void { return self.Init(); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0) -> void { return self.Init(a0); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Init(a0, a1); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4, const Standard_Boolean a5, const Approx_ParametrizationType a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Init", (void (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType, const Standard_Boolean)) &BRepApprox_TheComputeLineBezierOfApprox::Init, "Initializes the fields of the algorithm.", py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("NbIterations"), py::arg("cutting"), py::arg("parametrization"), py::arg("Squares"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Perform", (void (BRepApprox_TheComputeLineBezierOfApprox::*)(const BRepApprox_TheMultiLineOfApprox &)) &BRepApprox_TheComputeLineBezierOfApprox::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("SetDegrees", (void (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Integer, const Standard_Integer)) &BRepApprox_TheComputeLineBezierOfApprox::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("SetTolerances", (void (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Real, const Standard_Real)) &BRepApprox_TheComputeLineBezierOfApprox::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("SetConstraints", (void (BRepApprox_TheComputeLineBezierOfApprox::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &BRepApprox_TheComputeLineBezierOfApprox::SetConstraints, "changes the first and the last constraint points.", py::arg("firstC"), py::arg("lastC"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("IsAllApproximated", (Standard_Boolean (BRepApprox_TheComputeLineBezierOfApprox::*)() const) &BRepApprox_TheComputeLineBezierOfApprox::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_BRepApprox_TheComputeLineBezierOfApprox.def("IsToleranceReached", (Standard_Boolean (BRepApprox_TheComputeLineBezierOfApprox::*)() const) &BRepApprox_TheComputeLineBezierOfApprox::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Error", [](BRepApprox_TheComputeLineBezierOfApprox &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("NbMultiCurves", (Standard_Integer (BRepApprox_TheComputeLineBezierOfApprox::*)() const) &BRepApprox_TheComputeLineBezierOfApprox::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Value", [](BRepApprox_TheComputeLineBezierOfApprox &self) -> const AppParCurves_MultiCurve & { return self.Value(); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Value", (const AppParCurves_MultiCurve & (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Integer) const) &BRepApprox_TheComputeLineBezierOfApprox::Value, "returns the result of the approximation.", py::arg("Index"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("ChangeValue", [](BRepApprox_TheComputeLineBezierOfApprox &self) -> AppParCurves_MultiCurve & { return self.ChangeValue(); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("ChangeValue", (AppParCurves_MultiCurve & (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Integer)) &BRepApprox_TheComputeLineBezierOfApprox::ChangeValue, "returns the result of the approximation.", py::arg("Index"));
cls_BRepApprox_TheComputeLineBezierOfApprox.def("SplineValue", (const AppParCurves_MultiBSpCurve & (BRepApprox_TheComputeLineBezierOfApprox::*)()) &BRepApprox_TheComputeLineBezierOfApprox::SplineValue, "returns the result of the approximation.");
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Parametrization", (Approx_ParametrizationType (BRepApprox_TheComputeLineBezierOfApprox::*)() const) &BRepApprox_TheComputeLineBezierOfApprox::Parametrization, "returns the type of parametrization");
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Parameters", [](BRepApprox_TheComputeLineBezierOfApprox &self) -> const TColStd_Array1OfReal & { return self.Parameters(); });
cls_BRepApprox_TheComputeLineBezierOfApprox.def("Parameters", (const TColStd_Array1OfReal & (BRepApprox_TheComputeLineBezierOfApprox::*)(const Standard_Integer) const) &BRepApprox_TheComputeLineBezierOfApprox::Parameters, "returns the new parameters of the approximation corresponding to the points of the multicurve <Index>.", py::arg("Index"));

// Enums

}