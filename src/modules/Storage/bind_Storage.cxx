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
#include <Standard.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_CallBack.hxx>
#include <Storage_DefaultCallBack.hxx>
#include <Storage_HeaderData.hxx>
#include <Storage_Data.hxx>
#include <Storage_TypeData.hxx>
#include <Storage_RootData.hxx>
#include <Storage_Root.hxx>
#include <Storage_Schema.hxx>
#include <Storage_InternalData.hxx>
#include <Storage_TypedCallBack.hxx>
#include <Storage.hxx>

void bind_Storage(py::module &mod){

py::class_<Storage, std::unique_ptr<Storage, Deleter<Storage>>> cls_Storage(mod, "Storage", "Storage package is used to write and read persistent objects. These objects are read and written by a retrieval or storage algorithm (Storage_Schema object) in a container (disk, memory, network ...). Drivers (FSD_File objects) assign a physical container for data to be stored or retrieved. The standard procedure for an application in reading a container is the following: - open the driver in reading mode, - call the Read function from the schema, setting the driver as a parameter. This function returns an instance of the Storage_Data class which contains the data being read, - close the driver. The standard procedure for an application in writing a container is the following: - open the driver in writing mode, - create an instance of the Storage_Data class, then add the persistent data to write with the function AddRoot, - call the function Write from the schema, setting the driver and the Storage_Data instance as parameters, - close the driver.");

// Constructors

// Fields

// Methods
// cls_Storage.def_static("operator new_", (void * (*)(size_t)) &Storage::operator new, "None", py::arg("theSize"));
// cls_Storage.def_static("operator delete_", (void (*)(void *)) &Storage::operator delete, "None", py::arg("theAddress"));
// cls_Storage.def_static("operator new[]_", (void * (*)(size_t)) &Storage::operator new[], "None", py::arg("theSize"));
// cls_Storage.def_static("operator delete[]_", (void (*)(void *)) &Storage::operator delete[], "None", py::arg("theAddress"));
// cls_Storage.def_static("operator new_", (void * (*)(size_t, void *)) &Storage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Storage.def_static("operator delete_", (void (*)(void *, void *)) &Storage::operator delete, "None", py::arg(""), py::arg(""));
cls_Storage.def_static("Version_", (TCollection_AsciiString (*)()) &Storage::Version, "returns the version of Storage's read/write routines");

// Enums

}