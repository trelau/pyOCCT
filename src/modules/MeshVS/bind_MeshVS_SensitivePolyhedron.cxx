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
#include <TColgp_Array1OfPnt.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <MeshVS_SensitivePolyhedron.hxx>
#include <Standard_Type.hxx>
#include <gp_XYZ.hxx>
#include <TColgp_HArray1OfPnt.hxx>

void bind_MeshVS_SensitivePolyhedron(py::module &mod){

py::class_<MeshVS_SensitivePolyhedron, opencascade::handle<MeshVS_SensitivePolyhedron>, Select3D_SensitiveEntity> cls_MeshVS_SensitivePolyhedron(mod, "MeshVS_SensitivePolyhedron", "This class is used to detect selection of a polyhedron. The main principle of detection algorithm is to search for overlap with each polyhedron's face separately, treating them as planar convex polygons.");

// Constructors
cls_MeshVS_SensitivePolyhedron.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &>(), py::arg("theOwner"), py::arg("theNodes"), py::arg("theTopo"));

// Fields

// Methods
cls_MeshVS_SensitivePolyhedron.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::GetConnected, "None");
cls_MeshVS_SensitivePolyhedron.def("Matches", (Standard_Boolean (MeshVS_SensitivePolyhedron::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitivePolyhedron::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_SensitivePolyhedron.def("NbSubElements", (Standard_Integer (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::NbSubElements, "Returns the amount of nodes of polyhedron");
cls_MeshVS_SensitivePolyhedron.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::BoundingBox, "None");
cls_MeshVS_SensitivePolyhedron.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitivePolyhedron::*)() const) &MeshVS_SensitivePolyhedron::CenterOfGeometry, "None");
cls_MeshVS_SensitivePolyhedron.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitivePolyhedron::get_type_name, "None");
cls_MeshVS_SensitivePolyhedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitivePolyhedron::get_type_descriptor, "None");
cls_MeshVS_SensitivePolyhedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitivePolyhedron::*)() const) &MeshVS_SensitivePolyhedron::DynamicType, "None");

// Enums

}