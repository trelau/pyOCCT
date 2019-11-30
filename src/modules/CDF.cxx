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
#include <CDF_TypeOfActivation.hxx>
#include <CDF_TryStoreStatus.hxx>
#include <CDF_StoreSetNameStatus.hxx>
#include <CDF_SubComponentStatus.hxx>
#include <CDM_Application.hxx>
#include <Standard_Handle.hxx>
#include <CDF_Application.hxx>
#include <Standard_GUID.hxx>
#include <CDM_Document.hxx>
#include <CDM_CanCloseStatus.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <Standard_IStream.hxx>
#include <PCDM_Reader.hxx>
#include <PCDM_StorageDriver.hxx>
#include <CDF_Session.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <CDM_MetaData.hxx>
#include <CDF.hxx>
#include <Standard_Transient.hxx>
#include <CDF_DirectoryIterator.hxx>
#include <CDF_Directory.hxx>
#include <CDM_ListOfDocument.hxx>
#include <Standard.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <CDF_MetaDataDriver.hxx>
#include <CDF_FWOSDriver.hxx>
#include <Standard_Failure.hxx>
#include <CDF_MetaDataDriverError.hxx>
#include <Standard_SStream.hxx>
#include <CDF_MetaDataDriverFactory.hxx>
#include <PCDM_StoreStatus.hxx>
#include <CDF_StoreList.hxx>
#include <CDF_Store.hxx>
#include <CDM_MapOfDocument.hxx>

