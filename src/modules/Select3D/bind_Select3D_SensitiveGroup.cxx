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
#include <Select3D_SensitiveGroup.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_EntitySequence.hxx>
#include <Select3D_IndexedMapOfEntity.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <NCollection_Vector.hxx>

void bind_Select3D_SensitiveGroup(py::module &mod){

py::class_<Select3D_SensitiveGroup, opencascade::handle<Select3D_SensitiveGroup>, Select3D_SensitiveSet> cls_Select3D_SensitiveGroup(mod, "Select3D_SensitiveGroup", "A framework to define selection of a sensitive group by a sensitive entity which is a set of 3D sensitive entities. Remark: 2 modes are possible for rectangle selection the group is considered selected 1) when all the entities inside are selected in the rectangle 2) only one entity inside is selected by the rectangle By default the 'Match All entities' mode is set.");

// Constructors
cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theIsMustMatchAll"));
cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, Select3D_EntitySequence &>(), py::arg("theOwnerId"), py::arg("theEntities"));
cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, Select3D_EntitySequence &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theEntities"), py::arg("theIsMustMatchAll"));

// Fields

// Methods
cls_Select3D_SensitiveGroup.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveGroup::get_type_name, "None");
cls_Select3D_SensitiveGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveGroup::get_type_descriptor, "None");
cls_Select3D_SensitiveGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::DynamicType, "None");
cls_Select3D_SensitiveGroup.def("Entities", (const Select3D_IndexedMapOfEntity & (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::Entities, "Gets group content");
cls_Select3D_SensitiveGroup.def("SubEntity", (const opencascade::handle<Select3D_SensitiveEntity> & (Select3D_SensitiveGroup::*)(const Standard_Integer) const) &Select3D_SensitiveGroup::SubEntity, "Access entity by index [1, NbSubElements()].", py::arg("theIndex"));
cls_Select3D_SensitiveGroup.def("LastDetectedEntity", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::LastDetectedEntity, "Return last detected entity.");
cls_Select3D_SensitiveGroup.def("LastDetectedEntityIndex", (Standard_Integer (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::LastDetectedEntityIndex, "Return index of last detected entity.");
cls_Select3D_SensitiveGroup.def("Add", (void (Select3D_SensitiveGroup::*)(Select3D_EntitySequence &)) &Select3D_SensitiveGroup::Add, "Adds the list of sensitive entities LL to the empty sensitive group object created at construction time.", py::arg("theEntities"));
cls_Select3D_SensitiveGroup.def("Add", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveGroup::Add, "Adds the sensitive entity aSensitive to the non-empty sensitive group object created at construction time.", py::arg("theSensitive"));
cls_Select3D_SensitiveGroup.def("Remove", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveGroup::Remove, "None", py::arg("theSensitive"));
cls_Select3D_SensitiveGroup.def("Clear", (void (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::Clear, "Removes all sensitive entities from the list used at the time of construction, or added using the function Add.");
cls_Select3D_SensitiveGroup.def("IsIn", (Standard_Boolean (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &) const) &Select3D_SensitiveGroup::IsIn, "Returns true if the sensitive entity aSensitive is in the list used at the time of construction, or added using the function Add.", py::arg("theSensitive"));
cls_Select3D_SensitiveGroup.def("SetMatchType", (void (Select3D_SensitiveGroup::*)(const Standard_Boolean)) &Select3D_SensitiveGroup::SetMatchType, "Sets the requirement that all sensitive entities in the list used at the time of construction, or added using the function Add must be matched.", py::arg("theIsMustMatchAll"));
cls_Select3D_SensitiveGroup.def("MustMatchAll", (Standard_Boolean (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::MustMatchAll, "Returns true if all sensitive entities in the list used at the time of construction, or added using the function Add must be matched.");
cls_Select3D_SensitiveGroup.def("ToCheckOverlapAll", (Standard_Boolean (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::ToCheckOverlapAll, "Returns TRUE if all sensitive entities should be checked within rectangular/polygonal selection, FALSE by default. Can be useful for sensitive entities holding detection results as class property.");
cls_Select3D_SensitiveGroup.def("SetCheckOverlapAll", (void (Select3D_SensitiveGroup::*)(Standard_Boolean)) &Select3D_SensitiveGroup::SetCheckOverlapAll, "Returns TRUE if all sensitive entities should be checked within rectangular/polygonal selection, FALSE by default. Can be useful for sensitive entities holding detection results as class property.", py::arg("theToCheckAll"));
cls_Select3D_SensitiveGroup.def("Matches", (Standard_Boolean (Select3D_SensitiveGroup::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveGroup::Matches, "Checks whether the group overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_Select3D_SensitiveGroup.def("NbSubElements", (Standard_Integer (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::NbSubElements, "Returns the amount of sub-entities");
cls_Select3D_SensitiveGroup.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::GetConnected, "None");
cls_Select3D_SensitiveGroup.def("Set", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitiveGroup::Set, "Sets the owner for all entities in group", py::arg("theOwnerId"));
cls_Select3D_SensitiveGroup.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::BoundingBox, "Returns bounding box of the group. If location transformation is set, it will be applied");
cls_Select3D_SensitiveGroup.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::CenterOfGeometry, "Returns center of entity set. If location transformation is set, it will be applied");
cls_Select3D_SensitiveGroup.def("Box", (Select3D_BndBox3d (Select3D_SensitiveGroup::*)(const Standard_Integer) const) &Select3D_SensitiveGroup::Box, "Returns bounding box of sensitive entity with index theIdx", py::arg("theIdx"));
cls_Select3D_SensitiveGroup.def("Center", (Standard_Real (Select3D_SensitiveGroup::*)(const Standard_Integer, const Standard_Integer) const) &Select3D_SensitiveGroup::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
cls_Select3D_SensitiveGroup.def("Swap", (void (Select3D_SensitiveGroup::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveGroup::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
cls_Select3D_SensitiveGroup.def("Size", (Standard_Integer (Select3D_SensitiveGroup::*)() const) &Select3D_SensitiveGroup::Size, "Returns the length of vector of sensitive entities");

// Enums

}