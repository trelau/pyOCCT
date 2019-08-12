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
#include <Select3D_SensitivePoint.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>

void bind_Select3D_SensitivePoint(py::module &mod){

py::class_<Select3D_SensitivePoint, opencascade::handle<Select3D_SensitivePoint>, Select3D_SensitiveEntity> cls_Select3D_SensitivePoint(mod, "Select3D_SensitivePoint", "A framework to define sensitive 3D points.");

// Constructors
cls_Select3D_SensitivePoint.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("thePoint"));

// Fields

// Methods
cls_Select3D_SensitivePoint.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePoint::get_type_name, "None");
cls_Select3D_SensitivePoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePoint::get_type_descriptor, "None");
cls_Select3D_SensitivePoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePoint::*)() const) &Select3D_SensitivePoint::DynamicType, "None");
cls_Select3D_SensitivePoint.def("NbSubElements", (Standard_Integer (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::NbSubElements, "Returns the amount of sub-entities in sensitive");
cls_Select3D_SensitivePoint.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::GetConnected, "None");
cls_Select3D_SensitivePoint.def("Matches", (Standard_Boolean (Select3D_SensitivePoint::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitivePoint::Matches, "Checks whether the point overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitivePoint.def("Point", (const gp_Pnt & (Select3D_SensitivePoint::*)() const) &Select3D_SensitivePoint::Point, "Returns the point used at the time of construction.");
cls_Select3D_SensitivePoint.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePoint::*)() const) &Select3D_SensitivePoint::CenterOfGeometry, "Returns center of point. If location transformation is set, it will be applied");
cls_Select3D_SensitivePoint.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::BoundingBox, "Returns bounding box of the point. If location transformation is set, it will be applied");

// Enums

}