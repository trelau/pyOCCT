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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ExprIntrp_Generator.hxx>
#include <TCollection_AsciiString.hxx>
#include <ExprIntrp_GenExp.hxx>
#include <ExprIntrp_GenFct.hxx>
#include <ExprIntrp_GenRel.hxx>
#include <ExprIntrp_Analysis.hxx>
#include <ExprIntrp.hxx>
#include <NCollection_List.hxx>
#include <Expr_GeneralExpression.hxx>
#include <ExprIntrp_StackOfGeneralExpression.hxx>
#include <Expr_GeneralRelation.hxx>
#include <ExprIntrp_StackOfGeneralRelation.hxx>
#include <Expr_GeneralFunction.hxx>
#include <ExprIntrp_StackOfGeneralFunction.hxx>
#include <NCollection_Sequence.hxx>
#include <Expr_NamedFunction.hxx>
#include <ExprIntrp_SequenceOfNamedFunction.hxx>
#include <Expr_NamedExpression.hxx>
#include <ExprIntrp_SequenceOfNamedExpression.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Standard_Failure.hxx>
#include <ExprIntrp_SyntaxError.hxx>
#include <Standard_SStream.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(ExprIntrp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Expr");
py::module::import("OCCT.TColStd");

// CLASS: EXPRINTRP
py::class_<ExprIntrp> cls_ExprIntrp(mod, "ExprIntrp", "Describes an interpreter for GeneralExpressions, GeneralFunctions, and GeneralRelations defined in package Expr.");

// Constructors
cls_ExprIntrp.def(py::init<>());

// Methods
// cls_ExprIntrp.def_static("operator new_", (void * (*)(size_t)) &ExprIntrp::operator new, "None", py::arg("theSize"));
// cls_ExprIntrp.def_static("operator delete_", (void (*)(void *)) &ExprIntrp::operator delete, "None", py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator new[]_", (void * (*)(size_t)) &ExprIntrp::operator new[], "None", py::arg("theSize"));
// cls_ExprIntrp.def_static("operator delete[]_", (void (*)(void *)) &ExprIntrp::operator delete[], "None", py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator new_", (void * (*)(size_t, void *)) &ExprIntrp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ExprIntrp.def_static("operator delete_", (void (*)(void *, void *)) &ExprIntrp::operator delete, "None", py::arg(""), py::arg(""));

// TYPEDEF: EXPRINTRP_STACKOFGENERALEXPRESSION
bind_NCollection_List<opencascade::handle<Expr_GeneralExpression> >(mod, "ExprIntrp_StackOfGeneralExpression", py::module_local(false));

// TYPEDEF: EXPRINTRP_LISTITERATOROFSTACKOFGENERALEXPRESSION
bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralExpression> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralExpression", py::module_local(false));

// TYPEDEF: EXPRINTRP_STACKOFGENERALRELATION
bind_NCollection_List<opencascade::handle<Expr_GeneralRelation> >(mod, "ExprIntrp_StackOfGeneralRelation", py::module_local(false));

// TYPEDEF: EXPRINTRP_LISTITERATOROFSTACKOFGENERALRELATION
bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralRelation> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralRelation", py::module_local(false));

// TYPEDEF: EXPRINTRP_STACKOFGENERALFUNCTION
bind_NCollection_List<opencascade::handle<Expr_GeneralFunction> >(mod, "ExprIntrp_StackOfGeneralFunction", py::module_local(false));

// TYPEDEF: EXPRINTRP_LISTITERATOROFSTACKOFGENERALFUNCTION
bind_NCollection_TListIterator<opencascade::handle<Expr_GeneralFunction> >(mod, "ExprIntrp_ListIteratorOfStackOfGeneralFunction", py::module_local(false));

// TYPEDEF: EXPRINTRP_SEQUENCEOFNAMEDFUNCTION
bind_NCollection_Sequence<opencascade::handle<Expr_NamedFunction> >(mod, "ExprIntrp_SequenceOfNamedFunction", py::module_local(false));

