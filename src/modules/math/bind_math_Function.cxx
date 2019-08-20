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

void bind_math_Function(py::module &mod){

py::class_<math_Function, std::unique_ptr<math_Function>> cls_math_Function(mod, "math_Function", "This abstract class describes the virtual functions associated with a Function of a single variable.");

// Fields

// Methods
// cls_math_Function.def_static("operator new_", (void * (*)(size_t)) &math_Function::operator new, "None", py::arg("theSize"));
// cls_math_Function.def_static("operator delete_", (void (*)(void *)) &math_Function::operator delete, "None", py::arg("theAddress"));
// cls_math_Function.def_static("operator new[]_", (void * (*)(size_t)) &math_Function::operator new[], "None", py::arg("theSize"));
// cls_math_Function.def_static("operator delete[]_", (void (*)(void *)) &math_Function::operator delete[], "None", py::arg("theAddress"));
// cls_math_Function.def_static("operator new_", (void * (*)(size_t, void *)) &math_Function::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Function.def_static("operator delete_", (void (*)(void *, void *)) &math_Function::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Function.def("Value", [](math_Function &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function <F> for a given value of variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_math_Function.def("GetStateNumber", (Standard_Integer (math_Function::*)()) &math_Function::GetStateNumber, "returns the state of the function corresponding to the latest call of any methods associated with the function. This function is called by each of the algorithms described later which defined the function Integer Algorithm::StateNumber(). The algorithm has the responsibility to call this function when it has found a solution (i.e. a root or a minimum) and has to maintain the association between the solution found and this StateNumber. Byu default, this method returns 0 (which means for the algorithm: no state has been saved). It is the responsibility of the programmer to decide if he needs to save the current state of the function and to return an Integer that allows retrieval of the state.");

// Enums

}