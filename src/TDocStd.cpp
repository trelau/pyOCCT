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

#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Data.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_DeltaList.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <CDF_Application.hxx>
#include <CDM_MessageDriver.hxx>
#include <Resource_Manager.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <PCDM_StorageDriver.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <Standard_IStream.hxx>
#include <PCDM_StoreStatus.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_Application.hxx>
#include <TDF_Attribute.hxx>
#include <TDocStd_XLink.hxx>
#include <TDF_Reference.hxx>
#include <Standard_GUID.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDocStd_XLinkPtr.hxx>
#include <TDocStd_XLinkRoot.hxx>
#include <TDocStd_XLinkIterator.hxx>
#include <TDocStd_Context.hxx>
#include <TDF_DataSet.hxx>
#include <TDocStd_XLinkTool.hxx>
#include <TDocStd_Owner.hxx>
#include <TDocStd_Modified.hxx>
#include <TDocStd_PathParser.hxx>
#include <TDF_Delta.hxx>
#include <TDocStd_CompoundDelta.hxx>
#include <Standard_Transient.hxx>
#include <TDocStd_SequenceOfDocument.hxx>
#include <TDocStd_ApplicationDelta.hxx>
#include <TDocStd_SequenceOfApplicationDelta.hxx>
#include <TDocStd_MultiTransactionManager.hxx>
#include <TDF_IDList.hxx>
#include <TDocStd.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <TDocStd_LabelIDMapDataMap.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TDocStd, mod) {

	// IMPORT
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.CDF");
	py::module::import("OCCT.Resource");
	py::module::import("OCCT.PCDM");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_Document.hxx
	py::class_<TDocStd_Document, opencascade::handle<TDocStd_Document>, CDM_Document> cls_TDocStd_Document(mod, "TDocStd_Document", "The contents of a TDocStd_Application, a document is a container for a data framework composed of labels and attributes. As such, TDocStd_Document is the entry point into the data framework. To gain access to the data, you create a document as follows: Handle(TDocStd_Document) MyDF = new TDocStd_Document The document also allows you to manage: - modifications, providing Undo and Redo functions. - command transactions. Warning: The only data saved is the framework (TDF_Data)");
	cls_TDocStd_Document.def(py::init<const TCollection_ExtendedString &>(), py::arg("astorageformat"));
	cls_TDocStd_Document.def_static("Get_", (opencascade::handle<TDocStd_Document> (*)(const TDF_Label &)) &TDocStd_Document::Get, "Will Abort any execution, clear fields returns the document which contains <L>. raises an exception if the document is not found.", py::arg("L"));
	cls_TDocStd_Document.def("IsSaved", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::IsSaved, "the document is saved in a file.");
	cls_TDocStd_Document.def("IsChanged", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::IsChanged, "returns True if document differs from the state of last saving. this method have to be called only wroking in the transaction mode");
	cls_TDocStd_Document.def("SetSaved", (void (TDocStd_Document::*)()) &TDocStd_Document::SetSaved, "This method have to be called to show document that it has been saved");
	cls_TDocStd_Document.def("SetSavedTime", (void (TDocStd_Document::*)(const Standard_Integer)) &TDocStd_Document::SetSavedTime, "Say to document what it is not saved. Use value, returned earlier by GetSavedTime().", py::arg("theTime"));
	cls_TDocStd_Document.def("GetSavedTime", (Standard_Integer (TDocStd_Document::*)() const ) &TDocStd_Document::GetSavedTime, "Returns value of <mySavedTime> to be used later in SetSavedTime()");
	cls_TDocStd_Document.def("GetName", (TCollection_ExtendedString (TDocStd_Document::*)() const ) &TDocStd_Document::GetName, "raise if <me> is not saved.");
	cls_TDocStd_Document.def("GetPath", (TCollection_ExtendedString (TDocStd_Document::*)() const ) &TDocStd_Document::GetPath, "returns the OS path of the file, in wich one <me> is saved. Raise an exception if <me> is not saved.");
	cls_TDocStd_Document.def("SetData", (void (TDocStd_Document::*)(const opencascade::handle<TDF_Data> &)) &TDocStd_Document::SetData, "None", py::arg("data"));
	cls_TDocStd_Document.def("GetData", (opencascade::handle<TDF_Data> (TDocStd_Document::*)() const ) &TDocStd_Document::GetData, "None");
	cls_TDocStd_Document.def("Main", (TDF_Label (TDocStd_Document::*)() const ) &TDocStd_Document::Main, "Returns the main label in this data framework. By definition, this is the label with the entry 0:1.");
	cls_TDocStd_Document.def("IsEmpty", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::IsEmpty, "Returns True if the main label has no attributes");
	cls_TDocStd_Document.def("IsValid", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::IsValid, "Returns False if the document has been modified but not recomputed.");
	cls_TDocStd_Document.def("SetModified", (void (TDocStd_Document::*)(const TDF_Label &)) &TDocStd_Document::SetModified, "Notify the label as modified, the Document becomes UnValid. returns True if <L> has been notified as modified.", py::arg("L"));
	cls_TDocStd_Document.def("PurgeModified", (void (TDocStd_Document::*)()) &TDocStd_Document::PurgeModified, "Remove all modifications. After this call The document becomesagain Valid.");
	cls_TDocStd_Document.def("GetModified", (const TDF_LabelMap & (TDocStd_Document::*)() const ) &TDocStd_Document::GetModified, "Returns the labels which have been modified in this document.");
	cls_TDocStd_Document.def("NewCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::NewCommand, "Launches a new command. This command may be undone.");
	cls_TDocStd_Document.def("HasOpenCommand", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::HasOpenCommand, "returns True if a Command transaction is open in the curret .");
	cls_TDocStd_Document.def("OpenCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::OpenCommand, "Opens a new command transaction in this document. You can use HasOpenCommand to see whether a command is already open. Exceptions Standard_DomainError if a command is already open in this document.");
	cls_TDocStd_Document.def("CommitCommand", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::CommitCommand, "Commits documents transactions and fills the transaction manager with documents that have been changed during the transaction. If no command transaction is open, nothing is done. Returns True if a new delta has been added to myUndos.");
	cls_TDocStd_Document.def("AbortCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::AbortCommand, "Abort the Command transaction. Does nothing If there is no Command transaction open.");
	cls_TDocStd_Document.def("GetUndoLimit", (Standard_Integer (TDocStd_Document::*)() const ) &TDocStd_Document::GetUndoLimit, "The current limit on the number of undos");
	cls_TDocStd_Document.def("SetUndoLimit", (void (TDocStd_Document::*)(const Standard_Integer)) &TDocStd_Document::SetUndoLimit, "Set the limit on the number of Undo Delta stored 0 will disable Undo on the document A negative value means no limit. Note that by default Undo is disabled. Enabling it will take effect with the next call to NewCommand. Of course this limit is the same for Redo", py::arg("L"));
	cls_TDocStd_Document.def("ClearUndos", (void (TDocStd_Document::*)()) &TDocStd_Document::ClearUndos, "Remove all stored Undos and Redos");
	cls_TDocStd_Document.def("ClearRedos", (void (TDocStd_Document::*)()) &TDocStd_Document::ClearRedos, "Remove all stored Redos");
	cls_TDocStd_Document.def("GetAvailableUndos", (Standard_Integer (TDocStd_Document::*)() const ) &TDocStd_Document::GetAvailableUndos, "Returns the number of undos stored in this document. If this figure is greater than 0, the method Undo can be used.");
	cls_TDocStd_Document.def("Undo", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::Undo, "Will UNDO one step, returns False if no undo was done (Undos == 0). Otherwise, true is returned and one step in the list of undoes is undone.");
	cls_TDocStd_Document.def("GetAvailableRedos", (Standard_Integer (TDocStd_Document::*)() const ) &TDocStd_Document::GetAvailableRedos, "Returns the number of redos stored in this document. If this figure is greater than 0, the method Redo can be used.");
	cls_TDocStd_Document.def("Redo", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::Redo, "Will REDO one step, returns False if no redo was done (Redos == 0). Otherwise, true is returned, and one step in the list of redoes is done again.");
	cls_TDocStd_Document.def("GetUndos", (const TDF_DeltaList & (TDocStd_Document::*)() const ) &TDocStd_Document::GetUndos, "None");
	cls_TDocStd_Document.def("GetRedos", (const TDF_DeltaList & (TDocStd_Document::*)() const ) &TDocStd_Document::GetRedos, "None");
	cls_TDocStd_Document.def("RemoveFirstUndo", (void (TDocStd_Document::*)()) &TDocStd_Document::RemoveFirstUndo, "Removes the first undo in the list of document undos. It is used in the application when the undo limit is exceed.");
	cls_TDocStd_Document.def("InitDeltaCompaction", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::InitDeltaCompaction, "Initializes the procedure of delta compaction Returns false if there is no delta to compact Marks the last delta as a 'from' delta");
	cls_TDocStd_Document.def("PerformDeltaCompaction", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::PerformDeltaCompaction, "Performs the procedure of delta compaction Makes all deltas starting from 'from' delta till the last one to be one delta.");
	cls_TDocStd_Document.def("UpdateReferences", (void (TDocStd_Document::*)(const TCollection_AsciiString &)) &TDocStd_Document::UpdateReferences, "Set modifications on labels impacted by external references to the entry. The document becomes invalid and must be recomputed.", py::arg("aDocEntry"));
	cls_TDocStd_Document.def("Recompute", (void (TDocStd_Document::*)()) &TDocStd_Document::Recompute, "Recompute if the document was not valid and propagate the reccorded modification.");
	cls_TDocStd_Document.def("Update", (void (TDocStd_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer, const Standard_Address)) &TDocStd_Document::Update, "This method Update will be called to signal the end of the modified references list. The document should be recomputed and UpdateFromDocuments should be called. Update should returns True in case of success, false otherwise. In case of Failure, additional information can be given in ErrorString. Update the document by propagation ================================== Update the document from internal stored modifications. If you want to undoing this operation, please call NewCommand before. to change format (advanced programming) ================", py::arg("aToDocument"), py::arg("aReferenceIdentifier"), py::arg("aModifContext"));
	cls_TDocStd_Document.def("StorageFormat", (TCollection_ExtendedString (TDocStd_Document::*)() const ) &TDocStd_Document::StorageFormat, "None");
	cls_TDocStd_Document.def("SetEmptyLabelsSavingMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetEmptyLabelsSavingMode, "Sets saving mode for empty labels. If Standard_True, empty labels will be saved.", py::arg("isAllowed"));
	cls_TDocStd_Document.def("EmptyLabelsSavingMode", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::EmptyLabelsSavingMode, "Returns saving mode for empty labels.");
	cls_TDocStd_Document.def("ChangeStorageFormat", (void (TDocStd_Document::*)(const TCollection_ExtendedString &)) &TDocStd_Document::ChangeStorageFormat, "methods for the nested transaction mode", py::arg("newStorageFormat"));
	cls_TDocStd_Document.def("SetNestedTransactionMode", [](TDocStd_Document &self) -> void { return self.SetNestedTransactionMode(); });
	cls_TDocStd_Document.def("SetNestedTransactionMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetNestedTransactionMode, "Sets nested transaction mode if isAllowed == Standard_True", py::arg("isAllowed"));
	cls_TDocStd_Document.def("IsNestedTransactionMode", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::IsNestedTransactionMode, "Returns Standard_True if mode is set");
	cls_TDocStd_Document.def("SetModificationMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetModificationMode, "if theTransactionOnly is True changes is denied outside transactions", py::arg("theTransactionOnly"));
	cls_TDocStd_Document.def("ModificationMode", (Standard_Boolean (TDocStd_Document::*)() const ) &TDocStd_Document::ModificationMode, "returns True if changes allowed only inside transactions");
	cls_TDocStd_Document.def("BeforeClose", (void (TDocStd_Document::*)()) &TDocStd_Document::BeforeClose, "Prepares document for closing");
	cls_TDocStd_Document.def_static("get_type_name_", (const char * (*)()) &TDocStd_Document::get_type_name, "None");
	cls_TDocStd_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Document::get_type_descriptor, "None");
	cls_TDocStd_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Document::*)() const ) &TDocStd_Document::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_Application.hxx
	py::class_<TDocStd_Application, opencascade::handle<TDocStd_Application>, CDF_Application> cls_TDocStd_Application(mod, "TDocStd_Application", "The abstract root class for all application classes. They are in charge of: - Creating documents - Storing documents and retrieving them - Initializing document views. To create a useful OCAF-based application, you derive a class from Application and implement the methods below. You will have to redefine the deferred (virtual) methods Formats, InitDocument, and Resources, and override others. The application is a container for a document, which in its turn is the container of the data framework made up of labels and attributes. Besides furnishing a container for documents, TDocStd_Application provides the following services for them: - Creation of new documents - Activation of documents in sessions of an application - Storage and retrieval of documents - Initialization of document views. Note: If a client needs detailed information concerning the events during the Open/Store operation, MessageDriver inherited from CDM_MessageDriver of the corresponding application has to be implemented. If the MessageDriver is not defined all messages will be (by default) directed to CDM_NullMessageDriver and will be lost.");
	cls_TDocStd_Application.def(py::init<>());
	cls_TDocStd_Application.def("IsDriverLoaded", (Standard_Boolean (TDocStd_Application::*)() const ) &TDocStd_Application::IsDriverLoaded, "Check if meta data driver was successfully loaded by the application constructor");
	cls_TDocStd_Application.def("MessageDriver", (opencascade::handle<CDM_MessageDriver> (TDocStd_Application::*)()) &TDocStd_Application::MessageDriver, "Redefines message driver, by default outputs to cout.");
	cls_TDocStd_Application.def("Resources", (opencascade::handle<Resource_Manager> (TDocStd_Application::*)()) &TDocStd_Application::Resources, "Returns resource manager defining supported persistent formats.");
	cls_TDocStd_Application.def("ResourcesName", (Standard_CString (TDocStd_Application::*)()) &TDocStd_Application::ResourcesName, "Returns the name of the file containing the resources of this application, for support of legacy method of loading formats data from resource files.");
	cls_TDocStd_Application.def("DefineFormat", (void (TDocStd_Application::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const opencascade::handle<PCDM_RetrievalDriver> &, const opencascade::handle<PCDM_StorageDriver> &)) &TDocStd_Application::DefineFormat, "Sets up resources and registers read and storage drivers for the specified format.", py::arg("theFormat"), py::arg("theDescription"), py::arg("theExtension"), py::arg("theReader"), py::arg("theWriter"));
	cls_TDocStd_Application.def("ReadingFormats", (void (TDocStd_Application::*)(TColStd_SequenceOfAsciiString &)) &TDocStd_Application::ReadingFormats, "Returns the sequence of reading formats supported by the application.", py::arg("theFormats"));
	cls_TDocStd_Application.def("WritingFormats", (void (TDocStd_Application::*)(TColStd_SequenceOfAsciiString &)) &TDocStd_Application::WritingFormats, "Returns the sequence of writing formats supported by the application.", py::arg("theFormats"));
	cls_TDocStd_Application.def("NbDocuments", (Standard_Integer (TDocStd_Application::*)() const ) &TDocStd_Application::NbDocuments, "returns the number of documents handled by the current applicative session.");
	cls_TDocStd_Application.def("GetDocument", (void (TDocStd_Application::*)(const Standard_Integer, opencascade::handle<TDocStd_Document> &) const ) &TDocStd_Application::GetDocument, "Constructs the new document aDoc. aDoc is identified by the index index which is any integer between 1 and n where n is the number of documents returned by NbDocument. Example Handle(TDocStd_Application) anApp; if (!CafTest::Find(A)) return 1; Handle(TDocStd) aDoc; Standard_Integer nbdoc = anApp->NbDocuments(); for (Standard_Integer i = 1; i <= nbdoc; i++) { aApp->GetDocument(i,aDoc);", py::arg("index"), py::arg("aDoc"));
	cls_TDocStd_Application.def("NewDocument", (void (TDocStd_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::NewDocument, "Constructs the empty new document aDoc. This document will have the format format. If InitDocument is redefined for a specific application, the new document is handled by the applicative session.", py::arg("format"), py::arg("aDoc"));
	cls_TDocStd_Application.def("InitDocument", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &) const ) &TDocStd_Application::InitDocument, "Initialize the document aDoc for the applicative session. This virtual function is called by NewDocument and is to be redefined for each specific application. Modified flag (different of disk version) ============= to open/save a document =======================", py::arg("aDoc"));
	cls_TDocStd_Application.def("Close", (void (TDocStd_Application::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Close, "Close the given document. the document is not any more handled by the applicative session.", py::arg("aDoc"));
	cls_TDocStd_Application.def("IsInSession", (Standard_Integer (TDocStd_Application::*)(const TCollection_ExtendedString &) const ) &TDocStd_Application::IsInSession, "Returns an index for the document found in the path path in this applicative session. If the returned value is 0, the document is not present in the applicative session. This method can be used for the interactive part of an application. For instance, on a call to Open, the document to be opened may already be in memory. IsInSession checks to see if this is the case. Open can be made to depend on the value of the index returned: if IsInSession returns 0, the document is opened; if it returns another value, a message is displayed asking the user if he wants to override the version of the document in memory. Example: Standard_Integer insession = A->IsInSession(aDoc); if (insession > 0) { cout << 'document ' << insession << ' is already in session' << endl; return 0; }", py::arg("path"));
	// FIXME
	// cls_TDocStd_Application.def("Open", (PCDM_ReaderStatus (TDocStd_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TDocStd_Application::Open, "Retrieves the document aDoc stored under the name aName in the directory directory. In order not to override a version of aDoc which is already in memory, this method can be made to depend on the value returned by IsInSession.", py::arg("path"), py::arg("aDoc"));
	cls_TDocStd_Application.def("Open", [](TDocStd_Application &self, const TCollection_ExtendedString &path, opencascade::handle<TDocStd_Document> &aDoc) {PCDM_ReaderStatus status = self.Open(path, aDoc);  return std::tuple<PCDM_ReaderStatus, opencascade::handle<TDocStd_Document>>(status, aDoc); }, "Retrieves the document aDoc stored under the name aName in the directory directory. In order not to override a version of aDoc which is already in memory, this method can be made to depend on the value returned by IsInSession.", py::arg("path"), py::arg("aDoc"));
	//
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
	cls_TDocStd_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Application::*)() const ) &TDocStd_Application::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_XLink.hxx
	py::class_<TDocStd_XLink, opencascade::handle<TDocStd_XLink>, TDF_Attribute> cls_TDocStd_XLink(mod, "TDocStd_XLink", "An attribute to store the path and the entry of external links. These refer from one data structure to a data structure in another document.");
	cls_TDocStd_XLink.def(py::init<>());
	cls_TDocStd_XLink.def_static("Set_", (opencascade::handle<TDocStd_XLink> (*)(const TDF_Label &)) &TDocStd_XLink::Set, "Sets an empty external reference, at the label aLabel.", py::arg("atLabel"));
	cls_TDocStd_XLink.def("Update", (opencascade::handle<TDF_Reference> (TDocStd_XLink::*)()) &TDocStd_XLink::Update, "Updates the data referenced in this external link attribute.");
	cls_TDocStd_XLink.def("ID", (const Standard_GUID & (TDocStd_XLink::*)() const ) &TDocStd_XLink::ID, "Returns the ID of the attribute.");
	cls_TDocStd_XLink.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_XLink::GetID, "Returns the GUID for external links.");
	cls_TDocStd_XLink.def("DocumentEntry", (void (TDocStd_XLink::*)(const TCollection_AsciiString &)) &TDocStd_XLink::DocumentEntry, "Sets the name aDocEntry for the external document in this external link attribute.", py::arg("aDocEntry"));
	cls_TDocStd_XLink.def("DocumentEntry", (const TCollection_AsciiString & (TDocStd_XLink::*)() const ) &TDocStd_XLink::DocumentEntry, "Returns the contents of the document identified by aDocEntry. aDocEntry provides external data to this external link attribute.");
	cls_TDocStd_XLink.def("LabelEntry", (void (TDocStd_XLink::*)(const TDF_Label &)) &TDocStd_XLink::LabelEntry, "Sets the label entry for this external link attribute with the label aLabel. aLabel pilots the importation of data from the document entry.", py::arg("aLabel"));
	cls_TDocStd_XLink.def("LabelEntry", (void (TDocStd_XLink::*)(const TCollection_AsciiString &)) &TDocStd_XLink::LabelEntry, "Sets the label entry for this external link attribute as a document identified by aLabEntry.", py::arg("aLabEntry"));
	cls_TDocStd_XLink.def("LabelEntry", (const TCollection_AsciiString & (TDocStd_XLink::*)() const ) &TDocStd_XLink::LabelEntry, "Returns the contents of the field <myLabelEntry>.");
	cls_TDocStd_XLink.def("AfterAddition", (void (TDocStd_XLink::*)()) &TDocStd_XLink::AfterAddition, "Updates the XLinkRoot attribute by adding <me> to its list.");
	cls_TDocStd_XLink.def("BeforeRemoval", (void (TDocStd_XLink::*)()) &TDocStd_XLink::BeforeRemoval, "Updates the XLinkRoot attribute by removing <me> from its list.");
	cls_TDocStd_XLink.def("BeforeUndo", [](TDocStd_XLink &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); }, py::arg("anAttDelta"));
	cls_TDocStd_XLink.def("BeforeUndo", (Standard_Boolean (TDocStd_XLink::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDocStd_XLink::BeforeUndo, "Something to do before applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TDocStd_XLink.def("AfterUndo", [](TDocStd_XLink &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("anAttDelta"));
	cls_TDocStd_XLink.def("AfterUndo", (Standard_Boolean (TDocStd_XLink::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDocStd_XLink::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TDocStd_XLink.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDocStd_XLink::*)() const ) &TDocStd_XLink::BackupCopy, "Returns a null handle. Raise allways for ,it is nonsense to use this method.");
	cls_TDocStd_XLink.def("Restore", (void (TDocStd_XLink::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_XLink::Restore, "Does nothing.", py::arg("anAttribute"));
	cls_TDocStd_XLink.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_XLink::*)() const ) &TDocStd_XLink::NewEmpty, "Returns a null handle.");
	cls_TDocStd_XLink.def("Paste", (void (TDocStd_XLink::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDocStd_XLink::Paste, "Does nothing.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
	// FIXME cls_TDocStd_XLink.def("Dump", (Standard_OStream & (TDocStd_XLink::*)(Standard_OStream &) const ) &TDocStd_XLink::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
	cls_TDocStd_XLink.def_static("get_type_name_", (const char * (*)()) &TDocStd_XLink::get_type_name, "None");
	cls_TDocStd_XLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_XLink::get_type_descriptor, "None");
	cls_TDocStd_XLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_XLink::*)() const ) &TDocStd_XLink::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_XLinkRoot.hxx
	py::class_<TDocStd_XLinkRoot, opencascade::handle<TDocStd_XLinkRoot>, TDF_Attribute> cls_TDocStd_XLinkRoot(mod, "TDocStd_XLinkRoot", "This attribute is the root of all external references contained in a Data from TDF. Only one instance of this class is added to the TDF_Data root label. Starting from this attribute all the Reference are linked together, to be found easely.");
	cls_TDocStd_XLinkRoot.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_XLinkRoot::GetID, "Returns the ID: 2a96b61d-ec8b-11d0-bee7-080009dc3333");
	cls_TDocStd_XLinkRoot.def_static("Set_", (opencascade::handle<TDocStd_XLinkRoot> (*)(const opencascade::handle<TDF_Data> &)) &TDocStd_XLinkRoot::Set, "Sets an empty XLinkRoot to Root or gets the existing one. Only one attribute per TDF_Data.", py::arg("aDF"));
	cls_TDocStd_XLinkRoot.def_static("Insert_", (void (*)(const TDocStd_XLinkPtr &)) &TDocStd_XLinkRoot::Insert, "Inserts <anXLinkPtr> at the beginning of the XLink chain.", py::arg("anXLinkPtr"));
	cls_TDocStd_XLinkRoot.def_static("Remove_", (void (*)(const TDocStd_XLinkPtr &)) &TDocStd_XLinkRoot::Remove, "Removes <anXLinkPtr> from the XLink chain, if it exists.", py::arg("anXLinkPtr"));
	cls_TDocStd_XLinkRoot.def("ID", (const Standard_GUID & (TDocStd_XLinkRoot::*)() const ) &TDocStd_XLinkRoot::ID, "Returns the ID of the attribute.");
	cls_TDocStd_XLinkRoot.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDocStd_XLinkRoot::*)() const ) &TDocStd_XLinkRoot::BackupCopy, "Returns a null handle.");
	cls_TDocStd_XLinkRoot.def("Restore", (void (TDocStd_XLinkRoot::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_XLinkRoot::Restore, "Does nothing.", py::arg("anAttribute"));
	cls_TDocStd_XLinkRoot.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_XLinkRoot::*)() const ) &TDocStd_XLinkRoot::NewEmpty, "Returns a null handle.");
	cls_TDocStd_XLinkRoot.def("Paste", (void (TDocStd_XLinkRoot::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDocStd_XLinkRoot::Paste, "Does nothing.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
	// FIXME cls_TDocStd_XLinkRoot.def("Dump", (Standard_OStream & (TDocStd_XLinkRoot::*)(Standard_OStream &) const ) &TDocStd_XLinkRoot::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
	cls_TDocStd_XLinkRoot.def_static("get_type_name_", (const char * (*)()) &TDocStd_XLinkRoot::get_type_name, "None");
	cls_TDocStd_XLinkRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_XLinkRoot::get_type_descriptor, "None");
	cls_TDocStd_XLinkRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_XLinkRoot::*)() const ) &TDocStd_XLinkRoot::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_XLinkIterator.hxx
	py::class_<TDocStd_XLinkIterator, std::unique_ptr<TDocStd_XLinkIterator, Deleter<TDocStd_XLinkIterator>>> cls_TDocStd_XLinkIterator(mod, "TDocStd_XLinkIterator", "Iterates on Reference attributes. This is an iterator giving all the external references of a Document.");
	cls_TDocStd_XLinkIterator.def(py::init<>());
	cls_TDocStd_XLinkIterator.def(py::init<const opencascade::handle<TDocStd_Document> &>(), py::arg("D"));
	cls_TDocStd_XLinkIterator.def("Initialize", (void (TDocStd_XLinkIterator::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_XLinkIterator::Initialize, "Restarts an iteration with <D>.", py::arg("D"));
	cls_TDocStd_XLinkIterator.def("More", (Standard_Boolean (TDocStd_XLinkIterator::*)() const ) &TDocStd_XLinkIterator::More, "Returns True if there is a current Item in the iteration.");
	cls_TDocStd_XLinkIterator.def("Next", (void (TDocStd_XLinkIterator::*)()) &TDocStd_XLinkIterator::Next, "Move to the next item; raises if there is no more item.");
	cls_TDocStd_XLinkIterator.def("Value", (TDocStd_XLinkPtr (TDocStd_XLinkIterator::*)() const ) &TDocStd_XLinkIterator::Value, "Returns the current item; a null handle if there is none.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_Context.hxx
	py::class_<TDocStd_Context, std::unique_ptr<TDocStd_Context, Deleter<TDocStd_Context>>> cls_TDocStd_Context(mod, "TDocStd_Context", "None");
	cls_TDocStd_Context.def(py::init<>());
	cls_TDocStd_Context.def("SetModifiedReferences", (void (TDocStd_Context::*)(const Standard_Boolean)) &TDocStd_Context::SetModifiedReferences, "None", py::arg("Mod"));
	cls_TDocStd_Context.def("ModifiedReferences", (Standard_Boolean (TDocStd_Context::*)() const ) &TDocStd_Context::ModifiedReferences, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_XLinkTool.hxx
	py::class_<TDocStd_XLinkTool, std::unique_ptr<TDocStd_XLinkTool, Deleter<TDocStd_XLinkTool>>> cls_TDocStd_XLinkTool(mod, "TDocStd_XLinkTool", "This tool class is used to copy the content of source label under target label. Only child labels and attributes of source are copied. attributes located out of source scope are not copied by this algorithm. Depending of the called method an external reference is set in the the target document to registred the externallink. Provide services to set, update and perform external references. Warning1: Nothing is provided in this class about the opportunity to copy, set a link or update it. Such decisions must be under application control. Warning2: If the document manages shapes, use after copy TNaming::ChangeShapes(target,M) to make copy of shapes.");
	cls_TDocStd_XLinkTool.def(py::init<>());
	cls_TDocStd_XLinkTool.def("CopyWithLink", (void (TDocStd_XLinkTool::*)(const TDF_Label &, const TDF_Label &)) &TDocStd_XLinkTool::CopyWithLink, "Copies the content of the label <fromsource> to the label <intarget>. The link is registred with an XLink attribute by <intarget> label. if the content of <fromsource> is not self-contained, and/or <intarget> has already an XLink attribute, an exception is raised.", py::arg("intarget"), py::arg("fromsource"));
	cls_TDocStd_XLinkTool.def("UpdateLink", (void (TDocStd_XLinkTool::*)(const TDF_Label &)) &TDocStd_XLinkTool::UpdateLink, "Update the external reference set at <L>. Example Handle(TDocStd_Document) aDoc; if (!OCAFTest::GetDocument(1,aDoc)) return 1; Handle(TDataStd_Reference) aRef; TDocStd_XLinkTool xlinktool; if (!OCAFTest::Find(aDoc,2),TDataStd_Reference::GetID(),aRef) return 1; xlinktool.UpdateLink(aRef->Label()); Exceptions Standard_DomainError if <L> has no XLink attribute.", py::arg("L"));
	cls_TDocStd_XLinkTool.def("Copy", (void (TDocStd_XLinkTool::*)(const TDF_Label &, const TDF_Label &)) &TDocStd_XLinkTool::Copy, "Copy the content of <fromsource> under <intarget>. Noone link is registred. noone check is done. Example Handle(TDocStd_Document) DOC, XDOC; TDF_Label L, XL; TDocStd_XLinkTool xlinktool; xlinktool.Copy(L,XL); Exceptions: Standard_DomainError if the contents of fromsource are not entirely in the scope of this label, in other words, are not self-contained. !!! ==> Warning: If the document manages shapes use the next way: TDocStd_XLinkTool xlinktool; xlinktool.Copy(L,XL); TopTools_DataMapOfShapeShape M; TNaming::ChangeShapes(target,M);", py::arg("intarget"), py::arg("fromsource"));
	cls_TDocStd_XLinkTool.def("IsDone", (Standard_Boolean (TDocStd_XLinkTool::*)() const ) &TDocStd_XLinkTool::IsDone, "None");
	cls_TDocStd_XLinkTool.def("DataSet", (opencascade::handle<TDF_DataSet> (TDocStd_XLinkTool::*)() const ) &TDocStd_XLinkTool::DataSet, "None");
	cls_TDocStd_XLinkTool.def("RelocationTable", (opencascade::handle<TDF_RelocationTable> (TDocStd_XLinkTool::*)() const ) &TDocStd_XLinkTool::RelocationTable, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_Owner.hxx
	py::class_<TDocStd_Owner, opencascade::handle<TDocStd_Owner>, TDF_Attribute> cls_TDocStd_Owner(mod, "TDocStd_Owner", "This attribute located at the root label of the framework contains a back reference to the owner TDocStd_Document, providing acces to the document from any label. private class Owner;");
	cls_TDocStd_Owner.def(py::init<>());
	cls_TDocStd_Owner.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_Owner::GetID, "class methods =============");
	cls_TDocStd_Owner.def_static("SetDocument_", (void (*)(const opencascade::handle<TDF_Data> &, const opencascade::handle<TDocStd_Document> &)) &TDocStd_Owner::SetDocument, "None", py::arg("indata"), py::arg("doc"));
	cls_TDocStd_Owner.def_static("GetDocument_", (opencascade::handle<TDocStd_Document> (*)(const opencascade::handle<TDF_Data> &)) &TDocStd_Owner::GetDocument, "Owner methods ===============", py::arg("ofdata"));
	cls_TDocStd_Owner.def("SetDocument", (void (TDocStd_Owner::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Owner::SetDocument, "None", py::arg("document"));
	cls_TDocStd_Owner.def("GetDocument", (opencascade::handle<TDocStd_Document> (TDocStd_Owner::*)() const ) &TDocStd_Owner::GetDocument, "None");
	cls_TDocStd_Owner.def("ID", (const Standard_GUID & (TDocStd_Owner::*)() const ) &TDocStd_Owner::ID, "None");
	cls_TDocStd_Owner.def("Restore", (void (TDocStd_Owner::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_Owner::Restore, "None", py::arg("With"));
	cls_TDocStd_Owner.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_Owner::*)() const ) &TDocStd_Owner::NewEmpty, "None");
	cls_TDocStd_Owner.def("Paste", (void (TDocStd_Owner::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDocStd_Owner::Paste, "None", py::arg("Into"), py::arg("RT"));
	// FIXME cls_TDocStd_Owner.def("Dump", (Standard_OStream & (TDocStd_Owner::*)(Standard_OStream &) const ) &TDocStd_Owner::Dump, "None", py::arg("anOS"));
	cls_TDocStd_Owner.def_static("get_type_name_", (const char * (*)()) &TDocStd_Owner::get_type_name, "None");
	cls_TDocStd_Owner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Owner::get_type_descriptor, "None");
	cls_TDocStd_Owner.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Owner::*)() const ) &TDocStd_Owner::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_Modified.hxx
	py::class_<TDocStd_Modified, opencascade::handle<TDocStd_Modified>, TDF_Attribute> cls_TDocStd_Modified(mod, "TDocStd_Modified", "Transient attribute wich register modified labels. This attribute is attached to root label.");
	cls_TDocStd_Modified.def(py::init<>());
	cls_TDocStd_Modified.def_static("IsEmpty_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::IsEmpty, "API class methods =================", py::arg("access"));
	cls_TDocStd_Modified.def_static("Add_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Add, "None", py::arg("alabel"));
	cls_TDocStd_Modified.def_static("Remove_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Remove, "None", py::arg("alabel"));
	cls_TDocStd_Modified.def_static("Contains_", (Standard_Boolean (*)(const TDF_Label &)) &TDocStd_Modified::Contains, "None", py::arg("alabel"));
	cls_TDocStd_Modified.def_static("Get_", (const TDF_LabelMap & (*)(const TDF_Label &)) &TDocStd_Modified::Get, "if <IsEmpty> raise an exception.", py::arg("access"));
	cls_TDocStd_Modified.def_static("Clear_", (void (*)(const TDF_Label &)) &TDocStd_Modified::Clear, "remove all modified labels. becomes empty", py::arg("access"));
	cls_TDocStd_Modified.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_Modified::GetID, "Modified methods ================");
	cls_TDocStd_Modified.def("IsEmpty", (Standard_Boolean (TDocStd_Modified::*)() const ) &TDocStd_Modified::IsEmpty, "None");
	cls_TDocStd_Modified.def("Clear", (void (TDocStd_Modified::*)()) &TDocStd_Modified::Clear, "None");
	cls_TDocStd_Modified.def("AddLabel", (Standard_Boolean (TDocStd_Modified::*)(const TDF_Label &)) &TDocStd_Modified::AddLabel, "add <L> as modified", py::arg("L"));
	cls_TDocStd_Modified.def("RemoveLabel", (Standard_Boolean (TDocStd_Modified::*)(const TDF_Label &)) &TDocStd_Modified::RemoveLabel, "remove <L> as modified", py::arg("L"));
	cls_TDocStd_Modified.def("Get", (const TDF_LabelMap & (TDocStd_Modified::*)() const ) &TDocStd_Modified::Get, "returns modified label map");
	cls_TDocStd_Modified.def("ID", (const Standard_GUID & (TDocStd_Modified::*)() const ) &TDocStd_Modified::ID, "None");
	cls_TDocStd_Modified.def("Restore", (void (TDocStd_Modified::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_Modified::Restore, "None", py::arg("With"));
	cls_TDocStd_Modified.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_Modified::*)() const ) &TDocStd_Modified::NewEmpty, "None");
	cls_TDocStd_Modified.def("Paste", (void (TDocStd_Modified::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TDocStd_Modified::Paste, "None", py::arg("Into"), py::arg("RT"));
	// FIXME cls_TDocStd_Modified.def("Dump", (Standard_OStream & (TDocStd_Modified::*)(Standard_OStream &) const ) &TDocStd_Modified::Dump, "None", py::arg("anOS"));
	cls_TDocStd_Modified.def_static("get_type_name_", (const char * (*)()) &TDocStd_Modified::get_type_name, "None");
	cls_TDocStd_Modified.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Modified::get_type_descriptor, "None");
	cls_TDocStd_Modified.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Modified::*)() const ) &TDocStd_Modified::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_PathParser.hxx
	py::class_<TDocStd_PathParser, std::unique_ptr<TDocStd_PathParser, Deleter<TDocStd_PathParser>>> cls_TDocStd_PathParser(mod, "TDocStd_PathParser", "parse an OS path");
	cls_TDocStd_PathParser.def(py::init<const TCollection_ExtendedString &>(), py::arg("path"));
	cls_TDocStd_PathParser.def("Parse", (void (TDocStd_PathParser::*)()) &TDocStd_PathParser::Parse, "None");
	cls_TDocStd_PathParser.def("Trek", (TCollection_ExtendedString (TDocStd_PathParser::*)() const ) &TDocStd_PathParser::Trek, "None");
	cls_TDocStd_PathParser.def("Name", (TCollection_ExtendedString (TDocStd_PathParser::*)() const ) &TDocStd_PathParser::Name, "None");
	cls_TDocStd_PathParser.def("Extension", (TCollection_ExtendedString (TDocStd_PathParser::*)() const ) &TDocStd_PathParser::Extension, "None");
	cls_TDocStd_PathParser.def("Path", (TCollection_ExtendedString (TDocStd_PathParser::*)() const ) &TDocStd_PathParser::Path, "None");
	cls_TDocStd_PathParser.def("Length", (Standard_Integer (TDocStd_PathParser::*)() const ) &TDocStd_PathParser::Length, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_CompoundDelta.hxx
	py::class_<TDocStd_CompoundDelta, opencascade::handle<TDocStd_CompoundDelta>, TDF_Delta> cls_TDocStd_CompoundDelta(mod, "TDocStd_CompoundDelta", "A delta set is available at <aSourceTime>. If applied, it restores the TDF_Data in the state it was at <aTargetTime>.");
	cls_TDocStd_CompoundDelta.def(py::init<>());
	cls_TDocStd_CompoundDelta.def_static("get_type_name_", (const char * (*)()) &TDocStd_CompoundDelta::get_type_name, "None");
	cls_TDocStd_CompoundDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_CompoundDelta::get_type_descriptor, "None");
	cls_TDocStd_CompoundDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_CompoundDelta::*)() const ) &TDocStd_CompoundDelta::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_ApplicationDelta.hxx
	py::class_<TDocStd_ApplicationDelta, opencascade::handle<TDocStd_ApplicationDelta>, Standard_Transient> cls_TDocStd_ApplicationDelta(mod, "TDocStd_ApplicationDelta", "None");
	cls_TDocStd_ApplicationDelta.def(py::init<>());
	cls_TDocStd_ApplicationDelta.def("GetDocuments", (TDocStd_SequenceOfDocument & (TDocStd_ApplicationDelta::*)()) &TDocStd_ApplicationDelta::GetDocuments, "None");
	cls_TDocStd_ApplicationDelta.def("GetName", (const TCollection_ExtendedString & (TDocStd_ApplicationDelta::*)() const ) &TDocStd_ApplicationDelta::GetName, "None");
	cls_TDocStd_ApplicationDelta.def("SetName", (void (TDocStd_ApplicationDelta::*)(const TCollection_ExtendedString &)) &TDocStd_ApplicationDelta::SetName, "None", py::arg("theName"));
	// FIXME cls_TDocStd_ApplicationDelta.def("Dump", (void (TDocStd_ApplicationDelta::*)(Standard_OStream &) const ) &TDocStd_ApplicationDelta::Dump, "None", py::arg("anOS"));
	cls_TDocStd_ApplicationDelta.def_static("get_type_name_", (const char * (*)()) &TDocStd_ApplicationDelta::get_type_name, "None");
	cls_TDocStd_ApplicationDelta.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_ApplicationDelta::get_type_descriptor, "None");
	cls_TDocStd_ApplicationDelta.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_ApplicationDelta::*)() const ) &TDocStd_ApplicationDelta::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_MultiTransactionManager.hxx
	py::class_<TDocStd_MultiTransactionManager, opencascade::handle<TDocStd_MultiTransactionManager>, Standard_Transient> cls_TDocStd_MultiTransactionManager(mod, "TDocStd_MultiTransactionManager", "Class for synchronization of transactions within multiple documents. Each transaction of this class involvess one transaction in each modified document.");
	cls_TDocStd_MultiTransactionManager.def(py::init<>());
	cls_TDocStd_MultiTransactionManager.def("SetUndoLimit", (void (TDocStd_MultiTransactionManager::*)(const Standard_Integer)) &TDocStd_MultiTransactionManager::SetUndoLimit, "Sets undo limit for the manager and all documents.", py::arg("theLimit"));
	cls_TDocStd_MultiTransactionManager.def("GetUndoLimit", (Standard_Integer (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::GetUndoLimit, "Returns undo limit for the manager.");
	cls_TDocStd_MultiTransactionManager.def("Undo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::Undo, "Undoes the current transaction of the manager. It calls the Undo () method of the document being on top of the manager list of undos (list.First()) and moves the list item to the top of the list of manager redos (list.Prepend(item)).");
	cls_TDocStd_MultiTransactionManager.def("Redo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::Redo, "Redoes the current transaction of the application. It calls the Redo () method of the document being on top of the manager list of redos (list.First()) and moves the list item to the top of the list of manager undos (list.Prepend(item)).");
	cls_TDocStd_MultiTransactionManager.def("GetAvailableUndos", (const TDocStd_SequenceOfApplicationDelta & (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::GetAvailableUndos, "Returns available manager undos.");
	cls_TDocStd_MultiTransactionManager.def("GetAvailableRedos", (const TDocStd_SequenceOfApplicationDelta & (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::GetAvailableRedos, "Returns available manager redos.");
	cls_TDocStd_MultiTransactionManager.def("OpenCommand", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::OpenCommand, "Opens transaction in each document and sets the flag that transaction is opened. If there are already opened transactions in the documents, these transactions will be aborted before openning new ones.");
	cls_TDocStd_MultiTransactionManager.def("AbortCommand", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::AbortCommand, "Unsets the flag of started manager transaction and aborts transaction in each document.");
	cls_TDocStd_MultiTransactionManager.def("CommitCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::CommitCommand, "Commits transaction in all documents and fills the transaction manager with the documents that have been changed during the transaction. Returns True if new data has been added to myUndos. NOTE: All nested transactions in the documents will be commited.");
	cls_TDocStd_MultiTransactionManager.def("CommitCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)(const TCollection_ExtendedString &)) &TDocStd_MultiTransactionManager::CommitCommand, "Makes the same steps as the previous function but defines the name for transaction. Returns True if new data has been added to myUndos.", py::arg("theName"));
	cls_TDocStd_MultiTransactionManager.def("HasOpenCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::HasOpenCommand, "Returns true if a transaction is opened.");
	cls_TDocStd_MultiTransactionManager.def("RemoveLastUndo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::RemoveLastUndo, "Removes undo information from the list of undos of the manager and all documents which have been modified during the transaction.");
	cls_TDocStd_MultiTransactionManager.def("DumpTransaction", (void (TDocStd_MultiTransactionManager::*)(Standard_OStream &) const ) &TDocStd_MultiTransactionManager::DumpTransaction, "Dumps transactions in undos and redos", py::arg("theOS"));
	cls_TDocStd_MultiTransactionManager.def("AddDocument", (void (TDocStd_MultiTransactionManager::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_MultiTransactionManager::AddDocument, "Adds the document to the transaction manager and checks if it has been already added", py::arg("theDoc"));
	cls_TDocStd_MultiTransactionManager.def("RemoveDocument", (void (TDocStd_MultiTransactionManager::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_MultiTransactionManager::RemoveDocument, "Removes the document from the transaction manager.", py::arg("theDoc"));
	cls_TDocStd_MultiTransactionManager.def("Documents", (const TDocStd_SequenceOfDocument & (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::Documents, "Returns the added documents to the transaction manager.");
	cls_TDocStd_MultiTransactionManager.def("SetNestedTransactionMode", [](TDocStd_MultiTransactionManager &self) -> void { return self.SetNestedTransactionMode(); });
	cls_TDocStd_MultiTransactionManager.def("SetNestedTransactionMode", (void (TDocStd_MultiTransactionManager::*)(const Standard_Boolean)) &TDocStd_MultiTransactionManager::SetNestedTransactionMode, "Sets nested transaction mode if isAllowed == Standard_True NOTE: field myIsNestedTransactionMode exists only for synchronization between several documents and has no effect on transactions of multitransaction manager.", py::arg("isAllowed"));
	cls_TDocStd_MultiTransactionManager.def("IsNestedTransactionMode", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::IsNestedTransactionMode, "Returns Standard_True if NestedTransaction mode is set. Methods for protection of changes outside transactions");
	cls_TDocStd_MultiTransactionManager.def("SetModificationMode", (void (TDocStd_MultiTransactionManager::*)(const Standard_Boolean)) &TDocStd_MultiTransactionManager::SetModificationMode, "If theTransactionOnly is True, denies all changes outside transactions.", py::arg("theTransactionOnly"));
	cls_TDocStd_MultiTransactionManager.def("ModificationMode", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::ModificationMode, "Returns True if changes are allowed only inside transactions.");
	cls_TDocStd_MultiTransactionManager.def("ClearUndos", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::ClearUndos, "Clears undos in the manager and in documents.");
	cls_TDocStd_MultiTransactionManager.def("ClearRedos", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::ClearRedos, "Clears redos in the manager and in documents.");
	cls_TDocStd_MultiTransactionManager.def_static("get_type_name_", (const char * (*)()) &TDocStd_MultiTransactionManager::get_type_name, "None");
	cls_TDocStd_MultiTransactionManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_MultiTransactionManager::get_type_descriptor, "None");
	cls_TDocStd_MultiTransactionManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_MultiTransactionManager::*)() const ) &TDocStd_MultiTransactionManager::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd.hxx
	py::class_<TDocStd, std::unique_ptr<TDocStd, Deleter<TDocStd>>> cls_TDocStd(mod, "TDocStd", "This package define CAF main classes.");
	cls_TDocStd.def(py::init<>());
	cls_TDocStd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDocStd::IDList, "specific GUID of this package ============================= Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_XLinkPtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_SequenceOfDocument.hxx
	bind_NCollection_Sequence<opencascade::handle<TDocStd_Document> >(mod, "TDocStd_SequenceOfDocument");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_LabelIDMapDataMap.hxx
	bind_NCollection_DataMap<TDF_Label, NCollection_Map<Standard_GUID, Standard_GUID>, TDF_LabelMapHasher>(mod, "TDocStd_LabelIDMapDataMap");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TDocStd_SequenceOfApplicationDelta.hxx
	bind_NCollection_Sequence<opencascade::handle<TDocStd_ApplicationDelta> >(mod, "TDocStd_SequenceOfApplicationDelta");


}
