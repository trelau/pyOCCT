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
#include <OSD_Timer.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <MoniTool_Timer.hxx>
#include <MoniTool_DataMapOfTimer.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_Timer(py::module &mod){

py::class_<MoniTool_Timer, opencascade::handle<MoniTool_Timer>, Standard_Transient> cls_MoniTool_Timer(mod, "MoniTool_Timer", "Provides convenient service on global timers accessed by string name, mostly aimed for debugging purposes");

// Constructors
cls_MoniTool_Timer.def(py::init<>());

// Fields

// Methods
cls_MoniTool_Timer.def("Timer", (const OSD_Timer & (MoniTool_Timer::*)() const) &MoniTool_Timer::Timer, "None");
cls_MoniTool_Timer.def("Timer", (OSD_Timer & (MoniTool_Timer::*)()) &MoniTool_Timer::Timer, "Return reference to embedded OSD_Timer");
cls_MoniTool_Timer.def("Start", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Start, "None");
cls_MoniTool_Timer.def("Stop", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Stop, "None");
cls_MoniTool_Timer.def("Reset", (void (MoniTool_Timer::*)()) &MoniTool_Timer::Reset, "Start, Stop and reset the timer In addition to doing that to embedded OSD_Timer, manage also counter of hits");
cls_MoniTool_Timer.def("Count", (Standard_Integer (MoniTool_Timer::*)() const) &MoniTool_Timer::Count, "Return value of hits counter (count of Start/Stop pairs)");
cls_MoniTool_Timer.def("IsRunning", (Standard_Integer (MoniTool_Timer::*)() const) &MoniTool_Timer::IsRunning, "Returns value of nesting counter");
cls_MoniTool_Timer.def("CPU", (Standard_Real (MoniTool_Timer::*)()) &MoniTool_Timer::CPU, "Return value of CPU time minus accumulated amendment");
cls_MoniTool_Timer.def("Amend", (Standard_Real (MoniTool_Timer::*)() const) &MoniTool_Timer::Amend, "Return value of accumulated amendment on CPU time");
cls_MoniTool_Timer.def("Dump", (void (MoniTool_Timer::*)(Standard_OStream &)) &MoniTool_Timer::Dump, "Dumps current state of a timer shortly (one-line output)", py::arg("ostr"));
cls_MoniTool_Timer.def_static("Timer_", (opencascade::handle<MoniTool_Timer> (*)(const Standard_CString)) &MoniTool_Timer::Timer, "Returns a timer from a dictionary by its name If timer not existed, creates a new one", py::arg("name"));
cls_MoniTool_Timer.def_static("Start_", (void (*)(const Standard_CString)) &MoniTool_Timer::Start, "None", py::arg("name"));
cls_MoniTool_Timer.def_static("Stop_", (void (*)(const Standard_CString)) &MoniTool_Timer::Stop, "Inline methods to conveniently start/stop timer by name Shortcut to Timer(name)->Start/Stop()", py::arg("name"));
cls_MoniTool_Timer.def_static("Dictionary_", (MoniTool_DataMapOfTimer & (*)()) &MoniTool_Timer::Dictionary, "Returns map of timers");
cls_MoniTool_Timer.def_static("ClearTimers_", (void (*)()) &MoniTool_Timer::ClearTimers, "Clears map of timers");
cls_MoniTool_Timer.def_static("DumpTimers_", (void (*)(Standard_OStream &)) &MoniTool_Timer::DumpTimers, "Dumps contents of the whole dictionary", py::arg("ostr"));
cls_MoniTool_Timer.def_static("ComputeAmendments_", (void (*)()) &MoniTool_Timer::ComputeAmendments, "Computes and remembers amendments for times to access, start, and stop of timer, and estimates second-order error measured by 10 nested timers");
cls_MoniTool_Timer.def_static("GetAmendments_", [](Standard_Real & Access, Standard_Real & Internal, Standard_Real & External, Standard_Real & Error10){ MoniTool_Timer::GetAmendments(Access, Internal, External, Error10); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Access, Internal, External, Error10); }, "The computed amendmens are returned (for information only)", py::arg("Access"), py::arg("Internal"), py::arg("External"), py::arg("Error10"));
cls_MoniTool_Timer.def_static("get_type_name_", (const char * (*)()) &MoniTool_Timer::get_type_name, "None");
cls_MoniTool_Timer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_Timer::get_type_descriptor, "None");
cls_MoniTool_Timer.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_Timer::*)() const) &MoniTool_Timer::DynamicType, "None");

// Enums

}