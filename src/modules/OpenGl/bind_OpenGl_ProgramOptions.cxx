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
#include <OpenGl_SetOfShaderPrograms.hxx>

void bind_OpenGl_ProgramOptions(py::module &mod){

py::enum_<OpenGl_ProgramOptions>(mod, "OpenGl_ProgramOptions", "Standard GLSL program combination bits.")
	.value("OpenGl_PO_Point", OpenGl_ProgramOptions::OpenGl_PO_Point)
	.value("OpenGl_PO_VertColor", OpenGl_ProgramOptions::OpenGl_PO_VertColor)
	.value("OpenGl_PO_TextureRGB", OpenGl_ProgramOptions::OpenGl_PO_TextureRGB)
	.value("OpenGl_PO_TextureA", OpenGl_ProgramOptions::OpenGl_PO_TextureA)
	.value("OpenGl_PO_TextureEnv", OpenGl_ProgramOptions::OpenGl_PO_TextureEnv)
	.value("OpenGl_PO_StippleLine", OpenGl_ProgramOptions::OpenGl_PO_StippleLine)
	.value("OpenGl_PO_ClipPlanes1", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanes1)
	.value("OpenGl_PO_ClipPlanes2", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanes2)
	.value("OpenGl_PO_ClipPlanesN", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanesN)
	.value("OpenGl_PO_AlphaTest", OpenGl_ProgramOptions::OpenGl_PO_AlphaTest)
	.value("OpenGl_PO_WriteOit", OpenGl_ProgramOptions::OpenGl_PO_WriteOit)
	.value("OpenGl_PO_NB", OpenGl_ProgramOptions::OpenGl_PO_NB)
	.export_values();


}