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
#include <Standard_Type.hxx>
#include <Resource_Manager.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <Resource_DataMapOfAsciiStringAsciiString.hxx>
#include <Resource_DataMapOfAsciiStringExtendedString.hxx>
#include <Resource_FormatType.hxx>
#include <Resource_LexicalCompare.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Standard_SStream.hxx>
#include <Resource_NoSuchResource.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_PCharacter.hxx>
#include <Resource_Unicode.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Resource, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_FormatType.hxx
	py::enum_<Resource_FormatType>(mod, "Resource_FormatType", "List of non ASCII format types which may be converted into the Unicode 16 bits format type. Use the functions provided by the Resource_Unicode class to convert a string from one of these non ASCII format to Unicode, and vice versa.")
		.value("Resource_SJIS", Resource_FormatType::Resource_SJIS)
		.value("Resource_EUC", Resource_FormatType::Resource_EUC)
		.value("Resource_ANSI", Resource_FormatType::Resource_ANSI)
		.value("Resource_GB", Resource_FormatType::Resource_GB)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_Manager.hxx
	py::class_<Resource_Manager, opencascade::handle<Resource_Manager>, Standard_Transient> cls_Resource_Manager(mod, "Resource_Manager", "Defines a resource structure and its management methods.");
	cls_Resource_Manager.def(py::init<const Standard_CString>(), py::arg("aName"));
	cls_Resource_Manager.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("aName"), py::arg("Verbose"));
	cls_Resource_Manager.def(py::init<const Standard_CString, TCollection_AsciiString &, TCollection_AsciiString &>(), py::arg("aName"), py::arg("aDefaultsDirectory"), py::arg("anUserDefaultsDirectory"));
	cls_Resource_Manager.def(py::init<const Standard_CString, TCollection_AsciiString &, TCollection_AsciiString &, const Standard_Boolean>(), py::arg("aName"), py::arg("aDefaultsDirectory"), py::arg("anUserDefaultsDirectory"), py::arg("Verbose"));
	cls_Resource_Manager.def("Save", (Standard_Boolean (Resource_Manager::*)() const ) &Resource_Manager::Save, "Save the user resource structure in the specified file. Creates the file if it does not exist.");
	cls_Resource_Manager.def("Find", (Standard_Boolean (Resource_Manager::*)(const Standard_CString) const ) &Resource_Manager::Find, "returns True if the Resource does exist.", py::arg("aResource"));
	cls_Resource_Manager.def("Integer", (Standard_Integer (Resource_Manager::*)(const Standard_CString) const ) &Resource_Manager::Integer, "Gets the value of an integer resource according to its instance and its type.", py::arg("aResourceName"));
	cls_Resource_Manager.def("Real", (Standard_Real (Resource_Manager::*)(const Standard_CString) const ) &Resource_Manager::Real, "Gets the value of a real resource according to its instance and its type.", py::arg("aResourceName"));
	cls_Resource_Manager.def("Value", (Standard_CString (Resource_Manager::*)(const Standard_CString) const ) &Resource_Manager::Value, "Gets the value of a CString resource according to its instance and its type.", py::arg("aResourceName"));
	cls_Resource_Manager.def("ExtValue", (Standard_ExtString (Resource_Manager::*)(const Standard_CString)) &Resource_Manager::ExtValue, "Gets the value of an ExtString resource according to its instance and its type.", py::arg("aResourceName"));
	cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_Integer)) &Resource_Manager::SetResource, "Sets the new value of an integer resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
	cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_Real)) &Resource_Manager::SetResource, "Sets the new value of a real resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
	cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_CString)) &Resource_Manager::SetResource, "Sets the new value of an CString resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
	cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_ExtString)) &Resource_Manager::SetResource, "Sets the new value of an ExtString resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
	cls_Resource_Manager.def_static("GetResourcePath_", (void (*)(TCollection_AsciiString &, const Standard_CString, const Standard_Boolean)) &Resource_Manager::GetResourcePath, "Gets the resource file full path by its name. If corresponding environment variable is not set or file doesn't exist returns empty string.", py::arg("aPath"), py::arg("aName"), py::arg("isUserDefaults"));
	cls_Resource_Manager.def_static("get_type_name_", (const char * (*)()) &Resource_Manager::get_type_name, "None");
	cls_Resource_Manager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Resource_Manager::get_type_descriptor, "None");
	cls_Resource_Manager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Resource_Manager::*)() const ) &Resource_Manager::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_LexicalCompare.hxx
	py::class_<Resource_LexicalCompare, std::unique_ptr<Resource_LexicalCompare, Deleter<Resource_LexicalCompare>>> cls_Resource_LexicalCompare(mod, "Resource_LexicalCompare", "None");
	cls_Resource_LexicalCompare.def(py::init<>());
	cls_Resource_LexicalCompare.def("IsLower", (Standard_Boolean (Resource_LexicalCompare::*)(const TCollection_AsciiString &, const TCollection_AsciiString &) const ) &Resource_LexicalCompare::IsLower, "Returns True if <Left> is lower than <Right>.", py::arg("Left"), py::arg("Right"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_NoSuchResource.hxx
	py::class_<Resource_NoSuchResource, opencascade::handle<Resource_NoSuchResource>, Standard_NoSuchObject> cls_Resource_NoSuchResource(mod, "Resource_NoSuchResource", "None");
	cls_Resource_NoSuchResource.def(py::init<>());
	cls_Resource_NoSuchResource.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Resource_NoSuchResource.def_static("Raise_", (void (*)(const Standard_CString)) &Resource_NoSuchResource::Raise, "None", py::arg("theMessage"));
	cls_Resource_NoSuchResource.def_static("Raise_", (void (*)(Standard_SStream &)) &Resource_NoSuchResource::Raise, "None", py::arg("theMessage"));
	cls_Resource_NoSuchResource.def_static("NewInstance_", (opencascade::handle<Resource_NoSuchResource> (*)(const Standard_CString)) &Resource_NoSuchResource::NewInstance, "None", py::arg("theMessage"));
	cls_Resource_NoSuchResource.def_static("get_type_name_", (const char * (*)()) &Resource_NoSuchResource::get_type_name, "None");
	cls_Resource_NoSuchResource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Resource_NoSuchResource::get_type_descriptor, "None");
	cls_Resource_NoSuchResource.def("DynamicType", (const opencascade::handle<Standard_Type> & (Resource_NoSuchResource::*)() const ) &Resource_NoSuchResource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_Unicode.hxx
	py::class_<Resource_Unicode, std::unique_ptr<Resource_Unicode, Deleter<Resource_Unicode>>> cls_Resource_Unicode(mod, "Resource_Unicode", "This class provides functions used to convert a non-ASCII C string given in ANSI, EUC, GB or SJIS format, to a Unicode string of extended characters, and vice versa.");
	cls_Resource_Unicode.def(py::init<>());
	cls_Resource_Unicode.def_static("ConvertSJISToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertSJISToUnicode, "Converts non-ASCII CString <fromstr> in SJIS format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
	cls_Resource_Unicode.def_static("ConvertEUCToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertEUCToUnicode, "Converts non-ASCII CString <fromstr> in EUC format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
	cls_Resource_Unicode.def_static("ConvertGBToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertGBToUnicode, "Converts non-ASCII CString <fromstr> in GB format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
	cls_Resource_Unicode.def_static("ConvertANSIToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertANSIToUnicode, "Converts non-ASCII CString <fromstr> in ANSI format to Unicode ExtendedString <tostr>.", py::arg("fromstr"), py::arg("tostr"));
	// FIXME cls_Resource_Unicode.def_static("ConvertUnicodeToSJIS_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToSJIS, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in SJIS format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
	// FIXME cls_Resource_Unicode.def_static("ConvertUnicodeToEUC_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToEUC, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in EUC format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
	// FIXME cls_Resource_Unicode.def_static("ConvertUnicodeToGB_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToGB, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in GB format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
	// FIXME cls_Resource_Unicode.def_static("ConvertUnicodeToANSI_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToANSI, "Converts Unicode ExtendedString <fromstr> to non-ASCII CString <tostr> in ANSI format, limited to <maxsize> characters. To translate the whole <fromstr>, use more than twice the length of <fromstr>. Returns true if <maxsize> has not been reached before end of conversion.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));
	cls_Resource_Unicode.def_static("SetFormat_", (void (*)(const Resource_FormatType)) &Resource_Unicode::SetFormat, "Defines the current conversion format as typecode. This conversion format will then be used by the functions ConvertFormatToUnicode and ConvertUnicodeToFormat to convert the strings.", py::arg("typecode"));
	cls_Resource_Unicode.def_static("GetFormat_", (Resource_FormatType (*)()) &Resource_Unicode::GetFormat, "Returns the current conversion format (either ANSI, EUC, GB or SJIS). The current converting format must be defined in advance with the SetFormat function.");
	cls_Resource_Unicode.def_static("ReadFormat_", (void (*)()) &Resource_Unicode::ReadFormat, "Reads converting format from resource 'FormatType' in Resource Manager 'CharSet'");
	cls_Resource_Unicode.def_static("ConvertFormatToUnicode_", (void (*)(const Standard_CString, TCollection_ExtendedString &)) &Resource_Unicode::ConvertFormatToUnicode, "Converts the non-ASCII C string fromstr to the Unicode string of extended characters tostr. fromstr is translated according to the format (either ANSI, EUC, GB or SJIS) returned by the function GetFormat.", py::arg("fromstr"), py::arg("tostr"));
	// FIXME cls_Resource_Unicode.def_static("ConvertUnicodeToFormat_", (Standard_Boolean (*)(const TCollection_ExtendedString &, Standard_PCharacter &, const Standard_Integer)) &Resource_Unicode::ConvertUnicodeToFormat, "Converts the Unicode string of extended characters fromstr to the non-ASCII C string tostr according to the format (either ANSI, EUC, GB or SJIS) returned by the function GetFormat. maxsize limits the size of the string tostr to a maximum number of characters. You need more than twice the length of the string fromstr to complete the conversion. The function returns true if conversion is complete, i.e. the maximum number of characters maxsize is not reached by tostr before the end of conversion of fromstr.", py::arg("fromstr"), py::arg("tostr"), py::arg("maxsize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_DataMapOfAsciiStringAsciiString.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, TCollection_AsciiString, TCollection_AsciiString>(mod, "Resource_DataMapOfAsciiStringAsciiString");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_DataMapOfAsciiStringExtendedString.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, TCollection_ExtendedString, TCollection_AsciiString>(mod, "Resource_DataMapOfAsciiStringExtendedString");

	/* FIXME

	*/


}
