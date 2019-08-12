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
#include <Expr_BinaryExpression.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Expr_Division.hxx>
#include <Standard_Type.hxx>

void bind_Expr_Division(py::module &mod){

py::class_<Expr_Division, opencascade::handle<Expr_Division>, Expr_BinaryExpression> cls_Expr_Division(mod, "Expr_Division", "None");

// Constructors
cls_Expr_Division.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Fields

// Methods
cls_Expr_Division.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const) &Expr_Division::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Division.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const) &Expr_Division::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Division.def("IsIdentical", (Standard_Boolean (Expr_Division::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Division::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Division.def("IsLinear", (Standard_Boolean (Expr_Division::*)() const) &Expr_Division::IsLinear, "None");
cls_Expr_Division.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Division::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Division.def("Evaluate", (Standard_Real (Expr_Division::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Division::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Division.def("String", (TCollection_AsciiString (Expr_Division::*)() const) &Expr_Division::String, "returns a string representing <me> in a readable way.");
cls_Expr_Division.def_static("get_type_name_", (const char * (*)()) &Expr_Division::get_type_name, "None");
cls_Expr_Division.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Division::get_type_descriptor, "None");
cls_Expr_Division.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Division::*)() const) &Expr_Division::DynamicType, "None");

// Enums

}