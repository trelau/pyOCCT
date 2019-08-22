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
#include <math_FunctionSet.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <PLib_Base.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <FEmTool_ElementsOfRefMatrix.hxx>

void bind_FEmTool_ElementsOfRefMatrix(py::module &mod){

py::class_<FEmTool_ElementsOfRefMatrix, math_FunctionSet> cls_FEmTool_ElementsOfRefMatrix(mod, "FEmTool_ElementsOfRefMatrix", "this class describes the functions needed for calculating matrix elements of RefMatrix for linear criteriums (Tension, Flexsion and Jerk) by Gauss integration. Each function from set gives value Pi(u)'*Pj(u)' or Pi(u)''*Pj(u)'' or Pi(u)'''*Pj(u)''' for each i and j, where Pi(u) is i-th basis function of expansion and (') means derivative.");

// Constructors
cls_FEmTool_ElementsOfRefMatrix.def(py::init<const opencascade::handle<PLib_Base> &, const Standard_Integer>(), py::arg("TheBase"), py::arg("DerOrder"));

// Fields

// Methods
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new_", (void * (*)(size_t)) &FEmTool_ElementsOfRefMatrix::operator new, "None", py::arg("theSize"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete_", (void (*)(void *)) &FEmTool_ElementsOfRefMatrix::operator delete, "None", py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new[]_", (void * (*)(size_t)) &FEmTool_ElementsOfRefMatrix::operator new[], "None", py::arg("theSize"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete[]_", (void (*)(void *)) &FEmTool_ElementsOfRefMatrix::operator delete[], "None", py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator new_", (void * (*)(size_t, void *)) &FEmTool_ElementsOfRefMatrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FEmTool_ElementsOfRefMatrix.def_static("operator delete_", (void (*)(void *, void *)) &FEmTool_ElementsOfRefMatrix::operator delete, "None", py::arg(""), py::arg(""));
cls_FEmTool_ElementsOfRefMatrix.def("NbVariables", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const) &FEmTool_ElementsOfRefMatrix::NbVariables, "returns the number of variables of the function. It is supposed that NbVariables = 1.");
cls_FEmTool_ElementsOfRefMatrix.def("NbEquations", (Standard_Integer (FEmTool_ElementsOfRefMatrix::*)() const) &FEmTool_ElementsOfRefMatrix::NbEquations, "returns the number of equations of the function.");
cls_FEmTool_ElementsOfRefMatrix.def("Value", (Standard_Boolean (FEmTool_ElementsOfRefMatrix::*)(const math_Vector &, math_Vector &)) &FEmTool_ElementsOfRefMatrix::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise. F contains results only for i<=j in following order: P0*P0, P0*P1, P0*P2... P1*P1, P1*P2,... (upper triangle of matrix {PiPj})", py::arg("X"), py::arg("F"));

// Enums

}