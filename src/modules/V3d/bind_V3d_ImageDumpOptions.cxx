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
#include <Graphic3d_BufferType.hxx>
#include <V3d_StereoDumpOptions.hxx>
#include <V3d_ImageDumpOptions.hxx>

void bind_V3d_ImageDumpOptions(py::module &mod){

py::class_<V3d_ImageDumpOptions> cls_V3d_ImageDumpOptions(mod, "V3d_ImageDumpOptions", "The structure defines options for image dump functionality.");

// Constructors
cls_V3d_ImageDumpOptions.def(py::init<>());

// Fields
cls_V3d_ImageDumpOptions.def_readwrite("Width", &V3d_ImageDumpOptions::Width, "width of image dump to allocate an image, 0 by default (meaning that image should be already allocated)");
cls_V3d_ImageDumpOptions.def_readwrite("Height", &V3d_ImageDumpOptions::Height, "height of image dump to allocate an image, 0 by default (meaning that image should be already allocated)");
cls_V3d_ImageDumpOptions.def_readwrite("BufferType", &V3d_ImageDumpOptions::BufferType, "which buffer to dump (color / depth), Graphic3d_BT_RGB by default");
cls_V3d_ImageDumpOptions.def_readwrite("StereoOptions", &V3d_ImageDumpOptions::StereoOptions, "dumping stereoscopic camera, V3d_SDO_MONO by default (middle-point monographic projection)");
cls_V3d_ImageDumpOptions.def_readwrite("TileSize", &V3d_ImageDumpOptions::TileSize, "the view dimension limited for tiled dump, 0 by default (automatic tiling depending on hardware capabilities)");
cls_V3d_ImageDumpOptions.def_readwrite("ToAdjustAspect", &V3d_ImageDumpOptions::ToAdjustAspect, "flag to override active view aspect ratio by (Width / Height) defined for image dump (TRUE by default)");

// Methods

// Enums

}