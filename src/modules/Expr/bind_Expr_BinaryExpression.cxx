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
#include <Expr_GeneralExpression.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_BinaryExpression.hxx>
#include <Standard_Type.hxx>

void bind_Expr_BinaryExpression(py::module &mod){

py::class_<Expr_BinaryExpression, opencascade::handle<Expr_BinaryExpression>, Expr_GeneralExpression> cls_Expr_BinaryExpression(mod, "Expr_BinaryExpression", "Defines all binary expressions. The order of the two operands is significant.");

// Fields

// Methods
cls_Expr_BinaryExpression.def("FirstOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::FirstOperand, "None");
cls_Expr_BinaryExpression.def("SecondOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::SecondOperand, "None");
cls_Expr_BinaryExpression.def("SetFirstOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetFirstOperand, "Sets first operand of <me> Raises InvalidOperand if exp = me", py::arg("exp"));
cls_Expr_BinaryExpression.def("SetSecondOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetSecondOperand, "Sets second operand of <me> Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
cls_Expr_BinaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_BinaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)(const Standard_Integer) const) &Expr_BinaryExpression::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_BinaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::ContainsUnknowns, "Does <me> contain NamedUnknown ?");
cls_Expr_BinaryExpression.def("Contains", (Standard_Boolean (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_BinaryExpression::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
cls_Expr_BinaryExpression.def("Replace", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me>. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_BinaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_BinaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_BinaryExpression::get_type_name, "None");
cls_Expr_BinaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_BinaryExpression::get_type_descriptor, "None");
cls_Expr_BinaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::DynamicType, "None");

// Enums

}