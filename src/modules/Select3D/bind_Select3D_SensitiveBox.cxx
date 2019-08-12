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
#include <Select3D_SensitiveBox.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_BndBox3d.hxx>

void bind_Select3D_SensitiveBox(py::module &mod){

py::class_<Select3D_SensitiveBox, opencascade::handle<Select3D_SensitiveBox>, Select3D_SensitiveEntity> cls_Select3D_SensitiveBox(mod, "Select3D_SensitiveBox", "A framework to define selection by a sensitive box.");

// Constructors
cls_Select3D_SensitiveBox.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Bnd_Box &>(), py::arg("theOwnerId"), py::arg("theBox"));
cls_Select3D_SensitiveBox.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theOwnerId"), py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));

// Fields

// Methods
cls_Select3D_SensitiveBox.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveBox::get_type_name, "None");
cls_Select3D_SensitiveBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveBox::get_type_descriptor, "None");
cls_Select3D_SensitiveBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveBox::*)() const) &Select3D_SensitiveBox::DynamicType, "None");
cls_Select3D_SensitiveBox.def("NbSubElements", (Standard_Integer (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::NbSubElements, "Returns the amount of sub-entities in sensitive");
cls_Select3D_SensitiveBox.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::GetConnected, "None");
cls_Select3D_SensitiveBox.def("Matches", (Standard_Boolean (Select3D_SensitiveBox::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveBox::Matches, "Checks whether the box overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveBox.def("Box", (Bnd_Box (Select3D_SensitiveBox::*)() const) &Select3D_SensitiveBox::Box, "None");
cls_Select3D_SensitiveBox.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveBox::*)() const) &Select3D_SensitiveBox::CenterOfGeometry, "Returns center of the box. If location transformation is set, it will be applied");
cls_Select3D_SensitiveBox.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::BoundingBox, "Returns coordinates of the box. If location transformation is set, it will be applied");

// Enums

}