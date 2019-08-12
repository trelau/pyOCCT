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
#include <OpenGl_FrameStats.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Workspace.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OSD_Timer.hxx>

void bind_OpenGl_FrameStats(py::module &mod){

py::class_<OpenGl_FrameStats, opencascade::handle<OpenGl_FrameStats>, Standard_Transient> cls_OpenGl_FrameStats(mod, "OpenGl_FrameStats", "Class storing the frame statistics.");

// Constructors
cls_OpenGl_FrameStats.def(py::init<>());

// Fields

// Methods
cls_OpenGl_FrameStats.def_static("get_type_name_", (const char * (*)()) &OpenGl_FrameStats::get_type_name, "None");
cls_OpenGl_FrameStats.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_FrameStats::get_type_descriptor, "None");
cls_OpenGl_FrameStats.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::DynamicType, "None");
cls_OpenGl_FrameStats.def("UpdateInterval", (Standard_Real (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::UpdateInterval, "Returns interval in seconds for updating meters across several frames; 1 second by default.");
cls_OpenGl_FrameStats.def("SetUpdateInterval", (void (OpenGl_FrameStats::*)(Standard_Real)) &OpenGl_FrameStats::SetUpdateInterval, "Sets interval in seconds for updating values.", py::arg("theInterval"));
cls_OpenGl_FrameStats.def("IsLongLineFormat", (Standard_Boolean (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::IsLongLineFormat, "Prefer longer lines over more greater of lines.");
cls_OpenGl_FrameStats.def("SetLongLineFormat", (void (OpenGl_FrameStats::*)(Standard_Boolean)) &OpenGl_FrameStats::SetLongLineFormat, "Set if format should prefer longer lines over greater number of lines.", py::arg("theValue"));
cls_OpenGl_FrameStats.def("FrameStart", [](OpenGl_FrameStats &self) -> void { return self.FrameStart(); });
cls_OpenGl_FrameStats.def("FrameStart", (void (OpenGl_FrameStats::*)(const opencascade::handle<OpenGl_Workspace> &)) &OpenGl_FrameStats::FrameStart, "Frame redraw started.", py::arg("theWorkspace"));
cls_OpenGl_FrameStats.def("FrameEnd", [](OpenGl_FrameStats &self) -> void { return self.FrameEnd(); });
cls_OpenGl_FrameStats.def("FrameEnd", (void (OpenGl_FrameStats::*)(const opencascade::handle<OpenGl_Workspace> &)) &OpenGl_FrameStats::FrameEnd, "Frame redraw finished.", py::arg("theWorkspace"));
cls_OpenGl_FrameStats.def("FormatStats", (TCollection_AsciiString (OpenGl_FrameStats::*)(Graphic3d_RenderingParams::PerfCounters) const) &OpenGl_FrameStats::FormatStats, "Returns formatted string.", py::arg("theFlags"));
cls_OpenGl_FrameStats.def("FrameDuration", (Standard_Real (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::FrameDuration, "Returns duration of the last frame in seconds.");
cls_OpenGl_FrameStats.def("FrameRate", (Standard_Real (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::FrameRate, "Returns FPS (frames per seconds, elapsed time). This number indicates an actual frame rate averaged for several frames within UpdateInterval() duration, basing on a real elapsed time between updates.");
cls_OpenGl_FrameStats.def("FrameRateCpu", (Standard_Real (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::FrameRateCpu, "Returns CPU FPS (frames per seconds, CPU time). This number indicates a PREDICTED frame rate, basing on CPU elapsed time between updates and NOT real elapsed time (which might include periods of CPU inactivity). Number is expected to be greater then actual frame rate returned by FrameRate(). Values significantly greater actual frame rate indicate that rendering is limited by GPU performance (CPU is stalled in-between), while values around actual frame rate indicate rendering being limited by CPU performance (GPU is stalled in-between).");
cls_OpenGl_FrameStats.def("CounterValue", (Standard_Size (OpenGl_FrameStats::*)(OpenGl_FrameStats::Counter) const) &OpenGl_FrameStats::CounterValue, "Returns value of specified counter, cached between stats updates. Should NOT be called between ::FrameStart() and ::FrameEnd() calls.", py::arg("theCounter"));
cls_OpenGl_FrameStats.def("HasCulledLayers", (Standard_Boolean (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::HasCulledLayers, "Returns TRUE if some Layers have been culled.");
cls_OpenGl_FrameStats.def("HasCulledStructs", (Standard_Boolean (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::HasCulledStructs, "Returns TRUE if some structures have been culled.");
cls_OpenGl_FrameStats.def("IsEqual", (Standard_Boolean (OpenGl_FrameStats::*)(const opencascade::handle<OpenGl_FrameStats> &) const) &OpenGl_FrameStats::IsEqual, "Returns TRUE if this stats are equal to another.", py::arg("theOther"));
cls_OpenGl_FrameStats.def("CopyFrom", (void (OpenGl_FrameStats::*)(const opencascade::handle<OpenGl_FrameStats> &)) &OpenGl_FrameStats::CopyFrom, "Copy stats values from another instance", py::arg("theOther"));
cls_OpenGl_FrameStats.def("ChangeCounter", (Standard_Size & (OpenGl_FrameStats::*)(OpenGl_FrameStats::Counter)) &OpenGl_FrameStats::ChangeCounter, "Returns value of specified counter for modification, should be called between ::FrameStart() and ::FrameEnd() calls.", py::arg("theCounter"));

// Enums
py::enum_<OpenGl_FrameStats::Counter>(cls_OpenGl_FrameStats, "Counter", "Stats counter.")
	.value("Counter_NbLayers", OpenGl_FrameStats::Counter::Counter_NbLayers)
	.value("Counter_NbLayersNotCulled", OpenGl_FrameStats::Counter::Counter_NbLayersNotCulled)
	.value("Counter_NbStructs", OpenGl_FrameStats::Counter::Counter_NbStructs)
	.value("Counter_NbStructsNotCulled", OpenGl_FrameStats::Counter::Counter_NbStructsNotCulled)
	.value("Counter_NbGroupsNotCulled", OpenGl_FrameStats::Counter::Counter_NbGroupsNotCulled)
	.value("Counter_NbElemsNotCulled", OpenGl_FrameStats::Counter::Counter_NbElemsNotCulled)
	.value("Counter_NbElemsFillNotCulled", OpenGl_FrameStats::Counter::Counter_NbElemsFillNotCulled)
	.value("Counter_NbElemsLineNotCulled", OpenGl_FrameStats::Counter::Counter_NbElemsLineNotCulled)
	.value("Counter_NbElemsPointNotCulled", OpenGl_FrameStats::Counter::Counter_NbElemsPointNotCulled)
	.value("Counter_NbElemsTextNotCulled", OpenGl_FrameStats::Counter::Counter_NbElemsTextNotCulled)
	.value("Counter_NbTrianglesNotCulled", OpenGl_FrameStats::Counter::Counter_NbTrianglesNotCulled)
	.value("Counter_NbPointsNotCulled", OpenGl_FrameStats::Counter::Counter_NbPointsNotCulled)
	.value("Counter_EstimatedBytesGeom", OpenGl_FrameStats::Counter::Counter_EstimatedBytesGeom)
	.value("Counter_EstimatedBytesFbos", OpenGl_FrameStats::Counter::Counter_EstimatedBytesFbos)
	.value("Counter_EstimatedBytesTextures", OpenGl_FrameStats::Counter::Counter_EstimatedBytesTextures)
	.export_values();
cls_OpenGl_FrameStats.attr("Counter_NB") = py::cast(int(OpenGl_FrameStats::Counter_NB));

}