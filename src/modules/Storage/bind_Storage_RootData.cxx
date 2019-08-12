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
#include <Standard_Handle.hxx>
#include <Storage_Root.hxx>
#include <Storage_HSeqOfRoot.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_Error.hxx>
#include <Standard_Persistent.hxx>
#include <Storage_Schema.hxx>
#include <Storage_RootData.hxx>
#include <Standard_Type.hxx>
#include <Storage_MapOfPers.hxx>

void bind_Storage_RootData(py::module &mod){

py::class_<Storage_RootData, opencascade::handle<Storage_RootData>, Standard_Transient> cls_Storage_RootData(mod, "Storage_RootData", "None");

// Constructors
cls_Storage_RootData.def(py::init<>());

// Fields

// Methods
cls_Storage_RootData.def("Read", (Standard_Boolean (Storage_RootData::*)(Storage_BaseDriver &)) &Storage_RootData::Read, "None", py::arg("theDriver"));
cls_Storage_RootData.def("NumberOfRoots", (Standard_Integer (Storage_RootData::*)() const) &Storage_RootData::NumberOfRoots, "returns the number of roots.");
cls_Storage_RootData.def("AddRoot", (void (Storage_RootData::*)(const opencascade::handle<Storage_Root> &)) &Storage_RootData::AddRoot, "add a root to <me>. If a root with same name is present, it will be replaced by <aRoot>.", py::arg("aRoot"));
cls_Storage_RootData.def("Roots", (opencascade::handle<Storage_HSeqOfRoot> (Storage_RootData::*)() const) &Storage_RootData::Roots, "None");
cls_Storage_RootData.def("Find", (opencascade::handle<Storage_Root> (Storage_RootData::*)(const TCollection_AsciiString &) const) &Storage_RootData::Find, "find a root with name <aName>.", py::arg("aName"));
cls_Storage_RootData.def("IsRoot", (Standard_Boolean (Storage_RootData::*)(const TCollection_AsciiString &) const) &Storage_RootData::IsRoot, "returns Standard_True if <me> contains a root named <aName>", py::arg("aName"));
cls_Storage_RootData.def("RemoveRoot", (void (Storage_RootData::*)(const TCollection_AsciiString &)) &Storage_RootData::RemoveRoot, "remove the root named <aName>.", py::arg("aName"));
cls_Storage_RootData.def("ErrorStatus", (Storage_Error (Storage_RootData::*)() const) &Storage_RootData::ErrorStatus, "None");
cls_Storage_RootData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_RootData::*)() const) &Storage_RootData::ErrorStatusExtension, "None");
cls_Storage_RootData.def("ClearErrorStatus", (void (Storage_RootData::*)()) &Storage_RootData::ClearErrorStatus, "None");
cls_Storage_RootData.def("UpdateRoot", (void (Storage_RootData::*)(const TCollection_AsciiString &, const opencascade::handle<Standard_Persistent> &)) &Storage_RootData::UpdateRoot, "None", py::arg("aName"), py::arg("aPers"));
cls_Storage_RootData.def_static("get_type_name_", (const char * (*)()) &Storage_RootData::get_type_name, "None");
cls_Storage_RootData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_RootData::get_type_descriptor, "None");
cls_Storage_RootData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_RootData::*)() const) &Storage_RootData::DynamicType, "None");

// Enums

}