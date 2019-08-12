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
#include <XmlMNaming_NamingDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMNaming_NamingDriver(py::module &mod){

py::class_<XmlMNaming_NamingDriver, opencascade::handle<XmlMNaming_NamingDriver>, XmlMDF_ADriver> cls_XmlMNaming_NamingDriver(mod, "XmlMNaming_NamingDriver", "None");

// Constructors
cls_XmlMNaming_NamingDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("aMessageDriver"));

// Fields

// Methods
cls_XmlMNaming_NamingDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMNaming_NamingDriver::*)() const) &XmlMNaming_NamingDriver::NewEmpty, "None");
cls_XmlMNaming_NamingDriver.def("Paste", (Standard_Boolean (XmlMNaming_NamingDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMNaming_NamingDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMNaming_NamingDriver.def("Paste", (void (XmlMNaming_NamingDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMNaming_NamingDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMNaming_NamingDriver.def_static("get_type_name_", (const char * (*)()) &XmlMNaming_NamingDriver::get_type_name, "None");
cls_XmlMNaming_NamingDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMNaming_NamingDriver::get_type_descriptor, "None");
cls_XmlMNaming_NamingDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMNaming_NamingDriver::*)() const) &XmlMNaming_NamingDriver::DynamicType, "None");

// Enums

}