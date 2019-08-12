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
#include <CDF_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <Resource_Manager.hxx>
#include <TCollection_AsciiString.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <PCDM_StorageDriver.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <Standard_IStream.hxx>
#include <PCDM_StoreStatus.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_Application.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_Application(py::module &mod){

py::class_<TDocStd_Application, opencascade::handle<TDocStd_Application>, CDF_Application> cls_TDocStd_Application(mod, "TDocStd_Application", "The abstract root class for all application classes. They are in charge of: - Creating documents - Storing documents and retrieving them - Initializing document views. To create a useful OCAF-based application, you derive a class from Application and implement the methods below. You will have to redefine the deferred (virtual) methods Formats, InitDocument, and Resources, and override others. The application is a container for a document, which in its turn is the container of the data framework made up of labels and attributes. Besides furnishing a container for documents, TDocStd_Application provides the following services for them: - Creation of new documents - Activation of documents in sessions of an application - Storage and retrieval of documents - Initialization of document views. Note: If a client needs detailed information concerning the events during the Open/Store operation, a MessageDriver based on Message_PrinterOStream may be used. In case of need client can implement his own version inheriting from Message_Printer class and add it to the Messanger. Also the trace level of messages can be tuned by setting trace level (SetTraceLevel (Gravity )) for the used Printer. By default, trace level is Message_Info, so that all messages are output.");

// Constructors
cls_TDocStd_Application.def(py::init<>());

// Fields

