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
#include <BinTObjDrivers_ObjectDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinTObjDrivers_ObjectDriver(py::module &mod){

py::class_<BinTObjDrivers_ObjectDriver, opencascade::handle<BinTObjDrivers_ObjectDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ObjectDriver(mod, "BinTObjDrivers_ObjectDriver", "None");

// Constructors
cls_BinTObjDrivers_ObjectDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinTObjDrivers_ObjectDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ObjectDriver::*)() const) &BinTObjDrivers_ObjectDriver::NewEmpty, "None");
cls_BinTObjDrivers_ObjectDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ObjectDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ObjectDriver.def("Paste", (void (BinTObjDrivers_ObjectDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinTObjDrivers_ObjectDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ObjectDriver::get_type_name, "None");
cls_BinTObjDrivers_ObjectDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ObjectDriver::get_type_descriptor, "None");
cls_BinTObjDrivers_ObjectDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ObjectDriver::*)() const) &BinTObjDrivers_ObjectDriver::DynamicType, "None");

// Enums

}