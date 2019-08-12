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
#include <Aspect_WidthOfLine.hxx>

void bind_Aspect_WidthOfLine(py::module &mod){

py::enum_<Aspect_WidthOfLine>(mod, "Aspect_WidthOfLine", "Definition of line types")
	.value("Aspect_WOL_THIN", Aspect_WidthOfLine::Aspect_WOL_THIN)
	.value("Aspect_WOL_MEDIUM", Aspect_WidthOfLine::Aspect_WOL_MEDIUM)
	.value("Aspect_WOL_THICK", Aspect_WidthOfLine::Aspect_WOL_THICK)
	.value("Aspect_WOL_VERYTHICK", Aspect_WidthOfLine::Aspect_WOL_VERYTHICK)
	.value("Aspect_WOL_USERDEFINED", Aspect_WidthOfLine::Aspect_WOL_USERDEFINED)
	.export_values();


}