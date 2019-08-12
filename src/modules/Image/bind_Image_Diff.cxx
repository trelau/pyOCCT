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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_Vector.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <NCollection_List.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <Image_Diff.hxx>
#include <Standard_Type.hxx>

void bind_Image_Diff(py::module &mod){

py::class_<Image_Diff, opencascade::handle<Image_Diff>, Standard_Transient> cls_Image_Diff(mod, "Image_Diff", "This class compares two images pixel-by-pixel. It uses the following methods to ignore the difference between images: - Black/White comparison. It makes the images 2-colored before the comparison. - Equality with tolerance. Colors of two pixels are considered the same if the differnce of their color is less than a tolerance. - Border filter. The algorithm ignores alone independent pixels, which are different on both images, ignores the 'border effect' - the difference caused by triangles located at angle about 0 or 90 degrees to the user.");

// Constructors
cls_Image_Diff.def(py::init<>());

// Fields

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

// Enums

}