// TYPEDEF: EXPRINTRP_SEQUENCEOFNAMEDEXPRESSION
bind_NCollection_Sequence<opencascade::handle<Expr_NamedExpression> >(mod, "ExprIntrp_SequenceOfNamedExpression", py::module_local(false));

// CLASS: EXPRINTRP_ANALYSIS
py::class_<ExprIntrp_Analysis> cls_ExprIntrp_Analysis(mod, "ExprIntrp_Analysis", "None");

// Constructors
cls_ExprIntrp_Analysis.def(py::init<>());

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

// CLASS: EXPRINTRP_GENERATOR
py::class_<ExprIntrp_Generator, opencascade::handle<ExprIntrp_Generator>, Standard_Transient> cls_ExprIntrp_Generator(mod, "ExprIntrp_Generator", "Implements general services for interpretation of expressions.");

// Methods
cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedFunction> &)) &ExprIntrp_Generator::Use, "None", py::arg("func"));
cls_ExprIntrp_Generator.def("Use", (void (ExprIntrp_Generator::*)(const opencascade::handle<Expr_NamedExpression> &)) &ExprIntrp_Generator::Use, "None", py::arg("named"));
cls_ExprIntrp_Generator.def("GetNamed", (const ExprIntrp_SequenceOfNamedExpression & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::GetNamed, "None");
cls_ExprIntrp_Generator.def("GetFunctions", (const ExprIntrp_SequenceOfNamedFunction & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::GetFunctions, "None");
cls_ExprIntrp_Generator.def("GetNamed", (opencascade::handle<Expr_NamedExpression> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const) &ExprIntrp_Generator::GetNamed, "Returns NamedExpression with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
cls_ExprIntrp_Generator.def("GetFunction", (opencascade::handle<Expr_NamedFunction> (ExprIntrp_Generator::*)(const TCollection_AsciiString &) const) &ExprIntrp_Generator::GetFunction, "Returns NamedFunction with name <name> already interpreted if it exists. Returns a null handle if not.", py::arg("name"));
cls_ExprIntrp_Generator.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_Generator::get_type_name, "None");
cls_ExprIntrp_Generator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_Generator::get_type_descriptor, "None");
cls_ExprIntrp_Generator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_Generator::*)() const) &ExprIntrp_Generator::DynamicType, "None");

// CLASS: EXPRINTRP_GENEXP
py::class_<ExprIntrp_GenExp, opencascade::handle<ExprIntrp_GenExp>, ExprIntrp_Generator> cls_ExprIntrp_GenExp(mod, "ExprIntrp_GenExp", "This class permits, from a string, to create any kind of expression of package Expr by using built-in functions such as Sin,Cos, etc, and by creating variables.");

// Methods
cls_ExprIntrp_GenExp.def_static("Create_", (opencascade::handle<ExprIntrp_GenExp> (*)()) &ExprIntrp_GenExp::Create, "None");
cls_ExprIntrp_GenExp.def("Process", (void (ExprIntrp_GenExp::*)(const TCollection_AsciiString &)) &ExprIntrp_GenExp::Process, "Processes given string.", py::arg("str"));
cls_ExprIntrp_GenExp.def("IsDone", (Standard_Boolean (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::IsDone, "Returns false if any syntax error has occurred during process.");
cls_ExprIntrp_GenExp.def("Expression", (opencascade::handle<Expr_GeneralExpression> (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::Expression, "Returns expression generated. Raises an exception if IsDone answers false.");
cls_ExprIntrp_GenExp.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenExp::get_type_name, "None");
cls_ExprIntrp_GenExp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenExp::get_type_descriptor, "None");
cls_ExprIntrp_GenExp.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenExp::*)() const) &ExprIntrp_GenExp::DynamicType, "None");

