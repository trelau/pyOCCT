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
#include <Standard_PCharacter.hxx>
#include <Resource_FormatType.hxx>
#include <Resource_Unicode.hxx>

void bind_Resource_Unicode(py::module &mod){

py::class_<Resource_Unicode, std::unique_ptr<Resource_Unicode>> cls_Resource_Unicode(mod, "Resource_Unicode", "This class provides functions used to convert a non-ASCII C string given in ANSI, EUC, GB or SJIS format, to a Unicode string of extended characters, and vice versa.");

// Constructors

// Fields

// Methods
// cls_Resource_Unicode.def_static("operator new_", (void * (*)(size_t)) &Resource_Unicode::operator new, "None", py::arg("theSize"));
// cls_Resource_Unicode.def_static("operator delete_", (void (*)(void *)) &Resource_Unicode::operator delete, "None", py::arg("theAddress"));
// cls_Resource_Unicode.def_static("operator new[]_", (void * (*)(size_t)) &Resource_Unicode::operator new[], "None", py::arg("theSize"));
// cls_Resource_Unicode.def_static("operator delete[]_", (void (*)(void *)) &Resource_Unicode::operator delete[], "None", py::arg("theAddress"));
// cls_Resource_Unicode.def_static("operator new_", (void * (*)(size_t, void *)) &Resource_Unicode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Resource_Unicode.def_static("operator delete_", (void (*)(void *, void *)) &Resource_Unicode::operator delete, "None", py::arg(""), py::arg(""));
cls_Resource_Unicode.def_static("ConvertSJISToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertSJISToUnicode, "Converts non-ASCII CString <fromstr> in SJIS format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
cls_Resource_Unicode.def_static("ConvertEUCToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertEUCToUnicode, "Converts non-ASCII CString <fromstr> in EUC format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
cls_Resource_Unicode.def_static("ConvertGBToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertGBToUnicode, "Converts non-ASCII CString <fromstr> in GB format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
cls_Resource_Unicode.def_static("ConvertGBKToUnicode_", (Standard_Boolean (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertGBKToUnicode, "Converts non-ASCII CString <fromstr> in GBK format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
cls_Resource_Unicode.def_static("ConvertBig5ToUnicode_", (Standard_Boolean (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertBig5ToUnicode, "Converts non-ASCII CString <fromstr> in Big5 format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
cls_Resource_Unicode.def_static("ConvertANSIToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertANSIToUnicode, "Converts non-ASCII CString <fromstr> in ANSI format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
// cls_Resource_Unicode.def_static("ConvertUnicodeToSJIS_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToSJIS, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in SJIS format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
// cls_Resource_Unicode.def_static("ConvertUnicodeToEUC_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToEUC, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in EUC format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
// cls_Resource_Unicode.def_static("ConvertUnicodeToGB_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToGB, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in GB format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
// cls_Resource_Unicode.def_static("ConvertUnicodeToANSI_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToANSI, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in ANSI format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
cls_Resource_Unicode.def_static("SetFormat_", (void (*)(const Resource_FormatType)) &Resource_Unicode::SetFormat, "Defines the current conversion format as typecode. This conversion format will then be used by the functions ConvertFormatToUnicode and ConvertUnicodeToFormat to convert the strings.", py::arg("typecode"));
cls_Resource_Unicode.def_static("GetFormat_", (Resource_FormatType (*)()) &Resource_Unicode::GetFormat, "Returns the current conversion format (either ANSI, EUC, GB or SJIS). The current converting format must be defined in advance with the SetFormat function.");
cls_Resource_Unicode.def_static("ReadFormat_", (void (*)()) &Resource_Unicode::ReadFormat, "Reads converting format from resource 'FormatType' in Resource Manager 'CharSet'");
cls_Resource_Unicode.def_static("ConvertFormatToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertFormatToUnicode, "Converts the non-ASCII C string fromstr to the Unicode string of extended characters tostr. fromstr is translated according to the format (either ANSI, EUC, GB or SJIS) returned by the function GetFormat.", py::arg("fromstr"), py::arg("tostr"));
// cls_Resource_Unicode.def_static("ConvertUnicodeToFormat_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToFormat, "Converts the Unicode string of extended characters fromstr to the non-ASCII C string tostr according to the format (either ANSI, EUC, GB or SJIS) returned by the function GetFormat. maxsize limits the size of the string tostr to a maximum number of characters. You need more than twice the length of the string fromstr to complete the conversion. The function returns true if conversion is complete, i.e. the maximum number of characters maxsize is not reached by tostr before the end of conversion of fromstr.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));

// Enums

}