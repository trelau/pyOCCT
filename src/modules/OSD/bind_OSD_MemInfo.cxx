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
#include <TCollection_AsciiString.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OSD_MemInfo.hxx>

void bind_OSD_MemInfo(py::module &mod){

py::class_<OSD_MemInfo> cls_OSD_MemInfo(mod, "OSD_MemInfo", "This class provide information about memory utilized by current process. This information includes: - Private Memory - synthetic value that tries to filter out the memory usage only by the process itself (allocated for data and stack), excluding dynamic libraries. These pages may be in RAM or in SWAP. - Virtual Memory - amount of reserved and committed memory in the user-mode portion of the virtual address space. Notice that this counter includes reserved memory (not yet in used) and shared between processes memory (libraries). - Working Set - set of memory pages in the virtual address space of the process that are currently resident in physical memory (RAM). These pages are available for an application to use without triggering a page fault. - Pagefile Usage - space allocated for the pagefile, in bytes. Those pages may or may not be in memory (RAM) thus this counter couldn't be used to estimate how many active pages doesn't present in RAM.");

// Constructors
cls_OSD_MemInfo.def(py::init<>());

// Fields

// Methods
cls_OSD_MemInfo.def("Update", (void (OSD_MemInfo::*)()) &OSD_MemInfo::Update, "Update counters");
cls_OSD_MemInfo.def("ToString", (TCollection_AsciiString (OSD_MemInfo::*)() const) &OSD_MemInfo::ToString, "Return the string representation for all available counter.");
cls_OSD_MemInfo.def("Value", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const) &OSD_MemInfo::Value, "Return value or specified counter in bytes. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
cls_OSD_MemInfo.def("ValueMiB", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const) &OSD_MemInfo::ValueMiB, "Return value or specified counter in MiB. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
cls_OSD_MemInfo.def_static("PrintInfo_", (TCollection_AsciiString (*)()) &OSD_MemInfo::PrintInfo, "Return the string representation for all available counter.");

// Enums
py::enum_<OSD_MemInfo::Counter>(cls_OSD_MemInfo, "Counter", "None")
	.value("MemPrivate", OSD_MemInfo::Counter::MemPrivate)
	.value("MemVirtual", OSD_MemInfo::Counter::MemVirtual)
	.value("MemWorkingSet", OSD_MemInfo::Counter::MemWorkingSet)
	.value("MemWorkingSetPeak", OSD_MemInfo::Counter::MemWorkingSetPeak)
	.value("MemSwapUsage", OSD_MemInfo::Counter::MemSwapUsage)
	.value("MemSwapUsagePeak", OSD_MemInfo::Counter::MemSwapUsagePeak)
	.value("MemHeapUsage", OSD_MemInfo::Counter::MemHeapUsage)
	.value("MemCounter_NB", OSD_MemInfo::Counter::MemCounter_NB)
	.export_values();

}