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
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Standard.hxx>
#include <BRepApprox_TheMultiLineOfApprox.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Vector.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_Constraint.hxx>
#include <math_Matrix.hxx>
#include <BRepApprox_ParLeastSquareOfMyGradientbisOfTheComputeLineOfApprox.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.hxx>

void bind_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox(py::module &mod){

py::class_<BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox, math_MultipleVarFunctionWithGradient> cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox(mod, "BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox", "None");

// Constructors
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def(py::init<const BRepApprox_TheMultiLineOfApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Fields

// Methods
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("NbVariables", (Standard_Integer (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("Value", [](BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("Gradient", (Standard_Boolean (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)(const math_Vector &, math_Vector &)) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("Values", [](BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("NewParameters", (const math_Vector & (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::NewParameters, "returns the new parameters of the MultiLine.");
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("CurveValue", (const AppParCurves_MultiCurve & (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)()) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("Error", (Standard_Real (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)(const Standard_Integer, const Standard_Integer) const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("MaxError3d", (Standard_Real (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("MaxError2d", (Standard_Real (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)() const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("FirstConstraint", (AppParCurves_Constraint (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.def("LastConstraint", (AppParCurves_Constraint (BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// Enums

}