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
#include <Expr_GeneralRelation.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedUnknown.hxx>
#include <TCollection_AsciiString.hxx>
#include <Expr_SystemRelation.hxx>
#include <Standard_Type.hxx>
#include <Expr_SequenceOfGeneralRelation.hxx>

void bind_Expr_SystemRelation(py::module &mod){

py::class_<Expr_SystemRelation, opencascade::handle<Expr_SystemRelation>, Expr_GeneralRelation> cls_Expr_SystemRelation(mod, "Expr_SystemRelation", "None");

// Constructors
cls_Expr_SystemRelation.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("relation"));

// Fields

// Methods
cls_Expr_SystemRelation.def("Add", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SystemRelation::Add, "Appends <relation> in the list of components of <me>.", py::arg("relation"));
cls_Expr_SystemRelation.def("Remove", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SystemRelation::Remove, "None", py::arg("relation"));
cls_Expr_SystemRelation.def("IsLinear", (Standard_Boolean (Expr_SystemRelation::*)() const) &Expr_SystemRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
cls_Expr_SystemRelation.def("NbOfSubRelations", (Standard_Integer (Expr_SystemRelation::*)() const) &Expr_SystemRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
cls_Expr_SystemRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_SystemRelation::*)() const) &Expr_SystemRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me>.");
cls_Expr_SystemRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)(const Standard_Integer) const) &Expr_SystemRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if <index> is out of range.", py::arg("index"));
cls_Expr_SystemRelation.def("IsSatisfied", (Standard_Boolean (Expr_SystemRelation::*)() const) &Expr_SystemRelation::IsSatisfied, "None");
cls_Expr_SystemRelation.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)() const) &Expr_SystemRelation::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_SystemRelation.def("Simplify", (void (Expr_SystemRelation::*)()) &Expr_SystemRelation::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_SystemRelation.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)() const) &Expr_SystemRelation::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_SystemRelation.def("Contains", (Standard_Boolean (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_SystemRelation::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
cls_Expr_SystemRelation.def("Replace", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SystemRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
cls_Expr_SystemRelation.def("String", (TCollection_AsciiString (Expr_SystemRelation::*)() const) &Expr_SystemRelation::String, "returns a string representing <me> in a readable way.");
cls_Expr_SystemRelation.def_static("get_type_name_", (const char * (*)()) &Expr_SystemRelation::get_type_name, "None");
cls_Expr_SystemRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SystemRelation::get_type_descriptor, "None");
cls_Expr_SystemRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SystemRelation::*)() const) &Expr_SystemRelation::DynamicType, "None");

// Enums

}