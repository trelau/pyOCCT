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

void bind_Expr(py::module &);
void bind_Expr_Array1OfNamedUnknown(py::module &);
void bind_Expr_GeneralExpression(py::module &);
void bind_Expr_GeneralRelation(py::module &);
void bind_Expr_GeneralFunction(py::module &);
void bind_Expr_NamedFunction(py::module &);
void bind_Expr_NamedExpression(py::module &);
void bind_Expr_UnaryExpression(py::module &);
void bind_Expr_Absolute(py::module &);
void bind_Expr_ArcCosine(py::module &);
void bind_Expr_ArcSine(py::module &);
void bind_Expr_ArcTangent(py::module &);
void bind_Expr_ArgCosh(py::module &);
void bind_Expr_ArgSinh(py::module &);
void bind_Expr_ArgTanh(py::module &);
void bind_Expr_Array1OfGeneralExpression(py::module &);
void bind_Expr_SingleRelation(py::module &);
void bind_Expr_Array1OfSingleRelation(py::module &);
void bind_Expr_BinaryExpression(py::module &);
void bind_Expr_BinaryFunction(py::module &);
void bind_Expr_Cosh(py::module &);
void bind_Expr_Cosine(py::module &);
void bind_Expr_Difference(py::module &);
void bind_Expr_Different(py::module &);
void bind_Expr_Division(py::module &);
void bind_Expr_Equal(py::module &);
void bind_Expr_Exponential(py::module &);
void bind_Expr_Exponentiate(py::module &);
void bind_Expr_ExprFailure(py::module &);
void bind_Expr_FunctionDerivative(py::module &);
void bind_Expr_GreaterThan(py::module &);
void bind_Expr_GreaterThanOrEqual(py::module &);
void bind_Expr_InvalidAssignment(py::module &);
void bind_Expr_InvalidFunction(py::module &);
void bind_Expr_InvalidOperand(py::module &);
void bind_Expr_LessThan(py::module &);
void bind_Expr_LessThanOrEqual(py::module &);
void bind_Expr_LogOf10(py::module &);
void bind_Expr_LogOfe(py::module &);
void bind_Expr_NamedUnknown(py::module &);
void bind_Expr_MapOfNamedUnknown(py::module &);
void bind_Expr_NamedConstant(py::module &);
void bind_Expr_NotAssigned(py::module &);
void bind_Expr_NotEvaluable(py::module &);
void bind_Expr_NumericValue(py::module &);
void bind_Expr_SequenceOfGeneralExpression(py::module &);
void bind_Expr_PolyExpression(py::module &);
void bind_Expr_Sum(py::module &);
void bind_Expr_UnaryMinus(py::module &);
void bind_Expr_Product(py::module &);
void bind_Expr_PolyFunction(py::module &);
void bind_Expr_RelationIterator(py::module &);
void bind_Expr_RUIterator(py::module &);
void bind_Expr_SequenceOfGeneralRelation(py::module &);
void bind_Expr_Sign(py::module &);
void bind_Expr_Sine(py::module &);
void bind_Expr_Sinh(py::module &);
void bind_Expr_Square(py::module &);
void bind_Expr_SquareRoot(py::module &);
void bind_Expr_SystemRelation(py::module &);
void bind_Expr_Tangent(py::module &);
void bind_Expr_Tanh(py::module &);
void bind_Expr_UnaryFunction(py::module &);
void bind_Expr_UnknownIterator(py::module &);

PYBIND11_MODULE(Expr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");

bind_Expr(mod);
bind_Expr_Array1OfNamedUnknown(mod);
bind_Expr_GeneralExpression(mod);
bind_Expr_GeneralRelation(mod);
bind_Expr_GeneralFunction(mod);
bind_Expr_NamedFunction(mod);
bind_Expr_NamedExpression(mod);
bind_Expr_UnaryExpression(mod);
bind_Expr_Absolute(mod);
bind_Expr_ArcCosine(mod);
bind_Expr_ArcSine(mod);
bind_Expr_ArcTangent(mod);
bind_Expr_ArgCosh(mod);
bind_Expr_ArgSinh(mod);
bind_Expr_ArgTanh(mod);
bind_Expr_Array1OfGeneralExpression(mod);
bind_Expr_SingleRelation(mod);
bind_Expr_Array1OfSingleRelation(mod);
bind_Expr_BinaryExpression(mod);
bind_Expr_BinaryFunction(mod);
bind_Expr_Cosh(mod);
bind_Expr_Cosine(mod);
bind_Expr_Difference(mod);
bind_Expr_Different(mod);
bind_Expr_Division(mod);
bind_Expr_Equal(mod);
bind_Expr_Exponential(mod);
bind_Expr_Exponentiate(mod);
bind_Expr_ExprFailure(mod);
bind_Expr_FunctionDerivative(mod);
bind_Expr_GreaterThan(mod);
bind_Expr_GreaterThanOrEqual(mod);
bind_Expr_InvalidAssignment(mod);
bind_Expr_InvalidFunction(mod);
bind_Expr_InvalidOperand(mod);
bind_Expr_LessThan(mod);
bind_Expr_LessThanOrEqual(mod);
bind_Expr_LogOf10(mod);
bind_Expr_LogOfe(mod);
bind_Expr_NamedUnknown(mod);
bind_Expr_MapOfNamedUnknown(mod);
bind_Expr_NamedConstant(mod);
bind_Expr_NotAssigned(mod);
bind_Expr_NotEvaluable(mod);
bind_Expr_NumericValue(mod);
bind_Expr_SequenceOfGeneralExpression(mod);
bind_Expr_PolyExpression(mod);
bind_Expr_Sum(mod);
bind_Expr_UnaryMinus(mod);
bind_Expr_Product(mod);
bind_Expr_PolyFunction(mod);
bind_Expr_RelationIterator(mod);
bind_Expr_RUIterator(mod);
bind_Expr_SequenceOfGeneralRelation(mod);
bind_Expr_Sign(mod);
bind_Expr_Sine(mod);
bind_Expr_Sinh(mod);
bind_Expr_Square(mod);
bind_Expr_SquareRoot(mod);
bind_Expr_SystemRelation(mod);
bind_Expr_Tangent(mod);
bind_Expr_Tanh(mod);
bind_Expr_UnaryFunction(mod);
bind_Expr_UnknownIterator(mod);

}
