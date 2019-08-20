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
#include <AppParCurves_Constraint.hxx>
#include <math_Vector.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.hxx>

void bind_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute(py::module &mod){

py::class_<AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute, std::unique_ptr<AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute>> cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute(mod, "AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def(py::init<const AppDef_MultiLine &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Fields

// Methods
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Perform", (void (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("IsDone", (Standard_Boolean (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::IsDone, "returns True if all has been correctly done.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("BezierValue", (AppParCurves_MultiCurve (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("FunctionMatrix", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("DerivativeFunctionMatrix", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("ErrorGradient", [](AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Distance", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)()) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Error", [](AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("FirstLambda", (Standard_Real (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("LastLambda", (Standard_Real (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Points", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Points, "returns the matrix of points value.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("Poles", (const math_Matrix & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::Poles, "returns the matrix of resulting control points value.");
cls_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute.def("KIndex", (const math_IntegerVector & (AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::*)() const) &AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// Enums

}