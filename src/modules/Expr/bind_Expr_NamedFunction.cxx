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
#include <Expr_GeneralFunction.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Expr_NamedFunction.hxx>
#include <Standard_Type.hxx>

void bind_Expr_NamedFunction(py::module &mod){

py::class_<Expr_NamedFunction, opencascade::handle<Expr_NamedFunction>, Expr_GeneralFunction> cls_Expr_NamedFunction(mod, "Expr_NamedFunction", "None");

// Constructors
cls_Expr_NamedFunction.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Expr_GeneralExpression> &, const Expr_Array1OfNamedUnknown &>(), py::arg("name"), py::arg("exp"), py::arg("vars"));

// Fields

// Methods
cls_Expr_NamedFunction.def("SetName", (void (Expr_NamedFunction::*)(const TCollection_AsciiString &)) &Expr_NamedFunction::SetName, "Sets the name <newname> to <me>.", py::arg("newname"));
cls_Expr_NamedFunction.def("GetName", (TCollection_AsciiString (Expr_NamedFunction::*)() const) &Expr_NamedFunction::GetName, "Returns the name assigned to <me>");
cls_Expr_NamedFunction.def("NbOfVariables", (Standard_Integer (Expr_NamedFunction::*)() const) &Expr_NamedFunction::NbOfVariables, "Returns the number of variables of <me>.");
cls_Expr_NamedFunction.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_NamedFunction::*)(const Standard_Integer) const) &Expr_NamedFunction::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> is greater than NbOfVariables of <me>, or less than or equal to zero.", py::arg("index"));
cls_Expr_NamedFunction.def("Evaluate", (Standard_Real (Expr_NamedFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedFunction::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
cls_Expr_NamedFunction.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)() const) &Expr_NamedFunction::Copy, "Returns a copy of <me> with the same form.");
cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
cls_Expr_NamedFunction.def("IsIdentical", (Standard_Boolean (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralFunction> &) const) &Expr_NamedFunction::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
cls_Expr_NamedFunction.def("IsLinearOnVariable", (Standard_Boolean (Expr_NamedFunction::*)(const Standard_Integer) const) &Expr_NamedFunction::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
cls_Expr_NamedFunction.def("GetStringName", (TCollection_AsciiString (Expr_NamedFunction::*)() const) &Expr_NamedFunction::GetStringName, "None");
cls_Expr_NamedFunction.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedFunction::*)() const) &Expr_NamedFunction::Expression, "Returns equivalent expression of <me>.");
cls_Expr_NamedFunction.def("SetExpression", (void (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedFunction::SetExpression, "Modifies expression of <me>. Warning: Beware of derivatives. See FunctionDerivative", py::arg("exp"));
cls_Expr_NamedFunction.def_static("get_type_name_", (const char * (*)()) &Expr_NamedFunction::get_type_name, "None");
cls_Expr_NamedFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedFunction::get_type_descriptor, "None");
cls_Expr_NamedFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedFunction::*)() const) &Expr_NamedFunction::DynamicType, "None");

// Enums

}