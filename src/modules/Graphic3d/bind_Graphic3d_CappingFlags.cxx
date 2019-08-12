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
#include <Graphic3d_CappingFlags.hxx>

void bind_Graphic3d_CappingFlags(py::module &mod){

py::enum_<Graphic3d_CappingFlags>(mod, "Graphic3d_CappingFlags", "Enumeration of capping flags.")
	.value("Graphic3d_CappingFlags_None", Graphic3d_CappingFlags::Graphic3d_CappingFlags_None)
	.value("Graphic3d_CappingFlags_ObjectMaterial", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectMaterial)
	.value("Graphic3d_CappingFlags_ObjectTexture", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectTexture)
	.value("Graphic3d_CappingFlags_ObjectShader", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectShader)
	.value("Graphic3d_CappingFlags_ObjectAspect", Graphic3d_CappingFlags::Graphic3d_CappingFlags_ObjectAspect)
	.export_values();


}