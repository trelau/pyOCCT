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
#include <Expr_Different.hxx>
#include <Standard_Type.hxx>

void bind_Expr_Different(py::module &mod){

py::class_<Expr_Different, opencascade::handle<Expr_Different>, Expr_SingleRelation> cls_Expr_Different(mod, "Expr_Different", "None");

// Constructors
cls_Expr_Different.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Fields

// Methods
cls_Expr_Different.def("IsSatisfied", (Standard_Boolean (Expr_Different::*)() const) &Expr_Different::IsSatisfied, "None");
cls_Expr_Different.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const) &Expr_Different::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_Different.def("Simplify", (void (Expr_Different::*)()) &Expr_Different::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_Different.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const) &Expr_Different::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Different.def("String", (TCollection_AsciiString (Expr_Different::*)() const) &Expr_Different::String, "returns a string representing <me> in a readable way.");
cls_Expr_Different.def_static("get_type_name_", (const char * (*)()) &Expr_Different::get_type_name, "None");
cls_Expr_Different.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Different::get_type_descriptor, "None");
cls_Expr_Different.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Different::*)() const) &Expr_Different::DynamicType, "None");

// Enums

}