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
#include <Font_FontMgr.hxx>
#include <Font_NListOfSystemFont.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <Font_SystemFont.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Font_FontAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_Font_FontMgr(py::module &mod){

py::class_<Font_FontMgr, opencascade::handle<Font_FontMgr>, Standard_Transient> cls_Font_FontMgr(mod, "Font_FontMgr", "Collects and provides information about available fonts in system.");

// Constructors

// Fields

// Methods
cls_Font_FontMgr.def_static("GetInstance_", (opencascade::handle<Font_FontMgr> (*)()) &Font_FontMgr::GetInstance, "None");
cls_Font_FontMgr.def("GetAvailableFonts", (const Font_NListOfSystemFont & (Font_FontMgr::*)() const) &Font_FontMgr::GetAvailableFonts, "None");
cls_Font_FontMgr.def("GetAvailableFontsNames", (void (Font_FontMgr::*)(TColStd_SequenceOfHAsciiString &) const) &Font_FontMgr::GetAvailableFontsNames, "Returns sequence of available fonts names", py::arg("theFontsNames"));
cls_Font_FontMgr.def("GetFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const) &Font_FontMgr::GetFont, "Returns font that match given parameters. If theFontName is empty string returned font can have any FontName. If theFontAspect is Font_FA_Undefined returned font can have any FontAspect. If theFontSize is '-1' returned font can have any FontSize.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
cls_Font_FontMgr.def("FindFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const) &Font_FontMgr::FindFont, "Tries to find font by given parameters. If the specified font is not found tries to use font names mapping. If the requested family name not found -> search for any font family with given aspect and height. If the font is still not found, returns any font available in the system. Returns NULL in case when the fonts are not found in the system.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
cls_Font_FontMgr.def("CheckFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const Standard_CString) const) &Font_FontMgr::CheckFont, "Read font file and retrieve information from it.", py::arg("theFontPath"));
cls_Font_FontMgr.def("RegisterFont", (Standard_Boolean (Font_FontMgr::*)(const opencascade::handle<Font_SystemFont> &, const Standard_Boolean)) &Font_FontMgr::RegisterFont, "Register new font. If there is existing entity with the same name and properties but different path then font will will be overridden or ignored depending on theToOverride flag.", py::arg("theFont"), py::arg("theToOverride"));
cls_Font_FontMgr.def_static("get_type_name_", (const char * (*)()) &Font_FontMgr::get_type_name, "None");
cls_Font_FontMgr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FontMgr::get_type_descriptor, "None");
cls_Font_FontMgr.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FontMgr::*)() const) &Font_FontMgr::DynamicType, "None");

// Enums

}