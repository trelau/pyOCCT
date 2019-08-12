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
#include <BinMNaming_NamingDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinMNaming_NamingDriver(py::module &mod){

py::class_<BinMNaming_NamingDriver, opencascade::handle<BinMNaming_NamingDriver>, BinMDF_ADriver> cls_BinMNaming_NamingDriver(mod, "BinMNaming_NamingDriver", "Naming Attribute Driver.");

// Constructors
cls_BinMNaming_NamingDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinMNaming_NamingDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMNaming_NamingDriver::*)() const) &BinMNaming_NamingDriver::NewEmpty, "None");
cls_BinMNaming_NamingDriver.def("Paste", (Standard_Boolean (BinMNaming_NamingDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMNaming_NamingDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMNaming_NamingDriver.def("Paste", (void (BinMNaming_NamingDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMNaming_NamingDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMNaming_NamingDriver.def_static("get_type_name_", (const char * (*)()) &BinMNaming_NamingDriver::get_type_name, "None");
cls_BinMNaming_NamingDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMNaming_NamingDriver::get_type_descriptor, "None");
cls_BinMNaming_NamingDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMNaming_NamingDriver::*)() const) &BinMNaming_NamingDriver::DynamicType, "None");

// Enums

}