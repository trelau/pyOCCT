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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_Drawer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <MeshVS_PrsBuilder.hxx>
#include <Standard_Type.hxx>
#include <MeshVS_Mesh.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <MeshVS_MeshPtr.hxx>

void bind_MeshVS_PrsBuilder(py::module &mod){

py::class_<MeshVS_PrsBuilder, opencascade::handle<MeshVS_PrsBuilder>, Standard_Transient> cls_MeshVS_PrsBuilder(mod, "MeshVS_PrsBuilder", "This class is parent for all builders using in MeshVS_Mesh. It provides base fields and methods all buildes need.");

// Fields

// Methods
cls_MeshVS_PrsBuilder.def("Build", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const) &MeshVS_PrsBuilder::Build, "Builds presentation of certain type of data. Prs is presentation object which this method constructs. IDs is set of numeric identificators forming object appearance. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. IsElement indicates, IDs is identificators of nodes or elements. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("CustomBuild", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const) &MeshVS_PrsBuilder::CustomBuild, "This method is called to build presentation of custom elements (they have MeshVS_ET_0D type). IDs is set of numeric identificators of elements for custom building. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("CustomSensitiveEntity", (opencascade::handle<SelectBasics_SensitiveEntity> (MeshVS_PrsBuilder::*)(const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Integer) const) &MeshVS_PrsBuilder::CustomSensitiveEntity, "This method is called to build sensitive of custom elements ( they have MeshVS_ET_0D type )", py::arg("Owner"), py::arg("SelectMode"));
cls_MeshVS_PrsBuilder.def("GetFlags", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetFlags, "Returns flags, assigned with builder during creation");
cls_MeshVS_PrsBuilder.def("TestFlags", (Standard_Boolean (MeshVS_PrsBuilder::*)(const Standard_Integer) const) &MeshVS_PrsBuilder::TestFlags, "Test whether display mode has flags assigned with this builder. This method has default implementation and can be redefined for advance behavior Returns Standard_True only if display mode is appropriate for this builder", py::arg("DisplayMode"));
cls_MeshVS_PrsBuilder.def("GetId", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetId, "Returns builder ID");
cls_MeshVS_PrsBuilder.def("GetPriority", (Standard_Integer (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetPriority, "Returns priority; as priority bigger, as soon builder will be called.");
cls_MeshVS_PrsBuilder.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetDataSource, "Returns custom data source or default ( from MeshVS_Mesh ) if custom is NULL");
cls_MeshVS_PrsBuilder.def("SetDataSource", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_PrsBuilder::SetDataSource, "Change custom data source", py::arg("newDS"));
cls_MeshVS_PrsBuilder.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetDrawer, "Returns custom drawer or default ( from MeshVS_Mesh ) if custom is NULL");
cls_MeshVS_PrsBuilder.def("SetDrawer", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_PrsBuilder::SetDrawer, "Change custom drawer", py::arg("newDr"));
cls_MeshVS_PrsBuilder.def("SetExcluding", (void (MeshVS_PrsBuilder::*)(const Standard_Boolean)) &MeshVS_PrsBuilder::SetExcluding, "Set excluding state. If it is Standard_True, the nodes or elements, processed by current builder will be noted and next builder won't process its.", py::arg("state"));
cls_MeshVS_PrsBuilder.def("IsExcludingOn", (Standard_Boolean (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::IsExcludingOn, "Read excluding state");
cls_MeshVS_PrsBuilder.def("SetPresentationManager", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &MeshVS_PrsBuilder::SetPresentationManager, "Set presentation manager for builder", py::arg("thePrsMgr"));
cls_MeshVS_PrsBuilder.def("GetPresentationManager", (opencascade::handle<PrsMgr_PresentationManager3d> (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::GetPresentationManager, "Get presentation manager of builder");
cls_MeshVS_PrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_PrsBuilder::get_type_name, "None");
cls_MeshVS_PrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_PrsBuilder::get_type_descriptor, "None");
cls_MeshVS_PrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_PrsBuilder::*)() const) &MeshVS_PrsBuilder::DynamicType, "None");

// Enums

}