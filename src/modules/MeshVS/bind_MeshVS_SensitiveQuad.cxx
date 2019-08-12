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
#include <SelectMgr_EntityOwner.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <MeshVS_SensitiveQuad.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_SensitiveQuad(py::module &mod){

py::class_<MeshVS_SensitiveQuad, opencascade::handle<MeshVS_SensitiveQuad>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveQuad(mod, "MeshVS_SensitiveQuad", "This class contains description of planar quadrangle and defines methods for its detection by OCCT BVH selection mechanism");

// Constructors
cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("theQuadVerts"));
cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("thePnt4"));

// Fields

// Methods
cls_MeshVS_SensitiveQuad.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::NbSubElements, "Returns the amount of sub-entities in sensitive");
cls_MeshVS_SensitiveQuad.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::GetConnected, "Returns a copy of this sensitive quadrangle");
cls_MeshVS_SensitiveQuad.def("Matches", (Standard_Boolean (MeshVS_SensitiveQuad::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitiveQuad::Matches, "Checks whether the box overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_MeshVS_SensitiveQuad.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveQuad::*)() const) &MeshVS_SensitiveQuad::CenterOfGeometry, "Returns center of the box");
cls_MeshVS_SensitiveQuad.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::BoundingBox, "Returns coordinates of the box");
cls_MeshVS_SensitiveQuad.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveQuad::get_type_name, "None");
cls_MeshVS_SensitiveQuad.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveQuad::get_type_descriptor, "None");
cls_MeshVS_SensitiveQuad.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveQuad::*)() const) &MeshVS_SensitiveQuad::DynamicType, "None");

// Enums

}