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
#include <Standard_Persistent.hxx>
#include <Storage_Schema.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_CallBack.hxx>
#include <Standard_Type.hxx>

void bind_Storage_CallBack(py::module &mod){

py::class_<Storage_CallBack, opencascade::handle<Storage_CallBack>, Standard_Transient> cls_Storage_CallBack(mod, "Storage_CallBack", "None");

// Fields

// Methods
cls_Storage_CallBack.def("New", (opencascade::handle<Standard_Persistent> (Storage_CallBack::*)() const) &Storage_CallBack::New, "None");
cls_Storage_CallBack.def("Add", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, const opencascade::handle<Storage_Schema> &) const) &Storage_CallBack::Add, "None", py::arg("aPers"), py::arg("aSchema"));
cls_Storage_CallBack.def("Write", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const) &Storage_CallBack::Write, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
cls_Storage_CallBack.def("Read", (void (Storage_CallBack::*)(const opencascade::handle<Standard_Persistent> &, Storage_BaseDriver &, const opencascade::handle<Storage_Schema> &) const) &Storage_CallBack::Read, "None", py::arg("aPers"), py::arg("aDriver"), py::arg("aSchema"));
cls_Storage_CallBack.def_static("get_type_name_", (const char * (*)()) &Storage_CallBack::get_type_name, "None");
cls_Storage_CallBack.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_CallBack::get_type_descriptor, "None");
cls_Storage_CallBack.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_CallBack::*)() const) &Storage_CallBack::DynamicType, "None");

// Enums

}