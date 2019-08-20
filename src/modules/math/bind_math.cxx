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
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_Function.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <math_MultipleVarFunction.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <math_FunctionSet.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Gauss.hxx>
#include <math_GaussLeastSquare.hxx>
#include <math_SVD.hxx>
#include <math_DirectPolynomialRoots.hxx>
#include <math_FunctionRoots.hxx>
#include <math_BissecNewton.hxx>
#include <math_FunctionRoot.hxx>
#include <math_NewtonFunctionRoot.hxx>
#include <math_BracketedRoot.hxx>
#include <math_FunctionSetRoot.hxx>
#include <math_NewtonFunctionSetRoot.hxx>
#include <math_BracketMinimum.hxx>
#include <math_BrentMinimum.hxx>
#include <math_Powell.hxx>
#include <math_FRPR.hxx>
#include <math_BFGS.hxx>
#include <math_NewtonMinimum.hxx>
#include <math_Jacobi.hxx>
#include <math_GaussSingleIntegration.hxx>
#include <math_GaussMultipleIntegration.hxx>
#include <math_GaussSetIntegration.hxx>
#include <math_FunctionSample.hxx>
#include <math_FunctionAllRoots.hxx>
#include <math_Householder.hxx>
#include <math_Crout.hxx>
#include <math_Uzawa.hxx>
#include <math_TrigonometricFunctionRoots.hxx>
#include <math_KronrodSingleIntegration.hxx>
#include <math_EigenValuesSearcher.hxx>
#include <math_ComputeGaussPointsAndWeights.hxx>
#include <math_ComputeKronrodPointsAndWeights.hxx>
#include <math_DoubleTab.hxx>
#include <math.hxx>

void bind_math(py::module &mod){

py::class_<math, std::unique_ptr<math>> cls_math(mod, "math", "None");

// Constructors

// Fields

// Methods
// cls_math.def_static("operator new_", (void * (*)(size_t)) &math::operator new, "None", py::arg("theSize"));
// cls_math.def_static("operator delete_", (void (*)(void *)) &math::operator delete, "None", py::arg("theAddress"));
// cls_math.def_static("operator new[]_", (void * (*)(size_t)) &math::operator new[], "None", py::arg("theSize"));
// cls_math.def_static("operator delete[]_", (void (*)(void *)) &math::operator delete[], "None", py::arg("theAddress"));
// cls_math.def_static("operator new_", (void * (*)(size_t, void *)) &math::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math.def_static("operator delete_", (void (*)(void *, void *)) &math::operator delete, "None", py::arg(""), py::arg(""));
cls_math.def_static("GaussPointsMax_", (Standard_Integer (*)()) &math::GaussPointsMax, "None");
cls_math.def_static("GaussPoints_", (void (*)(const Standard_Integer, math_Vector &)) &math::GaussPoints, "None", py::arg("Index"), py::arg("Points"));
cls_math.def_static("GaussWeights_", (void (*)(const Standard_Integer, math_Vector &)) &math::GaussWeights, "None", py::arg("Index"), py::arg("Weights"));
cls_math.def_static("KronrodPointsMax_", (Standard_Integer (*)()) &math::KronrodPointsMax, "Returns the maximal number of points for that the values are stored in the table. If the number is greater then KronrodPointsMax, the points will be computed.");
cls_math.def_static("OrderedGaussPointsAndWeights_", (Standard_Boolean (*)(const Standard_Integer, math_Vector &, math_Vector &)) &math::OrderedGaussPointsAndWeights, "Returns a vector of Gauss points and a vector of their weights. The difference with the method GaussPoints is the following: - the points are returned in increasing order. - if Index is greater then GaussPointsMax, the points are computed. Returns Standard_True if Index is positive, Points' and Weights' length is equal to Index, Points and Weights are successfully computed.", py::arg("Index"), py::arg("Points"), py::arg("Weights"));
cls_math.def_static("KronrodPointsAndWeights_", (Standard_Boolean (*)(const Standard_Integer, math_Vector &, math_Vector &)) &math::KronrodPointsAndWeights, "Returns a vector of Kronrod points and a vector of their weights for Gauss-Kronrod computation method. Index should be odd and greater then or equal to 3, as the number of Kronrod points is equal to 2*N + 1, where N is a number of Gauss points. Points and Weights should have the size equal to Index. Each even element of Points represents a Gauss point value of N-th Gauss quadrature. The values from Index equal to 3 to 123 are stored in a table (see the file math_Kronrod.cxx). If Index is greater, then points and weights will be computed. Returns Standard_True if Index is odd, it is equal to the size of Points and Weights and the computation of Points and Weights is performed successfully. Otherwise this method returns Standard_False.", py::arg("Index"), py::arg("Points"), py::arg("Weights"));

// Enums

}