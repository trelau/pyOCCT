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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <gp_Circ2d.hxx>
#include <math_Vector.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Matrix.hxx>
#include <Geom2dGcc_Type3.hxx>
#include <Geom2dGcc_FunctionTanCuCu.hxx>

void bind_Geom2dGcc_FunctionTanCuCu(py::module &mod){

py::class_<Geom2dGcc_FunctionTanCuCu, std::unique_ptr<Geom2dGcc_FunctionTanCuCu>, math_FunctionSetWithDerivatives> cls_Geom2dGcc_FunctionTanCuCu(mod, "Geom2dGcc_FunctionTanCuCu", "This abstract class describes a Function of 1 Variable used to find a line tangent to two curves.");

// Constructors
cls_Geom2dGcc_FunctionTanCuCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &>(), py::arg("Curv1"), py::arg("Curv2"));
cls_Geom2dGcc_FunctionTanCuCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &>(), py::arg("Circ1"), py::arg("Curv2"));

// Fields

// Methods
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuCu.def("InitDerivative", (void (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, gp_Pnt2d &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_FunctionTanCuCu::InitDerivative, "None", py::arg("X"), py::arg("Point1"), py::arg("Point2"), py::arg("Tan1"), py::arg("Tan2"), py::arg("D21"), py::arg("D22"));
cls_Geom2dGcc_FunctionTanCuCu.def("NbVariables", (Standard_Integer (Geom2dGcc_FunctionTanCuCu::*)() const) &Geom2dGcc_FunctionTanCuCu::NbVariables, "returns the number of variables of the function.");
cls_Geom2dGcc_FunctionTanCuCu.def("NbEquations", (Standard_Integer (Geom2dGcc_FunctionTanCuCu::*)() const) &Geom2dGcc_FunctionTanCuCu::NbEquations, "returns the number of equations of the function.");
cls_Geom2dGcc_FunctionTanCuCu.def("Value", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Vector &)) &Geom2dGcc_FunctionTanCuCu::Value, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuCu.def("Derivatives", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCu::Derivatives, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanCuCu.def("Values", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCu::Values, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// Enums

}