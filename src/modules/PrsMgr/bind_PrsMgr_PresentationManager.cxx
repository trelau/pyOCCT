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
#include <PrsMgr_PresentationManager.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Prs3d_Presentation.hxx>
#include <V3d_Viewer.hxx>
#include <Prs3d_Drawer.hxx>
#include <Geom_Transformation.hxx>
#include <PrsMgr_Presentation.hxx>
#include <PrsMgr_ListOfPresentations.hxx>

void bind_PrsMgr_PresentationManager(py::module &mod){

py::class_<PrsMgr_PresentationManager, opencascade::handle<PrsMgr_PresentationManager>, Standard_Transient> cls_PrsMgr_PresentationManager(mod, "PrsMgr_PresentationManager", "A framework to manage 3D displays, graphic entities and their updates. Used in the AIS package (Application Interactive Services), to enable the advanced user to define the default display mode of a new interactive object which extends the list of signatures and types. Definition of new display types is handled by calling the presentation algorithms provided by the StdPrs package.");

// Constructors
cls_PrsMgr_PresentationManager.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theStructureManager"));

// Fields

// Methods
cls_PrsMgr_PresentationManager.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentationManager::get_type_name, "None");
cls_PrsMgr_PresentationManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentationManager::get_type_descriptor, "None");
cls_PrsMgr_PresentationManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::DynamicType, "None");
cls_PrsMgr_PresentationManager.def("Display", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Display(a0); });
cls_PrsMgr_PresentationManager.def("Display", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Display, "Displays the presentation of the object in the given Presentation manager with the given mode. The mode should be enumerated by the object which inherits PresentableObject.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Erase", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Erase(a0); });
cls_PrsMgr_PresentationManager.def("Erase", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Erase, "erases the presentation of the object in the given Presentation manager with the given mode. If is -1, then erases all presentations of the object.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Clear", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Clear(a0); });
cls_PrsMgr_PresentationManager.def("Clear", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Clear, "Clears the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetVisibility", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean)) &PrsMgr_PresentationManager::SetVisibility, "Sets the visibility of presentable object.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theValue"));
cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::Unhighlight, "Removes highlighting from the presentation of the presentable object.", py::arg("thePrsObject"));
cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Unhighlight, "None", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetDisplayPriority", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer) const) &PrsMgr_PresentationManager::SetDisplayPriority, "Sets the display priority theNewPrior of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theNewPrior"));
cls_PrsMgr_PresentationManager.def("DisplayPriority", (Standard_Integer (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::DisplayPriority, "Returns the display priority of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("SetZLayer", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Graphic3d_ZLayerId)) &PrsMgr_PresentationManager::SetZLayer, "Set Z layer ID for all presentations of the object.", py::arg("thePrsObject"), py::arg("theLayerId"));
cls_PrsMgr_PresentationManager.def("GetZLayer", (Graphic3d_ZLayerId (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &) const) &PrsMgr_PresentationManager::GetZLayer, "Get Z layer ID assigned to all presentations of the object. Method returns -1 value if object has no presentations and is impossible to get layer index.", py::arg("thePrsObject"));
cls_PrsMgr_PresentationManager.def("IsDisplayed", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsDisplayed(a0); });
cls_PrsMgr_PresentationManager.def("IsDisplayed", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::IsDisplayed, "None", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("IsHighlighted", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsHighlighted(a0); });
cls_PrsMgr_PresentationManager.def("IsHighlighted", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::IsHighlighted, "Returns true if the presentation of the presentable object thePrsObject in this framework with the display mode theMode is highlighted.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Update", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Update(a0); });
cls_PrsMgr_PresentationManager.def("Update", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::Update, "Updates the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("BeginImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::BeginImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode and begins accumulation of new list by following AddToImmediateList()/Color()/Highlight() calls.");
cls_PrsMgr_PresentationManager.def("ClearImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::ClearImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode.");
cls_PrsMgr_PresentationManager.def("AddToImmediateList", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<Prs3d_Presentation> &)) &PrsMgr_PresentationManager::AddToImmediateList, "Stores thePrs in the transient list of presentations to be displayed in immediate mode. Will be taken in account in EndImmediateDraw method.", py::arg("thePrs"));
cls_PrsMgr_PresentationManager.def("EndImmediateDraw", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::EndImmediateDraw, "Allows rapid drawing of the each view in theViewer by avoiding an update of the whole background.", py::arg("theViewer"));
cls_PrsMgr_PresentationManager.def("RedrawImmediate", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::RedrawImmediate, "Clears and redisplays immediate structures of the viewer taking into account its affinity.", py::arg("theViewer"));
cls_PrsMgr_PresentationManager.def("IsImmediateModeOn", (Standard_Boolean (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::IsImmediateModeOn, "Returns true if Presentation Manager is accumulating transient list of presentations to be displayed in immediate mode.");
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.Color(a0, a1); });
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2) -> void { return self.Color(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2, const opencascade::handle<PrsMgr_PresentableObject> & a3) -> void { return self.Color(a0, a1, a2, a3); });
cls_PrsMgr_PresentationManager.def("Color", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &, const Graphic3d_ZLayerId)) &PrsMgr_PresentationManager::Color, "Highlights the graphic object thePrsObject in the color theColor. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theStyle"), py::arg("theMode"), py::arg("theSelObj"), py::arg("theImmediateStructLayerId"));
cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.Connect(a0, a1); });
cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.Connect(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Connect", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer)) &PrsMgr_PresentationManager::Connect, "None", py::arg("thePrsObject"), py::arg("theOtherObject"), py::arg("theMode"), py::arg("theOtherMode"));
cls_PrsMgr_PresentationManager.def("Transform", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Geom_Transformation> & a1) -> void { return self.Transform(a0, a1); });
cls_PrsMgr_PresentationManager.def("Transform", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Geom_Transformation> &, const Standard_Integer)) &PrsMgr_PresentationManager::Transform, "Sets the transformation theTransformation for the presentable object thePrsObject. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theTransformation"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("StructureManager", (const opencascade::handle<Graphic3d_StructureManager> & (PrsMgr_PresentationManager::*)() const) &PrsMgr_PresentationManager::StructureManager, "Returns the structure manager.");
cls_PrsMgr_PresentationManager.def("HasPresentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.HasPresentation(a0); });
cls_PrsMgr_PresentationManager.def("HasPresentation", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const) &PrsMgr_PresentationManager::HasPresentation, "Returns true if there is a presentation of the presentable object thePrsObject in this framework, thePrsObject having the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0); });
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1); });
cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("Presentation", (opencascade::handle<PrsMgr_Presentation> (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean, const opencascade::handle<PrsMgr_PresentableObject> &) const) &PrsMgr_PresentationManager::Presentation, "Returns the presentation Presentation of the presentable object thePrsObject in this framework. When theToCreate is true - automatically creates presentation for specified mode when not exist. Optional argument theSelObj specifies parent decomposed object to inherit its view affinity.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theToCreate"), py::arg("theSelObj"));
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.UpdateHighlightTrsf(a0, a1); });
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.UpdateHighlightTrsf(a0, a1, a2); });
cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::UpdateHighlightTrsf, "Allows to apply location transformation to shadow highlight presentation immediately.", py::arg("theViewer"), py::arg("theObj"), py::arg("theMode"), py::arg("theSelObj"));

// Enums

}