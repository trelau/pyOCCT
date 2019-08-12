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
#include <Graphic3d_TypeOfLimit.hxx>

void bind_Graphic3d_TypeOfLimit(py::module &mod){

py::enum_<Graphic3d_TypeOfLimit>(mod, "Graphic3d_TypeOfLimit", "Type of graphic resource limit.")
	.value("Graphic3d_TypeOfLimit_MaxNbLights", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbLights)
	.value("Graphic3d_TypeOfLimit_MaxNbClipPlanes", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbClipPlanes)
	.value("Graphic3d_TypeOfLimit_MaxNbViews", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxNbViews)
	.value("Graphic3d_TypeOfLimit_MaxTextureSize", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxTextureSize)
	.value("Graphic3d_TypeOfLimit_MaxCombinedTextureUnits", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxCombinedTextureUnits)
	.value("Graphic3d_TypeOfLimit_MaxMsaa", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_MaxMsaa)
	.value("Graphic3d_TypeOfLimit_HasRayTracing", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracing)
	.value("Graphic3d_TypeOfLimit_HasRayTracingTextures", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracingTextures)
	.value("Graphic3d_TypeOfLimit_HasRayTracingAdaptiveSampling", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasRayTracingAdaptiveSampling)
	.value("Graphic3d_TypeOfLimit_HasBlendedOit", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasBlendedOit)
	.value("Graphic3d_TypeOfLimit_HasBlendedOitMsaa", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_HasBlendedOitMsaa)
	.value("Graphic3d_TypeOfLimit_NB", Graphic3d_TypeOfLimit::Graphic3d_TypeOfLimit_NB)
	.export_values();


}