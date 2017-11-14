#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Expr_NamedFunction.hxx>
#include <Expr_NamedExpression.hxx>
#include <ExprIntrp_SequenceOfNamedExpression.hxx>
#include <ExprIntrp_SequenceOfNamedFunction.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <ExprIntrp_Generator.hxx>
#include <ExprIntrp_GenExp.hxx>
#include <Standard_TypeDef.hxx>
#include <Expr_GeneralExpression.hxx>
#include <ExprIntrp_GenFct.hxx>
#include <ExprIntrp_GenRel.hxx>
#include <Expr_GeneralRelation.hxx>
#include <Expr_GeneralFunction.hxx>
#include <ExprIntrp_Analysis.hxx>
#include <ExprIntrp.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <ExprIntrp_StackOfGeneralExpression.hxx>
#include <ExprIntrp_StackOfGeneralRelation.hxx>
#include <ExprIntrp_StackOfGeneralFunction.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Failure.hxx>
#include <Standard_SStream.hxx>
#include <ExprIntrp_SyntaxError.hxx>
#include <ExprIntrp_yaccintrf.hxx>

PYBIND11_MODULE(ExprIntrp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Expr");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_yaccintrf.hxx
	mod.def("ExprIntrp_GetResult", (const TCollection_AsciiString & (*)()) &ExprIntrp_GetResult, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_yaccintrf.hxx
	mod.def("ExprIntrp_GetDegree", (int (*)()) &ExprIntrp_GetDegree, "None");


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_Generator.hxx
	py::class_<ExprIntrp_Generator, opencascade::handle<ExprIntrp_Generator>, Standard_Transient> cls_ExprIntrp_Generator(mod, "ExprIntrp_Generator", "Implements general services for interpretation of expressions.");
	cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_Generator::Use, "None", py::arg("func"));
	cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_Generator::Use, "None", py::arg("named"));
	cls_ExprIntrp_Generator.def("GetNamed", (const ExprIntrp_SequenceOfNamedExpression & (ExprIntrp_Generator::*)() const ) &ExprIntrp_Generator::GetNamed, "None");
	cls_ExprIntrp_Generator.def("GetFunctions", (const ExprIntrp_SequenceOfNamedFunction & (ExprIntrp_Generator::*)() const ) &ExprIntrp_Generator::GetFunctions, "None");
	cls_ExprIntrp_Generator.def("GetNamed", (opencascade::handle<Expr_NamedExpression> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const ) &ExprIntrp_Generator::GetNamed, "Returns NamedExpression with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
	cls_ExprIntrp_Generator.def("GetFunction", (opencascade::handle<Expr_NamedFunction> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const ) &ExprIntrp_Generator::GetFunction, "Returns NamedFunction with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
	cls_ExprIntrp_Generator.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_Generator::get_type_name, "None");
	cls_ExprIntrp_Generator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_Generator::get_type_descriptor, "None");
	cls_ExprIntrp_Generator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_Generator::*)() const ) &ExprIntrp_Generator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_GenExp.hxx
	py::class_<ExprIntrp_GenExp, opencascade::handle<ExprIntrp_GenExp>, ExprIntrp_Generator> cls_ExprIntrp_GenExp(mod, "ExprIntrp_GenExp", "This class permits, from a string, to create any kind of expression of package Expr by using built-in functions such as Sin,Cos, etc, and by creating variables.");
	cls_ExprIntrp_GenExp.def_static("Create_", (opencascade::handle<ExprIntrp_GenExp> (*)()) &ExprIntrp_GenExp::Create, "None");
	cls_ExprIntrp_GenExp.def("Process", (void (ExprIntrp_GenExp::*)(const TCollection_AsciiString &)) &ExprIntrp_GenExp::Process, "Processes given string.", py::arg("str"));
	cls_ExprIntrp_GenExp.def("IsDone", (Standard_Boolean (ExprIntrp_GenExp::*)() const ) &ExprIntrp_GenExp::IsDone, "Returns false if any syntax error has occurred during process.");
	cls_ExprIntrp_GenExp.def("Expression", (opencascade::handle<Expr_GeneralExpression> (ExprIntrp_GenExp::*)() const ) &ExprIntrp_GenExp::Expression, "Returns expression generated. Raises an exception if IsDone answers false.");
	cls_ExprIntrp_GenExp.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenExp::get_type_name, "None");
	cls_ExprIntrp_GenExp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenExp::get_type_descriptor, "None");
	cls_ExprIntrp_GenExp.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenExp::*)() const ) &ExprIntrp_GenExp::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_GenFct.hxx
	py::class_<ExprIntrp_GenFct, opencascade::handle<ExprIntrp_GenFct>, ExprIntrp_Generator> cls_ExprIntrp_GenFct(mod, "ExprIntrp_GenFct", "Implements an interpreter for defining functions. All its functionnalities can be found in class GenExp.");
	cls_ExprIntrp_GenFct.def_static("Create_", (opencascade::handle<ExprIntrp_GenFct> (*)()) &ExprIntrp_GenFct::Create, "None");
	cls_ExprIntrp_GenFct.def("Process", (void (ExprIntrp_GenFct::*)(const TCollection_AsciiString &)) &ExprIntrp_GenFct::Process, "None", py::arg("str"));
	cls_ExprIntrp_GenFct.def("IsDone", (Standard_Boolean (ExprIntrp_GenFct::*)() const ) &ExprIntrp_GenFct::IsDone, "None");
	cls_ExprIntrp_GenFct.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenFct::get_type_name, "None");
	cls_ExprIntrp_GenFct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenFct::get_type_descriptor, "None");
	cls_ExprIntrp_GenFct.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenFct::*)() const ) &ExprIntrp_GenFct::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_GenRel.hxx
	py::class_<ExprIntrp_GenRel, opencascade::handle<ExprIntrp_GenRel>, ExprIntrp_Generator> cls_ExprIntrp_GenRel(mod, "ExprIntrp_GenRel", "Implements an interpreter for equations or system of equations made of expressions of package Expr.");
	cls_ExprIntrp_GenRel.def_static("Create_", (opencascade::handle<ExprIntrp_GenRel> (*)()) &ExprIntrp_GenRel::Create, "None");
	cls_ExprIntrp_GenRel.def("Process", (void (ExprIntrp_GenRel::*)(const TCollection_AsciiString &)) &ExprIntrp_GenRel::Process, "Processes given string.", py::arg("str"));
	cls_ExprIntrp_GenRel.def("IsDone", (Standard_Boolean (ExprIntrp_GenRel::*)() const ) &ExprIntrp_GenRel::IsDone, "Returns false if any syntax error has occurred during process.");
	cls_ExprIntrp_GenRel.def("Relation", (opencascade::handle<Expr_GeneralRelation> (ExprIntrp_GenRel::*)() const ) &ExprIntrp_GenRel::Relation, "Returns relation generated. Raises an exception if IsDone answers false.");
	cls_ExprIntrp_GenRel.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenRel::get_type_name, "None");
	cls_ExprIntrp_GenRel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenRel::get_type_descriptor, "None");
	cls_ExprIntrp_GenRel.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenRel::*)() const ) &ExprIntrp_GenRel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_Analysis.hxx
	py::class_<ExprIntrp_Analysis, std::unique_ptr<ExprIntrp_Analysis, Deleter<ExprIntrp_Analysis>>> cls_ExprIntrp_Analysis(mod, "ExprIntrp_Analysis", "None");
	cls_ExprIntrp_Analysis.def(py::init<>());
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
	cls_ExprIntrp_Analysis.def("IsExpStackEmpty", (Standard_Boolean (ExprIntrp_Analysis::*)() const ) &ExprIntrp_Analysis::IsExpStackEmpty, "None");
	cls_ExprIntrp_Analysis.def("IsRelStackEmpty", (Standard_Boolean (ExprIntrp_Analysis::*)() const ) &ExprIntrp_Analysis::IsRelStackEmpty, "None");
	cls_ExprIntrp_Analysis.def("ResetAll", (void (ExprIntrp_Analysis::*)()) &ExprIntrp_Analysis::ResetAll, "None");
	cls_ExprIntrp_Analysis.def("Use", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_Analysis::Use, "None", py::arg("func"));
	cls_ExprIntrp_Analysis.def("Use", (void (ExprIntrp_Analysis::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_Analysis::Use, "None", py::arg("named"));
	cls_ExprIntrp_Analysis.def("GetNamed", (opencascade::handle<Expr_NamedExpression> (ExprIntrp_Analysis::*)(const TCollection_AsciiString &)) &ExprIntrp_Analysis::GetNamed, "None", py::arg("name"));
	cls_ExprIntrp_Analysis.def("GetFunction", (opencascade::handle<Expr_NamedFunction> (ExprIntrp_Analysis::*)(const TCollection_AsciiString &)) &ExprIntrp_Analysis::GetFunction, "None", py::arg("name"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp.hxx
	py::class_<ExprIntrp, std::unique_ptr<ExprIntrp, Deleter<ExprIntrp>>> cls_ExprIntrp(mod, "ExprIntrp", "Describes an interpreter for GeneralExpressions, GeneralFunctions, and GeneralRelations defined in package Expr.");
	cls_ExprIntrp.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_SyntaxError.hxx
	py::class_<ExprIntrp_SyntaxError, opencascade::handle<ExprIntrp_SyntaxError>, Standard_Failure> cls_ExprIntrp_SyntaxError(mod, "ExprIntrp_SyntaxError", "None");
	cls_ExprIntrp_SyntaxError.def(py::init<>());
	cls_ExprIntrp_SyntaxError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(const Standard_CString)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
	cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(Standard_SStream &)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
	cls_ExprIntrp_SyntaxError.def_static("NewInstance_", (opencascade::handle<ExprIntrp_SyntaxError> (*)(const Standard_CString)) &ExprIntrp_SyntaxError::NewInstance, "None", py::arg("theMessage"));
	cls_ExprIntrp_SyntaxError.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_SyntaxError::get_type_name, "None");
	cls_ExprIntrp_SyntaxError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_SyntaxError::get_type_descriptor, "None");
	cls_ExprIntrp_SyntaxError.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_SyntaxError::*)() const ) &ExprIntrp_SyntaxError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<ExprIntrp_StackOfGeneralExpression, std::unique_ptr<ExprIntrp_StackOfGeneralExpression, Deleter<ExprIntrp_StackOfGeneralExpression>>, NCollection_BaseList> cls_ExprIntrp_StackOfGeneralExpression(mod, "ExprIntrp_StackOfGeneralExpression", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_ExprIntrp_StackOfGeneralExpression.def(py::init<>());
	cls_ExprIntrp_StackOfGeneralExpression.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralExpression.def(py::init([] (const ExprIntrp_StackOfGeneralExpression &other) {return new ExprIntrp_StackOfGeneralExpression(other);}), "Copy constructor", py::arg("other"));
	cls_ExprIntrp_StackOfGeneralExpression.def("begin", (ExprIntrp_StackOfGeneralExpression::iterator (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::begin, "Returns an iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralExpression.def("end", (ExprIntrp_StackOfGeneralExpression::iterator (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralExpression.def("cbegin", (ExprIntrp_StackOfGeneralExpression::const_iterator (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralExpression.def("cend", (ExprIntrp_StackOfGeneralExpression::const_iterator (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralExpression.def("Size", (Standard_Integer (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::Size, "Size - Number of items");
	cls_ExprIntrp_StackOfGeneralExpression.def("Assign", (ExprIntrp_StackOfGeneralExpression & (ExprIntrp_StackOfGeneralExpression::*)(const ExprIntrp_StackOfGeneralExpression &)) &ExprIntrp_StackOfGeneralExpression::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralExpression.def("assign", (ExprIntrp_StackOfGeneralExpression & (ExprIntrp_StackOfGeneralExpression::*)(const ExprIntrp_StackOfGeneralExpression &)) &ExprIntrp_StackOfGeneralExpression::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Clear", [](ExprIntrp_StackOfGeneralExpression &self) -> void { return self.Clear(); });
	cls_ExprIntrp_StackOfGeneralExpression.def("Clear", (void (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_StackOfGeneralExpression::Clear, "Clear this list", py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralExpression.def("First", (const opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::First, "First item");
	cls_ExprIntrp_StackOfGeneralExpression.def("First", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)()) &ExprIntrp_StackOfGeneralExpression::First, "First item (non-const)");
	cls_ExprIntrp_StackOfGeneralExpression.def("Last", (const opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)() const ) &ExprIntrp_StackOfGeneralExpression::Last, "Last item");
	cls_ExprIntrp_StackOfGeneralExpression.def("Last", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)()) &ExprIntrp_StackOfGeneralExpression::Last, "Last item (non-const)");
	cls_ExprIntrp_StackOfGeneralExpression.def("Append", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &ExprIntrp_StackOfGeneralExpression::Append, "Append one item at the end", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Append", (void (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Append", (void (ExprIntrp_StackOfGeneralExpression::*)(ExprIntrp_StackOfGeneralExpression &)) &ExprIntrp_StackOfGeneralExpression::Append, "Append another list at the end", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Prepend", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &)) &ExprIntrp_StackOfGeneralExpression::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Prepend", (void (ExprIntrp_StackOfGeneralExpression::*)(ExprIntrp_StackOfGeneralExpression &)) &ExprIntrp_StackOfGeneralExpression::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralExpression.def("RemoveFirst", (void (ExprIntrp_StackOfGeneralExpression::*)()) &ExprIntrp_StackOfGeneralExpression::RemoveFirst, "RemoveFirst item");
	cls_ExprIntrp_StackOfGeneralExpression.def("Remove", (void (ExprIntrp_StackOfGeneralExpression::*)(ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("InsertBefore", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("InsertBefore", (void (ExprIntrp_StackOfGeneralExpression::*)(ExprIntrp_StackOfGeneralExpression &, ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("InsertAfter", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_StackOfGeneralExpression::*)(const opencascade::handle<Expr_GeneralExpression> &, ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("InsertAfter", (void (ExprIntrp_StackOfGeneralExpression::*)(ExprIntrp_StackOfGeneralExpression &, ExprIntrp_StackOfGeneralExpression::Iterator &)) &ExprIntrp_StackOfGeneralExpression::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralExpression.def("Reverse", (void (ExprIntrp_StackOfGeneralExpression::*)()) &ExprIntrp_StackOfGeneralExpression::Reverse, "Reverse the list");
	cls_ExprIntrp_StackOfGeneralExpression.def("__iter__", [](const ExprIntrp_StackOfGeneralExpression &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<ExprIntrp_ListIteratorOfStackOfGeneralExpression, std::unique_ptr<ExprIntrp_ListIteratorOfStackOfGeneralExpression, Deleter<ExprIntrp_ListIteratorOfStackOfGeneralExpression>>> cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression(mod, "ExprIntrp_ListIteratorOfStackOfGeneralExpression", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def(py::init<>());
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def("More", (Standard_Boolean (ExprIntrp_ListIteratorOfStackOfGeneralExpression::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralExpression::More, "Check end");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def("Next", (void (ExprIntrp_ListIteratorOfStackOfGeneralExpression::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralExpression::Next, "Make step");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def("Value", (const opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_ListIteratorOfStackOfGeneralExpression::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralExpression::Value, "Constant Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def("Value", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_ListIteratorOfStackOfGeneralExpression::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralExpression::Value, "Non-const Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralExpression.def("ChangeValue", (opencascade::handle<Expr_GeneralExpression> & (ExprIntrp_ListIteratorOfStackOfGeneralExpression::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralExpression::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<ExprIntrp_StackOfGeneralRelation, std::unique_ptr<ExprIntrp_StackOfGeneralRelation, Deleter<ExprIntrp_StackOfGeneralRelation>>, NCollection_BaseList> cls_ExprIntrp_StackOfGeneralRelation(mod, "ExprIntrp_StackOfGeneralRelation", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_ExprIntrp_StackOfGeneralRelation.def(py::init<>());
	cls_ExprIntrp_StackOfGeneralRelation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralRelation.def(py::init([] (const ExprIntrp_StackOfGeneralRelation &other) {return new ExprIntrp_StackOfGeneralRelation(other);}), "Copy constructor", py::arg("other"));
	cls_ExprIntrp_StackOfGeneralRelation.def("begin", (ExprIntrp_StackOfGeneralRelation::iterator (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::begin, "Returns an iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralRelation.def("end", (ExprIntrp_StackOfGeneralRelation::iterator (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralRelation.def("cbegin", (ExprIntrp_StackOfGeneralRelation::const_iterator (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralRelation.def("cend", (ExprIntrp_StackOfGeneralRelation::const_iterator (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralRelation.def("Size", (Standard_Integer (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::Size, "Size - Number of items");
	cls_ExprIntrp_StackOfGeneralRelation.def("Assign", (ExprIntrp_StackOfGeneralRelation & (ExprIntrp_StackOfGeneralRelation::*)(const ExprIntrp_StackOfGeneralRelation &)) &ExprIntrp_StackOfGeneralRelation::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralRelation.def("assign", (ExprIntrp_StackOfGeneralRelation & (ExprIntrp_StackOfGeneralRelation::*)(const ExprIntrp_StackOfGeneralRelation &)) &ExprIntrp_StackOfGeneralRelation::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Clear", [](ExprIntrp_StackOfGeneralRelation &self) -> void { return self.Clear(); });
	cls_ExprIntrp_StackOfGeneralRelation.def("Clear", (void (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_StackOfGeneralRelation::Clear, "Clear this list", py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralRelation.def("First", (const opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::First, "First item");
	cls_ExprIntrp_StackOfGeneralRelation.def("First", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)()) &ExprIntrp_StackOfGeneralRelation::First, "First item (non-const)");
	cls_ExprIntrp_StackOfGeneralRelation.def("Last", (const opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)() const ) &ExprIntrp_StackOfGeneralRelation::Last, "Last item");
	cls_ExprIntrp_StackOfGeneralRelation.def("Last", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)()) &ExprIntrp_StackOfGeneralRelation::Last, "Last item (non-const)");
	cls_ExprIntrp_StackOfGeneralRelation.def("Append", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &ExprIntrp_StackOfGeneralRelation::Append, "Append one item at the end", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Append", (void (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &, ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Append", (void (ExprIntrp_StackOfGeneralRelation::*)(ExprIntrp_StackOfGeneralRelation &)) &ExprIntrp_StackOfGeneralRelation::Append, "Append another list at the end", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Prepend", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &)) &ExprIntrp_StackOfGeneralRelation::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Prepend", (void (ExprIntrp_StackOfGeneralRelation::*)(ExprIntrp_StackOfGeneralRelation &)) &ExprIntrp_StackOfGeneralRelation::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralRelation.def("RemoveFirst", (void (ExprIntrp_StackOfGeneralRelation::*)()) &ExprIntrp_StackOfGeneralRelation::RemoveFirst, "RemoveFirst item");
	cls_ExprIntrp_StackOfGeneralRelation.def("Remove", (void (ExprIntrp_StackOfGeneralRelation::*)(ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("InsertBefore", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &, ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("InsertBefore", (void (ExprIntrp_StackOfGeneralRelation::*)(ExprIntrp_StackOfGeneralRelation &, ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("InsertAfter", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_StackOfGeneralRelation::*)(const opencascade::handle<Expr_GeneralRelation> &, ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("InsertAfter", (void (ExprIntrp_StackOfGeneralRelation::*)(ExprIntrp_StackOfGeneralRelation &, ExprIntrp_StackOfGeneralRelation::Iterator &)) &ExprIntrp_StackOfGeneralRelation::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralRelation.def("Reverse", (void (ExprIntrp_StackOfGeneralRelation::*)()) &ExprIntrp_StackOfGeneralRelation::Reverse, "Reverse the list");
	cls_ExprIntrp_StackOfGeneralRelation.def("__iter__", [](const ExprIntrp_StackOfGeneralRelation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<ExprIntrp_ListIteratorOfStackOfGeneralRelation, std::unique_ptr<ExprIntrp_ListIteratorOfStackOfGeneralRelation, Deleter<ExprIntrp_ListIteratorOfStackOfGeneralRelation>>> cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation(mod, "ExprIntrp_ListIteratorOfStackOfGeneralRelation", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def(py::init<>());
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def("More", (Standard_Boolean (ExprIntrp_ListIteratorOfStackOfGeneralRelation::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralRelation::More, "Check end");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def("Next", (void (ExprIntrp_ListIteratorOfStackOfGeneralRelation::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralRelation::Next, "Make step");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def("Value", (const opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_ListIteratorOfStackOfGeneralRelation::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralRelation::Value, "Constant Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def("Value", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_ListIteratorOfStackOfGeneralRelation::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralRelation::Value, "Non-const Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralRelation.def("ChangeValue", (opencascade::handle<Expr_GeneralRelation> & (ExprIntrp_ListIteratorOfStackOfGeneralRelation::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralRelation::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<ExprIntrp_StackOfGeneralFunction, std::unique_ptr<ExprIntrp_StackOfGeneralFunction, Deleter<ExprIntrp_StackOfGeneralFunction>>, NCollection_BaseList> cls_ExprIntrp_StackOfGeneralFunction(mod, "ExprIntrp_StackOfGeneralFunction", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_ExprIntrp_StackOfGeneralFunction.def(py::init<>());
	cls_ExprIntrp_StackOfGeneralFunction.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralFunction.def(py::init([] (const ExprIntrp_StackOfGeneralFunction &other) {return new ExprIntrp_StackOfGeneralFunction(other);}), "Copy constructor", py::arg("other"));
	cls_ExprIntrp_StackOfGeneralFunction.def("begin", (ExprIntrp_StackOfGeneralFunction::iterator (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::begin, "Returns an iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralFunction.def("end", (ExprIntrp_StackOfGeneralFunction::iterator (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralFunction.def("cbegin", (ExprIntrp_StackOfGeneralFunction::const_iterator (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_ExprIntrp_StackOfGeneralFunction.def("cend", (ExprIntrp_StackOfGeneralFunction::const_iterator (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_ExprIntrp_StackOfGeneralFunction.def("Size", (Standard_Integer (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::Size, "Size - Number of items");
	cls_ExprIntrp_StackOfGeneralFunction.def("Assign", (ExprIntrp_StackOfGeneralFunction & (ExprIntrp_StackOfGeneralFunction::*)(const ExprIntrp_StackOfGeneralFunction &)) &ExprIntrp_StackOfGeneralFunction::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralFunction.def("assign", (ExprIntrp_StackOfGeneralFunction & (ExprIntrp_StackOfGeneralFunction::*)(const ExprIntrp_StackOfGeneralFunction &)) &ExprIntrp_StackOfGeneralFunction::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Clear", [](ExprIntrp_StackOfGeneralFunction &self) -> void { return self.Clear(); });
	cls_ExprIntrp_StackOfGeneralFunction.def("Clear", (void (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_StackOfGeneralFunction::Clear, "Clear this list", py::arg("theAllocator"));
	cls_ExprIntrp_StackOfGeneralFunction.def("First", (const opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::First, "First item");
	cls_ExprIntrp_StackOfGeneralFunction.def("First", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)()) &ExprIntrp_StackOfGeneralFunction::First, "First item (non-const)");
	cls_ExprIntrp_StackOfGeneralFunction.def("Last", (const opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)() const ) &ExprIntrp_StackOfGeneralFunction::Last, "Last item");
	cls_ExprIntrp_StackOfGeneralFunction.def("Last", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)()) &ExprIntrp_StackOfGeneralFunction::Last, "Last item (non-const)");
	cls_ExprIntrp_StackOfGeneralFunction.def("Append", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &)) &ExprIntrp_StackOfGeneralFunction::Append, "Append one item at the end", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Append", (void (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &, ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Append", (void (ExprIntrp_StackOfGeneralFunction::*)(ExprIntrp_StackOfGeneralFunction &)) &ExprIntrp_StackOfGeneralFunction::Append, "Append another list at the end", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Prepend", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &)) &ExprIntrp_StackOfGeneralFunction::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Prepend", (void (ExprIntrp_StackOfGeneralFunction::*)(ExprIntrp_StackOfGeneralFunction &)) &ExprIntrp_StackOfGeneralFunction::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_ExprIntrp_StackOfGeneralFunction.def("RemoveFirst", (void (ExprIntrp_StackOfGeneralFunction::*)()) &ExprIntrp_StackOfGeneralFunction::RemoveFirst, "RemoveFirst item");
	cls_ExprIntrp_StackOfGeneralFunction.def("Remove", (void (ExprIntrp_StackOfGeneralFunction::*)(ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("InsertBefore", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &, ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("InsertBefore", (void (ExprIntrp_StackOfGeneralFunction::*)(ExprIntrp_StackOfGeneralFunction &, ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("InsertAfter", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_StackOfGeneralFunction::*)(const opencascade::handle<Expr_GeneralFunction> &, ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("InsertAfter", (void (ExprIntrp_StackOfGeneralFunction::*)(ExprIntrp_StackOfGeneralFunction &, ExprIntrp_StackOfGeneralFunction::Iterator &)) &ExprIntrp_StackOfGeneralFunction::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_ExprIntrp_StackOfGeneralFunction.def("Reverse", (void (ExprIntrp_StackOfGeneralFunction::*)()) &ExprIntrp_StackOfGeneralFunction::Reverse, "Reverse the list");
	cls_ExprIntrp_StackOfGeneralFunction.def("__iter__", [](const ExprIntrp_StackOfGeneralFunction &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<ExprIntrp_ListIteratorOfStackOfGeneralFunction, std::unique_ptr<ExprIntrp_ListIteratorOfStackOfGeneralFunction, Deleter<ExprIntrp_ListIteratorOfStackOfGeneralFunction>>> cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction(mod, "ExprIntrp_ListIteratorOfStackOfGeneralFunction", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def(py::init<>());
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def("More", (Standard_Boolean (ExprIntrp_ListIteratorOfStackOfGeneralFunction::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralFunction::More, "Check end");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def("Next", (void (ExprIntrp_ListIteratorOfStackOfGeneralFunction::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralFunction::Next, "Make step");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def("Value", (const opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_ListIteratorOfStackOfGeneralFunction::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralFunction::Value, "Constant Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def("Value", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_ListIteratorOfStackOfGeneralFunction::*)()) &ExprIntrp_ListIteratorOfStackOfGeneralFunction::Value, "Non-const Value access");
	cls_ExprIntrp_ListIteratorOfStackOfGeneralFunction.def("ChangeValue", (opencascade::handle<Expr_GeneralFunction> & (ExprIntrp_ListIteratorOfStackOfGeneralFunction::*)() const ) &ExprIntrp_ListIteratorOfStackOfGeneralFunction::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<ExprIntrp_SequenceOfNamedFunction, std::unique_ptr<ExprIntrp_SequenceOfNamedFunction, Deleter<ExprIntrp_SequenceOfNamedFunction>>, NCollection_BaseSequence> cls_ExprIntrp_SequenceOfNamedFunction(mod, "ExprIntrp_SequenceOfNamedFunction", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_ExprIntrp_SequenceOfNamedFunction.def(py::init<>());
	cls_ExprIntrp_SequenceOfNamedFunction.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ExprIntrp_SequenceOfNamedFunction.def(py::init([] (const ExprIntrp_SequenceOfNamedFunction &other) {return new ExprIntrp_SequenceOfNamedFunction(other);}), "Copy constructor", py::arg("other"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("begin", (ExprIntrp_SequenceOfNamedFunction::iterator (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("end", (ExprIntrp_SequenceOfNamedFunction::iterator (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("cbegin", (ExprIntrp_SequenceOfNamedFunction::const_iterator (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("cend", (ExprIntrp_SequenceOfNamedFunction::const_iterator (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Size", (Standard_Integer (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::Size, "Number of items");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Length", (Standard_Integer (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::Length, "Number of items");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Lower", (Standard_Integer (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::Lower, "Method for consistency with other collections.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Upper", (Standard_Integer (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::Upper, "Method for consistency with other collections.");
	cls_ExprIntrp_SequenceOfNamedFunction.def("IsEmpty", (Standard_Boolean (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::IsEmpty, "Empty query");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Reverse", (void (ExprIntrp_SequenceOfNamedFunction::*)()) &ExprIntrp_SequenceOfNamedFunction::Reverse, "Reverse sequence");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Exchange", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, const Standard_Integer)) &ExprIntrp_SequenceOfNamedFunction::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_ExprIntrp_SequenceOfNamedFunction.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_SequenceOfNamedFunction::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Clear", [](ExprIntrp_SequenceOfNamedFunction &self) -> void { return self.Clear(); });
	cls_ExprIntrp_SequenceOfNamedFunction.def("Clear", (void (ExprIntrp_SequenceOfNamedFunction::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_SequenceOfNamedFunction::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Assign", (ExprIntrp_SequenceOfNamedFunction & (ExprIntrp_SequenceOfNamedFunction::*)(const ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("assign", (ExprIntrp_SequenceOfNamedFunction & (ExprIntrp_SequenceOfNamedFunction::*)(const ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Remove", (void (ExprIntrp_SequenceOfNamedFunction::*)(ExprIntrp_SequenceOfNamedFunction::Iterator &)) &ExprIntrp_SequenceOfNamedFunction::Remove, "Remove one item", py::arg("thePosition"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Remove", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedFunction::Remove, "Remove one item", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Remove", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, const Standard_Integer)) &ExprIntrp_SequenceOfNamedFunction::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Append", (void (ExprIntrp_SequenceOfNamedFunction::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::Append, "Append one item", py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Append", (void (ExprIntrp_SequenceOfNamedFunction::*)(ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Prepend", (void (ExprIntrp_SequenceOfNamedFunction::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::Prepend, "Prepend one item", py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Prepend", (void (ExprIntrp_SequenceOfNamedFunction::*)(ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("InsertBefore", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("InsertBefore", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedFunction::*)(ExprIntrp_SequenceOfNamedFunction::Iterator &, const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("Split", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedFunction &)) &ExprIntrp_SequenceOfNamedFunction::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("First", (const opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::First, "First item access");
	cls_ExprIntrp_SequenceOfNamedFunction.def("ChangeFirst", (opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)()) &ExprIntrp_SequenceOfNamedFunction::ChangeFirst, "First item access");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Last", (const opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)() const ) &ExprIntrp_SequenceOfNamedFunction::Last, "Last item access");
	cls_ExprIntrp_SequenceOfNamedFunction.def("ChangeLast", (opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)()) &ExprIntrp_SequenceOfNamedFunction::ChangeLast, "Last item access");
	cls_ExprIntrp_SequenceOfNamedFunction.def("Value", (const opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer) const ) &ExprIntrp_SequenceOfNamedFunction::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("__call__", (const opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer) const ) &ExprIntrp_SequenceOfNamedFunction::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("ChangeValue", (opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedFunction::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("__call__", (opencascade::handle<Expr_NamedFunction> & (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedFunction::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("SetValue", (void (ExprIntrp_SequenceOfNamedFunction::*)(const Standard_Integer, const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_SequenceOfNamedFunction::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedFunction.def("__iter__", [](const ExprIntrp_SequenceOfNamedFunction &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<ExprIntrp_SequenceOfNamedExpression, std::unique_ptr<ExprIntrp_SequenceOfNamedExpression, Deleter<ExprIntrp_SequenceOfNamedExpression>>, NCollection_BaseSequence> cls_ExprIntrp_SequenceOfNamedExpression(mod, "ExprIntrp_SequenceOfNamedExpression", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_ExprIntrp_SequenceOfNamedExpression.def(py::init<>());
	cls_ExprIntrp_SequenceOfNamedExpression.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ExprIntrp_SequenceOfNamedExpression.def(py::init([] (const ExprIntrp_SequenceOfNamedExpression &other) {return new ExprIntrp_SequenceOfNamedExpression(other);}), "Copy constructor", py::arg("other"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("begin", (ExprIntrp_SequenceOfNamedExpression::iterator (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("end", (ExprIntrp_SequenceOfNamedExpression::iterator (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("cbegin", (ExprIntrp_SequenceOfNamedExpression::const_iterator (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("cend", (ExprIntrp_SequenceOfNamedExpression::const_iterator (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Size", (Standard_Integer (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::Size, "Number of items");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Length", (Standard_Integer (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::Length, "Number of items");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Lower", (Standard_Integer (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::Lower, "Method for consistency with other collections.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Upper", (Standard_Integer (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::Upper, "Method for consistency with other collections.");
	cls_ExprIntrp_SequenceOfNamedExpression.def("IsEmpty", (Standard_Boolean (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::IsEmpty, "Empty query");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Reverse", (void (ExprIntrp_SequenceOfNamedExpression::*)()) &ExprIntrp_SequenceOfNamedExpression::Reverse, "Reverse sequence");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Exchange", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, const Standard_Integer)) &ExprIntrp_SequenceOfNamedExpression::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_ExprIntrp_SequenceOfNamedExpression.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_SequenceOfNamedExpression::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Clear", [](ExprIntrp_SequenceOfNamedExpression &self) -> void { return self.Clear(); });
	cls_ExprIntrp_SequenceOfNamedExpression.def("Clear", (void (ExprIntrp_SequenceOfNamedExpression::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ExprIntrp_SequenceOfNamedExpression::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Assign", (ExprIntrp_SequenceOfNamedExpression & (ExprIntrp_SequenceOfNamedExpression::*)(const ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("assign", (ExprIntrp_SequenceOfNamedExpression & (ExprIntrp_SequenceOfNamedExpression::*)(const ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Remove", (void (ExprIntrp_SequenceOfNamedExpression::*)(ExprIntrp_SequenceOfNamedExpression::Iterator &)) &ExprIntrp_SequenceOfNamedExpression::Remove, "Remove one item", py::arg("thePosition"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Remove", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedExpression::Remove, "Remove one item", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Remove", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, const Standard_Integer)) &ExprIntrp_SequenceOfNamedExpression::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Append", (void (ExprIntrp_SequenceOfNamedExpression::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::Append, "Append one item", py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Append", (void (ExprIntrp_SequenceOfNamedExpression::*)(ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Prepend", (void (ExprIntrp_SequenceOfNamedExpression::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::Prepend, "Prepend one item", py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Prepend", (void (ExprIntrp_SequenceOfNamedExpression::*)(ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("InsertBefore", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("InsertBefore", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedExpression::*)(ExprIntrp_SequenceOfNamedExpression::Iterator &, const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("InsertAfter", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("Split", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, ExprIntrp_SequenceOfNamedExpression &)) &ExprIntrp_SequenceOfNamedExpression::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("First", (const opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::First, "First item access");
	cls_ExprIntrp_SequenceOfNamedExpression.def("ChangeFirst", (opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)()) &ExprIntrp_SequenceOfNamedExpression::ChangeFirst, "First item access");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Last", (const opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)() const ) &ExprIntrp_SequenceOfNamedExpression::Last, "Last item access");
	cls_ExprIntrp_SequenceOfNamedExpression.def("ChangeLast", (opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)()) &ExprIntrp_SequenceOfNamedExpression::ChangeLast, "Last item access");
	cls_ExprIntrp_SequenceOfNamedExpression.def("Value", (const opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer) const ) &ExprIntrp_SequenceOfNamedExpression::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("__call__", (const opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer) const ) &ExprIntrp_SequenceOfNamedExpression::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("ChangeValue", (opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedExpression::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("__call__", (opencascade::handle<Expr_NamedExpression> & (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer)) &ExprIntrp_SequenceOfNamedExpression::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("SetValue", (void (ExprIntrp_SequenceOfNamedExpression::*)(const Standard_Integer, const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_SequenceOfNamedExpression::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_ExprIntrp_SequenceOfNamedExpression.def("__iter__", [](const ExprIntrp_SequenceOfNamedExpression &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
