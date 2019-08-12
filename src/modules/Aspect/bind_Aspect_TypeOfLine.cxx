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
#include <Aspect_TypeOfLine.hxx>

void bind_Aspect_TypeOfLine(py::module &mod){

py::enum_<Aspect_TypeOfLine>(mod, "Aspect_TypeOfLine", "Definition of line types")
	.value("Aspect_TOL_EMPTY", Aspect_TypeOfLine::Aspect_TOL_EMPTY)
	.value("Aspect_TOL_SOLID", Aspect_TypeOfLine::Aspect_TOL_SOLID)
	.value("Aspect_TOL_DASH", Aspect_TypeOfLine::Aspect_TOL_DASH)
	.value("Aspect_TOL_DOT", Aspect_TypeOfLine::Aspect_TOL_DOT)
	.value("Aspect_TOL_DOTDASH", Aspect_TypeOfLine::Aspect_TOL_DOTDASH)
	.value("Aspect_TOL_USERDEFINED", Aspect_TypeOfLine::Aspect_TOL_USERDEFINED)
	.export_values();


}