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
#include <Quantity_TypeOfColor.hxx>

void bind_Quantity_TypeOfColor(py::module &mod){

py::enum_<Quantity_TypeOfColor>(mod, "Quantity_TypeOfColor", "Identifies color definition systems - Quantity_TOC_RGB: with this system a color is defined by its quantities of red, green and blue (R-G-B values). - Quantity_TOC_HLS: with this system a color is defined by its hue angle and its lightness and saturation values (H-L-S values). A Quantity_Color object may define a color from three values R-G-B or H-L-S according to a given color definition system.")
	.value("Quantity_TOC_RGB", Quantity_TypeOfColor::Quantity_TOC_RGB)
	.value("Quantity_TOC_HLS", Quantity_TypeOfColor::Quantity_TOC_HLS)
	.export_values();


}