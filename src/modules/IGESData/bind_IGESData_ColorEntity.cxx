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
#include <IGESData_ColorEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_ColorEntity(py::module &mod){

py::class_<IGESData_ColorEntity, opencascade::handle<IGESData_ColorEntity>, IGESData_IGESEntity> cls_IGESData_ColorEntity(mod, "IGESData_ColorEntity", "defines required type for Color in directory part an effective Color entity must inherits it");

// Constructors

// Fields

// Methods
cls_IGESData_ColorEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_ColorEntity::get_type_name, "None");
cls_IGESData_ColorEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ColorEntity::get_type_descriptor, "None");
cls_IGESData_ColorEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ColorEntity::*)() const) &IGESData_ColorEntity::DynamicType, "None");

// Enums

}