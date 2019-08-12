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
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Resource_DataMapOfAsciiStringAsciiString.hxx>
#include <Image_VideoRecorder.hxx>

void bind_Image_VideoParams(py::module &mod){

py::class_<Image_VideoParams, std::unique_ptr<Image_VideoParams, Deleter<Image_VideoParams>>> cls_Image_VideoParams(mod, "Image_VideoParams", "Auxiliary structure defining video parameters. Please refer to FFmpeg documentation for defining text values.");

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

// Enums

}