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
#include <Expr_SingleRelation.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralRelation.hxx>
#include <TCollection_AsciiString.hxx>
#include <Expr_GreaterThanOrEqual.hxx>
#include <Standard_Type.hxx>

void bind_Expr_GreaterThanOrEqual(py::module &mod){

py::class_<Expr_GreaterThanOrEqual, opencascade::handle<Expr_GreaterThanOrEqual>, Expr_SingleRelation> cls_Expr_GreaterThanOrEqual(mod, "Expr_GreaterThanOrEqual", "None");

// Constructors
cls_Expr_GreaterThanOrEqual.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Fields

// Methods
cls_Expr_GreaterThanOrEqual.def("IsSatisfied", (Standard_Boolean (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::IsSatisfied, "None");
cls_Expr_GreaterThanOrEqual.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_GreaterThanOrEqual.def("Simplify", (void (Expr_GreaterThanOrEqual::*)()) &Expr_GreaterThanOrEqual::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_GreaterThanOrEqual.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GreaterThanOrEqual.def("String", (TCollection_AsciiString (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::String, "returns a string representing <me> in a readable way.");
cls_Expr_GreaterThanOrEqual.def_static("get_type_name_", (const char * (*)()) &Expr_GreaterThanOrEqual::get_type_name, "None");
cls_Expr_GreaterThanOrEqual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GreaterThanOrEqual::get_type_descriptor, "None");
cls_Expr_GreaterThanOrEqual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::DynamicType, "None");

// Enums

}