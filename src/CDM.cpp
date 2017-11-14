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
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <CDM_Reference.hxx>
#include <CDM_MetaData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <CDM_Application.hxx>
#include <CDM_CanCloseStatus.hxx>
#include <CDM_MessageDriver.hxx>
#include <Resource_Manager.hxx>
#include <CDM_DocumentPointer.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <CDM_ListOfReferences.hxx>
#include <CDM_ReferenceIterator.hxx>
#include <CDM_ListOfDocument.hxx>
#include <CDM_DocumentHasher.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_Map.hxx>
#include <CDM_MapOfDocument.hxx>
#include <CDM_COutMessageDriver.hxx>
#include <NCollection_DataMap.hxx>
#include <CDM_MetaDataLookUpTable.hxx>
#include <CDM_PresentationDirectory.hxx>
#include <CDM_NamesDirectory.hxx>
#include <CDM_NullMessageDriver.hxx>

PYBIND11_MODULE(CDM, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Resource");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_CanCloseStatus.hxx
	py::enum_<CDM_CanCloseStatus>(mod, "CDM_CanCloseStatus", "None")
		.value("CDM_CCS_OK", CDM_CanCloseStatus::CDM_CCS_OK)
		.value("CDM_CCS_NotOpen", CDM_CanCloseStatus::CDM_CCS_NotOpen)
		.value("CDM_CCS_UnstoredReferenced", CDM_CanCloseStatus::CDM_CCS_UnstoredReferenced)
		.value("CDM_CCS_ModifiedReferenced", CDM_CanCloseStatus::CDM_CCS_ModifiedReferenced)
		.value("CDM_CCS_ReferenceRejection", CDM_CanCloseStatus::CDM_CCS_ReferenceRejection)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_Reference.hxx
	py::class_<CDM_Reference, opencascade::handle<CDM_Reference>, Standard_Transient> cls_CDM_Reference(mod, "CDM_Reference", "None");
	cls_CDM_Reference.def("FromDocument", (opencascade::handle<CDM_Document> (CDM_Reference::*)()) &CDM_Reference::FromDocument, "None");
	cls_CDM_Reference.def("ToDocument", (opencascade::handle<CDM_Document> (CDM_Reference::*)()) &CDM_Reference::ToDocument, "None");
	cls_CDM_Reference.def("ReferenceIdentifier", (Standard_Integer (CDM_Reference::*)()) &CDM_Reference::ReferenceIdentifier, "None");
	cls_CDM_Reference.def("DocumentVersion", (Standard_Integer (CDM_Reference::*)() const ) &CDM_Reference::DocumentVersion, "None");
	cls_CDM_Reference.def("IsReadOnly", (Standard_Boolean (CDM_Reference::*)() const ) &CDM_Reference::IsReadOnly, "None");
	cls_CDM_Reference.def_static("get_type_name_", (const char * (*)()) &CDM_Reference::get_type_name, "None");
	cls_CDM_Reference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Reference::get_type_descriptor, "None");
	cls_CDM_Reference.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Reference::*)() const ) &CDM_Reference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_MetaData.hxx
	py::class_<CDM_MetaData, opencascade::handle<CDM_MetaData>, Standard_Transient> cls_CDM_MetaData(mod, "CDM_MetaData", "None");
	cls_CDM_MetaData.def_static("LookUp_", (opencascade::handle<CDM_MetaData> (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDM_MetaData::LookUp, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aPath"), py::arg("aFileName"), py::arg("ReadOnly"));
	cls_CDM_MetaData.def_static("LookUp_", (opencascade::handle<CDM_MetaData> (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDM_MetaData::LookUp, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aPath"), py::arg("aVersion"), py::arg("aFileName"), py::arg("ReadOnly"));
	cls_CDM_MetaData.def("IsRetrieved", (Standard_Boolean (CDM_MetaData::*)() const ) &CDM_MetaData::IsRetrieved, "None");
	cls_CDM_MetaData.def("Document", (opencascade::handle<CDM_Document> (CDM_MetaData::*)() const ) &CDM_MetaData::Document, "None");
	cls_CDM_MetaData.def("Folder", (TCollection_ExtendedString (CDM_MetaData::*)() const ) &CDM_MetaData::Folder, "returns the folder in which the meta-data has to be created or has to be found.");
	cls_CDM_MetaData.def("Name", (TCollection_ExtendedString (CDM_MetaData::*)() const ) &CDM_MetaData::Name, "returns the name under which the meta-data has to be created or has to be found.");
	cls_CDM_MetaData.def("Version", (TCollection_ExtendedString (CDM_MetaData::*)() const ) &CDM_MetaData::Version, "returns the version under which the meta-data has to be found. Warning: raises NoSuchObject from Standard if no Version has been defined");
	cls_CDM_MetaData.def("HasVersion", (Standard_Boolean (CDM_MetaData::*)() const ) &CDM_MetaData::HasVersion, "indicates that the version has to be taken into account when searching the corresponding meta-data.");
	cls_CDM_MetaData.def("FileName", (TCollection_ExtendedString (CDM_MetaData::*)() const ) &CDM_MetaData::FileName, "None");
	cls_CDM_MetaData.def("Print", (Standard_OStream & (CDM_MetaData::*)(Standard_OStream &) const ) &CDM_MetaData::Print, "None", py::arg("anOStream"));
	cls_CDM_MetaData.def("operator<<", (Standard_OStream & (CDM_MetaData::*)(Standard_OStream &)) &CDM_MetaData::operator<<, "None", py::arg("anOStream"));
	cls_CDM_MetaData.def("Path", (TCollection_ExtendedString (CDM_MetaData::*)() const ) &CDM_MetaData::Path, "None");
	cls_CDM_MetaData.def("UnsetDocument", (void (CDM_MetaData::*)()) &CDM_MetaData::UnsetDocument, "None");
	cls_CDM_MetaData.def("IsReadOnly", (Standard_Boolean (CDM_MetaData::*)() const ) &CDM_MetaData::IsReadOnly, "None");
	cls_CDM_MetaData.def("SetIsReadOnly", (void (CDM_MetaData::*)()) &CDM_MetaData::SetIsReadOnly, "None");
	cls_CDM_MetaData.def("UnsetIsReadOnly", (void (CDM_MetaData::*)()) &CDM_MetaData::UnsetIsReadOnly, "None");
	cls_CDM_MetaData.def_static("get_type_name_", (const char * (*)()) &CDM_MetaData::get_type_name, "None");
	cls_CDM_MetaData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_MetaData::get_type_descriptor, "None");
	cls_CDM_MetaData.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_MetaData::*)() const ) &CDM_MetaData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_Document.hxx
	py::class_<CDM_Document, opencascade::handle<CDM_Document>, Standard_Transient> cls_CDM_Document(mod, "CDM_Document", "An applicative document is an instance of a class inheriting CDM_Document. These documents have the following properties: - they can have references to other documents. - the modifications of a document are propagated to the referencing documents. - a document can be stored in different formats, with or without a persistent model. - the drivers for storing and retrieving documents are plugged in when necessary. - a document has a modification counter. This counter is incremented when the document is modified. When a document is stored, the current counter value is memorized as the last storage version of the document. A document is considered to be modified when the counter value is different from the storage version. Once the document is saved the storage version and the counter value are identical. The document is now not considered to be modified. - a reference is a link between two documents. A reference has two components: the 'From Document' and the 'To Document'. When a reference is created, an identifier of the reference is generated. This identifier is unique in the scope of the From Document and is conserved during storage and retrieval. This means that the referenced document will be always accessible through this identifier. - a reference memorizes the counter value of the To Document when the reference is created. The From Document is considered to be up to date relative to the To Document when the reference counter value is equal to the To Document counter value. - retrieval of a document having references does not imply the retrieving of the referenced documents.");
	cls_CDM_Document.def("Update", (void (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer, const Standard_Address)) &CDM_Document::Update, "The Update method will be called once for each reference, but it should not perform any computation, to avoid multiple computation of a same document.", py::arg("aToDocument"), py::arg("aReferenceIdentifier"), py::arg("aModifContext"));
	cls_CDM_Document.def("Update", (Standard_Boolean (CDM_Document::*)(TCollection_ExtendedString &)) &CDM_Document::Update, "This method Update will be called to signal the end of the modified references list. The document should be recomputed and UpdateFromDocuments should be called. Update should returns True in case of success, false otherwise. In case of Failure, additional information can be given in ErrorString.", py::arg("ErrorString"));
	cls_CDM_Document.def("StorageFormat", (TCollection_ExtendedString (CDM_Document::*)() const ) &CDM_Document::StorageFormat, "The Storage Format is the key which is used to determine in the application resources the storage driver plugin, the file extension and other data used to store the document.");
	cls_CDM_Document.def("Extensions", (void (CDM_Document::*)(TColStd_SequenceOfExtendedString &) const ) &CDM_Document::Extensions, "by default empties the extensions.", py::arg("Extensions"));
	cls_CDM_Document.def("GetAlternativeDocument", (Standard_Boolean (CDM_Document::*)(const TCollection_ExtendedString &, opencascade::handle<CDM_Document> &)) &CDM_Document::GetAlternativeDocument, "This method can be redefined to extract another document in a different format. For example, to extract a Shape from an applicative document.", py::arg("aFormat"), py::arg("anAlternativeDocument"));
	cls_CDM_Document.def("CreateReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_Document> &)) &CDM_Document::CreateReference, "Creates a reference from this document to {anOtherDocument}. Returns a reference identifier. This reference identifier is unique in the document and will not be used for the next references, even after the storing of the document. If there is already a reference between the two documents, the reference is not created, but its reference identifier is returned.", py::arg("anOtherDocument"));
	cls_CDM_Document.def("RemoveReference", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::RemoveReference, "Removes the reference between the From Document and the To Document identified by a reference identifier.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("RemoveAllReferences", (void (CDM_Document::*)()) &CDM_Document::RemoveAllReferences, "Removes all references having this document for From Document.");
	cls_CDM_Document.def("Document", (opencascade::handle<CDM_Document> (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::Document, "Returns the To Document of the reference identified by aReferenceIdentifier. If the ToDocument is stored and has not yet been retrieved, this method will retrieve it.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("IsInSession", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::IsInSession, "returns True if the To Document of the reference identified by aReferenceIdentifier is in session, False if it corresponds to a not yet retrieved document.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("IsStored", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::IsStored, "returns True if the To Document of the reference identified by aReferenceIdentifier has already been stored, False otherwise.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("Name", (TCollection_ExtendedString (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::Name, "returns the name of the metadata of the To Document of the reference identified by aReferenceIdentifier.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("UpdateFromDocuments", (void (CDM_Document::*)(const Standard_Address) const ) &CDM_Document::UpdateFromDocuments, "call virtual method Update on all referencing documents. This method keeps the list of the -- documents to process.It may be the starting of an update -- cycle. If not, the reentrant calls made by Update method (without argument) will append the referencing documents to the list and call the Update method (with arguments). Only the first call to UpdateFromDocuments generate call to Update().", py::arg("aModifContext"));
	cls_CDM_Document.def("ToReferencesNumber", (Standard_Integer (CDM_Document::*)() const ) &CDM_Document::ToReferencesNumber, "returns the number of references having this document as From Document.");
	cls_CDM_Document.def("FromReferencesNumber", (Standard_Integer (CDM_Document::*)() const ) &CDM_Document::FromReferencesNumber, "returns the number of references having this document as To Document.");
	cls_CDM_Document.def("ShallowReferences", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &) const ) &CDM_Document::ShallowReferences, "returns True is this document references aDocument;", py::arg("aDocument"));
	cls_CDM_Document.def("DeepReferences", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &) const ) &CDM_Document::DeepReferences, "returns True is this document references aDocument;", py::arg("aDocument"));
	cls_CDM_Document.def("CopyReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer)) &CDM_Document::CopyReference, "Copies a reference to this document. This method avoid retrieval of referenced document. The arguments are the original document and a valid reference identifier Returns the local identifier.", py::arg("aFromDocument"), py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("IsReadOnly", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::IsReadOnly, "indicates that this document cannot be modified.");
	cls_CDM_Document.def("IsReadOnly", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::IsReadOnly, "indicates that the referenced document cannot be modified,", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("SetIsReadOnly", (void (CDM_Document::*)()) &CDM_Document::SetIsReadOnly, "None");
	cls_CDM_Document.def("UnsetIsReadOnly", (void (CDM_Document::*)()) &CDM_Document::UnsetIsReadOnly, "None");
	cls_CDM_Document.def("Modify", (void (CDM_Document::*)()) &CDM_Document::Modify, "Indicates that this document has been modified. This method increments the modification counter.");
	cls_CDM_Document.def("Modifications", (Standard_Integer (CDM_Document::*)() const ) &CDM_Document::Modifications, "returns the current modification counter.");
	cls_CDM_Document.def("UnModify", (void (CDM_Document::*)()) &CDM_Document::UnModify, "None");
	cls_CDM_Document.def("IsUpToDate", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::IsUpToDate, "returns true if the modification counter found in the given reference is equal to the actual modification counter of the To Document. This method is able to deal with a reference to a not retrieved document.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("SetIsUpToDate", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetIsUpToDate, "Resets the modification counter in the given reference to the actual modification counter of its To Document. This method should be called after the application has updated this document.", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("SetComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetComment, "associates a comment with this document.", py::arg("aComment"));
	cls_CDM_Document.def("AddComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::AddComment, "appends a comment into comments of this document.", py::arg("aComment"));
	cls_CDM_Document.def("SetComments", (void (CDM_Document::*)(const TColStd_SequenceOfExtendedString &)) &CDM_Document::SetComments, "associates a comments with this document.", py::arg("aComments"));
	cls_CDM_Document.def("Comments", (void (CDM_Document::*)(TColStd_SequenceOfExtendedString &) const ) &CDM_Document::Comments, "returns the associated comments through <aComments>. Returns empty sequence if no comments are associated.", py::arg("aComments"));
	cls_CDM_Document.def("Comment", (Standard_ExtString (CDM_Document::*)() const ) &CDM_Document::Comment, "returns the first of associated comments. By defaut the comment is an empty string.");
	cls_CDM_Document.def("Presentation", (Standard_ExtString (CDM_Document::*)()) &CDM_Document::Presentation, "Returns an alphanumeric string identifying this document in a unique manner in the current process. The presentation may change when the document is stored. Tries to get the 'FileFormat`.Presentation resource This item is used to give a default presentation to the document.");
	cls_CDM_Document.def_static("FindFromPresentation_", (opencascade::handle<CDM_Document> (*)(const TCollection_ExtendedString &)) &CDM_Document::FindFromPresentation, "returns the document having the given alphanumeric presentation.", py::arg("aPresentation"));
	cls_CDM_Document.def_static("FindPresentation_", (Standard_Boolean (*)(const TCollection_ExtendedString &)) &CDM_Document::FindPresentation, "indicates whether a document having the given presentation does exist.", py::arg("aPresentation"));
	cls_CDM_Document.def("IsStored", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::IsStored, "None");
	cls_CDM_Document.def("StorageVersion", (Standard_Integer (CDM_Document::*)() const ) &CDM_Document::StorageVersion, "returns the value of the modification counter at the time of storage. By default returns 0.");
	cls_CDM_Document.def("SetMetaData", (void (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &)) &CDM_Document::SetMetaData, "associates database information to a document which has been stored. The name of the document is now the name which has beenused to store the data.", py::arg("aMetaData"));
	cls_CDM_Document.def("UnsetIsStored", (void (CDM_Document::*)()) &CDM_Document::UnsetIsStored, "None");
	cls_CDM_Document.def("MetaData", (opencascade::handle<CDM_MetaData> (CDM_Document::*)() const ) &CDM_Document::MetaData, "None");
	cls_CDM_Document.def("Folder", (TCollection_ExtendedString (CDM_Document::*)() const ) &CDM_Document::Folder, "None");
	cls_CDM_Document.def("SetRequestedFolder", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedFolder, "defines the folder in which the object should be stored.", py::arg("aFolder"));
	cls_CDM_Document.def("RequestedFolder", (TCollection_ExtendedString (CDM_Document::*)() const ) &CDM_Document::RequestedFolder, "None");
	cls_CDM_Document.def("HasRequestedFolder", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::HasRequestedFolder, "None");
	cls_CDM_Document.def("SetRequestedName", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedName, "defines the name under which the object should be stored.", py::arg("aName"));
	cls_CDM_Document.def("RequestedName", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::RequestedName, "determines under which the document is going to be store. By default the name of the document wil be -- used. If the document has no name its presentation will be used.");
	cls_CDM_Document.def("SetRequestedPreviousVersion", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedPreviousVersion, "None", py::arg("aPreviousVersion"));
	cls_CDM_Document.def("UnsetRequestedPreviousVersion", (void (CDM_Document::*)()) &CDM_Document::UnsetRequestedPreviousVersion, "None");
	cls_CDM_Document.def("HasRequestedPreviousVersion", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::HasRequestedPreviousVersion, "None");
	cls_CDM_Document.def("RequestedPreviousVersion", (TCollection_ExtendedString (CDM_Document::*)() const ) &CDM_Document::RequestedPreviousVersion, "None");
	cls_CDM_Document.def("SetRequestedComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedComment, "defines the Comment with which the object should be stored.", py::arg("aComment"));
	cls_CDM_Document.def("RequestedComment", (TCollection_ExtendedString (CDM_Document::*)() const ) &CDM_Document::RequestedComment, "None");
	cls_CDM_Document.def("LoadResources", (void (CDM_Document::*)()) &CDM_Document::LoadResources, "read (or rereads) the following resource.");
	cls_CDM_Document.def("FindFileExtension", (Standard_Boolean (CDM_Document::*)()) &CDM_Document::FindFileExtension, "None");
	cls_CDM_Document.def("FileExtension", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::FileExtension, "gets the Desktop.Domain.Application.`FileFormat`.FileExtension resource.");
	cls_CDM_Document.def("FindDescription", (Standard_Boolean (CDM_Document::*)()) &CDM_Document::FindDescription, "None");
	cls_CDM_Document.def("Description", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::Description, "gets the `FileFormat`.Description resource.");
	cls_CDM_Document.def("IsModified", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::IsModified, "returns true if the version is greater than the storage version");
	cls_CDM_Document.def("Print", (Standard_OStream & (CDM_Document::*)(Standard_OStream &) const ) &CDM_Document::Print, "None", py::arg("anOStream"));
	cls_CDM_Document.def("operator<<", (Standard_OStream & (CDM_Document::*)(Standard_OStream &)) &CDM_Document::operator<<, "None", py::arg("anOStream"));
	cls_CDM_Document.def("IsOpened", (Standard_Boolean (CDM_Document::*)() const ) &CDM_Document::IsOpened, "None");
	cls_CDM_Document.def("Open", (void (CDM_Document::*)(const opencascade::handle<CDM_Application> &)) &CDM_Document::Open, "None", py::arg("anApplication"));
	cls_CDM_Document.def("CanClose", (CDM_CanCloseStatus (CDM_Document::*)() const ) &CDM_Document::CanClose, "None");
	cls_CDM_Document.def("Close", (void (CDM_Document::*)()) &CDM_Document::Close, "None");
	cls_CDM_Document.def("Application", (const opencascade::handle<CDM_Application> & (CDM_Document::*)() const ) &CDM_Document::Application, "None");
	cls_CDM_Document.def("CanCloseReference", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer) const ) &CDM_Document::CanCloseReference, "A referenced document may indicate through this virtual method that it does not allow the closing of aDocument which it references through the reference aReferenceIdentifier. By default returns Standard_True;;", py::arg("aDocument"), py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("CloseReference", (void (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer)) &CDM_Document::CloseReference, "A referenced document may update its internal data structure when {aDocument} which it references through the reference {aReferenceIdentifier} is being closed. By default this method does nothing.", py::arg("aDocument"), py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("IsOpened", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::IsOpened, "returns true if the document corresponding to the given reference has been retrieved and opened. Otherwise returns false. This method does not retrieve the referenced document", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("CreateReference", (void (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &, const Standard_Integer, const opencascade::handle<CDM_Application> &, const Standard_Integer, const Standard_Boolean)) &CDM_Document::CreateReference, "None", py::arg("aMetaData"), py::arg("aReferenceIdentifier"), py::arg("anApplication"), py::arg("aToDocumentVersion"), py::arg("UseStorageConfiguration"));
	cls_CDM_Document.def("CreateReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_Application> &, const Standard_Integer, const Standard_Boolean)) &CDM_Document::CreateReference, "None", py::arg("aMetaData"), py::arg("anApplication"), py::arg("aDocumentVersion"), py::arg("UseStorageConfiguration"));
	cls_CDM_Document.def("ReferenceCounter", (Standard_Integer (CDM_Document::*)() const ) &CDM_Document::ReferenceCounter, "None");
	cls_CDM_Document.def("Update", (void (CDM_Document::*)()) &CDM_Document::Update, "the following method should be used instead:");
	cls_CDM_Document.def("Reference", (opencascade::handle<CDM_Reference> (CDM_Document::*)(const Standard_Integer) const ) &CDM_Document::Reference, "None", py::arg("aReferenceIdentifier"));
	cls_CDM_Document.def("SetModifications", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetModifications, "None", py::arg("Modifications"));
	cls_CDM_Document.def("SetReferenceCounter", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetReferenceCounter, "None", py::arg("aReferenceCounter"));
	cls_CDM_Document.def_static("get_type_name_", (const char * (*)()) &CDM_Document::get_type_name, "None");
	cls_CDM_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Document::get_type_descriptor, "None");
	cls_CDM_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Document::*)() const ) &CDM_Document::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_MessageDriver.hxx
	py::class_<CDM_MessageDriver, opencascade::handle<CDM_MessageDriver>, Standard_Transient> cls_CDM_MessageDriver(mod, "CDM_MessageDriver", "None");
	cls_CDM_MessageDriver.def("Write", (void (CDM_MessageDriver::*)(const Standard_ExtString)) &CDM_MessageDriver::Write, "None", py::arg("aString"));
	cls_CDM_MessageDriver.def_static("get_type_name_", (const char * (*)()) &CDM_MessageDriver::get_type_name, "None");
	cls_CDM_MessageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_MessageDriver::get_type_descriptor, "None");
	cls_CDM_MessageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_MessageDriver::*)() const ) &CDM_MessageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_Application.hxx
	py::class_<CDM_Application, opencascade::handle<CDM_Application>, Standard_Transient> cls_CDM_Application(mod, "CDM_Application", "None");
	cls_CDM_Application.def("Resources", (opencascade::handle<Resource_Manager> (CDM_Application::*)()) &CDM_Application::Resources, "The manager returned by this virtual method will be used to search for Format.Retrieval resource items.");
	cls_CDM_Application.def("MessageDriver", (opencascade::handle<CDM_MessageDriver> (CDM_Application::*)()) &CDM_Application::MessageDriver, "By default returns a NullMessageDriver;");
	cls_CDM_Application.def("BeginOfUpdate", (void (CDM_Application::*)(const opencascade::handle<CDM_Document> &)) &CDM_Application::BeginOfUpdate, "this method is called before the update of a document. By default, writes in MessageDriver().", py::arg("aDocument"));
	cls_CDM_Application.def("EndOfUpdate", (void (CDM_Application::*)(const opencascade::handle<CDM_Document> &, const Standard_Boolean, const TCollection_ExtendedString &)) &CDM_Application::EndOfUpdate, "this method is called affter the update of a document. By default, writes in MessageDriver().", py::arg("aDocument"), py::arg("theStatus"), py::arg("ErrorString"));
	cls_CDM_Application.def("Write", (void (CDM_Application::*)(const Standard_ExtString)) &CDM_Application::Write, "writes the string in the application MessagerDriver.", py::arg("aString"));
	cls_CDM_Application.def_static("get_type_name_", (const char * (*)()) &CDM_Application::get_type_name, "None");
	cls_CDM_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Application::get_type_descriptor, "None");
	cls_CDM_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Application::*)() const ) &CDM_Application::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_ReferenceIterator.hxx
	py::class_<CDM_ReferenceIterator, std::unique_ptr<CDM_ReferenceIterator, Deleter<CDM_ReferenceIterator>>> cls_CDM_ReferenceIterator(mod, "CDM_ReferenceIterator", "None");
	cls_CDM_ReferenceIterator.def(py::init<const opencascade::handle<CDM_Document> &>(), py::arg("aDocument"));
	cls_CDM_ReferenceIterator.def("More", (Standard_Boolean (CDM_ReferenceIterator::*)() const ) &CDM_ReferenceIterator::More, "None");
	cls_CDM_ReferenceIterator.def("Next", (void (CDM_ReferenceIterator::*)()) &CDM_ReferenceIterator::Next, "None");
	cls_CDM_ReferenceIterator.def("Document", (opencascade::handle<CDM_Document> (CDM_ReferenceIterator::*)() const ) &CDM_ReferenceIterator::Document, "None");
	cls_CDM_ReferenceIterator.def("ReferenceIdentifier", (Standard_Integer (CDM_ReferenceIterator::*)() const ) &CDM_ReferenceIterator::ReferenceIdentifier, "None");
	cls_CDM_ReferenceIterator.def("DocumentVersion", (Standard_Integer (CDM_ReferenceIterator::*)() const ) &CDM_ReferenceIterator::DocumentVersion, "returns the Document Version in the reference.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_COutMessageDriver.hxx
	py::class_<CDM_COutMessageDriver, opencascade::handle<CDM_COutMessageDriver>, CDM_MessageDriver> cls_CDM_COutMessageDriver(mod, "CDM_COutMessageDriver", "aMessageDriver for output to COUT (only ASCII strings)");
	cls_CDM_COutMessageDriver.def("Write", (void (CDM_COutMessageDriver::*)(const Standard_ExtString)) &CDM_COutMessageDriver::Write, "None", py::arg("aString"));
	cls_CDM_COutMessageDriver.def_static("get_type_name_", (const char * (*)()) &CDM_COutMessageDriver::get_type_name, "None");
	cls_CDM_COutMessageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_COutMessageDriver::get_type_descriptor, "None");
	cls_CDM_COutMessageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_COutMessageDriver::*)() const ) &CDM_COutMessageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_NullMessageDriver.hxx
	py::class_<CDM_NullMessageDriver, opencascade::handle<CDM_NullMessageDriver>, CDM_MessageDriver> cls_CDM_NullMessageDriver(mod, "CDM_NullMessageDriver", "a MessageDriver that writes nowhere.");
	cls_CDM_NullMessageDriver.def(py::init<>());
	cls_CDM_NullMessageDriver.def("Write", (void (CDM_NullMessageDriver::*)(const Standard_ExtString)) &CDM_NullMessageDriver::Write, "None", py::arg("aString"));
	cls_CDM_NullMessageDriver.def_static("get_type_name_", (const char * (*)()) &CDM_NullMessageDriver::get_type_name, "None");
	cls_CDM_NullMessageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_NullMessageDriver::get_type_descriptor, "None");
	cls_CDM_NullMessageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_NullMessageDriver::*)() const ) &CDM_NullMessageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_DocumentPointer.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<CDM_ListOfReferences, std::unique_ptr<CDM_ListOfReferences, Deleter<CDM_ListOfReferences>>, NCollection_BaseList> cls_CDM_ListOfReferences(mod, "CDM_ListOfReferences", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_CDM_ListOfReferences.def(py::init<>());
	cls_CDM_ListOfReferences.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_CDM_ListOfReferences.def(py::init([] (const CDM_ListOfReferences &other) {return new CDM_ListOfReferences(other);}), "Copy constructor", py::arg("other"));
	cls_CDM_ListOfReferences.def("begin", (CDM_ListOfReferences::iterator (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::begin, "Returns an iterator pointing to the first element in the list.");
	cls_CDM_ListOfReferences.def("end", (CDM_ListOfReferences::iterator (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_CDM_ListOfReferences.def("cbegin", (CDM_ListOfReferences::const_iterator (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_CDM_ListOfReferences.def("cend", (CDM_ListOfReferences::const_iterator (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_CDM_ListOfReferences.def("Size", (Standard_Integer (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::Size, "Size - Number of items");
	cls_CDM_ListOfReferences.def("Assign", (CDM_ListOfReferences & (CDM_ListOfReferences::*)(const CDM_ListOfReferences &)) &CDM_ListOfReferences::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_CDM_ListOfReferences.def("assign", (CDM_ListOfReferences & (CDM_ListOfReferences::*)(const CDM_ListOfReferences &)) &CDM_ListOfReferences::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_CDM_ListOfReferences.def("Clear", [](CDM_ListOfReferences &self) -> void { return self.Clear(); });
	cls_CDM_ListOfReferences.def("Clear", (void (CDM_ListOfReferences::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &CDM_ListOfReferences::Clear, "Clear this list", py::arg("theAllocator"));
	cls_CDM_ListOfReferences.def("First", (const opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::First, "First item");
	cls_CDM_ListOfReferences.def("First", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)()) &CDM_ListOfReferences::First, "First item (non-const)");
	cls_CDM_ListOfReferences.def("Last", (const opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)() const ) &CDM_ListOfReferences::Last, "Last item");
	cls_CDM_ListOfReferences.def("Last", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)()) &CDM_ListOfReferences::Last, "Last item (non-const)");
	cls_CDM_ListOfReferences.def("Append", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)(const opencascade::handle<CDM_Reference> &)) &CDM_ListOfReferences::Append, "Append one item at the end", py::arg("theItem"));
	cls_CDM_ListOfReferences.def("Append", (void (CDM_ListOfReferences::*)(const opencascade::handle<CDM_Reference> &, CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfReferences.def("Append", (void (CDM_ListOfReferences::*)(CDM_ListOfReferences &)) &CDM_ListOfReferences::Append, "Append another list at the end", py::arg("theOther"));
	cls_CDM_ListOfReferences.def("Prepend", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)(const opencascade::handle<CDM_Reference> &)) &CDM_ListOfReferences::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_CDM_ListOfReferences.def("Prepend", (void (CDM_ListOfReferences::*)(CDM_ListOfReferences &)) &CDM_ListOfReferences::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_CDM_ListOfReferences.def("RemoveFirst", (void (CDM_ListOfReferences::*)()) &CDM_ListOfReferences::RemoveFirst, "RemoveFirst item");
	cls_CDM_ListOfReferences.def("Remove", (void (CDM_ListOfReferences::*)(CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_CDM_ListOfReferences.def("InsertBefore", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)(const opencascade::handle<CDM_Reference> &, CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfReferences.def("InsertBefore", (void (CDM_ListOfReferences::*)(CDM_ListOfReferences &, CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_CDM_ListOfReferences.def("InsertAfter", (opencascade::handle<CDM_Reference> & (CDM_ListOfReferences::*)(const opencascade::handle<CDM_Reference> &, CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfReferences.def("InsertAfter", (void (CDM_ListOfReferences::*)(CDM_ListOfReferences &, CDM_ListOfReferences::Iterator &)) &CDM_ListOfReferences::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_CDM_ListOfReferences.def("Reverse", (void (CDM_ListOfReferences::*)()) &CDM_ListOfReferences::Reverse, "Reverse the list");
	cls_CDM_ListOfReferences.def("__iter__", [](const CDM_ListOfReferences &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<CDM_ListIteratorOfListOfReferences, std::unique_ptr<CDM_ListIteratorOfListOfReferences, Deleter<CDM_ListIteratorOfListOfReferences>>> cls_CDM_ListIteratorOfListOfReferences(mod, "CDM_ListIteratorOfListOfReferences", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_CDM_ListIteratorOfListOfReferences.def(py::init<>());
	cls_CDM_ListIteratorOfListOfReferences.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_CDM_ListIteratorOfListOfReferences.def("More", (Standard_Boolean (CDM_ListIteratorOfListOfReferences::*)() const ) &CDM_ListIteratorOfListOfReferences::More, "Check end");
	cls_CDM_ListIteratorOfListOfReferences.def("Next", (void (CDM_ListIteratorOfListOfReferences::*)()) &CDM_ListIteratorOfListOfReferences::Next, "Make step");
	cls_CDM_ListIteratorOfListOfReferences.def("Value", (const opencascade::handle<CDM_Reference> & (CDM_ListIteratorOfListOfReferences::*)() const ) &CDM_ListIteratorOfListOfReferences::Value, "Constant Value access");
	cls_CDM_ListIteratorOfListOfReferences.def("Value", (opencascade::handle<CDM_Reference> & (CDM_ListIteratorOfListOfReferences::*)()) &CDM_ListIteratorOfListOfReferences::Value, "Non-const Value access");
	cls_CDM_ListIteratorOfListOfReferences.def("ChangeValue", (opencascade::handle<CDM_Reference> & (CDM_ListIteratorOfListOfReferences::*)() const ) &CDM_ListIteratorOfListOfReferences::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<CDM_ListOfDocument, std::unique_ptr<CDM_ListOfDocument, Deleter<CDM_ListOfDocument>>, NCollection_BaseList> cls_CDM_ListOfDocument(mod, "CDM_ListOfDocument", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_CDM_ListOfDocument.def(py::init<>());
	cls_CDM_ListOfDocument.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_CDM_ListOfDocument.def(py::init([] (const CDM_ListOfDocument &other) {return new CDM_ListOfDocument(other);}), "Copy constructor", py::arg("other"));
	cls_CDM_ListOfDocument.def("begin", (CDM_ListOfDocument::iterator (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::begin, "Returns an iterator pointing to the first element in the list.");
	cls_CDM_ListOfDocument.def("end", (CDM_ListOfDocument::iterator (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_CDM_ListOfDocument.def("cbegin", (CDM_ListOfDocument::const_iterator (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_CDM_ListOfDocument.def("cend", (CDM_ListOfDocument::const_iterator (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_CDM_ListOfDocument.def("Size", (Standard_Integer (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::Size, "Size - Number of items");
	cls_CDM_ListOfDocument.def("Assign", (CDM_ListOfDocument & (CDM_ListOfDocument::*)(const CDM_ListOfDocument &)) &CDM_ListOfDocument::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_CDM_ListOfDocument.def("assign", (CDM_ListOfDocument & (CDM_ListOfDocument::*)(const CDM_ListOfDocument &)) &CDM_ListOfDocument::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_CDM_ListOfDocument.def("Clear", [](CDM_ListOfDocument &self) -> void { return self.Clear(); });
	cls_CDM_ListOfDocument.def("Clear", (void (CDM_ListOfDocument::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &CDM_ListOfDocument::Clear, "Clear this list", py::arg("theAllocator"));
	cls_CDM_ListOfDocument.def("First", (const opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::First, "First item");
	cls_CDM_ListOfDocument.def("First", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)()) &CDM_ListOfDocument::First, "First item (non-const)");
	cls_CDM_ListOfDocument.def("Last", (const opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)() const ) &CDM_ListOfDocument::Last, "Last item");
	cls_CDM_ListOfDocument.def("Last", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)()) &CDM_ListOfDocument::Last, "Last item (non-const)");
	cls_CDM_ListOfDocument.def("Append", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)(const opencascade::handle<CDM_Document> &)) &CDM_ListOfDocument::Append, "Append one item at the end", py::arg("theItem"));
	cls_CDM_ListOfDocument.def("Append", (void (CDM_ListOfDocument::*)(const opencascade::handle<CDM_Document> &, CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfDocument.def("Append", (void (CDM_ListOfDocument::*)(CDM_ListOfDocument &)) &CDM_ListOfDocument::Append, "Append another list at the end", py::arg("theOther"));
	cls_CDM_ListOfDocument.def("Prepend", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)(const opencascade::handle<CDM_Document> &)) &CDM_ListOfDocument::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_CDM_ListOfDocument.def("Prepend", (void (CDM_ListOfDocument::*)(CDM_ListOfDocument &)) &CDM_ListOfDocument::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_CDM_ListOfDocument.def("RemoveFirst", (void (CDM_ListOfDocument::*)()) &CDM_ListOfDocument::RemoveFirst, "RemoveFirst item");
	cls_CDM_ListOfDocument.def("Remove", (void (CDM_ListOfDocument::*)(CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_CDM_ListOfDocument.def("InsertBefore", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)(const opencascade::handle<CDM_Document> &, CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfDocument.def("InsertBefore", (void (CDM_ListOfDocument::*)(CDM_ListOfDocument &, CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_CDM_ListOfDocument.def("InsertAfter", (opencascade::handle<CDM_Document> & (CDM_ListOfDocument::*)(const opencascade::handle<CDM_Document> &, CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_CDM_ListOfDocument.def("InsertAfter", (void (CDM_ListOfDocument::*)(CDM_ListOfDocument &, CDM_ListOfDocument::Iterator &)) &CDM_ListOfDocument::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_CDM_ListOfDocument.def("Reverse", (void (CDM_ListOfDocument::*)()) &CDM_ListOfDocument::Reverse, "Reverse the list");
	cls_CDM_ListOfDocument.def("__iter__", [](const CDM_ListOfDocument &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<CDM_ListIteratorOfListOfDocument, std::unique_ptr<CDM_ListIteratorOfListOfDocument, Deleter<CDM_ListIteratorOfListOfDocument>>> cls_CDM_ListIteratorOfListOfDocument(mod, "CDM_ListIteratorOfListOfDocument", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_CDM_ListIteratorOfListOfDocument.def(py::init<>());
	cls_CDM_ListIteratorOfListOfDocument.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_CDM_ListIteratorOfListOfDocument.def("More", (Standard_Boolean (CDM_ListIteratorOfListOfDocument::*)() const ) &CDM_ListIteratorOfListOfDocument::More, "Check end");
	cls_CDM_ListIteratorOfListOfDocument.def("Next", (void (CDM_ListIteratorOfListOfDocument::*)()) &CDM_ListIteratorOfListOfDocument::Next, "Make step");
	cls_CDM_ListIteratorOfListOfDocument.def("Value", (const opencascade::handle<CDM_Document> & (CDM_ListIteratorOfListOfDocument::*)() const ) &CDM_ListIteratorOfListOfDocument::Value, "Constant Value access");
	cls_CDM_ListIteratorOfListOfDocument.def("Value", (opencascade::handle<CDM_Document> & (CDM_ListIteratorOfListOfDocument::*)()) &CDM_ListIteratorOfListOfDocument::Value, "Non-const Value access");
	cls_CDM_ListIteratorOfListOfDocument.def("ChangeValue", (opencascade::handle<CDM_Document> & (CDM_ListIteratorOfListOfDocument::*)() const ) &CDM_ListIteratorOfListOfDocument::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<CDM_DocumentHasher, std::unique_ptr<CDM_DocumentHasher, Deleter<CDM_DocumentHasher>>> cls_CDM_DocumentHasher(mod, "CDM_DocumentHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_CDM_DocumentHasher.def(py::init<>());
	cls_CDM_DocumentHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<CDM_Document> &, const Standard_Integer)) &CDM_DocumentHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_CDM_DocumentHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Document> &)) &CDM_DocumentHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<CDM_MapOfDocument, std::unique_ptr<CDM_MapOfDocument, Deleter<CDM_MapOfDocument>>, NCollection_BaseMap> cls_CDM_MapOfDocument(mod, "CDM_MapOfDocument", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_CDM_MapOfDocument.def(py::init<>());
	cls_CDM_MapOfDocument.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_CDM_MapOfDocument.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_CDM_MapOfDocument.def(py::init([] (const CDM_MapOfDocument &other) {return new CDM_MapOfDocument(other);}), "Copy constructor", py::arg("other"));
	cls_CDM_MapOfDocument.def("cbegin", (CDM_MapOfDocument::const_iterator (CDM_MapOfDocument::*)() const ) &CDM_MapOfDocument::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_CDM_MapOfDocument.def("cend", (CDM_MapOfDocument::const_iterator (CDM_MapOfDocument::*)() const ) &CDM_MapOfDocument::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_CDM_MapOfDocument.def("Exchange", (void (CDM_MapOfDocument::*)(CDM_MapOfDocument &)) &CDM_MapOfDocument::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("Assign", (CDM_MapOfDocument & (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("assign", (CDM_MapOfDocument & (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("ReSize", (void (CDM_MapOfDocument::*)(const Standard_Integer)) &CDM_MapOfDocument::ReSize, "ReSize", py::arg("N"));
	cls_CDM_MapOfDocument.def("Add", (Standard_Boolean (CDM_MapOfDocument::*)(const opencascade::handle<CDM_Document> &)) &CDM_MapOfDocument::Add, "Add", py::arg("K"));
	cls_CDM_MapOfDocument.def("Added", (const opencascade::handle<CDM_Document> & (CDM_MapOfDocument::*)(const opencascade::handle<CDM_Document> &)) &CDM_MapOfDocument::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_CDM_MapOfDocument.def("Contains", (Standard_Boolean (CDM_MapOfDocument::*)(const opencascade::handle<CDM_Document> &) const ) &CDM_MapOfDocument::Contains, "Contains", py::arg("K"));
	cls_CDM_MapOfDocument.def("Remove", (Standard_Boolean (CDM_MapOfDocument::*)(const opencascade::handle<CDM_Document> &)) &CDM_MapOfDocument::Remove, "Remove", py::arg("K"));
	cls_CDM_MapOfDocument.def("Clear", [](CDM_MapOfDocument &self) -> void { return self.Clear(); });
	cls_CDM_MapOfDocument.def("Clear", (void (CDM_MapOfDocument::*)(const Standard_Boolean)) &CDM_MapOfDocument::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_CDM_MapOfDocument.def("Clear", (void (CDM_MapOfDocument::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &CDM_MapOfDocument::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_CDM_MapOfDocument.def("Size", (Standard_Integer (CDM_MapOfDocument::*)() const ) &CDM_MapOfDocument::Size, "Size");
	cls_CDM_MapOfDocument.def("IsEqual", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &) const ) &CDM_MapOfDocument::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("Contains", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &) const ) &CDM_MapOfDocument::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("Union", (void (CDM_MapOfDocument::*)(const CDM_MapOfDocument &, const CDM_MapOfDocument &)) &CDM_MapOfDocument::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_CDM_MapOfDocument.def("Unite", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("HasIntersection", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &) const ) &CDM_MapOfDocument::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_CDM_MapOfDocument.def("Intersection", (void (CDM_MapOfDocument::*)(const CDM_MapOfDocument &, const CDM_MapOfDocument &)) &CDM_MapOfDocument::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_CDM_MapOfDocument.def("Intersect", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("Subtraction", (void (CDM_MapOfDocument::*)(const CDM_MapOfDocument &, const CDM_MapOfDocument &)) &CDM_MapOfDocument::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_CDM_MapOfDocument.def("Subtract", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_CDM_MapOfDocument.def("Difference", (void (CDM_MapOfDocument::*)(const CDM_MapOfDocument &, const CDM_MapOfDocument &)) &CDM_MapOfDocument::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_CDM_MapOfDocument.def("Differ", (Standard_Boolean (CDM_MapOfDocument::*)(const CDM_MapOfDocument &)) &CDM_MapOfDocument::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_MapOfDocument.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<CDM_MetaDataLookUpTable, std::unique_ptr<CDM_MetaDataLookUpTable, Deleter<CDM_MetaDataLookUpTable>>, NCollection_BaseMap> cls_CDM_MetaDataLookUpTable(mod, "CDM_MetaDataLookUpTable", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_CDM_MetaDataLookUpTable.def(py::init<>());
	cls_CDM_MetaDataLookUpTable.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_CDM_MetaDataLookUpTable.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_CDM_MetaDataLookUpTable.def(py::init([] (const CDM_MetaDataLookUpTable &other) {return new CDM_MetaDataLookUpTable(other);}), "Copy constructor", py::arg("other"));
	cls_CDM_MetaDataLookUpTable.def("begin", (CDM_MetaDataLookUpTable::iterator (CDM_MetaDataLookUpTable::*)() const ) &CDM_MetaDataLookUpTable::begin, "Returns an iterator pointing to the first element in the map.");
	cls_CDM_MetaDataLookUpTable.def("end", (CDM_MetaDataLookUpTable::iterator (CDM_MetaDataLookUpTable::*)() const ) &CDM_MetaDataLookUpTable::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_CDM_MetaDataLookUpTable.def("cbegin", (CDM_MetaDataLookUpTable::const_iterator (CDM_MetaDataLookUpTable::*)() const ) &CDM_MetaDataLookUpTable::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_CDM_MetaDataLookUpTable.def("cend", (CDM_MetaDataLookUpTable::const_iterator (CDM_MetaDataLookUpTable::*)() const ) &CDM_MetaDataLookUpTable::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_CDM_MetaDataLookUpTable.def("Exchange", (void (CDM_MetaDataLookUpTable::*)(CDM_MetaDataLookUpTable &)) &CDM_MetaDataLookUpTable::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_CDM_MetaDataLookUpTable.def("Assign", (CDM_MetaDataLookUpTable & (CDM_MetaDataLookUpTable::*)(const CDM_MetaDataLookUpTable &)) &CDM_MetaDataLookUpTable::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_CDM_MetaDataLookUpTable.def("assign", (CDM_MetaDataLookUpTable & (CDM_MetaDataLookUpTable::*)(const CDM_MetaDataLookUpTable &)) &CDM_MetaDataLookUpTable::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_CDM_MetaDataLookUpTable.def("ReSize", (void (CDM_MetaDataLookUpTable::*)(const Standard_Integer)) &CDM_MetaDataLookUpTable::ReSize, "ReSize", py::arg("N"));
	cls_CDM_MetaDataLookUpTable.def("Bind", (Standard_Boolean (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MetaData> &)) &CDM_MetaDataLookUpTable::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_CDM_MetaDataLookUpTable.def("Bound", (opencascade::handle<CDM_MetaData> * (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_MetaData> &)) &CDM_MetaDataLookUpTable::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_CDM_MetaDataLookUpTable.def("IsBound", (Standard_Boolean (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &) const ) &CDM_MetaDataLookUpTable::IsBound, "IsBound", py::arg("theKey"));
	cls_CDM_MetaDataLookUpTable.def("UnBind", (Standard_Boolean (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &)) &CDM_MetaDataLookUpTable::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_CDM_MetaDataLookUpTable.def("Seek", (const opencascade::handle<CDM_MetaData> * (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &) const ) &CDM_MetaDataLookUpTable::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_CDM_MetaDataLookUpTable.def("Find", (const opencascade::handle<CDM_MetaData> & (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &) const ) &CDM_MetaDataLookUpTable::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_CDM_MetaDataLookUpTable.def("Find", (Standard_Boolean (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &, opencascade::handle<CDM_MetaData> &) const ) &CDM_MetaDataLookUpTable::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_CDM_MetaDataLookUpTable.def("__call__", (const opencascade::handle<CDM_MetaData> & (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &) const ) &CDM_MetaDataLookUpTable::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_CDM_MetaDataLookUpTable.def("ChangeSeek", (opencascade::handle<CDM_MetaData> * (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &)) &CDM_MetaDataLookUpTable::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_CDM_MetaDataLookUpTable.def("ChangeFind", (opencascade::handle<CDM_MetaData> & (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &)) &CDM_MetaDataLookUpTable::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_CDM_MetaDataLookUpTable.def("__call__", (opencascade::handle<CDM_MetaData> & (CDM_MetaDataLookUpTable::*)(const TCollection_ExtendedString &)) &CDM_MetaDataLookUpTable::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_CDM_MetaDataLookUpTable.def("Clear", [](CDM_MetaDataLookUpTable &self) -> void { return self.Clear(); });
	cls_CDM_MetaDataLookUpTable.def("Clear", (void (CDM_MetaDataLookUpTable::*)(const Standard_Boolean)) &CDM_MetaDataLookUpTable::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_CDM_MetaDataLookUpTable.def("Clear", (void (CDM_MetaDataLookUpTable::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &CDM_MetaDataLookUpTable::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_CDM_MetaDataLookUpTable.def("Size", (Standard_Integer (CDM_MetaDataLookUpTable::*)() const ) &CDM_MetaDataLookUpTable::Size, "Size");
	cls_CDM_MetaDataLookUpTable.def("__iter__", [](const CDM_MetaDataLookUpTable &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_MetaDataLookUpTable.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<CDM_PresentationDirectory, std::unique_ptr<CDM_PresentationDirectory, Deleter<CDM_PresentationDirectory>>, NCollection_BaseMap> cls_CDM_PresentationDirectory(mod, "CDM_PresentationDirectory", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_CDM_PresentationDirectory.def(py::init<>());
	cls_CDM_PresentationDirectory.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_CDM_PresentationDirectory.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_CDM_PresentationDirectory.def(py::init([] (const CDM_PresentationDirectory &other) {return new CDM_PresentationDirectory(other);}), "Copy constructor", py::arg("other"));
	cls_CDM_PresentationDirectory.def("begin", (CDM_PresentationDirectory::iterator (CDM_PresentationDirectory::*)() const ) &CDM_PresentationDirectory::begin, "Returns an iterator pointing to the first element in the map.");
	cls_CDM_PresentationDirectory.def("end", (CDM_PresentationDirectory::iterator (CDM_PresentationDirectory::*)() const ) &CDM_PresentationDirectory::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_CDM_PresentationDirectory.def("cbegin", (CDM_PresentationDirectory::const_iterator (CDM_PresentationDirectory::*)() const ) &CDM_PresentationDirectory::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_CDM_PresentationDirectory.def("cend", (CDM_PresentationDirectory::const_iterator (CDM_PresentationDirectory::*)() const ) &CDM_PresentationDirectory::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_CDM_PresentationDirectory.def("Exchange", (void (CDM_PresentationDirectory::*)(CDM_PresentationDirectory &)) &CDM_PresentationDirectory::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_CDM_PresentationDirectory.def("Assign", (CDM_PresentationDirectory & (CDM_PresentationDirectory::*)(const CDM_PresentationDirectory &)) &CDM_PresentationDirectory::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_CDM_PresentationDirectory.def("assign", (CDM_PresentationDirectory & (CDM_PresentationDirectory::*)(const CDM_PresentationDirectory &)) &CDM_PresentationDirectory::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_CDM_PresentationDirectory.def("ReSize", (void (CDM_PresentationDirectory::*)(const Standard_Integer)) &CDM_PresentationDirectory::ReSize, "ReSize", py::arg("N"));
	cls_CDM_PresentationDirectory.def("Bind", (Standard_Boolean (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &)) &CDM_PresentationDirectory::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_CDM_PresentationDirectory.def("Bound", (opencascade::handle<CDM_Document> * (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &)) &CDM_PresentationDirectory::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_CDM_PresentationDirectory.def("IsBound", (Standard_Boolean (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &) const ) &CDM_PresentationDirectory::IsBound, "IsBound", py::arg("theKey"));
	cls_CDM_PresentationDirectory.def("UnBind", (Standard_Boolean (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &)) &CDM_PresentationDirectory::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_CDM_PresentationDirectory.def("Seek", (const opencascade::handle<CDM_Document> * (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &) const ) &CDM_PresentationDirectory::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_CDM_PresentationDirectory.def("Find", (const opencascade::handle<CDM_Document> & (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &) const ) &CDM_PresentationDirectory::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_CDM_PresentationDirectory.def("Find", (Standard_Boolean (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &, opencascade::handle<CDM_Document> &) const ) &CDM_PresentationDirectory::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_CDM_PresentationDirectory.def("__call__", (const opencascade::handle<CDM_Document> & (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &) const ) &CDM_PresentationDirectory::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_CDM_PresentationDirectory.def("ChangeSeek", (opencascade::handle<CDM_Document> * (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &)) &CDM_PresentationDirectory::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_CDM_PresentationDirectory.def("ChangeFind", (opencascade::handle<CDM_Document> & (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &)) &CDM_PresentationDirectory::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_CDM_PresentationDirectory.def("__call__", (opencascade::handle<CDM_Document> & (CDM_PresentationDirectory::*)(const TCollection_ExtendedString &)) &CDM_PresentationDirectory::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_CDM_PresentationDirectory.def("Clear", [](CDM_PresentationDirectory &self) -> void { return self.Clear(); });
	cls_CDM_PresentationDirectory.def("Clear", (void (CDM_PresentationDirectory::*)(const Standard_Boolean)) &CDM_PresentationDirectory::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_CDM_PresentationDirectory.def("Clear", (void (CDM_PresentationDirectory::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &CDM_PresentationDirectory::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_CDM_PresentationDirectory.def("Size", (Standard_Integer (CDM_PresentationDirectory::*)() const ) &CDM_PresentationDirectory::Size, "Size");
	cls_CDM_PresentationDirectory.def("__iter__", [](const CDM_PresentationDirectory &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\CDM_PresentationDirectory.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfStringInteger")) {
		mod.attr("CDM_NamesDirectory") = other_mod.attr("TColStd_DataMapOfStringInteger");
	}


}
