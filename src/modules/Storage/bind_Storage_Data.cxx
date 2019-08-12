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
#include <Storage_Error.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Persistent.hxx>
#include <Storage_HSeqOfRoot.hxx>
#include <Storage_Root.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Storage_Schema.hxx>
#include <Storage_Data.hxx>
#include <Standard_Type.hxx>
#include <Storage_HeaderData.hxx>
#include <Storage_RootData.hxx>
#include <Storage_TypeData.hxx>
#include <Storage_InternalData.hxx>

void bind_Storage_Data(py::module &mod){

py::class_<Storage_Data, opencascade::handle<Storage_Data>, Standard_Transient> cls_Storage_Data(mod, "Storage_Data", "A picture memorizing the data stored in a container (for example, in a file). A Storage_Data object represents either: - persistent data to be written into a container, or - persistent data which are read from a container. A Storage_Data object is used in both the storage and retrieval operations: - Storage mechanism: create an empty Storage_Data object, then add successively persistent objects (roots) to be stored using the function AddRoot. When the set of data is complete, write it to a container using the function Write in your Storage_Schema storage/retrieval algorithm. - Retrieval mechanism: a Storage_Data object is returned by the Read function from your Storage_Schema storage/retrieval algorithm. Use the functions NumberOfRoots and Roots to find the roots which were stored in the read container. The roots of a Storage_Data object may share references on objects. The shared internal references of a Storage_Data object are maintained by the storage/retrieval mechanism. Note: References shared by objects which are contained in two distinct Storage_Data objects are not maintained by the storage/retrieval mechanism: external references are not supported by Storage_Schema algorithm");

// Constructors
cls_Storage_Data.def(py::init<>());

// Fields

// Methods
cls_Storage_Data.def("ErrorStatus", (Storage_Error (Storage_Data::*)() const) &Storage_Data::ErrorStatus, "Returns Storage_VSOk if - the last storage operation performed with the function Read, or - the last retrieval operation performed with the function Write by a Storage_Schema algorithm, on this set of data was successful. If the storage or retrieval operation was not performed, the returned error status indicates the reason why the operation failed. The algorithm stops its analysis at the first detected error");
cls_Storage_Data.def("ClearErrorStatus", (void (Storage_Data::*)()) &Storage_Data::ClearErrorStatus, "Clears the error status positioned either by: - the last storage operation performed with the Read function, or - the last retrieval operation performed with the Write function by a Storage_Schema algorithm, on this set of data. This error status may be read by the function ErrorStatus.");
cls_Storage_Data.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::ErrorStatusExtension, "None");
cls_Storage_Data.def("CreationDate", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::CreationDate, "return the creation date");
cls_Storage_Data.def("StorageVersion", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::StorageVersion, "return the Storage package version");
cls_Storage_Data.def("SchemaVersion", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::SchemaVersion, "get the version of the schema");
cls_Storage_Data.def("SchemaName", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::SchemaName, "get the schema's name");
cls_Storage_Data.def("SetApplicationVersion", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::SetApplicationVersion, "set the version of the application", py::arg("aVersion"));
cls_Storage_Data.def("ApplicationVersion", (TCollection_AsciiString (Storage_Data::*)() const) &Storage_Data::ApplicationVersion, "get the version of the application");
cls_Storage_Data.def("SetApplicationName", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::SetApplicationName, "set the name of the application", py::arg("aName"));
cls_Storage_Data.def("ApplicationName", (TCollection_ExtendedString (Storage_Data::*)() const) &Storage_Data::ApplicationName, "get the name of the application");
cls_Storage_Data.def("SetDataType", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::SetDataType, "set the data type", py::arg("aType"));
cls_Storage_Data.def("DataType", (TCollection_ExtendedString (Storage_Data::*)() const) &Storage_Data::DataType, "returns data type");
cls_Storage_Data.def("AddToUserInfo", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::AddToUserInfo, "add <theUserInfo> to the user informations", py::arg("anInfo"));
cls_Storage_Data.def("UserInfo", (const TColStd_SequenceOfAsciiString & (Storage_Data::*)() const) &Storage_Data::UserInfo, "return the user informations");
cls_Storage_Data.def("AddToComments", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::AddToComments, "add <theUserInfo> to the user informations", py::arg("aComment"));
cls_Storage_Data.def("Comments", (const TColStd_SequenceOfExtendedString & (Storage_Data::*)() const) &Storage_Data::Comments, "return the user informations");
cls_Storage_Data.def("NumberOfObjects", (Standard_Integer (Storage_Data::*)() const) &Storage_Data::NumberOfObjects, "the the number of persistent objects Return: the number of persistent objects readed");
cls_Storage_Data.def("NumberOfRoots", (Standard_Integer (Storage_Data::*)() const) &Storage_Data::NumberOfRoots, "Returns the number of root objects in this set of data. - When preparing a storage operation, the result is the number of roots inserted into this set of data with the function AddRoot. - When retrieving an object, the result is the number of roots stored in the read container. Use the Roots function to get these roots in a sequence.");
cls_Storage_Data.def("AddRoot", (void (Storage_Data::*)(const opencascade::handle<Standard_Persistent> &) const) &Storage_Data::AddRoot, "add a persistent root to write. the name of the root is a driver reference number.", py::arg("anObject"));
cls_Storage_Data.def("AddRoot", (void (Storage_Data::*)(const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &) const) &Storage_Data::AddRoot, "Adds the root anObject to this set of data. The name of the root is aName if given; if not, it will be a reference number assigned by the driver when writing the set of data into the container. When naming the roots, it is easier to retrieve objects by significant references rather than by references without any semantic values.", py::arg("aName"), py::arg("anObject"));
cls_Storage_Data.def("RemoveRoot", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::RemoveRoot, "Removes from this set of data the root object named aName. Warning Nothing is done if there is no root object whose name is aName in this set of data.", py::arg("aName"));
cls_Storage_Data.def("Roots", (opencascade::handle<Storage_HSeqOfRoot> (Storage_Data::*)() const) &Storage_Data::Roots, "Returns the roots of this set of data in a sequence. - When preparing a storage operation, the sequence contains the roots inserted into this set of data with the function AddRoot. - When retrieving an object, the sequence contains the roots stored in the container read. - An empty sequence is returned if there is no root in this set of data.");
cls_Storage_Data.def("Find", (opencascade::handle<Storage_Root> (Storage_Data::*)(const TCollection_AsciiString &) const) &Storage_Data::Find, "Gives the root object whose name is aName in this set of data. The returned object is a Storage_Root object, from which the object it encapsulates may be extracted. Warning A null handle is returned if there is no root object whose name is aName in this set of data.", py::arg("aName"));
cls_Storage_Data.def("IsRoot", (Standard_Boolean (Storage_Data::*)(const TCollection_AsciiString &) const) &Storage_Data::IsRoot, "returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
cls_Storage_Data.def("NumberOfTypes", (Standard_Integer (Storage_Data::*)() const) &Storage_Data::NumberOfTypes, "Returns the number of types of objects used in this set of data.");
cls_Storage_Data.def("IsType", (Standard_Boolean (Storage_Data::*)(const TCollection_AsciiString &) const) &Storage_Data::IsType, "Returns true if this set of data contains an object of type aName. Persistent objects from this set of data must have types which are recognized by the Storage_Schema algorithm used to store or retrieve them.", py::arg("aName"));
cls_Storage_Data.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_Data::*)() const) &Storage_Data::Types, "Gives the list of types of objects used in this set of data in a sequence.");
cls_Storage_Data.def_static("get_type_name_", (const char * (*)()) &Storage_Data::get_type_name, "None");
cls_Storage_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Data::get_type_descriptor, "None");
cls_Storage_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Data::*)() const) &Storage_Data::DynamicType, "None");
cls_Storage_Data.def("HeaderData", (opencascade::handle<Storage_HeaderData> (Storage_Data::*)() const) &Storage_Data::HeaderData, "None");
cls_Storage_Data.def("RootData", (opencascade::handle<Storage_RootData> (Storage_Data::*)() const) &Storage_Data::RootData, "None");
cls_Storage_Data.def("TypeData", (opencascade::handle<Storage_TypeData> (Storage_Data::*)() const) &Storage_Data::TypeData, "None");
cls_Storage_Data.def("InternalData", (opencascade::handle<Storage_InternalData> (Storage_Data::*)() const) &Storage_Data::InternalData, "None");
cls_Storage_Data.def("Clear", (void (Storage_Data::*)() const) &Storage_Data::Clear, "None");

// Enums

}