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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <Standard_Type.hxx>
#include <Image_Format.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Quantity_Color.hxx>
#include <Image_PixMapData.hxx>

void bind_Image_PixMap(py::module &mod){

py::class_<Image_PixMap, opencascade::handle<Image_PixMap>, Standard_Transient> cls_Image_PixMap(mod, "Image_PixMap", "Class represents packed image plane.");

// Constructors
cls_Image_PixMap.def(py::init<>());

// Fields

// Methods
cls_Image_PixMap.def_static("get_type_name_", (const char * (*)()) &Image_PixMap::get_type_name, "None");
cls_Image_PixMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_PixMap::get_type_descriptor, "None");
cls_Image_PixMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_PixMap::*)() const) &Image_PixMap::DynamicType, "None");
cls_Image_PixMap.def_static("IsBigEndianHost_", (bool (*)()) &Image_PixMap::IsBigEndianHost, "Determine Big-Endian at runtime");
cls_Image_PixMap.def_static("SwapRgbaBgra_", (bool (*)(Image_PixMap &)) &Image_PixMap::SwapRgbaBgra, "Auxiliary method for swapping bytes between RGB and BGR formats. This method modifies the image data but does not change pixel format! Method will fail if pixel format is not one of the following: - Image_Format_RGB32 / Image_Format_BGR32 - Image_Format_RGBA / Image_Format_BGRA - Image_Format_RGB / Image_Format_BGR - Image_Format_RGBF / Image_Format_BGRF - Image_Format_RGBAF / Image_Format_BGRAF", py::arg("theImage"));
cls_Image_PixMap.def_static("ToBlackWhite_", (void (*)(Image_PixMap &)) &Image_PixMap::ToBlackWhite, "Convert image to Black/White.", py::arg("theImage"));
cls_Image_PixMap.def("Format", (Image_Format (Image_PixMap::*)() const) &Image_PixMap::Format, "None");
cls_Image_PixMap.def("SetFormat", (void (Image_PixMap::*)(const Image_Format)) &Image_PixMap::SetFormat, "Override pixel format specified by InitXXX() methods. Will throw exception if pixel size of new format is not equal to currently initialized format. Intended to switch formats indicating different interpretation of the same data (e.g. ImgGray and ImgAlpha).", py::arg("thePixelFormat"));
cls_Image_PixMap.def("Width", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::Width, "Returns image width in pixels");
cls_Image_PixMap.def("Height", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::Height, "Returns image height in pixels");
cls_Image_PixMap.def("SizeX", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::SizeX, "Returns image width in pixels");
cls_Image_PixMap.def("SizeY", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::SizeY, "Returns image height in pixels");
cls_Image_PixMap.def("Ratio", (Standard_Real (Image_PixMap::*)() const) &Image_PixMap::Ratio, "Returns width / height.");
cls_Image_PixMap.def("IsEmpty", (bool (Image_PixMap::*)() const) &Image_PixMap::IsEmpty, "Returns true if data is NULL.");
cls_Image_PixMap.def("PixelColor", (Quantity_ColorRGBA (Image_PixMap::*)(const Standard_Integer, const Standard_Integer) const) &Image_PixMap::PixelColor, "Returns the pixel color. This function is relatively slow. Beware that this method takes coordinates in opposite order in contrast to ::Value() and ::ChangeValue().", py::arg("theX"), py::arg("theY"));
cls_Image_PixMap.def("SetPixelColor", (void (Image_PixMap::*)(const Standard_Integer, const Standard_Integer, const Quantity_Color &)) &Image_PixMap::SetPixelColor, "Sets the pixel color. This function is relatively slow. Beware that this method takes coordinates in opposite order in contrast to ::Value() and ::ChangeValue().", py::arg("theX"), py::arg("theY"), py::arg("theColor"));
cls_Image_PixMap.def("SetPixelColor", (void (Image_PixMap::*)(const Standard_Integer, const Standard_Integer, const Quantity_ColorRGBA &)) &Image_PixMap::SetPixelColor, "Sets the pixel color. This function is relatively slow. Beware that this method takes coordinates in opposite order in contrast to ::Value() and ::ChangeValue().", py::arg("theX"), py::arg("theY"), py::arg("theColor"));
cls_Image_PixMap.def("InitWrapper", [](Image_PixMap &self, Image_Format a0, Standard_Byte * a1, const Standard_Size a2, const Standard_Size a3) -> bool { return self.InitWrapper(a0, a1, a2, a3); });
cls_Image_PixMap.def("InitWrapper", (bool (Image_PixMap::*)(Image_Format, Standard_Byte *, const Standard_Size, const Standard_Size, const Standard_Size)) &Image_PixMap::InitWrapper, "Initialize image plane as wrapper over alien data. Data will not be copied! Notice that caller should ensure that data pointer will not be released during this wrapper lifetime. You may call InitCopy() to perform data copying.", py::arg("thePixelFormat"), py::arg("theDataPtr"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"));
cls_Image_PixMap.def("InitTrash", [](Image_PixMap &self, Image_Format a0, const Standard_Size a1, const Standard_Size a2) -> bool { return self.InitTrash(a0, a1, a2); });
cls_Image_PixMap.def("InitTrash", (bool (Image_PixMap::*)(Image_Format, const Standard_Size, const Standard_Size, const Standard_Size)) &Image_PixMap::InitTrash, "Initialize image plane with required dimensions. Memory will be left uninitialized (performance trick).", py::arg("thePixelFormat"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"));
cls_Image_PixMap.def("InitCopy", (bool (Image_PixMap::*)(const Image_PixMap &)) &Image_PixMap::InitCopy, "Initialize by copying data. If you want to copy alien data you should create wrapper using InitWrapper() before.", py::arg("theCopy"));
cls_Image_PixMap.def("InitZero", [](Image_PixMap &self, Image_Format a0, const Standard_Size a1, const Standard_Size a2) -> bool { return self.InitZero(a0, a1, a2); });
cls_Image_PixMap.def("InitZero", [](Image_PixMap &self, Image_Format a0, const Standard_Size a1, const Standard_Size a2, const Standard_Size a3) -> bool { return self.InitZero(a0, a1, a2, a3); });
cls_Image_PixMap.def("InitZero", (bool (Image_PixMap::*)(Image_Format, const Standard_Size, const Standard_Size, const Standard_Size, const Standard_Byte)) &Image_PixMap::InitZero, "Initialize image plane with required dimensions. Buffer will be zeroed (black color for most formats).", py::arg("thePixelFormat"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"), py::arg("theValue"));
cls_Image_PixMap.def("Clear", (void (Image_PixMap::*)()) &Image_PixMap::Clear, "Method correctly deallocate internal buffer.");
cls_Image_PixMap.def("IsTopDown", (bool (Image_PixMap::*)() const) &Image_PixMap::IsTopDown, "Returns TRUE if image data is stored from Top to the Down. By default Bottom Up order is used instead (topmost scanlines starts from the bottom in memory). which is most image frameworks naturally support.");
cls_Image_PixMap.def("SetTopDown", (void (Image_PixMap::*)(const bool)) &Image_PixMap::SetTopDown, "Setup scanlines order in memory - top-down or bottom-up. Drawers should explicitly specify this value if current state IsTopDown() was ignored!", py::arg("theIsTopDown"));
cls_Image_PixMap.def("TopDownInc", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::TopDownInc, "Returns +1 if scanlines ordered in Top->Down order in memory and -1 otherwise.");
cls_Image_PixMap.def("Data", (const Standard_Byte * (Image_PixMap::*)() const) &Image_PixMap::Data, "Returns data pointer for low-level operations (copying entire buffer, parsing with extra tools etc.).");
cls_Image_PixMap.def("ChangeData", (Standard_Byte * (Image_PixMap::*)()) &Image_PixMap::ChangeData, "Returns data pointer for low-level operations (copying entire buffer, parsing with extra tools etc.).");
cls_Image_PixMap.def("Row", (const Standard_Byte * (Image_PixMap::*)(const Standard_Size) const) &Image_PixMap::Row, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMap.def("ChangeRow", (Standard_Byte * (Image_PixMap::*)(const Standard_Size)) &Image_PixMap::ChangeRow, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMap.def("SizePixelBytes", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::SizePixelBytes, "Returns bytes reserved for one pixel (may include extra bytes for alignment).");
cls_Image_PixMap.def_static("SizePixelBytes_", (Standard_Size (*)(const Image_Format)) &Image_PixMap::SizePixelBytes, "Returns bytes reserved for one pixel (may include extra bytes for alignment).", py::arg("thePixelFormat"));
cls_Image_PixMap.def("SizeRowBytes", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::SizeRowBytes, "Returns bytes reserved per row. Could be larger than needed to store packed row (extra bytes for alignment etc.).");
cls_Image_PixMap.def("RowExtraBytes", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::RowExtraBytes, "Returns the extra bytes in the row.");
cls_Image_PixMap.def("MaxRowAligmentBytes", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::MaxRowAligmentBytes, "Compute the maximal row alignment for current row size.");
cls_Image_PixMap.def("SizeBytes", (Standard_Size (Image_PixMap::*)() const) &Image_PixMap::SizeBytes, "Returns buffer size");

// Enums

}