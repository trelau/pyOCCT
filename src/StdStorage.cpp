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

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StdStorage_HeaderData.hxx>
#include <StdStorage_TypeData.hxx>
#include <StdStorage_RootData.hxx>
#include <StdStorage_Data.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_Error.hxx>
#include <Storage_BaseDriver.hxx>
#include <StdStorage.hxx>
#include <Standard_TypeDef.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdStorage_BacketOfPersistent.hxx>
#include <Standard_Type.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <StdStorage_Root.hxx>
#include <StdStorage_HSequenceOfRoots.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StdStorage_SequenceOfRoots.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <StdStorage_MapOfRoots.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <StdStorage_MapOfTypes.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(StdStorage, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.StdObjMgt");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_Data.hxx
	py::class_<StdStorage_Data, opencascade::handle<StdStorage_Data>, Standard_Transient> cls_StdStorage_Data(mod, "StdStorage_Data", "A picture memorizing the stored in a container (for example, in a file). A StdStorage_Data object represents either: - persistent data to be written into a container, or - persistent data which are read from a container. A StdStorage_Data object is used in both the storage and retrieval operations: - Storage mechanism: create an empty StdStorage_Data object, then add successively persistent objects (roots) to be stored using the StdStorage_RootData's function AddRoot. When the set of data is complete, write it to a container using the function Write in your StdStorage algorithm. - Retrieval mechanism: a StdStorage_Data object is returned by the Read function from your StdStorage algorithm. Use the StdStorage_RootData's functions NumberOfRoots and Roots to find the roots which were stored in the read container. The roots of a StdStorage_Data object may share references on objects. The shared internal references of a StdStorage_Data object are maintained by the storage/retrieval mechanism. Note: References shared by objects which are contained in two distinct StdStorage_Data objects are not maintained by the storage/retrieval mechanism: external references are not supported by Storage_Schema algorithm");
	cls_StdStorage_Data.def(py::init<>());
	cls_StdStorage_Data.def("Clear", (void (StdStorage_Data::*)()) &StdStorage_Data::Clear, "Makes the container empty");
	cls_StdStorage_Data.def("HeaderData", (opencascade::handle<StdStorage_HeaderData> (StdStorage_Data::*)()) &StdStorage_Data::HeaderData, "Returns the header data section");
	cls_StdStorage_Data.def("TypeData", (opencascade::handle<StdStorage_TypeData> (StdStorage_Data::*)()) &StdStorage_Data::TypeData, "Returns the type data section");
	cls_StdStorage_Data.def("RootData", (opencascade::handle<StdStorage_RootData> (StdStorage_Data::*)()) &StdStorage_Data::RootData, "Returns the root data section");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage.hxx
	py::class_<StdStorage, std::unique_ptr<StdStorage, Deleter<StdStorage>>> cls_StdStorage(mod, "StdStorage", "StdStorage package is used to write and read persistent objects. These objects are read and written by a retrieval or storage algorithm (compatible with legacy Storage_Schema) in a container (disk, memory, network ...). Drivers (FSD_File objects) assign a physical container for data to be stored or retrieved. The standard procedure for an application in reading a container is to call one of the Read functions providing either a file path or a driver opened for reading. Thes function update the instance of the StdStorage_Data class which contains the data being read. The standard procedure for an application in writing a container is the following: - open the driver in writing mode, - create an instance of the StdStorage_Data class, then add the persistent data to write with the function AddRoot, - call the function Write from the storage, setting the driver and the Storage_Data instance as parameters, - close the driver.");
	cls_StdStorage.def(py::init<>());
	cls_StdStorage.def_static("Version_", (TCollection_AsciiString (*)()) &StdStorage::Version, "Returns the version of Storage's read/write routines");
	cls_StdStorage.def_static("Read_", (Storage_Error (*)(const TCollection_AsciiString &, opencascade::handle<StdStorage_Data> &)) &StdStorage::Read, "Returns the data read from a file located at theFileName. The storage format is compartible with legacy persistent one. These data are aggregated in a StdStorage_Data object which may be browsed in order to extract the root objects from the container. Note: - theData object will be created if it is null or cleared otherwise.", py::arg("theFileName"), py::arg("theData"));
	cls_StdStorage.def_static("Read_", (Storage_Error (*)(Storage_BaseDriver &, opencascade::handle<StdStorage_Data> &)) &StdStorage::Read, "Returns the data read from the container defined by theDriver. The storage format is compartible with legacy persistent one. These data are aggregated in a StdStorage_Data object which may be browsed in order to extract the root objects from the container. Note: - theData object will be created if it is null or cleared otherwise.", py::arg("theDriver"), py::arg("theData"));
	cls_StdStorage.def_static("Write_", (Storage_Error (*)(Storage_BaseDriver &, const opencascade::handle<StdStorage_Data> &)) &StdStorage::Write, "Writes the data aggregated in theData object into the container defined by theDriver. The storage format is compartible with legacy persistent one. Note: - theData may aggregate several root objects to be stored together. - createion date specified in the srorage header will be overwritten.", py::arg("theDriver"), py::arg("theData"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_BacketOfPersistent.hxx
	/* FIXME
	py::class_<StdStorage_BucketOfPersistent, std::unique_ptr<StdStorage_BucketOfPersistent, Deleter<StdStorage_BucketOfPersistent>>> cls_StdStorage_BucketOfPersistent(mod, "StdStorage_BucketOfPersistent", "None");
	cls_StdStorage_BucketOfPersistent.def(py::init<>());
	cls_StdStorage_BucketOfPersistent.def(py::init<const Standard_Integer>(), py::arg("theBucketSize"));
	cls_StdStorage_BucketOfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theBucketSize"), py::arg("theBucketNumber"));
	cls_StdStorage_BucketOfPersistent.def("Length", (Standard_Integer (StdStorage_BucketOfPersistent::*)() const ) &StdStorage_BucketOfPersistent::Length, "None");
	cls_StdStorage_BucketOfPersistent.def("Append", (void (StdStorage_BucketOfPersistent::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdStorage_BucketOfPersistent::Append, "None", py::arg("sp"));
	cls_StdStorage_BucketOfPersistent.def("Value", (StdObjMgt_Persistent * (StdStorage_BucketOfPersistent::*)(const Standard_Integer)) &StdStorage_BucketOfPersistent::Value, "None", py::arg("theIndex"));
	cls_StdStorage_BucketOfPersistent.def("Clear", (void (StdStorage_BucketOfPersistent::*)()) &StdStorage_BucketOfPersistent::Clear, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_BacketOfPersistent.hxx
	py::class_<StdStorage_BucketIterator, std::unique_ptr<StdStorage_BucketIterator, Deleter<StdStorage_BucketIterator>>> cls_StdStorage_BucketIterator(mod, "StdStorage_BucketIterator", "None");
	// cls_StdStorage_BucketIterator.def(py::init<StdStorage_BucketOfPersistent *>(), py::arg(""));
	// cls_StdStorage_BucketIterator.def("Init", (void (StdStorage_BucketIterator::*)(StdStorage_BucketOfPersistent *)) &StdStorage_BucketIterator::Init, "None", py::arg(""));
	// cls_StdStorage_BucketIterator.def("Reset", (void (StdStorage_BucketIterator::*)()) &StdStorage_BucketIterator::Reset, "None");
	cls_StdStorage_BucketIterator.def("Value", (StdObjMgt_Persistent * (StdStorage_BucketIterator::*)() const ) &StdStorage_BucketIterator::Value, "None");
	cls_StdStorage_BucketIterator.def("More", (Standard_Boolean (StdStorage_BucketIterator::*)() const ) &StdStorage_BucketIterator::More, "None");
	// cls_StdStorage_BucketIterator.def("Next", (void (StdStorage_BucketIterator::*)()) &StdStorage_BucketIterator::Next, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_BacketOfPersistent.hxx
	/* FIXME
	py::class_<StdStorage_Bucket, std::unique_ptr<StdStorage_Bucket, Deleter<StdStorage_Bucket>>> cls_StdStorage_Bucket(mod, "StdStorage_Bucket", "None");
	cls_StdStorage_Bucket.def(py::init<>());
	cls_StdStorage_Bucket.def(py::init<const Standard_Integer>(), py::arg("theSpaceSize"));
	cls_StdStorage_Bucket.def("Clear", (void (StdStorage_Bucket::*)()) &StdStorage_Bucket::Clear, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_HeaderData.hxx
	py::class_<StdStorage_HeaderData, opencascade::handle<StdStorage_HeaderData>, Standard_Transient> cls_StdStorage_HeaderData(mod, "StdStorage_HeaderData", "Storage header data section that contains some auxiliary information (application name, schema version, creation date, comments and so on...)");
	cls_StdStorage_HeaderData.def_static("get_type_name_", (const char * (*)()) &StdStorage_HeaderData::get_type_name, "None");
	cls_StdStorage_HeaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_HeaderData::get_type_descriptor, "None");
	cls_StdStorage_HeaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::DynamicType, "None");
	cls_StdStorage_HeaderData.def("Read", (Standard_Boolean (StdStorage_HeaderData::*)(Storage_BaseDriver &)) &StdStorage_HeaderData::Read, "Reads the header data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_HeaderData.def("Write", (Standard_Boolean (StdStorage_HeaderData::*)(Storage_BaseDriver &)) &StdStorage_HeaderData::Write, "Writes the header data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_HeaderData.def("CreationDate", (TCollection_AsciiString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::CreationDate, "Return the creation date");
	cls_StdStorage_HeaderData.def("StorageVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::StorageVersion, "Return the Storage package version");
	cls_StdStorage_HeaderData.def("SchemaVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::SchemaVersion, "Get the version of the schema");
	cls_StdStorage_HeaderData.def("SetApplicationVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetApplicationVersion, "Set the version of the application", py::arg("aVersion"));
	cls_StdStorage_HeaderData.def("ApplicationVersion", (TCollection_AsciiString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::ApplicationVersion, "Get the version of the application");
	cls_StdStorage_HeaderData.def("SetApplicationName", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::SetApplicationName, "Set the name of the application", py::arg("aName"));
	cls_StdStorage_HeaderData.def("ApplicationName", (TCollection_ExtendedString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::ApplicationName, "Get the name of the application");
	cls_StdStorage_HeaderData.def("SetDataType", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::SetDataType, "Set the data type", py::arg("aType"));
	cls_StdStorage_HeaderData.def("DataType", (TCollection_ExtendedString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::DataType, "Returns data type");
	cls_StdStorage_HeaderData.def("AddToUserInfo", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::AddToUserInfo, "Add <theUserInfo> to the user informations", py::arg("theUserInfo"));
	cls_StdStorage_HeaderData.def("UserInfo", (const TColStd_SequenceOfAsciiString & (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::UserInfo, "Return the user informations");
	cls_StdStorage_HeaderData.def("AddToComments", (void (StdStorage_HeaderData::*)(const TCollection_ExtendedString &)) &StdStorage_HeaderData::AddToComments, "Add <theUserInfo> to the user informations", py::arg("aComment"));
	cls_StdStorage_HeaderData.def("Comments", (const TColStd_SequenceOfExtendedString & (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::Comments, "Return the user informations");
	cls_StdStorage_HeaderData.def("NumberOfObjects", (Standard_Integer (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::NumberOfObjects, "Returns the number of persistent objects");
	cls_StdStorage_HeaderData.def("ErrorStatus", (Storage_Error (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
	cls_StdStorage_HeaderData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_HeaderData::*)() const ) &StdStorage_HeaderData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
	cls_StdStorage_HeaderData.def("ClearErrorStatus", (void (StdStorage_HeaderData::*)()) &StdStorage_HeaderData::ClearErrorStatus, "Clears error status");
	cls_StdStorage_HeaderData.def("SetNumberOfObjects", (void (StdStorage_HeaderData::*)(const Standard_Integer)) &StdStorage_HeaderData::SetNumberOfObjects, "None", py::arg("anObjectNumber"));
	cls_StdStorage_HeaderData.def("SetStorageVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetStorageVersion, "None", py::arg("aVersion"));
	cls_StdStorage_HeaderData.def("SetCreationDate", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetCreationDate, "None", py::arg("aDate"));
	cls_StdStorage_HeaderData.def("SetSchemaVersion", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetSchemaVersion, "None", py::arg("aVersion"));
	cls_StdStorage_HeaderData.def("SetSchemaName", (void (StdStorage_HeaderData::*)(const TCollection_AsciiString &)) &StdStorage_HeaderData::SetSchemaName, "None", py::arg("aName"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_TypeData.hxx
	py::class_<StdStorage_TypeData, opencascade::handle<StdStorage_TypeData>, Standard_Transient> cls_StdStorage_TypeData(mod, "StdStorage_TypeData", "Storage type data section keeps association between persistent textual types and their numbers");
	cls_StdStorage_TypeData.def_static("get_type_name_", (const char * (*)()) &StdStorage_TypeData::get_type_name, "None");
	cls_StdStorage_TypeData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_TypeData::get_type_descriptor, "None");
	cls_StdStorage_TypeData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_TypeData::*)() const ) &StdStorage_TypeData::DynamicType, "None");
	cls_StdStorage_TypeData.def("Read", (Standard_Boolean (StdStorage_TypeData::*)(Storage_BaseDriver &)) &StdStorage_TypeData::Read, "Reads the type data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_TypeData.def("Write", (Standard_Boolean (StdStorage_TypeData::*)(Storage_BaseDriver &)) &StdStorage_TypeData::Write, "Writes the type data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_TypeData.def("NumberOfTypes", (Standard_Integer (StdStorage_TypeData::*)() const ) &StdStorage_TypeData::NumberOfTypes, "Returns the number of registered types");
	cls_StdStorage_TypeData.def("AddType", (void (StdStorage_TypeData::*)(const TCollection_AsciiString &, const Standard_Integer)) &StdStorage_TypeData::AddType, "Add a type to the list in case of reading data", py::arg("aTypeName"), py::arg("aTypeNum"));
	cls_StdStorage_TypeData.def("AddType", (Standard_Integer (StdStorage_TypeData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdStorage_TypeData::AddType, "Add a type of the persistent object in case of writing data", py::arg("aPObj"));
	cls_StdStorage_TypeData.def("Type", (TCollection_AsciiString (StdStorage_TypeData::*)(const Standard_Integer) const ) &StdStorage_TypeData::Type, "Returns the name of the type with number <aTypeNum>", py::arg("aTypeNum"));
	cls_StdStorage_TypeData.def("Type", (Standard_Integer (StdStorage_TypeData::*)(const TCollection_AsciiString &) const ) &StdStorage_TypeData::Type, "Returns the name of the type with number <aTypeNum>", py::arg("aTypeName"));
	// FIXME cls_StdStorage_TypeData.def("Instantiator", (StdObjMgt_Persistent::Instantiator (StdStorage_TypeData::*)(const Standard_Integer) const ) &StdStorage_TypeData::Instantiator, "Returns a persistent object instantiator of <aTypeName>", py::arg("aTypeNum"));
	cls_StdStorage_TypeData.def("IsType", (Standard_Boolean (StdStorage_TypeData::*)(const TCollection_AsciiString &) const ) &StdStorage_TypeData::IsType, "Checks if <aName> is a registered type", py::arg("aName"));
	cls_StdStorage_TypeData.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (StdStorage_TypeData::*)() const ) &StdStorage_TypeData::Types, "Returns a sequence of all registered types");
	cls_StdStorage_TypeData.def("ErrorStatus", (Storage_Error (StdStorage_TypeData::*)() const ) &StdStorage_TypeData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
	cls_StdStorage_TypeData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_TypeData::*)() const ) &StdStorage_TypeData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
	cls_StdStorage_TypeData.def("ClearErrorStatus", (void (StdStorage_TypeData::*)()) &StdStorage_TypeData::ClearErrorStatus, "Clears error status");
	cls_StdStorage_TypeData.def("Clear", (void (StdStorage_TypeData::*)()) &StdStorage_TypeData::Clear, "Unregisters all types");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_RootData.hxx
	py::class_<StdStorage_RootData, opencascade::handle<StdStorage_RootData>, Standard_Transient> cls_StdStorage_RootData(mod, "StdStorage_RootData", "Storage root data section contains root persistent objects");
	cls_StdStorage_RootData.def_static("get_type_name_", (const char * (*)()) &StdStorage_RootData::get_type_name, "None");
	cls_StdStorage_RootData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_RootData::get_type_descriptor, "None");
	cls_StdStorage_RootData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_RootData::*)() const ) &StdStorage_RootData::DynamicType, "None");
	cls_StdStorage_RootData.def("Read", (Standard_Boolean (StdStorage_RootData::*)(Storage_BaseDriver &)) &StdStorage_RootData::Read, "Reads the root data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_RootData.def("Write", (Standard_Boolean (StdStorage_RootData::*)(Storage_BaseDriver &)) &StdStorage_RootData::Write, "Writes the root data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
	cls_StdStorage_RootData.def("NumberOfRoots", (Standard_Integer (StdStorage_RootData::*)() const ) &StdStorage_RootData::NumberOfRoots, "Returns the number of roots.");
	cls_StdStorage_RootData.def("AddRoot", (void (StdStorage_RootData::*)(const opencascade::handle<StdStorage_Root> &)) &StdStorage_RootData::AddRoot, "Add a root to <me>. If a root with same name is present, it will be replaced by <aRoot>.", py::arg("aRoot"));
	cls_StdStorage_RootData.def("Roots", (opencascade::handle<StdStorage_HSequenceOfRoots> (StdStorage_RootData::*)() const ) &StdStorage_RootData::Roots, "Returns a sequence of all roots");
	cls_StdStorage_RootData.def("Find", (opencascade::handle<StdStorage_Root> (StdStorage_RootData::*)(const TCollection_AsciiString &) const ) &StdStorage_RootData::Find, "Finds a root with name <aName>.", py::arg("aName"));
	cls_StdStorage_RootData.def("IsRoot", (Standard_Boolean (StdStorage_RootData::*)(const TCollection_AsciiString &) const ) &StdStorage_RootData::IsRoot, "Returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
	cls_StdStorage_RootData.def("RemoveRoot", (void (StdStorage_RootData::*)(const TCollection_AsciiString &)) &StdStorage_RootData::RemoveRoot, "Removes the root named <aName>.", py::arg("aName"));
	cls_StdStorage_RootData.def("ErrorStatus", (Storage_Error (StdStorage_RootData::*)() const ) &StdStorage_RootData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
	cls_StdStorage_RootData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_RootData::*)() const ) &StdStorage_RootData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
	cls_StdStorage_RootData.def("ClearErrorStatus", (void (StdStorage_RootData::*)()) &StdStorage_RootData::ClearErrorStatus, "Clears error status");
	cls_StdStorage_RootData.def("Clear", (void (StdStorage_RootData::*)()) &StdStorage_RootData::Clear, "Removes all persistent root objects");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_Root.hxx
	py::class_<StdStorage_Root, opencascade::handle<StdStorage_Root>, Standard_Transient> cls_StdStorage_Root(mod, "StdStorage_Root", "Describes a named persistent root");
	cls_StdStorage_Root.def(py::init<>());
	cls_StdStorage_Root.def(py::init<const TCollection_AsciiString &, const opencascade::handle<StdObjMgt_Persistent> &>(), py::arg("theName"), py::arg("theObject"));
	cls_StdStorage_Root.def_static("get_type_name_", (const char * (*)()) &StdStorage_Root::get_type_name, "None");
	cls_StdStorage_Root.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_Root::get_type_descriptor, "None");
	cls_StdStorage_Root.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_Root::*)() const ) &StdStorage_Root::DynamicType, "None");
	cls_StdStorage_Root.def("Name", (TCollection_AsciiString (StdStorage_Root::*)() const ) &StdStorage_Root::Name, "Returns a name of the root");
	cls_StdStorage_Root.def("SetName", (void (StdStorage_Root::*)(const TCollection_AsciiString &)) &StdStorage_Root::SetName, "Sets a name to the root object", py::arg("theName"));
	cls_StdStorage_Root.def("Object", (opencascade::handle<StdObjMgt_Persistent> (StdStorage_Root::*)() const ) &StdStorage_Root::Object, "Returns a root's persistent object");
	cls_StdStorage_Root.def("SetObject", (void (StdStorage_Root::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdStorage_Root::SetObject, "Sets a root's persistent object", py::arg("anObject"));
	cls_StdStorage_Root.def("Type", (TCollection_AsciiString (StdStorage_Root::*)() const ) &StdStorage_Root::Type, "Returns a root's persistent type");
	cls_StdStorage_Root.def("SetType", (void (StdStorage_Root::*)(const TCollection_AsciiString &)) &StdStorage_Root::SetType, "Sets a root's persistent type", py::arg("aType"));
	cls_StdStorage_Root.def("Reference", (Standard_Integer (StdStorage_Root::*)() const ) &StdStorage_Root::Reference, "Returns root's position in the root data section");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_SequenceOfRoots.hxx
	bind_NCollection_Sequence<opencascade::handle<StdStorage_Root> >(mod, "StdStorage_SequenceOfRoots");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_HSequenceOfRoots.hxx
	py::class_<StdStorage_HSequenceOfRoots, opencascade::handle<StdStorage_HSequenceOfRoots>, StdStorage_SequenceOfRoots, Standard_Transient> cls_StdStorage_HSequenceOfRoots(mod, "StdStorage_HSequenceOfRoots", "None");
	cls_StdStorage_HSequenceOfRoots.def(py::init<>());
	cls_StdStorage_HSequenceOfRoots.def(py::init<const StdStorage_SequenceOfRoots &>(), py::arg("theOther"));
	cls_StdStorage_HSequenceOfRoots.def("Sequence", (const StdStorage_SequenceOfRoots & (StdStorage_HSequenceOfRoots::*)() const ) &StdStorage_HSequenceOfRoots::Sequence, "None");
	cls_StdStorage_HSequenceOfRoots.def("Append", (void (StdStorage_HSequenceOfRoots::*)(const StdStorage_SequenceOfRoots::value_type &)) &StdStorage_HSequenceOfRoots::Append, "None", py::arg("theItem"));
	cls_StdStorage_HSequenceOfRoots.def("Append", (void (StdStorage_HSequenceOfRoots::*)(StdStorage_SequenceOfRoots &)) &StdStorage_HSequenceOfRoots::Append, "None", py::arg("theSequence"));
	cls_StdStorage_HSequenceOfRoots.def("ChangeSequence", (StdStorage_SequenceOfRoots & (StdStorage_HSequenceOfRoots::*)()) &StdStorage_HSequenceOfRoots::ChangeSequence, "None");
	cls_StdStorage_HSequenceOfRoots.def_static("get_type_name_", (const char * (*)()) &StdStorage_HSequenceOfRoots::get_type_name, "None");
	cls_StdStorage_HSequenceOfRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_HSequenceOfRoots::get_type_descriptor, "None");
	cls_StdStorage_HSequenceOfRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_HSequenceOfRoots::*)() const ) &StdStorage_HSequenceOfRoots::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_MapOfRoots.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<StdStorage_Root>, TCollection_AsciiString>(mod, "StdStorage_MapOfRoots");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdStorage_MapOfTypes.hxx
	bind_NCollection_IndexedDataMap<TCollection_AsciiString, int, TCollection_AsciiString>(mod, "StdStorage_MapOfTypes");


}
