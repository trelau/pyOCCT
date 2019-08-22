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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <CPnts_RealFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <CPnts_MyGaussFunction.hxx>
#include <CPnts_MyRootFunction.hxx>

void bind_CPnts_MyRootFunction(py::module &mod){

py::class_<CPnts_MyRootFunction, math_FunctionWithDerivative> cls_CPnts_MyRootFunction(mod, "CPnts_MyRootFunction", "Implements a function for the Newton algorithm to find the solution of Integral(F) = L (compute Length and Derivative of the curve for Newton)");

// Constructors
cls_CPnts_MyRootFunction.def(py::init<>());

// Fields

// Methods
// cls_CPnts_MyRootFunction.def_static("operator new_", (void * (*)(size_t)) &CPnts_MyRootFunction::operator new, "None", py::arg("theSize"));
// cls_CPnts_MyRootFunction.def_static("operator delete_", (void (*)(void *)) &CPnts_MyRootFunction::operator delete, "None", py::arg("theAddress"));
// cls_CPnts_MyRootFunction.def_static("operator new[]_", (void * (*)(size_t)) &CPnts_MyRootFunction::operator new[], "None", py::arg("theSize"));
// cls_CPnts_MyRootFunction.def_static("operator delete[]_", (void (*)(void *)) &CPnts_MyRootFunction::operator delete[], "None", py::arg("theAddress"));
// cls_CPnts_MyRootFunction.def_static("operator new_", (void * (*)(size_t, void *)) &CPnts_MyRootFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CPnts_MyRootFunction.def_static("operator delete_", (void (*)(void *, void *)) &CPnts_MyRootFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const CPnts_RealFunction &, const Standard_Address, const Standard_Integer)) &CPnts_MyRootFunction::Init, "F is a pointer on a function D is a client data Order is the order of integration to use", py::arg("F"), py::arg("D"), py::arg("Order"));
cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const Standard_Real, const Standard_Real)) &CPnts_MyRootFunction::Init, "We want to solve Integral(X0,X,F(X,D)) = L", py::arg("X0"), py::arg("L"));
cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_MyRootFunction::Init, "We want to solve Integral(X0,X,F(X,D)) = L with given tolerance", py::arg("X0"), py::arg("L"), py::arg("Tol"));
cls_CPnts_MyRootFunction.def("Value", [](CPnts_MyRootFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "This is Integral(X0,X,F(X,D)) - L", py::arg("X"), py::arg("F"));
cls_CPnts_MyRootFunction.def("Derivative", [](CPnts_MyRootFunction &self, const Standard_Real X, Standard_Real & Df){ Standard_Boolean rv = self.Derivative(X, Df); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Df); }, "This is F(X,D)", py::arg("X"), py::arg("Df"));
cls_CPnts_MyRootFunction.def("Values", [](CPnts_MyRootFunction &self, const Standard_Real X, Standard_Real & F, Standard_Real & Df){ Standard_Boolean rv = self.Values(X, F, Df); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, Df); }, "None", py::arg("X"), py::arg("F"), py::arg("Df"));

// Enums

}