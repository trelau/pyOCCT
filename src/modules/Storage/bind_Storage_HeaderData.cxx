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
#include <Storage_BaseDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_Error.hxx>
#include <Storage_Schema.hxx>
#include <Standard_Handle.hxx>
#include <Storage_HeaderData.hxx>
#include <Standard_Type.hxx>

void bind_Storage_HeaderData(py::module &mod){

py::class_<Storage_HeaderData, opencascade::handle<Storage_HeaderData>, Standard_Transient> cls_Storage_HeaderData(mod, "Storage_HeaderData", "None");

// Constructors
cls_Storage_HeaderData.def(py::init<>());

// Fields

// Methods
cls_Storage_HeaderData.def("Read", (Standard_Boolean (Storage_HeaderData::*)(Storage_BaseDriver &)) &Storage_HeaderData::Read, "None", py::arg("theDriver"));
cls_Storage_HeaderData.def("CreationDate", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::CreationDate, "return the creation date");
cls_Storage_HeaderData.def("StorageVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::StorageVersion, "return the Storage package version");
cls_Storage_HeaderData.def("SchemaVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::SchemaVersion, "get the version of the schema");
cls_Storage_HeaderData.def("SchemaName", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::SchemaName, "get the schema's name");
cls_Storage_HeaderData.def("SetApplicationVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetApplicationVersion, "set the version of the application", py::arg("aVersion"));
cls_Storage_HeaderData.def("ApplicationVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::ApplicationVersion, "get the version of the application");
cls_Storage_HeaderData.def("SetApplicationName", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::SetApplicationName, "set the name of the application", py::arg("aName"));
cls_Storage_HeaderData.def("ApplicationName", (TCollection_ExtendedString (Storage_HeaderData::*)() const) &Storage_HeaderData::ApplicationName, "get the name of the application");
cls_Storage_HeaderData.def("SetDataType", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::SetDataType, "set the data type", py::arg("aType"));
cls_Storage_HeaderData.def("DataType", (TCollection_ExtendedString (Storage_HeaderData::*)() const) &Storage_HeaderData::DataType, "returns data type");
cls_Storage_HeaderData.def("AddToUserInfo", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::AddToUserInfo, "add <theUserInfo> to the user informations", py::arg("theUserInfo"));
cls_Storage_HeaderData.def("UserInfo", (const TColStd_SequenceOfAsciiString & (Storage_HeaderData::*)() const) &Storage_HeaderData::UserInfo, "return the user informations");
cls_Storage_HeaderData.def("AddToComments", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::AddToComments, "add <theUserInfo> to the user informations", py::arg("aComment"));
cls_Storage_HeaderData.def("Comments", (const TColStd_SequenceOfExtendedString & (Storage_HeaderData::*)() const) &Storage_HeaderData::Comments, "return the user informations");
cls_Storage_HeaderData.def("NumberOfObjects", (Standard_Integer (Storage_HeaderData::*)() const) &Storage_HeaderData::NumberOfObjects, "the the number of persistent objects Return: the number of persistent objects readed");
cls_Storage_HeaderData.def("ErrorStatus", (Storage_Error (Storage_HeaderData::*)() const) &Storage_HeaderData::ErrorStatus, "None");
cls_Storage_HeaderData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_HeaderData::*)() const) &Storage_HeaderData::ErrorStatusExtension, "None");
cls_Storage_HeaderData.def("ClearErrorStatus", (void (Storage_HeaderData::*)()) &Storage_HeaderData::ClearErrorStatus, "None");
cls_Storage_HeaderData.def_static("get_type_name_", (const char * (*)()) &Storage_HeaderData::get_type_name, "None");
cls_Storage_HeaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HeaderData::get_type_descriptor, "None");
cls_Storage_HeaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HeaderData::*)() const) &Storage_HeaderData::DynamicType, "None");
cls_Storage_HeaderData.def("SetNumberOfObjects", (void (Storage_HeaderData::*)(const Standard_Integer)) &Storage_HeaderData::SetNumberOfObjects, "None", py::arg("anObjectNumber"));
cls_Storage_HeaderData.def("SetStorageVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetStorageVersion, "None", py::arg("aVersion"));
cls_Storage_HeaderData.def("SetCreationDate", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetCreationDate, "None", py::arg("aDate"));
cls_Storage_HeaderData.def("SetSchemaVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetSchemaVersion, "None", py::arg("aVersion"));
cls_Storage_HeaderData.def("SetSchemaName", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetSchemaName, "None", py::arg("aName"));

// Enums

}