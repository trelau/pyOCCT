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
#include <gp_Circ2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Elips2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_Ax2d.hxx>
#include <IntAna2d_Conic.hxx>

void bind_IntAna2d_Conic(py::module &mod){

py::class_<IntAna2d_Conic, std::unique_ptr<IntAna2d_Conic, Deleter<IntAna2d_Conic>>> cls_IntAna2d_Conic(mod, "IntAna2d_Conic", "Definition of a conic by its implicit quadaratic equation: A.X**2 + B.Y**2 + 2.C.X*Y + 2.D.X + 2.E.Y + F = 0.");

// Constructors
cls_IntAna2d_Conic.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_IntAna2d_Conic.def(py::init<const gp_Lin2d &>(), py::arg("C"));
cls_IntAna2d_Conic.def(py::init<const gp_Parab2d &>(), py::arg("C"));
cls_IntAna2d_Conic.def(py::init<const gp_Hypr2d &>(), py::arg("C"));
cls_IntAna2d_Conic.def(py::init<const gp_Elips2d &>(), py::arg("C"));

// Fields

// Methods
// cls_IntAna2d_Conic.def_static("operator new_", (void * (*)(size_t)) &IntAna2d_Conic::operator new, "None", py::arg("theSize"));
// cls_IntAna2d_Conic.def_static("operator delete_", (void (*)(void *)) &IntAna2d_Conic::operator delete, "None", py::arg("theAddress"));
// cls_IntAna2d_Conic.def_static("operator new[]_", (void * (*)(size_t)) &IntAna2d_Conic::operator new[], "None", py::arg("theSize"));
// cls_IntAna2d_Conic.def_static("operator delete[]_", (void (*)(void *)) &IntAna2d_Conic::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna2d_Conic.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna2d_Conic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna2d_Conic.def_static("operator delete_", (void (*)(void *, void *)) &IntAna2d_Conic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna2d_Conic.def("Value", (Standard_Real (IntAna2d_Conic::*)(const Standard_Real, const Standard_Real) const) &IntAna2d_Conic::Value, "value of the function F at the point X,Y.", py::arg("X"), py::arg("Y"));
cls_IntAna2d_Conic.def("Grad", (gp_XY (IntAna2d_Conic::*)(const Standard_Real, const Standard_Real) const) &IntAna2d_Conic::Grad, "returns the value of the gradient of F at the point X,Y.", py::arg("X"), py::arg("Y"));
cls_IntAna2d_Conic.def("ValAndGrad", [](IntAna2d_Conic &self, const Standard_Real X, const Standard_Real Y, Standard_Real & Val, gp_XY & Grd){ self.ValAndGrad(X, Y, Val, Grd); return Val; }, "Returns the value of the function and its gradient at the point X,Y.", py::arg("X"), py::arg("Y"), py::arg("Val"), py::arg("Grd"));
cls_IntAna2d_Conic.def("Coefficients", [](IntAna2d_Conic &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "returns the coefficients of the polynomial equation wich defines the conic: A.X**2 + B.Y**2 + 2.C.X*Y + 2.D.X + 2.E.Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_IntAna2d_Conic.def("NewCoefficients", [](IntAna2d_Conic &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F, const gp_Ax2d & Axis){ self.NewCoefficients(A, B, C, D, E, F, Axis); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Returns the coefficients of the polynomial equation ( written in the natural coordinates system ) A x x + B y y + 2 C x y + 2 D x + 2 E y + F in the local coordinates system defined by Axis", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"), py::arg("Axis"));

// Enums

}