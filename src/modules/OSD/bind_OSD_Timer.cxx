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
#include <OSD_Chronometer.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <OSD_Timer.hxx>

void bind_OSD_Timer(py::module &mod){

py::class_<OSD_Timer, std::unique_ptr<OSD_Timer>, OSD_Chronometer> cls_OSD_Timer(mod, "OSD_Timer", "Working on heterogeneous platforms we need to use the system call gettimeofday. This function is portable and it measures ELAPSED time and CPU time in seconds and microseconds. Example: OSD_Timer aTimer; aTimer.Start(); // Start the timers (t1). ..... // Do something. aTimer.Stop(); // Stop the timers (t2). aTimer.Show(); // Give the elapsed time between t1 and t2. // Give also the process CPU time between // t1 and t2.");

// Constructors
cls_OSD_Timer.def(py::init<>());
cls_OSD_Timer.def(py::init<Standard_Boolean>(), py::arg("theThisThreadOnly"));

// Fields

// Methods
// cls_OSD_Timer.def_static("operator new_", (void * (*)(size_t)) &OSD_Timer::operator new, "None", py::arg("theSize"));
// cls_OSD_Timer.def_static("operator delete_", (void (*)(void *)) &OSD_Timer::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Timer::operator new[], "None", py::arg("theSize"));
// cls_OSD_Timer.def_static("operator delete[]_", (void (*)(void *)) &OSD_Timer::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Timer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Timer::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)(const Standard_Real)) &OSD_Timer::Reset, "Stops and reinitializes the timer with specified elapsed time.", py::arg("theTimeElapsedSec"));
cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)()) &OSD_Timer::Reset, "Stops and reinitializes the timer with zero elapsed time.");
cls_OSD_Timer.def("Restart", (void (OSD_Timer::*)()) &OSD_Timer::Restart, "Restarts the Timer.");
cls_OSD_Timer.def("Show", (void (OSD_Timer::*)() const) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the standard output stream <cout>.The chronometer can be running (Lap Time) or stopped.");
cls_OSD_Timer.def("Show", (void (OSD_Timer::*)(Standard_OStream &) const) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the output stream <OS>.", py::arg("os"));
cls_OSD_Timer.def("Show", [](OSD_Timer &self, Standard_Real & theSeconds, Standard_Integer & theMinutes, Standard_Integer & theHours, Standard_Real & theCPUtime){ self.Show(theSeconds, theMinutes, theHours, theCPUtime); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Integer &, Standard_Real &>(theSeconds, theMinutes, theHours, theCPUtime); }, "returns both the elapsed time(seconds,minutes,hours) and CPU time.", py::arg("theSeconds"), py::arg("theMinutes"), py::arg("theHours"), py::arg("theCPUtime"));
cls_OSD_Timer.def("Stop", (void (OSD_Timer::*)()) &OSD_Timer::Stop, "Stops the Timer.");
cls_OSD_Timer.def("Start", (void (OSD_Timer::*)()) &OSD_Timer::Start, "Starts (after Create or Reset) or restarts (after Stop) the Timer.");
cls_OSD_Timer.def("ElapsedTime", (Standard_Real (OSD_Timer::*)() const) &OSD_Timer::ElapsedTime, "Returns elapsed time in seconds.");

// Enums

}