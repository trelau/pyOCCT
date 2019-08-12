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
#include <AIS_Animation.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Sequence.hxx>
#include <AIS_AnimationTimer.hxx>

void bind_AIS_Animation(py::module &mod){

py::class_<AIS_Animation, opencascade::handle<AIS_Animation>, Standard_Transient> cls_AIS_Animation(mod, "AIS_Animation", "Class represents single animation. It is defined with: - Start time on the timeline started from 0, in seconds - Duration, in seconds - virtual method Update() for handling an update");

// Constructors
cls_AIS_Animation.def(py::init<const TCollection_AsciiString &>(), py::arg("theAnimationName"));

// Fields

// Methods
cls_AIS_Animation.def_static("get_type_name_", (const char * (*)()) &AIS_Animation::get_type_name, "None");
cls_AIS_Animation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Animation::get_type_descriptor, "None");
cls_AIS_Animation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Animation::*)() const) &AIS_Animation::DynamicType, "None");
cls_AIS_Animation.def("Name", (const TCollection_AsciiString & (AIS_Animation::*)() const) &AIS_Animation::Name, "Animation name.");
cls_AIS_Animation.def("StartPts", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::StartPts, "Returns start time of the animation in the timeline");
cls_AIS_Animation.def("SetStartPts", (void (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::SetStartPts, "Sets time limits for animation in the animation timeline", py::arg("thePtsStart"));
cls_AIS_Animation.def("Duration", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::Duration, "Returns duration of the animation in the timeline");
cls_AIS_Animation.def("UpdateTotalDuration", (void (AIS_Animation::*)()) &AIS_Animation::UpdateTotalDuration, "Update total duration considering all animations on timeline.");
cls_AIS_Animation.def("HasOwnDuration", (Standard_Boolean (AIS_Animation::*)() const) &AIS_Animation::HasOwnDuration, "Return true if duration is defined.");
cls_AIS_Animation.def("OwnDuration", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::OwnDuration, "Returns own duration of the animation in the timeline");
cls_AIS_Animation.def("SetOwnDuration", (void (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::SetOwnDuration, "Defines duration of the animation.", py::arg("theDuration"));
cls_AIS_Animation.def("Add", (void (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Add, "Add single animation to the timeline.", py::arg("theAnimation"));
cls_AIS_Animation.def("Clear", (void (AIS_Animation::*)()) &AIS_Animation::Clear, "Clear animation timeline - remove all animations from it.");
cls_AIS_Animation.def("Find", (opencascade::handle<AIS_Animation> (AIS_Animation::*)(const TCollection_AsciiString &) const) &AIS_Animation::Find, "Return the child animation with the given name.", py::arg("theAnimationName"));
cls_AIS_Animation.def("Remove", (Standard_Boolean (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Remove, "Remove the child animation.", py::arg("theAnimation"));
cls_AIS_Animation.def("Replace", (Standard_Boolean (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &, const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Replace, "Replace the child animation.", py::arg("theAnimationOld"), py::arg("theAnimationNew"));
cls_AIS_Animation.def("CopyFrom", (void (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::CopyFrom, "Clears own children and then copy child animations from another object. Copy also Start Time and Duration values.", py::arg("theOther"));
cls_AIS_Animation.def("Children", (const NCollection_Sequence<opencascade::handle<AIS_Animation> > & (AIS_Animation::*)() const) &AIS_Animation::Children, "Return sequence of child animations.");
cls_AIS_Animation.def("StartTimer", [](AIS_Animation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.StartTimer(a0, a1, a2); });
cls_AIS_Animation.def("StartTimer", (void (AIS_Animation::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &AIS_Animation::StartTimer, "Start animation with internally defined timer instance. Calls ::Start() internally.", py::arg("theStartPts"), py::arg("thePlaySpeed"), py::arg("theToUpdate"), py::arg("theToStopTimer"));
cls_AIS_Animation.def("UpdateTimer", (Standard_Real (AIS_Animation::*)()) &AIS_Animation::UpdateTimer, "Update single frame of animation, update timer state");
cls_AIS_Animation.def("ElapsedTime", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::ElapsedTime, "Return elapsed time.");
cls_AIS_Animation.def("Start", (void (AIS_Animation::*)(const Standard_Boolean)) &AIS_Animation::Start, "Start animation. This method changes status of the animation to Started. This status defines whether animation is to be performed in the timeline or not.", py::arg("theToUpdate"));
cls_AIS_Animation.def("Pause", (void (AIS_Animation::*)()) &AIS_Animation::Pause, "Pause the process timeline.");
cls_AIS_Animation.def("Stop", (void (AIS_Animation::*)()) &AIS_Animation::Stop, "Stop animation. This method changed status of the animation to Stopped. This status shows that animation will not be performed in the timeline or it is finished.");
cls_AIS_Animation.def("IsStopped", (bool (AIS_Animation::*)()) &AIS_Animation::IsStopped, "Check if animation is to be performed in the animation timeline.");
cls_AIS_Animation.def("Update", (Standard_Boolean (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::Update, "Update single frame of animation, update timer state", py::arg("thePts"));

// Enums

}