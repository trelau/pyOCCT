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
#include <BVH_PrimitiveSet3d.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_SensitiveEntitySet.hxx>
#include <Standard_Type.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <SelectMgr_SensitiveEntity.hxx>
#include <SelectMgr_Selection.hxx>
#include <Select3D_BndBox3d.hxx>
#include <Standard_TypeDef.hxx>

void bind_SelectMgr_SensitiveEntitySet(py::module &mod){

py::class_<SelectMgr_SensitiveEntitySet, opencascade::handle<SelectMgr_SensitiveEntitySet>, BVH_PrimitiveSet3d> cls_SelectMgr_SensitiveEntitySet(mod, "SelectMgr_SensitiveEntitySet", "This class is used to store all calculated sensitive entites of one selectable object. It provides an interface for building BVH tree which is used to speed-up the performance of searching for overlap among sensitives of one selectable object");

// Constructors
cls_SelectMgr_SensitiveEntitySet.def(py::init<const opencascade::handle<Select3D_BVHBuilder3d> &>(), py::arg("theBuilder"));

// Fields

// Methods
cls_SelectMgr_SensitiveEntitySet.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SensitiveEntitySet::get_type_name, "None");
cls_SelectMgr_SensitiveEntitySet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SensitiveEntitySet::get_type_descriptor, "None");
cls_SelectMgr_SensitiveEntitySet.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SensitiveEntitySet::*)() const) &SelectMgr_SensitiveEntitySet::DynamicType, "None");
cls_SelectMgr_SensitiveEntitySet.def("Append", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_SensitiveEntity> &)) &SelectMgr_SensitiveEntitySet::Append, "Adds new entity to the set and marks BVH tree for rebuild", py::arg("theEntity"));
cls_SelectMgr_SensitiveEntitySet.def("Append", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SensitiveEntitySet::Append, "Adds every entity of selection theSelection to the set and marks BVH tree for rebuild", py::arg("theSelection"));
cls_SelectMgr_SensitiveEntitySet.def("Remove", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SensitiveEntitySet::Remove, "Removes every entity of selection theSelection from the set and marks BVH tree for rebuild", py::arg("theSelection"));
cls_SelectMgr_SensitiveEntitySet.def("Box", (Select3D_BndBox3d (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer) const) &SelectMgr_SensitiveEntitySet::Box, "Returns bounding box of entity with index theIdx", py::arg("theIndex"));
cls_SelectMgr_SensitiveEntitySet.def("Center", (Standard_Real (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer, const Standard_Integer) const) &SelectMgr_SensitiveEntitySet::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIndex"), py::arg("theAxis"));
cls_SelectMgr_SensitiveEntitySet.def("Swap", (void (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_SensitiveEntitySet::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIndex1"), py::arg("theIndex2"));
cls_SelectMgr_SensitiveEntitySet.def("Size", (Standard_Integer (SelectMgr_SensitiveEntitySet::*)() const) &SelectMgr_SensitiveEntitySet::Size, "Returns the amount of entities");
cls_SelectMgr_SensitiveEntitySet.def("GetSensitiveById", (const opencascade::handle<SelectMgr_SensitiveEntity> & (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer) const) &SelectMgr_SensitiveEntitySet::GetSensitiveById, "Returns the entity with index theIndex in the set", py::arg("theIndex"));
cls_SelectMgr_SensitiveEntitySet.def("Sensitives", (const SelectMgr_IndexedMapOfHSensitive & (SelectMgr_SensitiveEntitySet::*)() const) &SelectMgr_SensitiveEntitySet::Sensitives, "Returns map of entities.");

// Enums

}