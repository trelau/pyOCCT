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
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <TopLoc_Location.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <V3d_Viewer.hxx>

void bind_SelectMgr_EntityOwner(py::module &mod){

py::class_<SelectMgr_EntityOwner, opencascade::handle<SelectMgr_EntityOwner>, SelectBasics_EntityOwner> cls_SelectMgr_EntityOwner(mod, "SelectMgr_EntityOwner", "A framework to define classes of owners of sensitive primitives. The owner is the link between application and selection data structures. For the application to make its own objects selectable, it must define owner classes inheriting this framework.");

// Constructors
cls_SelectMgr_EntityOwner.def(py::init<>());
cls_SelectMgr_EntityOwner.def(py::init<const Standard_Integer>(), py::arg("aPriority"));
cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &>(), py::arg("aSO"));
cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer>(), py::arg("aSO"), py::arg("aPriority"));
cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &>(), py::arg("theOwner"));
cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer>(), py::arg("theOwner"), py::arg("aPriority"));

// Fields

// Methods
cls_SelectMgr_EntityOwner.def_static("get_type_name_", (const char * (*)()) &SelectMgr_EntityOwner::get_type_name, "None");
cls_SelectMgr_EntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_EntityOwner::get_type_descriptor, "None");
cls_SelectMgr_EntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::DynamicType, "None");
cls_SelectMgr_EntityOwner.def("HasSelectable", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::HasSelectable, "Returns true if there is a selectable object to serve as an owner.");
cls_SelectMgr_EntityOwner.def("Selectable", (opencascade::handle<SelectMgr_SelectableObject> (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::Selectable, "Returns a selectable object detected in the working context.");
cls_SelectMgr_EntityOwner.def("SetSelectable", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_EntityOwner::SetSelectable, "Sets the selectable object.", py::arg("theSelObj"));
cls_SelectMgr_EntityOwner.def("IsHilighted", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_SelectMgr_EntityOwner.def("IsHilighted", (Standard_Boolean (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &SelectMgr_EntityOwner::IsHilighted, "Returns true if the presentation manager aPM highlights selections corresponding to the selection mode aMode.", py::arg("aPM"), py::arg("aMode"));
cls_SelectMgr_EntityOwner.def("HilightWithColor", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_SelectMgr_EntityOwner.def("HilightWithColor", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &SelectMgr_EntityOwner::HilightWithColor, "Highlights selectable object's presentation with mode theMode in presentation manager with given highlight style. Also a check for auto-highlight is performed - if selectable object manages highlighting on its own, execution will be passed to SelectMgr_SelectableObject::HilightOwnerWithColor method", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_SelectMgr_EntityOwner.def("Unhilight", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_SelectMgr_EntityOwner.def("Unhilight", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &SelectMgr_EntityOwner::Unhilight, "Removes highlighting from the owner of a detected selectable object in the presentation manager. This object could be the owner of a sensitive primitive.", py::arg("thePrsMgr"), py::arg("theMode"));
cls_SelectMgr_EntityOwner.def("Clear", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); });
cls_SelectMgr_EntityOwner.def("Clear", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &SelectMgr_EntityOwner::Clear, "Clears the owners matching the value of the selection mode aMode from the presentation manager object aPM.", py::arg("aPM"), py::arg("aMode"));
cls_SelectMgr_EntityOwner.def("HasLocation", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::HasLocation, "None");
cls_SelectMgr_EntityOwner.def("SetLocation", (void (SelectMgr_EntityOwner::*)(const TopLoc_Location &)) &SelectMgr_EntityOwner::SetLocation, "None", py::arg("aLoc"));
cls_SelectMgr_EntityOwner.def("ResetLocation", (void (SelectMgr_EntityOwner::*)()) &SelectMgr_EntityOwner::ResetLocation, "None");
cls_SelectMgr_EntityOwner.def("Location", (TopLoc_Location (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::Location, "None");
cls_SelectMgr_EntityOwner.def("SetSelected", (void (SelectMgr_EntityOwner::*)(const Standard_Boolean)) &SelectMgr_EntityOwner::SetSelected, "Set the state of the owner.", py::arg("theIsSelected"));
cls_SelectMgr_EntityOwner.def("IsSelected", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::IsSelected, "Returns Standard_True if the owner is selected.");
cls_SelectMgr_EntityOwner.def("State", (void (SelectMgr_EntityOwner::*)(const Standard_Integer)) &SelectMgr_EntityOwner::State, "Set the state of the owner. The method is deprecated. Use SetSelected() instead.", py::arg("theStatus"));
cls_SelectMgr_EntityOwner.def("State", (Standard_Integer (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::State, "None");
cls_SelectMgr_EntityOwner.def("IsAutoHilight", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::IsAutoHilight, "if owner is not auto hilighted, for group contains many such owners will be called one method HilightSelected of SelectableObject");
cls_SelectMgr_EntityOwner.def("IsForcedHilight", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::IsForcedHilight, "if this method returns TRUE the owner will allways call method Hilight for SelectableObject when the owner is detected. By default it always return FALSE.");
cls_SelectMgr_EntityOwner.def("SetZLayer", (void (SelectMgr_EntityOwner::*)(const Graphic3d_ZLayerId)) &SelectMgr_EntityOwner::SetZLayer, "Set Z layer ID and update all presentations.", py::arg("theLayerId"));
cls_SelectMgr_EntityOwner.def("UpdateHighlightTrsf", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentationManager3d> &, const Standard_Integer)) &SelectMgr_EntityOwner::UpdateHighlightTrsf, "Implements immediate application of location transformation of parent object to dynamic highlight structure", py::arg("theViewer"), py::arg("theManager"), py::arg("theDispMode"));
cls_SelectMgr_EntityOwner.def("IsSameSelectable", (Standard_Boolean (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const) &SelectMgr_EntityOwner::IsSameSelectable, "Returns true if pointer to selectable object of this owner is equal to the given one", py::arg("theOther"));
cls_SelectMgr_EntityOwner.def("ComesFromDecomposition", (Standard_Boolean (SelectMgr_EntityOwner::*)() const) &SelectMgr_EntityOwner::ComesFromDecomposition, "Returns TRUE if this owner points to a part of object and FALSE for entire object.");
cls_SelectMgr_EntityOwner.def("SetComesFromDecomposition", (void (SelectMgr_EntityOwner::*)(const Standard_Boolean)) &SelectMgr_EntityOwner::SetComesFromDecomposition, "Sets flag indicating this owner points to a part of object (TRUE) or to entire object (FALSE).", py::arg("theIsFromDecomposition"));
cls_SelectMgr_EntityOwner.def("Set", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_EntityOwner::Set, "Sets the selectable object.", py::arg("theSelObj"));

// Enums

}