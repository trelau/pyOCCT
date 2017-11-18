#include <pyOCCT_Common.hpp>

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
#include <NCollection_Templates.hpp>

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralExpression.hxx
	bind_NCollection_List<opencascade::handle<Expr_GeneralExpression> >(mod, "ExprIntrp_StackOfGeneralExpression");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralExpression.hxx
	bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralExpression> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralExpression");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralRelation.hxx
	bind_NCollection_List<opencascade::handle<Expr_GeneralRelation> >(mod, "ExprIntrp_StackOfGeneralRelation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralRelation.hxx
	bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralRelation> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralRelation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralFunction.hxx
	bind_NCollection_List<opencascade::handle<Expr_GeneralFunction> >(mod, "ExprIntrp_StackOfGeneralFunction");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_StackOfGeneralFunction.hxx
	bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralFunction> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralFunction");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_SequenceOfNamedFunction.hxx
	bind_NCollection_Sequence<opencascade::handle<Expr_NamedFunction> >(mod, "ExprIntrp_SequenceOfNamedFunction");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ExprIntrp_SequenceOfNamedExpression.hxx
	bind_NCollection_Sequence<opencascade::handle<Expr_NamedExpression> >(mod, "ExprIntrp_SequenceOfNamedExpression");


}
