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
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_PCharacter.hxx>
#include <Standard_PExtCharacter.hxx>

void bind_TCollection_ExtendedString(py::module &mod){

py::class_<TCollection_ExtendedString> cls_TCollection_ExtendedString(mod, "TCollection_ExtendedString", "A variable-length sequence of 'extended' (UNICODE) characters (16-bit character type). It provides editing operations with built-in memory management to make ExtendedString objects easier to use than ordinary extended character arrays. ExtendedString objects follow 'value semantics', that is, they are the actual strings, not handles to strings, and are copied through assignment. You may use HExtendedString objects to get handles to strings.");

// Constructors
cls_TCollection_ExtendedString.def(py::init<>());
cls_TCollection_ExtendedString.def(py::init<const Standard_CString>(), py::arg("astring"));
cls_TCollection_ExtendedString.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("astring"), py::arg("isMultiByte"));
cls_TCollection_ExtendedString.def(py::init<const Standard_ExtString>(), py::arg("astring"));
cls_TCollection_ExtendedString.def(py::init<const Standard_WideChar *>(), py::arg("theStringUtf"));
cls_TCollection_ExtendedString.def(py::init<const Standard_Character>(), py::arg("aChar"));
cls_TCollection_ExtendedString.def(py::init<const Standard_ExtCharacter>(), py::arg("aChar"));
cls_TCollection_ExtendedString.def(py::init<const Standard_Integer, const Standard_ExtCharacter>(), py::arg("length"), py::arg("filler"));
cls_TCollection_ExtendedString.def(py::init<const Standard_Integer>(), py::arg("value"));
cls_TCollection_ExtendedString.def(py::init<const Standard_Real>(), py::arg("value"));
cls_TCollection_ExtendedString.def(py::init<const TCollection_ExtendedString &>(), py::arg("astring"));
// cls_TCollection_ExtendedString.def(py::init<TCollection_ExtendedString &&>(), py::arg("theOther"));
cls_TCollection_ExtendedString.def(py::init<const TCollection_AsciiString &>(), py::arg("astring"));

// Fields

