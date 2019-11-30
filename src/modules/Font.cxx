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
#include <Font_FontAspect.hxx>
#include <Font_StrictLevel.hxx>
#include <Font_UnicodeSubset.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Font_SystemFont.hxx>
#include <Font_NListOfSystemFont.hxx>
#include <NCollection_Vec2.hxx>
#include <Font_Rect.hxx>
#include <Font_FTFont.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Font_FTLibrary.hxx>
#include <Image_PixMap.hxx>
#include <NCollection_Buffer.hxx>
#include <NCollection_String.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <NCollection_Vector.hxx>
#include <Font_TextFormatter.hxx>
#include <Font_BRepFont.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Mutex.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <NCollection_Sequence.hxx>
#include <TopoDS_Wire.hxx>
#include <NCollection_DataMap.hxx>
#include <Geom_Surface.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom2dConvert_CompCurveToBSplineCurve.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <BRep_Builder.hxx>
#include <gp_Ax3.hxx>
#include <Font_BRepTextBuilder.hxx>
#include <NCollection_List.hxx>
#include <Font_FontMgr.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <bind_NCollection_List.hxx>

PYBIND11_MODULE(Font, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Image");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2dConvert");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");

struct ImportGraphic3d{
	ImportGraphic3d() { py::module::import("OCCT.Graphic3d"); }
};

// ENUM: FONT_FONTASPECT
py::enum_<Font_FontAspect>(mod, "Font_FontAspect", "Specifies aspect of system font.")
	.value("Font_FontAspect_UNDEFINED", Font_FontAspect::Font_FontAspect_UNDEFINED)
	.value("Font_FontAspect_Regular", Font_FontAspect::Font_FontAspect_Regular)
	.value("Font_FontAspect_Bold", Font_FontAspect::Font_FontAspect_Bold)
	.value("Font_FontAspect_Italic", Font_FontAspect::Font_FontAspect_Italic)
	.value("Font_FontAspect_BoldItalic", Font_FontAspect::Font_FontAspect_BoldItalic)
	.value("Font_FA_Undefined", Font_FontAspect::Font_FA_Undefined)
	.value("Font_FA_Regular", Font_FontAspect::Font_FA_Regular)
	.value("Font_FA_Bold", Font_FontAspect::Font_FA_Bold)
	.value("Font_FA_Italic", Font_FontAspect::Font_FA_Italic)
	.value("Font_FA_BoldItalic", Font_FontAspect::Font_FA_BoldItalic)
	.export_values();


// ENUM: FONT_STRICTLEVEL
py::enum_<Font_StrictLevel>(mod, "Font_StrictLevel", "Enumeration defining font search restrictions.")
	.value("Font_StrictLevel_Strict", Font_StrictLevel::Font_StrictLevel_Strict)
	.value("Font_StrictLevel_Aliases", Font_StrictLevel::Font_StrictLevel_Aliases)
	.value("Font_StrictLevel_Any", Font_StrictLevel::Font_StrictLevel_Any)
	.export_values();


// ENUM: FONT_UNICODESUBSET
py::enum_<Font_UnicodeSubset>(mod, "Font_UnicodeSubset", "Enumeration defining Unicode subsets.")
	.value("Font_UnicodeSubset_Western", Font_UnicodeSubset::Font_UnicodeSubset_Western)
	.value("Font_UnicodeSubset_Korean", Font_UnicodeSubset::Font_UnicodeSubset_Korean)
	.value("Font_UnicodeSubset_CJK", Font_UnicodeSubset::Font_UnicodeSubset_CJK)
	.value("Font_UnicodeSubset_Arabic", Font_UnicodeSubset::Font_UnicodeSubset_Arabic)
	.export_values();


// FUNCTION: ISEQUAL
mod.def("IsEqual", (Standard_Boolean (*) (const opencascade::handle<Font_SystemFont> &, const opencascade::handle<Font_SystemFont> &)) &IsEqual, "None", py::arg("theFirstFont"), py::arg("theSecondFont"));

// CLASS: FONT_RECT
py::class_<Font_Rect> cls_Font_Rect(mod, "Font_Rect", "Auxiliary POD structure - 2D rectangle definition.");

