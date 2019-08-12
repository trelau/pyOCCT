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
#include <ExprIntrp_Generator.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_GenExp.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Standard_Type.hxx>

void bind_ExprIntrp_GenExp(py::module &mod){

py::class_<ExprIntrp_GenExp, opencascade::handle<ExprIntrp_GenExp>, ExprIntrp_Generator> cls_ExprIntrp_GenExp(mod, "ExprIntrp_GenExp", "This class permits, from a string, to create any kind of expression of package Expr by using built-in functions such as Sin,Cos, etc, and by creating variables.");

// Constructors

// Fields

// Methods
cls_ExprIntrp_GenExp.def_static("Create_", (opencascade::handle<ExprIntrp_GenExp> (*)()) &ExprIntrp_GenExp::Create, "None");
cls_ExprIntrp_GenExp.def("Process", (void (ExprIntrp_GenExp::*)(const TCollection_AsciiString &)) &ExprIntrp_GenExp::Process, "Processes given string.", py::arg("str"));
cls_ExprIntrp_GenExp.def("IsDone", (Standard_Boolean (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::IsDone, "Returns false if any syntax error has occurred during process.");
cls_ExprIntrp_GenExp.def("Expression", (opencascade::handle<Expr_GeneralExpression> (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::Expression, "Returns expression generated. Raises an exception if IsDone answers false.");
cls_ExprIntrp_GenExp.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenExp::get_type_name, "None");
cls_ExprIntrp_GenExp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenExp::get_type_descriptor, "None");
cls_ExprIntrp_GenExp.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::DynamicType, "None");

// Enums

}