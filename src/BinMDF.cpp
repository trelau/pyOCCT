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
#include <BinMDF_ADriver.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_AsciiString.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_MessageDriver.hxx>
#include <BinMDF_ReferenceDriver.hxx>
#include <BinMDF_TagSourceDriver.hxx>
#include <BinMDF.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BinMDF_TypeADriverMap.hxx>
#include <NCollection_DoubleMap.hxx>
#include <BinMDF_TypeIdMap.hxx>
#include <BinMDF_StringIdMap.hxx>

PYBIND11_MODULE(BinMDF, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.BinObjMgt");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ADriverTable.hxx
	py::class_<BinMDF_ADriverTable, opencascade::handle<BinMDF_ADriverTable>, Standard_Transient> cls_BinMDF_ADriverTable(mod, "BinMDF_ADriverTable", "A driver table is an object building links between object types and object drivers. In the translation process, a driver table is asked to give a translation driver for each current object to be translated.");
	cls_BinMDF_ADriverTable.def(py::init<>());
	cls_BinMDF_ADriverTable.def("AddDriver", (void (BinMDF_ADriverTable::*)(const opencascade::handle<BinMDF_ADriver> &)) &BinMDF_ADriverTable::AddDriver, "Adds a translation driver <theDriver>.", py::arg("theDriver"));
	cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_IndexedMapOfTransient &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Types. It uses indices in the map as IDs. Useful in storage procedure.", py::arg("theTypes"));
	cls_BinMDF_ADriverTable.def("AssignIds", (void (BinMDF_ADriverTable::*)(const TColStd_SequenceOfAsciiString &)) &BinMDF_ADriverTable::AssignIds, "Assigns the IDs to the drivers of the given Type Names; It uses indices in the sequence as IDs. Useful in retrieval procedure.", py::arg("theTypeNames"));
	cls_BinMDF_ADriverTable.def("GetDriver", (Standard_Integer (BinMDF_ADriverTable::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<BinMDF_ADriver> &) const ) &BinMDF_ADriverTable::GetDriver, "Gets a driver <theDriver> according to <theType>. Returns Type ID if the driver was assigned an ID; 0 otherwise.", py::arg("theType"), py::arg("theDriver"));
	cls_BinMDF_ADriverTable.def("GetDriver", (opencascade::handle<BinMDF_ADriver> (BinMDF_ADriverTable::*)(const Standard_Integer) const ) &BinMDF_ADriverTable::GetDriver, "Returns a driver according to <theTypeId>. Returns null handle if a driver is not found", py::arg("theTypeId"));
	cls_BinMDF_ADriverTable.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriverTable::get_type_name, "None");
	cls_BinMDF_ADriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriverTable::get_type_descriptor, "None");
	cls_BinMDF_ADriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriverTable::*)() const ) &BinMDF_ADriverTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ADriver.hxx
	py::class_<BinMDF_ADriver, opencascade::handle<BinMDF_ADriver>, Standard_Transient> cls_BinMDF_ADriver(mod, "BinMDF_ADriver", "Attribute Storage/Retrieval Driver.");
	cls_BinMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
	cls_BinMDF_ADriver.def("SourceType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
	cls_BinMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::TypeName, "Returns the type name of the attribute object");
	cls_BinMDF_ADriver.def("Paste", (Standard_Boolean (BinMDF_ADriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_BinMDF_ADriver.def("Paste", (void (BinMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
	cls_BinMDF_ADriver.def("WriteMessage", (void (BinMDF_ADriver::*)(const TCollection_ExtendedString &) const ) &BinMDF_ADriver::WriteMessage, "Send message to Application (usually when error occurres)", py::arg("theMessage"));
	cls_BinMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriver::get_type_name, "None");
	cls_BinMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriver::get_type_descriptor, "None");
	cls_BinMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const ) &BinMDF_ADriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_ReferenceDriver.hxx
	py::class_<BinMDF_ReferenceDriver, opencascade::handle<BinMDF_ReferenceDriver>, BinMDF_ADriver> cls_BinMDF_ReferenceDriver(mod, "BinMDF_ReferenceDriver", "Reference attribute Driver.");
	cls_BinMDF_ReferenceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDF_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_ReferenceDriver::*)() const ) &BinMDF_ReferenceDriver::NewEmpty, "None");
	cls_BinMDF_ReferenceDriver.def("Paste", (Standard_Boolean (BinMDF_ReferenceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_ReferenceDriver.def("Paste", (void (BinMDF_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_ReferenceDriver::get_type_name, "None");
	cls_BinMDF_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ReferenceDriver::get_type_descriptor, "None");
	cls_BinMDF_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ReferenceDriver::*)() const ) &BinMDF_ReferenceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TagSourceDriver.hxx
	py::class_<BinMDF_TagSourceDriver, opencascade::handle<BinMDF_TagSourceDriver>, BinMDF_ADriver> cls_BinMDF_TagSourceDriver(mod, "BinMDF_TagSourceDriver", "TDF_TagSource Driver.");
	cls_BinMDF_TagSourceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDF_TagSourceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_TagSourceDriver::*)() const ) &BinMDF_TagSourceDriver::NewEmpty, "None");
	cls_BinMDF_TagSourceDriver.def("Paste", (Standard_Boolean (BinMDF_TagSourceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_TagSourceDriver.def("Paste", (void (BinMDF_TagSourceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDF_TagSourceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDF_TagSourceDriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_TagSourceDriver::get_type_name, "None");
	cls_BinMDF_TagSourceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_TagSourceDriver::get_type_descriptor, "None");
	cls_BinMDF_TagSourceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_TagSourceDriver::*)() const ) &BinMDF_TagSourceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF.hxx
	py::class_<BinMDF, std::unique_ptr<BinMDF, Deleter<BinMDF>>> cls_BinMDF(mod, "BinMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");
	cls_BinMDF.def(py::init<>());
	cls_BinMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("aMsgDrv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BinMDF_TypeADriverMap, std::unique_ptr<BinMDF_TypeADriverMap, Deleter<BinMDF_TypeADriverMap>>, NCollection_BaseMap> cls_BinMDF_TypeADriverMap(mod, "BinMDF_TypeADriverMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BinMDF_TypeADriverMap.def(py::init<>());
	cls_BinMDF_TypeADriverMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BinMDF_TypeADriverMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BinMDF_TypeADriverMap.def(py::init([] (const BinMDF_TypeADriverMap &other) {return new BinMDF_TypeADriverMap(other);}), "Copy constructor", py::arg("other"));
	cls_BinMDF_TypeADriverMap.def("begin", (BinMDF_TypeADriverMap::iterator (BinMDF_TypeADriverMap::*)() const ) &BinMDF_TypeADriverMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BinMDF_TypeADriverMap.def("end", (BinMDF_TypeADriverMap::iterator (BinMDF_TypeADriverMap::*)() const ) &BinMDF_TypeADriverMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BinMDF_TypeADriverMap.def("cbegin", (BinMDF_TypeADriverMap::const_iterator (BinMDF_TypeADriverMap::*)() const ) &BinMDF_TypeADriverMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BinMDF_TypeADriverMap.def("cend", (BinMDF_TypeADriverMap::const_iterator (BinMDF_TypeADriverMap::*)() const ) &BinMDF_TypeADriverMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BinMDF_TypeADriverMap.def("Exchange", (void (BinMDF_TypeADriverMap::*)(BinMDF_TypeADriverMap &)) &BinMDF_TypeADriverMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BinMDF_TypeADriverMap.def("Assign", (BinMDF_TypeADriverMap & (BinMDF_TypeADriverMap::*)(const BinMDF_TypeADriverMap &)) &BinMDF_TypeADriverMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BinMDF_TypeADriverMap.def("assign", (BinMDF_TypeADriverMap & (BinMDF_TypeADriverMap::*)(const BinMDF_TypeADriverMap &)) &BinMDF_TypeADriverMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BinMDF_TypeADriverMap.def("ReSize", (void (BinMDF_TypeADriverMap::*)(const Standard_Integer)) &BinMDF_TypeADriverMap::ReSize, "ReSize", py::arg("N"));
	cls_BinMDF_TypeADriverMap.def("Bind", (Standard_Boolean (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, const opencascade::handle<BinMDF_ADriver> &)) &BinMDF_TypeADriverMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BinMDF_TypeADriverMap.def("Bound", (opencascade::handle<BinMDF_ADriver> * (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, const opencascade::handle<BinMDF_ADriver> &)) &BinMDF_TypeADriverMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BinMDF_TypeADriverMap.def("IsBound", (Standard_Boolean (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeADriverMap::IsBound, "IsBound", py::arg("theKey"));
	cls_BinMDF_TypeADriverMap.def("UnBind", (Standard_Boolean (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &BinMDF_TypeADriverMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BinMDF_TypeADriverMap.def("Seek", (const opencascade::handle<BinMDF_ADriver> * (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeADriverMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BinMDF_TypeADriverMap.def("Find", (const opencascade::handle<BinMDF_ADriver> & (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeADriverMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BinMDF_TypeADriverMap.def("Find", (Standard_Boolean (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &, opencascade::handle<BinMDF_ADriver> &) const ) &BinMDF_TypeADriverMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BinMDF_TypeADriverMap.def("__call__", (const opencascade::handle<BinMDF_ADriver> & (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeADriverMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BinMDF_TypeADriverMap.def("ChangeSeek", (opencascade::handle<BinMDF_ADriver> * (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &BinMDF_TypeADriverMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BinMDF_TypeADriverMap.def("ChangeFind", (opencascade::handle<BinMDF_ADriver> & (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &BinMDF_TypeADriverMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BinMDF_TypeADriverMap.def("__call__", (opencascade::handle<BinMDF_ADriver> & (BinMDF_TypeADriverMap::*)(const opencascade::handle<Standard_Type> &)) &BinMDF_TypeADriverMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BinMDF_TypeADriverMap.def("Clear", [](BinMDF_TypeADriverMap &self) -> void { return self.Clear(); });
	cls_BinMDF_TypeADriverMap.def("Clear", (void (BinMDF_TypeADriverMap::*)(const Standard_Boolean)) &BinMDF_TypeADriverMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BinMDF_TypeADriverMap.def("Clear", (void (BinMDF_TypeADriverMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BinMDF_TypeADriverMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BinMDF_TypeADriverMap.def("Size", (Standard_Integer (BinMDF_TypeADriverMap::*)() const ) &BinMDF_TypeADriverMap::Size, "Size");
	cls_BinMDF_TypeADriverMap.def("__iter__", [](const BinMDF_TypeADriverMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TypeADriverMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<BinMDF_TypeIdMap, std::unique_ptr<BinMDF_TypeIdMap, Deleter<BinMDF_TypeIdMap>>, NCollection_BaseMap> cls_BinMDF_TypeIdMap(mod, "BinMDF_TypeIdMap", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_BinMDF_TypeIdMap.def(py::init<>());
	cls_BinMDF_TypeIdMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BinMDF_TypeIdMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BinMDF_TypeIdMap.def(py::init([] (const BinMDF_TypeIdMap &other) {return new BinMDF_TypeIdMap(other);}), "Copy constructor", py::arg("other"));
	cls_BinMDF_TypeIdMap.def("Exchange", (void (BinMDF_TypeIdMap::*)(BinMDF_TypeIdMap &)) &BinMDF_TypeIdMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BinMDF_TypeIdMap.def("Assign", (BinMDF_TypeIdMap & (BinMDF_TypeIdMap::*)(const BinMDF_TypeIdMap &)) &BinMDF_TypeIdMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BinMDF_TypeIdMap.def("assign", (BinMDF_TypeIdMap & (BinMDF_TypeIdMap::*)(const BinMDF_TypeIdMap &)) &BinMDF_TypeIdMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BinMDF_TypeIdMap.def("ReSize", (void (BinMDF_TypeIdMap::*)(const Standard_Integer)) &BinMDF_TypeIdMap::ReSize, "ReSize", py::arg("N"));
	cls_BinMDF_TypeIdMap.def("Bind", (void (BinMDF_TypeIdMap::*)(const opencascade::handle<Standard_Type> &, const Standard_Integer &)) &BinMDF_TypeIdMap::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_BinMDF_TypeIdMap.def("AreBound", (Standard_Boolean (BinMDF_TypeIdMap::*)(const opencascade::handle<Standard_Type> &, const Standard_Integer &) const ) &BinMDF_TypeIdMap::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_BinMDF_TypeIdMap.def("IsBound1", (Standard_Boolean (BinMDF_TypeIdMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeIdMap::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_BinMDF_TypeIdMap.def("IsBound2", (Standard_Boolean (BinMDF_TypeIdMap::*)(const Standard_Integer &) const ) &BinMDF_TypeIdMap::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_BinMDF_TypeIdMap.def("UnBind1", (Standard_Boolean (BinMDF_TypeIdMap::*)(const opencascade::handle<Standard_Type> &)) &BinMDF_TypeIdMap::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_BinMDF_TypeIdMap.def("UnBind2", (Standard_Boolean (BinMDF_TypeIdMap::*)(const Standard_Integer &)) &BinMDF_TypeIdMap::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_BinMDF_TypeIdMap.def("Find1", (const Standard_Integer & (BinMDF_TypeIdMap::*)(const opencascade::handle<Standard_Type> &) const ) &BinMDF_TypeIdMap::Find1, "Find1", py::arg("theKey1"));
	cls_BinMDF_TypeIdMap.def("Find2", (const opencascade::handle<Standard_Type> & (BinMDF_TypeIdMap::*)(const Standard_Integer &) const ) &BinMDF_TypeIdMap::Find2, "Find2", py::arg("theKey2"));
	cls_BinMDF_TypeIdMap.def("Clear", [](BinMDF_TypeIdMap &self) -> void { return self.Clear(); });
	cls_BinMDF_TypeIdMap.def("Clear", (void (BinMDF_TypeIdMap::*)(const Standard_Boolean)) &BinMDF_TypeIdMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BinMDF_TypeIdMap.def("Clear", (void (BinMDF_TypeIdMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BinMDF_TypeIdMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BinMDF_TypeIdMap.def("Size", (Standard_Integer (BinMDF_TypeIdMap::*)() const ) &BinMDF_TypeIdMap::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDF_TypeIdMap.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfAsciiStringInteger")) {
		mod.attr("BinMDF_StringIdMap") = other_mod.attr("TColStd_DataMapOfAsciiStringInteger");
	}


}
