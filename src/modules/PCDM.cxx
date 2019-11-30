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
#include <Storage_BaseDriver.hxx>
#include <Standard_IStream.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <PCDM_StoreStatus.hxx>
#include <PCDM_TypeOfFileDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Storage_Data.hxx>
#include <Standard_Std.hxx>
#include <PCDM_Reader.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_Reference.hxx>
#include <NCollection_Sequence.hxx>
#include <PCDM_SequenceOfReference.hxx>
#include <Message_Messenger.hxx>
#include <CDM_MetaData.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <Standard_OStream.hxx>
#include <PCDM_Writer.hxx>
#include <Standard_Persistent.hxx>
#include <PCDM_Document.hxx>
#include <PCDM_SequenceOfDocument.hxx>
#include <PCDM_StorageDriver.hxx>
#include <PCDM_BaseDriverPointer.hxx>
#include <TCollection_AsciiString.hxx>
#include <PCDM.hxx>
#include <LDOMParser.hxx>
#include <LDOM_Element.hxx>
#include <LDOMString.hxx>
#include <PCDM_DOMHeaderParser.hxx>
#include <Standard_Failure.hxx>
#include <PCDM_DriverError.hxx>
#include <Standard_SStream.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_OpenMode.hxx>
#include <PCDM_ReadWriter.hxx>
#include <PCDM_ReadWriter_1.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(PCDM, mod) {

py::module::import("OCCT.Storage");
py::module::import("OCCT.Standard");
py::module::import("OCCT.CDM");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.LDOMParser");
py::module::import("OCCT.LDOM");
py::module::import("OCCT.LDOMString");
py::module::import("OCCT.TColStd");

// ENUM: PCDM_READERSTATUS
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


// ENUM: PCDM_STORESTATUS
py::enum_<PCDM_StoreStatus>(mod, "PCDM_StoreStatus", "None")
	.value("PCDM_SS_OK", PCDM_StoreStatus::PCDM_SS_OK)
	.value("PCDM_SS_DriverFailure", PCDM_StoreStatus::PCDM_SS_DriverFailure)
	.value("PCDM_SS_WriteFailure", PCDM_StoreStatus::PCDM_SS_WriteFailure)
	.value("PCDM_SS_Failure", PCDM_StoreStatus::PCDM_SS_Failure)
	.value("PCDM_SS_Doc_IsNull", PCDM_StoreStatus::PCDM_SS_Doc_IsNull)
	.value("PCDM_SS_No_Obj", PCDM_StoreStatus::PCDM_SS_No_Obj)
	.value("PCDM_SS_Info_Section_Error", PCDM_StoreStatus::PCDM_SS_Info_Section_Error)
	.export_values();


// ENUM: PCDM_TYPEOFFILEDRIVER
py::enum_<PCDM_TypeOfFileDriver>(mod, "PCDM_TypeOfFileDriver", "None")
	.value("PCDM_TOFD_File", PCDM_TypeOfFileDriver::PCDM_TOFD_File)
	.value("PCDM_TOFD_CmpFile", PCDM_TypeOfFileDriver::PCDM_TOFD_CmpFile)
	.value("PCDM_TOFD_XmlFile", PCDM_TypeOfFileDriver::PCDM_TOFD_XmlFile)
	.value("PCDM_TOFD_Unknown", PCDM_TypeOfFileDriver::PCDM_TOFD_Unknown)
	.export_values();


// CLASS: PCDM_READER
py::class_<PCDM_Reader, opencascade::handle<PCDM_Reader>, Standard_Transient> cls_PCDM_Reader(mod, "PCDM_Reader", "None");

