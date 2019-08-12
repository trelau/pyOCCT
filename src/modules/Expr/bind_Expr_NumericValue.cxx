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
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Expr_NumericValue.hxx>
#include <Standard_Type.hxx>

void bind_Expr_NumericValue(py::module &mod){

py::class_<Expr_NumericValue, opencascade::handle<Expr_NumericValue>, Expr_GeneralExpression> cls_Expr_NumericValue(mod, "Expr_NumericValue", "This class describes any reel value defined in an expression.");

// Constructors
cls_Expr_NumericValue.def(py::init<const Standard_Real>(), py::arg("val"));

// Fields

// Methods
cls_Expr_NumericValue.def("GetValue", (Standard_Real (Expr_NumericValue::*)() const) &Expr_NumericValue::GetValue, "None");
cls_Expr_NumericValue.def("SetValue", (void (Expr_NumericValue::*)(const Standard_Real)) &Expr_NumericValue::SetValue, "None", py::arg("val"));
cls_Expr_NumericValue.def("NbSubExpressions", (Standard_Integer (Expr_NumericValue::*)() const) &Expr_NumericValue::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_NumericValue.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NumericValue::*)(const Standard_Integer) const) &Expr_NumericValue::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_NumericValue.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NumericValue.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NumericValue.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NumericValue.def("ContainsUnknowns", (Standard_Boolean (Expr_NumericValue::*)() const) &Expr_NumericValue::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
cls_Expr_NumericValue.def("Contains", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NumericValue::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NumericValue.def("IsIdentical", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NumericValue::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_NumericValue.def("IsLinear", (Standard_Boolean (Expr_NumericValue::*)() const) &Expr_NumericValue::IsLinear, "None");
cls_Expr_NumericValue.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NumericValue::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NumericValue.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NumericValue::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_NumericValue.def("Replace", (void (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NumericValue::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
cls_Expr_NumericValue.def("Evaluate", (Standard_Real (Expr_NumericValue::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NumericValue::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
cls_Expr_NumericValue.def("String", (TCollection_AsciiString (Expr_NumericValue::*)() const) &Expr_NumericValue::String, "returns a string representing <me> in a readable way.");
cls_Expr_NumericValue.def_static("get_type_name_", (const char * (*)()) &Expr_NumericValue::get_type_name, "None");
cls_Expr_NumericValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NumericValue::get_type_descriptor, "None");
cls_Expr_NumericValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NumericValue::*)() const) &Expr_NumericValue::DynamicType, "None");

// Enums

}