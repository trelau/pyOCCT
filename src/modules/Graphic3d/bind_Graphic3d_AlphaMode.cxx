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
#include <Graphic3d_AlphaMode.hxx>

void bind_Graphic3d_AlphaMode(py::module &mod){

py::enum_<Graphic3d_AlphaMode>(mod, "Graphic3d_AlphaMode", "Defines how alpha value of base color / texture should be treated.")
	.value("Graphic3d_AlphaMode_Opaque", Graphic3d_AlphaMode::Graphic3d_AlphaMode_Opaque)
	.value("Graphic3d_AlphaMode_Mask", Graphic3d_AlphaMode::Graphic3d_AlphaMode_Mask)
	.value("Graphic3d_AlphaMode_Blend", Graphic3d_AlphaMode::Graphic3d_AlphaMode_Blend)
	.value("Graphic3d_AlphaMode_BlendAuto", Graphic3d_AlphaMode::Graphic3d_AlphaMode_BlendAuto)
	.export_values();


}