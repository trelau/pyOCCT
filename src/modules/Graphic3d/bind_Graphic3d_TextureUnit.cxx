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
#include <Graphic3d_TextureUnit.hxx>

void bind_Graphic3d_TextureUnit(py::module &mod){

py::enum_<Graphic3d_TextureUnit>(mod, "Graphic3d_TextureUnit", "Texture unit.")
	.value("Graphic3d_TextureUnit_0", Graphic3d_TextureUnit::Graphic3d_TextureUnit_0)
	.value("Graphic3d_TextureUnit_1", Graphic3d_TextureUnit::Graphic3d_TextureUnit_1)
	.value("Graphic3d_TextureUnit_2", Graphic3d_TextureUnit::Graphic3d_TextureUnit_2)
	.value("Graphic3d_TextureUnit_3", Graphic3d_TextureUnit::Graphic3d_TextureUnit_3)
	.value("Graphic3d_TextureUnit_4", Graphic3d_TextureUnit::Graphic3d_TextureUnit_4)
	.value("Graphic3d_TextureUnit_5", Graphic3d_TextureUnit::Graphic3d_TextureUnit_5)
	.value("Graphic3d_TextureUnit_6", Graphic3d_TextureUnit::Graphic3d_TextureUnit_6)
	.value("Graphic3d_TextureUnit_7", Graphic3d_TextureUnit::Graphic3d_TextureUnit_7)
	.value("Graphic3d_TextureUnit_8", Graphic3d_TextureUnit::Graphic3d_TextureUnit_8)
	.value("Graphic3d_TextureUnit_9", Graphic3d_TextureUnit::Graphic3d_TextureUnit_9)
	.value("Graphic3d_TextureUnit_10", Graphic3d_TextureUnit::Graphic3d_TextureUnit_10)
	.value("Graphic3d_TextureUnit_11", Graphic3d_TextureUnit::Graphic3d_TextureUnit_11)
	.value("Graphic3d_TextureUnit_12", Graphic3d_TextureUnit::Graphic3d_TextureUnit_12)
	.value("Graphic3d_TextureUnit_13", Graphic3d_TextureUnit::Graphic3d_TextureUnit_13)
	.value("Graphic3d_TextureUnit_14", Graphic3d_TextureUnit::Graphic3d_TextureUnit_14)
	.value("Graphic3d_TextureUnit_15", Graphic3d_TextureUnit::Graphic3d_TextureUnit_15)
	.value("Graphic3d_TextureUnit_BaseColor", Graphic3d_TextureUnit::Graphic3d_TextureUnit_BaseColor)
	.export_values();


}