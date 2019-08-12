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
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_DeltaOnAddition.hxx>
#include <TDF_DeltaOnForget.hxx>
#include <TDF_DeltaOnResume.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDF_DeltaOnRemoval.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <TDF_Data.hxx>
#include <TDF_LabelNode.hxx>
#include <TDF_AttributeIterator.hxx>
#include <Standard_Type.hxx>
#include <TDF_LabelNodePtr.hxx>

void bind_TDF_Attribute(py::module &mod){

py::class_<TDF_Attribute, opencascade::handle<TDF_Attribute>, Standard_Transient> cls_TDF_Attribute(mod, "TDF_Attribute", "A class each application has to implement. It is used to contain the application data. This abstract class, alongwith Label, is one of the cornerstones of Model Editor. The groundwork is to define the root of information. This information is to be attached to a Label, and could be of any of the following types: - a feature - a constraint - a comment");

// Fields

// Methods
cls_TDF_Attribute.def("ID", (const Standard_GUID & (TDF_Attribute::*)() const) &TDF_Attribute::ID, "Returns the ID of the attribute.");
cls_TDF_Attribute.def("SetID", (void (TDF_Attribute::*)(const Standard_GUID &)) &TDF_Attribute::SetID, "Sets specific ID of the attribute (supports several attributes of one type at the same label feature).", py::arg(""));
cls_TDF_Attribute.def("SetID", (void (TDF_Attribute::*)()) &TDF_Attribute::SetID, "Sets default ID defined in nested class (to be used for attributes having User ID feature).");
cls_TDF_Attribute.def("Label", (const TDF_Label (TDF_Attribute::*)() const) &TDF_Attribute::Label, "Returns the label to which the attribute is attached. If the label is not included in a DF, the label is null. See Label. Warning If the label is not included in a data framework, it is null. This function should not be redefined inline.");
cls_TDF_Attribute.def("Transaction", (Standard_Integer (TDF_Attribute::*)() const) &TDF_Attribute::Transaction, "Returns the transaction index in which the attribute has been created or modified.");
cls_TDF_Attribute.def("UntilTransaction", (Standard_Integer (TDF_Attribute::*)() const) &TDF_Attribute::UntilTransaction, "Returns the upper transaction index until which the attribute is/was valid. This number may vary. A removed attribute validity range is reduced to its transaction index.");
cls_TDF_Attribute.def("IsValid", (Standard_Boolean (TDF_Attribute::*)() const) &TDF_Attribute::IsValid, "Returns true if the attribute is valid; i.e. not a backuped or removed one.");
cls_TDF_Attribute.def("IsNew", (Standard_Boolean (TDF_Attribute::*)() const) &TDF_Attribute::IsNew, "Returns true if the attribute has no backup");
cls_TDF_Attribute.def("IsForgotten", (Standard_Boolean (TDF_Attribute::*)() const) &TDF_Attribute::IsForgotten, "Returns true if the attribute forgotten status is set.");
cls_TDF_Attribute.def("IsAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &) const) &TDF_Attribute::IsAttribute, "Returns true if it exists an associated attribute of <me> with <anID> as ID.", py::arg("anID"));
cls_TDF_Attribute.def("FindAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &, opencascade::handle<TDF_Attribute> &) const) &TDF_Attribute::FindAttribute, "Finds an associated attribute of <me>, according to <anID>. the returned <anAttribute> is a valid one. The method returns True if found, False otherwise. A removed attribute cannot be found using this method.", py::arg("anID"), py::arg("anAttribute"));
cls_TDF_Attribute.def("AddAttribute", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_Attribute::AddAttribute, "Adds an Attribute <other> to the label of <me>.Raises if there is already one of the same GUID fhan <other>.", py::arg("other"));
cls_TDF_Attribute.def("ForgetAttribute", (Standard_Boolean (TDF_Attribute::*)(const Standard_GUID &) const) &TDF_Attribute::ForgetAttribute, "Forgets the Attribute of GUID <aguid> associated to the label of <me>. Be carefull that if <me> is the attribute of <guid>, <me> will have a null label after this call. If the attribute doesn't exist returns False. Otherwise returns True.", py::arg("aguid"));
cls_TDF_Attribute.def("ForgetAllAttributes", [](TDF_Attribute &self) -> void { return self.ForgetAllAttributes(); });
cls_TDF_Attribute.def("ForgetAllAttributes", (void (TDF_Attribute::*)(const Standard_Boolean) const) &TDF_Attribute::ForgetAllAttributes, "Forgets all the attributes attached to the label of <me>. Does it on the sub-labels if <clearChildren> is set to true. Of course, this method is compatible with Transaction & Delta mecanisms. Be carefull that if <me> will have a null label after this call", py::arg("clearChildren"));
cls_TDF_Attribute.def("AfterAddition", (void (TDF_Attribute::*)()) &TDF_Attribute::AfterAddition, "Something to do after adding an Attribute to a label.");
cls_TDF_Attribute.def("BeforeRemoval", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeRemoval, "Something to do before removing an Attribute from a label.");
cls_TDF_Attribute.def("BeforeForget", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeForget, "Something to do before forgetting an Attribute to a label.");
cls_TDF_Attribute.def("AfterResume", (void (TDF_Attribute::*)()) &TDF_Attribute::AfterResume, "Something to do after resuming an Attribute from a label.");
cls_TDF_Attribute.def("AfterRetrieval", [](TDF_Attribute &self) -> Standard_Boolean { return self.AfterRetrieval(); });
cls_TDF_Attribute.def("AfterRetrieval", (Standard_Boolean (TDF_Attribute::*)(const Standard_Boolean)) &TDF_Attribute::AfterRetrieval, "Something to do AFTER creation of an attribute by persistent-transient translation. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("forceIt"));
cls_TDF_Attribute.def("BeforeUndo", [](TDF_Attribute &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TDF_Attribute.def("BeforeUndo", (Standard_Boolean (TDF_Attribute::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDF_Attribute::BeforeUndo, "Something to do before applying <anAttDelta>. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDF_Attribute.def("AfterUndo", [](TDF_Attribute &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TDF_Attribute.def("AfterUndo", (Standard_Boolean (TDF_Attribute::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDF_Attribute::AfterUndo, "Something to do after applying <anAttDelta>. The returned status says if AfterUndo has been performed (true) or if this callback must be called once again further (false). If <forceIt> is set to true, the method MUST perform and return true. Does nothing by default and returns true.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDF_Attribute.def("BeforeCommitTransaction", (void (TDF_Attribute::*)()) &TDF_Attribute::BeforeCommitTransaction, "A callback. By default does nothing. It is called by TDF_Data::CommitTransaction() method.");
cls_TDF_Attribute.def("Backup", (void (TDF_Attribute::*)()) &TDF_Attribute::Backup, "Backups the attribute. The backuped attribute is flagged 'Backuped' and not 'Valid'.");
cls_TDF_Attribute.def("IsBackuped", (Standard_Boolean (TDF_Attribute::*)() const) &TDF_Attribute::IsBackuped, "Returns true if the attribute backup status is set. This status is set/unset by the Backup() method.");
cls_TDF_Attribute.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDF_Attribute::*)() const) &TDF_Attribute::BackupCopy, "Copies the attribute contents into a new other attribute. It is used by Backup().");
cls_TDF_Attribute.def("Restore", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &)) &TDF_Attribute::Restore, "Restores the backuped contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TDF_Attribute.def("DeltaOnAddition", (opencascade::handle<TDF_DeltaOnAddition> (TDF_Attribute::*)() const) &TDF_Attribute::DeltaOnAddition, "Makes an AttributeDelta because <me> appeared. The only known use of a redefinition of this method is to return a null handle (no delta).");
cls_TDF_Attribute.def("DeltaOnForget", (opencascade::handle<TDF_DeltaOnForget> (TDF_Attribute::*)() const) &TDF_Attribute::DeltaOnForget, "Makes an AttributeDelta because <me> has been forgotten.");
cls_TDF_Attribute.def("DeltaOnResume", (opencascade::handle<TDF_DeltaOnResume> (TDF_Attribute::*)() const) &TDF_Attribute::DeltaOnResume, "Makes an AttributeDelta because <me> has been resumed.");
cls_TDF_Attribute.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_Attribute::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute.", py::arg("anOldAttribute"));
cls_TDF_Attribute.def("DeltaOnModification", (void (TDF_Attribute::*)(const opencascade::handle<TDF_DeltaOnModification> &)) &TDF_Attribute::DeltaOnModification, "Applies a DeltaOnModification to <me>.", py::arg("aDelta"));
cls_TDF_Attribute.def("DeltaOnRemoval", (opencascade::handle<TDF_DeltaOnRemoval> (TDF_Attribute::*)() const) &TDF_Attribute::DeltaOnRemoval, "Makes a DeltaOnRemoval on <me> because <me> has disappeared from the DS.");
cls_TDF_Attribute.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDF_Attribute::*)() const) &TDF_Attribute::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TDF_Attribute.def("Paste", (void (TDF_Attribute::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDF_Attribute::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method may paste the contents of <me> into <intoAttribute>.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
cls_TDF_Attribute.def("References", (void (TDF_Attribute::*)(const opencascade::handle<TDF_DataSet> &) const) &TDF_Attribute::References, "Adds the first level referenced attributes and labels to <aDataSet>.", py::arg("aDataSet"));
cls_TDF_Attribute.def("Dump", (Standard_OStream & (TDF_Attribute::*)(Standard_OStream &) const) &TDF_Attribute::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
cls_TDF_Attribute.def("bits_left", (Standard_OStream & (TDF_Attribute::*)(Standard_OStream &) const) &TDF_Attribute::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TDF_Attribute.def("ExtendedDump", (void (TDF_Attribute::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const) &TDF_Attribute::ExtendedDump, "Dumps the attribute content on <aStream>, using <aMap> like this: if an attribute is not in the map, first put add it to the map and then dump it. Use the map rank instead of dumping each attribute field.", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
cls_TDF_Attribute.def("Forget", (void (TDF_Attribute::*)(const Standard_Integer)) &TDF_Attribute::Forget, "Forgets the attribute. <aTransaction> is the current transaction in which the forget is done. A forgotten attribute is also flagged not 'Valid'.", py::arg("aTransaction"));
cls_TDF_Attribute.def_static("get_type_name_", (const char * (*)()) &TDF_Attribute::get_type_name, "None");
cls_TDF_Attribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDF_Attribute::get_type_descriptor, "None");
cls_TDF_Attribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDF_Attribute::*)() const) &TDF_Attribute::DynamicType, "None");

// Enums

}