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
#include <Standard_Handle.hxx>
#include <StdStorage_HeaderData.hxx>
#include <StdStorage_TypeData.hxx>
#include <StdStorage_RootData.hxx>
#include <StdStorage_Data.hxx>

void bind_StdStorage_Data(py::module &mod){

py::class_<StdStorage_Data, opencascade::handle<StdStorage_Data>, Standard_Transient> cls_StdStorage_Data(mod, "StdStorage_Data", "A picture memorizing the stored in a container (for example, in a file). A StdStorage_Data object represents either: - persistent data to be written into a container, or - persistent data which are read from a container. A StdStorage_Data object is used in both the storage and retrieval operations: - Storage mechanism: create an empty StdStorage_Data object, then add successively persistent objects (roots) to be stored using the StdStorage_RootData's function AddRoot. When the set of data is complete, write it to a container using the function Write in your StdStorage algorithm. - Retrieval mechanism: a StdStorage_Data object is returned by the Read function from your StdStorage algorithm. Use the StdStorage_RootData's functions NumberOfRoots and Roots to find the roots which were stored in the read container. The roots of a StdStorage_Data object may share references on objects. The shared internal references of a StdStorage_Data object are maintained by the storage/retrieval mechanism. Note: References shared by objects which are contained in two distinct StdStorage_Data objects are not maintained by the storage/retrieval mechanism: external references are not supported by Storage_Schema algorithm");

// Constructors
cls_StdStorage_Data.def(py::init<>());

// Fields

// Methods
cls_StdStorage_Data.def("Clear", (void (StdStorage_Data::*)()) &StdStorage_Data::Clear, "Makes the container empty");
cls_StdStorage_Data.def("HeaderData", (opencascade::handle<StdStorage_HeaderData> (StdStorage_Data::*)()) &StdStorage_Data::HeaderData, "Returns the header data section");
cls_StdStorage_Data.def("TypeData", (opencascade::handle<StdStorage_TypeData> (StdStorage_Data::*)()) &StdStorage_Data::TypeData, "Returns the type data section");
cls_StdStorage_Data.def("RootData", (opencascade::handle<StdStorage_RootData> (StdStorage_Data::*)()) &StdStorage_Data::RootData, "Returns the root data section");

// Enums

}