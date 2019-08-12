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
#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlTObjDrivers_XYZDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlTObjDrivers_XYZDriver(py::module &mod){

py::class_<XmlTObjDrivers_XYZDriver, opencascade::handle<XmlTObjDrivers_XYZDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_XYZDriver(mod, "XmlTObjDrivers_XYZDriver", "None");

// Constructors
cls_XmlTObjDrivers_XYZDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_XmlTObjDrivers_XYZDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_XYZDriver::*)() const) &XmlTObjDrivers_XYZDriver::NewEmpty, "None");
cls_XmlTObjDrivers_XYZDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_XYZDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlTObjDrivers_XYZDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlTObjDrivers_XYZDriver.def("Paste", (void (XmlTObjDrivers_XYZDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlTObjDrivers_XYZDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlTObjDrivers_XYZDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_XYZDriver::get_type_name, "None");
cls_XmlTObjDrivers_XYZDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_XYZDriver::get_type_descriptor, "None");
cls_XmlTObjDrivers_XYZDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_XYZDriver::*)() const) &XmlTObjDrivers_XYZDriver::DynamicType, "None");

// Enums

}