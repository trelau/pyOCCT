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
#include <NCollection_Array1.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Expr_Array1OfGeneralExpression.hxx>
#include <Expr_Array1OfSingleRelation.hxx>
#include <Standard_Failure.hxx>
#include <Expr_ExprFailure.hxx>
#include <Standard_SStream.hxx>
#include <Expr_InvalidAssignment.hxx>
#include <Expr_InvalidFunction.hxx>
#include <Expr_InvalidOperand.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <Expr_MapOfNamedUnknown.hxx>
#include <Expr_NotAssigned.hxx>
#include <Expr_NotEvaluable.hxx>
#include <NCollection_Sequence.hxx>
#include <Expr_SequenceOfGeneralExpression.hxx>
#include <Expr_SequenceOfGeneralRelation.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_IndexedMap.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(Expr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");

// CLASS: EXPR
py::class_<Expr> cls_Expr(mod, "Expr", "This package describes the data structure of any expression, relation or function used in mathematics. It also describes the assignment of variables. Standard mathematical functions are implemented such as trigonometrics, hyperbolics, and log functions.");

// Constructors
cls_Expr.def(py::init<>());

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

// TYPEDEF: EXPR_ARRAY1OFNAMEDUNKNOWN
bind_NCollection_Array1<opencascade::handle<Expr_NamedUnknown> >(mod, "Expr_Array1OfNamedUnknown", py::module_local(false));

// CLASS: EXPR_GENERALEXPRESSION
py::class_<Expr_GeneralExpression, opencascade::handle<Expr_GeneralExpression>, Standard_Transient> cls_Expr_GeneralExpression(mod, "Expr_GeneralExpression", "Defines the general purposes of any expression.");

// Methods
cls_Expr_GeneralExpression.def("NbSubExpressions", (Standard_Integer (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_GeneralExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_GeneralExpression::*)(const Standard_Integer) const) &Expr_GeneralExpression::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_GeneralExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_GeneralExpression.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_GeneralExpression.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GeneralExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::ContainsUnknowns, "Tests if <me> contains NamedUnknowns.");
cls_Expr_GeneralExpression.def("Contains", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_GeneralExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_GeneralExpression.def("IsLinear", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::IsLinear, "Tests if <me> is linear on every NamedUnknown it contains.");
cls_Expr_GeneralExpression.def("IsShareable", (Standard_Boolean (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method returns False as a default value. To be redefined ( especially for NamedUnknown).");
cls_Expr_GeneralExpression.def("IsIdentical", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_GeneralExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. Warning: This method does not include any simplification before testing. It could also be very slow; to be used carefully.", py::arg("Other"));
cls_Expr_GeneralExpression.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_GeneralExpression::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_GeneralExpression.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_GeneralExpression::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raise OutOfRange if N <= 0", py::arg("X"), py::arg("N"));
cls_Expr_GeneralExpression.def("Replace", (void (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_GeneralExpression::Replace, "Replaces all occurences of <var> with copies of <with> in <me>. Copies of <with> are made with the Copy() method. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_GeneralExpression.def("Evaluate", (Standard_Real (Expr_GeneralExpression::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_GeneralExpression::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_GeneralExpression.def("EvaluateNumeric", (Standard_Real (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::EvaluateNumeric, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.");
cls_Expr_GeneralExpression.def("String", (TCollection_AsciiString (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::String, "returns a string representing <me> in a readable way.");
cls_Expr_GeneralExpression.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralExpression::get_type_name, "None");
cls_Expr_GeneralExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralExpression::get_type_descriptor, "None");
cls_Expr_GeneralExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralExpression::*)() const) &Expr_GeneralExpression::DynamicType, "None");

// CLASS: EXPR_GENERALRELATION
py::class_<Expr_GeneralRelation, opencascade::handle<Expr_GeneralRelation>, Standard_Transient> cls_Expr_GeneralRelation(mod, "Expr_GeneralRelation", "Defines the general purposes of any relation between expressions.");

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

// CLASS: EXPR_GENERALFUNCTION
py::class_<Expr_GeneralFunction, opencascade::handle<Expr_GeneralFunction>, Standard_Transient> cls_Expr_GeneralFunction(mod, "Expr_GeneralFunction", "Defines the general purposes of any function.");

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

// CLASS: EXPR_NAMEDFUNCTION
py::class_<Expr_NamedFunction, opencascade::handle<Expr_NamedFunction>, Expr_GeneralFunction> cls_Expr_NamedFunction(mod, "Expr_NamedFunction", "None");

// Constructors
cls_Expr_NamedFunction.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Expr_GeneralExpression> &, const Expr_Array1OfNamedUnknown &>(), py::arg("name"), py::arg("exp"), py::arg("vars"));

// Methods
cls_Expr_NamedFunction.def("SetName", (void (Expr_NamedFunction::*)(const TCollection_AsciiString &)) &Expr_NamedFunction::SetName, "Sets the name <newname> to <me>.", py::arg("newname"));
cls_Expr_NamedFunction.def("GetName", (TCollection_AsciiString (Expr_NamedFunction::*)() const) &Expr_NamedFunction::GetName, "Returns the name assigned to <me>");
cls_Expr_NamedFunction.def("NbOfVariables", (Standard_Integer (Expr_NamedFunction::*)() const) &Expr_NamedFunction::NbOfVariables, "Returns the number of variables of <me>.");
cls_Expr_NamedFunction.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_NamedFunction::*)(const Standard_Integer) const) &Expr_NamedFunction::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> is greater than NbOfVariables of <me>, or less than or equal to zero.", py::arg("index"));
cls_Expr_NamedFunction.def("Evaluate", (Standard_Real (Expr_NamedFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedFunction::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
cls_Expr_NamedFunction.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)() const) &Expr_NamedFunction::Copy, "Returns a copy of <me> with the same form.");
cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
cls_Expr_NamedFunction.def("IsIdentical", (Standard_Boolean (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralFunction> &) const) &Expr_NamedFunction::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
cls_Expr_NamedFunction.def("IsLinearOnVariable", (Standard_Boolean (Expr_NamedFunction::*)(const Standard_Integer) const) &Expr_NamedFunction::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
cls_Expr_NamedFunction.def("GetStringName", (TCollection_AsciiString (Expr_NamedFunction::*)() const) &Expr_NamedFunction::GetStringName, "None");
cls_Expr_NamedFunction.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedFunction::*)() const) &Expr_NamedFunction::Expression, "Returns equivalent expression of <me>.");
cls_Expr_NamedFunction.def("SetExpression", (void (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedFunction::SetExpression, "Modifies expression of <me>. Warning: Beware of derivatives. See FunctionDerivative", py::arg("exp"));
cls_Expr_NamedFunction.def_static("get_type_name_", (const char * (*)()) &Expr_NamedFunction::get_type_name, "None");
cls_Expr_NamedFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedFunction::get_type_descriptor, "None");
cls_Expr_NamedFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedFunction::*)() const) &Expr_NamedFunction::DynamicType, "None");

// CLASS: EXPR_NAMEDEXPRESSION
py::class_<Expr_NamedExpression, opencascade::handle<Expr_NamedExpression>, Expr_GeneralExpression> cls_Expr_NamedExpression(mod, "Expr_NamedExpression", "Describe an expression used by its name (as constants or variables). A single reference is made to a NamedExpression in every Expression (i.e. a NamedExpression is shared).");

// Methods
cls_Expr_NamedExpression.def("GetName", (const TCollection_AsciiString & (Expr_NamedExpression::*)() const) &Expr_NamedExpression::GetName, "None");
cls_Expr_NamedExpression.def("SetName", (void (Expr_NamedExpression::*)(const TCollection_AsciiString &)) &Expr_NamedExpression::SetName, "None", py::arg("name"));
cls_Expr_NamedExpression.def("IsShareable", (Standard_Boolean (Expr_NamedExpression::*)() const) &Expr_NamedExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method redefines to a True value the GeneralExpression method.");
cls_Expr_NamedExpression.def("IsIdentical", (Standard_Boolean (Expr_NamedExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_NamedExpression.def("String", (TCollection_AsciiString (Expr_NamedExpression::*)() const) &Expr_NamedExpression::String, "returns a string representing <me> in a readable way.");
cls_Expr_NamedExpression.def_static("get_type_name_", (const char * (*)()) &Expr_NamedExpression::get_type_name, "None");
cls_Expr_NamedExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedExpression::get_type_descriptor, "None");
cls_Expr_NamedExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedExpression::*)() const) &Expr_NamedExpression::DynamicType, "None");

// CLASS: EXPR_UNARYEXPRESSION
py::class_<Expr_UnaryExpression, opencascade::handle<Expr_UnaryExpression>, Expr_GeneralExpression> cls_Expr_UnaryExpression(mod, "Expr_UnaryExpression", "None");

// Methods
cls_Expr_UnaryExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::Operand, "Returns the operand used");
cls_Expr_UnaryExpression.def("SetOperand", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::SetOperand, "Sets the operand used Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
cls_Expr_UnaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_UnaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)(const Standard_Integer) const) &Expr_UnaryExpression::SubExpression, "Returns the <I>-th sub-expression of <me>. Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_UnaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
cls_Expr_UnaryExpression.def("Contains", (Standard_Boolean (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_UnaryExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_UnaryExpression.def("Replace", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_UnaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_UnaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryExpression::get_type_name, "None");
cls_Expr_UnaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryExpression::get_type_descriptor, "None");
cls_Expr_UnaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryExpression::*)() const) &Expr_UnaryExpression::DynamicType, "None");

