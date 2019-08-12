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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <CDM_MetaData.hxx>
#include <Standard_OStream.hxx>
#include <CDM_Application.hxx>
#include <CDM_CanCloseStatus.hxx>
#include <CDM_Reference.hxx>
#include <CDM_ReferenceIterator.hxx>
#include <Standard_Type.hxx>
#include <Resource_Manager.hxx>
#include <CDM_ListOfReferences.hxx>

void bind_CDM_Document(py::module &mod){

py::class_<CDM_Document, opencascade::handle<CDM_Document>, Standard_Transient> cls_CDM_Document(mod, "CDM_Document", "An applicative document is an instance of a class inheriting CDM_Document. These documents have the following properties: - they can have references to other documents. - the modifications of a document are propagated to the referencing documents. - a document can be stored in different formats, with or without a persistent model. - the drivers for storing and retrieving documents are plugged in when necessary. - a document has a modification counter. This counter is incremented when the document is modified. When a document is stored, the current counter value is memorized as the last storage version of the document. A document is considered to be modified when the counter value is different from the storage version. Once the document is saved the storage version and the counter value are identical. The document is now not considered to be modified. - a reference is a link between two documents. A reference has two components: the 'From Document' and the 'To Document'. When a reference is created, an identifier of the reference is generated. This identifier is unique in the scope of the From Document and is conserved during storage and retrieval. This means that the referenced document will be always accessible through this identifier. - a reference memorizes the counter value of the To Document when the reference is created. The From Document is considered to be up to date relative to the To Document when the reference counter value is equal to the To Document counter value. - retrieval of a document having references does not imply the retrieving of the referenced documents.");

// Fields

// Methods
cls_CDM_Document.def("Update", (void (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer, const Standard_Address)) &CDM_Document::Update, "The Update method will be called once for each reference, but it should not perform any computation, to avoid multiple computation of a same document.", py::arg("aToDocument"), py::arg("aReferenceIdentifier"), py::arg("aModifContext"));
cls_CDM_Document.def("Update", (Standard_Boolean (CDM_Document::*)(TCollection_ExtendedString &)) &CDM_Document::Update, "This method Update will be called to signal the end of the modified references list. The document should be recomputed and UpdateFromDocuments should be called. Update should returns True in case of success, false otherwise. In case of Failure, additional information can be given in ErrorString.", py::arg("ErrorString"));
cls_CDM_Document.def("StorageFormat", (TCollection_ExtendedString (CDM_Document::*)() const) &CDM_Document::StorageFormat, "The Storage Format is the key which is used to determine in the application resources the storage driver plugin, the file extension and other data used to store the document.");
cls_CDM_Document.def("Extensions", (void (CDM_Document::*)(TColStd_SequenceOfExtendedString &) const) &CDM_Document::Extensions, "by default empties the extensions.", py::arg("Extensions"));
cls_CDM_Document.def("GetAlternativeDocument", (Standard_Boolean (CDM_Document::*)(const TCollection_ExtendedString &, opencascade::handle<CDM_Document> &)) &CDM_Document::GetAlternativeDocument, "This method can be redefined to extract another document in a different format. For example, to extract a Shape from an applicative document.", py::arg("aFormat"), py::arg("anAlternativeDocument"));
cls_CDM_Document.def("CreateReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_Document> &)) &CDM_Document::CreateReference, "Creates a reference from this document to {anOtherDocument}. Returns a reference identifier. This reference identifier is unique in the document and will not be used for the next references, even after the storing of the document. If there is already a reference between the two documents, the reference is not created, but its reference identifier is returned.", py::arg("anOtherDocument"));
cls_CDM_Document.def("RemoveReference", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::RemoveReference, "Removes the reference between the From Document and the To Document identified by a reference identifier.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("RemoveAllReferences", (void (CDM_Document::*)()) &CDM_Document::RemoveAllReferences, "Removes all references having this document for From Document.");
cls_CDM_Document.def("Document", (opencascade::handle<CDM_Document> (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::Document, "Returns the To Document of the reference identified by aReferenceIdentifier. If the ToDocument is stored and has not yet been retrieved, this method will retrieve it.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("IsInSession", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::IsInSession, "returns True if the To Document of the reference identified by aReferenceIdentifier is in session, False if it corresponds to a not yet retrieved document.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("IsStored", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::IsStored, "returns True if the To Document of the reference identified by aReferenceIdentifier has already been stored, False otherwise.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("Name", (TCollection_ExtendedString (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::Name, "returns the name of the metadata of the To Document of the reference identified by aReferenceIdentifier.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("UpdateFromDocuments", (void (CDM_Document::*)(const Standard_Address) const) &CDM_Document::UpdateFromDocuments, "call virtual method Update on all referencing documents. This method keeps the list of the -- documents to process.It may be the starting of an update -- cycle. If not, the reentrant calls made by Update method (without argument) will append the referencing documents to the list and call the Update method (with arguments). Only the first call to UpdateFromDocuments generate call to Update().", py::arg("aModifContext"));
cls_CDM_Document.def("ToReferencesNumber", (Standard_Integer (CDM_Document::*)() const) &CDM_Document::ToReferencesNumber, "returns the number of references having this document as From Document.");
cls_CDM_Document.def("FromReferencesNumber", (Standard_Integer (CDM_Document::*)() const) &CDM_Document::FromReferencesNumber, "returns the number of references having this document as To Document.");
cls_CDM_Document.def("ShallowReferences", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &) const) &CDM_Document::ShallowReferences, "returns True is this document references aDocument;", py::arg("aDocument"));
cls_CDM_Document.def("DeepReferences", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &) const) &CDM_Document::DeepReferences, "returns True is this document references aDocument;", py::arg("aDocument"));
cls_CDM_Document.def("CopyReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer)) &CDM_Document::CopyReference, "Copies a reference to this document. This method avoid retrieval of referenced document. The arguments are the original document and a valid reference identifier Returns the local identifier.", py::arg("aFromDocument"), py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("IsReadOnly", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::IsReadOnly, "indicates that this document cannot be modified.");
cls_CDM_Document.def("IsReadOnly", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::IsReadOnly, "indicates that the referenced document cannot be modified,", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("SetIsReadOnly", (void (CDM_Document::*)()) &CDM_Document::SetIsReadOnly, "None");
cls_CDM_Document.def("UnsetIsReadOnly", (void (CDM_Document::*)()) &CDM_Document::UnsetIsReadOnly, "None");
cls_CDM_Document.def("Modify", (void (CDM_Document::*)()) &CDM_Document::Modify, "Indicates that this document has been modified. This method increments the modification counter.");
cls_CDM_Document.def("Modifications", (Standard_Integer (CDM_Document::*)() const) &CDM_Document::Modifications, "returns the current modification counter.");
cls_CDM_Document.def("UnModify", (void (CDM_Document::*)()) &CDM_Document::UnModify, "None");
cls_CDM_Document.def("IsUpToDate", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::IsUpToDate, "returns true if the modification counter found in the given reference is equal to the actual modification counter of the To Document. This method is able to deal with a reference to a not retrieved document.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("SetIsUpToDate", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetIsUpToDate, "Resets the modification counter in the given reference to the actual modification counter of its To Document. This method should be called after the application has updated this document.", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("SetComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetComment, "associates a comment with this document.", py::arg("aComment"));
cls_CDM_Document.def("AddComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::AddComment, "appends a comment into comments of this document.", py::arg("aComment"));
cls_CDM_Document.def("SetComments", (void (CDM_Document::*)(const TColStd_SequenceOfExtendedString &)) &CDM_Document::SetComments, "associates a comments with this document.", py::arg("aComments"));
cls_CDM_Document.def("Comments", (void (CDM_Document::*)(TColStd_SequenceOfExtendedString &) const) &CDM_Document::Comments, "returns the associated comments through <aComments>. Returns empty sequence if no comments are associated.", py::arg("aComments"));
cls_CDM_Document.def("Comment", (Standard_ExtString (CDM_Document::*)() const) &CDM_Document::Comment, "returns the first of associated comments. By defaut the comment is an empty string.");
cls_CDM_Document.def("Presentation", (Standard_ExtString (CDM_Document::*)()) &CDM_Document::Presentation, "Returns an alphanumeric string identifying this document in a unique manner in the current process. The presentation may change when the document is stored. Tries to get the 'FileFormat`.Presentation resource This item is used to give a default presentation to the document.");
cls_CDM_Document.def_static("FindFromPresentation_", (opencascade::handle<CDM_Document> (*)(const TCollection_ExtendedString &)) &CDM_Document::FindFromPresentation, "returns the document having the given alphanumeric presentation.", py::arg("aPresentation"));
cls_CDM_Document.def_static("FindPresentation_", (Standard_Boolean (*)(const TCollection_ExtendedString &)) &CDM_Document::FindPresentation, "indicates whether a document having the given presentation does exist.", py::arg("aPresentation"));
cls_CDM_Document.def("IsStored", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::IsStored, "None");
cls_CDM_Document.def("StorageVersion", (Standard_Integer (CDM_Document::*)() const) &CDM_Document::StorageVersion, "returns the value of the modification counter at the time of storage. By default returns 0.");
cls_CDM_Document.def("SetMetaData", (void (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &)) &CDM_Document::SetMetaData, "associates database information to a document which has been stored. The name of the document is now the name which has beenused to store the data.", py::arg("aMetaData"));
cls_CDM_Document.def("UnsetIsStored", (void (CDM_Document::*)()) &CDM_Document::UnsetIsStored, "None");
cls_CDM_Document.def("MetaData", (opencascade::handle<CDM_MetaData> (CDM_Document::*)() const) &CDM_Document::MetaData, "None");
cls_CDM_Document.def("Folder", (TCollection_ExtendedString (CDM_Document::*)() const) &CDM_Document::Folder, "None");
cls_CDM_Document.def("SetRequestedFolder", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedFolder, "defines the folder in which the object should be stored.", py::arg("aFolder"));
cls_CDM_Document.def("RequestedFolder", (TCollection_ExtendedString (CDM_Document::*)() const) &CDM_Document::RequestedFolder, "None");
cls_CDM_Document.def("HasRequestedFolder", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::HasRequestedFolder, "None");
cls_CDM_Document.def("SetRequestedName", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedName, "defines the name under which the object should be stored.", py::arg("aName"));
cls_CDM_Document.def("RequestedName", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::RequestedName, "determines under which the document is going to be store. By default the name of the document wil be -- used. If the document has no name its presentation will be used.");
cls_CDM_Document.def("SetRequestedPreviousVersion", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedPreviousVersion, "None", py::arg("aPreviousVersion"));
cls_CDM_Document.def("UnsetRequestedPreviousVersion", (void (CDM_Document::*)()) &CDM_Document::UnsetRequestedPreviousVersion, "None");
cls_CDM_Document.def("HasRequestedPreviousVersion", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::HasRequestedPreviousVersion, "None");
cls_CDM_Document.def("RequestedPreviousVersion", (TCollection_ExtendedString (CDM_Document::*)() const) &CDM_Document::RequestedPreviousVersion, "None");
cls_CDM_Document.def("SetRequestedComment", (void (CDM_Document::*)(const TCollection_ExtendedString &)) &CDM_Document::SetRequestedComment, "defines the Comment with which the object should be stored.", py::arg("aComment"));
cls_CDM_Document.def("RequestedComment", (TCollection_ExtendedString (CDM_Document::*)() const) &CDM_Document::RequestedComment, "None");
cls_CDM_Document.def("LoadResources", (void (CDM_Document::*)()) &CDM_Document::LoadResources, "read (or rereads) the following resource.");
cls_CDM_Document.def("FindFileExtension", (Standard_Boolean (CDM_Document::*)()) &CDM_Document::FindFileExtension, "None");
cls_CDM_Document.def("FileExtension", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::FileExtension, "gets the Desktop.Domain.Application.`FileFormat`.FileExtension resource.");
cls_CDM_Document.def("FindDescription", (Standard_Boolean (CDM_Document::*)()) &CDM_Document::FindDescription, "None");
cls_CDM_Document.def("Description", (TCollection_ExtendedString (CDM_Document::*)()) &CDM_Document::Description, "gets the `FileFormat`.Description resource.");
cls_CDM_Document.def("IsModified", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::IsModified, "returns true if the version is greater than the storage version");
cls_CDM_Document.def("Print", (Standard_OStream & (CDM_Document::*)(Standard_OStream &) const) &CDM_Document::Print, "None", py::arg("anOStream"));
// cls_CDM_Document.def("bits_left", (Standard_OStream & (CDM_Document::*)(Standard_OStream &)) &CDM_Document::operator<<, py::is_operator(), "None", py::arg("anOStream"));
cls_CDM_Document.def("IsOpened", (Standard_Boolean (CDM_Document::*)() const) &CDM_Document::IsOpened, "None");
cls_CDM_Document.def("Open", (void (CDM_Document::*)(const opencascade::handle<CDM_Application> &)) &CDM_Document::Open, "None", py::arg("anApplication"));
cls_CDM_Document.def("CanClose", (CDM_CanCloseStatus (CDM_Document::*)() const) &CDM_Document::CanClose, "None");
cls_CDM_Document.def("Close", (void (CDM_Document::*)()) &CDM_Document::Close, "None");
cls_CDM_Document.def("Application", (const opencascade::handle<CDM_Application> & (CDM_Document::*)() const) &CDM_Document::Application, "None");
cls_CDM_Document.def("CanCloseReference", (Standard_Boolean (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer) const) &CDM_Document::CanCloseReference, "A referenced document may indicate through this virtual method that it does not allow the closing of aDocument which it references through the reference aReferenceIdentifier. By default returns Standard_True;;", py::arg("aDocument"), py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("CloseReference", (void (CDM_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer)) &CDM_Document::CloseReference, "A referenced document may update its internal data structure when {aDocument} which it references through the reference {aReferenceIdentifier} is being closed. By default this method does nothing.", py::arg("aDocument"), py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("IsOpened", (Standard_Boolean (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::IsOpened, "returns true if the document corresponding to the given reference has been retrieved and opened. Otherwise returns false. This method does not retrieve the referenced document", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("CreateReference", (void (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &, const Standard_Integer, const opencascade::handle<CDM_Application> &, const Standard_Integer, const Standard_Boolean)) &CDM_Document::CreateReference, "None", py::arg("aMetaData"), py::arg("aReferenceIdentifier"), py::arg("anApplication"), py::arg("aToDocumentVersion"), py::arg("UseStorageConfiguration"));
cls_CDM_Document.def("CreateReference", (Standard_Integer (CDM_Document::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_Application> &, const Standard_Integer, const Standard_Boolean)) &CDM_Document::CreateReference, "None", py::arg("aMetaData"), py::arg("anApplication"), py::arg("aDocumentVersion"), py::arg("UseStorageConfiguration"));
cls_CDM_Document.def("ReferenceCounter", (Standard_Integer (CDM_Document::*)() const) &CDM_Document::ReferenceCounter, "None");
cls_CDM_Document.def("Update", (void (CDM_Document::*)()) &CDM_Document::Update, "the following method should be used instead:");
cls_CDM_Document.def("Reference", (opencascade::handle<CDM_Reference> (CDM_Document::*)(const Standard_Integer) const) &CDM_Document::Reference, "None", py::arg("aReferenceIdentifier"));
cls_CDM_Document.def("SetModifications", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetModifications, "None", py::arg("Modifications"));
cls_CDM_Document.def("SetReferenceCounter", (void (CDM_Document::*)(const Standard_Integer)) &CDM_Document::SetReferenceCounter, "None", py::arg("aReferenceCounter"));
cls_CDM_Document.def_static("get_type_name_", (const char * (*)()) &CDM_Document::get_type_name, "None");
cls_CDM_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Document::get_type_descriptor, "None");
cls_CDM_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Document::*)() const) &CDM_Document::DynamicType, "None");

// Enums

}