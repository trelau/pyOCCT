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
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <math_FunctionRoots.hxx>

void bind_math_FunctionRoots(py::module &mod){

py::class_<math_FunctionRoots, std::unique_ptr<math_FunctionRoots, Deleter<math_FunctionRoots>>> cls_math_FunctionRoots(mod, "math_FunctionRoots", "This class implements an algorithm which finds all the real roots of a function with derivative within a given range. Knowledge of the derivative is required.");

// Constructors
cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"));
cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"));
cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"));
cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNull"));
cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNull"), py::arg("K"));

// Fields

// Methods
// cls_math_FunctionRoots.def_static("operator new_", (void * (*)(size_t)) &math_FunctionRoots::operator new, "None", py::arg("theSize"));
// cls_math_FunctionRoots.def_static("operator delete_", (void (*)(void *)) &math_FunctionRoots::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionRoots.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionRoots::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionRoots.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionRoots::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionRoots.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionRoots.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionRoots::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionRoots.def("IsDone", (Standard_Boolean (math_FunctionRoots::*)() const) &math_FunctionRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_FunctionRoots.def("IsAllNull", (Standard_Boolean (math_FunctionRoots::*)() const) &math_FunctionRoots::IsAllNull, "returns true if the function is considered as null between A and B. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
cls_math_FunctionRoots.def("NbSolutions", (Standard_Integer (math_FunctionRoots::*)() const) &math_FunctionRoots::NbSolutions, "Returns the number of solutions found. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
cls_math_FunctionRoots.def("Value", (Standard_Real (math_FunctionRoots::*)(const Standard_Integer) const) &math_FunctionRoots::Value, "Returns the Nth value of the root of function F. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("Nieme"));
cls_math_FunctionRoots.def("StateNumber", (Standard_Integer (math_FunctionRoots::*)(const Standard_Integer) const) &math_FunctionRoots::StateNumber, "returns the StateNumber of the Nieme root. Exception RangeError is raised if Nieme is < 1 or Nieme > NbSolutions.", py::arg("Nieme"));
cls_math_FunctionRoots.def("Dump", (void (math_FunctionRoots::*)(Standard_OStream &) const) &math_FunctionRoots::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

// Enums

}