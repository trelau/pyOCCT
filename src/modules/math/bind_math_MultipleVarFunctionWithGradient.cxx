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
#include <math_MultipleVarFunction.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>

void bind_math_MultipleVarFunctionWithGradient(py::module &mod){

py::class_<math_MultipleVarFunctionWithGradient, math_MultipleVarFunction> cls_math_MultipleVarFunctionWithGradient(mod, "math_MultipleVarFunctionWithGradient", "The abstract class MultipleVarFunctionWithGradient describes the virtual functions associated with a multiple variable function.");

// Fields

// Methods
// cls_math_MultipleVarFunctionWithGradient.def_static("operator new_", (void * (*)(size_t)) &math_MultipleVarFunctionWithGradient::operator new, "None", py::arg("theSize"));
// cls_math_MultipleVarFunctionWithGradient.def_static("operator delete_", (void (*)(void *)) &math_MultipleVarFunctionWithGradient::operator delete, "None", py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithGradient.def_static("operator new[]_", (void * (*)(size_t)) &math_MultipleVarFunctionWithGradient::operator new[], "None", py::arg("theSize"));
// cls_math_MultipleVarFunctionWithGradient.def_static("operator delete[]_", (void (*)(void *)) &math_MultipleVarFunctionWithGradient::operator delete[], "None", py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithGradient.def_static("operator new_", (void * (*)(size_t, void *)) &math_MultipleVarFunctionWithGradient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithGradient.def_static("operator delete_", (void (*)(void *, void *)) &math_MultipleVarFunctionWithGradient::operator delete, "None", py::arg(""), py::arg(""));
cls_math_MultipleVarFunctionWithGradient.def("NbVariables", (Standard_Integer (math_MultipleVarFunctionWithGradient::*)() const) &math_MultipleVarFunctionWithGradient::NbVariables, "Returns the number of variables of the function.");
cls_math_MultipleVarFunctionWithGradient.def("Value", [](math_MultipleVarFunctionWithGradient &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions <F> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_math_MultipleVarFunctionWithGradient.def("Gradient", (Standard_Boolean (math_MultipleVarFunctionWithGradient::*)(const math_Vector &, math_Vector &)) &math_MultipleVarFunctionWithGradient::Gradient, "Computes the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
cls_math_MultipleVarFunctionWithGradient.def("Values", [](math_MultipleVarFunctionWithGradient &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F> and the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"));

// Enums

}