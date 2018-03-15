/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Standard_TypeDef.hxx>
#include <PrsMgr_ListOfPresentations.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_Presentations.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Geom_Transformation.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <PrsMgr_ListOfPresentableObjects.hxx>
#include <PrsMgr_PresentableObjectPointer.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_Presentation.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <V3d_Viewer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <PrsMgr_PresentationPointer.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <PrsMgr_Prs.hxx>
#include <PrsMgr_ModedPresentation.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <PrsMgr_Presentation3d.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(PrsMgr, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Prs3d");
	py::module::import("OCCT.V3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_TypeOfPresentation3d.hxx
	py::enum_<PrsMgr_TypeOfPresentation3d>(mod, "PrsMgr_TypeOfPresentation3d", "To declare the type of presentation as follows - AllView for display involving no recalculation for new projectors (points of view)in hidden line removal mode - ProjectorDependant for display in hidden line removal mode, where every new point of view entails recalculation of the display.")
		.value("PrsMgr_TOP_AllView", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_AllView)
		.value("PrsMgr_TOP_ProjectorDependant", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_ProjectorDependant)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_PresentableObject.hxx
	py::class_<PrsMgr_PresentableObject, opencascade::handle<PrsMgr_PresentableObject>, Standard_Transient> cls_PrsMgr_PresentableObject(mod, "PrsMgr_PresentableObject", "A framework to supply the Graphic3d structure of the object to be presented. On the first display request, this structure is created by calling the appropriate algorithm and retaining this frameworkfor further display. This abstract framework is inherited in Application Interactive Services (AIS), notably in: - AIS_InteractiveObject - AIS_ConnectedInteractive - AIS_MultipleConnectedInteractive - AIS_Shape Consequently, 3D presentation should be handled by the relevant daughter classes and their member functions in AIS. This is particularly true in the creation of new interactive objects.");
	cls_PrsMgr_PresentableObject.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentableObject::get_type_name, "None");
	cls_PrsMgr_PresentableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentableObject::get_type_descriptor, "None");
	cls_PrsMgr_PresentableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::DynamicType, "None");
	cls_PrsMgr_PresentableObject.def("Presentations", (PrsMgr_Presentations & (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::Presentations, "None");
	cls_PrsMgr_PresentableObject.def("TypeOfPresentation3d", (PrsMgr_TypeOfPresentation3d (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::TypeOfPresentation3d, "Returns information on whether the object accepts display in HLR mode or not.");
	cls_PrsMgr_PresentableObject.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::TransformPersistence, "Returns transform persistence of the presentable object.");
	cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence for this object.", py::arg("theTrsfPers"));
	cls_PrsMgr_PresentableObject.def("SetTransformPersistence", [](PrsMgr_PresentableObject &self, const Graphic3d_TransModeFlags a0) -> void { return self.SetTransformPersistence(a0); }, py::arg("theMode"));
	cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const Graphic3d_TransModeFlags, const gp_Pnt &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence Mode for this object. This function used to lock in object position, rotation and / or zooming relative to camera position. Object will be drawn in the origin set by thePoint parameter (except Graphic3d_TMF_TriedronPers flag - see description later). theMode should be: - Graphic3d_TMF_None - no persistence attributes (reset); - Graphic3d_TMF_ZoomPers - object doesn't resize; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_ZoomRotatePers - object doesn't resize and rotate; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_TriedronPers - object behaves like trihedron. If Graphic3d_TMF_TriedronPers or Graphic3d_TMF_2d persistence mode selected thePoint coordinates X and Y means: - X = 0.0, Y = 0.0 - center of view window; - X > 0.0, Y > 0.0 - right upper corner of view window; - X > 0.0, Y < 0.0 - right lower corner of view window; - X < 0.0, Y > 0.0 - left upper corner of view window; - X < 0.0, Y < 0.0 - left lower corner of view window. And Z coordinate defines the gap from border of view window (except center position).", py::arg("theMode"), py::arg("thePoint"));
	cls_PrsMgr_PresentableObject.def("GetTransformPersistenceMode", (Graphic3d_TransModeFlags (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::GetTransformPersistenceMode, "Gets Transform Persistence Mode for this object");
	cls_PrsMgr_PresentableObject.def("GetTransformPersistencePoint", (gp_Pnt (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::GetTransformPersistencePoint, "Gets point of transform persistence for this object");
	cls_PrsMgr_PresentableObject.def("SetTypeOfPresentation", (void (PrsMgr_PresentableObject::*)(const PrsMgr_TypeOfPresentation3d)) &PrsMgr_PresentableObject::SetTypeOfPresentation, "None", py::arg("aType"));
	cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)(const Standard_Integer)) &PrsMgr_PresentableObject::SetToUpdate, "flags the Prs of mode <AMode> to be Updated. the Update will be done when needed.", py::arg("aMode"));
	cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::SetToUpdate, "flags all the Presentations to be Updated.");
	cls_PrsMgr_PresentableObject.def("ToBeUpdated", (void (PrsMgr_PresentableObject::*)(TColStd_ListOfInteger &) const ) &PrsMgr_PresentableObject::ToBeUpdated, "gives the list of modes which are flagged 'to be updated'.", py::arg("ListOfMode"));
	cls_PrsMgr_PresentableObject.def("LocalTransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::LocalTransformationGeom, "Return the local transformation.");
	cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const gp_Trsf &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation.", py::arg("theTrsf"));
	cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Geom_Transformation> &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation.", py::arg("theTrsf"));
	cls_PrsMgr_PresentableObject.def("HasTransformation", (Standard_Boolean (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::HasTransformation, "Returns true if object has a transformation that is different from the identity.");
	cls_PrsMgr_PresentableObject.def("TransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::TransformationGeom, "Return the transformation taking into account transformation of parent object(s).");
	cls_PrsMgr_PresentableObject.def("LocalTransformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::LocalTransformation, "Return the local transformation.");
	cls_PrsMgr_PresentableObject.def("Transformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::Transformation, "Return the transformation taking into account transformation of parent object(s).");
	cls_PrsMgr_PresentableObject.def("InversedTransformation", (const gp_GTrsf & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::InversedTransformation, "None");
	cls_PrsMgr_PresentableObject.def("ResetTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::ResetTransformation, "resets local transformation to identity.");
	cls_PrsMgr_PresentableObject.def("UpdateTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UpdateTransformation, "None");
	cls_PrsMgr_PresentableObject.def("UpdateTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Presentation> &)) &PrsMgr_PresentableObject::UpdateTransformation, "None", py::arg("P"));
	cls_PrsMgr_PresentableObject.def("SetZLayer", (void (PrsMgr_PresentableObject::*)(const Graphic3d_ZLayerId)) &PrsMgr_PresentableObject::SetZLayer, "Set Z layer ID and update all presentations of the presentable object. The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.", py::arg("theLayerId"));
	cls_PrsMgr_PresentableObject.def("ZLayer", (Graphic3d_ZLayerId (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::ZLayer, "Get ID of Z layer.");
	cls_PrsMgr_PresentableObject.def("AddClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::AddClipPlane, "Adds clip plane for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be substracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlane"));
	cls_PrsMgr_PresentableObject.def("RemoveClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::RemoveClipPlane, "Removes previously added clip plane.", py::arg("thePlane"));
	cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &PrsMgr_PresentableObject::SetClipPlanes, "Set clip planes for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be subtracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlanes"));
	cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const Graphic3d_SequenceOfHClipPlane &)) &PrsMgr_PresentableObject::SetClipPlanes, "None", py::arg("thePlanes"));
	cls_PrsMgr_PresentableObject.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::ClipPlanes, "Get clip planes.");
	cls_PrsMgr_PresentableObject.def("SetMutable", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetMutable, "Sets if the object has mutable nature (content or location will be changed regularly). This method should be called before object displaying to take effect.", py::arg("theIsMutable"));
	cls_PrsMgr_PresentableObject.def("IsMutable", (Standard_Boolean (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::IsMutable, "Returns true if object has mutable nature (content or location are be changed regularly). Mutable object will be managed in different way than static once (another optimizations).");
	cls_PrsMgr_PresentableObject.def("AddChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::AddChild, "Makes theObject child of current object in scene hierarchy.", py::arg("theObject"));
	cls_PrsMgr_PresentableObject.def("RemoveChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::RemoveChild, "Removes theObject from children of current object in scene hierarchy.", py::arg("theObject"));
	cls_PrsMgr_PresentableObject.def("Children", (const PrsMgr_ListOfPresentableObjects & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::Children, "Returns children of the current object.");
	cls_PrsMgr_PresentableObject.def("HasOwnPresentations", (Standard_Boolean (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::HasOwnPresentations, "Returns true if object should have own presentations.");
	cls_PrsMgr_PresentableObject.def("Parent", (PrsMgr_PresentableObjectPointer (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::Parent, "Returns parent of current object in scene hierarchy.");
	cls_PrsMgr_PresentableObject.def("SetAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetAttributes, "Initializes the drawing tool theDrawer.", py::arg("theDrawer"));
	cls_PrsMgr_PresentableObject.def("Attributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::Attributes, "Returns the attributes settings.");
	cls_PrsMgr_PresentableObject.def("UnsetAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetAttributes, "Clears settings provided by the drawing tool theDrawer.");
	cls_PrsMgr_PresentableObject.def("HilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::HilightAttributes, "Returns the highlight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalSelected and Prs3d_TypeOfHighlight_Selected defined within AIS_InteractiveContext.");
	cls_PrsMgr_PresentableObject.def("SetHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetHilightAttributes, "Initializes the highlight drawing tool theDrawer.", py::arg("theDrawer"));
	cls_PrsMgr_PresentableObject.def("DynamicHilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const ) &PrsMgr_PresentableObject::DynamicHilightAttributes, "Returns the highlight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalDynamic and Prs3d_TypeOfHighlight_Dynamic defined within AIS_InteractiveContext.");
	cls_PrsMgr_PresentableObject.def("SetDynamicHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetDynamicHilightAttributes, "Initializes the dynamic highlight drawing tool.", py::arg("theDrawer"));
	cls_PrsMgr_PresentableObject.def("UnsetHilightAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetHilightAttributes, "Clears settings provided by the highlight drawing tool theDrawer.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_Presentation.hxx
	py::class_<PrsMgr_Presentation, opencascade::handle<PrsMgr_Presentation>, Standard_Transient> cls_PrsMgr_Presentation(mod, "PrsMgr_Presentation", "None");
	cls_PrsMgr_Presentation.def_static("get_type_name_", (const char * (*)()) &PrsMgr_Presentation::get_type_name, "None");
	cls_PrsMgr_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_Presentation::get_type_descriptor, "None");
	cls_PrsMgr_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_Presentation::*)() const ) &PrsMgr_Presentation::DynamicType, "None");
	cls_PrsMgr_Presentation.def("Presentation", (const opencascade::handle<Prs3d_Presentation> & (PrsMgr_Presentation::*)() const ) &PrsMgr_Presentation::Presentation, "None");
	cls_PrsMgr_Presentation.def("PresentationManager", (const opencascade::handle<PrsMgr_PresentationManager> & (PrsMgr_Presentation::*)() const ) &PrsMgr_Presentation::PresentationManager, "returns the PresentationManager in which the presentation has been created.");
	cls_PrsMgr_Presentation.def("SetUpdateStatus", (void (PrsMgr_Presentation::*)(const Standard_Boolean)) &PrsMgr_Presentation::SetUpdateStatus, "None", py::arg("theUpdateStatus"));
	cls_PrsMgr_Presentation.def("MustBeUpdated", (Standard_Boolean (PrsMgr_Presentation::*)() const ) &PrsMgr_Presentation::MustBeUpdated, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_PresentationManager.hxx
	py::class_<PrsMgr_PresentationManager, opencascade::handle<PrsMgr_PresentationManager>, Standard_Transient> cls_PrsMgr_PresentationManager(mod, "PrsMgr_PresentationManager", "A framework to manage 3D displays, graphic entities and their updates. Used in the AIS package (Application Interactive Services), to enable the advanced user to define the default display mode of a new interactive object which extends the list of signatures and types. Definition of new display types is handled by calling the presentation algorithms provided by the StdPrs package.");
	cls_PrsMgr_PresentationManager.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theStructureManager"));
	cls_PrsMgr_PresentationManager.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentationManager::get_type_name, "None");
	cls_PrsMgr_PresentationManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentationManager::get_type_descriptor, "None");
	cls_PrsMgr_PresentationManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentationManager::*)() const ) &PrsMgr_PresentationManager::DynamicType, "None");
	cls_PrsMgr_PresentationManager.def("Display", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Display(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Display", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Display, "Displays the presentation of the object in the given Presentation manager with the given mode. The mode should be enumerated by the object which inherits PresentableObject.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Erase", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Erase(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Erase", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Erase, "erases the presentation of the object in the given Presentation manager with the given mode. If is -1, then erases all presentations of the object.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Clear", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Clear(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Clear", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Clear, "Clears the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("SetVisibility", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean)) &PrsMgr_PresentationManager::SetVisibility, "Sets the visibility of presentable object.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theValue"));
	cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::Unhighlight, "Removes highlighting from the presentation of the presentable object.", py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Unhighlight", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::Unhighlight, "None", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("SetDisplayPriority", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer) const ) &PrsMgr_PresentationManager::SetDisplayPriority, "Sets the display priority theNewPrior of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theNewPrior"));
	cls_PrsMgr_PresentationManager.def("DisplayPriority", (Standard_Integer (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const ) &PrsMgr_PresentationManager::DisplayPriority, "Returns the display priority of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("SetZLayer", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer)) &PrsMgr_PresentationManager::SetZLayer, "Set Z layer ID for all presentations of the object.", py::arg("thePrsObject"), py::arg("theLayerId"));
	cls_PrsMgr_PresentationManager.def("GetZLayer", (Standard_Integer (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &) const ) &PrsMgr_PresentationManager::GetZLayer, "Get Z layer ID assigned to all presentations of the object. Method returns -1 value if object has no presentations and is impossible to get layer index.", py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("IsDisplayed", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsDisplayed(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("IsDisplayed", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const ) &PrsMgr_PresentationManager::IsDisplayed, "None", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("IsHighlighted", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.IsHighlighted(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("IsHighlighted", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const ) &PrsMgr_PresentationManager::IsHighlighted, "Returns true if the presentation of the presentable object thePrsObject in this framework with the display mode theMode is highlighted.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Update", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> void { return self.Update(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Update", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const ) &PrsMgr_PresentationManager::Update, "Updates the presentation of the presentable object thePrsObject in this framework with the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("BeginImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::BeginImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode and begins accumulation of new list by following AddToImmediateList()/Color()/Highlight() calls.");
	cls_PrsMgr_PresentationManager.def("ClearImmediateDraw", (void (PrsMgr_PresentationManager::*)()) &PrsMgr_PresentationManager::ClearImmediateDraw, "Resets the transient list of presentations previously displayed in immediate mode.");
	cls_PrsMgr_PresentationManager.def("AddToImmediateList", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<Prs3d_Presentation> &)) &PrsMgr_PresentationManager::AddToImmediateList, "Stores thePrs in the transient list of presentations to be displayed in immediate mode. Will be taken in account in EndImmediateDraw method.", py::arg("thePrs"));
	cls_PrsMgr_PresentationManager.def("EndImmediateDraw", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::EndImmediateDraw, "Allows rapid drawing of the each view in theViewer by avoiding an update of the whole background.", py::arg("theViewer"));
	cls_PrsMgr_PresentationManager.def("RedrawImmediate", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &)) &PrsMgr_PresentationManager::RedrawImmediate, "Clears and redisplays immediate structures of the viewer taking into account its affinity.", py::arg("theViewer"));
	cls_PrsMgr_PresentationManager.def("IsImmediateModeOn", (Standard_Boolean (PrsMgr_PresentationManager::*)() const ) &PrsMgr_PresentationManager::IsImmediateModeOn, "Returns true if Presentation Manager is accumulating transient list of presentations to be displayed in immediate mode.");
	cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.Color(a0, a1); }, py::arg("thePrsObject"), py::arg("theStyle"));
	cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2) -> void { return self.Color(a0, a1, a2); }, py::arg("thePrsObject"), py::arg("theStyle"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Color", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const Standard_Integer a2, const opencascade::handle<PrsMgr_PresentableObject> & a3) -> void { return self.Color(a0, a1, a2, a3); }, py::arg("thePrsObject"), py::arg("theStyle"), py::arg("theMode"), py::arg("theSelObj"));
	cls_PrsMgr_PresentationManager.def("Color", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &, const Graphic3d_ZLayerId)) &PrsMgr_PresentationManager::Color, "Highlights the graphic object thePrsObject in the color theColor. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theStyle"), py::arg("theMode"), py::arg("theSelObj"), py::arg("theImmediateStructLayerId"));
	cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.Connect(a0, a1); }, py::arg("thePrsObject"), py::arg("theOtherObject"));
	cls_PrsMgr_PresentationManager.def("Connect", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.Connect(a0, a1, a2); }, py::arg("thePrsObject"), py::arg("theOtherObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Connect", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Integer)) &PrsMgr_PresentationManager::Connect, "None", py::arg("thePrsObject"), py::arg("theOtherObject"), py::arg("theMode"), py::arg("theOtherMode"));
	cls_PrsMgr_PresentationManager.def("Transform", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const opencascade::handle<Geom_Transformation> & a1) -> void { return self.Transform(a0, a1); }, py::arg("thePrsObject"), py::arg("theTransformation"));
	cls_PrsMgr_PresentationManager.def("Transform", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const opencascade::handle<Geom_Transformation> &, const Standard_Integer)) &PrsMgr_PresentationManager::Transform, "Sets the transformation theTransformation for the presentable object thePrsObject. thePrsObject has the display mode theMode; this has the default value of 0, that is, the wireframe display mode.", py::arg("thePrsObject"), py::arg("theTransformation"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("StructureManager", (const opencascade::handle<Graphic3d_StructureManager> & (PrsMgr_PresentationManager::*)() const ) &PrsMgr_PresentationManager::StructureManager, "Returns the structure manager.");
	cls_PrsMgr_PresentationManager.def("HasPresentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> Standard_Boolean { return self.HasPresentation(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("HasPresentation", (Standard_Boolean (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer) const ) &PrsMgr_PresentationManager::HasPresentation, "Returns true if there is a presentation of the presentable object thePrsObject in this framework, thePrsObject having the display mode theMode.", py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0); }, py::arg("thePrsObject"));
	cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1); }, py::arg("thePrsObject"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("Presentation", [](PrsMgr_PresentationManager &self, const opencascade::handle<PrsMgr_PresentableObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> opencascade::handle<PrsMgr_Presentation> { return self.Presentation(a0, a1, a2); }, py::arg("thePrsObject"), py::arg("theMode"), py::arg("theToCreate"));
	cls_PrsMgr_PresentationManager.def("Presentation", (opencascade::handle<PrsMgr_Presentation> (PrsMgr_PresentationManager::*)(const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const Standard_Boolean, const opencascade::handle<PrsMgr_PresentableObject> &) const ) &PrsMgr_PresentationManager::Presentation, "Returns the presentation Presentation of the presentable object thePrsObject in this framework. When theToCreate is true - automatically creates presentation for specified mode when not exist. Optional argument theSelObj specifies parent decomposed object to inherit its view affinity.", py::arg("thePrsObject"), py::arg("theMode"), py::arg("theToCreate"), py::arg("theSelObj"));
	cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1) -> void { return self.UpdateHighlightTrsf(a0, a1); }, py::arg("theViewer"), py::arg("theObj"));
	cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", [](PrsMgr_PresentationManager &self, const opencascade::handle<V3d_Viewer> & a0, const opencascade::handle<PrsMgr_PresentableObject> & a1, const Standard_Integer a2) -> void { return self.UpdateHighlightTrsf(a0, a1, a2); }, py::arg("theViewer"), py::arg("theObj"), py::arg("theMode"));
	cls_PrsMgr_PresentationManager.def("UpdateHighlightTrsf", (void (PrsMgr_PresentationManager::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentableObject> &, const Standard_Integer, const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentationManager::UpdateHighlightTrsf, "Allows to apply location transformation to shadow highlight presentation immediately.", py::arg("theViewer"), py::arg("theObj"), py::arg("theMode"), py::arg("theSelObj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_Prs.hxx
	py::class_<PrsMgr_Prs, opencascade::handle<PrsMgr_Prs>, Prs3d_Presentation> cls_PrsMgr_Prs(mod, "PrsMgr_Prs", "None");
	cls_PrsMgr_Prs.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const PrsMgr_PresentationPointer &, const PrsMgr_TypeOfPresentation3d>(), py::arg("theStructManager"), py::arg("thePresentation"), py::arg("theTypeOfPresentation3d"));
	cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)()) &PrsMgr_Prs::Compute, "None");
	cls_PrsMgr_Prs.def("Compute", (opencascade::handle<Graphic3d_Structure> (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &PrsMgr_Prs::Compute, "None", py::arg("aProjector"));
	cls_PrsMgr_Prs.def("Compute", (opencascade::handle<Graphic3d_Structure> (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &PrsMgr_Prs::Compute, "the 'degenerated' Structure is displayed with a transformation defined by <AMatrix> which is not a Pure Translation. We have to take in account this Transformation in the computation of hidden line removal... returns a filled Graphic Structure.", py::arg("theProjector"), py::arg("theTrsf"));
	cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &PrsMgr_Prs::Compute, "No need to return a structure, just to fill <ComputedStruct> ....", py::arg("aProjector"), py::arg("ComputedStruct"));
	cls_PrsMgr_Prs.def("Compute", (void (PrsMgr_Prs::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &PrsMgr_Prs::Compute, "No Need to return a Structure, just to Fill <aStructure>. The Trsf has to be taken in account in the computation (Rotation Part....)", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
	cls_PrsMgr_Prs.def_static("get_type_name_", (const char * (*)()) &PrsMgr_Prs::get_type_name, "None");
	cls_PrsMgr_Prs.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_Prs::get_type_descriptor, "None");
	cls_PrsMgr_Prs.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_Prs::*)() const ) &PrsMgr_Prs::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_ModedPresentation.hxx
	py::class_<PrsMgr_ModedPresentation, std::unique_ptr<PrsMgr_ModedPresentation, Deleter<PrsMgr_ModedPresentation>>> cls_PrsMgr_ModedPresentation(mod, "PrsMgr_ModedPresentation", "None");
	cls_PrsMgr_ModedPresentation.def(py::init<>());
	cls_PrsMgr_ModedPresentation.def(py::init<const opencascade::handle<PrsMgr_Presentation> &, const Standard_Integer>(), py::arg("thePrs"), py::arg("theMode"));
	cls_PrsMgr_ModedPresentation.def("Presentation", (const opencascade::handle<PrsMgr_Presentation> & (PrsMgr_ModedPresentation::*)() const ) &PrsMgr_ModedPresentation::Presentation, "None");
	cls_PrsMgr_ModedPresentation.def("Mode", (Standard_Integer (PrsMgr_ModedPresentation::*)() const ) &PrsMgr_ModedPresentation::Mode, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_ListOfPresentations.hxx
	bind_NCollection_List<opencascade::handle<Prs3d_Presentation> >(mod, "PrsMgr_ListOfPresentations");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_PresentationManager3d.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_ListOfPresentableObjects.hxx
	bind_NCollection_List<opencascade::handle<PrsMgr_PresentableObject> >(mod, "PrsMgr_ListOfPresentableObjects");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_ListOfPresentableObjects.hxx
	bind_NCollection_TListIterator<opencascade::handle<PrsMgr_PresentableObject> >(mod, "PrsMgr_ListOfPresentableObjectsIter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_PresentableObjectPointer.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_Presentations.hxx
	bind_NCollection_Sequence<PrsMgr_ModedPresentation>(mod, "PrsMgr_Presentations");

	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_Presentation3d.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\PrsMgr_PresentationPointer.hxx

}
