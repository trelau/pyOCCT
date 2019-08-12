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

void bind_math_Status(py::module &);
void bind_math_Function(py::module &);
void bind_math_FunctionWithDerivative(py::module &);
void bind_math_Vector(py::module &);
void bind_math_DoubleTab(py::module &);
void bind_math_Matrix(py::module &);
void bind_math_BFGS(py::module &);
void bind_math_IntegerVector(py::module &);
void bind_math_MultipleVarFunction(py::module &);
void bind_math_MultipleVarFunctionWithGradient(py::module &);
void bind_math_FunctionSet(py::module &);
void bind_math_FunctionSetWithDerivatives(py::module &);
void bind_math_MultipleVarFunctionWithHessian(py::module &);
void bind_math_NewtonMinimum(py::module &);
void bind_math_FunctionSample(py::module &);
void bind_math_DirectPolynomialRoots(py::module &);
void bind_math_TrigonometricFunctionRoots(py::module &);
void bind_math(py::module &);
void bind_math_ValueAndWeight(py::module &);
void bind_math_Array1OfValueAndWeight(py::module &);
void bind_math_BissecNewton(py::module &);
void bind_math_BracketedRoot(py::module &);
void bind_math_BracketMinimum(py::module &);
void bind_math_BrentMinimum(py::module &);
void bind_math_BullardGenerator(py::module &);
void bind_math_ComputeGaussPointsAndWeights(py::module &);
void bind_math_ComputeKronrodPointsAndWeights(py::module &);
void bind_math_Crout(py::module &);
void bind_math_EigenValuesSearcher(py::module &);
void bind_math_FRPR(py::module &);
void bind_math_FunctionAllRoots(py::module &);
void bind_math_FunctionRoot(py::module &);
void bind_math_FunctionRoots(py::module &);
void bind_math_FunctionSetRoot(py::module &);
void bind_math_Gauss(py::module &);
void bind_math_GaussLeastSquare(py::module &);
void bind_math_GaussMultipleIntegration(py::module &);
void bind_math_GaussSetIntegration(py::module &);
void bind_math_GaussSingleIntegration(py::module &);
void bind_math_GlobOptMin(py::module &);
void bind_math_Householder(py::module &);
void bind_math_Jacobi(py::module &);
void bind_math_KronrodSingleIntegration(py::module &);
void bind_math_NewtonFunctionRoot(py::module &);
void bind_math_NewtonFunctionSetRoot(py::module &);
void bind_math_NotSquare(py::module &);
void bind_math_Powell(py::module &);
void bind_math_PSO(py::module &);
void bind_PSO_Particle(py::module &);
void bind_math_PSOParticlesPool(py::module &);
void bind_math_SingularMatrix(py::module &);
void bind_math_SVD(py::module &);
void bind_math_TrigonometricEquationFunction(py::module &);
void bind_math_Uzawa(py::module &);

PYBIND11_MODULE(math, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");

bind_math_Status(mod);
bind_math_Function(mod);
bind_math_FunctionWithDerivative(mod);
bind_math_Vector(mod);
bind_math_DoubleTab(mod);
bind_math_Matrix(mod);
bind_math_BFGS(mod);
bind_math_IntegerVector(mod);
bind_math_MultipleVarFunction(mod);
bind_math_MultipleVarFunctionWithGradient(mod);
bind_math_FunctionSet(mod);
bind_math_FunctionSetWithDerivatives(mod);
bind_math_MultipleVarFunctionWithHessian(mod);
bind_math_NewtonMinimum(mod);
bind_math_FunctionSample(mod);
bind_math_DirectPolynomialRoots(mod);
bind_math_TrigonometricFunctionRoots(mod);
bind_math(mod);
bind_math_ValueAndWeight(mod);
bind_math_Array1OfValueAndWeight(mod);
bind_math_BissecNewton(mod);
bind_math_BracketedRoot(mod);
bind_math_BracketMinimum(mod);
bind_math_BrentMinimum(mod);
bind_math_BullardGenerator(mod);
bind_math_ComputeGaussPointsAndWeights(mod);
bind_math_ComputeKronrodPointsAndWeights(mod);
bind_math_Crout(mod);
bind_math_EigenValuesSearcher(mod);
bind_math_FRPR(mod);
bind_math_FunctionAllRoots(mod);
bind_math_FunctionRoot(mod);
bind_math_FunctionRoots(mod);
bind_math_FunctionSetRoot(mod);
bind_math_Gauss(mod);
bind_math_GaussLeastSquare(mod);
bind_math_GaussMultipleIntegration(mod);
bind_math_GaussSetIntegration(mod);
bind_math_GaussSingleIntegration(mod);
bind_math_GlobOptMin(mod);
bind_math_Householder(mod);
bind_math_Jacobi(mod);
bind_math_KronrodSingleIntegration(mod);
bind_math_NewtonFunctionRoot(mod);
bind_math_NewtonFunctionSetRoot(mod);
bind_math_NotSquare(mod);
bind_math_Powell(mod);
bind_math_PSO(mod);
bind_PSO_Particle(mod);
bind_math_PSOParticlesPool(mod);
bind_math_SingularMatrix(mod);
bind_math_SVD(mod);
bind_math_TrigonometricEquationFunction(mod);
bind_math_Uzawa(mod);

}