PYBIND11_MODULE(CDF, mod) {

py::module::import("OCCT.CDM");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.PCDM");
py::module::import("OCCT.NCollection");

// ENUM: CDF_TYPEOFACTIVATION
py::enum_<CDF_TypeOfActivation>(mod, "CDF_TypeOfActivation", "None")
	.value("CDF_TOA_New", CDF_TypeOfActivation::CDF_TOA_New)
	.value("CDF_TOA_Modified", CDF_TypeOfActivation::CDF_TOA_Modified)
	.value("CDF_TOA_Unchanged", CDF_TypeOfActivation::CDF_TOA_Unchanged)
	.export_values();


// ENUM: CDF_TRYSTORESTATUS
py::enum_<CDF_TryStoreStatus>(mod, "CDF_TryStoreStatus", "None")
	.value("CDF_TS_OK", CDF_TryStoreStatus::CDF_TS_OK)
	.value("CDF_TS_NoCurrentDocument", CDF_TryStoreStatus::CDF_TS_NoCurrentDocument)
	.value("CDF_TS_NoDriver", CDF_TryStoreStatus::CDF_TS_NoDriver)
	.value("CDF_TS_NoSubComponentDriver", CDF_TryStoreStatus::CDF_TS_NoSubComponentDriver)
	.export_values();


// ENUM: CDF_STORESETNAMESTATUS
py::enum_<CDF_StoreSetNameStatus>(mod, "CDF_StoreSetNameStatus", "None")
	.value("CDF_SSNS_OK", CDF_StoreSetNameStatus::CDF_SSNS_OK)
	.value("CDF_SSNS_ReplacingAnExistentDocument", CDF_StoreSetNameStatus::CDF_SSNS_ReplacingAnExistentDocument)
	.value("CDF_SSNS_OpenDocument", CDF_StoreSetNameStatus::CDF_SSNS_OpenDocument)
	.export_values();


// ENUM: CDF_SUBCOMPONENTSTATUS
py::enum_<CDF_SubComponentStatus>(mod, "CDF_SubComponentStatus", "None")
	.value("CDF_SCS_Consistent", CDF_SubComponentStatus::CDF_SCS_Consistent)
	.value("CDF_SCS_Unconsistent", CDF_SubComponentStatus::CDF_SCS_Unconsistent)
	.value("CDF_SCS_Stored", CDF_SubComponentStatus::CDF_SCS_Stored)
	.value("CDF_SCS_Modified", CDF_SubComponentStatus::CDF_SCS_Modified)
	.export_values();


// CLASS: CDF_APPLICATION
py::class_<CDF_Application, opencascade::handle<CDF_Application>, CDM_Application> cls_CDF_Application(mod, "CDF_Application", "None");

// Methods
cls_CDF_Application.def_static("Load_", (opencascade::handle<CDF_Application> (*)(const Standard_GUID &)) &CDF_Application::Load, "plugs an application.", py::arg("aGUID"));
cls_CDF_Application.def("Open", (void (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::Open, "puts the document in the current session directory and calls the virtual method Activate on it.", py::arg("aDocument"));
cls_CDF_Application.def("CanClose", (CDM_CanCloseStatus (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::CanClose, "None", py::arg("aDocument"));
cls_CDF_Application.def("Close", (void (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::Close, "removes the document of the current session directory and closes the document;", py::arg("aDocument"));
cls_CDF_Application.def("Retrieve", [](CDF_Application &self, const TCollection_ExtendedString & a0, const TCollection_ExtendedString & a1) -> opencascade::handle<CDM_Document> { return self.Retrieve(a0, a1); });
cls_CDF_Application.def("Retrieve", (opencascade::handle<CDM_Document> (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDF_Application::Retrieve, "This method retrieves a document from the database. If the Document references other documents which have been updated, the latest version of these documents will be used if {UseStorageConfiguration} is Standard_True. The content of {aFolder}, {aName} and {aVersion} depends on the Database Manager system. If the DBMS is only based on the OS, {aFolder} is a directory and {aName} is the name of a file. In this case the use of the syntax with {aVersion} has no sense. For example:", py::arg("aFolder"), py::arg("aName"), py::arg("UseStorageConfiguration"));
cls_CDF_Application.def("Retrieve", [](CDF_Application &self, const TCollection_ExtendedString & a0, const TCollection_ExtendedString & a1, const TCollection_ExtendedString & a2) -> opencascade::handle<CDM_Document> { return self.Retrieve(a0, a1, a2); });
cls_CDF_Application.def("Retrieve", (opencascade::handle<CDM_Document> (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDF_Application::Retrieve, "This method retrieves a document from the database. If the Document references other documents which have been updated, the latest version of these documents will be used if {UseStorageConfiguration} is Standard_True. -- If the DBMS is only based on the OS, this syntax should not be used.", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"), py::arg("UseStorageConfiguration"));
cls_CDF_Application.def("CanRetrieve", (PCDM_ReaderStatus (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_Application::CanRetrieve, "None", py::arg("aFolder"), py::arg("aName"));
cls_CDF_Application.def("CanRetrieve", (PCDM_ReaderStatus (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_Application::CanRetrieve, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_Application.def("GetRetrieveStatus", (PCDM_ReaderStatus (CDF_Application::*)() const) &CDF_Application::GetRetrieveStatus, "Checks status after Retrieve");
cls_CDF_Application.def("Read", (opencascade::handle<CDM_Document> (CDF_Application::*)(Standard_IStream &)) &CDF_Application::Read, "Reads aDoc from standard SEEKABLE stream theIStream, the stream should support SEEK fuctionality", py::arg("theIStream"));
cls_CDF_Application.def("ReaderFromFormat", (opencascade::handle<PCDM_Reader> (CDF_Application::*)(const TCollection_ExtendedString &)) &CDF_Application::ReaderFromFormat, "Returns instance of read driver for specified format.", py::arg("aFormat"));
cls_CDF_Application.def("WriterFromFormat", (opencascade::handle<PCDM_StorageDriver> (CDF_Application::*)(const TCollection_ExtendedString &)) &CDF_Application::WriterFromFormat, "Returns instance of storage driver for specified format.", py::arg("aFormat"));
cls_CDF_Application.def("Format", (Standard_Boolean (CDF_Application::*)(const TCollection_ExtendedString &, TCollection_ExtendedString &)) &CDF_Application::Format, "try to retrieve a Format directly in the file or in application resource by using extension. returns True if found;", py::arg("aFileName"), py::arg("theFormat"));
cls_CDF_Application.def("DefaultFolder", (Standard_ExtString (CDF_Application::*)()) &CDF_Application::DefaultFolder, "None");
cls_CDF_Application.def("SetDefaultFolder", (Standard_Boolean (CDF_Application::*)(const Standard_ExtString)) &CDF_Application::SetDefaultFolder, "None", py::arg("aFolder"));
cls_CDF_Application.def_static("get_type_name_", (const char * (*)()) &CDF_Application::get_type_name, "None");
cls_CDF_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Application::get_type_descriptor, "None");
cls_CDF_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Application::*)() const) &CDF_Application::DynamicType, "None");

// CLASS: CDF
py::class_<CDF> cls_CDF(mod, "CDF", "None");

// Methods
cls_CDF.def_static("GetLicense_", (void (*)(const Standard_Integer)) &CDF::GetLicense, "None", py::arg("anApplicationIdentifier"));
cls_CDF.def_static("IsAvailable_", (Standard_Boolean (*)(const Standard_Integer)) &CDF::IsAvailable, "None", py::arg("anApplicationIdentifier"));

// CLASS: CDF_DIRECTORY
py::class_<CDF_Directory, opencascade::handle<CDF_Directory>, Standard_Transient> cls_CDF_Directory(mod, "CDF_Directory", "A directory is a collection of documents. There is only one instance of a given document in a directory. put.");

// Constructors
cls_CDF_Directory.def(py::init<>());

// Methods
cls_CDF_Directory.def("Add", (void (CDF_Directory::*)(const opencascade::handle<CDM_Document> &)) &CDF_Directory::Add, "adds a document into the directory.", py::arg("aDocument"));
cls_CDF_Directory.def("Remove", (void (CDF_Directory::*)(const opencascade::handle<CDM_Document> &)) &CDF_Directory::Remove, "removes the document.", py::arg("aDocument"));
cls_CDF_Directory.def("Contains", (Standard_Boolean (CDF_Directory::*)(const opencascade::handle<CDM_Document> &) const) &CDF_Directory::Contains, "Returns true if the document aDocument is in the directory", py::arg("aDocument"));
cls_CDF_Directory.def("Last", (opencascade::handle<CDM_Document> (CDF_Directory::*)()) &CDF_Directory::Last, "returns the last document (if any) which has been added in the directory.");
cls_CDF_Directory.def("Length", (Standard_Integer (CDF_Directory::*)() const) &CDF_Directory::Length, "returns the number of documents of the directory.");
cls_CDF_Directory.def("IsEmpty", (Standard_Boolean (CDF_Directory::*)() const) &CDF_Directory::IsEmpty, "returns true if the directory is empty.");
cls_CDF_Directory.def_static("get_type_name_", (const char * (*)()) &CDF_Directory::get_type_name, "None");
cls_CDF_Directory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Directory::get_type_descriptor, "None");
cls_CDF_Directory.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Directory::*)() const) &CDF_Directory::DynamicType, "None");

// CLASS: CDF_DIRECTORYITERATOR
py::class_<CDF_DirectoryIterator> cls_CDF_DirectoryIterator(mod, "CDF_DirectoryIterator", "None");

// Constructors
cls_CDF_DirectoryIterator.def(py::init<>());
cls_CDF_DirectoryIterator.def(py::init<const opencascade::handle<CDF_Directory> &>(), py::arg("aDirectory"));

// Methods
// cls_CDF_DirectoryIterator.def_static("operator new_", (void * (*)(size_t)) &CDF_DirectoryIterator::operator new, "None", py::arg("theSize"));
// cls_CDF_DirectoryIterator.def_static("operator delete_", (void (*)(void *)) &CDF_DirectoryIterator::operator delete, "None", py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator new[]_", (void * (*)(size_t)) &CDF_DirectoryIterator::operator new[], "None", py::arg("theSize"));
// cls_CDF_DirectoryIterator.def_static("operator delete[]_", (void (*)(void *)) &CDF_DirectoryIterator::operator delete[], "None", py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator new_", (void * (*)(size_t, void *)) &CDF_DirectoryIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CDF_DirectoryIterator.def_static("operator delete_", (void (*)(void *, void *)) &CDF_DirectoryIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_CDF_DirectoryIterator.def("MoreDocument", (Standard_Boolean (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::MoreDocument, "Returns True if there are more entries to return");
cls_CDF_DirectoryIterator.def("NextDocument", (void (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::NextDocument, "Go to the next entry (if there is not, Value will raise an exception)");
cls_CDF_DirectoryIterator.def("Document", (opencascade::handle<CDM_Document> (CDF_DirectoryIterator::*)()) &CDF_DirectoryIterator::Document, "Returns item value of current entry");

// CLASS: CDF_METADATADRIVER
py::class_<CDF_MetaDataDriver, opencascade::handle<CDF_MetaDataDriver>, Standard_Transient> cls_CDF_MetaDataDriver(mod, "CDF_MetaDataDriver", "this class list the method that must be available for a specific DBMS");

// Methods
cls_CDF_MetaDataDriver.def("HasVersionCapability", (Standard_Boolean (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::HasVersionCapability, "returns true if the MetaDataDriver can manage different versions of a Data. By default, returns Standard_False.");
cls_CDF_MetaDataDriver.def("CreateDependsOn", (void (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_MetaData> &)) &CDF_MetaDataDriver::CreateDependsOn, "Creates a 'Depends On' relation between two Datas. By default does nothing", py::arg("aFirstData"), py::arg("aSecondData"));
cls_CDF_MetaDataDriver.def("CreateReference", (void (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_MetaData> &, const Standard_Integer, const Standard_Integer)) &CDF_MetaDataDriver::CreateReference, "None", py::arg("aFrom"), py::arg("aTo"), py::arg("aReferenceIdentifier"), py::arg("aToDocumentVersion"));
cls_CDF_MetaDataDriver.def("HasVersion", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::HasVersion, "by default return Standard_True.", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("BuildFileName", (TCollection_ExtendedString (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &)) &CDF_MetaDataDriver::BuildFileName, "None", py::arg("aDocument"));
cls_CDF_MetaDataDriver.def("SetName", (TCollection_ExtendedString (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::SetName, "this methods is usefull if the name of an object -- depends on the metadatadriver. For example a Driver -- based on the operating system can choose to add the extension of file to create to the object.", py::arg("aDocument"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("Find", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::Find, "should indicate whether meta-data exist in the DBMS corresponding to the Data. aVersion may be NULL;", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("HasReadPermission", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::HasReadPermission, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("MetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::MetaData, "should return the MetaData stored in the DBMS with the meta-data corresponding to the Data. If the MetaDataDriver has version management capabilities the version has to be set in the returned MetaData. aVersion may be NULL MetaData is called by GetMetaData If the version is set to NULL, MetaData should return the last version of the metadata", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("LastVersion", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &)) &CDF_MetaDataDriver::LastVersion, "by default returns aMetaDATA should return the MetaData stored in the DBMS with the meta-data corresponding to the path. If the MetaDataDriver has version management capabilities the version has to be set in the returned MetaData. MetaData is called by GetMetaData If the version is not included in the path , MetaData should return the last version of the metadata is deferred;", py::arg("aMetaData"));
cls_CDF_MetaDataDriver.def("CreateMetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::CreateMetaData, "should create meta-data corresponding to aData and maintaining a meta-link between these meta-data and aFileName CreateMetaData is called by CreateData If the metadata-driver has version capabilities, version must be set in the returned Data.", py::arg("aDocument"), py::arg("aFileName"));
cls_CDF_MetaDataDriver.def("FindFolder", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &)) &CDF_MetaDataDriver::FindFolder, "None", py::arg("aFolder"));
cls_CDF_MetaDataDriver.def("DefaultFolder", (TCollection_ExtendedString (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::DefaultFolder, "None");
cls_CDF_MetaDataDriver.def("ReferenceIterator", (opencascade::handle<PCDM_ReferenceIterator> (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::ReferenceIterator, "None");
cls_CDF_MetaDataDriver.def("Find", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::Find, "calls Find with an empty version", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("MetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::MetaData, "calls MetaData with an empty version", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def_static("get_type_name_", (const char * (*)()) &CDF_MetaDataDriver::get_type_name, "None");
cls_CDF_MetaDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_MetaDataDriver::get_type_descriptor, "None");
cls_CDF_MetaDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_MetaDataDriver::*)() const) &CDF_MetaDataDriver::DynamicType, "None");

// CLASS: CDF_FWOSDRIVER
py::class_<CDF_FWOSDriver, opencascade::handle<CDF_FWOSDriver>, CDF_MetaDataDriver> cls_CDF_FWOSDriver(mod, "CDF_FWOSDriver", "None");

// Constructors
cls_CDF_FWOSDriver.def(py::init<>());

// Methods
cls_CDF_FWOSDriver.def("Find", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::Find, "indicate whether a file exists corresponding to the folder and the name", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_FWOSDriver.def("HasReadPermission", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::HasReadPermission, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_FWOSDriver.def("FindFolder", (Standard_Boolean (CDF_FWOSDriver::*)(const TCollection_ExtendedString &)) &CDF_FWOSDriver::FindFolder, "None", py::arg("aFolder"));
cls_CDF_FWOSDriver.def("DefaultFolder", (TCollection_ExtendedString (CDF_FWOSDriver::*)()) &CDF_FWOSDriver::DefaultFolder, "None");
cls_CDF_FWOSDriver.def("BuildFileName", (TCollection_ExtendedString (CDF_FWOSDriver::*)(const opencascade::handle<CDM_Document> &)) &CDF_FWOSDriver::BuildFileName, "None", py::arg("aDocument"));
cls_CDF_FWOSDriver.def("SetName", (TCollection_ExtendedString (CDF_FWOSDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_FWOSDriver::SetName, "None", py::arg("aDocument"), py::arg("aName"));
cls_CDF_FWOSDriver.def_static("get_type_name_", (const char * (*)()) &CDF_FWOSDriver::get_type_name, "None");
cls_CDF_FWOSDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_FWOSDriver::get_type_descriptor, "None");
cls_CDF_FWOSDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_FWOSDriver::*)() const) &CDF_FWOSDriver::DynamicType, "None");

// CLASS: CDF_METADATADRIVERERROR
py::class_<CDF_MetaDataDriverError, opencascade::handle<CDF_MetaDataDriverError>, Standard_Failure> cls_CDF_MetaDataDriverError(mod, "CDF_MetaDataDriverError", "This exception is used in the deferred methods. Programmer implementing such methods may use this exception or any exception inheriting MetaDataDriverError.");

// Constructors
cls_CDF_MetaDataDriverError.def(py::init<>());
cls_CDF_MetaDataDriverError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_CDF_MetaDataDriverError.def_static("Raise_", (void (*)(const Standard_CString)) &CDF_MetaDataDriverError::Raise, "None", py::arg("theMessage"));
cls_CDF_MetaDataDriverError.def_static("Raise_", (void (*)(Standard_SStream &)) &CDF_MetaDataDriverError::Raise, "None", py::arg("theMessage"));
cls_CDF_MetaDataDriverError.def_static("NewInstance_", (opencascade::handle<CDF_MetaDataDriverError> (*)(const Standard_CString)) &CDF_MetaDataDriverError::NewInstance, "None", py::arg("theMessage"));
cls_CDF_MetaDataDriverError.def_static("get_type_name_", (const char * (*)()) &CDF_MetaDataDriverError::get_type_name, "None");
cls_CDF_MetaDataDriverError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_MetaDataDriverError::get_type_descriptor, "None");
cls_CDF_MetaDataDriverError.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_MetaDataDriverError::*)() const) &CDF_MetaDataDriverError::DynamicType, "None");

// CLASS: CDF_METADATADRIVERFACTORY
py::class_<CDF_MetaDataDriverFactory, opencascade::handle<CDF_MetaDataDriverFactory>, Standard_Transient> cls_CDF_MetaDataDriverFactory(mod, "CDF_MetaDataDriverFactory", "None");

// Methods
cls_CDF_MetaDataDriverFactory.def("Build", (opencascade::handle<CDF_MetaDataDriver> (CDF_MetaDataDriverFactory::*)() const) &CDF_MetaDataDriverFactory::Build, "None");
cls_CDF_MetaDataDriverFactory.def_static("get_type_name_", (const char * (*)()) &CDF_MetaDataDriverFactory::get_type_name, "None");
cls_CDF_MetaDataDriverFactory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_MetaDataDriverFactory::get_type_descriptor, "None");
cls_CDF_MetaDataDriverFactory.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_MetaDataDriverFactory::*)() const) &CDF_MetaDataDriverFactory::DynamicType, "None");

// CLASS: CDF_SESSION
py::class_<CDF_Session, opencascade::handle<CDF_Session>, Standard_Transient> cls_CDF_Session(mod, "CDF_Session", "None");

// Constructors
cls_CDF_Session.def(py::init<>());

// Methods
cls_CDF_Session.def_static("Exists_", (Standard_Boolean (*)()) &CDF_Session::Exists, "returns true if a session has been created.");
cls_CDF_Session.def_static("CurrentSession_", (opencascade::handle<CDF_Session> (*)()) &CDF_Session::CurrentSession, "returns the only one instance of Session that has been created.");
cls_CDF_Session.def("Directory", (opencascade::handle<CDF_Directory> (CDF_Session::*)() const) &CDF_Session::Directory, "returns the directory of the session;");
cls_CDF_Session.def("HasCurrentApplication", (Standard_Boolean (CDF_Session::*)() const) &CDF_Session::HasCurrentApplication, "None");
cls_CDF_Session.def("CurrentApplication", (opencascade::handle<CDF_Application> (CDF_Session::*)() const) &CDF_Session::CurrentApplication, "None");
cls_CDF_Session.def("SetCurrentApplication", (void (CDF_Session::*)(const opencascade::handle<CDF_Application> &)) &CDF_Session::SetCurrentApplication, "None", py::arg("anApplication"));
cls_CDF_Session.def("UnsetCurrentApplication", (void (CDF_Session::*)()) &CDF_Session::UnsetCurrentApplication, "None");
cls_CDF_Session.def("MetaDataDriver", (opencascade::handle<CDF_MetaDataDriver> (CDF_Session::*)() const) &CDF_Session::MetaDataDriver, "None");
cls_CDF_Session.def("LoadDriver", (void (CDF_Session::*)()) &CDF_Session::LoadDriver, "None");
cls_CDF_Session.def_static("get_type_name_", (const char * (*)()) &CDF_Session::get_type_name, "None");
cls_CDF_Session.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Session::get_type_descriptor, "None");
cls_CDF_Session.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Session::*)() const) &CDF_Session::DynamicType, "None");

// CLASS: CDF_STORE
py::class_<CDF_Store> cls_CDF_Store(mod, "CDF_Store", "None");

// Constructors
cls_CDF_Store.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));

// Methods
// cls_CDF_Store.def_static("operator new_", (void * (*)(size_t)) &CDF_Store::operator new, "None", py::arg("theSize"));
// cls_CDF_Store.def_static("operator delete_", (void (*)(void *)) &CDF_Store::operator delete, "None", py::arg("theAddress"));
// cls_CDF_Store.def_static("operator new[]_", (void * (*)(size_t)) &CDF_Store::operator new[], "None", py::arg("theSize"));
// cls_CDF_Store.def_static("operator delete[]_", (void (*)(void *)) &CDF_Store::operator delete[], "None", py::arg("theAddress"));
// cls_CDF_Store.def_static("operator new_", (void * (*)(size_t, void *)) &CDF_Store::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CDF_Store.def_static("operator delete_", (void (*)(void *, void *)) &CDF_Store::operator delete, "None", py::arg(""), py::arg(""));
cls_CDF_Store.def("Folder", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Folder, "returns the folder in which the current document will be stored.");
cls_CDF_Store.def("Name", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Name, "returns the name under which the current document will be stored");
cls_CDF_Store.def("IsStored", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsStored, "returns true if the current document is already stored");
cls_CDF_Store.def("IsModified", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsModified, "None");
cls_CDF_Store.def("CurrentIsConsistent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::CurrentIsConsistent, "None");
cls_CDF_Store.def("IsConsistent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsConsistent, "None");
cls_CDF_Store.def("HasAPreviousVersion", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::HasAPreviousVersion, "None");
cls_CDF_Store.def("PreviousVersion", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::PreviousVersion, "None");
cls_CDF_Store.def("IsMainDocument", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::IsMainDocument, "returns true if the currentdocument is the main one, ie the document of the current selection.");
cls_CDF_Store.def("SetFolder", (Standard_Boolean (CDF_Store::*)(const TCollection_ExtendedString &)) &CDF_Store::SetFolder, "defines the folder in which the document should be stored. returns Standard_True if the Folder exists, Standard_False otherwise.", py::arg("aFolder"));
cls_CDF_Store.def("SetName", (CDF_StoreSetNameStatus (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetName, "defines the name under which the document should be stored.", py::arg("aName"));
cls_CDF_Store.def("SetComment", (void (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetComment, "None", py::arg("aComment"));
cls_CDF_Store.def("Comment", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Comment, "None");
cls_CDF_Store.def("RecheckName", (CDF_StoreSetNameStatus (CDF_Store::*)()) &CDF_Store::RecheckName, "defines the name under which the document should be stored. uses for example after modification of the folder.");
cls_CDF_Store.def("SetPreviousVersion", (Standard_Boolean (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetPreviousVersion, "None", py::arg("aPreviousVersion"));
cls_CDF_Store.def("Realize", (void (CDF_Store::*)()) &CDF_Store::Realize, "None");
cls_CDF_Store.def("Path", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Path, "returns the complete path of the created meta-data.");
cls_CDF_Store.def("MetaDataPath", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::MetaDataPath, "returns the path of the previous store is the object is already stored, otherwise an empty string;");
cls_CDF_Store.def("Description", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Description, "returns the description of the format of the main object.");
cls_CDF_Store.def("InitComponent", (void (CDF_Store::*)()) &CDF_Store::InitComponent, "Allows to Start a new Iteration from beginning");
cls_CDF_Store.def("MoreComponent", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::MoreComponent, "Returns True if there are more entries to return");
cls_CDF_Store.def("NextComponent", (void (CDF_Store::*)()) &CDF_Store::NextComponent, "Go to the next entry (if there is not, Value will raise an exception)");
cls_CDF_Store.def("SetCurrent", (void (CDF_Store::*)()) &CDF_Store::SetCurrent, "None");
cls_CDF_Store.def("Component", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::Component, "Returns item value of current entry");
cls_CDF_Store.def("HasSubComponents", (Standard_Boolean (CDF_Store::*)() const) &CDF_Store::HasSubComponents, "None");
cls_CDF_Store.def("SubComponentStatus", (CDF_SubComponentStatus (CDF_Store::*)(const Standard_ExtString) const) &CDF_Store::SubComponentStatus, "None", py::arg("aPresentation"));
cls_CDF_Store.def("SetCurrent", (void (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetCurrent, "None", py::arg("aPresentation"));
cls_CDF_Store.def("SetMain", (void (CDF_Store::*)()) &CDF_Store::SetMain, "the two following methods can be used just after Realize or Import -- method to know if thes methods worked correctly, and if not why.");
cls_CDF_Store.def("StoreStatus", (PCDM_StoreStatus (CDF_Store::*)() const) &CDF_Store::StoreStatus, "None");
cls_CDF_Store.def("AssociatedStatusText", (Standard_ExtString (CDF_Store::*)() const) &CDF_Store::AssociatedStatusText, "None");
cls_CDF_Store.def("SetName", (CDF_StoreSetNameStatus (CDF_Store::*)(const TCollection_ExtendedString &)) &CDF_Store::SetName, "defines the name under which the document should be stored.", py::arg("aName"));
cls_CDF_Store.def("SetFolder", (Standard_Boolean (CDF_Store::*)(const Standard_ExtString)) &CDF_Store::SetFolder, "defines the folder in which the document should be stored. returns Standard_True if the Folder exists, Standard_False otherwise.", py::arg("aFolder"));

// CLASS: CDF_STORELIST
py::class_<CDF_StoreList, opencascade::handle<CDF_StoreList>, Standard_Transient> cls_CDF_StoreList(mod, "CDF_StoreList", "None");

// Constructors
cls_CDF_StoreList.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));

// Methods
cls_CDF_StoreList.def("IsConsistent", (Standard_Boolean (CDF_StoreList::*)() const) &CDF_StoreList::IsConsistent, "None");
cls_CDF_StoreList.def("Store", (PCDM_StoreStatus (CDF_StoreList::*)(opencascade::handle<CDM_MetaData> &, TCollection_ExtendedString &)) &CDF_StoreList::Store, "stores each object of the storelist in the reverse order of which they had been added.", py::arg("aMetaData"), py::arg("aStatusAssociatedText"));
cls_CDF_StoreList.def("Init", (void (CDF_StoreList::*)()) &CDF_StoreList::Init, "None");
cls_CDF_StoreList.def("More", (Standard_Boolean (CDF_StoreList::*)() const) &CDF_StoreList::More, "None");
cls_CDF_StoreList.def("Next", (void (CDF_StoreList::*)()) &CDF_StoreList::Next, "None");
cls_CDF_StoreList.def("Value", (opencascade::handle<CDM_Document> (CDF_StoreList::*)() const) &CDF_StoreList::Value, "None");
cls_CDF_StoreList.def_static("get_type_name_", (const char * (*)()) &CDF_StoreList::get_type_name, "None");
cls_CDF_StoreList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_StoreList::get_type_descriptor, "None");
cls_CDF_StoreList.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_StoreList::*)() const) &CDF_StoreList::DynamicType, "None");


}
