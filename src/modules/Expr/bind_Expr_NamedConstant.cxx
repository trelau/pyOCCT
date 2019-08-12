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
#include <Expr_NamedConstant.hxx>
#include <Standard_Type.hxx>

void bind_Expr_NamedConstant(py::module &mod){

py::class_<Expr_NamedConstant, opencascade::handle<Expr_NamedConstant>, Expr_NamedExpression> cls_Expr_NamedConstant(mod, "Expr_NamedConstant", "Describes any numeric constant known by a special name (as PI, e,...).");

// Constructors
cls_Expr_NamedConstant.def(py::init<const TCollection_AsciiString &, const Standard_Real>(), py::arg("name"), py::arg("value"));

// Fields

// Methods
cls_Expr_NamedConstant.def("GetValue", (Standard_Real (Expr_NamedConstant::*)() const) &Expr_NamedConstant::GetValue, "None");
cls_Expr_NamedConstant.def("NbSubExpressions", (Standard_Integer (Expr_NamedConstant::*)() const) &Expr_NamedConstant::NbSubExpressions, "returns the number of sub-expressions contained in <me> (always returns zero)");
cls_Expr_NamedConstant.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedConstant::*)(const Standard_Integer) const) &Expr_NamedConstant::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange", py::arg("I"));
cls_Expr_NamedConstant.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::Simplified, "returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NamedConstant.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NamedConstant.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NamedConstant.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedConstant::*)() const) &Expr_NamedConstant::ContainsUnknowns, "Tests if <me> contains NamedUnknown. (returns always False)");
cls_Expr_NamedConstant.def("Contains", (Standard_Boolean (Expr_NamedConstant::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedConstant::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NamedConstant.def("IsLinear", (Standard_Boolean (Expr_NamedConstant::*)() const) &Expr_NamedConstant::IsLinear, "None");
cls_Expr_NamedConstant.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedConstant::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NamedConstant.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NamedConstant::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_NamedConstant.def("Replace", (void (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedConstant::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
cls_Expr_NamedConstant.def("Evaluate", (Standard_Real (Expr_NamedConstant::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedConstant::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
cls_Expr_NamedConstant.def_static("get_type_name_", (const char * (*)()) &Expr_NamedConstant::get_type_name, "None");
cls_Expr_NamedConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedConstant::get_type_descriptor, "None");
cls_Expr_NamedConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedConstant::*)() const) &Expr_NamedConstant::DynamicType, "None");

// Enums

}