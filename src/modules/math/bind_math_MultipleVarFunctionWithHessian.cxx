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
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>

void bind_math_MultipleVarFunctionWithHessian(py::module &mod){

py::class_<math_MultipleVarFunctionWithHessian, std::unique_ptr<math_MultipleVarFunctionWithHessian, Deleter<math_MultipleVarFunctionWithHessian>>, math_MultipleVarFunctionWithGradient> cls_math_MultipleVarFunctionWithHessian(mod, "math_MultipleVarFunctionWithHessian", "None");

// Fields

// Methods
// cls_math_MultipleVarFunctionWithHessian.def_static("operator new_", (void * (*)(size_t)) &math_MultipleVarFunctionWithHessian::operator new, "None", py::arg("theSize"));
// cls_math_MultipleVarFunctionWithHessian.def_static("operator delete_", (void (*)(void *)) &math_MultipleVarFunctionWithHessian::operator delete, "None", py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithHessian.def_static("operator new[]_", (void * (*)(size_t)) &math_MultipleVarFunctionWithHessian::operator new[], "None", py::arg("theSize"));
// cls_math_MultipleVarFunctionWithHessian.def_static("operator delete[]_", (void (*)(void *)) &math_MultipleVarFunctionWithHessian::operator delete[], "None", py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithHessian.def_static("operator new_", (void * (*)(size_t, void *)) &math_MultipleVarFunctionWithHessian::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_MultipleVarFunctionWithHessian.def_static("operator delete_", (void (*)(void *, void *)) &math_MultipleVarFunctionWithHessian::operator delete, "None", py::arg(""), py::arg(""));
cls_math_MultipleVarFunctionWithHessian.def("NbVariables", (Standard_Integer (math_MultipleVarFunctionWithHessian::*)() const) &math_MultipleVarFunctionWithHessian::NbVariables, "returns the number of variables of the function.");
cls_math_MultipleVarFunctionWithHessian.def("Value", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the values of the Functions <F> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_math_MultipleVarFunctionWithHessian.def("Gradient", (Standard_Boolean (math_MultipleVarFunctionWithHessian::*)(const math_Vector &, math_Vector &)) &math_MultipleVarFunctionWithHessian::Gradient, "computes the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
cls_math_MultipleVarFunctionWithHessian.def("Values", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F> and the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_math_MultipleVarFunctionWithHessian.def("Values", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F, math_Vector & G, math_Matrix & H){ Standard_Boolean rv = self.Values(X, F, G, H); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>, the gradient <G> and the hessian <H> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"), py::arg("H"));

// Enums

}