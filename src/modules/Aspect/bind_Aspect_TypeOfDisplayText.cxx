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
#include <Aspect_TypeOfDisplayText.hxx>

void bind_Aspect_TypeOfDisplayText(py::module &mod){

py::enum_<Aspect_TypeOfDisplayText>(mod, "Aspect_TypeOfDisplayText", "Define the display type of the text.")
	.value("Aspect_TODT_NORMAL", Aspect_TypeOfDisplayText::Aspect_TODT_NORMAL)
	.value("Aspect_TODT_SUBTITLE", Aspect_TypeOfDisplayText::Aspect_TODT_SUBTITLE)
	.value("Aspect_TODT_DEKALE", Aspect_TypeOfDisplayText::Aspect_TODT_DEKALE)
	.value("Aspect_TODT_BLEND", Aspect_TypeOfDisplayText::Aspect_TODT_BLEND)
	.value("Aspect_TODT_DIMENSION", Aspect_TypeOfDisplayText::Aspect_TODT_DIMENSION)
	.value("Aspect_TODT_SHADOW", Aspect_TypeOfDisplayText::Aspect_TODT_SHADOW)
	.export_values();


}