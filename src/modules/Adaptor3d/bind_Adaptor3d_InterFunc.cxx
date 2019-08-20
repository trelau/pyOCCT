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
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_InterFunc.hxx>

void bind_Adaptor3d_InterFunc(py::module &mod){

py::class_<Adaptor3d_InterFunc, std::unique_ptr<Adaptor3d_InterFunc>, math_FunctionWithDerivative> cls_Adaptor3d_InterFunc(mod, "Adaptor3d_InterFunc", "Used to find the points U(t) = U0 or V(t) = V0 in order to determine the Cn discontinuities of an Adpator_CurveOnSurface relativly to the discontinuities of the surface. Used to find the roots of the functions");

// Constructors
cls_Adaptor3d_InterFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FixVal"), py::arg("Fix"));

// Fields

// Methods
// cls_Adaptor3d_InterFunc.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_InterFunc::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_InterFunc.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_InterFunc::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_InterFunc.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_InterFunc::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_InterFunc.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_InterFunc::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_InterFunc.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_InterFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_InterFunc.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_InterFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_InterFunc.def("Value", [](Adaptor3d_InterFunc &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Adaptor3d_InterFunc.def("Derivative", [](Adaptor3d_InterFunc &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_Adaptor3d_InterFunc.def("Values", [](Adaptor3d_InterFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}