// CLASS: EXPRINTRP_GENFCT
py::class_<ExprIntrp_GenFct, opencascade::handle<ExprIntrp_GenFct>, ExprIntrp_Generator> cls_ExprIntrp_GenFct(mod, "ExprIntrp_GenFct", "Implements an interpreter for defining functions. All its functionnalities can be found in class GenExp.");

// Methods
cls_ExprIntrp_GenFct.def_static("Create_", (opencascade::handle<ExprIntrp_GenFct> (*)()) &ExprIntrp_GenFct::Create, "None");
cls_ExprIntrp_GenFct.def("Process", (void (ExprIntrp_GenFct::*)(const TCollection_AsciiString &)) &ExprIntrp_GenFct::Process, "None", py::arg("str"));
cls_ExprIntrp_GenFct.def("IsDone", (Standard_Boolean (ExprIntrp_GenFct::*)() const) &ExprIntrp_GenFct::IsDone, "None");
cls_ExprIntrp_GenFct.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenFct::get_type_name, "None");
cls_ExprIntrp_GenFct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenFct::get_type_descriptor, "None");
cls_ExprIntrp_GenFct.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenFct::*)() const) &ExprIntrp_GenFct::DynamicType, "None");

// CLASS: EXPRINTRP_GENREL
py::class_<ExprIntrp_GenRel, opencascade::handle<ExprIntrp_GenRel>, ExprIntrp_Generator> cls_ExprIntrp_GenRel(mod, "ExprIntrp_GenRel", "Implements an interpreter for equations or system of equations made of expressions of package Expr.");

// Methods
cls_ExprIntrp_GenRel.def_static("Create_", (opencascade::handle<ExprIntrp_GenRel> (*)()) &ExprIntrp_GenRel::Create, "None");
cls_ExprIntrp_GenRel.def("Process", (void (ExprIntrp_GenRel::*)(const TCollection_AsciiString &)) &ExprIntrp_GenRel::Process, "Processes given string.", py::arg("str"));
cls_ExprIntrp_GenRel.def("IsDone", (Standard_Boolean (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::IsDone, "Returns false if any syntax error has occurred during process.");
cls_ExprIntrp_GenRel.def("Relation", (opencascade::handle<Expr_GeneralRelation> (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::Relation, "Returns relation generated. Raises an exception if IsDone answers false.");
cls_ExprIntrp_GenRel.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_GenRel::get_type_name, "None");
cls_ExprIntrp_GenRel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_GenRel::get_type_descriptor, "None");
cls_ExprIntrp_GenRel.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_GenRel::*)() const) &ExprIntrp_GenRel::DynamicType, "None");

// CLASS: EXPRINTRP_SYNTAXERROR
py::class_<ExprIntrp_SyntaxError, opencascade::handle<ExprIntrp_SyntaxError>, Standard_Failure> cls_ExprIntrp_SyntaxError(mod, "ExprIntrp_SyntaxError", "None");

// Constructors
cls_ExprIntrp_SyntaxError.def(py::init<>());
cls_ExprIntrp_SyntaxError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(const Standard_CString)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("Raise_", (void (*)(Standard_SStream &)) &ExprIntrp_SyntaxError::Raise, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("NewInstance_", (opencascade::handle<ExprIntrp_SyntaxError> (*)(const Standard_CString)) &ExprIntrp_SyntaxError::NewInstance, "None", py::arg("theMessage"));
cls_ExprIntrp_SyntaxError.def_static("get_type_name_", (const char * (*)()) &ExprIntrp_SyntaxError::get_type_name, "None");
cls_ExprIntrp_SyntaxError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ExprIntrp_SyntaxError::get_type_descriptor, "None");
cls_ExprIntrp_SyntaxError.def("DynamicType", (const opencascade::handle<Standard_Type> & (ExprIntrp_SyntaxError::*)() const) &ExprIntrp_SyntaxError::DynamicType, "None");


}