// Methods
cls_PCDM_Reader.def("CreateDocument", (opencascade::handle<CDM_Document> (PCDM_Reader::*)()) &PCDM_Reader::CreateDocument, "this method is called by the framework before the read method.");
cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "retrieves the content of the file into a new Document.", py::arg("aFileName"), py::arg("aNewDocument"), py::arg("anApplication"));
cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
cls_PCDM_Reader.def("GetStatus", (PCDM_ReaderStatus (PCDM_Reader::*)() const) &PCDM_Reader::GetStatus, "None");
cls_PCDM_Reader.def_static("get_type_name_", (const char * (*)()) &PCDM_Reader::get_type_name, "None");
cls_PCDM_Reader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Reader::get_type_descriptor, "None");
cls_PCDM_Reader.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Reader::*)() const) &PCDM_Reader::DynamicType, "None");

// CLASS: PCDM_REFERENCE
py::class_<PCDM_Reference> cls_PCDM_Reference(mod, "PCDM_Reference", "None");

// Constructors
cls_PCDM_Reference.def(py::init<>());
cls_PCDM_Reference.def(py::init<const Standard_Integer, const TCollection_ExtendedString &, const Standard_Integer>(), py::arg("aReferenceIdentifier"), py::arg("aFileName"), py::arg("aDocumentVersion"));

// Methods
// cls_PCDM_Reference.def_static("operator new_", (void * (*)(size_t)) &PCDM_Reference::operator new, "None", py::arg("theSize"));
// cls_PCDM_Reference.def_static("operator delete_", (void (*)(void *)) &PCDM_Reference::operator delete, "None", py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator new[]_", (void * (*)(size_t)) &PCDM_Reference::operator new[], "None", py::arg("theSize"));
// cls_PCDM_Reference.def_static("operator delete[]_", (void (*)(void *)) &PCDM_Reference::operator delete[], "None", py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator new_", (void * (*)(size_t, void *)) &PCDM_Reference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PCDM_Reference.def_static("operator delete_", (void (*)(void *, void *)) &PCDM_Reference::operator delete, "None", py::arg(""), py::arg(""));
cls_PCDM_Reference.def("ReferenceIdentifier", (Standard_Integer (PCDM_Reference::*)() const) &PCDM_Reference::ReferenceIdentifier, "None");
cls_PCDM_Reference.def("FileName", (TCollection_ExtendedString (PCDM_Reference::*)() const) &PCDM_Reference::FileName, "None");
cls_PCDM_Reference.def("DocumentVersion", (Standard_Integer (PCDM_Reference::*)() const) &PCDM_Reference::DocumentVersion, "None");

// TYPEDEF: PCDM_SEQUENCEOFREFERENCE
bind_NCollection_Sequence<PCDM_Reference>(mod, "PCDM_SequenceOfReference", py::module_local(false));

// CLASS: PCDM_REFERENCEITERATOR
py::class_<PCDM_ReferenceIterator, opencascade::handle<PCDM_ReferenceIterator>, Standard_Transient> cls_PCDM_ReferenceIterator(mod, "PCDM_ReferenceIterator", "None");

// Constructors
cls_PCDM_ReferenceIterator.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Methods
cls_PCDM_ReferenceIterator.def("LoadReferences", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_Application> &, const Standard_Boolean)) &PCDM_ReferenceIterator::LoadReferences, "None", py::arg("aDocument"), py::arg("aMetaData"), py::arg("anApplication"), py::arg("UseStorageConfiguration"));
cls_PCDM_ReferenceIterator.def("Init", (void (PCDM_ReferenceIterator::*)(const opencascade::handle<CDM_MetaData> &)) &PCDM_ReferenceIterator::Init, "None", py::arg("aMetaData"));
cls_PCDM_ReferenceIterator.def_static("get_type_name_", (const char * (*)()) &PCDM_ReferenceIterator::get_type_name, "None");
cls_PCDM_ReferenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReferenceIterator::get_type_descriptor, "None");
cls_PCDM_ReferenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReferenceIterator::*)() const) &PCDM_ReferenceIterator::DynamicType, "None");

// CLASS: PCDM_RETRIEVALDRIVER
py::class_<PCDM_RetrievalDriver, opencascade::handle<PCDM_RetrievalDriver>, PCDM_Reader> cls_PCDM_RetrievalDriver(mod, "PCDM_RetrievalDriver", "None");

