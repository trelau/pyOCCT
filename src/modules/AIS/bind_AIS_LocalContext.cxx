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
#include <AIS_InteractiveContext.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_Selection.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_ClearMode.hxx>
#include <AIS_SelectionModesConcurrency.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <AIS_StatusOfDetection.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_StatusOfPick.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopoDS_Shape.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <Prs3d_Drawer.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_LocalStatus.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <AIS_LocalContext.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <AIS_DataMapOfSelStat.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_AIS_LocalContext(py::module &mod){

py::class_<AIS_LocalContext, opencascade::handle<AIS_LocalContext>, Standard_Transient> cls_AIS_LocalContext(mod, "AIS_LocalContext", "Defines a specific context for selection. It becomes possible to: + Load InteractiveObjects with a mode to be activated + associate InteractiveObjects with a set of temporary selectable Objects.... + + activate StandardMode of selection for Entities inheriting BasicShape from AIS (Selection Of vertices, edges, wires,faces... + Add Filters acting on detected owners of sensitive primitives");

// Constructors
cls_AIS_LocalContext.def(py::init<>());
cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer>(), py::arg("aCtx"), py::arg("anIndex"));
cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"));
cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"));
cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"), py::arg("AcceptErase"));
cls_AIS_LocalContext.def(py::init<const opencascade::handle<AIS_InteractiveContext> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aCtx"), py::arg("anIndex"), py::arg("LoadDisplayed"), py::arg("AcceptStandardModes"), py::arg("AcceptErase"), py::arg("UseBothViewers"));

// Fields

// Methods
cls_AIS_LocalContext.def("AcceptErase", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::AcceptErase, "authorize or not others contexts to erase temporary displayed objects here;", py::arg("aStatus"));
cls_AIS_LocalContext.def("AcceptErase", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::AcceptErase, "None");
cls_AIS_LocalContext.def("SetContext", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_LocalContext::SetContext, "None", py::arg("aCtx"));
cls_AIS_LocalContext.def("Selection", (const opencascade::handle<AIS_Selection> & (AIS_LocalContext::*)() const) &AIS_LocalContext::Selection, "None");
cls_AIS_LocalContext.def("Terminate", [](AIS_LocalContext &self) -> void { return self.Terminate(); });
cls_AIS_LocalContext.def("Terminate", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::Terminate, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.Display(a0); });
cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Display(a0, a1); });
cls_AIS_LocalContext.def("Display", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Display(a0, a1, a2); });
cls_AIS_LocalContext.def("Display", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &AIS_LocalContext::Display, "returns true if done...", py::arg("anInteractive"), py::arg("DisplayMode"), py::arg("AllowShapeDecomposition"), py::arg("ActivationMode"));
cls_AIS_LocalContext.def("Load", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.Load(a0); });
cls_AIS_LocalContext.def("Load", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Load(a0, a1); });
cls_AIS_LocalContext.def("Load", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Integer)) &AIS_LocalContext::Load, "loads <anInteractive> with nodisplay... returns true if done", py::arg("anInteractive"), py::arg("AllowShapeDecomposition"), py::arg("ActivationMode"));
cls_AIS_LocalContext.def("Erase", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Erase, "returns true if done...", py::arg("anInteractive"));
cls_AIS_LocalContext.def("Remove", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Remove, "None", py::arg("aSelectable"));
cls_AIS_LocalContext.def("ClearPrs", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ClearPrs, "None", py::arg("anInteractive"), py::arg("aMode"));
cls_AIS_LocalContext.def("SetShapeDecomposition", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::SetShapeDecomposition, "allows or forbids the shape decomposition into Activated Standard Mode for <aStoredObject> does nothing if the object doesn't inherits BasicShape from AIS", py::arg("aStoredObject"), py::arg("aStatus"));
cls_AIS_LocalContext.def("Clear", [](AIS_LocalContext &self) -> void { return self.Clear(); });
cls_AIS_LocalContext.def("Clear", (void (AIS_LocalContext::*)(const AIS_ClearMode)) &AIS_LocalContext::Clear, "according to <atype> , clears the different parts of the selector (filters, modeof activation, objects...)", py::arg("atype"));
cls_AIS_LocalContext.def("SetSelectionModeActive", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean, const AIS_SelectionModesConcurrency)) &AIS_LocalContext::SetSelectionModeActive, "None", py::arg("theObj"), py::arg("theMode"), py::arg("theIsActive"), py::arg("theActiveFilter"));
cls_AIS_LocalContext.def("ActivateMode", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ActivateMode, "optional : activation of a mode which is not 0 for a selectable...", py::arg("theObj"), py::arg("theMode"));
cls_AIS_LocalContext.def("DeactivateMode", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::DeactivateMode, "None", py::arg("theObj"), py::arg("theMode"));
cls_AIS_LocalContext.def("Deactivate", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Deactivate, "None", py::arg("theObj"));
cls_AIS_LocalContext.def("ActivateStandardMode", (void (AIS_LocalContext::*)(const TopAbs_ShapeEnum)) &AIS_LocalContext::ActivateStandardMode, "decomposition of shapes into <aType>", py::arg("aType"));
cls_AIS_LocalContext.def("DeactivateStandardMode", (void (AIS_LocalContext::*)(const TopAbs_ShapeEnum)) &AIS_LocalContext::DeactivateStandardMode, "None", py::arg("aType"));
cls_AIS_LocalContext.def("StandardModes", (const TColStd_ListOfInteger & (AIS_LocalContext::*)() const) &AIS_LocalContext::StandardModes, "None");
cls_AIS_LocalContext.def("AddFilter", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_LocalContext::AddFilter, "None", py::arg("aFilter"));
cls_AIS_LocalContext.def("RemoveFilter", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_LocalContext::RemoveFilter, "None", py::arg("aFilter"));
cls_AIS_LocalContext.def("ListOfFilter", (const SelectMgr_ListOfFilter & (AIS_LocalContext::*)() const) &AIS_LocalContext::ListOfFilter, "None");
cls_AIS_LocalContext.def("Filter", (const opencascade::handle<SelectMgr_OrFilter> & (AIS_LocalContext::*)() const) &AIS_LocalContext::Filter, "None");
cls_AIS_LocalContext.def("SetAutomaticHilight", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::SetAutomaticHilight, "if <aStatus> = True , the shapes or subshapes detected by the selector will be automatically hilighted in the main viewer. Else the user has to manage the detected shape outside the Shape Selector....", py::arg("aStatus"));
cls_AIS_LocalContext.def("AutomaticHilight", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::AutomaticHilight, "None");
cls_AIS_LocalContext.def("MoveTo", (AIS_StatusOfDetection (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::MoveTo, "None", py::arg("theXpix"), py::arg("theYpix"), py::arg("theView"), py::arg("theToRedrawImmediate"));
cls_AIS_LocalContext.def("HasNextDetected", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasNextDetected, "returns True if more than one entity was detected at the last Mouse position.");
cls_AIS_LocalContext.def("HilightNextDetected", (Standard_Integer (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::HilightNextDetected, "returns True if last detected. the next detected will be first one (endless loop)", py::arg("theView"), py::arg("theToRedrawImmediate"));
cls_AIS_LocalContext.def("HilightPreviousDetected", (Standard_Integer (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::HilightPreviousDetected, "None", py::arg("theView"), py::arg("theToRedrawImmediate"));
cls_AIS_LocalContext.def("UnhilightLastDetected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_LocalContext::UnhilightLastDetected, "returns True if something was done...", py::arg("theViewer"));
cls_AIS_LocalContext.def("UnhilightLastDetected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::UnhilightLastDetected, "returns True if something was done...", py::arg("theView"));
cls_AIS_LocalContext.def("AddSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_LocalContext::AddSelect, "returns the number of selected", py::arg("theObject"));
cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self) -> AIS_StatusOfPick { return self.Select(); });
cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self) -> AIS_StatusOfPick { return self.ShiftSelect(); });
cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const opencascade::handle<V3d_View> & a4) -> AIS_StatusOfPick { return self.Select(a0, a1, a2, a3, a4); });
cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const opencascade::handle<V3d_View> & a4) -> AIS_StatusOfPick { return self.ShiftSelect(a0, a1, a2, a3, a4); });
cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("XPMin"), py::arg("YPMin"), py::arg("XPMax"), py::arg("YPMax"), py::arg("aView"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("Select", [](AIS_LocalContext &self, const TColgp_Array1OfPnt2d & a0, const opencascade::handle<V3d_View> & a1) -> AIS_StatusOfPick { return self.Select(a0, a1); });
cls_AIS_LocalContext.def("Select", (AIS_StatusOfPick (AIS_LocalContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::Select, "None", py::arg("Polyline"), py::arg("aView"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("ShiftSelect", [](AIS_LocalContext &self, const TColgp_Array1OfPnt2d & a0, const opencascade::handle<V3d_View> & a1) -> AIS_StatusOfPick { return self.ShiftSelect(a0, a1); });
cls_AIS_LocalContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_LocalContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_LocalContext::ShiftSelect, "None", py::arg("Polyline"), py::arg("aView"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("HilightPicked", [](AIS_LocalContext &self) -> void { return self.HilightPicked(); });
cls_AIS_LocalContext.def("HilightPicked", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::HilightPicked, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("UnhilightPicked", [](AIS_LocalContext &self) -> void { return self.UnhilightPicked(); });
cls_AIS_LocalContext.def("UnhilightPicked", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::UnhilightPicked, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("UpdateSelected", [](AIS_LocalContext &self) -> void { return self.UpdateSelected(); });
cls_AIS_LocalContext.def("UpdateSelected", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::UpdateSelected, "None", py::arg("updateviewer"));
cls_AIS_LocalContext.def("UpdateSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.UpdateSelected(a0); });
cls_AIS_LocalContext.def("UpdateSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::UpdateSelected, "Part of advanced selection highlighting mechanism. If no owners belonging to anobj are selected, calls anobj->ClearSelected(), otherwise calls anobj->HilightSelected(). This method can be used to avoid redrawing the whole selection belonging to several Selectable Objects.", py::arg("anobj"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("SetSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.SetSelected(a0); });
cls_AIS_LocalContext.def("SetSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::SetSelected, "useful to update selection with objects coming from Collector or stack", py::arg("anobj"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.AddOrRemoveSelected(a0); });
cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "useful to update selection with objects coming from Collector or stack", py::arg("anobj"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const TopoDS_Shape & a0) -> void { return self.AddOrRemoveSelected(a0); });
cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const TopoDS_Shape &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "None", py::arg("aShape"), py::arg("updateviewer"));
cls_AIS_LocalContext.def("AddOrRemoveSelected", [](AIS_LocalContext &self, const opencascade::handle<SelectMgr_EntityOwner> & a0) -> void { return self.AddOrRemoveSelected(a0); });
cls_AIS_LocalContext.def("AddOrRemoveSelected", (void (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_LocalContext::AddOrRemoveSelected, "None", py::arg("theOwner"), py::arg("toUpdateViewer"));
cls_AIS_LocalContext.def("ClearSelected", [](AIS_LocalContext &self) -> void { return self.ClearSelected(); });
cls_AIS_LocalContext.def("ClearSelected", (void (AIS_LocalContext::*)(const Standard_Boolean)) &AIS_LocalContext::ClearSelected, "Clears local context selection.", py::arg("toUpdateViewer"));
cls_AIS_LocalContext.def("ClearOutdatedSelection", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_LocalContext::ClearOutdatedSelection, "Clears outdated selection and detection of owners for the interactive object. Use this method if selection structures of the interactive object have changed. The method unhilights and removes outdated entity owners from lists of selected and detected owners.", py::arg("theIO"), py::arg("toClearDeactivated"));
cls_AIS_LocalContext.def("HasDetected", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasDetected, "None");
cls_AIS_LocalContext.def("InitDetected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::InitDetected, "Initialization for iteration through mouse-detected objects in local context.");
cls_AIS_LocalContext.def("MoreDetected", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::MoreDetected, "Returns true if there is more mouse-detected objects after the current one during iteration through mouse-detected interactive objects.");
cls_AIS_LocalContext.def("NextDetected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::NextDetected, "Gets next current object during iteration through mouse-detected interactive objects.");
cls_AIS_LocalContext.def("DetectedCurrentOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedCurrentOwner, "Returns current mouse-detected Owner or null object if there is no current detected.");
cls_AIS_LocalContext.def("DetectedCurrentShape", (const TopoDS_Shape & (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedCurrentShape, "Returns current mouse-detected shape or empty (null) shape, if current interactive object is not a shape (AIS_Shape) or there is no current mouse-detected interactive object at all.");
cls_AIS_LocalContext.def("DetectedCurrentObject", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedCurrentObject, "Returns current mouse-detected interactive object or null object if there is no current detected.");
cls_AIS_LocalContext.def("HasDetectedShape", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasDetectedShape, "None");
cls_AIS_LocalContext.def("DetectedShape", (const TopoDS_Shape & (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedShape, "None");
cls_AIS_LocalContext.def("DetectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedInteractive, "None");
cls_AIS_LocalContext.def("DetectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const) &AIS_LocalContext::DetectedOwner, "None");
cls_AIS_LocalContext.def("InitSelected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::InitSelected, "None");
cls_AIS_LocalContext.def("MoreSelected", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::MoreSelected, "None");
cls_AIS_LocalContext.def("NextSelected", (void (AIS_LocalContext::*)()) &AIS_LocalContext::NextSelected, "None");
cls_AIS_LocalContext.def("HasShape", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasShape, "returns TRUE if the detected entity is a shape coming from a Decomposition of an element.");
cls_AIS_LocalContext.def("HasSelectedShape", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasSelectedShape, "returns true if current selection is not empty and the owner of selected object contains a shape. This method does not take into account decomposition status of detected shape.");
cls_AIS_LocalContext.def("SelectedShape", (TopoDS_Shape (AIS_LocalContext::*)() const) &AIS_LocalContext::SelectedShape, "None");
cls_AIS_LocalContext.def("SelectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)() const) &AIS_LocalContext::SelectedOwner, "None");
cls_AIS_LocalContext.def("IsSelected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::IsSelected, "None", py::arg("aniobj"));
cls_AIS_LocalContext.def("IsSelected", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_LocalContext::IsSelected, "None", py::arg("anOwner"));
cls_AIS_LocalContext.def("SelectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_LocalContext::*)() const) &AIS_LocalContext::SelectedInteractive, "None");
cls_AIS_LocalContext.def("HasApplicative", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::HasApplicative, "returns TRUE if an interactive element was associated with the current picked entity.");
cls_AIS_LocalContext.def("SelectedApplicative", (const opencascade::handle<Standard_Transient> & (AIS_LocalContext::*)() const) &AIS_LocalContext::SelectedApplicative, "None");
cls_AIS_LocalContext.def("SetDisplayPriority", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::SetDisplayPriority, "None", py::arg("anObject"), py::arg("Prior"));
cls_AIS_LocalContext.def("DisplayedObjects", (Standard_Integer (AIS_LocalContext::*)(TColStd_MapOfTransient &) const) &AIS_LocalContext::DisplayedObjects, "None", py::arg("theMapToFill"));
cls_AIS_LocalContext.def("IsIn", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::IsIn, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("IsDisplayed", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::IsDisplayed, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("IsDisplayed", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const) &AIS_LocalContext::IsDisplayed, "None", py::arg("anObject"), py::arg("aMode"));
cls_AIS_LocalContext.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::SelectionModes, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("SubIntensityOn", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::SubIntensityOn, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("SubIntensityOff", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::SubIntensityOff, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("Hilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Hilight, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("Hilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &)) &AIS_LocalContext::Hilight, "None", py::arg("theObj"), py::arg("theStyle"));
cls_AIS_LocalContext.def("Unhilight", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_LocalContext::Unhilight, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("IsHilighted", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::IsHilighted, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("HighlightStyle", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, opencascade::handle<Prs3d_Drawer> &) const) &AIS_LocalContext::HighlightStyle, "None", py::arg("theObject"), py::arg("theStyle"));
cls_AIS_LocalContext.def("SetPixelTolerance", [](AIS_LocalContext &self) -> void { return self.SetPixelTolerance(); });
cls_AIS_LocalContext.def("SetPixelTolerance", (void (AIS_LocalContext::*)(const Standard_Integer)) &AIS_LocalContext::SetPixelTolerance, "Define the current selection sensitivity for this local context according to the view size.", py::arg("aPrecision"));
cls_AIS_LocalContext.def("PixelTolerance", (Standard_Integer (AIS_LocalContext::*)() const) &AIS_LocalContext::PixelTolerance, "Returns the pixel tolerance.");
cls_AIS_LocalContext.def("SetSelectionSensitivity", (void (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer)) &AIS_LocalContext::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSensitivity"));
cls_AIS_LocalContext.def("BeginImmediateDraw", (Standard_Boolean (AIS_LocalContext::*)()) &AIS_LocalContext::BeginImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode and begins accumulation of new list by following AddToImmediateList()/Color()/Highlight() calls.");
cls_AIS_LocalContext.def("ClearImmediateDraw", (void (AIS_LocalContext::*)()) &AIS_LocalContext::ClearImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode.");
cls_AIS_LocalContext.def("ImmediateAdd", [](AIS_LocalContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.ImmediateAdd(a0); });
cls_AIS_LocalContext.def("ImmediateAdd", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_LocalContext::ImmediateAdd, "Stores presentation theMode of object theObj in the transient list of presentations to be displayed in immediate mode. Will be taken in account in EndImmediateDraw method.", py::arg("theObj"), py::arg("theMode"));
cls_AIS_LocalContext.def("EndImmediateDraw", (Standard_Boolean (AIS_LocalContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_LocalContext::EndImmediateDraw, "Allows rapid drawing of the view theView by avoiding an update of the whole background.", py::arg("theViewer"));
cls_AIS_LocalContext.def("IsImmediateModeOn", (Standard_Boolean (AIS_LocalContext::*)() const) &AIS_LocalContext::IsImmediateModeOn, "Returns true if Presentation Manager is accumulating transient list of presentations to be displayed in immediate mode.");
cls_AIS_LocalContext.def("Status", (TCollection_AsciiString (AIS_LocalContext::*)() const) &AIS_LocalContext::Status, "None");
cls_AIS_LocalContext.def("Status", (const opencascade::handle<AIS_LocalStatus> & (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::Status, "None", py::arg("anObject"));
cls_AIS_LocalContext.def("LoadContextObjects", (void (AIS_LocalContext::*)()) &AIS_LocalContext::LoadContextObjects, "None");
cls_AIS_LocalContext.def("UnloadContextObjects", (void (AIS_LocalContext::*)()) &AIS_LocalContext::UnloadContextObjects, "None");
cls_AIS_LocalContext.def("DisplaySensitive", (void (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::DisplaySensitive, "None", py::arg("aView"));
cls_AIS_LocalContext.def("ClearSensitive", (void (AIS_LocalContext::*)(const opencascade::handle<V3d_View> &)) &AIS_LocalContext::ClearSensitive, "None", py::arg("aView"));
cls_AIS_LocalContext.def("MainSelector", (const opencascade::handle<StdSelect_ViewerSelector3d> & (AIS_LocalContext::*)() const) &AIS_LocalContext::MainSelector, "None");
cls_AIS_LocalContext.def("FindSelectedOwnerFromIO", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_LocalContext::FindSelectedOwnerFromIO, "None", py::arg("anIObj"));
cls_AIS_LocalContext.def("FindSelectedOwnerFromShape", (opencascade::handle<SelectMgr_EntityOwner> (AIS_LocalContext::*)(const TopoDS_Shape &) const) &AIS_LocalContext::FindSelectedOwnerFromShape, "None", py::arg("aShape"));
cls_AIS_LocalContext.def("RestoreActivatedModes", (void (AIS_LocalContext::*)() const) &AIS_LocalContext::RestoreActivatedModes, "Iterates through all interactive objects of local context and activates selection modes stored in local status");
cls_AIS_LocalContext.def_static("get_type_name_", (const char * (*)()) &AIS_LocalContext::get_type_name, "None");
cls_AIS_LocalContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LocalContext::get_type_descriptor, "None");
cls_AIS_LocalContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LocalContext::*)() const) &AIS_LocalContext::DynamicType, "None");

// Enums

}