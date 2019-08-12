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
#include <XmlMXCAFDoc_NotesToolDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlMXCAFDoc_NotesToolDriver(py::module &mod){

py::class_<XmlMXCAFDoc_NotesToolDriver, opencascade::handle<XmlMXCAFDoc_NotesToolDriver>, XmlMDF_ADriver> cls_XmlMXCAFDoc_NotesToolDriver(mod, "XmlMXCAFDoc_NotesToolDriver", "Attribute Driver.");

// Constructors
cls_XmlMXCAFDoc_NotesToolDriver.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("theMsgDriver"));

// Fields

// Methods
cls_XmlMXCAFDoc_NotesToolDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMXCAFDoc_NotesToolDriver::*)() const) &XmlMXCAFDoc_NotesToolDriver::NewEmpty, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def("Paste", (Standard_Boolean (XmlMXCAFDoc_NotesToolDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NotesToolDriver.def("Paste", (void (XmlMXCAFDoc_NotesToolDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMXCAFDoc_NotesToolDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
cls_XmlMXCAFDoc_NotesToolDriver.def_static("get_type_name_", (const char * (*)()) &XmlMXCAFDoc_NotesToolDriver::get_type_name, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMXCAFDoc_NotesToolDriver::get_type_descriptor, "None");
cls_XmlMXCAFDoc_NotesToolDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMXCAFDoc_NotesToolDriver::*)() const) &XmlMXCAFDoc_NotesToolDriver::DynamicType, "None");

// Enums

}