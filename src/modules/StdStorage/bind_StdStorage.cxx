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
#include <TCollection_AsciiString.hxx>
#include <Storage_Error.hxx>
#include <Standard_Handle.hxx>
#include <StdStorage_Data.hxx>
#include <Storage_BaseDriver.hxx>
#include <StdStorage.hxx>

void bind_StdStorage(py::module &mod){

py::class_<StdStorage, std::unique_ptr<StdStorage>> cls_StdStorage(mod, "StdStorage", "StdStorage package is used to write and read persistent objects. These objects are read and written by a retrieval or storage algorithm (compatible with legacy Storage_Schema) in a container (disk, memory, network ...). Drivers (FSD_File objects) assign a physical container for data to be stored or retrieved. The standard procedure for an application in reading a container is to call one of the Read functions providing either a file path or a driver opened for reading. Thes function update the instance of the StdStorage_Data class which contains the data being read. The standard procedure for an application in writing a container is the following: - open the driver in writing mode, - create an instance of the StdStorage_Data class, then add the persistent data to write with the function AddRoot, - call the function Write from the storage, setting the driver and the Storage_Data instance as parameters, - close the driver.");

// Constructors

// Fields

// Methods
cls_StdStorage.def_static("Version_", (TCollection_AsciiString (*)()) &StdStorage::Version, "Returns the version of Storage's read/write routines");
cls_StdStorage.def_static("Read_", (Storage_Error (*)(const TCollection_AsciiString &, opencascade::handle<StdStorage_Data> &)) &StdStorage::Read, "Returns the data read from a file located at theFileName. The storage format is compartible with legacy persistent one. These data are aggregated in a StdStorage_Data object which may be browsed in order to extract the root objects from the container. Note: - theData object will be created if it is null or cleared otherwise.", py::arg("theFileName"), py::arg("theData"));
cls_StdStorage.def_static("Read_", (Storage_Error (*)(Storage_BaseDriver &, opencascade::handle<StdStorage_Data> &)) &StdStorage::Read, "Returns the data read from the container defined by theDriver. The storage format is compartible with legacy persistent one. These data are aggregated in a StdStorage_Data object which may be browsed in order to extract the root objects from the container. Note: - theData object will be created if it is null or cleared otherwise.", py::arg("theDriver"), py::arg("theData"));
cls_StdStorage.def_static("Write_", (Storage_Error (*)(Storage_BaseDriver &, const opencascade::handle<StdStorage_Data> &)) &StdStorage::Write, "Writes the data aggregated in theData object into the container defined by theDriver. The storage format is compartible with legacy persistent one. Note: - theData may aggregate several root objects to be stored together. - createion date specified in the srorage header will be overwritten.", py::arg("theDriver"), py::arg("theData"));

// Enums

}