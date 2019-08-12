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
#include <PrsMgr_PresentableObject.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <SelectMgr_Selection.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SequenceOfSelection.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Bnd_Box.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>

void bind_SelectMgr_SelectableObject(py::module &mod){

py::class_<SelectMgr_SelectableObject, opencascade::handle<SelectMgr_SelectableObject>, PrsMgr_PresentableObject> cls_SelectMgr_SelectableObject(mod, "SelectMgr_SelectableObject", "A framework to supply the structure of the object to be selected. At the first pick, this structure is created by calling the appropriate algorithm and retaining this framework for further picking. This abstract framework is inherited in Application Interactive Services (AIS), notably in AIS_InteractiveObject. Consequently, 3D selection should be handled by the relevant daughter classes and their member functions in AIS. This is particularly true in the creation of new interactive objects.");

// Fields

// Methods
cls_SelectMgr_SelectableObject.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SelectableObject::get_type_name, "None");
cls_SelectMgr_SelectableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SelectableObject::get_type_descriptor, "None");
cls_SelectMgr_SelectableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::DynamicType, "None");
cls_SelectMgr_SelectableObject.def("ComputeSelection", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &SelectMgr_SelectableObject::ComputeSelection, "Recovers and calculates any sensitive primitive, aSelection, available in Shape mode, specified by aMode. As a rule, these are sensitive faces. This method is defined as virtual. This enables you to implement it in the creation of a new class of AIS Interactive Object. You need to do this and in so doing, redefine this method, if you create a class which enriches the list of signatures and types.", py::arg("aSelection"), py::arg("aMode"));
cls_SelectMgr_SelectableObject.def("RecomputePrimitives", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::RecomputePrimitives, "Re-computes the sensitive primitives for all modes. IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager! This method does not take into account necessary BVH updates, but may invalidate the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.");
cls_SelectMgr_SelectableObject.def("RecomputePrimitives", (void (SelectMgr_SelectableObject::*)(const Standard_Integer)) &SelectMgr_SelectableObject::RecomputePrimitives, "Re-computes the sensitive primitives which correspond to the <theMode>th selection mode. IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager! selection manager! This method does not take into account necessary BVH updates, but may invalidate the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.", py::arg("theMode"));
cls_SelectMgr_SelectableObject.def("AddSelection", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &SelectMgr_SelectableObject::AddSelection, "Adds the selection aSelection with the selection mode index aMode to this framework.", py::arg("aSelection"), py::arg("aMode"));
cls_SelectMgr_SelectableObject.def("ClearSelections", [](SelectMgr_SelectableObject &self) -> void { return self.ClearSelections(); });
cls_SelectMgr_SelectableObject.def("ClearSelections", (void (SelectMgr_SelectableObject::*)(const Standard_Boolean)) &SelectMgr_SelectableObject::ClearSelections, "Empties all the selections in the SelectableObject <update> parameter defines whether all object's selections should be flagged for further update or not. This improved method can be used to recompute an object's selection (without redisplaying the object completely) when some selection mode is activated not for the first time.", py::arg("update"));
cls_SelectMgr_SelectableObject.def("Selection", (const opencascade::handle<SelectMgr_Selection> & (SelectMgr_SelectableObject::*)(const Standard_Integer) const) &SelectMgr_SelectableObject::Selection, "Returns the selection having specified selection mode or NULL.", py::arg("theMode"));
cls_SelectMgr_SelectableObject.def("HasSelection", (Standard_Boolean (SelectMgr_SelectableObject::*)(const Standard_Integer) const) &SelectMgr_SelectableObject::HasSelection, "Returns true if a selection corresponding to the selection mode theMode was computed for this object.", py::arg("theMode"));
cls_SelectMgr_SelectableObject.def("Selections", (const SelectMgr_SequenceOfSelection & (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::Selections, "Return the sequence of selections.");
cls_SelectMgr_SelectableObject.def("Init", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::Init, "Begins the iteration scanning for sensitive primitives.");
cls_SelectMgr_SelectableObject.def("More", (Standard_Boolean (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::More, "Continues the iteration scanning for sensitive primitives.");
cls_SelectMgr_SelectableObject.def("Next", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::Next, "Continues the iteration scanning for sensitive primitives.");
cls_SelectMgr_SelectableObject.def("CurrentSelection", (const opencascade::handle<SelectMgr_Selection> & (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::CurrentSelection, "Returns the current selection in this framework.");
cls_SelectMgr_SelectableObject.def("ResetTransformation", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::ResetTransformation, "None");
cls_SelectMgr_SelectableObject.def("UpdateTransformation", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::UpdateTransformation, "Recomputes the location of the selection aSelection.");
cls_SelectMgr_SelectableObject.def("UpdateTransformations", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SelectableObject::UpdateTransformations, "Updates locations in all sensitive entities from <aSelection> and in corresponding entity owners.", py::arg("aSelection"));
cls_SelectMgr_SelectableObject.def("HilightSelected", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &SelectMgr_SelectableObject::HilightSelected, "Method which draws selected owners ( for fast presentation draw )", py::arg("PM"), py::arg("Seq"));
cls_SelectMgr_SelectableObject.def("ClearSelected", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw )");
cls_SelectMgr_SelectableObject.def("ClearDynamicHighlight", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::ClearDynamicHighlight, "Method that needs to be implemented when the object manages selection and dynamic highlighting on its own. Clears or invalidates dynamic highlight presentation. By default it clears immediate draw of given presentation manager.", py::arg("theMgr"));
cls_SelectMgr_SelectableObject.def("HilightOwnerWithColor", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &SelectMgr_SelectableObject::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw )", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));
cls_SelectMgr_SelectableObject.def("IsAutoHilight", (Standard_Boolean (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::IsAutoHilight, "If returns True, the old mechanism for highlighting selected objects is used (HilightSelected Method may be empty). If returns False, the HilightSelected method will be fully responsible for highlighting selected entity owners belonging to this selectable object.");
cls_SelectMgr_SelectableObject.def("SetAutoHilight", (void (SelectMgr_SelectableObject::*)(const Standard_Boolean)) &SelectMgr_SelectableObject::SetAutoHilight, "Set AutoHilight property to true or false Sets up Transform Persistence Mode for this object", py::arg("newAutoHilight"));
cls_SelectMgr_SelectableObject.def("GetHilightPresentation", (opencascade::handle<Prs3d_Presentation> (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::GetHilightPresentation, "None", py::arg("TheMgr"));
cls_SelectMgr_SelectableObject.def("GetSelectPresentation", (opencascade::handle<Prs3d_Presentation> (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::GetSelectPresentation, "None", py::arg("TheMgr"));
cls_SelectMgr_SelectableObject.def("ErasePresentations", (void (SelectMgr_SelectableObject::*)(Standard_Boolean)) &SelectMgr_SelectableObject::ErasePresentations, "Removes presentations returned by GetHilightPresentation() and GetSelectPresentation().", py::arg("theToRemove"));
cls_SelectMgr_SelectableObject.def("SetZLayer", (void (SelectMgr_SelectableObject::*)(const Graphic3d_ZLayerId)) &SelectMgr_SelectableObject::SetZLayer, "Set Z layer ID and update all presentations of the selectable object. The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.", py::arg("theLayerId"));
cls_SelectMgr_SelectableObject.def("UpdateSelection", [](SelectMgr_SelectableObject &self) -> void { return self.UpdateSelection(); });
cls_SelectMgr_SelectableObject.def("UpdateSelection", (void (SelectMgr_SelectableObject::*)(const Standard_Integer)) &SelectMgr_SelectableObject::UpdateSelection, "Sets update status FULL to selections of the object. Must be used as the only method of UpdateSelection from outer classes to prevent BVH structures from being outdated.", py::arg("theMode"));
cls_SelectMgr_SelectableObject.def("BoundingBox", (void (SelectMgr_SelectableObject::*)(Bnd_Box &)) &SelectMgr_SelectableObject::BoundingBox, "Returns bounding box of selectable object by storing its minimum and maximum 3d coordinates to output parameters", py::arg("theBndBox"));
cls_SelectMgr_SelectableObject.def("SetAssemblyOwner", [](SelectMgr_SelectableObject &self, const opencascade::handle<SelectMgr_EntityOwner> & a0) -> void { return self.SetAssemblyOwner(a0); });
cls_SelectMgr_SelectableObject.def("SetAssemblyOwner", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer)) &SelectMgr_SelectableObject::SetAssemblyOwner, "Sets common entity owner for assembly sensitive object entities", py::arg("theOwner"), py::arg("theMode"));
cls_SelectMgr_SelectableObject.def("BndBoxOfSelected", (Bnd_Box (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_IndexedMapOfOwner> &)) &SelectMgr_SelectableObject::BndBoxOfSelected, "Returns a bounding box of sensitive entities with the owners given if they are a part of activated selection", py::arg("theOwners"));
cls_SelectMgr_SelectableObject.def("GlobalSelectionMode", (Standard_Integer (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::GlobalSelectionMode, "Returns the mode for selection of object as a whole");
cls_SelectMgr_SelectableObject.def("GlobalSelOwner", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::GlobalSelOwner, "Returns the owner of mode for selection of object as a whole");
cls_SelectMgr_SelectableObject.def("GetAssemblyOwner", (const opencascade::handle<SelectMgr_EntityOwner> & (SelectMgr_SelectableObject::*)() const) &SelectMgr_SelectableObject::GetAssemblyOwner, "Returns common entity owner if the object is an assembly");

// Enums

}