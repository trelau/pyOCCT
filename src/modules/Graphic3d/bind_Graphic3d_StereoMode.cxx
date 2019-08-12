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
#include <Graphic3d_StereoMode.hxx>

void bind_Graphic3d_StereoMode(py::module &mod){

py::enum_<Graphic3d_StereoMode>(mod, "Graphic3d_StereoMode", "This enumeration defines the list of stereoscopic output modes.")
	.value("Graphic3d_StereoMode_QuadBuffer", Graphic3d_StereoMode::Graphic3d_StereoMode_QuadBuffer)
	.value("Graphic3d_StereoMode_Anaglyph", Graphic3d_StereoMode::Graphic3d_StereoMode_Anaglyph)
	.value("Graphic3d_StereoMode_RowInterlaced", Graphic3d_StereoMode::Graphic3d_StereoMode_RowInterlaced)
	.value("Graphic3d_StereoMode_ColumnInterlaced", Graphic3d_StereoMode::Graphic3d_StereoMode_ColumnInterlaced)
	.value("Graphic3d_StereoMode_ChessBoard", Graphic3d_StereoMode::Graphic3d_StereoMode_ChessBoard)
	.value("Graphic3d_StereoMode_SideBySide", Graphic3d_StereoMode::Graphic3d_StereoMode_SideBySide)
	.value("Graphic3d_StereoMode_OverUnder", Graphic3d_StereoMode::Graphic3d_StereoMode_OverUnder)
	.value("Graphic3d_StereoMode_SoftPageFlip", Graphic3d_StereoMode::Graphic3d_StereoMode_SoftPageFlip)
	.value("Graphic3d_StereoMode_NB", Graphic3d_StereoMode::Graphic3d_StereoMode_NB)
	.export_values();


}