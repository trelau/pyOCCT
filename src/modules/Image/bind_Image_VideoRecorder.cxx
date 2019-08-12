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
#include <Image_VideoRecorder.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Image_PixMap.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Image_VideoRecorder(py::module &mod){

py::class_<Image_VideoRecorder, opencascade::handle<Image_VideoRecorder>, Standard_Transient> cls_Image_VideoRecorder(mod, "Image_VideoRecorder", "Video recording tool based on FFmpeg framework.");

// Constructors
cls_Image_VideoRecorder.def(py::init<>());

// Fields

// Methods
cls_Image_VideoRecorder.def_static("get_type_name_", (const char * (*)()) &Image_VideoRecorder::get_type_name, "None");
cls_Image_VideoRecorder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Image_VideoRecorder::get_type_descriptor, "None");
cls_Image_VideoRecorder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Image_VideoRecorder::*)() const) &Image_VideoRecorder::DynamicType, "None");
cls_Image_VideoRecorder.def("Close", (void (Image_VideoRecorder::*)()) &Image_VideoRecorder::Close, "Close the stream - stop recorder.");
cls_Image_VideoRecorder.def("Open", (Standard_Boolean (Image_VideoRecorder::*)(const char *, const Image_VideoParams &)) &Image_VideoRecorder::Open, "Open output stream - initialize recorder.", py::arg("theFileName"), py::arg("theParams"));
cls_Image_VideoRecorder.def("ChangeFrame", (Image_PixMap & (Image_VideoRecorder::*)()) &Image_VideoRecorder::ChangeFrame, "Access RGBA frame, should NOT be re-initialized outside. Note that image is expected to have upper-left origin.");
cls_Image_VideoRecorder.def("FrameCount", (int64_t (Image_VideoRecorder::*)() const) &Image_VideoRecorder::FrameCount, "Return current frame index.");
cls_Image_VideoRecorder.def("PushFrame", (Standard_Boolean (Image_VideoRecorder::*)()) &Image_VideoRecorder::PushFrame, "Push new frame, should be called after Open().");

// Enums

}