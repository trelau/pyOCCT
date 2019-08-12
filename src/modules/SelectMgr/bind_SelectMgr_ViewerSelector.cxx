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
#include <SelectMgr_ViewerSelector.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_SortCriterion.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <gp_Pnt.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <SelectMgr_StateOfSelection.hxx>
#include <SelectMgr_Selection.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_List.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <SelectMgr_SelectingVolumeManager.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <gp_GTrsf.hxx>
#include <SelectMgr_IndexedDataMapOfOwnerCriterion.hxx>
#include <SelectMgr_SelectableObjectSet.hxx>
#include <SelectMgr_ToleranceMap.hxx>
#include <NCollection_DataMap.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <gp_Dir.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_SelectMgr_ViewerSelector(py::module &mod){

py::class_<SelectMgr_ViewerSelector, opencascade::handle<SelectMgr_ViewerSelector>, Standard_Transient> cls_SelectMgr_ViewerSelector(mod, "SelectMgr_ViewerSelector", "A framework to define finding, sorting the sensitive primitives in a view. Services are also provided to define the return of the owners of those primitives selected. The primitives are sorted by criteria such as priority of the primitive or its depth in the view relative to that of other primitives. Note that in 3D, the inheriting framework StdSelect_ViewerSelector3d is only to be used if you do not want to use the services provided by AIS. Two tools are available to find and select objects found at a given position in the view. If you want to select the owners of all the objects detected at point x,y,z you use the Init - More - Next - Picked loop. If, on the other hand, you want to select only one object detected at that point, you use the Init - More - OnePicked loop. In this iteration, More is used to see if an object was picked and OnePicked, to get the object closest to the pick position. Viewer selectors are driven by SelectMgr_SelectionManager, and manipulate the SelectMgr_Selection objects given to them by the selection manager.");

// Constructors

// Fields

