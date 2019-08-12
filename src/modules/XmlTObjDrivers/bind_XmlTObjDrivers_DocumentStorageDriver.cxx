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
#include <XmlTObjDrivers_DocumentStorageDriver.hxx>
#include <Standard_Type.hxx>

void bind_XmlTObjDrivers_DocumentStorageDriver(py::module &mod){

py::class_<XmlTObjDrivers_DocumentStorageDriver, opencascade::handle<XmlTObjDrivers_DocumentStorageDriver>, XmlLDrivers_DocumentStorageDriver> cls_XmlTObjDrivers_DocumentStorageDriver(mod, "XmlTObjDrivers_DocumentStorageDriver", "None");

// Constructors
cls_XmlTObjDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));

// Fields

// Methods
cls_XmlTObjDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlTObjDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlTObjDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlTObjDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_DocumentStorageDriver::get_type_name, "None");
cls_XmlTObjDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_XmlTObjDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_DocumentStorageDriver::*)() const) &XmlTObjDrivers_DocumentStorageDriver::DynamicType, "None");

// Enums

}