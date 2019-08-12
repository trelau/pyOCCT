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
#include <XCAFDoc_ColorType.hxx>

void bind_XCAFDoc_ColorType(py::module &mod){

py::enum_<XCAFDoc_ColorType>(mod, "XCAFDoc_ColorType", "Defines types of color assignments Color of shape is defined following way in dependance with type of color. If type of color is XCAFDoc_ColorGen - then this color defines default color for surfaces and curves. If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified then such color overrides generic color. simple color color of surfaces color of curves")
	.value("XCAFDoc_ColorGen", XCAFDoc_ColorType::XCAFDoc_ColorGen)
	.value("XCAFDoc_ColorSurf", XCAFDoc_ColorType::XCAFDoc_ColorSurf)
	.value("XCAFDoc_ColorCurv", XCAFDoc_ColorType::XCAFDoc_ColorCurv)
	.export_values();


}