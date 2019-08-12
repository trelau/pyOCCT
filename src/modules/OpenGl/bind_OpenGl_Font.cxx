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
#include <OpenGl_Resource.hxx>
#include <Font_Rect.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Font_FTFont.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_Context.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_Font.hxx>
#include <NCollection_Vector.hxx>
#include <OpenGl_Texture.hxx>
#include <NCollection_DataMap.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_Font(py::module &mod){

py::class_<OpenGl_Font, opencascade::handle<OpenGl_Font>, OpenGl_Resource> cls_OpenGl_Font(mod, "OpenGl_Font", "Texture font.");

// Constructors
cls_OpenGl_Font.def(py::init<const opencascade::handle<Font_FTFont> &>(), py::arg("theFont"));
cls_OpenGl_Font.def(py::init<const opencascade::handle<Font_FTFont> &, const TCollection_AsciiString &>(), py::arg("theFont"), py::arg("theKey"));

// Fields

// Methods
cls_OpenGl_Font.def("Release", (void (OpenGl_Font::*)(OpenGl_Context *)) &OpenGl_Font::Release, "Destroy object - will release GPU memory if any", py::arg("theCtx"));
cls_OpenGl_Font.def("EstimatedDataSize", (Standard_Size (OpenGl_Font::*)() const) &OpenGl_Font::EstimatedDataSize, "Returns estimated GPU memory usage.");
cls_OpenGl_Font.def("ResourceKey", (const TCollection_AsciiString & (OpenGl_Font::*)() const) &OpenGl_Font::ResourceKey, "Returns key of shared resource");
cls_OpenGl_Font.def("FTFont", (const opencascade::handle<Font_FTFont> & (OpenGl_Font::*)() const) &OpenGl_Font::FTFont, "Returns FreeType font instance specified on construction.");
cls_OpenGl_Font.def("IsValid", (bool (OpenGl_Font::*)() const) &OpenGl_Font::IsValid, "Returns true if font was loaded successfully.");
cls_OpenGl_Font.def("WasInitialized", (bool (OpenGl_Font::*)() const) &OpenGl_Font::WasInitialized, "Notice that this method doesn't return initialization success state. Use IsValid() instead.");
cls_OpenGl_Font.def("Init", (bool (OpenGl_Font::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Font::Init, "Initialize GL resources. FreeType font instance should be already initialized!", py::arg("theCtx"));
cls_OpenGl_Font.def("Ascender", (float (OpenGl_Font::*)() const) &OpenGl_Font::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate");
cls_OpenGl_Font.def("Descender", (float (OpenGl_Font::*)() const) &OpenGl_Font::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate");
cls_OpenGl_Font.def("LineSpacing", (float (OpenGl_Font::*)() const) &OpenGl_Font::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance)");
cls_OpenGl_Font.def("RenderGlyph", (bool (OpenGl_Font::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Utf32Char, OpenGl_Font::Tile &)) &OpenGl_Font::RenderGlyph, "Render glyph to texture if not already.", py::arg("theCtx"), py::arg("theUChar"), py::arg("theGlyph"));
cls_OpenGl_Font.def_static("get_type_name_", (const char * (*)()) &OpenGl_Font::get_type_name, "None");
cls_OpenGl_Font.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Font::get_type_descriptor, "None");
cls_OpenGl_Font.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Font::*)() const) &OpenGl_Font::DynamicType, "None");

// Enums

}