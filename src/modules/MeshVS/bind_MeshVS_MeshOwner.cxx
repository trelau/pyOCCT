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
#include <Standard_Handle.hxx>
#include <MeshVS_DataSource.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <MeshVS_MeshOwner.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_MeshOwner(py::module &mod){

py::class_<MeshVS_MeshOwner, opencascade::handle<MeshVS_MeshOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshOwner(mod, "MeshVS_MeshOwner", "The custom mesh owner used for advanced mesh selection. This class provides methods to store information: 1) IDs of hilighted mesh nodes and elements 2) IDs of mesh nodes and elements selected on the mesh");

// Constructors
cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("theSelObj"), py::arg("theDS"));
cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("theSelObj"), py::arg("theDS"), py::arg("thePriority"));

// Fields

// Methods
cls_MeshVS_MeshOwner.def("GetDataSource", (const opencascade::handle<MeshVS_DataSource> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDataSource, "None");
cls_MeshVS_MeshOwner.def("GetSelectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetSelectedNodes, "Returns ids of selected mesh nodes");
cls_MeshVS_MeshOwner.def("GetSelectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetSelectedElements, "Returns ids of selected mesh elements");
cls_MeshVS_MeshOwner.def("AddSelectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::AddSelectedEntities, "Saves ids of selected mesh entities", py::arg("Nodes"), py::arg("Elems"));
cls_MeshVS_MeshOwner.def("ClearSelectedEntities", (void (MeshVS_MeshOwner::*)()) &MeshVS_MeshOwner::ClearSelectedEntities, "Clears ids of selected mesh entities");
cls_MeshVS_MeshOwner.def("GetDetectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDetectedNodes, "Returns ids of hilighted mesh nodes");
cls_MeshVS_MeshOwner.def("GetDetectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::GetDetectedElements, "Returns ids of hilighted mesh elements");
cls_MeshVS_MeshOwner.def("SetDetectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::SetDetectedEntities, "Saves ids of hilighted mesh entities", py::arg("Nodes"), py::arg("Elems"));
cls_MeshVS_MeshOwner.def("HilightWithColor", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_MeshVS_MeshOwner.def("HilightWithColor", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theColor"), py::arg("theMode"));
cls_MeshVS_MeshOwner.def("Unhilight", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_MeshVS_MeshOwner.def("Unhilight", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshOwner::Unhilight, "None", py::arg("PM"), py::arg("Mode"));
cls_MeshVS_MeshOwner.def("IsForcedHilight", (Standard_Boolean (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::IsForcedHilight, "None");
cls_MeshVS_MeshOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshOwner::get_type_name, "None");
cls_MeshVS_MeshOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshOwner::get_type_descriptor, "None");
cls_MeshVS_MeshOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshOwner::*)() const) &MeshVS_MeshOwner::DynamicType, "None");

// Enums

}