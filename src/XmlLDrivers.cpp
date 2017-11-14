#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <PCDM_RetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <Standard_Type.hxx>
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlLDrivers_NamespaceDef.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlLDrivers_SequenceOfNamespaceDef.hxx>
#include <PCDM_StorageDriver.hxx>
#include <Standard_OStream.hxx>
#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <XmlLDrivers.hxx>

PYBIND11_MODULE(XmlLDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.PCDM");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TDocStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_DocumentRetrievalDriver.hxx
	py::class_<XmlLDrivers_DocumentRetrievalDriver, opencascade::handle<XmlLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_XmlLDrivers_DocumentRetrievalDriver(mod, "XmlLDrivers_DocumentRetrievalDriver", "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_XmlLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (XmlLDrivers_DocumentRetrievalDriver::*)()) &XmlLDrivers_DocumentRetrievalDriver::CreateDocument, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentRetrievalDriver::*)() const ) &XmlLDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_NamespaceDef.hxx
	py::class_<XmlLDrivers_NamespaceDef, std::unique_ptr<XmlLDrivers_NamespaceDef, Deleter<XmlLDrivers_NamespaceDef>>> cls_XmlLDrivers_NamespaceDef(mod, "XmlLDrivers_NamespaceDef", "None");
	cls_XmlLDrivers_NamespaceDef.def(py::init<>());
	cls_XmlLDrivers_NamespaceDef.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("thePrefix"), py::arg("theURI"));
	cls_XmlLDrivers_NamespaceDef.def("Prefix", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const ) &XmlLDrivers_NamespaceDef::Prefix, "None");
	cls_XmlLDrivers_NamespaceDef.def("URI", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const ) &XmlLDrivers_NamespaceDef::URI, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_DocumentStorageDriver.hxx
	py::class_<XmlLDrivers_DocumentStorageDriver, opencascade::handle<XmlLDrivers_DocumentStorageDriver>, PCDM_StorageDriver> cls_XmlLDrivers_DocumentStorageDriver(mod, "XmlLDrivers_DocumentStorageDriver", "None");
	cls_XmlLDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));
	cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theFileName"));
	cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theOStream"));
	cls_XmlLDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_XmlLDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentStorageDriver::*)() const ) &XmlLDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers.hxx
	py::class_<XmlLDrivers, std::unique_ptr<XmlLDrivers, Deleter<XmlLDrivers>>> cls_XmlLDrivers(mod, "XmlLDrivers", "None");
	cls_XmlLDrivers.def(py::init<>());
	cls_XmlLDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &XmlLDrivers::Factory, "None", py::arg("theGUID"));
	cls_XmlLDrivers.def_static("CreationDate_", (TCollection_AsciiString (*)()) &XmlLDrivers::CreationDate, "None");
	cls_XmlLDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &XmlLDrivers::DefineFormat, "Defines format 'XmlLOcaf' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_XmlLDrivers.def_static("AttributeDrivers_", (opencascade::handle<XmlMDF_ADriverTable> (*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers.def_static("StorageVersion_", (int (*)()) &XmlLDrivers::StorageVersion, "None");
	cls_XmlLDrivers.def_static("SetStorageVersion_", (void (*)(const int)) &XmlLDrivers::SetStorageVersion, "None", py::arg("version"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<XmlLDrivers_SequenceOfNamespaceDef, std::unique_ptr<XmlLDrivers_SequenceOfNamespaceDef, Deleter<XmlLDrivers_SequenceOfNamespaceDef>>, NCollection_BaseSequence> cls_XmlLDrivers_SequenceOfNamespaceDef(mod, "XmlLDrivers_SequenceOfNamespaceDef", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def(py::init<>());
	cls_XmlLDrivers_SequenceOfNamespaceDef.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def(py::init([] (const XmlLDrivers_SequenceOfNamespaceDef &other) {return new XmlLDrivers_SequenceOfNamespaceDef(other);}), "Copy constructor", py::arg("other"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("begin", (XmlLDrivers_SequenceOfNamespaceDef::iterator (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("end", (XmlLDrivers_SequenceOfNamespaceDef::iterator (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("cbegin", (XmlLDrivers_SequenceOfNamespaceDef::const_iterator (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("cend", (XmlLDrivers_SequenceOfNamespaceDef::const_iterator (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Size", (Standard_Integer (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::Size, "Number of items");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Length", (Standard_Integer (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::Length, "Number of items");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Lower", (Standard_Integer (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::Lower, "Method for consistency with other collections.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Upper", (Standard_Integer (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::Upper, "Method for consistency with other collections.");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("IsEmpty", (Standard_Boolean (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::IsEmpty, "Empty query");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Reverse", (void (XmlLDrivers_SequenceOfNamespaceDef::*)()) &XmlLDrivers_SequenceOfNamespaceDef::Reverse, "Reverse sequence");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Exchange", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, const Standard_Integer)) &XmlLDrivers_SequenceOfNamespaceDef::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &XmlLDrivers_SequenceOfNamespaceDef::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Clear", [](XmlLDrivers_SequenceOfNamespaceDef &self) -> void { return self.Clear(); });
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Clear", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XmlLDrivers_SequenceOfNamespaceDef::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Assign", (XmlLDrivers_SequenceOfNamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("assign", (XmlLDrivers_SequenceOfNamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Remove", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(XmlLDrivers_SequenceOfNamespaceDef::Iterator &)) &XmlLDrivers_SequenceOfNamespaceDef::Remove, "Remove one item", py::arg("thePosition"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Remove", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer)) &XmlLDrivers_SequenceOfNamespaceDef::Remove, "Remove one item", py::arg("theIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Remove", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, const Standard_Integer)) &XmlLDrivers_SequenceOfNamespaceDef::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Append", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Append, "Append one item", py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Append", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Prepend", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Prepend, "Prepend one item", py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Prepend", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("InsertBefore", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("InsertBefore", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("InsertAfter", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(XmlLDrivers_SequenceOfNamespaceDef::Iterator &, const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("InsertAfter", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("InsertAfter", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Split", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, XmlLDrivers_SequenceOfNamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("First", (const XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::First, "First item access");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("ChangeFirst", (XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)()) &XmlLDrivers_SequenceOfNamespaceDef::ChangeFirst, "First item access");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Last", (const XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)() const ) &XmlLDrivers_SequenceOfNamespaceDef::Last, "Last item access");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("ChangeLast", (XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)()) &XmlLDrivers_SequenceOfNamespaceDef::ChangeLast, "Last item access");
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("Value", (const XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer) const ) &XmlLDrivers_SequenceOfNamespaceDef::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("__call__", (const XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer) const ) &XmlLDrivers_SequenceOfNamespaceDef::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("ChangeValue", (XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer)) &XmlLDrivers_SequenceOfNamespaceDef::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("__call__", (XmlLDrivers_NamespaceDef & (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer)) &XmlLDrivers_SequenceOfNamespaceDef::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("SetValue", (void (XmlLDrivers_SequenceOfNamespaceDef::*)(const Standard_Integer, const XmlLDrivers_NamespaceDef &)) &XmlLDrivers_SequenceOfNamespaceDef::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_XmlLDrivers_SequenceOfNamespaceDef.def("__iter__", [](const XmlLDrivers_SequenceOfNamespaceDef &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
