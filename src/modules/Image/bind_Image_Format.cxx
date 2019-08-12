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
#include <Image_Format.hxx>

void bind_Image_Format(py::module &mod){

py::enum_<Image_Format>(mod, "Image_Format", "This enumeration defines packed image plane formats")
	.value("Image_Format_UNKNOWN", Image_Format::Image_Format_UNKNOWN)
	.value("Image_Format_Gray", Image_Format::Image_Format_Gray)
	.value("Image_Format_Alpha", Image_Format::Image_Format_Alpha)
	.value("Image_Format_RGB", Image_Format::Image_Format_RGB)
	.value("Image_Format_BGR", Image_Format::Image_Format_BGR)
	.value("Image_Format_RGB32", Image_Format::Image_Format_RGB32)
	.value("Image_Format_BGR32", Image_Format::Image_Format_BGR32)
	.value("Image_Format_RGBA", Image_Format::Image_Format_RGBA)
	.value("Image_Format_BGRA", Image_Format::Image_Format_BGRA)
	.value("Image_Format_GrayF", Image_Format::Image_Format_GrayF)
	.value("Image_Format_AlphaF", Image_Format::Image_Format_AlphaF)
	.value("Image_Format_RGBF", Image_Format::Image_Format_RGBF)
	.value("Image_Format_BGRF", Image_Format::Image_Format_BGRF)
	.value("Image_Format_RGBAF", Image_Format::Image_Format_RGBAF)
	.value("Image_Format_BGRAF", Image_Format::Image_Format_BGRAF)
	.export_values();


}