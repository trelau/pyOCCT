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
#ifndef __NCollection_UtfString__
#define __NCollection_UtfString__

#include <pyOCCT_Common.hxx>
#include <NCollection_UtfIterator.hxx>
#include <NCollection_UtfString.hxx>
#include <Standard_TypeDef.hxx>

template <typename Type>
void bind_NCollection_UtfString(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_UtfString<Type>, std::unique_ptr<NCollection_UtfString<Type>>> cls_NCollection_UtfString(mod, name.c_str(), "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.", local);

// Constructors
cls_NCollection_UtfString.def(py::init<>());
cls_NCollection_UtfString.def(py::init<const NCollection_UtfString<Type> &>(), py::arg("theCopy"));
// cls_NCollection_UtfString.def(py::init<NCollection_UtfString<Type> &&>(), py::arg("theOther"));
cls_NCollection_UtfString.def(py::init<const char *>(), py::arg("theCopyUtf8"));
cls_NCollection_UtfString.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
cls_NCollection_UtfString.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
cls_NCollection_UtfString.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
cls_NCollection_UtfString.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
cls_NCollection_UtfString.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
cls_NCollection_UtfString.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
cls_NCollection_UtfString.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));

// Fields

// Methods
cls_NCollection_UtfString.def("Iterator", (NCollection_UtfIterator<Type> (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::Iterator, "None");
cls_NCollection_UtfString.def("Size", (Standard_Integer (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::Size, "Returns the size of the buffer in bytes, excluding NULL-termination symbol");
cls_NCollection_UtfString.def("Length", (Standard_Integer (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::Length, "Returns the length of the string in Unicode symbols");
cls_NCollection_UtfString.def("GetChar", (Standard_Utf32Char (NCollection_UtfString<Type>::*)(const Standard_Integer) const) &NCollection_UtfString<Type>::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
cls_NCollection_UtfString.def("GetCharBuffer", (const Type * (NCollection_UtfString<Type>::*)(const Standard_Integer) const) &NCollection_UtfString<Type>::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
cls_NCollection_UtfString.def("__getitem__", (Standard_Utf32Char (NCollection_UtfString<Type>::*)(const Standard_Integer) const) &NCollection_UtfString<Type>::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
cls_NCollection_UtfString.def("FromLocale", [](NCollection_UtfString<Type> &self, const char * a0) -> void { return self.FromLocale(a0); });
cls_NCollection_UtfString.def("FromLocale", (void (NCollection_UtfString<Type>::*)(const char *, const Standard_Integer)) &NCollection_UtfString<Type>::FromLocale, "Copy from multibyte string in current system locale.", py::arg("theString"), py::arg("theLength"));
cls_NCollection_UtfString.def("IsEqual", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const) &NCollection_UtfString<Type>::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
cls_NCollection_UtfString.def("SubString", (NCollection_UtfString<Type> (NCollection_UtfString<Type>::*)(const Standard_Integer, const Standard_Integer) const) &NCollection_UtfString<Type>::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
cls_NCollection_UtfString.def("ToCString", (const Type * (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
cls_NCollection_UtfString.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::ToUtf8, "Returns copy in UTF-8 format");
cls_NCollection_UtfString.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::ToUtf16, "Returns copy in UTF-16 format");
cls_NCollection_UtfString.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::ToUtf32, "Returns copy in UTF-32 format");
cls_NCollection_UtfString.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
cls_NCollection_UtfString.def("ToLocale", (bool (NCollection_UtfString<Type>::*)(char *, const Standard_Integer) const) &NCollection_UtfString<Type>::ToLocale, "Converts the string into string in the current system locale.", py::arg("theBuffer"), py::arg("theSizeBytes"));
cls_NCollection_UtfString.def("IsEmpty", (bool (NCollection_UtfString<Type>::*)() const) &NCollection_UtfString<Type>::IsEmpty, "Returns true if string is empty");
cls_NCollection_UtfString.def("Clear", (void (NCollection_UtfString<Type>::*)()) &NCollection_UtfString<Type>::Clear, "Zero string.");
cls_NCollection_UtfString.def("Assign", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::Assign, "Copy from another string.", py::arg("theOther"));
cls_NCollection_UtfString.def("Swap", (void (NCollection_UtfString<Type>::*)(NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::Swap, "Exchange the data of two strings (without reallocating memory).", py::arg("theOther"));
// cls_NCollection_UtfString.def("operator=", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::operator=, "Copy from another string.", py::arg("theOther"));
// cls_NCollection_UtfString.def("operator=", (NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(NCollection_UtfString<Type> &&)) &NCollection_UtfString<Type>::operator=, "Move assignment operator.", py::arg("theOther"));
// cls_NCollection_UtfString.def("operator=", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const char *)) &NCollection_UtfString<Type>::operator=, "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
// cls_NCollection_UtfString.def("operator=", (const NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const Standard_WideChar *)) &NCollection_UtfString<Type>::operator=, "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
cls_NCollection_UtfString.def("__iadd__", (NCollection_UtfString<Type> & (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &)) &NCollection_UtfString<Type>::operator+=, py::is_operator(), "Join strings.", py::arg("theAppend"));
cls_NCollection_UtfString.def("__eq__", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const) &NCollection_UtfString<Type>::operator==, py::is_operator(), "", py::arg("theCompare"));
cls_NCollection_UtfString.def("__ne__", (bool (NCollection_UtfString<Type>::*)(const NCollection_UtfString<Type> &) const) &NCollection_UtfString<Type>::operator!=, py::is_operator(), "None", py::arg("theCompare"));

// Enums

}

#endif