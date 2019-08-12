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
#include <SelectBasics_EntityOwner.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Vector.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <Select3D_SensitiveWire.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>

void bind_Select3D_SensitiveWire(py::module &mod){

py::class_<Select3D_SensitiveWire, opencascade::handle<Select3D_SensitiveWire>, Select3D_SensitiveSet> cls_Select3D_SensitiveWire(mod, "Select3D_SensitiveWire", "A framework to define selection of a wire owner by an elastic wire band.");

// Constructors
cls_Select3D_SensitiveWire.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));

// Fields

// Methods
cls_Select3D_SensitiveWire.def("Add", (void (Select3D_SensitiveWire::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveWire::Add, "Adds the sensitive entity theSensitive to this framework.", py::arg("theSensitive"));
cls_Select3D_SensitiveWire.def("NbSubElements", (Standard_Integer (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::NbSubElements, "Returns the amount of sub-entities");
cls_Select3D_SensitiveWire.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::GetConnected, "None");
cls_Select3D_SensitiveWire.def("GetEdges", (const NCollection_Vector<opencascade::handle<Select3D_SensitiveEntity> > & (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::GetEdges, "returns the sensitive edges stored in this wire");
cls_Select3D_SensitiveWire.def("Set", (void (Select3D_SensitiveWire::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitiveWire::Set, "Sets the owner for all entities in wire", py::arg("theOwnerId"));
cls_Select3D_SensitiveWire.def("GetLastDetected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveWire::*)() const) &Select3D_SensitiveWire::GetLastDetected, "None");
cls_Select3D_SensitiveWire.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::BoundingBox, "Returns bounding box of the wire. If location transformation is set, it will be applied");
cls_Select3D_SensitiveWire.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveWire::*)() const) &Select3D_SensitiveWire::CenterOfGeometry, "Returns center of the wire. If location transformation is set, it will be applied");
cls_Select3D_SensitiveWire.def("Size", (Standard_Integer (Select3D_SensitiveWire::*)() const) &Select3D_SensitiveWire::Size, "Returns the length of vector of sensitive entities");
cls_Select3D_SensitiveWire.def("Box", (Select3D_BndBox3d (Select3D_SensitiveWire::*)(const Standard_Integer) const) &Select3D_SensitiveWire::Box, "Returns bounding box of sensitive entity with index theIdx", py::arg("theIdx"));
cls_Select3D_SensitiveWire.def("Center", (Standard_Real (Select3D_SensitiveWire::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitiveWire::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitiveWire.def("Swap", (void (Select3D_SensitiveWire::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveWire::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_SensitiveWire.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveWire::get_type_name, "None");
cls_Select3D_SensitiveWire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveWire::get_type_descriptor, "None");
cls_Select3D_SensitiveWire.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveWire::*)() const) &Select3D_SensitiveWire::DynamicType, "None");

// Enums

}