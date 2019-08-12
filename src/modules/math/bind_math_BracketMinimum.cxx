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
#include <math_Function.hxx>
#include <Standard_OStream.hxx>
#include <math_BracketMinimum.hxx>

void bind_math_BracketMinimum(py::module &mod){

py::class_<math_BracketMinimum, std::unique_ptr<math_BracketMinimum, Deleter<math_BracketMinimum>>> cls_math_BracketMinimum(mod, "math_BracketMinimum", "Given two distinct initial points, BracketMinimum implements the computation of three points (a, b, c) which bracket the minimum of the function and verify A less than B, B less than C and F(B) less than F(A), F(B) less than F(C).");

// Constructors
cls_math_BracketMinimum.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"));
cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"));
cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("FA"));
cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("FA"), py::arg("FB"));

// Fields

// Methods
// cls_math_BracketMinimum.def_static("operator new_", (void * (*)(size_t)) &math_BracketMinimum::operator new, "None", py::arg("theSize"));
// cls_math_BracketMinimum.def_static("operator delete_", (void (*)(void *)) &math_BracketMinimum::operator delete, "None", py::arg("theAddress"));
// cls_math_BracketMinimum.def_static("operator new[]_", (void * (*)(size_t)) &math_BracketMinimum::operator new[], "None", py::arg("theSize"));
// cls_math_BracketMinimum.def_static("operator delete[]_", (void (*)(void *)) &math_BracketMinimum::operator delete[], "None", py::arg("theAddress"));
// cls_math_BracketMinimum.def_static("operator new_", (void * (*)(size_t, void *)) &math_BracketMinimum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_BracketMinimum.def_static("operator delete_", (void (*)(void *, void *)) &math_BracketMinimum::operator delete, "None", py::arg(""), py::arg(""));
cls_math_BracketMinimum.def("SetLimits", (void (math_BracketMinimum::*)(const Standard_Real, const Standard_Real)) &math_BracketMinimum::SetLimits, "Set limits of the parameter. By default no limits are applied to the parameter change. If no minimum is found in limits then IsDone() will return false. The user is in charge of providing A and B to be in limits.", py::arg("theLeft"), py::arg("theRight"));
cls_math_BracketMinimum.def("SetFA", (void (math_BracketMinimum::*)(const Standard_Real)) &math_BracketMinimum::SetFA, "Set function value at A", py::arg("theValue"));
cls_math_BracketMinimum.def("SetFB", (void (math_BracketMinimum::*)(const Standard_Real)) &math_BracketMinimum::SetFB, "Set function value at B", py::arg("theValue"));
cls_math_BracketMinimum.def("Perform", (void (math_BracketMinimum::*)(math_Function &)) &math_BracketMinimum::Perform, "The method performing the job. It is called automatically by constructors with the function.", py::arg("F"));
cls_math_BracketMinimum.def("IsDone", (Standard_Boolean (math_BracketMinimum::*)() const) &math_BracketMinimum::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_BracketMinimum.def("Values", [](math_BracketMinimum &self, Standard_Real & A, Standard_Real & B, Standard_Real & C){ self.Values(A, B, C); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C); }, "Returns the bracketed triplet of abscissae. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("A"), py::arg("B"), py::arg("C"));
cls_math_BracketMinimum.def("FunctionValues", [](math_BracketMinimum &self, Standard_Real & FA, Standard_Real & FB, Standard_Real & FC){ self.FunctionValues(FA, FB, FC); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(FA, FB, FC); }, "returns the bracketed triplet function values. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("FA"), py::arg("FB"), py::arg("FC"));
cls_math_BracketMinimum.def("Dump", (void (math_BracketMinimum::*)(Standard_OStream &) const) &math_BracketMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}