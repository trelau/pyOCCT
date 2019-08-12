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

void bind_Image_ColorRGBA(py::module &mod){

py::class_<Image_ColorRGBA, std::unique_ptr<Image_ColorRGBA, Deleter<Image_ColorRGBA>>> cls_Image_ColorRGBA(mod, "Image_ColorRGBA", "POD structure for packed RGBA color value (4 bytes)");

// Constructors

// Fields
// cls_Image_ColorRGBA.def_readwrite("v", &Image_ColorRGBA::v, "None");

// Methods
cls_Image_ColorRGBA.def_static("Length_", (Standard_Integer (*)()) &Image_ColorRGBA::Length, "Returns the number of components.");
cls_Image_ColorRGBA.def("r", (Standard_Byte (Image_ColorRGBA::*)() const) &Image_ColorRGBA::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBA.def("g", (Standard_Byte (Image_ColorRGBA::*)() const) &Image_ColorRGBA::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBA.def("b", (Standard_Byte (Image_ColorRGBA::*)() const) &Image_ColorRGBA::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGBA.def("a", (Standard_Byte (Image_ColorRGBA::*)() const) &Image_ColorRGBA::a, "Alias to 4th component (alpha value).");
cls_Image_ColorRGBA.def("r", (Standard_Byte & (Image_ColorRGBA::*)()) &Image_ColorRGBA::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBA.def("g", (Standard_Byte & (Image_ColorRGBA::*)()) &Image_ColorRGBA::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBA.def("b", (Standard_Byte & (Image_ColorRGBA::*)()) &Image_ColorRGBA::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGBA.def("a", (Standard_Byte & (Image_ColorRGBA::*)()) &Image_ColorRGBA::a, "Alias to 4th component (alpha value).");

// Enums

}