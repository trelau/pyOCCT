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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Storage_Error.hxx>
#include <Storage_Schema.hxx>
#include <Storage_TypeData.hxx>
#include <Standard_Type.hxx>
#include <Storage_PType.hxx>

void bind_Storage_TypeData(py::module &mod){

py::class_<Storage_TypeData, opencascade::handle<Storage_TypeData>, Standard_Transient> cls_Storage_TypeData(mod, "Storage_TypeData", "None");

// Constructors
cls_Storage_TypeData.def(py::init<>());

// Fields

// Methods
cls_Storage_TypeData.def("Read", (Standard_Boolean (Storage_TypeData::*)(Storage_BaseDriver &)) &Storage_TypeData::Read, "None", py::arg("theDriver"));
cls_Storage_TypeData.def("NumberOfTypes", (Standard_Integer (Storage_TypeData::*)() const) &Storage_TypeData::NumberOfTypes, "None");
cls_Storage_TypeData.def("AddType", (void (Storage_TypeData::*)(const TCollection_AsciiString &, const Standard_Integer)) &Storage_TypeData::AddType, "add a type to the list", py::arg("aName"), py::arg("aTypeNum"));
cls_Storage_TypeData.def("Type", (TCollection_AsciiString (Storage_TypeData::*)(const Standard_Integer) const) &Storage_TypeData::Type, "returns the name of the type with number <aTypeNum>", py::arg("aTypeNum"));
cls_Storage_TypeData.def("Type", (Standard_Integer (Storage_TypeData::*)(const TCollection_AsciiString &) const) &Storage_TypeData::Type, "returns the name of the type with number <aTypeNum>", py::arg("aTypeName"));
cls_Storage_TypeData.def("IsType", (Standard_Boolean (Storage_TypeData::*)(const TCollection_AsciiString &) const) &Storage_TypeData::IsType, "None", py::arg("aName"));
cls_Storage_TypeData.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (Storage_TypeData::*)() const) &Storage_TypeData::Types, "None");
cls_Storage_TypeData.def("ErrorStatus", (Storage_Error (Storage_TypeData::*)() const) &Storage_TypeData::ErrorStatus, "None");
cls_Storage_TypeData.def("ErrorStatusExtension", (TCollection_AsciiString (Storage_TypeData::*)() const) &Storage_TypeData::ErrorStatusExtension, "None");
cls_Storage_TypeData.def("ClearErrorStatus", (void (Storage_TypeData::*)()) &Storage_TypeData::ClearErrorStatus, "None");
cls_Storage_TypeData.def("Clear", (void (Storage_TypeData::*)()) &Storage_TypeData::Clear, "None");
cls_Storage_TypeData.def_static("get_type_name_", (const char * (*)()) &Storage_TypeData::get_type_name, "None");
cls_Storage_TypeData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_TypeData::get_type_descriptor, "None");
cls_Storage_TypeData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_TypeData::*)() const) &Storage_TypeData::DynamicType, "None");

// Enums

}