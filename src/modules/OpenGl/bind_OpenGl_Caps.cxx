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
#include <Standard_TypeDef.hxx>
#include <OpenGl_Caps.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_Caps(py::module &mod){

py::class_<OpenGl_Caps, opencascade::handle<OpenGl_Caps>, Standard_Transient> cls_OpenGl_Caps(mod, "OpenGl_Caps", "Class to define graphic driver capabilities. Notice that these options will be ignored if particular functionality does not provided by GL driver");

// Constructors
cls_OpenGl_Caps.def(py::init<>());

// Fields
cls_OpenGl_Caps.def_readwrite("vboDisable", &OpenGl_Caps::vboDisable, "flag permits VBO usage, will significantly affect performance (OFF by default)");
cls_OpenGl_Caps.def_readwrite("pntSpritesDisable", &OpenGl_Caps::pntSpritesDisable, "flag permits Point Sprites usage, will significantly affect performance (OFF by default)");
cls_OpenGl_Caps.def_readwrite("keepArrayData", &OpenGl_Caps::keepArrayData, "Disables freeing CPU memory after building VBOs (OFF by default)");
cls_OpenGl_Caps.def_readwrite("ffpEnable", &OpenGl_Caps::ffpEnable, "Enables FFP (fixed-function pipeline), do not use built-in GLSL programs (ON by default on desktop OpenGL and OFF on OpenGL ES)");
cls_OpenGl_Caps.def_readwrite("useSystemBuffer", &OpenGl_Caps::useSystemBuffer, "Enables usage of system backbuffer for blitting (OFF by default on desktop OpenGL and ON on OpenGL ES for testing)");
cls_OpenGl_Caps.def_readwrite("swapInterval", &OpenGl_Caps::swapInterval, "controls swap interval - 0 for VSync off and 1 for VSync on, 1 by default");
cls_OpenGl_Caps.def_readwrite("buffersNoSwap", &OpenGl_Caps::buffersNoSwap, "Specify that driver should not swap back/front buffers at the end of frame. Useful when OCCT Viewer is integrated into existing OpenGL rendering pipeline as part, thus swapping part is performed outside.");
cls_OpenGl_Caps.def_readwrite("contextStereo", &OpenGl_Caps::contextStereo, "Request stereoscopic context (with Quad Buffer). This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("contextDebug", &OpenGl_Caps::contextDebug, "Request debug GL context. This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("contextSyncDebug", &OpenGl_Caps::contextSyncDebug, "Request debug GL context to emit messages within main thread (when contextDebug is specified!).");
cls_OpenGl_Caps.def_readwrite("contextNoAccel", &OpenGl_Caps::contextNoAccel, "Disable hardware acceleration.");
cls_OpenGl_Caps.def_readwrite("contextCompatible", &OpenGl_Caps::contextCompatible, "Request backward-compatible GL context. This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("glslWarnings", &OpenGl_Caps::glslWarnings, "Print GLSL program compilation/linkage warnings, if any. OFF by default.");
cls_OpenGl_Caps.def_readwrite("suppressExtraMsg", &OpenGl_Caps::suppressExtraMsg, "Suppress redundant messages from debug GL context. ON by default.");

// Methods
// cls_OpenGl_Caps.def("operator=", (OpenGl_Caps & (OpenGl_Caps::*)(const OpenGl_Caps &)) &OpenGl_Caps::operator=, "Copy maker.", py::arg("theCopy"));
cls_OpenGl_Caps.def_static("get_type_name_", (const char * (*)()) &OpenGl_Caps::get_type_name, "None");
cls_OpenGl_Caps.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Caps::get_type_descriptor, "None");
cls_OpenGl_Caps.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Caps::*)() const) &OpenGl_Caps::DynamicType, "None");

// Enums

}