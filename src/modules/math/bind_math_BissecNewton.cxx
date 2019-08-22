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
#include <math_FunctionWithDerivative.hxx>
#include <Standard_OStream.hxx>
#include <math_Status.hxx>
#include <math_BissecNewton.hxx>

void bind_math_BissecNewton(py::module &mod){

py::class_<math_BissecNewton> cls_math_BissecNewton(mod, "math_BissecNewton", "This class implements a combination of Newton-Raphson and bissection methods to find the root of the function between two bounds. Knowledge of the derivative is required.");

// Constructors
cls_math_BissecNewton.def(py::init<const Standard_Real>(), py::arg("theXTolerance"));

// Fields

// Methods
// cls_math_BissecNewton.def_static("operator new_", (void * (*)(size_t)) &math_BissecNewton::operator new, "None", py::arg("theSize"));
// cls_math_BissecNewton.def_static("operator delete_", (void (*)(void *)) &math_BissecNewton::operator delete, "None", py::arg("theAddress"));
// cls_math_BissecNewton.def_static("operator new[]_", (void * (*)(size_t)) &math_BissecNewton::operator new[], "None", py::arg("theSize"));
// cls_math_BissecNewton.def_static("operator delete[]_", (void (*)(void *)) &math_BissecNewton::operator delete[], "None", py::arg("theAddress"));
// cls_math_BissecNewton.def_static("operator new_", (void * (*)(size_t, void *)) &math_BissecNewton::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_BissecNewton.def_static("operator delete_", (void (*)(void *, void *)) &math_BissecNewton::operator delete, "None", py::arg(""), py::arg(""));
cls_math_BissecNewton.def("Perform", [](math_BissecNewton &self, math_FunctionWithDerivative & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_math_BissecNewton.def("Perform", (void (math_BissecNewton::*)(math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer)) &math_BissecNewton::Perform, "A combination of Newton-Raphson and bissection methods is done to find the root of the function F between the bounds Bound1 and Bound2 on the function F. The tolerance required on the root is given by TolX. The solution is found when: abs(Xi - Xi-1) <= TolX and F(Xi) * F(Xi-1) <= 0 The maximum number of iterations allowed is given by NbIterations.", py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("NbIterations"));
cls_math_BissecNewton.def("IsSolutionReached", (Standard_Boolean (math_BissecNewton::*)(math_FunctionWithDerivative &)) &math_BissecNewton::IsSolutionReached, "This method is called at the end of each iteration to check if the solution has been found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("theFunction"));
cls_math_BissecNewton.def("IsDone", (Standard_Boolean (math_BissecNewton::*)() const) &math_BissecNewton::IsDone, "Tests is the root has been successfully found.");
cls_math_BissecNewton.def("Root", (Standard_Real (math_BissecNewton::*)() const) &math_BissecNewton::Root, "returns the value of the root. Exception NotDone is raised if the minimum was not found.");
cls_math_BissecNewton.def("Derivative", (Standard_Real (math_BissecNewton::*)() const) &math_BissecNewton::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the minimum was not found.");
cls_math_BissecNewton.def("Value", (Standard_Real (math_BissecNewton::*)() const) &math_BissecNewton::Value, "returns the value of the function at the root. Exception NotDone is raised if the minimum was not found.");
cls_math_BissecNewton.def("Dump", (void (math_BissecNewton::*)(Standard_OStream &) const) &math_BissecNewton::Dump, "Prints on the stream o information on the current state of the object. Is used to redifine the operator <<.", py::arg("o"));

// Enums

}