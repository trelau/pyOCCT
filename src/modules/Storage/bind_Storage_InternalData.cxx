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
#include <Storage_HPArray.hxx>
#include <Storage_Schema.hxx>
#include <Storage_InternalData.hxx>
#include <Standard_Type.hxx>
#include <Storage_BucketOfPersistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_MapOfCallBack.hxx>

void bind_Storage_InternalData(py::module &mod){

py::class_<Storage_InternalData, opencascade::handle<Storage_InternalData>, Standard_Transient> cls_Storage_InternalData(mod, "Storage_InternalData", "None");

// Constructors
cls_Storage_InternalData.def(py::init<>());

// Fields

// Methods
cls_Storage_InternalData.def("ReadArray", (opencascade::handle<Storage_HPArray> (Storage_InternalData::*)()) &Storage_InternalData::ReadArray, "None");
cls_Storage_InternalData.def("Clear", (void (Storage_InternalData::*)()) &Storage_InternalData::Clear, "None");
cls_Storage_InternalData.def_static("get_type_name_", (const char * (*)()) &Storage_InternalData::get_type_name, "None");
cls_Storage_InternalData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_InternalData::get_type_descriptor, "None");
cls_Storage_InternalData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_InternalData::*)() const) &Storage_InternalData::DynamicType, "None");

// Enums

}