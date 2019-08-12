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
#include <AIS_InteractiveObject.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_ManipulatorMode.hxx>
#include <AIS_Manipulator.hxx>
#include <Standard_Handle.hxx>
#include <V3d_View.hxx>
#include <gp_Trsf.hxx>
#include <Standard_ProgramError.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Graphic3d_Group.hxx>
#include <Bnd_Box.hxx>
#include <Geom_Transformation.hxx>
#include <Poly_Triangulation.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Quantity_Color.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Type.hxx>

void bind_AIS_Manipulator(py::module &mod){

py::class_<AIS_Manipulator, opencascade::handle<AIS_Manipulator>, AIS_InteractiveObject> cls_AIS_Manipulator(mod, "AIS_Manipulator", "Interactive object class to manipulate local transformation of another interactive object or a group of objects via mouse. It manages three types of manipulations in 3D space: - translation through axis - scaling within axis - rotation around axis To enable one of this modes, selection mode (from 1 to 3) is to be activated. There are three orthogonal transformation axes defined by position property of the manipulator. Particular transformation mode can be disabled for each of the axes or all of them. Furthermore each of the axes can be hidden or made visible. The following steps demonstrate how to attach, configure and use manipulator for an interactive object: Step 1. Create manipulator object and adjust it appearance: Note that you can enable only one manipulation mode but have all visual parts displayed. This code allows you to view manipulator and select its manipulation parts. Note that manipulator activates mode on part selection. If this mode is activated, no selection will be performed for manipulator. It can be activated with highlighting. To enable this: Step 2. To perform transformation of object use next code in your event processing chain: Step 3. To deactivate current manipulation mode use: Step 4. To detach manipulator from object use: The last method erases manipulator object.");

// Constructors
cls_AIS_Manipulator.def(py::init<>());
cls_AIS_Manipulator.def(py::init<const gp_Ax2 &>(), py::arg("thePosition"));

// Fields

// Methods
cls_AIS_Manipulator.def("SetPart", (void (AIS_Manipulator::*)(const Standard_Integer, const AIS_ManipulatorMode, const Standard_Boolean)) &AIS_Manipulator::SetPart, "Disable or enable visual parts for translation, rotation or scaling for some axis. By default all parts are enabled (will be displayed).", py::arg("theAxisIndex"), py::arg("theMode"), py::arg("theIsEnabled"));
cls_AIS_Manipulator.def("Attach", [](AIS_Manipulator &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Attach(a0); });
cls_AIS_Manipulator.def("Attach", (void (AIS_Manipulator::*)(const opencascade::handle<AIS_InteractiveObject> &, const AIS_Manipulator::OptionsForAttach &)) &AIS_Manipulator::Attach, "Attaches himself to the input interactive object and become displayed in the same context. It is placed in the center of object bounding box, and its size is adjusted to the object bounding box.", py::arg("theObject"), py::arg("theOptions"));
cls_AIS_Manipulator.def("Attach", [](AIS_Manipulator &self, const opencascade::handle<AIS_ManipulatorObjectSequence> & a0) -> void { return self.Attach(a0); });
cls_AIS_Manipulator.def("Attach", (void (AIS_Manipulator::*)(const opencascade::handle<AIS_ManipulatorObjectSequence> &, const AIS_Manipulator::OptionsForAttach &)) &AIS_Manipulator::Attach, "Attaches himself to the input interactive object group and become displayed in the same context. It become attached to the first object, baut manage manipulation of the whole group. It is placed in the center of object bounding box, and its size is adjusted to the object bounding box.", py::arg("theObject"), py::arg("theOptions"));
cls_AIS_Manipulator.def("EnableMode", (void (AIS_Manipulator::*)(const AIS_ManipulatorMode)) &AIS_Manipulator::EnableMode, "Enable manipualtion mode.", py::arg("theMode"));
cls_AIS_Manipulator.def("SetModeActivationOnDetection", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::SetModeActivationOnDetection, "Enables mode activation on detection (highlighting). By default, mode is activated on selection of manipulator part.", py::arg("theToEnable"));
cls_AIS_Manipulator.def("IsModeActivationOnDetection", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsModeActivationOnDetection, "Returns true if manual mode activation is enabled.");
cls_AIS_Manipulator.def("StartTransform", (void (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &AIS_Manipulator::StartTransform, "Init start (reference) transformation.", py::arg("theX"), py::arg("theY"), py::arg("theView"));
cls_AIS_Manipulator.def("Transform", (void (AIS_Manipulator::*)(const gp_Trsf &)) &AIS_Manipulator::Transform, "Apply to the owning objects the input transformation.", py::arg("aTrsf"));
cls_AIS_Manipulator.def("StopTransform", [](AIS_Manipulator &self) -> void { return self.StopTransform(); });
cls_AIS_Manipulator.def("StopTransform", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::StopTransform, "Reset start (reference) transformation.", py::arg("theToApply"));
cls_AIS_Manipulator.def("Transform", (gp_Trsf (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &AIS_Manipulator::Transform, "Apply transformation made from mouse moving from start position (save on the first Tranform() call and reset on DeactivateCurrentMode() call.) to the in/out mouse position (theX, theY)", py::arg("theX"), py::arg("theY"), py::arg("theView"));
cls_AIS_Manipulator.def("ObjectTransformation", (Standard_Boolean (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, gp_Trsf &)) &AIS_Manipulator::ObjectTransformation, "Computes transformation of parent object according to the active mode and input motion vector. You can use this method to get object transformation according to current mode or use own algorithm to implement any other tranformation for modes.", py::arg("theX"), py::arg("theY"), py::arg("theView"), py::arg("theTrsf"));
cls_AIS_Manipulator.def("DeactivateCurrentMode", (void (AIS_Manipulator::*)()) &AIS_Manipulator::DeactivateCurrentMode, "Make inactive the current selected manipulator part and reset current axis index and current mode. After its call HasActiveMode() returns false.");
cls_AIS_Manipulator.def("Detach", (void (AIS_Manipulator::*)()) &AIS_Manipulator::Detach, "Detaches himself from the owner object, and removes itself from context.");
cls_AIS_Manipulator.def("Objects", (opencascade::handle<AIS_ManipulatorObjectSequence> (AIS_Manipulator::*)() const) &AIS_Manipulator::Objects, "Returns all owning objects.");
cls_AIS_Manipulator.def("Object", (opencascade::handle<AIS_InteractiveObject> (AIS_Manipulator::*)() const) &AIS_Manipulator::Object, "Returns the first (leading) object of the owning objects.");
cls_AIS_Manipulator.def("Object", (opencascade::handle<AIS_InteractiveObject> (AIS_Manipulator::*)(const Standard_Integer) const) &AIS_Manipulator::Object, "Returns one of the owning objects. raises program error if theIndex is more than owning objects count or less than 1.", py::arg("theIndex"));
cls_AIS_Manipulator.def("IsAttached", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsAttached, "Returns true if manipulator is attached to some interactive object (has owning object).");
cls_AIS_Manipulator.def("HasActiveMode", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::HasActiveMode, "Returns true if some part of manipulator is selected (transformation mode is active, and owning object can be transformed).");
cls_AIS_Manipulator.def("HasActiveTransformation", (Standard_Boolean (AIS_Manipulator::*)()) &AIS_Manipulator::HasActiveTransformation, "None");
cls_AIS_Manipulator.def("StartTransformation", (gp_Trsf (AIS_Manipulator::*)() const) &AIS_Manipulator::StartTransformation, "None");
cls_AIS_Manipulator.def("StartTransformation", (gp_Trsf (AIS_Manipulator::*)(Standard_Integer) const) &AIS_Manipulator::StartTransformation, "None", py::arg("theIndex"));
cls_AIS_Manipulator.def("SetZoomPersistence", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::SetZoomPersistence, "Enable or disable zoom persistence mode for the manipulator. With this mode turned on the presentation will keep fixed screen size.", py::arg("theToEnable"));
cls_AIS_Manipulator.def("ZoomPersistence", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::ZoomPersistence, "Returns state of zoom persistence mode, whether it turned on or off.");
cls_AIS_Manipulator.def("SetTransformPersistence", (void (AIS_Manipulator::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_Manipulator::SetTransformPersistence, "Redefines transform persistence management to setup transformation for sub-presentation of axes.", py::arg("theTrsfPers"));
cls_AIS_Manipulator.def("ActiveMode", (AIS_ManipulatorMode (AIS_Manipulator::*)() const) &AIS_Manipulator::ActiveMode, "");
cls_AIS_Manipulator.def("Position", (const gp_Ax2 & (AIS_Manipulator::*)() const) &AIS_Manipulator::Position, "Returns poition of manipulator interactive object.");
cls_AIS_Manipulator.def("SetPosition", (void (AIS_Manipulator::*)(const gp_Ax2 &)) &AIS_Manipulator::SetPosition, "Sets position of the manipulator object.", py::arg("thePosition"));
cls_AIS_Manipulator.def("Size", (Standard_ShortReal (AIS_Manipulator::*)() const) &AIS_Manipulator::Size, "None");
cls_AIS_Manipulator.def("SetSize", (void (AIS_Manipulator::*)(const Standard_ShortReal)) &AIS_Manipulator::SetSize, "Sets size (length of side of the manipulator cubic bounding box.", py::arg("theSideLength"));
cls_AIS_Manipulator.def("SetGap", (void (AIS_Manipulator::*)(const Standard_ShortReal)) &AIS_Manipulator::SetGap, "Sets gaps between translator, scaler and rotator sub-presentations.", py::arg("theValue"));
cls_AIS_Manipulator.def("SetTransformBehavior", (void (AIS_Manipulator::*)(const AIS_Manipulator::BehaviorOnTransform &)) &AIS_Manipulator::SetTransformBehavior, "Sets behavior settings for transformation action carried on the manipulator, whether it translates, rotates together with the transformed object or not.", py::arg("theSettings"));
cls_AIS_Manipulator.def("ChangeTransformBehavior", (AIS_Manipulator::BehaviorOnTransform & (AIS_Manipulator::*)()) &AIS_Manipulator::ChangeTransformBehavior, "Returns behavior settings for transformation action of the manipulator.");
cls_AIS_Manipulator.def("TransformBehavior", (const AIS_Manipulator::BehaviorOnTransform & (AIS_Manipulator::*)() const) &AIS_Manipulator::TransformBehavior, "Returns behavior settings for transformation action of the manipulator.");
cls_AIS_Manipulator.def("Compute", [](AIS_Manipulator &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Presentation> & a1) -> void { return self.Compute(a0, a1); });
cls_AIS_Manipulator.def("Compute", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &AIS_Manipulator::Compute, "Fills presentation.", py::arg("thePrsMgr"), py::arg("thePrs"), py::arg("theMode"));
cls_AIS_Manipulator.def("ComputeSelection", (void (AIS_Manipulator::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_Manipulator::ComputeSelection, "Computes selection sensitive zones (triangulation) for manipulator.", py::arg("theSelection"), py::arg("theMode"));
cls_AIS_Manipulator.def("IsAutoHilight", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsAutoHilight, "Disables auto highlighting to use HilightSelected() and HilightOwnerWithColor() overridden methods.");
cls_AIS_Manipulator.def("ClearSelected", (void (AIS_Manipulator::*)()) &AIS_Manipulator::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw ).");
cls_AIS_Manipulator.def("HilightSelected", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &AIS_Manipulator::HilightSelected, "Method which draws selected owners ( for fast presentation draw ).", py::arg("thePM"), py::arg("theSeq"));
cls_AIS_Manipulator.def("HilightOwnerWithColor", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Manipulator::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw ).", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));
cls_AIS_Manipulator.def_static("get_type_name_", (const char * (*)()) &AIS_Manipulator::get_type_name, "None");
cls_AIS_Manipulator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Manipulator::get_type_descriptor, "None");
cls_AIS_Manipulator.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Manipulator::*)() const) &AIS_Manipulator::DynamicType, "None");

// Enums

}