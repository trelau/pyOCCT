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
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pnt2d.hxx>
#include <math_Vector.hxx>
#include <gp_Vec2d.hxx>
#include <math_Matrix.hxx>
#include <Geom2dGcc_Type2.hxx>
#include <Geom2dGcc_FunctionTanCuCuOnCu.hxx>

void bind_Geom2dGcc_FunctionTanCuCuOnCu(py::module &mod){

py::class_<Geom2dGcc_FunctionTanCuCuOnCu, std::unique_ptr<Geom2dGcc_FunctionTanCuCuOnCu, Deleter<Geom2dGcc_FunctionTanCuCuOnCu>>, math_FunctionSetWithDerivatives> cls_Geom2dGcc_FunctionTanCuCuOnCu(mod, "Geom2dGcc_FunctionTanCuCuOnCu", "This abstract class describes a set on N Functions of M independant variables.");

// Constructors
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("P2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("P2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("P1"), py::arg("OnCu"), py::arg("Rad"));

// Fields

// Methods
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("InitDerivative", (void (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_FunctionTanCuCuOnCu::InitDerivative, "None", py::arg("X"), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tan1"), py::arg("Tan2"), py::arg("Tan3"), py::arg("D21"), py::arg("D22"), py::arg("D23"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("NbVariables", (Standard_Integer (Geom2dGcc_FunctionTanCuCuOnCu::*)() const) &Geom2dGcc_FunctionTanCuCuOnCu::NbVariables, "Returns the number of variables of the function.");
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("NbEquations", (Standard_Integer (Geom2dGcc_FunctionTanCuCuOnCu::*)() const) &Geom2dGcc_FunctionTanCuCuOnCu::NbEquations, "Returns the number of equations of the function.");
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Value", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Vector &)) &Geom2dGcc_FunctionTanCuCuOnCu::Value, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Derivatives", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuOnCu::Derivatives, "Returns the values of the derivatives for the variable <X>.", py::arg("X"), py::arg("D"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Values", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuOnCu::Values, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}