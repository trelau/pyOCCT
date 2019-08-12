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
#include <gp_Pnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <Select3D_SensitiveTriangle.hxx>
#include <Standard_Type.hxx>

void bind_Select3D_SensitiveTriangle(py::module &mod){

py::class_<Select3D_SensitiveTriangle, opencascade::handle<Select3D_SensitiveTriangle>, Select3D_SensitiveEntity> cls_Select3D_SensitiveTriangle(mod, "Select3D_SensitiveTriangle", "A framework to define selection of triangles in a view. This comes into play in the detection of meshing and triangulation in surfaces. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");

// Constructors
cls_Select3D_SensitiveTriangle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"));
cls_Select3D_SensitiveTriangle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theType"));

// Fields

// Methods
cls_Select3D_SensitiveTriangle.def("Matches", (Standard_Boolean (Select3D_SensitiveTriangle::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveTriangle::Matches, "Checks whether the triangle overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveTriangle.def("Points3D", (void (Select3D_SensitiveTriangle::*)(gp_Pnt &, gp_Pnt &, gp_Pnt &) const) &Select3D_SensitiveTriangle::Points3D, "Returns the 3D points P1, P2, P3 used at the time of construction.", py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"));
cls_Select3D_SensitiveTriangle.def("Center3D", (gp_Pnt (Select3D_SensitiveTriangle::*)() const) &Select3D_SensitiveTriangle::Center3D, "Returns the center point of the sensitive triangle created at construction time.");
cls_Select3D_SensitiveTriangle.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::GetConnected, "Returns the copy of this");
cls_Select3D_SensitiveTriangle.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::BoundingBox, "Returns bounding box of the triangle. If location transformation is set, it will be applied");
cls_Select3D_SensitiveTriangle.def("NbSubElements", (Standard_Integer (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::NbSubElements, "Returns the amount of points");
cls_Select3D_SensitiveTriangle.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveTriangle::*)() const) &Select3D_SensitiveTriangle::CenterOfGeometry, "None");
cls_Select3D_SensitiveTriangle.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveTriangle::get_type_name, "None");
cls_Select3D_SensitiveTriangle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveTriangle::get_type_descriptor, "None");
cls_Select3D_SensitiveTriangle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveTriangle::*)() const) &Select3D_SensitiveTriangle::DynamicType, "None");

// Enums

}