// Methods
cls_TDocStd_Application.def("IsDriverLoaded", (Standard_Boolean (TDocStd_Application::*)() const) &TDocStd_Application::IsDriverLoaded, "Check if meta data driver was successfully loaded by the application constructor");
cls_TDocStd_Application.def("MessageDriver", (opencascade::handle<Message_Messenger> (TDocStd_Application::*)()) &TDocStd_Application::MessageDriver, "Redefines message driver, by default outputs to cout.");
cls_TDocStd_Application.def("Resources", (opencascade::handle<Resource_Manager> (TDocStd_Application::*)()) &TDocStd_Application::Resources, "Returns resource manager defining supported persistent formats.");
cls_TDocStd_Application.def("ResourcesName", (Standard_CString (TDocStd_Application::*)()) &TDocStd_Application::ResourcesName, "Returns the name of the file containing the resources of this application, for support of legacy method of loading formats data from resource files.");
cls_TDocStd_Application.def("DefineFormat", (void (TDocStd_Application::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const opencascade::handle<PCDM_RetrievalDriver> &, const opencascade::handle<PCDM_StorageDriver> &)) &TDocStd_Application::DefineFormat, "Sets up resources and registers read and storage drivers for the specified format.", py::arg("theFormat"), py::arg("theDescription"), py::arg("theExtension"), py::arg("theReader"), py::arg("theWriter"));
cls_TDocStd_Application.def("ReadingFormats", (void (TDocStd_Application::*)(TColStd_SequenceOfAsciiString &)) &TDocStd_Application::ReadingFormats, "Returns the sequence of reading formats supported by the application.", py::arg("theFormats"));
cls_TDocStd_Application.def("WritingFormats", (void (TDocStd_Application::*)(TColStd_SequenceOfAsciiString &)) &TDocStd_Application::WritingFormats, "Returns the sequence of writing formats supported by the application.", py::arg("theFormats"));
cls_TDocStd_Application.def("NbDocuments", (Standard_Integer (TDocStd_Application::*)() const) &TDocStd_Application::NbDocuments, "returns the number of documents handled by the current applicative session.");
cls_TDocStd_Application.def("GetDocument", (void (TDocStd_Application::*)(const Standard_Integer, opencascade::handle<TDocStd_Document> &) const) &TDocStd_Application::GetDocument, "Constructs the new document aDoc. aDoc is identified by the index index which is any integer between 1 and n where n is the number of documents returned by NbDocument. Example Handle(TDocStd_Application) anApp; if (!CafTest::Find(A)) return 1; Handle(TDocStd) aDoc; Standard_Integer nbdoc = anApp->NbDocuments(); for (Standard_Integer i = 1; i <= nbdoc; i++) { aApp->GetDocument(i,aDoc);", py::arg("index"), py::arg("aDoc"));
cls_TDocStd_Application.def("NewDocument", (void (TDocStd_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::NewDocument, "Constructs the empty new document aDoc. This document will have the format format. If InitDocument is redefined for a specific application, the new document is handled by the applicative session.", py::arg("format"), py::arg("aDoc"));
cls_TDocStd_Application.def("InitDocument", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &) const) &TDocStd_Application::InitDocument, "Initialize the document aDoc for the applicative session. This virtual function is called by NewDocument and is to be redefined for each specific application. Modified flag (different of disk version) ============= to open/save a document =======================", py::arg("aDoc"));
cls_TDocStd_Application.def("Close", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Close, "Close the given document. the document is not any more handled by the applicative session.", py::arg("aDoc"));
cls_TDocStd_Application.def("IsInSession", (Standard_Integer (TDocStd_Application::*)(const TCollection_ExtendedString &) const) &TDocStd_Application::IsInSession, "Returns an index for the document found in the path path in this applicative session. If the returned value is 0, the document is not present in the applicative session. This method can be used for the interactive part of an application. For instance, on a call to Open, the document to be opened may already be in memory. IsInSession checks to see if this is the case. Open can be made to depend on the value of the index returned: if IsInSession returns 0, the document is opened; if it returns another value, a message is displayed asking the user if he wants to override the version of the document in memory. Example: Standard_Integer insession = A->IsInSession(aDoc); if (insession > 0) { cout << 'document ' << insession << ' is already in session' << endl; return 0; }", py::arg("path"));
cls_TDocStd_Application.def("Open", (PCDM_ReaderStatus (TDocStd_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Open, "Retrieves the document aDoc stored under the name aName in the directory directory. In order not to override a version of aDoc which is already in memory, this method can be made to depend on the value returned by IsInSession.", py::arg("path"), py::arg("aDoc"));
cls_TDocStd_Application.def("Open", (PCDM_ReaderStatus (TDocStd_Application::*)(Standard_IStream &, opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Open, "Retrieves aDoc from standard SEEKABLE stream theIStream. the stream should support SEEK fuctionality", py::arg("theIStream"), py::arg("theDoc"));
cls_TDocStd_Application.def("SaveAs", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &)) &TDocStd_Application::SaveAs, "Save the active document in the file <name> in the path <path> ; o verwrites the file if it already exists.", py::arg("aDoc"), py::arg("path"));
cls_TDocStd_Application.def("SaveAs", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &, Standard_OStream &)) &TDocStd_Application::SaveAs, "Save theDoc to standard SEEKABLE stream theOStream. the stream should support SEEK fuctionality", py::arg("theDoc"), py::arg("theOStream"));
cls_TDocStd_Application.def("Save", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Save, "Save aDoc active document. Exceptions: Standard_NotImplemented if the document was not retrieved in the applicative session by using Open.", py::arg("aDoc"));
cls_TDocStd_Application.def("SaveAs", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &, TCollection_ExtendedString &)) &TDocStd_Application::SaveAs, "Save the active document in the file <name> in the path <path> . overwrite the file if it already exist.", py::arg("aDoc"), py::arg("path"), py::arg("theStatusMessage"));
cls_TDocStd_Application.def("SaveAs", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &, Standard_OStream &, TCollection_ExtendedString &)) &TDocStd_Application::SaveAs, "Save theDoc TO standard SEEKABLE stream theOStream. the stream should support SEEK fuctionality", py::arg("theDoc"), py::arg("theOStream"), py::arg("theStatusMessage"));
cls_TDocStd_Application.def("Save", (PCDM_StoreStatus (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &, TCollection_ExtendedString &)) &TDocStd_Application::Save, "Save the document overwriting the previous file", py::arg("aDoc"), py::arg("theStatusMessage"));
cls_TDocStd_Application.def("OnOpenTransaction", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::OnOpenTransaction, "Notification that is fired at each OpenTransaction event.", py::arg("theDoc"));
cls_TDocStd_Application.def("OnCommitTransaction", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::OnCommitTransaction, "Notification that is fired at each CommitTransaction event.", py::arg("theDoc"));
cls_TDocStd_Application.def("OnAbortTransaction", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::OnAbortTransaction, "Notification that is fired at each AbortTransaction event.", py::arg("theDoc"));
cls_TDocStd_Application.def_static("get_type_name_", (const char * (*)()) &TDocStd_Application::get_type_name, "None");
cls_TDocStd_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Application::get_type_descriptor, "None");
cls_TDocStd_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Application::*)() const) &TDocStd_Application::DynamicType, "None");

// Enums

}