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
#include <Font_FTLibrary.hxx>
#include <Image_PixMap.hxx>
#include <NCollection_String.hxx>
#include <Font_FontAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Font_Rect.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Font_FTFont.hxx>
#include <Standard_Type.hxx>

void bind_Font_FTFont(py::module &mod){

py::class_<Font_FTFont, opencascade::handle<Font_FTFont>, Standard_Transient> cls_Font_FTFont(mod, "Font_FTFont", "Wrapper over FreeType font. Notice that this class uses internal buffers for loaded glyphs and it is absolutely UNSAFE to load/read glyph from concurrent threads!");

// Constructors
cls_Font_FTFont.def(py::init<>());
cls_Font_FTFont.def(py::init<const opencascade::handle<Font_FTLibrary> &>(), py::arg("theFTLib"));

// Fields

// Methods
cls_Font_FTFont.def("IsValid", (bool (Font_FTFont::*)() const) &Font_FTFont::IsValid, "Returns true if font is loaded");
cls_Font_FTFont.def("GlyphImage", (const Image_PixMap & (Font_FTFont::*)() const) &Font_FTFont::GlyphImage, "Returns image plane for currently rendered glyph");
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("thePointSize"), py::arg("theResolution"));
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const Font_FontAspect, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("thePointSize"), py::arg("theResolution"));
cls_Font_FTFont.def("IsSingleStrokeFont", (bool (Font_FTFont::*)() const) &Font_FTFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_FTFont.def("SetSingleStrokeFont", (void (Font_FTFont::*)(bool)) &Font_FTFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));
cls_Font_FTFont.def("Release", (void (Font_FTFont::*)()) &Font_FTFont::Release, "Release currently loaded font.");
cls_Font_FTFont.def("RenderGlyph", (bool (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::RenderGlyph, "Render specified glyph into internal buffer (bitmap).", py::arg("theChar"));
cls_Font_FTFont.def("GlyphMaxSizeX", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::GlyphMaxSizeX, "Returns maximal glyph width in pixels (rendered to bitmap).");
cls_Font_FTFont.def("GlyphMaxSizeY", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::GlyphMaxSizeY, "Returns maximal glyph height in pixels (rendered to bitmap).");
cls_Font_FTFont.def("Ascender", (float (Font_FTFont::*)() const) &Font_FTFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
cls_Font_FTFont.def("Descender", (float (Font_FTFont::*)() const) &Font_FTFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
cls_Font_FTFont.def("LineSpacing", (float (Font_FTFont::*)() const) &Font_FTFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
cls_Font_FTFont.def("PointSize", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::PointSize, "Configured point size");
cls_Font_FTFont.def("SetWidthScaling", (void (Font_FTFont::*)(const float)) &Font_FTFont::SetWidthScaling, "Setup glyph scaling along X-axis. By default glyphs are not scaled (scaling factor = 1.0)", py::arg("theScaleFactor"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("GlyphsNumber", (Standard_Integer (Font_FTFont::*)() const) &Font_FTFont::GlyphsNumber, "Returns glyphs number in this font.");
cls_Font_FTFont.def("GlyphRect", (void (Font_FTFont::*)(Font_Rect &) const) &Font_FTFont::GlyphRect, "Retrieve glyph bitmap rectangle", py::arg("theRect"));
cls_Font_FTFont.def("BoundingBox", (Font_Rect (Font_FTFont::*)(const NCollection_String &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_FTFont::BoundingBox, "Computes bounding box of the given text using plain-text formatter (Font_TextFormatter). Note that bounding box takes into account the text alignment options. Its corners are relative to the text alignment anchor point, their coordinates can be negative.", py::arg("theString"), py::arg("theAlignX"), py::arg("theAlignY"));
cls_Font_FTFont.def_static("get_type_name_", (const char * (*)()) &Font_FTFont::get_type_name, "None");
cls_Font_FTFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTFont::get_type_descriptor, "None");
cls_Font_FTFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTFont::*)() const) &Font_FTFont::DynamicType, "None");

// Enums

}