// Methods
cls_PCDM_RetrievalDriver.def_static("DocumentVersion_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &)) &PCDM_RetrievalDriver::DocumentVersion, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_RetrievalDriver.def_static("ReferenceCounter_", (Standard_Integer (*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &)) &PCDM_RetrievalDriver::ReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_RetrievalDriver.def("SetFormat", (void (PCDM_RetrievalDriver::*)(const TCollection_ExtendedString &)) &PCDM_RetrievalDriver::SetFormat, "None", py::arg("aformat"));
cls_PCDM_RetrievalDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_RetrievalDriver::*)() const) &PCDM_RetrievalDriver::GetFormat, "None");
cls_PCDM_RetrievalDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_RetrievalDriver::get_type_name, "None");
cls_PCDM_RetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_RetrievalDriver::get_type_descriptor, "None");
cls_PCDM_RetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_RetrievalDriver::*)() const) &PCDM_RetrievalDriver::DynamicType, "None");

// CLASS: PCDM_WRITER
py::class_<PCDM_Writer, opencascade::handle<PCDM_Writer>, Standard_Transient> cls_PCDM_Writer(mod, "PCDM_Writer", "None");

// Methods
cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_Writer::Write, "None", py::arg("aDocument"), py::arg("aFileName"));
cls_PCDM_Writer.def("Write", (void (PCDM_Writer::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_Writer::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
cls_PCDM_Writer.def_static("get_type_name_", (const char * (*)()) &PCDM_Writer::get_type_name, "None");
cls_PCDM_Writer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Writer::get_type_descriptor, "None");
cls_PCDM_Writer.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Writer::*)() const) &PCDM_Writer::DynamicType, "None");

// CLASS: PCDM_DOCUMENT
py::class_<PCDM_Document, opencascade::handle<PCDM_Document>, Standard_Persistent> cls_PCDM_Document(mod, "PCDM_Document", "None");

// Constructors
cls_PCDM_Document.def(py::init<>());

// Methods
cls_PCDM_Document.def_static("get_type_name_", (const char * (*)()) &PCDM_Document::get_type_name, "None");
cls_PCDM_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Document::get_type_descriptor, "None");
cls_PCDM_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Document::*)() const) &PCDM_Document::DynamicType, "None");

// TYPEDEF: PCDM_SEQUENCEOFDOCUMENT
bind_NCollection_Sequence<opencascade::handle<PCDM_Document> >(mod, "PCDM_SequenceOfDocument", py::module_local(false));

// CLASS: PCDM_STORAGEDRIVER
py::class_<PCDM_StorageDriver, opencascade::handle<PCDM_StorageDriver>, PCDM_Writer> cls_PCDM_StorageDriver(mod, "PCDM_StorageDriver", "persistent implemention of storage.");

// Constructors
cls_PCDM_StorageDriver.def(py::init<>());

