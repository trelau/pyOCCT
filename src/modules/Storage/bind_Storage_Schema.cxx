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
#include <TCollection_AsciiString.hxx>
#include <Storage_BaseDriver.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_CallBack.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Standard_Persistent.hxx>
#include <Storage_Schema.hxx>
#include <Standard_Type.hxx>
#include <Storage_MapOfCallBack.hxx>

void bind_Storage_Schema(py::module &mod){

py::class_<Storage_Schema, opencascade::handle<Storage_Schema>, Standard_Transient> cls_Storage_Schema(mod, "Storage_Schema", "Root class for basic storage/retrieval algorithms. A Storage_Schema object processes: - writing of a set of persistent data into a container (store mechanism), - reading of a container to extract all the contained persistent data (retrieve mechanism). A Storage_Schema object is based on the data schema for the persistent data of the application, i.e.: - the list of all persistent objects which may be known by the application, - the organization of their data; a data schema knows how to browse each persistent object it contains. During the store or retrieve operation, only persistent objects known from the data schema can be processed; they are then stored or retrieved according to their description in the schema. A data schema is specific to the object classes to be read or written. Tools dedicated to the environment in use allow a description of the application persistent data structure. Storage_Schema algorithms are called basic because they do not support external references between containers.");

// Constructors
cls_Storage_Schema.def(py::init<>());

// Fields

// Methods
cls_Storage_Schema.def("SetVersion", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::SetVersion, "returns version of the schema", py::arg("aVersion"));
cls_Storage_Schema.def("Version", (TCollection_AsciiString (Storage_Schema::*)() const) &Storage_Schema::Version, "returns the version of the schema");
cls_Storage_Schema.def("SetName", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::SetName, "set the schema's name", py::arg("aSchemaName"));
cls_Storage_Schema.def("Name", (TCollection_AsciiString (Storage_Schema::*)() const) &Storage_Schema::Name, "returns the schema's name");
cls_Storage_Schema.def("Write", (void (Storage_Schema::*)(Storage_BaseDriver &, const opencascade::handle<Storage_Data> &) const) &Storage_Schema::Write, "Writes the data aggregated in aData into the container defined by the driver s. The storage operation is performed according to the data schema with which this algorithm is working. Note: aData may aggregate several root objects to be stored together.", py::arg("s"), py::arg("aData"));
cls_Storage_Schema.def_static("ICreationDate_", (TCollection_AsciiString (*)()) &Storage_Schema::ICreationDate, "return a current date string");
cls_Storage_Schema.def_static("CheckTypeMigration_", (Standard_Boolean (*)(const TCollection_AsciiString &, TCollection_AsciiString &)) &Storage_Schema::CheckTypeMigration, "returns True if theType migration is identified the callback support provides a way to read a file with a incomplete schema. ex. : A file contains 3 types a,b and c. The application's schema contains only 2 type a and b. If you try to read the file in the application, you will have an error.To bypass this problem you can give to your application's schema a callback used when the schema dosent know how to handle this type.", py::arg("theTypeName"), py::arg("theNewName"));
cls_Storage_Schema.def("AddReadUnknownTypeCallBack", (void (Storage_Schema::*)(const TCollection_AsciiString &, const opencascade::handle<Storage_CallBack> &)) &Storage_Schema::AddReadUnknownTypeCallBack, "add two functions to the callback list", py::arg("aTypeName"), py::arg("aCallBack"));
cls_Storage_Schema.def("RemoveReadUnknownTypeCallBack", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::RemoveReadUnknownTypeCallBack, "remove a callback for a type", py::arg("aTypeName"));
cls_Storage_Schema.def("InstalledCallBackList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_Schema::*)() const) &Storage_Schema::InstalledCallBackList, "returns a list of type name with installed callback.");
cls_Storage_Schema.def("ClearCallBackList", (void (Storage_Schema::*)()) &Storage_Schema::ClearCallBackList, "clear all callback from schema instance.");
cls_Storage_Schema.def("UseDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::UseDefaultCallBack, "install a callback for all unknown type. the objects with unknown types will be skipped. (look SkipObject method in BaseDriver)");
cls_Storage_Schema.def("DontUseDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::DontUseDefaultCallBack, "tells schema to uninstall the default callback.");
cls_Storage_Schema.def("IsUsingDefaultCallBack", (Standard_Boolean (Storage_Schema::*)() const) &Storage_Schema::IsUsingDefaultCallBack, "ask if the schema is using the default callback.");
cls_Storage_Schema.def("SetDefaultCallBack", (void (Storage_Schema::*)(const opencascade::handle<Storage_CallBack> &)) &Storage_Schema::SetDefaultCallBack, "overload the default function for build.(use to set an error message or skip an object while reading an unknown type).", py::arg("f"));
cls_Storage_Schema.def("ResetDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::ResetDefaultCallBack, "reset the default function defined by Storage package.");
cls_Storage_Schema.def("DefaultCallBack", (opencascade::handle<Storage_CallBack> (Storage_Schema::*)() const) &Storage_Schema::DefaultCallBack, "returns the read function used when the UseDefaultCallBack() is set.");
cls_Storage_Schema.def("WritePersistentObjectHeader", (void (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &)) &Storage_Schema::WritePersistentObjectHeader, "None", py::arg("sp"), py::arg("s"));
cls_Storage_Schema.def("WritePersistentReference", (void (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &)) &Storage_Schema::WritePersistentReference, "None", py::arg("sp"), py::arg("s"));
cls_Storage_Schema.def("AddPersistent", (Standard_Boolean (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, const Standard_CString) const) &Storage_Schema::AddPersistent, "None", py::arg("sp"), py::arg("tName"));
cls_Storage_Schema.def("PersistentToAdd", (Standard_Boolean (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &) const) &Storage_Schema::PersistentToAdd, "None", py::arg("sp"));
cls_Storage_Schema.def_static("get_type_name_", (const char * (*)()) &Storage_Schema::get_type_name, "None");
cls_Storage_Schema.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Schema::get_type_descriptor, "None");
cls_Storage_Schema.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Schema::*)() const) &Storage_Schema::DynamicType, "None");

// Enums

}