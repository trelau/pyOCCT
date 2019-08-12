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
#include <Graphic3d_TypeOfTextureMode.hxx>

void bind_Graphic3d_TypeOfTextureMode(py::module &mod){

py::enum_<Graphic3d_TypeOfTextureMode>(mod, "Graphic3d_TypeOfTextureMode", "Type of the texture projection.")
	.value("Graphic3d_TOTM_OBJECT", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_OBJECT)
	.value("Graphic3d_TOTM_SPHERE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_SPHERE)
	.value("Graphic3d_TOTM_EYE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_EYE)
	.value("Graphic3d_TOTM_MANUAL", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_MANUAL)
	.value("Graphic3d_TOTM_SPRITE", Graphic3d_TypeOfTextureMode::Graphic3d_TOTM_SPRITE)
	.export_values();


}