// CLASS: EXPR_ABSOLUTE
py::class_<Expr_Absolute, opencascade::handle<Expr_Absolute>, Expr_UnaryExpression> cls_Expr_Absolute(mod, "Expr_Absolute", "None");

// Constructors
cls_Expr_Absolute.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Absolute.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)() const) &Expr_Absolute::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Absolute.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)() const) &Expr_Absolute::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Absolute.def("IsIdentical", (Standard_Boolean (Expr_Absolute::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Absolute::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Absolute.def("IsLinear", (Standard_Boolean (Expr_Absolute::*)() const) &Expr_Absolute::IsLinear, "None");
cls_Expr_Absolute.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Absolute::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Absolute.def("Evaluate", (Standard_Real (Expr_Absolute::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Absolute::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Absolute.def("String", (TCollection_AsciiString (Expr_Absolute::*)() const) &Expr_Absolute::String, "returns a string representing <me> in a readable way.");
cls_Expr_Absolute.def_static("get_type_name_", (const char * (*)()) &Expr_Absolute::get_type_name, "None");
cls_Expr_Absolute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Absolute::get_type_descriptor, "None");
cls_Expr_Absolute.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Absolute::*)() const) &Expr_Absolute::DynamicType, "None");

// CLASS: EXPR_ARCCOSINE
py::class_<Expr_ArcCosine, opencascade::handle<Expr_ArcCosine>, Expr_UnaryExpression> cls_Expr_ArcCosine(mod, "Expr_ArcCosine", "None");

// Constructors
cls_Expr_ArcCosine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArcCosine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)() const) &Expr_ArcCosine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArcCosine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)() const) &Expr_ArcCosine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArcCosine.def("IsIdentical", (Standard_Boolean (Expr_ArcCosine::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArcCosine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArcCosine.def("IsLinear", (Standard_Boolean (Expr_ArcCosine::*)() const) &Expr_ArcCosine::IsLinear, "None");
cls_Expr_ArcCosine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArcCosine::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArcCosine.def("Evaluate", (Standard_Real (Expr_ArcCosine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArcCosine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArcCosine.def("String", (TCollection_AsciiString (Expr_ArcCosine::*)() const) &Expr_ArcCosine::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArcCosine.def_static("get_type_name_", (const char * (*)()) &Expr_ArcCosine::get_type_name, "None");
cls_Expr_ArcCosine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcCosine::get_type_descriptor, "None");
cls_Expr_ArcCosine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcCosine::*)() const) &Expr_ArcCosine::DynamicType, "None");

// CLASS: EXPR_ARCSINE
py::class_<Expr_ArcSine, opencascade::handle<Expr_ArcSine>, Expr_UnaryExpression> cls_Expr_ArcSine(mod, "Expr_ArcSine", "None");

// Constructors
cls_Expr_ArcSine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArcSine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)() const) &Expr_ArcSine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArcSine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)() const) &Expr_ArcSine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArcSine.def("IsIdentical", (Standard_Boolean (Expr_ArcSine::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArcSine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArcSine.def("IsLinear", (Standard_Boolean (Expr_ArcSine::*)() const) &Expr_ArcSine::IsLinear, "None");
cls_Expr_ArcSine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArcSine::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArcSine.def("Evaluate", (Standard_Real (Expr_ArcSine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArcSine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArcSine.def("String", (TCollection_AsciiString (Expr_ArcSine::*)() const) &Expr_ArcSine::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArcSine.def_static("get_type_name_", (const char * (*)()) &Expr_ArcSine::get_type_name, "None");
cls_Expr_ArcSine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcSine::get_type_descriptor, "None");
cls_Expr_ArcSine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcSine::*)() const) &Expr_ArcSine::DynamicType, "None");

// CLASS: EXPR_ARCTANGENT
py::class_<Expr_ArcTangent, opencascade::handle<Expr_ArcTangent>, Expr_UnaryExpression> cls_Expr_ArcTangent(mod, "Expr_ArcTangent", "None");

// Constructors
cls_Expr_ArcTangent.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArcTangent.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)() const) &Expr_ArcTangent::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArcTangent.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)() const) &Expr_ArcTangent::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArcTangent.def("IsIdentical", (Standard_Boolean (Expr_ArcTangent::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArcTangent::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArcTangent.def("IsLinear", (Standard_Boolean (Expr_ArcTangent::*)() const) &Expr_ArcTangent::IsLinear, "None");
cls_Expr_ArcTangent.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArcTangent::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArcTangent.def("Evaluate", (Standard_Real (Expr_ArcTangent::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArcTangent::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArcTangent.def("String", (TCollection_AsciiString (Expr_ArcTangent::*)() const) &Expr_ArcTangent::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArcTangent.def_static("get_type_name_", (const char * (*)()) &Expr_ArcTangent::get_type_name, "None");
cls_Expr_ArcTangent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcTangent::get_type_descriptor, "None");
cls_Expr_ArcTangent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcTangent::*)() const) &Expr_ArcTangent::DynamicType, "None");

// CLASS: EXPR_ARGCOSH
py::class_<Expr_ArgCosh, opencascade::handle<Expr_ArgCosh>, Expr_UnaryExpression> cls_Expr_ArgCosh(mod, "Expr_ArgCosh", "None");

// Constructors
cls_Expr_ArgCosh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArgCosh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)() const) &Expr_ArgCosh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArgCosh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)() const) &Expr_ArgCosh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArgCosh.def("IsIdentical", (Standard_Boolean (Expr_ArgCosh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArgCosh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArgCosh.def("IsLinear", (Standard_Boolean (Expr_ArgCosh::*)() const) &Expr_ArgCosh::IsLinear, "None");
cls_Expr_ArgCosh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArgCosh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArgCosh.def("Evaluate", (Standard_Real (Expr_ArgCosh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArgCosh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArgCosh.def("String", (TCollection_AsciiString (Expr_ArgCosh::*)() const) &Expr_ArgCosh::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArgCosh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgCosh::get_type_name, "None");
cls_Expr_ArgCosh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgCosh::get_type_descriptor, "None");
cls_Expr_ArgCosh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgCosh::*)() const) &Expr_ArgCosh::DynamicType, "None");

// CLASS: EXPR_ARGSINH
py::class_<Expr_ArgSinh, opencascade::handle<Expr_ArgSinh>, Expr_UnaryExpression> cls_Expr_ArgSinh(mod, "Expr_ArgSinh", "None");

// Constructors
cls_Expr_ArgSinh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArgSinh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)() const) &Expr_ArgSinh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArgSinh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)() const) &Expr_ArgSinh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArgSinh.def("IsIdentical", (Standard_Boolean (Expr_ArgSinh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArgSinh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArgSinh.def("IsLinear", (Standard_Boolean (Expr_ArgSinh::*)() const) &Expr_ArgSinh::IsLinear, "None");
cls_Expr_ArgSinh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArgSinh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArgSinh.def("Evaluate", (Standard_Real (Expr_ArgSinh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArgSinh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArgSinh.def("String", (TCollection_AsciiString (Expr_ArgSinh::*)() const) &Expr_ArgSinh::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArgSinh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgSinh::get_type_name, "None");
cls_Expr_ArgSinh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgSinh::get_type_descriptor, "None");
cls_Expr_ArgSinh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgSinh::*)() const) &Expr_ArgSinh::DynamicType, "None");

// CLASS: EXPR_ARGTANH
py::class_<Expr_ArgTanh, opencascade::handle<Expr_ArgTanh>, Expr_UnaryExpression> cls_Expr_ArgTanh(mod, "Expr_ArgTanh", "None");

// Constructors
cls_Expr_ArgTanh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_ArgTanh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)() const) &Expr_ArgTanh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_ArgTanh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)() const) &Expr_ArgTanh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_ArgTanh.def("IsIdentical", (Standard_Boolean (Expr_ArgTanh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_ArgTanh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_ArgTanh.def("IsLinear", (Standard_Boolean (Expr_ArgTanh::*)() const) &Expr_ArgTanh::IsLinear, "None");
cls_Expr_ArgTanh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_ArgTanh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_ArgTanh.def("Evaluate", (Standard_Real (Expr_ArgTanh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_ArgTanh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_ArgTanh.def("String", (TCollection_AsciiString (Expr_ArgTanh::*)() const) &Expr_ArgTanh::String, "returns a string representing <me> in a readable way.");
cls_Expr_ArgTanh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgTanh::get_type_name, "None");
cls_Expr_ArgTanh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgTanh::get_type_descriptor, "None");
cls_Expr_ArgTanh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgTanh::*)() const) &Expr_ArgTanh::DynamicType, "None");

// TYPEDEF: EXPR_ARRAY1OFGENERALEXPRESSION
bind_NCollection_Array1<opencascade::handle<Expr_GeneralExpression> >(mod, "Expr_Array1OfGeneralExpression", py::module_local(false));

// CLASS: EXPR_SINGLERELATION
py::class_<Expr_SingleRelation, opencascade::handle<Expr_SingleRelation>, Expr_GeneralRelation> cls_Expr_SingleRelation(mod, "Expr_SingleRelation", "None");

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

// TYPEDEF: EXPR_ARRAY1OFSINGLERELATION
bind_NCollection_Array1<opencascade::handle<Expr_SingleRelation> >(mod, "Expr_Array1OfSingleRelation", py::module_local(false));

// CLASS: EXPR_BINARYEXPRESSION
py::class_<Expr_BinaryExpression, opencascade::handle<Expr_BinaryExpression>, Expr_GeneralExpression> cls_Expr_BinaryExpression(mod, "Expr_BinaryExpression", "Defines all binary expressions. The order of the two operands is significant.");

// Methods
cls_Expr_BinaryExpression.def("FirstOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::FirstOperand, "None");
cls_Expr_BinaryExpression.def("SecondOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::SecondOperand, "None");
cls_Expr_BinaryExpression.def("SetFirstOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetFirstOperand, "Sets first operand of <me> Raises InvalidOperand if exp = me", py::arg("exp"));
cls_Expr_BinaryExpression.def("SetSecondOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetSecondOperand, "Sets second operand of <me> Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
cls_Expr_BinaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_BinaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)(const Standard_Integer) const) &Expr_BinaryExpression::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_BinaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::ContainsUnknowns, "Does <me> contain NamedUnknown ?");
cls_Expr_BinaryExpression.def("Contains", (Standard_Boolean (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_BinaryExpression::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
cls_Expr_BinaryExpression.def("Replace", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me>. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_BinaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_BinaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_BinaryExpression::get_type_name, "None");
cls_Expr_BinaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_BinaryExpression::get_type_descriptor, "None");
cls_Expr_BinaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_BinaryExpression::*)() const) &Expr_BinaryExpression::DynamicType, "None");

// CLASS: EXPR_BINARYFUNCTION
py::class_<Expr_BinaryFunction, opencascade::handle<Expr_BinaryFunction>, Expr_BinaryExpression> cls_Expr_BinaryFunction(mod, "Expr_BinaryFunction", "Defines the use of a binary function in an expression with given arguments.");

// Constructors
cls_Expr_BinaryFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("func"), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_BinaryFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::Function, "Returns the function defining <me>.");
cls_Expr_BinaryFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_BinaryFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_BinaryFunction.def("IsIdentical", (Standard_Boolean (Expr_BinaryFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_BinaryFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_BinaryFunction.def("IsLinear", (Standard_Boolean (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::IsLinear, "None");
cls_Expr_BinaryFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_BinaryFunction::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_BinaryFunction.def("Evaluate", (Standard_Real (Expr_BinaryFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_BinaryFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_BinaryFunction.def("String", (TCollection_AsciiString (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::String, "returns a string representing <me> in a readable way.");
cls_Expr_BinaryFunction.def_static("get_type_name_", (const char * (*)()) &Expr_BinaryFunction::get_type_name, "None");
cls_Expr_BinaryFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_BinaryFunction::get_type_descriptor, "None");
cls_Expr_BinaryFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_BinaryFunction::*)() const) &Expr_BinaryFunction::DynamicType, "None");

// CLASS: EXPR_COSH
py::class_<Expr_Cosh, opencascade::handle<Expr_Cosh>, Expr_UnaryExpression> cls_Expr_Cosh(mod, "Expr_Cosh", "None");

// Constructors
cls_Expr_Cosh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Cosh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)() const) &Expr_Cosh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Cosh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)() const) &Expr_Cosh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Cosh.def("IsIdentical", (Standard_Boolean (Expr_Cosh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Cosh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Cosh.def("IsLinear", (Standard_Boolean (Expr_Cosh::*)() const) &Expr_Cosh::IsLinear, "None");
cls_Expr_Cosh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Cosh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Cosh.def("Evaluate", (Standard_Real (Expr_Cosh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Cosh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Cosh.def("String", (TCollection_AsciiString (Expr_Cosh::*)() const) &Expr_Cosh::String, "returns a string representing <me> in a readable way.");
cls_Expr_Cosh.def_static("get_type_name_", (const char * (*)()) &Expr_Cosh::get_type_name, "None");
cls_Expr_Cosh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Cosh::get_type_descriptor, "None");
cls_Expr_Cosh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Cosh::*)() const) &Expr_Cosh::DynamicType, "None");

// CLASS: EXPR_COSINE
py::class_<Expr_Cosine, opencascade::handle<Expr_Cosine>, Expr_UnaryExpression> cls_Expr_Cosine(mod, "Expr_Cosine", "None");

// Constructors
cls_Expr_Cosine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("Exp"));

// Methods
cls_Expr_Cosine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)() const) &Expr_Cosine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Cosine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)() const) &Expr_Cosine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Cosine.def("IsIdentical", (Standard_Boolean (Expr_Cosine::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Cosine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Cosine.def("IsLinear", (Standard_Boolean (Expr_Cosine::*)() const) &Expr_Cosine::IsLinear, "None");
cls_Expr_Cosine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Cosine::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Cosine.def("Evaluate", (Standard_Real (Expr_Cosine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Cosine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Cosine.def("String", (TCollection_AsciiString (Expr_Cosine::*)() const) &Expr_Cosine::String, "returns a string representing <me> in a readable way.");
cls_Expr_Cosine.def_static("get_type_name_", (const char * (*)()) &Expr_Cosine::get_type_name, "None");
cls_Expr_Cosine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Cosine::get_type_descriptor, "None");
cls_Expr_Cosine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Cosine::*)() const) &Expr_Cosine::DynamicType, "None");

// CLASS: EXPR_DIFFERENCE
py::class_<Expr_Difference, opencascade::handle<Expr_Difference>, Expr_BinaryExpression> cls_Expr_Difference(mod, "Expr_Difference", "None");

// Constructors
cls_Expr_Difference.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Difference.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)() const) &Expr_Difference::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Difference.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)() const) &Expr_Difference::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Difference.def("IsIdentical", (Standard_Boolean (Expr_Difference::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Difference::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Difference.def("IsLinear", (Standard_Boolean (Expr_Difference::*)() const) &Expr_Difference::IsLinear, "None");
cls_Expr_Difference.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Difference::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Difference.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_Difference::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_Difference.def("Evaluate", (Standard_Real (Expr_Difference::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Difference::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Difference.def("String", (TCollection_AsciiString (Expr_Difference::*)() const) &Expr_Difference::String, "returns a string representing <me> in a readable way.");
cls_Expr_Difference.def_static("get_type_name_", (const char * (*)()) &Expr_Difference::get_type_name, "None");
cls_Expr_Difference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Difference::get_type_descriptor, "None");
cls_Expr_Difference.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Difference::*)() const) &Expr_Difference::DynamicType, "None");

// CLASS: EXPR_DIFFERENT
py::class_<Expr_Different, opencascade::handle<Expr_Different>, Expr_SingleRelation> cls_Expr_Different(mod, "Expr_Different", "None");

// Constructors
cls_Expr_Different.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Different.def("IsSatisfied", (Standard_Boolean (Expr_Different::*)() const) &Expr_Different::IsSatisfied, "None");
cls_Expr_Different.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const) &Expr_Different::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_Different.def("Simplify", (void (Expr_Different::*)()) &Expr_Different::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_Different.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const) &Expr_Different::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Different.def("String", (TCollection_AsciiString (Expr_Different::*)() const) &Expr_Different::String, "returns a string representing <me> in a readable way.");
cls_Expr_Different.def_static("get_type_name_", (const char * (*)()) &Expr_Different::get_type_name, "None");
cls_Expr_Different.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Different::get_type_descriptor, "None");
cls_Expr_Different.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Different::*)() const) &Expr_Different::DynamicType, "None");

