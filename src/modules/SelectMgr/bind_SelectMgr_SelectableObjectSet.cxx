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
#include <NCollection_IndexedMap.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_SelectableObjectSet.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <BVH_Tree.hxx>
#include <Select3D_BVHBuilder3d.hxx>

void bind_SelectMgr_SelectableObjectSet(py::module &mod){

py::class_<SelectMgr_SelectableObjectSet> cls_SelectMgr_SelectableObjectSet(mod, "SelectMgr_SelectableObjectSet", "The purpose of this class is to organize all selectable objects into data structure, allowing to build set of BVH trees for each transformation persistence subclass of selectable objects. This allow to minify number of updates for BVH trees - for example 2D persistent object subclass depends only on camera's projection and the corresponding BVH tree needs to be updated when camera's projection parameters change, while another tree for non-persistent objects can be left unchanged in this case.");

// Constructors
cls_SelectMgr_SelectableObjectSet.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_SelectableObjectSet.def("Append", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::Append, "Adds the new selectable object to the set. The selectable object is placed into one of the predefined subsets depending on its persistence type. After adding an object, this method marks the corresponding BVH tree for rebuild.", py::arg("theObject"));
cls_SelectMgr_SelectableObjectSet.def("Remove", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::Remove, "Removes the selectable object from the set. The selectable object is removed from the subset it has been placed into. After removing an object, this method marks the corresponding BVH tree for rebuild.", py::arg("theObject"));
cls_SelectMgr_SelectableObjectSet.def("ChangeSubset", (void (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::ChangeSubset, "Performs necessary updates when object's persistence types changes. This method should be called right after changing transformation persistence flags of the objects and before updating BVH tree - to provide up-to-date state of the object set.", py::arg("theObject"));
cls_SelectMgr_SelectableObjectSet.def("UpdateBVH", (void (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<Graphic3d_Camera> &, const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Graphic3d_WorldViewProjState &, const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectableObjectSet::UpdateBVH, "Updates outdated BVH trees and remembers the last state of the camera view-projection matrices and viewport (window) dimensions.", py::arg("theCamera"), py::arg("theProjectionMat"), py::arg("theWorldViewMat"), py::arg("theViewState"), py::arg("theViewportWidth"), py::arg("theViewportHeight"));
cls_SelectMgr_SelectableObjectSet.def("MarkDirty", (void (SelectMgr_SelectableObjectSet::*)()) &SelectMgr_SelectableObjectSet::MarkDirty, "Marks every BVH subset for update.");
cls_SelectMgr_SelectableObjectSet.def("Contains", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const) &SelectMgr_SelectableObjectSet::Contains, "Returns true if this objects set contains theObject given.", py::arg("theObject"));
cls_SelectMgr_SelectableObjectSet.def("IsEmpty", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)() const) &SelectMgr_SelectableObjectSet::IsEmpty, "Returns true if the object set does not contain any selectable objects.");
cls_SelectMgr_SelectableObjectSet.def("IsEmpty", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset) const) &SelectMgr_SelectableObjectSet::IsEmpty, "Returns true if the specified object subset is empty.", py::arg("theSubset"));
cls_SelectMgr_SelectableObjectSet.def("GetObjectById", (const opencascade::handle<SelectMgr_SelectableObject> & (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset, const Standard_Integer) const) &SelectMgr_SelectableObjectSet::GetObjectById, "Returns object from subset theSubset by theIndex given. The method allows to get selectable object referred by the index of an element of the subset's BVH tree.", py::arg("theSubset"), py::arg("theIndex"));
cls_SelectMgr_SelectableObjectSet.def("BVH", (const opencascade::handle<BVH_Tree<Standard_Real, 3> > & (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset) const) &SelectMgr_SelectableObjectSet::BVH, "Returns computed BVH for the theSubset given.", py::arg("theSubset"));

// Enums
py::enum_<SelectMgr_SelectableObjectSet::BVHSubset>(cls_SelectMgr_SelectableObjectSet, "BVHSubset", "This enumeration declares names for subsets of selectable objects. Each subset has independent BVH tree. The class maintains subsets of selectable objects by their persistence flag. This allows to restric rebuilding of the trees for particular subset when the camera change does not implicitly require it: - BVHSubset_3d refers to the subset of normal world-space 3D objects. Associated BVH tree does not depend on the camera's state at all. This subset uses binned BVH builder with 32 bins and 1 element per leaf. - BVHSubset_3dPersistent refers to the subset of 3D persistent selectable objects (rotate, pan, zoom persistence). Associated BVH tree needs to be updated when either the camera's projection and position change. This subset uses linear BVH builder with 32 levels of depth and 1 element per leaf. - BVHSubset_2dPersistent refers to the subset of 2D persistent selectable objects. Associated BVH tree needs to be updated only when camera's projection changes. Bounding volumes for this object subclass is represented directly in eye space coordinates. This subset uses linear BVH builder with 32 levels of depth and 1 element per leaf.")
	.value("BVHSubset_3d", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_3d)
	.value("BVHSubset_3dPersistent", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_3dPersistent)
	.value("BVHSubset_2dPersistent", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_2dPersistent)
	.value("BVHSubsetNb", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubsetNb)
	.export_values();

}