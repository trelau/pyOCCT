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
#include <Graphic3d_NameOfTexture2D.hxx>

void bind_Graphic3d_NameOfTexture2D(py::module &mod){

py::enum_<Graphic3d_NameOfTexture2D>(mod, "Graphic3d_NameOfTexture2D", "Types of standard textures.")
	.value("Graphic3d_NOT_2D_MATRA", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MATRA)
	.value("Graphic3d_NOT_2D_ALIENSKIN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ALIENSKIN)
	.value("Graphic3d_NOT_2D_BLUE_ROCK", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BLUE_ROCK)
	.value("Graphic3d_NOT_2D_BLUEWHITE_PAPER", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BLUEWHITE_PAPER)
	.value("Graphic3d_NOT_2D_BRUSHED", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BRUSHED)
	.value("Graphic3d_NOT_2D_BUBBLES", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BUBBLES)
	.value("Graphic3d_NOT_2D_BUMP", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_BUMP)
	.value("Graphic3d_NOT_2D_CAST", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CAST)
	.value("Graphic3d_NOT_2D_CHIPBD", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CHIPBD)
	.value("Graphic3d_NOT_2D_CLOUDS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CLOUDS)
	.value("Graphic3d_NOT_2D_FLESH", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_FLESH)
	.value("Graphic3d_NOT_2D_FLOOR", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_FLOOR)
	.value("Graphic3d_NOT_2D_GALVNISD", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_GALVNISD)
	.value("Graphic3d_NOT_2D_GRASS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_GRASS)
	.value("Graphic3d_NOT_2D_ALUMINUM", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ALUMINUM)
	.value("Graphic3d_NOT_2D_ROCK", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_ROCK)
	.value("Graphic3d_NOT_2D_KNURL", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_KNURL)
	.value("Graphic3d_NOT_2D_MAPLE", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MAPLE)
	.value("Graphic3d_NOT_2D_MARBLE", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MARBLE)
	.value("Graphic3d_NOT_2D_MOTTLED", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_MOTTLED)
	.value("Graphic3d_NOT_2D_RAIN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_RAIN)
	.value("Graphic3d_NOT_2D_CHESS", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_CHESS)
	.value("Graphic3d_NOT_2D_UNKNOWN", Graphic3d_NameOfTexture2D::Graphic3d_NOT_2D_UNKNOWN)
	.export_values();


}