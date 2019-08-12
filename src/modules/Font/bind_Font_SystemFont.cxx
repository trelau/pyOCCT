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
#include <Font_SystemFont.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Font_FontAspect.hxx>
#include <Standard_TypeDef.hxx>

void bind_Font_SystemFont(py::module &mod){

py::class_<Font_SystemFont, opencascade::handle<Font_SystemFont>, Standard_Transient> cls_Font_SystemFont(mod, "Font_SystemFont", "This class stores information about the font, which is merely a file path and cached metadata about the font.");

// Constructors
cls_Font_SystemFont.def(py::init<>());
cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFilePath"));
cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theXLFD"), py::arg("theFilePath"));

// Fields

// Methods
cls_Font_SystemFont.def_static("get_type_name_", (const char * (*)()) &Font_SystemFont::get_type_name, "None");
cls_Font_SystemFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_SystemFont::get_type_descriptor, "None");
cls_Font_SystemFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_SystemFont::*)() const) &Font_SystemFont::DynamicType, "None");
cls_Font_SystemFont.def("FontName", (const opencascade::handle<TCollection_HAsciiString> & (Font_SystemFont::*)() const) &Font_SystemFont::FontName, "Returns font family name.");
cls_Font_SystemFont.def("FontPath", (const opencascade::handle<TCollection_HAsciiString> & (Font_SystemFont::*)() const) &Font_SystemFont::FontPath, "Returns font file path.");
cls_Font_SystemFont.def("FontAspect", (Font_FontAspect (Font_SystemFont::*)() const) &Font_SystemFont::FontAspect, "Returns font aspect.");
cls_Font_SystemFont.def("FontHeight", (Standard_Integer (Font_SystemFont::*)() const) &Font_SystemFont::FontHeight, "Returns font height. If returned value is equal -1 it means that font is resizable.");
cls_Font_SystemFont.def("IsValid", (Standard_Boolean (Font_SystemFont::*)() const) &Font_SystemFont::IsValid, "None");
cls_Font_SystemFont.def("IsEqual", (Standard_Boolean (Font_SystemFont::*)(const opencascade::handle<Font_SystemFont> &) const) &Font_SystemFont::IsEqual, "Return true if the FontName, FontAspect and FontSize are the same.", py::arg("theOtherFont"));
cls_Font_SystemFont.def("IsSingleStrokeFont", (Standard_Boolean (Font_SystemFont::*)() const) &Font_SystemFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_SystemFont.def("SetSingleStrokeFont", (void (Font_SystemFont::*)(Standard_Boolean)) &Font_SystemFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));

// Enums

}