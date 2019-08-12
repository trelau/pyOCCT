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
#include <ExprIntrp_GenRel.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralRelation.hxx>
#include <Standard_Type.hxx>

void bind_ExprIntrp_GenRel(py::module &mod){

py::class_<ExprIntrp_GenRel, opencascade::handle<ExprIntrp_GenRel>, ExprIntrp_Generator> cls_ExprIntrp_GenRel(mod, "ExprIntrp_GenRel", "Implements an interpreter for equations or system of equations made of expressions of package Expr.");

// Constructors

// Fields

// Methods
cls_ExprIntrp_GenRel.def_static("Create_", (opencascade::handle<ExprIntrp_GenRel> (*)()) &ExprIntrp_GenRel::Create, "None");
cls_ExprIntrp_GenRel.def("Process", (void (ExprIntrp_GenRel::*)(const TCollection_AsciiString &)) &ExprIntrp_GenRel::Process, "Processes given string.", py::arg("str"));
cls_ExprIntrp_GenRel.def("IsDone", (Standard_Boolean (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::IsDone, "Returns false if any syntax error has occurred during process.");
cls_ExprIntrp_GenRel.def("Relation", (opencascade::handle<Expr_GeneralRelation> (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::Relation, "Returns relation generated. Raises an exception if IsDone answers false.");
cls_ExprIntrp_GenRel.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenRel::get_type_name, "None");
cls_ExprIntrp_GenRel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenRel::get_type_descriptor, "None");
cls_ExprIntrp_GenRel.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::DynamicType, "None");

// Enums

}