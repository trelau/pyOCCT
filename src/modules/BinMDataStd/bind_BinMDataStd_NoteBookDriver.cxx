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
#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <BinMDataStd_NoteBookDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinMDataStd_NoteBookDriver(py::module &mod){

py::class_<BinMDataStd_NoteBookDriver, opencascade::handle<BinMDataStd_NoteBookDriver>, BinMDF_ADriver> cls_BinMDataStd_NoteBookDriver(mod, "BinMDataStd_NoteBookDriver", "NoteBook attribute Driver.");

// Constructors
cls_BinMDataStd_NoteBookDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinMDataStd_NoteBookDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NoteBookDriver::*)() const) &BinMDataStd_NoteBookDriver::NewEmpty, "None");
cls_BinMDataStd_NoteBookDriver.def("Paste", (Standard_Boolean (BinMDataStd_NoteBookDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NoteBookDriver.def("Paste", (void (BinMDataStd_NoteBookDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataStd_NoteBookDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NoteBookDriver::get_type_name, "None");
cls_BinMDataStd_NoteBookDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NoteBookDriver::get_type_descriptor, "None");
cls_BinMDataStd_NoteBookDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NoteBookDriver::*)() const) &BinMDataStd_NoteBookDriver::DynamicType, "None");

// Enums

}