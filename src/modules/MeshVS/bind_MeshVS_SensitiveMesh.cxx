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
#include <Select3D_SensitiveEntity.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <MeshVS_SensitiveMesh.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_SensitiveMesh(py::module &mod){

py::class_<MeshVS_SensitiveMesh, opencascade::handle<MeshVS_SensitiveMesh>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveMesh(mod, "MeshVS_SensitiveMesh", "This class provides custom mesh sensitive entity used in advanced mesh selection.");

// Constructors
cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwner"));
cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Integer>(), py::arg("theOwner"), py::arg("theMode"));

// Fields

// Methods
cls_MeshVS_SensitiveMesh.def("GetMode", (Standard_Integer (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::GetMode, "None");
cls_MeshVS_SensitiveMesh.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::GetConnected, "None");
cls_MeshVS_SensitiveMesh.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::NbSubElements, "Returns the amount of mesh nodes");
cls_MeshVS_SensitiveMesh.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::BoundingBox, "Returns bounding box of mesh");
cls_MeshVS_SensitiveMesh.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::CenterOfGeometry, "Returns center of mesh");
cls_MeshVS_SensitiveMesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveMesh::get_type_name, "None");
cls_MeshVS_SensitiveMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveMesh::get_type_descriptor, "None");
cls_MeshVS_SensitiveMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveMesh::*)() const) &MeshVS_SensitiveMesh::DynamicType, "None");

// Enums

}