#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <Plugin_MapOfFunctions.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <Plugin.hxx>
#include <Standard_Failure.hxx>
#include <Standard_SStream.hxx>
#include <Plugin_Failure.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(Plugin, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin.hxx
	py::class_<Plugin, std::unique_ptr<Plugin, Deleter<Plugin>>> cls_Plugin(mod, "Plugin", "None");
	cls_Plugin.def(py::init<>());
	cls_Plugin.def_static("Load_", [](const Standard_GUID & a0) -> opencascade::handle<Standard_Transient> { return Plugin::Load(a0); }, py::arg("aGUID"));
	cls_Plugin.def_static("Load_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &, const Standard_Boolean)) &Plugin::Load, "None", py::arg("aGUID"), py::arg("theVerbose"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin_Failure.hxx
	py::class_<Plugin_Failure, opencascade::handle<Plugin_Failure>, Standard_Failure> cls_Plugin_Failure(mod, "Plugin_Failure", "None");
	cls_Plugin_Failure.def(py::init<>());
	cls_Plugin_Failure.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Plugin_Failure.def_static("Raise_", (void (*)(const Standard_CString)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("Raise_", (void (*)(Standard_SStream &)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("NewInstance_", (opencascade::handle<Plugin_Failure> (*)(const Standard_CString)) &Plugin_Failure::NewInstance, "None", py::arg("theMessage"));
	cls_Plugin_Failure.def_static("get_type_name_", (const char * (*)()) &Plugin_Failure::get_type_name, "None");
	cls_Plugin_Failure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Plugin_Failure::get_type_descriptor, "None");
	cls_Plugin_Failure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Plugin_Failure::*)() const ) &Plugin_Failure::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<Plugin_MapOfFunctions, std::unique_ptr<Plugin_MapOfFunctions, Deleter<Plugin_MapOfFunctions>>, NCollection_BaseMap> cls_Plugin_MapOfFunctions(mod, "Plugin_MapOfFunctions", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_Plugin_MapOfFunctions.def(py::init<>());
	cls_Plugin_MapOfFunctions.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Plugin_MapOfFunctions.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Plugin_MapOfFunctions.def(py::init([] (const Plugin_MapOfFunctions &other) {return new Plugin_MapOfFunctions(other);}), "Copy constructor", py::arg("other"));
	cls_Plugin_MapOfFunctions.def("begin", (Plugin_MapOfFunctions::iterator (Plugin_MapOfFunctions::*)() const ) &Plugin_MapOfFunctions::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Plugin_MapOfFunctions.def("end", (Plugin_MapOfFunctions::iterator (Plugin_MapOfFunctions::*)() const ) &Plugin_MapOfFunctions::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Plugin_MapOfFunctions.def("cbegin", (Plugin_MapOfFunctions::const_iterator (Plugin_MapOfFunctions::*)() const ) &Plugin_MapOfFunctions::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Plugin_MapOfFunctions.def("cend", (Plugin_MapOfFunctions::const_iterator (Plugin_MapOfFunctions::*)() const ) &Plugin_MapOfFunctions::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Plugin_MapOfFunctions.def("Exchange", (void (Plugin_MapOfFunctions::*)(Plugin_MapOfFunctions &)) &Plugin_MapOfFunctions::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Plugin_MapOfFunctions.def("Assign", (Plugin_MapOfFunctions & (Plugin_MapOfFunctions::*)(const Plugin_MapOfFunctions &)) &Plugin_MapOfFunctions::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Plugin_MapOfFunctions.def("assign", (Plugin_MapOfFunctions & (Plugin_MapOfFunctions::*)(const Plugin_MapOfFunctions &)) &Plugin_MapOfFunctions::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Plugin_MapOfFunctions.def("ReSize", (void (Plugin_MapOfFunctions::*)(const Standard_Integer)) &Plugin_MapOfFunctions::ReSize, "ReSize", py::arg("N"));
	cls_Plugin_MapOfFunctions.def("Bind", (Standard_Boolean (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &, const OSD_Function &)) &Plugin_MapOfFunctions::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_Plugin_MapOfFunctions.def("Bound", (OSD_Function * (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &, const OSD_Function &)) &Plugin_MapOfFunctions::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_Plugin_MapOfFunctions.def("IsBound", (Standard_Boolean (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &) const ) &Plugin_MapOfFunctions::IsBound, "IsBound", py::arg("theKey"));
	cls_Plugin_MapOfFunctions.def("UnBind", (Standard_Boolean (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &)) &Plugin_MapOfFunctions::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_Plugin_MapOfFunctions.def("Seek", (const OSD_Function * (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &) const ) &Plugin_MapOfFunctions::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_Plugin_MapOfFunctions.def("Find", (const OSD_Function & (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &) const ) &Plugin_MapOfFunctions::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_Plugin_MapOfFunctions.def("Find", (Standard_Boolean (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &, OSD_Function &) const ) &Plugin_MapOfFunctions::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_Plugin_MapOfFunctions.def("__call__", (const OSD_Function & (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &) const ) &Plugin_MapOfFunctions::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_Plugin_MapOfFunctions.def("ChangeSeek", (OSD_Function * (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &)) &Plugin_MapOfFunctions::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_Plugin_MapOfFunctions.def("ChangeFind", (OSD_Function & (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &)) &Plugin_MapOfFunctions::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_Plugin_MapOfFunctions.def("__call__", (OSD_Function & (Plugin_MapOfFunctions::*)(const TCollection_AsciiString &)) &Plugin_MapOfFunctions::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_Plugin_MapOfFunctions.def("Clear", [](Plugin_MapOfFunctions &self) -> void { return self.Clear(); });
	cls_Plugin_MapOfFunctions.def("Clear", (void (Plugin_MapOfFunctions::*)(const Standard_Boolean)) &Plugin_MapOfFunctions::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Plugin_MapOfFunctions.def("Clear", (void (Plugin_MapOfFunctions::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Plugin_MapOfFunctions::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Plugin_MapOfFunctions.def("Size", (Standard_Integer (Plugin_MapOfFunctions::*)() const ) &Plugin_MapOfFunctions::Size, "Size");
	cls_Plugin_MapOfFunctions.def("__iter__", [](const Plugin_MapOfFunctions &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Plugin_MapOfFunctions.hxx

}
