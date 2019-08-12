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
#include <Select3D_SensitiveSegment.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>

void bind_Select3D_SensitiveSegment(py::module &mod){

py::class_<Select3D_SensitiveSegment, opencascade::handle<Select3D_SensitiveSegment>, Select3D_SensitiveEntity> cls_Select3D_SensitiveSegment(mod, "Select3D_SensitiveSegment", "A framework to define sensitive zones along a segment One gives the 3D start and end point");

// Constructors
cls_Select3D_SensitiveSegment.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("theFirstPnt"), py::arg("theLastPnt"));

// Fields

// Methods
cls_Select3D_SensitiveSegment.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveSegment::get_type_name, "None");
cls_Select3D_SensitiveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveSegment::get_type_descriptor, "None");
cls_Select3D_SensitiveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveSegment::*)() const) &Select3D_SensitiveSegment::DynamicType, "None");
cls_Select3D_SensitiveSegment.def("SetStartPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::SetStartPoint, "changes the start Point of the Segment;", py::arg("thePnt"));
cls_Select3D_SensitiveSegment.def("SetEndPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::SetEndPoint, "changes the end point of the segment", py::arg("thePnt"));
cls_Select3D_SensitiveSegment.def("StartPoint", (const gp_Pnt & (Select3D_SensitiveSegment::*)() const) &Select3D_SensitiveSegment::StartPoint, "gives the 3D start Point of the Segment");
cls_Select3D_SensitiveSegment.def("EndPoint", (const gp_Pnt & (Select3D_SensitiveSegment::*)() const) &Select3D_SensitiveSegment::EndPoint, "gives the 3D End Point of the Segment");
cls_Select3D_SensitiveSegment.def("NbSubElements", (Standard_Integer (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::NbSubElements, "Returns the amount of points");
cls_Select3D_SensitiveSegment.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::GetConnected, "None");
cls_Select3D_SensitiveSegment.def("Matches", (Standard_Boolean (Select3D_SensitiveSegment::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveSegment::Matches, "Checks whether the segment overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveSegment.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveSegment::*)() const) &Select3D_SensitiveSegment::CenterOfGeometry, "Returns center of the segment. If location transformation is set, it will be applied");
cls_Select3D_SensitiveSegment.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::BoundingBox, "Returns bounding box of the segment. If location transformation is set, it will be applied");
cls_Select3D_SensitiveSegment.def("StartPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::StartPoint, "changes the start Point of the Segment;", py::arg("thePnt"));
cls_Select3D_SensitiveSegment.def("EndPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::EndPoint, "changes the end point of the segment", py::arg("thePnt"));

// Enums

}