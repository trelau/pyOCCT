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
#include <Expr_NamedUnknown.hxx>
#include <Expr_GeneralFunction.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_Expr_GeneralFunction(py::module &mod){

py::class_<Expr_GeneralFunction, opencascade::handle<Expr_GeneralFunction>, Standard_Transient> cls_Expr_GeneralFunction(mod, "Expr_GeneralFunction", "Defines the general purposes of any function.");

// Fields

// Methods
cls_Expr_GeneralFunction.def("NbOfVariables", (Standard_Integer (Expr_GeneralFunction::*)() const) &Expr_GeneralFunction::NbOfVariables, "Returns the number of variables of <me>.");
cls_Expr_GeneralFunction.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_GeneralFunction::*)(const Standard_Integer) const) &Expr_GeneralFunction::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if index > NbOfVariables.", py::arg("index"));
cls_Expr_GeneralFunction.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)() const) &Expr_GeneralFunction::Copy, "Returns a copy of <me> with the same form.");
cls_Expr_GeneralFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_GeneralFunction::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
cls_Expr_GeneralFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_GeneralFunction::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
cls_Expr_GeneralFunction.def("Evaluate", (Standard_Real (Expr_GeneralFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_GeneralFunction::Evaluate, "Computes the value of <me> with the given variables. Raises NotEvaluable if <vars> does not match all variables of <me>.", py::arg("vars"), py::arg("vals"));
cls_Expr_GeneralFunction.def("IsIdentical", (Standard_Boolean (Expr_GeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &) const) &Expr_GeneralFunction::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
cls_Expr_GeneralFunction.def("IsLinearOnVariable", (Standard_Boolean (Expr_GeneralFunction::*)(const Standard_Integer) const) &Expr_GeneralFunction::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
cls_Expr_GeneralFunction.def("GetStringName", (TCollection_AsciiString (Expr_GeneralFunction::*)() const) &Expr_GeneralFunction::GetStringName, "None");
cls_Expr_GeneralFunction.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralFunction::get_type_name, "None");
cls_Expr_GeneralFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralFunction::get_type_descriptor, "None");
cls_Expr_GeneralFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralFunction::*)() const) &Expr_GeneralFunction::DynamicType, "None");

// Enums

}