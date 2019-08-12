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
#include <NCollection_Buffer.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Image_PixMapData.hxx>
#include <Standard_Type.hxx>

void bind_Image_PixMapData(py::module &mod){

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

// Enums

}