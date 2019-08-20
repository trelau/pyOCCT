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
#include <Aspect_XWD.hxx>

void bind__xwd_file_header(py::module &mod){

py::class_<_xwd_file_header, std::unique_ptr<_xwd_file_header>> cls__xwd_file_header(mod, "_xwd_file_header", "None");

// Constructors

// Fields
cls__xwd_file_header.def_readwrite("header_size", &_xwd_file_header::header_size, "None");
cls__xwd_file_header.def_readwrite("file_version", &_xwd_file_header::file_version, "None");
cls__xwd_file_header.def_readwrite("pixmap_format", &_xwd_file_header::pixmap_format, "None");
cls__xwd_file_header.def_readwrite("pixmap_depth", &_xwd_file_header::pixmap_depth, "None");
cls__xwd_file_header.def_readwrite("pixmap_width", &_xwd_file_header::pixmap_width, "None");
cls__xwd_file_header.def_readwrite("pixmap_height", &_xwd_file_header::pixmap_height, "None");
cls__xwd_file_header.def_readwrite("xoffset", &_xwd_file_header::xoffset, "None");
cls__xwd_file_header.def_readwrite("byte_order", &_xwd_file_header::byte_order, "None");
cls__xwd_file_header.def_readwrite("bitmap_unit", &_xwd_file_header::bitmap_unit, "None");
cls__xwd_file_header.def_readwrite("bitmap_bit_order", &_xwd_file_header::bitmap_bit_order, "None");
cls__xwd_file_header.def_readwrite("bitmap_pad", &_xwd_file_header::bitmap_pad, "None");
cls__xwd_file_header.def_readwrite("bits_per_pixel", &_xwd_file_header::bits_per_pixel, "None");
cls__xwd_file_header.def_readwrite("bytes_per_line", &_xwd_file_header::bytes_per_line, "None");
cls__xwd_file_header.def_readwrite("visual_class", &_xwd_file_header::visual_class, "None");
cls__xwd_file_header.def_readwrite("red_mask", &_xwd_file_header::red_mask, "None");
cls__xwd_file_header.def_readwrite("green_mask", &_xwd_file_header::green_mask, "None");
cls__xwd_file_header.def_readwrite("blue_mask", &_xwd_file_header::blue_mask, "None");
cls__xwd_file_header.def_readwrite("bits_per_rgb", &_xwd_file_header::bits_per_rgb, "None");
cls__xwd_file_header.def_readwrite("colormap_entries", &_xwd_file_header::colormap_entries, "None");
cls__xwd_file_header.def_readwrite("ncolors", &_xwd_file_header::ncolors, "None");
cls__xwd_file_header.def_readwrite("window_width", &_xwd_file_header::window_width, "None");
cls__xwd_file_header.def_readwrite("window_height", &_xwd_file_header::window_height, "None");
cls__xwd_file_header.def_readwrite("window_x", &_xwd_file_header::window_x, "None");
cls__xwd_file_header.def_readwrite("window_y", &_xwd_file_header::window_y, "None");
cls__xwd_file_header.def_readwrite("window_bdrwidth", &_xwd_file_header::window_bdrwidth, "None");

// Methods

// Enums

}