// CLASS: EXPR_DIVISION
py::class_<Expr_Division, opencascade::handle<Expr_Division>, Expr_BinaryExpression> cls_Expr_Division(mod, "Expr_Division", "None");

// Constructors
cls_Expr_Division.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Division.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const) &Expr_Division::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Division.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const) &Expr_Division::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Division.def("IsIdentical", (Standard_Boolean (Expr_Division::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Division::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Division.def("IsLinear", (Standard_Boolean (Expr_Division::*)() const) &Expr_Division::IsLinear, "None");
cls_Expr_Division.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Division::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Division.def("Evaluate", (Standard_Real (Expr_Division::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Division::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Division.def("String", (TCollection_AsciiString (Expr_Division::*)() const) &Expr_Division::String, "returns a string representing <me> in a readable way.");
cls_Expr_Division.def_static("get_type_name_", (const char * (*)()) &Expr_Division::get_type_name, "None");
cls_Expr_Division.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Division::get_type_descriptor, "None");
cls_Expr_Division.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Division::*)() const) &Expr_Division::DynamicType, "None");

// CLASS: EXPR_EQUAL
py::class_<Expr_Equal, opencascade::handle<Expr_Equal>, Expr_SingleRelation> cls_Expr_Equal(mod, "Expr_Equal", "None");

// Constructors
cls_Expr_Equal.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Equal.def("IsSatisfied", (Standard_Boolean (Expr_Equal::*)() const) &Expr_Equal::IsSatisfied, "None");
cls_Expr_Equal.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_Equal::*)() const) &Expr_Equal::Simplified, "returns a GeneralRelation after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_Equal.def("Simplify", (void (Expr_Equal::*)()) &Expr_Equal::Simplify, "Replaces NamedUnknowns by an associated expressions and computes values in <me>.");
cls_Expr_Equal.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_Equal::*)() const) &Expr_Equal::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Equal.def("String", (TCollection_AsciiString (Expr_Equal::*)() const) &Expr_Equal::String, "returns a string representing <me> in a readable way.");
cls_Expr_Equal.def_static("get_type_name_", (const char * (*)()) &Expr_Equal::get_type_name, "None");
cls_Expr_Equal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Equal::get_type_descriptor, "None");
cls_Expr_Equal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Equal::*)() const) &Expr_Equal::DynamicType, "None");

