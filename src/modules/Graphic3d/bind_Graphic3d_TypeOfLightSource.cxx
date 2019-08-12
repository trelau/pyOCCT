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
#include <Graphic3d_TypeOfLightSource.hxx>

void bind_Graphic3d_TypeOfLightSource(py::module &mod){

py::enum_<Graphic3d_TypeOfLightSource>(mod, "Graphic3d_TypeOfLightSource", "Definition of all the type of light source.")
	.value("Graphic3d_TOLS_AMBIENT", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_AMBIENT)
	.value("Graphic3d_TOLS_DIRECTIONAL", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_DIRECTIONAL)
	.value("Graphic3d_TOLS_POSITIONAL", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_POSITIONAL)
	.value("Graphic3d_TOLS_SPOT", Graphic3d_TypeOfLightSource::Graphic3d_TOLS_SPOT)
	.value("V3d_AMBIENT", Graphic3d_TypeOfLightSource::V3d_AMBIENT)
	.value("V3d_DIRECTIONAL", Graphic3d_TypeOfLightSource::V3d_DIRECTIONAL)
	.value("V3d_POSITIONAL", Graphic3d_TypeOfLightSource::V3d_POSITIONAL)
	.value("V3d_SPOT", Graphic3d_TypeOfLightSource::V3d_SPOT)
	.export_values();


}