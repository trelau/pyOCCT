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
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <CSLib_NormalPolyDef.hxx>

void bind_CSLib_NormalPolyDef(py::module &mod){

py::class_<CSLib_NormalPolyDef, math_FunctionWithDerivative> cls_CSLib_NormalPolyDef(mod, "CSLib_NormalPolyDef", "None");

// Constructors
cls_CSLib_NormalPolyDef.def(py::init<const Standard_Integer, const TColStd_Array1OfReal &>(), py::arg("k0"), py::arg("li"));

// Fields

// Methods
// cls_CSLib_NormalPolyDef.def_static("operator new_", (void * (*)(size_t)) &CSLib_NormalPolyDef::operator new, "None", py::arg("theSize"));
// cls_CSLib_NormalPolyDef.def_static("operator delete_", (void (*)(void *)) &CSLib_NormalPolyDef::operator delete, "None", py::arg("theAddress"));
// cls_CSLib_NormalPolyDef.def_static("operator new[]_", (void * (*)(size_t)) &CSLib_NormalPolyDef::operator new[], "None", py::arg("theSize"));
// cls_CSLib_NormalPolyDef.def_static("operator delete[]_", (void (*)(void *)) &CSLib_NormalPolyDef::operator delete[], "None", py::arg("theAddress"));
// cls_CSLib_NormalPolyDef.def_static("operator new_", (void * (*)(size_t, void *)) &CSLib_NormalPolyDef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CSLib_NormalPolyDef.def_static("operator delete_", (void (*)(void *, void *)) &CSLib_NormalPolyDef::operator delete, "None", py::arg(""), py::arg(""));
cls_CSLib_NormalPolyDef.def("Value", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_CSLib_NormalPolyDef.def("Derivative", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_CSLib_NormalPolyDef.def("Values", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}