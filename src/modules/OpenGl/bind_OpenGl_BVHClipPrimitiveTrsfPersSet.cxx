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
#include <BVH_Set.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <Standard_Handle.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <OpenGl_Structure.hxx>
#include <NCollection_IndexedMap.hxx>
#include <BVH_Tree.hxx>
#include <Graphic3d_Camera.hxx>
#include <OpenGl_Vec.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <OpenGl_BVHClipPrimitiveTrsfPersSet.hxx>

void bind_OpenGl_BVHClipPrimitiveTrsfPersSet(py::module &mod){

/*
py::class_<OpenGl_BVHClipPrimitiveTrsfPersSet, std::unique_ptr<OpenGl_BVHClipPrimitiveTrsfPersSet, Deleter<OpenGl_BVHClipPrimitiveTrsfPersSet>>, BVH_Set<Standard_Real, 3>> cls_OpenGl_BVHClipPrimitiveTrsfPersSet(mod, "OpenGl_BVHClipPrimitiveTrsfPersSet", "Set of transformation persistent OpenGl_Structure for building BVH tree. Provides built-in mechanism to invalidate tree when world view projection state changes. Due to frequent invalidation of BVH tree the choice of BVH tree builder is made in favor of BVH linear builder (quick rebuild).");

// Constructors
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def(py::init<const opencascade::handle<Select3D_BVHBuilder3d> &>(), py::arg("theBuilder"));

// Fields

// Methods
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Size", (Standard_Integer (OpenGl_BVHClipPrimitiveTrsfPersSet::*)() const) &OpenGl_BVHClipPrimitiveTrsfPersSet::Size, "Returns total number of structures.");
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Box", (Graphic3d_BndBox3d (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const Standard_Integer) const) &OpenGl_BVHClipPrimitiveTrsfPersSet::Box, "Returns AABB of the structure.", py::arg("theIdx"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Center", (Standard_Real (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_BVHClipPrimitiveTrsfPersSet::Center, "Calculates center of the AABB along given axis.", py::arg("theIdx"), py::arg("theAxis"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Swap", (void (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_BVHClipPrimitiveTrsfPersSet::Swap, "Swaps structures with the given indices.", py::arg("theIdx1"), py::arg("theIdx2"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Add", (Standard_Boolean (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const OpenGl_Structure *)) &OpenGl_BVHClipPrimitiveTrsfPersSet::Add, "Adds structure to the set.", py::arg("theStruct"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Remove", (Standard_Boolean (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const OpenGl_Structure *)) &OpenGl_BVHClipPrimitiveTrsfPersSet::Remove, "Removes the given structure from the set.", py::arg("theStruct"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Clear", (void (OpenGl_BVHClipPrimitiveTrsfPersSet::*)()) &OpenGl_BVHClipPrimitiveTrsfPersSet::Clear, "Cleans the whole primitive set.");
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("GetStructureById", (const OpenGl_Structure * (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(Standard_Integer)) &OpenGl_BVHClipPrimitiveTrsfPersSet::GetStructureById, "Returns the structure corresponding to the given ID.", py::arg("theId"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Structures", (const NCollection_IndexedMap<const OpenGl_Structure *> & (OpenGl_BVHClipPrimitiveTrsfPersSet::*)() const) &OpenGl_BVHClipPrimitiveTrsfPersSet::Structures, "Access directly a collection of structures.");
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("MarkDirty", (void (OpenGl_BVHClipPrimitiveTrsfPersSet::*)()) &OpenGl_BVHClipPrimitiveTrsfPersSet::MarkDirty, "Marks object state as outdated (needs BVH rebuilding).");
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("BVH", (const opencascade::handle<BVH_Tree<Standard_Real, 3> > & (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const opencascade::handle<Graphic3d_Camera> &, const OpenGl_Mat4d &, const OpenGl_Mat4d &, const Standard_Integer, const Standard_Integer, const Graphic3d_WorldViewProjState &)) &OpenGl_BVHClipPrimitiveTrsfPersSet::BVH, "Returns BVH tree for the given world view projection (builds it if necessary).", py::arg("theCamera"), py::arg("theProjectionMatrix"), py::arg("theWorldViewMatrix"), py::arg("theViewportWidth"), py::arg("theViewportHeight"), py::arg("theWVPState"));
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("Builder", (const opencascade::handle<Select3D_BVHBuilder3d> & (OpenGl_BVHClipPrimitiveTrsfPersSet::*)() const) &OpenGl_BVHClipPrimitiveTrsfPersSet::Builder, "Returns builder for bottom-level BVH.");
cls_OpenGl_BVHClipPrimitiveTrsfPersSet.def("SetBuilder", (void (OpenGl_BVHClipPrimitiveTrsfPersSet::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &OpenGl_BVHClipPrimitiveTrsfPersSet::SetBuilder, "Assigns builder for bottom-level BVH.", py::arg("theBuilder"));

// Enums
*/

}