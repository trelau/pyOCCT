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
#include <TColStd_HArray1OfByte.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_MarkerImage(py::module &mod){

py::class_<Graphic3d_MarkerImage, opencascade::handle<Graphic3d_MarkerImage>, Standard_Transient> cls_Graphic3d_MarkerImage(mod, "Graphic3d_MarkerImage", "This class is used to store bitmaps and images for markers rendering. It can convert bitmap texture stored in TColStd_HArray1OfByte to Image_PixMap and vice versa.");

// Constructors
cls_Graphic3d_MarkerImage.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("theImage"));
cls_Graphic3d_MarkerImage.def(py::init<const opencascade::handle<TColStd_HArray1OfByte> &, const Standard_Integer &, const Standard_Integer &>(), py::arg("theBitMap"), py::arg("theWidth"), py::arg("theHeight"));

// Fields

// Methods
cls_Graphic3d_MarkerImage.def("GetBitMapArray", [](Graphic3d_MarkerImage &self) -> opencascade::handle<TColStd_HArray1OfByte> { return self.GetBitMapArray(); });
cls_Graphic3d_MarkerImage.def("GetBitMapArray", (opencascade::handle<TColStd_HArray1OfByte> (Graphic3d_MarkerImage::*)(const Standard_Real &) const) &Graphic3d_MarkerImage::GetBitMapArray, "Returns marker image as array of bytes. If an instance of the class has been initialized with image, it will be converted to bitmap based on the parameter theAlphaValue.", py::arg("theAlphaValue"));
cls_Graphic3d_MarkerImage.def("GetImage", (const opencascade::handle<Image_PixMap> & (Graphic3d_MarkerImage::*)()) &Graphic3d_MarkerImage::GetImage, "Returns marker image. If an instance of the class has been initialized with a bitmap, it will be converted to image.");
cls_Graphic3d_MarkerImage.def("GetImageAlpha", (const opencascade::handle<Image_PixMap> & (Graphic3d_MarkerImage::*)()) &Graphic3d_MarkerImage::GetImageAlpha, "Returns image alpha as grayscale image. Note that if an instance of the class has been initialized with a bitmap or with grayscale image this method will return exactly the same image as GetImage()");
cls_Graphic3d_MarkerImage.def("GetImageId", (const TCollection_AsciiString & (Graphic3d_MarkerImage::*)() const) &Graphic3d_MarkerImage::GetImageId, "Returns an unique ID. This ID will be used to manage resource in graphic driver.");
cls_Graphic3d_MarkerImage.def("GetImageAlphaId", (const TCollection_AsciiString & (Graphic3d_MarkerImage::*)() const) &Graphic3d_MarkerImage::GetImageAlphaId, "Returns an unique ID. This ID will be used to manage resource in graphic driver.");
cls_Graphic3d_MarkerImage.def("GetTextureSize", [](Graphic3d_MarkerImage &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.GetTextureSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns texture size", py::arg("theWidth"), py::arg("theHeight"));
cls_Graphic3d_MarkerImage.def_static("get_type_name_", (const char * (*)()) &Graphic3d_MarkerImage::get_type_name, "None");
cls_Graphic3d_MarkerImage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_MarkerImage::get_type_descriptor, "None");
cls_Graphic3d_MarkerImage.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_MarkerImage::*)() const) &Graphic3d_MarkerImage::DynamicType, "None");

// Enums

}