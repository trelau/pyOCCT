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
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Expr_NamedExpression.hxx>
#include <Standard_Type.hxx>

void bind_Expr_NamedExpression(py::module &mod){

py::class_<Expr_NamedExpression, opencascade::handle<Expr_NamedExpression>, Expr_GeneralExpression> cls_Expr_NamedExpression(mod, "Expr_NamedExpression", "Describe an expression used by its name (as constants or variables). A single reference is made to a NamedExpression in every Expression (i.e. a NamedExpression is shared).");

// Fields

// Methods
cls_Expr_NamedExpression.def("GetName", (const TCollection_AsciiString & (Expr_NamedExpression::*)() const) &Expr_NamedExpression::GetName, "None");
cls_Expr_NamedExpression.def("SetName", (void (Expr_NamedExpression::*)(const TCollection_AsciiString &)) &Expr_NamedExpression::SetName, "None", py::arg("name"));
cls_Expr_NamedExpression.def("IsShareable", (Standard_Boolean (Expr_NamedExpression::*)() const) &Expr_NamedExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method redefines to a True value the GeneralExpression method.");
cls_Expr_NamedExpression.def("IsIdentical", (Standard_Boolean (Expr_NamedExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_NamedExpression.def("String", (TCollection_AsciiString (Expr_NamedExpression::*)() const) &Expr_NamedExpression::String, "returns a string representing <me> in a readable way.");
cls_Expr_NamedExpression.def_static("get_type_name_", (const char * (*)()) &Expr_NamedExpression::get_type_name, "None");
cls_Expr_NamedExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedExpression::get_type_descriptor, "None");
cls_Expr_NamedExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedExpression::*)() const) &Expr_NamedExpression::DynamicType, "None");

// Enums

}