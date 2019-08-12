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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESData_NameEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_NameEntity(py::module &mod){

py::class_<IGESData_NameEntity, opencascade::handle<IGESData_NameEntity>, IGESData_IGESEntity> cls_IGESData_NameEntity(mod, "IGESData_NameEntity", "a NameEntity is a kind of IGESEntity which can provide a Name under alphanumeric (String) form, from Properties list an effective Name entity must inherit it");

// Fields

// Methods
cls_IGESData_NameEntity.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESData_NameEntity::*)() const) &IGESData_NameEntity::Value, "Retyrns the alphanumeric value of the Name, to be defined");
cls_IGESData_NameEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_NameEntity::get_type_name, "None");
cls_IGESData_NameEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NameEntity::get_type_descriptor, "None");
cls_IGESData_NameEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NameEntity::*)() const) &IGESData_NameEntity::DynamicType, "None");

// Enums

}