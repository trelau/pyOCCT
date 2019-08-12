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
#include <PrsMgr_PresentableObject.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_Presentation.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_Presentations.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Geom_Transformation.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <PrsMgr_ListOfPresentableObjects.hxx>
#include <PrsMgr_PresentableObjectPointer.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Projector.hxx>

void bind_PrsMgr_PresentableObject(py::module &mod){

py::class_<PrsMgr_PresentableObject, opencascade::handle<PrsMgr_PresentableObject>, Standard_Transient> cls_PrsMgr_PresentableObject(mod, "PrsMgr_PresentableObject", "A framework to supply the Graphic3d structure of the object to be presented. On the first display request, this structure is created by calling the appropriate algorithm and retaining this frameworkfor further display. This abstract framework is inherited in Application Interactive Services (AIS), notably in: - AIS_InteractiveObject - AIS_ConnectedInteractive - AIS_MultipleConnectedInteractive - AIS_Shape Consequently, 3D presentation should be handled by the relevant daughter classes and their member functions in AIS. This is particularly true in the creation of new interactive objects.");

// Constructors

// Fields

// Methods
cls_PrsMgr_PresentableObject.def_static("get_type_name_", (const char * (*)()) &PrsMgr_PresentableObject::get_type_name, "None");
cls_PrsMgr_PresentableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PrsMgr_PresentableObject::get_type_descriptor, "None");
cls_PrsMgr_PresentableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DynamicType, "None");
cls_PrsMgr_PresentableObject.def("Presentations", (PrsMgr_Presentations & (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::Presentations, "None");
cls_PrsMgr_PresentableObject.def("TypeOfPresentation3d", (PrsMgr_TypeOfPresentation3d (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TypeOfPresentation3d, "Returns information on whether the object accepts display in HLR mode or not.");
cls_PrsMgr_PresentableObject.def("TransformPersistence", (const opencascade::handle<Graphic3d_TransformPers> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TransformPersistence, "Returns Transformation Persistence defining a special Local Coordinate system where this presentable object is located or NULL handle if not defined. Position of the object having Transformation Persistence is mutable and depends on camera position. The same applies to a bounding box of the object.");
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence defining a special Local Coordinate system where this object should be located. Note that management of Transform Persistence object is more expensive than of the normal one, because it requires its position being recomputed basing on camera position within each draw call / traverse.", py::arg("theTrsfPers"));
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", [](PrsMgr_PresentableObject &self, const Graphic3d_TransModeFlags a0) -> void { return self.SetTransformPersistence(a0); });
cls_PrsMgr_PresentableObject.def("SetTransformPersistence", (void (PrsMgr_PresentableObject::*)(const Graphic3d_TransModeFlags, const gp_Pnt &)) &PrsMgr_PresentableObject::SetTransformPersistence, "Sets up Transform Persistence Mode for this object. This function used to lock in object position, rotation and / or zooming relative to camera position. Object will be drawn in the origin setted by thePoint parameter (except Graphic3d_TMF_TriedronPers flag - see description later). theMode should be: - Graphic3d_TMF_None - no persistence attributes (reset); - Graphic3d_TMF_ZoomPers - object doesn't resize; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_ZoomRotatePers - object doesn't resize and rotate; - Graphic3d_TMF_RotatePers - object doesn't rotate; - Graphic3d_TMF_TriedronPers - object behaves like trihedron. If Graphic3d_TMF_TriedronPers or Graphic3d_TMF_2d persistence mode selected thePoint coordinates X and Y means: - X = 0.0, Y = 0.0 - center of view window; - X > 0.0, Y > 0.0 - right upper corner of view window; - X > 0.0, Y < 0.0 - right lower corner of view window; - X < 0.0, Y > 0.0 - left upper corner of view window; - X < 0.0, Y < 0.0 - left lower corner of view window. And Z coordinate defines the gap from border of view window (except center position).", py::arg("theMode"), py::arg("thePoint"));
cls_PrsMgr_PresentableObject.def("GetTransformPersistenceMode", (Graphic3d_TransModeFlags (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::GetTransformPersistenceMode, "Gets Transform Persistence Mode for this object");
cls_PrsMgr_PresentableObject.def("GetTransformPersistencePoint", (gp_Pnt (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::GetTransformPersistencePoint, "Gets point of transform persistence for this object");
cls_PrsMgr_PresentableObject.def("SetTypeOfPresentation", (void (PrsMgr_PresentableObject::*)(const PrsMgr_TypeOfPresentation3d)) &PrsMgr_PresentableObject::SetTypeOfPresentation, "None", py::arg("aType"));
cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)(const Standard_Integer)) &PrsMgr_PresentableObject::SetToUpdate, "flags the Prs of mode <AMode> to be Updated. the Update will be done when needed.", py::arg("aMode"));
cls_PrsMgr_PresentableObject.def("SetToUpdate", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::SetToUpdate, "flags all the Presentations to be Updated.");
cls_PrsMgr_PresentableObject.def("ToBeUpdated", (void (PrsMgr_PresentableObject::*)(TColStd_ListOfInteger &) const) &PrsMgr_PresentableObject::ToBeUpdated, "gives the list of modes which are flagged 'to be updated'.", py::arg("ListOfMode"));
cls_PrsMgr_PresentableObject.def("LocalTransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::LocalTransformationGeom, "Return the local transformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const gp_Trsf &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.", py::arg("theTrsf"));
cls_PrsMgr_PresentableObject.def("SetLocalTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Geom_Transformation> &)) &PrsMgr_PresentableObject::SetLocalTransformation, "Sets local transformation to theTransformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.", py::arg("theTrsf"));
cls_PrsMgr_PresentableObject.def("HasTransformation", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasTransformation, "Returns true if object has a transformation that is different from the identity.");
cls_PrsMgr_PresentableObject.def("TransformationGeom", (const opencascade::handle<Geom_Transformation> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::TransformationGeom, "Return the transformation taking into account transformation of parent object(s). Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("LocalTransformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::LocalTransformation, "Return the local transformation. Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("Transformation", (const gp_Trsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Transformation, "Return the transformation taking into account transformation of parent object(s). Note that the local transformation of the object having Transformation Persistence is applied within Local Coordinate system defined by this Persistence.");
cls_PrsMgr_PresentableObject.def("InversedTransformation", (const gp_GTrsf & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::InversedTransformation, "None");
cls_PrsMgr_PresentableObject.def("ResetTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::ResetTransformation, "resets local transformation to identity.");
cls_PrsMgr_PresentableObject.def("UpdateTransformation", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UpdateTransformation, "None");
cls_PrsMgr_PresentableObject.def("UpdateTransformation", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Presentation> &)) &PrsMgr_PresentableObject::UpdateTransformation, "None", py::arg("P"));
cls_PrsMgr_PresentableObject.def("SetZLayer", (void (PrsMgr_PresentableObject::*)(const Graphic3d_ZLayerId)) &PrsMgr_PresentableObject::SetZLayer, "Set Z layer ID and update all presentations of the presentable object. The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.", py::arg("theLayerId"));
cls_PrsMgr_PresentableObject.def("ZLayer", (Graphic3d_ZLayerId (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::ZLayer, "Get ID of Z layer.");
cls_PrsMgr_PresentableObject.def("AddClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::AddClipPlane, "Adds clip plane for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be substracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlane"));
cls_PrsMgr_PresentableObject.def("RemoveClipPlane", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &PrsMgr_PresentableObject::RemoveClipPlane, "Removes previously added clip plane.", py::arg("thePlane"));
cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &PrsMgr_PresentableObject::SetClipPlanes, "Set clip planes for graphical clipping for all display mode presentations. The composition of clip planes truncates the rendering space to convex volume. Please be aware that number of supported clip plane is limited. The planes which exceed the limit are ignored. Besides of this, some planes can be already set in view where the object is shown: the number of these planes should be subtracted from limit to predict the maximum possible number of object clipping planes.", py::arg("thePlanes"));
cls_PrsMgr_PresentableObject.def("SetClipPlanes", (void (PrsMgr_PresentableObject::*)(const Graphic3d_SequenceOfHClipPlane &)) &PrsMgr_PresentableObject::SetClipPlanes, "None", py::arg("thePlanes"));
cls_PrsMgr_PresentableObject.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::ClipPlanes, "Get clip planes.");
cls_PrsMgr_PresentableObject.def("SetMutable", (void (PrsMgr_PresentableObject::*)(const Standard_Boolean)) &PrsMgr_PresentableObject::SetMutable, "Sets if the object has mutable nature (content or location will be changed regularly). This method should be called before object displaying to take effect.", py::arg("theIsMutable"));
cls_PrsMgr_PresentableObject.def("IsMutable", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::IsMutable, "Returns true if object has mutable nature (content or location are be changed regularly). Mutable object will be managed in different way than static onces (another optimizations).");
cls_PrsMgr_PresentableObject.def("AddChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::AddChild, "Makes theObject child of current object in scene hierarchy.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("RemoveChild", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<PrsMgr_PresentableObject> &)) &PrsMgr_PresentableObject::RemoveChild, "Removes theObject from children of current object in scene hierarchy.", py::arg("theObject"));
cls_PrsMgr_PresentableObject.def("Children", (const PrsMgr_ListOfPresentableObjects & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Children, "Returns children of the current object.");
cls_PrsMgr_PresentableObject.def("HasOwnPresentations", (Standard_Boolean (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HasOwnPresentations, "Returns true if object should have own presentations.");
cls_PrsMgr_PresentableObject.def("Parent", (PrsMgr_PresentableObjectPointer (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Parent, "Returns parent of current object in scene hierarchy.");
cls_PrsMgr_PresentableObject.def("SetAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetAttributes, "Initializes the drawing tool theDrawer.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("Attributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::Attributes, "Returns the attributes settings.");
cls_PrsMgr_PresentableObject.def("UnsetAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetAttributes, "Clears settings provided by the drawing tool theDrawer.");
cls_PrsMgr_PresentableObject.def("HilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::HilightAttributes, "Returns the hilight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalSelected and Prs3d_TypeOfHighlight_Selected defined within AIS_InteractiveContext.");
cls_PrsMgr_PresentableObject.def("SetHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetHilightAttributes, "Initializes the hilight drawing tool theDrawer.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("DynamicHilightAttributes", (const opencascade::handle<Prs3d_Drawer> & (PrsMgr_PresentableObject::*)() const) &PrsMgr_PresentableObject::DynamicHilightAttributes, "Returns the hilight attributes settings. When not NULL, overrides both Prs3d_TypeOfHighlight_LocalDynamic and Prs3d_TypeOfHighlight_Dynamic defined within AIS_InteractiveContext.");
cls_PrsMgr_PresentableObject.def("SetDynamicHilightAttributes", (void (PrsMgr_PresentableObject::*)(const opencascade::handle<Prs3d_Drawer> &)) &PrsMgr_PresentableObject::SetDynamicHilightAttributes, "Initializes the dynamic hilight drawing tool.", py::arg("theDrawer"));
cls_PrsMgr_PresentableObject.def("UnsetHilightAttributes", (void (PrsMgr_PresentableObject::*)()) &PrsMgr_PresentableObject::UnsetHilightAttributes, "Clears settings provided by the hilight drawing tool theDrawer.");

// Enums

}