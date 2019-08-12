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
#include <Expr_NamedExpression.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Type.hxx>

void bind_Expr_NamedUnknown(py::module &mod){

py::class_<Expr_NamedUnknown, opencascade::handle<Expr_NamedUnknown>, Expr_NamedExpression> cls_Expr_NamedUnknown(mod, "Expr_NamedUnknown", "This class describes any variable of an expression. Assignment is treated directly in this class.");

// Constructors
cls_Expr_NamedUnknown.def(py::init<const TCollection_AsciiString &>(), py::arg("name"));

// Fields

// Methods
cls_Expr_NamedUnknown.def("IsAssigned", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::IsAssigned, "Tests if an expression is assigned to <me>.");
cls_Expr_NamedUnknown.def("AssignedExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::AssignedExpression, "If exists, returns the assigned expression. An exception is raised if the expression does not exist.");
cls_Expr_NamedUnknown.def("Assign", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Assign, "Assigns <me> to <exp> expression. Raises exception if <exp> refers to <me>.", py::arg("exp"));
cls_Expr_NamedUnknown.def("Deassign", (void (Expr_NamedUnknown::*)()) &Expr_NamedUnknown::Deassign, "Supresses the assigned expression");
cls_Expr_NamedUnknown.def("NbSubExpressions", (Standard_Integer (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_NamedUnknown.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)(const Standard_Integer) const) &Expr_NamedUnknown::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_NamedUnknown.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NamedUnknown.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NamedUnknown.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NamedUnknown.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
cls_Expr_NamedUnknown.def("Contains", (Standard_Boolean (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedUnknown::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NamedUnknown.def("IsLinear", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::IsLinear, "None");
cls_Expr_NamedUnknown.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedUnknown::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NamedUnknown.def("Replace", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_NamedUnknown.def("Evaluate", (Standard_Real (Expr_NamedUnknown::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedUnknown::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_NamedUnknown.def_static("get_type_name_", (const char * (*)()) &Expr_NamedUnknown::get_type_name, "None");
cls_Expr_NamedUnknown.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedUnknown::get_type_descriptor, "None");
cls_Expr_NamedUnknown.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::DynamicType, "None");

// Enums

}