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
#include <OSD_MAllocHook.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Mutex.hxx>

void bind_OSD_MAllocHook(py::module &mod){

py::class_<OSD_MAllocHook, std::unique_ptr<OSD_MAllocHook, Deleter<OSD_MAllocHook>>> cls_OSD_MAllocHook(mod, "OSD_MAllocHook", "This class provides the possibility to set callback for memory allocation/deallocation. On MS Windows, it works only in Debug builds. It relies on the debug CRT function _CrtSetAllocHook (see MSDN for help).");

// Constructors

// Fields

// Methods
cls_OSD_MAllocHook.def_static("SetCallback_", (void (*)(OSD_MAllocHook::Callback *)) &OSD_MAllocHook::SetCallback, "Set handler of allocation/deallocation events", py::arg("theCB"));
cls_OSD_MAllocHook.def_static("GetCallback_", (OSD_MAllocHook::Callback * (*)()) &OSD_MAllocHook::GetCallback, "Get current handler of allocation/deallocation events");
cls_OSD_MAllocHook.def_static("GetLogFileHandler_", (OSD_MAllocHook::LogFileHandler * (*)()) &OSD_MAllocHook::GetLogFileHandler, "Get static instance of LogFileHandler handler");
cls_OSD_MAllocHook.def_static("GetCollectBySize_", (OSD_MAllocHook::CollectBySize * (*)()) &OSD_MAllocHook::GetCollectBySize, "Get static instance of CollectBySize handler");

// Enums

}