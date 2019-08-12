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
#include <CDM_Document.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Data.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_DeltaList.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <TDocStd_CompoundDelta.hxx>
#include <TDF_Delta.hxx>
#include <TDF_Transaction.hxx>

void bind_TDocStd_Document(py::module &mod){

py::class_<TDocStd_Document, opencascade::handle<TDocStd_Document>, CDM_Document> cls_TDocStd_Document(mod, "TDocStd_Document", "The contents of a TDocStd_Application, a document is a container for a data framework composed of labels and attributes. As such, TDocStd_Document is the entry point into the data framework. To gain access to the data, you create a document as follows: Handle(TDocStd_Document) MyDF = new TDocStd_Document The document also allows you to manage: - modifications, providing Undo and Redo functions. - command transactions. Warning: The only data saved is the framework (TDF_Data)");

// Constructors
cls_TDocStd_Document.def(py::init<const TCollection_ExtendedString &>(), py::arg("astorageformat"));

// Fields

// Methods
cls_TDocStd_Document.def_static("Get_", (opencascade::handle<TDocStd_Document> (*)(const TDF_Label &)) &TDocStd_Document::Get, "Will Abort any execution, clear fields returns the document which contains <L>. raises an exception if the document is not found.", py::arg("L"));
cls_TDocStd_Document.def("IsSaved", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::IsSaved, "the document is saved in a file.");
cls_TDocStd_Document.def("IsChanged", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::IsChanged, "returns True if document differs from the state of last saving. this method have to be called only wroking in the transaction mode");
cls_TDocStd_Document.def("SetSaved", (void (TDocStd_Document::*)()) &TDocStd_Document::SetSaved, "This method have to be called to show document that it has been saved");
cls_TDocStd_Document.def("SetSavedTime", (void (TDocStd_Document::*)(const Standard_Integer)) &TDocStd_Document::SetSavedTime, "Say to document what it is not saved. Use value, returned earlier by GetSavedTime().", py::arg("theTime"));
cls_TDocStd_Document.def("GetSavedTime", (Standard_Integer (TDocStd_Document::*)() const) &TDocStd_Document::GetSavedTime, "Returns value of <mySavedTime> to be used later in SetSavedTime()");
cls_TDocStd_Document.def("GetName", (TCollection_ExtendedString (TDocStd_Document::*)() const) &TDocStd_Document::GetName, "raise if <me> is not saved.");
cls_TDocStd_Document.def("GetPath", (TCollection_ExtendedString (TDocStd_Document::*)() const) &TDocStd_Document::GetPath, "returns the OS path of the file, in wich one <me> is saved. Raise an exception if <me> is not saved.");
cls_TDocStd_Document.def("SetData", (void (TDocStd_Document::*)(const opencascade::handle<TDF_Data> &)) &TDocStd_Document::SetData, "None", py::arg("data"));
cls_TDocStd_Document.def("GetData", (opencascade::handle<TDF_Data> (TDocStd_Document::*)() const) &TDocStd_Document::GetData, "None");
cls_TDocStd_Document.def("Main", (TDF_Label (TDocStd_Document::*)() const) &TDocStd_Document::Main, "Returns the main label in this data framework. By definition, this is the label with the entry 0:1.");
cls_TDocStd_Document.def("IsEmpty", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::IsEmpty, "Returns True if the main label has no attributes");
cls_TDocStd_Document.def("IsValid", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::IsValid, "Returns False if the document has been modified but not recomputed.");
cls_TDocStd_Document.def("SetModified", (void (TDocStd_Document::*)(const TDF_Label &)) &TDocStd_Document::SetModified, "Notify the label as modified, the Document becomes UnValid. returns True if <L> has been notified as modified.", py::arg("L"));
cls_TDocStd_Document.def("PurgeModified", (void (TDocStd_Document::*)()) &TDocStd_Document::PurgeModified, "Remove all modifications. After this call The document becomesagain Valid.");
cls_TDocStd_Document.def("GetModified", (const TDF_LabelMap & (TDocStd_Document::*)() const) &TDocStd_Document::GetModified, "Returns the labels which have been modified in this document.");
cls_TDocStd_Document.def("NewCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::NewCommand, "Launches a new command. This command may be undone.");
cls_TDocStd_Document.def("HasOpenCommand", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::HasOpenCommand, "returns True if a Command transaction is open in the curret .");
cls_TDocStd_Document.def("OpenCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::OpenCommand, "Opens a new command transaction in this document. You can use HasOpenCommand to see whether a command is already open. Exceptions Standard_DomainError if a command is already open in this document.");
cls_TDocStd_Document.def("CommitCommand", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::CommitCommand, "Commits documents transactions and fills the transaction manager with documents that have been changed during the transaction. If no command transaction is open, nothing is done. Returns True if a new delta has been added to myUndos.");
cls_TDocStd_Document.def("AbortCommand", (void (TDocStd_Document::*)()) &TDocStd_Document::AbortCommand, "Abort the Command transaction. Does nothing If there is no Command transaction open.");
cls_TDocStd_Document.def("GetUndoLimit", (Standard_Integer (TDocStd_Document::*)() const) &TDocStd_Document::GetUndoLimit, "The current limit on the number of undos");
cls_TDocStd_Document.def("SetUndoLimit", (void (TDocStd_Document::*)(const Standard_Integer)) &TDocStd_Document::SetUndoLimit, "Set the limit on the number of Undo Delta stored 0 will disable Undo on the document A negative value means no limit. Note that by default Undo is disabled. Enabling it will take effect with the next call to NewCommand. Of course this limit is the same for Redo", py::arg("L"));
cls_TDocStd_Document.def("ClearUndos", (void (TDocStd_Document::*)()) &TDocStd_Document::ClearUndos, "Remove all stored Undos and Redos");
cls_TDocStd_Document.def("ClearRedos", (void (TDocStd_Document::*)()) &TDocStd_Document::ClearRedos, "Remove all stored Redos");
cls_TDocStd_Document.def("GetAvailableUndos", (Standard_Integer (TDocStd_Document::*)() const) &TDocStd_Document::GetAvailableUndos, "Returns the number of undos stored in this document. If this figure is greater than 0, the method Undo can be used.");
cls_TDocStd_Document.def("Undo", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::Undo, "Will UNDO one step, returns False if no undo was done (Undos == 0). Otherwise, true is returned and one step in the list of undoes is undone.");
cls_TDocStd_Document.def("GetAvailableRedos", (Standard_Integer (TDocStd_Document::*)() const) &TDocStd_Document::GetAvailableRedos, "Returns the number of redos stored in this document. If this figure is greater than 0, the method Redo can be used.");
cls_TDocStd_Document.def("Redo", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::Redo, "Will REDO one step, returns False if no redo was done (Redos == 0). Otherwise, true is returned, and one step in the list of redoes is done again.");
cls_TDocStd_Document.def("GetUndos", (const TDF_DeltaList & (TDocStd_Document::*)() const) &TDocStd_Document::GetUndos, "None");
cls_TDocStd_Document.def("GetRedos", (const TDF_DeltaList & (TDocStd_Document::*)() const) &TDocStd_Document::GetRedos, "None");
cls_TDocStd_Document.def("RemoveFirstUndo", (void (TDocStd_Document::*)()) &TDocStd_Document::RemoveFirstUndo, "Removes the first undo in the list of document undos. It is used in the application when the undo limit is exceed.");
cls_TDocStd_Document.def("InitDeltaCompaction", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::InitDeltaCompaction, "Initializes the procedure of delta compaction Returns false if there is no delta to compact Marks the last delta as a 'from' delta");
cls_TDocStd_Document.def("PerformDeltaCompaction", (Standard_Boolean (TDocStd_Document::*)()) &TDocStd_Document::PerformDeltaCompaction, "Performs the procedure of delta compaction Makes all deltas starting from 'from' delta till the last one to be one delta.");
cls_TDocStd_Document.def("UpdateReferences", (void (TDocStd_Document::*)(const TCollection_AsciiString &)) &TDocStd_Document::UpdateReferences, "Set modifications on labels impacted by external references to the entry. The document becomes invalid and must be recomputed.", py::arg("aDocEntry"));
cls_TDocStd_Document.def("Recompute", (void (TDocStd_Document::*)()) &TDocStd_Document::Recompute, "Recompute if the document was not valid and propagate the reccorded modification.");
cls_TDocStd_Document.def("Update", (void (TDocStd_Document::*)(const opencascade::handle<CDM_Document> &, const Standard_Integer, const Standard_Address)) &TDocStd_Document::Update, "This method Update will be called to signal the end of the modified references list. The document should be recomputed and UpdateFromDocuments should be called. Update should returns True in case of success, false otherwise. In case of Failure, additional information can be given in ErrorString. Update the document by propagation ================================== Update the document from internal stored modifications. If you want to undoing this operation, please call NewCommand before. to change format (advanced programming) ================", py::arg("aToDocument"), py::arg("aReferenceIdentifier"), py::arg("aModifContext"));
cls_TDocStd_Document.def("StorageFormat", (TCollection_ExtendedString (TDocStd_Document::*)() const) &TDocStd_Document::StorageFormat, "None");
cls_TDocStd_Document.def("SetEmptyLabelsSavingMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetEmptyLabelsSavingMode, "Sets saving mode for empty labels. If Standard_True, empty labels will be saved.", py::arg("isAllowed"));
cls_TDocStd_Document.def("EmptyLabelsSavingMode", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::EmptyLabelsSavingMode, "Returns saving mode for empty labels.");
cls_TDocStd_Document.def("ChangeStorageFormat", (void (TDocStd_Document::*)(const TCollection_ExtendedString &)) &TDocStd_Document::ChangeStorageFormat, "methods for the nested transaction mode", py::arg("newStorageFormat"));
cls_TDocStd_Document.def("SetNestedTransactionMode", [](TDocStd_Document &self) -> void { return self.SetNestedTransactionMode(); });
cls_TDocStd_Document.def("SetNestedTransactionMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetNestedTransactionMode, "Sets nested transaction mode if isAllowed == Standard_True", py::arg("isAllowed"));
cls_TDocStd_Document.def("IsNestedTransactionMode", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::IsNestedTransactionMode, "Returns Standard_True if mode is set");
cls_TDocStd_Document.def("SetModificationMode", (void (TDocStd_Document::*)(const Standard_Boolean)) &TDocStd_Document::SetModificationMode, "if theTransactionOnly is True changes is denied outside transactions", py::arg("theTransactionOnly"));
cls_TDocStd_Document.def("ModificationMode", (Standard_Boolean (TDocStd_Document::*)() const) &TDocStd_Document::ModificationMode, "returns True if changes allowed only inside transactions");
cls_TDocStd_Document.def("BeforeClose", (void (TDocStd_Document::*)()) &TDocStd_Document::BeforeClose, "Prepares document for closing");
cls_TDocStd_Document.def_static("get_type_name_", (const char * (*)()) &TDocStd_Document::get_type_name, "None");
cls_TDocStd_Document.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Document::get_type_descriptor, "None");
cls_TDocStd_Document.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Document::*)() const) &TDocStd_Document::DynamicType, "None");

// Enums

}