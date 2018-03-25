/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_PCharacter.hxx>
#include <Standard_IStream.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TCollection_BasicMap.hxx>
#include <TCollection.hxx>
#include <TCollection_BaseSequence.hxx>
#include <TCollection_SeqNodePtr.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_MapNodePtr.hxx>
#include <TCollection_MapNode.hxx>
#include <TCollection_Side.hxx>

PYBIND11_MODULE(TCollection, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_Side.hxx
	py::enum_<TCollection_Side>(mod, "TCollection_Side", "None")
		.value("TCollection_Left", TCollection_Side::TCollection_Left)
		.value("TCollection_Right", TCollection_Side::TCollection_Right)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_ExtendedString.hxx
	mod.def("HashCode", (Standard_Integer (*)(const TCollection_ExtendedString &, const Standard_Integer)) &HashCode, "Compute hash code for extended string", py::arg("theString"), py::arg("theUpper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_AsciiString.lxx
	mod.def("IsEqual", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &IsEqual, "None", py::arg("string1"), py::arg("string2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_HAsciiString.hxx
	py::class_<TCollection_HAsciiString, opencascade::handle<TCollection_HAsciiString>, Standard_Transient> cls_TCollection_HAsciiString(mod, "TCollection_HAsciiString", "A variable-length sequence of ASCII characters (normal 8-bit character type). It provides editing operations with built-in memory management to make HAsciiString objects easier to use than ordinary character arrays. HAsciiString objects are handles to strings. - HAsciiString strings may be shared by several objects. - You may use an AsciiString object to get the actual string. Note: HAsciiString objects use an AsciiString string as a field.");
	cls_TCollection_HAsciiString.def(py::init<>());
	cls_TCollection_HAsciiString.def(py::init<const Standard_CString>(), py::arg("message"));
	cls_TCollection_HAsciiString.def(py::init<const Standard_Character>(), py::arg("aChar"));
	cls_TCollection_HAsciiString.def(py::init<const Standard_Integer, const Standard_Character>(), py::arg("length"), py::arg("filler"));
	cls_TCollection_HAsciiString.def(py::init<const Standard_Integer>(), py::arg("value"));
	cls_TCollection_HAsciiString.def(py::init<const Standard_Real>(), py::arg("value"));
	cls_TCollection_HAsciiString.def(py::init<const TCollection_AsciiString &>(), py::arg("aString"));
	cls_TCollection_HAsciiString.def(py::init<const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("aString"));
	cls_TCollection_HAsciiString.def(py::init<const opencascade::handle<TCollection_HExtendedString> &, const Standard_Character>(), py::arg("aString"), py::arg("replaceNonAscii"));
	cls_TCollection_HAsciiString.def("AssignCat", (void (TCollection_HAsciiString::*)(const Standard_CString)) &TCollection_HAsciiString::AssignCat, "Appends <other> to me.", py::arg("other"));
	cls_TCollection_HAsciiString.def("AssignCat", (void (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::AssignCat, "Appends <other> to me. Example: aString = aString + anotherString", py::arg("other"));
	cls_TCollection_HAsciiString.def("Capitalize", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::Capitalize, "Converts the first character into its corresponding upper-case character and the other characters into lowercase. Example: before me = 'hellO ' after me = 'Hello '");
	cls_TCollection_HAsciiString.def("Cat", (opencascade::handle<TCollection_HAsciiString> (TCollection_HAsciiString::*)(const Standard_CString) const ) &TCollection_HAsciiString::Cat, "Creates a new string by concatenation of this ASCII string and the other ASCII string. Example: aString = aString + anotherString aString = aString + 'Dummy' aString contains 'I say ' aString = aString + 'Hello ' + 'Dolly' gives 'I say Hello Dolly' Warning: To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
	cls_TCollection_HAsciiString.def("Cat", (opencascade::handle<TCollection_HAsciiString> (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::Cat, "Creates a new string by concatenation of this ASCII string and the other ASCII string. Example: aString = aString + anotherString", py::arg("other"));
	cls_TCollection_HAsciiString.def("Center", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_HAsciiString::Center, "Modifies this ASCII string so that its length becomes equal to Width and the new characters are equal to Filler. New characters are added both at the beginning and at the end of this string. If Width is less than the length of this ASCII string, nothing happens. Example Handle(TCollection_HAsciiString) myAlphabet = new TCollection_HAsciiString ('abcdef'); myAlphabet->Center(9,' '); assert ( !strcmp( myAlphabet->ToCString(), ' abcdef ') );", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_HAsciiString.def("ChangeAll", [](TCollection_HAsciiString &self, const Standard_Character a0, const Standard_Character a1) -> void { return self.ChangeAll(a0, a1); }, py::arg("aChar"), py::arg("NewChar"));
	cls_TCollection_HAsciiString.def("ChangeAll", (void (TCollection_HAsciiString::*)(const Standard_Character, const Standard_Character, const Standard_Boolean)) &TCollection_HAsciiString::ChangeAll, "Replaces all characters equal to aChar by NewChar in this ASCII string. The substitution is case sensitive if CaseSensitive is true (default value). If you do not use the default case sensitive option, it does not matter whether aChar is upper-case or not. Example Handle(TCollection_HAsciiString) myMistake = new TCollection_HAsciiString ('Hather'); myMistake->ChangeAll('H','F'); assert ( !strcmp( myMistake->ToCString(), 'Father') );", py::arg("aChar"), py::arg("NewChar"), py::arg("CaseSensitive"));
	cls_TCollection_HAsciiString.def("Clear", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::Clear, "Removes all characters contained in <me>. This produces an empty HAsciiString.");
	cls_TCollection_HAsciiString.def("FirstLocationInSet", (Standard_Integer (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer) const ) &TCollection_HAsciiString::FirstLocationInSet, "Returns the index of the first character of <me> that is present in <Set>. The search begins to the index FromIndex and ends to the the index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 1", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_HAsciiString.def("FirstLocationNotInSet", (Standard_Integer (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer) const ) &TCollection_HAsciiString::FirstLocationNotInSet, "Returns the index of the first character of <me> that is not present in the set <Set>. The search begins to the index FromIndex and ends to the the index ToIndex in <me>. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 3", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_HAsciiString.def("Insert", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_HAsciiString::Insert, "Insert a Character at position <where>. Example: aString contains 'hy not ?' aString.Insert(1,'W'); gives 'Why not ?' aString contains 'Wh' aString.Insert(3,'y'); gives 'Why' aString contains 'Way' aString.Insert(2,'h'); gives 'Why'", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("Insert", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_HAsciiString::Insert, "Insert a HAsciiString at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("Insert", (void (TCollection_HAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::Insert, "Insert a HAsciiString at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("InsertAfter", (void (TCollection_HAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::InsertAfter, "Inserts the other ASCII string a after a specific index in the string <me> Example: before me = 'cde' , Index = 0 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
	cls_TCollection_HAsciiString.def("InsertBefore", (void (TCollection_HAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::InsertBefore, "Inserts the other ASCII string a before a specific index in the string <me> Raises an exception if Index is out of bounds Example: before me = 'cde' , Index = 1 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
	cls_TCollection_HAsciiString.def("IsEmpty", (Standard_Boolean (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::IsEmpty, "Returns True if the string <me> contains zero character");
	cls_TCollection_HAsciiString.def("IsLess", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::IsLess, "Returns TRUE if <me> is 'ASCII' less than <other>.", py::arg("other"));
	cls_TCollection_HAsciiString.def("IsGreater", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::IsGreater, "Returns TRUE if <me> is 'ASCII' greater than <other>.", py::arg("other"));
	cls_TCollection_HAsciiString.def("IntegerValue", (Standard_Integer (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::IntegerValue, "Converts a HAsciiString containing a numeric expression to an Integer. Example: '215' returns 215.");
	cls_TCollection_HAsciiString.def("IsIntegerValue", (Standard_Boolean (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::IsIntegerValue, "Returns True if the string contains an integer value.");
	cls_TCollection_HAsciiString.def("IsRealValue", (Standard_Boolean (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::IsRealValue, "Returns True if the string contains a real value.");
	cls_TCollection_HAsciiString.def("IsAscii", (Standard_Boolean (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::IsAscii, "Returns True if the string contains only ASCII characters between ' ' and '~'. This means no control character and no extended ASCII code.");
	cls_TCollection_HAsciiString.def("IsDifferent", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::IsDifferent, "Returns True if the string S not contains same characters than the string <me>.", py::arg("S"));
	cls_TCollection_HAsciiString.def("IsSameString", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::IsSameString, "Returns True if the string S contains same characters than the string <me>.", py::arg("S"));
	cls_TCollection_HAsciiString.def("IsSameString", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const ) &TCollection_HAsciiString::IsSameString, "Returns True if the string S contains same characters than the string <me>.", py::arg("S"), py::arg("CaseSensitive"));
	cls_TCollection_HAsciiString.def("LeftAdjust", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::LeftAdjust, "Removes all space characters in the begining of the string");
	cls_TCollection_HAsciiString.def("LeftJustify", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_HAsciiString::LeftJustify, "Left justify. Length becomes equal to Width and the new characters are equal to Filler if Width < Length nothing happens Raises an exception if Width is less than zero Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = 'abcdef '", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_HAsciiString.def("Length", (Standard_Integer (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::Length, "Returns number of characters in <me>. This is the same functionality as 'strlen' in C.");
	cls_TCollection_HAsciiString.def("Location", (Standard_Integer (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer) const ) &TCollection_HAsciiString::Location, "returns an index in the string <me> of the first occurence of the string S in the string <me> from the starting index FromIndex to the ending index ToIndex returns zero if failure Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAaAa', S = 'Aa', FromIndex = 1, ToIndex = 7 after me = 'aabAaAa' returns 4", py::arg("other"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_HAsciiString.def("Location", (Standard_Integer (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character, const Standard_Integer, const Standard_Integer) const ) &TCollection_HAsciiString::Location, "Returns the index of the nth occurence of the character C in the string <me> from the starting index FromIndex to the ending index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range Example: before me = 'aabAa', N = 3, C = 'a', FromIndex = 1, ToIndex = 5 after me = 'aabAa' returns 5", py::arg("N"), py::arg("C"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_HAsciiString.def("LowerCase", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::LowerCase, "Converts <me> to its lower-case equivalent.");
	cls_TCollection_HAsciiString.def("Prepend", (void (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::Prepend, "Inserts the other string at the begining of the string <me> Example: before me = 'cde' , S = 'ab' after me = 'abcde' , S = 'ab'", py::arg("other"));
	cls_TCollection_HAsciiString.def("Print", (void (TCollection_HAsciiString::*)(Standard_OStream &) const ) &TCollection_HAsciiString::Print, "Prints this string on the stream <astream>.", py::arg("astream"));
	cls_TCollection_HAsciiString.def("RealValue", (Standard_Real (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::RealValue, "Converts a string containing a numeric expression to a Real. Example: '215' returns 215.0. '3.14159267' returns 3.14159267.");
	cls_TCollection_HAsciiString.def("RemoveAll", (void (TCollection_HAsciiString::*)(const Standard_Character, const Standard_Boolean)) &TCollection_HAsciiString::RemoveAll, "Remove all the occurences of the character C in the string Example: before me = 'HellLLo', C = 'L' , CaseSensitive = True after me = 'Hello'", py::arg("C"), py::arg("CaseSensitive"));
	cls_TCollection_HAsciiString.def("RemoveAll", (void (TCollection_HAsciiString::*)(const Standard_Character)) &TCollection_HAsciiString::RemoveAll, "Removes every <what> characters from <me>", py::arg("what"));
	cls_TCollection_HAsciiString.def("Remove", [](TCollection_HAsciiString &self, const Standard_Integer a0) -> void { return self.Remove(a0); }, py::arg("where"));
	cls_TCollection_HAsciiString.def("Remove", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_HAsciiString::Remove, "Erases <ahowmany> characters from position <where>, <where> included. Example: aString contains 'Hello' aString.Erase(2,2) erases 2 characters from position 1 This gives 'Hlo'.", py::arg("where"), py::arg("ahowmany"));
	cls_TCollection_HAsciiString.def("RightAdjust", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::RightAdjust, "Removes all space characters at the end of the string.");
	cls_TCollection_HAsciiString.def("RightJustify", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_HAsciiString::RightJustify, "Right justify. Length becomes equal to Width and the new characters are equal to Filler if Width < Length nothing happens Raises an exception if Width is less than zero Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = ' abcdef'", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_HAsciiString.def("Search", (Standard_Integer (TCollection_HAsciiString::*)(const Standard_CString) const ) &TCollection_HAsciiString::Search, "Searches a CString in <me> from the beginning and returns position of first item <what> matching. It returns -1 if not found. Example: aString contains 'Sample single test' aString.Search('le') returns 5", py::arg("what"));
	cls_TCollection_HAsciiString.def("Search", (Standard_Integer (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::Search, "Searches a String in <me> from the beginning and returns position of first item <what> matching. it returns -1 if not found.", py::arg("what"));
	cls_TCollection_HAsciiString.def("SearchFromEnd", (Standard_Integer (TCollection_HAsciiString::*)(const Standard_CString) const ) &TCollection_HAsciiString::SearchFromEnd, "Searches a CString in a String from the end and returns position of first item <what> matching. It returns -1 if not found. Example: aString contains 'Sample single test' aString.SearchFromEnd('le') returns 12", py::arg("what"));
	cls_TCollection_HAsciiString.def("SearchFromEnd", (Standard_Integer (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::SearchFromEnd, "Searches a HAsciiString in another HAsciiString from the end and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
	cls_TCollection_HAsciiString.def("SetValue", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_HAsciiString::SetValue, "Replaces one character in the string at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("SetValue", (void (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_HAsciiString::SetValue, "Replaces a part of <me> in the string at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("SetValue", (void (TCollection_HAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TCollection_HAsciiString::SetValue, "Replaces a part of <me> by another string.", py::arg("where"), py::arg("what"));
	cls_TCollection_HAsciiString.def("Split", (opencascade::handle<TCollection_HAsciiString> (TCollection_HAsciiString::*)(const Standard_Integer)) &TCollection_HAsciiString::Split, "Splits a HAsciiString into two sub-strings. Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
	cls_TCollection_HAsciiString.def("SubString", (opencascade::handle<TCollection_HAsciiString> (TCollection_HAsciiString::*)(const Standard_Integer, const Standard_Integer) const ) &TCollection_HAsciiString::SubString, "Creation of a sub-string of the string <me>. The sub-string starts to the index Fromindex and ends to the index ToIndex. Raises an exception if ToIndex or FromIndex is out of bounds Example: before me = 'abcdefg', ToIndex=3, FromIndex=6 after me = 'abcdefg' returns 'cdef'", py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_HAsciiString.def("ToCString", (Standard_CString (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::ToCString, "Returns pointer to string (char *) This is useful for some casual manipulations Because this 'char *' is 'const', you can't modify its contents.");
	cls_TCollection_HAsciiString.def("Token", [](TCollection_HAsciiString &self) -> opencascade::handle<TCollection_HAsciiString> { return self.Token(); });
	cls_TCollection_HAsciiString.def("Token", [](TCollection_HAsciiString &self, const Standard_CString a0) -> opencascade::handle<TCollection_HAsciiString> { return self.Token(a0); }, py::arg("separators"));
	cls_TCollection_HAsciiString.def("Token", (opencascade::handle<TCollection_HAsciiString> (TCollection_HAsciiString::*)(const Standard_CString, const Standard_Integer) const ) &TCollection_HAsciiString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns an empty String. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
	cls_TCollection_HAsciiString.def("Trunc", (void (TCollection_HAsciiString::*)(const Standard_Integer)) &TCollection_HAsciiString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel'", py::arg("ahowmany"));
	cls_TCollection_HAsciiString.def("UpperCase", (void (TCollection_HAsciiString::*)()) &TCollection_HAsciiString::UpperCase, "Converts <me> to its upper-case equivalent.");
	cls_TCollection_HAsciiString.def("UsefullLength", (Standard_Integer (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::UsefullLength, "Length of the string ignoring all spaces (' ') and the control character at the end.");
	cls_TCollection_HAsciiString.def("Value", (Standard_Character (TCollection_HAsciiString::*)(const Standard_Integer) const ) &TCollection_HAsciiString::Value, "Returns character at position <where> in <me>. If <where> is less than zero or greater than the lenght of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e'", py::arg("where"));
	cls_TCollection_HAsciiString.def("String", (const TCollection_AsciiString & (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::String, "Returns the field myString.");
	cls_TCollection_HAsciiString.def("IsSameState", (Standard_Boolean (TCollection_HAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &) const ) &TCollection_HAsciiString::IsSameState, "None", py::arg("other"));
	cls_TCollection_HAsciiString.def_static("get_type_name_", (const char * (*)()) &TCollection_HAsciiString::get_type_name, "None");
	cls_TCollection_HAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_HAsciiString::get_type_descriptor, "None");
	cls_TCollection_HAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_HAsciiString::*)() const ) &TCollection_HAsciiString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_ExtendedString.hxx
	py::class_<TCollection_ExtendedString, std::unique_ptr<TCollection_ExtendedString, Deleter<TCollection_ExtendedString>>> cls_TCollection_ExtendedString(mod, "TCollection_ExtendedString", "A variable-length sequence of 'extended' (UNICODE) characters (16-bit character type). It provides editing operations with built-in memory management to make ExtendedString objects easier to use than ordinary extended character arrays. ExtendedString objects follow 'value semantics', that is, they are the actual strings, not handles to strings, and are copied through assignment. You may use HExtendedString objects to get handles to strings.");
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
	cls_TCollection_ExtendedString.def(py::init([] (const TCollection_ExtendedString &other) {return new TCollection_ExtendedString(other);}), "Copy constructor", py::arg("other"));
	cls_TCollection_ExtendedString.def(py::init<const TCollection_AsciiString &>(), py::arg("astring"));
	cls_TCollection_ExtendedString.def("AssignCat", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::AssignCat, "Appends the other extended string to this extended string. Note that this method is an alias of operator +=. Example: aString += anotherString", py::arg("other"));
	cls_TCollection_ExtendedString.def("__iadd__", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::operator+=, "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("Cat", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::Cat, "Appends <other> to me.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__add__", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("ChangeAll", (void (TCollection_ExtendedString::*)(const Standard_ExtCharacter, const Standard_ExtCharacter)) &TCollection_ExtendedString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the ExtendedString <me>. The substitution can be case sensitive. If you don't use default case sensitive, no matter wether aChar is uppercase or not.", py::arg("aChar"), py::arg("NewChar"));
	cls_TCollection_ExtendedString.def("Clear", (void (TCollection_ExtendedString::*)()) &TCollection_ExtendedString::Clear, "Removes all characters contained in <me>. This produces an empty ExtendedString.");
	cls_TCollection_ExtendedString.def("Copy", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::Copy, "Copy <fromwhere> to <me>. Used as operator =", py::arg("fromwhere"));
	cls_TCollection_ExtendedString.def("assign", (void (TCollection_ExtendedString::*)(const TCollection_ExtendedString &)) &TCollection_ExtendedString::operator=, py::is_operator(), "None", py::arg("fromwhere"));
	cls_TCollection_ExtendedString.def("Insert", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_ExtendedString::Insert, "Insert a Character at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_ExtendedString.def("Insert", (void (TCollection_ExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TCollection_ExtendedString::Insert, "Insert a ExtendedString at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_ExtendedString.def("IsEmpty", (Standard_Boolean (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::IsEmpty, "Returns True if this string contains no characters.");
	cls_TCollection_ExtendedString.def("IsEqual", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==", py::arg("other"));
	cls_TCollection_ExtendedString.def("__eq__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::operator==, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsEqual", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==", py::arg("other"));
	cls_TCollection_ExtendedString.def("__eq__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::operator==, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsDifferent", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::IsDifferent, "Returns true if there are differences between the characters in this extended string and the other extended string. Note that this method is an alias of operator !=.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__ne__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::operator!=, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsDifferent", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::IsDifferent, "Returns true if there are differences between the characters in this extended string and the other extended string. Note that this method is an alias of operator !=.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__ne__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::operator!=, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsLess", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__lt__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::operator<, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsLess", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__lt__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::operator<, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsGreater", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__gt__", (Standard_Boolean (TCollection_ExtendedString::*)(const Standard_ExtString) const ) &TCollection_ExtendedString::operator>, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("IsGreater", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
	cls_TCollection_ExtendedString.def("__gt__", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::operator>, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_ExtendedString.def("StartsWith", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::StartsWith, "Determines whether the beginning of this string instance matches the specified string.", py::arg("theStartString"));
	cls_TCollection_ExtendedString.def("EndsWith", (Standard_Boolean (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::EndsWith, "Determines whether the end of this string instance matches the specified string.", py::arg("theEndString"));
	cls_TCollection_ExtendedString.def("IsAscii", (Standard_Boolean (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::IsAscii, "Returns True if the ExtendedString contains only 'Ascii Range' characters .");
	cls_TCollection_ExtendedString.def("Length", (Standard_Integer (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::Length, "Returns the number of 16-bit code units (might be greater than number of Unicode symbols if string contains surrogate pairs).");
	cls_TCollection_ExtendedString.def("Print", (void (TCollection_ExtendedString::*)(Standard_OStream &) const ) &TCollection_ExtendedString::Print, "Displays <me> .", py::arg("astream"));
	cls_TCollection_ExtendedString.def("RemoveAll", (void (TCollection_ExtendedString::*)(const Standard_ExtCharacter)) &TCollection_ExtendedString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
	cls_TCollection_ExtendedString.def("Remove", [](TCollection_ExtendedString &self, const Standard_Integer a0) -> void { return self.Remove(a0); }, py::arg("where"));
	cls_TCollection_ExtendedString.def("Remove", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_ExtendedString::Remove, "Erases <ahowmany> characters from position <where>,<where> included.", py::arg("where"), py::arg("ahowmany"));
	cls_TCollection_ExtendedString.def("Search", (Standard_Integer (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::Search, "Searches a ExtendedString in <me> from the beginning and returns position of first item <what> matching. it returns -1 if not found.", py::arg("what"));
	cls_TCollection_ExtendedString.def("SearchFromEnd", (Standard_Integer (TCollection_ExtendedString::*)(const TCollection_ExtendedString &) const ) &TCollection_ExtendedString::SearchFromEnd, "Searches a ExtendedString in another ExtendedString from the end and returns position of first item <what> matching. it returns -1 if not found.", py::arg("what"));
	cls_TCollection_ExtendedString.def("SetValue", (void (TCollection_ExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_ExtendedString::SetValue, "Replaces one character in the ExtendedString at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised.", py::arg("where"), py::arg("what"));
	cls_TCollection_ExtendedString.def("SetValue", (void (TCollection_ExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TCollection_ExtendedString::SetValue, "Replaces a part of <me> by another ExtendedString see above.", py::arg("where"), py::arg("what"));
	cls_TCollection_ExtendedString.def("Split", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const Standard_Integer)) &TCollection_ExtendedString::Split, "Splits this extended string into two sub-strings at position where. - The second sub-string (from position where + 1 of this string to the end) is returned in a new extended string. - this extended string is modified: its last characters are removed, it becomes equal to the first sub-string (from the first character to position where). Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
	cls_TCollection_ExtendedString.def("Token", [](TCollection_ExtendedString &self, const Standard_ExtString a0) -> TCollection_ExtendedString { return self.Token(a0); }, py::arg("separators"));
	cls_TCollection_ExtendedString.def("Token", (TCollection_ExtendedString (TCollection_ExtendedString::*)(const Standard_ExtString, const Standard_Integer) const ) &TCollection_ExtendedString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns an empty AsciiString. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed : aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
	cls_TCollection_ExtendedString.def("ToExtString", (Standard_ExtString (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::ToExtString, "Returns pointer to ExtString");
	// FIXME cls_TCollection_ExtendedString.def("ToWideString", (const Standard_WideChar * (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::ToWideString, "Returns pointer to string as wchar_t* on Windows platform where wchar_t* is considered as UTF-16 string. This method is useful to pass string into wide-char system APIs, and makes sense only on Windows (other systems use UTF-8 and can miss wide-char functions at all).");
	cls_TCollection_ExtendedString.def("Trunc", (void (TCollection_ExtendedString::*)(const Standard_Integer)) &TCollection_ExtendedString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel' Exceptions Standard_OutOfRange if ahowmany is greater than the length of this string.", py::arg("ahowmany"));
	cls_TCollection_ExtendedString.def("Value", (Standard_ExtCharacter (TCollection_ExtendedString::*)(const Standard_Integer) const ) &TCollection_ExtendedString::Value, "Returns character at position <where> in <me>. If <where> is less than zero or greater than the lenght of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e' Exceptions Standard_OutOfRange if where lies outside the bounds of this extended string.", py::arg("where"));
	cls_TCollection_ExtendedString.def_static("HashCode_", (Standard_Integer (*)(const TCollection_ExtendedString &, const Standard_Integer)) &TCollection_ExtendedString::HashCode, "Returns a hashed value for the extended string within the range 1..theUpper. Note: if string is ASCII, the computed value is the same as the value computed with the HashCode function on a TCollection_AsciiString string composed with equivalent ASCII characters.", py::arg("theString"), py::arg("theUpper"));
	cls_TCollection_ExtendedString.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TCollection_ExtendedString::IsEqual, "Returns true if the characters in this extended string are identical to the characters in the other extended string. Note that this method is an alias of operator ==.", py::arg("theString1"), py::arg("theString2"));
	// FIXME cls_TCollection_ExtendedString.def("ToUTF8CString", (Standard_Integer (TCollection_ExtendedString::*)(Standard_PCharacter &) const ) &TCollection_ExtendedString::ToUTF8CString, "Converts the internal <mystring> to UTF8 coding and returns length of the out CString. A memory for the <theCString> should be allocated before call!", py::arg("theCString"));
	cls_TCollection_ExtendedString.def("LengthOfCString", (Standard_Integer (TCollection_ExtendedString::*)() const ) &TCollection_ExtendedString::LengthOfCString, "Returns expected CString length in UTF8 coding. It can be used for memory calculation before converting to CString containing symbols in UTF8 coding.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_AsciiString.hxx
	py::class_<TCollection_AsciiString, std::unique_ptr<TCollection_AsciiString, Deleter<TCollection_AsciiString>>> cls_TCollection_AsciiString(mod, "TCollection_AsciiString", "Class defines a variable-length sequence of 8-bit characters. Despite class name (kept for historical reasons), it is intended to store UTF-8 string, not just ASCII characters. However, multi-byte nature of UTF-8 is not considered by the following methods: - Method ::Length() return the number of bytes, not the number of Unicode symbols. - Methods taking/returning symbol index work with 8-bit code units, not true Unicode symbols, including ::Remove(), ::SetValue(), ::Value(), ::Search(), ::Trunc() and others. If application needs to process multi-byte Unicode symbols explicitly, NCollection_Utf8Iter class can be used for iterating through Unicode string (UTF-32 code unit will be returned for each position).");
	cls_TCollection_AsciiString.def(py::init<>());
	cls_TCollection_AsciiString.def(py::init<const Standard_CString>(), py::arg("message"));
	cls_TCollection_AsciiString.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("message"), py::arg("aLen"));
	cls_TCollection_AsciiString.def(py::init<const Standard_Character>(), py::arg("aChar"));
	cls_TCollection_AsciiString.def(py::init<const Standard_Integer, const Standard_Character>(), py::arg("length"), py::arg("filler"));
	cls_TCollection_AsciiString.def(py::init<const Standard_Integer>(), py::arg("value"));
	cls_TCollection_AsciiString.def(py::init<const Standard_Real>(), py::arg("value"));
	cls_TCollection_AsciiString.def(py::init([] (const TCollection_AsciiString &other) {return new TCollection_AsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_TCollection_AsciiString.def(py::init<const TCollection_AsciiString &, const Standard_Character>(), py::arg("astring"), py::arg("message"));
	cls_TCollection_AsciiString.def(py::init<const TCollection_AsciiString &, const Standard_CString>(), py::arg("astring"), py::arg("message"));
	cls_TCollection_AsciiString.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("astring"), py::arg("message"));
	cls_TCollection_AsciiString.def(py::init<const TCollection_ExtendedString &>(), py::arg("astring"));
	cls_TCollection_AsciiString.def(py::init<const TCollection_ExtendedString &, const Standard_Character>(), py::arg("astring"), py::arg("replaceNonAscii"));
	cls_TCollection_AsciiString.def(py::init<const Standard_WideChar *>(), py::arg("theStringUtf"));
	cls_TCollection_AsciiString.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
	cls_TCollection_AsciiString.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::operator+=, "None", py::arg("other"));
	cls_TCollection_AsciiString.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
	cls_TCollection_AsciiString.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::operator+=, "None", py::arg("other"));
	cls_TCollection_AsciiString.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_Real)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator.", py::arg("other"));
	cls_TCollection_AsciiString.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_Real)) &TCollection_AsciiString::operator+=, "None", py::arg("other"));
	cls_TCollection_AsciiString.def("AssignCat", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator. ex: aString += 'Dummy' To catenate more than one CString, you must put a AsciiString before. Example: aString += 'Hello ' + 'Dolly' IS NOT VALID ! But astring += anotherString + 'Hello ' + 'Dolly' is valid.", py::arg("other"));
	cls_TCollection_AsciiString.def("__iadd__", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::operator+=, "None", py::arg("other"));
	cls_TCollection_AsciiString.def("AssignCat", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::AssignCat, "Appends <other> to me. This is an unary operator. Example: aString += anotherString", py::arg("other"));
	cls_TCollection_AsciiString.def("__iadd__", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::operator+=, "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Capitalize", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::Capitalize, "Converts the first character into its corresponding upper-case character and the other characters into lowercase Example: before me = 'hellO ' after me = 'Hello '");
	cls_TCollection_AsciiString.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Character) const ) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 'Dummy' Example: aString contains 'I say ' aString = aString + 'Hello ' + 'Dolly' gives 'I say Hello Dolly' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
	cls_TCollection_AsciiString.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Character) const ) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer) const ) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 15; Example: aString contains 'I say ' gives 'I say 15' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
	cls_TCollection_AsciiString.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer) const ) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Real) const ) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 15.15; Example: aString contains 'I say ' gives 'I say 15.15' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
	cls_TCollection_AsciiString.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Real) const ) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::Cat, "Appends <other> to me. Syntax: aString = aString + 'Dummy' Example: aString contains 'I say ' aString = aString + 'Hello ' + 'Dolly' gives 'I say Hello Dolly' To catenate more than one CString, you must put a String before. So the following example is WRONG ! aString = 'Hello ' + 'Dolly' THIS IS NOT ALLOWED This rule is applicable to AssignCat (operator +=) too.", py::arg("other"));
	cls_TCollection_AsciiString.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Cat", (TCollection_AsciiString (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::Cat, "Appends <other> to me. Example: aString = aString + anotherString", py::arg("other"));
	cls_TCollection_AsciiString.def("__add__", (TCollection_AsciiString (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::operator+, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("Center", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::Center, "Modifies this ASCII string so that its length becomes equal to Width and the new characters are equal to Filler. New characters are added both at the beginning and at the end of this string. If Width is less than the length of this ASCII string, nothing happens. Example TCollection_AsciiString myAlphabet('abcdef'); myAlphabet.Center(9,' '); assert ( myAlphabet == ' abcdef ' );", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_AsciiString.def("ChangeAll", [](TCollection_AsciiString &self, const Standard_Character a0, const Standard_Character a1) -> void { return self.ChangeAll(a0, a1); }, py::arg("aChar"), py::arg("NewChar"));
	cls_TCollection_AsciiString.def("ChangeAll", (void (TCollection_AsciiString::*)(const Standard_Character, const Standard_Character, const Standard_Boolean)) &TCollection_AsciiString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the AsciiString <me>. The substitution can be case sensitive. If you don't use default case sensitive, no matter wether aChar is uppercase or not. Example: me = 'Histake' -> ChangeAll('H','M',Standard_True) gives me = 'Mistake'", py::arg("aChar"), py::arg("NewChar"), py::arg("CaseSensitive"));
	cls_TCollection_AsciiString.def("Clear", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::Clear, "Removes all characters contained in <me>. This produces an empty AsciiString.");
	cls_TCollection_AsciiString.def("Copy", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::Copy, "Copy <fromwhere> to <me>. Used as operator = Example: aString = anotherCString;", py::arg("fromwhere"));
	cls_TCollection_AsciiString.def("assign", (void (TCollection_AsciiString::*)(const Standard_CString)) &TCollection_AsciiString::operator=, py::is_operator(), "None", py::arg("fromwhere"));
	cls_TCollection_AsciiString.def("Copy", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::Copy, "Copy <fromwhere> to <me>. Used as operator = Example: aString = anotherString;", py::arg("fromwhere"));
	cls_TCollection_AsciiString.def("assign", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::operator=, py::is_operator(), "None", py::arg("fromwhere"));
	cls_TCollection_AsciiString.def("FirstLocationInSet", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const ) &TCollection_AsciiString::FirstLocationInSet, "Returns the index of the first character of <me> that is present in <Set>. The search begins to the index FromIndex and ends to the the index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 1", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_AsciiString.def("FirstLocationNotInSet", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const ) &TCollection_AsciiString::FirstLocationNotInSet, "Returns the index of the first character of <me> that is not present in the set <Set>. The search begins to the index FromIndex and ends to the the index ToIndex in <me>. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAcAa', S = 'Aa', FromIndex = 1, Toindex = 7 after me = 'aabAcAa' returns 3", py::arg("Set"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_AsciiString.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::Insert, "Inserts a Character at position <where>. Example: aString contains 'hy not ?' aString.Insert(1,'W'); gives 'Why not ?' aString contains 'Wh' aString.Insert(3,'y'); gives 'Why' aString contains 'Way' aString.Insert(2,'h'); gives 'Why'", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_AsciiString::Insert, "Inserts a CString at position <where>. Example: aString contains 'O more' aString.Insert(2,'nce'); gives 'Once more'", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("Insert", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::Insert, "Inserts a AsciiString at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("InsertAfter", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::InsertAfter, "Pushing a string after a specific index in the string <me>. Raises an exception if Index is out of bounds. - less than 0 (InsertAfter), or less than 1 (InsertBefore), or - greater than the number of characters in this ASCII string. Example: before me = 'cde' , Index = 0 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
	cls_TCollection_AsciiString.def("InsertBefore", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::InsertBefore, "Pushing a string before a specific index in the string <me>. Raises an exception if Index is out of bounds. - less than 0 (InsertAfter), or less than 1 (InsertBefore), or - greater than the number of characters in this ASCII string. Example: before me = 'cde' , Index = 1 , other = 'ab' after me = 'abcde' , other = 'ab'", py::arg("Index"), py::arg("other"));
	cls_TCollection_AsciiString.def("IsEmpty", (Standard_Boolean (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::IsEmpty, "Returns True if the string <me> contains zero character.");
	cls_TCollection_AsciiString.def("IsEqual", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::IsEqual, "Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==.", py::arg("other"));
	cls_TCollection_AsciiString.def("__eq__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::operator==, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsEqual", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::IsEqual, "Returns true if the characters in this ASCII string are identical to the characters in ASCII string other. Note that this method is an alias of operator ==.", py::arg("other"));
	cls_TCollection_AsciiString.def("__eq__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::operator==, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsDifferent", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::IsDifferent, "Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator !=", py::arg("other"));
	cls_TCollection_AsciiString.def("__ne__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::operator!=, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsDifferent", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::IsDifferent, "Returns true if there are differences between the characters in this ASCII string and ASCII string other. Note that this method is an alias of operator !=", py::arg("other"));
	cls_TCollection_AsciiString.def("__ne__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::operator!=, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsLess", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::IsLess, "Returns TRUE if <me> is 'ASCII' less than <other>.", py::arg("other"));
	cls_TCollection_AsciiString.def("__lt__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::operator<, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsLess", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::IsLess, "Returns TRUE if <me> is 'ASCII' less than <other>.", py::arg("other"));
	cls_TCollection_AsciiString.def("__lt__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::operator<, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsGreater", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::IsGreater, "Returns TRUE if <me> is 'ASCII' greater than <other>.", py::arg("other"));
	cls_TCollection_AsciiString.def("__gt__", (Standard_Boolean (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::operator>, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("IsGreater", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::IsGreater, "Returns TRUE if <me> is 'ASCII' greater than <other>.", py::arg("other"));
	cls_TCollection_AsciiString.def("__gt__", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::operator>, py::is_operator(), "None", py::arg("other"));
	cls_TCollection_AsciiString.def("StartsWith", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::StartsWith, "Determines whether the beginning of this string instance matches the specified string.", py::arg("theStartString"));
	cls_TCollection_AsciiString.def("EndsWith", (Standard_Boolean (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::EndsWith, "Determines whether the end of this string instance matches the specified string.", py::arg("theEndString"));
	cls_TCollection_AsciiString.def("IntegerValue", (Standard_Integer (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::IntegerValue, "Converts a AsciiString containing a numeric expression to an Integer. Example: '215' returns 215.");
	cls_TCollection_AsciiString.def("IsIntegerValue", (Standard_Boolean (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::IsIntegerValue, "Returns True if the AsciiString contains an integer value. Note: an integer value is considered to be a real value as well.");
	cls_TCollection_AsciiString.def("IsRealValue", (Standard_Boolean (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::IsRealValue, "Returns True if the AsciiString contains a real value. Note: an integer value is considered to be a real value as well.");
	cls_TCollection_AsciiString.def("IsAscii", (Standard_Boolean (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::IsAscii, "Returns True if the AsciiString contains only ASCII characters between ' ' and '~'. This means no control character and no extended ASCII code.");
	cls_TCollection_AsciiString.def("LeftAdjust", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::LeftAdjust, "Removes all space characters in the begining of the string.");
	cls_TCollection_AsciiString.def("LeftJustify", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::LeftJustify, "left justify Length becomes equal to Width and the new characters are equal to Filler. If Width < Length nothing happens. Raises an exception if Width is less than zero. Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = 'abcdef '", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_AsciiString.def("Length", (Standard_Integer (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::Length, "Returns number of characters in <me>. This is the same functionality as 'strlen' in C. Example TCollection_AsciiString myAlphabet('abcdef'); assert ( myAlphabet.Length() == 6 ); - 1 is the position of the first character in this string. - The length of this string gives the position of its last character. - Positions less than or equal to zero, or greater than the length of this string are invalid in functions which identify a character of this string by its position.");
	cls_TCollection_AsciiString.def("Location", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer) const ) &TCollection_AsciiString::Location, "Returns an index in the string <me> of the first occurence of the string S in the string <me> from the starting index FromIndex to the ending index ToIndex returns zero if failure Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAaAa', S = 'Aa', FromIndex = 1, ToIndex = 7 after me = 'aabAaAa' returns 4", py::arg("other"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_AsciiString.def("Location", (Standard_Integer (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character, const Standard_Integer, const Standard_Integer) const ) &TCollection_AsciiString::Location, "Returns the index of the nth occurence of the character C in the string <me> from the starting index FromIndex to the ending index ToIndex. Returns zero if failure. Raises an exception if FromIndex or ToIndex is out of range. Example: before me = 'aabAa', N = 3, C = 'a', FromIndex = 1, ToIndex = 5 after me = 'aabAa' returns 5", py::arg("N"), py::arg("C"), py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_AsciiString.def("LowerCase", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::LowerCase, "Converts <me> to its lower-case equivalent. Example TCollection_AsciiString myString('Hello Dolly'); myString.UpperCase(); assert ( myString == 'HELLO DOLLY' ); myString.LowerCase(); assert ( myString == 'hello dolly' );");
	cls_TCollection_AsciiString.def("Prepend", (void (TCollection_AsciiString::*)(const TCollection_AsciiString &)) &TCollection_AsciiString::Prepend, "Inserts the string other at the beginning of this ASCII string. Example TCollection_AsciiString myAlphabet('cde'); TCollection_AsciiString myBegin('ab'); myAlphabet.Prepend(myBegin); assert ( myAlphabet == 'abcde' );", py::arg("other"));
	cls_TCollection_AsciiString.def("Print", (void (TCollection_AsciiString::*)(Standard_OStream &) const ) &TCollection_AsciiString::Print, "Displays <me> on a stream.", py::arg("astream"));
	cls_TCollection_AsciiString.def("Read", (void (TCollection_AsciiString::*)(Standard_IStream &)) &TCollection_AsciiString::Read, "Read <me> from a stream.", py::arg("astream"));
	cls_TCollection_AsciiString.def("RealValue", (Standard_Real (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::RealValue, "Converts an AsciiString containing a numeric expression. to a Real. Example: ex: '215' returns 215.0. ex: '3.14159267' returns 3.14159267.");
	cls_TCollection_AsciiString.def("RemoveAll", (void (TCollection_AsciiString::*)(const Standard_Character, const Standard_Boolean)) &TCollection_AsciiString::RemoveAll, "Remove all the occurences of the character C in the string. Example: before me = 'HellLLo', C = 'L' , CaseSensitive = True after me = 'Hello'", py::arg("C"), py::arg("CaseSensitive"));
	cls_TCollection_AsciiString.def("RemoveAll", (void (TCollection_AsciiString::*)(const Standard_Character)) &TCollection_AsciiString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
	cls_TCollection_AsciiString.def("Remove", [](TCollection_AsciiString &self, const Standard_Integer a0) -> void { return self.Remove(a0); }, py::arg("where"));
	cls_TCollection_AsciiString.def("Remove", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_AsciiString::Remove, "Erases <ahowmany> characters from position <where>, <where> included. Example: aString contains 'Hello' aString.Remove(2,2) erases 2 characters from position 2 This gives 'Hlo'.", py::arg("where"), py::arg("ahowmany"));
	cls_TCollection_AsciiString.def("RightAdjust", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::RightAdjust, "Removes all space characters at the end of the string.");
	cls_TCollection_AsciiString.def("RightJustify", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::RightJustify, "Right justify. Length becomes equal to Width and the new characters are equal to Filler. if Width < Length nothing happens. Raises an exception if Width is less than zero. Example: before me = 'abcdef' , Width = 9 , Filler = ' ' after me = ' abcdef'", py::arg("Width"), py::arg("Filler"));
	cls_TCollection_AsciiString.def("Search", (Standard_Integer (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::Search, "Searches a CString in <me> from the beginning and returns position of first item <what> matching. it returns -1 if not found. Example: aString contains 'Sample single test' aString.Search('le') returns 5", py::arg("what"));
	cls_TCollection_AsciiString.def("Search", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::Search, "Searches an AsciiString in <me> from the beginning and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
	cls_TCollection_AsciiString.def("SearchFromEnd", (Standard_Integer (TCollection_AsciiString::*)(const Standard_CString) const ) &TCollection_AsciiString::SearchFromEnd, "Searches a CString in a AsciiString from the end and returns position of first item <what> matching. It returns -1 if not found. Example: aString contains 'Sample single test' aString.SearchFromEnd('le') returns 12", py::arg("what"));
	cls_TCollection_AsciiString.def("SearchFromEnd", (Standard_Integer (TCollection_AsciiString::*)(const TCollection_AsciiString &) const ) &TCollection_AsciiString::SearchFromEnd, "Searches a AsciiString in another AsciiString from the end and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
	cls_TCollection_AsciiString.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Character)) &TCollection_AsciiString::SetValue, "Replaces one character in the AsciiString at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const Standard_CString)) &TCollection_AsciiString::SetValue, "Replaces a part of <me> by a CString. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'abcde' aString.SetValue(4,'1234567') gives <me> = 'abc1234567'", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("SetValue", (void (TCollection_AsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TCollection_AsciiString::SetValue, "Replaces a part of <me> by another AsciiString.", py::arg("where"), py::arg("what"));
	cls_TCollection_AsciiString.def("Split", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::Split, "Splits a AsciiString into two sub-strings. Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
	cls_TCollection_AsciiString.def("SubString", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_Integer, const Standard_Integer) const ) &TCollection_AsciiString::SubString, "Creation of a sub-string of the string <me>. The sub-string starts to the index Fromindex and ends to the index ToIndex. Raises an exception if ToIndex or FromIndex is out of bounds Example: before me = 'abcdefg', ToIndex=3, FromIndex=6 after me = 'abcdefg' returns 'cdef'", py::arg("FromIndex"), py::arg("ToIndex"));
	cls_TCollection_AsciiString.def("ToCString", (Standard_CString (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::ToCString, "Returns pointer to AsciiString (char *). This is useful for some casual manipulations. Warning: Because this 'char *' is 'const', you can't modify its contents.");
	cls_TCollection_AsciiString.def("Token", [](TCollection_AsciiString &self) -> TCollection_AsciiString { return self.Token(); });
	cls_TCollection_AsciiString.def("Token", [](TCollection_AsciiString &self, const Standard_CString a0) -> TCollection_AsciiString { return self.Token(a0); }, py::arg("separators"));
	cls_TCollection_AsciiString.def("Token", (TCollection_AsciiString (TCollection_AsciiString::*)(const Standard_CString, const Standard_Integer) const ) &TCollection_AsciiString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns empty AsciiString. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed : aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
	cls_TCollection_AsciiString.def("Trunc", (void (TCollection_AsciiString::*)(const Standard_Integer)) &TCollection_AsciiString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel'", py::arg("ahowmany"));
	cls_TCollection_AsciiString.def("UpperCase", (void (TCollection_AsciiString::*)()) &TCollection_AsciiString::UpperCase, "Converts <me> to its upper-case equivalent.");
	cls_TCollection_AsciiString.def("UsefullLength", (Standard_Integer (TCollection_AsciiString::*)() const ) &TCollection_AsciiString::UsefullLength, "Length of the string ignoring all spaces (' ') and the control character at the end.");
	cls_TCollection_AsciiString.def("Value", (Standard_Character (TCollection_AsciiString::*)(const Standard_Integer) const ) &TCollection_AsciiString::Value, "Returns character at position <where> in <me>. If <where> is less than zero or greater than the lenght of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e'", py::arg("where"));
	cls_TCollection_AsciiString.def_static("HashCode_", (Standard_Integer (*)(const TCollection_AsciiString &, const Standard_Integer)) &TCollection_AsciiString::HashCode, "Hash function for AsciiString (returns the same Integer value that the hash function for ExtendedString)", py::arg("astring"), py::arg("Upper"));
	cls_TCollection_AsciiString.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TCollection_AsciiString::IsEqual, "Returns True when the two strings are the same. (Just for HashCode for AsciiString)", py::arg("string1"), py::arg("string2"));
	cls_TCollection_AsciiString.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const Standard_CString)) &TCollection_AsciiString::IsEqual, "Returns True when the two strings are the same. (Just for HashCode for AsciiString)", py::arg("string1"), py::arg("string2"));
	cls_TCollection_AsciiString.def_static("IsSameString_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const Standard_Boolean)) &TCollection_AsciiString::IsSameString, "Returns True if the strings contain same characters.", py::arg("theString1"), py::arg("theString2"), py::arg("theIsCaseSensitive"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_HExtendedString.hxx
	py::class_<TCollection_HExtendedString, opencascade::handle<TCollection_HExtendedString>, Standard_Transient> cls_TCollection_HExtendedString(mod, "TCollection_HExtendedString", "A variable-length sequence of 'extended' (UNICODE) characters (16-bit character type). It provides editing operations with built-in memory management to make ExtendedString objects easier to use than ordinary extended character arrays. HExtendedString objects are handles to strings. - HExtendedString strings may be shared by several objects. - You may use an ExtendedString object to get the actual string. Note: HExtendedString objects use an ExtendedString string as a field.");
	cls_TCollection_HExtendedString.def(py::init<>());
	cls_TCollection_HExtendedString.def(py::init<const Standard_CString>(), py::arg("message"));
	cls_TCollection_HExtendedString.def(py::init<const Standard_ExtString>(), py::arg("message"));
	cls_TCollection_HExtendedString.def(py::init<const Standard_ExtCharacter>(), py::arg("aChar"));
	cls_TCollection_HExtendedString.def(py::init<const Standard_Integer, const Standard_ExtCharacter>(), py::arg("length"), py::arg("filler"));
	cls_TCollection_HExtendedString.def(py::init<const TCollection_ExtendedString &>(), py::arg("aString"));
	cls_TCollection_HExtendedString.def(py::init<const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("aString"));
	cls_TCollection_HExtendedString.def(py::init<const opencascade::handle<TCollection_HExtendedString> &>(), py::arg("aString"));
	cls_TCollection_HExtendedString.def("AssignCat", (void (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::AssignCat, "Appends <other> to me.", py::arg("other"));
	cls_TCollection_HExtendedString.def("Cat", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::Cat, "Returns a string appending <other> to me.", py::arg("other"));
	cls_TCollection_HExtendedString.def("ChangeAll", (void (TCollection_HExtendedString::*)(const Standard_ExtCharacter, const Standard_ExtCharacter)) &TCollection_HExtendedString::ChangeAll, "Substitutes all the characters equal to aChar by NewChar in the string <me>.", py::arg("aChar"), py::arg("NewChar"));
	cls_TCollection_HExtendedString.def("Clear", (void (TCollection_HExtendedString::*)()) &TCollection_HExtendedString::Clear, "Removes all characters contained in <me>. This produces an empty ExtendedString.");
	cls_TCollection_HExtendedString.def("IsEmpty", (Standard_Boolean (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::IsEmpty, "Returns True if the string <me> contains zero character");
	cls_TCollection_HExtendedString.def("Insert", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_HExtendedString::Insert, "Insert a ExtCharacter at position <where>. Example: aString contains 'hy not ?' aString.Insert(1,'W'); gives 'Why not ?' aString contains 'Wh' aString.Insert(3,'y'); gives 'Why' aString contains 'Way' aString.Insert(2,'h'); gives 'Why'", py::arg("where"), py::arg("what"));
	cls_TCollection_HExtendedString.def("Insert", (void (TCollection_HExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::Insert, "Insert a HExtendedString at position <where>.", py::arg("where"), py::arg("what"));
	cls_TCollection_HExtendedString.def("IsLess", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::IsLess, "Returns TRUE if <me> is less than <other>.", py::arg("other"));
	cls_TCollection_HExtendedString.def("IsGreater", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::IsGreater, "Returns TRUE if <me> is greater than <other>.", py::arg("other"));
	cls_TCollection_HExtendedString.def("IsAscii", (Standard_Boolean (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::IsAscii, "Returns True if the string contains only 'Ascii Range' characters");
	cls_TCollection_HExtendedString.def("Length", (Standard_Integer (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::Length, "Returns number of characters in <me>. This is the same functionality as 'strlen' in C.");
	cls_TCollection_HExtendedString.def("Remove", [](TCollection_HExtendedString &self, const Standard_Integer a0) -> void { return self.Remove(a0); }, py::arg("where"));
	cls_TCollection_HExtendedString.def("Remove", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TCollection_HExtendedString::Remove, "Erases <ahowmany> characters from position <where>, <where> included. Example: aString contains 'Hello' aString.Erase(2,2) erases 2 characters from position 1 This gives 'Hlo'.", py::arg("where"), py::arg("ahowmany"));
	cls_TCollection_HExtendedString.def("RemoveAll", (void (TCollection_HExtendedString::*)(const Standard_ExtCharacter)) &TCollection_HExtendedString::RemoveAll, "Removes every <what> characters from <me>.", py::arg("what"));
	cls_TCollection_HExtendedString.def("SetValue", (void (TCollection_HExtendedString::*)(const Standard_Integer, const Standard_ExtCharacter)) &TCollection_HExtendedString::SetValue, "Replaces one character in the string at position <where>. If <where> is less than zero or greater than the length of <me> an exception is raised. Example: aString contains 'Garbake' astring.Replace(6,'g') gives <me> = 'Garbage'", py::arg("where"), py::arg("what"));
	cls_TCollection_HExtendedString.def("SetValue", (void (TCollection_HExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TCollection_HExtendedString::SetValue, "Replaces a part of <me> by another string.", py::arg("where"), py::arg("what"));
	cls_TCollection_HExtendedString.def("Split", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const Standard_Integer)) &TCollection_HExtendedString::Split, "Splits a ExtendedString into two sub-strings. Example: aString contains 'abcdefg' aString.Split(3) gives <me> = 'abc' and returns 'defg'", py::arg("where"));
	cls_TCollection_HExtendedString.def("Search", (Standard_Integer (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::Search, "Searches a String in <me> from the beginning and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
	cls_TCollection_HExtendedString.def("SearchFromEnd", (Standard_Integer (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::SearchFromEnd, "Searches a ExtendedString in another ExtendedString from the end and returns position of first item <what> matching. It returns -1 if not found.", py::arg("what"));
	cls_TCollection_HExtendedString.def("ToExtString", (Standard_ExtString (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::ToExtString, "Returns pointer to ExtString");
	cls_TCollection_HExtendedString.def("Token", [](TCollection_HExtendedString &self, const Standard_ExtString a0) -> opencascade::handle<TCollection_HExtendedString> { return self.Token(a0); }, py::arg("separators"));
	cls_TCollection_HExtendedString.def("Token", (opencascade::handle<TCollection_HExtendedString> (TCollection_HExtendedString::*)(const Standard_ExtString, const Standard_Integer) const ) &TCollection_HExtendedString::Token, "Extracts <whichone> token from <me>. By default, the <separators> is set to space and tabulation. By default, the token extracted is the first one (whichone = 1). <separators> contains all separators you need. If no token indexed by <whichone> is found, it returns an empty String. Example: aString contains 'This is a message' aString.Token() returns 'This' aString.Token(' ',4) returns 'message' aString.Token(' ',2) returns 'is' aString.Token(' ',9) returns '' Other separators than space character and tabulation are allowed aString contains '1234; test:message , value' aString.Token('; :,',4) returns 'value' aString.Token('; :,',2) returns 'test'", py::arg("separators"), py::arg("whichone"));
	cls_TCollection_HExtendedString.def("Trunc", (void (TCollection_HExtendedString::*)(const Standard_Integer)) &TCollection_HExtendedString::Trunc, "Truncates <me> to <ahowmany> characters. Example: me = 'Hello Dolly' -> Trunc(3) -> me = 'Hel'", py::arg("ahowmany"));
	cls_TCollection_HExtendedString.def("Value", (Standard_ExtCharacter (TCollection_HExtendedString::*)(const Standard_Integer) const ) &TCollection_HExtendedString::Value, "Returns ExtCharacter at position <where> in <me>. If <where> is less than zero or greater than the length of <me>, an exception is raised. Example: aString contains 'Hello' aString.Value(2) returns 'e'", py::arg("where"));
	cls_TCollection_HExtendedString.def("String", (const TCollection_ExtendedString & (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::String, "Returns the field myString");
	cls_TCollection_HExtendedString.def("Print", (void (TCollection_HExtendedString::*)(Standard_OStream &) const ) &TCollection_HExtendedString::Print, "Displays <me> .", py::arg("astream"));
	cls_TCollection_HExtendedString.def("IsSameState", (Standard_Boolean (TCollection_HExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &) const ) &TCollection_HExtendedString::IsSameState, "None", py::arg("other"));
	cls_TCollection_HExtendedString.def_static("get_type_name_", (const char * (*)()) &TCollection_HExtendedString::get_type_name, "None");
	cls_TCollection_HExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_HExtendedString::get_type_descriptor, "None");
	cls_TCollection_HExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_HExtendedString::*)() const ) &TCollection_HExtendedString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_BasicMapIterator.hxx
	py::class_<TCollection_BasicMapIterator, std::unique_ptr<TCollection_BasicMapIterator, Deleter<TCollection_BasicMapIterator>>> cls_TCollection_BasicMapIterator(mod, "TCollection_BasicMapIterator", "This class provides basic services for the iterators on Maps. The iterators are inherited from this one.");
	cls_TCollection_BasicMapIterator.def("Reset", (void (TCollection_BasicMapIterator::*)()) &TCollection_BasicMapIterator::Reset, "Resets the iterator to the first node.");
	cls_TCollection_BasicMapIterator.def("More", (Standard_Boolean (TCollection_BasicMapIterator::*)() const ) &TCollection_BasicMapIterator::More, "Returns true if there is a current entry for this iterator in the map. Use the function Next to set this iterator to the position of the next entry, if it exists.");
	cls_TCollection_BasicMapIterator.def("Next", (void (TCollection_BasicMapIterator::*)()) &TCollection_BasicMapIterator::Next, "Sets this iterator to the position of the next entry of the map. Nothing is changed if there is no more entry to explore in the map: this iterator is always positioned on the last entry of the map but the function More returns false.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_BasicMap.hxx
	py::class_<TCollection_BasicMap, std::unique_ptr<TCollection_BasicMap, Deleter<TCollection_BasicMap>>> cls_TCollection_BasicMap(mod, "TCollection_BasicMap", "Root class of all the maps, provides utilitites for managing the buckets. Maps are dynamically extended data structures where data is quickly accessed with a key. General properties of maps - Map items may be (complex) non-unitary data; they may be difficult to manage with an array. Moreover, the map allows a data structure to be indexed by complex data. - The size of a map is dynamically extended. So a map may be first dimensioned for a little number of items. Maps avoid the use of large and quasi-empty arrays. - The access to a map item is much faster than the one to a sequence, a list, a queue or a stack item. - The access time to a map item may be compared with the one to an array item. First of all, it depends on the size of the map. It also depends on the quality of a user redefinable function (the hashing function) to find quickly where the item is. - The exploration of a map may be of better performance than the exploration of an array because the size of the map is adapted to the number of inserted items. These properties explain why maps are commonly used as internal data structures for algorithms. Definitions - A map is a data structure for which data is addressed by keys. - Once inserted in the map, a map item is referenced as an entry of the map. - Each entry of the map is addressed by a key. Two different keys address two different entries of the map. - The position of an entry in the map is called a bucket. - A map is dimensioned by its number of buckets, i.e. the maximum number of entries in the map. The performance of a map is conditioned by the number of buckets. - The hashing function transforms a key into a bucket index. The number of values that can be computed by the hashing function is equal to the number of buckets of the map. - Both the hashing function and the equality test between two keys are provided by a hasher object. - A map may be explored by a map iterator. This exploration provides only inserted entries in the map (i.e. non empty buckets). Collections' generic maps The Collections component provides numerous generic derived maps. - These maps include automatic management of the number of buckets: they are automatically resized when the number of keys exceeds the number of buckets. If you have a fair idea of the number of items in your map, you can save on automatic resizing by specifying a number of buckets at the time of construction, or by using a resizing function. This may be considered for crucial optimization issues. - Keys, items and hashers are parameters of these generic derived maps. - TCollection_MapHasher class describes the functions required by any hasher which is to be used with a map instantiated from the Collections component. - An iterator class is automatically instantiated at the time of instantiation of a map provided by the Collections component if this map is to be explored with an iterator. Note that some provided generic maps are not to be explored with an iterator but with indexes (indexed maps).");
	cls_TCollection_BasicMap.def("NbBuckets", (Standard_Integer (TCollection_BasicMap::*)() const ) &TCollection_BasicMap::NbBuckets, "Returns the number of buckets in <me>.");
	cls_TCollection_BasicMap.def("Extent", (Standard_Integer (TCollection_BasicMap::*)() const ) &TCollection_BasicMap::Extent, "Returns the number of keys already stored in <me>.");
	cls_TCollection_BasicMap.def("IsEmpty", (Standard_Boolean (TCollection_BasicMap::*)() const ) &TCollection_BasicMap::IsEmpty, "Returns True when the map contains no keys. This is exactly Extent() == 0.");
	cls_TCollection_BasicMap.def("Statistics", (void (TCollection_BasicMap::*)(Standard_OStream &) const ) &TCollection_BasicMap::Statistics, "Prints on <S> usefull statistics about the map <me>. It can be used to test the quality of the hashcoding.", py::arg("S"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_Array1, std::unique_ptr<TCollection_Array1, Deleter<TCollection_Array1>>> cls_TCollection_Array1(mod, "TCollection_Array1", "None");
	cls_TCollection_Array1.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_HArray1, std::unique_ptr<TCollection_HArray1, Deleter<TCollection_HArray1>>> cls_TCollection_HArray1(mod, "TCollection_HArray1", "None");
	cls_TCollection_HArray1.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_Array2, std::unique_ptr<TCollection_Array2, Deleter<TCollection_Array2>>> cls_TCollection_Array2(mod, "TCollection_Array2", "None");
	cls_TCollection_Array2.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_HArray2, std::unique_ptr<TCollection_HArray2, Deleter<TCollection_HArray2>>> cls_TCollection_HArray2(mod, "TCollection_HArray2", "None");
	cls_TCollection_HArray2.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_List, std::unique_ptr<TCollection_List, Deleter<TCollection_List>>> cls_TCollection_List(mod, "TCollection_List", "None");
	cls_TCollection_List.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_ListNode, std::unique_ptr<TCollection_ListNode, Deleter<TCollection_ListNode>>> cls_TCollection_ListNode(mod, "TCollection_ListNode", "None");
	cls_TCollection_ListNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_ListIterator, std::unique_ptr<TCollection_ListIterator, Deleter<TCollection_ListIterator>>> cls_TCollection_ListIterator(mod, "TCollection_ListIterator", "None");
	cls_TCollection_ListIterator.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_BaseSequence.hxx
	py::class_<TCollection_BaseSequence, std::unique_ptr<TCollection_BaseSequence, Deleter<TCollection_BaseSequence>>> cls_TCollection_BaseSequence(mod, "TCollection_BaseSequence", "Definition of a base class for all instanciations of sequence.");
	cls_TCollection_BaseSequence.def("IsEmpty", (Standard_Boolean (TCollection_BaseSequence::*)() const ) &TCollection_BaseSequence::IsEmpty, "returns True if the sequence <me> contains no elements.");
	cls_TCollection_BaseSequence.def("Length", (Standard_Integer (TCollection_BaseSequence::*)() const ) &TCollection_BaseSequence::Length, "Returns the number of element(s) in the sequence. Returns zero if the sequence is empty.");
	cls_TCollection_BaseSequence.def("Reverse", (void (TCollection_BaseSequence::*)()) &TCollection_BaseSequence::Reverse, "Reverses the order of items on <me>. Example: before me = (A B C) after me = (C B A)");
	cls_TCollection_BaseSequence.def("Exchange", (void (TCollection_BaseSequence::*)(const Standard_Integer, const Standard_Integer)) &TCollection_BaseSequence::Exchange, "Swaps elements which are located at positions <I> and <J> in <me>. Raises an exception if I or J is out of bound. Example: before me = (A B C), I = 1, J = 3 after me = (C B A)", py::arg("I"), py::arg("J"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_SeqNode.hxx
	py::class_<TCollection_SeqNode, opencascade::handle<TCollection_SeqNode>, Standard_Transient> cls_TCollection_SeqNode(mod, "TCollection_SeqNode", "None");
	cls_TCollection_SeqNode.def(py::init<const TCollection_SeqNodePtr &, const TCollection_SeqNodePtr &>(), py::arg("n"), py::arg("p"));
	cls_TCollection_SeqNode.def("Next", (TCollection_SeqNodePtr & (TCollection_SeqNode::*)() const ) &TCollection_SeqNode::Next, "None");
	cls_TCollection_SeqNode.def("Previous", (TCollection_SeqNodePtr & (TCollection_SeqNode::*)() const ) &TCollection_SeqNode::Previous, "None");
	cls_TCollection_SeqNode.def_static("get_type_name_", (const char * (*)()) &TCollection_SeqNode::get_type_name, "None");
	cls_TCollection_SeqNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_SeqNode::get_type_descriptor, "None");
	cls_TCollection_SeqNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_SeqNode::*)() const ) &TCollection_SeqNode::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_Sequence, std::unique_ptr<TCollection_Sequence, Deleter<TCollection_Sequence>>> cls_TCollection_Sequence(mod, "TCollection_Sequence", "None");
	cls_TCollection_Sequence.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_SequenceNode, std::unique_ptr<TCollection_SequenceNode, Deleter<TCollection_SequenceNode>>> cls_TCollection_SequenceNode(mod, "TCollection_SequenceNode", "None");
	cls_TCollection_SequenceNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_HSequence, std::unique_ptr<TCollection_HSequence, Deleter<TCollection_HSequence>>> cls_TCollection_HSequence(mod, "TCollection_HSequence", "None");
	cls_TCollection_HSequence.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_MapHasher, std::unique_ptr<TCollection_MapHasher, Deleter<TCollection_MapHasher>>> cls_TCollection_MapHasher(mod, "TCollection_MapHasher", "None");
	cls_TCollection_MapHasher.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_MapNode.hxx
	py::class_<TCollection_MapNode, opencascade::handle<TCollection_MapNode>, Standard_Transient> cls_TCollection_MapNode(mod, "TCollection_MapNode", "Basic class root of all the Maps.");
	cls_TCollection_MapNode.def(py::init<const TCollection_MapNodePtr &>(), py::arg("n"));
	cls_TCollection_MapNode.def("Next", (TCollection_MapNodePtr & (TCollection_MapNode::*)() const ) &TCollection_MapNode::Next, "None");
	cls_TCollection_MapNode.def_static("get_type_name_", (const char * (*)()) &TCollection_MapNode::get_type_name, "None");
	cls_TCollection_MapNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_MapNode::get_type_descriptor, "None");
	cls_TCollection_MapNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_MapNode::*)() const ) &TCollection_MapNode::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_Map, std::unique_ptr<TCollection_Map, Deleter<TCollection_Map>>> cls_TCollection_Map(mod, "TCollection_Map", "None");
	cls_TCollection_Map.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_MapIterator, std::unique_ptr<TCollection_MapIterator, Deleter<TCollection_MapIterator>>> cls_TCollection_MapIterator(mod, "TCollection_MapIterator", "None");
	cls_TCollection_MapIterator.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_StdMapNode, std::unique_ptr<TCollection_StdMapNode, Deleter<TCollection_StdMapNode>>> cls_TCollection_StdMapNode(mod, "TCollection_StdMapNode", "None");
	cls_TCollection_StdMapNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DataMap, std::unique_ptr<TCollection_DataMap, Deleter<TCollection_DataMap>>> cls_TCollection_DataMap(mod, "TCollection_DataMap", "None");
	cls_TCollection_DataMap.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DataMapIterator, std::unique_ptr<TCollection_DataMapIterator, Deleter<TCollection_DataMapIterator>>> cls_TCollection_DataMapIterator(mod, "TCollection_DataMapIterator", "None");
	cls_TCollection_DataMapIterator.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DataMapNode, std::unique_ptr<TCollection_DataMapNode, Deleter<TCollection_DataMapNode>>> cls_TCollection_DataMapNode(mod, "TCollection_DataMapNode", "None");
	cls_TCollection_DataMapNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DoubleMap, std::unique_ptr<TCollection_DoubleMap, Deleter<TCollection_DoubleMap>>> cls_TCollection_DoubleMap(mod, "TCollection_DoubleMap", "None");
	cls_TCollection_DoubleMap.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DoubleMapIterator, std::unique_ptr<TCollection_DoubleMapIterator, Deleter<TCollection_DoubleMapIterator>>> cls_TCollection_DoubleMapIterator(mod, "TCollection_DoubleMapIterator", "None");
	cls_TCollection_DoubleMapIterator.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_DoubleMapNode, std::unique_ptr<TCollection_DoubleMapNode, Deleter<TCollection_DoubleMapNode>>> cls_TCollection_DoubleMapNode(mod, "TCollection_DoubleMapNode", "None");
	cls_TCollection_DoubleMapNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_IndexedMap, std::unique_ptr<TCollection_IndexedMap, Deleter<TCollection_IndexedMap>>> cls_TCollection_IndexedMap(mod, "TCollection_IndexedMap", "None");
	cls_TCollection_IndexedMap.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_IndexedMapNode, std::unique_ptr<TCollection_IndexedMapNode, Deleter<TCollection_IndexedMapNode>>> cls_TCollection_IndexedMapNode(mod, "TCollection_IndexedMapNode", "None");
	cls_TCollection_IndexedMapNode.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_IndexedDataMap, std::unique_ptr<TCollection_IndexedDataMap, Deleter<TCollection_IndexedDataMap>>> cls_TCollection_IndexedDataMap(mod, "TCollection_IndexedDataMap", "None");
	cls_TCollection_IndexedDataMap.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection_IndexedDataMapNode, std::unique_ptr<TCollection_IndexedDataMapNode, Deleter<TCollection_IndexedDataMapNode>>> cls_TCollection_IndexedDataMapNode(mod, "TCollection_IndexedDataMapNode", "None");
	cls_TCollection_IndexedDataMapNode.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection.hxx
	py::class_<TCollection, std::unique_ptr<TCollection, Deleter<TCollection>>> cls_TCollection(mod, "TCollection", "The package <TCollection> provides the services for the transient basic data structures.");
	cls_TCollection.def(py::init<>());
	cls_TCollection.def_static("NextPrimeForMap_", (Standard_Integer (*)(const Standard_Integer)) &TCollection::NextPrimeForMap, "Returns a prime number greater than <I> suitable to dimension a Map. When <I> becomes great there is a limit on the result (today the limit is around 1 000 000). This is not a limit of the number of items but a limit in the number of buckets. i.e. there will be more collisions in the map.", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_MapNodePtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TCollection_SeqNodePtr.hxx

}
