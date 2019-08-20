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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_Generator.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_GeneralRelation.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralFunction.hxx>
#include <Expr_NamedFunction.hxx>
#include <Expr_NamedExpression.hxx>
#include <ExprIntrp_StackOfGeneralExpression.hxx>
#include <ExprIntrp_StackOfGeneralRelation.hxx>
#include <ExprIntrp_StackOfGeneralFunction.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <ExprIntrp_SequenceOfNamedFunction.hxx>
#include <ExprIntrp_SequenceOfNamedExpression.hxx>
#include <ExprIntrp_Analysis.hxx>

void bind_ExprIntrp_Analysis(py::module &mod){

py::class_<ExprIntrp_Analysis, std::unique_ptr<ExprIntrp_Analysis>> cls_ExprIntrp_Analysis(mod, "ExprIntrp_Analysis", "None");

// Constructors
cls_ExprIntrp_Analysis.def(py::init<>());

// Fields

// Methods
// cls_ExprIntrp_Analysis.def_static("operator new_", (void * (*)(size_t)) &ExprIntrp_Analysis::operator new, "None", py::arg("theSize"));
// cls_ExprIntrp_Analysis.def_static("operator delete_", (void (*)(void *)) &ExprIntrp_Analysis::operator delete, "None", py::arg("theAddress"));
// cls_ExprIntrp_Analysis.def_static("operator new[]_", (void * (*)(size_t)) &ExprIntrp_Analysis::operator new[], "None", py::arg("theSize"));
// cls_ExprIntrp_Analysis.def_static("operator delete[]_", (void (*)(void *)) &ExprIntrp_Analysis::operator delete[], "None", py::arg("theAddress"));
// cls_ExprIntrp_Analysis.def_static("operator new_", (void * (*)(size_t, void *)) &ExprIntrp_Analysis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ExprIntrp_Analysis.def_static("operator delete_", (void (*)(void *, void *)) &ExprIntrp_Analysis::operator delete, "None", py::arg(""), py::arg(""));
cls_ExprIntrp_Analysis.def("SetMaster", (void (ExprIntrp_Analysis::*)(const opencascade::handle<ExprIntrp_Generator> &)) &ExprIntrp_Analysis::SetMaster, "None", py::arg("agen"));
cls_ExprIntrp_Analysis.def("Push", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_GeneralExpression> &)) &ExprIntrp_Analysis::Push, "None", py::arg("exp"));
cls_ExprIntrp_Analysis.def("PushRelation", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_GeneralRelation> &)) &ExprIntrp_Analysis::PushRelation, "None", py::arg("rel"));
cls_ExprIntrp_Analysis.def("PushName", (void (ExprIntrp_Analysis::*)(const TCollection_AsciiString &)) &ExprIntrp_Analysis::PushName, "None", py::arg("name"));
cls_ExprIntrp_Analysis.def("PushValue", (void (ExprIntrp_Analysis::*)(const Standard_Integer)) &ExprIntrp_Analysis::PushValue, "None", py::arg("degree"));
cls_ExprIntrp_Analysis.def("PushFunction", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_GeneralFunction> &)) &ExprIntrp_Analysis::PushFunction, "None", py::arg("func"));
cls_ExprIntrp_Analysis.def("Pop", (opencascade::handle<Expr_GeneralExpression> (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::Pop, "None");
cls_ExprIntrp_Analysis.def("PopRelation", (opencascade::handle<Expr_GeneralRelation> (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::PopRelation, "None");
cls_ExprIntrp_Analysis.def("PopName", (TCollection_AsciiString (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::PopName, "None");
cls_ExprIntrp_Analysis.def("PopValue", (Standard_Integer (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::PopValue, "None");
cls_ExprIntrp_Analysis.def("PopFunction", (opencascade::handle<Expr_GeneralFunction> (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::PopFunction, "None");
cls_ExprIntrp_Analysis.def("IsExpStackEmpty", (Standard_Boolean (ExprIntrp_Analysis::*)() const) &ExprIntrp_Analysis::IsExpStackEmpty, "None");
cls_ExprIntrp_Analysis.def("IsRelStackEmpty", (Standard_Boolean (ExprIntrp_Analysis::*)() const) &ExprIntrp_Analysis::IsRelStackEmpty, "None");
cls_ExprIntrp_Analysis.def("ResetAll", (void (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::ResetAll, "None");
cls_ExprIntrp_Analysis.def("Use", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_Analysis::Use, "None", py::arg("func"));
cls_ExprIntrp_Analysis.def("Use", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_Analysis::Use, "None", py::arg("named"));
cls_ExprIntrp_Analysis.def("GetNamed", (opencascade::handle<Expr_NamedExpression> (ExprIntrp_Analysis::*)(const TCollection_AsciiString &)) &ExprIntrp_Analysis::GetNamed, "None", py::arg("name"));
cls_ExprIntrp_Analysis.def("GetFunction", (opencascade::handle<Expr_NamedFunction> (ExprIntrp_Analysis::*)(const TCollection_AsciiString &)) &ExprIntrp_Analysis::GetFunction, "None", py::arg("name"));

// Enums

}