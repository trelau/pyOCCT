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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <OSD_Chronometer.hxx>

void bind_OSD_Chronometer(py::module &mod){

py::class_<OSD_Chronometer, std::unique_ptr<OSD_Chronometer, Deleter<OSD_Chronometer>>> cls_OSD_Chronometer(mod, "OSD_Chronometer", "This class measures CPU time (both user and system) consumed by current process or thread. The chronometer can be started and stopped multiple times, and measures cumulative time.");

// Constructors
cls_OSD_Chronometer.def(py::init<>());
cls_OSD_Chronometer.def(py::init<Standard_Boolean>(), py::arg("theThisThreadOnly"));

// Fields

// Methods
// cls_OSD_Chronometer.def_static("operator new_", (void * (*)(size_t)) &OSD_Chronometer::operator new, "None", py::arg("theSize"));
// cls_OSD_Chronometer.def_static("operator delete_", (void (*)(void *)) &OSD_Chronometer::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Chronometer::operator new[], "None", py::arg("theSize"));
// cls_OSD_Chronometer.def_static("operator delete[]_", (void (*)(void *)) &OSD_Chronometer::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Chronometer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Chronometer::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Chronometer.def("IsStarted", (Standard_Boolean (OSD_Chronometer::*)() const) &OSD_Chronometer::IsStarted, "Return true if timer has been started.");
cls_OSD_Chronometer.def("Reset", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Reset, "Stops and Reinitializes the Chronometer.");
cls_OSD_Chronometer.def("Restart", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Restart, "Restarts the Chronometer.");
cls_OSD_Chronometer.def("Stop", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Stop, "Stops the Chronometer.");
cls_OSD_Chronometer.def("Start", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Start, "Starts (after Create or Reset) or restarts (after Stop) the chronometer.");
cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)() const) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the standard output stream <cout>. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)(Standard_OStream &) const) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the output stream <os>. The chronometer can be running (laps Time) or stopped.", py::arg("theOStream"));
cls_OSD_Chronometer.def("UserTimeCPU", (Standard_Real (OSD_Chronometer::*)() const) &OSD_Chronometer::UserTimeCPU, "Returns the current CPU user time in seconds. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("SystemTimeCPU", (Standard_Real (OSD_Chronometer::*)() const) &OSD_Chronometer::SystemTimeCPU, "Returns the current CPU system time in seconds. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSeconds){ self.Show(theUserSeconds); return theUserSeconds; }, "Returns the current CPU user time in a variable. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSeconds"));
cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSec, Standard_Real & theSystemSec){ self.Show(theUserSec, theSystemSec); return std::tuple<Standard_Real &, Standard_Real &>(theUserSec, theSystemSec); }, "Returns the current CPU user and system time in variables. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSec"), py::arg("theSystemSec"));
cls_OSD_Chronometer.def_static("GetProcessCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetProcessCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current process since its start, in seconds. The actual precision of the measurement depends on granularity provided by the system, and is platform-specific.", py::arg("UserSeconds"), py::arg("SystemSeconds"));
cls_OSD_Chronometer.def_static("GetThreadCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetThreadCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current thread since its start. Note that this measurement is platform-specific, as threads are implemented and managed differently on different platforms and CPUs.", py::arg("UserSeconds"), py::arg("SystemSeconds"));

// Enums

}