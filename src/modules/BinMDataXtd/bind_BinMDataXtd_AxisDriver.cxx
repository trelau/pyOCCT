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
#include <BinMDataXtd_AxisDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinMDataXtd_AxisDriver(py::module &mod){

py::class_<BinMDataXtd_AxisDriver, opencascade::handle<BinMDataXtd_AxisDriver>, BinMDF_ADriver> cls_BinMDataXtd_AxisDriver(mod, "BinMDataXtd_AxisDriver", "Axis attribute Driver.");

// Constructors
cls_BinMDataXtd_AxisDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_BinMDataXtd_AxisDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataXtd_AxisDriver::*)() const) &BinMDataXtd_AxisDriver::NewEmpty, "None");
cls_BinMDataXtd_AxisDriver.def("Paste", (Standard_Boolean (BinMDataXtd_AxisDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataXtd_AxisDriver.def("Paste", (void (BinMDataXtd_AxisDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDataXtd_AxisDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_BinMDataXtd_AxisDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataXtd_AxisDriver::get_type_name, "None");
cls_BinMDataXtd_AxisDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataXtd_AxisDriver::get_type_descriptor, "None");
cls_BinMDataXtd_AxisDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataXtd_AxisDriver::*)() const) &BinMDataXtd_AxisDriver::DynamicType, "None");

// Enums

}