// Fields
cls_Font_Rect.def_readwrite("Left", &Font_Rect::Left, "left position");
cls_Font_Rect.def_readwrite("Right", &Font_Rect::Right, "right position");
cls_Font_Rect.def_readwrite("Top", &Font_Rect::Top, "top position");
cls_Font_Rect.def_readwrite("Bottom", &Font_Rect::Bottom, "bottom position");

// Methods
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> (Font_Rect::*)() const) &Font_Rect::TopLeft, "Top-left corner as vec2.");
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopLeft, "Top-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("TopRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopRight, "Top-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomLeft, "Bottom-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomRight, "Bottom-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("Width", (float (Font_Rect::*)() const) &Font_Rect::Width, "Rectangle width.");
cls_Font_Rect.def("Height", (float (Font_Rect::*)() const) &Font_Rect::Height, "Rectangle height.");

// TYPEDEF: FT_FACE

// TYPEDEF: FT_VECTOR

// CLASS: FONT_FTFONTPARAMS
py::class_<Font_FTFontParams> cls_Font_FTFontParams(mod, "Font_FTFontParams", "Font initialization parameters.");

// Constructors
cls_Font_FTFontParams.def(py::init<>());
cls_Font_FTFontParams.def(py::init<unsigned int, unsigned int>(), py::arg("thePointSize"), py::arg("theResolution"));

// Fields
cls_Font_FTFontParams.def_readwrite("PointSize", &Font_FTFontParams::PointSize, "face size in points (1/72 inch)");
cls_Font_FTFontParams.def_readwrite("Resolution", &Font_FTFontParams::Resolution, "resolution of the target device in dpi for FT_Set_Char_Size()");
cls_Font_FTFontParams.def_readwrite("ToSynthesizeItalic", &Font_FTFontParams::ToSynthesizeItalic, "generate italic style (e.g. for font family having no italic style); FALSE by default");
cls_Font_FTFontParams.def_readwrite("IsSingleStrokeFont", &Font_FTFontParams::IsSingleStrokeFont, "single-stroke (one-line) font, FALSE by default");

// CLASS: FONT_FTFONT
py::class_<Font_FTFont, opencascade::handle<Font_FTFont>, Standard_Transient> cls_Font_FTFont(mod, "Font_FTFont", "Wrapper over FreeType font. Notice that this class uses internal buffers for loaded glyphs and it is absolutely UNSAFE to load/read glyph from concurrent threads!");

// Constructors
cls_Font_FTFont.def(py::init<>());
cls_Font_FTFont.def(py::init<const opencascade::handle<Font_FTLibrary> &>(), py::arg("theFTLib"));

