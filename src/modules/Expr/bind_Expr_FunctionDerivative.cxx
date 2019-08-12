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
#include <Expr_GeneralFunction.hxx>
#include <Standard_Handle.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedFunction.hxx>
#include <Expr_FunctionDerivative.hxx>
#include <Standard_Type.hxx>

void bind_Expr_FunctionDerivative(py::module &mod){

py::class_<Expr_FunctionDerivative, opencascade::handle<Expr_FunctionDerivative>, Expr_GeneralFunction> cls_Expr_FunctionDerivative(mod, "Expr_FunctionDerivative", "None");

// Constructors
cls_Expr_FunctionDerivative.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer>(), py::arg("func"), py::arg("withX"), py::arg("deg"));

// Fields

// Methods
cls_Expr_FunctionDerivative.def("NbOfVariables", (Standard_Integer (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::NbOfVariables, "Returns the number of variables of <me>.");
cls_Expr_FunctionDerivative.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)(const Standard_Integer) const) &Expr_FunctionDerivative::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> greater than NbOfVariables of <me>.", py::arg("index"));
cls_Expr_FunctionDerivative.def("Evaluate", (Standard_Real (Expr_FunctionDerivative::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_FunctionDerivative::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
cls_Expr_FunctionDerivative.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Copy, "Returns a copy of <me> with the same form.");
cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
cls_Expr_FunctionDerivative.def("IsIdentical", (Standard_Boolean (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_GeneralFunction> &) const) &Expr_FunctionDerivative::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
cls_Expr_FunctionDerivative.def("IsLinearOnVariable", (Standard_Boolean (Expr_FunctionDerivative::*)(const Standard_Integer) const) &Expr_FunctionDerivative::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
cls_Expr_FunctionDerivative.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Function, "Returns the function of which <me> is the derivative.");
cls_Expr_FunctionDerivative.def("Degree", (Standard_Integer (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Degree, "Returns the degree of derivation of <me>.");
cls_Expr_FunctionDerivative.def("DerivVariable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::DerivVariable, "Returns the derivation variable of <me>.");
cls_Expr_FunctionDerivative.def("GetStringName", (TCollection_AsciiString (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::GetStringName, "None");
cls_Expr_FunctionDerivative.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Expression, "None");
cls_Expr_FunctionDerivative.def("UpdateExpression", (void (Expr_FunctionDerivative::*)()) &Expr_FunctionDerivative::UpdateExpression, "None");
cls_Expr_FunctionDerivative.def_static("get_type_name_", (const char * (*)()) &Expr_FunctionDerivative::get_type_name, "None");
cls_Expr_FunctionDerivative.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_FunctionDerivative::get_type_descriptor, "None");
cls_Expr_FunctionDerivative.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::DynamicType, "None");

// Enums

}