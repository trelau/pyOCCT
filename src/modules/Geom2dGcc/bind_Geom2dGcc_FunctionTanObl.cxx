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
#include <Geom2dAdaptor_Curve.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dGcc_FunctionTanObl.hxx>

void bind_Geom2dGcc_FunctionTanObl(py::module &mod){

py::class_<Geom2dGcc_FunctionTanObl, math_FunctionWithDerivative> cls_Geom2dGcc_FunctionTanObl(mod, "Geom2dGcc_FunctionTanObl", "This class describe a function of a single variable.");

// Constructors
cls_Geom2dGcc_FunctionTanObl.def(py::init<const Geom2dAdaptor_Curve &, const gp_Dir2d &>(), py::arg("Curve"), py::arg("Dir"));

// Fields

// Methods
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanObl::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanObl::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanObl::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanObl::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanObl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanObl::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanObl.def("Value", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanObl.def("Derivative", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & Deriv){ Standard_Boolean rv = self.Derivative(X, Deriv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Deriv); }, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanObl.def("Values", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & F, Standard_Real & Deriv){ Standard_Boolean rv = self.Values(X, F, Deriv); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, Deriv); }, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// Enums

}