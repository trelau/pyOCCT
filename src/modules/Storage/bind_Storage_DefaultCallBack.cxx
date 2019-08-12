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
#include <Storage_CallBack.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Persistent.hxx>
#include <Storage_Schema.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_DefaultCallBack.hxx>
#include <Standard_Type.hxx>

void bind_Storage_DefaultCallBack(py::module &mod){

py::class_<Storage_DefaultCallBack, opencascade::handle<Storage_DefaultCallBack>, Storage_CallBack> cls_Storage_DefaultCallBack(mod, "Storage_DefaultCallBack", "None");

// Constructors
cls_Storage_DefaultCallBack.def(py::init<>());

// Fields

// Methods
cls_Storage_DefaultCallBack.def("New", (opencascade::handle<Standard_Persistent> (Storage_DefaultCallBack::*)() const) &Storage_DefaultCallBack::New, "None");
cls_Storage_DefaultCallBack.def("Add", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, const opencascade::handle<Storage_Schema> &) const) &Storage_DefaultCallBack::Add, "None", py::arg("aPers"), py::arg("aSchema"));
cls_Storage_DefaultCallBack.def("Write", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const) &Storage_DefaultCallBack::Write, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
cls_Storage_DefaultCallBack.def("Read", (void (Storage_DefaultCallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const) &Storage_DefaultCallBack::Read, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
cls_Storage_DefaultCallBack.def_static("get_type_name_", (const char * (*)()) &Storage_DefaultCallBack::get_type_name, "None");
cls_Storage_DefaultCallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_DefaultCallBack::get_type_descriptor, "None");
cls_Storage_DefaultCallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_DefaultCallBack::*)() const) &Storage_DefaultCallBack::DynamicType, "None");

// Enums

}