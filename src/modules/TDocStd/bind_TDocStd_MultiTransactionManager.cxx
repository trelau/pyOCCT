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
#include <Standard_TypeDef.hxx>
#include <TDocStd_SequenceOfApplicationDelta.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_Document.hxx>
#include <TDocStd_SequenceOfDocument.hxx>
#include <TDocStd_MultiTransactionManager.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_MultiTransactionManager(py::module &mod){

py::class_<TDocStd_MultiTransactionManager, opencascade::handle<TDocStd_MultiTransactionManager>, Standard_Transient> cls_TDocStd_MultiTransactionManager(mod, "TDocStd_MultiTransactionManager", "Class for synchronization of transactions within multiple documents. Each transaction of this class involvess one transaction in each modified document.");

// Constructors
cls_TDocStd_MultiTransactionManager.def(py::init<>());

// Fields

// Methods
cls_TDocStd_MultiTransactionManager.def("SetUndoLimit", (void (TDocStd_MultiTransactionManager::*)(const Standard_Integer)) &TDocStd_MultiTransactionManager::SetUndoLimit, "Sets undo limit for the manager and all documents.", py::arg("theLimit"));
cls_TDocStd_MultiTransactionManager.def("GetUndoLimit", (Standard_Integer (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::GetUndoLimit, "Returns undo limit for the manager.");
cls_TDocStd_MultiTransactionManager.def("Undo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::Undo, "Undoes the current transaction of the manager. It calls the Undo () method of the document being on top of the manager list of undos (list.First()) and moves the list item to the top of the list of manager redos (list.Prepend(item)).");
cls_TDocStd_MultiTransactionManager.def("Redo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::Redo, "Redoes the current transaction of the application. It calls the Redo () method of the document being on top of the manager list of redos (list.First()) and moves the list item to the top of the list of manager undos (list.Prepend(item)).");
cls_TDocStd_MultiTransactionManager.def("GetAvailableUndos", (const TDocStd_SequenceOfApplicationDelta & (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::GetAvailableUndos, "Returns available manager undos.");
cls_TDocStd_MultiTransactionManager.def("GetAvailableRedos", (const TDocStd_SequenceOfApplicationDelta & (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::GetAvailableRedos, "Returns available manager redos.");
cls_TDocStd_MultiTransactionManager.def("OpenCommand", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::OpenCommand, "Opens transaction in each document and sets the flag that transaction is opened. If there are already opened transactions in the documents, these transactions will be aborted before openning new ones.");
cls_TDocStd_MultiTransactionManager.def("AbortCommand", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::AbortCommand, "Unsets the flag of started manager transaction and aborts transaction in each document.");
cls_TDocStd_MultiTransactionManager.def("CommitCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::CommitCommand, "Commits transaction in all documents and fills the transaction manager with the documents that have been changed during the transaction. Returns True if new data has been added to myUndos. NOTE: All nested transactions in the documents will be commited.");
cls_TDocStd_MultiTransactionManager.def("CommitCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)(const TCollection_ExtendedString &)) &TDocStd_MultiTransactionManager::CommitCommand, "Makes the same steps as the previous function but defines the name for transaction. Returns True if new data has been added to myUndos.", py::arg("theName"));
cls_TDocStd_MultiTransactionManager.def("HasOpenCommand", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::HasOpenCommand, "Returns true if a transaction is opened.");
cls_TDocStd_MultiTransactionManager.def("RemoveLastUndo", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::RemoveLastUndo, "Removes undo information from the list of undos of the manager and all documents which have been modified during the transaction.");
cls_TDocStd_MultiTransactionManager.def("DumpTransaction", (void (TDocStd_MultiTransactionManager::*)(Standard_OStream &) const) &TDocStd_MultiTransactionManager::DumpTransaction, "Dumps transactions in undos and redos", py::arg("theOS"));
cls_TDocStd_MultiTransactionManager.def("AddDocument", (void (TDocStd_MultiTransactionManager::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_MultiTransactionManager::AddDocument, "Adds the document to the transaction manager and checks if it has been already added", py::arg("theDoc"));
cls_TDocStd_MultiTransactionManager.def("RemoveDocument", (void (TDocStd_MultiTransactionManager::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_MultiTransactionManager::RemoveDocument, "Removes the document from the transaction manager.", py::arg("theDoc"));
cls_TDocStd_MultiTransactionManager.def("Documents", (const TDocStd_SequenceOfDocument & (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::Documents, "Returns the added documents to the transaction manager.");
cls_TDocStd_MultiTransactionManager.def("SetNestedTransactionMode", [](TDocStd_MultiTransactionManager &self) -> void { return self.SetNestedTransactionMode(); });
cls_TDocStd_MultiTransactionManager.def("SetNestedTransactionMode", (void (TDocStd_MultiTransactionManager::*)(const Standard_Boolean)) &TDocStd_MultiTransactionManager::SetNestedTransactionMode, "Sets nested transaction mode if isAllowed == Standard_True NOTE: field myIsNestedTransactionMode exists only for synchronization between several documents and has no effect on transactions of multitransaction manager.", py::arg("isAllowed"));
cls_TDocStd_MultiTransactionManager.def("IsNestedTransactionMode", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::IsNestedTransactionMode, "Returns Standard_True if NestedTransaction mode is set. Methods for protection of changes outside transactions");
cls_TDocStd_MultiTransactionManager.def("SetModificationMode", (void (TDocStd_MultiTransactionManager::*)(const Standard_Boolean)) &TDocStd_MultiTransactionManager::SetModificationMode, "If theTransactionOnly is True, denies all changes outside transactions.", py::arg("theTransactionOnly"));
cls_TDocStd_MultiTransactionManager.def("ModificationMode", (Standard_Boolean (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::ModificationMode, "Returns True if changes are allowed only inside transactions.");
cls_TDocStd_MultiTransactionManager.def("ClearUndos", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::ClearUndos, "Clears undos in the manager and in documents.");
cls_TDocStd_MultiTransactionManager.def("ClearRedos", (void (TDocStd_MultiTransactionManager::*)()) &TDocStd_MultiTransactionManager::ClearRedos, "Clears redos in the manager and in documents.");
cls_TDocStd_MultiTransactionManager.def_static("get_type_name_", (const char * (*)()) &TDocStd_MultiTransactionManager::get_type_name, "None");
cls_TDocStd_MultiTransactionManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_MultiTransactionManager::get_type_descriptor, "None");
cls_TDocStd_MultiTransactionManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_MultiTransactionManager::*)() const) &TDocStd_MultiTransactionManager::DynamicType, "None");

// Enums

}