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
#include <Prs3d_DimensionTextHorizontalPosition.hxx>

void bind_Prs3d_DimensionTextHorizontalPosition(py::module &mod){

py::enum_<Prs3d_DimensionTextHorizontalPosition>(mod, "Prs3d_DimensionTextHorizontalPosition", "Specifies options for positioning dimension value label in horizontal direction. DTHP_Left - value label located at left side on dimension extension. DTHP_Right - value label located at right side on dimension extension. DTHP_Center - value label located at center of dimension line. DTHP_Fit - value label located automatically at left side if does not fits the dimension space, otherwise the value label is placed at center.")
	.value("Prs3d_DTHP_Left", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Left)
	.value("Prs3d_DTHP_Right", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Right)
	.value("Prs3d_DTHP_Center", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Center)
	.value("Prs3d_DTHP_Fit", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Fit)
	.export_values();


}