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
#include <AIS_InteractiveObject.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <MeshVS_PrsBuilder.hxx>
#include <MeshVS_DataMapOfIntegerOwner.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_Drawer.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <MeshVS_MeshSelectionMethod.hxx>
#include <MeshVS_Mesh.hxx>
#include <Standard_Type.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <MeshVS_SequenceOfPrsBuilder.hxx>

void bind_MeshVS_Mesh(py::module &mod){

py::class_<MeshVS_Mesh, opencascade::handle<MeshVS_Mesh>, AIS_InteractiveObject> cls_MeshVS_Mesh(mod, "MeshVS_Mesh", "the main class provides interface to create mesh presentation as a whole");

// Constructors
cls_MeshVS_Mesh.def(py::init<>());
cls_MeshVS_Mesh.def(py::init<const Standard_Boolean>(), py::arg("theIsAllowOverlapped"));

// Fields

// Methods
cls_MeshVS_Mesh.def("AcceptDisplayMode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::AcceptDisplayMode, "Returns true for supported display modes basing on a list of defined builders.", py::arg("theMode"));
cls_MeshVS_Mesh.def("Compute", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &MeshVS_Mesh::Compute, "Computes presentation using builders added to sequence. Each builder computes own part of mesh presentation according to its type.", py::arg("PM"), py::arg("Prs"), py::arg("DisplayMode"));
cls_MeshVS_Mesh.def("ComputeSelection", (void (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &MeshVS_Mesh::ComputeSelection, "Computes selection according to SelectMode", py::arg("Sel"), py::arg("SelectMode"));
cls_MeshVS_Mesh.def("HilightSelected", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &MeshVS_Mesh::HilightSelected, "Draw selected owners presentation", py::arg("PM"), py::arg("Owners"));
cls_MeshVS_Mesh.def("HilightOwnerWithColor", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &MeshVS_Mesh::HilightOwnerWithColor, "Draw hilighted owner presentation", py::arg("thePM"), py::arg("theColor"), py::arg("theOwner"));
cls_MeshVS_Mesh.def("ClearSelected", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::ClearSelected, "Clears internal selection presentation");
cls_MeshVS_Mesh.def("GetBuildersCount", (Standard_Integer (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetBuildersCount, "How many builders there are in sequence");
cls_MeshVS_Mesh.def("GetBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::GetBuilder, "Returns builder by its index in sequence", py::arg("Index"));
cls_MeshVS_Mesh.def("GetBuilderById", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::GetBuilderById, "Returns builder by its ID", py::arg("Id"));
cls_MeshVS_Mesh.def("GetFreeId", (Standard_Integer (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetFreeId, "Returns the smallest positive ID, not occupied by any builder. This method using when builder is created with ID = -1");
cls_MeshVS_Mesh.def("AddBuilder", [](MeshVS_Mesh &self, const opencascade::handle<MeshVS_PrsBuilder> & a0) -> void { return self.AddBuilder(a0); });
cls_MeshVS_Mesh.def("AddBuilder", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &, const Standard_Boolean)) &MeshVS_Mesh::AddBuilder, "Adds builder to tale of sequence. PrsBuilder is builder to be added If TreatAsHilighter is true, MeshVS_Mesh will use this builder to create presentation of hilighted and selected owners. Only one builder can be hilighter, so that if you call this method with TreatAsHilighter = Standard_True some times, only last builder will be hilighter WARNING: As minimum one builder must be added as hilighter, otherwise selection cannot be computed", py::arg("Builder"), py::arg("TreatAsHilighter"));
cls_MeshVS_Mesh.def("SetHilighter", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_Mesh::SetHilighter, "Changes hilighter ( see above )", py::arg("Builder"));
cls_MeshVS_Mesh.def("SetHilighter", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighter, "Sets builder with sequence index 'Index' as hilighter", py::arg("Index"));
cls_MeshVS_Mesh.def("SetHilighterById", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighterById, "Sets builder with identificator 'Id' as hilighter", py::arg("Id"));
cls_MeshVS_Mesh.def("GetHilighter", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHilighter, "Returns hilighter");
cls_MeshVS_Mesh.def("RemoveBuilder", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilder, "Removes builder from sequence. If it is hilighter, hilighter will be NULL ( Don't remember to set it to other after!!! )", py::arg("Index"));
cls_MeshVS_Mesh.def("RemoveBuilderById", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilderById, "Removes builder with identificator Id", py::arg("Id"));
cls_MeshVS_Mesh.def("FindBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_CString) const) &MeshVS_Mesh::FindBuilder, "Finds builder by its type the string represents", py::arg("TypeString"));
cls_MeshVS_Mesh.def("GetOwnerMaps", (const MeshVS_DataMapOfIntegerOwner & (MeshVS_Mesh::*)(const Standard_Boolean)) &MeshVS_Mesh::GetOwnerMaps, "Returns map of owners.", py::arg("IsElement"));
cls_MeshVS_Mesh.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetDataSource, "Returns default builders' data source");
cls_MeshVS_Mesh.def("SetDataSource", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_Mesh::SetDataSource, "Sets default builders' data source", py::arg("aDataSource"));
cls_MeshVS_Mesh.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetDrawer, "Returns default builders' drawer");
cls_MeshVS_Mesh.def("SetDrawer", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Mesh::SetDrawer, "Sets default builders' drawer", py::arg("aDrawer"));
cls_MeshVS_Mesh.def("IsHiddenElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsHiddenElem, "Returns True if specified element is hidden By default no elements are hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsHiddenNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsHiddenNode, "Returns True if specified node is hidden. By default all nodes are hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsSelectableElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsSelectableElem, "Returns True if specified element is not hidden", py::arg("ID"));
cls_MeshVS_Mesh.def("IsSelectableNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const) &MeshVS_Mesh::IsSelectableNode, "Returns True if specified node is specified as selectable.", py::arg("ID"));
cls_MeshVS_Mesh.def("GetHiddenNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHiddenNodes, "Returns map of hidden nodes (may be null handle)");
cls_MeshVS_Mesh.def("SetHiddenNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenNodes, "Sets map of hidden nodes, which shall not be displayed individually. If nodes shared by some elements shall not be drawn, they should be included into that map", py::arg("Ids"));
cls_MeshVS_Mesh.def("GetHiddenElems", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetHiddenElems, "Returns map of hidden elements (may be null handle)");
cls_MeshVS_Mesh.def("SetHiddenElems", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenElems, "Sets map of hidden elements", py::arg("Ids"));
cls_MeshVS_Mesh.def("GetSelectableNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetSelectableNodes, "Returns map of selectable elements (may be null handle)");
cls_MeshVS_Mesh.def("SetSelectableNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetSelectableNodes, "Sets map of selectable nodes.", py::arg("Ids"));
cls_MeshVS_Mesh.def("UpdateSelectableNodes", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::UpdateSelectableNodes, "Automatically computes selectable nodes; the node is considered as being selectable if it is either not hidden, or is hidden but referred by at least one non-hidden element. Thus all nodes that are visible (either individually, or as ends or corners of elements) are selectable by default.");
cls_MeshVS_Mesh.def("GetMeshSelMethod", (MeshVS_MeshSelectionMethod (MeshVS_Mesh::*)() const) &MeshVS_Mesh::GetMeshSelMethod, "Returns set mesh selection method (see MeshVS.cdl)");
cls_MeshVS_Mesh.def("SetMeshSelMethod", (void (MeshVS_Mesh::*)(const MeshVS_MeshSelectionMethod)) &MeshVS_Mesh::SetMeshSelMethod, "Sets mesh selection method (see MeshVS.cdl)", py::arg("M"));
cls_MeshVS_Mesh.def("IsWholeMeshOwner", (Standard_Boolean (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &MeshVS_Mesh::IsWholeMeshOwner, "Returns True if the given owner represents a whole mesh.", py::arg("theOwner"));
cls_MeshVS_Mesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_Mesh::get_type_name, "None");
cls_MeshVS_Mesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Mesh::get_type_descriptor, "None");
cls_MeshVS_Mesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Mesh::*)() const) &MeshVS_Mesh::DynamicType, "None");

// Enums

}