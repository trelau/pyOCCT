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
#include <Standard_TypeDef.hxx>
#include <Image_Color.hxx>
#include <NCollection_Buffer.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Image_PixMapData.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <Image_PixMap.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Quantity_Color.hxx>
#include <Image_AlienPixMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_Vector.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <NCollection_List.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <Image_Diff.hxx>
#include <Resource_DataMapOfAsciiStringAsciiString.hxx>
#include <Image_VideoRecorder.hxx>

PYBIND11_MODULE(Image, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Resource");

// ENUM: IMAGE_FORMAT
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


// CLASS: IMAGE_COLORRGB
py::class_<Image_ColorRGB> cls_Image_ColorRGB(mod, "Image_ColorRGB", "POD structure for packed RGB color value (3 bytes)");

// Fields
// cls_Image_ColorRGB.def_readwrite("v", &Image_ColorRGB::v, "None");

// Methods
cls_Image_ColorRGB.def_static("Length_", (Standard_Integer (*)()) &Image_ColorRGB::Length, "Returns the number of components.");
cls_Image_ColorRGB.def("r", (Standard_Byte (Image_ColorRGB::*)() const) &Image_ColorRGB::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGB.def("g", (Standard_Byte (Image_ColorRGB::*)() const) &Image_ColorRGB::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGB.def("b", (Standard_Byte (Image_ColorRGB::*)() const) &Image_ColorRGB::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGB.def("r", (Standard_Byte & (Image_ColorRGB::*)()) &Image_ColorRGB::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGB.def("g", (Standard_Byte & (Image_ColorRGB::*)()) &Image_ColorRGB::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGB.def("b", (Standard_Byte & (Image_ColorRGB::*)()) &Image_ColorRGB::b, "Alias to 3rd component (blue intensity).");

// CLASS: IMAGE_COLORRGB32
py::class_<Image_ColorRGB32> cls_Image_ColorRGB32(mod, "Image_ColorRGB32", "POD structure for packed RGB color value (4 bytes with extra byte for alignment)");

// Fields
// cls_Image_ColorRGB32.def_readwrite("v", &Image_ColorRGB32::v, "None");

// Methods
cls_Image_ColorRGB32.def_static("Length_", (Standard_Integer (*)()) &Image_ColorRGB32::Length, "Returns the number of components.");
cls_Image_ColorRGB32.def("r", (Standard_Byte (Image_ColorRGB32::*)() const) &Image_ColorRGB32::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGB32.def("g", (Standard_Byte (Image_ColorRGB32::*)() const) &Image_ColorRGB32::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGB32.def("b", (Standard_Byte (Image_ColorRGB32::*)() const) &Image_ColorRGB32::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGB32.def("a_", (Standard_Byte (Image_ColorRGB32::*)() const) &Image_ColorRGB32::a_, "Alias to 4th component (dummy).");
cls_Image_ColorRGB32.def("r", (Standard_Byte & (Image_ColorRGB32::*)()) &Image_ColorRGB32::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGB32.def("g", (Standard_Byte & (Image_ColorRGB32::*)()) &Image_ColorRGB32::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGB32.def("b", (Standard_Byte & (Image_ColorRGB32::*)()) &Image_ColorRGB32::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGB32.def("a_", (Standard_Byte & (Image_ColorRGB32::*)()) &Image_ColorRGB32::a_, "Alias to 4th component (dummy).");

// CLASS: IMAGE_COLORRGBA
py::class_<Image_ColorRGBA> cls_Image_ColorRGBA(mod, "Image_ColorRGBA", "POD structure for packed RGBA color value (4 bytes)");

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

// CLASS: IMAGE_COLORBGR
py::class_<Image_ColorBGR> cls_Image_ColorBGR(mod, "Image_ColorBGR", "POD structure for packed BGR color value (3 bytes)");

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

// CLASS: IMAGE_COLORBGR32
py::class_<Image_ColorBGR32> cls_Image_ColorBGR32(mod, "Image_ColorBGR32", "POD structure for packed BGR color value (4 bytes with extra byte for alignment)");

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

// CLASS: IMAGE_COLORBGRA
py::class_<Image_ColorBGRA> cls_Image_ColorBGRA(mod, "Image_ColorBGRA", "POD structure for packed BGRA color value (4 bytes)");

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

// CLASS: IMAGE_COLORRGBF
py::class_<Image_ColorRGBF> cls_Image_ColorRGBF(mod, "Image_ColorRGBF", "POD structure for packed float RGB color value (3 floats)");

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

// CLASS: IMAGE_COLORBGRF
py::class_<Image_ColorBGRF> cls_Image_ColorBGRF(mod, "Image_ColorBGRF", "POD structure for packed BGR float color value (3 floats)");

// Fields
// cls_Image_ColorBGRF.def_readwrite("v", &Image_ColorBGRF::v, "None");

// Methods
cls_Image_ColorBGRF.def_static("Length_", (Standard_Integer (*)()) &Image_ColorBGRF::Length, "Returns the number of components.");
cls_Image_ColorBGRF.def("r", (Standard_ShortReal (Image_ColorBGRF::*)() const) &Image_ColorBGRF::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRF.def("g", (Standard_ShortReal (Image_ColorBGRF::*)() const) &Image_ColorBGRF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRF.def("b", (Standard_ShortReal (Image_ColorBGRF::*)() const) &Image_ColorBGRF::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGRF.def("r", (Standard_ShortReal & (Image_ColorBGRF::*)()) &Image_ColorBGRF::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRF.def("g", (Standard_ShortReal & (Image_ColorBGRF::*)()) &Image_ColorBGRF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRF.def("b", (Standard_ShortReal & (Image_ColorBGRF::*)()) &Image_ColorBGRF::b, "Alias to 1st component (blue intensity).");

// CLASS: IMAGE_COLORRGBAF
py::class_<Image_ColorRGBAF> cls_Image_ColorRGBAF(mod, "Image_ColorRGBAF", "POD structure for packed RGBA color value (4 floats)");

// Fields
// cls_Image_ColorRGBAF.def_readwrite("v", &Image_ColorRGBAF::v, "None");

// Methods
cls_Image_ColorRGBAF.def_static("Length_", (Standard_Integer (*)()) &Image_ColorRGBAF::Length, "Returns the number of components.");
cls_Image_ColorRGBAF.def("r", (Standard_ShortReal (Image_ColorRGBAF::*)() const) &Image_ColorRGBAF::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBAF.def("g", (Standard_ShortReal (Image_ColorRGBAF::*)() const) &Image_ColorRGBAF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBAF.def("b", (Standard_ShortReal (Image_ColorRGBAF::*)() const) &Image_ColorRGBAF::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGBAF.def("a", (Standard_ShortReal (Image_ColorRGBAF::*)() const) &Image_ColorRGBAF::a, "Alias to 4th component (alpha value).");
cls_Image_ColorRGBAF.def("r", (Standard_ShortReal & (Image_ColorRGBAF::*)()) &Image_ColorRGBAF::r, "Alias to 1st component (red intensity).");
cls_Image_ColorRGBAF.def("g", (Standard_ShortReal & (Image_ColorRGBAF::*)()) &Image_ColorRGBAF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorRGBAF.def("b", (Standard_ShortReal & (Image_ColorRGBAF::*)()) &Image_ColorRGBAF::b, "Alias to 3rd component (blue intensity).");
cls_Image_ColorRGBAF.def("a", (Standard_ShortReal & (Image_ColorRGBAF::*)()) &Image_ColorRGBAF::a, "Alias to 4th component (alpha value).");

// CLASS: IMAGE_COLORBGRAF
py::class_<Image_ColorBGRAF> cls_Image_ColorBGRAF(mod, "Image_ColorBGRAF", "POD structure for packed float BGRA color value (4 floats)");

// Fields
// cls_Image_ColorBGRAF.def_readwrite("v", &Image_ColorBGRAF::v, "None");

// Methods
cls_Image_ColorBGRAF.def_static("Length_", (Standard_Integer (*)()) &Image_ColorBGRAF::Length, "Returns the number of components.");
cls_Image_ColorBGRAF.def("r", (Standard_ShortReal (Image_ColorBGRAF::*)() const) &Image_ColorBGRAF::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRAF.def("g", (Standard_ShortReal (Image_ColorBGRAF::*)() const) &Image_ColorBGRAF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRAF.def("b", (Standard_ShortReal (Image_ColorBGRAF::*)() const) &Image_ColorBGRAF::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGRAF.def("a", (Standard_ShortReal (Image_ColorBGRAF::*)() const) &Image_ColorBGRAF::a, "Alias to 4th component (alpha value).");
cls_Image_ColorBGRAF.def("r", (Standard_ShortReal & (Image_ColorBGRAF::*)()) &Image_ColorBGRAF::r, "Alias to 3rd component (red intensity).");
cls_Image_ColorBGRAF.def("g", (Standard_ShortReal & (Image_ColorBGRAF::*)()) &Image_ColorBGRAF::g, "Alias to 2nd component (green intensity).");
cls_Image_ColorBGRAF.def("b", (Standard_ShortReal & (Image_ColorBGRAF::*)()) &Image_ColorBGRAF::b, "Alias to 1st component (blue intensity).");
cls_Image_ColorBGRAF.def("a", (Standard_ShortReal & (Image_ColorBGRAF::*)()) &Image_ColorBGRAF::a, "Alias to 4th component (alpha value).");

// CLASS: IMAGE_PIXMAPDATA
py::class_<Image_PixMapData, opencascade::handle<Image_PixMapData>, NCollection_Buffer> cls_Image_PixMapData(mod, "Image_PixMapData", "Structure to manage image buffer.");

// Constructors
cls_Image_PixMapData.def(py::init<>());

// Fields
cls_Image_PixMapData.def_readwrite("SizeBPP", &Image_PixMapData::SizeBPP, "bytes per pixel");
cls_Image_PixMapData.def_readwrite("SizeX", &Image_PixMapData::SizeX, "width in pixels");
cls_Image_PixMapData.def_readwrite("SizeY", &Image_PixMapData::SizeY, "height in pixels");
cls_Image_PixMapData.def_readwrite("SizeRowBytes", &Image_PixMapData::SizeRowBytes, "number of bytes per line (in most cases equal to 3 * sizeX)");
cls_Image_PixMapData.def_readwrite("TopToDown", &Image_PixMapData::TopToDown, "image scanlines direction in memory from Top to the Down");

// Methods
cls_Image_PixMapData.def("Init", (void (Image_PixMapData::*)(const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Size, const Standard_Size, const Standard_Size, const Standard_Size, Standard_Byte *)) &Image_PixMapData::Init, "Initializer.", py::arg("theAlloc"), py::arg("theSizeBPP"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"), py::arg("theDataPtr"));
cls_Image_PixMapData.def("Row", (const Standard_Byte * (Image_PixMapData::*)(const Standard_Size) const) &Image_PixMapData::Row, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMapData.def("ChangeRow", (Standard_Byte * (Image_PixMapData::*)(const Standard_Size)) &Image_PixMapData::ChangeRow, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMapData.def("Value", (const Standard_Byte * (Image_PixMapData::*)(const Standard_Size, const Standard_Size) const) &Image_PixMapData::Value, "Returns data pointer to requested position.", py::arg("theRow"), py::arg("theCol"));
cls_Image_PixMapData.def("ChangeValue", (Standard_Byte * (Image_PixMapData::*)(const Standard_Size, const Standard_Size)) &Image_PixMapData::ChangeValue, "Returns data pointer to requested position.", py::arg("theRow"), py::arg("theCol"));
cls_Image_PixMapData.def("MaxRowAligmentBytes", (Standard_Size (Image_PixMapData::*)() const) &Image_PixMapData::MaxRowAligmentBytes, "Compute the maximal row alignment for current row size.");
cls_Image_PixMapData.def("SetTopDown", (void (Image_PixMapData::*)(const bool)) &Image_PixMapData::SetTopDown, "Setup scanlines order in memory - top-down or bottom-up. Drawers should explicitly specify this value if current state IsTopDown() was ignored!", py::arg("theIsTopDown"));
cls_Image_PixMapData.def_static("get_type_name_", (const char * (*)()) &Image_PixMapData::get_type_name, "None");
cls_Image_PixMapData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_PixMapData::get_type_descriptor, "None");
cls_Image_PixMapData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_PixMapData::*)() const) &Image_PixMapData::DynamicType, "None");

// CLASS: IMAGE_PIXMAP
py::class_<Image_PixMap, opencascade::handle<Image_PixMap>, Standard_Transient> cls_Image_PixMap(mod, "Image_PixMap", "Class represents packed image plane.");

// Constructors
cls_Image_PixMap.def(py::init<>());

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

// CLASS: IMAGE_ALIENPIXMAP
py::class_<Image_AlienPixMap, opencascade::handle<Image_AlienPixMap>, Image_PixMap> cls_Image_AlienPixMap(mod, "Image_AlienPixMap", "Image class that support file reading/writing operations using auxiliary image library. Supported image formats: - *.bmp - bitmap image, lossless format without compression. - *.ppm - PPM (Portable Pixmap Format), lossless format without compression. - *.png - PNG (Portable Network Graphics) lossless format with compression. - *.jpg, *.jpe, *.jpeg - JPEG/JIFF (Joint Photographic Experts Group) lossy format (compressed with quality losses). YUV color space used (automatically converted from/to RGB). - *.tif, *.tiff - TIFF (Tagged Image File Format). - *.tga - TGA (Truevision Targa Graphic), lossless format. - *.gif - GIF (Graphical Interchange Format), lossy format. Color stored using palette (up to 256 distinct colors). - *.exr - OpenEXR high dynamic-range format (supports float pixel formats).");

// Constructors
cls_Image_AlienPixMap.def(py::init<>());

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

// CLASS: IMAGE_DIFF
py::class_<Image_Diff, opencascade::handle<Image_Diff>, Standard_Transient> cls_Image_Diff(mod, "Image_Diff", "This class compares two images pixel-by-pixel. It uses the following methods to ignore the difference between images: - Black/White comparison. It makes the images 2-colored before the comparison. - Equality with tolerance. Colors of two pixels are considered the same if the differnce of their color is less than a tolerance. - Border filter. The algorithm ignores alone independent pixels, which are different on both images, ignores the 'border effect' - the difference caused by triangles located at angle about 0 or 90 degrees to the user.");

// Constructors
cls_Image_Diff.def(py::init<>());

// Methods
cls_Image_Diff.def("Init", [](Image_Diff &self, const opencascade::handle<Image_PixMap> & a0, const opencascade::handle<Image_PixMap> & a1) -> Standard_Boolean { return self.Init(a0, a1); });
cls_Image_Diff.def("Init", (Standard_Boolean (Image_Diff::*)(const opencascade::handle<Image_PixMap> &, const opencascade::handle<Image_PixMap> &, const Standard_Boolean)) &Image_Diff::Init, "Initialize algorithm by two images.", py::arg("theImageRef"), py::arg("theImageNew"), py::arg("theToBlackWhite"));
cls_Image_Diff.def("Init", [](Image_Diff &self, const TCollection_AsciiString & a0, const TCollection_AsciiString & a1) -> Standard_Boolean { return self.Init(a0, a1); });
cls_Image_Diff.def("Init", (Standard_Boolean (Image_Diff::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const Standard_Boolean)) &Image_Diff::Init, "Initialize algorithm by two images (will be loaded from files).", py::arg("theImgPathRef"), py::arg("theImgPathNew"), py::arg("theToBlackWhite"));
cls_Image_Diff.def("SetColorTolerance", (void (Image_Diff::*)(const Standard_Real)) &Image_Diff::SetColorTolerance, "Color tolerance for equality check. Should be within range 0..1: Corresponds to a difference between white and black colors (maximum difference). By default, the tolerance is equal to 0 thus equality check will return false for any different colors.", py::arg("theTolerance"));
cls_Image_Diff.def("ColorTolerance", (Standard_Real (Image_Diff::*)() const) &Image_Diff::ColorTolerance, "Color tolerance for equality check.");
cls_Image_Diff.def("SetBorderFilterOn", (void (Image_Diff::*)(const Standard_Boolean)) &Image_Diff::SetBorderFilterOn, "Sets taking into account (ignoring) a 'border effect' on comparison of images. The border effect is caused by a border of shaded shapes in the viewer 3d. Triangles of this area are located at about 0 or 90 degrees to the user. Therefore, they deflect light differently according to implementation of a video card driver. This flag allows to detect such a 'border' area and skip it from comparison of images. Filter turned OFF by default.", py::arg("theToIgnore"));
cls_Image_Diff.def("IsBorderFilterOn", (Standard_Boolean (Image_Diff::*)() const) &Image_Diff::IsBorderFilterOn, "Returns a flag of taking into account (ignoring) a border effect in comparison of images.");
cls_Image_Diff.def("Compare", (Standard_Integer (Image_Diff::*)()) &Image_Diff::Compare, "Compares two images. It returns a number of different pixels (or groups of pixels). It returns -1 if algorithm not initialized before.");
cls_Image_Diff.def("SaveDiffImage", (Standard_Boolean (Image_Diff::*)(Image_PixMap &) const) &Image_Diff::SaveDiffImage, "Saves a difference between two images as white pixels on black backgroud.", py::arg("theDiffImage"));
cls_Image_Diff.def("SaveDiffImage", (Standard_Boolean (Image_Diff::*)(const TCollection_AsciiString &) const) &Image_Diff::SaveDiffImage, "Saves a difference between two images as white pixels on black backgroud.", py::arg("theDiffPath"));
cls_Image_Diff.def_static("get_type_name_", (const char * (*)()) &Image_Diff::get_type_name, "None");
cls_Image_Diff.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_Diff::get_type_descriptor, "None");
cls_Image_Diff.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_Diff::*)() const) &Image_Diff::DynamicType, "None");

// CLASS: IMAGE_VIDEOPARAMS
py::class_<Image_VideoParams> cls_Image_VideoParams(mod, "Image_VideoParams", "Auxiliary structure defining video parameters. Please refer to FFmpeg documentation for defining text values.");

// Constructors
cls_Image_VideoParams.def(py::init<>());

// Fields
cls_Image_VideoParams.def_readwrite("Format", &Image_VideoParams::Format, "[optional] video format (container), if empty - will be determined from the file name");
cls_Image_VideoParams.def_readwrite("VideoCodec", &Image_VideoParams::VideoCodec, "[optional] codec identifier, if empty - default codec from file format will be used");
cls_Image_VideoParams.def_readwrite("PixelFormat", &Image_VideoParams::PixelFormat, "[optional] pixel format, if empty - default codec pixel format will be used");
cls_Image_VideoParams.def_readwrite("Width", &Image_VideoParams::Width, "[mandatory] video frame width");
cls_Image_VideoParams.def_readwrite("Height", &Image_VideoParams::Height, "[mandatory] video frame height");
cls_Image_VideoParams.def_readwrite("FpsNum", &Image_VideoParams::FpsNum, "[mandatory] framerate numerator");
cls_Image_VideoParams.def_readwrite("FpsDen", &Image_VideoParams::FpsDen, "[mandatory] framerate denumerator");
cls_Image_VideoParams.def_readwrite("VideoCodecParams", &Image_VideoParams::VideoCodecParams, "map of advanced video codec parameters");

// Methods
cls_Image_VideoParams.def("SetFramerate", (void (Image_VideoParams::*)(const Standard_Integer, const Standard_Integer)) &Image_VideoParams::SetFramerate, "Setup playback FPS.", py::arg("theNumerator"), py::arg("theDenominator"));
cls_Image_VideoParams.def("SetFramerate", (void (Image_VideoParams::*)(const Standard_Integer)) &Image_VideoParams::SetFramerate, "Setup playback FPS. For fixed-fps content, timebase should be 1/framerate and timestamp increments should be identical to 1.", py::arg("theValue"));

// CLASS: IMAGE_VIDEORECORDER
py::class_<Image_VideoRecorder, opencascade::handle<Image_VideoRecorder>, Standard_Transient> cls_Image_VideoRecorder(mod, "Image_VideoRecorder", "Video recording tool based on FFmpeg framework.");

// Constructors
cls_Image_VideoRecorder.def(py::init<>());

// Methods
cls_Image_VideoRecorder.def_static("get_type_name_", (const char * (*)()) &Image_VideoRecorder::get_type_name, "None");
cls_Image_VideoRecorder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_VideoRecorder::get_type_descriptor, "None");
cls_Image_VideoRecorder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_VideoRecorder::*)() const) &Image_VideoRecorder::DynamicType, "None");
cls_Image_VideoRecorder.def("Close", (void (Image_VideoRecorder::*)()) &Image_VideoRecorder::Close, "Close the stream - stop recorder.");
cls_Image_VideoRecorder.def("Open", (Standard_Boolean (Image_VideoRecorder::*)(const char *, const Image_VideoParams &)) &Image_VideoRecorder::Open, "Open output stream - initialize recorder.", py::arg("theFileName"), py::arg("theParams"));
cls_Image_VideoRecorder.def("ChangeFrame", (Image_PixMap & (Image_VideoRecorder::*)()) &Image_VideoRecorder::ChangeFrame, "Access RGBA frame, should NOT be re-initialized outside. Note that image is expected to have upper-left origin.");
cls_Image_VideoRecorder.def("FrameCount", (int64_t (Image_VideoRecorder::*)() const) &Image_VideoRecorder::FrameCount, "Return current frame index.");
cls_Image_VideoRecorder.def("PushFrame", (Standard_Boolean (Image_VideoRecorder::*)()) &Image_VideoRecorder::PushFrame, "Push new frame, should be called after Open().");


}
