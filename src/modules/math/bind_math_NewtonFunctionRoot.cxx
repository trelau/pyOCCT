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
#include <math_FunctionWithDerivative.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_NewtonFunctionRoot.hxx>

void bind_math_NewtonFunctionRoot(py::module &mod){

py::class_<math_NewtonFunctionRoot, std::unique_ptr<math_NewtonFunctionRoot, Deleter<math_NewtonFunctionRoot>>> cls_math_NewtonFunctionRoot(mod, "math_NewtonFunctionRoot", "This class implements the calculation of a root of a function of a single variable starting from an initial near guess using the Newton algorithm. Knowledge of the derivative is required.");

// Constructors
cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"));
cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("NbIterations"));
cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("A"), py::arg("B"));
cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("A"), py::arg("B"), py::arg("NbIterations"));
cls_math_NewtonFunctionRoot.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EpsX"), py::arg("EpsF"));
cls_math_NewtonFunctionRoot.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("EpsX"), py::arg("EpsF"), py::arg("NbIterations"));

// Fields

// Methods
// cls_math_NewtonFunctionRoot.def_static("operator new_", (void * (*)(size_t)) &math_NewtonFunctionRoot::operator new, "None", py::arg("theSize"));
// cls_math_NewtonFunctionRoot.def_static("operator delete_", (void (*)(void *)) &math_NewtonFunctionRoot::operator delete, "None", py::arg("theAddress"));
// cls_math_NewtonFunctionRoot.def_static("operator new[]_", (void * (*)(size_t)) &math_NewtonFunctionRoot::operator new[], "None", py::arg("theSize"));
// cls_math_NewtonFunctionRoot.def_static("operator delete[]_", (void (*)(void *)) &math_NewtonFunctionRoot::operator delete[], "None", py::arg("theAddress"));
// cls_math_NewtonFunctionRoot.def_static("operator new_", (void * (*)(size_t, void *)) &math_NewtonFunctionRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_NewtonFunctionRoot.def_static("operator delete_", (void (*)(void *, void *)) &math_NewtonFunctionRoot::operator delete, "None", py::arg(""), py::arg(""));
cls_math_NewtonFunctionRoot.def("Perform", (void (math_NewtonFunctionRoot::*)(math_FunctionWithDerivative &, const Standard_Real)) &math_NewtonFunctionRoot::Perform, "is used internally by the constructors.", py::arg("F"), py::arg("Guess"));
cls_math_NewtonFunctionRoot.def("IsDone", (Standard_Boolean (math_NewtonFunctionRoot::*)() const) &math_NewtonFunctionRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_NewtonFunctionRoot.def("Root", (Standard_Real (math_NewtonFunctionRoot::*)() const) &math_NewtonFunctionRoot::Root, "Returns the value of the root of function <F>. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionRoot.def("Derivative", (Standard_Real (math_NewtonFunctionRoot::*)() const) &math_NewtonFunctionRoot::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionRoot.def("Value", (Standard_Real (math_NewtonFunctionRoot::*)() const) &math_NewtonFunctionRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionRoot.def("NbIterations", (Standard_Integer (math_NewtonFunctionRoot::*)() const) &math_NewtonFunctionRoot::NbIterations, "Returns the number of iterations really done on the computation of the Root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionRoot.def("Dump", (void (math_NewtonFunctionRoot::*)(Standard_OStream &) const) &math_NewtonFunctionRoot::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}