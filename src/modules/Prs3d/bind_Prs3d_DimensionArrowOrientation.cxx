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
#include <Prs3d_DimensionArrowOrientation.hxx>

void bind_Prs3d_DimensionArrowOrientation(py::module &mod){

py::enum_<Prs3d_DimensionArrowOrientation>(mod, "Prs3d_DimensionArrowOrientation", "Specifies dimension arrow location and orientation. DAO_Internal - arrows 'inside', pointing outwards. DAO_External - arrows 'outside', pointing inwards. DAO_Fit - arrows oriented inside if value label with arrowtips fit the dimension line, otherwise - externally")
	.value("Prs3d_DAO_Internal", Prs3d_DimensionArrowOrientation::Prs3d_DAO_Internal)
	.value("Prs3d_DAO_External", Prs3d_DimensionArrowOrientation::Prs3d_DAO_External)
	.value("Prs3d_DAO_Fit", Prs3d_DimensionArrowOrientation::Prs3d_DAO_Fit)
	.export_values();


}