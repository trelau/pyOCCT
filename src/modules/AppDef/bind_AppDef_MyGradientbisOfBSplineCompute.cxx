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
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Vector.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppDef_MyGradientbisOfBSplineCompute.hxx>

void bind_AppDef_MyGradientbisOfBSplineCompute(py::module &mod){

py::class_<AppDef_MyGradientbisOfBSplineCompute, std::unique_ptr<AppDef_MyGradientbisOfBSplineCompute>> cls_AppDef_MyGradientbisOfBSplineCompute(mod, "AppDef_MyGradientbisOfBSplineCompute", "None");

// Constructors
cls_AppDef_MyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppDef_MyGradientbisOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, math_Vector &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIterations"));

// Fields

// Methods
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyGradientbisOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyGradientbisOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyGradientbisOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyGradientbisOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyGradientbisOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyGradientbisOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("Value", (AppParCurves_MultiCurve (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::Value, "returns all the Bezier curves approximating the MultiLine SSP after minimization of the parameter.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("Error", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)(const Standard_Integer) const) &AppDef_MyGradientbisOfBSplineCompute::Error, "returns the difference between the old and the new approximation. An exception is raised if NotDone. An exception is raised if Index<1 or Index>NbParameters.", py::arg("Index"));
cls_AppDef_MyGradientbisOfBSplineCompute.def("MaxError3d", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::MaxError3d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("MaxError2d", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::MaxError2d, "returns the maximum difference between the old and the new approximation.");
cls_AppDef_MyGradientbisOfBSplineCompute.def("AverageError", (Standard_Real (AppDef_MyGradientbisOfBSplineCompute::*)() const) &AppDef_MyGradientbisOfBSplineCompute::AverageError, "returns the average error between the old and the new approximation.");

// Enums

}