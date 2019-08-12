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
#include <Expr_UnaryExpression.hxx>
#include <Standard_Type.hxx>

void bind_Expr_UnaryExpression(py::module &mod){

py::class_<Expr_UnaryExpression, opencascade::handle<Expr_UnaryExpression>, Expr_GeneralExpression> cls_Expr_UnaryExpression(mod, "Expr_UnaryExpression", "None");

// Fields

// Methods
cls_Expr_UnaryExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::Operand, "Returns the operand used");
cls_Expr_UnaryExpression.def("SetOperand", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::SetOperand, "Sets the operand used Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
cls_Expr_UnaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_UnaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)(const Standard_Integer) const) &Expr_UnaryExpression::SubExpression, "Returns the <I>-th sub-expression of <me>. Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_UnaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
cls_Expr_UnaryExpression.def("Contains", (Standard_Boolean (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_UnaryExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_UnaryExpression.def("Replace", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_UnaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_UnaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryExpression::get_type_name, "None");
cls_Expr_UnaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryExpression::get_type_descriptor, "None");
cls_Expr_UnaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::DynamicType, "None");

// Enums

}