// CLASS: EXPR_EXPONENTIAL
py::class_<Expr_Exponential, opencascade::handle<Expr_Exponential>, Expr_UnaryExpression> cls_Expr_Exponential(mod, "Expr_Exponential", "None");

// Constructors
cls_Expr_Exponential.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Exponential.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)() const) &Expr_Exponential::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Exponential.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)() const) &Expr_Exponential::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Exponential.def("IsIdentical", (Standard_Boolean (Expr_Exponential::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Exponential::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Exponential.def("IsLinear", (Standard_Boolean (Expr_Exponential::*)() const) &Expr_Exponential::IsLinear, "None");
cls_Expr_Exponential.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Exponential::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Exponential.def("Evaluate", (Standard_Real (Expr_Exponential::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Exponential::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Exponential.def("String", (TCollection_AsciiString (Expr_Exponential::*)() const) &Expr_Exponential::String, "returns a string representing <me> in a readable way.");
cls_Expr_Exponential.def_static("get_type_name_", (const char * (*)()) &Expr_Exponential::get_type_name, "None");
cls_Expr_Exponential.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Exponential::get_type_descriptor, "None");
cls_Expr_Exponential.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Exponential::*)() const) &Expr_Exponential::DynamicType, "None");

// CLASS: EXPR_EXPONENTIATE
py::class_<Expr_Exponentiate, opencascade::handle<Expr_Exponentiate>, Expr_BinaryExpression> cls_Expr_Exponentiate(mod, "Expr_Exponentiate", "None");

// Constructors
cls_Expr_Exponentiate.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Exponentiate.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)() const) &Expr_Exponentiate::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Exponentiate.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)() const) &Expr_Exponentiate::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Exponentiate.def("IsIdentical", (Standard_Boolean (Expr_Exponentiate::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Exponentiate::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Exponentiate.def("IsLinear", (Standard_Boolean (Expr_Exponentiate::*)() const) &Expr_Exponentiate::IsLinear, "None");
cls_Expr_Exponentiate.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Exponentiate::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Exponentiate.def("Evaluate", (Standard_Real (Expr_Exponentiate::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Exponentiate::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Exponentiate.def("String", (TCollection_AsciiString (Expr_Exponentiate::*)() const) &Expr_Exponentiate::String, "returns a string representing <me> in a readable way.");
cls_Expr_Exponentiate.def_static("get_type_name_", (const char * (*)()) &Expr_Exponentiate::get_type_name, "None");
cls_Expr_Exponentiate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Exponentiate::get_type_descriptor, "None");
cls_Expr_Exponentiate.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Exponentiate::*)() const) &Expr_Exponentiate::DynamicType, "None");

// CLASS: EXPR_EXPRFAILURE
py::class_<Expr_ExprFailure, opencascade::handle<Expr_ExprFailure>, Standard_Failure> cls_Expr_ExprFailure(mod, "Expr_ExprFailure", "None");

// Constructors
cls_Expr_ExprFailure.def(py::init<>());
cls_Expr_ExprFailure.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_ExprFailure.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_ExprFailure::Raise, "None", py::arg("theMessage"));
cls_Expr_ExprFailure.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_ExprFailure::Raise, "None", py::arg("theMessage"));
cls_Expr_ExprFailure.def_static("NewInstance_", (opencascade::handle<Expr_ExprFailure> (*)(const Standard_CString)) &Expr_ExprFailure::NewInstance, "None", py::arg("theMessage"));
cls_Expr_ExprFailure.def_static("get_type_name_", (const char * (*)()) &Expr_ExprFailure::get_type_name, "None");
cls_Expr_ExprFailure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ExprFailure::get_type_descriptor, "None");
cls_Expr_ExprFailure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ExprFailure::*)() const) &Expr_ExprFailure::DynamicType, "None");

// CLASS: EXPR_FUNCTIONDERIVATIVE
py::class_<Expr_FunctionDerivative, opencascade::handle<Expr_FunctionDerivative>, Expr_GeneralFunction> cls_Expr_FunctionDerivative(mod, "Expr_FunctionDerivative", "None");

// Constructors
cls_Expr_FunctionDerivative.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer>(), py::arg("func"), py::arg("withX"), py::arg("deg"));

// Methods
cls_Expr_FunctionDerivative.def("NbOfVariables", (Standard_Integer (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::NbOfVariables, "Returns the number of variables of <me>.");
cls_Expr_FunctionDerivative.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)(const Standard_Integer) const) &Expr_FunctionDerivative::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> greater than NbOfVariables of <me>.", py::arg("index"));
cls_Expr_FunctionDerivative.def("Evaluate", (Standard_Real (Expr_FunctionDerivative::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_FunctionDerivative::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
cls_Expr_FunctionDerivative.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Copy, "Returns a copy of <me> with the same form.");
cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
cls_Expr_FunctionDerivative.def("IsIdentical", (Standard_Boolean (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_GeneralFunction> &) const) &Expr_FunctionDerivative::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
cls_Expr_FunctionDerivative.def("IsLinearOnVariable", (Standard_Boolean (Expr_FunctionDerivative::*)(const Standard_Integer) const) &Expr_FunctionDerivative::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
cls_Expr_FunctionDerivative.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Function, "Returns the function of which <me> is the derivative.");
cls_Expr_FunctionDerivative.def("Degree", (Standard_Integer (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Degree, "Returns the degree of derivation of <me>.");
cls_Expr_FunctionDerivative.def("DerivVariable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::DerivVariable, "Returns the derivation variable of <me>.");
cls_Expr_FunctionDerivative.def("GetStringName", (TCollection_AsciiString (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::GetStringName, "None");
cls_Expr_FunctionDerivative.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::Expression, "None");
cls_Expr_FunctionDerivative.def("UpdateExpression", (void (Expr_FunctionDerivative::*)()) &Expr_FunctionDerivative::UpdateExpression, "None");
cls_Expr_FunctionDerivative.def_static("get_type_name_", (const char * (*)()) &Expr_FunctionDerivative::get_type_name, "None");
cls_Expr_FunctionDerivative.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_FunctionDerivative::get_type_descriptor, "None");
cls_Expr_FunctionDerivative.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_FunctionDerivative::*)() const) &Expr_FunctionDerivative::DynamicType, "None");

// CLASS: EXPR_GREATERTHAN
py::class_<Expr_GreaterThan, opencascade::handle<Expr_GreaterThan>, Expr_SingleRelation> cls_Expr_GreaterThan(mod, "Expr_GreaterThan", "None");

// Constructors
cls_Expr_GreaterThan.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_GreaterThan.def("IsSatisfied", (Standard_Boolean (Expr_GreaterThan::*)() const) &Expr_GreaterThan::IsSatisfied, "None");
cls_Expr_GreaterThan.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThan::*)() const) &Expr_GreaterThan::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_GreaterThan.def("Simplify", (void (Expr_GreaterThan::*)()) &Expr_GreaterThan::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_GreaterThan.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThan::*)() const) &Expr_GreaterThan::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GreaterThan.def("String", (TCollection_AsciiString (Expr_GreaterThan::*)() const) &Expr_GreaterThan::String, "returns a string representing <me> in a readable way.");
cls_Expr_GreaterThan.def_static("get_type_name_", (const char * (*)()) &Expr_GreaterThan::get_type_name, "None");
cls_Expr_GreaterThan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GreaterThan::get_type_descriptor, "None");
cls_Expr_GreaterThan.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GreaterThan::*)() const) &Expr_GreaterThan::DynamicType, "None");

// CLASS: EXPR_GREATERTHANOREQUAL
py::class_<Expr_GreaterThanOrEqual, opencascade::handle<Expr_GreaterThanOrEqual>, Expr_SingleRelation> cls_Expr_GreaterThanOrEqual(mod, "Expr_GreaterThanOrEqual", "None");

// Constructors
cls_Expr_GreaterThanOrEqual.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_GreaterThanOrEqual.def("IsSatisfied", (Standard_Boolean (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::IsSatisfied, "None");
cls_Expr_GreaterThanOrEqual.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_GreaterThanOrEqual.def("Simplify", (void (Expr_GreaterThanOrEqual::*)()) &Expr_GreaterThanOrEqual::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_GreaterThanOrEqual.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_GreaterThanOrEqual.def("String", (TCollection_AsciiString (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::String, "returns a string representing <me> in a readable way.");
cls_Expr_GreaterThanOrEqual.def_static("get_type_name_", (const char * (*)()) &Expr_GreaterThanOrEqual::get_type_name, "None");
cls_Expr_GreaterThanOrEqual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GreaterThanOrEqual::get_type_descriptor, "None");
cls_Expr_GreaterThanOrEqual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GreaterThanOrEqual::*)() const) &Expr_GreaterThanOrEqual::DynamicType, "None");

// CLASS: EXPR_INVALIDASSIGNMENT
py::class_<Expr_InvalidAssignment, opencascade::handle<Expr_InvalidAssignment>, Expr_ExprFailure> cls_Expr_InvalidAssignment(mod, "Expr_InvalidAssignment", "None");

// Constructors
cls_Expr_InvalidAssignment.def(py::init<>());
cls_Expr_InvalidAssignment.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_InvalidAssignment.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidAssignment::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidAssignment.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidAssignment::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidAssignment.def_static("NewInstance_", (opencascade::handle<Expr_InvalidAssignment> (*)(const Standard_CString)) &Expr_InvalidAssignment::NewInstance, "None", py::arg("theMessage"));
cls_Expr_InvalidAssignment.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidAssignment::get_type_name, "None");
cls_Expr_InvalidAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidAssignment::get_type_descriptor, "None");
cls_Expr_InvalidAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidAssignment::*)() const) &Expr_InvalidAssignment::DynamicType, "None");

