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
#include <GeomInt_TheMultiLineOfWLApprox.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <AppParCurves_Constraint.hxx>
#include <GeomInt_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfWLApprox.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.hxx>

void bind_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox(py::module &mod){

py::class_<GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox, std::unique_ptr<GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox>, math_MultipleVarFunctionWithGradient> cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox(mod, "GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox", "None");

// Constructors
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Knots"), py::arg("Mults"), py::arg("NbPol"));

// Fields

// Methods
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("NbVariables", (Standard_Integer (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("Value", [](GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("Gradient", (Standard_Boolean (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const math_Vector &, math_Vector &)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("Values", [](GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("NewParameters", (const math_Vector & (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::NewParameters, "returns the new parameters of the MultiLine.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("CurveValue", (AppParCurves_MultiBSpCurve (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)()) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::CurveValue, "returns the MultiBSpCurve approximating the set after computing the value F or Grad(F).");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("Error", (Standard_Real (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const Standard_Integer, const Standard_Integer)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("MaxError3d", (Standard_Real (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::MaxError3d, "returns the maximum distance between the points and the MultiBSpCurve.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("MaxError2d", (Standard_Real (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::MaxError2d, "returns the maximum distance between the points and the MultiBSpCurve.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("FunctionMatrix", (const math_Matrix & (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::FunctionMatrix, "returns the function matrix used to approximate the multiline.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("DerivativeFunctionMatrix", (const math_Matrix & (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the multiline.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("Index", (const math_IntegerVector & (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)() const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::Index, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("FirstConstraint", (AppParCurves_Constraint (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("LastConstraint", (AppParCurves_Constraint (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("SetFirstLambda", (void (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const Standard_Real)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::SetFirstLambda, "None", py::arg("l1"));
cls_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox.def("SetLastLambda", (void (GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::*)(const Standard_Real)) &GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox::SetLastLambda, "None", py::arg("l2"));

// Enums

}