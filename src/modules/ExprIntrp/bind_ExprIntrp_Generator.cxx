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
#include <Standard_Handle.hxx>
#include <Expr_NamedFunction.hxx>
#include <Expr_NamedExpression.hxx>
#include <ExprIntrp_SequenceOfNamedExpression.hxx>
#include <ExprIntrp_SequenceOfNamedFunction.hxx>
#include <TCollection_AsciiString.hxx>
#include <ExprIntrp_Generator.hxx>
#include <Standard_Type.hxx>

void bind_ExprIntrp_Generator(py::module &mod){

py::class_<ExprIntrp_Generator, opencascade::handle<ExprIntrp_Generator>, Standard_Transient> cls_ExprIntrp_Generator(mod, "ExprIntrp_Generator", "Implements general services for interpretation of expressions.");

// Constructors

// Fields

// Methods
cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_Generator::Use, "None", py::arg("func"));
cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_Generator::Use, "None", py::arg("named"));
cls_ExprIntrp_Generator.def("GetNamed", (const ExprIntrp_SequenceOfNamedExpression & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::GetNamed, "None");
cls_ExprIntrp_Generator.def("GetFunctions", (const ExprIntrp_SequenceOfNamedFunction & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::GetFunctions, "None");
cls_ExprIntrp_Generator.def("GetNamed", (opencascade::handle<Expr_NamedExpression> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const) &ExprIntrp_Generator::GetNamed, "Returns NamedExpression with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
cls_ExprIntrp_Generator.def("GetFunction", (opencascade::handle<Expr_NamedFunction> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const) &ExprIntrp_Generator::GetFunction, "Returns NamedFunction with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
cls_ExprIntrp_Generator.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_Generator::get_type_name, "None");
cls_ExprIntrp_Generator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_Generator::get_type_descriptor, "None");
cls_ExprIntrp_Generator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::DynamicType, "None");

// Enums

}