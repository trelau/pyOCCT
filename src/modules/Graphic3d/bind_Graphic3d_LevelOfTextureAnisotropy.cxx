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
#include <Graphic3d_LevelOfTextureAnisotropy.hxx>

void bind_Graphic3d_LevelOfTextureAnisotropy(py::module &mod){

py::enum_<Graphic3d_LevelOfTextureAnisotropy>(mod, "Graphic3d_LevelOfTextureAnisotropy", "Level of anisotropy filter. Notice that actual quality depends on hardware capabilities!")
	.value("Graphic3d_LOTA_OFF", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_OFF)
	.value("Graphic3d_LOTA_FAST", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_FAST)
	.value("Graphic3d_LOTA_MIDDLE", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_MIDDLE)
	.value("Graphic3d_LOTA_QUALITY", Graphic3d_LevelOfTextureAnisotropy::Graphic3d_LOTA_QUALITY)
	.export_values();


}