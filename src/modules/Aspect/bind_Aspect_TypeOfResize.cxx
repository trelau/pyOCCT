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
#include <Aspect_TypeOfResize.hxx>

void bind_Aspect_TypeOfResize(py::module &mod){

py::enum_<Aspect_TypeOfResize>(mod, "Aspect_TypeOfResize", "Defines the type of Resize Window method applied by the user.")
	.value("Aspect_TOR_UNKNOWN", Aspect_TypeOfResize::Aspect_TOR_UNKNOWN)
	.value("Aspect_TOR_NO_BORDER", Aspect_TypeOfResize::Aspect_TOR_NO_BORDER)
	.value("Aspect_TOR_TOP_BORDER", Aspect_TypeOfResize::Aspect_TOR_TOP_BORDER)
	.value("Aspect_TOR_RIGHT_BORDER", Aspect_TypeOfResize::Aspect_TOR_RIGHT_BORDER)
	.value("Aspect_TOR_BOTTOM_BORDER", Aspect_TypeOfResize::Aspect_TOR_BOTTOM_BORDER)
	.value("Aspect_TOR_LEFT_BORDER", Aspect_TypeOfResize::Aspect_TOR_LEFT_BORDER)
	.value("Aspect_TOR_TOP_AND_RIGHT_BORDER", Aspect_TypeOfResize::Aspect_TOR_TOP_AND_RIGHT_BORDER)
	.value("Aspect_TOR_RIGHT_AND_BOTTOM_BORDER", Aspect_TypeOfResize::Aspect_TOR_RIGHT_AND_BOTTOM_BORDER)
	.value("Aspect_TOR_BOTTOM_AND_LEFT_BORDER", Aspect_TypeOfResize::Aspect_TOR_BOTTOM_AND_LEFT_BORDER)
	.value("Aspect_TOR_LEFT_AND_TOP_BORDER", Aspect_TypeOfResize::Aspect_TOR_LEFT_AND_TOP_BORDER)
	.export_values();


}