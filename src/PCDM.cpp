#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_IStream.hxx>

#include <PCDM_ReaderStatus.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <Standard_Type.hxx>
#include <PCDM_Reader.hxx>
#include <Standard_TypeDef.hxx>
#include <CDM_MessageDriver.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <PCDM_Writer.hxx>
#include <PCDM_Document.hxx>
#include <PCDM_SequenceOfDocument.hxx>
#include <Standard_OStream.hxx>
#include <PCDM_StoreStatus.hxx>
#include <PCDM_StorageDriver.hxx>
#include <Standard_Failure.hxx>
#include <Standard_SStream.hxx>
#include <PCDM_DriverError.hxx>
#include <PCDM_Reference.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <PCDM_SequenceOfReference.hxx>
#include <CDM_MetaData.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <Standard_Persistent.hxx>
#include <PCDM_TypeOfFileDriver.hxx>
#include <PCDM_BaseDriverPointer.hxx>
#include <TCollection_AsciiString.hxx>
#include <PCDM.hxx>
#include <LDOMParser.hxx>
#include <LDOM_Element.hxx>
#include <PCDM_DOMHeaderParser.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_OpenMode.hxx>
#include <PCDM_ReadWriter.hxx>
#include <PCDM_ReadWriter_1.hxx>

PYBIND11_MODULE(PCDM, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.LDOMParser");
	py::module::import("OCCT.LDOM");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_ReaderStatus.hxx
	py::enum_<PCDM_ReaderStatus>(mod, "PCDM_ReaderStatus", "None")
		.value("PCDM_RS_OK", PCDM_ReaderStatus::PCDM_RS_OK)
		.value("PCDM_RS_NoDriver", PCDM_ReaderStatus::PCDM_RS_NoDriver)
		.value("PCDM_RS_UnknownFileDriver", PCDM_ReaderStatus::PCDM_RS_UnknownFileDriver)
		.value("PCDM_RS_OpenError", PCDM_ReaderStatus::PCDM_RS_OpenError)
		.value("PCDM_RS_NoVersion", PCDM_ReaderStatus::PCDM_RS_NoVersion)
		.value("PCDM_RS_NoSchema", PCDM_ReaderStatus::PCDM_RS_NoSchema)
		.value("PCDM_RS_NoDocument", PCDM_ReaderStatus::PCDM_RS_NoDocument)
		.value("PCDM_RS_ExtensionFailure", PCDM_ReaderStatus::PCDM_RS_ExtensionFailure)
		.value("PCDM_RS_WrongStreamMode", PCDM_ReaderStatus::PCDM_RS_WrongStreamMode)
		.value("PCDM_RS_FormatFailure", PCDM_ReaderStatus::PCDM_RS_FormatFailure)
		.value("PCDM_RS_TypeFailure", PCDM_ReaderStatus::PCDM_RS_TypeFailure)
		.value("PCDM_RS_TypeNotFoundInSchema", PCDM_ReaderStatus::PCDM_RS_TypeNotFoundInSchema)
		.value("PCDM_RS_UnrecognizedFileFormat", PCDM_ReaderStatus::PCDM_RS_UnrecognizedFileFormat)
		.value("PCDM_RS_MakeFailure", PCDM_ReaderStatus::PCDM_RS_MakeFailure)
		.value("PCDM_RS_PermissionDenied", PCDM_ReaderStatus::PCDM_RS_PermissionDenied)
		.value("PCDM_RS_DriverFailure", PCDM_ReaderStatus::PCDM_RS_DriverFailure)
		.value("PCDM_RS_AlreadyRetrievedAndModified", PCDM_ReaderStatus::PCDM_RS_AlreadyRetrievedAndModified)
		.value("PCDM_RS_AlreadyRetrieved", PCDM_ReaderStatus::PCDM_RS_AlreadyRetrieved)
		.value("PCDM_RS_UnknownDocument", PCDM_ReaderStatus::PCDM_RS_UnknownDocument)
		.value("PCDM_RS_WrongResource", PCDM_ReaderStatus::PCDM_RS_WrongResource)
		.value("PCDM_RS_ReaderException", PCDM_ReaderStatus::PCDM_RS_ReaderException)
		.value("PCDM_RS_NoModel", PCDM_ReaderStatus::PCDM_RS_NoModel)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_StoreStatus.hxx
	py::enum_<PCDM_StoreStatus>(mod, "PCDM_StoreStatus", "None")
		.value("PCDM_SS_OK", PCDM_StoreStatus::PCDM_SS_OK)
		.value("PCDM_SS_DriverFailure", PCDM_StoreStatus::PCDM_SS_DriverFailure)
		.value("PCDM_SS_WriteFailure", PCDM_StoreStatus::PCDM_SS_WriteFailure)
		.value("PCDM_SS_Failure", PCDM_StoreStatus::PCDM_SS_Failure)
		.value("PCDM_SS_Doc_IsNull", PCDM_StoreStatus::PCDM_SS_Doc_IsNull)
		.value("PCDM_SS_No_Obj", PCDM_StoreStatus::PCDM_SS_No_Obj)
		.value("PCDM_SS_Info_Section_Error", PCDM_StoreStatus::PCDM_SS_Info_Section_Error)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_TypeOfFileDriver.hxx
	py::enum_<PCDM_TypeOfFileDriver>(mod, "PCDM_TypeOfFileDriver", "None")
		.value("PCDM_TOFD_File", PCDM_TypeOfFileDriver::PCDM_TOFD_File)
		.value("PCDM_TOFD_CmpFile", PCDM_TypeOfFileDriver::PCDM_TOFD_CmpFile)
		.value("PCDM_TOFD_XmlFile", PCDM_TypeOfFileDriver::PCDM_TOFD_XmlFile)
		.value("PCDM_TOFD_Unknown", PCDM_TypeOfFileDriver::PCDM_TOFD_Unknown)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_Reader.hxx
	py::class_<PCDM_Reader, opencascade::handle<PCDM_Reader>, Standard_Transient> cls_PCDM_Reader(mod, "PCDM_Reader", "None");
	cls_PCDM_Reader.def("CreateDocument", (opencascade::handle<CDM_Document> (PCDM_Reader::*)()) &PCDM_Reader::CreateDocument, "this method is called by the framework before the read method.");
	cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "retrieves the content of the file into a new Document.", py::arg("aFileName"), py::arg("aNewDocument"), py::arg("anApplication"));
	cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
	cls_PCDM_Reader.def("GetStatus", (PCDM_ReaderStatus (PCDM_Reader::*)() const ) &PCDM_Reader::GetStatus, "None");
	cls_PCDM_Reader.def_static("get_type_name_", (const char * (*)()) &PCDM_Reader::get_type_name, "None");
	cls_PCDM_Reader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Reader::get_type_descriptor, "None");
	cls_PCDM_Reader.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Reader::*)() const ) &PCDM_Reader::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_RetrievalDriver.hxx
	py::class_<PCDM_RetrievalDriver, opencascade::handle<PCDM_RetrievalDriver>, PCDM_Reader> cls_PCDM_RetrievalDriver(mod, "PCDM_RetrievalDriver", "None");
	cls_PCDM_RetrievalDriver.def_static("DocumentVersion_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &)) &PCDM_RetrievalDriver::DocumentVersion, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
	cls_PCDM_RetrievalDriver.def_static("ReferenceCounter_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &)) &PCDM_RetrievalDriver::ReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
	cls_PCDM_RetrievalDriver.def("SetFormat", (void (PCDM_RetrievalDriver::*)(const TCollection_ExtendedString &)) &PCDM_RetrievalDriver::SetFormat, "None", py::arg("aformat"));
	cls_PCDM_RetrievalDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_RetrievalDriver::*)() const ) &PCDM_RetrievalDriver::GetFormat, "None");
	cls_PCDM_RetrievalDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_RetrievalDriver::get_type_name, "None");
	cls_PCDM_RetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_RetrievalDriver::get_type_descriptor, "None");
	cls_PCDM_RetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_RetrievalDriver::*)() const ) &PCDM_RetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_Writer.hxx
	py::class_<PCDM_Writer, opencascade::handle<PCDM_Writer>, Standard_Transient> cls_PCDM_Writer(mod, "PCDM_Writer", "None");
	cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_Writer::Write, "None", py::arg("aDocument"), py::arg("aFileName"));
	cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_Writer::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
	cls_PCDM_Writer.def_static("get_type_name_", (const char * (*)()) &PCDM_Writer::get_type_name, "None");
	cls_PCDM_Writer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Writer::get_type_descriptor, "None");
	cls_PCDM_Writer.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Writer::*)() const ) &PCDM_Writer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_DriverError.hxx
	py::class_<PCDM_DriverError, opencascade::handle<PCDM_DriverError>, Standard_Failure> cls_PCDM_DriverError(mod, "PCDM_DriverError", "None");
	cls_PCDM_DriverError.def(py::init<>());
	cls_PCDM_DriverError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_PCDM_DriverError.def_static("Raise_", (void (*)(const Standard_CString)) &PCDM_DriverError::Raise, "None", py::arg("theMessage"));
	cls_PCDM_DriverError.def_static("Raise_", (void (*)(Standard_SStream &)) &PCDM_DriverError::Raise, "None", py::arg("theMessage"));
	cls_PCDM_DriverError.def_static("NewInstance_", (opencascade::handle<PCDM_DriverError> (*)(const Standard_CString)) &PCDM_DriverError::NewInstance, "None", py::arg("theMessage"));
	cls_PCDM_DriverError.def_static("get_type_name_", (const char * (*)()) &PCDM_DriverError::get_type_name, "None");
	cls_PCDM_DriverError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_DriverError::get_type_descriptor, "None");
	cls_PCDM_DriverError.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_DriverError::*)() const ) &PCDM_DriverError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_Reference.hxx
	py::class_<PCDM_Reference, std::unique_ptr<PCDM_Reference, Deleter<PCDM_Reference>>> cls_PCDM_Reference(mod, "PCDM_Reference", "None");
	cls_PCDM_Reference.def(py::init<>());
	cls_PCDM_Reference.def(py::init<const Standard_Integer, const TCollection_ExtendedString &, const Standard_Integer>(), py::arg("aReferenceIdentifier"), py::arg("aFileName"), py::arg("aDocumentVersion"));
	cls_PCDM_Reference.def("ReferenceIdentifier", (Standard_Integer (PCDM_Reference::*)() const ) &PCDM_Reference::ReferenceIdentifier, "None");
	cls_PCDM_Reference.def("FileName", (TCollection_ExtendedString (PCDM_Reference::*)() const ) &PCDM_Reference::FileName, "None");
	cls_PCDM_Reference.def("DocumentVersion", (Standard_Integer (PCDM_Reference::*)() const ) &PCDM_Reference::DocumentVersion, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_ReferenceIterator.hxx
	py::class_<PCDM_ReferenceIterator, opencascade::handle<PCDM_ReferenceIterator>, Standard_Transient> cls_PCDM_ReferenceIterator(mod, "PCDM_ReferenceIterator", "None");
	cls_PCDM_ReferenceIterator.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_PCDM_ReferenceIterator.def("LoadReferences", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_Application> &, const Standard_Boolean)) &PCDM_ReferenceIterator::LoadReferences, "None", py::arg("aDocument"), py::arg("aMetaData"), py::arg("anApplication"), py::arg("UseStorageConfiguration"));
	cls_PCDM_ReferenceIterator.def("Init", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_MetaData> &)) &PCDM_ReferenceIterator::Init, "None", py::arg("aMetaData"));
	cls_PCDM_ReferenceIterator.def_static("get_type_name_", (const char * (*)()) &PCDM_ReferenceIterator::get_type_name, "None");
	cls_PCDM_ReferenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReferenceIterator::get_type_descriptor, "None");
	cls_PCDM_ReferenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReferenceIterator::*)() const ) &PCDM_ReferenceIterator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_Document.hxx
	py::class_<PCDM_Document, opencascade::handle<PCDM_Document>, Standard_Persistent> cls_PCDM_Document(mod, "PCDM_Document", "None");
	cls_PCDM_Document.def_static("get_type_name_", (const char * (*)()) &PCDM_Document::get_type_name, "None");
	cls_PCDM_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Document::get_type_descriptor, "None");
	cls_PCDM_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Document::*)() const ) &PCDM_Document::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_StorageDriver.hxx
	py::class_<PCDM_StorageDriver, opencascade::handle<PCDM_StorageDriver>, PCDM_Writer> cls_PCDM_StorageDriver(mod, "PCDM_StorageDriver", "persistent implemention of storage.");
	cls_PCDM_StorageDriver.def("Make", (opencascade::handle<PCDM_Document> (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &)) &PCDM_StorageDriver::Make, "raises NotImplemented.", py::arg("aDocument"));
	cls_PCDM_StorageDriver.def("Make", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, PCDM_SequenceOfDocument &)) &PCDM_StorageDriver::Make, "By default, puts in the Sequence the document returns by the previous Make method.", py::arg("aDocument"), py::arg("Documents"));
	cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_StorageDriver::Write, "Warning! raises DriverError if an error occurs during inside the Make method. stores the content of the Document into a new file.", py::arg("aDocument"), py::arg("aFileName"));
	cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_StorageDriver::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
	cls_PCDM_StorageDriver.def("SetFormat", (void (PCDM_StorageDriver::*)(const TCollection_ExtendedString &)) &PCDM_StorageDriver::SetFormat, "None", py::arg("aformat"));
	cls_PCDM_StorageDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_StorageDriver::*)() const ) &PCDM_StorageDriver::GetFormat, "None");
	cls_PCDM_StorageDriver.def("IsError", (Standard_Boolean (PCDM_StorageDriver::*)() const ) &PCDM_StorageDriver::IsError, "None");
	cls_PCDM_StorageDriver.def("SetIsError", (void (PCDM_StorageDriver::*)(const Standard_Boolean)) &PCDM_StorageDriver::SetIsError, "None", py::arg("theIsError"));
	cls_PCDM_StorageDriver.def("GetStoreStatus", (PCDM_StoreStatus (PCDM_StorageDriver::*)() const ) &PCDM_StorageDriver::GetStoreStatus, "None");
	cls_PCDM_StorageDriver.def("SetStoreStatus", (void (PCDM_StorageDriver::*)(const PCDM_StoreStatus)) &PCDM_StorageDriver::SetStoreStatus, "None", py::arg("theStoreStatus"));
	cls_PCDM_StorageDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_StorageDriver::get_type_name, "None");
	cls_PCDM_StorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_StorageDriver::get_type_descriptor, "None");
	cls_PCDM_StorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_StorageDriver::*)() const ) &PCDM_StorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM.hxx
	py::class_<PCDM, std::unique_ptr<PCDM, Deleter<PCDM>>> cls_PCDM(mod, "PCDM", "None");
	cls_PCDM.def(py::init<>());
	// FIXME cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(const TCollection_AsciiString &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("aFileName"), py::arg("aBaseDriver"));
	// FIXME cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(Standard_IStream &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("theIStream"), py::arg("theBaseDriver"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_DOMHeaderParser.hxx
	py::class_<PCDM_DOMHeaderParser, std::unique_ptr<PCDM_DOMHeaderParser, Deleter<PCDM_DOMHeaderParser>>, LDOMParser> cls_PCDM_DOMHeaderParser(mod, "PCDM_DOMHeaderParser", "None");
	cls_PCDM_DOMHeaderParser.def("SetStartElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetStartElementName, "None", py::arg("aStartElementName"));
	cls_PCDM_DOMHeaderParser.def("SetEndElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetEndElementName, "None", py::arg("anEndElementName"));
	cls_PCDM_DOMHeaderParser.def("startElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::startElement, "None");
	cls_PCDM_DOMHeaderParser.def("endElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::endElement, "None");
	cls_PCDM_DOMHeaderParser.def("GetElement", (const LDOM_Element & (PCDM_DOMHeaderParser::*)() const ) &PCDM_DOMHeaderParser::GetElement, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_ReadWriter.hxx
	py::class_<PCDM_ReadWriter, opencascade::handle<PCDM_ReadWriter>, Standard_Transient> cls_PCDM_ReadWriter(mod, "PCDM_ReadWriter", "None");
	cls_PCDM_ReadWriter.def("Version", (TCollection_AsciiString (PCDM_ReadWriter::*)() const ) &PCDM_ReadWriter::Version, "returns PCDM_ReadWriter_1.");
	cls_PCDM_ReadWriter.def("WriteReferenceCounter", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter.def("WriteReferences", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const ) &PCDM_ReadWriter::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
	cls_PCDM_ReadWriter.def("WriteExtensions", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter.def("WriteVersion", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter::ReadReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter.def("ReadReferences", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter.def("ReadExtensions", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter.def_static("Open_", (void (*)(Storage_BaseDriver &, const TCollection_ExtendedString &, const Storage_OpenMode)) &PCDM_ReadWriter::Open, "None", py::arg("aDriver"), py::arg("aFileName"), py::arg("anOpenMode"));
	cls_PCDM_ReadWriter.def_static("Reader_", (opencascade::handle<PCDM_ReadWriter> (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::Reader, "returns the convenient Reader for a File.", py::arg("aFileName"));
	cls_PCDM_ReadWriter.def_static("Writer_", (opencascade::handle<PCDM_ReadWriter> (*)()) &PCDM_ReadWriter::Writer, "None");
	cls_PCDM_ReadWriter.def_static("WriteFileFormat_", (void (*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &)) &PCDM_ReadWriter::WriteFileFormat, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::FileFormat, "tries to get a format in the file. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("aFileName"));
	cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &PCDM_ReadWriter::FileFormat, "tries to get a format from the stream. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("theIStream"), py::arg("theData"));
	cls_PCDM_ReadWriter.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter::get_type_name, "None");
	cls_PCDM_ReadWriter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter::get_type_descriptor, "None");
	cls_PCDM_ReadWriter.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter::*)() const ) &PCDM_ReadWriter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_ReadWriter_1.hxx
	py::class_<PCDM_ReadWriter_1, opencascade::handle<PCDM_ReadWriter_1>, PCDM_ReadWriter> cls_PCDM_ReadWriter_1(mod, "PCDM_ReadWriter_1", "None");
	cls_PCDM_ReadWriter_1.def(py::init<>());
	cls_PCDM_ReadWriter_1.def("Version", (TCollection_AsciiString (PCDM_ReadWriter_1::*)() const ) &PCDM_ReadWriter_1::Version, "returns PCDM_ReadWriter_1.");
	cls_PCDM_ReadWriter_1.def("WriteReferenceCounter", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter_1::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter_1.def("WriteReferences", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const ) &PCDM_ReadWriter_1::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
	cls_PCDM_ReadWriter_1.def("WriteExtensions", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter_1::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter_1.def("WriteVersion", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const ) &PCDM_ReadWriter_1::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
	cls_PCDM_ReadWriter_1.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter_1::ReadReferenceCounter, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter_1.def("ReadReferences", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter_1::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter_1.def("ReadExtensions", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter_1::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter_1.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MessageDriver> &) const ) &PCDM_ReadWriter_1::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
	cls_PCDM_ReadWriter_1.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter_1::get_type_name, "None");
	cls_PCDM_ReadWriter_1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter_1::get_type_descriptor, "None");
	cls_PCDM_ReadWriter_1.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter_1::*)() const ) &PCDM_ReadWriter_1::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<PCDM_SequenceOfReference, std::unique_ptr<PCDM_SequenceOfReference, Deleter<PCDM_SequenceOfReference>>, NCollection_BaseSequence> cls_PCDM_SequenceOfReference(mod, "PCDM_SequenceOfReference", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_PCDM_SequenceOfReference.def(py::init<>());
	cls_PCDM_SequenceOfReference.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_PCDM_SequenceOfReference.def(py::init([] (const PCDM_SequenceOfReference &other) {return new PCDM_SequenceOfReference(other);}), "Copy constructor", py::arg("other"));
	cls_PCDM_SequenceOfReference.def("begin", (PCDM_SequenceOfReference::iterator (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_PCDM_SequenceOfReference.def("end", (PCDM_SequenceOfReference::iterator (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_PCDM_SequenceOfReference.def("cbegin", (PCDM_SequenceOfReference::const_iterator (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_PCDM_SequenceOfReference.def("cend", (PCDM_SequenceOfReference::const_iterator (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_PCDM_SequenceOfReference.def("Size", (Standard_Integer (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::Size, "Number of items");
	cls_PCDM_SequenceOfReference.def("Length", (Standard_Integer (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::Length, "Number of items");
	cls_PCDM_SequenceOfReference.def("Lower", (Standard_Integer (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::Lower, "Method for consistency with other collections.");
	cls_PCDM_SequenceOfReference.def("Upper", (Standard_Integer (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::Upper, "Method for consistency with other collections.");
	cls_PCDM_SequenceOfReference.def("IsEmpty", (Standard_Boolean (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::IsEmpty, "Empty query");
	cls_PCDM_SequenceOfReference.def("Reverse", (void (PCDM_SequenceOfReference::*)()) &PCDM_SequenceOfReference::Reverse, "Reverse sequence");
	cls_PCDM_SequenceOfReference.def("Exchange", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, const Standard_Integer)) &PCDM_SequenceOfReference::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_PCDM_SequenceOfReference.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &PCDM_SequenceOfReference::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_PCDM_SequenceOfReference.def("Clear", [](PCDM_SequenceOfReference &self) -> void { return self.Clear(); });
	cls_PCDM_SequenceOfReference.def("Clear", (void (PCDM_SequenceOfReference::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &PCDM_SequenceOfReference::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_PCDM_SequenceOfReference.def("Assign", (PCDM_SequenceOfReference & (PCDM_SequenceOfReference::*)(const PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_PCDM_SequenceOfReference.def("assign", (PCDM_SequenceOfReference & (PCDM_SequenceOfReference::*)(const PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_PCDM_SequenceOfReference.def("Remove", (void (PCDM_SequenceOfReference::*)(PCDM_SequenceOfReference::Iterator &)) &PCDM_SequenceOfReference::Remove, "Remove one item", py::arg("thePosition"));
	cls_PCDM_SequenceOfReference.def("Remove", (void (PCDM_SequenceOfReference::*)(const Standard_Integer)) &PCDM_SequenceOfReference::Remove, "Remove one item", py::arg("theIndex"));
	cls_PCDM_SequenceOfReference.def("Remove", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, const Standard_Integer)) &PCDM_SequenceOfReference::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_PCDM_SequenceOfReference.def("Append", (void (PCDM_SequenceOfReference::*)(const PCDM_Reference &)) &PCDM_SequenceOfReference::Append, "Append one item", py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("Append", (void (PCDM_SequenceOfReference::*)(PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_PCDM_SequenceOfReference.def("Prepend", (void (PCDM_SequenceOfReference::*)(const PCDM_Reference &)) &PCDM_SequenceOfReference::Prepend, "Prepend one item", py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("Prepend", (void (PCDM_SequenceOfReference::*)(PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_PCDM_SequenceOfReference.def("InsertBefore", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, const PCDM_Reference &)) &PCDM_SequenceOfReference::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("InsertBefore", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfReference.def("InsertAfter", (void (PCDM_SequenceOfReference::*)(PCDM_SequenceOfReference::Iterator &, const PCDM_Reference &)) &PCDM_SequenceOfReference::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("InsertAfter", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfReference.def("InsertAfter", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, const PCDM_Reference &)) &PCDM_SequenceOfReference::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("Split", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, PCDM_SequenceOfReference &)) &PCDM_SequenceOfReference::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfReference.def("First", (const PCDM_Reference & (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::First, "First item access");
	cls_PCDM_SequenceOfReference.def("ChangeFirst", (PCDM_Reference & (PCDM_SequenceOfReference::*)()) &PCDM_SequenceOfReference::ChangeFirst, "First item access");
	cls_PCDM_SequenceOfReference.def("Last", (const PCDM_Reference & (PCDM_SequenceOfReference::*)() const ) &PCDM_SequenceOfReference::Last, "Last item access");
	cls_PCDM_SequenceOfReference.def("ChangeLast", (PCDM_Reference & (PCDM_SequenceOfReference::*)()) &PCDM_SequenceOfReference::ChangeLast, "Last item access");
	cls_PCDM_SequenceOfReference.def("Value", (const PCDM_Reference & (PCDM_SequenceOfReference::*)(const Standard_Integer) const ) &PCDM_SequenceOfReference::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_PCDM_SequenceOfReference.def("__call__", (const PCDM_Reference & (PCDM_SequenceOfReference::*)(const Standard_Integer) const ) &PCDM_SequenceOfReference::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_PCDM_SequenceOfReference.def("ChangeValue", (PCDM_Reference & (PCDM_SequenceOfReference::*)(const Standard_Integer)) &PCDM_SequenceOfReference::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_PCDM_SequenceOfReference.def("__call__", (PCDM_Reference & (PCDM_SequenceOfReference::*)(const Standard_Integer)) &PCDM_SequenceOfReference::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_PCDM_SequenceOfReference.def("SetValue", (void (PCDM_SequenceOfReference::*)(const Standard_Integer, const PCDM_Reference &)) &PCDM_SequenceOfReference::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfReference.def("__iter__", [](const PCDM_SequenceOfReference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<PCDM_SequenceOfDocument, std::unique_ptr<PCDM_SequenceOfDocument, Deleter<PCDM_SequenceOfDocument>>, NCollection_BaseSequence> cls_PCDM_SequenceOfDocument(mod, "PCDM_SequenceOfDocument", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_PCDM_SequenceOfDocument.def(py::init<>());
	cls_PCDM_SequenceOfDocument.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_PCDM_SequenceOfDocument.def(py::init([] (const PCDM_SequenceOfDocument &other) {return new PCDM_SequenceOfDocument(other);}), "Copy constructor", py::arg("other"));
	cls_PCDM_SequenceOfDocument.def("begin", (PCDM_SequenceOfDocument::iterator (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_PCDM_SequenceOfDocument.def("end", (PCDM_SequenceOfDocument::iterator (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_PCDM_SequenceOfDocument.def("cbegin", (PCDM_SequenceOfDocument::const_iterator (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_PCDM_SequenceOfDocument.def("cend", (PCDM_SequenceOfDocument::const_iterator (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_PCDM_SequenceOfDocument.def("Size", (Standard_Integer (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::Size, "Number of items");
	cls_PCDM_SequenceOfDocument.def("Length", (Standard_Integer (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::Length, "Number of items");
	cls_PCDM_SequenceOfDocument.def("Lower", (Standard_Integer (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::Lower, "Method for consistency with other collections.");
	cls_PCDM_SequenceOfDocument.def("Upper", (Standard_Integer (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::Upper, "Method for consistency with other collections.");
	cls_PCDM_SequenceOfDocument.def("IsEmpty", (Standard_Boolean (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::IsEmpty, "Empty query");
	cls_PCDM_SequenceOfDocument.def("Reverse", (void (PCDM_SequenceOfDocument::*)()) &PCDM_SequenceOfDocument::Reverse, "Reverse sequence");
	cls_PCDM_SequenceOfDocument.def("Exchange", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, const Standard_Integer)) &PCDM_SequenceOfDocument::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_PCDM_SequenceOfDocument.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &PCDM_SequenceOfDocument::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_PCDM_SequenceOfDocument.def("Clear", [](PCDM_SequenceOfDocument &self) -> void { return self.Clear(); });
	cls_PCDM_SequenceOfDocument.def("Clear", (void (PCDM_SequenceOfDocument::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &PCDM_SequenceOfDocument::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_PCDM_SequenceOfDocument.def("Assign", (PCDM_SequenceOfDocument & (PCDM_SequenceOfDocument::*)(const PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_PCDM_SequenceOfDocument.def("assign", (PCDM_SequenceOfDocument & (PCDM_SequenceOfDocument::*)(const PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_PCDM_SequenceOfDocument.def("Remove", (void (PCDM_SequenceOfDocument::*)(PCDM_SequenceOfDocument::Iterator &)) &PCDM_SequenceOfDocument::Remove, "Remove one item", py::arg("thePosition"));
	cls_PCDM_SequenceOfDocument.def("Remove", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer)) &PCDM_SequenceOfDocument::Remove, "Remove one item", py::arg("theIndex"));
	cls_PCDM_SequenceOfDocument.def("Remove", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, const Standard_Integer)) &PCDM_SequenceOfDocument::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_PCDM_SequenceOfDocument.def("Append", (void (PCDM_SequenceOfDocument::*)(const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::Append, "Append one item", py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("Append", (void (PCDM_SequenceOfDocument::*)(PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_PCDM_SequenceOfDocument.def("Prepend", (void (PCDM_SequenceOfDocument::*)(const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::Prepend, "Prepend one item", py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("Prepend", (void (PCDM_SequenceOfDocument::*)(PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_PCDM_SequenceOfDocument.def("InsertBefore", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("InsertBefore", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfDocument.def("InsertAfter", (void (PCDM_SequenceOfDocument::*)(PCDM_SequenceOfDocument::Iterator &, const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("InsertAfter", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfDocument.def("InsertAfter", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("Split", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, PCDM_SequenceOfDocument &)) &PCDM_SequenceOfDocument::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_PCDM_SequenceOfDocument.def("First", (const opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::First, "First item access");
	cls_PCDM_SequenceOfDocument.def("ChangeFirst", (opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)()) &PCDM_SequenceOfDocument::ChangeFirst, "First item access");
	cls_PCDM_SequenceOfDocument.def("Last", (const opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)() const ) &PCDM_SequenceOfDocument::Last, "Last item access");
	cls_PCDM_SequenceOfDocument.def("ChangeLast", (opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)()) &PCDM_SequenceOfDocument::ChangeLast, "Last item access");
	cls_PCDM_SequenceOfDocument.def("Value", (const opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)(const Standard_Integer) const ) &PCDM_SequenceOfDocument::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_PCDM_SequenceOfDocument.def("__call__", (const opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)(const Standard_Integer) const ) &PCDM_SequenceOfDocument::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_PCDM_SequenceOfDocument.def("ChangeValue", (opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)(const Standard_Integer)) &PCDM_SequenceOfDocument::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_PCDM_SequenceOfDocument.def("__call__", (opencascade::handle<PCDM_Document> & (PCDM_SequenceOfDocument::*)(const Standard_Integer)) &PCDM_SequenceOfDocument::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_PCDM_SequenceOfDocument.def("SetValue", (void (PCDM_SequenceOfDocument::*)(const Standard_Integer, const opencascade::handle<PCDM_Document> &)) &PCDM_SequenceOfDocument::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_PCDM_SequenceOfDocument.def("__iter__", [](const PCDM_SequenceOfDocument &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\PCDM_BaseDriverPointer.hxx

}
