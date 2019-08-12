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
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDocStd_Owner.hxx>
#include <Standard_Type.hxx>

void bind_TDocStd_Owner(py::module &mod){

py::class_<TDocStd_Owner, opencascade::handle<TDocStd_Owner>, TDF_Attribute> cls_TDocStd_Owner(mod, "TDocStd_Owner", "This attribute located at the root label of the framework contains a back reference to the owner TDocStd_Document, providing acces to the document from any label. private class Owner;");

// Constructors
cls_TDocStd_Owner.def(py::init<>());

// Fields

// Methods
cls_TDocStd_Owner.def_static("GetID_", (const Standard_GUID & (*)()) &TDocStd_Owner::GetID, "class methods =============");
cls_TDocStd_Owner.def_static("SetDocument_", (void (*)(const opencascade::handle<TDF_Data> &, const opencascade::handle<TDocStd_Document> &)) &TDocStd_Owner::SetDocument, "None", py::arg("indata"), py::arg("doc"));
cls_TDocStd_Owner.def_static("GetDocument_", (opencascade::handle<TDocStd_Document> (*)(const opencascade::handle<TDF_Data> &)) &TDocStd_Owner::GetDocument, "Owner methods ===============", py::arg("ofdata"));
cls_TDocStd_Owner.def("SetDocument", (void (TDocStd_Owner::*)(const opencascade::handle<TDocStd_Document> &)) &TDocStd_Owner::SetDocument, "None", py::arg("document"));
cls_TDocStd_Owner.def("GetDocument", (opencascade::handle<TDocStd_Document> (TDocStd_Owner::*)() const) &TDocStd_Owner::GetDocument, "None");
cls_TDocStd_Owner.def("ID", (const Standard_GUID & (TDocStd_Owner::*)() const) &TDocStd_Owner::ID, "None");
cls_TDocStd_Owner.def("Restore", (void (TDocStd_Owner::*)(const opencascade::handle<TDF_Attribute> &)) &TDocStd_Owner::Restore, "None", py::arg("With"));
cls_TDocStd_Owner.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDocStd_Owner::*)() const) &TDocStd_Owner::NewEmpty, "None");
cls_TDocStd_Owner.def("Paste", (void (TDocStd_Owner::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDocStd_Owner::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDocStd_Owner.def("Dump", (Standard_OStream & (TDocStd_Owner::*)(Standard_OStream &) const) &TDocStd_Owner::Dump, "None", py::arg("anOS"));
cls_TDocStd_Owner.def_static("get_type_name_", (const char * (*)()) &TDocStd_Owner::get_type_name, "None");
cls_TDocStd_Owner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDocStd_Owner::get_type_descriptor, "None");
cls_TDocStd_Owner.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDocStd_Owner::*)() const) &TDocStd_Owner::DynamicType, "None");

// Enums

}