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
#include <SelectBasics_SensitiveEntity.hxx>
#include <Standard_Handle.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <gp_GTrsf.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>

void bind_Select3D_SensitiveEntity(py::module &mod){

py::class_<Select3D_SensitiveEntity, opencascade::handle<Select3D_SensitiveEntity>, SelectBasics_SensitiveEntity> cls_Select3D_SensitiveEntity(mod, "Select3D_SensitiveEntity", "Abstract framework to define 3D sensitive entities. As the selection process uses the principle of a projection of 3D shapes onto a 2D view where nearness to a rectangle determines whether a shape is picked or not, all 3D shapes need to be converted into 2D ones in order to be selected.");

// Fields

// Methods
cls_Select3D_SensitiveEntity.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::GetConnected, "Originally this method intended to return sensitive entity with new location aLocation, but currently sensitive entities do not hold a location, instead HasLocation() and Location() methods call corresponding entity owner's methods. Thus all entities returned by GetConnected() share the same location propagated from corresponding selectable object. You must redefine this function for any type of sensitive entity which can accept another connected sensitive entity.//can be connected to another sensitive entity.");
cls_Select3D_SensitiveEntity.def("Matches", (Standard_Boolean (Select3D_SensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveEntity::Matches, "Checks whether sensitive overlaps current selecting volume. Stores minimum depth, distance to center of geometry and closest point detected into thePickResult", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveEntity.def("NbSubElements", (Standard_Integer (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::NbSubElements, "Returns the number of sub-entities or elements in sensitive entity. Is used to determine if entity is complex and needs to pre-build BVH at the creation of sensitive entity step or is light-weighted so the tree can be build on demand with unnoticeable delay");
cls_Select3D_SensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::BoundingBox, "Returns bounding box of a sensitive with transformation applied");
cls_Select3D_SensitiveEntity.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveEntity::*)() const) &Select3D_SensitiveEntity::CenterOfGeometry, "Returns center of a sensitive with transformation applied");
cls_Select3D_SensitiveEntity.def("BVH", (void (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::BVH, "Builds BVH tree for a sensitive if needed");
cls_Select3D_SensitiveEntity.def("Clear", (void (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::Clear, "Clears up all resources and memory");
cls_Select3D_SensitiveEntity.def("HasInitLocation", (Standard_Boolean (Select3D_SensitiveEntity::*)() const) &Select3D_SensitiveEntity::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
cls_Select3D_SensitiveEntity.def("InvInitLocation", (gp_GTrsf (Select3D_SensitiveEntity::*)() const) &Select3D_SensitiveEntity::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
cls_Select3D_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveEntity::get_type_name, "None");
cls_Select3D_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveEntity::get_type_descriptor, "None");
cls_Select3D_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveEntity::*)() const) &Select3D_SensitiveEntity::DynamicType, "None");

// Enums

}