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
#include <GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.hxx>

void bind_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox(py::module &mod){

py::class_<GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox, std::unique_ptr<GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox>> cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox(mod, "GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox", "None");

// Constructors
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("Parameters"), py::arg("NbPol"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def(py::init<const GeomInt_TheMultiLineOfWLApprox &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Integer, const AppParCurves_Constraint, const AppParCurves_Constraint, const Standard_Integer>(), py::arg("SSP"), py::arg("Knots"), py::arg("Mults"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("FirstCons"), py::arg("LastCons"), py::arg("NbPol"));

// Fields

// Methods
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Perform", (void (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)(const math_Vector &)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Perform, "Is used after having initialized the fields. The case 'CurvaturePoint' is not treated in this method.", py::arg("Parameters"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Perform", (void (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)(const math_Vector &, const Standard_Real, const Standard_Real)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Perform, "Is used after having initialized the fields.", py::arg("Parameters"), py::arg("l1"), py::arg("l2"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Perform", (void (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)(const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("l1"), py::arg("l2"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Perform", (void (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)(const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real)) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Perform, "Is used after having initialized the fields. <V1t> is the tangent vector at the first point. <V2t> is the tangent vector at the last point. <V1c> is the tangent vector at the first point. <V2c> is the tangent vector at the last point.", py::arg("Parameters"), py::arg("V1t"), py::arg("V2t"), py::arg("V1c"), py::arg("V2c"), py::arg("l1"), py::arg("l2"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("IsDone", (Standard_Boolean (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::IsDone, "returns True if all has been correctly done.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("BezierValue", (AppParCurves_MultiCurve (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)()) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::BezierValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("BSplineValue", (const AppParCurves_MultiBSpCurve & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)()) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::BSplineValue, "returns the result of the approximation, i.e. all the Curves. An exception is raised if NotDone.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("FunctionMatrix", (const math_Matrix & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::FunctionMatrix, "returns the function matrix used to approximate the set.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("DerivativeFunctionMatrix", (const math_Matrix & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::DerivativeFunctionMatrix, "returns the derivative function matrix used to approximate the set.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("ErrorGradient", [](GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox &self, math_Vector & Grad, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.ErrorGradient(Grad, F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances. Grad is the derivative vector of the function F.", py::arg("Grad"), py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Distance", (const math_Matrix & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)()) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Distance, "returns the distances between the points of the multiline and the approximation curves.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Error", [](GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox &self, Standard_Real & F, Standard_Real & MaxE3d, Standard_Real & MaxE2d){ self.Error(F, MaxE3d, MaxE2d); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, MaxE3d, MaxE2d); }, "returns the maximum errors between the MultiLine and the approximation curves. F is the sum of the square distances.", py::arg("F"), py::arg("MaxE3d"), py::arg("MaxE2d"));
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("FirstLambda", (Standard_Real (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::FirstLambda, "returns the value (P2 - P1)/ V1 if the first point was a tangency point.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("LastLambda", (Standard_Real (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::LastLambda, "returns the value (PN - PN-1)/ VN if the last point was a tangency point.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Points", (const math_Matrix & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Points, "returns the matrix of points value.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("Poles", (const math_Matrix & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::Poles, "returns the matrix of resulting control points value.");
cls_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox.def("KIndex", (const math_IntegerVector & (GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::*)() const) &GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox::KIndex, "Returns the indexes of the first non null values of A and DA. The values are non null from Index(ieme point) +1 to Index(ieme point) + degree +1.");

// Enums

}