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

void bind_Image_ColorBGR(py::module &mod){

py::class_<Image_ColorBGR, std::unique_ptr<Image_ColorBGR>> cls_Image_ColorBGR(mod, "Image_ColorBGR", "POD structure for packed BGR color value (3 bytes)");

// Constructors

// Fields
// cls_Image_ColorBGR.def_readwrite("v", &Image_ColorBGR::v, "None");

// Methods
cls_Image_ColorBGR.def_static("Length_", (Standard_Integer (*)()) &Image_ColorBGR::Length, "Returns the number of components.");
cls_Image_ColorBGR.def("r", (Standard_Byte (Image_ColorBGR::*)() const) &Image_ColorBGR::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGR.def("g", (Standard_Byte (Image_ColorBGR::*)() const) &Image_ColorBGR::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGR.def("b", (Standard_Byte (Image_ColorBGR::*)() const) &Image_ColorBGR::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGR.def("r", (Standard_Byte & (Image_ColorBGR::*)()) &Image_ColorBGR::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGR.def("g", (Standard_Byte & (Image_ColorBGR::*)()) &Image_ColorBGR::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGR.def("b", (Standard_Byte & (Image_ColorBGR::*)()) &Image_ColorBGR::b, "Alias to 1st component (blue intensity).");

// Enums

}