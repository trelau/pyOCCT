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
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TCollection_HExtendedString(py::module &mod){

py::class_<TCollection_HExtendedString, opencascade::handle<TCollection_HExtendedString>, Standard_Transient> cls_TCollection_HExtendedString(mod, "TCollection_HExtendedString", "A variable-length sequence of 'extended' (UNICODE) characters (16-bit character type). It provides editing operations with built-in memory management to make ExtendedString objects easier to use than ordinary extended character arrays. HExtendedString objects are handles to strings. - HExtendedString strings may be shared by several objects. - You may use an ExtendedString object to get the actual string. Note: HExtendedString objects use an ExtendedString string as a field.");

// Constructors
cls_TCollection_HExtendedString.def(py::init<>());
cls_TCollection_HExtendedString.def(py::init<const Standard_CString>(), py::arg("message"));
cls_TCollection_HExtendedString.def(py::init<const Standard_ExtString>(), py::arg("message"));
cls_TCollection_HExtendedString.def(py::init<const Standard_ExtCharacter>(), py::arg("aChar"));
cls_TCollection_HExtendedString.def(py::init<const Standard_Integer, const Standard_ExtCharacter>(), py::arg("length"), py::arg("filler"));
cls_TCollection_HExtendedString.def(py::init<const TCollection_ExtendedString &>(), py::arg("aString"));
cls_TCollection_HExtendedString.def(py::init<const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("aString"));
cls_TCollection_HExtendedString.def(py::init<const opencascade::handle<TCollection_HExtendedString> &>(), py::arg("aString"));

// Fields

// Methods
cls_TCollection_HExtendedString.def("AssignCat", (void (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::AssignCat, "Appends <other> to me.", py::arg("other"));
cls_TCollection_HExtendedString.def("Cat", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::Cat, "Returns a string appending <other> to me.", py::arg("other"));
cls_TCollection_HExtendedString.def("ChangeAll", (void (TCollection_HExtendedString::*)(const Standard_ExtCharacter, const Standard_ExtCharacter)) &TCollection_HExtendedString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the string <me>.", py::arg("aChar"), py::arg("NewChar"));
cls_TCollection_HExtendedString.def("Clear", (void (TCollection_HExtendedString::*)()) &TCollection_HExtendedString::Clear, "Removes all characters contained in <me>. This produces an empty ExtendedString.");
cls_TCollection_HExtendedString.def("IsEmpty", (Standard_Boolean (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::IsEmpty, "Returns True if the string <me> contains zero character");
cls_TCollection_HExtendedString.def("Insert", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_HExtendedString::Insert, "Insert a ExtCharacter at position <where>. Example: aString contains 'hy not ?' aString.Insert(1,'W'); gives 'Why not ?' aString contains 'Wh' aString.Insert(3,'y'); gives 'Why' aString contains 'Way' aString.Insert(2,'h'); gives 'Why'", py::arg("where"), py::arg("what"));
cls_TCollection_HExtendedString.def("Insert", (void (TCollection_HExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::Insert, "Insert a HExtendedString at position <where>.", py::arg("where"), py::arg("what"));
cls_TCollection_HExtendedString.def("IsLess", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
cls_TCollection_HExtendedString.def("IsGreater", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
cls_TCollection_HExtendedString.def("IsAscii", (Standard_Boolean (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::IsAscii, "Returns True if the string contains only 'Ascii Range' characters");
cls_TCollection_HExtendedString.def("Length", (Standard_Integer (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::Length, "Returns number of characters in <me>. This is the same functionality as 'strlen' in C.");
cls_TCollection_HExtendedString.def("Remove", [](TCollection_HExtendedString &self, const Standard_Integer a0) -> void { return self.Remove(a0); });
cls_TCollection_HExtendedString.def("Remove", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_HExtendedString::Remove, "Erases <ahowmany> characters from position <where>, <where> included. Example: aString contains 'Hello' aString.Erase(2,2) erases 2 characters from position 1 This gives 'Hlo'.", py::arg("where"), py::arg("ahowmany"));
cls_TCollection_HExtendedString.def("RemoveAll", (void (TCollection_HExtendedString::*)(const Standard_ExtCharacter)) &TCollection_HExtendedString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
cls_TCollection_HExtendedString.def("SetValue", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_HExtendedString::SetValue, "Replaces one character in the string at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
cls_TCollection_HExtendedString.def("SetValue", (void (TCollection_HExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::SetValue, "Replaces a part of <me> by another string.", py::arg("where"), py::arg("what"));
cls_TCollection_HExtendedString.def("Split", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const Standard_Integer)) &TCollection_HExtendedString::Split, "Splits a ExtendedString into two sub-strings. Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
cls_TCollection_HExtendedString.def("Search", (Standard_Integer (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::Search, "Searches a String in <me> from the beginning and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
cls_TCollection_HExtendedString.def("SearchFromEnd", (Standard_Integer (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::SearchFromEnd, "Searches a ExtendedString in another ExtendedString from the end and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
cls_TCollection_HExtendedString.def("ToExtString", (Standard_ExtString (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::ToExtString, "Returns pointer to ExtString");
cls_TCollection_HExtendedString.def("Token", [](TCollection_HExtendedString &self, const Standard_ExtString a0) -> opencascade::handle<TCollection_HExtendedString> { return self.Token(a0); });
cls_TCollection_HExtendedString.def("Token", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const Standard_ExtString, const Standard_Integer) const) &TCollection_HExtendedString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns an empty String. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
cls_TCollection_HExtendedString.def("Trunc", (void (TCollection_HExtendedString::*)(const Standard_Integer)) &TCollection_HExtendedString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel'", py::arg("ahowmany"));
cls_TCollection_HExtendedString.def("Value", (Standard_ExtCharacter (TCollection_HExtendedString::*)(const Standard_Integer) const) &TCollection_HExtendedString::Value, "Returns ExtCharacter at position <where> in <me>. If <where> is less than zero or greater than the length of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e'", py::arg("where"));
cls_TCollection_HExtendedString.def("String", (const TCollection_ExtendedString & (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::String, "Returns the field myString");
cls_TCollection_HExtendedString.def("Print", (void (TCollection_HExtendedString::*)(Standard_OStream &) const) &TCollection_HExtendedString::Print, "Displays <me> .", py::arg("astream"));
cls_TCollection_HExtendedString.def("IsSameState", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const) &TCollection_HExtendedString::IsSameState, "None", py::arg("other"));
cls_TCollection_HExtendedString.def_static("get_type_name_", (const char * (*)()) &TCollection_HExtendedString::get_type_name, "None");
cls_TCollection_HExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_HExtendedString::get_type_descriptor, "None");
cls_TCollection_HExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_HExtendedString::*)() const) &TCollection_HExtendedString::DynamicType, "None");

// Enums

}