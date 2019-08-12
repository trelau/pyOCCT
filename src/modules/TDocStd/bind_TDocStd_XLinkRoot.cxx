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
#include <TDocStd_XLink.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_XLinkRoot.hxx>
#include <TDF_Data.hxx>
#include <TDocStd_XLinkPtr.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_XLinkIterator.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_XLinkRoot(py::module &mod){

py::class_<TDocStd_XLinkRoot, opencascade::handle<TDocStd_XLinkRoot>, TDF_Attribute> cls_TDocStd_XLinkRoot(mod, "TDocStd_XLinkRoot", "This attribute is the root of all external references contained in a Data from TDF. Only one instance of this class is added to the TDF_Data root label. Starting from this attribute all the Reference are linked together, to be found easely.");

// Constructors

// Fields

// Methods
cls_TDocStd_XLinkRoot.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_XLinkRoot::GetID, "Returns the ID: 2a96b61d-ec8b-11d0-bee7-080009dc3333");
cls_TDocStd_XLinkRoot.def_static("Set_", (opencascade::handle<TDocStd_XLinkRoot> (*)(const opencascade::handle<TDF_Data> &)) &TDocStd_XLinkRoot::Set, "Sets an empty XLinkRoot to Root or gets the existing one. Only one attribute per TDF_Data.", py::arg("aDF"));
cls_TDocStd_XLinkRoot.def_static("Insert_", (void (*)(const TDocStd_XLinkPtr &)) &TDocStd_XLinkRoot::Insert, "Inserts <anXLinkPtr> at the beginning of the XLink chain.", py::arg("anXLinkPtr"));
cls_TDocStd_XLinkRoot.def_static("Remove_", (void (*)(const TDocStd_XLinkPtr &)) &TDocStd_XLinkRoot::Remove, "Removes <anXLinkPtr> from the XLink chain, if it exists.", py::arg("anXLinkPtr"));
cls_TDocStd_XLinkRoot.def("ID", (const Standard_GUID & (TDocStd_XLinkRoot::*)() const) &TDocStd_XLinkRoot::ID, "Returns the ID of the attribute.");
cls_TDocStd_XLinkRoot.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDocStd_XLinkRoot::*)() const) &TDocStd_XLinkRoot::BackupCopy, "Returns a null handle.");
cls_TDocStd_XLinkRoot.def("Restore", (void (TDocStd_XLinkRoot::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_XLinkRoot::Restore, "Does nothing.", py::arg("anAttribute"));
cls_TDocStd_XLinkRoot.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_XLinkRoot::*)() const) &TDocStd_XLinkRoot::NewEmpty, "Returns a null handle.");
cls_TDocStd_XLinkRoot.def("Paste", (void (TDocStd_XLinkRoot::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDocStd_XLinkRoot::Paste, "Does nothing.", py::arg("intoAttribute"), py::arg("aRelocationTable"));
cls_TDocStd_XLinkRoot.def("Dump", (Standard_OStream & (TDocStd_XLinkRoot::*)(Standard_OStream &) const) &TDocStd_XLinkRoot::Dump, "Dumps the attribute on <aStream>.", py::arg("anOS"));
cls_TDocStd_XLinkRoot.def_static("get_type_name_", (const char * (*)()) &TDocStd_XLinkRoot::get_type_name, "None");
cls_TDocStd_XLinkRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_XLinkRoot::get_type_descriptor, "None");
cls_TDocStd_XLinkRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_XLinkRoot::*)() const) &TDocStd_XLinkRoot::DynamicType, "None");

// Enums

}