// Methods
cls_SelectMgr_ViewerSelector.def_static("get_type_name_", (const char * (*)()) &SelectMgr_ViewerSelector::get_type_name, "None");
cls_SelectMgr_ViewerSelector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_ViewerSelector::get_type_descriptor, "None");
cls_SelectMgr_ViewerSelector.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::DynamicType, "None");
cls_SelectMgr_ViewerSelector.def("Clear", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Clear, "Empties all the tables, removes all selections...");
cls_SelectMgr_ViewerSelector.def("Sensitivity", (Standard_Real (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::Sensitivity, "returns the Sensitivity of picking");
cls_SelectMgr_ViewerSelector.def("SortResult", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::SortResult, "Sorts the detected entites by priority and distance. to be redefined if other criterion are used...");
cls_SelectMgr_ViewerSelector.def("OnePicked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::OnePicked, "Returns the picked element with the highest priority, and which is the closest to the last successful mouse position.");
cls_SelectMgr_ViewerSelector.def("SetPickClosest", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::SetPickClosest, "Set preference of selecting one object for OnePicked() method: - If True, objects with less depth (distance fron the view plane) are preferred regardless of priority (priority is used then to choose among objects with similar depth), - If False, objects with higher priority are preferred regardless of the depth which is used to choose among objects of the same priority.", py::arg("theToPreferClosest"));
cls_SelectMgr_ViewerSelector.def("NbPicked", (Standard_Integer (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::NbPicked, "Returns the number of detected owners.");
cls_SelectMgr_ViewerSelector.def("ClearPicked", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::ClearPicked, "Clears picking results.");
cls_SelectMgr_ViewerSelector.def("Picked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)(const Standard_Integer) const) &SelectMgr_ViewerSelector::Picked, "Returns the entity Owner for the object picked at specified position.", py::arg("theRank"));
cls_SelectMgr_ViewerSelector.def("PickedData", (const SelectMgr_SortCriterion & (SelectMgr_ViewerSelector::*)(const Standard_Integer) const) &SelectMgr_ViewerSelector::PickedData, "Returns the Entity for the object picked at specified position.", py::arg("theRank"));
cls_SelectMgr_ViewerSelector.def("PickedEntity", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_ViewerSelector::*)(const Standard_Integer) const) &SelectMgr_ViewerSelector::PickedEntity, "Returns the Entity for the object picked at specified position.", py::arg("theRank"));
cls_SelectMgr_ViewerSelector.def("PickedPoint", (gp_Pnt (SelectMgr_ViewerSelector::*)(const Standard_Integer) const) &SelectMgr_ViewerSelector::PickedPoint, "Returns the 3D point (intersection of picking axis with the object nearest to eye) for the object picked at specified position.", py::arg("theRank"));
cls_SelectMgr_ViewerSelector.def("Contains", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const) &SelectMgr_ViewerSelector::Contains, "None", py::arg("theObject"));
cls_SelectMgr_ViewerSelector.def("EntitySetBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::EntitySetBuilder, "Returns the default builder used to construct BVH of entity set.");
cls_SelectMgr_ViewerSelector.def("SetEntitySetBuilder", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &SelectMgr_ViewerSelector::SetEntitySetBuilder, "Sets the default builder used to construct BVH of entity set. The new builder will be also assigned for already defined objects, but computed BVH trees will not be invalidated.", py::arg("theBuilder"));
cls_SelectMgr_ViewerSelector.def("Modes", [](SelectMgr_ViewerSelector &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, TColStd_ListOfInteger & a1) -> Standard_Boolean { return self.Modes(a0, a1); });
cls_SelectMgr_ViewerSelector.def("Modes", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, TColStd_ListOfInteger &, const SelectMgr_StateOfSelection) const) &SelectMgr_ViewerSelector::Modes, "Returns the list of selection modes ModeList found in this selector for the selectable object aSelectableObject. Returns true if aSelectableObject is referenced inside this selector; returns false if the object is not present in this selector.", py::arg("theSelectableObject"), py::arg("theModeList"), py::arg("theWantedState"));
cls_SelectMgr_ViewerSelector.def("IsActive", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer) const) &SelectMgr_ViewerSelector::IsActive, "Returns true if the selectable object aSelectableObject having the selection mode aMode is active in this selector.", py::arg("theSelectableObject"), py::arg("theMode"));
cls_SelectMgr_ViewerSelector.def("IsInside", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer) const) &SelectMgr_ViewerSelector::IsInside, "Returns true if the selectable object aSelectableObject having the selection mode aMode is in this selector.", py::arg("theSelectableObject"), py::arg("theMode"));
cls_SelectMgr_ViewerSelector.def("Status", (SelectMgr_StateOfSelection (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_Selection> &) const) &SelectMgr_ViewerSelector::Status, "Returns the selection status Status of the selection aSelection.", py::arg("theSelection"));
cls_SelectMgr_ViewerSelector.def("Status", (TCollection_AsciiString (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const) &SelectMgr_ViewerSelector::Status, "None", py::arg("theSelectableObject"));
cls_SelectMgr_ViewerSelector.def("ActiveOwners", (void (SelectMgr_ViewerSelector::*)(NCollection_List<opencascade::handle<SelectBasics_EntityOwner> > &) const) &SelectMgr_ViewerSelector::ActiveOwners, "Returns the list of active entity owners", py::arg("theOwners"));
cls_SelectMgr_ViewerSelector.def("AddSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::AddSelectableObject, "Adds new object to the map of selectable objects", py::arg("theObject"));
cls_SelectMgr_ViewerSelector.def("AddSelectionToObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_ViewerSelector::AddSelectionToObject, "Adds new selection to the object and builds its BVH tree", py::arg("theObject"), py::arg("theSelection"));
cls_SelectMgr_ViewerSelector.def("MoveSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::MoveSelectableObject, "Moves existing object from set of not transform persistence objects to set of transform persistence objects (or vice versa).", py::arg("theObject"));
cls_SelectMgr_ViewerSelector.def("RemoveSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::RemoveSelectableObject, "Removes selectable object from map of selectable ones", py::arg("theObject"));
cls_SelectMgr_ViewerSelector.def("RemoveSelectionOfObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_ViewerSelector::RemoveSelectionOfObject, "Removes selection of the object and marks its BVH tree for rebuild", py::arg("theObject"), py::arg("theSelection"));
cls_SelectMgr_ViewerSelector.def("RebuildObjectsTree", [](SelectMgr_ViewerSelector &self) -> void { return self.RebuildObjectsTree(); });
cls_SelectMgr_ViewerSelector.def("RebuildObjectsTree", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::RebuildObjectsTree, "Marks BVH of selectable objects for rebuild. Parameter theIsForce set as true guarantees that 1st level BVH for the viewer selector will be rebuilt during this call", py::arg("theIsForce"));
cls_SelectMgr_ViewerSelector.def("RebuildSensitivesTree", [](SelectMgr_ViewerSelector &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RebuildSensitivesTree(a0); });
cls_SelectMgr_ViewerSelector.def("RebuildSensitivesTree", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean)) &SelectMgr_ViewerSelector::RebuildSensitivesTree, "Marks BVH of sensitive entities of particular selectable object for rebuild. Parameter theIsForce set as true guarantees that 2nd level BVH for the object given will be rebuilt during this call", py::arg("theObject"), py::arg("theIsForce"));
cls_SelectMgr_ViewerSelector.def("GetManager", (SelectMgr_SelectingVolumeManager & (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::GetManager, "Returns instance of selecting volume manager of the viewer selector");
cls_SelectMgr_ViewerSelector.def("ResetSelectionActivationStatus", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::ResetSelectionActivationStatus, "Marks all added sensitive entities of all objects as non-selectable");
cls_SelectMgr_ViewerSelector.def("AllowOverlapDetection", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::AllowOverlapDetection, "Is used for rectangular selection only If theIsToAllow is false, only fully included sensitives will be detected, otherwise the algorithm will mark both included and overlapped entities as matched", py::arg("theIsToAllow"));
cls_SelectMgr_ViewerSelector.def("Init", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Init, "Begins an iteration scanning for the owners detected at a position in the view.");
cls_SelectMgr_ViewerSelector.def("More", (Standard_Boolean (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::More, "Continues the interation scanning for the owners detected at a position in the view, or continues the iteration scanning for the owner closest to the position in the view.");
cls_SelectMgr_ViewerSelector.def("Next", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Next, "Returns the next owner found in the iteration. This is a scan for the owners detected at a position in the view.");
cls_SelectMgr_ViewerSelector.def("Picked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::Picked, "Returns the current selected entity detected by the selector;");
cls_SelectMgr_ViewerSelector.def("InitDetected", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::InitDetected, "Initializes internal iterator for stored detected sensitive entities");
cls_SelectMgr_ViewerSelector.def("NextDetected", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::NextDetected, "Makes a step along the map of detected sensitive entities and their owners");
cls_SelectMgr_ViewerSelector.def("MoreDetected", (Standard_Boolean (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::MoreDetected, "Returns true if iterator of map of detected sensitive entities has reached its end");
cls_SelectMgr_ViewerSelector.def("DetectedEntity", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_ViewerSelector::*)() const) &SelectMgr_ViewerSelector::DetectedEntity, "Returns sensitive entity that was detected during the previous run of selection algorithm");

// Enums

}