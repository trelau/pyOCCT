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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Storage_CallBack.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_TypedCallBack.hxx>
#include <Standard_Type.hxx>

void bind_Storage_TypedCallBack(py::module &mod){

py::class_<Storage_TypedCallBack, opencascade::handle<Storage_TypedCallBack>, Standard_Transient> cls_Storage_TypedCallBack(mod, "Storage_TypedCallBack", "None");

// Constructors
cls_Storage_TypedCallBack.def(py::init<>());
cls_Storage_TypedCallBack.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Storage_CallBack> &>(), py::arg("aTypeName"), py::arg("aCallBack"));

// Fields

// Methods
cls_Storage_TypedCallBack.def("SetType", (void (Storage_TypedCallBack::*)(const TCollection_AsciiString &)) &Storage_TypedCallBack::SetType, "None", py::arg("aType"));
cls_Storage_TypedCallBack.def("Type", (TCollection_AsciiString (Storage_TypedCallBack::*)() const) &Storage_TypedCallBack::Type, "None");
cls_Storage_TypedCallBack.def("SetCallBack", (void (Storage_TypedCallBack::*)(const opencascade::handle<Storage_CallBack> &)) &Storage_TypedCallBack::SetCallBack, "None", py::arg("aCallBack"));
cls_Storage_TypedCallBack.def("CallBack", (opencascade::handle<Storage_CallBack> (Storage_TypedCallBack::*)() const) &Storage_TypedCallBack::CallBack, "None");
cls_Storage_TypedCallBack.def("SetIndex", (void (Storage_TypedCallBack::*)(const Standard_Integer)) &Storage_TypedCallBack::SetIndex, "None", py::arg("anIndex"));
cls_Storage_TypedCallBack.def("Index", (Standard_Integer (Storage_TypedCallBack::*)() const) &Storage_TypedCallBack::Index, "None");
cls_Storage_TypedCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_TypedCallBack::get_type_name, "None");
cls_Storage_TypedCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_TypedCallBack::get_type_descriptor, "None");
cls_Storage_TypedCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_TypedCallBack::*)() const) &Storage_TypedCallBack::DynamicType, "None");

// Enums

}