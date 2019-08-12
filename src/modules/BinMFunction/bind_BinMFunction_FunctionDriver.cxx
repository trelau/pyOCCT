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
#include <BinMFunction_FunctionDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinMFunction_FunctionDriver(py::module &mod){

py::class_<BinMFunction_FunctionDriver, opencascade::handle<BinMFunction_FunctionDriver>, BinMDF_ADriver> cls_BinMFunction_FunctionDriver(mod, "BinMFunction_FunctionDriver", "Function attribute Driver.");

// Constructors
cls_BinMFunction_FunctionDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinMFunction_FunctionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_FunctionDriver::*)() const) &BinMFunction_FunctionDriver::NewEmpty, "None");
cls_BinMFunction_FunctionDriver.def("Paste", (Standard_Boolean (BinMFunction_FunctionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_FunctionDriver.def("Paste", (void (BinMFunction_FunctionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMFunction_FunctionDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_FunctionDriver::get_type_name, "None");
cls_BinMFunction_FunctionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_FunctionDriver::get_type_descriptor, "None");
cls_BinMFunction_FunctionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_FunctionDriver::*)() const) &BinMFunction_FunctionDriver::DynamicType, "None");

// Enums

}