// Methods
// cls_TCollection_ExtendedString.def_static("operator new_", (void * (*)(size_t)) &TCollection_ExtendedString::operator new, "None", py::arg("theSize"));
// cls_TCollection_ExtendedString.def_static("operator delete_", (void (*)(void *)) &TCollection_ExtendedString::operator delete, "None", py::arg("theAddress"));
// cls_TCollection_ExtendedString.def_static("operator new[]_", (void * (*)(size_t)) &TCollection_ExtendedString::operator new[], "None", py::arg("theSize"));
// cls_TCollection_ExtendedString.def_static("operator delete[]_", (void (*)(void *)) &TCollection_ExtendedString::operator delete[], "None", py::arg("theAddress"));
// cls_TCollection_ExtendedString.def_static("operator new_", (void * (*)(size_t, void *)) &TCollection_ExtendedString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TCollection_ExtendedString.def_static("operator delete_", (void (*)(void *, void *)) &TCollection_ExtendedString::operator delete, "None", py::arg(""), py::arg(""));
cls_TCollection_ExtendedString.def("AssignCat", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::AssignCat, "Appends the other extended string to this extended string. Note that this method is an alias of operator +=. Example: aString += anotherString", py::arg("other"));
cls_TCollection_ExtendedString.def("__iadd__", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::operator+=, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("Cat", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::Cat, "Appends <other> to me.", py::arg("other"));
cls_TCollection_ExtendedString.def("__add__", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::operator+, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("ChangeAll", (void (TCollection_ExtendedString::*)(const Standard_ExtCharacter, const Standard_ExtCharacter)) &TCollection_ExtendedString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the ExtendedString <me>. The substitution can be case sensitive. If you don't use default case sensitive, no matter wether aChar is uppercase or not.", py::arg("aChar"), py::arg("NewChar"));
cls_TCollection_ExtendedString.def("Clear", (void (TCollection_ExtendedString::*)()) &TCollection_ExtendedString::Clear, "Removes all characters contained in <me>. This produces an empty ExtendedString.");
cls_TCollection_ExtendedString.def("Copy", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::Copy, "Copy <fromwhere> to <me>. Used as operator =", py::arg("fromwhere"));
// cls_TCollection_ExtendedString.def("operator=", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::operator=, "None", py::arg("fromwhere"));
cls_TCollection_ExtendedString.def("Swap", (void (TCollection_ExtendedString::*)(TCollection_ExtendedString &)) &TCollection_ExtendedString::Swap, "Exchange the data of two strings (without reallocating memory).", py::arg("theOther"));
// cls_TCollection_ExtendedString.def("operator=", (TCollection_ExtendedString & (TCollection_ExtendedString::*)(TCollection_ExtendedString &&)) &TCollection_ExtendedString::operator=, "Move assignment operator", py::arg("theOther"));
cls_TCollection_ExtendedString.def("Insert", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_ExtendedString::Insert, "Insert a Character at position <where>.", py::arg("where"), py::arg("what"));
cls_TCollection_ExtendedString.def("Insert", (void (TCollection_ExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TCollection_ExtendedString::Insert, "Insert a ExtendedString at position <where>.", py::arg("where"), py::arg("what"));
cls_TCollection_ExtendedString.def("IsEmpty", (Standard_Boolean (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::IsEmpty, "Returns True if this string contains no characters.");
cls_TCollection_ExtendedString.def("IsEqual", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==", py::arg("other"));
cls_TCollection_ExtendedString.def("__eq__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::operator==, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsEqual", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==", py::arg("other"));
cls_TCollection_ExtendedString.def("__eq__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::operator==, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsDifferent", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::IsDifferent, "Returns true if there are differences between the characters in this extended string and the other extended string. Note that this method is an alias of operator !=.", py::arg("other"));
cls_TCollection_ExtendedString.def("__ne__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::operator!=, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsDifferent", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::IsDifferent, "Returns true if there are differences between the characters in this extended string and the other extended string. Note that this method is an alias of operator !=.", py::arg("other"));
cls_TCollection_ExtendedString.def("__ne__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::operator!=, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsLess", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
cls_TCollection_ExtendedString.def("__lt__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::operator<, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsLess", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
cls_TCollection_ExtendedString.def("__lt__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::operator<, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsGreater", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
cls_TCollection_ExtendedString.def("__gt__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const) &TCollection_ExtendedString::operator>, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("IsGreater", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
cls_TCollection_ExtendedString.def("__gt__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::operator>, py::is_operator(), "None", py::arg("other"));
cls_TCollection_ExtendedString.def("StartsWith", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::StartsWith, "Determines whether the beginning of this string instance matches the specified string.", py::arg("theStartString"));
cls_TCollection_ExtendedString.def("EndsWith", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::EndsWith, "Determines whether the end of this string instance matches the specified string.", py::arg("theEndString"));
cls_TCollection_ExtendedString.def("IsAscii", (Standard_Boolean (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::IsAscii, "Returns True if the ExtendedString contains only 'Ascii Range' characters .");
cls_TCollection_ExtendedString.def("Length", (Standard_Integer (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::Length, "Returns the number of 16-bit code units (might be greater than number of Unicode symbols if string contains surrogate pairs).");
cls_TCollection_ExtendedString.def("Print", (void (TCollection_ExtendedString::*)(Standard_OStream &) const) &TCollection_ExtendedString::Print, "Displays <me> .", py::arg("astream"));
cls_TCollection_ExtendedString.def("RemoveAll", (void (TCollection_ExtendedString::*)(const Standard_ExtCharacter)) &TCollection_ExtendedString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
cls_TCollection_ExtendedString.def("Remove", [](TCollection_ExtendedString &self, const Standard_Integer a0) -> void { return self.Remove(a0); });
cls_TCollection_ExtendedString.def("Remove", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_ExtendedString::Remove, "Erases <ahowmany> characters from position <where>,<where> included.", py::arg("where"), py::arg("ahowmany"));
cls_TCollection_ExtendedString.def("Search", (Standard_Integer (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::Search, "Searches a ExtendedString in <me> from the beginning and returns position of first item <what> matching. it returns -1 if not found.", py::arg("what"));
cls_TCollection_ExtendedString.def("SearchFromEnd", (Standard_Integer (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const) &TCollection_ExtendedString::SearchFromEnd, "Searches a ExtendedString in another ExtendedString from the end and returns position of first item <what> matching. it returns -1 if not found.", py::arg("what"));
cls_TCollection_ExtendedString.def("SetValue", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_ExtendedString::SetValue, "Replaces one character in the ExtendedString at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised.", py::arg("where"), py::arg("what"));
cls_TCollection_ExtendedString.def("SetValue", (void (TCollection_ExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TCollection_ExtendedString::SetValue, "Replaces a part of <me> by another ExtendedString see above.", py::arg("where"), py::arg("what"));
cls_TCollection_ExtendedString.def("Split", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const Standard_Integer)) &TCollection_ExtendedString::Split, "Splits this extended string into two sub-strings at position where. - The second sub-string (from position where + 1 of this string to the end) is returned in a new extended string. - this extended string is modified: its last characters are removed, it becomes equal to the first sub-string (from the first character to position where). Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
cls_TCollection_ExtendedString.def("Token", [](TCollection_ExtendedString &self, const Standard_ExtString a0) -> TCollection_ExtendedString { return self.Token(a0); });
cls_TCollection_ExtendedString.def("Token", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const Standard_ExtString, const Standard_Integer) const) &TCollection_ExtendedString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns an empty AsciiString. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed : aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
cls_TCollection_ExtendedString.def("ToExtString", (Standard_ExtString (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::ToExtString, "Returns pointer to ExtString");
// cls_TCollection_ExtendedString.def("ToWideString", (const Standard_WideChar * (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::ToWideString, "Returns pointer to string as wchar_t* on Windows platform where wchar_t* is considered as UTF-16 string. This method is useful to pass string into wide-char system APIs, and makes sense only on Windows (other systems use UTF-8 and can miss wide-char functions at all).");
cls_TCollection_ExtendedString.def("Trunc", (void (TCollection_ExtendedString::*)(const Standard_Integer)) &TCollection_ExtendedString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel' Exceptions Standard_OutOfRange if ahowmany is greater than the length of this string.", py::arg("ahowmany"));
cls_TCollection_ExtendedString.def("Value", (Standard_ExtCharacter (TCollection_ExtendedString::*)(const Standard_Integer) const) &TCollection_ExtendedString::Value, "Returns character at position <where> in <me>. If <where> is less than zero or greater than the lenght of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e' Exceptions Standard_OutOfRange if where lies outside the bounds of this extended string.", py::arg("where"));
cls_TCollection_ExtendedString.def_static("HashCode_", (Standard_Integer (*)(const TCollection_ExtendedString &, const Standard_Integer)) &TCollection_ExtendedString::HashCode, "Returns a hashed value for the extended string within the range 1..theUpper. Note: if string is ASCII, the computed value is the same as the value computed with the HashCode function on a TCollection_AsciiString string composed with equivalent ASCII characters.", py::arg("theString"), py::arg("theUpper"));
cls_TCollection_ExtendedString.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==.", py::arg("theString1"), py::arg("theString2"));
// cls_TCollection_ExtendedString.def("ToUTF8CString", (Standard_Integer (TCollection_ExtendedString::*)(Standard_PCharacter &) const) &TCollection_ExtendedString::ToUTF8CString, "Converts the internal <mystring> to UTF8 coding and returns length of the out CString. A memory for the <theCString> should be allocated before call!", py::arg("theCString"));
cls_TCollection_ExtendedString.def("LengthOfCString", (Standard_Integer (TCollection_ExtendedString::*)() const) &TCollection_ExtendedString::LengthOfCString, "Returns expected CString length in UTF8 coding. It can be used for memory calculation before converting to CString containing symbols in UTF8 coding.");

// Enums

}