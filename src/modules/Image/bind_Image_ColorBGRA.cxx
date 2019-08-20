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
#include <Standard_TypeDef.hxx>
#include <Image_Color.hxx>

void bind_Image_ColorBGRA(py::module &mod){

py::class_<Image_ColorBGRA, std::unique_ptr<Image_ColorBGRA>> cls_Image_ColorBGRA(mod, "Image_ColorBGRA", "POD structure for packed BGRA color value (4 bytes)");

// Constructors

// Fields
// cls_Image_ColorBGRA.def_readwrite("v", &Image_ColorBGRA::v, "None");

// Methods
cls_Image_ColorBGRA.def_static("Length_", (Standard_Integer (*)()) &Image_ColorBGRA::Length, "Returns the number of components.");
cls_Image_ColorBGRA.def("r", (Standard_Byte (Image_ColorBGRA::*)() const) &Image_ColorBGRA::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRA.def("g", (Standard_Byte (Image_ColorBGRA::*)() const) &Image_ColorBGRA::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRA.def("b", (Standard_Byte (Image_ColorBGRA::*)() const) &Image_ColorBGRA::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGRA.def("a", (Standard_Byte (Image_ColorBGRA::*)() const) &Image_ColorBGRA::a, "Alias to 4th component (alpha value).");
cls_Image_ColorBGRA.def("r", (Standard_Byte & (Image_ColorBGRA::*)()) &Image_ColorBGRA::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRA.def("g", (Standard_Byte & (Image_ColorBGRA::*)()) &Image_ColorBGRA::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRA.def("b", (Standard_Byte & (Image_ColorBGRA::*)()) &Image_ColorBGRA::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGRA.def("a", (Standard_Byte & (Image_ColorBGRA::*)()) &Image_ColorBGRA::a, "Alias to 4th component (alpha value).");

// Enums

}