// CLASS: EXPR_INVALIDFUNCTION
py::class_<Expr_InvalidFunction, opencascade::handle<Expr_InvalidFunction>, Expr_ExprFailure> cls_Expr_InvalidFunction(mod, "Expr_InvalidFunction", "None");

// Constructors
cls_Expr_InvalidFunction.def(py::init<>());
cls_Expr_InvalidFunction.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_InvalidFunction.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidFunction::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidFunction.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidFunction::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidFunction.def_static("NewInstance_", (opencascade::handle<Expr_InvalidFunction> (*)(const Standard_CString)) &Expr_InvalidFunction::NewInstance, "None", py::arg("theMessage"));
cls_Expr_InvalidFunction.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidFunction::get_type_name, "None");
cls_Expr_InvalidFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidFunction::get_type_descriptor, "None");
cls_Expr_InvalidFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidFunction::*)() const) &Expr_InvalidFunction::DynamicType, "None");

// CLASS: EXPR_INVALIDOPERAND
py::class_<Expr_InvalidOperand, opencascade::handle<Expr_InvalidOperand>, Expr_ExprFailure> cls_Expr_InvalidOperand(mod, "Expr_InvalidOperand", "None");

// Constructors
cls_Expr_InvalidOperand.def(py::init<>());
cls_Expr_InvalidOperand.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_InvalidOperand.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidOperand::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidOperand.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidOperand::Raise, "None", py::arg("theMessage"));
cls_Expr_InvalidOperand.def_static("NewInstance_", (opencascade::handle<Expr_InvalidOperand> (*)(const Standard_CString)) &Expr_InvalidOperand::NewInstance, "None", py::arg("theMessage"));
cls_Expr_InvalidOperand.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidOperand::get_type_name, "None");
cls_Expr_InvalidOperand.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidOperand::get_type_descriptor, "None");
cls_Expr_InvalidOperand.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidOperand::*)() const) &Expr_InvalidOperand::DynamicType, "None");

// CLASS: EXPR_LESSTHAN
py::class_<Expr_LessThan, opencascade::handle<Expr_LessThan>, Expr_SingleRelation> cls_Expr_LessThan(mod, "Expr_LessThan", "None");

// Constructors
cls_Expr_LessThan.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_LessThan.def("IsSatisfied", (Standard_Boolean (Expr_LessThan::*)() const) &Expr_LessThan::IsSatisfied, "None");
cls_Expr_LessThan.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThan::*)() const) &Expr_LessThan::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_LessThan.def("Simplify", (void (Expr_LessThan::*)()) &Expr_LessThan::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_LessThan.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThan::*)() const) &Expr_LessThan::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_LessThan.def("String", (TCollection_AsciiString (Expr_LessThan::*)() const) &Expr_LessThan::String, "returns a string representing <me> in a readable way.");
cls_Expr_LessThan.def_static("get_type_name_", (const char * (*)()) &Expr_LessThan::get_type_name, "None");
cls_Expr_LessThan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LessThan::get_type_descriptor, "None");
cls_Expr_LessThan.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LessThan::*)() const) &Expr_LessThan::DynamicType, "None");

// CLASS: EXPR_LESSTHANOREQUAL
py::class_<Expr_LessThanOrEqual, opencascade::handle<Expr_LessThanOrEqual>, Expr_SingleRelation> cls_Expr_LessThanOrEqual(mod, "Expr_LessThanOrEqual", "None");

// Constructors
cls_Expr_LessThanOrEqual.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_LessThanOrEqual.def("IsSatisfied", (Standard_Boolean (Expr_LessThanOrEqual::*)() const) &Expr_LessThanOrEqual::IsSatisfied, "None");
cls_Expr_LessThanOrEqual.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThanOrEqual::*)() const) &Expr_LessThanOrEqual::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
cls_Expr_LessThanOrEqual.def("Simplify", (void (Expr_LessThanOrEqual::*)()) &Expr_LessThanOrEqual::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
cls_Expr_LessThanOrEqual.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThanOrEqual::*)() const) &Expr_LessThanOrEqual::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_LessThanOrEqual.def("String", (TCollection_AsciiString (Expr_LessThanOrEqual::*)() const) &Expr_LessThanOrEqual::String, "returns a string representing <me> in a readable way.");
cls_Expr_LessThanOrEqual.def_static("get_type_name_", (const char * (*)()) &Expr_LessThanOrEqual::get_type_name, "None");
cls_Expr_LessThanOrEqual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LessThanOrEqual::get_type_descriptor, "None");
cls_Expr_LessThanOrEqual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LessThanOrEqual::*)() const) &Expr_LessThanOrEqual::DynamicType, "None");

// CLASS: EXPR_LOGOF10
py::class_<Expr_LogOf10, opencascade::handle<Expr_LogOf10>, Expr_UnaryExpression> cls_Expr_LogOf10(mod, "Expr_LogOf10", "None");

