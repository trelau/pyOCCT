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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_Expr_GeneralExpression(py::module &mod){

py::class_<Expr_GeneralExpression, opencascade::handle<Expr_GeneralExpression>, Standard_Transient> cls_Expr_GeneralExpression(mod, "Expr_GeneralExpression", "Defines the general purposes of any expression.");

// Fields

// Methods
cls_Expr_GeneralExpression.def("NbSubExpressions", (Standard_Integer (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_GeneralExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_GeneralExpression::*)(const Standard_Integer) const) &Expr_GeneralExpression::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_GeneralExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_GeneralExpression.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_GeneralExpression.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GeneralExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::ContainsUnknowns, "Tests if <me> contains NamedUnknowns.");
cls_Expr_GeneralExpression.def("Contains", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_GeneralExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_GeneralExpression.def("IsLinear", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::IsLinear, "Tests if <me> is linear on every NamedUnknown it contains.");
cls_Expr_GeneralExpression.def("IsShareable", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method returns False as a default value. To be redefined ( especially for NamedUnknown).");
cls_Expr_GeneralExpression.def("IsIdentical", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_GeneralExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. Warning: This method does not include any simplification before testing. It could also be very slow; to be used carefully.", py::arg("Other"));
cls_Expr_GeneralExpression.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_GeneralExpression::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_GeneralExpression.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_GeneralExpression::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raise OutOfRange if N <= 0", py::arg("X"), py::arg("N"));
cls_Expr_GeneralExpression.def("Replace", (void (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_GeneralExpression::Replace, "Replaces all occurences of <var> with copies of <with> in <me>. Copies of <with> are made with the Copy() method. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_GeneralExpression.def("Evaluate", (Standard_Real (Expr_GeneralExpression::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_GeneralExpression::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_GeneralExpression.def("EvaluateNumeric", (Standard_Real (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::EvaluateNumeric, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.");
cls_Expr_GeneralExpression.def("String", (TCollection_AsciiString (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::String, "returns a string representing <me> in a readable way.");
cls_Expr_GeneralExpression.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralExpression::get_type_name, "None");
cls_Expr_GeneralExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralExpression::get_type_descriptor, "None");
cls_Expr_GeneralExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::DynamicType, "None");

// Enums

}