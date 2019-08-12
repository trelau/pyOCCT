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
#include <Expr_GeneralRelation.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedUnknown.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_Expr_GeneralRelation(py::module &mod){

py::class_<Expr_GeneralRelation, opencascade::handle<Expr_GeneralRelation>, Standard_Transient> cls_Expr_GeneralRelation(mod, "Expr_GeneralRelation", "Defines the general purposes of any relation between expressions.");

// Fields

// Methods
cls_Expr_GeneralRelation.def("IsSatisfied", (Standard_Boolean (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::IsSatisfied, "Returns the current status of the relation");
cls_Expr_GeneralRelation.def("IsLinear", (Standard_Boolean (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
cls_Expr_GeneralRelation.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_GeneralRelation.def("Simplify", (void (Expr_GeneralRelation::*)()) &Expr_GeneralRelation::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_GeneralRelation.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GeneralRelation.def("NbOfSubRelations", (Standard_Integer (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
cls_Expr_GeneralRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me>.");
cls_Expr_GeneralRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)(const Standard_Integer) const) &Expr_GeneralRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if <index> is out of range.", py::arg("index"));
cls_Expr_GeneralRelation.def("Contains", (Standard_Boolean (Expr_GeneralRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_GeneralRelation::Contains, "Tests if <exp> contains <var>.", py::arg("exp"));
cls_Expr_GeneralRelation.def("Replace", (void (Expr_GeneralRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_GeneralRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
cls_Expr_GeneralRelation.def("String", (TCollection_AsciiString (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::String, "returns a string representing <me> in a readable way.");
cls_Expr_GeneralRelation.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralRelation::get_type_name, "None");
cls_Expr_GeneralRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralRelation::get_type_descriptor, "None");
cls_Expr_GeneralRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralRelation::*)() const) &Expr_GeneralRelation::DynamicType, "None");

// Enums

}