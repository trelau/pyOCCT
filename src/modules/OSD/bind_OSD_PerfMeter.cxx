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
#include <OSD_PerfMeter.hxx>

void bind_OSD_PerfMeter(py::module &mod){

py::class_<OSD_PerfMeter> cls_OSD_PerfMeter(mod, "OSD_PerfMeter", "This class enables measuring the CPU time between two points of code execution, regardless of the scope of these points of code. A meter is identified by its name (string). So multiple objects in various places of user code may point to the same meter. The results will be printed on stdout upon finish of the program. For details see OSD_PerfMeter.h");

// Constructors
cls_OSD_PerfMeter.def(py::init<>());
cls_OSD_PerfMeter.def(py::init<const char *>(), py::arg("theMeter"));
cls_OSD_PerfMeter.def(py::init<const char *, const bool>(), py::arg("theMeter"), py::arg("theToAutoStart"));

// Fields

// Methods
cls_OSD_PerfMeter.def("Init", (void (OSD_PerfMeter::*)(const char *)) &OSD_PerfMeter::Init, "Prepares the named meter", py::arg("theMeter"));
cls_OSD_PerfMeter.def("Start", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Start, "Starts the meter");
cls_OSD_PerfMeter.def("Stop", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Stop, "Stops the meter");
cls_OSD_PerfMeter.def("Tick", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Tick, "Increments the counter w/o time measurement");
cls_OSD_PerfMeter.def("Flush", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Flush, "Outputs the meter data and resets it to initial state");

// Enums

}