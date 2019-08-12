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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_Token.hxx>
#include <Units_Dimensions.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_Units_Token(py::module &mod){

py::class_<Units_Token, opencascade::handle<Units_Token>, Standard_Transient> cls_Units_Token(mod, "Units_Token", "This class defines an elementary word contained in a Sentence object.");

// Constructors
cls_Units_Token.def(py::init<>());
cls_Units_Token.def(py::init<const Standard_CString>(), py::arg("aword"));
cls_Units_Token.def(py::init<const opencascade::handle<Units_Token> &>(), py::arg("atoken"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("aword"), py::arg("amean"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"));
cls_Units_Token.def(py::init<const Standard_CString, const Standard_CString, const Standard_Real, const opencascade::handle<Units_Dimensions> &>(), py::arg("aword"), py::arg("amean"), py::arg("avalue"), py::arg("adimension"));

// Fields

// Methods
cls_Units_Token.def("Creates", (opencascade::handle<Units_Token> (Units_Token::*)() const) &Units_Token::Creates, "Creates and returns a token, which is a ShiftedToken.");
cls_Units_Token.def("Length", (Standard_Integer (Units_Token::*)() const) &Units_Token::Length, "Returns the length of the word.");
cls_Units_Token.def("Word", (TCollection_AsciiString (Units_Token::*)() const) &Units_Token::Word, "Returns the string <theword>");
cls_Units_Token.def("Word", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Word, "Sets the field <theword> to <aword>.", py::arg("aword"));
cls_Units_Token.def("Mean", (TCollection_AsciiString (Units_Token::*)() const) &Units_Token::Mean, "Returns the significance of the word <theword>, which is in the field <themean>.");
cls_Units_Token.def("Mean", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Mean, "Sets the field <themean> to <amean>.", py::arg("amean"));
cls_Units_Token.def("Value", (Standard_Real (Units_Token::*)() const) &Units_Token::Value, "Returns the value stored in the field <thevalue>.");
cls_Units_Token.def("Value", (void (Units_Token::*)(const Standard_Real)) &Units_Token::Value, "Sets the field <thevalue> to <avalue>.", py::arg("avalue"));
cls_Units_Token.def("Dimensions", (opencascade::handle<Units_Dimensions> (Units_Token::*)() const) &Units_Token::Dimensions, "Returns the dimensions of the token <thedimensions>.");
cls_Units_Token.def("Dimensions", (void (Units_Token::*)(const opencascade::handle<Units_Dimensions> &)) &Units_Token::Dimensions, "Sets the field <thedimensions> to <adimensions>.", py::arg("adimensions"));
cls_Units_Token.def("Update", (void (Units_Token::*)(const Standard_CString)) &Units_Token::Update, "Updates the token <me> with the additional signification <amean> by concatenation of the two strings <themean> and <amean>. If the two significations are the same , an information message is written in the output device.", py::arg("amean"));
cls_Units_Token.def("Add", (opencascade::handle<Units_Token> (Units_Token::*)(const Standard_Integer) const) &Units_Token::Add, "None", py::arg("aninteger"));
cls_Units_Token.def("Add", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Add, "Returns a token which is the addition of <me> and another token <atoken>. The addition is possible if and only if the dimensions are the same.", py::arg("atoken"));
cls_Units_Token.def("Subtract", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Subtract, "Returns a token which is the subtraction of <me> and another token <atoken>. The subtraction is possible if and only if the dimensions are the same.", py::arg("atoken"));
cls_Units_Token.def("Multiply", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Multiply, "Returns a token which is the product of <me> and another token <atoken>.", py::arg("atoken"));
cls_Units_Token.def("Multiplied", (Standard_Real (Units_Token::*)(const Standard_Real) const) &Units_Token::Multiplied, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_Token.def("Divide", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Divide, "Returns a token which is the division of <me> by another token <atoken>.", py::arg("atoken"));
cls_Units_Token.def("Divided", (Standard_Real (Units_Token::*)(const Standard_Real) const) &Units_Token::Divided, "This virtual method is called by the Measurement methods, to compute the measurement during a conversion.", py::arg("avalue"));
cls_Units_Token.def("Power", (opencascade::handle<Units_Token> (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::Power, "Returns a token which is <me> to the power of another token <atoken>. The computation is possible only if <atoken> is a dimensionless constant.", py::arg("atoken"));
cls_Units_Token.def("Power", (opencascade::handle<Units_Token> (Units_Token::*)(const Standard_Real) const) &Units_Token::Power, "Returns a token which is <me> to the power of <anexponent>.", py::arg("anexponent"));
cls_Units_Token.def("IsEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsEqual, "Returns true if the field <theword> and the string <astring> are the same, false otherwise.", py::arg("astring"));
cls_Units_Token.def("IsEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsEqual, "Returns true if the field <theword> and the string <theword> contained in the token <atoken> are the same, false otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsNotEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsNotEqual, "Returns false if the field <theword> and the string <astring> are the same, true otherwise.", py::arg("astring"));
cls_Units_Token.def("IsNotEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsNotEqual, "Returns false if the field <theword> and the string <theword> contained in the token <atoken> are the same, true otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsLessOrEqual", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsLessOrEqual, "Returns true if the field <theword> is strictly contained at the beginning of the string <astring>, false otherwise.", py::arg("astring"));
cls_Units_Token.def("IsGreater", (Standard_Boolean (Units_Token::*)(const Standard_CString) const) &Units_Token::IsGreater, "Returns false if the field <theword> is strictly contained at the beginning of the string <astring>, true otherwise.", py::arg("astring"));
cls_Units_Token.def("IsGreater", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsGreater, "Returns false if the field <theword> is strictly contained at the beginning of the string <astring>, true otherwise.", py::arg("atoken"));
cls_Units_Token.def("IsGreaterOrEqual", (Standard_Boolean (Units_Token::*)(const opencascade::handle<Units_Token> &) const) &Units_Token::IsGreaterOrEqual, "Returns true if the string <astring> is strictly contained at the beginning of the field <theword> false otherwise.", py::arg("atoken"));
cls_Units_Token.def("Dump", (void (Units_Token::*)(const Standard_Integer, const Standard_Integer) const) &Units_Token::Dump, "Useful for debugging", py::arg("ashift"), py::arg("alevel"));
cls_Units_Token.def_static("get_type_name_", (const char * (*)()) &Units_Token::get_type_name, "None");
cls_Units_Token.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_Token::get_type_descriptor, "None");
cls_Units_Token.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_Token::*)() const) &Units_Token::DynamicType, "None");

// Enums

}