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
#include <Expr_GeneralExpression.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_SingleRelation.hxx>
#include <Standard_Type.hxx>

void bind_Expr_SingleRelation(py::module &mod){

py::class_<Expr_SingleRelation, opencascade::handle<Expr_SingleRelation>, Expr_GeneralRelation> cls_Expr_SingleRelation(mod, "Expr_SingleRelation", "None");

// Fields

// Methods
cls_Expr_SingleRelation.def("SetFirstMember", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::SetFirstMember, "Defines the first member of the relation", py::arg("exp"));
cls_Expr_SingleRelation.def("SetSecondMember", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::SetSecondMember, "Defines the second member of the relation", py::arg("exp"));
cls_Expr_SingleRelation.def("FirstMember", (opencascade::handle<Expr_GeneralExpression> (Expr_SingleRelation::*)() const) &Expr_SingleRelation::FirstMember, "Returns the first member of the relation");
cls_Expr_SingleRelation.def("SecondMember", (opencascade::handle<Expr_GeneralExpression> (Expr_SingleRelation::*)() const) &Expr_SingleRelation::SecondMember, "Returns the second member of the relation");
cls_Expr_SingleRelation.def("IsLinear", (Standard_Boolean (Expr_SingleRelation::*)() const) &Expr_SingleRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
cls_Expr_SingleRelation.def("NbOfSubRelations", (Standard_Integer (Expr_SingleRelation::*)() const) &Expr_SingleRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
cls_Expr_SingleRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_SingleRelation::*)() const) &Expr_SingleRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me> (Always 1).");
cls_Expr_SingleRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_SingleRelation::*)(const Standard_Integer) const) &Expr_SingleRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if index is out of range.", py::arg("index"));
cls_Expr_SingleRelation.def("Contains", (Standard_Boolean (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_SingleRelation::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
cls_Expr_SingleRelation.def("Replace", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
cls_Expr_SingleRelation.def_static("get_type_name_", (const char * (*)()) &Expr_SingleRelation::get_type_name, "None");
cls_Expr_SingleRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SingleRelation::get_type_descriptor, "None");
cls_Expr_SingleRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SingleRelation::*)() const) &Expr_SingleRelation::DynamicType, "None");

// Enums

}