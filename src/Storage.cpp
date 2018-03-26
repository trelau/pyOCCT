/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Storage_Error.hxx>
#include <Standard_Transient.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_BaseDriver.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_CallBack.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Standard_Persistent.hxx>
#include <Standard_Type.hxx>
#include <Storage_Schema.hxx>
#include <Storage_Root.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Storage_SeqOfRoot.hxx>
#include <Storage_HSeqOfRoot.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_HeaderData.hxx>
#include <Storage_RootData.hxx>
#include <Storage_TypeData.hxx>
#include <Storage_HPArray.hxx>
#include <Storage_InternalData.hxx>
#include <Storage_Position.hxx>
#include <Storage_OpenMode.hxx>
#include <Storage_StreamReadError.hxx>
#include <Standard_SStream.hxx>
#include <Storage_StreamTypeMismatchError.hxx>
#include <Standard_Failure.hxx>
#include <Storage_StreamFormatError.hxx>
#include <Storage_StreamWriteError.hxx>
#include <Storage_StreamExtCharParityError.hxx>
#include <Standard_IStream.hxx>
#include <Storage_DefaultCallBack.hxx>
#include <Storage_stCONSTclCOM.hxx>
#include <Storage_TypedCallBack.hxx>
#include <Storage.hxx>
#include <NCollection_Array1.hxx>
#include <Storage_ArrayOfCallBack.hxx>
#include <Storage_ArrayOfSchema.hxx>
#include <Storage_BucketOfPersistent.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <Storage_MapOfCallBack.hxx>
#include <Storage_MapOfPers.hxx>
#include <Storage_HArrayOfCallBack.hxx>
#include <Storage_SolveMode.hxx>
#include <Storage_PArray.hxx>
#include <Storage_HArrayOfSchema.hxx>
#include <Storage_StreamModeError.hxx>
#include <Storage_StreamUnknownTypeError.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Storage, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_Error.hxx
	py::enum_<Storage_Error>(mod, "Storage_Error", "Error codes returned by the ErrorStatus function on a Storage_Data set of data during a storage or retrieval operation : - Storage_VSOk : no problem has been detected - Storage_VSOpenError : an error has occurred when opening the driver - Storage_VSModeError : the driver has not been opened in the correct mode - Storage_VSCloseError : an error has occurred when closing the driver - Storage_VSAlreadyOpen : the driver is already open - Storage_VSNotOpen : the driver is not open - Storage_VSSectionNotFound : a section has not been found in the driver - Storage_VSWriteError : an error occurred when writing the driver - Storage_VSFormatError : the file format is wrong - Storage_VSUnknownType : a type is not known from the schema - Storage_VSTypeMismatch : trying to read a wrong type - Storage_VSInternalError : an internal error has been detected - Storage_VSExtCharParityError : an error has occurred while reading 16 bit characte")
		.value("Storage_VSOk", Storage_Error::Storage_VSOk)
		.value("Storage_VSOpenError", Storage_Error::Storage_VSOpenError)
		.value("Storage_VSModeError", Storage_Error::Storage_VSModeError)
		.value("Storage_VSCloseError", Storage_Error::Storage_VSCloseError)
		.value("Storage_VSAlreadyOpen", Storage_Error::Storage_VSAlreadyOpen)
		.value("Storage_VSNotOpen", Storage_Error::Storage_VSNotOpen)
		.value("Storage_VSSectionNotFound", Storage_Error::Storage_VSSectionNotFound)
		.value("Storage_VSWriteError", Storage_Error::Storage_VSWriteError)
		.value("Storage_VSFormatError", Storage_Error::Storage_VSFormatError)
		.value("Storage_VSUnknownType", Storage_Error::Storage_VSUnknownType)
		.value("Storage_VSTypeMismatch", Storage_Error::Storage_VSTypeMismatch)
		.value("Storage_VSInternalError", Storage_Error::Storage_VSInternalError)
		.value("Storage_VSExtCharParityError", Storage_Error::Storage_VSExtCharParityError)
		.value("Storage_VSWrongFileDriver", Storage_Error::Storage_VSWrongFileDriver)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_OpenMode.hxx
	py::enum_<Storage_OpenMode>(mod, "Storage_OpenMode", "Specifies opening modes for a file: - Storage_VSNone : no mode is specified - Storage_VSRead : the file is open for reading operations - Storage_VSWrite : the file is open for writing operations - Storage_VSReadWrite : the file is open for both reading and writing operations.")
		.value("Storage_VSNone", Storage_OpenMode::Storage_VSNone)
		.value("Storage_VSRead", Storage_OpenMode::Storage_VSRead)
		.value("Storage_VSWrite", Storage_OpenMode::Storage_VSWrite)
		.value("Storage_VSReadWrite", Storage_OpenMode::Storage_VSReadWrite)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_SolveMode.hxx
	py::enum_<Storage_SolveMode>(mod, "Storage_SolveMode", "None")
		.value("Storage_AddSolve", Storage_SolveMode::Storage_AddSolve)
		.value("Storage_WriteSolve", Storage_SolveMode::Storage_WriteSolve)
		.value("Storage_ReadSolve", Storage_SolveMode::Storage_ReadSolve)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_Schema.hxx
	py::class_<Storage_Schema, opencascade::handle<Storage_Schema>, Standard_Transient> cls_Storage_Schema(mod, "Storage_Schema", "Root class for basic storage/retrieval algorithms. A Storage_Schema object processes: - writing of a set of persistent data into a container (store mechanism), - reading of a container to extract all the contained persistent data (retrieve mechanism). A Storage_Schema object is based on the data schema for the persistent data of the application, i.e.: - the list of all persistent objects which may be known by the application, - the organization of their data; a data schema knows how to browse each persistent object it contains. During the store or retrieve operation, only persistent objects known from the data schema can be processed; they are then stored or retrieved according to their description in the schema. A data schema is specific to the object classes to be read or written. Tools dedicated to the environment in use allow a description of the application persistent data structure. Storage_Schema algorithms are called basic because they do not support external references between containers.");
	cls_Storage_Schema.def(py::init<>());
	cls_Storage_Schema.def("SetVersion", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::SetVersion, "returns version of the schema", py::arg("aVersion"));
	cls_Storage_Schema.def("Version", (TCollection_AsciiString (Storage_Schema::*)() const ) &Storage_Schema::Version, "returns the version of the schema");
	cls_Storage_Schema.def("SetName", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::SetName, "set the schema's name", py::arg("aSchemaName"));
	cls_Storage_Schema.def("Name", (TCollection_AsciiString (Storage_Schema::*)() const ) &Storage_Schema::Name, "returns the schema's name");
	cls_Storage_Schema.def("Write", (void (Storage_Schema::*)(Storage_BaseDriver &, const opencascade::handle<Storage_Data> &) const ) &Storage_Schema::Write, "Writes the data aggregated in aData into the container defined by the driver s. The storage operation is performed according to the data schema with which this algorithm is working. Note: aData may aggregate several root objects to be stored together.", py::arg("s"), py::arg("aData"));
	cls_Storage_Schema.def_static("ICreationDate_", (TCollection_AsciiString (*)()) &Storage_Schema::ICreationDate, "return a current date string");
	cls_Storage_Schema.def_static("CheckTypeMigration_", (Standard_Boolean (*)(const TCollection_AsciiString &, TCollection_AsciiString &)) &Storage_Schema::CheckTypeMigration, "returns True if theType migration is identified the callback support provides a way to read a file with a incomplete schema. ex. : A file contains 3 types a,b and c. The application's schema contains only 2 type a and b. If you try to read the file in the application, you will have an error.To bypass this problem you can give to your application's schema a callback used when the schema dosent know how to handle this type.", py::arg("theTypeName"), py::arg("theNewName"));
	cls_Storage_Schema.def("AddReadUnknownTypeCallBack", (void (Storage_Schema::*)(const TCollection_AsciiString &, const opencascade::handle<Storage_CallBack> &)) &Storage_Schema::AddReadUnknownTypeCallBack, "add two functions to the callback list", py::arg("aTypeName"), py::arg("aCallBack"));
	cls_Storage_Schema.def("RemoveReadUnknownTypeCallBack", (void (Storage_Schema::*)(const TCollection_AsciiString &)) &Storage_Schema::RemoveReadUnknownTypeCallBack, "remove a callback for a type", py::arg("aTypeName"));
	cls_Storage_Schema.def("InstalledCallBackList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_Schema::*)() const ) &Storage_Schema::InstalledCallBackList, "returns a list of type name with installed callback.");
	cls_Storage_Schema.def("ClearCallBackList", (void (Storage_Schema::*)()) &Storage_Schema::ClearCallBackList, "clear all callback from schema instance.");
	cls_Storage_Schema.def("UseDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::UseDefaultCallBack, "install a callback for all unknown type. the objects with unknown types will be skipped. (look SkipObject method in BaseDriver)");
	cls_Storage_Schema.def("DontUseDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::DontUseDefaultCallBack, "tells schema to uninstall the default callback.");
	cls_Storage_Schema.def("IsUsingDefaultCallBack", (Standard_Boolean (Storage_Schema::*)() const ) &Storage_Schema::IsUsingDefaultCallBack, "ask if the schema is using the default callback.");
	cls_Storage_Schema.def("SetDefaultCallBack", (void (Storage_Schema::*)(const opencascade::handle<Storage_CallBack> &)) &Storage_Schema::SetDefaultCallBack, "overload the default function for build.(use to set an error message or skip an object while reading an unknown type).", py::arg("f"));
	cls_Storage_Schema.def("ResetDefaultCallBack", (void (Storage_Schema::*)()) &Storage_Schema::ResetDefaultCallBack, "reset the default function defined by Storage package.");
	cls_Storage_Schema.def("DefaultCallBack", (opencascade::handle<Storage_CallBack> (Storage_Schema::*)() const ) &Storage_Schema::DefaultCallBack, "returns the read function used when the UseDefaultCallBack() is set.");
	cls_Storage_Schema.def("WritePersistentObjectHeader", (void (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &)) &Storage_Schema::WritePersistentObjectHeader, "None", py::arg("sp"), py::arg("s"));
	cls_Storage_Schema.def("WritePersistentReference", (void (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &)) &Storage_Schema::WritePersistentReference, "None", py::arg("sp"), py::arg("s"));
	cls_Storage_Schema.def("AddPersistent", (Standard_Boolean (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &, const Standard_CString) const ) &Storage_Schema::AddPersistent, "None", py::arg("sp"), py::arg("tName"));
	cls_Storage_Schema.def("PersistentToAdd", (Standard_Boolean (Storage_Schema::*)(const opencascade::handle<Standard_Persistent> &) const ) &Storage_Schema::PersistentToAdd, "None", py::arg("sp"));
	cls_Storage_Schema.def_static("get_type_name_", (const char * (*)()) &Storage_Schema::get_type_name, "None");
	cls_Storage_Schema.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Schema::get_type_descriptor, "None");
	cls_Storage_Schema.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Schema::*)() const ) &Storage_Schema::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_Root.hxx
	py::class_<Storage_Root, opencascade::handle<Storage_Root>, Standard_Transient> cls_Storage_Root(mod, "Storage_Root", "A root object extracted from a Storage_Data object. A Storage_Root encapsulates a persistent object which is a root of a Storage_Data object. It contains additional information: the name and the data type of the persistent object. When retrieving a Storage_Data object from a container (for example, a file) you access its roots with the function Roots which returns a sequence of root objects. The provided functions allow you to request information about each root of the sequence. You do not create explicit roots: when inserting data in a Storage_Data object, you just provide the persistent object and optionally its name to the function AddRoot.");
	cls_Storage_Root.def(py::init<>());
	cls_Storage_Root.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &>(), py::arg("theName"), py::arg("theObject"));
	cls_Storage_Root.def(py::init<const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &>(), py::arg("theName"), py::arg("theRef"), py::arg("theType"));
	cls_Storage_Root.def("SetName", (void (Storage_Root::*)(const TCollection_AsciiString &)) &Storage_Root::SetName, "None", py::arg("theName"));
	cls_Storage_Root.def("Name", (TCollection_AsciiString (Storage_Root::*)() const ) &Storage_Root::Name, "Returns the name of this root object. The name may have been given explicitly when the root was inserted into the Storage_Data object. If not, the name is a reference number which was assigned automatically by the driver when writing the set of data into the container. When naming the roots, it is easier to retrieve objects by significant references rather than by references without any semantic values. Warning The returned string will be empty if you call this function before having named this root object, either explicitly, or when writing the set of data into the container.");
	cls_Storage_Root.def("SetObject", (void (Storage_Root::*)(const opencascade::handle<Standard_Persistent> &)) &Storage_Root::SetObject, "None", py::arg("anObject"));
	cls_Storage_Root.def("Object", (opencascade::handle<Standard_Persistent> (Storage_Root::*)() const ) &Storage_Root::Object, "Returns the persistent object encapsulated by this root.");
	cls_Storage_Root.def("Type", (TCollection_AsciiString (Storage_Root::*)() const ) &Storage_Root::Type, "Returns the name of this root type.");
	cls_Storage_Root.def("SetReference", (void (Storage_Root::*)(const Standard_Integer)) &Storage_Root::SetReference, "None", py::arg("aRef"));
	cls_Storage_Root.def("Reference", (Standard_Integer (Storage_Root::*)() const ) &Storage_Root::Reference, "None");
	cls_Storage_Root.def("SetType", (void (Storage_Root::*)(const TCollection_AsciiString &)) &Storage_Root::SetType, "None", py::arg("aType"));
	cls_Storage_Root.def_static("get_type_name_", (const char * (*)()) &Storage_Root::get_type_name, "None");
	cls_Storage_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Root::get_type_descriptor, "None");
	cls_Storage_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Root::*)() const ) &Storage_Root::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_SeqOfRoot.hxx
	bind_NCollection_Sequence<opencascade::handle<Storage_Root> >(mod, "Storage_SeqOfRoot");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_HeaderData.hxx
	py::class_<Storage_HeaderData, opencascade::handle<Storage_HeaderData>, Standard_Transient> cls_Storage_HeaderData(mod, "Storage_HeaderData", "None");
	cls_Storage_HeaderData.def(py::init<>());
	cls_Storage_HeaderData.def("Read", (Standard_Boolean (Storage_HeaderData::*)(Storage_BaseDriver &)) &Storage_HeaderData::Read, "None", py::arg("theDriver"));
	cls_Storage_HeaderData.def("CreationDate", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::CreationDate, "return the creation date");
	cls_Storage_HeaderData.def("StorageVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::StorageVersion, "return the Storage package version");
	cls_Storage_HeaderData.def("SchemaVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::SchemaVersion, "get the version of the schema");
	cls_Storage_HeaderData.def("SchemaName", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::SchemaName, "get the schema's name");
	cls_Storage_HeaderData.def("SetApplicationVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetApplicationVersion, "set the version of the application", py::arg("aVersion"));
	cls_Storage_HeaderData.def("ApplicationVersion", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::ApplicationVersion, "get the version of the application");
	cls_Storage_HeaderData.def("SetApplicationName", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::SetApplicationName, "set the name of the application", py::arg("aName"));
	cls_Storage_HeaderData.def("ApplicationName", (TCollection_ExtendedString (Storage_HeaderData::*)() const ) &Storage_HeaderData::ApplicationName, "get the name of the application");
	cls_Storage_HeaderData.def("SetDataType", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::SetDataType, "set the data type", py::arg("aType"));
	cls_Storage_HeaderData.def("DataType", (TCollection_ExtendedString (Storage_HeaderData::*)() const ) &Storage_HeaderData::DataType, "returns data type");
	cls_Storage_HeaderData.def("AddToUserInfo", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::AddToUserInfo, "add <theUserInfo> to the user informations", py::arg("theUserInfo"));
	cls_Storage_HeaderData.def("UserInfo", (const TColStd_SequenceOfAsciiString & (Storage_HeaderData::*)() const ) &Storage_HeaderData::UserInfo, "return the user informations");
	cls_Storage_HeaderData.def("AddToComments", (void (Storage_HeaderData::*)(const TCollection_ExtendedString &)) &Storage_HeaderData::AddToComments, "add <theUserInfo> to the user informations", py::arg("aComment"));
	cls_Storage_HeaderData.def("Comments", (const TColStd_SequenceOfExtendedString & (Storage_HeaderData::*)() const ) &Storage_HeaderData::Comments, "return the user informations");
	cls_Storage_HeaderData.def("NumberOfObjects", (Standard_Integer (Storage_HeaderData::*)() const ) &Storage_HeaderData::NumberOfObjects, "the the number of persistent objects Return: the number of persistent objects readed");
	cls_Storage_HeaderData.def("ErrorStatus", (Storage_Error (Storage_HeaderData::*)() const ) &Storage_HeaderData::ErrorStatus, "None");
	cls_Storage_HeaderData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_HeaderData::*)() const ) &Storage_HeaderData::ErrorStatusExtension, "None");
	cls_Storage_HeaderData.def("ClearErrorStatus", (void (Storage_HeaderData::*)()) &Storage_HeaderData::ClearErrorStatus, "None");
	cls_Storage_HeaderData.def_static("get_type_name_", (const char * (*)()) &Storage_HeaderData::get_type_name, "None");
	cls_Storage_HeaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HeaderData::get_type_descriptor, "None");
	cls_Storage_HeaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HeaderData::*)() const ) &Storage_HeaderData::DynamicType, "None");
	cls_Storage_HeaderData.def("SetNumberOfObjects", (void (Storage_HeaderData::*)(const Standard_Integer)) &Storage_HeaderData::SetNumberOfObjects, "None", py::arg("anObjectNumber"));
	cls_Storage_HeaderData.def("SetStorageVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetStorageVersion, "None", py::arg("aVersion"));
	cls_Storage_HeaderData.def("SetCreationDate", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetCreationDate, "None", py::arg("aDate"));
	cls_Storage_HeaderData.def("SetSchemaVersion", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetSchemaVersion, "None", py::arg("aVersion"));
	cls_Storage_HeaderData.def("SetSchemaName", (void (Storage_HeaderData::*)(const TCollection_AsciiString &)) &Storage_HeaderData::SetSchemaName, "None", py::arg("aName"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_RootData.hxx
	py::class_<Storage_RootData, opencascade::handle<Storage_RootData>, Standard_Transient> cls_Storage_RootData(mod, "Storage_RootData", "None");
	cls_Storage_RootData.def(py::init<>());
	cls_Storage_RootData.def("Read", (Standard_Boolean (Storage_RootData::*)(Storage_BaseDriver &)) &Storage_RootData::Read, "None", py::arg("theDriver"));
	cls_Storage_RootData.def("NumberOfRoots", (Standard_Integer (Storage_RootData::*)() const ) &Storage_RootData::NumberOfRoots, "returns the number of roots.");
	cls_Storage_RootData.def("AddRoot", (void (Storage_RootData::*)(const opencascade::handle<Storage_Root> &)) &Storage_RootData::AddRoot, "add a root to <me>. If a root with same name is present, it will be replaced by <aRoot>.", py::arg("aRoot"));
	cls_Storage_RootData.def("Roots", (opencascade::handle<Storage_HSeqOfRoot> (Storage_RootData::*)() const ) &Storage_RootData::Roots, "None");
	cls_Storage_RootData.def("Find", (opencascade::handle<Storage_Root> (Storage_RootData::*)(const TCollection_AsciiString &) const ) &Storage_RootData::Find, "find a root with name <aName>.", py::arg("aName"));
	cls_Storage_RootData.def("IsRoot", (Standard_Boolean (Storage_RootData::*)(const TCollection_AsciiString &) const ) &Storage_RootData::IsRoot, "returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
	cls_Storage_RootData.def("RemoveRoot", (void (Storage_RootData::*)(const TCollection_AsciiString &)) &Storage_RootData::RemoveRoot, "remove the root named <aName>.", py::arg("aName"));
	cls_Storage_RootData.def("ErrorStatus", (Storage_Error (Storage_RootData::*)() const ) &Storage_RootData::ErrorStatus, "None");
	cls_Storage_RootData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_RootData::*)() const ) &Storage_RootData::ErrorStatusExtension, "None");
	cls_Storage_RootData.def("ClearErrorStatus", (void (Storage_RootData::*)()) &Storage_RootData::ClearErrorStatus, "None");
	cls_Storage_RootData.def("UpdateRoot", (void (Storage_RootData::*)(const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &)) &Storage_RootData::UpdateRoot, "None", py::arg("aName"), py::arg("aPers"));
	cls_Storage_RootData.def_static("get_type_name_", (const char * (*)()) &Storage_RootData::get_type_name, "None");
	cls_Storage_RootData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_RootData::get_type_descriptor, "None");
	cls_Storage_RootData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_RootData::*)() const ) &Storage_RootData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_TypeData.hxx
	py::class_<Storage_TypeData, opencascade::handle<Storage_TypeData>, Standard_Transient> cls_Storage_TypeData(mod, "Storage_TypeData", "None");
	cls_Storage_TypeData.def(py::init<>());
	cls_Storage_TypeData.def("Read", (Standard_Boolean (Storage_TypeData::*)(Storage_BaseDriver &)) &Storage_TypeData::Read, "None", py::arg("theDriver"));
	cls_Storage_TypeData.def("NumberOfTypes", (Standard_Integer (Storage_TypeData::*)() const ) &Storage_TypeData::NumberOfTypes, "None");
	cls_Storage_TypeData.def("AddType", (void (Storage_TypeData::*)(const TCollection_AsciiString &, const Standard_Integer)) &Storage_TypeData::AddType, "add a type to the list", py::arg("aName"), py::arg("aTypeNum"));
	cls_Storage_TypeData.def("Type", (TCollection_AsciiString (Storage_TypeData::*)(const Standard_Integer) const ) &Storage_TypeData::Type, "returns the name of the type with number <aTypeNum>", py::arg("aTypeNum"));
	cls_Storage_TypeData.def("Type", (Standard_Integer (Storage_TypeData::*)(const TCollection_AsciiString &) const ) &Storage_TypeData::Type, "returns the name of the type with number <aTypeNum>", py::arg("aTypeName"));
	cls_Storage_TypeData.def("IsType", (Standard_Boolean (Storage_TypeData::*)(const TCollection_AsciiString &) const ) &Storage_TypeData::IsType, "None", py::arg("aName"));
	cls_Storage_TypeData.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_TypeData::*)() const ) &Storage_TypeData::Types, "None");
	cls_Storage_TypeData.def("ErrorStatus", (Storage_Error (Storage_TypeData::*)() const ) &Storage_TypeData::ErrorStatus, "None");
	cls_Storage_TypeData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_TypeData::*)() const ) &Storage_TypeData::ErrorStatusExtension, "None");
	cls_Storage_TypeData.def("ClearErrorStatus", (void (Storage_TypeData::*)()) &Storage_TypeData::ClearErrorStatus, "None");
	cls_Storage_TypeData.def("Clear", (void (Storage_TypeData::*)()) &Storage_TypeData::Clear, "None");
	cls_Storage_TypeData.def_static("get_type_name_", (const char * (*)()) &Storage_TypeData::get_type_name, "None");
	cls_Storage_TypeData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_TypeData::get_type_descriptor, "None");
	cls_Storage_TypeData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_TypeData::*)() const ) &Storage_TypeData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_InternalData.hxx
	py::class_<Storage_InternalData, opencascade::handle<Storage_InternalData>, Standard_Transient> cls_Storage_InternalData(mod, "Storage_InternalData", "None");
	cls_Storage_InternalData.def(py::init<>());
	cls_Storage_InternalData.def("ReadArray", (opencascade::handle<Storage_HPArray> (Storage_InternalData::*)()) &Storage_InternalData::ReadArray, "None");
	cls_Storage_InternalData.def("Clear", (void (Storage_InternalData::*)()) &Storage_InternalData::Clear, "None");
	cls_Storage_InternalData.def_static("get_type_name_", (const char * (*)()) &Storage_InternalData::get_type_name, "None");
	cls_Storage_InternalData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_InternalData::get_type_descriptor, "None");
	cls_Storage_InternalData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_InternalData::*)() const ) &Storage_InternalData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_Data.hxx
	py::class_<Storage_Data, opencascade::handle<Storage_Data>, Standard_Transient> cls_Storage_Data(mod, "Storage_Data", "A picture memorizing the data stored in a container (for example, in a file). A Storage_Data object represents either: - persistent data to be written into a container, or - persistent data which are read from a container. A Storage_Data object is used in both the storage and retrieval operations: - Storage mechanism: create an empty Storage_Data object, then add successively persistent objects (roots) to be stored using the function AddRoot. When the set of data is complete, write it to a container using the function Write in your Storage_Schema storage/retrieval algorithm. - Retrieval mechanism: a Storage_Data object is returned by the Read function from your Storage_Schema storage/retrieval algorithm. Use the functions NumberOfRoots and Roots to find the roots which were stored in the read container. The roots of a Storage_Data object may share references on objects. The shared internal references of a Storage_Data object are maintained by the storage/retrieval mechanism. Note: References shared by objects which are contained in two distinct Storage_Data objects are not maintained by the storage/retrieval mechanism: external references are not supported by Storage_Schema algorithm");
	cls_Storage_Data.def(py::init<>());
	cls_Storage_Data.def("ErrorStatus", (Storage_Error (Storage_Data::*)() const ) &Storage_Data::ErrorStatus, "Returns Storage_VSOk if - the last storage operation performed with the function Read, or - the last retrieval operation performed with the function Write by a Storage_Schema algorithm, on this set of data was successful. If the storage or retrieval operation was not performed, the returned error status indicates the reason why the operation failed. The algorithm stops its analysis at the first detected error");
	cls_Storage_Data.def("ClearErrorStatus", (void (Storage_Data::*)()) &Storage_Data::ClearErrorStatus, "Clears the error status positioned either by: - the last storage operation performed with the Read function, or - the last retrieval operation performed with the Write function by a Storage_Schema algorithm, on this set of data. This error status may be read by the function ErrorStatus.");
	cls_Storage_Data.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::ErrorStatusExtension, "None");
	cls_Storage_Data.def("CreationDate", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::CreationDate, "return the creation date");
	cls_Storage_Data.def("StorageVersion", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::StorageVersion, "return the Storage package version");
	cls_Storage_Data.def("SchemaVersion", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::SchemaVersion, "get the version of the schema");
	cls_Storage_Data.def("SchemaName", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::SchemaName, "get the schema's name");
	cls_Storage_Data.def("SetApplicationVersion", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::SetApplicationVersion, "set the version of the application", py::arg("aVersion"));
	cls_Storage_Data.def("ApplicationVersion", (TCollection_AsciiString (Storage_Data::*)() const ) &Storage_Data::ApplicationVersion, "get the version of the application");
	cls_Storage_Data.def("SetApplicationName", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::SetApplicationName, "set the name of the application", py::arg("aName"));
	cls_Storage_Data.def("ApplicationName", (TCollection_ExtendedString (Storage_Data::*)() const ) &Storage_Data::ApplicationName, "get the name of the application");
	cls_Storage_Data.def("SetDataType", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::SetDataType, "set the data type", py::arg("aType"));
	cls_Storage_Data.def("DataType", (TCollection_ExtendedString (Storage_Data::*)() const ) &Storage_Data::DataType, "returns data type");
	cls_Storage_Data.def("AddToUserInfo", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::AddToUserInfo, "add <theUserInfo> to the user informations", py::arg("anInfo"));
	cls_Storage_Data.def("UserInfo", (const TColStd_SequenceOfAsciiString & (Storage_Data::*)() const ) &Storage_Data::UserInfo, "return the user informations");
	cls_Storage_Data.def("AddToComments", (void (Storage_Data::*)(const TCollection_ExtendedString &)) &Storage_Data::AddToComments, "add <theUserInfo> to the user informations", py::arg("aComment"));
	cls_Storage_Data.def("Comments", (const TColStd_SequenceOfExtendedString & (Storage_Data::*)() const ) &Storage_Data::Comments, "return the user informations");
	cls_Storage_Data.def("NumberOfObjects", (Standard_Integer (Storage_Data::*)() const ) &Storage_Data::NumberOfObjects, "the the number of persistent objects Return: the number of persistent objects readed");
	cls_Storage_Data.def("NumberOfRoots", (Standard_Integer (Storage_Data::*)() const ) &Storage_Data::NumberOfRoots, "Returns the number of root objects in this set of data. - When preparing a storage operation, the result is the number of roots inserted into this set of data with the function AddRoot. - When retrieving an object, the result is the number of roots stored in the read container. Use the Roots function to get these roots in a sequence.");
	cls_Storage_Data.def("AddRoot", (void (Storage_Data::*)(const opencascade::handle<Standard_Persistent> &) const ) &Storage_Data::AddRoot, "add a persistent root to write. the name of the root is a driver reference number.", py::arg("anObject"));
	cls_Storage_Data.def("AddRoot", (void (Storage_Data::*)(const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &) const ) &Storage_Data::AddRoot, "Adds the root anObject to this set of data. The name of the root is aName if given; if not, it will be a reference number assigned by the driver when writing the set of data into the container. When naming the roots, it is easier to retrieve objects by significant references rather than by references without any semantic values.", py::arg("aName"), py::arg("anObject"));
	cls_Storage_Data.def("RemoveRoot", (void (Storage_Data::*)(const TCollection_AsciiString &)) &Storage_Data::RemoveRoot, "Removes from this set of data the root object named aName. Warning Nothing is done if there is no root object whose name is aName in this set of data.", py::arg("aName"));
	cls_Storage_Data.def("Roots", (opencascade::handle<Storage_HSeqOfRoot> (Storage_Data::*)() const ) &Storage_Data::Roots, "Returns the roots of this set of data in a sequence. - When preparing a storage operation, the sequence contains the roots inserted into this set of data with the function AddRoot. - When retrieving an object, the sequence contains the roots stored in the container read. - An empty sequence is returned if there is no root in this set of data.");
	cls_Storage_Data.def("Find", (opencascade::handle<Storage_Root> (Storage_Data::*)(const TCollection_AsciiString &) const ) &Storage_Data::Find, "Gives the root object whose name is aName in this set of data. The returned object is a Storage_Root object, from which the object it encapsulates may be extracted. Warning A null handle is returned if there is no root object whose name is aName in this set of data.", py::arg("aName"));
	cls_Storage_Data.def("IsRoot", (Standard_Boolean (Storage_Data::*)(const TCollection_AsciiString &) const ) &Storage_Data::IsRoot, "returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
	cls_Storage_Data.def("NumberOfTypes", (Standard_Integer (Storage_Data::*)() const ) &Storage_Data::NumberOfTypes, "Returns the number of types of objects used in this set of data.");
	cls_Storage_Data.def("IsType", (Standard_Boolean (Storage_Data::*)(const TCollection_AsciiString &) const ) &Storage_Data::IsType, "Returns true if this set of data contains an object of type aName. Persistent objects from this set of data must have types which are recognized by the Storage_Schema algorithm used to store or retrieve them.", py::arg("aName"));
	cls_Storage_Data.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_Data::*)() const ) &Storage_Data::Types, "Gives the list of types of objects used in this set of data in a sequence.");
	cls_Storage_Data.def_static("get_type_name_", (const char * (*)()) &Storage_Data::get_type_name, "None");
	cls_Storage_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_Data::get_type_descriptor, "None");
	cls_Storage_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_Data::*)() const ) &Storage_Data::DynamicType, "None");
	cls_Storage_Data.def("HeaderData", (opencascade::handle<Storage_HeaderData> (Storage_Data::*)() const ) &Storage_Data::HeaderData, "None");
	cls_Storage_Data.def("RootData", (opencascade::handle<Storage_RootData> (Storage_Data::*)() const ) &Storage_Data::RootData, "None");
	cls_Storage_Data.def("TypeData", (opencascade::handle<Storage_TypeData> (Storage_Data::*)() const ) &Storage_Data::TypeData, "None");
	cls_Storage_Data.def("InternalData", (opencascade::handle<Storage_InternalData> (Storage_Data::*)() const ) &Storage_Data::InternalData, "None");
	cls_Storage_Data.def("Clear", (void (Storage_Data::*)() const ) &Storage_Data::Clear, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamReadError.hxx
	py::class_<Storage_StreamReadError, opencascade::handle<Storage_StreamReadError>, Standard_Failure> cls_Storage_StreamReadError(mod, "Storage_StreamReadError", "None");
	cls_Storage_StreamReadError.def(py::init<>());
	cls_Storage_StreamReadError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamReadError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamReadError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamReadError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamReadError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamReadError.def_static("NewInstance_", (opencascade::handle<Storage_StreamReadError> (*)(const Standard_CString)) &Storage_StreamReadError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamReadError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamReadError::get_type_name, "None");
	cls_Storage_StreamReadError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamReadError::get_type_descriptor, "None");
	cls_Storage_StreamReadError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamReadError::*)() const ) &Storage_StreamReadError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamFormatError.hxx
	py::class_<Storage_StreamFormatError, opencascade::handle<Storage_StreamFormatError>, Standard_Failure> cls_Storage_StreamFormatError(mod, "Storage_StreamFormatError", "None");
	cls_Storage_StreamFormatError.def(py::init<>());
	cls_Storage_StreamFormatError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamFormatError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamFormatError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamFormatError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamFormatError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamFormatError.def_static("NewInstance_", (opencascade::handle<Storage_StreamFormatError> (*)(const Standard_CString)) &Storage_StreamFormatError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamFormatError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamFormatError::get_type_name, "None");
	cls_Storage_StreamFormatError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamFormatError::get_type_descriptor, "None");
	cls_Storage_StreamFormatError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamFormatError::*)() const ) &Storage_StreamFormatError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamWriteError.hxx
	py::class_<Storage_StreamWriteError, opencascade::handle<Storage_StreamWriteError>, Standard_Failure> cls_Storage_StreamWriteError(mod, "Storage_StreamWriteError", "None");
	cls_Storage_StreamWriteError.def(py::init<>());
	cls_Storage_StreamWriteError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamWriteError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamWriteError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamWriteError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamWriteError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamWriteError.def_static("NewInstance_", (opencascade::handle<Storage_StreamWriteError> (*)(const Standard_CString)) &Storage_StreamWriteError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamWriteError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamWriteError::get_type_name, "None");
	cls_Storage_StreamWriteError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamWriteError::get_type_descriptor, "None");
	cls_Storage_StreamWriteError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamWriteError::*)() const ) &Storage_StreamWriteError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamExtCharParityError.hxx
	py::class_<Storage_StreamExtCharParityError, opencascade::handle<Storage_StreamExtCharParityError>, Storage_StreamReadError> cls_Storage_StreamExtCharParityError(mod, "Storage_StreamExtCharParityError", "None");
	cls_Storage_StreamExtCharParityError.def(py::init<>());
	cls_Storage_StreamExtCharParityError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamExtCharParityError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamExtCharParityError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamExtCharParityError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamExtCharParityError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamExtCharParityError.def_static("NewInstance_", (opencascade::handle<Storage_StreamExtCharParityError> (*)(const Standard_CString)) &Storage_StreamExtCharParityError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamExtCharParityError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamExtCharParityError::get_type_name, "None");
	cls_Storage_StreamExtCharParityError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamExtCharParityError::get_type_descriptor, "None");
	cls_Storage_StreamExtCharParityError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamExtCharParityError::*)() const ) &Storage_StreamExtCharParityError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_BaseDriver.hxx
	py::class_<Storage_BaseDriver, std::unique_ptr<Storage_BaseDriver, Deleter<Storage_BaseDriver>>> cls_Storage_BaseDriver(mod, "Storage_BaseDriver", "Root class for drivers. A driver assigns a physical container to data to be stored or retrieved, for instance a file. The FSD package provides two derived concrete classes : - FSD_File is a general driver which defines a file as the container of data.");
	cls_Storage_BaseDriver.def("Open", (Storage_Error (Storage_BaseDriver::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &Storage_BaseDriver::Open, "None", py::arg("aName"), py::arg("aMode"));
	cls_Storage_BaseDriver.def("Name", (TCollection_AsciiString (Storage_BaseDriver::*)() const ) &Storage_BaseDriver::Name, "None");
	cls_Storage_BaseDriver.def("OpenMode", (Storage_OpenMode (Storage_BaseDriver::*)() const ) &Storage_BaseDriver::OpenMode, "None");
	cls_Storage_BaseDriver.def_static("ReadMagicNumber_", (TCollection_AsciiString (*)(Standard_IStream &)) &Storage_BaseDriver::ReadMagicNumber, "None", py::arg("theIStream"));
	cls_Storage_BaseDriver.def("IsEnd", (Standard_Boolean (Storage_BaseDriver::*)()) &Storage_BaseDriver::IsEnd, "returns True if we are at end of the stream");
	cls_Storage_BaseDriver.def("Tell", (Storage_Position (Storage_BaseDriver::*)()) &Storage_BaseDriver::Tell, "return position in the file. Return -1 upon error.");
	cls_Storage_BaseDriver.def("BeginWriteInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteInfoSection, "None");
	cls_Storage_BaseDriver.def("WriteInfo", (void (Storage_BaseDriver::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &Storage_BaseDriver::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_Storage_BaseDriver.def("EndWriteInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteInfoSection, "None");
	cls_Storage_BaseDriver.def("BeginReadInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadInfoSection, "None");
	cls_Storage_BaseDriver.def("ReadInfo", [](Storage_BaseDriver &self, Standard_Integer & nbObj, TCollection_AsciiString & dbVersion, TCollection_AsciiString & date, TCollection_AsciiString & schemaName, TCollection_AsciiString & schemaVersion, TCollection_ExtendedString & appName, TCollection_AsciiString & appVersion, TCollection_ExtendedString & objectType, TColStd_SequenceOfAsciiString & userInfo){ self.ReadInfo(nbObj, dbVersion, date, schemaName, schemaVersion, appName, appVersion, objectType, userInfo); return nbObj; }, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_Storage_BaseDriver.def("ReadCompleteInfo", (void (Storage_BaseDriver::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &Storage_BaseDriver::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
	cls_Storage_BaseDriver.def("EndReadInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadInfoSection, "None");
	cls_Storage_BaseDriver.def("BeginWriteCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteCommentSection, "None");
	cls_Storage_BaseDriver.def("WriteComment", (void (Storage_BaseDriver::*)(const TColStd_SequenceOfExtendedString &)) &Storage_BaseDriver::WriteComment, "None", py::arg("userComments"));
	cls_Storage_BaseDriver.def("EndWriteCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteCommentSection, "None");
	cls_Storage_BaseDriver.def("BeginReadCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadCommentSection, "None");
	cls_Storage_BaseDriver.def("ReadComment", (void (Storage_BaseDriver::*)(TColStd_SequenceOfExtendedString &)) &Storage_BaseDriver::ReadComment, "None", py::arg("userComments"));
	cls_Storage_BaseDriver.def("EndReadCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadCommentSection, "None");
	cls_Storage_BaseDriver.def("BeginWriteTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteTypeSection, "None");
	cls_Storage_BaseDriver.def("SetTypeSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetTypeSectionSize, "None", py::arg("aSize"));
	cls_Storage_BaseDriver.def("WriteTypeInformations", (void (Storage_BaseDriver::*)(const Standard_Integer, const TCollection_AsciiString &)) &Storage_BaseDriver::WriteTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_Storage_BaseDriver.def("EndWriteTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteTypeSection, "None");
	cls_Storage_BaseDriver.def("BeginReadTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadTypeSection, "None");
	cls_Storage_BaseDriver.def("TypeSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::TypeSectionSize, "None");
	cls_Storage_BaseDriver.def("ReadTypeInformations", [](Storage_BaseDriver &self, Standard_Integer & typeNum, TCollection_AsciiString & typeName){ self.ReadTypeInformations(typeNum, typeName); return typeNum; }, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_Storage_BaseDriver.def("EndReadTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadTypeSection, "None");
	cls_Storage_BaseDriver.def("BeginWriteRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteRootSection, "None");
	cls_Storage_BaseDriver.def("SetRootSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetRootSectionSize, "None", py::arg("aSize"));
	cls_Storage_BaseDriver.def("WriteRoot", (void (Storage_BaseDriver::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &Storage_BaseDriver::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_Storage_BaseDriver.def("EndWriteRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteRootSection, "None");
	cls_Storage_BaseDriver.def("BeginReadRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadRootSection, "None");
	cls_Storage_BaseDriver.def("RootSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::RootSectionSize, "None");
	cls_Storage_BaseDriver.def("ReadRoot", [](Storage_BaseDriver &self, TCollection_AsciiString & rootName, Standard_Integer & aRef, TCollection_AsciiString & aType){ self.ReadRoot(rootName, aRef, aType); return aRef; }, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_Storage_BaseDriver.def("EndReadRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadRootSection, "None");
	cls_Storage_BaseDriver.def("BeginWriteRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteRefSection, "None");
	cls_Storage_BaseDriver.def("SetRefSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetRefSectionSize, "None", py::arg("aSize"));
	cls_Storage_BaseDriver.def("WriteReferenceType", (void (Storage_BaseDriver::*)(const Standard_Integer, const Standard_Integer)) &Storage_BaseDriver::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_Storage_BaseDriver.def("EndWriteRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteRefSection, "None");
	cls_Storage_BaseDriver.def("BeginReadRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadRefSection, "None");
	cls_Storage_BaseDriver.def("RefSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::RefSectionSize, "None");
	cls_Storage_BaseDriver.def("ReadReferenceType", [](Storage_BaseDriver &self, Standard_Integer & reference, Standard_Integer & typeNum){ self.ReadReferenceType(reference, typeNum); return std::tuple<Standard_Integer &, Standard_Integer &>(reference, typeNum); }, "None", py::arg("reference"), py::arg("typeNum"));
	cls_Storage_BaseDriver.def("EndReadRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadRefSection, "None");
	cls_Storage_BaseDriver.def("BeginWriteDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteDataSection, "None");
	cls_Storage_BaseDriver.def("WritePersistentObjectHeader", (void (Storage_BaseDriver::*)(const Standard_Integer, const Standard_Integer)) &Storage_BaseDriver::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_Storage_BaseDriver.def("BeginWritePersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWritePersistentObjectData, "None");
	cls_Storage_BaseDriver.def("BeginWriteObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteObjectData, "None");
	cls_Storage_BaseDriver.def("EndWriteObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteObjectData, "None");
	cls_Storage_BaseDriver.def("EndWritePersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWritePersistentObjectData, "None");
	cls_Storage_BaseDriver.def("EndWriteDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteDataSection, "None");
	cls_Storage_BaseDriver.def("BeginReadDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadDataSection, "None");
	cls_Storage_BaseDriver.def("ReadPersistentObjectHeader", [](Storage_BaseDriver &self, Standard_Integer & aRef, Standard_Integer & aType){ self.ReadPersistentObjectHeader(aRef, aType); return std::tuple<Standard_Integer &, Standard_Integer &>(aRef, aType); }, "None", py::arg("aRef"), py::arg("aType"));
	cls_Storage_BaseDriver.def("BeginReadPersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadPersistentObjectData, "None");
	cls_Storage_BaseDriver.def("BeginReadObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadObjectData, "None");
	cls_Storage_BaseDriver.def("EndReadObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadObjectData, "None");
	cls_Storage_BaseDriver.def("EndReadPersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadPersistentObjectData, "None");
	cls_Storage_BaseDriver.def("EndReadDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadDataSection, "None");
	cls_Storage_BaseDriver.def("SkipObject", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::SkipObject, "None");
	cls_Storage_BaseDriver.def("PutReference", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::PutReference, "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Character)) &Storage_BaseDriver::PutCharacter, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Character)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutExtCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ExtCharacter)) &Storage_BaseDriver::PutExtCharacter, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ExtCharacter)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutInteger", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::PutInteger, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutBoolean", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Boolean)) &Storage_BaseDriver::PutBoolean, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Boolean)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Real)) &Storage_BaseDriver::PutReal, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Real)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("PutShortReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ShortReal)) &Storage_BaseDriver::PutShortReal, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ShortReal)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("GetReference", [](Storage_BaseDriver &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetReference(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("GetCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Character &)) &Storage_BaseDriver::GetCharacter, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Character &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("GetExtCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ExtCharacter &)) &Storage_BaseDriver::GetExtCharacter, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ExtCharacter &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("GetInteger", [](Storage_BaseDriver &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetInteger(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Integer &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("GetBoolean", [](Storage_BaseDriver &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.GetBoolean(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Boolean &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("GetReal", [](Storage_BaseDriver &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.GetReal(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Real &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("GetShortReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ShortReal &)) &Storage_BaseDriver::GetShortReal, "None", py::arg("aValue"));
	// FIXME cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ShortReal &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
	cls_Storage_BaseDriver.def("Close", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::Close, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_CallBack.hxx
	py::class_<Storage_CallBack, opencascade::handle<Storage_CallBack>, Standard_Transient> cls_Storage_CallBack(mod, "Storage_CallBack", "None");
	cls_Storage_CallBack.def("New", (opencascade::handle<Standard_Persistent> (Storage_CallBack::*)() const ) &Storage_CallBack::New, "None");
	cls_Storage_CallBack.def("Add", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, const opencascade::handle<Storage_Schema> &) const ) &Storage_CallBack::Add, "None", py::arg("aPers"), py::arg("aSchema"));
	cls_Storage_CallBack.def("Write", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const ) &Storage_CallBack::Write, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
	cls_Storage_CallBack.def("Read", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const ) &Storage_CallBack::Read, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
	cls_Storage_CallBack.def_static("get_type_name_", (const char * (*)()) &Storage_CallBack::get_type_name, "None");
	cls_Storage_CallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_CallBack::get_type_descriptor, "None");
	cls_Storage_CallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_CallBack::*)() const ) &Storage_CallBack::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_DefaultCallBack.hxx
	py::class_<Storage_DefaultCallBack, opencascade::handle<Storage_DefaultCallBack>, Storage_CallBack> cls_Storage_DefaultCallBack(mod, "Storage_DefaultCallBack", "None");
	cls_Storage_DefaultCallBack.def(py::init<>());
	cls_Storage_DefaultCallBack.def("New", (opencascade::handle<Standard_Persistent> (Storage_DefaultCallBack::*)() const ) &Storage_DefaultCallBack::New, "None");
	cls_Storage_DefaultCallBack.def("Add", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, const opencascade::handle<Storage_Schema> &) const ) &Storage_DefaultCallBack::Add, "None", py::arg("aPers"), py::arg("aSchema"));
	cls_Storage_DefaultCallBack.def("Write", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const ) &Storage_DefaultCallBack::Write, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
	cls_Storage_DefaultCallBack.def("Read", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const ) &Storage_DefaultCallBack::Read, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
	cls_Storage_DefaultCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_DefaultCallBack::get_type_name, "None");
	cls_Storage_DefaultCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_DefaultCallBack::get_type_descriptor, "None");
	cls_Storage_DefaultCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_DefaultCallBack::*)() const ) &Storage_DefaultCallBack::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_stCONSTclCOM.hxx
	py::class_<Storage_stCONSTclCOM, std::unique_ptr<Storage_stCONSTclCOM, Deleter<Storage_stCONSTclCOM>>> cls_Storage_stCONSTclCOM(mod, "Storage_stCONSTclCOM", "None");
	cls_Storage_stCONSTclCOM.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_TypedCallBack.hxx
	py::class_<Storage_TypedCallBack, opencascade::handle<Storage_TypedCallBack>, Standard_Transient> cls_Storage_TypedCallBack(mod, "Storage_TypedCallBack", "None");
	cls_Storage_TypedCallBack.def(py::init<>());
	cls_Storage_TypedCallBack.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Storage_CallBack> &>(), py::arg("aTypeName"), py::arg("aCallBack"));
	cls_Storage_TypedCallBack.def("SetType", (void (Storage_TypedCallBack::*)(const TCollection_AsciiString &)) &Storage_TypedCallBack::SetType, "None", py::arg("aType"));
	cls_Storage_TypedCallBack.def("Type", (TCollection_AsciiString (Storage_TypedCallBack::*)() const ) &Storage_TypedCallBack::Type, "None");
	cls_Storage_TypedCallBack.def("SetCallBack", (void (Storage_TypedCallBack::*)(const opencascade::handle<Storage_CallBack> &)) &Storage_TypedCallBack::SetCallBack, "None", py::arg("aCallBack"));
	cls_Storage_TypedCallBack.def("CallBack", (opencascade::handle<Storage_CallBack> (Storage_TypedCallBack::*)() const ) &Storage_TypedCallBack::CallBack, "None");
	cls_Storage_TypedCallBack.def("SetIndex", (void (Storage_TypedCallBack::*)(const Standard_Integer)) &Storage_TypedCallBack::SetIndex, "None", py::arg("anIndex"));
	cls_Storage_TypedCallBack.def("Index", (Standard_Integer (Storage_TypedCallBack::*)() const ) &Storage_TypedCallBack::Index, "None");
	cls_Storage_TypedCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_TypedCallBack::get_type_name, "None");
	cls_Storage_TypedCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_TypedCallBack::get_type_descriptor, "None");
	cls_Storage_TypedCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_TypedCallBack::*)() const ) &Storage_TypedCallBack::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage.hxx
	py::class_<Storage, std::unique_ptr<Storage, Deleter<Storage>>> cls_Storage(mod, "Storage", "Storage package is used to write and read persistent objects. These objects are read and written by a retrieval or storage algorithm (Storage_Schema object) in a container (disk, memory, network ...). Drivers (FSD_File objects) assign a physical container for data to be stored or retrieved. The standard procedure for an application in reading a container is the following: - open the driver in reading mode, - call the Read function from the schema, setting the driver as a parameter. This function returns an instance of the Storage_Data class which contains the data being read, - close the driver. The standard procedure for an application in writing a container is the following: - open the driver in writing mode, - create an instance of the Storage_Data class, then add the persistent data to write with the function AddRoot, - call the function Write from the schema, setting the driver and the Storage_Data instance as parameters, - close the driver.");
	cls_Storage.def(py::init<>());
	cls_Storage.def_static("Version_", (TCollection_AsciiString (*)()) &Storage::Version, "returns the version of Storage's read/write routines");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_BucketOfPersistent.hxx
	/* FIXME
	py::class_<Storage_BucketOfPersistent, std::unique_ptr<Storage_BucketOfPersistent, Deleter<Storage_BucketOfPersistent>>> cls_Storage_BucketOfPersistent(mod, "Storage_BucketOfPersistent", "None");
	cls_Storage_BucketOfPersistent.def(py::init<>());
	cls_Storage_BucketOfPersistent.def(py::init<const Standard_Integer>(), py::arg("theBucketSize"));
	cls_Storage_BucketOfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theBucketSize"), py::arg("theBucketNumber"));
	cls_Storage_BucketOfPersistent.def("Length", (Standard_Integer (Storage_BucketOfPersistent::*)() const ) &Storage_BucketOfPersistent::Length, "None");
	cls_Storage_BucketOfPersistent.def("Append", (void (Storage_BucketOfPersistent::*)(const opencascade::handle<Standard_Persistent> &)) &Storage_BucketOfPersistent::Append, "None", py::arg("sp"));
	cls_Storage_BucketOfPersistent.def("Value", (Standard_Persistent * (Storage_BucketOfPersistent::*)(const Standard_Integer)) &Storage_BucketOfPersistent::Value, "None", py::arg("theIndex"));
	cls_Storage_BucketOfPersistent.def("Clear", (void (Storage_BucketOfPersistent::*)()) &Storage_BucketOfPersistent::Clear, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_BucketOfPersistent.hxx
	py::class_<Storage_BucketIterator, std::unique_ptr<Storage_BucketIterator, Deleter<Storage_BucketIterator>>> cls_Storage_BucketIterator(mod, "Storage_BucketIterator", "None");
	// cls_Storage_BucketIterator.def(py::init<Storage_BucketOfPersistent *>(), py::arg(""));
	// cls_Storage_BucketIterator.def("Init", (void (Storage_BucketIterator::*)(Storage_BucketOfPersistent *)) &Storage_BucketIterator::Init, "None", py::arg(""));
	// cls_Storage_BucketIterator.def("Reset", (void (Storage_BucketIterator::*)()) &Storage_BucketIterator::Reset, "None");
	cls_Storage_BucketIterator.def("Value", (Standard_Persistent * (Storage_BucketIterator::*)() const ) &Storage_BucketIterator::Value, "None");
	cls_Storage_BucketIterator.def("More", (Standard_Boolean (Storage_BucketIterator::*)() const ) &Storage_BucketIterator::More, "None");
	// cls_Storage_BucketIterator.def("Next", (void (Storage_BucketIterator::*)()) &Storage_BucketIterator::Next, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_BucketOfPersistent.hxx
	/* FIXME
	py::class_<Storage_Bucket, std::unique_ptr<Storage_Bucket, Deleter<Storage_Bucket>>> cls_Storage_Bucket(mod, "Storage_Bucket", "None");
	cls_Storage_Bucket.def(py::init<>());
	cls_Storage_Bucket.def(py::init<const Standard_Integer>(), py::arg("theSpaceSize"));
	cls_Storage_Bucket.def("Clear", (void (Storage_Bucket::*)()) &Storage_Bucket::Clear, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_ArrayOfCallBack.hxx
	bind_NCollection_Array1<opencascade::handle<Storage_CallBack> >(mod, "Storage_ArrayOfCallBack");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_PArray.hxx
	bind_NCollection_Array1<opencascade::handle<Standard_Persistent> >(mod, "Storage_PArray");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_ArrayOfSchema.hxx
	bind_NCollection_Array1<opencascade::handle<Storage_Schema> >(mod, "Storage_ArrayOfSchema");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamTypeMismatchError.hxx
	py::class_<Storage_StreamTypeMismatchError, opencascade::handle<Storage_StreamTypeMismatchError>, Storage_StreamReadError> cls_Storage_StreamTypeMismatchError(mod, "Storage_StreamTypeMismatchError", "None");
	cls_Storage_StreamTypeMismatchError.def(py::init<>());
	cls_Storage_StreamTypeMismatchError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamTypeMismatchError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamTypeMismatchError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamTypeMismatchError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamTypeMismatchError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamTypeMismatchError.def_static("NewInstance_", (opencascade::handle<Storage_StreamTypeMismatchError> (*)(const Standard_CString)) &Storage_StreamTypeMismatchError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamTypeMismatchError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamTypeMismatchError::get_type_name, "None");
	cls_Storage_StreamTypeMismatchError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamTypeMismatchError::get_type_descriptor, "None");
	cls_Storage_StreamTypeMismatchError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamTypeMismatchError::*)() const ) &Storage_StreamTypeMismatchError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamModeError.hxx
	py::class_<Storage_StreamModeError, opencascade::handle<Storage_StreamModeError>, Standard_Failure> cls_Storage_StreamModeError(mod, "Storage_StreamModeError", "None");
	cls_Storage_StreamModeError.def(py::init<>());
	cls_Storage_StreamModeError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamModeError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamModeError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamModeError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamModeError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamModeError.def_static("NewInstance_", (opencascade::handle<Storage_StreamModeError> (*)(const Standard_CString)) &Storage_StreamModeError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamModeError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamModeError::get_type_name, "None");
	cls_Storage_StreamModeError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamModeError::get_type_descriptor, "None");
	cls_Storage_StreamModeError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamModeError::*)() const ) &Storage_StreamModeError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_StreamUnknownTypeError.hxx
	py::class_<Storage_StreamUnknownTypeError, opencascade::handle<Storage_StreamUnknownTypeError>, Storage_StreamReadError> cls_Storage_StreamUnknownTypeError(mod, "Storage_StreamUnknownTypeError", "None");
	cls_Storage_StreamUnknownTypeError.def(py::init<>());
	cls_Storage_StreamUnknownTypeError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Storage_StreamUnknownTypeError.def_static("Raise_", (void (*)(const Standard_CString)) &Storage_StreamUnknownTypeError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamUnknownTypeError.def_static("Raise_", (void (*)(Standard_SStream &)) &Storage_StreamUnknownTypeError::Raise, "None", py::arg("theMessage"));
	cls_Storage_StreamUnknownTypeError.def_static("NewInstance_", (opencascade::handle<Storage_StreamUnknownTypeError> (*)(const Standard_CString)) &Storage_StreamUnknownTypeError::NewInstance, "None", py::arg("theMessage"));
	cls_Storage_StreamUnknownTypeError.def_static("get_type_name_", (const char * (*)()) &Storage_StreamUnknownTypeError::get_type_name, "None");
	cls_Storage_StreamUnknownTypeError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_StreamUnknownTypeError::get_type_descriptor, "None");
	cls_Storage_StreamUnknownTypeError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_StreamUnknownTypeError::*)() const ) &Storage_StreamUnknownTypeError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_HSeqOfRoot.hxx
	py::class_<Storage_HSeqOfRoot, opencascade::handle<Storage_HSeqOfRoot>, Storage_SeqOfRoot, Standard_Transient> cls_Storage_HSeqOfRoot(mod, "Storage_HSeqOfRoot", "None");
	cls_Storage_HSeqOfRoot.def(py::init<>());
	cls_Storage_HSeqOfRoot.def(py::init<const Storage_SeqOfRoot &>(), py::arg("theOther"));
	cls_Storage_HSeqOfRoot.def("Sequence", (const Storage_SeqOfRoot & (Storage_HSeqOfRoot::*)() const ) &Storage_HSeqOfRoot::Sequence, "None");
	cls_Storage_HSeqOfRoot.def("Append", (void (Storage_HSeqOfRoot::*)(const Storage_SeqOfRoot::value_type &)) &Storage_HSeqOfRoot::Append, "None", py::arg("theItem"));
	cls_Storage_HSeqOfRoot.def("Append", (void (Storage_HSeqOfRoot::*)(Storage_SeqOfRoot &)) &Storage_HSeqOfRoot::Append, "None", py::arg("theSequence"));
	cls_Storage_HSeqOfRoot.def("ChangeSequence", (Storage_SeqOfRoot & (Storage_HSeqOfRoot::*)()) &Storage_HSeqOfRoot::ChangeSequence, "None");
	cls_Storage_HSeqOfRoot.def_static("get_type_name_", (const char * (*)()) &Storage_HSeqOfRoot::get_type_name, "None");
	cls_Storage_HSeqOfRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HSeqOfRoot::get_type_descriptor, "None");
	cls_Storage_HSeqOfRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HSeqOfRoot::*)() const ) &Storage_HSeqOfRoot::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_Position.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "logical")) {
		mod.attr("Storage_Position") = other_mod.attr("logical");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_HArrayOfCallBack.hxx
	py::class_<Storage_HArrayOfCallBack, opencascade::handle<Storage_HArrayOfCallBack>, Storage_ArrayOfCallBack, Standard_Transient> cls_Storage_HArrayOfCallBack(mod, "Storage_HArrayOfCallBack", "None");
	cls_Storage_HArrayOfCallBack.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Storage_HArrayOfCallBack.def(py::init<const Standard_Integer, const Standard_Integer, const Storage_ArrayOfCallBack::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Storage_HArrayOfCallBack.def(py::init<const Storage_ArrayOfCallBack &>(), py::arg("theOther"));
	cls_Storage_HArrayOfCallBack.def("Array1", (const Storage_ArrayOfCallBack & (Storage_HArrayOfCallBack::*)() const ) &Storage_HArrayOfCallBack::Array1, "None");
	cls_Storage_HArrayOfCallBack.def("ChangeArray1", (Storage_ArrayOfCallBack & (Storage_HArrayOfCallBack::*)()) &Storage_HArrayOfCallBack::ChangeArray1, "None");
	cls_Storage_HArrayOfCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_HArrayOfCallBack::get_type_name, "None");
	cls_Storage_HArrayOfCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HArrayOfCallBack::get_type_descriptor, "None");
	cls_Storage_HArrayOfCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HArrayOfCallBack::*)() const ) &Storage_HArrayOfCallBack::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_HArrayOfSchema.hxx
	py::class_<Storage_HArrayOfSchema, opencascade::handle<Storage_HArrayOfSchema>, Storage_ArrayOfSchema, Standard_Transient> cls_Storage_HArrayOfSchema(mod, "Storage_HArrayOfSchema", "None");
	cls_Storage_HArrayOfSchema.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Storage_HArrayOfSchema.def(py::init<const Standard_Integer, const Standard_Integer, const Storage_ArrayOfSchema::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Storage_HArrayOfSchema.def(py::init<const Storage_ArrayOfSchema &>(), py::arg("theOther"));
	cls_Storage_HArrayOfSchema.def("Array1", (const Storage_ArrayOfSchema & (Storage_HArrayOfSchema::*)() const ) &Storage_HArrayOfSchema::Array1, "None");
	cls_Storage_HArrayOfSchema.def("ChangeArray1", (Storage_ArrayOfSchema & (Storage_HArrayOfSchema::*)()) &Storage_HArrayOfSchema::ChangeArray1, "None");
	cls_Storage_HArrayOfSchema.def_static("get_type_name_", (const char * (*)()) &Storage_HArrayOfSchema::get_type_name, "None");
	cls_Storage_HArrayOfSchema.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HArrayOfSchema::get_type_descriptor, "None");
	cls_Storage_HArrayOfSchema.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HArrayOfSchema::*)() const ) &Storage_HArrayOfSchema::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_MapOfCallBack.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Storage_TypedCallBack>, TCollection_AsciiString>(mod, "Storage_MapOfCallBack");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_MapOfPers.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Storage_Root>, TCollection_AsciiString>(mod, "Storage_MapOfPers");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Storage_HPArray.hxx
	py::class_<Storage_HPArray, opencascade::handle<Storage_HPArray>, Storage_PArray, Standard_Transient> cls_Storage_HPArray(mod, "Storage_HPArray", "None");
	cls_Storage_HPArray.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Storage_HPArray.def(py::init<const Standard_Integer, const Standard_Integer, const Storage_PArray::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Storage_HPArray.def(py::init<const Storage_PArray &>(), py::arg("theOther"));
	cls_Storage_HPArray.def("Array1", (const Storage_PArray & (Storage_HPArray::*)() const ) &Storage_HPArray::Array1, "None");
	cls_Storage_HPArray.def("ChangeArray1", (Storage_PArray & (Storage_HPArray::*)()) &Storage_HPArray::ChangeArray1, "None");
	cls_Storage_HPArray.def_static("get_type_name_", (const char * (*)()) &Storage_HPArray::get_type_name, "None");
	cls_Storage_HPArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HPArray::get_type_descriptor, "None");
	cls_Storage_HPArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HPArray::*)() const ) &Storage_HPArray::DynamicType, "None");


}
