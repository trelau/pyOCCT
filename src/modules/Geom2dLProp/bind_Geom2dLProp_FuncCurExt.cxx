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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dLProp_FuncCurExt.hxx>

void bind_Geom2dLProp_FuncCurExt(py::module &mod){

py::class_<Geom2dLProp_FuncCurExt, math_FunctionWithDerivative> cls_Geom2dLProp_FuncCurExt(mod, "Geom2dLProp_FuncCurExt", "Function used to find the extremas of curvature in 2d.");

// Constructors
cls_Geom2dLProp_FuncCurExt.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("C"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dLProp_FuncCurExt.def_static("operator new_", (void * (*)(size_t)) &Geom2dLProp_FuncCurExt::operator new, "None", py::arg("theSize"));
// cls_Geom2dLProp_FuncCurExt.def_static("operator delete_", (void (*)(void *)) &Geom2dLProp_FuncCurExt::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dLProp_FuncCurExt.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dLProp_FuncCurExt::operator new[], "None", py::arg("theSize"));
// cls_Geom2dLProp_FuncCurExt.def_static("operator delete[]_", (void (*)(void *)) &Geom2dLProp_FuncCurExt::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dLProp_FuncCurExt.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dLProp_FuncCurExt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dLProp_FuncCurExt.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dLProp_FuncCurExt::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dLProp_FuncCurExt.def("Value", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Returns the value for the variable <X>.", py::arg("X"), py::arg("F"));
cls_Geom2dLProp_FuncCurExt.def("Derivative", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Returns the derivative for the variable <X>.", py::arg("X"), py::arg("D"));
cls_Geom2dLProp_FuncCurExt.def("Values", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the value of the function and the derivative for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Geom2dLProp_FuncCurExt.def("IsMinKC", (Standard_Boolean (Geom2dLProp_FuncCurExt::*)(const Standard_Real) const) &Geom2dLProp_FuncCurExt::IsMinKC, "True if Param corresponds to a minus of the radius of curvature.", py::arg("Param"));

// Enums

}