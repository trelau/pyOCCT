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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_PolyExpression.hxx>
#include <Standard_Type.hxx>
#include <Expr_SequenceOfGeneralExpression.hxx>

void bind_Expr_PolyExpression(py::module &mod){

py::class_<Expr_PolyExpression, opencascade::handle<Expr_PolyExpression>, Expr_GeneralExpression> cls_Expr_PolyExpression(mod, "Expr_PolyExpression", "None");

// Fields

// Methods
cls_Expr_PolyExpression.def("NbOperands", (Standard_Integer (Expr_PolyExpression::*)() const) &Expr_PolyExpression::NbOperands, "returns the number of operands contained in <me>");
cls_Expr_PolyExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const) &Expr_PolyExpression::Operand, "Returns the <index>-th operand used in <me>. An exception is raised if index is out of range", py::arg("index"));
cls_Expr_PolyExpression.def("SetOperand", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Integer)) &Expr_PolyExpression::SetOperand, "Sets the <index>-th operand used in <me>. An exception is raised if <index> is out of range Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"), py::arg("index"));
cls_Expr_PolyExpression.def("NbSubExpressions", (Standard_Integer (Expr_PolyExpression::*)() const) &Expr_PolyExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 2)");
cls_Expr_PolyExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const) &Expr_PolyExpression::SubExpression, "Returns the sub-expression denoted by <I> in <me> Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_PolyExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_PolyExpression::*)() const) &Expr_PolyExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
cls_Expr_PolyExpression.def("Contains", (Standard_Boolean (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_PolyExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_PolyExpression.def("Replace", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_PolyExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_PolyExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyExpression::*)() const) &Expr_PolyExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_PolyExpression.def_static("get_type_name_", (const char * (*)()) &Expr_PolyExpression::get_type_name, "None");
cls_Expr_PolyExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_PolyExpression::get_type_descriptor, "None");
cls_Expr_PolyExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_PolyExpression::*)() const) &Expr_PolyExpression::DynamicType, "None");

// Enums

}