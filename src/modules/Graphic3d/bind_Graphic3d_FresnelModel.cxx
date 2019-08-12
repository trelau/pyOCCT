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
#include <Graphic3d_BSDF.hxx>

void bind_Graphic3d_FresnelModel(py::module &mod){

py::enum_<Graphic3d_FresnelModel>(mod, "Graphic3d_FresnelModel", "Type of the Fresnel model.")
	.value("Graphic3d_FM_SCHLICK", Graphic3d_FresnelModel::Graphic3d_FM_SCHLICK)
	.value("Graphic3d_FM_CONSTANT", Graphic3d_FresnelModel::Graphic3d_FM_CONSTANT)
	.value("Graphic3d_FM_CONDUCTOR", Graphic3d_FresnelModel::Graphic3d_FM_CONDUCTOR)
	.value("Graphic3d_FM_DIELECTRIC", Graphic3d_FresnelModel::Graphic3d_FM_DIELECTRIC)
	.export_values();


}