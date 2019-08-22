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
#include <math_Function.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_FunctionWithDerivative.hxx>

void bind_math_FunctionWithDerivative(py::module &mod){

py::class_<math_FunctionWithDerivative, math_Function> cls_math_FunctionWithDerivative(mod, "math_FunctionWithDerivative", "This abstract class describes the virtual functions associated with a function of a single variable for which the first derivative is available.");

// Fields

// Methods
// cls_math_FunctionWithDerivative.def_static("operator new_", (void * (*)(size_t)) &math_FunctionWithDerivative::operator new, "None", py::arg("theSize"));
// cls_math_FunctionWithDerivative.def_static("operator delete_", (void (*)(void *)) &math_FunctionWithDerivative::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionWithDerivative.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionWithDerivative::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionWithDerivative.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionWithDerivative::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionWithDerivative.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionWithDerivative::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionWithDerivative.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionWithDerivative::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionWithDerivative.def("Value", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_math_FunctionWithDerivative.def("Derivative", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_math_FunctionWithDerivative.def("Values", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}