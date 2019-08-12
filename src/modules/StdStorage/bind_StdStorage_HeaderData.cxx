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
#include <StdStorage_Data.hxx>
#include <Standard_Handle.hxx>
#include <StdStorage_HeaderData.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_BaseDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_Error.hxx>

void bind_StdStorage_HeaderData(py::module &mod){

py::class_<StdStorage_HeaderData, opencascade::handle<StdStorage_HeaderData>, Standard_Transient> cls_StdStorage_HeaderData(mod, "StdStorage_HeaderData", "Storage header data section that contains some auxiliary information (application name, schema version, creation date, comments and so on...)");

// Constructors

// Fields

// Methods
cls_StdStorage_HeaderData.def_static("get_type_name_", (const char * (*)()) &StdStorage_HeaderData::get_type_name, "None");
cls_StdStorage_HeaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_HeaderData::get_type_descriptor, "None");
cls_StdStorage_HeaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::DynamicType, "None");
cls_StdStorage_HeaderData.def("Read", (Standard_Boolean (StdStorage_HeaderData::*)(Storage_BaseDriver &)) &StdStorage_HeaderData::Read, "Reads the header data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_HeaderData.def("Write", (Standard_Boolean (StdStorage_HeaderData::*)(Storage_BaseDriver &)) &StdStorage_HeaderData::Write, "Writes the header data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_HeaderData.def("CreationDate", (TCollection_AsciiString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::CreationDate, "Return the creation date");
cls_StdStorage_HeaderData.def("StorageVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::StorageVersion, "Return the Storage package version");
cls_StdStorage_HeaderData.def("SchemaVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::SchemaVersion, "Get the version of the schema");
cls_StdStorage_HeaderData.def("SetApplicationVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetApplicationVersion, "Set the version of the application", py::arg("aVersion"));
cls_StdStorage_HeaderData.def("ApplicationVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::ApplicationVersion, "Get the version of the application");
cls_StdStorage_HeaderData.def("SetApplicationName", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::SetApplicationName, "Set the name of the application", py::arg("aName"));
cls_StdStorage_HeaderData.def("ApplicationName", (TCollection_ExtendedString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::ApplicationName, "Get the name of the application");
cls_StdStorage_HeaderData.def("SetDataType", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::SetDataType, "Set the data type", py::arg("aType"));
cls_StdStorage_HeaderData.def("DataType", (TCollection_ExtendedString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::DataType, "Returns data type");
cls_StdStorage_HeaderData.def("AddToUserInfo", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::AddToUserInfo, "Add <theUserInfo> to the user informations", py::arg("theUserInfo"));
cls_StdStorage_HeaderData.def("UserInfo", (const TColStd_SequenceOfAsciiString & (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::UserInfo, "Return the user informations");
cls_StdStorage_HeaderData.def("AddToComments", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::AddToComments, "Add <theUserInfo> to the user informations", py::arg("aComment"));
cls_StdStorage_HeaderData.def("Comments", (const TColStd_SequenceOfExtendedString & (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::Comments, "Return the user informations");
cls_StdStorage_HeaderData.def("NumberOfObjects", (Standard_Integer (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::NumberOfObjects, "Returns the number of persistent objects");
cls_StdStorage_HeaderData.def("ErrorStatus", (Storage_Error (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
cls_StdStorage_HeaderData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_HeaderData::*)() const) &StdStorage_HeaderData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
cls_StdStorage_HeaderData.def("ClearErrorStatus", (void (StdStorage_HeaderData::*)()) &StdStorage_HeaderData::ClearErrorStatus, "Clears error status");
cls_StdStorage_HeaderData.def("SetNumberOfObjects", (void (StdStorage_HeaderData::*)(const Standard_Integer)) &StdStorage_HeaderData::SetNumberOfObjects, "None", py::arg("anObjectNumber"));
cls_StdStorage_HeaderData.def("SetStorageVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetStorageVersion, "None", py::arg("aVersion"));
cls_StdStorage_HeaderData.def("SetCreationDate", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetCreationDate, "None", py::arg("aDate"));
cls_StdStorage_HeaderData.def("SetSchemaVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetSchemaVersion, "None", py::arg("aVersion"));
cls_StdStorage_HeaderData.def("SetSchemaName", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetSchemaName, "None", py::arg("aName"));

// Enums

}