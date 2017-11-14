#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Expr_GeneralExpression.hxx>
#include <Expr_NamedUnknown.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <Expr_GeneralRelation.hxx>
#include <Expr_NumericValue.hxx>
#include <Expr_NamedExpression.hxx>
#include <Expr_NamedConstant.hxx>
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
#include <Expr_GeneralFunction.hxx>
#include <Expr_UnaryFunction.hxx>
#include <Expr_UnaryMinus.hxx>
#include <Expr_BinaryExpression.hxx>
#include <Expr_BinaryFunction.hxx>
#include <Expr_Difference.hxx>
#include <Expr_Division.hxx>
#include <Expr_Exponentiate.hxx>
#include <Expr_PolyExpression.hxx>
#include <Expr_Array1OfGeneralExpression.hxx>
#include <Expr_PolyFunction.hxx>
#include <Expr_SequenceOfGeneralExpression.hxx>
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
#include <Expr_NamedFunction.hxx>
#include <Expr_FunctionDerivative.hxx>
#include <Expr.hxx>
#include <NCollection_Array1.hxx>
#include <Expr_ExprFailure.hxx>
#include <Standard_SStream.hxx>
#include <Expr_NotEvaluable.hxx>
#include <Expr_InvalidOperand.hxx>
#include <Expr_Array1OfSingleRelation.hxx>
#include <Expr_InvalidFunction.hxx>
#include <Standard_Failure.hxx>
#include <Expr_InvalidAssignment.hxx>
#include <Expr_NotAssigned.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedMap.hxx>
#include <Expr_MapOfNamedUnknown.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Expr_Operators.hxx>
#include <Expr_SequenceOfGeneralRelation.hxx>