// Methods
cls_PCDM_StorageDriver.def("Make", (opencascade::handle<PCDM_Document> (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &)) &PCDM_StorageDriver::Make, "raises NotImplemented.", py::arg("aDocument"));
cls_PCDM_StorageDriver.def("Make", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, PCDM_SequenceOfDocument &)) &PCDM_StorageDriver::Make, "By default, puts in the Sequence the document returns by the previous Make method.", py::arg("aDocument"), py::arg("Documents"));
cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_StorageDriver::Write, "Warning! raises DriverError if an error occurs during inside the Make method. stores the content of the Document into a new file.", py::arg("aDocument"), py::arg("aFileName"));
cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_StorageDriver::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
cls_PCDM_StorageDriver.def("SetFormat", (void (PCDM_StorageDriver::*)(const TCollection_ExtendedString &)) &PCDM_StorageDriver::SetFormat, "None", py::arg("aformat"));
cls_PCDM_StorageDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::GetFormat, "None");
cls_PCDM_StorageDriver.def("IsError", (Standard_Boolean (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::IsError, "None");
cls_PCDM_StorageDriver.def("SetIsError", (void (PCDM_StorageDriver::*)(const Standard_Boolean)) &PCDM_StorageDriver::SetIsError, "None", py::arg("theIsError"));
cls_PCDM_StorageDriver.def("GetStoreStatus", (PCDM_StoreStatus (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::GetStoreStatus, "None");
cls_PCDM_StorageDriver.def("SetStoreStatus", (void (PCDM_StorageDriver::*)(const PCDM_StoreStatus)) &PCDM_StorageDriver::SetStoreStatus, "None", py::arg("theStoreStatus"));
cls_PCDM_StorageDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_StorageDriver::get_type_name, "None");
cls_PCDM_StorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_StorageDriver::get_type_descriptor, "None");
cls_PCDM_StorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::DynamicType, "None");

// TYPEDEF: PCDM_BASEDRIVERPOINTER

// CLASS: PCDM
py::class_<PCDM> cls_PCDM(mod, "PCDM", "None");

// Constructors
cls_PCDM.def(py::init<>());

// Methods
// cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(const TCollection_AsciiString &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("aFileName"), py::arg("aBaseDriver"));
// cls_PCDM.def_static("FileDriverType_", (PCDM_TypeOfFileDriver (*)(Standard_IStream &, PCDM_BaseDriverPointer &)) &PCDM::FileDriverType, "None", py::arg("theIStream"), py::arg("theBaseDriver"));
// cls_PCDM.def_static("operator new_", (void * (*)(size_t)) &PCDM::operator new, "None", py::arg("theSize"));
// cls_PCDM.def_static("operator delete_", (void (*)(void *)) &PCDM::operator delete, "None", py::arg("theAddress"));
// cls_PCDM.def_static("operator new[]_", (void * (*)(size_t)) &PCDM::operator new[], "None", py::arg("theSize"));
// cls_PCDM.def_static("operator delete[]_", (void (*)(void *)) &PCDM::operator delete[], "None", py::arg("theAddress"));
// cls_PCDM.def_static("operator new_", (void * (*)(size_t, void *)) &PCDM::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PCDM.def_static("operator delete_", (void (*)(void *, void *)) &PCDM::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: PCDM_DOMHEADERPARSER
py::class_<PCDM_DOMHeaderParser, LDOMParser> cls_PCDM_DOMHeaderParser(mod, "PCDM_DOMHeaderParser", "None");

// Constructors
cls_PCDM_DOMHeaderParser.def(py::init<>());

// Methods
// cls_PCDM_DOMHeaderParser.def("SetStartElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetStartElementName, "None", py::arg("aStartElementName"));
// cls_PCDM_DOMHeaderParser.def("SetEndElementName", (void (PCDM_DOMHeaderParser::*)(const TCollection_AsciiString &)) &PCDM_DOMHeaderParser::SetEndElementName, "None", py::arg("anEndElementName"));
cls_PCDM_DOMHeaderParser.def("startElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::startElement, "None");
cls_PCDM_DOMHeaderParser.def("endElement", (Standard_Boolean (PCDM_DOMHeaderParser::*)()) &PCDM_DOMHeaderParser::endElement, "None");
cls_PCDM_DOMHeaderParser.def("GetElement", (const LDOM_Element & (PCDM_DOMHeaderParser::*)() const) &PCDM_DOMHeaderParser::GetElement, "None");

// CLASS: PCDM_DRIVERERROR
py::class_<PCDM_DriverError, opencascade::handle<PCDM_DriverError>, Standard_Failure> cls_PCDM_DriverError(mod, "PCDM_DriverError", "None");

// Constructors
cls_PCDM_DriverError.def(py::init<>());
cls_PCDM_DriverError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_PCDM_DriverError.def_static("Raise_", (void (*)(const Standard_CString)) &PCDM_DriverError::Raise, "None", py::arg("theMessage"));
cls_PCDM_DriverError.def_static("Raise_", (void (*)(Standard_SStream &)) &PCDM_DriverError::Raise, "None", py::arg("theMessage"));
cls_PCDM_DriverError.def_static("NewInstance_", (opencascade::handle<PCDM_DriverError> (*)(const Standard_CString)) &PCDM_DriverError::NewInstance, "None", py::arg("theMessage"));
cls_PCDM_DriverError.def_static("get_type_name_", (const char * (*)()) &PCDM_DriverError::get_type_name, "None");
cls_PCDM_DriverError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_DriverError::get_type_descriptor, "None");
cls_PCDM_DriverError.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_DriverError::*)() const) &PCDM_DriverError::DynamicType, "None");

