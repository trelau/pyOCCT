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
#include <Graphic3d_DiagnosticInfo.hxx>

void bind_Graphic3d_DiagnosticInfo(py::module &mod){

py::enum_<Graphic3d_DiagnosticInfo>(mod, "Graphic3d_DiagnosticInfo", "Diagnostic info categories bit flags.")
	.value("Graphic3d_DiagnosticInfo_Device", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Device)
	.value("Graphic3d_DiagnosticInfo_FrameBuffer", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_FrameBuffer)
	.value("Graphic3d_DiagnosticInfo_Limits", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Limits)
	.value("Graphic3d_DiagnosticInfo_Memory", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Memory)
	.value("Graphic3d_DiagnosticInfo_NativePlatform", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_NativePlatform)
	.value("Graphic3d_DiagnosticInfo_Extensions", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Extensions)
	.value("Graphic3d_DiagnosticInfo_Short", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Short)
	.value("Graphic3d_DiagnosticInfo_Basic", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Basic)
	.value("Graphic3d_DiagnosticInfo_Complete", Graphic3d_DiagnosticInfo::Graphic3d_DiagnosticInfo_Complete)
	.export_values();


}