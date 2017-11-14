#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriver.hxx>
#include <XmlMDF_TypeADriverMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <TCollection_ExtendedString.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <XmlMDF_MapOfDriver.hxx>
#include <CDM_MessageDriver.hxx>
#include <XmlMDF_TagSourceDriver.hxx>
#include <XmlMDF_ReferenceDriver.hxx>
#include <TDF_Data.hxx>
#include <XmlObjMgt_Element.hxx>
#include <XmlMDF.hxx>

PYBIND11_MODULE(XmlMDF, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.XmlObjMgt");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.CDM");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_ADriverTable.hxx
	py::class_<XmlMDF_ADriverTable, opencascade::handle<XmlMDF_ADriverTable>, Standard_Transient> cls_XmlMDF_ADriverTable(mod, "XmlMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");
	cls_XmlMDF_ADriverTable.def(py::init<>());
	cls_XmlMDF_ADriverTable.def("AddDriver", (void (XmlMDF_ADriverTable::*)(const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_ADriverTable::AddDriver, "Sets a translation driver: <aDriver>.", py::arg("anHDriver"));
	cls_XmlMDF_ADriverTable.def("GetDrivers", (const XmlMDF_TypeADriverMap & (XmlMDF_ADriverTable::*)() const ) &XmlMDF_ADriverTable::GetDrivers, "Gets a map of drivers.");
	cls_XmlMDF_ADriverTable.def("GetDriver", (Standard_Boolean (XmlMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<XmlMDF_ADriver> &) const ) &XmlMDF_ADriverTable::GetDriver, "Gets a driver <aDriver> according to <aType>", py::arg("aType"), py::arg("anHDriver"));
	cls_XmlMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriverTable::get_type_name, "None");
	cls_XmlMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriverTable::get_type_descriptor, "None");
	cls_XmlMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriverTable::*)() const ) &XmlMDF_ADriverTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_ADriver.hxx
	py::class_<XmlMDF_ADriver, opencascade::handle<XmlMDF_ADriver>, Standard_Transient> cls_XmlMDF_ADriver(mod, "XmlMDF_ADriver", "Attribute Storage/Retrieval Driver.");
	cls_XmlMDF_ADriver.def("VersionNumber", (Standard_Integer (XmlMDF_ADriver::*)() const ) &XmlMDF_ADriver::VersionNumber, "Returns the version number from which the driver is available.");
	cls_XmlMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_ADriver::*)() const ) &XmlMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
	cls_XmlMDF_ADriver.def("SourceType", (opencascade::handle<Standard_Type> (XmlMDF_ADriver::*)() const ) &XmlMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
	cls_XmlMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (XmlMDF_ADriver::*)() const ) &XmlMDF_ADriver::TypeName, "Returns the full XML tag name (including NS prefix)");
	cls_XmlMDF_ADriver.def("Paste", (Standard_Boolean (XmlMDF_ADriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_XmlMDF_ADriver.def("Paste", (void (XmlMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_XmlMDF_ADriver.def("WriteMessage", (void (XmlMDF_ADriver::*)(const TCollection_ExtendedString &) const ) &XmlMDF_ADriver::WriteMessage, "Send message to Application (usually when error occurres)", py::arg("theMessage"));
	cls_XmlMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriver::get_type_name, "None");
	cls_XmlMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriver::get_type_descriptor, "None");
	cls_XmlMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriver::*)() const ) &XmlMDF_ADriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_TagSourceDriver.hxx
	py::class_<XmlMDF_TagSourceDriver, opencascade::handle<XmlMDF_TagSourceDriver>, XmlMDF_ADriver> cls_XmlMDF_TagSourceDriver(mod, "XmlMDF_TagSourceDriver", "Attribute Driver.");
	cls_XmlMDF_TagSourceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMDF_TagSourceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_TagSourceDriver::*)() const ) &XmlMDF_TagSourceDriver::NewEmpty, "None");
	cls_XmlMDF_TagSourceDriver.def("Paste", (Standard_Boolean (XmlMDF_TagSourceDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDF_TagSourceDriver.def("Paste", (void (XmlMDF_TagSourceDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDF_TagSourceDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_TagSourceDriver::get_type_name, "None");
	cls_XmlMDF_TagSourceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_TagSourceDriver::get_type_descriptor, "None");
	cls_XmlMDF_TagSourceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_TagSourceDriver::*)() const ) &XmlMDF_TagSourceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_ReferenceDriver.hxx
	py::class_<XmlMDF_ReferenceDriver, opencascade::handle<XmlMDF_ReferenceDriver>, XmlMDF_ADriver> cls_XmlMDF_ReferenceDriver(mod, "XmlMDF_ReferenceDriver", "Attribute Driver.");
	cls_XmlMDF_ReferenceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMDF_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_ReferenceDriver::*)() const ) &XmlMDF_ReferenceDriver::NewEmpty, "None");
	cls_XmlMDF_ReferenceDriver.def("Paste", (Standard_Boolean (XmlMDF_ReferenceDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDF_ReferenceDriver.def("Paste", (void (XmlMDF_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDF_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ReferenceDriver::get_type_name, "None");
	cls_XmlMDF_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ReferenceDriver::get_type_descriptor, "None");
	cls_XmlMDF_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ReferenceDriver::*)() const ) &XmlMDF_ReferenceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF.hxx
	py::class_<XmlMDF, std::unique_ptr<XmlMDF, Deleter<XmlMDF>>> cls_XmlMDF(mod, "XmlMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");
	cls_XmlMDF.def(py::init<>());
	cls_XmlMDF.def_static("FromTo_", (void (*)(const opencascade::handle<TDF_Data> &, XmlObjMgt_Element &, XmlObjMgt_SRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a transient <aSource> into a persistent <aTarget>.", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
	cls_XmlMDF.def_static("FromTo_", (Standard_Boolean (*)(const XmlObjMgt_Element &, opencascade::handle<TDF_Data> &, XmlObjMgt_RRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a persistent <aSource> into a transient <aTarget>. Returns True if completed successfully (False on error)", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
	cls_XmlMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &XmlMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverSeq>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XmlMDF_MapOfDriver, std::unique_ptr<XmlMDF_MapOfDriver, Deleter<XmlMDF_MapOfDriver>>, NCollection_BaseMap> cls_XmlMDF_MapOfDriver(mod, "XmlMDF_MapOfDriver", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XmlMDF_MapOfDriver.def(py::init<>());
	cls_XmlMDF_MapOfDriver.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XmlMDF_MapOfDriver.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XmlMDF_MapOfDriver.def(py::init([] (const XmlMDF_MapOfDriver &other) {return new XmlMDF_MapOfDriver(other);}), "Copy constructor", py::arg("other"));
	cls_XmlMDF_MapOfDriver.def("begin", (XmlMDF_MapOfDriver::iterator (XmlMDF_MapOfDriver::*)() const ) &XmlMDF_MapOfDriver::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XmlMDF_MapOfDriver.def("end", (XmlMDF_MapOfDriver::iterator (XmlMDF_MapOfDriver::*)() const ) &XmlMDF_MapOfDriver::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XmlMDF_MapOfDriver.def("cbegin", (XmlMDF_MapOfDriver::const_iterator (XmlMDF_MapOfDriver::*)() const ) &XmlMDF_MapOfDriver::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XmlMDF_MapOfDriver.def("cend", (XmlMDF_MapOfDriver::const_iterator (XmlMDF_MapOfDriver::*)() const ) &XmlMDF_MapOfDriver::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XmlMDF_MapOfDriver.def("Exchange", (void (XmlMDF_MapOfDriver::*)(XmlMDF_MapOfDriver &)) &XmlMDF_MapOfDriver::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XmlMDF_MapOfDriver.def("Assign", (XmlMDF_MapOfDriver & (XmlMDF_MapOfDriver::*)(const XmlMDF_MapOfDriver &)) &XmlMDF_MapOfDriver::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XmlMDF_MapOfDriver.def("assign", (XmlMDF_MapOfDriver & (XmlMDF_MapOfDriver::*)(const XmlMDF_MapOfDriver &)) &XmlMDF_MapOfDriver::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XmlMDF_MapOfDriver.def("ReSize", (void (XmlMDF_MapOfDriver::*)(const Standard_Integer)) &XmlMDF_MapOfDriver::ReSize, "ReSize", py::arg("N"));
	cls_XmlMDF_MapOfDriver.def("Bind", (Standard_Boolean (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &, const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_MapOfDriver::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XmlMDF_MapOfDriver.def("Bound", (opencascade::handle<XmlMDF_ADriver> * (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &, const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_MapOfDriver::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XmlMDF_MapOfDriver.def("IsBound", (Standard_Boolean (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &) const ) &XmlMDF_MapOfDriver::IsBound, "IsBound", py::arg("theKey"));
	cls_XmlMDF_MapOfDriver.def("UnBind", (Standard_Boolean (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &)) &XmlMDF_MapOfDriver::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XmlMDF_MapOfDriver.def("Seek", (const opencascade::handle<XmlMDF_ADriver> * (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &) const ) &XmlMDF_MapOfDriver::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XmlMDF_MapOfDriver.def("Find", (const opencascade::handle<XmlMDF_ADriver> & (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &) const ) &XmlMDF_MapOfDriver::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XmlMDF_MapOfDriver.def("Find", (Standard_Boolean (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &, opencascade::handle<XmlMDF_ADriver> &) const ) &XmlMDF_MapOfDriver::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XmlMDF_MapOfDriver.def("__call__", (const opencascade::handle<XmlMDF_ADriver> & (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &) const ) &XmlMDF_MapOfDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XmlMDF_MapOfDriver.def("ChangeSeek", (opencascade::handle<XmlMDF_ADriver> * (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &)) &XmlMDF_MapOfDriver::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XmlMDF_MapOfDriver.def("ChangeFind", (opencascade::handle<XmlMDF_ADriver> & (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &)) &XmlMDF_MapOfDriver::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XmlMDF_MapOfDriver.def("__call__", (opencascade::handle<XmlMDF_ADriver> & (XmlMDF_MapOfDriver::*)(const TCollection_AsciiString &)) &XmlMDF_MapOfDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XmlMDF_MapOfDriver.def("Clear", [](XmlMDF_MapOfDriver &self) -> void { return self.Clear(); });
	cls_XmlMDF_MapOfDriver.def("Clear", (void (XmlMDF_MapOfDriver::*)(const Standard_Boolean)) &XmlMDF_MapOfDriver::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XmlMDF_MapOfDriver.def("Clear", (void (XmlMDF_MapOfDriver::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XmlMDF_MapOfDriver::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XmlMDF_MapOfDriver.def("Size", (Standard_Integer (XmlMDF_MapOfDriver::*)() const ) &XmlMDF_MapOfDriver::Size, "Size");
	cls_XmlMDF_MapOfDriver.def("__iter__", [](const XmlMDF_MapOfDriver &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_MapOfDriver.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XmlMDF_TypeADriverMap, std::unique_ptr<XmlMDF_TypeADriverMap, Deleter<XmlMDF_TypeADriverMap>>, NCollection_BaseMap> cls_XmlMDF_TypeADriverMap(mod, "XmlMDF_TypeADriverMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XmlMDF_TypeADriverMap.def(py::init<>());
	cls_XmlMDF_TypeADriverMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XmlMDF_TypeADriverMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XmlMDF_TypeADriverMap.def(py::init([] (const XmlMDF_TypeADriverMap &other) {return new XmlMDF_TypeADriverMap(other);}), "Copy constructor", py::arg("other"));
	cls_XmlMDF_TypeADriverMap.def("begin", (XmlMDF_TypeADriverMap::iterator (XmlMDF_TypeADriverMap::*)() const ) &XmlMDF_TypeADriverMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XmlMDF_TypeADriverMap.def("end", (XmlMDF_TypeADriverMap::iterator (XmlMDF_TypeADriverMap::*)() const ) &XmlMDF_TypeADriverMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XmlMDF_TypeADriverMap.def("cbegin", (XmlMDF_TypeADriverMap::const_iterator (XmlMDF_TypeADriverMap::*)() const ) &XmlMDF_TypeADriverMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XmlMDF_TypeADriverMap.def("cend", (XmlMDF_TypeADriverMap::const_iterator (XmlMDF_TypeADriverMap::*)() const ) &XmlMDF_TypeADriverMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XmlMDF_TypeADriverMap.def("Exchange", (void (XmlMDF_TypeADriverMap::*)(XmlMDF_TypeADriverMap &)) &XmlMDF_TypeADriverMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XmlMDF_TypeADriverMap.def("Assign", (XmlMDF_TypeADriverMap & (XmlMDF_TypeADriverMap::*)(const XmlMDF_TypeADriverMap &)) &XmlMDF_TypeADriverMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XmlMDF_TypeADriverMap.def("assign", (XmlMDF_TypeADriverMap & (XmlMDF_TypeADriverMap::*)(const XmlMDF_TypeADriverMap &)) &XmlMDF_TypeADriverMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XmlMDF_TypeADriverMap.def("ReSize", (void (XmlMDF_TypeADriverMap::*)(const Standard_Integer)) &XmlMDF_TypeADriverMap::ReSize, "ReSize", py::arg("N"));
	cls_XmlMDF_TypeADriverMap.def("Bind", (Standard_Boolean (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_TypeADriverMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XmlMDF_TypeADriverMap.def("Bound", (opencascade::handle<XmlMDF_ADriver> * (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, const opencascade::handle<XmlMDF_ADriver> &)) &XmlMDF_TypeADriverMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XmlMDF_TypeADriverMap.def("IsBound", (Standard_Boolean (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &XmlMDF_TypeADriverMap::IsBound, "IsBound", py::arg("theKey"));
	cls_XmlMDF_TypeADriverMap.def("UnBind", (Standard_Boolean (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &XmlMDF_TypeADriverMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XmlMDF_TypeADriverMap.def("Seek", (const opencascade::handle<XmlMDF_ADriver> * (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &XmlMDF_TypeADriverMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XmlMDF_TypeADriverMap.def("Find", (const opencascade::handle<XmlMDF_ADriver> & (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &XmlMDF_TypeADriverMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XmlMDF_TypeADriverMap.def("Find", (Standard_Boolean (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<XmlMDF_ADriver> &) const ) &XmlMDF_TypeADriverMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XmlMDF_TypeADriverMap.def("__call__", (const opencascade::handle<XmlMDF_ADriver> & (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &XmlMDF_TypeADriverMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XmlMDF_TypeADriverMap.def("ChangeSeek", (opencascade::handle<XmlMDF_ADriver> * (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &XmlMDF_TypeADriverMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XmlMDF_TypeADriverMap.def("ChangeFind", (opencascade::handle<XmlMDF_ADriver> & (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &XmlMDF_TypeADriverMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XmlMDF_TypeADriverMap.def("__call__", (opencascade::handle<XmlMDF_ADriver> & (XmlMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &XmlMDF_TypeADriverMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XmlMDF_TypeADriverMap.def("Clear", [](XmlMDF_TypeADriverMap &self) -> void { return self.Clear(); });
	cls_XmlMDF_TypeADriverMap.def("Clear", (void (XmlMDF_TypeADriverMap::*)(const Standard_Boolean)) &XmlMDF_TypeADriverMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XmlMDF_TypeADriverMap.def("Clear", (void (XmlMDF_TypeADriverMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XmlMDF_TypeADriverMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XmlMDF_TypeADriverMap.def("Size", (Standard_Integer (XmlMDF_TypeADriverMap::*)() const ) &XmlMDF_TypeADriverMap::Size, "Size");
	cls_XmlMDF_TypeADriverMap.def("__iter__", [](const XmlMDF_TypeADriverMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDF_TypeADriverMap.hxx

}