// CLASS: PCDM_READWRITER
py::class_<PCDM_ReadWriter, opencascade::handle<PCDM_ReadWriter>, Standard_Transient> cls_PCDM_ReadWriter(mod, "PCDM_ReadWriter", "None");

// Methods
cls_PCDM_ReadWriter.def("Version", (TCollection_AsciiString (PCDM_ReadWriter::*)() const) &PCDM_ReadWriter::Version, "returns PCDM_ReadWriter_1.");
cls_PCDM_ReadWriter.def("WriteReferenceCounter", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("WriteReferences", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const) &PCDM_ReadWriter::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
cls_PCDM_ReadWriter.def("WriteExtensions", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("WriteVersion", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadReferences", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadExtensions", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def_static("Open_", (void (*)(Storage_BaseDriver &, const TCollection_ExtendedString &, const Storage_OpenMode)) &PCDM_ReadWriter::Open, "None", py::arg("aDriver"), py::arg("aFileName"), py::arg("anOpenMode"));
cls_PCDM_ReadWriter.def_static("Reader_", (opencascade::handle<PCDM_ReadWriter> (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::Reader, "returns the convenient Reader for a File.", py::arg("aFileName"));
cls_PCDM_ReadWriter.def_static("Writer_", (opencascade::handle<PCDM_ReadWriter> (*)()) &PCDM_ReadWriter::Writer, "None");
cls_PCDM_ReadWriter.def_static("WriteFileFormat_", (void (*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &)) &PCDM_ReadWriter::WriteFileFormat, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::FileFormat, "tries to get a format in the file. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("aFileName"));
cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &PCDM_ReadWriter::FileFormat, "tries to get a format from the stream. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("theIStream"), py::arg("theData"));
cls_PCDM_ReadWriter.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter::get_type_name, "None");
cls_PCDM_ReadWriter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter::get_type_descriptor, "None");
cls_PCDM_ReadWriter.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter::*)() const) &PCDM_ReadWriter::DynamicType, "None");

// CLASS: PCDM_READWRITER_1
py::class_<PCDM_ReadWriter_1, opencascade::handle<PCDM_ReadWriter_1>, PCDM_ReadWriter> cls_PCDM_ReadWriter_1(mod, "PCDM_ReadWriter_1", "None");

// Constructors
cls_PCDM_ReadWriter_1.def(py::init<>());

// Methods
cls_PCDM_ReadWriter_1.def("Version", (TCollection_AsciiString (PCDM_ReadWriter_1::*)() const) &PCDM_ReadWriter_1::Version, "returns PCDM_ReadWriter_1.");
cls_PCDM_ReadWriter_1.def("WriteReferenceCounter", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("WriteReferences", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const) &PCDM_ReadWriter_1::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
cls_PCDM_ReadWriter_1.def("WriteExtensions", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("WriteVersion", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadReferenceCounter, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadReferences", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadExtensions", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter_1::get_type_name, "None");
cls_PCDM_ReadWriter_1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter_1::get_type_descriptor, "None");
cls_PCDM_ReadWriter_1.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter_1::*)() const) &PCDM_ReadWriter_1::DynamicType, "None");


}
