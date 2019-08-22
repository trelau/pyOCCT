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
#include <Bisector_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Bisector_FunctionInter.hxx>

void bind_Bisector_FunctionInter(py::module &mod){

py::class_<Bisector_FunctionInter, math_FunctionWithDerivative> cls_Bisector_FunctionInter(mod, "Bisector_FunctionInter", "2 2 F(u) = (PC(u) - PBis1(u)) + (PC(u) - PBis2(u))");

// Constructors
cls_Bisector_FunctionInter.def(py::init<>());
cls_Bisector_FunctionInter.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Bisector_Curve> &, const opencascade::handle<Bisector_Curve> &>(), py::arg("C"), py::arg("Bis1"), py::arg("Bis2"));

// Fields

// Methods
// cls_Bisector_FunctionInter.def_static("operator new_", (void * (*)(size_t)) &Bisector_FunctionInter::operator new, "None", py::arg("theSize"));
// cls_Bisector_FunctionInter.def_static("operator delete_", (void (*)(void *)) &Bisector_FunctionInter::operator delete, "None", py::arg("theAddress"));
// cls_Bisector_FunctionInter.def_static("operator new[]_", (void * (*)(size_t)) &Bisector_FunctionInter::operator new[], "None", py::arg("theSize"));
// cls_Bisector_FunctionInter.def_static("operator delete[]_", (void (*)(void *)) &Bisector_FunctionInter::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector_FunctionInter.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector_FunctionInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector_FunctionInter.def_static("operator delete_", (void (*)(void *, void *)) &Bisector_FunctionInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector_FunctionInter.def("Perform", (void (Bisector_FunctionInter::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Bisector_Curve> &, const opencascade::handle<Bisector_Curve> &)) &Bisector_FunctionInter::Perform, "None", py::arg("C"), py::arg("Bis1"), py::arg("Bis2"));
cls_Bisector_FunctionInter.def("Value", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
cls_Bisector_FunctionInter.def("Derivative", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
cls_Bisector_FunctionInter.def("Values", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}