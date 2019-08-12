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
#include <StdStorage_TypeData.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_BaseDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Storage_Error.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdStorage_MapOfTypes.hxx>

void bind_StdStorage_TypeData(py::module &mod){

py::class_<StdStorage_TypeData, opencascade::handle<StdStorage_TypeData>, Standard_Transient> cls_StdStorage_TypeData(mod, "StdStorage_TypeData", "Storage type data section keeps association between persistent textual types and their numbers");

// Constructors

// Fields

// Methods
cls_StdStorage_TypeData.def_static("get_type_name_", (const char * (*)()) &StdStorage_TypeData::get_type_name, "None");
cls_StdStorage_TypeData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_TypeData::get_type_descriptor, "None");
cls_StdStorage_TypeData.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_TypeData::*)() const) &StdStorage_TypeData::DynamicType, "None");
cls_StdStorage_TypeData.def("Read", (Standard_Boolean (StdStorage_TypeData::*)(Storage_BaseDriver &)) &StdStorage_TypeData::Read, "Reads the type data section from the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_TypeData.def("Write", (Standard_Boolean (StdStorage_TypeData::*)(Storage_BaseDriver &)) &StdStorage_TypeData::Write, "Writes the type data section to the container defined by theDriver. Returns Standard_True in case of success. Otherwise, one need to get an error code and description using ErrorStatus and ErrorStatusExtension functions correspondingly.", py::arg("theDriver"));
cls_StdStorage_TypeData.def("NumberOfTypes", (Standard_Integer (StdStorage_TypeData::*)() const) &StdStorage_TypeData::NumberOfTypes, "Returns the number of registered types");
cls_StdStorage_TypeData.def("AddType", (void (StdStorage_TypeData::*)(const TCollection_AsciiString &, const Standard_Integer)) &StdStorage_TypeData::AddType, "Add a type to the list in case of reading data", py::arg("aTypeName"), py::arg("aTypeNum"));
cls_StdStorage_TypeData.def("AddType", (Standard_Integer (StdStorage_TypeData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdStorage_TypeData::AddType, "Add a type of the persistent object in case of writing data", py::arg("aPObj"));
cls_StdStorage_TypeData.def("Type", (TCollection_AsciiString (StdStorage_TypeData::*)(const Standard_Integer) const) &StdStorage_TypeData::Type, "Returns the name of the type with number <aTypeNum>", py::arg("aTypeNum"));
cls_StdStorage_TypeData.def("Type", (Standard_Integer (StdStorage_TypeData::*)(const TCollection_AsciiString &) const) &StdStorage_TypeData::Type, "Returns the name of the type with number <aTypeNum>", py::arg("aTypeName"));
cls_StdStorage_TypeData.def("Instantiator", (StdObjMgt_Persistent::Instantiator (StdStorage_TypeData::*)(const Standard_Integer) const) &StdStorage_TypeData::Instantiator, "Returns a persistent object instantiator of <aTypeName>", py::arg("aTypeNum"));
cls_StdStorage_TypeData.def("IsType", (Standard_Boolean (StdStorage_TypeData::*)(const TCollection_AsciiString &) const) &StdStorage_TypeData::IsType, "Checks if <aName> is a registered type", py::arg("aName"));
cls_StdStorage_TypeData.def("Types", (opencascade::handle<TColStd_HSequenceOfAsciiString> (StdStorage_TypeData::*)() const) &StdStorage_TypeData::Types, "Returns a sequence of all registered types");
cls_StdStorage_TypeData.def("ErrorStatus", (Storage_Error (StdStorage_TypeData::*)() const) &StdStorage_TypeData::ErrorStatus, "Returns a status of the latest call to Read / Write functions");
cls_StdStorage_TypeData.def("ErrorStatusExtension", (TCollection_AsciiString (StdStorage_TypeData::*)() const) &StdStorage_TypeData::ErrorStatusExtension, "Returns an error message if any of the latest call to Read / Write functions");
cls_StdStorage_TypeData.def("ClearErrorStatus", (void (StdStorage_TypeData::*)()) &StdStorage_TypeData::ClearErrorStatus, "Clears error status");
cls_StdStorage_TypeData.def("Clear", (void (StdStorage_TypeData::*)()) &StdStorage_TypeData::Clear, "Unregisters all types");

// Enums

}