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
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <NCollection_String.hxx>
#include <Font_FTFont.hxx>
#include <NCollection_Vec2.hxx>
#include <Standard_TypeDef.hxx>
#include <Font_Rect.hxx>
#include <NCollection_Vector.hxx>
#include <Font_TextFormatter.hxx>

void bind_Font_TextFormatter(py::module &mod){

py::class_<Font_TextFormatter, std::unique_ptr<Font_TextFormatter, Deleter<Font_TextFormatter>>> cls_Font_TextFormatter(mod, "Font_TextFormatter", "This class intended to prepare formatted text.");

// Constructors
cls_Font_TextFormatter.def(py::init<>());

// Fields

// Methods
cls_Font_TextFormatter.def("SetupAlignment", (void (Font_TextFormatter::*)(const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_TextFormatter::SetupAlignment, "Setup alignment style.", py::arg("theAlignX"), py::arg("theAlignY"), py::call_guard<ImportGraphic3d>());
cls_Font_TextFormatter.def("Reset", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Reset, "Reset current progress.");
cls_Font_TextFormatter.def("Append", (void (Font_TextFormatter::*)(const NCollection_String &, Font_FTFont &)) &Font_TextFormatter::Append, "Render specified text to inner buffer.", py::arg("theString"), py::arg("theFont"));
cls_Font_TextFormatter.def("Format", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Format, "Perform formatting on the buffered text. Should not be called more than once after initialization!");
cls_Font_TextFormatter.def("TopLeft", (const NCollection_Vec2<Standard_ShortReal> & (Font_TextFormatter::*)(const Standard_Integer) const) &Font_TextFormatter::TopLeft, "Returns specific glyph rectangle.", py::arg("theIndex"));
cls_Font_TextFormatter.def("String", (const NCollection_String & (Font_TextFormatter::*)() const) &Font_TextFormatter::String, "Returns current rendering string.");
cls_Font_TextFormatter.def("TabSize", (Standard_Integer (Font_TextFormatter::*)() const) &Font_TextFormatter::TabSize, "Returns tab size.");
cls_Font_TextFormatter.def("ResultWidth", (Standard_ShortReal (Font_TextFormatter::*)() const) &Font_TextFormatter::ResultWidth, "Returns width of formatted text.");
cls_Font_TextFormatter.def("ResultHeight", (Standard_ShortReal (Font_TextFormatter::*)() const) &Font_TextFormatter::ResultHeight, "Returns height of formatted text.");
cls_Font_TextFormatter.def("BndBox", (void (Font_TextFormatter::*)(Font_Rect &) const) &Font_TextFormatter::BndBox, "", py::arg("theBndBox"));

// Enums

}