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
#include <Graphic3d_Buffer.hxx>

void bind_Graphic3d_TypeOfAttribute(py::module &mod){

py::enum_<Graphic3d_TypeOfAttribute>(mod, "Graphic3d_TypeOfAttribute", "Type of attribute in Vertex Buffer")
	.value("Graphic3d_TOA_POS", Graphic3d_TypeOfAttribute::Graphic3d_TOA_POS)
	.value("Graphic3d_TOA_NORM", Graphic3d_TypeOfAttribute::Graphic3d_TOA_NORM)
	.value("Graphic3d_TOA_UV", Graphic3d_TypeOfAttribute::Graphic3d_TOA_UV)
	.value("Graphic3d_TOA_COLOR", Graphic3d_TypeOfAttribute::Graphic3d_TOA_COLOR)
	.value("Graphic3d_TOA_CUSTOM", Graphic3d_TypeOfAttribute::Graphic3d_TOA_CUSTOM)
	.export_values();

py::enum_<Graphic3d_TypeOfData>(mod, "Graphic3d_TypeOfData", "Type of the element in Vertex or Index Buffer")
	.value("Graphic3d_TOD_USHORT", Graphic3d_TypeOfData::Graphic3d_TOD_USHORT)
	.value("Graphic3d_TOD_UINT", Graphic3d_TypeOfData::Graphic3d_TOD_UINT)
	.value("Graphic3d_TOD_VEC2", Graphic3d_TypeOfData::Graphic3d_TOD_VEC2)
	.value("Graphic3d_TOD_VEC3", Graphic3d_TypeOfData::Graphic3d_TOD_VEC3)
	.value("Graphic3d_TOD_VEC4", Graphic3d_TypeOfData::Graphic3d_TOD_VEC4)
	.value("Graphic3d_TOD_VEC4UB", Graphic3d_TypeOfData::Graphic3d_TOD_VEC4UB)
	.value("Graphic3d_TOD_FLOAT", Graphic3d_TypeOfData::Graphic3d_TOD_FLOAT)
	.export_values();


}