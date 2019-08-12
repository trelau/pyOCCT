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
#include <PCDM_StorageDriver.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <Standard_OStream.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Element.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlLDrivers_SequenceOfNamespaceDef.hxx>

void bind_XmlLDrivers_DocumentStorageDriver(py::module &mod){

py::class_<XmlLDrivers_DocumentStorageDriver, opencascade::handle<XmlLDrivers_DocumentStorageDriver>, PCDM_StorageDriver> cls_XmlLDrivers_DocumentStorageDriver(mod, "XmlLDrivers_DocumentStorageDriver", "None");

// Constructors
cls_XmlLDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));

// Fields

// Methods
cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theFileName"));
cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theOStream"));
cls_XmlLDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlLDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_name, "None");
cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_XmlLDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentStorageDriver::*)() const) &XmlLDrivers_DocumentStorageDriver::DynamicType, "None");

// Enums

}