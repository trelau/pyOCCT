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
#include <Select3D_SensitiveSet.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_CommonSensitiveEntity.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <MeshVS_Mesh.hxx>
#include <MeshVS_MeshSelectionMethod.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <MeshVS_DataSource.hxx>
#include <NCollection_Vector.hxx>

void bind_MeshVS_CommonSensitiveEntity(py::module &mod){

py::class_<MeshVS_CommonSensitiveEntity, opencascade::handle<MeshVS_CommonSensitiveEntity>, Select3D_SensitiveSet> cls_MeshVS_CommonSensitiveEntity(mod, "MeshVS_CommonSensitiveEntity", "Sensitive entity covering entire mesh for global selection.");

// Constructors
cls_MeshVS_CommonSensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<MeshVS_Mesh> &, const MeshVS_MeshSelectionMethod>(), py::arg("theOwner"), py::arg("theParentMesh"), py::arg("theSelMethod"));

// Fields

// Methods
cls_MeshVS_CommonSensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_CommonSensitiveEntity::get_type_name, "None");
cls_MeshVS_CommonSensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_CommonSensitiveEntity::get_type_descriptor, "None");
cls_MeshVS_CommonSensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::DynamicType, "None");
cls_MeshVS_CommonSensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::NbSubElements, "Number of elements.");
cls_MeshVS_CommonSensitiveEntity.def("Size", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::Size, "Returns the amount of sub-entities of the complex entity");
cls_MeshVS_CommonSensitiveEntity.def("Box", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer) const) &MeshVS_CommonSensitiveEntity::Box, "Returns bounding box of sub-entity with index theIdx in sub-entity list", py::arg("theIdx"));
cls_MeshVS_CommonSensitiveEntity.def("Center", (Standard_Real (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer) const) &MeshVS_CommonSensitiveEntity::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_MeshVS_CommonSensitiveEntity.def("Swap", (void (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_CommonSensitiveEntity::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIdx1"), py::arg("theIdx2"));
cls_MeshVS_CommonSensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
cls_MeshVS_CommonSensitiveEntity.def("CenterOfGeometry", (gp_Pnt (MeshVS_CommonSensitiveEntity::*)() const) &MeshVS_CommonSensitiveEntity::CenterOfGeometry, "Returns center of a mesh");
cls_MeshVS_CommonSensitiveEntity.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::GetConnected, "Create a copy.");

// Enums

}