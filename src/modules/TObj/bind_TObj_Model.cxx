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
#include <TObj_Partition.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDocStd_Document.hxx>
#include <TObj_Model.hxx>
#include <TDF_Label.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TObj_ObjectIterator.hxx>
#include <TObj_Object.hxx>
#include <TObj_TNameContainer.hxx>
#include <TObj_CheckModel.hxx>
#include <TObj_Application.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_TObj_Model(py::module &mod){

py::class_<TObj_Model, opencascade::handle<TObj_Model>, Standard_Transient> cls_TObj_Model(mod, "TObj_Model", "Base class for OCAF based models. Defines common behaviour for all models based on TObject classes, basic services to access model objects and common operations with the model. Provides default implementation for many methods.");

// Fields

// Methods
cls_TObj_Model.def("SetMessenger", (void (TObj_Model::*)(const opencascade::handle<Message_Messenger> &)) &TObj_Model::SetMessenger, "Set messenger to use for messages output", py::arg("theMsgr"));
cls_TObj_Model.def("Messenger", (opencascade::handle<Message_Messenger> (TObj_Model::*)() const) &TObj_Model::Messenger, "Get messenger used for messages output (by default, the messenger from application is used)");
cls_TObj_Model.def("Load", (Standard_Boolean (TObj_Model::*)(const TCollection_ExtendedString &)) &TObj_Model::Load, "Load the OCAF model from a file. If the filename is empty or file does not exists, it just initializes model by empty data.", py::arg("theFile"));
cls_TObj_Model.def("SaveAs", (Standard_Boolean (TObj_Model::*)(const TCollection_ExtendedString &)) &TObj_Model::SaveAs, "Save the model to a file", py::arg("theFile"));
cls_TObj_Model.def("Save", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Save, "Save the model to the same file");
cls_TObj_Model.def("Close", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Close, "Close the model");
cls_TObj_Model.def("CloseDocument", (void (TObj_Model::*)(const opencascade::handle<TDocStd_Document> &)) &TObj_Model::CloseDocument, "Close Free OCAF document", py::arg("theDoc"));
cls_TObj_Model.def_static("GetDocumentModel_", (opencascade::handle<TObj_Model> (*)(const TDF_Label &)) &TObj_Model::GetDocumentModel, "Returns model which contains a document with the label, or NULL handle if label is NULL", py::arg("theLabel"));
cls_TObj_Model.def("GetFile", (opencascade::handle<TCollection_HExtendedString> (TObj_Model::*)() const) &TObj_Model::GetFile, "Returns the full file name this model is to be saved to, or null if the model was not saved yet");
cls_TObj_Model.def("GetObjects", (opencascade::handle<TObj_ObjectIterator> (TObj_Model::*)() const) &TObj_Model::GetObjects, "Returns an Iterator on all objects in the Model");
cls_TObj_Model.def("GetChildren", (opencascade::handle<TObj_ObjectIterator> (TObj_Model::*)() const) &TObj_Model::GetChildren, "Returns an Iterator on objects in the main partition");
cls_TObj_Model.def("FindObject", (opencascade::handle<TObj_Object> (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const) &TObj_Model::FindObject, "Returns an Object by given Name (or Null if not found).", py::arg("theName"), py::arg("theDictionary"));
cls_TObj_Model.def("GetChecker", (opencascade::handle<TObj_CheckModel> (TObj_Model::*)() const) &TObj_Model::GetChecker, "Returns the tool checking model consistency. Descendant may redefine it to return its own tool.");
cls_TObj_Model.def("GetRoot", (opencascade::handle<TObj_Object> (TObj_Model::*)() const) &TObj_Model::GetRoot, "Returns root object of model");
cls_TObj_Model.def("GetMainPartition", (opencascade::handle<TObj_Partition> (TObj_Model::*)() const) &TObj_Model::GetMainPartition, "Returns root object of model");
cls_TObj_Model.def("GetLabel", (TDF_Label (TObj_Model::*)() const) &TObj_Model::GetLabel, "Returns OCAF label on which model data are stored.");
cls_TObj_Model.def("GetModelName", (opencascade::handle<TCollection_HExtendedString> (TObj_Model::*)() const) &TObj_Model::GetModelName, "Returns the name of the model");
cls_TObj_Model.def_static("SetNewName_", (void (*)(const opencascade::handle<TObj_Object> &)) &TObj_Model::SetNewName, "Sets new unique name for the object", py::arg("theObject"));
cls_TObj_Model.def("IsRegisteredName", (Standard_Boolean (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const) &TObj_Model::IsRegisteredName, "Returns True is name is registered in the names map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theDictionary"));
cls_TObj_Model.def("RegisterName", (void (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const TDF_Label &, const opencascade::handle<TObj_TNameContainer> &) const) &TObj_Model::RegisterName, "Register name in the map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theLabel"), py::arg("theDictionary"));
cls_TObj_Model.def("UnRegisterName", (void (TObj_Model::*)(const opencascade::handle<TCollection_HExtendedString> &, const opencascade::handle<TObj_TNameContainer> &) const) &TObj_Model::UnRegisterName, "Unregisters name from the map The input argument may be NULL handle, then model check in own global container", py::arg("theName"), py::arg("theDictionary"));
cls_TObj_Model.def("HasOpenCommand", (Standard_Boolean (TObj_Model::*)() const) &TObj_Model::HasOpenCommand, "Returns True if a Command transaction is open Starting, finishing the transaction");
cls_TObj_Model.def("OpenCommand", (void (TObj_Model::*)() const) &TObj_Model::OpenCommand, "Open a new command transaction.");
cls_TObj_Model.def("CommitCommand", (void (TObj_Model::*)() const) &TObj_Model::CommitCommand, "Commit the Command transaction. Do nothing If there is no Command transaction open.");
cls_TObj_Model.def("AbortCommand", (void (TObj_Model::*)() const) &TObj_Model::AbortCommand, "Abort the Command transaction. Do nothing If there is no Command transaction open.");
cls_TObj_Model.def("IsModified", (Standard_Boolean (TObj_Model::*)() const) &TObj_Model::IsModified, "Modification status");
cls_TObj_Model.def("SetModified", (void (TObj_Model::*)(const Standard_Boolean)) &TObj_Model::SetModified, "Sets modification status", py::arg("theModified"));
cls_TObj_Model.def("GetApplication", (const opencascade::handle<TObj_Application> (TObj_Model::*)()) &TObj_Model::GetApplication, "Returns handle to static instance of the relevant application class");
cls_TObj_Model.def("GetFormat", (TCollection_ExtendedString (TObj_Model::*)() const) &TObj_Model::GetFormat, "Returns the format for save/restore. This implementation returns 'BinOcaf'. The method should be redefined for those models that should use another format.");
cls_TObj_Model.def("GetFormatVersion", (Standard_Integer (TObj_Model::*)() const) &TObj_Model::GetFormatVersion, "Returns the version of format stored in TObj file");
cls_TObj_Model.def("Update", (Standard_Boolean (TObj_Model::*)()) &TObj_Model::Update, "this method is called before activating this model");
cls_TObj_Model.def("GetGUID", (Standard_GUID (TObj_Model::*)() const) &TObj_Model::GetGUID, "Defines interface GUID for TObj_Model");
cls_TObj_Model.def("GetDictionary", (opencascade::handle<TObj_TNameContainer> (TObj_Model::*)() const) &TObj_Model::GetDictionary, "Returns the map of names of the objects");
cls_TObj_Model.def("GetDocument", (opencascade::handle<TDocStd_Document> (TObj_Model::*)() const) &TObj_Model::GetDocument, "Returns OCAF document of Model");
cls_TObj_Model.def("SetLabel", (void (TObj_Model::*)(const TDF_Label &)) &TObj_Model::SetLabel, "Sets OCAF label on which model data are stored. Used by persistence mechanism.", py::arg("theLabel"));
cls_TObj_Model.def("Paste", (Standard_Boolean (TObj_Model::*)(opencascade::handle<TObj_Model>, opencascade::handle<TDF_RelocationTable>)) &TObj_Model::Paste, "Pastes me to the new model references will not be copied if theRelocTable is not 0 if theRelocTable is not NULL theRelocTable is filled by objects", py::arg("theModel"), py::arg("theRelocTable"));
cls_TObj_Model.def("NewEmpty", (opencascade::handle<TObj_Model> (TObj_Model::*)()) &TObj_Model::NewEmpty, "This function have to create a new model with type like me");
cls_TObj_Model.def("CopyReferences", (void (TObj_Model::*)(const opencascade::handle<TObj_Model> &, const opencascade::handle<TDF_RelocationTable> &)) &TObj_Model::CopyReferences, "Copy references from me to the other", py::arg("theTarget"), py::arg("theRelocTable"));
cls_TObj_Model.def_static("get_type_name_", (const char * (*)()) &TObj_Model::get_type_name, "None");
cls_TObj_Model.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Model::get_type_descriptor, "None");
cls_TObj_Model.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Model::*)() const) &TObj_Model::DynamicType, "None");

// Enums

}