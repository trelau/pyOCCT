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
#include <math_FunctionRoot.hxx>

void bind_math_FunctionRoot(py::module &mod){

py::class_<math_FunctionRoot, std::unique_ptr<math_FunctionRoot, Deleter<math_FunctionRoot>>> cls_math_FunctionRoot(mod, "math_FunctionRoot", "This class implements the computation of a root of a function of a single variable which is near an initial guess using a minimization algorithm.Knowledge of the derivative is required. The algorithm used is the same as in");

// Constructors
cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"));
cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("A"), py::arg("B"));
cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("A"), py::arg("B"), py::arg("NbIterations"));

// Fields

// Methods
// cls_math_FunctionRoot.def_static("operator new_", (void * (*)(size_t)) &math_FunctionRoot::operator new, "None", py::arg("theSize"));
// cls_math_FunctionRoot.def_static("operator delete_", (void (*)(void *)) &math_FunctionRoot::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionRoot.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionRoot::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionRoot.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionRoot::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionRoot.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionRoot.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionRoot::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionRoot.def("IsDone", (Standard_Boolean (math_FunctionRoot::*)() const) &math_FunctionRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_FunctionRoot.def("Root", (Standard_Real (math_FunctionRoot::*)() const) &math_FunctionRoot::Root, "returns the value of the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionRoot.def("Derivative", (Standard_Real (math_FunctionRoot::*)() const) &math_FunctionRoot::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionRoot.def("Value", (Standard_Real (math_FunctionRoot::*)() const) &math_FunctionRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionRoot.def("NbIterations", (Standard_Integer (math_FunctionRoot::*)() const) &math_FunctionRoot::NbIterations, "returns the number of iterations really done on the computation of the Root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionRoot.def("Dump", (void (math_FunctionRoot::*)(Standard_OStream &) const) &math_FunctionRoot::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}