#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<Resource_DataMapOfAsciiStringAsciiString, std::unique_ptr<Resource_DataMapOfAsciiStringAsciiString, Deleter<Resource_DataMapOfAsciiStringAsciiString>>, NCollection_BaseMap> cls_Resource_DataMapOfAsciiStringAsciiString(mod, "Resource_DataMapOfAsciiStringAsciiString", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_Resource_DataMapOfAsciiStringAsciiString.def(py::init<>());
	cls_Resource_DataMapOfAsciiStringAsciiString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def(py::init([] (const Resource_DataMapOfAsciiStringAsciiString &other) {return new Resource_DataMapOfAsciiStringAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("begin", (Resource_DataMapOfAsciiStringAsciiString::iterator (Resource_DataMapOfAsciiStringAsciiString::*)() const ) &Resource_DataMapOfAsciiStringAsciiString::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Resource_DataMapOfAsciiStringAsciiString.def("end", (Resource_DataMapOfAsciiStringAsciiString::iterator (Resource_DataMapOfAsciiStringAsciiString::*)() const ) &Resource_DataMapOfAsciiStringAsciiString::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Resource_DataMapOfAsciiStringAsciiString.def("cbegin", (Resource_DataMapOfAsciiStringAsciiString::const_iterator (Resource_DataMapOfAsciiStringAsciiString::*)() const ) &Resource_DataMapOfAsciiStringAsciiString::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Resource_DataMapOfAsciiStringAsciiString.def("cend", (Resource_DataMapOfAsciiStringAsciiString::const_iterator (Resource_DataMapOfAsciiStringAsciiString::*)() const ) &Resource_DataMapOfAsciiStringAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Exchange", (void (Resource_DataMapOfAsciiStringAsciiString::*)(Resource_DataMapOfAsciiStringAsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Assign", (Resource_DataMapOfAsciiStringAsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const Resource_DataMapOfAsciiStringAsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("assign", (Resource_DataMapOfAsciiStringAsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const Resource_DataMapOfAsciiStringAsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("ReSize", (void (Resource_DataMapOfAsciiStringAsciiString::*)(const Standard_Integer)) &Resource_DataMapOfAsciiStringAsciiString::ReSize, "ReSize", py::arg("N"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Bind", (Standard_Boolean (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_Resource_DataMapOfAsciiStringAsciiString.def("Bound", (TCollection_AsciiString * (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("IsBound", (Standard_Boolean (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringAsciiString::IsBound, "IsBound", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("UnBind", (Standard_Boolean (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringAsciiString.def("Seek", (const TCollection_AsciiString * (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringAsciiString::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringAsciiString.def("Find", (const TCollection_AsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringAsciiString::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringAsciiString.def("Find", (Standard_Boolean (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &, TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringAsciiString::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("__call__", (const TCollection_AsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringAsciiString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringAsciiString.def("ChangeSeek", (TCollection_AsciiString * (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("ChangeFind", (TCollection_AsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("__call__", (TCollection_AsciiString & (Resource_DataMapOfAsciiStringAsciiString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringAsciiString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Clear", [](Resource_DataMapOfAsciiStringAsciiString &self) -> void { return self.Clear(); });
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Clear", (void (Resource_DataMapOfAsciiStringAsciiString::*)(const Standard_Boolean)) &Resource_DataMapOfAsciiStringAsciiString::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Clear", (void (Resource_DataMapOfAsciiStringAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Resource_DataMapOfAsciiStringAsciiString::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Resource_DataMapOfAsciiStringAsciiString.def("Size", (Standard_Integer (Resource_DataMapOfAsciiStringAsciiString::*)() const ) &Resource_DataMapOfAsciiStringAsciiString::Size, "Size");
	cls_Resource_DataMapOfAsciiStringAsciiString.def("__iter__", [](const Resource_DataMapOfAsciiStringAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_DataMapOfAsciiStringAsciiString.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<Resource_DataMapOfAsciiStringExtendedString, std::unique_ptr<Resource_DataMapOfAsciiStringExtendedString, Deleter<Resource_DataMapOfAsciiStringExtendedString>>, NCollection_BaseMap> cls_Resource_DataMapOfAsciiStringExtendedString(mod, "Resource_DataMapOfAsciiStringExtendedString", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_Resource_DataMapOfAsciiStringExtendedString.def(py::init<>());
	cls_Resource_DataMapOfAsciiStringExtendedString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def(py::init([] (const Resource_DataMapOfAsciiStringExtendedString &other) {return new Resource_DataMapOfAsciiStringExtendedString(other);}), "Copy constructor", py::arg("other"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("begin", (Resource_DataMapOfAsciiStringExtendedString::iterator (Resource_DataMapOfAsciiStringExtendedString::*)() const ) &Resource_DataMapOfAsciiStringExtendedString::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Resource_DataMapOfAsciiStringExtendedString.def("end", (Resource_DataMapOfAsciiStringExtendedString::iterator (Resource_DataMapOfAsciiStringExtendedString::*)() const ) &Resource_DataMapOfAsciiStringExtendedString::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Resource_DataMapOfAsciiStringExtendedString.def("cbegin", (Resource_DataMapOfAsciiStringExtendedString::const_iterator (Resource_DataMapOfAsciiStringExtendedString::*)() const ) &Resource_DataMapOfAsciiStringExtendedString::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Resource_DataMapOfAsciiStringExtendedString.def("cend", (Resource_DataMapOfAsciiStringExtendedString::const_iterator (Resource_DataMapOfAsciiStringExtendedString::*)() const ) &Resource_DataMapOfAsciiStringExtendedString::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Exchange", (void (Resource_DataMapOfAsciiStringExtendedString::*)(Resource_DataMapOfAsciiStringExtendedString &)) &Resource_DataMapOfAsciiStringExtendedString::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Assign", (Resource_DataMapOfAsciiStringExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const Resource_DataMapOfAsciiStringExtendedString &)) &Resource_DataMapOfAsciiStringExtendedString::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("assign", (Resource_DataMapOfAsciiStringExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const Resource_DataMapOfAsciiStringExtendedString &)) &Resource_DataMapOfAsciiStringExtendedString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("ReSize", (void (Resource_DataMapOfAsciiStringExtendedString::*)(const Standard_Integer)) &Resource_DataMapOfAsciiStringExtendedString::ReSize, "ReSize", py::arg("N"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Bind", (Standard_Boolean (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &, const TCollection_ExtendedString &)) &Resource_DataMapOfAsciiStringExtendedString::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_Resource_DataMapOfAsciiStringExtendedString.def("Bound", (TCollection_ExtendedString * (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &, const TCollection_ExtendedString &)) &Resource_DataMapOfAsciiStringExtendedString::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("IsBound", (Standard_Boolean (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringExtendedString::IsBound, "IsBound", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("UnBind", (Standard_Boolean (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringExtendedString::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringExtendedString.def("Seek", (const TCollection_ExtendedString * (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringExtendedString::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringExtendedString.def("Find", (const TCollection_ExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringExtendedString::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringExtendedString.def("Find", (Standard_Boolean (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &, TCollection_ExtendedString &) const ) &Resource_DataMapOfAsciiStringExtendedString::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("__call__", (const TCollection_ExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &) const ) &Resource_DataMapOfAsciiStringExtendedString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_Resource_DataMapOfAsciiStringExtendedString.def("ChangeSeek", (TCollection_ExtendedString * (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringExtendedString::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("ChangeFind", (TCollection_ExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringExtendedString::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("__call__", (TCollection_ExtendedString & (Resource_DataMapOfAsciiStringExtendedString::*)(const TCollection_AsciiString &)) &Resource_DataMapOfAsciiStringExtendedString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Clear", [](Resource_DataMapOfAsciiStringExtendedString &self) -> void { return self.Clear(); });
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Clear", (void (Resource_DataMapOfAsciiStringExtendedString::*)(const Standard_Boolean)) &Resource_DataMapOfAsciiStringExtendedString::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Clear", (void (Resource_DataMapOfAsciiStringExtendedString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Resource_DataMapOfAsciiStringExtendedString::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Resource_DataMapOfAsciiStringExtendedString.def("Size", (Standard_Integer (Resource_DataMapOfAsciiStringExtendedString::*)() const ) &Resource_DataMapOfAsciiStringExtendedString::Size, "Size");
	cls_Resource_DataMapOfAsciiStringExtendedString.def("__iter__", [](const Resource_DataMapOfAsciiStringExtendedString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Resource_DataMapOfAsciiStringExtendedString.hxx

}
