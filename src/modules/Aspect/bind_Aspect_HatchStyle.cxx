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
#include <Aspect_HatchStyle.hxx>

void bind_Aspect_HatchStyle(py::module &mod){

py::enum_<Aspect_HatchStyle>(mod, "Aspect_HatchStyle", "Definition of all available hatch styles.")
	.value("Aspect_HS_SOLID", Aspect_HatchStyle::Aspect_HS_SOLID)
	.value("Aspect_HS_HORIZONTAL", Aspect_HatchStyle::Aspect_HS_HORIZONTAL)
	.value("Aspect_HS_HORIZONTAL_WIDE", Aspect_HatchStyle::Aspect_HS_HORIZONTAL_WIDE)
	.value("Aspect_HS_VERTICAL", Aspect_HatchStyle::Aspect_HS_VERTICAL)
	.value("Aspect_HS_VERTICAL_WIDE", Aspect_HatchStyle::Aspect_HS_VERTICAL_WIDE)
	.value("Aspect_HS_DIAGONAL_45", Aspect_HatchStyle::Aspect_HS_DIAGONAL_45)
	.value("Aspect_HS_DIAGONAL_45_WIDE", Aspect_HatchStyle::Aspect_HS_DIAGONAL_45_WIDE)
	.value("Aspect_HS_DIAGONAL_135", Aspect_HatchStyle::Aspect_HS_DIAGONAL_135)
	.value("Aspect_HS_DIAGONAL_135_WIDE", Aspect_HatchStyle::Aspect_HS_DIAGONAL_135_WIDE)
	.value("Aspect_HS_GRID", Aspect_HatchStyle::Aspect_HS_GRID)
	.value("Aspect_HS_GRID_WIDE", Aspect_HatchStyle::Aspect_HS_GRID_WIDE)
	.value("Aspect_HS_GRID_DIAGONAL", Aspect_HatchStyle::Aspect_HS_GRID_DIAGONAL)
	.value("Aspect_HS_GRID_DIAGONAL_WIDE", Aspect_HatchStyle::Aspect_HS_GRID_DIAGONAL_WIDE)
	.value("Aspect_HS_NB", Aspect_HatchStyle::Aspect_HS_NB)
	.export_values();


}