// Methods
cls_Font_FTFont.def_static("get_type_name_", (const char * (*)()) &Font_FTFont::get_type_name, "None");
cls_Font_FTFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTFont::get_type_descriptor, "None");
cls_Font_FTFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTFont::*)() const) &Font_FTFont::DynamicType, "None");
cls_Font_FTFont.def_static("FindAndCreate_", [](const TCollection_AsciiString & a0, const Font_FontAspect a1, const Font_FTFontParams & a2) -> opencascade::handle<Font_FTFont> { return Font_FTFont::FindAndCreate(a0, a1, a2); });
cls_Font_FTFont.def_static("FindAndCreate_", (opencascade::handle<Font_FTFont> (*)(const TCollection_AsciiString &, const Font_FontAspect, const Font_FTFontParams &, const Font_StrictLevel)) &Font_FTFont::FindAndCreate, "Find the font Initialize the font.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theParams"), py::arg("theStrictLevel"));
cls_Font_FTFont.def_static("IsCharFromCJK_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharFromCJK, "Return TRUE if specified character is within subset of modern CJK characters.", py::arg("theUChar"));
cls_Font_FTFont.def_static("IsCharFromHiragana_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharFromHiragana, "Return TRUE if specified character is within subset of Hiragana (Japanese).", py::arg("theUChar"));
cls_Font_FTFont.def_static("IsCharFromKatakana_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharFromKatakana, "Return TRUE if specified character is within subset of Katakana (Japanese).", py::arg("theUChar"));
cls_Font_FTFont.def_static("IsCharFromKorean_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharFromKorean, "Return TRUE if specified character is within subset of modern Korean characters (Hangul).", py::arg("theUChar"));
cls_Font_FTFont.def_static("IsCharFromArabic_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharFromArabic, "Return TRUE if specified character is within subset of Arabic characters.", py::arg("theUChar"));
cls_Font_FTFont.def_static("IsCharRightToLeft_", (bool (*)(Standard_Utf32Char)) &Font_FTFont::IsCharRightToLeft, "Return TRUE if specified character should be displayed in Right-to-Left order.", py::arg("theUChar"));
cls_Font_FTFont.def_static("CharSubset_", (Font_UnicodeSubset (*)(Standard_Utf32Char)) &Font_FTFont::CharSubset, "Determine Unicode subset for specified character", py::arg("theUChar"));
cls_Font_FTFont.def("IsValid", (bool (Font_FTFont::*)() const) &Font_FTFont::IsValid, "Returns true if font is loaded");
cls_Font_FTFont.def("GlyphImage", (const Image_PixMap & (Font_FTFont::*)() const) &Font_FTFont::GlyphImage, "Returns image plane for currently rendered glyph");
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const TCollection_AsciiString &, const Font_FTFontParams &)) &Font_FTFont::Init, "Initialize the font from the given file path.", py::arg("theFontPath"), py::arg("theParams"));
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const opencascade::handle<NCollection_Buffer> &, const TCollection_AsciiString &, const Font_FTFontParams &)) &Font_FTFont::Init, "Initialize the font from the given file path or memory buffer.", py::arg("theData"), py::arg("theFileName"), py::arg("theParams"));
cls_Font_FTFont.def("FindAndInit", [](Font_FTFont &self, const TCollection_AsciiString & a0, Font_FontAspect a1, const Font_FTFontParams & a2) -> bool { return self.FindAndInit(a0, a1, a2); });
cls_Font_FTFont.def("FindAndInit", (bool (Font_FTFont::*)(const TCollection_AsciiString &, Font_FontAspect, const Font_FTFontParams &, Font_StrictLevel)) &Font_FTFont::FindAndInit, "Find (using Font_FontMgr) and initialize the font from the given name.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theParams"), py::arg("theStrictLevel"));
cls_Font_FTFont.def("ToUseUnicodeSubsetFallback", (Standard_Boolean (Font_FTFont::*)() const) &Font_FTFont::ToUseUnicodeSubsetFallback, "Return flag to use fallback fonts in case if used font does not include symbols from specific Unicode subset; TRUE by default.");
cls_Font_FTFont.def("SetUseUnicodeSubsetFallback", (void (Font_FTFont::*)(Standard_Boolean)) &Font_FTFont::SetUseUnicodeSubsetFallback, "Set if fallback fonts should be used in case if used font does not include symbols from specific Unicode subset.", py::arg("theToFallback"));
cls_Font_FTFont.def("IsSingleStrokeFont", (bool (Font_FTFont::*)() const) &Font_FTFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_FTFont.def("SetSingleStrokeFont", (void (Font_FTFont::*)(bool)) &Font_FTFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));
cls_Font_FTFont.def("ToSynthesizeItalic", (bool (Font_FTFont::*)() const) &Font_FTFont::ToSynthesizeItalic, "Return TRUE if italic style should be synthesized; FALSE by default.");
cls_Font_FTFont.def("Release", (void (Font_FTFont::*)()) &Font_FTFont::Release, "Release currently loaded font.");
cls_Font_FTFont.def("RenderGlyph", (bool (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::RenderGlyph, "Render specified glyph into internal buffer (bitmap).", py::arg("theChar"));
cls_Font_FTFont.def("GlyphMaxSizeX", [](Font_FTFont &self) -> unsigned int { return self.GlyphMaxSizeX(); });
cls_Font_FTFont.def("GlyphMaxSizeX", (unsigned int (Font_FTFont::*)(bool) const) &Font_FTFont::GlyphMaxSizeX, "Returns maximal glyph width in pixels (rendered to bitmap).", py::arg("theToIncludeFallback"));
cls_Font_FTFont.def("GlyphMaxSizeY", [](Font_FTFont &self) -> unsigned int { return self.GlyphMaxSizeY(); });
cls_Font_FTFont.def("GlyphMaxSizeY", (unsigned int (Font_FTFont::*)(bool) const) &Font_FTFont::GlyphMaxSizeY, "Returns maximal glyph height in pixels (rendered to bitmap).", py::arg("theToIncludeFallback"));
cls_Font_FTFont.def("Ascender", (float (Font_FTFont::*)() const) &Font_FTFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
cls_Font_FTFont.def("Descender", (float (Font_FTFont::*)() const) &Font_FTFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
cls_Font_FTFont.def("LineSpacing", (float (Font_FTFont::*)() const) &Font_FTFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
cls_Font_FTFont.def("PointSize", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::PointSize, "Configured point size");
cls_Font_FTFont.def("SetWidthScaling", (void (Font_FTFont::*)(const float)) &Font_FTFont::SetWidthScaling, "Setup glyph scaling along X-axis. By default glyphs are not scaled (scaling factor = 1.0)", py::arg("theScaleFactor"));
cls_Font_FTFont.def("HasSymbol", (bool (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::HasSymbol, "Return TRUE if font contains specified symbol (excluding fallback list).", py::arg("theUChar"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("GlyphsNumber", [](Font_FTFont &self) -> Standard_Integer { return self.GlyphsNumber(); });
cls_Font_FTFont.def("GlyphsNumber", (Standard_Integer (Font_FTFont::*)(bool) const) &Font_FTFont::GlyphsNumber, "Return glyphs number in this font.", py::arg("theToIncludeFallback"));
cls_Font_FTFont.def("GlyphRect", (void (Font_FTFont::*)(Font_Rect &) const) &Font_FTFont::GlyphRect, "Retrieve glyph bitmap rectangle", py::arg("theRect"));
cls_Font_FTFont.def("BoundingBox", (Font_Rect (Font_FTFont::*)(const NCollection_String &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_FTFont::BoundingBox, "Computes bounding box of the given text using plain-text formatter (Font_TextFormatter). Note that bounding box takes into account the text alignment options. Its corners are relative to the text alignment anchor point, their coordinates can be negative.", py::arg("theString"), py::arg("theAlignX"), py::arg("theAlignY"));
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, unsigned int, unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("thePointSize"), py::arg("theResolution"));
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, Font_FontAspect, unsigned int, unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("thePointSize"), py::arg("theResolution"));

// CLASS: FONT_TEXTFORMATTER
py::class_<Font_TextFormatter> cls_Font_TextFormatter(mod, "Font_TextFormatter", "This class intended to prepare formatted text.");

// Constructors
cls_Font_TextFormatter.def(py::init<>());

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

// CLASS: FONT_BREPFONT
/*
py::class_<Font_BRepFont, opencascade::handle<Font_BRepFont>> cls_Font_BRepFont(mod, "Font_BRepFont", "This tool provides basic services for rendering of vectorized text glyphs as BRep shapes. Single instance initialize single font for sequential glyphs rendering with implicit caching of already rendered glyphs. Thus position of each glyph in the text is specified by shape location.");

// Constructors
cls_Font_BRepFont.def(py::init<>());
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Standard_Real>(), py::arg("theFontPath"), py::arg("theSize"));
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Font_FontAspect, const Standard_Real>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Font_FontAspect, const Standard_Real, const Font_StrictLevel>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"), py::arg("theStrictLevel"));

// Methods
cls_Font_BRepFont.def_static("get_type_name_", (const char * (*)()) &Font_BRepFont::get_type_name, "None");
cls_Font_BRepFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_BRepFont::get_type_descriptor, "None");
cls_Font_BRepFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_BRepFont::*)() const) &Font_BRepFont::DynamicType, "None");
cls_Font_BRepFont.def("Release", (void (Font_BRepFont::*)()) &Font_BRepFont::Release, "Release currently loaded font.");
cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Standard_Real)) &Font_BRepFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("theSize"));
cls_Font_BRepFont.def("FindAndInit", [](Font_BRepFont &self, const TCollection_AsciiString & a0, const Font_FontAspect a1, const Standard_Real a2) -> bool { return self.FindAndInit(a0, a1, a2); });
cls_Font_BRepFont.def("FindAndInit", (bool (Font_BRepFont::*)(const TCollection_AsciiString &, const Font_FontAspect, const Standard_Real, const Font_StrictLevel)) &Font_BRepFont::FindAndInit, "Find (using Font_FontMgr) and initialize the font from the given name. Please take into account that size is specified NOT in typography points (pt.). If you need to specify size in points, value should be converted. Formula for pt. -> m conversion: aSizeMeters = 0.0254 * theSizePt / 72.0", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"), py::arg("theStrictLevel"));
cls_Font_BRepFont.def("RenderGlyph", (TopoDS_Shape (Font_BRepFont::*)(const Standard_Utf32Char &)) &Font_BRepFont::RenderGlyph, "Render single glyph as TopoDS_Shape.", py::arg("theChar"));
cls_Font_BRepFont.def("SetCompositeCurveMode", (void (Font_BRepFont::*)(const Standard_Boolean)) &Font_BRepFont::SetCompositeCurveMode, "Setup glyph geometry construction mode. By default algorithm creates independent TopoDS_Edge for each original curve in the glyph (line segment or Bezie curve). Algorithm might optionally create composite BSpline curve for each contour which reduces memory footprint but limits curve class to C0. Notice that altering this flag clears currently accumulated cache!", py::arg("theToConcatenate"));
cls_Font_BRepFont.def("SetWidthScaling", (void (Font_BRepFont::*)(const float)) &Font_BRepFont::SetWidthScaling, "Setup glyph scaling along X-axis. By default glyphs are not scaled (scaling factor = 1.0)", py::arg("theScaleFactor"));
cls_Font_BRepFont.def("Ascender", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
cls_Font_BRepFont.def("Descender", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
cls_Font_BRepFont.def("LineSpacing", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
cls_Font_BRepFont.def("PointSize", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::PointSize, "Configured point size");
cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_BRepFont.def("Scale", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Scale, "Returns scaling factor for current font size.");
cls_Font_BRepFont.def("Mutex", (Standard_Mutex & (Font_BRepFont::*)()) &Font_BRepFont::Mutex, "Returns mutex.");
cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Font_FontAspect, const Standard_Real)) &Font_BRepFont::Init, "Find (using Font_FontMgr) and initialize the font from the given name. Alias for FindAndInit() for backward compatibility.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));
*/

// CLASS: FONT_BREPTEXTBUILDER
py::class_<Font_BRepTextBuilder> cls_Font_BRepTextBuilder(mod, "Font_BRepTextBuilder", "Represents class for applying text formatting.");

// Methods
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const Font_TextFormatter & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const Font_TextFormatter &, const gp_Ax3 &)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theFormatter"), py::arg("thePenLoc"), py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2) -> TopoDS_Shape { return self.Perform(a0, a1, a2); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2, const Graphic3d_HorizontalTextAlignment a3) -> TopoDS_Shape { return self.Perform(a0, a1, a2, a3); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const NCollection_String &, const gp_Ax3 &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::arg("theHAlign"), py::arg("theVAlign"), py::call_guard<ImportGraphic3d>());

// CLASS: FONT_SYSTEMFONT
py::class_<Font_SystemFont, opencascade::handle<Font_SystemFont>, Standard_Transient> cls_Font_SystemFont(mod, "Font_SystemFont", "This class stores information about the font, which is merely a file path and cached metadata about the font.");

// Constructors
cls_Font_SystemFont.def(py::init<const TCollection_AsciiString &>(), py::arg("theFontName"));

// Methods
cls_Font_SystemFont.def_static("get_type_name_", (const char * (*)()) &Font_SystemFont::get_type_name, "None");
cls_Font_SystemFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_SystemFont::get_type_descriptor, "None");
cls_Font_SystemFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_SystemFont::*)() const) &Font_SystemFont::DynamicType, "None");
cls_Font_SystemFont.def("FontKey", (const TCollection_AsciiString & (Font_SystemFont::*)() const) &Font_SystemFont::FontKey, "Returns font family name (lower-cased).");
cls_Font_SystemFont.def("FontName", (const TCollection_AsciiString & (Font_SystemFont::*)() const) &Font_SystemFont::FontName, "Returns font family name.");
cls_Font_SystemFont.def("FontPath", (const TCollection_AsciiString & (Font_SystemFont::*)(Font_FontAspect) const) &Font_SystemFont::FontPath, "Returns font file path.", py::arg("theAspect"));
cls_Font_SystemFont.def("SetFontPath", (void (Font_SystemFont::*)(Font_FontAspect, const TCollection_AsciiString &)) &Font_SystemFont::SetFontPath, "Sets font file path for specific aspect.", py::arg("theAspect"), py::arg("thePath"));
cls_Font_SystemFont.def("HasFontAspect", (bool (Font_SystemFont::*)(Font_FontAspect) const) &Font_SystemFont::HasFontAspect, "Returns TRUE if dedicated file for specified font aspect has been defined.", py::arg("theAspect"));
cls_Font_SystemFont.def("FontPathAny", (const TCollection_AsciiString & (Font_SystemFont::*)(Font_FontAspect, bool &) const) &Font_SystemFont::FontPathAny, "Returns any defined font file path.", py::arg("theAspect"), py::arg("theToSynthesizeItalic"));
cls_Font_SystemFont.def("IsEqual", (Standard_Boolean (Font_SystemFont::*)(const opencascade::handle<Font_SystemFont> &) const) &Font_SystemFont::IsEqual, "Return true if the FontName, FontAspect and FontSize are the same.", py::arg("theOtherFont"));
cls_Font_SystemFont.def("IsSingleStrokeFont", (Standard_Boolean (Font_SystemFont::*)() const) &Font_SystemFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_SystemFont.def("SetSingleStrokeFont", (void (Font_SystemFont::*)(Standard_Boolean)) &Font_SystemFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));
cls_Font_SystemFont.def("ToString", (TCollection_AsciiString (Font_SystemFont::*)() const) &Font_SystemFont::ToString, "Format font description.");
cls_Font_SystemFont.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<Font_SystemFont> &, const Standard_Integer)) &Font_SystemFont::HashCode, "Computes a hash code for the system font, in the range [1, theUpperBound]. Based on Font Family, so that the whole family with different aspects can be found within the same bucket of some map", py::arg("theSystemFont"), py::arg("theUpperBound"));
cls_Font_SystemFont.def_static("IsEqual_", (bool (*)(const opencascade::handle<Font_SystemFont> &, const opencascade::handle<Font_SystemFont> &)) &Font_SystemFont::IsEqual, "Matching two instances, for Map interface.", py::arg("theFont1"), py::arg("theFont2"));

// TYPEDEF: FONT_NLISTOFSYSTEMFONT
bind_NCollection_List<opencascade::handle<Font_SystemFont> >(mod, "Font_NListOfSystemFont", py::module_local(false));

// CLASS: FONT_FONTMGR
py::class_<Font_FontMgr, opencascade::handle<Font_FontMgr>, Standard_Transient> cls_Font_FontMgr(mod, "Font_FontMgr", "Collects and provides information about available fonts in system.");

// Methods
cls_Font_FontMgr.def_static("get_type_name_", (const char * (*)()) &Font_FontMgr::get_type_name, "None");
cls_Font_FontMgr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FontMgr::get_type_descriptor, "None");
cls_Font_FontMgr.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FontMgr::*)() const) &Font_FontMgr::DynamicType, "None");
cls_Font_FontMgr.def_static("GetInstance_", (opencascade::handle<Font_FontMgr> (*)()) &Font_FontMgr::GetInstance, "Return global instance of font manager.");
cls_Font_FontMgr.def_static("FontAspectToString_", (const char * (*)(Font_FontAspect)) &Font_FontMgr::FontAspectToString, "Return font aspect as string.", py::arg("theAspect"));
cls_Font_FontMgr.def_static("ToUseUnicodeSubsetFallback_", (Standard_Boolean & (*)()) &Font_FontMgr::ToUseUnicodeSubsetFallback, "Return flag to use fallback fonts in case if used font does not include symbols from specific Unicode subset; TRUE by default.");
cls_Font_FontMgr.def("AvailableFonts", (void (Font_FontMgr::*)(Font_NListOfSystemFont &) const) &Font_FontMgr::AvailableFonts, "Return the list of available fonts.", py::arg("theList"));
cls_Font_FontMgr.def("GetAvailableFonts", (Font_NListOfSystemFont (Font_FontMgr::*)() const) &Font_FontMgr::GetAvailableFonts, "Return the list of available fonts.");
cls_Font_FontMgr.def("GetAvailableFontsNames", (void (Font_FontMgr::*)(TColStd_SequenceOfHAsciiString &) const) &Font_FontMgr::GetAvailableFontsNames, "Returns sequence of available fonts names", py::arg("theFontsNames"));
cls_Font_FontMgr.def("GetFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const) &Font_FontMgr::GetFont, "Returns font that match given parameters. If theFontName is empty string returned font can have any FontName. If theFontAspect is Font_FA_Undefined returned font can have any FontAspect. If theFontSize is '-1' returned font can have any FontSize.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
cls_Font_FontMgr.def("GetFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const TCollection_AsciiString &) const) &Font_FontMgr::GetFont, "Returns font that match given name or NULL if such font family is NOT registered. Note that unlike FindFont(), this method ignores font aliases and does not look for fall-back.", py::arg("theFontName"));
cls_Font_FontMgr.def("FindFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const TCollection_AsciiString &, Font_StrictLevel, Font_FontAspect &) const) &Font_FontMgr::FindFont, "Tries to find font by given parameters. If the specified font is not found tries to use font names mapping. If the requested family name not found -> search for any font family with given aspect and height. If the font is still not found, returns any font available in the system. Returns NULL in case when the fonts are not found in the system.", py::arg("theFontName"), py::arg("theStrictLevel"), py::arg("theFontAspect"));
cls_Font_FontMgr.def("FindFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const TCollection_AsciiString &, Font_FontAspect &) const) &Font_FontMgr::FindFont, "Tries to find font by given parameters.", py::arg("theFontName"), py::arg("theFontAspect"));
cls_Font_FontMgr.def("FindFallbackFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(Font_UnicodeSubset, Font_FontAspect) const) &Font_FontMgr::FindFallbackFont, "Tries to find fallback font for specified Unicode subset. Returns NULL in case when fallback font is not found in the system.", py::arg("theSubset"), py::arg("theFontAspect"));
cls_Font_FontMgr.def("CheckFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const Standard_CString) const) &Font_FontMgr::CheckFont, "Read font file and retrieve information from it.", py::arg("theFontPath"));
cls_Font_FontMgr.def("RegisterFont", (Standard_Boolean (Font_FontMgr::*)(const opencascade::handle<Font_SystemFont> &, const Standard_Boolean)) &Font_FontMgr::RegisterFont, "Register new font. If there is existing entity with the same name and properties but different path then font will be overridden or ignored depending on theToOverride flag.", py::arg("theFont"), py::arg("theToOverride"));
cls_Font_FontMgr.def("ToTraceAliases", (Standard_Boolean (Font_FontMgr::*)() const) &Font_FontMgr::ToTraceAliases, "Return flag for tracing font aliases usage via Message_Trace messages; TRUE by default.");
cls_Font_FontMgr.def("SetTraceAliases", (void (Font_FontMgr::*)(Standard_Boolean)) &Font_FontMgr::SetTraceAliases, "Set flag for tracing font alias usage; useful to trace which fonts are actually used. Can be disabled to avoid redundant messages with Message_Trace level.", py::arg("theToTrace"));

// TYPEDEF: FT_LIBRARY

// CLASS: FONT_FTLIBRARY
py::class_<Font_FTLibrary, opencascade::handle<Font_FTLibrary>, Standard_Transient> cls_Font_FTLibrary(mod, "Font_FTLibrary", "Wrapper over FT_Library. Provides access to FreeType library.");

// Constructors
cls_Font_FTLibrary.def(py::init<>());

// Methods
cls_Font_FTLibrary.def("IsValid", (bool (Font_FTLibrary::*)() const) &Font_FTLibrary::IsValid, "This method should always return true.");
// cls_Font_FTLibrary.def("Instance", (FT_Library (Font_FTLibrary::*)() const) &Font_FTLibrary::Instance, "Access FT_Library instance.");
cls_Font_FTLibrary.def_static("get_type_name_", (const char * (*)()) &Font_FTLibrary::get_type_name, "None");
cls_Font_FTLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTLibrary::get_type_descriptor, "None");
cls_Font_FTLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTLibrary::*)() const) &Font_FTLibrary::DynamicType, "None");


}