PYBIND11_MODULE(Expr, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Operators.hxx
	mod.def("__add__", (opencascade::handle<Expr_Sum> (*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Real)) &operator+, py::is_operator(), "None", py::arg("x"), py::arg("y"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Operators.hxx
	mod.def("__sub__", (opencascade::handle<Expr_UnaryMinus> (*)(const opencascade::handle<Expr_GeneralExpression> &)) &operator-, py::is_operator(), "None", py::arg("x"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Operators.hxx
	mod.def("__mul__", (opencascade::handle<Expr_Product> (*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Real)) &operator*, py::is_operator(), "None", py::arg("x"), py::arg("y"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Operators.hxx
	mod.def("__truediv__", (opencascade::handle<Expr_Division> (*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Real)) &operator/, py::is_operator(), "None", py::arg("x"), py::arg("y"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_GeneralExpression.hxx
	py::class_<Expr_GeneralExpression, opencascade::handle<Expr_GeneralExpression>, Standard_Transient> cls_Expr_GeneralExpression(mod, "Expr_GeneralExpression", "Defines the general purposes of any expression.");
	cls_Expr_GeneralExpression.def("NbSubExpressions", (Standard_Integer (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
	cls_Expr_GeneralExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_GeneralExpression::*)(const Standard_Integer) const ) &Expr_GeneralExpression::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_GeneralExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_GeneralExpression.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_GeneralExpression.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_GeneralExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::ContainsUnknowns, "Tests if <me> contains NamedUnknowns.");
	cls_Expr_GeneralExpression.def("Contains", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_GeneralExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_GeneralExpression.def("IsLinear", (Standard_Boolean (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::IsLinear, "Tests if <me> is linear on every NamedUnknown it contains.");
	cls_Expr_GeneralExpression.def("IsShareable", (Standard_Boolean (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method returns False as a default value. To be redefined ( especially for NamedUnknown).");
	cls_Expr_GeneralExpression.def("IsIdentical", (Standard_Boolean (Expr_GeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_GeneralExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. Warning: This method does not include any simplification before testing. It could also be very slow; to be used carefully.", py::arg("Other"));
	cls_Expr_GeneralExpression.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_GeneralExpression::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_GeneralExpression.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_GeneralExpression::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raise OutOfRange if N <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_GeneralExpression.def("Replace", (void (Expr_GeneralExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_GeneralExpression::Replace, "Replaces all occurences of <var> with copies of <with> in <me>. Copies of <with> are made with the Copy() method. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_GeneralExpression.def("Evaluate", (Standard_Real (Expr_GeneralExpression::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_GeneralExpression::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_GeneralExpression.def("EvaluateNumeric", (Standard_Real (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::EvaluateNumeric, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.");
	cls_Expr_GeneralExpression.def("String", (TCollection_AsciiString (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::String, "returns a string representing <me> in a readable way.");
	cls_Expr_GeneralExpression.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralExpression::get_type_name, "None");
	cls_Expr_GeneralExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralExpression::get_type_descriptor, "None");
	cls_Expr_GeneralExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralExpression::*)() const ) &Expr_GeneralExpression::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_GeneralRelation.hxx
	py::class_<Expr_GeneralRelation, opencascade::handle<Expr_GeneralRelation>, Standard_Transient> cls_Expr_GeneralRelation(mod, "Expr_GeneralRelation", "Defines the general purposes of any relation between expressions.");
	cls_Expr_GeneralRelation.def("IsSatisfied", (Standard_Boolean (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::IsSatisfied, "Returns the current status of the relation");
	cls_Expr_GeneralRelation.def("IsLinear", (Standard_Boolean (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
	cls_Expr_GeneralRelation.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_GeneralRelation.def("Simplify", (void (Expr_GeneralRelation::*)()) &Expr_GeneralRelation::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_GeneralRelation.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_GeneralRelation.def("NbOfSubRelations", (Standard_Integer (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
	cls_Expr_GeneralRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me>.");
	cls_Expr_GeneralRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_GeneralRelation::*)(const Standard_Integer) const ) &Expr_GeneralRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if <index> is out of range.", py::arg("index"));
	cls_Expr_GeneralRelation.def("Contains", (Standard_Boolean (Expr_GeneralRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_GeneralRelation::Contains, "Tests if <exp> contains <var>.", py::arg("exp"));
	cls_Expr_GeneralRelation.def("Replace", (void (Expr_GeneralRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_GeneralRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_GeneralRelation.def("String", (TCollection_AsciiString (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::String, "returns a string representing <me> in a readable way.");
	cls_Expr_GeneralRelation.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralRelation::get_type_name, "None");
	cls_Expr_GeneralRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralRelation::get_type_descriptor, "None");
	cls_Expr_GeneralRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralRelation::*)() const ) &Expr_GeneralRelation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NumericValue.hxx
	py::class_<Expr_NumericValue, opencascade::handle<Expr_NumericValue>, Expr_GeneralExpression> cls_Expr_NumericValue(mod, "Expr_NumericValue", "This class describes any reel value defined in an expression.");
	cls_Expr_NumericValue.def(py::init<const Standard_Real>(), py::arg("val"));
	cls_Expr_NumericValue.def("GetValue", (Standard_Real (Expr_NumericValue::*)() const ) &Expr_NumericValue::GetValue, "None");
	cls_Expr_NumericValue.def("SetValue", (void (Expr_NumericValue::*)(const Standard_Real)) &Expr_NumericValue::SetValue, "None", py::arg("val"));
	cls_Expr_NumericValue.def("NbSubExpressions", (Standard_Integer (Expr_NumericValue::*)() const ) &Expr_NumericValue::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
	cls_Expr_NumericValue.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NumericValue::*)(const Standard_Integer) const ) &Expr_NumericValue::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_NumericValue.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const ) &Expr_NumericValue::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_NumericValue.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const ) &Expr_NumericValue::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_NumericValue.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)() const ) &Expr_NumericValue::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_NumericValue.def("ContainsUnknowns", (Standard_Boolean (Expr_NumericValue::*)() const ) &Expr_NumericValue::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
	cls_Expr_NumericValue.def("Contains", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_NumericValue::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_NumericValue.def("IsIdentical", (Standard_Boolean (Expr_NumericValue::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_NumericValue::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_NumericValue.def("IsLinear", (Standard_Boolean (Expr_NumericValue::*)() const ) &Expr_NumericValue::IsLinear, "None");
	cls_Expr_NumericValue.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_NumericValue::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_NumericValue.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_NumericValue::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_NumericValue.def("Replace", (void (Expr_NumericValue::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NumericValue::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
	cls_Expr_NumericValue.def("Evaluate", (Standard_Real (Expr_NumericValue::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_NumericValue::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
	cls_Expr_NumericValue.def("String", (TCollection_AsciiString (Expr_NumericValue::*)() const ) &Expr_NumericValue::String, "returns a string representing <me> in a readable way.");
	cls_Expr_NumericValue.def_static("get_type_name_", (const char * (*)()) &Expr_NumericValue::get_type_name, "None");
	cls_Expr_NumericValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NumericValue::get_type_descriptor, "None");
	cls_Expr_NumericValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NumericValue::*)() const ) &Expr_NumericValue::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NamedExpression.hxx
	py::class_<Expr_NamedExpression, opencascade::handle<Expr_NamedExpression>, Expr_GeneralExpression> cls_Expr_NamedExpression(mod, "Expr_NamedExpression", "Describe an expression used by its name (as constants or variables). A single reference is made to a NamedExpression in every Expression (i.e. a NamedExpression is shared).");
	cls_Expr_NamedExpression.def("GetName", (const TCollection_AsciiString & (Expr_NamedExpression::*)() const ) &Expr_NamedExpression::GetName, "None");
	cls_Expr_NamedExpression.def("SetName", (void (Expr_NamedExpression::*)(const TCollection_AsciiString &)) &Expr_NamedExpression::SetName, "None", py::arg("name"));
	cls_Expr_NamedExpression.def("IsShareable", (Standard_Boolean (Expr_NamedExpression::*)() const ) &Expr_NamedExpression::IsShareable, "Tests if <me> can be shared by one or more expressions or must be copied. This method redefines to a True value the GeneralExpression method.");
	cls_Expr_NamedExpression.def("IsIdentical", (Standard_Boolean (Expr_NamedExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_NamedExpression::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_NamedExpression.def("String", (TCollection_AsciiString (Expr_NamedExpression::*)() const ) &Expr_NamedExpression::String, "returns a string representing <me> in a readable way.");
	cls_Expr_NamedExpression.def_static("get_type_name_", (const char * (*)()) &Expr_NamedExpression::get_type_name, "None");
	cls_Expr_NamedExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedExpression::get_type_descriptor, "None");
	cls_Expr_NamedExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedExpression::*)() const ) &Expr_NamedExpression::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NamedConstant.hxx
	py::class_<Expr_NamedConstant, opencascade::handle<Expr_NamedConstant>, Expr_NamedExpression> cls_Expr_NamedConstant(mod, "Expr_NamedConstant", "Describes any numeric constant known by a special name (as PI, e,...).");
	cls_Expr_NamedConstant.def(py::init<const TCollection_AsciiString &, const Standard_Real>(), py::arg("name"), py::arg("value"));
	cls_Expr_NamedConstant.def("GetValue", (Standard_Real (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::GetValue, "None");
	cls_Expr_NamedConstant.def("NbSubExpressions", (Standard_Integer (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::NbSubExpressions, "returns the number of sub-expressions contained in <me> (always returns zero)");
	cls_Expr_NamedConstant.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedConstant::*)(const Standard_Integer) const ) &Expr_NamedConstant::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange", py::arg("I"));
	cls_Expr_NamedConstant.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::Simplified, "returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_NamedConstant.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_NamedConstant.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_NamedConstant.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::ContainsUnknowns, "Tests if <me> contains NamedUnknown. (returns always False)");
	cls_Expr_NamedConstant.def("Contains", (Standard_Boolean (Expr_NamedConstant::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_NamedConstant::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_NamedConstant.def("IsLinear", (Standard_Boolean (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::IsLinear, "None");
	cls_Expr_NamedConstant.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_NamedConstant::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_NamedConstant.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_NamedConstant::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_NamedConstant.def("Replace", (void (Expr_NamedConstant::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedConstant::Replace, "Replaces all occurences of <var> with <with> in <me>", py::arg("var"), py::arg("with"));
	cls_Expr_NamedConstant.def("Evaluate", (Standard_Real (Expr_NamedConstant::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_NamedConstant::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>.", py::arg("vars"), py::arg("vals"));
	cls_Expr_NamedConstant.def_static("get_type_name_", (const char * (*)()) &Expr_NamedConstant::get_type_name, "None");
	cls_Expr_NamedConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedConstant::get_type_descriptor, "None");
	cls_Expr_NamedConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedConstant::*)() const ) &Expr_NamedConstant::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NamedUnknown.hxx
	py::class_<Expr_NamedUnknown, opencascade::handle<Expr_NamedUnknown>, Expr_NamedExpression> cls_Expr_NamedUnknown(mod, "Expr_NamedUnknown", "This class describes any variable of an expression. Assignment is treated directly in this class.");
	cls_Expr_NamedUnknown.def(py::init<const TCollection_AsciiString &>(), py::arg("name"));
	cls_Expr_NamedUnknown.def("IsAssigned", (Standard_Boolean (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::IsAssigned, "Tests if an expression is assigned to <me>.");
	cls_Expr_NamedUnknown.def("AssignedExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::AssignedExpression, "If exists, returns the assigned expression. An exception is raised if the expression does not exist.");
	cls_Expr_NamedUnknown.def("Assign", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Assign, "Assigns <me> to <exp> expression. Raises exception if <exp> refers to <me>.", py::arg("exp"));
	cls_Expr_NamedUnknown.def("Deassign", (void (Expr_NamedUnknown::*)()) &Expr_NamedUnknown::Deassign, "Supresses the assigned expression");
	cls_Expr_NamedUnknown.def("NbSubExpressions", (Standard_Integer (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
	cls_Expr_NamedUnknown.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_NamedUnknown::*)(const Standard_Integer) const ) &Expr_NamedUnknown::SubExpression, "Returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_NamedUnknown.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_NamedUnknown.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_NamedUnknown.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_NamedUnknown.def("ContainsUnknowns", (Standard_Boolean (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::ContainsUnknowns, "Tests if <me> contains NamedUnknown.");
	cls_Expr_NamedUnknown.def("Contains", (Standard_Boolean (Expr_NamedUnknown::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_NamedUnknown::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_NamedUnknown.def("IsLinear", (Standard_Boolean (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::IsLinear, "None");
	cls_Expr_NamedUnknown.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_NamedUnknown::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_NamedUnknown.def("Replace", (void (Expr_NamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedUnknown::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_NamedUnknown.def("Evaluate", (Standard_Real (Expr_NamedUnknown::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_NamedUnknown::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_NamedUnknown.def_static("get_type_name_", (const char * (*)()) &Expr_NamedUnknown::get_type_name, "None");
	cls_Expr_NamedUnknown.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedUnknown::get_type_descriptor, "None");
	cls_Expr_NamedUnknown.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedUnknown::*)() const ) &Expr_NamedUnknown::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_UnaryExpression.hxx
	py::class_<Expr_UnaryExpression, opencascade::handle<Expr_UnaryExpression>, Expr_GeneralExpression> cls_Expr_UnaryExpression(mod, "Expr_UnaryExpression", "None");
	cls_Expr_UnaryExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)() const ) &Expr_UnaryExpression::Operand, "Returns the operand used");
	cls_Expr_UnaryExpression.def("SetOperand", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::SetOperand, "Sets the operand used Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
	cls_Expr_UnaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_UnaryExpression::*)() const ) &Expr_UnaryExpression::NbSubExpressions, "Returns the number of sub-expressions contained in <me> ( >= 0)");
	cls_Expr_UnaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_UnaryExpression::*)(const Standard_Integer) const ) &Expr_UnaryExpression::SubExpression, "Returns the <I>-th sub-expression of <me>. Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_UnaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_UnaryExpression::*)() const ) &Expr_UnaryExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
	cls_Expr_UnaryExpression.def("Contains", (Standard_Boolean (Expr_UnaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_UnaryExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_UnaryExpression.def("Replace", (void (Expr_UnaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_UnaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_UnaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryExpression::*)() const ) &Expr_UnaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_UnaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryExpression::get_type_name, "None");
	cls_Expr_UnaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryExpression::get_type_descriptor, "None");
	cls_Expr_UnaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryExpression::*)() const ) &Expr_UnaryExpression::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Absolute.hxx
	py::class_<Expr_Absolute, opencascade::handle<Expr_Absolute>, Expr_UnaryExpression> cls_Expr_Absolute(mod, "Expr_Absolute", "None");
	cls_Expr_Absolute.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Absolute.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)() const ) &Expr_Absolute::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Absolute.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)() const ) &Expr_Absolute::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Absolute.def("IsIdentical", (Standard_Boolean (Expr_Absolute::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Absolute::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Absolute.def("IsLinear", (Standard_Boolean (Expr_Absolute::*)() const ) &Expr_Absolute::IsLinear, "None");
	cls_Expr_Absolute.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Absolute::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Absolute::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Absolute.def("Evaluate", (Standard_Real (Expr_Absolute::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Absolute::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Absolute.def("String", (TCollection_AsciiString (Expr_Absolute::*)() const ) &Expr_Absolute::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Absolute.def_static("get_type_name_", (const char * (*)()) &Expr_Absolute::get_type_name, "None");
	cls_Expr_Absolute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Absolute::get_type_descriptor, "None");
	cls_Expr_Absolute.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Absolute::*)() const ) &Expr_Absolute::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArcCosine.hxx
	py::class_<Expr_ArcCosine, opencascade::handle<Expr_ArcCosine>, Expr_UnaryExpression> cls_Expr_ArcCosine(mod, "Expr_ArcCosine", "None");
	cls_Expr_ArcCosine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArcCosine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)() const ) &Expr_ArcCosine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArcCosine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)() const ) &Expr_ArcCosine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArcCosine.def("IsIdentical", (Standard_Boolean (Expr_ArcCosine::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArcCosine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArcCosine.def("IsLinear", (Standard_Boolean (Expr_ArcCosine::*)() const ) &Expr_ArcCosine::IsLinear, "None");
	cls_Expr_ArcCosine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcCosine::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArcCosine::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArcCosine.def("Evaluate", (Standard_Real (Expr_ArcCosine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArcCosine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArcCosine.def("String", (TCollection_AsciiString (Expr_ArcCosine::*)() const ) &Expr_ArcCosine::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArcCosine.def_static("get_type_name_", (const char * (*)()) &Expr_ArcCosine::get_type_name, "None");
	cls_Expr_ArcCosine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcCosine::get_type_descriptor, "None");
	cls_Expr_ArcCosine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcCosine::*)() const ) &Expr_ArcCosine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArcSine.hxx
	py::class_<Expr_ArcSine, opencascade::handle<Expr_ArcSine>, Expr_UnaryExpression> cls_Expr_ArcSine(mod, "Expr_ArcSine", "None");
	cls_Expr_ArcSine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArcSine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)() const ) &Expr_ArcSine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArcSine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)() const ) &Expr_ArcSine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArcSine.def("IsIdentical", (Standard_Boolean (Expr_ArcSine::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArcSine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArcSine.def("IsLinear", (Standard_Boolean (Expr_ArcSine::*)() const ) &Expr_ArcSine::IsLinear, "None");
	cls_Expr_ArcSine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcSine::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArcSine::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArcSine.def("Evaluate", (Standard_Real (Expr_ArcSine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArcSine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArcSine.def("String", (TCollection_AsciiString (Expr_ArcSine::*)() const ) &Expr_ArcSine::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArcSine.def_static("get_type_name_", (const char * (*)()) &Expr_ArcSine::get_type_name, "None");
	cls_Expr_ArcSine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcSine::get_type_descriptor, "None");
	cls_Expr_ArcSine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcSine::*)() const ) &Expr_ArcSine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArcTangent.hxx
	py::class_<Expr_ArcTangent, opencascade::handle<Expr_ArcTangent>, Expr_UnaryExpression> cls_Expr_ArcTangent(mod, "Expr_ArcTangent", "None");
	cls_Expr_ArcTangent.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArcTangent.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)() const ) &Expr_ArcTangent::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArcTangent.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)() const ) &Expr_ArcTangent::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArcTangent.def("IsIdentical", (Standard_Boolean (Expr_ArcTangent::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArcTangent::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArcTangent.def("IsLinear", (Standard_Boolean (Expr_ArcTangent::*)() const ) &Expr_ArcTangent::IsLinear, "None");
	cls_Expr_ArcTangent.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArcTangent::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArcTangent::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArcTangent.def("Evaluate", (Standard_Real (Expr_ArcTangent::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArcTangent::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArcTangent.def("String", (TCollection_AsciiString (Expr_ArcTangent::*)() const ) &Expr_ArcTangent::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArcTangent.def_static("get_type_name_", (const char * (*)()) &Expr_ArcTangent::get_type_name, "None");
	cls_Expr_ArcTangent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArcTangent::get_type_descriptor, "None");
	cls_Expr_ArcTangent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArcTangent::*)() const ) &Expr_ArcTangent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArgCosh.hxx
	py::class_<Expr_ArgCosh, opencascade::handle<Expr_ArgCosh>, Expr_UnaryExpression> cls_Expr_ArgCosh(mod, "Expr_ArgCosh", "None");
	cls_Expr_ArgCosh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArgCosh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)() const ) &Expr_ArgCosh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArgCosh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)() const ) &Expr_ArgCosh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArgCosh.def("IsIdentical", (Standard_Boolean (Expr_ArgCosh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArgCosh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArgCosh.def("IsLinear", (Standard_Boolean (Expr_ArgCosh::*)() const ) &Expr_ArgCosh::IsLinear, "None");
	cls_Expr_ArgCosh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgCosh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArgCosh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArgCosh.def("Evaluate", (Standard_Real (Expr_ArgCosh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArgCosh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArgCosh.def("String", (TCollection_AsciiString (Expr_ArgCosh::*)() const ) &Expr_ArgCosh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArgCosh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgCosh::get_type_name, "None");
	cls_Expr_ArgCosh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgCosh::get_type_descriptor, "None");
	cls_Expr_ArgCosh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgCosh::*)() const ) &Expr_ArgCosh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArgSinh.hxx
	py::class_<Expr_ArgSinh, opencascade::handle<Expr_ArgSinh>, Expr_UnaryExpression> cls_Expr_ArgSinh(mod, "Expr_ArgSinh", "None");
	cls_Expr_ArgSinh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArgSinh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)() const ) &Expr_ArgSinh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArgSinh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)() const ) &Expr_ArgSinh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArgSinh.def("IsIdentical", (Standard_Boolean (Expr_ArgSinh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArgSinh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArgSinh.def("IsLinear", (Standard_Boolean (Expr_ArgSinh::*)() const ) &Expr_ArgSinh::IsLinear, "None");
	cls_Expr_ArgSinh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgSinh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArgSinh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArgSinh.def("Evaluate", (Standard_Real (Expr_ArgSinh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArgSinh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArgSinh.def("String", (TCollection_AsciiString (Expr_ArgSinh::*)() const ) &Expr_ArgSinh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArgSinh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgSinh::get_type_name, "None");
	cls_Expr_ArgSinh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgSinh::get_type_descriptor, "None");
	cls_Expr_ArgSinh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgSinh::*)() const ) &Expr_ArgSinh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ArgTanh.hxx
	py::class_<Expr_ArgTanh, opencascade::handle<Expr_ArgTanh>, Expr_UnaryExpression> cls_Expr_ArgTanh(mod, "Expr_ArgTanh", "None");
	cls_Expr_ArgTanh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_ArgTanh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)() const ) &Expr_ArgTanh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_ArgTanh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)() const ) &Expr_ArgTanh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_ArgTanh.def("IsIdentical", (Standard_Boolean (Expr_ArgTanh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_ArgTanh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_ArgTanh.def("IsLinear", (Standard_Boolean (Expr_ArgTanh::*)() const ) &Expr_ArgTanh::IsLinear, "None");
	cls_Expr_ArgTanh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_ArgTanh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_ArgTanh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_ArgTanh.def("Evaluate", (Standard_Real (Expr_ArgTanh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_ArgTanh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_ArgTanh.def("String", (TCollection_AsciiString (Expr_ArgTanh::*)() const ) &Expr_ArgTanh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_ArgTanh.def_static("get_type_name_", (const char * (*)()) &Expr_ArgTanh::get_type_name, "None");
	cls_Expr_ArgTanh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ArgTanh::get_type_descriptor, "None");
	cls_Expr_ArgTanh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ArgTanh::*)() const ) &Expr_ArgTanh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Cosh.hxx
	py::class_<Expr_Cosh, opencascade::handle<Expr_Cosh>, Expr_UnaryExpression> cls_Expr_Cosh(mod, "Expr_Cosh", "None");
	cls_Expr_Cosh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Cosh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)() const ) &Expr_Cosh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Cosh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)() const ) &Expr_Cosh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Cosh.def("IsIdentical", (Standard_Boolean (Expr_Cosh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Cosh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Cosh.def("IsLinear", (Standard_Boolean (Expr_Cosh::*)() const ) &Expr_Cosh::IsLinear, "None");
	cls_Expr_Cosh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Cosh::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Cosh.def("Evaluate", (Standard_Real (Expr_Cosh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Cosh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Cosh.def("String", (TCollection_AsciiString (Expr_Cosh::*)() const ) &Expr_Cosh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Cosh.def_static("get_type_name_", (const char * (*)()) &Expr_Cosh::get_type_name, "None");
	cls_Expr_Cosh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Cosh::get_type_descriptor, "None");
	cls_Expr_Cosh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Cosh::*)() const ) &Expr_Cosh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Cosine.hxx
	py::class_<Expr_Cosine, opencascade::handle<Expr_Cosine>, Expr_UnaryExpression> cls_Expr_Cosine(mod, "Expr_Cosine", "None");
	cls_Expr_Cosine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("Exp"));
	cls_Expr_Cosine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)() const ) &Expr_Cosine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Cosine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)() const ) &Expr_Cosine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Cosine.def("IsIdentical", (Standard_Boolean (Expr_Cosine::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Cosine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Cosine.def("IsLinear", (Standard_Boolean (Expr_Cosine::*)() const ) &Expr_Cosine::IsLinear, "None");
	cls_Expr_Cosine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Cosine::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Cosine::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Cosine.def("Evaluate", (Standard_Real (Expr_Cosine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Cosine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Cosine.def("String", (TCollection_AsciiString (Expr_Cosine::*)() const ) &Expr_Cosine::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Cosine.def_static("get_type_name_", (const char * (*)()) &Expr_Cosine::get_type_name, "None");
	cls_Expr_Cosine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Cosine::get_type_descriptor, "None");
	cls_Expr_Cosine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Cosine::*)() const ) &Expr_Cosine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Exponential.hxx
	py::class_<Expr_Exponential, opencascade::handle<Expr_Exponential>, Expr_UnaryExpression> cls_Expr_Exponential(mod, "Expr_Exponential", "None");
	cls_Expr_Exponential.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Exponential.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)() const ) &Expr_Exponential::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Exponential.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)() const ) &Expr_Exponential::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Exponential.def("IsIdentical", (Standard_Boolean (Expr_Exponential::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Exponential::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Exponential.def("IsLinear", (Standard_Boolean (Expr_Exponential::*)() const ) &Expr_Exponential::IsLinear, "None");
	cls_Expr_Exponential.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponential::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Exponential::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Exponential.def("Evaluate", (Standard_Real (Expr_Exponential::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Exponential::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Exponential.def("String", (TCollection_AsciiString (Expr_Exponential::*)() const ) &Expr_Exponential::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Exponential.def_static("get_type_name_", (const char * (*)()) &Expr_Exponential::get_type_name, "None");
	cls_Expr_Exponential.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Exponential::get_type_descriptor, "None");
	cls_Expr_Exponential.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Exponential::*)() const ) &Expr_Exponential::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_LogOf10.hxx
	py::class_<Expr_LogOf10, opencascade::handle<Expr_LogOf10>, Expr_UnaryExpression> cls_Expr_LogOf10(mod, "Expr_LogOf10", "None");
	cls_Expr_LogOf10.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_LogOf10.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)() const ) &Expr_LogOf10::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_LogOf10.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)() const ) &Expr_LogOf10::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_LogOf10.def("IsIdentical", (Standard_Boolean (Expr_LogOf10::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_LogOf10::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_LogOf10.def("IsLinear", (Standard_Boolean (Expr_LogOf10::*)() const ) &Expr_LogOf10::IsLinear, "None");
	cls_Expr_LogOf10.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOf10::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_LogOf10::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_LogOf10.def("Evaluate", (Standard_Real (Expr_LogOf10::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_LogOf10::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_LogOf10.def("String", (TCollection_AsciiString (Expr_LogOf10::*)() const ) &Expr_LogOf10::String, "returns a string representing <me> in a readable way.");
	cls_Expr_LogOf10.def_static("get_type_name_", (const char * (*)()) &Expr_LogOf10::get_type_name, "None");
	cls_Expr_LogOf10.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LogOf10::get_type_descriptor, "None");
	cls_Expr_LogOf10.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LogOf10::*)() const ) &Expr_LogOf10::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_LogOfe.hxx
	py::class_<Expr_LogOfe, opencascade::handle<Expr_LogOfe>, Expr_UnaryExpression> cls_Expr_LogOfe(mod, "Expr_LogOfe", "None");
	cls_Expr_LogOfe.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_LogOfe.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)() const ) &Expr_LogOfe::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_LogOfe.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)() const ) &Expr_LogOfe::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_LogOfe.def("IsIdentical", (Standard_Boolean (Expr_LogOfe::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_LogOfe::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_LogOfe.def("IsLinear", (Standard_Boolean (Expr_LogOfe::*)() const ) &Expr_LogOfe::IsLinear, "None");
	cls_Expr_LogOfe.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_LogOfe::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_LogOfe::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_LogOfe.def("Evaluate", (Standard_Real (Expr_LogOfe::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_LogOfe::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_LogOfe.def("String", (TCollection_AsciiString (Expr_LogOfe::*)() const ) &Expr_LogOfe::String, "returns a string representing <me> in a readable way.");
	cls_Expr_LogOfe.def_static("get_type_name_", (const char * (*)()) &Expr_LogOfe::get_type_name, "None");
	cls_Expr_LogOfe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LogOfe::get_type_descriptor, "None");
	cls_Expr_LogOfe.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LogOfe::*)() const ) &Expr_LogOfe::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Sign.hxx
	py::class_<Expr_Sign, opencascade::handle<Expr_Sign>, Expr_UnaryExpression> cls_Expr_Sign(mod, "Expr_Sign", "None");
	cls_Expr_Sign.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Sign.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)() const ) &Expr_Sign::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Sign.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)() const ) &Expr_Sign::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Sign.def("IsIdentical", (Standard_Boolean (Expr_Sign::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Sign::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Sign.def("IsLinear", (Standard_Boolean (Expr_Sign::*)() const ) &Expr_Sign::IsLinear, "None");
	cls_Expr_Sign.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sign::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Sign::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Sign.def("Evaluate", (Standard_Real (Expr_Sign::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Sign::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Sign.def("String", (TCollection_AsciiString (Expr_Sign::*)() const ) &Expr_Sign::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Sign.def_static("get_type_name_", (const char * (*)()) &Expr_Sign::get_type_name, "None");
	cls_Expr_Sign.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sign::get_type_descriptor, "None");
	cls_Expr_Sign.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sign::*)() const ) &Expr_Sign::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Sine.hxx
	py::class_<Expr_Sine, opencascade::handle<Expr_Sine>, Expr_UnaryExpression> cls_Expr_Sine(mod, "Expr_Sine", "None");
	cls_Expr_Sine.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Sine.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)() const ) &Expr_Sine::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Sine.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)() const ) &Expr_Sine::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Sine.def("IsIdentical", (Standard_Boolean (Expr_Sine::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Sine::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Sine.def("IsLinear", (Standard_Boolean (Expr_Sine::*)() const ) &Expr_Sine::IsLinear, "None");
	cls_Expr_Sine.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sine::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Sine::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Sine.def("Evaluate", (Standard_Real (Expr_Sine::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Sine::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Sine.def("String", (TCollection_AsciiString (Expr_Sine::*)() const ) &Expr_Sine::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Sine.def_static("get_type_name_", (const char * (*)()) &Expr_Sine::get_type_name, "None");
	cls_Expr_Sine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sine::get_type_descriptor, "None");
	cls_Expr_Sine.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sine::*)() const ) &Expr_Sine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Sinh.hxx
	py::class_<Expr_Sinh, opencascade::handle<Expr_Sinh>, Expr_UnaryExpression> cls_Expr_Sinh(mod, "Expr_Sinh", "None");
	cls_Expr_Sinh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Sinh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)() const ) &Expr_Sinh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Sinh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)() const ) &Expr_Sinh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Sinh.def("IsIdentical", (Standard_Boolean (Expr_Sinh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Sinh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Sinh.def("IsLinear", (Standard_Boolean (Expr_Sinh::*)() const ) &Expr_Sinh::IsLinear, "None");
	cls_Expr_Sinh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sinh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Sinh::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Sinh.def("Evaluate", (Standard_Real (Expr_Sinh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Sinh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Sinh.def("String", (TCollection_AsciiString (Expr_Sinh::*)() const ) &Expr_Sinh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Sinh.def_static("get_type_name_", (const char * (*)()) &Expr_Sinh::get_type_name, "None");
	cls_Expr_Sinh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sinh::get_type_descriptor, "None");
	cls_Expr_Sinh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sinh::*)() const ) &Expr_Sinh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Square.hxx
	py::class_<Expr_Square, opencascade::handle<Expr_Square>, Expr_UnaryExpression> cls_Expr_Square(mod, "Expr_Square", "None");
	cls_Expr_Square.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Square.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)() const ) &Expr_Square::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Square.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)() const ) &Expr_Square::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Square.def("IsIdentical", (Standard_Boolean (Expr_Square::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Square::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Square.def("IsLinear", (Standard_Boolean (Expr_Square::*)() const ) &Expr_Square::IsLinear, "None");
	cls_Expr_Square.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Square::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Square::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Square.def("Evaluate", (Standard_Real (Expr_Square::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Square::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Square.def("String", (TCollection_AsciiString (Expr_Square::*)() const ) &Expr_Square::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Square.def_static("get_type_name_", (const char * (*)()) &Expr_Square::get_type_name, "None");
	cls_Expr_Square.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Square::get_type_descriptor, "None");
	cls_Expr_Square.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Square::*)() const ) &Expr_Square::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_SquareRoot.hxx
	py::class_<Expr_SquareRoot, opencascade::handle<Expr_SquareRoot>, Expr_UnaryExpression> cls_Expr_SquareRoot(mod, "Expr_SquareRoot", "None");
	cls_Expr_SquareRoot.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_SquareRoot.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)() const ) &Expr_SquareRoot::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_SquareRoot.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)() const ) &Expr_SquareRoot::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_SquareRoot.def("IsIdentical", (Standard_Boolean (Expr_SquareRoot::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_SquareRoot::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_SquareRoot.def("IsLinear", (Standard_Boolean (Expr_SquareRoot::*)() const ) &Expr_SquareRoot::IsLinear, "None");
	cls_Expr_SquareRoot.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_SquareRoot::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_SquareRoot::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_SquareRoot.def("Evaluate", (Standard_Real (Expr_SquareRoot::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_SquareRoot::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_SquareRoot.def("String", (TCollection_AsciiString (Expr_SquareRoot::*)() const ) &Expr_SquareRoot::String, "returns a string representing <me> in a readable way.");
	cls_Expr_SquareRoot.def_static("get_type_name_", (const char * (*)()) &Expr_SquareRoot::get_type_name, "None");
	cls_Expr_SquareRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SquareRoot::get_type_descriptor, "None");
	cls_Expr_SquareRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SquareRoot::*)() const ) &Expr_SquareRoot::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Tangent.hxx
	py::class_<Expr_Tangent, opencascade::handle<Expr_Tangent>, Expr_UnaryExpression> cls_Expr_Tangent(mod, "Expr_Tangent", "None");
	cls_Expr_Tangent.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Tangent.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)() const ) &Expr_Tangent::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Tangent.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)() const ) &Expr_Tangent::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Tangent.def("IsIdentical", (Standard_Boolean (Expr_Tangent::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Tangent::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Tangent.def("IsLinear", (Standard_Boolean (Expr_Tangent::*)() const ) &Expr_Tangent::IsLinear, "None");
	cls_Expr_Tangent.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Tangent::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Tangent::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Tangent.def("Evaluate", (Standard_Real (Expr_Tangent::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Tangent::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Tangent.def("String", (TCollection_AsciiString (Expr_Tangent::*)() const ) &Expr_Tangent::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Tangent.def_static("get_type_name_", (const char * (*)()) &Expr_Tangent::get_type_name, "None");
	cls_Expr_Tangent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Tangent::get_type_descriptor, "None");
	cls_Expr_Tangent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Tangent::*)() const ) &Expr_Tangent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Tanh.hxx
	py::class_<Expr_Tanh, opencascade::handle<Expr_Tanh>, Expr_UnaryExpression> cls_Expr_Tanh(mod, "Expr_Tanh", "None");
	cls_Expr_Tanh.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_Tanh.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)() const ) &Expr_Tanh::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Tanh.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)() const ) &Expr_Tanh::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Tanh.def("IsIdentical", (Standard_Boolean (Expr_Tanh::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Tanh::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Tanh.def("IsLinear", (Standard_Boolean (Expr_Tanh::*)() const ) &Expr_Tanh::IsLinear, "None");
	cls_Expr_Tanh.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Tanh::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Tanh::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Tanh.def("Evaluate", (Standard_Real (Expr_Tanh::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Tanh::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Tanh.def("String", (TCollection_AsciiString (Expr_Tanh::*)() const ) &Expr_Tanh::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Tanh.def_static("get_type_name_", (const char * (*)()) &Expr_Tanh::get_type_name, "None");
	cls_Expr_Tanh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Tanh::get_type_descriptor, "None");
	cls_Expr_Tanh.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Tanh::*)() const ) &Expr_Tanh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_UnaryFunction.hxx
	py::class_<Expr_UnaryFunction, opencascade::handle<Expr_UnaryFunction>, Expr_UnaryExpression> cls_Expr_UnaryFunction(mod, "Expr_UnaryFunction", "Defines the use of an unary function in an expression with a given argument.");
	cls_Expr_UnaryFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("func"), py::arg("exp"));
	cls_Expr_UnaryFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::Function, "Returns the function defining <me>.");
	cls_Expr_UnaryFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_UnaryFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_UnaryFunction.def("IsIdentical", (Standard_Boolean (Expr_UnaryFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_UnaryFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_UnaryFunction.def("IsLinear", (Standard_Boolean (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::IsLinear, "None");
	cls_Expr_UnaryFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_UnaryFunction::Derivative, "returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_UnaryFunction.def("Evaluate", (Standard_Real (Expr_UnaryFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_UnaryFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_UnaryFunction.def("String", (TCollection_AsciiString (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::String, "returns a string representing <me> in a readable way.");
	cls_Expr_UnaryFunction.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryFunction::get_type_name, "None");
	cls_Expr_UnaryFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryFunction::get_type_descriptor, "None");
	cls_Expr_UnaryFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryFunction::*)() const ) &Expr_UnaryFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_UnaryMinus.hxx
	py::class_<Expr_UnaryMinus, opencascade::handle<Expr_UnaryMinus>, Expr_UnaryExpression> cls_Expr_UnaryMinus(mod, "Expr_UnaryMinus", "None");
	cls_Expr_UnaryMinus.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_UnaryMinus.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)() const ) &Expr_UnaryMinus::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_UnaryMinus.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)() const ) &Expr_UnaryMinus::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_UnaryMinus.def("IsIdentical", (Standard_Boolean (Expr_UnaryMinus::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_UnaryMinus::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_UnaryMinus.def("IsLinear", (Standard_Boolean (Expr_UnaryMinus::*)() const ) &Expr_UnaryMinus::IsLinear, "None");
	cls_Expr_UnaryMinus.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_UnaryMinus::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_UnaryMinus.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_UnaryMinus::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_UnaryMinus::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_UnaryMinus.def("Evaluate", (Standard_Real (Expr_UnaryMinus::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_UnaryMinus::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_UnaryMinus.def("String", (TCollection_AsciiString (Expr_UnaryMinus::*)() const ) &Expr_UnaryMinus::String, "returns a string representing <me> in a readable way.");
	cls_Expr_UnaryMinus.def_static("get_type_name_", (const char * (*)()) &Expr_UnaryMinus::get_type_name, "None");
	cls_Expr_UnaryMinus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_UnaryMinus::get_type_descriptor, "None");
	cls_Expr_UnaryMinus.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_UnaryMinus::*)() const ) &Expr_UnaryMinus::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_BinaryExpression.hxx
	py::class_<Expr_BinaryExpression, opencascade::handle<Expr_BinaryExpression>, Expr_GeneralExpression> cls_Expr_BinaryExpression(mod, "Expr_BinaryExpression", "Defines all binary expressions. The order of the two operands is significant.");
	cls_Expr_BinaryExpression.def("FirstOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::FirstOperand, "None");
	cls_Expr_BinaryExpression.def("SecondOperand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::SecondOperand, "None");
	cls_Expr_BinaryExpression.def("SetFirstOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetFirstOperand, "Sets first operand of <me> Raises InvalidOperand if exp = me", py::arg("exp"));
	cls_Expr_BinaryExpression.def("SetSecondOperand", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::SetSecondOperand, "Sets second operand of <me> Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"));
	cls_Expr_BinaryExpression.def("NbSubExpressions", (Standard_Integer (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 0)");
	cls_Expr_BinaryExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_BinaryExpression::*)(const Standard_Integer) const ) &Expr_BinaryExpression::SubExpression, "returns the <I>-th sub-expression of <me> raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_BinaryExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::ContainsUnknowns, "Does <me> contain NamedUnknown ?");
	cls_Expr_BinaryExpression.def("Contains", (Standard_Boolean (Expr_BinaryExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_BinaryExpression::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
	cls_Expr_BinaryExpression.def("Replace", (void (Expr_BinaryExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_BinaryExpression::Replace, "Replaces all occurences of <var> with <with> in <me>. Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_BinaryExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_BinaryExpression.def_static("get_type_name_", (const char * (*)()) &Expr_BinaryExpression::get_type_name, "None");
	cls_Expr_BinaryExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_BinaryExpression::get_type_descriptor, "None");
	cls_Expr_BinaryExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_BinaryExpression::*)() const ) &Expr_BinaryExpression::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_BinaryFunction.hxx
	py::class_<Expr_BinaryFunction, opencascade::handle<Expr_BinaryFunction>, Expr_BinaryExpression> cls_Expr_BinaryFunction(mod, "Expr_BinaryFunction", "Defines the use of a binary function in an expression with given arguments.");
	cls_Expr_BinaryFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("func"), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_BinaryFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::Function, "Returns the function defining <me>.");
	cls_Expr_BinaryFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_BinaryFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_BinaryFunction.def("IsIdentical", (Standard_Boolean (Expr_BinaryFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_BinaryFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_BinaryFunction.def("IsLinear", (Standard_Boolean (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::IsLinear, "None");
	cls_Expr_BinaryFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_BinaryFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_BinaryFunction::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_BinaryFunction.def("Evaluate", (Standard_Real (Expr_BinaryFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_BinaryFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_BinaryFunction.def("String", (TCollection_AsciiString (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::String, "returns a string representing <me> in a readable way.");
	cls_Expr_BinaryFunction.def_static("get_type_name_", (const char * (*)()) &Expr_BinaryFunction::get_type_name, "None");
	cls_Expr_BinaryFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_BinaryFunction::get_type_descriptor, "None");
	cls_Expr_BinaryFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_BinaryFunction::*)() const ) &Expr_BinaryFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Difference.hxx
	py::class_<Expr_Difference, opencascade::handle<Expr_Difference>, Expr_BinaryExpression> cls_Expr_Difference(mod, "Expr_Difference", "None");
	cls_Expr_Difference.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Difference.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)() const ) &Expr_Difference::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Difference.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)() const ) &Expr_Difference::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Difference.def("IsIdentical", (Standard_Boolean (Expr_Difference::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Difference::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Difference.def("IsLinear", (Standard_Boolean (Expr_Difference::*)() const ) &Expr_Difference::IsLinear, "None");
	cls_Expr_Difference.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Difference::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Difference.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Difference::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_Difference::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_Difference.def("Evaluate", (Standard_Real (Expr_Difference::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Difference::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Difference.def("String", (TCollection_AsciiString (Expr_Difference::*)() const ) &Expr_Difference::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Difference.def_static("get_type_name_", (const char * (*)()) &Expr_Difference::get_type_name, "None");
	cls_Expr_Difference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Difference::get_type_descriptor, "None");
	cls_Expr_Difference.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Difference::*)() const ) &Expr_Difference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Division.hxx
	py::class_<Expr_Division, opencascade::handle<Expr_Division>, Expr_BinaryExpression> cls_Expr_Division(mod, "Expr_Division", "None");
	cls_Expr_Division.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Division.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const ) &Expr_Division::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Division.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)() const ) &Expr_Division::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Division.def("IsIdentical", (Standard_Boolean (Expr_Division::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Division::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Division.def("IsLinear", (Standard_Boolean (Expr_Division::*)() const ) &Expr_Division::IsLinear, "None");
	cls_Expr_Division.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Division::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Division::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Division.def("Evaluate", (Standard_Real (Expr_Division::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Division::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Division.def("String", (TCollection_AsciiString (Expr_Division::*)() const ) &Expr_Division::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Division.def_static("get_type_name_", (const char * (*)()) &Expr_Division::get_type_name, "None");
	cls_Expr_Division.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Division::get_type_descriptor, "None");
	cls_Expr_Division.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Division::*)() const ) &Expr_Division::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Exponentiate.hxx
	py::class_<Expr_Exponentiate, opencascade::handle<Expr_Exponentiate>, Expr_BinaryExpression> cls_Expr_Exponentiate(mod, "Expr_Exponentiate", "None");
	cls_Expr_Exponentiate.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Exponentiate.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)() const ) &Expr_Exponentiate::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Exponentiate.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)() const ) &Expr_Exponentiate::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Exponentiate.def("IsIdentical", (Standard_Boolean (Expr_Exponentiate::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Exponentiate::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Exponentiate.def("IsLinear", (Standard_Boolean (Expr_Exponentiate::*)() const ) &Expr_Exponentiate::IsLinear, "None");
	cls_Expr_Exponentiate.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Exponentiate::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Exponentiate::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Exponentiate.def("Evaluate", (Standard_Real (Expr_Exponentiate::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Exponentiate::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Exponentiate.def("String", (TCollection_AsciiString (Expr_Exponentiate::*)() const ) &Expr_Exponentiate::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Exponentiate.def_static("get_type_name_", (const char * (*)()) &Expr_Exponentiate::get_type_name, "None");
	cls_Expr_Exponentiate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Exponentiate::get_type_descriptor, "None");
	cls_Expr_Exponentiate.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Exponentiate::*)() const ) &Expr_Exponentiate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_PolyExpression.hxx
	py::class_<Expr_PolyExpression, opencascade::handle<Expr_PolyExpression>, Expr_GeneralExpression> cls_Expr_PolyExpression(mod, "Expr_PolyExpression", "None");
	cls_Expr_PolyExpression.def("NbOperands", (Standard_Integer (Expr_PolyExpression::*)() const ) &Expr_PolyExpression::NbOperands, "returns the number of operands contained in <me>");
	cls_Expr_PolyExpression.def("Operand", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const ) &Expr_PolyExpression::Operand, "Returns the <index>-th operand used in <me>. An exception is raised if index is out of range", py::arg("index"));
	cls_Expr_PolyExpression.def("SetOperand", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, const Standard_Integer)) &Expr_PolyExpression::SetOperand, "Sets the <index>-th operand used in <me>. An exception is raised if <index> is out of range Raises InvalidOperand if <exp> contains <me>.", py::arg("exp"), py::arg("index"));
	cls_Expr_PolyExpression.def("NbSubExpressions", (Standard_Integer (Expr_PolyExpression::*)() const ) &Expr_PolyExpression::NbSubExpressions, "returns the number of sub-expressions contained in <me> ( >= 2)");
	cls_Expr_PolyExpression.def("SubExpression", (const opencascade::handle<Expr_GeneralExpression> & (Expr_PolyExpression::*)(const Standard_Integer) const ) &Expr_PolyExpression::SubExpression, "Returns the sub-expression denoted by <I> in <me> Raises OutOfRange if <I> > NbSubExpressions(me)", py::arg("I"));
	cls_Expr_PolyExpression.def("ContainsUnknowns", (Standard_Boolean (Expr_PolyExpression::*)() const ) &Expr_PolyExpression::ContainsUnknowns, "Does <me> contains NamedUnknown ?");
	cls_Expr_PolyExpression.def("Contains", (Standard_Boolean (Expr_PolyExpression::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_PolyExpression::Contains, "Tests if <exp> is contained in <me>.", py::arg("exp"));
	cls_Expr_PolyExpression.def("Replace", (void (Expr_PolyExpression::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_PolyExpression::Replace, "Replaces all occurences of <var> with <with> in <me> Raises InvalidOperand if <with> contains <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_PolyExpression.def("Simplified", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyExpression::*)() const ) &Expr_PolyExpression::Simplified, "Returns a GeneralExpression after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_PolyExpression.def_static("get_type_name_", (const char * (*)()) &Expr_PolyExpression::get_type_name, "None");
	cls_Expr_PolyExpression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_PolyExpression::get_type_descriptor, "None");
	cls_Expr_PolyExpression.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_PolyExpression::*)() const ) &Expr_PolyExpression::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_PolyFunction.hxx
	py::class_<Expr_PolyFunction, opencascade::handle<Expr_PolyFunction>, Expr_PolyExpression> cls_Expr_PolyFunction(mod, "Expr_PolyFunction", "Defines the use of an n-ary function in an expression with given arguments.");
	cls_Expr_PolyFunction.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const Expr_Array1OfGeneralExpression &>(), py::arg("func"), py::arg("exps"));
	cls_Expr_PolyFunction.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::Function, "Returns the function defining <me>.");
	cls_Expr_PolyFunction.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_PolyFunction.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_PolyFunction.def("IsIdentical", (Standard_Boolean (Expr_PolyFunction::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_PolyFunction::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_PolyFunction.def("IsLinear", (Standard_Boolean (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::IsLinear, "None");
	cls_Expr_PolyFunction.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_PolyFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_PolyFunction::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_PolyFunction.def("Evaluate", (Standard_Real (Expr_PolyFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_PolyFunction::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_PolyFunction.def("String", (TCollection_AsciiString (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::String, "returns a string representing <me> in a readable way.");
	cls_Expr_PolyFunction.def_static("get_type_name_", (const char * (*)()) &Expr_PolyFunction::get_type_name, "None");
	cls_Expr_PolyFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_PolyFunction::get_type_descriptor, "None");
	cls_Expr_PolyFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_PolyFunction::*)() const ) &Expr_PolyFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Product.hxx
	py::class_<Expr_Product, opencascade::handle<Expr_Product>, Expr_PolyExpression> cls_Expr_Product(mod, "Expr_Product", "None");
	cls_Expr_Product.def(py::init<const Expr_SequenceOfGeneralExpression &>(), py::arg("exps"));
	cls_Expr_Product.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Product.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)() const ) &Expr_Product::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Product.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)() const ) &Expr_Product::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Product.def("IsIdentical", (Standard_Boolean (Expr_Product::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Product::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Product.def("IsLinear", (Standard_Boolean (Expr_Product::*)() const ) &Expr_Product::IsLinear, "None");
	cls_Expr_Product.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Product::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Product::Derivative, "Returns the derivative on <X> unknown of <me>", py::arg("X"));
	cls_Expr_Product.def("Evaluate", (Standard_Real (Expr_Product::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Product::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Product.def("String", (TCollection_AsciiString (Expr_Product::*)() const ) &Expr_Product::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Product.def_static("get_type_name_", (const char * (*)()) &Expr_Product::get_type_name, "None");
	cls_Expr_Product.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Product::get_type_descriptor, "None");
	cls_Expr_Product.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Product::*)() const ) &Expr_Product::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Sum.hxx
	py::class_<Expr_Sum, opencascade::handle<Expr_Sum>, Expr_PolyExpression> cls_Expr_Sum(mod, "Expr_Sum", "None");
	cls_Expr_Sum.def(py::init<const Expr_SequenceOfGeneralExpression &>(), py::arg("exps"));
	cls_Expr_Sum.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Sum.def("ShallowSimplified", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)() const ) &Expr_Sum::ShallowSimplified, "Returns a GeneralExpression after a simplification of the arguments of <me>.");
	cls_Expr_Sum.def("Copy", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)() const ) &Expr_Sum::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Sum.def("IsIdentical", (Standard_Boolean (Expr_Sum::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_Sum::IsIdentical, "Tests if <me> and <Other> define the same expression. This method does not include any simplification before testing.", py::arg("Other"));
	cls_Expr_Sum.def("IsLinear", (Standard_Boolean (Expr_Sum::*)() const ) &Expr_Sum::IsLinear, "None");
	cls_Expr_Sum.def("Derivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_Sum::Derivative, "Returns the derivative on <X> unknown of <me>.", py::arg("X"));
	cls_Expr_Sum.def("NDerivative", (opencascade::handle<Expr_GeneralExpression> (Expr_Sum::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_Sum::NDerivative, "Returns the <N>-th derivative on <X> unknown of <me>. Raises OutOfRange if <N> <= 0", py::arg("X"), py::arg("N"));
	cls_Expr_Sum.def("Evaluate", (Standard_Real (Expr_Sum::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_Sum::Evaluate, "Returns the value of <me> (as a Real) by replacement of <vars> by <vals>. Raises NotEvaluable if <me> contains NamedUnknown not in <vars> or NumericError if result cannot be computed.", py::arg("vars"), py::arg("vals"));
	cls_Expr_Sum.def("String", (TCollection_AsciiString (Expr_Sum::*)() const ) &Expr_Sum::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Sum.def_static("get_type_name_", (const char * (*)()) &Expr_Sum::get_type_name, "None");
	cls_Expr_Sum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Sum::get_type_descriptor, "None");
	cls_Expr_Sum.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Sum::*)() const ) &Expr_Sum::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_UnknownIterator.hxx
	py::class_<Expr_UnknownIterator, std::unique_ptr<Expr_UnknownIterator, Deleter<Expr_UnknownIterator>>> cls_Expr_UnknownIterator(mod, "Expr_UnknownIterator", "Describes an iterator on NamedUnknowns contained in any GeneralExpression.");
	cls_Expr_UnknownIterator.def(py::init<const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp"));
	cls_Expr_UnknownIterator.def("More", (Standard_Boolean (Expr_UnknownIterator::*)() const ) &Expr_UnknownIterator::More, "None");
	cls_Expr_UnknownIterator.def("Next", (void (Expr_UnknownIterator::*)()) &Expr_UnknownIterator::Next, "None");
	cls_Expr_UnknownIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_UnknownIterator::*)() const ) &Expr_UnknownIterator::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_SingleRelation.hxx
	py::class_<Expr_SingleRelation, opencascade::handle<Expr_SingleRelation>, Expr_GeneralRelation> cls_Expr_SingleRelation(mod, "Expr_SingleRelation", "None");
	cls_Expr_SingleRelation.def("SetFirstMember", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::SetFirstMember, "Defines the first member of the relation", py::arg("exp"));
	cls_Expr_SingleRelation.def("SetSecondMember", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::SetSecondMember, "Defines the second member of the relation", py::arg("exp"));
	cls_Expr_SingleRelation.def("FirstMember", (opencascade::handle<Expr_GeneralExpression> (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::FirstMember, "Returns the first member of the relation");
	cls_Expr_SingleRelation.def("SecondMember", (opencascade::handle<Expr_GeneralExpression> (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::SecondMember, "Returns the second member of the relation");
	cls_Expr_SingleRelation.def("IsLinear", (Standard_Boolean (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
	cls_Expr_SingleRelation.def("NbOfSubRelations", (Standard_Integer (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
	cls_Expr_SingleRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me> (Always 1).");
	cls_Expr_SingleRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_SingleRelation::*)(const Standard_Integer) const ) &Expr_SingleRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if index is out of range.", py::arg("index"));
	cls_Expr_SingleRelation.def("Contains", (Standard_Boolean (Expr_SingleRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_SingleRelation::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
	cls_Expr_SingleRelation.def("Replace", (void (Expr_SingleRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SingleRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_SingleRelation.def_static("get_type_name_", (const char * (*)()) &Expr_SingleRelation::get_type_name, "None");
	cls_Expr_SingleRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SingleRelation::get_type_descriptor, "None");
	cls_Expr_SingleRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SingleRelation::*)() const ) &Expr_SingleRelation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Different.hxx
	py::class_<Expr_Different, opencascade::handle<Expr_Different>, Expr_SingleRelation> cls_Expr_Different(mod, "Expr_Different", "None");
	cls_Expr_Different.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Different.def("IsSatisfied", (Standard_Boolean (Expr_Different::*)() const ) &Expr_Different::IsSatisfied, "None");
	cls_Expr_Different.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const ) &Expr_Different::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_Different.def("Simplify", (void (Expr_Different::*)()) &Expr_Different::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_Different.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_Different::*)() const ) &Expr_Different::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Different.def("String", (TCollection_AsciiString (Expr_Different::*)() const ) &Expr_Different::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Different.def_static("get_type_name_", (const char * (*)()) &Expr_Different::get_type_name, "None");
	cls_Expr_Different.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Different::get_type_descriptor, "None");
	cls_Expr_Different.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Different::*)() const ) &Expr_Different::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_Equal.hxx
	py::class_<Expr_Equal, opencascade::handle<Expr_Equal>, Expr_SingleRelation> cls_Expr_Equal(mod, "Expr_Equal", "None");
	cls_Expr_Equal.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_Equal.def("IsSatisfied", (Standard_Boolean (Expr_Equal::*)() const ) &Expr_Equal::IsSatisfied, "None");
	cls_Expr_Equal.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_Equal::*)() const ) &Expr_Equal::Simplified, "returns a GeneralRelation after replacement of NamedUnknowns by an associated expression and after values computation.");
	cls_Expr_Equal.def("Simplify", (void (Expr_Equal::*)()) &Expr_Equal::Simplify, "Replaces NamedUnknowns by an associated expressions and computes values in <me>.");
	cls_Expr_Equal.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_Equal::*)() const ) &Expr_Equal::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_Equal.def("String", (TCollection_AsciiString (Expr_Equal::*)() const ) &Expr_Equal::String, "returns a string representing <me> in a readable way.");
	cls_Expr_Equal.def_static("get_type_name_", (const char * (*)()) &Expr_Equal::get_type_name, "None");
	cls_Expr_Equal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_Equal::get_type_descriptor, "None");
	cls_Expr_Equal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_Equal::*)() const ) &Expr_Equal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_GreaterThan.hxx
	py::class_<Expr_GreaterThan, opencascade::handle<Expr_GreaterThan>, Expr_SingleRelation> cls_Expr_GreaterThan(mod, "Expr_GreaterThan", "None");
	cls_Expr_GreaterThan.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_GreaterThan.def("IsSatisfied", (Standard_Boolean (Expr_GreaterThan::*)() const ) &Expr_GreaterThan::IsSatisfied, "None");
	cls_Expr_GreaterThan.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThan::*)() const ) &Expr_GreaterThan::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_GreaterThan.def("Simplify", (void (Expr_GreaterThan::*)()) &Expr_GreaterThan::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_GreaterThan.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThan::*)() const ) &Expr_GreaterThan::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_GreaterThan.def("String", (TCollection_AsciiString (Expr_GreaterThan::*)() const ) &Expr_GreaterThan::String, "returns a string representing <me> in a readable way.");
	cls_Expr_GreaterThan.def_static("get_type_name_", (const char * (*)()) &Expr_GreaterThan::get_type_name, "None");
	cls_Expr_GreaterThan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GreaterThan::get_type_descriptor, "None");
	cls_Expr_GreaterThan.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GreaterThan::*)() const ) &Expr_GreaterThan::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_GreaterThanOrEqual.hxx
	py::class_<Expr_GreaterThanOrEqual, opencascade::handle<Expr_GreaterThanOrEqual>, Expr_SingleRelation> cls_Expr_GreaterThanOrEqual(mod, "Expr_GreaterThanOrEqual", "None");
	cls_Expr_GreaterThanOrEqual.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_GreaterThanOrEqual.def("IsSatisfied", (Standard_Boolean (Expr_GreaterThanOrEqual::*)() const ) &Expr_GreaterThanOrEqual::IsSatisfied, "None");
	cls_Expr_GreaterThanOrEqual.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const ) &Expr_GreaterThanOrEqual::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_GreaterThanOrEqual.def("Simplify", (void (Expr_GreaterThanOrEqual::*)()) &Expr_GreaterThanOrEqual::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_GreaterThanOrEqual.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_GreaterThanOrEqual::*)() const ) &Expr_GreaterThanOrEqual::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_GreaterThanOrEqual.def("String", (TCollection_AsciiString (Expr_GreaterThanOrEqual::*)() const ) &Expr_GreaterThanOrEqual::String, "returns a string representing <me> in a readable way.");
	cls_Expr_GreaterThanOrEqual.def_static("get_type_name_", (const char * (*)()) &Expr_GreaterThanOrEqual::get_type_name, "None");
	cls_Expr_GreaterThanOrEqual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GreaterThanOrEqual::get_type_descriptor, "None");
	cls_Expr_GreaterThanOrEqual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GreaterThanOrEqual::*)() const ) &Expr_GreaterThanOrEqual::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_LessThan.hxx
	py::class_<Expr_LessThan, opencascade::handle<Expr_LessThan>, Expr_SingleRelation> cls_Expr_LessThan(mod, "Expr_LessThan", "None");
	cls_Expr_LessThan.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_LessThan.def("IsSatisfied", (Standard_Boolean (Expr_LessThan::*)() const ) &Expr_LessThan::IsSatisfied, "None");
	cls_Expr_LessThan.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThan::*)() const ) &Expr_LessThan::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_LessThan.def("Simplify", (void (Expr_LessThan::*)()) &Expr_LessThan::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_LessThan.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThan::*)() const ) &Expr_LessThan::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_LessThan.def("String", (TCollection_AsciiString (Expr_LessThan::*)() const ) &Expr_LessThan::String, "returns a string representing <me> in a readable way.");
	cls_Expr_LessThan.def_static("get_type_name_", (const char * (*)()) &Expr_LessThan::get_type_name, "None");
	cls_Expr_LessThan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LessThan::get_type_descriptor, "None");
	cls_Expr_LessThan.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LessThan::*)() const ) &Expr_LessThan::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_LessThanOrEqual.hxx
	py::class_<Expr_LessThanOrEqual, opencascade::handle<Expr_LessThanOrEqual>, Expr_SingleRelation> cls_Expr_LessThanOrEqual(mod, "Expr_LessThanOrEqual", "None");
	cls_Expr_LessThanOrEqual.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const opencascade::handle<Expr_GeneralExpression> &>(), py::arg("exp1"), py::arg("exp2"));
	cls_Expr_LessThanOrEqual.def("IsSatisfied", (Standard_Boolean (Expr_LessThanOrEqual::*)() const ) &Expr_LessThanOrEqual::IsSatisfied, "None");
	cls_Expr_LessThanOrEqual.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThanOrEqual::*)() const ) &Expr_LessThanOrEqual::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_LessThanOrEqual.def("Simplify", (void (Expr_LessThanOrEqual::*)()) &Expr_LessThanOrEqual::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_LessThanOrEqual.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_LessThanOrEqual::*)() const ) &Expr_LessThanOrEqual::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_LessThanOrEqual.def("String", (TCollection_AsciiString (Expr_LessThanOrEqual::*)() const ) &Expr_LessThanOrEqual::String, "returns a string representing <me> in a readable way.");
	cls_Expr_LessThanOrEqual.def_static("get_type_name_", (const char * (*)()) &Expr_LessThanOrEqual::get_type_name, "None");
	cls_Expr_LessThanOrEqual.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_LessThanOrEqual::get_type_descriptor, "None");
	cls_Expr_LessThanOrEqual.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_LessThanOrEqual::*)() const ) &Expr_LessThanOrEqual::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_SystemRelation.hxx
	py::class_<Expr_SystemRelation, opencascade::handle<Expr_SystemRelation>, Expr_GeneralRelation> cls_Expr_SystemRelation(mod, "Expr_SystemRelation", "None");
	cls_Expr_SystemRelation.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("relation"));
	cls_Expr_SystemRelation.def("Add", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SystemRelation::Add, "Appends <relation> in the list of components of <me>.", py::arg("relation"));
	cls_Expr_SystemRelation.def("Remove", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SystemRelation::Remove, "None", py::arg("relation"));
	cls_Expr_SystemRelation.def("IsLinear", (Standard_Boolean (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::IsLinear, "Tests if <me> is linear between its NamedUnknowns.");
	cls_Expr_SystemRelation.def("NbOfSubRelations", (Standard_Integer (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::NbOfSubRelations, "Returns the number of relations contained in <me>.");
	cls_Expr_SystemRelation.def("NbOfSingleRelations", (Standard_Integer (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::NbOfSingleRelations, "Returns the number of SingleRelations contained in <me>.");
	cls_Expr_SystemRelation.def("SubRelation", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)(const Standard_Integer) const ) &Expr_SystemRelation::SubRelation, "Returns the relation denoted by <index> in <me>. An exception is raised if <index> is out of range.", py::arg("index"));
	cls_Expr_SystemRelation.def("IsSatisfied", (Standard_Boolean (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::IsSatisfied, "None");
	cls_Expr_SystemRelation.def("Simplified", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::Simplified, "Returns a GeneralRelation after replacement of NamedUnknowns by an associated expression, and after values computation.");
	cls_Expr_SystemRelation.def("Simplify", (void (Expr_SystemRelation::*)()) &Expr_SystemRelation::Simplify, "Replaces NamedUnknowns by associated expressions, and computes values in <me>.");
	cls_Expr_SystemRelation.def("Copy", (opencascade::handle<Expr_GeneralRelation> (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::Copy, "Returns a copy of <me> having the same unknowns and functions.");
	cls_Expr_SystemRelation.def("Contains", (Standard_Boolean (Expr_SystemRelation::*)(const opencascade::handle<Expr_GeneralExpression> &) const ) &Expr_SystemRelation::Contains, "Tests if <me> contains <exp>.", py::arg("exp"));
	cls_Expr_SystemRelation.def("Replace", (void (Expr_SystemRelation::*)(const opencascade::handle<Expr_NamedUnknown> &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SystemRelation::Replace, "Replaces all occurences of <var> with <with> in <me>.", py::arg("var"), py::arg("with"));
	cls_Expr_SystemRelation.def("String", (TCollection_AsciiString (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::String, "returns a string representing <me> in a readable way.");
	cls_Expr_SystemRelation.def_static("get_type_name_", (const char * (*)()) &Expr_SystemRelation::get_type_name, "None");
	cls_Expr_SystemRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_SystemRelation::get_type_descriptor, "None");
	cls_Expr_SystemRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_SystemRelation::*)() const ) &Expr_SystemRelation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_RelationIterator.hxx
	py::class_<Expr_RelationIterator, std::unique_ptr<Expr_RelationIterator, Deleter<Expr_RelationIterator>>> cls_Expr_RelationIterator(mod, "Expr_RelationIterator", "Iterates on every basic relation contained in a GeneralRelation.");
	cls_Expr_RelationIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));
	cls_Expr_RelationIterator.def("More", (Standard_Boolean (Expr_RelationIterator::*)() const ) &Expr_RelationIterator::More, "Returns False if no other relation remains.");
	cls_Expr_RelationIterator.def("Next", (void (Expr_RelationIterator::*)()) &Expr_RelationIterator::Next, "None");
	cls_Expr_RelationIterator.def("Value", (opencascade::handle<Expr_SingleRelation> (Expr_RelationIterator::*)() const ) &Expr_RelationIterator::Value, "Returns current basic relation. Exception is raised if no more relation remains.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_RUIterator.hxx
	py::class_<Expr_RUIterator, std::unique_ptr<Expr_RUIterator, Deleter<Expr_RUIterator>>> cls_Expr_RUIterator(mod, "Expr_RUIterator", "Iterates on NamedUnknowns in a GeneralRelation.");
	cls_Expr_RUIterator.def(py::init<const opencascade::handle<Expr_GeneralRelation> &>(), py::arg("rel"));
	cls_Expr_RUIterator.def("More", (Standard_Boolean (Expr_RUIterator::*)() const ) &Expr_RUIterator::More, "Returns False if on other unknown remains.");
	cls_Expr_RUIterator.def("Next", (void (Expr_RUIterator::*)()) &Expr_RUIterator::Next, "None");
	cls_Expr_RUIterator.def("Value", (opencascade::handle<Expr_NamedUnknown> (Expr_RUIterator::*)() const ) &Expr_RUIterator::Value, "Returns current NamedUnknown. Raises exception if no more unknowns remain.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_GeneralFunction.hxx
	py::class_<Expr_GeneralFunction, opencascade::handle<Expr_GeneralFunction>, Standard_Transient> cls_Expr_GeneralFunction(mod, "Expr_GeneralFunction", "Defines the general purposes of any function.");
	cls_Expr_GeneralFunction.def("NbOfVariables", (Standard_Integer (Expr_GeneralFunction::*)() const ) &Expr_GeneralFunction::NbOfVariables, "Returns the number of variables of <me>.");
	cls_Expr_GeneralFunction.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_GeneralFunction::*)(const Standard_Integer) const ) &Expr_GeneralFunction::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if index > NbOfVariables.", py::arg("index"));
	cls_Expr_GeneralFunction.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)() const ) &Expr_GeneralFunction::Copy, "Returns a copy of <me> with the same form.");
	cls_Expr_GeneralFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_GeneralFunction::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
	cls_Expr_GeneralFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_GeneralFunction::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_GeneralFunction::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
	cls_Expr_GeneralFunction.def("Evaluate", (Standard_Real (Expr_GeneralFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_GeneralFunction::Evaluate, "Computes the value of <me> with the given variables. Raises NotEvaluable if <vars> does not match all variables of <me>.", py::arg("vars"), py::arg("vals"));
	cls_Expr_GeneralFunction.def("IsIdentical", (Standard_Boolean (Expr_GeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &) const ) &Expr_GeneralFunction::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
	cls_Expr_GeneralFunction.def("IsLinearOnVariable", (Standard_Boolean (Expr_GeneralFunction::*)(const Standard_Integer) const ) &Expr_GeneralFunction::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
	cls_Expr_GeneralFunction.def("GetStringName", (TCollection_AsciiString (Expr_GeneralFunction::*)() const ) &Expr_GeneralFunction::GetStringName, "None");
	cls_Expr_GeneralFunction.def_static("get_type_name_", (const char * (*)()) &Expr_GeneralFunction::get_type_name, "None");
	cls_Expr_GeneralFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_GeneralFunction::get_type_descriptor, "None");
	cls_Expr_GeneralFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_GeneralFunction::*)() const ) &Expr_GeneralFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NamedFunction.hxx
	py::class_<Expr_NamedFunction, opencascade::handle<Expr_NamedFunction>, Expr_GeneralFunction> cls_Expr_NamedFunction(mod, "Expr_NamedFunction", "None");
	cls_Expr_NamedFunction.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Expr_GeneralExpression> &, const Expr_Array1OfNamedUnknown &>(), py::arg("name"), py::arg("exp"), py::arg("vars"));
	cls_Expr_NamedFunction.def("SetName", (void (Expr_NamedFunction::*)(const TCollection_AsciiString &)) &Expr_NamedFunction::SetName, "Sets the name <newname> to <me>.", py::arg("newname"));
	cls_Expr_NamedFunction.def("GetName", (TCollection_AsciiString (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::GetName, "Returns the name assigned to <me>");
	cls_Expr_NamedFunction.def("NbOfVariables", (Standard_Integer (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::NbOfVariables, "Returns the number of variables of <me>.");
	cls_Expr_NamedFunction.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_NamedFunction::*)(const Standard_Integer) const ) &Expr_NamedFunction::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> is greater than NbOfVariables of <me>, or less than or equal to zero.", py::arg("index"));
	cls_Expr_NamedFunction.def("Evaluate", (Standard_Real (Expr_NamedFunction::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_NamedFunction::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
	cls_Expr_NamedFunction.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::Copy, "Returns a copy of <me> with the same form.");
	cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
	cls_Expr_NamedFunction.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_NamedFunction::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_NamedFunction::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
	cls_Expr_NamedFunction.def("IsIdentical", (Standard_Boolean (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralFunction> &) const ) &Expr_NamedFunction::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
	cls_Expr_NamedFunction.def("IsLinearOnVariable", (Standard_Boolean (Expr_NamedFunction::*)(const Standard_Integer) const ) &Expr_NamedFunction::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
	cls_Expr_NamedFunction.def("GetStringName", (TCollection_AsciiString (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::GetStringName, "None");
	cls_Expr_NamedFunction.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::Expression, "Returns equivalent expression of <me>.");
	cls_Expr_NamedFunction.def("SetExpression", (void (Expr_NamedFunction::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_NamedFunction::SetExpression, "Modifies expression of <me>. Warning: Beware of derivatives. See FunctionDerivative", py::arg("exp"));
	cls_Expr_NamedFunction.def_static("get_type_name_", (const char * (*)()) &Expr_NamedFunction::get_type_name, "None");
	cls_Expr_NamedFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NamedFunction::get_type_descriptor, "None");
	cls_Expr_NamedFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NamedFunction::*)() const ) &Expr_NamedFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_FunctionDerivative.hxx
	py::class_<Expr_FunctionDerivative, opencascade::handle<Expr_FunctionDerivative>, Expr_GeneralFunction> cls_Expr_FunctionDerivative(mod, "Expr_FunctionDerivative", "None");
	cls_Expr_FunctionDerivative.def(py::init<const opencascade::handle<Expr_GeneralFunction> &, const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer>(), py::arg("func"), py::arg("withX"), py::arg("deg"));
	cls_Expr_FunctionDerivative.def("NbOfVariables", (Standard_Integer (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::NbOfVariables, "Returns the number of variables of <me>.");
	cls_Expr_FunctionDerivative.def("Variable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)(const Standard_Integer) const ) &Expr_FunctionDerivative::Variable, "Returns the variable denoted by <index> in <me>. Raises OutOfRange if <index> greater than NbOfVariables of <me>.", py::arg("index"));
	cls_Expr_FunctionDerivative.def("Evaluate", (Standard_Real (Expr_FunctionDerivative::*)(const Expr_Array1OfNamedUnknown &, const TColStd_Array1OfReal &) const ) &Expr_FunctionDerivative::Evaluate, "Computes the value of <me> with the given variables. Raises DimensionMismatch if Length(vars) is different from Length(values).", py::arg("vars"), py::arg("values"));
	cls_Expr_FunctionDerivative.def("Copy", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::Copy, "Returns a copy of <me> with the same form.");
	cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var>.", py::arg("var"));
	cls_Expr_FunctionDerivative.def("Derivative", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer) const ) &Expr_FunctionDerivative::Derivative, "Returns Derivative of <me> for variable <var> with degree <deg>.", py::arg("var"), py::arg("deg"));
	cls_Expr_FunctionDerivative.def("IsIdentical", (Standard_Boolean (Expr_FunctionDerivative::*)(const opencascade::handle<Expr_GeneralFunction> &) const ) &Expr_FunctionDerivative::IsIdentical, "Tests if <me> and <func> are similar functions (same name and same used expression).", py::arg("func"));
	cls_Expr_FunctionDerivative.def("IsLinearOnVariable", (Standard_Boolean (Expr_FunctionDerivative::*)(const Standard_Integer) const ) &Expr_FunctionDerivative::IsLinearOnVariable, "Tests if <me> is linear on variable on range <index>", py::arg("index"));
	cls_Expr_FunctionDerivative.def("Function", (opencascade::handle<Expr_GeneralFunction> (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::Function, "Returns the function of which <me> is the derivative.");
	cls_Expr_FunctionDerivative.def("Degree", (Standard_Integer (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::Degree, "Returns the degree of derivation of <me>.");
	cls_Expr_FunctionDerivative.def("DerivVariable", (opencascade::handle<Expr_NamedUnknown> (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::DerivVariable, "Returns the derivation variable of <me>.");
	cls_Expr_FunctionDerivative.def("GetStringName", (TCollection_AsciiString (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::GetStringName, "None");
	cls_Expr_FunctionDerivative.def("Expression", (opencascade::handle<Expr_GeneralExpression> (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::Expression, "None");
	cls_Expr_FunctionDerivative.def("UpdateExpression", (void (Expr_FunctionDerivative::*)()) &Expr_FunctionDerivative::UpdateExpression, "None");
	cls_Expr_FunctionDerivative.def_static("get_type_name_", (const char * (*)()) &Expr_FunctionDerivative::get_type_name, "None");
	cls_Expr_FunctionDerivative.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_FunctionDerivative::get_type_descriptor, "None");
	cls_Expr_FunctionDerivative.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_FunctionDerivative::*)() const ) &Expr_FunctionDerivative::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr.hxx
	py::class_<Expr, std::unique_ptr<Expr, Deleter<Expr>>> cls_Expr(mod, "Expr", "This package describes the data structure of any expression, relation or function used in mathematics. It also describes the assignment of variables. Standard mathematical functions are implemented such as trigonometrics, hyperbolics, and log functions.");
	cls_Expr.def(py::init<>());
	cls_Expr.def_static("CopyShare_", (opencascade::handle<Expr_GeneralExpression> (*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr::CopyShare, "None", py::arg("exp"));
	cls_Expr.def_static("NbOfFreeVariables_", (Standard_Integer (*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr::NbOfFreeVariables, "None", py::arg("exp"));
	cls_Expr.def_static("NbOfFreeVariables_", (Standard_Integer (*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr::NbOfFreeVariables, "None", py::arg("exp"));
	cls_Expr.def_static("Sign_", (Standard_Real (*)(const Standard_Real)) &Expr::Sign, "None", py::arg("val"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_ExprFailure.hxx
	py::class_<Expr_ExprFailure, opencascade::handle<Expr_ExprFailure>, Standard_Failure> cls_Expr_ExprFailure(mod, "Expr_ExprFailure", "None");
	cls_Expr_ExprFailure.def(py::init<>());
	cls_Expr_ExprFailure.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_ExprFailure.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_ExprFailure::Raise, "None", py::arg("theMessage"));
	cls_Expr_ExprFailure.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_ExprFailure::Raise, "None", py::arg("theMessage"));
	cls_Expr_ExprFailure.def_static("NewInstance_", (opencascade::handle<Expr_ExprFailure> (*)(const Standard_CString)) &Expr_ExprFailure::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_ExprFailure.def_static("get_type_name_", (const char * (*)()) &Expr_ExprFailure::get_type_name, "None");
	cls_Expr_ExprFailure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_ExprFailure::get_type_descriptor, "None");
	cls_Expr_ExprFailure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_ExprFailure::*)() const ) &Expr_ExprFailure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_InvalidOperand.hxx
	py::class_<Expr_InvalidOperand, opencascade::handle<Expr_InvalidOperand>, Expr_ExprFailure> cls_Expr_InvalidOperand(mod, "Expr_InvalidOperand", "None");
	cls_Expr_InvalidOperand.def(py::init<>());
	cls_Expr_InvalidOperand.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_InvalidOperand.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidOperand::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidOperand.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidOperand::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidOperand.def_static("NewInstance_", (opencascade::handle<Expr_InvalidOperand> (*)(const Standard_CString)) &Expr_InvalidOperand::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_InvalidOperand.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidOperand::get_type_name, "None");
	cls_Expr_InvalidOperand.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidOperand::get_type_descriptor, "None");
	cls_Expr_InvalidOperand.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidOperand::*)() const ) &Expr_InvalidOperand::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_InvalidFunction.hxx
	py::class_<Expr_InvalidFunction, opencascade::handle<Expr_InvalidFunction>, Expr_ExprFailure> cls_Expr_InvalidFunction(mod, "Expr_InvalidFunction", "None");
	cls_Expr_InvalidFunction.def(py::init<>());
	cls_Expr_InvalidFunction.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_InvalidFunction.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidFunction::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidFunction.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidFunction::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidFunction.def_static("NewInstance_", (opencascade::handle<Expr_InvalidFunction> (*)(const Standard_CString)) &Expr_InvalidFunction::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_InvalidFunction.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidFunction::get_type_name, "None");
	cls_Expr_InvalidFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidFunction::get_type_descriptor, "None");
	cls_Expr_InvalidFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidFunction::*)() const ) &Expr_InvalidFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NotEvaluable.hxx
	py::class_<Expr_NotEvaluable, opencascade::handle<Expr_NotEvaluable>, Expr_ExprFailure> cls_Expr_NotEvaluable(mod, "Expr_NotEvaluable", "None");
	cls_Expr_NotEvaluable.def(py::init<>());
	cls_Expr_NotEvaluable.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_NotEvaluable.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_NotEvaluable::Raise, "None", py::arg("theMessage"));
	cls_Expr_NotEvaluable.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_NotEvaluable::Raise, "None", py::arg("theMessage"));
	cls_Expr_NotEvaluable.def_static("NewInstance_", (opencascade::handle<Expr_NotEvaluable> (*)(const Standard_CString)) &Expr_NotEvaluable::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_NotEvaluable.def_static("get_type_name_", (const char * (*)()) &Expr_NotEvaluable::get_type_name, "None");
	cls_Expr_NotEvaluable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NotEvaluable::get_type_descriptor, "None");
	cls_Expr_NotEvaluable.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NotEvaluable::*)() const ) &Expr_NotEvaluable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_InvalidAssignment.hxx
	py::class_<Expr_InvalidAssignment, opencascade::handle<Expr_InvalidAssignment>, Expr_ExprFailure> cls_Expr_InvalidAssignment(mod, "Expr_InvalidAssignment", "None");
	cls_Expr_InvalidAssignment.def(py::init<>());
	cls_Expr_InvalidAssignment.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_InvalidAssignment.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_InvalidAssignment::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidAssignment.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_InvalidAssignment::Raise, "None", py::arg("theMessage"));
	cls_Expr_InvalidAssignment.def_static("NewInstance_", (opencascade::handle<Expr_InvalidAssignment> (*)(const Standard_CString)) &Expr_InvalidAssignment::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_InvalidAssignment.def_static("get_type_name_", (const char * (*)()) &Expr_InvalidAssignment::get_type_name, "None");
	cls_Expr_InvalidAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_InvalidAssignment::get_type_descriptor, "None");
	cls_Expr_InvalidAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_InvalidAssignment::*)() const ) &Expr_InvalidAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Expr_NotAssigned.hxx
	py::class_<Expr_NotAssigned, opencascade::handle<Expr_NotAssigned>, Expr_ExprFailure> cls_Expr_NotAssigned(mod, "Expr_NotAssigned", "None");
	cls_Expr_NotAssigned.def(py::init<>());
	cls_Expr_NotAssigned.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Expr_NotAssigned.def_static("Raise_", (void (*)(const Standard_CString)) &Expr_NotAssigned::Raise, "None", py::arg("theMessage"));
	cls_Expr_NotAssigned.def_static("Raise_", (void (*)(Standard_SStream &)) &Expr_NotAssigned::Raise, "None", py::arg("theMessage"));
	cls_Expr_NotAssigned.def_static("NewInstance_", (opencascade::handle<Expr_NotAssigned> (*)(const Standard_CString)) &Expr_NotAssigned::NewInstance, "None", py::arg("theMessage"));
	cls_Expr_NotAssigned.def_static("get_type_name_", (const char * (*)()) &Expr_NotAssigned::get_type_name, "None");
	cls_Expr_NotAssigned.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Expr_NotAssigned::get_type_descriptor, "None");
	cls_Expr_NotAssigned.def("DynamicType", (const opencascade::handle<Standard_Type> & (Expr_NotAssigned::*)() const ) &Expr_NotAssigned::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Expr_Array1OfNamedUnknown, std::unique_ptr<Expr_Array1OfNamedUnknown, Deleter<Expr_Array1OfNamedUnknown>>> cls_Expr_Array1OfNamedUnknown(mod, "Expr_Array1OfNamedUnknown", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Expr_Array1OfNamedUnknown.def(py::init<>());
	cls_Expr_Array1OfNamedUnknown.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfNamedUnknown.def(py::init([] (const Expr_Array1OfNamedUnknown &other) {return new Expr_Array1OfNamedUnknown(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Expr_Array1OfNamedUnknown.def(py::init<Expr_Array1OfNamedUnknown &&>(), py::arg("theOther"));
	cls_Expr_Array1OfNamedUnknown.def(py::init<const opencascade::handle<Expr_NamedUnknown> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfNamedUnknown.def("begin", (Expr_Array1OfNamedUnknown::iterator (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Expr_Array1OfNamedUnknown.def("end", (Expr_Array1OfNamedUnknown::iterator (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfNamedUnknown.def("cbegin", (Expr_Array1OfNamedUnknown::const_iterator (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Expr_Array1OfNamedUnknown.def("cend", (Expr_Array1OfNamedUnknown::const_iterator (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfNamedUnknown.def("Init", (void (Expr_Array1OfNamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &)) &Expr_Array1OfNamedUnknown::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Expr_Array1OfNamedUnknown.def("Size", (Standard_Integer (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::Size, "Size query");
	cls_Expr_Array1OfNamedUnknown.def("Length", (Standard_Integer (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::Length, "Length query (the same)");
	cls_Expr_Array1OfNamedUnknown.def("IsEmpty", (Standard_Boolean (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::IsEmpty, "Return TRUE if array has zero length.");
	cls_Expr_Array1OfNamedUnknown.def("Lower", (Standard_Integer (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::Lower, "Lower bound");
	cls_Expr_Array1OfNamedUnknown.def("Upper", (Standard_Integer (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::Upper, "Upper bound");
	cls_Expr_Array1OfNamedUnknown.def("IsDeletable", (Standard_Boolean (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::IsDeletable, "myDeletable flag");
	cls_Expr_Array1OfNamedUnknown.def("IsAllocated", (Standard_Boolean (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Expr_Array1OfNamedUnknown.def("Assign", (Expr_Array1OfNamedUnknown & (Expr_Array1OfNamedUnknown::*)(const Expr_Array1OfNamedUnknown &)) &Expr_Array1OfNamedUnknown::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfNamedUnknown.def("Move", (Expr_Array1OfNamedUnknown & (Expr_Array1OfNamedUnknown::*)(Expr_Array1OfNamedUnknown &&)) &Expr_Array1OfNamedUnknown::Move, "Move assignment", py::arg("theOther"));
	cls_Expr_Array1OfNamedUnknown.def("assign", (Expr_Array1OfNamedUnknown & (Expr_Array1OfNamedUnknown::*)(const Expr_Array1OfNamedUnknown &)) &Expr_Array1OfNamedUnknown::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfNamedUnknown.def("assign", (Expr_Array1OfNamedUnknown & (Expr_Array1OfNamedUnknown::*)(Expr_Array1OfNamedUnknown &&)) &Expr_Array1OfNamedUnknown::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Expr_Array1OfNamedUnknown.def("First", (const opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::First, "Returns first element");
	cls_Expr_Array1OfNamedUnknown.def("ChangeFirst", (opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)()) &Expr_Array1OfNamedUnknown::ChangeFirst, "Returns first element");
	cls_Expr_Array1OfNamedUnknown.def("Last", (const opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)() const ) &Expr_Array1OfNamedUnknown::Last, "Returns last element");
	cls_Expr_Array1OfNamedUnknown.def("ChangeLast", (opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)()) &Expr_Array1OfNamedUnknown::ChangeLast, "Returns last element");
	cls_Expr_Array1OfNamedUnknown.def("Value", (const opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)(const Standard_Integer) const ) &Expr_Array1OfNamedUnknown::Value, "Constant value access", py::arg("theIndex"));
	cls_Expr_Array1OfNamedUnknown.def("__call__", (const opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)(const Standard_Integer) const ) &Expr_Array1OfNamedUnknown::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Expr_Array1OfNamedUnknown.def("ChangeValue", (opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)(const Standard_Integer)) &Expr_Array1OfNamedUnknown::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Expr_Array1OfNamedUnknown.def("__call__", (opencascade::handle<Expr_NamedUnknown> & (Expr_Array1OfNamedUnknown::*)(const Standard_Integer)) &Expr_Array1OfNamedUnknown::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Expr_Array1OfNamedUnknown.def("SetValue", (void (Expr_Array1OfNamedUnknown::*)(const Standard_Integer, const opencascade::handle<Expr_NamedUnknown> &)) &Expr_Array1OfNamedUnknown::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_Array1OfNamedUnknown.def("Resize", (void (Expr_Array1OfNamedUnknown::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Expr_Array1OfNamedUnknown::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Expr_Array1OfNamedUnknown.def("__iter__", [](const Expr_Array1OfNamedUnknown &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Expr_Array1OfGeneralExpression, std::unique_ptr<Expr_Array1OfGeneralExpression, Deleter<Expr_Array1OfGeneralExpression>>> cls_Expr_Array1OfGeneralExpression(mod, "Expr_Array1OfGeneralExpression", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Expr_Array1OfGeneralExpression.def(py::init<>());
	cls_Expr_Array1OfGeneralExpression.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfGeneralExpression.def(py::init([] (const Expr_Array1OfGeneralExpression &other) {return new Expr_Array1OfGeneralExpression(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Expr_Array1OfGeneralExpression.def(py::init<Expr_Array1OfGeneralExpression &&>(), py::arg("theOther"));
	cls_Expr_Array1OfGeneralExpression.def(py::init<const opencascade::handle<Expr_GeneralExpression> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfGeneralExpression.def("begin", (Expr_Array1OfGeneralExpression::iterator (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Expr_Array1OfGeneralExpression.def("end", (Expr_Array1OfGeneralExpression::iterator (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfGeneralExpression.def("cbegin", (Expr_Array1OfGeneralExpression::const_iterator (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Expr_Array1OfGeneralExpression.def("cend", (Expr_Array1OfGeneralExpression::const_iterator (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfGeneralExpression.def("Init", (void (Expr_Array1OfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_Array1OfGeneralExpression::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Expr_Array1OfGeneralExpression.def("Size", (Standard_Integer (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::Size, "Size query");
	cls_Expr_Array1OfGeneralExpression.def("Length", (Standard_Integer (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::Length, "Length query (the same)");
	cls_Expr_Array1OfGeneralExpression.def("IsEmpty", (Standard_Boolean (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::IsEmpty, "Return TRUE if array has zero length.");
	cls_Expr_Array1OfGeneralExpression.def("Lower", (Standard_Integer (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::Lower, "Lower bound");
	cls_Expr_Array1OfGeneralExpression.def("Upper", (Standard_Integer (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::Upper, "Upper bound");
	cls_Expr_Array1OfGeneralExpression.def("IsDeletable", (Standard_Boolean (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::IsDeletable, "myDeletable flag");
	cls_Expr_Array1OfGeneralExpression.def("IsAllocated", (Standard_Boolean (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Expr_Array1OfGeneralExpression.def("Assign", (Expr_Array1OfGeneralExpression & (Expr_Array1OfGeneralExpression::*)(const Expr_Array1OfGeneralExpression &)) &Expr_Array1OfGeneralExpression::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfGeneralExpression.def("Move", (Expr_Array1OfGeneralExpression & (Expr_Array1OfGeneralExpression::*)(Expr_Array1OfGeneralExpression &&)) &Expr_Array1OfGeneralExpression::Move, "Move assignment", py::arg("theOther"));
	cls_Expr_Array1OfGeneralExpression.def("assign", (Expr_Array1OfGeneralExpression & (Expr_Array1OfGeneralExpression::*)(const Expr_Array1OfGeneralExpression &)) &Expr_Array1OfGeneralExpression::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfGeneralExpression.def("assign", (Expr_Array1OfGeneralExpression & (Expr_Array1OfGeneralExpression::*)(Expr_Array1OfGeneralExpression &&)) &Expr_Array1OfGeneralExpression::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Expr_Array1OfGeneralExpression.def("First", (const opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::First, "Returns first element");
	cls_Expr_Array1OfGeneralExpression.def("ChangeFirst", (opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)()) &Expr_Array1OfGeneralExpression::ChangeFirst, "Returns first element");
	cls_Expr_Array1OfGeneralExpression.def("Last", (const opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)() const ) &Expr_Array1OfGeneralExpression::Last, "Returns last element");
	cls_Expr_Array1OfGeneralExpression.def("ChangeLast", (opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)()) &Expr_Array1OfGeneralExpression::ChangeLast, "Returns last element");
	cls_Expr_Array1OfGeneralExpression.def("Value", (const opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)(const Standard_Integer) const ) &Expr_Array1OfGeneralExpression::Value, "Constant value access", py::arg("theIndex"));
	cls_Expr_Array1OfGeneralExpression.def("__call__", (const opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)(const Standard_Integer) const ) &Expr_Array1OfGeneralExpression::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Expr_Array1OfGeneralExpression.def("ChangeValue", (opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)(const Standard_Integer)) &Expr_Array1OfGeneralExpression::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Expr_Array1OfGeneralExpression.def("__call__", (opencascade::handle<Expr_GeneralExpression> & (Expr_Array1OfGeneralExpression::*)(const Standard_Integer)) &Expr_Array1OfGeneralExpression::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Expr_Array1OfGeneralExpression.def("SetValue", (void (Expr_Array1OfGeneralExpression::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_Array1OfGeneralExpression::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_Array1OfGeneralExpression.def("Resize", (void (Expr_Array1OfGeneralExpression::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Expr_Array1OfGeneralExpression::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Expr_Array1OfGeneralExpression.def("__iter__", [](const Expr_Array1OfGeneralExpression &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Expr_Array1OfSingleRelation, std::unique_ptr<Expr_Array1OfSingleRelation, Deleter<Expr_Array1OfSingleRelation>>> cls_Expr_Array1OfSingleRelation(mod, "Expr_Array1OfSingleRelation", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Expr_Array1OfSingleRelation.def(py::init<>());
	cls_Expr_Array1OfSingleRelation.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfSingleRelation.def(py::init([] (const Expr_Array1OfSingleRelation &other) {return new Expr_Array1OfSingleRelation(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Expr_Array1OfSingleRelation.def(py::init<Expr_Array1OfSingleRelation &&>(), py::arg("theOther"));
	cls_Expr_Array1OfSingleRelation.def(py::init<const opencascade::handle<Expr_SingleRelation> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Expr_Array1OfSingleRelation.def("begin", (Expr_Array1OfSingleRelation::iterator (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Expr_Array1OfSingleRelation.def("end", (Expr_Array1OfSingleRelation::iterator (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfSingleRelation.def("cbegin", (Expr_Array1OfSingleRelation::const_iterator (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Expr_Array1OfSingleRelation.def("cend", (Expr_Array1OfSingleRelation::const_iterator (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Expr_Array1OfSingleRelation.def("Init", (void (Expr_Array1OfSingleRelation::*)(const opencascade::handle<Expr_SingleRelation> &)) &Expr_Array1OfSingleRelation::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Expr_Array1OfSingleRelation.def("Size", (Standard_Integer (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::Size, "Size query");
	cls_Expr_Array1OfSingleRelation.def("Length", (Standard_Integer (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::Length, "Length query (the same)");
	cls_Expr_Array1OfSingleRelation.def("IsEmpty", (Standard_Boolean (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::IsEmpty, "Return TRUE if array has zero length.");
	cls_Expr_Array1OfSingleRelation.def("Lower", (Standard_Integer (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::Lower, "Lower bound");
	cls_Expr_Array1OfSingleRelation.def("Upper", (Standard_Integer (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::Upper, "Upper bound");
	cls_Expr_Array1OfSingleRelation.def("IsDeletable", (Standard_Boolean (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::IsDeletable, "myDeletable flag");
	cls_Expr_Array1OfSingleRelation.def("IsAllocated", (Standard_Boolean (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Expr_Array1OfSingleRelation.def("Assign", (Expr_Array1OfSingleRelation & (Expr_Array1OfSingleRelation::*)(const Expr_Array1OfSingleRelation &)) &Expr_Array1OfSingleRelation::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfSingleRelation.def("Move", (Expr_Array1OfSingleRelation & (Expr_Array1OfSingleRelation::*)(Expr_Array1OfSingleRelation &&)) &Expr_Array1OfSingleRelation::Move, "Move assignment", py::arg("theOther"));
	cls_Expr_Array1OfSingleRelation.def("assign", (Expr_Array1OfSingleRelation & (Expr_Array1OfSingleRelation::*)(const Expr_Array1OfSingleRelation &)) &Expr_Array1OfSingleRelation::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Expr_Array1OfSingleRelation.def("assign", (Expr_Array1OfSingleRelation & (Expr_Array1OfSingleRelation::*)(Expr_Array1OfSingleRelation &&)) &Expr_Array1OfSingleRelation::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Expr_Array1OfSingleRelation.def("First", (const opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::First, "Returns first element");
	cls_Expr_Array1OfSingleRelation.def("ChangeFirst", (opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)()) &Expr_Array1OfSingleRelation::ChangeFirst, "Returns first element");
	cls_Expr_Array1OfSingleRelation.def("Last", (const opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)() const ) &Expr_Array1OfSingleRelation::Last, "Returns last element");
	cls_Expr_Array1OfSingleRelation.def("ChangeLast", (opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)()) &Expr_Array1OfSingleRelation::ChangeLast, "Returns last element");
	cls_Expr_Array1OfSingleRelation.def("Value", (const opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)(const Standard_Integer) const ) &Expr_Array1OfSingleRelation::Value, "Constant value access", py::arg("theIndex"));
	cls_Expr_Array1OfSingleRelation.def("__call__", (const opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)(const Standard_Integer) const ) &Expr_Array1OfSingleRelation::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Expr_Array1OfSingleRelation.def("ChangeValue", (opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)(const Standard_Integer)) &Expr_Array1OfSingleRelation::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Expr_Array1OfSingleRelation.def("__call__", (opencascade::handle<Expr_SingleRelation> & (Expr_Array1OfSingleRelation::*)(const Standard_Integer)) &Expr_Array1OfSingleRelation::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Expr_Array1OfSingleRelation.def("SetValue", (void (Expr_Array1OfSingleRelation::*)(const Standard_Integer, const opencascade::handle<Expr_SingleRelation> &)) &Expr_Array1OfSingleRelation::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_Array1OfSingleRelation.def("Resize", (void (Expr_Array1OfSingleRelation::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Expr_Array1OfSingleRelation::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Expr_Array1OfSingleRelation.def("__iter__", [](const Expr_Array1OfSingleRelation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<Expr_MapOfNamedUnknown, std::unique_ptr<Expr_MapOfNamedUnknown, Deleter<Expr_MapOfNamedUnknown>>, NCollection_BaseMap> cls_Expr_MapOfNamedUnknown(mod, "Expr_MapOfNamedUnknown", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_Expr_MapOfNamedUnknown.def(py::init<>());
	cls_Expr_MapOfNamedUnknown.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Expr_MapOfNamedUnknown.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Expr_MapOfNamedUnknown.def(py::init([] (const Expr_MapOfNamedUnknown &other) {return new Expr_MapOfNamedUnknown(other);}), "Copy constructor", py::arg("other"));
	cls_Expr_MapOfNamedUnknown.def("cbegin", (Expr_MapOfNamedUnknown::const_iterator (Expr_MapOfNamedUnknown::*)() const ) &Expr_MapOfNamedUnknown::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Expr_MapOfNamedUnknown.def("cend", (Expr_MapOfNamedUnknown::const_iterator (Expr_MapOfNamedUnknown::*)() const ) &Expr_MapOfNamedUnknown::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Expr_MapOfNamedUnknown.def("Exchange", (void (Expr_MapOfNamedUnknown::*)(Expr_MapOfNamedUnknown &)) &Expr_MapOfNamedUnknown::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Expr_MapOfNamedUnknown.def("Assign", (Expr_MapOfNamedUnknown & (Expr_MapOfNamedUnknown::*)(const Expr_MapOfNamedUnknown &)) &Expr_MapOfNamedUnknown::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Expr_MapOfNamedUnknown.def("assign", (Expr_MapOfNamedUnknown & (Expr_MapOfNamedUnknown::*)(const Expr_MapOfNamedUnknown &)) &Expr_MapOfNamedUnknown::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Expr_MapOfNamedUnknown.def("ReSize", (void (Expr_MapOfNamedUnknown::*)(const Standard_Integer)) &Expr_MapOfNamedUnknown::ReSize, "ReSize", py::arg("N"));
	cls_Expr_MapOfNamedUnknown.def("Add", (Standard_Integer (Expr_MapOfNamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &)) &Expr_MapOfNamedUnknown::Add, "Add", py::arg("theKey1"));
	cls_Expr_MapOfNamedUnknown.def("Contains", (Standard_Boolean (Expr_MapOfNamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_MapOfNamedUnknown::Contains, "Contains", py::arg("theKey1"));
	cls_Expr_MapOfNamedUnknown.def("Substitute", (void (Expr_MapOfNamedUnknown::*)(const Standard_Integer, const opencascade::handle<Expr_NamedUnknown> &)) &Expr_MapOfNamedUnknown::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_Expr_MapOfNamedUnknown.def("Swap", (void (Expr_MapOfNamedUnknown::*)(const Standard_Integer, const Standard_Integer)) &Expr_MapOfNamedUnknown::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_Expr_MapOfNamedUnknown.def("RemoveLast", (void (Expr_MapOfNamedUnknown::*)()) &Expr_MapOfNamedUnknown::RemoveLast, "RemoveLast");
	cls_Expr_MapOfNamedUnknown.def("RemoveFromIndex", (void (Expr_MapOfNamedUnknown::*)(const Standard_Integer)) &Expr_MapOfNamedUnknown::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_Expr_MapOfNamedUnknown.def("RemoveKey", (Standard_Boolean (Expr_MapOfNamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &)) &Expr_MapOfNamedUnknown::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_Expr_MapOfNamedUnknown.def("FindKey", (const opencascade::handle<Expr_NamedUnknown> & (Expr_MapOfNamedUnknown::*)(const Standard_Integer) const ) &Expr_MapOfNamedUnknown::FindKey, "FindKey", py::arg("theKey2"));
	cls_Expr_MapOfNamedUnknown.def("__call__", (const opencascade::handle<Expr_NamedUnknown> & (Expr_MapOfNamedUnknown::*)(const Standard_Integer) const ) &Expr_MapOfNamedUnknown::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Expr_MapOfNamedUnknown.def("FindIndex", (Standard_Integer (Expr_MapOfNamedUnknown::*)(const opencascade::handle<Expr_NamedUnknown> &) const ) &Expr_MapOfNamedUnknown::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_Expr_MapOfNamedUnknown.def("Clear", [](Expr_MapOfNamedUnknown &self) -> void { return self.Clear(); });
	cls_Expr_MapOfNamedUnknown.def("Clear", (void (Expr_MapOfNamedUnknown::*)(const Standard_Boolean)) &Expr_MapOfNamedUnknown::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Expr_MapOfNamedUnknown.def("Clear", (void (Expr_MapOfNamedUnknown::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Expr_MapOfNamedUnknown::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Expr_MapOfNamedUnknown.def("Size", (Standard_Integer (Expr_MapOfNamedUnknown::*)() const ) &Expr_MapOfNamedUnknown::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Expr_SequenceOfGeneralExpression, std::unique_ptr<Expr_SequenceOfGeneralExpression, Deleter<Expr_SequenceOfGeneralExpression>>, NCollection_BaseSequence> cls_Expr_SequenceOfGeneralExpression(mod, "Expr_SequenceOfGeneralExpression", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Expr_SequenceOfGeneralExpression.def(py::init<>());
	cls_Expr_SequenceOfGeneralExpression.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Expr_SequenceOfGeneralExpression.def(py::init([] (const Expr_SequenceOfGeneralExpression &other) {return new Expr_SequenceOfGeneralExpression(other);}), "Copy constructor", py::arg("other"));
	cls_Expr_SequenceOfGeneralExpression.def("begin", (Expr_SequenceOfGeneralExpression::iterator (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Expr_SequenceOfGeneralExpression.def("end", (Expr_SequenceOfGeneralExpression::iterator (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Expr_SequenceOfGeneralExpression.def("cbegin", (Expr_SequenceOfGeneralExpression::const_iterator (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Expr_SequenceOfGeneralExpression.def("cend", (Expr_SequenceOfGeneralExpression::const_iterator (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Expr_SequenceOfGeneralExpression.def("Size", (Standard_Integer (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::Size, "Number of items");
	cls_Expr_SequenceOfGeneralExpression.def("Length", (Standard_Integer (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::Length, "Number of items");
	cls_Expr_SequenceOfGeneralExpression.def("Lower", (Standard_Integer (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::Lower, "Method for consistency with other collections.");
	cls_Expr_SequenceOfGeneralExpression.def("Upper", (Standard_Integer (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::Upper, "Method for consistency with other collections.");
	cls_Expr_SequenceOfGeneralExpression.def("IsEmpty", (Standard_Boolean (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::IsEmpty, "Empty query");
	cls_Expr_SequenceOfGeneralExpression.def("Reverse", (void (Expr_SequenceOfGeneralExpression::*)()) &Expr_SequenceOfGeneralExpression::Reverse, "Reverse sequence");
	cls_Expr_SequenceOfGeneralExpression.def("Exchange", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, const Standard_Integer)) &Expr_SequenceOfGeneralExpression::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Expr_SequenceOfGeneralExpression.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Expr_SequenceOfGeneralExpression::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Expr_SequenceOfGeneralExpression.def("Clear", [](Expr_SequenceOfGeneralExpression &self) -> void { return self.Clear(); });
	cls_Expr_SequenceOfGeneralExpression.def("Clear", (void (Expr_SequenceOfGeneralExpression::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Expr_SequenceOfGeneralExpression::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Expr_SequenceOfGeneralExpression.def("Assign", (Expr_SequenceOfGeneralExpression & (Expr_SequenceOfGeneralExpression::*)(const Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Expr_SequenceOfGeneralExpression.def("assign", (Expr_SequenceOfGeneralExpression & (Expr_SequenceOfGeneralExpression::*)(const Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Expr_SequenceOfGeneralExpression.def("Remove", (void (Expr_SequenceOfGeneralExpression::*)(Expr_SequenceOfGeneralExpression::Iterator &)) &Expr_SequenceOfGeneralExpression::Remove, "Remove one item", py::arg("thePosition"));
	cls_Expr_SequenceOfGeneralExpression.def("Remove", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer)) &Expr_SequenceOfGeneralExpression::Remove, "Remove one item", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("Remove", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, const Standard_Integer)) &Expr_SequenceOfGeneralExpression::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("Append", (void (Expr_SequenceOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::Append, "Append one item", py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("Append", (void (Expr_SequenceOfGeneralExpression::*)(Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralExpression.def("Prepend", (void (Expr_SequenceOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("Prepend", (void (Expr_SequenceOfGeneralExpression::*)(Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralExpression.def("InsertBefore", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("InsertBefore", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralExpression.def("InsertAfter", (void (Expr_SequenceOfGeneralExpression::*)(Expr_SequenceOfGeneralExpression::Iterator &, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("InsertAfter", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralExpression.def("InsertAfter", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("Split", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, Expr_SequenceOfGeneralExpression &)) &Expr_SequenceOfGeneralExpression::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralExpression.def("First", (const opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::First, "First item access");
	cls_Expr_SequenceOfGeneralExpression.def("ChangeFirst", (opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)()) &Expr_SequenceOfGeneralExpression::ChangeFirst, "First item access");
	cls_Expr_SequenceOfGeneralExpression.def("Last", (const opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)() const ) &Expr_SequenceOfGeneralExpression::Last, "Last item access");
	cls_Expr_SequenceOfGeneralExpression.def("ChangeLast", (opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)()) &Expr_SequenceOfGeneralExpression::ChangeLast, "Last item access");
	cls_Expr_SequenceOfGeneralExpression.def("Value", (const opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer) const ) &Expr_SequenceOfGeneralExpression::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("__call__", (const opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer) const ) &Expr_SequenceOfGeneralExpression::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("ChangeValue", (opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer)) &Expr_SequenceOfGeneralExpression::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("__call__", (opencascade::handle<Expr_GeneralExpression> & (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer)) &Expr_SequenceOfGeneralExpression::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralExpression.def("SetValue", (void (Expr_SequenceOfGeneralExpression::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralExpression> &)) &Expr_SequenceOfGeneralExpression::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralExpression.def("__iter__", [](const Expr_SequenceOfGeneralExpression &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Expr_SequenceOfGeneralRelation, std::unique_ptr<Expr_SequenceOfGeneralRelation, Deleter<Expr_SequenceOfGeneralRelation>>, NCollection_BaseSequence> cls_Expr_SequenceOfGeneralRelation(mod, "Expr_SequenceOfGeneralRelation", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Expr_SequenceOfGeneralRelation.def(py::init<>());
	cls_Expr_SequenceOfGeneralRelation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Expr_SequenceOfGeneralRelation.def(py::init([] (const Expr_SequenceOfGeneralRelation &other) {return new Expr_SequenceOfGeneralRelation(other);}), "Copy constructor", py::arg("other"));
	cls_Expr_SequenceOfGeneralRelation.def("begin", (Expr_SequenceOfGeneralRelation::iterator (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Expr_SequenceOfGeneralRelation.def("end", (Expr_SequenceOfGeneralRelation::iterator (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Expr_SequenceOfGeneralRelation.def("cbegin", (Expr_SequenceOfGeneralRelation::const_iterator (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Expr_SequenceOfGeneralRelation.def("cend", (Expr_SequenceOfGeneralRelation::const_iterator (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Expr_SequenceOfGeneralRelation.def("Size", (Standard_Integer (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::Size, "Number of items");
	cls_Expr_SequenceOfGeneralRelation.def("Length", (Standard_Integer (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::Length, "Number of items");
	cls_Expr_SequenceOfGeneralRelation.def("Lower", (Standard_Integer (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::Lower, "Method for consistency with other collections.");
	cls_Expr_SequenceOfGeneralRelation.def("Upper", (Standard_Integer (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::Upper, "Method for consistency with other collections.");
	cls_Expr_SequenceOfGeneralRelation.def("IsEmpty", (Standard_Boolean (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::IsEmpty, "Empty query");
	cls_Expr_SequenceOfGeneralRelation.def("Reverse", (void (Expr_SequenceOfGeneralRelation::*)()) &Expr_SequenceOfGeneralRelation::Reverse, "Reverse sequence");
	cls_Expr_SequenceOfGeneralRelation.def("Exchange", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, const Standard_Integer)) &Expr_SequenceOfGeneralRelation::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Expr_SequenceOfGeneralRelation.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Expr_SequenceOfGeneralRelation::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Expr_SequenceOfGeneralRelation.def("Clear", [](Expr_SequenceOfGeneralRelation &self) -> void { return self.Clear(); });
	cls_Expr_SequenceOfGeneralRelation.def("Clear", (void (Expr_SequenceOfGeneralRelation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Expr_SequenceOfGeneralRelation::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Expr_SequenceOfGeneralRelation.def("Assign", (Expr_SequenceOfGeneralRelation & (Expr_SequenceOfGeneralRelation::*)(const Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Expr_SequenceOfGeneralRelation.def("assign", (Expr_SequenceOfGeneralRelation & (Expr_SequenceOfGeneralRelation::*)(const Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Expr_SequenceOfGeneralRelation.def("Remove", (void (Expr_SequenceOfGeneralRelation::*)(Expr_SequenceOfGeneralRelation::Iterator &)) &Expr_SequenceOfGeneralRelation::Remove, "Remove one item", py::arg("thePosition"));
	cls_Expr_SequenceOfGeneralRelation.def("Remove", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer)) &Expr_SequenceOfGeneralRelation::Remove, "Remove one item", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("Remove", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, const Standard_Integer)) &Expr_SequenceOfGeneralRelation::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("Append", (void (Expr_SequenceOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::Append, "Append one item", py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("Append", (void (Expr_SequenceOfGeneralRelation::*)(Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralRelation.def("Prepend", (void (Expr_SequenceOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("Prepend", (void (Expr_SequenceOfGeneralRelation::*)(Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralRelation.def("InsertBefore", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("InsertBefore", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralRelation.def("InsertAfter", (void (Expr_SequenceOfGeneralRelation::*)(Expr_SequenceOfGeneralRelation::Iterator &, const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("InsertAfter", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralRelation.def("InsertAfter", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("Split", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, Expr_SequenceOfGeneralRelation &)) &Expr_SequenceOfGeneralRelation::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Expr_SequenceOfGeneralRelation.def("First", (const opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::First, "First item access");
	cls_Expr_SequenceOfGeneralRelation.def("ChangeFirst", (opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)()) &Expr_SequenceOfGeneralRelation::ChangeFirst, "First item access");
	cls_Expr_SequenceOfGeneralRelation.def("Last", (const opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)() const ) &Expr_SequenceOfGeneralRelation::Last, "Last item access");
	cls_Expr_SequenceOfGeneralRelation.def("ChangeLast", (opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)()) &Expr_SequenceOfGeneralRelation::ChangeLast, "Last item access");
	cls_Expr_SequenceOfGeneralRelation.def("Value", (const opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer) const ) &Expr_SequenceOfGeneralRelation::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("__call__", (const opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer) const ) &Expr_SequenceOfGeneralRelation::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("ChangeValue", (opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer)) &Expr_SequenceOfGeneralRelation::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("__call__", (opencascade::handle<Expr_GeneralRelation> & (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer)) &Expr_SequenceOfGeneralRelation::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Expr_SequenceOfGeneralRelation.def("SetValue", (void (Expr_SequenceOfGeneralRelation::*)(const Standard_Integer, const opencascade::handle<Expr_GeneralRelation> &)) &Expr_SequenceOfGeneralRelation::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Expr_SequenceOfGeneralRelation.def("__iter__", [](const Expr_SequenceOfGeneralRelation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
