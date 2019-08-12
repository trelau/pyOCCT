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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_LevelListEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_LevelListEntity(py::module &mod){

py::class_<IGESData_LevelListEntity, opencascade::handle<IGESData_LevelListEntity>, IGESData_IGESEntity> cls_IGESData_LevelListEntity(mod, "IGESData_LevelListEntity", "defines required type for LevelList in directory part an effective LevelList entity must inherits it");

// Fields

// Methods
cls_IGESData_LevelListEntity.def("NbLevelNumbers", (Standard_Integer (IGESData_LevelListEntity::*)() const) &IGESData_LevelListEntity::NbLevelNumbers, "Must return the count of levels");
cls_IGESData_LevelListEntity.def("LevelNumber", (Standard_Integer (IGESData_LevelListEntity::*)(const Standard_Integer) const) &IGESData_LevelListEntity::LevelNumber, "returns the Level Number of <me>, indicated by <num> raises an exception if num is out of range", py::arg("num"));
cls_IGESData_LevelListEntity.def("HasLevelNumber", (Standard_Boolean (IGESData_LevelListEntity::*)(const Standard_Integer) const) &IGESData_LevelListEntity::HasLevelNumber, "returns True if <level> is in the list", py::arg("level"));
cls_IGESData_LevelListEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_LevelListEntity::get_type_name, "None");
cls_IGESData_LevelListEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_LevelListEntity::get_type_descriptor, "None");
cls_IGESData_LevelListEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_LevelListEntity::*)() const) &IGESData_LevelListEntity::DynamicType, "None");

// Enums

}