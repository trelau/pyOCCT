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
#include <math_BrentMinimum.hxx>

void bind_math_BrentMinimum(py::module &mod){

py::class_<math_BrentMinimum, std::unique_ptr<math_BrentMinimum, Deleter<math_BrentMinimum>>> cls_math_BrentMinimum(mod, "math_BrentMinimum", "This class implements the Brent's method to find the minimum of a function of a single variable. No knowledge of the derivative is required.");

// Constructors
cls_math_BrentMinimum.def(py::init<const Standard_Real>(), py::arg("TolX"));
cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("TolX"), py::arg("NbIterations"));
cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("TolX"), py::arg("NbIterations"), py::arg("ZEPS"));
cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("TolX"), py::arg("Fbx"));
cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("TolX"), py::arg("Fbx"), py::arg("NbIterations"));
cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("TolX"), py::arg("Fbx"), py::arg("NbIterations"), py::arg("ZEPS"));

// Fields

// Methods
// cls_math_BrentMinimum.def_static("operator new_", (void * (*)(size_t)) &math_BrentMinimum::operator new, "None", py::arg("theSize"));
// cls_math_BrentMinimum.def_static("operator delete_", (void (*)(void *)) &math_BrentMinimum::operator delete, "None", py::arg("theAddress"));
// cls_math_BrentMinimum.def_static("operator new[]_", (void * (*)(size_t)) &math_BrentMinimum::operator new[], "None", py::arg("theSize"));
// cls_math_BrentMinimum.def_static("operator delete[]_", (void (*)(void *)) &math_BrentMinimum::operator delete[], "None", py::arg("theAddress"));
// cls_math_BrentMinimum.def_static("operator new_", (void * (*)(size_t, void *)) &math_BrentMinimum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_BrentMinimum.def_static("operator delete_", (void (*)(void *, void *)) &math_BrentMinimum::operator delete, "None", py::arg(""), py::arg(""));
cls_math_BrentMinimum.def("Perform", (void (math_BrentMinimum::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Real)) &math_BrentMinimum::Perform, "Brent minimization is performed on function F from a given bracketing triplet of abscissas Ax, Bx, Cx (such that Bx is between Ax and Cx, F(Bx) is less than both F(Bx) and F(Cx)) The solution is found when: abs(Xi - Xi-1) <= TolX * abs(Xi) + ZEPS;", py::arg("F"), py::arg("Ax"), py::arg("Bx"), py::arg("Cx"));
cls_math_BrentMinimum.def("IsSolutionReached", (Standard_Boolean (math_BrentMinimum::*)(math_Function &)) &math_BrentMinimum::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("theFunction"));
cls_math_BrentMinimum.def("IsDone", (Standard_Boolean (math_BrentMinimum::*)() const) &math_BrentMinimum::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_BrentMinimum.def("Location", (Standard_Real (math_BrentMinimum::*)() const) &math_BrentMinimum::Location, "returns the location value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BrentMinimum.def("Minimum", (Standard_Real (math_BrentMinimum::*)() const) &math_BrentMinimum::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BrentMinimum.def("NbIterations", (Standard_Integer (math_BrentMinimum::*)() const) &math_BrentMinimum::NbIterations, "returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BrentMinimum.def("Dump", (void (math_BrentMinimum::*)(Standard_OStream &) const) &math_BrentMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}