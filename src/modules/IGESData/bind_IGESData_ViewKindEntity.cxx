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
#include <IGESData_ViewKindEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_ViewKindEntity(py::module &mod){

py::class_<IGESData_ViewKindEntity, opencascade::handle<IGESData_ViewKindEntity>, IGESData_IGESEntity> cls_IGESData_ViewKindEntity(mod, "IGESData_ViewKindEntity", "defines required type for ViewKind in directory part that is, Single view or Multiple view An effective ViewKind entity must inherit it and define IsSingle (True for Single, False for List of Views), NbViews and ViewItem (especially for a List)");

// Fields

// Methods
cls_IGESData_ViewKindEntity.def("IsSingle", (Standard_Boolean (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::IsSingle, "says if 'me' is a Single View (True) or a List of Views (False)");
cls_IGESData_ViewKindEntity.def("NbViews", (Standard_Integer (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::NbViews, "Returns the count of Views for a List of Views. For a Single View, may return simply 1");
cls_IGESData_ViewKindEntity.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESData_ViewKindEntity::*)(const Standard_Integer) const) &IGESData_ViewKindEntity::ViewItem, "Returns the View n0. <num> for a List of Views. For a Single Views, may return <me> itself", py::arg("num"));
cls_IGESData_ViewKindEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_ViewKindEntity::get_type_name, "None");
cls_IGESData_ViewKindEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ViewKindEntity::get_type_descriptor, "None");
cls_IGESData_ViewKindEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::DynamicType, "None");

// Enums

}