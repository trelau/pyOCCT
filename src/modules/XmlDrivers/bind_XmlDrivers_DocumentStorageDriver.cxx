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
#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Element.hxx>
#include <XmlDrivers_DocumentStorageDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlDrivers_DocumentStorageDriver(py::module &mod){

py::class_<XmlDrivers_DocumentStorageDriver, opencascade::handle<XmlDrivers_DocumentStorageDriver>, XmlLDrivers_DocumentStorageDriver> cls_XmlDrivers_DocumentStorageDriver(mod, "XmlDrivers_DocumentStorageDriver", "None");

// Constructors
cls_XmlDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));

// Fields

// Methods
cls_XmlDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlDrivers_DocumentStorageDriver.def("WriteShapeSection", (Standard_Boolean (XmlDrivers_DocumentStorageDriver::*)(XmlObjMgt_Element &)) &XmlDrivers_DocumentStorageDriver::WriteShapeSection, "None", py::arg("thePDoc"));
cls_XmlDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlDrivers_DocumentStorageDriver::get_type_name, "None");
cls_XmlDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_XmlDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlDrivers_DocumentStorageDriver::*)() const) &XmlDrivers_DocumentStorageDriver::DynamicType, "None");

// Enums

}