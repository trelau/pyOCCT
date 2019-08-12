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
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_GTrsf.hxx>
#include <MeshVS_DummySensitiveEntity.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_DummySensitiveEntity(py::module &mod){

py::class_<MeshVS_DummySensitiveEntity, opencascade::handle<MeshVS_DummySensitiveEntity>, SelectBasics_SensitiveEntity> cls_MeshVS_DummySensitiveEntity(mod, "MeshVS_DummySensitiveEntity", "This class allows to create owners to all elements or nodes, both hidden and shown, but these owners user cannot select 'by hands' in viewer. They means for internal application tasks, for example, receiving all owners, both for hidden and shown entities.");

// Constructors
cls_MeshVS_DummySensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));

// Fields

// Methods
cls_MeshVS_DummySensitiveEntity.def("Matches", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_DummySensitiveEntity::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_DummySensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::NbSubElements, "None");
cls_MeshVS_DummySensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BoundingBox, "None");
cls_MeshVS_DummySensitiveEntity.def("BVH", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BVH, "None");
cls_MeshVS_DummySensitiveEntity.def("Clear", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::Clear, "None");
cls_MeshVS_DummySensitiveEntity.def("HasInitLocation", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::HasInitLocation, "None");
cls_MeshVS_DummySensitiveEntity.def("InvInitLocation", (gp_GTrsf (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::InvInitLocation, "None");
cls_MeshVS_DummySensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_DummySensitiveEntity::get_type_name, "None");
cls_MeshVS_DummySensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DummySensitiveEntity::get_type_descriptor, "None");
cls_MeshVS_DummySensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DummySensitiveEntity::*)() const) &MeshVS_DummySensitiveEntity::DynamicType, "None");

// Enums

}