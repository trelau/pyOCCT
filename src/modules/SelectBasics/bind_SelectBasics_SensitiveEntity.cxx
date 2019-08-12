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
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Standard_ProgramError.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_GTrsf.hxx>

void bind_SelectBasics_SensitiveEntity(py::module &mod){

py::class_<SelectBasics_SensitiveEntity, opencascade::handle<SelectBasics_SensitiveEntity>, Standard_Transient> cls_SelectBasics_SensitiveEntity(mod, "SelectBasics_SensitiveEntity", "root class; the inheriting classes will be able to give sensitive Areas for the dynamic selection algorithms");

// Fields

// Methods
cls_SelectBasics_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &SelectBasics_SensitiveEntity::get_type_name, "None");
cls_SelectBasics_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectBasics_SensitiveEntity::get_type_descriptor, "None");
cls_SelectBasics_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::DynamicType, "None");
cls_SelectBasics_SensitiveEntity.def("Set", (void (SelectBasics_SensitiveEntity::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &SelectBasics_SensitiveEntity::Set, "Sets owner of the entity", py::arg("theOwnerId"));
cls_SelectBasics_SensitiveEntity.def("OwnerId", (const opencascade::handle<SelectBasics_EntityOwner> & (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::OwnerId, "Returns pointer to owner of the entity");
cls_SelectBasics_SensitiveEntity.def("Matches", (Standard_Boolean (SelectBasics_SensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &SelectBasics_SensitiveEntity::Matches, "Checks whether the sensitive entity is overlapped by current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_SelectBasics_SensitiveEntity.def("SensitivityFactor", (Standard_Integer (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::SensitivityFactor, "allows a better sensitivity for a specific entity in selection algorithms useful for small sized entities.");
cls_SelectBasics_SensitiveEntity.def("SetSensitivityFactor", (void (SelectBasics_SensitiveEntity::*)(const Standard_Integer)) &SelectBasics_SensitiveEntity::SetSensitivityFactor, "Allows to manage sensitivity of a particular sensitive entity", py::arg("theNewSens"));
cls_SelectBasics_SensitiveEntity.def("NbSubElements", (Standard_Integer (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::NbSubElements, "Returns the number of sub-entities or elements in sensitive entity. Is used to determine if entity is complex and needs to pre-build BVH at the creation of sensitive entity step or is light-weighted so the tree can be build on demand with unnoticeable delay");
cls_SelectBasics_SensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::BoundingBox, "Returns bounding box of sensitive entity", py::call_guard<ImportSelect3D>());
cls_SelectBasics_SensitiveEntity.def("BVH", (void (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::BVH, "Builds BVH tree for sensitive if it is needed");
cls_SelectBasics_SensitiveEntity.def("Clear", (void (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::Clear, "Clears up all the resources and memory allocated");
cls_SelectBasics_SensitiveEntity.def("HasInitLocation", (Standard_Boolean (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
cls_SelectBasics_SensitiveEntity.def("InvInitLocation", (gp_GTrsf (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");

// Enums

}