// Constructors
cls_Expr_LogOf10.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_LogOf10.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)() const) &Expr_LogOf10::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_LogOf10.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)() const) &Expr_LogOf10::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_LogOf10.def("IsIdentical", (Standard_Boolean (Expr_LogOf10::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_LogOf10::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_LogOf10.def("IsLinear", (Standard_Boolean (Expr_LogOf10::*)() const) &Expr_LogOf10::IsLinear, "None");
cls_Expr_LogOf10.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_LogOf10::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_LogOf10.def("Evaluate", (Standard_Real (Expr_LogOf10::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_LogOf10::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_LogOf10.def("String", (TCollection_AsciiString (Expr_LogOf10::*)() const) &Expr_LogOf10::String, "returns a string representing <me> in a readable way.");
cls_Expr_LogOf10.def_static("get_type_name_", (const char * (*)()) &Expr_LogOf10::get_type_name, "None");
cls_Expr_LogOf10.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LogOf10::get_type_descriptor, "None");
cls_Expr_LogOf10.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LogOf10::*)() const) &Expr_LogOf10::DynamicType, "None");

// CLASS: EXPR_LOGOFE
py::class_<Expr_LogOfe, opencascade::handle<Expr_LogOfe>, Expr_UnaryExpression> cls_Expr_LogOfe(mod, "Expr_LogOfe", "None");

// Constructors
cls_Expr_LogOfe.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_LogOfe.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)() const) &Expr_LogOfe::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_LogOfe.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)() const) &Expr_LogOfe::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_LogOfe.def("IsIdentical", (Standard_Boolean (Expr_LogOfe::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_LogOfe::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_LogOfe.def("IsLinear", (Standard_Boolean (Expr_LogOfe::*)() const) &Expr_LogOfe::IsLinear, "None");
cls_Expr_LogOfe.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_LogOfe::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_LogOfe.def("Evaluate", (Standard_Real (Expr_LogOfe::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_LogOfe::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_LogOfe.def("String", (TCollection_AsciiString (Expr_LogOfe::*)() const) &Expr_LogOfe::String, "returns a string representing <me> in a readable way.");
cls_Expr_LogOfe.def_static("get_type_name_", (const char * (*)()) &Expr_LogOfe::get_type_name, "None");
cls_Expr_LogOfe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LogOfe::get_type_descriptor, "None");
cls_Expr_LogOfe.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LogOfe::*)() const) &Expr_LogOfe::DynamicType, "None");

// CLASS: EXPR_NAMEDUNKNOWN
py::class_<Expr_NamedUnknown, opencascade::handle<Expr_NamedUnknown>, Expr_NamedExpression> cls_Expr_NamedUnknown(mod, "Expr_NamedUnknown", "This class describes any variable of an expression. Assignment is treated directly in this class.");

// Constructors
cls_Expr_NamedUnknown.def(py::init<const TCollection_AsciiString &>(), py::arg("name"));

// Methods
cls_Expr_NamedUnknown.def("IsAssigned", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::IsAssigned, "Tests if an expression is assigned to <me>.");
cls_Expr_NamedUnknown.def("AssignedExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::AssignedExpression, "If exists, returns the assigned expression. An exception is raised if the expression does not exist.");
cls_Expr_NamedUnknown.def("Assign", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Assign, "Assigns <me> to <exp> expression. Raises exception if <exp> refers to <me>.", py::arg("exp"));
cls_Expr_NamedUnknown.def("Deassign", (void (Expr_NamedUnknown::*)()) &Expr_NamedUnknown::Deassign, "Supresses the assigned expression");
cls_Expr_NamedUnknown.def("NbSubExpressions", (Standard_Integer (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_NamedUnknown.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)(const Standard_Integer) const) &Expr_NamedUnknown::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_NamedUnknown.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NamedUnknown.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NamedUnknown.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NamedUnknown.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
cls_Expr_NamedUnknown.def("Contains", (Standard_Boolean (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedUnknown::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NamedUnknown.def("IsLinear", (Standard_Boolean (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::IsLinear, "None");
cls_Expr_NamedUnknown.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedUnknown::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NamedUnknown.def("Replace", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_NamedUnknown.def("Evaluate", (Standard_Real (Expr_NamedUnknown::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedUnknown::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_NamedUnknown.def_static("get_type_name_", (const char * (*)()) &Expr_NamedUnknown::get_type_name, "None");
cls_Expr_NamedUnknown.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedUnknown::get_type_descriptor, "None");
cls_Expr_NamedUnknown.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedUnknown::*)() const) &Expr_NamedUnknown::DynamicType, "None");

// TYPEDEF: EXPR_MAPOFNAMEDUNKNOWN
bind_NCollection_IndexedMap<opencascade::handle<Expr_NamedUnknown>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "Expr_MapOfNamedUnknown", py::module_local(false));

// CLASS: EXPR_NAMEDCONSTANT
py::class_<Expr_NamedConstant, opencascade::handle<Expr_NamedConstant>, Expr_NamedExpression> cls_Expr_NamedConstant(mod, "Expr_NamedConstant", "Describes any numeric constant known by a special name (as PI, e,...).");

// Constructors
cls_Expr_NamedConstant.def(py::init<const TCollection_AsciiString &, const Standard_Real>(), py::arg("name"), py::arg("value"));

// Methods
cls_Expr_NamedConstant.def("GetValue", (Standard_Real (Expr_NamedConstant::*)() const) &Expr_NamedConstant::GetValue, "None");
cls_Expr_NamedConstant.def("NbSubExpressions", (Standard_Integer (Expr_NamedConstant::*)() const) &Expr_NamedConstant::NbSubExpressions, "returns the number of sub-expressions contained in <me> (always returns zero)");
cls_Expr_NamedConstant.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedConstant::*)(const Standard_Integer) const) &Expr_NamedConstant::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange", py::arg("I"));
cls_Expr_NamedConstant.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::Simplified, "returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NamedConstant.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NamedConstant.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const) &Expr_NamedConstant::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NamedConstant.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedConstant::*)() const) &Expr_NamedConstant::ContainsUnknowns, "Tests if <me> contains NamedUnknown. (returns always False)");
cls_Expr_NamedConstant.def("Contains", (Standard_Boolean (Expr_NamedConstant::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NamedConstant::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NamedConstant.def("IsLinear", (Standard_Boolean (Expr_NamedConstant::*)() const) &Expr_NamedConstant::IsLinear, "None");
cls_Expr_NamedConstant.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NamedConstant::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NamedConstant.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NamedConstant::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_NamedConstant.def("Replace", (void (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedConstant::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
cls_Expr_NamedConstant.def("Evaluate", (Standard_Real (Expr_NamedConstant::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NamedConstant::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
cls_Expr_NamedConstant.def_static("get_type_name_", (const char * (*)()) &Expr_NamedConstant::get_type_name, "None");
cls_Expr_NamedConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedConstant::get_type_descriptor, "None");
cls_Expr_NamedConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedConstant::*)() const) &Expr_NamedConstant::DynamicType, "None");

// CLASS: EXPR_NOTASSIGNED
py::class_<Expr_NotAssigned, opencascade::handle<Expr_NotAssigned>, Expr_ExprFailure> cls_Expr_NotAssigned(mod, "Expr_NotAssigned", "None");

// Constructors
cls_Expr_NotAssigned.def(py::init<>());
cls_Expr_NotAssigned.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_NotAssigned.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_NotAssigned::Raise, "None", py::arg("theMessage"));
cls_Expr_NotAssigned.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_NotAssigned::Raise, "None", py::arg("theMessage"));
cls_Expr_NotAssigned.def_static("NewInstance_", (opencascade::handle<Expr_NotAssigned> (*)(const Standard_CString)) &Expr_NotAssigned::NewInstance, "None", py::arg("theMessage"));
cls_Expr_NotAssigned.def_static("get_type_name_", (const char * (*)()) &Expr_NotAssigned::get_type_name, "None");
cls_Expr_NotAssigned.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NotAssigned::get_type_descriptor, "None");
cls_Expr_NotAssigned.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NotAssigned::*)() const) &Expr_NotAssigned::DynamicType, "None");

// CLASS: EXPR_NOTEVALUABLE
py::class_<Expr_NotEvaluable, opencascade::handle<Expr_NotEvaluable>, Expr_ExprFailure> cls_Expr_NotEvaluable(mod, "Expr_NotEvaluable", "None");

// Constructors
cls_Expr_NotEvaluable.def(py::init<>());
cls_Expr_NotEvaluable.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Expr_NotEvaluable.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_NotEvaluable::Raise, "None", py::arg("theMessage"));
cls_Expr_NotEvaluable.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_NotEvaluable::Raise, "None", py::arg("theMessage"));
cls_Expr_NotEvaluable.def_static("NewInstance_", (opencascade::handle<Expr_NotEvaluable> (*)(const Standard_CString)) &Expr_NotEvaluable::NewInstance, "None", py::arg("theMessage"));
cls_Expr_NotEvaluable.def_static("get_type_name_", (const char * (*)()) &Expr_NotEvaluable::get_type_name, "None");
cls_Expr_NotEvaluable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NotEvaluable::get_type_descriptor, "None");
cls_Expr_NotEvaluable.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NotEvaluable::*)() const) &Expr_NotEvaluable::DynamicType, "None");

// CLASS: EXPR_NUMERICVALUE
py::class_<Expr_NumericValue, opencascade::handle<Expr_NumericValue>, Expr_GeneralExpression> cls_Expr_NumericValue(mod, "Expr_NumericValue", "This class describes any reel value defined in an expression.");

// Constructors
cls_Expr_NumericValue.def(py::init<const Standard_Real>(), py::arg("val"));

// Methods
cls_Expr_NumericValue.def("GetValue", (Standard_Real (Expr_NumericValue::*)() const) &Expr_NumericValue::GetValue, "None");
cls_Expr_NumericValue.def("SetValue", (void (Expr_NumericValue::*)(const Standard_Real)) &Expr_NumericValue::SetValue, "None", py::arg("val"));
cls_Expr_NumericValue.def("NbSubExpressions", (Standard_Integer (Expr_NumericValue::*)() const) &Expr_NumericValue::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
cls_Expr_NumericValue.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NumericValue::*)(const Standard_Integer) const) &Expr_NumericValue::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_NumericValue.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_NumericValue.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_NumericValue.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const) &Expr_NumericValue::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_NumericValue.def("ContainsUnknowns", (Standard_Boolean (Expr_NumericValue::*)() const) &Expr_NumericValue::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
cls_Expr_NumericValue.def("Contains", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NumericValue::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_NumericValue.def("IsIdentical", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_NumericValue::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_NumericValue.def("IsLinear", (Standard_Boolean (Expr_NumericValue::*)() const) &Expr_NumericValue::IsLinear, "None");
cls_Expr_NumericValue.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_NumericValue::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_NumericValue.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_NumericValue::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_NumericValue.def("Replace", (void (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NumericValue::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
cls_Expr_NumericValue.def("Evaluate", (Standard_Real (Expr_NumericValue::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_NumericValue::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
cls_Expr_NumericValue.def("String", (TCollection_AsciiString (Expr_NumericValue::*)() const) &Expr_NumericValue::String, "returns a string representing <me> in a readable way.");
cls_Expr_NumericValue.def_static("get_type_name_", (const char * (*)()) &Expr_NumericValue::get_type_name, "None");
cls_Expr_NumericValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NumericValue::get_type_descriptor, "None");
cls_Expr_NumericValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NumericValue::*)() const) &Expr_NumericValue::DynamicType, "None");

// TYPEDEF: EXPR_SEQUENCEOFGENERALEXPRESSION
bind_NCollection_Sequence<opencascade::handle<Expr_GeneralExpression> >(mod, "Expr_SequenceOfGeneralExpression", py::module_local(false));

// CLASS: EXPR_POLYEXPRESSION
py::class_<Expr_PolyExpression, opencascade::handle<Expr_PolyExpression>, Expr_GeneralExpression> cls_Expr_PolyExpression(mod, "Expr_PolyExpression", "None");

// Methods
cls_Expr_PolyExpression.def("NbOperands", (Standard_Integer (Expr_PolyExpression::*)() const) &Expr_PolyExpression::NbOperands, "returns the number of operands contained in <me>");
cls_Expr_PolyExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const) &Expr_PolyExpression::Operand, "Returns the <index>-th operand used in <me>. An exception is raised if index is out of range", py::arg("index"));
cls_Expr_PolyExpression.def("SetOperand", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Integer)) &Expr_PolyExpression::SetOperand, "Sets the <index>-th operand used in <me>. An exception is raised if <index> is out of range Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"), py::arg("index"));
cls_Expr_PolyExpression.def("NbSubExpressions", (Standard_Integer (Expr_PolyExpression::*)() const) &Expr_PolyExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 2)");
cls_Expr_PolyExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const) &Expr_PolyExpression::SubExpression, "Returns the sub-expression denoted by <I> in <me> Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
cls_Expr_PolyExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_PolyExpression::*)() const) &Expr_PolyExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
cls_Expr_PolyExpression.def("Contains", (Standard_Boolean (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_PolyExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
cls_Expr_PolyExpression.def("Replace", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_PolyExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
cls_Expr_PolyExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyExpression::*)() const) &Expr_PolyExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
cls_Expr_PolyExpression.def_static("get_type_name_", (const char * (*)()) &Expr_PolyExpression::get_type_name, "None");
cls_Expr_PolyExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_PolyExpression::get_type_descriptor, "None");
cls_Expr_PolyExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_PolyExpression::*)() const) &Expr_PolyExpression::DynamicType, "None");

// CLASS: EXPR_SUM
py::class_<Expr_Sum, opencascade::handle<Expr_Sum>, Expr_PolyExpression> cls_Expr_Sum(mod, "Expr_Sum", "None");

