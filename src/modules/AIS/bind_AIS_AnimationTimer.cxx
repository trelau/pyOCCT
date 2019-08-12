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
#include <AIS_AnimationTimer.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Timer.hxx>

void bind_AIS_AnimationTimer(py::module &mod){

py::class_<AIS_AnimationTimer, opencascade::handle<AIS_AnimationTimer>, Standard_Transient> cls_AIS_AnimationTimer(mod, "AIS_AnimationTimer", "Auxiliary class defining the animation timer.");

// Constructors
cls_AIS_AnimationTimer.def(py::init<>());

// Fields

// Methods
cls_AIS_AnimationTimer.def_static("get_type_name_", (const char * (*)()) &AIS_AnimationTimer::get_type_name, "None");
cls_AIS_AnimationTimer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AnimationTimer::get_type_descriptor, "None");
cls_AIS_AnimationTimer.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AnimationTimer::*)() const) &AIS_AnimationTimer::DynamicType, "None");
cls_AIS_AnimationTimer.def("ElapsedTime", (Standard_Real (AIS_AnimationTimer::*)() const) &AIS_AnimationTimer::ElapsedTime, "Return elapsed time in seconds.");
cls_AIS_AnimationTimer.def("PlaybackSpeed", (Standard_Real (AIS_AnimationTimer::*)() const) &AIS_AnimationTimer::PlaybackSpeed, "Return playback speed coefficient (1.0 means normal speed).");
cls_AIS_AnimationTimer.def("SetPlaybackSpeed", (void (AIS_AnimationTimer::*)(const Standard_Real)) &AIS_AnimationTimer::SetPlaybackSpeed, "Setup playback speed coefficient.", py::arg("theSpeed"));
cls_AIS_AnimationTimer.def("IsStarted", (Standard_Boolean (AIS_AnimationTimer::*)() const) &AIS_AnimationTimer::IsStarted, "Return true if timer has been started.");
cls_AIS_AnimationTimer.def("Start", (void (AIS_AnimationTimer::*)()) &AIS_AnimationTimer::Start, "Start the timer.");
cls_AIS_AnimationTimer.def("Pause", (void (AIS_AnimationTimer::*)()) &AIS_AnimationTimer::Pause, "Pause the timer.");
cls_AIS_AnimationTimer.def("Stop", (void (AIS_AnimationTimer::*)()) &AIS_AnimationTimer::Stop, "Stop the timer.");
cls_AIS_AnimationTimer.def("Seek", (void (AIS_AnimationTimer::*)(const Standard_Real)) &AIS_AnimationTimer::Seek, "Seek the timer to specified position.", py::arg("theTime"));

// Enums

}