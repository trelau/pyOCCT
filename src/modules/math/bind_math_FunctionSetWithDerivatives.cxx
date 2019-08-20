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
#include <math_FunctionSet.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_FunctionSetWithDerivatives.hxx>

void bind_math_FunctionSetWithDerivatives(py::module &mod){

py::class_<math_FunctionSetWithDerivatives, std::unique_ptr<math_FunctionSetWithDerivatives>, math_FunctionSet> cls_math_FunctionSetWithDerivatives(mod, "math_FunctionSetWithDerivatives", "This abstract class describes the virtual functions associated with a set of N Functions each of M independant variables.");

// Fields

// Methods
// cls_math_FunctionSetWithDerivatives.def_static("operator new_", (void * (*)(size_t)) &math_FunctionSetWithDerivatives::operator new, "None", py::arg("theSize"));
// cls_math_FunctionSetWithDerivatives.def_static("operator delete_", (void (*)(void *)) &math_FunctionSetWithDerivatives::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionSetWithDerivatives.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionSetWithDerivatives::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionSetWithDerivatives.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionSetWithDerivatives::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionSetWithDerivatives.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionSetWithDerivatives::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionSetWithDerivatives.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionSetWithDerivatives::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionSetWithDerivatives.def("NbVariables", (Standard_Integer (math_FunctionSetWithDerivatives::*)() const) &math_FunctionSetWithDerivatives::NbVariables, "Returns the number of variables of the function.");
cls_math_FunctionSetWithDerivatives.def("NbEquations", (Standard_Integer (math_FunctionSetWithDerivatives::*)() const) &math_FunctionSetWithDerivatives::NbEquations, "Returns the number of equations of the function.");
cls_math_FunctionSetWithDerivatives.def("Value", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Vector &)) &math_FunctionSetWithDerivatives::Value, "Computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_math_FunctionSetWithDerivatives.def("Derivatives", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Matrix &)) &math_FunctionSetWithDerivatives::Derivatives, "Returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_math_FunctionSetWithDerivatives.def("Values", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Vector &, math_Matrix &)) &math_FunctionSetWithDerivatives::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}