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
#include <math_FunctionWithDerivative.hxx>
#include <Standard_TypeDef.hxx>
#include <math_TrigonometricEquationFunction.hxx>

void bind_math_TrigonometricEquationFunction(py::module &mod){

py::class_<math_TrigonometricEquationFunction, math_FunctionWithDerivative> cls_math_TrigonometricEquationFunction(mod, "math_TrigonometricEquationFunction", "This is function, which corresponds trigonometric equation a*Cos(x)*Cos(x) + 2*b*Cos(x)*Sin(x) + c*Cos(x) + d*Sin(x) + e = 0 See class math_TrigonometricFunctionRoots");

// Constructors
cls_math_TrigonometricEquationFunction.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"));

// Fields

// Methods
cls_math_TrigonometricEquationFunction.def("Value", [](math_TrigonometricEquationFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_math_TrigonometricEquationFunction.def("Derivative", [](math_TrigonometricEquationFunction &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
cls_math_TrigonometricEquationFunction.def("Values", [](math_TrigonometricEquationFunction &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "None", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}