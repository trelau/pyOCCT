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
#ifndef __Image_PixMapTypedData__
#define __Image_PixMapTypedData__

#include <Image_PixMapData.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Image_PixMapTypedData.hxx>

template <typename PixelType_t>
void bind_Image_PixMapTypedData(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<Image_PixMapTypedData<PixelType_t>, opencascade::handle<Image_PixMapTypedData<PixelType_t>>, Image_PixMapData> cls_Image_PixMapTypedData(mod, name.c_str(), "Structure to manage image buffer with predefined pixel type.", local);

// Constructors
cls_Image_PixMapTypedData.def(py::init<>());

// Methods
cls_Image_PixMapTypedData.def("Init", [](Image_PixMapTypedData<PixelType_t> &self, const opencascade::handle<NCollection_BaseAllocator> & a0, Standard_Size a1, Standard_Size a2) -> bool { return self.Init(a0, a1, a2); });
cls_Image_PixMapTypedData.def("Init", [](Image_PixMapTypedData<PixelType_t> &self, const opencascade::handle<NCollection_BaseAllocator> & a0, Standard_Size a1, Standard_Size a2, Standard_Size a3) -> bool { return self.Init(a0, a1, a2, a3); });
cls_Image_PixMapTypedData.def("Init", (bool (Image_PixMapTypedData<PixelType_t>::*)(const opencascade::handle<NCollection_BaseAllocator> &, Standard_Size, Standard_Size, Standard_Size, Standard_Byte *)) &Image_PixMapTypedData<PixelType_t>::Init, "Initializer.", py::arg("theAlloc"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeRowBytes"), py::arg("theDataPtr"));
cls_Image_PixMapTypedData.def("Init", (void (Image_PixMapTypedData<PixelType_t>::*)(const PixelType_t &)) &Image_PixMapTypedData<PixelType_t>::Init, "Reset all values to specified one.", py::arg("theValue"));
cls_Image_PixMapTypedData.def("Row", (const PixelType_t * (Image_PixMapTypedData<PixelType_t>::*)(Standard_Size) const) &Image_PixMapTypedData<PixelType_t>::Row, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMapTypedData.def("ChangeRow", (PixelType_t * (Image_PixMapTypedData<PixelType_t>::*)(Standard_Size)) &Image_PixMapTypedData<PixelType_t>::ChangeRow, "Returns data pointer to requested row (first column).", py::arg("theRow"));
cls_Image_PixMapTypedData.def("Value", (const PixelType_t & (Image_PixMapTypedData<PixelType_t>::*)(Standard_Size, Standard_Size) const) &Image_PixMapTypedData<PixelType_t>::Value, "Returns data pointer to requested position.", py::arg("theRow"), py::arg("theCol"));
cls_Image_PixMapTypedData.def("ChangeValue", (PixelType_t & (Image_PixMapTypedData<PixelType_t>::*)(Standard_Size, Standard_Size)) &Image_PixMapTypedData<PixelType_t>::ChangeValue, "Returns data pointer to requested position.", py::arg("theRow"), py::arg("theCol"));

}

#endif