// Constructors
cls_Expr_Sum.def(py::init<const Expr_SequenceOfGeneralExpression &>(), py::arg("exps"));
cls_Expr_Sum.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Sum.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)() const) &Expr_Sum::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Sum.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)() const) &Expr_Sum::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Sum.def("IsIdentical", (Standard_Boolean (Expr_Sum::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Sum::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Sum.def("IsLinear", (Standard_Boolean (Expr_Sum::*)() const) &Expr_Sum::IsLinear, "None");
cls_Expr_Sum.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Sum::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Sum.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_Sum::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_Sum.def("Evaluate", (Standard_Real (Expr_Sum::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Sum::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Sum.def("String", (TCollection_AsciiString (Expr_Sum::*)() const) &Expr_Sum::String, "returns a string representing <me> in a readable way.");
cls_Expr_Sum.def_static("get_type_name_", (const char * (*)()) &Expr_Sum::get_type_name, "None");
cls_Expr_Sum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sum::get_type_descriptor, "None");
cls_Expr_Sum.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sum::*)() const) &Expr_Sum::DynamicType, "None");

// CLASS: EXPR_UNARYMINUS
py::class_<Expr_UnaryMinus, opencascade::handle<Expr_UnaryMinus>, Expr_UnaryExpression> cls_Expr_UnaryMinus(mod, "Expr_UnaryMinus", "None");

// Constructors
cls_Expr_UnaryMinus.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_UnaryMinus.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)() const) &Expr_UnaryMinus::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_UnaryMinus.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)() const) &Expr_UnaryMinus::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_UnaryMinus.def("IsIdentical", (Standard_Boolean (Expr_UnaryMinus::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_UnaryMinus::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_UnaryMinus.def("IsLinear", (Standard_Boolean (Expr_UnaryMinus::*)() const) &Expr_UnaryMinus::IsLinear, "None");
cls_Expr_UnaryMinus.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_UnaryMinus::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_UnaryMinus.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const) &Expr_UnaryMinus::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
cls_Expr_UnaryMinus.def("Evaluate", (Standard_Real (Expr_UnaryMinus::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_UnaryMinus::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_UnaryMinus.def("String", (TCollection_AsciiString (Expr_UnaryMinus::*)() const) &Expr_UnaryMinus::String, "returns a string representing <me> in a readable way.");
cls_Expr_UnaryMinus.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryMinus::get_type_name, "None");
cls_Expr_UnaryMinus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryMinus::get_type_descriptor, "None");
cls_Expr_UnaryMinus.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryMinus::*)() const) &Expr_UnaryMinus::DynamicType, "None");

// CLASS: EXPR_PRODUCT
py::class_<Expr_Product, opencascade::handle<Expr_Product>, Expr_PolyExpression> cls_Expr_Product(mod, "Expr_Product", "None");

// Constructors
cls_Expr_Product.def(py::init<const Expr_SequenceOfGeneralExpression &>(), py::arg("exps"));
cls_Expr_Product.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));

// Methods
cls_Expr_Product.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)() const) &Expr_Product::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Product.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)() const) &Expr_Product::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Product.def("IsIdentical", (Standard_Boolean (Expr_Product::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Product::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Product.def("IsLinear", (Standard_Boolean (Expr_Product::*)() const) &Expr_Product::IsLinear, "None");
cls_Expr_Product.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Product::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Product.def("Evaluate", (Standard_Real (Expr_Product::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Product::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Product.def("String", (TCollection_AsciiString (Expr_Product::*)() const) &Expr_Product::String, "returns a string representing <me> in a readable way.");
cls_Expr_Product.def_static("get_type_name_", (const char * (*)()) &Expr_Product::get_type_name, "None");
cls_Expr_Product.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Product::get_type_descriptor, "None");
cls_Expr_Product.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Product::*)() const) &Expr_Product::DynamicType, "None");

// CLASS: EXPR_POLYFUNCTION
py::class_<Expr_PolyFunction, opencascade::handle<Expr_PolyFunction>, Expr_PolyExpression> cls_Expr_PolyFunction(mod, "Expr_PolyFunction", "Defines the use of an n-ary function in an expression with given arguments.");

// Constructors
cls_Expr_PolyFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const Expr_Array1OfGeneralExpression &>(), py::arg("func"), py::arg("exps"));

// Methods
cls_Expr_PolyFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_PolyFunction::*)() const) &Expr_PolyFunction::Function, "Returns the function defining <me>.");
cls_Expr_PolyFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)() const) &Expr_PolyFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_PolyFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)() const) &Expr_PolyFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_PolyFunction.def("IsIdentical", (Standard_Boolean (Expr_PolyFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_PolyFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_PolyFunction.def("IsLinear", (Standard_Boolean (Expr_PolyFunction::*)() const) &Expr_PolyFunction::IsLinear, "None");
cls_Expr_PolyFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_PolyFunction::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_PolyFunction.def("Evaluate", (Standard_Real (Expr_PolyFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_PolyFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_PolyFunction.def("String", (TCollection_AsciiString (Expr_PolyFunction::*)() const) &Expr_PolyFunction::String, "returns a string representing <me> in a readable way.");
cls_Expr_PolyFunction.def_static("get_type_name_", (const char * (*)()) &Expr_PolyFunction::get_type_name, "None");
cls_Expr_PolyFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_PolyFunction::get_type_descriptor, "None");
cls_Expr_PolyFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_PolyFunction::*)() const) &Expr_PolyFunction::DynamicType, "None");

// CLASS: EXPR_RELATIONITERATOR
py::class_<Expr_RelationIterator> cls_Expr_RelationIterator(mod, "Expr_RelationIterator", "Iterates on every basic relation contained in a GeneralRelation.");

// Constructors
cls_Expr_RelationIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));

// Methods
// cls_Expr_RelationIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_RelationIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_RelationIterator.def_static("operator delete_", (void (*)(void *)) &Expr_RelationIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_RelationIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_RelationIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_RelationIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_RelationIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_RelationIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_RelationIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_RelationIterator.def("More", (Standard_Boolean (Expr_RelationIterator::*)() const) &Expr_RelationIterator::More, "Returns False if no other relation remains.");
cls_Expr_RelationIterator.def("Next", (void (Expr_RelationIterator::*)()) &Expr_RelationIterator::Next, "None");
cls_Expr_RelationIterator.def("Value", (opencascade::handle<Expr_SingleRelation> (Expr_RelationIterator::*)() const) &Expr_RelationIterator::Value, "Returns current basic relation. Exception is raised if no more relation remains.");

// CLASS: EXPR_RUITERATOR
py::class_<Expr_RUIterator> cls_Expr_RUIterator(mod, "Expr_RUIterator", "Iterates on NamedUnknowns in a GeneralRelation.");

// Constructors
cls_Expr_RUIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));

// Methods
// cls_Expr_RUIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_RUIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_RUIterator.def_static("operator delete_", (void (*)(void *)) &Expr_RUIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_RUIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_RUIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_RUIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_RUIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_RUIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_RUIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_RUIterator.def("More", (Standard_Boolean (Expr_RUIterator::*)() const) &Expr_RUIterator::More, "Returns False if on other unknown remains.");
cls_Expr_RUIterator.def("Next", (void (Expr_RUIterator::*)()) &Expr_RUIterator::Next, "None");
cls_Expr_RUIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_RUIterator::*)() const) &Expr_RUIterator::Value, "Returns current NamedUnknown. Raises exception if no more unknowns remain.");

// TYPEDEF: EXPR_SEQUENCEOFGENERALRELATION
bind_NCollection_Sequence<opencascade::handle<Expr_GeneralRelation> >(mod, "Expr_SequenceOfGeneralRelation", py::module_local(false));

// CLASS: EXPR_SIGN
py::class_<Expr_Sign, opencascade::handle<Expr_Sign>, Expr_UnaryExpression> cls_Expr_Sign(mod, "Expr_Sign", "None");

