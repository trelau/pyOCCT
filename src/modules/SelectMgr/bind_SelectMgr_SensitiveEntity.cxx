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
#include <SelectBasics_SensitiveEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SensitiveEntity.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_SensitiveEntity(py::module &mod){

py::class_<SelectMgr_SensitiveEntity, opencascade::handle<SelectMgr_SensitiveEntity>, Standard_Transient> cls_SelectMgr_SensitiveEntity(mod, "SelectMgr_SensitiveEntity", "The purpose of this class is to mark sensitive entities selectable or not depending on current active selection of parent object for proper BVH traverse");

// Constructors
cls_SelectMgr_SensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_SensitiveEntity> &>(), py::arg("theEntity"));

// Fields

// Methods
cls_SelectMgr_SensitiveEntity.def("Clear", (void (SelectMgr_SensitiveEntity::*)()) &SelectMgr_SensitiveEntity::Clear, "Clears up all resources and memory");
cls_SelectMgr_SensitiveEntity.def("BaseSensitive", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_SensitiveEntity::*)() const) &SelectMgr_SensitiveEntity::BaseSensitive, "Returns related instance of SelectBasics class");
cls_SelectMgr_SensitiveEntity.def("IsActiveForSelection", (Standard_Boolean (SelectMgr_SensitiveEntity::*)() const) &SelectMgr_SensitiveEntity::IsActiveForSelection, "Returns true if this entity belongs to the active selection mode of parent object");
cls_SelectMgr_SensitiveEntity.def("ResetSelectionActiveStatus", (void (SelectMgr_SensitiveEntity::*)() const) &SelectMgr_SensitiveEntity::ResetSelectionActiveStatus, "Marks entity as inactive for selection");
cls_SelectMgr_SensitiveEntity.def("SetActiveForSelection", (void (SelectMgr_SensitiveEntity::*)() const) &SelectMgr_SensitiveEntity::SetActiveForSelection, "Marks entity as active for selection");
cls_SelectMgr_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SensitiveEntity::get_type_name, "None");
cls_SelectMgr_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SensitiveEntity::get_type_descriptor, "None");
cls_SelectMgr_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SensitiveEntity::*)() const) &SelectMgr_SensitiveEntity::DynamicType, "None");

// Enums

}