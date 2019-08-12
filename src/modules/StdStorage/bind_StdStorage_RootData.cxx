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
#include <StdStorage_RootData.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_BaseDriver.hxx>
#include <StdStorage_Root.hxx>
#include <StdStorage_HSequenceOfRoots.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_Error.hxx>
#include <StdStorage_MapOfRoots.hxx>

void bind_StdStorage_RootData(py::module &mod){

py::class_<StdStorage_RootData, opencascade::handle<StdStorage_RootData>, Standard_Transient> cls_StdStorage_RootData(mod, "StdStorage_RootData", "Storage root data section contains root persistent objects");

// Constructors

// Fields

// Methods
cls_StdStorage_RootData.def_static("get_type_name_", (const char * (*)()) &StdStorage_RootData::get_type_name, "None");
cls_StdStorage_RootData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_RootData::get_type_descriptor, "None");
cls_StdStorage_RootData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_RootData::*)() const) &StdStorage_RootData::DynamicType, "None");
cls_StdStorage_RootData.def("Read", (Standard_Boolean (StdStorage_RootData::*)(Storage_BaseDriver &)) &StdStorage_RootData::Read, "Reads the root data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_RootData.def("Write", (Standard_Boolean (StdStorage_RootData::*)(Storage_BaseDriver &)) &StdStorage_RootData::Write, "Writes the root data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_RootData.def("NumberOfRoots", (Standard_Integer (StdStorage_RootData::*)() const) &StdStorage_RootData::NumberOfRoots, "Returns the number of roots.");
cls_StdStorage_RootData.def("AddRoot", (void (StdStorage_RootData::*)(const opencascade::handle<StdStorage_Root> &)) &StdStorage_RootData::AddRoot, "Add a root to <me>. If a root with same name is present, it will be replaced by <aRoot>.", py::arg("aRoot"));
cls_StdStorage_RootData.def("Roots", (opencascade::handle<StdStorage_HSequenceOfRoots> (StdStorage_RootData::*)() const) &StdStorage_RootData::Roots, "Returns a sequence of all roots");
cls_StdStorage_RootData.def("Find", (opencascade::handle<StdStorage_Root> (StdStorage_RootData::*)(const TCollection_AsciiString &) const) &StdStorage_RootData::Find, "Finds a root with name <aName>.", py::arg("aName"));
cls_StdStorage_RootData.def("IsRoot", (Standard_Boolean (StdStorage_RootData::*)(const TCollection_AsciiString &) const) &StdStorage_RootData::IsRoot, "Returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
cls_StdStorage_RootData.def("RemoveRoot", (void (StdStorage_RootData::*)(const TCollection_AsciiString &)) &StdStorage_RootData::RemoveRoot, "Removes the root named <aName>.", py::arg("aName"));
cls_StdStorage_RootData.def("ErrorStatus", (Storage_Error (StdStorage_RootData::*)() const) &StdStorage_RootData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
cls_StdStorage_RootData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_RootData::*)() const) &StdStorage_RootData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
cls_StdStorage_RootData.def("ClearErrorStatus", (void (StdStorage_RootData::*)()) &StdStorage_RootData::ClearErrorStatus, "Clears error status");
cls_StdStorage_RootData.def("Clear", (void (StdStorage_RootData::*)()) &StdStorage_RootData::Clear, "Removes all persistent root objects");

// Enums

}