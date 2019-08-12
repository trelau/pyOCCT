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
#include <Expr_GeneralExpression.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralRelation.hxx>
#include <Expr_NumericValue.hxx>
#include <Expr_NamedExpression.hxx>
#include <Expr_NamedConstant.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_UnaryExpression.hxx>
#include <Expr_Absolute.hxx>
#include <Expr_ArcCosine.hxx>
#include <Expr_ArcSine.hxx>
#include <Expr_ArcTangent.hxx>
#include <Expr_ArgCosh.hxx>
#include <Expr_ArgSinh.hxx>
#include <Expr_ArgTanh.hxx>
#include <Expr_Cosh.hxx>
#include <Expr_Cosine.hxx>
#include <Expr_Exponential.hxx>
#include <Expr_LogOf10.hxx>
#include <Expr_LogOfe.hxx>
#include <Expr_Sign.hxx>
#include <Expr_Sine.hxx>
#include <Expr_Sinh.hxx>
#include <Expr_Square.hxx>
#include <Expr_SquareRoot.hxx>
#include <Expr_Tangent.hxx>
#include <Expr_Tanh.hxx>
#include <Expr_UnaryFunction.hxx>
#include <Expr_UnaryMinus.hxx>
#include <Expr_BinaryExpression.hxx>
#include <Expr_BinaryFunction.hxx>
#include <Expr_Difference.hxx>
#include <Expr_Division.hxx>
#include <Expr_Exponentiate.hxx>
#include <Expr_PolyExpression.hxx>
#include <Expr_PolyFunction.hxx>
#include <Expr_Product.hxx>
#include <Expr_Sum.hxx>
#include <Expr_UnknownIterator.hxx>
#include <Expr_SingleRelation.hxx>
#include <Expr_Different.hxx>
#include <Expr_Equal.hxx>
#include <Expr_GreaterThan.hxx>
#include <Expr_GreaterThanOrEqual.hxx>
#include <Expr_LessThan.hxx>
#include <Expr_LessThanOrEqual.hxx>
#include <Expr_SystemRelation.hxx>
#include <Expr_RelationIterator.hxx>
#include <Expr_RUIterator.hxx>
#include <Expr_GeneralFunction.hxx>
#include <Expr_NamedFunction.hxx>
#include <Expr_FunctionDerivative.hxx>
#include <Expr.hxx>

void bind_Expr(py::module &mod){

py::class_<Expr, std::unique_ptr<Expr, Deleter<Expr>>> cls_Expr(mod, "Expr", "This package describes the data structure of any expression, relation or function used in mathematics. It also describes the assignment of variables. Standard mathematical functions are implemented such as trigonometrics, hyperbolics, and log functions.");

// Constructors

// Fields

// Methods
// cls_Expr.def_static("operator new_", (void * (*)(size_t)) &Expr::operator new, "None", py::arg("theSize"));
// cls_Expr.def_static("operator delete_", (void (*)(void *)) &Expr::operator delete, "None", py::arg("theAddress"));
// cls_Expr.def_static("operator new[]_", (void * (*)(size_t)) &Expr::operator new[], "None", py::arg("theSize"));
// cls_Expr.def_static("operator delete[]_", (void (*)(void *)) &Expr::operator delete[], "None", py::arg("theAddress"));
// cls_Expr.def_static("operator new_", (void * (*)(size_t, void *)) &Expr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr.def_static("operator delete_", (void (*)(void *, void *)) &Expr::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr.def_static("CopyShare_", (opencascade::handle<Expr_GeneralExpression> (*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr::CopyShare, "None", py::arg("exp"));
cls_Expr.def_static("NbOfFreeVariables_", (Standard_Integer (*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr::NbOfFreeVariables, "None", py::arg("exp"));
cls_Expr.def_static("NbOfFreeVariables_", (Standard_Integer (*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr::NbOfFreeVariables, "None", py::arg("exp"));
cls_Expr.def_static("Sign_", (Standard_Real (*)(const Standard_Real)) &Expr::Sign, "None", py::arg("val"));

// Enums

}