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
#include <Select3D_SensitiveSet.hxx>
#include <Standard_Type.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BndBox3d.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <gp_Pnt.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <BVH_Tree.hxx>

void bind_Select3D_SensitiveSet(py::module &mod){

py::class_<Select3D_SensitiveSet, opencascade::handle<Select3D_SensitiveSet>, Select3D_SensitiveEntity> cls_Select3D_SensitiveSet(mod, "Select3D_SensitiveSet", "This class is base class for handling overlap detection of complex sensitive entities. It provides an interface for building BVH tree for some set of entities. Thereby, each iteration of overlap detection is a traverse of BVH tree in fact. To use speed-up hierarchical structure in a custom complex sensitive entity, it is necessary to make that custom entity a descendant of this class and organize sub-entities in some container which allows referencing to elements by index. Note that methods taking index as a parameter are used for BVH build and the range of given index is [0; Size() - 1]. For example of usage see Select3D_SensitiveTriangulation.");

// Fields

// Methods
cls_Select3D_SensitiveSet.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveSet::get_type_name, "None");
cls_Select3D_SensitiveSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveSet::get_type_descriptor, "None");
cls_Select3D_SensitiveSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveSet::*)() const) &Select3D_SensitiveSet::DynamicType, "None");
cls_Select3D_SensitiveSet.def_static("DefaultBVHBuilder_", (const opencascade::handle<Select3D_BVHBuilder3d> & (*)()) &Select3D_SensitiveSet::DefaultBVHBuilder, "Return global instance to default BVH builder.");
cls_Select3D_SensitiveSet.def_static("SetDefaultBVHBuilder_", (void (*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &Select3D_SensitiveSet::SetDefaultBVHBuilder, "Assign new BVH builder to be used by default for new sensitive sets (assigning is NOT thread-safe!).", py::arg("theBuilder"));
cls_Select3D_SensitiveSet.def("Size", (Standard_Integer (Select3D_SensitiveSet::*)() const) &Select3D_SensitiveSet::Size, "Returns the amount of sub-entities of the complex entity");
cls_Select3D_SensitiveSet.def("Box", (Select3D_BndBox3d (Select3D_SensitiveSet::*)(const Standard_Integer) const) &Select3D_SensitiveSet::Box, "Returns bounding box of sub-entity with index theIdx in sub-entity list", py::arg("theIdx"));
cls_Select3D_SensitiveSet.def("Center", (Standard_Real (Select3D_SensitiveSet::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitiveSet::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitiveSet.def("Swap", (void (Select3D_SensitiveSet::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveSet::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_SensitiveSet.def("Matches", (Standard_Boolean (Select3D_SensitiveSet::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveSet::Matches, "Checks whether one or more entities of the set overlap current selecting volume. Implements the traverse of BVH tree built for the set", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveSet.def("BVH", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::BVH, "Builds BVH tree for sensitive set. Must be called manually to build BVH tree for any sensitive set in case if its content was initialized not in a constructor, but element by element");
cls_Select3D_SensitiveSet.def("SetBuilder", (void (Select3D_SensitiveSet::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &Select3D_SensitiveSet::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));
cls_Select3D_SensitiveSet.def("MarkDirty", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::MarkDirty, "Marks BVH tree of the set as outdated. It will be rebuild at the next call of BVH()");
cls_Select3D_SensitiveSet.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::BoundingBox, "Returns bounding box of the whole set. This method should be redefined in Select3D_SensitiveSet descendants");
cls_Select3D_SensitiveSet.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveSet::*)() const) &Select3D_SensitiveSet::CenterOfGeometry, "Returns center of the whole set. This method should be redefined in Select3D_SensitiveSet descendants");
cls_Select3D_SensitiveSet.def("Clear", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::Clear, "Destroys cross-reference to avoid memory leak");
cls_Select3D_SensitiveSet.def("GetLeafNodeSize", (Standard_Integer (Select3D_SensitiveSet::*)() const) &Select3D_SensitiveSet::GetLeafNodeSize, "Returns a number of nodes in 1 BVH leaf");

// Enums

}