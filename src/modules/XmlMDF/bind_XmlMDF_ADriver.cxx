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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlMDF_ADriver.hxx>
#include <Message_Messenger.hxx>
#include <XmlMDF.hxx>

void bind_XmlMDF_ADriver(py::module &mod){

py::class_<XmlMDF_ADriver, opencascade::handle<XmlMDF_ADriver>, Standard_Transient> cls_XmlMDF_ADriver(mod, "XmlMDF_ADriver", "Attribute Storage/Retrieval Driver.");

// Fields

// Methods
cls_XmlMDF_ADriver.def("VersionNumber", (Standard_Integer (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::VersionNumber, "Returns the version number from which the driver is available.");
cls_XmlMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
cls_XmlMDF_ADriver.def("SourceType", (opencascade::handle<Standard_Type> (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
cls_XmlMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::TypeName, "Returns the full XML tag name (including NS prefix)");
cls_XmlMDF_ADriver.def("Paste", (Standard_Boolean (XmlMDF_ADriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_XmlMDF_ADriver.def("Paste", (void (XmlMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const) &XmlMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_XmlMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &XmlMDF_ADriver::get_type_name, "None");
cls_XmlMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDF_ADriver::get_type_descriptor, "None");
cls_XmlMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDF_ADriver::*)() const) &XmlMDF_ADriver::DynamicType, "None");

// Enums

}