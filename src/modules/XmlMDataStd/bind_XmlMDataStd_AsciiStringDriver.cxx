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
#include <XmlMDataStd_AsciiStringDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMDataStd_AsciiStringDriver(py::module &mod){

py::class_<XmlMDataStd_AsciiStringDriver, opencascade::handle<XmlMDataStd_AsciiStringDriver>, XmlMDF_ADriver> cls_XmlMDataStd_AsciiStringDriver(mod, "XmlMDataStd_AsciiStringDriver", "TDataStd_AsciiString attribute Driver.");

// Constructors
cls_XmlMDataStd_AsciiStringDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMessageDriver"));

// Fields

// Methods
cls_XmlMDataStd_AsciiStringDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDataStd_AsciiStringDriver::*)() const) &XmlMDataStd_AsciiStringDriver::NewEmpty, "None");
cls_XmlMDataStd_AsciiStringDriver.def("Paste", (Standard_Boolean (XmlMDataStd_AsciiStringDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDataStd_AsciiStringDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_AsciiStringDriver.def("Paste", (void (XmlMDataStd_AsciiStringDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDataStd_AsciiStringDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
cls_XmlMDataStd_AsciiStringDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDataStd_AsciiStringDriver::get_type_name, "None");
cls_XmlMDataStd_AsciiStringDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDataStd_AsciiStringDriver::get_type_descriptor, "None");
cls_XmlMDataStd_AsciiStringDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDataStd_AsciiStringDriver::*)() const) &XmlMDataStd_AsciiStringDriver::DynamicType, "None");

// Enums

}