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

void bind_Image_ColorRGBF(py::module &mod){

py::class_<Image_ColorRGBF, std::unique_ptr<Image_ColorRGBF, Deleter<Image_ColorRGBF>>> cls_Image_ColorRGBF(mod, "Image_ColorRGBF", "POD structure for packed float RGB color value (3 floats)");

// Constructors

// Fields
// cls_Image_ColorRGBF.def_readwrite("v", &Image_ColorRGBF::v, "None");

// Methods
cls_Image_ColorRGBF.def_static("Length_", (Standard_Integer (*)()) &Image_ColorRGBF::Length, "Returns the number of components.");
cls_Image_ColorRGBF.def("r", (Standard_ShortReal (Image_ColorRGBF::*)() const) &Image_ColorRGBF::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBF.def("g", (Standard_ShortReal (Image_ColorRGBF::*)() const) &Image_ColorRGBF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBF.def("b", (Standard_ShortReal (Image_ColorRGBF::*)() const) &Image_ColorRGBF::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGBF.def("r", (Standard_ShortReal & (Image_ColorRGBF::*)()) &Image_ColorRGBF::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBF.def("g", (Standard_ShortReal & (Image_ColorRGBF::*)()) &Image_ColorRGBF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBF.def("b", (Standard_ShortReal & (Image_ColorRGBF::*)()) &Image_ColorRGBF::b, "Alias to 3rd component (blue intensity).");

// Enums

}