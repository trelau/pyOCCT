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
#include <Graphic3d_TypeOfShadingModel.hxx>

void bind_Graphic3d_TypeOfShadingModel(py::module &mod){

py::enum_<Graphic3d_TypeOfShadingModel>(mod, "Graphic3d_TypeOfShadingModel", "Definition of the color shading model.")
	.value("Graphic3d_TOSM_DEFAULT", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_DEFAULT)
	.value("Graphic3d_TOSM_UNLIT", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_UNLIT)
	.value("Graphic3d_TOSM_FACET", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_FACET)
	.value("Graphic3d_TOSM_VERTEX", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_VERTEX)
	.value("Graphic3d_TOSM_FRAGMENT", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_FRAGMENT)
	.value("Graphic3d_TOSM_NONE", Graphic3d_TypeOfShadingModel::Graphic3d_TOSM_NONE)
	.value("V3d_COLOR", Graphic3d_TypeOfShadingModel::V3d_COLOR)
	.value("V3d_FLAT", Graphic3d_TypeOfShadingModel::V3d_FLAT)
	.value("V3d_GOURAUD", Graphic3d_TypeOfShadingModel::V3d_GOURAUD)
	.value("V3d_PHONG", Graphic3d_TypeOfShadingModel::V3d_PHONG)
	.export_values();


}