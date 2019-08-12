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
#include <AppCont_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Approx_FitAndDivide2d.hxx>

void bind_Approx_FitAndDivide2d(py::module &mod){

py::class_<Approx_FitAndDivide2d, std::unique_ptr<Approx_FitAndDivide2d, Deleter<Approx_FitAndDivide2d>>> cls_Approx_FitAndDivide2d(mod, "Approx_FitAndDivide2d", "None");

// Constructors
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &>(), py::arg("Line"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
cls_Approx_FitAndDivide2d.def(py::init<>());
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));

// Fields

// Methods
// cls_Approx_FitAndDivide2d.def_static("operator new_", (void * (*)(size_t)) &Approx_FitAndDivide2d::operator new, "None", py::arg("theSize"));
// cls_Approx_FitAndDivide2d.def_static("operator delete_", (void (*)(void *)) &Approx_FitAndDivide2d::operator delete, "None", py::arg("theAddress"));
// cls_Approx_FitAndDivide2d.def_static("operator new[]_", (void * (*)(size_t)) &Approx_FitAndDivide2d::operator new[], "None", py::arg("theSize"));
// cls_Approx_FitAndDivide2d.def_static("operator delete[]_", (void (*)(void *)) &Approx_FitAndDivide2d::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_FitAndDivide2d.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_FitAndDivide2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_FitAndDivide2d.def_static("operator delete_", (void (*)(void *, void *)) &Approx_FitAndDivide2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_FitAndDivide2d.def("Perform", (void (Approx_FitAndDivide2d::*)(const AppCont_Function &)) &Approx_FitAndDivide2d::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
cls_Approx_FitAndDivide2d.def("SetDegrees", (void (Approx_FitAndDivide2d::*)(const Standard_Integer, const Standard_Integer)) &Approx_FitAndDivide2d::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
cls_Approx_FitAndDivide2d.def("SetTolerances", (void (Approx_FitAndDivide2d::*)(const Standard_Real, const Standard_Real)) &Approx_FitAndDivide2d::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
cls_Approx_FitAndDivide2d.def("SetConstraints", (void (Approx_FitAndDivide2d::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &Approx_FitAndDivide2d::SetConstraints, "Changes the constraints of the approximation.", py::arg("FirstC"), py::arg("LastC"));
cls_Approx_FitAndDivide2d.def("SetMaxSegments", (void (Approx_FitAndDivide2d::*)(const Standard_Integer)) &Approx_FitAndDivide2d::SetMaxSegments, "Changes the max number of segments, which is allowed for cutting.", py::arg("theMaxSegments"));
cls_Approx_FitAndDivide2d.def("IsAllApproximated", (Standard_Boolean (Approx_FitAndDivide2d::*)() const) &Approx_FitAndDivide2d::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
cls_Approx_FitAndDivide2d.def("IsToleranceReached", (Standard_Boolean (Approx_FitAndDivide2d::*)() const) &Approx_FitAndDivide2d::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
cls_Approx_FitAndDivide2d.def("Error", [](Approx_FitAndDivide2d &self, const Standard_Integer Index, Standard_Real & tol3d, Standard_Real & tol2d){ self.Error(Index, tol3d, tol2d); return std::tuple<Standard_Real &, Standard_Real &>(tol3d, tol2d); }, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
cls_Approx_FitAndDivide2d.def("NbMultiCurves", (Standard_Integer (Approx_FitAndDivide2d::*)() const) &Approx_FitAndDivide2d::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
cls_Approx_FitAndDivide2d.def("Value", [](Approx_FitAndDivide2d &self) -> AppParCurves_MultiCurve { return self.Value(); });
cls_Approx_FitAndDivide2d.def("Value", (AppParCurves_MultiCurve (Approx_FitAndDivide2d::*)(const Standard_Integer) const) &Approx_FitAndDivide2d::Value, "returns the approximation MultiCurve of range <Index>.", py::arg("Index"));
cls_Approx_FitAndDivide2d.def("Parameters", [](Approx_FitAndDivide2d &self, const Standard_Integer Index, Standard_Real & firstp, Standard_Real & lastp){ self.Parameters(Index, firstp, lastp); return std::tuple<Standard_Real &, Standard_Real &>(firstp, lastp); }, "None", py::arg("Index"), py::arg("firstp"), py::arg("lastp"));

// Enums

}