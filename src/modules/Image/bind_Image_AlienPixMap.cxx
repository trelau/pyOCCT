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
#include <Image_PixMap.hxx>
#include <Standard_Handle.hxx>
#include <Image_AlienPixMap.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Image_Format.hxx>
#include <Standard_TypeDef.hxx>

void bind_Image_AlienPixMap(py::module &mod){

py::class_<Image_AlienPixMap, opencascade::handle<Image_AlienPixMap>, Image_PixMap> cls_Image_AlienPixMap(mod, "Image_AlienPixMap", "Image class that support file reading/writing operations using auxiliary image library. Supported image formats: - *.bmp - bitmap image, lossless format without compression. - *.ppm - PPM (Portable Pixmap Format), lossless format without compression. - *.png - PNG (Portable Network Graphics) lossless format with compression. - *.jpg, *.jpe, *.jpeg - JPEG/JIFF (Joint Photographic Experts Group) lossy format (compressed with quality losses). YUV color space used (automatically converted from/to RGB). - *.tif, *.tiff - TIFF (Tagged Image File Format). - *.tga - TGA (Truevision Targa Graphic), lossless format. - *.gif - GIF (Graphical Interchange Format), lossy format. Color stored using palette (up to 256 distinct colors). - *.exr - OpenEXR high dynamic-range format (supports float pixel formats).");

// Constructors
cls_Image_AlienPixMap.def(py::init<>());

// Fields

// Methods
cls_Image_AlienPixMap.def_static("get_type_name_", (const char * (*)()) &Image_AlienPixMap::get_type_name, "None");
cls_Image_AlienPixMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_AlienPixMap::get_type_descriptor, "None");
cls_Image_AlienPixMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_AlienPixMap::*)() const) &Image_AlienPixMap::DynamicType, "None");
cls_Image_AlienPixMap.def("Load", (bool (Image_AlienPixMap::*)(const TCollection_AsciiString &)) &Image_AlienPixMap::Load, "Read image data from file.", py::arg("theFileName"));
cls_Image_AlienPixMap.def("Save", (bool (Image_AlienPixMap::*)(const TCollection_AsciiString &)) &Image_AlienPixMap::Save, "Write image data to file using file extension to determine compression format.", py::arg("theFileName"));
cls_Image_AlienPixMap.def("InitTrash", [](Image_AlienPixMap &self, Image_Format a0, const Standard_Size a1, const Standard_Size a2) -> bool { return self.InitTrash(a0, a1, a2); });
cls_Image_AlienPixMap.def("InitTrash", (bool (Image_AlienPixMap::*)(Image_Format, const Standard_Size, const Standard_Size, const Standard_Size)) &Image_AlienPixMap::InitTrash, "Initialize image plane with required dimensions. thePixelFormat - if specified pixel format doesn't supported by image library than nearest supported will be used instead! theSizeRowBytes - may be ignored by this class and required alignemnt will be used instead!", py::arg("thePixelFormat"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"));
cls_Image_AlienPixMap.def("InitCopy", (bool (Image_AlienPixMap::*)(const Image_PixMap &)) &Image_AlienPixMap::InitCopy, "Initialize by copying data.", py::arg("theCopy"));
cls_Image_AlienPixMap.def("Clear", (void (Image_AlienPixMap::*)()) &Image_AlienPixMap::Clear, "Method correctly deallocate internal buffer.");
cls_Image_AlienPixMap.def("AdjustGamma", (bool (Image_AlienPixMap::*)(const Standard_Real)) &Image_AlienPixMap::AdjustGamma, "Performs gamma correction on image. theGamma - gamma value to use; a value of 1.0 leaves the image alone", py::arg("theGammaCorr"));

// Enums

}