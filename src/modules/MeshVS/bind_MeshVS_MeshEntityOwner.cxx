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
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_SOPtr.hxx>
#include <Standard_TypeDef.hxx>
#include <MeshVS_EntityType.hxx>
#include <Standard_Handle.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <MeshVS_MeshEntityOwner.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_MeshEntityOwner(py::module &mod){

py::class_<MeshVS_MeshEntityOwner, opencascade::handle<MeshVS_MeshEntityOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshEntityOwner(mod, "MeshVS_MeshEntityOwner", "The custom owner. This class provides methods to store owner information: 1) An address of element or node data structure 2) Type of node or element owner assigned 3) ID of node or element owner assigned");

// Constructors
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"));
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"));
cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer, const Standard_Boolean>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"), py::arg("IsGroup"));

// Fields

// Methods
cls_MeshVS_MeshEntityOwner.def("Owner", (Standard_Address (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::Owner, "Returns an address of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("Type", (MeshVS_EntityType (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::Type, "Returns type of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("ID", (Standard_Integer (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::ID, "Returns ID of element or node data structure");
cls_MeshVS_MeshEntityOwner.def("IsGroup", (Standard_Boolean (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::IsGroup, "Returns true if owner represents group of nodes or elements");
cls_MeshVS_MeshEntityOwner.def("IsHilighted", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_MeshVS_MeshEntityOwner.def("IsHilighted", (Standard_Boolean (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &MeshVS_MeshEntityOwner::IsHilighted, "Returns true if owner is hilighted", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def("HilightWithColor", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_MeshVS_MeshEntityOwner.def("HilightWithColor", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::HilightWithColor, "Hilights owner with the certain color", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_MeshVS_MeshEntityOwner.def("Unhilight", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_MeshVS_MeshEntityOwner.def("Unhilight", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Unhilight, "Strip hilight of owner", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def("Clear", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); });
cls_MeshVS_MeshEntityOwner.def("Clear", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Clear, "None", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshEntityOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshEntityOwner::get_type_name, "None");
cls_MeshVS_MeshEntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshEntityOwner::get_type_descriptor, "None");
cls_MeshVS_MeshEntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshEntityOwner::*)() const) &MeshVS_MeshEntityOwner::DynamicType, "None");

// Enums

}