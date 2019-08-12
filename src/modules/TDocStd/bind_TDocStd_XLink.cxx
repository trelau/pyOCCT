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
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_XLink.hxx>
#include <TDF_Label.hxx>
#include <TDF_Reference.hxx>
#include <Standard_GUID.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_XLinkRoot.hxx>
#include <TDocStd_XLinkIterator.hxx>
#include <Standard_Type.hxx>
#include <TDocStd_XLinkPtr.hxx>

void bind_TDocStd_XLink(py::module &mod){

py::class_<TDocStd_XLink, opencascade::handle<TDocStd_XLink>, TDF_Attribute> cls_TDocStd_XLink(mod, "TDocStd_XLink", "An attribute to store the path and the entry of external links. These refer from one data structure to a data structure in another document.");

// Constructors
cls_TDocStd_XLink.def(py::init<>());

// Fields

// Methods
cls_TDocStd_XLink.def_static("Set_", (opencascade::handle<TDocStd_XLink> (*)(const TDF_Label &)) &TDocStd_XLink::Set, "Sets an empty external reference, at the label aLabel.", py::arg("atLabel"));
cls_TDocStd_XLink.def("Update", (opencascade::handle<TDF_Reference> (TDocStd_XLink::*)()) &TDocStd_XLink::Update, "Updates the data referenced in this external link attribute.");
cls_TDocStd_XLink.def("ID", (const Standard_GUID & (TDocStd_XLink::*)() const) &TDocStd_XLink::ID, "Returns the ID of the attribute.");
cls_TDocStd_XLink.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_XLink::GetID, "Returns the GUID for external links.");
cls_TDocStd_XLink.def("DocumentEntry", (void (TDocStd_XLink::*)(const TCollection_AsciiString &)) &TDocStd_XLink::DocumentEntry, "Sets the name aDocEntry for the external document in this external link attribute.", py::arg("aDocEntry"));
cls_TDocStd_XLink.def("DocumentEntry", (const TCollection_AsciiString & (TDocStd_XLink::*)() const) &TDocStd_XLink::DocumentEntry, "Returns the contents of the document identified by aDocEntry. aDocEntry provides external data to this external link attribute.");
cls_TDocStd_XLink.def("LabelEntry", (void (TDocStd_XLink::*)(const TDF_Label &)) &TDocStd_XLink::LabelEntry, "Sets the label entry for this external link attribute with the label aLabel. aLabel pilots the importation of data from the document entry.", py::arg("aLabel"));
cls_TDocStd_XLink.def("LabelEntry", (void (TDocStd_XLink::*)(const TCollection_AsciiString &)) &TDocStd_XLink::LabelEntry, "Sets the label entry for this external link attribute as a document identified by aLabEntry.", py::arg("aLabEntry"));
cls_TDocStd_XLink.def("LabelEntry", (const TCollection_AsciiString & (TDocStd_XLink::*)() const) &TDocStd_XLink::LabelEntry, "Returns the contents of the field <myLabelEntry>.");
cls_TDocStd_XLink.def("AfterAddition", (void (TDocStd_XLink::*)()) &TDocStd_XLink::AfterAddition, "Updates the XLinkRoot attribute by adding <me> to its list.");
cls_TDocStd_XLink.def("BeforeRemoval", (void (TDocStd_XLink::*)()) &TDocStd_XLink::BeforeRemoval, "Updates the XLinkRoot attribute by removing <me> from its list.");
cls_TDocStd_XLink.def("BeforeUndo", [](TDocStd_XLink &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TDocStd_XLink.def("BeforeUndo", (Standard_Boolean (TDocStd_XLink::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDocStd_XLink::BeforeUndo, "Something to do before applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDocStd_XLink.def("AfterUndo", [](TDocStd_XLink &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TDocStd_XLink.def("AfterUndo", (Standard_Boolean (TDocStd_XLink::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDocStd_XLink::AfterUndo, "Something to do after applying <anAttDelta>.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDocStd_XLink.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDocStd_XLink::*)() const) &TDocStd_XLink::BackupCopy, "Returns a null handle. Raise allways for ,it is nonsense to use this method.");
cls_TDocStd_XLink.def("Restore", (void (TDocStd_XLink::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_XLink::Restore, "Does nothing.", py::arg("anAttribute"));
cls_TDocStd_XLink.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_XLink::*)() const) &TDocStd_XLink::NewEmpty, "Returns a null handle.");
cls_TDocStd_XLink.def("Paste", (void (TDocStd_XLink::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDocStd_XLink::Paste, "Does nothing.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
cls_TDocStd_XLink.def("Dump", (Standard_OStream & (TDocStd_XLink::*)(Standard_OStream &) const) &TDocStd_XLink::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
cls_TDocStd_XLink.def_static("get_type_name_", (const char * (*)()) &TDocStd_XLink::get_type_name, "None");
cls_TDocStd_XLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_XLink::get_type_descriptor, "None");
cls_TDocStd_XLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_XLink::*)() const) &TDocStd_XLink::DynamicType, "None");

// Enums

}