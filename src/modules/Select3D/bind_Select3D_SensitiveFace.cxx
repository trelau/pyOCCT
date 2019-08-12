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
#include <Select3D_SensitiveFace.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_SensitiveSet.hxx>

void bind_Select3D_SensitiveFace(py::module &mod){

py::class_<Select3D_SensitiveFace, opencascade::handle<Select3D_SensitiveFace>, Select3D_SensitiveEntity> cls_Select3D_SensitiveFace(mod, "Select3D_SensitiveFace", "Sensitive Entity to make a face selectable. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");

// Constructors
cls_Select3D_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theType"));
cls_Select3D_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theType"));

// Fields

// Methods
cls_Select3D_SensitiveFace.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveFace::get_type_name, "None");
cls_Select3D_SensitiveFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveFace::get_type_descriptor, "None");
cls_Select3D_SensitiveFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveFace::*)() const) &Select3D_SensitiveFace::DynamicType, "None");
cls_Select3D_SensitiveFace.def("GetPoints", (void (Select3D_SensitiveFace::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_SensitiveFace::GetPoints, "Initializes the given array theHArrayOfPnt by 3d coordinates of vertices of the face", py::arg("theHArrayOfPnt"));
cls_Select3D_SensitiveFace.def("Matches", (Standard_Boolean (Select3D_SensitiveFace::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveFace::Matches, "Checks whether the face overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveFace.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::GetConnected, "None");
cls_Select3D_SensitiveFace.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::BoundingBox, "Returns bounding box of the face. If location transformation is set, it will be applied");
cls_Select3D_SensitiveFace.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveFace::*)() const) &Select3D_SensitiveFace::CenterOfGeometry, "Returns center of the face. If location transformation is set, it will be applied");
cls_Select3D_SensitiveFace.def("BVH", (void (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::BVH, "Builds BVH tree for the face");
cls_Select3D_SensitiveFace.def("NbSubElements", (Standard_Integer (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::NbSubElements, "Returns the amount of sub-entities (points or planar convex polygons)");

// Enums

}