// Constructors
cls_Expr_Sign.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Sign.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)() const) &Expr_Sign::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Sign.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)() const) &Expr_Sign::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Sign.def("IsIdentical", (Standard_Boolean (Expr_Sign::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Sign::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Sign.def("IsLinear", (Standard_Boolean (Expr_Sign::*)() const) &Expr_Sign::IsLinear, "None");
cls_Expr_Sign.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Sign::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Sign.def("Evaluate", (Standard_Real (Expr_Sign::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Sign::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Sign.def("String", (TCollection_AsciiString (Expr_Sign::*)() const) &Expr_Sign::String, "returns a string representing <me> in a readable way.");
cls_Expr_Sign.def_static("get_type_name_", (const char * (*)()) &Expr_Sign::get_type_name, "None");
cls_Expr_Sign.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sign::get_type_descriptor, "None");
cls_Expr_Sign.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sign::*)() const) &Expr_Sign::DynamicType, "None");

// CLASS: EXPR_SINE
py::class_<Expr_Sine, opencascade::handle<Expr_Sine>, Expr_UnaryExpression> cls_Expr_Sine(mod, "Expr_Sine", "None");

// Constructors
cls_Expr_Sine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Sine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)() const) &Expr_Sine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Sine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)() const) &Expr_Sine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Sine.def("IsIdentical", (Standard_Boolean (Expr_Sine::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Sine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Sine.def("IsLinear", (Standard_Boolean (Expr_Sine::*)() const) &Expr_Sine::IsLinear, "None");
cls_Expr_Sine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Sine::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Sine.def("Evaluate", (Standard_Real (Expr_Sine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Sine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Sine.def("String", (TCollection_AsciiString (Expr_Sine::*)() const) &Expr_Sine::String, "returns a string representing <me> in a readable way.");
cls_Expr_Sine.def_static("get_type_name_", (const char * (*)()) &Expr_Sine::get_type_name, "None");
cls_Expr_Sine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sine::get_type_descriptor, "None");
cls_Expr_Sine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sine::*)() const) &Expr_Sine::DynamicType, "None");

// CLASS: EXPR_SINH
py::class_<Expr_Sinh, opencascade::handle<Expr_Sinh>, Expr_UnaryExpression> cls_Expr_Sinh(mod, "Expr_Sinh", "None");

// Constructors
cls_Expr_Sinh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Sinh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)() const) &Expr_Sinh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Sinh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)() const) &Expr_Sinh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Sinh.def("IsIdentical", (Standard_Boolean (Expr_Sinh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Sinh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Sinh.def("IsLinear", (Standard_Boolean (Expr_Sinh::*)() const) &Expr_Sinh::IsLinear, "None");
cls_Expr_Sinh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Sinh::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Sinh.def("Evaluate", (Standard_Real (Expr_Sinh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Sinh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Sinh.def("String", (TCollection_AsciiString (Expr_Sinh::*)() const) &Expr_Sinh::String, "returns a string representing <me> in a readable way.");
cls_Expr_Sinh.def_static("get_type_name_", (const char * (*)()) &Expr_Sinh::get_type_name, "None");
cls_Expr_Sinh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sinh::get_type_descriptor, "None");
cls_Expr_Sinh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sinh::*)() const) &Expr_Sinh::DynamicType, "None");

// CLASS: EXPR_SQUARE
py::class_<Expr_Square, opencascade::handle<Expr_Square>, Expr_UnaryExpression> cls_Expr_Square(mod, "Expr_Square", "None");

// Constructors
cls_Expr_Square.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Square.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)() const) &Expr_Square::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Square.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)() const) &Expr_Square::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Square.def("IsIdentical", (Standard_Boolean (Expr_Square::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Square::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Square.def("IsLinear", (Standard_Boolean (Expr_Square::*)() const) &Expr_Square::IsLinear, "None");
cls_Expr_Square.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Square::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_Square.def("Evaluate", (Standard_Real (Expr_Square::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Square::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Square.def("String", (TCollection_AsciiString (Expr_Square::*)() const) &Expr_Square::String, "returns a string representing <me> in a readable way.");
cls_Expr_Square.def_static("get_type_name_", (const char * (*)()) &Expr_Square::get_type_name, "None");
cls_Expr_Square.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Square::get_type_descriptor, "None");
cls_Expr_Square.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Square::*)() const) &Expr_Square::DynamicType, "None");

// CLASS: EXPR_SQUAREROOT
py::class_<Expr_SquareRoot, opencascade::handle<Expr_SquareRoot>, Expr_UnaryExpression> cls_Expr_SquareRoot(mod, "Expr_SquareRoot", "None");

// Constructors
cls_Expr_SquareRoot.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_SquareRoot.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)() const) &Expr_SquareRoot::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_SquareRoot.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)() const) &Expr_SquareRoot::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_SquareRoot.def("IsIdentical", (Standard_Boolean (Expr_SquareRoot::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_SquareRoot::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_SquareRoot.def("IsLinear", (Standard_Boolean (Expr_SquareRoot::*)() const) &Expr_SquareRoot::IsLinear, "None");
cls_Expr_SquareRoot.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_SquareRoot::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_SquareRoot.def("Evaluate", (Standard_Real (Expr_SquareRoot::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_SquareRoot::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_SquareRoot.def("String", (TCollection_AsciiString (Expr_SquareRoot::*)() const) &Expr_SquareRoot::String, "returns a string representing <me> in a readable way.");
cls_Expr_SquareRoot.def_static("get_type_name_", (const char * (*)()) &Expr_SquareRoot::get_type_name, "None");
cls_Expr_SquareRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SquareRoot::get_type_descriptor, "None");
cls_Expr_SquareRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SquareRoot::*)() const) &Expr_SquareRoot::DynamicType, "None");

// CLASS: EXPR_SYSTEMRELATION
py::class_<Expr_SystemRelation, opencascade::handle<Expr_SystemRelation>, Expr_GeneralRelation> cls_Expr_SystemRelation(mod, "Expr_SystemRelation", "None");

// Constructors
cls_Expr_SystemRelation.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("relation"));

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

// CLASS: EXPR_TANGENT
py::class_<Expr_Tangent, opencascade::handle<Expr_Tangent>, Expr_UnaryExpression> cls_Expr_Tangent(mod, "Expr_Tangent", "None");

// Constructors
cls_Expr_Tangent.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Tangent.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)() const) &Expr_Tangent::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Tangent.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)() const) &Expr_Tangent::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Tangent.def("IsIdentical", (Standard_Boolean (Expr_Tangent::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Tangent::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Tangent.def("IsLinear", (Standard_Boolean (Expr_Tangent::*)() const) &Expr_Tangent::IsLinear, "None");
cls_Expr_Tangent.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Tangent::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Tangent.def("Evaluate", (Standard_Real (Expr_Tangent::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Tangent::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Tangent.def("String", (TCollection_AsciiString (Expr_Tangent::*)() const) &Expr_Tangent::String, "returns a string representing <me> in a readable way.");
cls_Expr_Tangent.def_static("get_type_name_", (const char * (*)()) &Expr_Tangent::get_type_name, "None");
cls_Expr_Tangent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Tangent::get_type_descriptor, "None");
cls_Expr_Tangent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Tangent::*)() const) &Expr_Tangent::DynamicType, "None");

// CLASS: EXPR_TANH
py::class_<Expr_Tanh, opencascade::handle<Expr_Tanh>, Expr_UnaryExpression> cls_Expr_Tanh(mod, "Expr_Tanh", "None");

// Constructors
cls_Expr_Tanh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
cls_Expr_Tanh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)() const) &Expr_Tanh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_Tanh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)() const) &Expr_Tanh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_Tanh.def("IsIdentical", (Standard_Boolean (Expr_Tanh::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_Tanh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_Tanh.def("IsLinear", (Standard_Boolean (Expr_Tanh::*)() const) &Expr_Tanh::IsLinear, "None");
cls_Expr_Tanh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_Tanh::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
cls_Expr_Tanh.def("Evaluate", (Standard_Real (Expr_Tanh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_Tanh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_Tanh.def("String", (TCollection_AsciiString (Expr_Tanh::*)() const) &Expr_Tanh::String, "returns a string representing <me> in a readable way.");
cls_Expr_Tanh.def_static("get_type_name_", (const char * (*)()) &Expr_Tanh::get_type_name, "None");
cls_Expr_Tanh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Tanh::get_type_descriptor, "None");
cls_Expr_Tanh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Tanh::*)() const) &Expr_Tanh::DynamicType, "None");

// CLASS: EXPR_UNARYFUNCTION
py::class_<Expr_UnaryFunction, opencascade::handle<Expr_UnaryFunction>, Expr_UnaryExpression> cls_Expr_UnaryFunction(mod, "Expr_UnaryFunction", "Defines the use of an unary function in an expression with a given argument.");

// Constructors
cls_Expr_UnaryFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("func"), py::arg("exp"));

// Methods
cls_Expr_UnaryFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::Function, "Returns the function defining <me>.");
cls_Expr_UnaryFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
cls_Expr_UnaryFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
cls_Expr_UnaryFunction.def("IsIdentical", (Standard_Boolean (Expr_UnaryFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const) &Expr_UnaryFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
cls_Expr_UnaryFunction.def("IsLinear", (Standard_Boolean (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::IsLinear, "None");
cls_Expr_UnaryFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const) &Expr_UnaryFunction::Derivative, "returns the derivative on <X> unknown of <me>.", py::arg("X"));
cls_Expr_UnaryFunction.def("Evaluate", (Standard_Real (Expr_UnaryFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const) &Expr_UnaryFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
cls_Expr_UnaryFunction.def("String", (TCollection_AsciiString (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::String, "returns a string representing <me> in a readable way.");
cls_Expr_UnaryFunction.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryFunction::get_type_name, "None");
cls_Expr_UnaryFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryFunction::get_type_descriptor, "None");
cls_Expr_UnaryFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryFunction::*)() const) &Expr_UnaryFunction::DynamicType, "None");

// CLASS: EXPR_UNKNOWNITERATOR
py::class_<Expr_UnknownIterator> cls_Expr_UnknownIterator(mod, "Expr_UnknownIterator", "Describes an iterator on NamedUnknowns contained in any GeneralExpression.");

// Constructors
cls_Expr_UnknownIterator.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));

// Methods
// cls_Expr_UnknownIterator.def_static("operator new_", (void * (*)(size_t)) &Expr_UnknownIterator::operator new, "None", py::arg("theSize"));
// cls_Expr_UnknownIterator.def_static("operator delete_", (void (*)(void *)) &Expr_UnknownIterator::operator delete, "None", py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator new[]_", (void * (*)(size_t)) &Expr_UnknownIterator::operator new[], "None", py::arg("theSize"));
// cls_Expr_UnknownIterator.def_static("operator delete[]_", (void (*)(void *)) &Expr_UnknownIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Expr_UnknownIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Expr_UnknownIterator.def_static("operator delete_", (void (*)(void *, void *)) &Expr_UnknownIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Expr_UnknownIterator.def("More", (Standard_Boolean (Expr_UnknownIterator::*)() const) &Expr_UnknownIterator::More, "None");
cls_Expr_UnknownIterator.def("Next", (void (Expr_UnknownIterator::*)()) &Expr_UnknownIterator::Next, "None");
cls_Expr_UnknownIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_UnknownIterator::*)() const) &Expr_UnknownIterator::Value, "None");


}
