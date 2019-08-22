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

void bind_Image_ColorBGR32(py::module &mod){

py::class_<Image_ColorBGR32> cls_Image_ColorBGR32(mod, "Image_ColorBGR32", "POD structure for packed BGR color value (4 bytes with extra byte for alignment)");

// Constructors

// Fields
// cls_Image_ColorBGR32.def_readwrite("v", &Image_ColorBGR32::v, "None");

// Methods
cls_Image_ColorBGR32.def_static("Length_", (Standard_Integer (*)()) &Image_ColorBGR32::Length, "Returns the number of components.");
cls_Image_ColorBGR32.def("r", (Standard_Byte (Image_ColorBGR32::*)() const) &Image_ColorBGR32::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGR32.def("g", (Standard_Byte (Image_ColorBGR32::*)() const) &Image_ColorBGR32::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGR32.def("b", (Standard_Byte (Image_ColorBGR32::*)() const) &Image_ColorBGR32::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGR32.def("a_", (Standard_Byte (Image_ColorBGR32::*)() const) &Image_ColorBGR32::a_, "Alias to 4th component (dummy).");
cls_Image_ColorBGR32.def("r", (Standard_Byte & (Image_ColorBGR32::*)()) &Image_ColorBGR32::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGR32.def("g", (Standard_Byte & (Image_ColorBGR32::*)()) &Image_ColorBGR32::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGR32.def("b", (Standard_Byte & (Image_ColorBGR32::*)()) &Image_ColorBGR32::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGR32.def("a_", (Standard_Byte & (Image_ColorBGR32::*)()) &Image_ColorBGR32::a_, "Alias to 4th component (dummy).");

// Enums

}