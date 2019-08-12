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
#include <Standard_TypeDef.hxx>
#include <IGESData_SingleParentEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_SingleParentEntity(py::module &mod){

py::class_<IGESData_SingleParentEntity, opencascade::handle<IGESData_SingleParentEntity>, IGESData_IGESEntity> cls_IGESData_SingleParentEntity(mod, "IGESData_SingleParentEntity", "a SingleParentEntity is a kind of IGESEntity which can refer to a (Single) Parent, from Associativities list of an Entity a effective SingleParent definition entity must inherit it");

// Fields

// Methods
cls_IGESData_SingleParentEntity.def("SingleParent", (opencascade::handle<IGESData_IGESEntity> (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::SingleParent, "Returns the parent designated by the Entity, if only one !");
cls_IGESData_SingleParentEntity.def("NbChildren", (Standard_Integer (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::NbChildren, "Returns the count of Entities designated as children");
cls_IGESData_SingleParentEntity.def("Child", (opencascade::handle<IGESData_IGESEntity> (IGESData_SingleParentEntity::*)(const Standard_Integer) const) &IGESData_SingleParentEntity::Child, "Returns a Child given its rank", py::arg("num"));
cls_IGESData_SingleParentEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_SingleParentEntity::get_type_name, "None");
cls_IGESData_SingleParentEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_SingleParentEntity::get_type_descriptor, "None");
cls_IGESData_SingleParentEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::DynamicType, "None");

// Enums

}