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
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_ViewerSelector.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_TypeOfUpdate.hxx>
#include <SelectMgr_Selection.hxx>
#include <NCollection_Map.hxx>
#include <SelectMgr_DataMapOfObjectSelectors.hxx>

void bind_SelectMgr_SelectionManager(py::module &mod){

py::class_<SelectMgr_SelectionManager, opencascade::handle<SelectMgr_SelectionManager>, Standard_Transient> cls_SelectMgr_SelectionManager(mod, "SelectMgr_SelectionManager", "A framework to manage selection from the point of view of viewer selectors. These can be added and removed, and selection modes can be activated and deactivated. In addition, objects may be known to all selectors or only to some.");

// Constructors
cls_SelectMgr_SelectionManager.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_SelectionManager.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SelectionManager::get_type_name, "None");
cls_SelectMgr_SelectionManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SelectionManager::get_type_descriptor, "None");
cls_SelectMgr_SelectionManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SelectionManager::*)() const) &SelectMgr_SelectionManager::DynamicType, "None");
cls_SelectMgr_SelectionManager.def("Add", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Add, "Adds the viewer selector theSelector to the list of known items.", py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Remove, "Removes viewer selector theSelector from the list of known items.", py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("Contains", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &) const) &SelectMgr_SelectionManager::Contains, "Returns true if the manager contains the viewer selector theSelector in a list of known items.", py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("Contains", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const) &SelectMgr_SelectionManager::Contains, "Returns true if the manager contains the selectable object theObject.", py::arg("theObject"));
cls_SelectMgr_SelectionManager.def("Load", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Load(a0); });
cls_SelectMgr_SelectionManager.def("Load", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer)) &SelectMgr_SelectionManager::Load, "Loads and computes selection mode theMode (if it is not equal to -1) in global context and adds selectable object to BVH tree. If the object theObject has an already calculated selection with mode theMode and it was removed, the selection will be recalculated.", py::arg("theObject"), py::arg("theMode"));
cls_SelectMgr_SelectionManager.def("Load", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const opencascade::handle<SelectMgr_ViewerSelector> & a1) -> void { return self.Load(a0, a1); });
cls_SelectMgr_SelectionManager.def("Load", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &, const Standard_Integer)) &SelectMgr_SelectionManager::Load, "Loads and computes selection mode theMode (if it is not equal to -1) and adds selectable object to BVH tree. Does not perform check of existence of theObject in global context before addition, but adds theSelector to local context.", py::arg("theObject"), py::arg("theSelector"), py::arg("theMode"));
cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectionManager::Remove, "Removes selectable object theObject from all viewer selectors it was added to previously, removes it from all contexts and clears all computed selections of theObject.", py::arg("theObject"));
cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Remove, "Removes theObject from theSelector, does not clear selections and unbind theObject from context maps.", py::arg("theObject"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("Activate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Activate(a0); });
cls_SelectMgr_SelectionManager.def("Activate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.Activate(a0, a1); });
cls_SelectMgr_SelectionManager.def("Activate", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Activate, "Activates the selection mode theMode in the selector theSelector for the selectable object anObject. By default, theMode is equal to 0. If theSelector is set to default (NULL), the selection with the mode theMode will be activated in all the viewers available.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("Deactivate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Deactivate(a0); });
cls_SelectMgr_SelectionManager.def("Deactivate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.Deactivate(a0, a1); });
cls_SelectMgr_SelectionManager.def("Deactivate", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Deactivate, "Deactivates mode theMode of theObject in theSelector. If theMode value is set to default (-1), all active selection modes will be deactivated. Likewise, if theSelector value is set to default (NULL), theMode will be deactivated in all viewer selectors.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("IsActivated", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> Standard_Boolean { return self.IsActivated(a0); });
cls_SelectMgr_SelectionManager.def("IsActivated", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> Standard_Boolean { return self.IsActivated(a0, a1); });
cls_SelectMgr_SelectionManager.def("IsActivated", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &) const) &SelectMgr_SelectionManager::IsActivated, "Returns true if the selection with theMode is active for the selectable object theObject and selector theSelector. If all parameters are set to default values, it returns it there is any active selection in any known viewer selector for object theObject.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.ClearSelectionStructures(a0); });
cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.ClearSelectionStructures(a0, a1); });
cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::ClearSelectionStructures, "Removes sensitive entities from all viewer selectors after method Clear() was called to the selection they belonged to or it was recomputed somehow.", py::arg("theObj"), py::arg("theMode"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RestoreSelectionStructures(a0); });
cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.RestoreSelectionStructures(a0, a1); });
cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::RestoreSelectionStructures, "Re-adds newly calculated sensitive entities of recomputed selection defined by mode theMode to all viewer selectors contained that selection.", py::arg("theObj"), py::arg("theMode"), py::arg("theSelector"));
cls_SelectMgr_SelectionManager.def("RecomputeSelection", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RecomputeSelection(a0); });
cls_SelectMgr_SelectionManager.def("RecomputeSelection", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Boolean a1) -> void { return self.RecomputeSelection(a0, a1); });
cls_SelectMgr_SelectionManager.def("RecomputeSelection", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean, const Standard_Integer)) &SelectMgr_SelectionManager::RecomputeSelection, "Recomputes activated selections of theObject for all known viewer selectors according to theMode specified. If theMode is set to default (-1), then all activated selections will be recomputed. If theIsForce is set to true, then selection mode theMode for object theObject will be recomputed regardless of its activation status.", py::arg("theObject"), py::arg("theIsForce"), py::arg("theMode"));
cls_SelectMgr_SelectionManager.def("Update", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Update(a0); });
cls_SelectMgr_SelectionManager.def("Update", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean)) &SelectMgr_SelectionManager::Update, "Updates all selections of theObject in all viewer selectors according to its current update status. If theIsForce is set to true, the call is equal to recomputation.", py::arg("theObject"), py::arg("theIsForce"));
cls_SelectMgr_SelectionManager.def("Update", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const opencascade::handle<SelectMgr_ViewerSelector> & a1) -> void { return self.Update(a0, a1); });
cls_SelectMgr_SelectionManager.def("Update", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &, const Standard_Boolean)) &SelectMgr_SelectionManager::Update, "Updates all selections of theObject in specified viewer selector according to its current update status. If theIsForce is set to true, the call is equal to recomputation.", py::arg("theObject"), py::arg("theSelector"), py::arg("theIsForce"));
cls_SelectMgr_SelectionManager.def("SetUpdateMode", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const SelectMgr_TypeOfUpdate)) &SelectMgr_SelectionManager::SetUpdateMode, "Sets type of update of all selections of theObject to the given theType.", py::arg("theObject"), py::arg("theType"));
cls_SelectMgr_SelectionManager.def("SetUpdateMode", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const SelectMgr_TypeOfUpdate)) &SelectMgr_SelectionManager::SetUpdateMode, "Sets type of update of selection with theMode of theObject to the given theType.", py::arg("theObject"), py::arg("theMode"), py::arg("theType"));
cls_SelectMgr_SelectionManager.def("SetSelectionSensitivity", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectionManager::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSens"));
cls_SelectMgr_SelectionManager.def("UpdateSelection", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectionManager::UpdateSelection, "Re-adds selectable object in BVHs in all viewer selectors.", py::arg("theObj"));

// Enums

}